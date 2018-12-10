/*
 * Sm2Certification.cpp
 *
 *  Created on: 2016-3-10
 *      Author: root
 */



#include <stdlib.h>
#include <stdio.h>

#include <string.h>
#include <time.h>

#include "sm2.h"
#include "main_application.h"
#include "Sm2Certification.h"
#include "MCUToSecureComm.h"

Sm2Certification::Sm2Certification() {
	// TODO Auto-generated constructor stub
//	this->certificatedata = llrp_u8v_t(1024);
//	this->userdata = llrp_u8v_t(224);
//	this->finishCerChain = 0;

//	digitalCer = NULL;

//	readyForBindingRequest = false;

}

Sm2Certification::~Sm2Certification() {
	// TODO Auto-generated destructor stub
//	if(digitalCer!=NULL){
//		delete [] digitalCer;
//	}
}

bool Sm2Certification::initSm2Key(){

	uint8_t key_x[32] = {0x41,0x62,0xB7,0x29,0x9B,0xF3,0x92,0x0B,0xBE,0xD5,0x70,0xC8,0x2E,0x3A,0xD0,0x0B,
											 0x88,0x86,0x33,0x3D,0xC9,0xE5,0xE1,0xBE,0x67,0xF1,0xB9,0xF3,0x75,0x03,0xBA,0x9F};
	uint8_t key_y[32] = {0xB3,0xDF,0x6C,0x1C,0x6D,0xF9,0x3F,0x78,0x70,0xFC,0xCB,0x25,0x6A,0x88,0x38,0x5C,
											 0x63,0x04,0x66,0xF2,0x8C,0x77,0x01,0x50,0x9E,0x1E,0x2D,0x19,0xD6,0xCA,0x94,0xB5};
	uint8_t privkey[32] = { 
													0xA2,0xA8,0x43,0x2C,0x90,0x5E,0x8D,0xF5,0xD0,0x1C,0xC0,0x1F,0xED,0x4C,0xF5,0xD3,
													0x54,0x85,0x3B,0xF7,0x9A,0x52,0x01,0xC7,0x3F,0x15,0x56,0xB4,0xFF,0x46,0x16,0x9C
												};
	sm2PubKey_x = new uint8_t[32];
	sm2PubKey_y	= new uint8_t[32];
	sm2PrivKey = new uint8_t[32];
											 
	memcpy(sm2PubKey_x,key_x,32);
	memcpy(sm2PubKey_y,key_y,32);
	memcpy(sm2PrivKey,privkey,32);
	
	return true;
}

bool Sm2Certification::initDevNr(){
	uint8_t testnr[] = {'B','L','1','2','3','4','5','6'};

  memcpy(devNr,testnr,8);
	return true;
}

