#include "param_manager.h"
#include "main_application.h"
//#include "HbFrame_Operation.h"
//#include "general_functions.h"
#include "EN25Q256.h"
//#include "main.h"
//#include "fpga_pwr_en.h"
//#include "fpga_download.h"
//#include "AD5602.h"
/**
 * @brief param_manager::param_manager
 * @param pConfig，要管理的Config类
 */
Param_Manager::Param_Manager()
{
	initDeviceConfig();
}

Param_Manager::~Param_Manager(){
    delete m_pSetDeviceConfig;
}

//2018.10.09新加，将私有配置下发给安全模块
bool Param_Manager::setSpecialSetToSec(llrp_u8v_t specialSetData){
	//uint8_t *contentbuf = specialSetData.m_pValue;
	//int contentlen = specialSetData.m_nValue;
	uint8_t *contentbuf = new uint8_t[specialSetData.m_nValue+1];
	int contentlen = specialSetData.m_nValue+1;
	
	contentbuf[0] = 2; //配置私有配置操作符
	memcpy(contentbuf+1,specialSetData.m_pValue,specialSetData.m_nValue);
	
	STRUCT_M2SEC_FRAME *pframe = m_pM2SecComm->creatFrame(M2SEC_SPECIALWRITE_FRAME,contentbuf,contentlen);
	delete [] contentbuf;
	printf("set frame is : \n");
	MCUToSecureComm::printfSecFrame(pframe);
	if(m_pM2SecComm->sendFrameToSecure(pframe)){
		printf("Send set special set frame success!\n");
	}else{
		printf("Send set special set frame fail!\n");
		m_pM2SecComm->removeFrame(pframe);
        
        return false;
	}
	m_pM2SecComm->removeFrame(pframe);
	
	//Beep_Delay(100);
	
	//printf("f3...\n");
	//以下读取返回的响应
	//等待下降沿
	if(this->m_pM2SecComm->waitSecReadyForComm(500)<0){
		printf("Error,SM comm fail!\n");
		//Delay_ms(100);
		//Beep_Delay(250);
    return false;
	}
	//Delay_ms(100);
	//Beep_Delay(100);
	
	STRUCT_M2SEC_FRAME *packframe = m_pM2SecComm->getFrameFromSecure(M2SEC_SPECIALWRITEACK_FRAME);
	
	bool success = false;
	if(packframe!=NULL){
		printf("set frame ack is De: ");
		//MCUToSecureComm::printfSecFrame(packframe);
		//MCUToSecureComm::echoSecFrame(packframe);
		//Delay_ms(100);
		//Beep_Delay(10);
		if(packframe->OperId==0x03){
			//Delay_ms(100);
			//			Delay_ms(100);
			if(packframe->DataBuf[0]==0){
				//Delay_ms(100);
				//Beep_Delay(100);
				success = true;
			}else{
				//Delay_ms(100);
				//Beep_Delay(250);
			}
		}else{
			//Delay_ms(100);
			//Beep_Delay(250);
		}
		MCUToSecureComm::removeFrame(packframe);
		if(success==false){
			
			//Delay_ms(100);
			//Beep_Delay(500);			
		}
		
		return success;
		
	}
	//Delay_ms(100);
	//Beep_Delay(500);
	return false;
}

//2018.12.12新加，从安全模块获取私有配置(用作与发卡平台的安全认证) 
llrp_u8v_t Param_Manager::getSpecialSetToSec(llrp_u8v_t specialSetData){
	llrp_u8v_t res = llrp_u8v_t(0);
	uint8_t *contentbuf = new uint8_t[specialSetData.m_nValue+1];
	int contentlen = specialSetData.m_nValue+1;
	
	contentbuf[0] = 2; //配置私有配置操作符
	memcpy(contentbuf+1,specialSetData.m_pValue,specialSetData.m_nValue);
	
	STRUCT_M2SEC_FRAME *pframe = m_pM2SecComm->creatFrame(M2SEC_SPECIALWRITE_FRAME,contentbuf,contentlen);
	delete [] contentbuf;
	printf("get frame is : \n");
	MCUToSecureComm::printfSecFrame(pframe);
	if(m_pM2SecComm->sendFrameToSecure(pframe)){
		printf("Send get special set frame success!\n");
	}else{
		printf("Send get special set frame fail!\n");
		m_pM2SecComm->removeFrame(pframe);
        
        return false;
	}
	m_pM2SecComm->removeFrame(pframe);
	
	//Beep_Delay(100);
	
	//printf("f3...\n");
	//以下读取返回的响应
	//等待下降沿
	if(this->m_pM2SecComm->waitSecReadyForComm(100)<0){
		printf("Error,SM comm fail!\n");
		//Beep_Delay(10);
    return false;
	}
	//Delay_ms(100);
	//Beep_Delay(100);
	
	STRUCT_M2SEC_FRAME *packframe = m_pM2SecComm->getFrameFromSecure(M2SEC_SPECIALWRITEACK_FRAME);
	
	if(packframe!=NULL){
		//Delay_ms(50);
		//Beep_Delay(50);
		//printf("set frame ack is : ");
		//MCUToSecureComm::printfSecFrame(packframe);
		
		if(packframe->OperId==0x03&&packframe->DataBuf[0]==0x02){
			Delay_ms(100);
			//Beep_Delay(100);
//			int datalen = MCUToSecureComm::getFrameContenLen(packframe);
//			llrp_u8v_t t = llrp_u8v_t(datalen-1); //有效数据应是去了操作码和状态码2的数据
//			memcpy(t.m_pValue,packframe->DataBuf+1,t.m_nValue);
//			//MCUToSecureComm::echoSecFrame(packframe);
//			MCUToSecureComm::removeFrame(packframe);
			//res = t;
		}
	}else{
		Delay_ms(100);
		//Beep_Delay(500);
	}

	return res;
}

