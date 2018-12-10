/*
 * Update_SM_Firmware.cpp
 *
 *  Created on: 2016-6-12
 *      Author: root
 */

#include "Update_SM_Firmware.h"
#include "systick.h"


Update_SM_Firmware::Update_SM_Firmware() {
	// TODO Auto-generated constructor stub

}

Update_SM_Firmware::~Update_SM_Firmware() {
	// TODO Auto-generated destructor stub
}

bool Update_SM_Firmware::enterUpateState(){
    //printf("Start update sec module firmware!\n");
    //对安全模块进行复位
    int t = 0;
    m_pIOCtrl->setSMResetLow();
    while(t<5){
        Delay_ms(100);
        t++;
    }
    m_pIOCtrl->setSMResetHigh();
    t = 0;
    while(t<5){
        Delay_ms(100);
        t++;
    }

    //printf("reseted sec module!\n");
    //等待安全模块Status脚信号变为低
    if(this->m_pM2SecComm->waitSecReadyForUpdate()<0){
        return false;
    }else{
		return true;
	}
}

/*
 * 注意，这里传入的数据包括operid和block数据。长度是两者的总长
 */
bool Update_SM_Firmware::sendUpdateBlockToSM(unsigned char *contentbuf,unsigned int contentlen){
	STRUCT_M2SEC_FRAME *pframe = this->m_pM2SecComm->creatFrame(M2SEC_UPDATE_FRAME,contentbuf,contentlen);
	if(pframe==NULL){
		printf("Update_SM_Firmware:create upate frame fail!\n");
		return false;
	}
	//发送帧
	if(m_pM2SecComm->sendFrameToSecure(pframe)){
		//printf("Update_SM_Firmware:send update frame success!\n");
	}else{
		printf("Update_SM_Firmware:send update frame fail!\n");
	}
	m_pM2SecComm->removeFrame(pframe);
	pframe = NULL;
	//等待应答
	if(m_pM2SecComm->waitSecReadyForComm(2000)<0){
		printf("Update_SM_Firmware:wait update ack overtime!\n");
		return false;
	}
	//读取应答
	pframe = m_pM2SecComm->getFrameFromSecure(M2SEC_UPDATEACK_FRAME);
	if(pframe==NULL){
		printf("Update_SM_Firmware:Read update ack from Secure fail!\n");
		return false;
	}

	//this->printfSecFrame(pframe);

	if(pframe->DataBuf[0]==0){ //返回的应答帧是成功则返回真，否则返回假
		//MCUToSecureComm::printfSecFrame(pframe);
		m_pM2SecComm->removeFrame(pframe);
		return true;
	}else{
		//MCUToSecureComm::printfSecFrame(pframe);
		m_pM2SecComm->removeFrame(pframe);
		return false;
	}

}