bool Sm2Certification::initDigitalCer(){

	uint8_t data[586] = {
		0x30,0x82,0x02,0x06,0x30,0x82,0x01,0xA9,0xA0,0x03,0x02,0x01,0x02,0x02,0x09,0x00,
		0xFD,0xA4,0x25,0x42,0x3D,0x6E,0xFB,0xCD,0x30,0x0C,0x06,0x08,0x2A,0x81,0x1C,0xCF,
		0x55,0x01,0x83,0x75,0x05,0x00,0x30,0x56,0x31,0x0B,0x30,0x09,0x06,0x03,0x55,0x04,
		0x06,0x0C,0x02,0x43,0x4E,0x31,0x0B,0x30,0x09,0x06,0x03,0x55,0x04,0x08,0x0C,0x02,
		0x4A,0x53,0x31,0x0B,0x30,0x09,0x06,0x03,0x55,0x04,0x07,0x0C,0x02,0x57,0x58,0x31,
		0x0D,0x30,0x0B,0x06,0x03,0x55,0x04,0x0A,0x0C,0x04,0x54,0x4D,0x52,0x49,0x31,0x0D,
		0x30,0x0B,0x06,0x03,0x55,0x04,0x0B,0x0C,0x04,0x54,0x4D,0x52,0x49,0x31,0x0F,0x30,
		0x0D,0x06,0x03,0x55,0x04,0x03,0x0C,0x06,0x52,0x46,0x49,0x44,0x43,0x41,0x30,0x1E,
		0x17,0x0D,0x31,0x36,0x30,0x33,0x32,0x32,0x30,0x38,0x34,0x34,0x31,0x35,0x5A,0x17,
		0x0D,0x33,0x36,0x30,0x33,0x32,0x32,0x30,0x38,0x34,0x34,0x31,0x35,0x5A,0x30,0x57,
		0x31,0x0B,0x30,0x09,0x06,0x03,0x55,0x04,0x06,0x0C,0x02,0x43,0x4E,0x31,0x0B,0x30,
		0x09,0x06,0x03,0x55,0x04,0x08,0x0C,0x02,0x4A,0x53,0x31,0x0B,0x30,0x09,0x06,0x03,
		0x55,0x04,0x07,0x0C,0x02,0x4E,0x4A,0x31,0x0D,0x30,0x0B,0x06,0x03,0x55,0x04,0x0A,
		0x0C,0x04,0x42,0x45,0x4C,0x4E,0x31,0x0D,0x30,0x0B,0x06,0x03,0x55,0x04,0x0B,0x0C,
		0x04,0x42,0x45,0x4C,0x4E,0x31,0x10,0x30,0x0E,0x06,0x03,0x55,0x04,0x03,0x0C,0x07,
		0x32,0x42,0x4C,0x42,0x45,0x4C,0x4E,0x30,0x59,0x30,0x13,0x06,0x07,0x2A,0x86,0x48,
		0xCE,0x3D,0x02,0x01,0x06,0x08,0x2A,0x81,0x1C,0xCF,0x55,0x01,0x82,0x2D,0x03,0x42,
		0x00,0x04,0x41,0x62,0xB7,0x29,0x9B,0xF3,0x92,0x0B,0xBE,0xD5,0x70,0xC8,0x2E,0x3A,
		0xD0,0x0B,0x88,0x86,0x33,0x3D,0xC9,0xE5,0xE1,0xBE,0x67,0xF1,0xB9,0xF3,0x75,0x03,
		0xBA,0x9F,0xB3,0xDF,0x6C,0x1C,0x6D,0xF9,0x3F,0x78,0x70,0xFC,0xCB,0x25,0x6A,0x88,
		0x38,0x5C,0x63,0x04,0x66,0xF2,0x8C,0x77,0x01,0x50,0x9E,0x1E,0x2D,0x19,0xD6,0xCA,
		0x94,0xB5,0xA3,0x5D,0x30,0x5B,0x30,0x1F,0x06,0x03,0x55,0x1D,0x23,0x04,0x18,0x30,
		0x16,0x80,0x14,0x4C,0x32,0xB1,0x97,0xD9,0x33,0x1B,0xC4,0xA6,0x05,0xC1,0xC6,0xE5,
		0x8B,0x62,0x5B,0xF0,0x97,0x76,0x58,0x30,0x0C,0x06,0x03,0x55,0x1D,0x13,0x04,0x05,
		0x30,0x03,0x01,0x01,0xFF,0x30,0x0B,0x06,0x03,0x55,0x1D,0x0F,0x04,0x04,0x03,0x02,
		0x01,0x06,0x30,0x1D,0x06,0x03,0x55,0x1D,0x0E,0x04,0x16,0x04,0x14,0x4C,0x32,0xB1,
		0x97,0xD9,0x33,0x1B,0xC4,0xA6,0x05,0xC1,0xC6,0xE5,0x8B,0x62,0x5B,0xF0,0x97,0x76,
		0x58,0x30,0x0C,0x06,0x08,0x2A,0x81,0x1C,0xCF,0x55,0x01,0x83,0x75,0x05,0x00,0x03,
		0x49,0x00,0x30,0x46,0x02,0x21,0x00,0x88,0xDB,0xC8,0x1D,0x5B,0xD7,0xA7,0x5F,0xF3,
		0x02,0xDF,0xF0,0xDD,0x25,0x18,0xB6,0x8B,0x39,0x64,0xA1,0x12,0x60,0x46,0x31,0x73,
		0x74,0x77,0x69,0xFB,0xD5,0x30,0xEC,0x02,0x21,0x00,0xA4,0xA1,0x87,0x0D,0x9F,0x95,
		0xD1,0x86,0x05,0x6B,0xEA,0x81,0x0E,0xB0,0x88,0x06,0xD8,0xC2,0x6C,0xFE,0x15,0x8D,
		0x6B,0xBA,0x1D,0xA5,0xBF,0x61,0xC4,0x9F,0x6D,0x93  
	};             ; 
	digitalCerLen = 586;
	digitalCer = new uint8_t[digitalCerLen];
	memcpy(digitalCer,data,digitalCerLen);

	return true;
}