CSetDeviceConfig * Param_Manager::readCfg(){
	CSetDeviceConfig *psetdeviceconfig = NULL;

	//这里从FLASH中读取配置
//	unsigned char buf[CONFIG_STORAGE_SIZE];
//	EN25Q256_Read(buf,CONFIG_STORAGE_ADDR,CONFIG_STORAGE_SIZE);
//	psetdeviceconfig = (CSetDeviceConfig *)HbFrame_Operation::getMessageFromBuf(buf,CONFIG_STORAGE_SIZE);
//  if(psetdeviceconfig==NULL){
//		printf("read device config fail!\n");
//  }	
	return psetdeviceconfig;
}

bool Param_Manager::writeCfg(CSetDeviceConfig *pDevCfg){
//	unsigned char buf[CONFIG_STORAGE_SIZE];
//	int buflen = HbFrame_Operation::putMessageToBuf(pDevCfg,buf,CONFIG_STORAGE_SIZE);
//	if(buflen>=CONFIG_STORAGE_SIZE||buflen<=0){
//		return false;
//	}
//	EN25Q256_Write(buf,CONFIG_STORAGE_ADDR,buflen);
//	return true;
}

//测试用代码
bool Param_Manager::writeGetCfg(CGetDeviceConfig *pDevCfg){
//	unsigned char buf[GETCFG_SIZE];
//	int buflen = HbFrame_Operation::putMessageToBuf(pDevCfg,buf,GETCFG_SIZE);
//	if(buflen>=GETCFG_SIZE||buflen<=0){
//		return false;
//	}
//	EN25Q256_Write(buf,GETCFG_ADDR,buflen);
//	return true;
}

#include "uart_bsp_comm.h"
#include "HbFrame_Operation.h"
void Param_Manager::echoGetCfg(){
	
	CGetDeviceConfig *pgetdeviceconfig = NULL;

//	//这里从FLASH中读取配置
//	unsigned char buf[GETCFG_SIZE];
//	EN25Q256_Read(buf,GETCFG_ADDR,GETCFG_SIZE);
//	pgetdeviceconfig = (CGetDeviceConfig *)HbFrame_Operation::getMessageFromBuf(buf,GETCFG_SIZE);
//	
//	std::string xmlstring = HbFrame_Operation::getXmlFromMessage(pgetdeviceconfig);
//	const char *a = xmlstring.c_str();
//	while(1){
//		CommUSARTx_SendData((unsigned char *)a,xmlstring.length());
//		Delay_ms(1000);
//	}
}
////////////////////////////////////////////////////////
	
/**
 * @brief Param_Manager::initDeviceConfig
 * 从文件中读取配置
 */
void Param_Manager::initDeviceConfig(){
    printf("Init Device Config ****************************************\n");
    m_pSetDeviceConfig = this->readCfg();
    if(m_pSetDeviceConfig==NULL){
        m_pSetDeviceConfig = (CSetDeviceConfig*)HbFrame_Operation::genMessage(SetDeviceConfig,0);
        m_pSetDeviceConfig->setResetToFactoryDefault(SetDeviceConfigResetToFactoryDefault_NO_RESTORE );
        m_pSetDeviceConfig->setSelectReportSpec(this->getDefaultSelectReportSpec());
        m_pSetDeviceConfig->addAntennaConfiguration(this->getDefalutAntennaConfiguration(1));
        m_pSetDeviceConfig->addAntennaConfiguration(this->getDefalutAntennaConfiguration(2));
        m_pSetDeviceConfig->addAntennaConfiguration(this->getDefalutAntennaConfiguration(3));
        m_pSetDeviceConfig->addAntennaConfiguration(this->getDefalutAntennaConfiguration(4));
        m_pSetDeviceConfig->setCommunicationConfiguration(this->getDefaultCommunicationConfiguration());
        m_pSetDeviceConfig->setAlarmConfiguration(this->getDefaultAlarmConfiguration());
				m_pSetDeviceConfig->setIdentification(this->getDefaultIdentification());
    }
    if(m_pSetDeviceConfig->getAlarmConfiguration()==NULL){
        m_pSetDeviceConfig->setAlarmConfiguration(this->getDefaultAlarmConfiguration());
    }
		//HbFrame_Operation::printMessage(m_pSetDeviceConfig);
    printf("Init Device Config end!***************************************\n");
}


