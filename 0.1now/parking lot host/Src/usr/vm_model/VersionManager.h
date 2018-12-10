/*
 * VersionManager.h
 *
 *  Created on: 2016-5-13
 *      Author: root
 */

#ifndef VERSIONMANAGER_H_
#define VERSIONMANAGER_H_

#include "general.h"

#include "HbFrame_Operation.h"
#include "MCUToSecureComm.h"
#include "model_base.h"

#define APP_VERSION_STR "VER:Blue.2.00.HB.2018-07-02 "


/**
* 版本说明
*	行标手持机
* VER:UHFLowPower.2.00.00.2018-03-15
*	初版，读卡功能已实现。但还有些功能未实现。
*	
*/

class VersionManager:public Model_Base{
public:
	VersionManager();
	virtual ~VersionManager();

public:
	//Update_SM_Firmware m_UpdateSM;

public:

    void startUpdateFPGA(int commID);
    void startUpdateSM(int commID);

private:

public:

    int dealMessage(CMessage *pMessage,Base_Comm *pComm); //处理版本管理相关消息
public:
    void run(); 
private:
    bool isUpdateRunning;
};

#endif /* VERSIONMANAGER_H_ */
