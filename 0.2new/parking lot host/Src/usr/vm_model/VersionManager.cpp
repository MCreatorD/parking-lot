/*
 * VersionManager.cpp
 *
 *  Created on: 2016-5-13
 *      Author: root
 */

#include <string>
#include <stdio.h>

#include <stdlib.h>

#include "VersionManager.h"
#include "main_application.h"
#include "lowpower.h"
#include "read_manage.h"
VersionManager::VersionManager() {
	// TODO Auto-generated constructor stub
    isUpdateRunning = false;
}

VersionManager::~VersionManager() {
	// TODO Auto -generated destructor stub
}

llrp_u8v_t VersionManager::getSecSerial(){
//	llrp_u8v_t serialnr = llrp_u8v_t(0);
//	STRUCT_M2SEC_FRAME *pframe = NULL;
//	pframe = MCUToSecureComm::genSecSerialRequestFrame();
//	//发送配置
//	printf("Get Sec serial nr frame is :");
//	MCUToSecureComm::printfSecFrame(pframe);
//	if(g_pMainApplication->m_pM2SecComm->sendFrameToSecure(pframe)){
//			printf("RfOper:send get sec chip version frame success!\n");
//	}else{
//			printf("RfOper:send get sec chip version frame fail!\n");
//			g_pMainApplication->m_pM2SecComm->removeFrame(pframe);
//			pframe = NULL;
//			return serialnr;
//	}
//	g_pMainApplication->m_pM2SecComm->removeFrame(pframe);
//	pframe = NULL;

//	if(g_pMainApplication->m_pM2SecComm->waitSecReadyForComm()<0){
//			printf("RfOper:wait get sec chip version frame overtime!\n");
//			return serialnr;
//	}

//	pframe = g_pMainApplication->m_pM2SecComm->getFrameFromSecure(M2SEC_SECVERSIONACK_FRAME);

//	if(pframe==NULL){
//			printf("pframe is null!\n");
//			return serialnr;
//	}

//	if((pframe->Type&0xF0)==0x80){
//			printf("pframe is error pframe!\n");
//			return serialnr;
//	}
//	serialnr = llrp_u8v_t(20);//序列号目前长12字节，ASCII
//	int posi = 0;
//	serialnr.m_pValue[posi++] = pframe->DataBuf[2];
//	serialnr.m_pValue[posi++] = pframe->DataBuf[3];
//	unsigned int t = pframe->DataBuf[4];
//	char a[10] = {0x00};
//	sprintf(a,"%02d",t);
//	serialnr.m_pValue[posi++] = a[0];
//	serialnr.m_pValue[posi++] = a[1];
//	
//	t = pframe->DataBuf[5];
//	t = t<<8|pframe->DataBuf[6];
//	sprintf(a,"%03d",t);
//	serialnr.m_pValue[posi++] = a[0];
//	serialnr.m_pValue[posi++] = a[1];
//	serialnr.m_pValue[posi++] = a[2];
//	
//	t = pframe->DataBuf[7];
//	t = t<<8|pframe->DataBuf[8];
//	t = t<<8|pframe->DataBuf[9];
//	sprintf(a,"%05d",t);
//	serialnr.m_pValue[posi++] = a[0];
//	serialnr.m_pValue[posi++] = a[1];
//	serialnr.m_pValue[posi++] = a[2];
//	serialnr.m_pValue[posi++] = a[3];
//	serialnr.m_pValue[posi++] = a[4];
//	
//	serialnr.m_pValue[posi++] = 0x00;
//	//memcpy(serialnr.m_pValue,pframe->DataBuf+2,8);
//	return serialnr;
}

/**
 * @brief VersionManager::dealVMMessage
 * @param pMessage，待处理的消息
 * @param commID，消息所属的通信链路ID号
 * @return
 * 处理版本管理消息，返回值为0表示已处理，-1表示未处理。
 */