CIdentification *Param_Manager::getDefaultIdentification(){
//    CIdentification *p = (CIdentification *)HbFrame_Operation::genParam(Identification,0,NULL);
//    string idstr = "Bellon_HB_Reader_2016061800001";
//    llrp_utf8v_t devicename = llrp_utf8v_t(idstr.length());
//    memcpy(devicename.m_pValue,idstr.c_str(),devicename.m_nValue);
//    return p;
	  CIdentification *p = (CIdentification *)HbFrame_Operation::genParam(Identification,0,NULL);
    //string idstr = "";//"VIR-GDGW-BLUR400 1.2.156.3007 ";
    //idstr = idstr + General_Functions::snBytesToString(g_pMainApplication->deviceSN.m_pValue);
    //llrp_utf8v_t devicename = llrp_utf8v_t(idstr.length());
    //memcpy(devicename.m_pValue,idstr.c_str(),devicename.m_nValue);
	
	printf("deviceSN is :");
	for(int i=0;i<g_pMainApplication->convertdeviceSN().m_nValue;i++){
		printf("0x%02x,",g_pMainApplication->convertdeviceSN().m_pValue[i]);
	}
	printf("\n");
    llrp_utf8v_t devicename = llrp_utf8v_t(8);
		for(int i=0;i<8;i++){
			devicename.m_pValue[i] = g_pMainApplication->convertdeviceSN().m_pValue[i];
		}
		//memcpy(devicename.m_pValue,g_pMainApplication->deviceSN.m_pValue,8);
		//devicename.m_pValue[8] = 0x00;
		printf("devicename is :");
		for(int i=0;i<devicename.m_nValue;i++){
			printf("0x%02x,",devicename.m_pValue[i]);
		}
		printf("\n");
		p->setDeviceName(devicename);
    return p;
}

CAntennaConfiguration *Param_Manager::getDefalutAntennaConfiguration(int antennaid){
    CAntennaConfiguration *pantennacfg = (CAntennaConfiguration*)HbFrame_Operation::genParam(AntennaConfiguration,0,NULL);
    pantennacfg->setAntennaID(antennaid);
    pantennacfg->setTransmitPowerIndex(DEFAULT_POWERID);
    llrp_u16v_t freqs = llrp_u16v_t(1);
    /*for(int i=0;i<freqs.m_nValue;i++){
        freqs.m_pValue[i] = 0;
    }*/
    freqs.m_pValue[0] = 1; //默认采用频道0
    pantennacfg->setFrequencyIndexes(freqs);
    pantennacfg->setForDataRateIndex(0);
    pantennacfg->setRevDataRateIndex(5);
    pantennacfg->setForModulationIndex(0);
    pantennacfg->setRevDataEncodingIndex(1);

    return pantennacfg;
}

CSelectReportSpec *Param_Manager::getDefaultSelectReportSpec(){
    CSelectReportSpec *pselecreport = (CSelectReportSpec *)HbFrame_Operation::genParam(SelectReportSpec,0,NULL);
    pselecreport = (CSelectReportSpec*)HbFrame_Operation::genParam(SelectReportSpec,0,NULL);
    pselecreport->setSelectReportTrigger(SelectReportTrigger_Unconditional);
    pselecreport->setNValue(0);
    pselecreport->setEnableSelectSpecID(1);
    pselecreport->setEnableSpecIndex(1);
    pselecreport->setEnableRfSpecID(1);
    pselecreport->setEnableAntennaID(1);
    pselecreport->setEnablePeakRSSI(1);
    pselecreport->setEnableFirstSeenTimestamp(1);
    pselecreport->setEnableLastSeenTimestamp(1);
    pselecreport->setEnableTagSeenCount(1);
    pselecreport->setEnableAccessSpecID(1);

    return pselecreport;
}

CAccessReportSpec *Param_Manager::getDefaultAccessReportSpec(){
	return NULL;
}

CTcpLinkConfiguration *Param_Manager::getDefaultTcpLinkConfiguration(int defaultport){
    CTcpLinkConfiguration *ptcplinkcfg = (CTcpLinkConfiguration*)HbFrame_Operation::genParam(TcpLinkConfiguration,0,NULL);
    ptcplinkcfg->setCommMode(CommMode_SERVER_MODE);
    ptcplinkcfg->setIsSSL(0);

    CServerModeConfiguration *pservermodecfg = (CServerModeConfiguration*)HbFrame_Operation::genParam(ServerModeConfiguration,0,NULL);
    pservermodecfg->setPort(defaultport);

    ptcplinkcfg->setServerModeConfiguration(pservermodecfg);

    return ptcplinkcfg;
}

CCommunicationConfiguration *Param_Manager::getDefaultCommunicationConfiguration(){
    CCommunicationConfiguration *pcommcfg = (CCommunicationConfiguration *)HbFrame_Operation::genParam(CommunicationConfiguration,0,NULL);

    //配置默认通信链路，只添加一条配置
    pcommcfg->addCommLinkConfiguration(this->getDefaultCommLinkConfiguration(0));

    //添加IPV4地址相关
    pcommcfg->addEthernetConfiguration(this->getDefaultEthernetIpv4Configuration());

    return pcommcfg;
}