/*
 * 从获取的证书链中取得用户信息数据
 */
bool Sm2Certification::initUserMsg(){
	userMsg = new uint8_t[224];
	memcpy(userMsg,userdata.m_pValue,224);
	return true;
}

/*
 * 从收到的消息帧中获取证书链
 */
bool Sm2Certification::applyCerChain(){

	cerChain = new uint8_t[1024];
	memcpy(cerChain,certificatedata.m_pValue,certificatedata.m_nValue);
	cerChainLen = certificatedata.m_nValue;
	return true;
}

bool Sm2Certification::sendCerChainToSec(){
	return true;
}

/*
 * 将安全模块的授权申请打包成数字信封
 * 具体过程不详，暂未实现
 */
void Sm2Certification::notifyBindingRequestToCA(){

	readyForBindingRequest = true;

	return;
}

/*
 * 从CA服务器获取许可证信封，并解包成许可证
 * 具体过程不详，暂未实现
 */
/*void Sm2Certification::waitBindingAcceptFromCA(){
	while(!recivedForBindingAccept){
		usleep(100000);
	}

}*/

/**
 * @brief Sm2Certification::CertificationID
 * @param isTestMode，true表示以测试模式认证，false表示以正式模式认证
 * @return
 * 对安全模块进行认证
 */
