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


VersionManager::VersionManager() {
	// TODO Auto-generated constructor stub
    isUpdateRunning = false;
}

VersionManager::~VersionManager() {
	// TODO Auto-generated destructor stub
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
            break;
        case GetVersionVerType_SECURITY_CHIP_SYSTEM_VER:
						break;
			}

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