CCommLinkConfiguration * Param_Manager::getDefaultCommLinkConfiguration(int index){
    CCommLinkConfiguration *pcommlinkcfg = (CCommLinkConfiguration *)HbFrame_Operation::genParam(CommLinkConfiguration,0,NULL);
    pcommlinkcfg->setLinkType(LinkType_TCP);

    CKeepaliveSpec * parakeepalivespec = (CKeepaliveSpec *)HbFrame_Operation::genParam(KeepaliveSpec,0,NULL);
    //parakeepalivespec->setKeepaliveTriggerType(KeepaliveTriggerType_NON_HEART_BEAT);
    parakeepalivespec->setKeepaliveTriggerType(KeepaliveTriggerType_PERIODIC_HEART_BEAT);

    parakeepalivespec->setPeriodicTriggerValue(10000);
    pcommlinkcfg->setKeepaliveSpec(parakeepalivespec);

    pcommlinkcfg->setTcpLinkConfiguration(this->getDefaultTcpLinkConfiguration(DEFAULT_SERVERPORT+index));

    return pcommlinkcfg;
}

CEthernetIpv4Configuration *Param_Manager::getDefaultEthernetIpv4Configuration(){
    return NULL;
}

CClientModeConfiguration *Param_Manager::getDefaultClientModeConfiguration(){
   return NULL;
}

CServerModeConfiguration *Param_Manager::getDefaultServerModeConfiguration(){
    CServerModeConfiguration *pcfg = (CServerModeConfiguration*)HbFrame_Operation::genParam(ServerModeConfiguration,0,NULL);
    pcfg->setPort(DEFAULT_SERVERPORT);
    return pcfg;
}

CLocationConfiguration *Param_Manager::getDefaultLocationConfiguration(){

}

CAlarmThreshod *Param_Manager::getDefaultAlarmThreshod(){
    CAlarmThreshod *palarmthreshod = (CAlarmThreshod*)HbFrame_Operation::genParam(AlarmThreshod,0,NULL);
    palarmthreshod->setTemperatureMaxValue(70);
    palarmthreshod->setTemperatureMinValue(30);
    return palarmthreshod;
}

CAlarmConfiguration *Param_Manager::getDefaultAlarmConfiguration(){
    CAlarmConfiguration *palarmcfg = (CAlarmConfiguration *)HbFrame_Operation::genParam(AlarmConfiguration,0,NULL);
    palarmcfg->setAlarmMask(0x00); 
    palarmcfg->setAlarmThreshod(this->getDefaultAlarmThreshod());
    return palarmcfg;
}