int Sm2Certification::CertificationID(bool isTestMode){

	
	if(!initSm2Key()){
		printf("init Sm2 key fail!\n");
        certificationID_State = 0x0B;
        return -1;
	}
	//printf("d0...\n");
	if(!initDevNr()){
		printf("init Dev Nr fail!\n");
        certificationID_State = 0x0B;
        return -1;
	}
	//printf("d1...\n");
	if(!initDigitalCer()){
		printf("init digital cer fail\n");
        certificationID_State = 0x0B;
        return -1;
	}
	if(!initUserMsg()){
		printf("init User Msg fail!\n");
        certificationID_State = 0x0B;
        return -1;
	}
	//printf("f1...\n");
	uint8_t Rs[8] = {0};
	uint8_t Rm[8] = {0};

    //正式认证流程前需重启安全模块
    m_pIOCtrl->resetSecureModule();
    //usleep(4000000);//至少延时3秒后，才能进行正常操作包括认证，读卡等 。
    m_pM2SecComm->waitSecReadyForWork(); //等待安全模块成功启动
    /////////////////////////////////////////////////////////////////////////////////////
    //2017.06.13新加，设置测试模式
////    if(isTestMode==true){
//        printf("Start set sec model test mode!\n");
//        unsigned char buf[1] = {6};
//        STRUCT_M2SEC_FRAME *settest_frame = m_pM2SecComm->creatFrame(M2SEC_SETTEST_FRAME,buf,1);
//        MCUToSecureComm::printfSecFrame(settest_frame);
//        if(m_pM2SecComm->sendFrameToSecure(settest_frame)){
//            printf("Send set test frame success!\n");
//        }else{
//            printf("Send set test frame fail!\n");
//        }
//        m_pM2SecComm->removeFrame(settest_frame);
//        //以下读取返回
//        //等待下降沿
//        if(this->m_pM2SecComm->waitSecReadyForComm()<0){
//            printf("Sm2Certification:Error,SM comm fail!\n");
//        }
//        //读取返回响应
//        STRUCT_M2SEC_FRAME *settestack_frame = m_pM2SecComm->getFrameFromSecure(M2SEC_SETTESTACK_FRAME);
//        if(settestack_frame==NULL){
//            printf("Get set test ack from Secure fail!\n");
//        }else{
//            if(settestack_frame->DataBuf==NULL){
//                printf("set test ack is NULL!\n");
//            }else{
//                if(settestack_frame->OperId==6){
//                    if(settestack_frame->DataBuf[0]==0){
//                        printf("set secmodel test mode success!\n");
//                    }else{
//                        printf("set secmodel test mode fail!\n");
//                    }
//                }
//            }
//            MCUToSecureComm::removeFrame(settestack_frame);
//        }
//    }
    /////////////////////////////////////////////////////////////////////////////////////
    STRUCT_M2SEC_FRAME *papplyrs_frame = m_pM2SecComm->creatFrame(M2SEC_APPLYRS_FRAME,NULL,0);
	//printf("d0\n");
	if(m_pM2SecComm->sendFrameToSecure(papplyrs_frame)){
		printf("Send apply rs frame success!\n");
	}else{
		printf("Send apply rs frame fail!\n");
		m_pM2SecComm->removeFrame(papplyrs_frame);
        certificationID_State = 0x0B;
        return -1;
	}
	//printf("d1\n");
	m_pM2SecComm->removeFrame(papplyrs_frame);
	//printf("f3...\n");
	//以下读取返回的随机数
	//等待下降沿
	if(this->m_pM2SecComm->waitSecReadyForComm()<0){
		printf("Sm2Certification:Error,SM comm fail!\n");
        certificationID_State = 0x0B;
        return -1;
	}
	//printf("d2\n");
	//读取返回的随机数
	STRUCT_M2SEC_FRAME *resrs_frame = m_pM2SecComm->getFrameFromSecure(M2SEC_RESRS_FRAME);

	if(resrs_frame==NULL){
		printf("Get RS from Secure fail!\n");
        certificationID_State = 0x0B;
        return -1;
	}else{
		//printf("f0\n");
		if(resrs_frame->DataBuf==NULL){
			printf("RS data is NULL!\n");
			delete resrs_frame;
            certificationID_State = 0x0B;
            return -1;
		}
		memcpy(Rs,resrs_frame->DataBuf,8);
		//printf("d4\n");
		delete resrs_frame;
		//这里应进行返回数据帧是否是随机数请求响应帧的判断，这里暂时略掉不做此判断
		printf("Get Rs success!\n");
		printf("Rs is: ");
		for(int i=0;i<8;i++){
			printf("%2x,",Rs[i]);
		}
		printf("\n");
	}
	//================================================//
	//以下产生数字签名
	//生成Rm随机数，因生成方法不确定，这里暂定为每字节随机生成
	srand(randNum++);
	for(int i=0;i<8;i++){
		Rm[i] = rand()%256;
	}
	uint8_t needsigndata[32] = {0x00};
	memcpy(needsigndata,Rm,8); //读写设备随机数
	memcpy(needsigndata+8,Rs,8); //向安全模块请求的随机数
	memcpy(needsigndata+16,devNr,8); //读写设备序列号

	uint8_t hash[32] = {0x00};
	for(int i=0;i<32;i++){
		hash[i] = needsigndata[31-i];
	}
	uint8_t sign_cr[32] = {0x00}; //签名第一部分
	int crlen = 32;
	uint8_t sign_cs[32] = {0x00}; //签名第二部分
	int cslen = 32;
	sm2_sign(hash,32, sm2PrivKey,32, sign_cr, &crlen, sign_cs, &cslen);
	//===================================================================//
	//以下发送数字签名
	uint8_t cerbuf[MAX_M2SECFRAME_LEN];
	int pos = 0;
	memcpy(cerbuf,needsigndata,32);//放入认证数据
	pos += 32;
	//放入数字签名，按以前的程序，先对签名进行反序
	uint8_t signtemp[32];
	for(int i=0;i<32;i++){
		signtemp[i] = sign_cr[31-i];
	}
	memcpy(cerbuf+pos,signtemp,32);
	pos += 32;
	for(int i=0;i<32;i++){
		signtemp[i] = sign_cs[31-i];
	}
	memcpy(cerbuf+pos,signtemp,32);
	pos += 32;
	//放入密钥证书
	memcpy(cerbuf+pos,digitalCer,digitalCerLen);
	pos += digitalCerLen;
	//printf("pos=%d,digitalCerlen=%d\n",pos,digitalCerLen);
	//生成认证数据帧
	STRUCT_M2SEC_FRAME *pframe = m_pM2SecComm->creatFrame(M2SEC_CER_FRAME,cerbuf,pos);
	if(!m_pM2SecComm->sendFrameToSecure(pframe)){
		printf("Send CER frame to Secure fail!\n");
		m_pM2SecComm->removeFrame(pframe);
        certificationID_State = 0x0B;
        return -1;
	}else{
		printf("Send CER frame to Secure success!\n");
		m_pM2SecComm->removeFrame(pframe);
	}
	//等待中断，即等待安全模块返回
	if(this->m_pM2SecComm->waitSecReadyForComm(10000)<0){
		printf("Sm2Certification:Error,SM comm fail!\n");
        certificationID_State = 0x0B;
        return -1;
	}
	int rescer = 0; //认证结果
	pframe = m_pM2SecComm->getFrameFromSecure(M2SEC_RESCER_FRAME);
	if(pframe==NULL){
		printf("Get res Cer from Secure fail!\n");
        certificationID_State = 0x0B;
        return -1;
	}else{
		printf("Get res Cer from Secure success!\n");
		rescer = pframe->DataBuf[0];
		printf("Certification res=%d\n",rescer);
		switch(rescer){
		case 0:
			printf("Certification success!\n");
			break;
		case 1:
			printf("Check signed data fail!\n");
			break;
		case 2:
			printf("Check rand data fail!\n");
			break;
		case 3:
			printf("Secure module is not activated!\n");
			break;
		case 4:
			printf("Secure module has activated by other UHF device!Cannot activated again!\n");
			break;
		case 0x0a:
			printf("UHF device vendor code is error!\n");
			break;
		}
	}
  certificationID_State = rescer;
	
	//释放认证所点用的内存
	delete [] sm2PubKey_x;
	delete [] sm2PubKey_y;
	delete [] sm2PrivKey;
	delete [] digitalCer;
	delete [] cerChain;
	delete [] userMsg;
	////////////////////////////////
	return rescer;

}

