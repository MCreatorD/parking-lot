#ifndef PARAM_MANAGER_H
#define PARAM_MANAGER_H

#include "HbFrame_Operation.h"

#include <string>
#include <vector>
using namespace std;

#include "VersionManager.h"
#include "Model_Base.h"
#include "rf_oper_base.h"

/**
 * @brief The param_manager class
 * 工作参数配置读取管理类
 * by lijin,2017.03.24
 */

class Param_Manager:public Model_Base
{
public:
    Param_Manager();
    ~Param_Manager();
private:
    CSetDeviceConfig *m_pSetDeviceConfig;
		void initDeviceConfig();
public:
    //几个默认参数
    CIdentification *getDefaultIdentification();
    CAntennaConfiguration *getDefalutAntennaConfiguration(int antennaid);
    CAccessReportSpec *getDefaultAccessReportSpec();
    CCommunicationConfiguration *getDefaultCommunicationConfiguration();
    CCommLinkConfiguration * getDefaultCommLinkConfiguration(int index);
    CEthernetIpv4Configuration *getDefaultEthernetIpv4Configuration();
    CTcpLinkConfiguration *getDefaultTcpLinkConfiguration(int defaultport);
    CServerModeConfiguration *getDefaultServerModeConfiguration();
    CClientModeConfiguration *getDefaultClientModeConfiguration();
    CLocationConfiguration *getDefaultLocationConfiguration();
    CAlarmThreshod *getDefaultAlarmThreshod();
    CAlarmConfiguration *getDefaultAlarmConfiguration();
public:
     CSelectReportSpec *getDefaultSelectReportSpec();

public:
    inline CSetDeviceConfig *getDeviceConfig(){
        return this->m_pSetDeviceConfig;
    }

    int dealMessage(CMessage *pMessage,Base_Comm *pComm);
		
		void run();

};

#endif // PARAM_MANAGER_H