int Param_Manager::dealMessage(CMessage *pMessage,Base_Comm *pComm){
    CMessage *pack = NULL;
	CStatus *pstatus = (CStatus*)HbFrame_Operation::genParam(Status,0,NULL);
	
    switch(pMessage->m_pType->m_TypeNum){
    case GetDeviceConfig:
				//Delay_ms(100);
				//Beep_Delay(1000);
				//this->writeGetCfg((CGetDeviceConfig*)pMessage);
		printf("Deal GetDeviceConfig...\n");
    {
        CGetDeviceConfig *pgetdeviceconfig;
        pgetdeviceconfig = (CGetDeviceConfig*)pMessage;
        llrp_u8_t requesteddata;
        requesteddata = pgetdeviceconfig->getRequestedData();
		
        CSetDeviceConfig *psetdeviceconfig = (CSetDeviceConfig*)HbFrame_Operation::copyMessage(m_pSetDeviceConfig);
        CGetDeviceConfigAck *pgetcfgack = (CGetDeviceConfigAck*)HbFrame_Operation::genMessage(GetDeviceConfigAck,0);
        //printf("D0...................\n");
        //CStatus *pstatus = (CStatus*)HbFrame_Operation::genParam(Status,0,NULL);

        //printf("D1...................\n");
        ((CStatus*)pstatus)->setStatusCode(StatusCode_M_Success);
        pgetcfgack->setStatus((CStatus*)pstatus);
		
		if(psetdeviceconfig->getIdentification()!=NULL){
			//printf("D3...................\n");
			pgetcfgack->setIdentification(psetdeviceconfig->getIdentification());
			//psetdeviceconfig->setIdentification(NULL);
			//printf("D4...................\n");
		}
		if(psetdeviceconfig->getDeviceEventNotificationSpec()!=NULL){
			pgetcfgack->setDeviceEventNotificationSpec(psetdeviceconfig->getDeviceEventNotificationSpec());
			//psetdeviceconfig->setDeviceEventNotificationSpec(NULL);
		}
		if(psetdeviceconfig->getAlarmConfiguration()!=NULL){
			pgetcfgack->setAlarmConfiguration(psetdeviceconfig->getAlarmConfiguration());
			//psetdeviceconfig->setAlarmConfiguration(NULL);
		}
		if(psetdeviceconfig->getModuleDepth()!=NULL){
			pgetcfgack->setModuleDepth(psetdeviceconfig->getModuleDepth());
			//psetdeviceconfig->setModuleDepth(NULL);
		}
		if(psetdeviceconfig->getSelectReportSpec()!=NULL){
			pgetcfgack->setSelectReportSpec(psetdeviceconfig->getSelectReportSpec());
			//psetdeviceconfig->setSelectReportSpec(NULL);
		}
		if(psetdeviceconfig->getAccessReportSpec()!=NULL){
			pgetcfgack->setAccessReportSpec(psetdeviceconfig->getAccessReportSpec());
			//psetdeviceconfig->setAccessReportSpec(NULL);
		}
		if(psetdeviceconfig->getCommunicationConfiguration()!=NULL){
			pgetcfgack->setCommunicationConfiguration(psetdeviceconfig->getCommunicationConfiguration());
			//psetdeviceconfig->setCommunicationConfiguration(NULL);
		}
		if(psetdeviceconfig->getLocationConfiguration()!=NULL){
			pgetcfgack->setLocationConfiguration(psetdeviceconfig->getLocationConfiguration());
			//psetdeviceconfig->setLocationConfiguration(NULL);
		}
		if(psetdeviceconfig->getSecurityModuleConfiguration()!=NULL){
			pgetcfgack->setSecurityModuleConfiguration(psetdeviceconfig->getSecurityModuleConfiguration());
		}
//            if(pgetdeviceconfig->getSecurityModuleConfiguration()!=NULL){
//							pgetcfgack->setSecurityModuleConfiguration(this->getSecConfig(pgetdeviceconfig->getSecurityModuleConfiguration()));
//						}
					
		for(list<CAntennaConfiguration*>::iterator it=psetdeviceconfig->beginAntennaConfiguration();
				it!=psetdeviceconfig->endAntennaConfiguration();it++){
			pgetcfgack->addAntennaConfiguration((*it));
			//(*it) = NULL;
		}
        //printf("D2...................\n");
        switch(requesteddata){
        case 0: //所有配置
            break;
        case 1: 
            //pgetcfgack->setIdentification(psetdeviceconfig->getIdentification());
            //pgetcfgack->setIdentification(NULL);
			pgetcfgack->setDeviceEventNotificationSpec(NULL);
			pgetcfgack->setCommunicationConfiguration(NULL);
			pgetcfgack->setAlarmConfiguration(NULL);
			pgetcfgack->clearAntennaConfiguration();
			pgetcfgack->setModuleDepth(NULL);
			pgetcfgack->setSelectReportSpec(NULL);
			pgetcfgack->setAccessReportSpec(NULL);
			pgetcfgack->setLocationConfiguration(NULL);
			pgetcfgack->setSecurityModuleConfiguration(NULL);		

            break;
        case 2: 
            //pgetcfgack->setDeviceEventNotificationSpec(psetdeviceconfig->getDeviceEventNotificationSpec());

			pgetcfgack->setIdentification(NULL);
			//pgetcfgack->setDeviceEventNotificationSpec(NULL);
			pgetcfgack->setCommunicationConfiguration(NULL);
			pgetcfgack->setAlarmConfiguration(NULL);
			pgetcfgack->clearAntennaConfiguration();
			pgetcfgack->setModuleDepth(NULL);
			pgetcfgack->setSelectReportSpec(NULL);
			pgetcfgack->setAccessReportSpec(NULL);
			pgetcfgack->setLocationConfiguration(NULL);
			pgetcfgack->setSecurityModuleConfiguration(NULL);
            break;
        case 3:
            //pgetcfgack->setCommunicationConfiguration(psetdeviceconfig->getCommunicationConfiguration());

			pgetcfgack->setIdentification(NULL);
			pgetcfgack->setDeviceEventNotificationSpec(NULL);
			//pgetcfgack->setCommunicationConfiguration(NULL);
			pgetcfgack->setAlarmConfiguration(NULL);
			pgetcfgack->clearAntennaConfiguration();
			pgetcfgack->setModuleDepth(NULL);
			pgetcfgack->setSelectReportSpec(NULL);
			pgetcfgack->setAccessReportSpec(NULL);
			pgetcfgack->setLocationConfiguration(NULL);
			pgetcfgack->setSecurityModuleConfiguration(NULL);
            break;
        case 4: 
            //pgetcfgack->setAlarmConfiguration(psetdeviceconfig->getAlarmConfiguration());

			pgetcfgack->setIdentification(NULL);
			pgetcfgack->setDeviceEventNotificationSpec(NULL);
			pgetcfgack->setCommunicationConfiguration(NULL);
			//pgetcfgack->setAlarmConfiguration(NULL);
			pgetcfgack->clearAntennaConfiguration();
			pgetcfgack->setModuleDepth(NULL);
			pgetcfgack->setSelectReportSpec(NULL);
			pgetcfgack->setAccessReportSpec(NULL);
			pgetcfgack->setLocationConfiguration(NULL);
			pgetcfgack->setSecurityModuleConfiguration(NULL);
		
            break;
        case 5: 
            break;
        case 6:
			pgetcfgack->setIdentification(NULL);
			pgetcfgack->setDeviceEventNotificationSpec(NULL);
			pgetcfgack->setCommunicationConfiguration(NULL);
			pgetcfgack->setAlarmConfiguration(NULL);
			//pgetcfgack->clearAntennaConfiguration();
			pgetcfgack->setModuleDepth(NULL);
			pgetcfgack->setSelectReportSpec(NULL);
			pgetcfgack->setAccessReportSpec(NULL);
			pgetcfgack->setLocationConfiguration(NULL);
			pgetcfgack->setSecurityModuleConfiguration(NULL);	
		
		
//            for(list<CAntennaConfiguration*>::iterator it=psetdeviceconfig->beginAntennaConfiguration();
//                    it!=psetdeviceconfig->endAntennaConfiguration();it++){
//                pgetcfgack->addAntennaConfiguration((*it));
//                //*it = NULL;
//            }
            break;
        case 7:
            //pgetcfgack->setModuleDepth(psetdeviceconfig->getModuleDepth());
		
			pgetcfgack->setIdentification(NULL);
			pgetcfgack->setDeviceEventNotificationSpec(NULL);
			pgetcfgack->setCommunicationConfiguration(NULL);
			pgetcfgack->setAlarmConfiguration(NULL);
			pgetcfgack->clearAntennaConfiguration();
			//pgetcfgack->setModuleDepth(NULL);
			pgetcfgack->setSelectReportSpec(NULL);
			pgetcfgack->setAccessReportSpec(NULL);
			pgetcfgack->setLocationConfiguration(NULL);
			pgetcfgack->setSecurityModuleConfiguration(NULL);
            break;
        case 8:
            //pgetcfgack->setSelectReportSpec(psetdeviceconfig->getSelectReportSpec());
            //psetdeviceconfig->setSelectReportSpec(NULL);
			pgetcfgack->setIdentification(NULL);
			pgetcfgack->setDeviceEventNotificationSpec(NULL);
			pgetcfgack->setCommunicationConfiguration(NULL);
			pgetcfgack->setAlarmConfiguration(NULL);
			pgetcfgack->clearAntennaConfiguration();
			pgetcfgack->setModuleDepth(NULL);
			//pgetcfgack->setSelectReportSpec(NULL);
			pgetcfgack->setAccessReportSpec(NULL);
			pgetcfgack->setLocationConfiguration(NULL);
			pgetcfgack->setSecurityModuleConfiguration(NULL);
            break;
        case 9:
            //pgetcfgack->setAccessReportSpec(psetdeviceconfig->getAccessReportSpec());
 
			pgetcfgack->setIdentification(NULL);
			pgetcfgack->setDeviceEventNotificationSpec(NULL);
			pgetcfgack->setCommunicationConfiguration(NULL);
			pgetcfgack->setAlarmConfiguration(NULL);
			pgetcfgack->clearAntennaConfiguration();
			pgetcfgack->setModuleDepth(NULL);
			pgetcfgack->setSelectReportSpec(NULL);
			//pgetcfgack->setAccessReportSpec(NULL);
			pgetcfgack->setLocationConfiguration(NULL);
			pgetcfgack->setSecurityModuleConfiguration(NULL);
            break;
        case 10:
            //pgetcfgack->setLocationConfiguration(psetdeviceconfig->getLocationConfiguration());
		
			pgetcfgack->setIdentification(NULL);
			pgetcfgack->setDeviceEventNotificationSpec(NULL);
			pgetcfgack->setCommunicationConfiguration(NULL);
			pgetcfgack->setAlarmConfiguration(NULL);
			pgetcfgack->clearAntennaConfiguration();
			pgetcfgack->setModuleDepth(NULL);
			pgetcfgack->setSelectReportSpec(NULL);
			pgetcfgack->setAccessReportSpec(NULL);
			//pgetcfgack->setLocationConfiguration(NULL);
			pgetcfgack->setSecurityModuleConfiguration(NULL);
            break;
        case 11:
            //pgetcfgack->setSecurityModuleConfiguration(psetdeviceconfig->getSecurityModuleConfiguration());
			pgetcfgack->setIdentification(NULL);
			pgetcfgack->setDeviceEventNotificationSpec(NULL);
			pgetcfgack->setCommunicationConfiguration(NULL);
			pgetcfgack->setAlarmConfiguration(NULL);
			pgetcfgack->clearAntennaConfiguration();
			pgetcfgack->setModuleDepth(NULL);
			pgetcfgack->setSelectReportSpec(NULL);
			pgetcfgack->setAccessReportSpec(NULL);
			pgetcfgack->setLocationConfiguration(NULL);
			//pgetcfgack->setSecurityModuleConfiguration(NULL);
		
//            if(pgetdeviceconfig->getSecurityModuleConfiguration()!=NULL){
//							pgetcfgack->setSecurityModuleConfiguration(this->getSecConfig(pgetdeviceconfig->getSecurityModuleConfiguration()));
//						}
			break;
        }
        
        for(tListOfParameters::iterator it=psetdeviceconfig->m_listAllSubParameters.begin();
                it!=psetdeviceconfig->m_listAllSubParameters.end();it++){
            (*it) = NULL;
        }
				

        delete psetdeviceconfig;
        pack = pgetcfgack;
				HbFrame_Operation::printMessage(pack);
    }

        break;
    //==============================================================//
    case SetDeviceConfig:
    {
			//HbFrame_Operation::echoMessage(pMessage);
        pack = HbFrame_Operation::genMessage(SetDeviceConfigAck,0);
        //CStatus *pstatus = (CStatus*)HbFrame_Operation::genParam(Status,0,NULL);
        if(updateDeviceConfig((CSetDeviceConfig*)pMessage)==true){
            ((CStatus*)pstatus)->setStatusCode(StatusCode_M_Success);
        }else{
            ((CStatus*)pstatus)->setStatusCode(StatusCode_R_DeviceError);
        }
        HbFrame_Operation::addParamToMessage(pstatus,pack);

    }
        break;
    default:
        break;
    }
	
    if(pack!=NULL){
			pComm->immediateSendMessage(pack,pMessage->getMessageID());
		
			delete pack;
			//Delay_ms(100);
			return 0;
		}else{
			
			if(pstatus != NULL )
			{
				delete pstatus;
			}
			
			return -1;
		}
}