bool Sm2Certification::getCerFromSecModule(){
	int rescer = 0; //激活结果

	initUserMsg();
	this->applyCerChain();
	//向安全模块发送证书链。
	STRUCT_M2SEC_FRAME *pframe = m_pM2SecComm->creatFrame(M2SEC_CERCHAIN_FRAME,cerChain,cerChainLen);
	if(!m_pM2SecComm->sendFrameToSecure(pframe)){
		printf("Send CerChain frame to Secure fail!\n");
		m_pM2SecComm->removeFrame(pframe);
		return false;
	}else{
		printf("Send CerChain frame to Secure success!\n");
		m_pM2SecComm->removeFrame(pframe);
	}

	//等待中断，即等待安全模块返回
	if(this->m_pM2SecComm->waitSecReadyForComm(10000)<0){
		printf("Sm2Certification:Error,SM comm fail!\n");
		return false;
	}
	//读取发送证书链返回
	pframe = m_pM2SecComm->getFrameFromSecure(M2SEC_CERACK_FRAME);
	if(pframe==NULL){
		printf("Send CerChain to SecModule fail!\n");
		return false;
	}else{
        MCUToSecureComm::printfSecFrame(pframe);
		//非证书链返回帧或结果为非零
		if(pframe->OperId!=0x05||pframe->DataBuf[0]!=0x00){
			printf("Send Cerchain to SecModule fail!\n");
			m_pM2SecComm->removeFrame(pframe);
			return false;
		}else{
			printf("Send Cerchain to SecModule success!\n");
		}
	}
	//向安全模块发送用户信息
	pframe = m_pM2SecComm->creatFrame(M2SEC_USERMSG_FRAME,userMsg,224);
	if(!m_pM2SecComm->sendFrameToSecure(pframe)){
		printf("Send user msg fail!\n");
		m_pM2SecComm->removeFrame(pframe);
		return false;
	}else{
		printf("Send user msg succes!\n");
		m_pM2SecComm->removeFrame(pframe);
	}
	//等待中断，即等待安全模块返回
	if(this->m_pM2SecComm->waitSecReadyForComm(10000)<0){
		printf("Sm2Certification:Error,SM comm fail!\n");
		return false;
	}
	//读取安全模块给CA的授权
	//uint8_t *sectocabuf;
	pframe = m_pM2SecComm->getFrameFromSecure(M2SEC_SEC2CA_FRAME);
	if(pframe==NULL){
		printf("Get secure to ca frame fail!\n");
		return false;
	}else{
        MCUToSecureComm::printfSecFrame(pframe);
		printf("Get secure to ca frame success!\n");
		int contentlen = m_pM2SecComm->getFrameContenLen(pframe);
		if(contentlen<=0){
			m_pM2SecComm->removeFrame(pframe);
			return false;
		}
		printf("contentlen=%d\n",contentlen);
		//printf("A0.......................\n");
		llrp_u8v_t bindingrequestdata(contentlen);
		//printf("A1.......................\n");
		memcpy(bindingrequestdata.m_pValue,pframe->DataBuf+1,contentlen-1); //去掉第一个是否再次激活的标识字节

		//printf("A2.......................\n");
		m_pM2SecComm->removeFrame(pframe);
		//printf("A3.......................\n");
		//将授权申请打包成数字信封转发给后台服务器
		bindingRequestData = bindingrequestdata;
		//printf("A4.......................\n");
		this->notifyBindingRequestToCA();
		//printf("A5.......................\n");
		return true;
	}
	//==================================================//

}

