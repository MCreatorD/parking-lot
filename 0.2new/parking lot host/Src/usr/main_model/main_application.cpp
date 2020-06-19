#include "main_application.h"
#include <stdio.h>

#include <rtc.h>

#include "general.h"
#include "GetDeviceCapabilities.h"
#include "ExtendLLRP.h"
#include "ManufacturerFrame.h"
#include "ExtendHbFrame_Operation.h"
#include "sim_Spi.h"
#include "sim_Spi1.h"
#include "systick.h"
#include "lowpower.h"
#include "read_manage.h"
#include "pcf8563.h"
#include "banister.h"
Main_Application *g_pMainApplication;


Main_Application::Main_Application()
{

  //////////////////////////////////////////////////////////////
  g_pMainApplication = this;

	m_pIOCtrl = new IOCtrl();
	m_read_manage = new read_manage();
	initSerialComm();
	initOperationProcess();
	initVersionManager();
	initParamManager();
	
	initRfManager();
	
	m_pRfManager->setRfOper(m_pOperationProcess->getOpExecute()->getRfOper());
	
	initM2SecComm();
	m_pM2SecComm->setIOCtrl(m_pIOCtrl);
	
	m_pOperationProcess->getOpExecute()->setMCUToSecComm(m_pM2SecComm);
	m_pOperationProcess->getOpExecute()->getRfOper()->setIOCtrl(m_pIOCtrl);
	m_pOperationProcess->getOpExecute()->getRfOper()->setM2SecComm(m_pM2SecComm);
	
	m_pSm2Certification = new Sm2Certification();
	m_pSm2Certification->setM2SecComm(m_pM2SecComm);
	m_pSm2Certification->setIOCtrl(m_pIOCtrl);
	this->SMCertification(); //进行安全认证

	//m_read_manage->read_managetest(3);//参数从节点地址
	//m_read_manage->SendRadarData(200);
}

Main_Application::~Main_Application(){
	delete m_pSerialComm;
	delete m_pOperationProcess;
}


void Main_Application::SMCertification(){
    //进行安全认证工作。
    //printf("Start Certification...\n");

    m_pSm2Certification->CertificationID(false);

    //printf("Certification end!\n");
}

bool Main_Application::sendMessageWithID(CMessage *,int,llrp_u32_t){
	
}

bool Main_Application::sendMessage(){
	
}

void Main_Application::initSerialComm(){
	m_pSerialComm = new Serial_Comm(0); //串口通信口，默认ID号为3
}

void Main_Application::initOperationProcess(){
	m_pOperationProcess = new Operation_Process();
}

void Main_Application::initVersionManager(){
	m_pVersionManager = new VersionManager();
}

void Main_Application::initParamManager(){
	m_pParamManager = new Param_Manager();
}

void Main_Application::initRfManager(){
	m_pRfManager = new Rf_Manager();
}

void Main_Application::initM2SecComm(){
	m_pM2SecComm = new MCUToSecureComm();
}



/**
 * @brief Main_Application::dealGeneralMessage
 * @param pMessage
 * @return
 * 处理通用的消息
 */
int Main_Application::dealGeneralMessage(CMessage *pMessage,Base_Comm *pComm){
    CMessage *pack = NULL;
    switch(pMessage->m_pType->m_TypeNum){
    case GetDeviceCapabilities:
    {
        llrp_u8_t requesteddata;
        CGetDeviceCapabilities *pGetDeviceCapabilities = (CGetDeviceCapabilities *)pMessage;
        requesteddata = pGetDeviceCapabilities->getRequestedData();
        GetDeviceCapabilitiesFuction capabilities;
        pack = capabilities.getDeviceCapabilitiesRequestedDataMessage(requesteddata);
    }
        break;
    case ResetDevice:
    {
        pack = HbFrame_Operation::genMessage(ResetDeviceAck,0);
        CStatus *pstatus = (CStatus*)HbFrame_Operation::genParam(Status,0,NULL);
        pstatus->setStatusCode(StatusCode_M_Success);
        HbFrame_Operation::addParamToMessage(pstatus,pack);
				//单片机复位
				SoftReset();
			
    }
        break;
    default:
        break;
    }
    if(pack!=NULL){
			pComm->immediateSendMessage(pack,pMessage->getMessageID());
			delete pack;
			return 0;
		}else{
			return -1;
		}
}