bool Param_Manager::updateDeviceConfig(CSetDeviceConfig *pcfg){
	
	CSetDeviceConfig *ptempcfg = (CSetDeviceConfig*)HbFrame_Operation::genMessage(SetDeviceConfig,0);

    if(m_pSetDeviceConfig->getIdentification()!=NULL){
        ptempcfg->setIdentification(m_pSetDeviceConfig->getIdentification());
    }else{
        ptempcfg->setIdentification(this->getDefaultIdentification());
    }

    if(pcfg->getDeviceEventNotificationSpec()!=NULL){
        ptempcfg->setDeviceEventNotificationSpec(pcfg->getDeviceEventNotificationSpec());
    }else if(m_pSetDeviceConfig->getDeviceEventNotificationSpec()!=NULL){
        ptempcfg->setDeviceEventNotificationSpec(m_pSetDeviceConfig->getDeviceEventNotificationSpec());
    }

    if(pcfg->getAlarmConfiguration()!=NULL){
        ptempcfg->setAlarmConfiguration(pcfg->getAlarmConfiguration());
    }else if(m_pSetDeviceConfig->getAlarmConfiguration()!=NULL){
        ptempcfg->setAlarmConfiguration(m_pSetDeviceConfig->getAlarmConfiguration());
    }

    if(pcfg->beginAntennaConfiguration()!=pcfg->endAntennaConfiguration()){
        for(list<CAntennaConfiguration*>::iterator it=pcfg->beginAntennaConfiguration();
                it!=pcfg->endAntennaConfiguration();it++){
            ptempcfg->addAntennaConfiguration(*it);
        }
    }else if(m_pSetDeviceConfig->beginAntennaConfiguration()!=m_pSetDeviceConfig->endAntennaConfiguration()){
        for(list<CAntennaConfiguration*>::iterator it=m_pSetDeviceConfig->beginAntennaConfiguration();
                it!=m_pSetDeviceConfig->endAntennaConfiguration();it++){
            ptempcfg->addAntennaConfiguration(*it);
        }
    }

    if(pcfg->getModuleDepth()!=NULL){
        ptempcfg->setModuleDepth(pcfg->getModuleDepth());
    }else if(m_pSetDeviceConfig->getModuleDepth()!=NULL){
        ptempcfg->setModuleDepth(m_pSetDeviceConfig->getModuleDepth());
    }

    if(pcfg->getSelectReportSpec()!=NULL){
        ptempcfg->setSelectReportSpec(pcfg->getSelectReportSpec());
    }else if(m_pSetDeviceConfig->getSelectReportSpec()!=NULL){
        ptempcfg->setSelectReportSpec(m_pSetDeviceConfig->getSelectReportSpec());
    }

    if(pcfg->getAccessReportSpec()!=NULL){
        ptempcfg->setAccessReportSpec(pcfg->getAccessReportSpec());
    }else if(m_pSetDeviceConfig->getAccessReportSpec()!=NULL){
        ptempcfg->setAccessReportSpec(m_pSetDeviceConfig->getAccessReportSpec());
    }

    //bool isnewcomcfg = false;
    CCommunicationConfiguration *ptempcomcfg = (CCommunicationConfiguration *)HbFrame_Operation::genParam(CommunicationConfiguration,0,NULL);
    if(pcfg->getCommunicationConfiguration()!=NULL){
        //ptempcfg->setCommunicationConfiguration(pcfg->getCommunicationConfiguration());
        if(m_pSetDeviceConfig->getCommunicationConfiguration()!=NULL){
            CCommunicationConfiguration *pcomcfg = pcfg->getCommunicationConfiguration();
            CCommunicationConfiguration *g_pcomcfg = m_pSetDeviceConfig->getCommunicationConfiguration();
            //isnewcomcfg = true;
            //==========================================================================//
            if(pcomcfg->beginCommLinkConfiguration()!=pcomcfg->endCommLinkConfiguration()){
                for(list<CCommLinkConfiguration*>::iterator it=pcomcfg->beginCommLinkConfiguration();
                        it!=pcomcfg->endCommLinkConfiguration();it++){
                    ptempcomcfg->addCommLinkConfiguration(*it);
                }
            }else if(g_pcomcfg->beginCommLinkConfiguration()!=g_pcomcfg->endCommLinkConfiguration()){
                for(list<CCommLinkConfiguration*>::iterator it=g_pcomcfg->beginCommLinkConfiguration();
                        it!=g_pcomcfg->endCommLinkConfiguration();it++){
                    ptempcomcfg->addCommLinkConfiguration(*it);
                }
            }

            if(pcomcfg->beginEthernetConfiguration()!=pcomcfg->endEthernetConfiguration()){
                for(list<CParameter*>::iterator it=pcomcfg->beginEthernetConfiguration();
                        it!=pcomcfg->endEthernetConfiguration();it++){
                    ptempcomcfg->addEthernetConfiguration(*it);
                }
            }else if(g_pcomcfg->beginEthernetConfiguration()!=g_pcomcfg->endEthernetConfiguration()){
                for(list<CParameter*>::iterator it=g_pcomcfg->beginEthernetConfiguration();
                        it!=g_pcomcfg->endEthernetConfiguration();it++){
                    ptempcomcfg->addEthernetConfiguration(*it);
                }
            }

            if(pcomcfg->beginSerialPortConfiguration()!=pcomcfg->endSerialPortConfiguration()){
                for(list<CSerialPortConfiguration*>::iterator it=pcomcfg->beginSerialPortConfiguration();
                        it!=pcomcfg->endSerialPortConfiguration();it++){
                    ptempcomcfg->addSerialPortConfiguration(*it);
                }
            }else if(g_pcomcfg->beginSerialPortConfiguration()!=g_pcomcfg->endSerialPortConfiguration()){
                for(list<CSerialPortConfiguration*>::iterator it=g_pcomcfg->beginSerialPortConfiguration();
                        it!=g_pcomcfg->endSerialPortConfiguration();it++){
                    ptempcomcfg->addSerialPortConfiguration(*it);
                }
            }

            if(pcomcfg->getNTPConfiguration()!=NULL){
                ptempcomcfg->setNTPConfiguration(pcomcfg->getNTPConfiguration());
            }else if(g_pcomcfg->getNTPConfiguration()!=NULL){
                ptempcomcfg->setNTPConfiguration(g_pcomcfg->getNTPConfiguration());
            }

            ptempcfg->setCommunicationConfiguration(ptempcomcfg);
            //==========================================================================//
        }else{
            ptempcfg->setCommunicationConfiguration(pcfg->getCommunicationConfiguration());
        }

    }else if(m_pSetDeviceConfig->getCommunicationConfiguration()!=NULL){
        ptempcfg->setCommunicationConfiguration(m_pSetDeviceConfig->getCommunicationConfiguration());
    }

    if(pcfg->getLocationConfiguration()!=NULL){
        ptempcfg->setLocationConfiguration(pcfg->getLocationConfiguration());
    }else if(m_pSetDeviceConfig->getLocationConfiguration()!=NULL){
        ptempcfg->setLocationConfiguration(m_pSetDeviceConfig->getLocationConfiguration());
    }

		bool success = true;
    if(pcfg->getSecurityModuleConfiguration()!=NULL){
//				llrp_u8v_t configdata = pcfg->getSecurityModuleConfiguration()->getConfigData();
//				if(this->setSpecialSetToSec(configdata)==false){
//					success = false;
//				}
        //ptempcfg->setSecurityModuleConfiguration(pcfg->getSecurityModuleConfiguration());
    }else if(m_pSetDeviceConfig->getSecurityModuleConfiguration()!=NULL){
        //ptempcfg->setSecurityModuleConfiguration(m_pSetDeviceConfig->getSecurityModuleConfiguration());
    }



	
	CSetDeviceConfig *ptemp = (CSetDeviceConfig*)HbFrame_Operation::copyMessage(ptempcfg);
	
    //以下用以打断各参数与读取到的配置消息的联系，并将原消息删除(这样做，就不会删除配置消息下的各参数。)。
    for(tListOfParameters::iterator it=ptempcfg->m_listAllSubParameters.begin();
            it!=ptempcfg->m_listAllSubParameters.end();it++){
        (*it) = NULL;
    }	
    delete ptempcfg;
	

    for(tListOfParameters::iterator it=ptempcomcfg->m_listAllSubParameters.begin();
            it!=ptempcomcfg->m_listAllSubParameters.end();it++){
        (*it) = NULL;
    }
    delete ptempcomcfg;
	
	delete m_pSetDeviceConfig; //删除原配置
	m_pSetDeviceConfig = ptemp;
	
	if(this->writeCfg(m_pSetDeviceConfig)==true){
		//success = true;
	}else{
		success = false;
	}
		
	return success;
}

llrp_u64_t Param_Manager::convertDeviceSN(llrp_u8v_t devicesn){
    llrp_u64_t res = 0;

    //printf("deviceSN.m_nValue=%d\n",deviceSN.m_nValue);
    if(devicesn.m_nValue<8){//输入的sn大于8位，也只会取前8位
        return res;
    }

    for(int i=0;i<8;i++){
        llrp_u64_t t = devicesn.m_pValue[i];
        res |= t<<(56-8*i);
        //res |= t<<(8*i);
    }
    return res;
}

void Param_Manager::run(){
	
}

CSecurityModuleConfiguration *Param_Manager::getSecConfig(CSecurityModuleConfiguration *pSecCfg){
	
	if(pSecCfg==NULL){
		return NULL;
	}
	
	//llrp_u8v_t t = pSecCfg->getConfigData();
	//t = this->getSpecialSetToSec(t);
	
	CSecurityModuleConfiguration *pres = new CSecurityModuleConfiguration();
	//pres->setConfigData(t);
	
	return pres;
}
