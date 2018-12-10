#include "param_manager.h"
#include "main_application.h"


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

/**
 * @brief Param_Manager::initDeviceConfig
 * 从文件中读取配置
 */
void Param_Manager::initDeviceConfig(){
    printf("Init Device Config ****************************************\n");
    m_pSetDeviceConfig = NULL;
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
    }
    if(m_pSetDeviceConfig->getAlarmConfiguration()==NULL){
        m_pSetDeviceConfig->setAlarmConfiguration(this->getDefaultAlarmConfiguration());
    }
    printf("Init Device Config end!***************************************\n");
}


CIdentification *Param_Manager::getDefaultIdentification(){
    CIdentification *p = (CIdentification *)HbFrame_Operation::genParam(Identification,0,NULL);
    string idstr = "Bellon_HB_Reader_2016061800001";
    llrp_utf8v_t devicename = llrp_utf8v_t(idstr.length());
    memcpy(devicename.m_pValue,idstr.c_str(),devicename.m_nValue);
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
    switch(pMessage->m_pType->m_TypeNum){
    case GetDeviceConfig:
        printf("Deal GetDeviceConfig...\n");
    {
        CGetDeviceConfig *pgetdeviceconfig;
        pgetdeviceconfig = (CGetDeviceConfig*)pMessage;
        llrp_u8_t requesteddata;
        requesteddata = pgetdeviceconfig->getRequestedData();
        CSetDeviceConfig *psetdeviceconfig = NULL;

        CGetDeviceConfigAck *pgetcfgack = (CGetDeviceConfigAck*)HbFrame_Operation::genMessage(GetDeviceConfigAck,0);
        //printf("D0...................\n");
        CStatus *pstatus = (CStatus*)HbFrame_Operation::genParam(Status,0,NULL);
        if(psetdeviceconfig==NULL){
            printf("psetdeviceconfig is NULL!\n");
            psetdeviceconfig = (CSetDeviceConfig*)HbFrame_Operation::genMessage(SetDeviceConfig,0);
            psetdeviceconfig->setResetToFactoryDefault(SetDeviceConfigResetToFactoryDefault_NO_RESTORE );
            psetdeviceconfig->setSelectReportSpec(getDefaultSelectReportSpec());
            psetdeviceconfig->addAntennaConfiguration(getDefalutAntennaConfiguration(1));
            psetdeviceconfig->addAntennaConfiguration(getDefalutAntennaConfiguration(2));
            psetdeviceconfig->addAntennaConfiguration(getDefalutAntennaConfiguration(3));
            psetdeviceconfig->addAntennaConfiguration(getDefalutAntennaConfiguration(4));
            psetdeviceconfig->setCommunicationConfiguration(getDefaultCommunicationConfiguration());
            CIdentification *pid = (CIdentification*)HbFrame_Operation::genParam(Identification,0,NULL);
            llrp_utf8v_t devicename = llrp_utf8v_t(8);
            memcpy(devicename.m_pValue,DEVICE_NAME,8);
            pid->setDeviceName(devicename);
            psetdeviceconfig->setIdentification(pid);
        }
        //printf("D1...................\n");
        ((CStatus*)pstatus)->setStatusCode(StatusCode_M_Success);
        pgetcfgack->setStatus((CStatus*)pstatus);
        //printf("D2...................\n");
        switch(requesteddata){
        case 0: //所有配置
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
                //psetdeviceconfig->setSecurityModuleConfiguration(NULL);
            }
            for(list<CAntennaConfiguration*>::iterator it=psetdeviceconfig->beginAntennaConfiguration();
                    it!=psetdeviceconfig->endAntennaConfiguration();it++){
                pgetcfgack->addAntennaConfiguration((*it));
                //(*it) = NULL;
            }
            //printf("D6...................\n");
            break;
        case 1: 
            pgetcfgack->setIdentification(psetdeviceconfig->getIdentification());
            //psetdeviceconfig->setIdentification(NULL);
            break;
        case 2: 
            pgetcfgack->setDeviceEventNotificationSpec(psetdeviceconfig->getDeviceEventNotificationSpec());
            //psetdeviceconfig->setDeviceEventNotificationSpec(NULL);
            break;
        case 3:
            pgetcfgack->setCommunicationConfiguration(psetdeviceconfig->getCommunicationConfiguration());
            //psetdeviceconfig->setCommunicationConfiguration(NULL);
            break;
        case 4: 
            pgetcfgack->setAlarmConfiguration(psetdeviceconfig->getAlarmConfiguration());
            //psetdeviceconfig->setAlarmConfiguration(NULL);
            break;
        case 5: 
            break;
        case 6:
            for(list<CAntennaConfiguration*>::iterator it=psetdeviceconfig->beginAntennaConfiguration();
                    it!=psetdeviceconfig->endAntennaConfiguration();it++){
                pgetcfgack->addAntennaConfiguration((*it));
                //*it = NULL;
            }
            break;
        case 7:
            pgetcfgack->setModuleDepth(psetdeviceconfig->getModuleDepth());
            //psetdeviceconfig->setModuleDepth(NULL);
            break;
        case 8:
            pgetcfgack->setSelectReportSpec(psetdeviceconfig->getSelectReportSpec());
            //psetdeviceconfig->setSelectReportSpec(NULL);
            break;
        case 9:
            pgetcfgack->setAccessReportSpec(psetdeviceconfig->getAccessReportSpec());
            //psetdeviceconfig->setAccessReportSpec(NULL);
            break;
        case 10:
            pgetcfgack->setLocationConfiguration(psetdeviceconfig->getLocationConfiguration());
            break;
        case 11:
            pgetcfgack->setSecurityModuleConfiguration(psetdeviceconfig->getSecurityModuleConfiguration());
            break;
        }
        
        for(tListOfParameters::iterator it=psetdeviceconfig->m_listAllSubParameters.begin();
                it!=psetdeviceconfig->m_listAllSubParameters.end();it++){
            (*it) = NULL;
        }
        delete psetdeviceconfig;
        pack = pgetcfgack;
    }

        break;
    //==============================================================//
    case SetDeviceConfig:
    {
        pack = HbFrame_Operation::genMessage(SetDeviceConfigAck,0);
        CStatus *pstatus = (CStatus*)HbFrame_Operation::genParam(Status,0,NULL);
        //if(updateDeviceConfig((CSetDeviceConfig*)pMessage)==true){
            ((CStatus*)pstatus)->setStatusCode(StatusCode_M_Success);
        //}else{
            ((CStatus*)pstatus)->setStatusCode(StatusCode_R_DeviceError);
        //}
        HbFrame_Operation::addParamToMessage(pstatus,pack);
        initDeviceConfig();

    }
        break;
    default:
        break;
    }
    if(pack!=NULL){
			pComm->immediateSendMessage(pack,pMessage->getMessageID());
			return 0;
		}else{
			return -1;
		}
}

void Param_Manager::run(){
	
}