bool Sm2Certification::activeSecModule(){

	//转发许可证给安全模块
    printf("bindingAcceptData length is:\n",bindingAcceptData.m_nValue);
    printf("bindingAcceptData content is:\n");
    for(int i=0;i<bindingAcceptData.m_nValue;i++){
        printf("%02x,",bindingAcceptData.m_pValue[i]);
    }
    printf("\n");

	STRUCT_M2SEC_FRAME *pframe = m_pM2SecComm->creatFrame(M2SEC_LICENSE_FRAME,bindingAcceptData.m_pValue,bindingAcceptData.m_nValue);
	if(!m_pM2SecComm->sendFrameToSecure(pframe)){
		printf("Send license to secure module fail!\n");
		m_pM2SecComm->removeFrame(pframe);
		return false;
	}else{
        printf("Send license to secure success!\n");
		m_pM2SecComm->removeFrame(pframe);
	}

	//读取安全模块的激活返回，如完成激活则再次进行认证过程。
	//等待中断，即等待安全模块返回
    if(this->m_pM2SecComm->waitSecReadyForComm(10000)<0){
		printf("Sm2Certification:Error,SM comm fail!\n");
		return false;
	}
	int resactive = 0; //激活结果
	pframe = m_pM2SecComm->getFrameFromSecure(M2SEC_RESACTIVE_FRAME);
	if(pframe==NULL){
		printf("Get res active from Secure fail!\n");
		return false;
	}else{
		printf("Get res active from Secure success!\n");
        bool success = false;
        if(pframe->Type == 0x82)
        {
            printf("Get res active type from Secure is 0x82,pfram is:\n");
            MCUToSecureComm::printfSecFrame(pframe);
            return false;
        }
//        printf("111111111111111111\n");
//        printf("DataBuf[0]=%02x\n",pframe->DataBuf[0]);
		resactive = pframe->DataBuf[0];
//        printf("resactive:%d\n",resactive);
		switch(resactive){
		case 0:
			printf("Active success!\n");
			success = true;
			break;
		case 1:
			printf("Active license decrypt fail!\n");
			break;
		case 2:
			printf("Active license sign check fail!\n");
			break;
		case 3:
			printf("Active Sn is not same!\n");
			break;
		}
		return success;
	}
}