int VersionManager::dealMessage(CMessage *pMessage,Base_Comm *pComm){
    llrp_u32_t messageid = pMessage->getMessageID();
    switch(pMessage->m_pType->m_TypeNum){
    case SetVersion:
        break;
    case ActiveVersion:
        break;
    case GetVersion: //获取版本号
    {
        CGetVersionAck *pack = (CGetVersionAck*)HbFrame_Operation::genMessage(GetVersionAck,0);
        CStatus *pstatus = (CStatus*)HbFrame_Operation::genParam(Status,0,NULL);
        CGetVersion *pgetversion = (CGetVersion*)pMessage;
        switch(pgetversion->getVerType()){
        case GetVersionVerType_READER_BOOT_VER:
        {
            //llrp_u64_t ver = g_pMainApplication->getFPGAVersion();
            llrp_u64_t ver = g_pMainApplication->getOpProcess()->getOpExecute()->getRfOper()->getFPGAVersion();
						if(ver!=0){
                CVersionInfo *pverinfo = (CVersionInfo*)HbFrame_Operation::genParam(VersionInfo,0,NULL);

                llrp_u8v_t verdata(7); //FPGA版本号是7个字节
                llrp_u8v_t tempdata(7);
                memcpy(tempdata.m_pValue,(unsigned char *)&ver,7);
                for(int i=0;i<7;i++){
                    verdata.m_pValue[i] = tempdata.m_pValue[6-i];
                }
                pverinfo->setVersionData(verdata);
                pverinfo->setUsedOrSpare(VersionInfoUsedOrSpare_PRIMARY_USE);
                pverinfo->setSetUse(VersionInfoSetUse_ACTIVE);
                pverinfo->setHasRun(VersionInfoHasRun_RUN);
                pverinfo->setCanRun(VersionInfoCanRun_CAN);

                char *verdesbuf = new char[16];
                memset(verdesbuf,0x00,16);
                memcpy(verdesbuf,verdata.m_pValue,7);
                printf("verdesbuf is %s\n",verdesbuf);
                llrp_utf8v_t des(strlen(verdesbuf)+1);
                memcpy(des.m_pValue,verdesbuf,strlen(verdesbuf)+1);

                pverinfo->setVerDescInfo(des);
                HbFrame_Operation::addParamToMessage(pverinfo,(CGetVersionAck*)pack);
                ((CStatus*)pstatus)->setStatusCode(StatusCode_M_Success);
            }else{
                ((CStatus*)pstatus)->setStatusCode(StatusCode_R_DeviceError);
            }
        }
            break;
        case GetVersionVerType_READER_SYSTEM_VER:
        {
            CVersionInfo *pverinfo = (CVersionInfo*)HbFrame_Operation::genParam(VersionInfo,0,NULL);
            string verstr = APP_VERSION_STR;

            char *ver = (char *)verstr.c_str();
            llrp_u8v_t data(strlen(ver)+1);
            memcpy(data.m_pValue,ver,strlen(ver)+1);
            pverinfo->setVersionData(data);
            pverinfo->setUsedOrSpare(VersionInfoUsedOrSpare_PRIMARY_USE);
            pverinfo->setSetUse(VersionInfoSetUse_ACTIVE);
            pverinfo->setHasRun(VersionInfoHasRun_RUN);
            pverinfo->setCanRun(VersionInfoCanRun_CAN);
            llrp_utf8v_t des(strlen(ver)+1);
            memcpy(des.m_pValue,ver,strlen(ver)+1);
            pverinfo->setVerDescInfo(des);
            HbFrame_Operation::addParamToMessage(pverinfo,(CGetVersionAck*)pack);
            ((CStatus*)pstatus)->setStatusCode(StatusCode_M_Success);
        }
            break;
        case GetVersionVerType_SECURITY_MODULE_SYSTEM_VER:
       {
            STRUCT_M2SEC_FRAME *pframe = NULL;
            pframe = MCUToSecureComm::genSecVersionRequestFrame();
            //发送配置帧
            printf("Get Sec Version frame is :");
            MCUToSecureComm::printfSecFrame(pframe);
//            if(g_pMainApplication->m_pM2SecComm->sendFrameToSecure(pframe)){
//                printf("VersionManager:send get sec version frame success!\n");
//            }else{
//                printf("VersionManager:send get sec version frame fail!\n");
//                g_pMainApplication->m_pM2SecComm->removeFrame(pframe);
//                pframe = NULL;
//                ((CStatus*)pstatus)->setStatusCode(StatusCode_M_UnsupportedMessage);
//                break;
//            }
//            g_pMainApplication->m_pM2SecComm->removeFrame(pframe);
//            pframe = NULL;

//            if(g_pMainApplication->m_pM2SecComm->waitSecReadyForComm()<0){
//                printf("VersionManager:wait get sec version frame overtime!\n");
//                break;
//            }

//            pframe = g_pMainApplication->m_pM2SecComm->getFrameFromSecure(M2SEC_SECVERSIONACK_FRAME);
//            if(pframe==NULL){
//                printf("pframe is null!\n");
//                ((CStatus*)pstatus)->setStatusCode(StatusCode_M_UnsupportedMessage);
//                break;
//            }
            //MCUToSecureComm::printfSecFrame(pframe);
            if((pframe->Type&0xF0)==0x80){
                printf("pframe is error pframe!\n");
                ((CStatus*)pstatus)->setStatusCode(StatusCode_M_UnsupportedMessage);
                break;
            }

            CVersionInfo *pverinfo = (CVersionInfo*)HbFrame_Operation::genParam(VersionInfo,0,NULL);
            char ver[6] = {0x00};
            memcpy(ver,pframe->DataBuf+2,4);
            memcpy(ver+4,pframe->DataBuf+8,2);
            llrp_u8v_t data(strlen(ver)+1);
            memcpy(data.m_pValue,ver,strlen(ver)+1);
            pverinfo->setVersionData(data);
            pverinfo->setUsedOrSpare(VersionInfoUsedOrSpare_PRIMARY_USE);
            pverinfo->setSetUse(VersionInfoSetUse_ACTIVE);
            pverinfo->setHasRun(VersionInfoHasRun_RUN);
            pverinfo->setCanRun(VersionInfoCanRun_CAN);

            char hardwareversion[2];
            char controlchipbootversion[2];
            char controlchipuserprogramversion[2];
            memcpy(hardwareversion,pframe->DataBuf+2,2);
            memcpy(controlchipbootversion,pframe->DataBuf+4,2);
            memcpy(controlchipuserprogramversion,pframe->DataBuf+8,2);
            char *verdesbuf = new char[1024];
            sprintf(verdesbuf,"HardWareVersion:%02x%02x ControlChipBootVersion:%02x%02x ControlChipUserProgramVersion:%02x%02x",hardwareversion[0],hardwareversion[1],controlchipbootversion[0],controlchipbootversion[1],controlchipuserprogramversion[0],controlchipuserprogramversion[1]);
            llrp_utf8v_t des(strlen(verdesbuf)+1);
            memcpy(des.m_pValue,verdesbuf,strlen(verdesbuf)+1);
            pverinfo->setVerDescInfo(des);
            HbFrame_Operation::addParamToMessage(pverinfo,(CGetVersionAck*)pack);
            ((CStatus*)pstatus)->setStatusCode(StatusCode_M_Success);
        }

            break;
        case GetVersionVerType_SECURITY_CHIP_SYSTEM_VER:
		{
            STRUCT_M2SEC_FRAME *pframe = NULL;
            pframe = MCUToSecureComm::genSecVersionRequestFrame();
            //发送配置帧
            printf("Get Sec Chip Version frame is :");
            //MCUToSecureComm::printfSecFrame(pframe);
//            if(g_pMainApplication->m_pM2SecComm->sendFrameToSecure(pframe)){
//                printf("RfOper:send get sec chip version frame success!\n");
//            }else{
//                printf("RfOper:send get sec chip version frame fail!\n");
//                g_pMainApplication->m_pM2SecComm->removeFrame(pframe);
//                pframe = NULL;
//                ((CStatus*)pstatus)->setStatusCode(StatusCode_M_UnsupportedMessage);
//                break;
//            }
//            g_pMainApplication->m_pM2SecComm->removeFrame(pframe);
//            pframe = NULL;

//            if(g_pMainApplication->m_pM2SecComm->waitSecReadyForComm()<0){
//                printf("RfOper:wait get sec chip version frame overtime!\n");
//                break;
//            }

//            pframe = g_pMainApplication->m_pM2SecComm->getFrameFromSecure(M2SEC_SECVERSIONACK_FRAME);

            if(pframe==NULL){
                printf("pframe is null!\n");
                ((CStatus*)pstatus)->setStatusCode(StatusCode_M_UnsupportedMessage);
                break;
            }

            if((pframe->Type&0xF0)==0x80){
                printf("pframe is error pframe!\n");
                ((CStatus*)pstatus)->setStatusCode(StatusCode_M_UnsupportedMessage);
                break;
            }

            CVersionInfo *pverinfo = (CVersionInfo*)HbFrame_Operation::genParam(VersionInfo,0,NULL);
            char ver[6] = {0x00};
            memcpy(ver,pframe->DataBuf+6,2);
            memcpy(ver+2,pframe->DataBuf+10,4);
            llrp_u8v_t data(strlen(ver)+1);
            memcpy(data.m_pValue,ver,strlen(ver)+1);
            pverinfo->setVersionData(data);
            pverinfo->setUsedOrSpare(VersionInfoUsedOrSpare_PRIMARY_USE);
            pverinfo->setSetUse(VersionInfoSetUse_ACTIVE);
            pverinfo->setHasRun(VersionInfoHasRun_RUN);
            pverinfo->setCanRun(VersionInfoCanRun_CAN);

            char secretbootversion[2];
            char secretoneuserprogramversion[2];
            char secrettwouserprogramversion[2];
            memcpy(secretbootversion,pframe->DataBuf+6,2);
            memcpy(secretoneuserprogramversion,pframe->DataBuf+10,2);
            memcpy(secrettwouserprogramversion,pframe->DataBuf+12,2);
            char *verdesbuf = new char[1024];
            sprintf(verdesbuf,"SecretBootVersion:%02x%02x SecretOneUserProgramVersion:%02x%02x SecretTwoUserProgramVersion:%02x%02x",secretbootversion[0],secretbootversion[1],secretoneuserprogramversion[0],secretoneuserprogramversion[1],secrettwouserprogramversion[0],secrettwouserprogramversion[1]);
            llrp_utf8v_t des(strlen(verdesbuf)+1);
            memcpy(des.m_pValue,verdesbuf,strlen(verdesbuf)+1);

            pverinfo->setVerDescInfo(des);
            HbFrame_Operation::addParamToMessage(pverinfo,(CGetVersionAck*)pack);
            ((CStatus*)pstatus)->setStatusCode(StatusCode_M_Success);
        }
            break;
		}//end of switch

        HbFrame_Operation::addParamToMessage(pstatus,pack);
        if(!pComm->immediateSendMessage(pack,messageid)){
            printf("Send GetVersionAck fail!\n");
        }
        delete pack;
    }
        break;
    case UnActiveVersion:
        break;
    default: //默认返回未处理
        return -1;
    }
    return 0;
}