void Main_Application::dealRecvMessages(CMessage *pMessage,Base_Comm *pComm){
    llrp_u32_t messageid = pMessage->getMessageID();
    llrp_u64_t messagedevsn = pMessage->getDeviceSN(); //取出命令消息的deviceSN,新规范中，可能会要求只对和设备SN一致的消息响应。

    //printf("Main_Application:message name is %s\n",pMessage->m_pType->m_pName);

    switch(pMessage->m_pType->m_TypeNum){
    case KeepaliveAck: //心跳返回消息
        //2017.06.27将心跳包的接收处理放入各个链路中自行处理。这里不再会有心跳包在此处理
        //pComm->clearKeepOverTimer();
        break;
		case ManufacturerCommand: //厂家自定义消息
        {	
				CManufacturerCommand *pcommd = (CManufacturerCommand*)pMessage;
				llrp_u8v_t bufs = pcommd->getByteStream();

				STRUCT_ManufacturerFrame manuframe = {0};
				manuframe.OperID = bufs.m_pValue[0];    //操作标识
				manuframe.Datalen_H = bufs.m_pValue[1]; //帧长度 2字节(大端模式)
				manuframe.Datalen_L = bufs.m_pValue[2];
				manuframe.DataBuf = bufs.m_pValue+3;    //帧内容 N字节
				CManufacturerReport *preportmessage =  (CManufacturerReport *)ExtendHbFrame_Operation::genMessage(ManufacturerReport,0);

				switch(manuframe.OperID){
					
				case 0x91: //手动校时
				{
						llrp_u8v_t bytes = llrp_u8v_t(4);   //响应
						bytes.m_pValue[0] = 0x11;  					//操作标识
						bytes.m_pValue[1] = 0x00;           //帧长度
						bytes.m_pValue[2] = 0x01;           //帧长度
						bytes.m_pValue[3] = 0x00; //成功    //帧内容
						llrp_u64_t utctime = 0;
						llrp_u64_t temp = 0;
						//取出UTC，注意，命令中的UTC是低字节在前
						for(int i=0;i<8;i++){
								temp = manuframe.DataBuf[i];
								utctime = utctime | (temp<<(i*8));
						}
						
						//printf("utctime=%llu\n",utctime);
						//this->m_ntpClient.setUTCTime(utctime);
						//if(utcTotime((unsigned int)(utctime/1000000))>0){
						if(utcTotime((unsigned int)(utctime/1000000))>0){
							bytes.m_pValue[3] = 0x00; //成功
						}else{
							bytes.m_pValue[3] = 0x01; //失败
						}
						preportmessage->setByteStream(bytes);
						if(preportmessage!=NULL){
							if(!pComm->immediateSendMessage(preportmessage,pMessage->getMessageID())){
									//printf("send ack fail!\n");
							}else{
									//printf("send ack success!\n");
							}
							delete preportmessage;
						}	
						
				}
						break;
				
				case 0xa0://获取当前设备时间
				{
					long long  res = pcf8563Utc(readAllPcf8563Time()); 
					res = res *1000000;
					llrp_u8v_t bytes = llrp_u8v_t(11); 
					bytes.m_pValue[0] = 0xa1;  					
					bytes.m_pValue[1] = 0x00;           
					bytes.m_pValue[2] = 0x08;  
					bytes.m_pValue[3] = (res>>56)%256;  
					bytes.m_pValue[4] = (res>>48)%256;	
					bytes.m_pValue[5] = (res>>40)%256;  
					bytes.m_pValue[6] = (res>>32)%256;	
					bytes.m_pValue[7] = (res>>24)%256;  
					bytes.m_pValue[8] = (res>>16)%256;	
					bytes.m_pValue[9] = (res>>8)%256;  
					bytes.m_pValue[10] = res%256;						
					preportmessage->setByteStream(bytes);
					if(preportmessage!=NULL)
					{
						if(false == pComm->immediateSendMessage(preportmessage,pMessage->getMessageID()))
						{
								printf("send ack fail!\n");
						}
						delete preportmessage;
					}					
					break;
				}					
				
				
				case 0xa4://下发道闸机指令数据
				{
					printf("ContrlBanister\n");
					//unsigned char Contrlbanister = manuframe.DataBuf[0];
					//if(Contrlbanister == 0)//开启道闸
					//{
						//PC6 IO1
					
					ContrlBanister(Baister_EN);
					
					Delay_ms(500);
					
					ContrlBanister(!Baister_EN);
					//响应
					llrp_u8v_t bytes = llrp_u8v_t(3); 
					bytes.m_pValue[0] = 0x24;  					
					bytes.m_pValue[1] = 0x00;           
					bytes.m_pValue[2] = 0x00;  
					preportmessage->setByteStream(bytes);
					if(preportmessage!=NULL)
					{
						if(false == pComm->immediateSendMessage(preportmessage,pMessage->getMessageID()))
						{
								printf("send ack fail!\n");
						}
						delete preportmessage;
					}
					break;					
				}
				
				
				
				case 0xa5://查询设备节点配置信息
				{
					//1.从flash中获取节点信息(ID,Address);
					map<unsigned char,unsigned char> nodeInfos =  m_read_manage->GetNodeInfoFromFlash();//未实现
					//2.组响应帧
					int count = nodeInfos.size();
					llrp_u8v_t bytes = llrp_u8v_t(count * 2 + (count -1) + 3); 
					bytes.m_pValue[0] = 0x25;  					
					bytes.m_pValue[1] = 0x00;           
					bytes.m_pValue[2] = 0x00;         
					int i = 2;
					for (map<unsigned char,unsigned char>::iterator it = nodeInfos.begin();it!=nodeInfos.end();it++)
					{
						bytes.m_pValue[++i] = it->first;  					
						bytes.m_pValue[++i] = it->second;
						if ( i < count * 2 + (count -1) + 3 - 1)
						{
							bytes.m_pValue[++i] = 0x00;
						}
					}
					int len = count * 2 + (count -1);
					bytes.m_pValue[1] = (len & 0xFF00) >> 8;           
					bytes.m_pValue[2] = len & 0xFF;			
					preportmessage->setByteStream(bytes);
					if(preportmessage!=NULL)
					{
						if(false == pComm->immediateSendMessage(preportmessage,pMessage->getMessageID()))
						{
								printf("send ack fail!\n");
						}
						delete preportmessage;
					}
					break;
				}
				case 0xa6://设置从节点数量
				{
					unsigned char nodeCount = manuframe.DataBuf[0];
					bool res = m_read_manage->SetNodeCountToFlash(nodeCount);//未实现
					llrp_u8v_t bytes = llrp_u8v_t(4); 
					bytes.m_pValue[0] = 0x26;  					
					bytes.m_pValue[1] = 0x00;           
					bytes.m_pValue[2] = 0x01;  
					bytes.m_pValue[3] = res ? 0x00 : 0x01;
					preportmessage->setByteStream(bytes);
					if(preportmessage!=NULL)
					{
						if(false == pComm->immediateSendMessage(preportmessage,pMessage->getMessageID()))
						{
								printf("send ack fail!\n");
						}
						delete preportmessage;
					}
					break;
				}
				
				case 0xa7://设置节点信息(ID,Address)
				{
					//1.从buff中获取节点信息.
					map<unsigned char,unsigned char> nodeInfo;
					unsigned short dataLen = ((manuframe.Datalen_H << 8) & 0xFF00) | (manuframe.Datalen_L);
					int i = -1;
					while (i < dataLen-1)
					{
							++i;
							if (manuframe.DataBuf[i] != 0x00)
							{
									nodeInfo.insert(pair<unsigned char,unsigned char>(manuframe.DataBuf[i],manuframe.DataBuf[++i]));
							}
					}
					//2.向flash中写入节点信息
					bool res = m_read_manage->SetNodeInfoToFlash(nodeInfo);//未实现
					//3.发送响应
					llrp_u8v_t bytes = llrp_u8v_t(4); 
					bytes.m_pValue[0] = 0x27;  					
					bytes.m_pValue[1] = 0x00;           
					bytes.m_pValue[2] = 0x01;  
					printf("res : %d\n",res);
					bytes.m_pValue[3] = res ? 0x00 : 0x01;
					preportmessage->setByteStream(bytes);
					if(preportmessage!=NULL)
					{
						if(false == pComm->immediateSendMessage(preportmessage,pMessage->getMessageID()))
						{
								printf("send ack fail!\n");
						}
						delete preportmessage;
					}
					break;
				}
				
				case 0xa8://查询节点的数量
				{
					int nodeCount = m_read_manage->GetNodeCountFromFlash();//未实现
					llrp_u8v_t bytes = llrp_u8v_t(4); 
					bytes.m_pValue[0] = 0x28;  					
					bytes.m_pValue[1] = 0x00;           
					bytes.m_pValue[2] = 0x01;  
					bytes.m_pValue[3] = nodeCount;
					preportmessage->setByteStream(bytes);
					if(preportmessage!=NULL)
					{
						if(false == pComm->immediateSendMessage(preportmessage,pMessage->getMessageID()))
						{
								printf("send ack fail!\n");
						}
						delete preportmessage;
					}
					break;
				}
				
				case 0xa9:// 查询从节点实际配置信息(从节点上线情况)
				{
					//1.从buff中获取节点信息. 
					int num =  manuframe.DataBuf[0];//配置几号节点 获取主机flash存储的信息
					int mySlaveAddr = m_read_manage->salve_dev[num];				
					bool res = m_read_manage->GetSlave_Addr(mySlaveAddr);
					//3.发送响应
					llrp_u8v_t bytes = llrp_u8v_t(4); 
					bytes.m_pValue[0] = 0x29;  					
					bytes.m_pValue[1] = 0x00;           
					bytes.m_pValue[2] = 0x01;  
					printf("res : %d\n",res);
					bytes.m_pValue[3] = res ? 0x00 : 0x01;
					preportmessage->setByteStream(bytes);
					if(preportmessage!=NULL)
					{
						if(false == pComm->immediateSendMessage(preportmessage,pMessage->getMessageID()))
						{
								printf("send ack fail!\n");
						}
						delete preportmessage;
					}			
					break;
				}	
				
				case 0xaa://设置从机节点的地址、序列号、型号、版本号
				{
					  //1.从buff中获取节点信息. 
						u8 Example_version[70]={0};
						//u8 Example_version[60]={"SN:BL1810303020|Type:BL-MR-200 |Version:V3.2.9"};
						if(manuframe.DataBuf == NULL) return;
						//printf("slave message:%s\n",manuframe.DataBuf);
						int num = manuframe.Datalen_H<<8|manuframe.Datalen_L;
						printf("\nstrlen :%d\n",num);
						memcpy(Example_version,manuframe.DataBuf,num);
						*(Example_version + num)= 0;//补上\0
						printf("Slave_version:%s\n",Example_version);						
						bool res = m_read_manage->SetSlave_Message(0,Example_version,num);			
						//3.发送响应
						llrp_u8v_t bytes = llrp_u8v_t(4); 
						bytes.m_pValue[0] = 0x2a;  					
						bytes.m_pValue[1] = 0x00;           
						bytes.m_pValue[2] = 0x01;  
						printf("res : %d\n",res);
						bytes.m_pValue[3] = res ? 0x00 : 0x01;
						preportmessage->setByteStream(bytes);
						if(preportmessage!=NULL)
						{
							if(false == pComm->immediateSendMessage(preportmessage,pMessage->getMessageID()))
							{
									printf("send ack fail!\n");
							}
							delete preportmessage;
						}			
						break;			
				}					
				
				case 0xab://主节点的型号、序列号和版本号查询
				{
					u8 versionnum[60];
					int numL = 45;
					printf("numl :%d",numL);					
					m_read_manage->GetDerviceVersion(versionnum,numL);
					//3.发送响应
					llrp_u8v_t bytes = llrp_u8v_t(3+numL); 
					bytes.m_pValue[0] = 0x2b;  					
					bytes.m_pValue[1] = numL/256;           
					bytes.m_pValue[2] = numL%256;  
					memcpy(&bytes.m_pValue[3],versionnum,numL);
					preportmessage->setByteStream(bytes);
					if(preportmessage!=NULL)
					{
						if(false == pComm->immediateSendMessage(preportmessage,pMessage->getMessageID()))
						{
								printf("send ack fail!\n");
						}
						delete preportmessage;
					}
					break;
				}			
	
				case 0xac://从节点节点的型号、序列号和版本号查询
				{
          //char versionnum[] = "Address:23| SN:BL1810303020|Type:BL-SR-200|Version:V3.1.1";
					unsigned char versionnum[57] = {0};
					m_read_manage->GetSlave_Message(0,versionnum,56);	

					int numL = sizeof(versionnum)/sizeof(char)-1;
					printf("numl :%d",numL);
					//3.发送响应
					llrp_u8v_t bytes = llrp_u8v_t(3+numL); 
					bytes.m_pValue[0] = 0x2c;  					
					bytes.m_pValue[1] = numL/256;           
					bytes.m_pValue[2] = numL%256;  
					memcpy(&bytes.m_pValue[3],versionnum,numL);
					preportmessage->setByteStream(bytes);
					if(preportmessage!=NULL)
					{
						if(false == pComm->immediateSendMessage(preportmessage,pMessage->getMessageID()))
						{
								printf("send ack fail!\n");
						}
						delete preportmessage;
					}
					break;
				}	
				
				case 0xad://开始对消(针对单个节点)
				{
					unsigned char slave_id   = manuframe.DataBuf[0];//从节点ID
					unsigned char slave_addr = manuframe.DataBuf[1];//第二字节:从节点地址
					if(m_read_manage->salve_dev[slave_id] != slave_addr)
					{
						printf("slave_id != slave_addr\n");
					}	
					
			  	llrp_u8v_t bytes = llrp_u8v_t(14); 				
					bool res = m_read_manage->Config_Cancellation(slave_addr,&bytes.m_pValue[6]);
					//3.发送响应
					bytes.m_pValue[0] = 0x2d;  					
					bytes.m_pValue[1] = 0x00;           
					bytes.m_pValue[2] = 0x07;
		
					bytes.m_pValue[3] = slave_id; 
					bytes.m_pValue[4] = slave_addr;  					
					printf(" cancell res : %d\n",res);
					bytes.m_pValue[5] = res ? 0x00 : 0x01;
					
					preportmessage->setByteStream(bytes);
					if(preportmessage!=NULL)
					{
						if(false == pComm->immediateSendMessage(preportmessage,pMessage->getMessageID()))
						{
								printf("send ack fail!\n");
						}
						delete preportmessage;
					}
					break;
				}				
			
				case 0xae://配置节点的频点
				{
					unsigned char slave_id   = manuframe.DataBuf[0];//从节点ID
					unsigned char slave_addr = manuframe.DataBuf[1];//第二字节:从节点地址
					unsigned char slave_Fre = manuframe.DataBuf[2];//第三字节:频点(取值1-20)
					if(m_read_manage->salve_dev[slave_id] != slave_addr)
					{
						printf("slave_id != slave_addr\n");
					}
					
					bool res = m_read_manage->Config_Frequency(slave_addr,slave_Fre);
					//3.发送响应
					llrp_u8v_t bytes = llrp_u8v_t(6); 
					bytes.m_pValue[0] = 0x2e;  					
					bytes.m_pValue[1] = 0x00;           
					bytes.m_pValue[2] = 0x03;  
					
					bytes.m_pValue[3] = slave_id; 
					bytes.m_pValue[4] = slave_addr;  					
					printf("res : %d\n",res);
					bytes.m_pValue[5] = res ? 0x00 : 0x01;
					preportmessage->setByteStream(bytes);
					if(preportmessage!=NULL)
					{
						if(false == pComm->immediateSendMessage(preportmessage,pMessage->getMessageID()))
						{
								printf("send ack fail!\n");
						}
						delete preportmessage;
					}
					break;
				}

				case 0xaf://配置节点的功率
				{
					unsigned char slave_id   = manuframe.DataBuf[0];//从节点ID
					unsigned char slave_addr = manuframe.DataBuf[1];//第二字节:从节点地址
					unsigned short int  slave_Power = manuframe.DataBuf[2]<<8|manuframe.DataBuf[3];//第三-第四字节:射频功率
					if(m_read_manage->salve_dev[slave_id] != slave_addr)
					{
						printf("slave_id != slave_addr\n");
					}
					
					bool res = m_read_manage->ConfigRf_Power(slave_addr,slave_Power);
					//3.发送响应
					llrp_u8v_t bytes = llrp_u8v_t(6); 
					bytes.m_pValue[0] = 0x2f;  					
					bytes.m_pValue[1] = 0x00;           
					bytes.m_pValue[2] = 0x03;  
					
					bytes.m_pValue[3] = slave_id; 
					bytes.m_pValue[4] = slave_addr;  					
					printf("res : %d\n",res);
					bytes.m_pValue[5] = res ? 0x00 : 0x01;
					preportmessage->setByteStream(bytes);
					if(preportmessage!=NULL)
					{
						if(false == pComm->immediateSendMessage(preportmessage,pMessage->getMessageID()))
						{
								printf("send ack fail!\n");
						}
						delete preportmessage;
					}
					break;
				}

				case 0xb0://配置节点的载波状态
				{
					unsigned char slave_id      =  manuframe.DataBuf[0];//从节点ID
					unsigned char slave_addr    =  manuframe.DataBuf[1];//第二字节:从节点地址
					unsigned char slave_Carrier =  manuframe.DataBuf[2];//第三字节:从节点地址					
					if(m_read_manage->salve_dev[slave_id] != slave_addr)
					{
						printf("slave_id != slave_addr\n");
					}					
					
					bool res = m_read_manage->Config_Carrier(slave_addr,slave_Carrier);
					//3.发送响应
					llrp_u8v_t bytes = llrp_u8v_t(6); 
					bytes.m_pValue[0] = 0x30;  					
					bytes.m_pValue[1] = 0x00;           
					bytes.m_pValue[2] = 0x03;  
					
					bytes.m_pValue[3] = slave_id; 
					bytes.m_pValue[4] = slave_addr;  					
					printf("res : %d\n",res);
					bytes.m_pValue[5] = res ? 0x00 : 0x01;
					preportmessage->setByteStream(bytes);
					if(preportmessage!=NULL)
					{
						if(false == pComm->immediateSendMessage(preportmessage,pMessage->getMessageID()))
						{
								printf("send ack fail!\n");
						}
						delete preportmessage;
					}
					break;
				}
	
				case 0xb1://查询节点射频信息 全部
				{
					u8 sl_num = m_read_manage->slave_num;//节点数量
					unsigned char slave1_Cancel[8] = {0};//对消结果
					u8 slave1_rffre = 0;	//频点结果
					u16 slave1_rfpower = 0;		//1.1查询从节点的功率值
					//3.发送响应
					llrp_u8v_t bytes = llrp_u8v_t(18); 
							
					for(u8 i = 0 ;i <= sl_num;i++) 
					{		
						m_read_manage->GetSlave_Cancellation(m_read_manage->salve_dev[i],&bytes.m_pValue[5]);
						//载波状态
						m_read_manage->GetSlaveRf_Power(m_read_manage->salve_dev[i],&slave1_rfpower);				
	        	//2.1查询频点值
		        m_read_manage->GetSlave_Frequency(m_read_manage->salve_dev[i],&slave1_rffre);	
						
				
						bytes.m_pValue[0] = 0x31;  					
						bytes.m_pValue[1] = 0x00;           
						bytes.m_pValue[2] = 0x03;  
						
						bytes.m_pValue[3] = i; 
						bytes.m_pValue[4] = m_read_manage->salve_dev[i];  					
						//中间8个是对消值		
				  	bytes.m_pValue[13] = slave1_rffre;
				  	bytes.m_pValue[14] = 0;		//载波状态
					  bytes.m_pValue[15] = (slave1_rfpower>>8)&0xff;		//射频功率
				  	bytes.m_pValue[16] =  slave1_rfpower&0xff;		//射频功率						
				  	preportmessage->setByteStream(bytes);	
						if(preportmessage!=NULL)
						{
							if(false == pComm->immediateSendMessage(preportmessage,pMessage->getMessageID()))
							{
									printf("send ack fail!\n");
							}
							//delete preportmessage;						
						}		
					}	
					delete preportmessage;											
					break;
				}

				case 0xb2://配置读卡(针对单节点)
				{
					unsigned char slave_id      =  manuframe.DataBuf[0];//从节点ID
					unsigned char slave_addr    =  manuframe.DataBuf[1];//第二字节:从节点地址
					unsigned char single_mode    =  manuframe.DataBuf[2];//
					bool res = m_read_manage->select_dev_Read(slave_id,single_mode);
					//为手持机新加一默认的读卡规则。
					g_pMainApplication->m_pOperationProcess->getOpSpecManager()->initDefaultSelectSpec();
		      g_pMainApplication->m_pOperationProcess->getOpSpecManager()->addSelectSpec(g_pMainApplication->m_pOperationProcess->getOpSpecManager()->m_pCurrentSelectSpec,false);		
					OperationSpec_Manager *opManger = g_pMainApplication->m_pOperationProcess->getOpSpecManager();
					if(single_mode == 1)
					{	
						opManger->startSelectSpec(3001);						
					}
					else{
						opManger->stopSelectSpec(3001);
					}			
					//3.发送响应 
					llrp_u8v_t bytes = llrp_u8v_t(4); 
					bytes.m_pValue[0] = 0x32;  					
					bytes.m_pValue[1] = 0x00;           
					bytes.m_pValue[2] = 0x01;  					
					printf("res : %d\n",res);
					bytes.m_pValue[3] = res ? 0x00 : 0x01;
					preportmessage->setByteStream(bytes);
					if(preportmessage!=NULL)
					{
						if(false == pComm->immediateSendMessage(preportmessage,pMessage->getMessageID()))
						{
								printf("send ack fail!\n");
						}
						delete preportmessage;
					}
					break;
				}				
				case 0xb3://设置主节点的序列号,型号,版本号:
				{
						u8 Example_version[60]={0};
						//u8 Example_version[60]={"SN:BL1810303020|Type:BL-MR-200 |Version:V3.2.9"};
						printf("slave message:%s\n",manuframe.DataBuf);
						int num = strlen((const char *)manuframe.DataBuf);
						printf("strlen :%d\n",num);
						memcpy(Example_version,manuframe.DataBuf,num);
						bool res = m_read_manage->SetDerviceVersion(Example_version,num);
						//3.发送响应 
						llrp_u8v_t bytes = llrp_u8v_t(4); 
						bytes.m_pValue[0] = 0x33;  					
						bytes.m_pValue[1] = 0x00;           
						bytes.m_pValue[2] = 0x01;  					
						printf("res : %d\n",res);
						bytes.m_pValue[3] = res ? 0x00 : 0x01;
						preportmessage->setByteStream(bytes);
						if(preportmessage!=NULL)
						{
							if(false == pComm->immediateSendMessage(preportmessage,pMessage->getMessageID()))
							{
									printf("send ack fail!\n");
							}
							delete preportmessage;
						}
						break;						
				}
								
				case 0xb4://设置灯光控制模式
				{
					u8 sl_num = m_read_manage->slave_num;//节点数量
					u8 led_mode_set = manuframe.DataBuf[0];
					u8 resualt = 0;
					for(u8 i = 0 ;i <= sl_num;i++) 
					{//灯光模式
						resualt = m_read_manage->Config_LedMode(m_read_manage->salve_dev[i],led_mode_set);
						resualt += resualt;
					}
					//3.发送响应
					bool res = 0;						
					if(resualt == sl_num+1)//全部配置成功应该为节点数量+1(主机自身)
					{
						res = 0;//成功
					}else{
						res = 1;//失败
					}
					//3.发送响应
					llrp_u8v_t bytes = llrp_u8v_t(4); 
					bytes.m_pValue[0] = 0x33;  					
					bytes.m_pValue[1] = 0x00;           
					bytes.m_pValue[2] = 0x01;  					
					printf("res : %d\n",res);
					bytes.m_pValue[3] = res ? 0x00 : 0x01;
					preportmessage->setByteStream(bytes);
					if(preportmessage!=NULL)
					{
						if(false == pComm->immediateSendMessage(preportmessage,pMessage->getMessageID()))
						{
								printf("send ack fail!\n");
						}
						delete preportmessage;
					}
					break;
				}
							
				case 0xb5://灯光模式查询
				{
					//3.发送响应
					llrp_u8v_t bytes = llrp_u8v_t(4); 
					bytes.m_pValue[0] = 0x34;  					
					bytes.m_pValue[1] = 0x00;           
					bytes.m_pValue[2] = 0x01;  					
					printf("res : %d\n",m_read_manage->led_mode);
					bytes.m_pValue[3] = 0;
					preportmessage->setByteStream(bytes);
					if(preportmessage!=NULL)
					{
						if(false == pComm->immediateSendMessage(preportmessage,pMessage->getMessageID()))
						{
								printf("send ack fail!\n");
						}
						delete preportmessage;
					}
					break;				
				}
				
				case 0xb6://雷达信息查询的检测查询
				{
					u8 sl_num = m_read_manage->slave_num;//节点数量
					u16 radar_distance = 0;		//1.1查询从节点的功率值
					//3.发送响应
					llrp_u8v_t bytes = llrp_u8v_t(6); 						
					for(u8 i = 0 ;i <= sl_num;i++) 
					{				
	        	//2.1雷达信息查询的检测查询
		        m_read_manage->GetSlaveRadar(m_read_manage->salve_dev[i],&radar_distance);	
							
						bytes.m_pValue[0] = 0x36;  					
						bytes.m_pValue[1] = 0x00;           
						bytes.m_pValue[2] = 0x03;
						bytes.m_pValue[3] = i;//当前节点ID
					  bytes.m_pValue[4] = (radar_distance>>8)&0xff;		//射频功率
				  	bytes.m_pValue[5] =  radar_distance&0xff;		//射频功率						
				  	preportmessage->setByteStream(bytes);	
						if(preportmessage!=NULL)
						{				
							//printf("pMessage->getMessageID() :%d\n",pMessage->getMessageID());
							if(false == pComm->immediateSendMessage(preportmessage,pMessage->getMessageID()))
							{
									printf("send ack fail!\n");
							}
							//delete preportmessage;						
						}		
					}	
					delete preportmessage;											
					break;				
				}
				case 0xb7://一键对消
				{
					u8 sl_num = m_read_manage->slave_num;//节点数量				
					bool res = 0;		
			  	llrp_u8v_t bytes = llrp_u8v_t(14); 	
					for(u8 i = 0 ;i <= sl_num;i++)//按节点数量自动对消
					{	
							res = m_read_manage->Config_Cancellation(m_read_manage->salve_dev[i],&bytes.m_pValue[6]);
							//3.发送响应
							bytes.m_pValue[0] = 0x2d;  					
							bytes.m_pValue[1] = 0x00;           
							bytes.m_pValue[2] = 0x07;
				
							bytes.m_pValue[3] = i; 
							bytes.m_pValue[4] = m_read_manage->salve_dev[i];  					
							printf("cancell res : %d\n",res);
							bytes.m_pValue[5] = res ? 0x00 : 0x01;
							
							preportmessage->setByteStream(bytes);
							if(preportmessage!=NULL)
							{
								if(false == pComm->immediateSendMessage(preportmessage,pMessage->getMessageID()))
								{
										printf("send ack fail!\n");
								}
							}						
					}
					delete preportmessage;
					
					break;
				}
					
				case 0xb8://灯光的在位限制门槛
				{
					//1.接收下发的参数
					u8 LedThreshold_set = manuframe.DataBuf[0];					
					//2.配置参数
					u8 sl_num = m_read_manage->slave_num;//节点数量		
					u8 resualt = 0;
					for(u8 i = 0 ;i <= sl_num;i++) 
					{//灯光模式的在位检测门槛
						resualt = m_read_manage->Config_LedThreshold(m_read_manage->salve_dev[i],LedThreshold_set);
						resualt += resualt;//记录返回值的和全部配置成应该为节点数量
					}	
					
					//3.发送响应
					bool res = 0;						
					if(resualt == sl_num+1)//全部配置成功应该为节点数量+1(主机自身)
					{
						res = 0;//成功
					}else{
						res = 1;//失败
					}
	
			  	llrp_u8v_t bytes = llrp_u8v_t(4); 						
					bytes.m_pValue[0] = 0x38;  					
					bytes.m_pValue[1] = 0x00;           
					bytes.m_pValue[2] = 0x01;				
					printf("cancell res : %d\n",res);
					bytes.m_pValue[3] = res ? 0x00 : 0x01;			
					preportmessage->setByteStream(bytes);
					if(preportmessage!=NULL)
					{
						if(false == pComm->immediateSendMessage(preportmessage,pMessage->getMessageID()))
						{
								printf("send ack fail!\n");
						}
					}						
					break;
				}
				
						
				default: //各个模块处理自定义消息
				{
					delete preportmessage;//删除内存泄漏
					if(m_pRfManager->dealMessage(pMessage,pComm)<0){
						if(m_pSm2Certification->dealMfeMessage(pMessage,pComm)){
							
						}
					}
						if(m_pVersionManager->dealMfeMessage(pMessage,pComm)<0){
						
						}
				}
						break;
				}//end of switch



		}
				break;
    default://处理常规消息
				if(this->dealGeneralMessage(pMessage,pComm)<0){
					if(m_pOperationProcess->dealMessage(pMessage,pComm)<0){
						if(m_pVersionManager->dealMessage(pMessage,pComm)<0){
							
								if(m_pSm2Certification->dealMessage(pMessage,pComm)<0){
									if(m_pParamManager->dealMessage(pMessage,pComm)<0){
								}
							}
							
						}
					}
				}
				break;
    }
}

void Main_Application::run(){


		m_pSerialComm->run();
		//含有立即触发、开始标签选择规则、读卡流程
	  //标签信息上报
		m_pOperationProcess->run(); 
	
	  m_read_manage->run();
		//////////////////////////////////////////////////////
		if(m_pSerialComm->getRecMessage()!=NULL){
			printf("recv some message!\n");
			//HbFrame_Operation::printMessage(m_SerialComm.getRecMessage());
			//
			dealRecvMessages(m_pSerialComm->getRecMessage(),m_pSerialComm);
			m_pSerialComm->deleteRecMessage(); //删除消息本身
		}
		
		
		//将读标签报告发往各通信链路
    OperationReport_Manager *preportmanager = m_pOperationProcess->getOpReportManager();
    if(preportmanager->getSelectAccessReportsSize()>0){

        CTagSelectAccessReport *preport = preportmanager->frontSelectAccessReport();

        //HbFrame_Operation::printMessage(preport);

				if(m_pSerialComm->sendMessage(preport)==true){
						//printf("send success...............................\n");
				}else{
					
				}
        //删除当前的报告
        preportmanager->popSelectAccessReport();
        delete preport;
    }	
}

