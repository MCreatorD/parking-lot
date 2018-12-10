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
#include "Update_SM_Firmware.h"
#include "Update_Mcu_Firmware.h"
#define APP_VERSION_STR "VER:ISSUSER.2.06.HB.2018-11-29"


/**
*	版本说明
*	行标手持机
* 	VER:UHFLowPower.2.00.00.2018-03-15
*	初版，读卡功能已实现。但还有些功能未实现。
*	VER:Blue.2.01.HB.2018-10-22
*	实现了较稳定的读写卡功能。实现了桌面发卡机的功能（还未测试）。
* 加入了安全模块升级功能。
*	VER:Blue.2.02.HB.2018-10-24 
*	串口通信中的CRC校验码根据无锡所要求改为不取反。
* VER:ISSUSER.2.03.HB.2018-11-05
*	能正常发卡。且已调整为新旧测试卡都能正常发卡。
* 加入低功耗控制，开始读卡前开启功放，AD，读卡后关闭功放，AD
* VER:ISSUSER.2.04.HB.2018-11-09
*	排除在私有写时，因为私有写配置返回帧未删除而引起的内存泄漏问题。
* 加入校时功能，加入软复位功能，加入设置设备序列号功能。
* 调通了获取激活申请文件的功能。激活尚未测试。
*	VER:ISSUSER.2.05.HB.2018-11-28
* 添加了设备配置和读取的功能
*	VER:ISSUSER.2.06.HB.2018-11-29
* 调整了私有写读取安全模块返回为读取完才退出。
*	加入功率值的配置功能。
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
	int dealMfeMessage(CMessage *pMessage,Base_Comm *pComm);
public:
    void run(); 
private:
    bool isUpdateRunning;
	unsigned char m_UpdateType; //升级类型
	unsigned char m_UpdateMCUID; //升级类型
	unsigned int  m_UpdateTotalPack; //升级内容总包数

public:
	Update_SM_Firmware  m_UpdateSM;
	Update_Mcu_Firmware m_UpdateMcu;

public:
	llrp_u8v_t getSecSerial();
};

#endif /* VERSIONMANAGER_H_ */