void Sm2Certification::sendBindingRequest(llrp_u8v_t &requestdata,Base_Comm *pComm){
    CDeviceBinding *pmessage = (CDeviceBinding*)HbFrame_Operation::genMessage(DeviceBinding,0);
    pmessage->setBindingType(1);
    pmessage->setBindingData(requestdata);

    if(!pComm->immediateSendMessage(pmessage)){
        printf("Send binding request data fail!\n");
    }else{
        printf("Send binding request data success!\n");
    }
    delete pmessage;
}

/**
 * @brief Sm2Certification::dealMessage
 * @param pMessage
 * @param commID
 * @return，返回小于0表示未处理，大于等于0表示已处理
 */
int Sm2Certification::dealMessage(CMessage *pMessage, Base_Comm *pComm){
		llrp_u32_t messageid = pMessage->getMessageID();
    switch(pMessage->m_pType->m_TypeNum){
    case DeviceBindingAck: //激活第二步
    {
        CDeviceBindingAck *pbindingack = ((CDeviceBindingAck*)pMessage);
        CStatus *pbindstatus = pbindingack->getStatus();
        CMessage *pack = NULL;
        CParameter *pstatus = NULL;
        if(pbindstatus->getStatusCode()==StatusCode_M_Success){
            printf("DeviceBindingAck:CA:Binding success!\n");
            this->bindingAcceptData = pbindingack->getBindingData();
            printf("DeviceBindingAck:start active sec module!\n");
            if(this->activeSecModule()){
                printf("Reader:Active SecModule Success!\n");
                pack = HbFrame_Operation::genMessage(DeviceBindingResultNotification,0);
                pstatus = HbFrame_Operation::genParam(Status,0,NULL);
                ((CStatus*)pstatus)->setStatusCode(StatusCode_M_Success);
                HbFrame_Operation::addParamToMessage(pstatus,pack);
                if(!pComm->immediateSendMessage(pack)){
                    printf("Send DeviceBindingResultNotification fail!\n");
                }else{
                    printf("Send DeviceBindingResultNotification success!\n");
                }
            }else{
                printf("Reader:Active SecModule fail!\n");
                pack = HbFrame_Operation::genMessage(DeviceBindingResultNotification,0);
                pstatus = HbFrame_Operation::genParam(Status,0,NULL);
                ((CStatus*)pstatus)->setStatusCode(StatusCode_M_UnknownField);
                HbFrame_Operation::addParamToMessage(pstatus,pack);
                if(!pComm->immediateSendMessage(pack,messageid)){
                    printf("Send DeviceBindingResultNotification fail!\n");
                }else{
                    printf("Send DeviceBindingResultNotification success!\n");
                }
            }

        }else{
            printf("CA:Binding fail!\n");
            pack = HbFrame_Operation::genMessage(DeviceBindingResultNotification,0);
            pstatus = HbFrame_Operation::genParam(Status,0,NULL);
            ((CStatus*)pstatus)->setStatusCode(StatusCode_M_UnknownField);
            HbFrame_Operation::addParamToMessage(pstatus,pack);
            if(!pComm->immediateSendMessage(pack,messageid)){
                printf("Send DeviceBindingResultNotification fail!\n");
            }else{
                printf("Send DeviceBindingResultNotification success!\n");
            }
        }
        delete pack;
    }
        break;
    case DeviceCertificateConfig: //激活第一步
    {
        printf("Received DeviceCertificateConfig...!\n");

        CMessage *pack = NULL;
        CParameter *pstatus = NULL;
        CDeviceCertificateConfig *pDeviceCertificateConfig;
        pDeviceCertificateConfig = (CDeviceCertificateConfig *)pMessage;
        memcpy(this->certificatedata.m_pValue,pDeviceCertificateConfig->getCertificateData().m_pValue,pDeviceCertificateConfig->getCertificateData().m_nValue);
        this->certificatedata.m_nValue = pDeviceCertificateConfig->getCertificateData().m_nValue;
        memcpy(this->userdata.m_pValue,pDeviceCertificateConfig->getUserData().m_pValue,pDeviceCertificateConfig->getUserData().m_nValue);
        this->userdata.m_nValue = pDeviceCertificateConfig->getUserData().m_nValue;
        pack = HbFrame_Operation::genMessage(DeviceCertificateConfigAck,0);
        pstatus = HbFrame_Operation::genParam(Status,0,NULL);
        ((CStatus*)pstatus)->setStatusCode(StatusCode_M_Success);
        HbFrame_Operation::addParamToMessage(pstatus,pack);
        pComm->immediateSendMessage(pack,messageid);
        this->finishCerChain = 1;
        delete pack;

        if(this->getCerFromSecModule()){
            printf("Reader:Get Cer from Sec Module success!\n");
            if(this->readyForBindingRequest==true){
                this->readyForBindingRequest = false;
                this->sendBindingRequest(bindingRequestData,pComm);
            }
        }else{
            printf("Reader:Get Cer from Sec Module fail!\n");
        }
    }
        break;
    default: //默认返回未处理
        return -1;
    }
    return 0;
}