void VersionManager::run(){

}

int VersionManager::dealMfeMessage(CMessage *pMessage,Base_Comm *pComm){
	static uint32_t binlen = 0;
	static int nr = 0;
    //printf("dealMfeMessage........................!\n");
    llrp_u32_t messageid = pMessage->getMessageID();
	if(pMessage->m_pType->m_TypeNum!=ManufacturerCommand){
        return -1;
    }
    CManufacturerCommand *pcommd = (CManufacturerCommand*)pMessage;
    llrp_u8v_t bufs = pcommd->getByteStream();

//    printf("bytes is ");
//    for(int i=0;i<bufs.m_nValue;i++){
//        printf("0x%02x,",bufs.m_pValue[i]);
//    }
//    printf("\n");
	
    STRUCT_ManufacturerFrame manuframe;
    manuframe.OperID = bufs.m_pValue[0];
    manuframe.Datalen_H = bufs.m_pValue[1];
    manuframe.Datalen_L = bufs.m_pValue[2];
    manuframe.DataBuf = bufs.m_pValue+3;

    switch(manuframe.OperID){

    case 0xB9://自定义升级通知
    {
				m_UpdateType  = manuframe.DataBuf[0];  //保存升级类型 0x00,升级MCU程序,0x01,升级安全模块
				m_UpdateMCUID = manuframe.DataBuf[1]; //节点ID(0代表主机ID,其他代表从机ID)
				m_UpdateTotalPack = manuframe.DataBuf[2]<<8|manuframe.DataBuf[3]; //总包数
				printf("m_UpdateTye=%d,m_UpdateMCUID=%d,m_UpdateTotalPack=%d\n",m_UpdateType,m_UpdateMCUID,m_UpdateTotalPack);
				
				uint8_t res = 1;
				if(m_UpdateType == 0){//是单片机升级	
					if(m_UpdateMCUID == 0)
					{
						FlashSource = bin_start;//归还起始
						binlen = 0;
						res = 0;
					}
					else
					{
							res = g_pMainApplication->m_read_manage->UpdateslaveHandle(g_pMainApplication->m_read_manage->salve_dev[m_UpdateMCUID],m_UpdateTotalPack);
					  	res = !res;
					}			
				
				}
				else if(m_UpdateType==1){ //是安全模块升级
					m_UpdateSM.enterUpateState();
					res = 0;
				}
				
				CManufacturerReport *pack =  (CManufacturerReport *)ExtendHbFrame_Operation::genMessage(ManufacturerReport,0);

				llrp_u8v_t bytes = llrp_u8v_t(4);
				bytes.m_pValue[0] = 0x39;
				bytes.m_pValue[1] = 0x00; //长度
				bytes.m_pValue[2] = 0x01; //长度
        bytes.m_pValue[3] = res;  //表示已准备好升级  0x00 代表设备已准备好接收数据包,0x01代表设备未准备好.需重试.
        pack->setByteStream(bytes);
        if(pComm->immediateSendMessage(pack,messageid)){
            printf("send ack message success!\n");
        }else{
            printf("send ack message fail!\n");
        }
        delete pack;
    }
        break;
    case 0xBA: //接收下发的数据包进行升级操作
    {
				CManufacturerReport *pack =  (CManufacturerReport *)ExtendHbFrame_Operation::genMessage(ManufacturerReport,0);

				switch(m_UpdateType){
					case 0: //升级单片机程序
					{
						if(m_UpdateMCUID == 0)//升级主机
						{
								llrp_u8v_t bytes = llrp_u8v_t(6);
								bytes.m_pValue[0] = 0x3A;
								bytes.m_pValue[1] = 0x00; //长度
								bytes.m_pValue[2] = 0x03; //长度

								nr = manuframe.DataBuf[0]<<8|manuframe.DataBuf[1];      //包数
								int packlen = manuframe.DataBuf[2]<<8|manuframe.DataBuf[3]; //包长
								//printf("nr=%d,packlen=%d\n",nr,packlen);
								bytes.m_pValue[3] = nr>>8;
								bytes.m_pValue[4] = nr;
								
//								if(nr == 1||nr == m_UpdateTotalPack)
//								{
//									printf("bytes is ");
//									for(int i=0;i<packlen;i++){
//											printf("0x%02x,",manuframe.DataBuf[4+i]);
//									}
//									printf("\n");
//								}
							
								if(this->m_UpdateMcu.sendUpdateBlockToMcu(updatedev_hostmcu,manuframe.DataBuf+4,packlen)==false){
									printf("update block to host mcu fail!\n");
									bytes.m_pValue[5] = 0x01; //表示失败
								}else{
									printf("update blcok[%d] to host mcu success,block len is %d !\n",nr,packlen);
									bytes.m_pValue[5] = 0x00; //表示成功
								}
								binlen += packlen;//每包的实时len进行累加
//								if(m_UpdateTotalPack == nr)//接收到最后一包更新标志位
//								{
//									char *p= "host20181204V2.bin";
//									this->m_UpdateMcu.FLASH_Message(binlen,p,flash_Isok);
//									printf("update has get sucess \n");
//									SoftReset();
//								}	
								
								pack->setByteStream(bytes);	
						}else
						{
								llrp_u8v_t bytes = llrp_u8v_t(6);
								bytes.m_pValue[0] = 0x3A;
								bytes.m_pValue[1] = 0x00; //长度
								bytes.m_pValue[2] = 0x03; //长度

								nr = manuframe.DataBuf[0]<<8|manuframe.DataBuf[1];      //包数
								int packlen = manuframe.DataBuf[2]<<8|manuframe.DataBuf[3]; //包长
								printf("nr=%d,packlen=%d\n",nr,packlen);
//								if(nr == 1||nr == m_UpdateTotalPack)
//								{
//									printf("bytes is ");
//									for(int i=0;i<packlen;i++){
//											printf("0x%02x,",manuframe.DataBuf[4+i]);
//									}
//									printf("\n");
//								}						
						   UpdateslaveAcktypedef m_result = 	g_pMainApplication->m_read_manage->Updateslavepag(g_pMainApplication->m_read_manage->salve_dev[m_UpdateMCUID],nr,packlen,manuframe.DataBuf+4);
									
								bytes.m_pValue[3] = m_result.nr>>8;
								bytes.m_pValue[4] = m_result.nr;	

							
							if( m_result.result==1){
									printf("update block to host mcu fail!\n");
									bytes.m_pValue[5] = 0x01; //表示失败
								}else{
									printf("update blcok[%d] to host mcu success,block len is %d !\n",m_result.nr,packlen);
									bytes.m_pValue[5] = 0x00; //表示成功
								}
								binlen += packlen;//每包的实时len进行累加
							//升级其他的从机
							//m_UpdateMCUID 通过485升级其他从机的程序
								pack->setByteStream(bytes);	
						}
					}
						break;
					case 1://升级安全模块系统程序
					{
						llrp_u8v_t bytes = llrp_u8v_t(6);
						bytes.m_pValue[0] = 0x26;
						bytes.m_pValue[1] = 0x00; //长度
						bytes.m_pValue[2] = 0x03; //长度

						
						
						int nr = manuframe.DataBuf[0]<<8|manuframe.DataBuf[1];      //包数
						int packlen = manuframe.DataBuf[2]<<8|manuframe.DataBuf[3]; //包长
						//printf("nr=%d,packlen=%d\n",nr,packlen);
						
						bytes.m_pValue[3] = nr>>8;
						bytes.m_pValue[4] = nr;
						
						if(this->m_UpdateSM.sendUpdateBlockToSM(manuframe.DataBuf+4,packlen)==false){
							printf("update block to sm fail!\n");
							bytes.m_pValue[5] = 0x01; //表示失败

						}else{
							printf("update blcok[%d] to sm success,block len is %d !\n",nr,packlen);
							bytes.m_pValue[5] = 0x00; //表示成功
						}
						
		//				for(int i=0;i<bytes.m_nValue;i++){
		//					printf("0x%02x,",bytes.m_pValue[i]);
		//					
		//				}

						pack->setByteStream(bytes);
						
					}
						break;
				}
		

        if(pComm->immediateSendMessage(pack,messageid)){
            printf("send ack message success!\n");
        }else{
            printf("send ack message fail!\n");
        }
				if(m_UpdateTotalPack == nr && m_UpdateMCUID == 0)//接收到最后一包更新标志位
				{
					char *p= "host20181204V2.bin";
					this->m_UpdateMcu.FLASH_Message(binlen,p,flash_Isok);
					printf("update has get sucess \n");
					SoftReset();
				}					
        delete pack;
				
    }
        break;
    default:
        return -1;
    }
    return 0;

}