int Sm2Certification::dealMfeMessage(CMessage *pMessage,Base_Comm *pComm){
    //printf("dealMfeMessage........................!\n");
    llrp_u32_t messageid = pMessage->getMessageID();
		if(pMessage->m_pType->m_TypeNum!=ManufacturerCommand){
        return -1;
    }
    CManufacturerCommand *pcommd = (CManufacturerCommand*)pMessage;
    llrp_u8v_t bufs = pcommd->getByteStream();

    STRUCT_ManufacturerFrame manuframe;
    manuframe.OperID = bufs.m_pValue[0];
    manuframe.Datalen_H = bufs.m_pValue[1];
    manuframe.Datalen_L = bufs.m_pValue[2];
    manuframe.DataBuf = bufs.m_pValue+3;

    switch(manuframe.OperID){

    case 0x8E://查询安全模块激活情况
    {
        CManufacturerReport *pack =  (CManufacturerReport *)ExtendHbFrame_Operation::genMessage(ManufacturerReport,0);

        llrp_u8v_t bytes = llrp_u8v_t(4);
        bytes.m_pValue[0] = 0x0E;
        bytes.m_pValue[1] = 0x01;
        bytes.m_pValue[2] = 0x00;
        bytes.m_pValue[3] = certificationID_State;
        pack->setByteStream(bytes);
        if(pComm->immediateSendMessage(pack,messageid)){
            printf("send ack message success!\n");
        }else{
            printf("send ack message fail!\n");
        }
        delete pack;
    }
        break;
    case 0x96: //进入或退出测试模式
    {
        CManufacturerReport *pack =  (CManufacturerReport *)ExtendHbFrame_Operation::genMessage(ManufacturerReport,0);

        llrp_u8v_t bytes = llrp_u8v_t(4);
        bytes.m_pValue[0] = 0x16;
        bytes.m_pValue[1] = 0x01; //放入长度
        bytes.m_pValue[2] = 0x00;
        if(manuframe.DataBuf[0]==0){//进入测试模式
            if(this->CertificationID(true)>=0){
                bytes.m_pValue[3] = 0;
            }else{
                bytes.m_pValue[3] = 1;
            }
        }else{//退出测试模式
            if(this->CertificationID(false)>=0){
                bytes.m_pValue[3] = 2;
            }else{
                bytes.m_pValue[3] = 3;
            }
        }
        pack->setByteStream(bytes);
        if(pComm->immediateSendMessage(pack,messageid)){
            printf("send ack message success!\n");
        }else{
            printf("send ack message fail!\n");
        }
        delete pack;

    }
        break;
    default:
        return -1;
    }
    return 0;

}