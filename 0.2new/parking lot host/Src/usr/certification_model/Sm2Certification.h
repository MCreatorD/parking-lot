/*
 * Sm2Certification.h
 *
 *  Created on: 2016-3-10
 *      Author: root
 */

#ifndef SM2CERTIFICATION_H_
#define SM2CERTIFICATION_H_

#include <stdint.h>


#include "model_base.h"
#include "MCUToSecureComm.h"
#include "IOCtrl.h"
#include "HbFrame_Operation.h"
#include "base_comm.h"

/**
 * @brief The Sm2Certification class
 * by lijin,2017.04.28
 * 安全模块认证类，负责对安全认证，负责对安全认证的消息进行处理。
 */

class Sm2Certification {
public:
	Sm2Certification();
	~Sm2Certification();

private:
	uint8_t *sm2PubKey_x; //公钥X轴
	uint8_t *sm2PubKey_y; //公钥Y轴
	uint8_t *sm2PrivKey;  //私钥
	uint8_t devNr[8];   //读写设备序列号，前2个字节由CA服务器指定，后6个字节可自定义
	uint8_t *digitalCer; //数字证书，因为不定长，所以用指针表示
	int digitalCerLen; //数字证书长度
	uint8_t *cerChain; //证书链，长度未知，所以要动态分配内存
	int cerChainLen; //证书链长度
	uint8_t *userMsg; //用作激活用的用户信息数据
private:
	MCUToSecureComm *m_pM2SecComm;
	IOCtrl *m_pIOCtrl;
private:
	bool initSm2Key();
	bool initDevNr();
	bool initDigitalCer();
	bool initUserMsg();
	bool applyCerChain(); //申请证书链
	bool sendCerChainToSec();//发送证书链给安全模块
	void notifyBindingRequestToCA(); //提示给CA服务器的授权申请已准备好
	//void waitBindingAcceptFromCA(); //从CA服务器获取许可证的数字信封，再解包出许可证
public:
	inline void setM2SecComm(MCUToSecureComm *pM2SecComm){
		m_pM2SecComm = pM2SecComm;
	};
	inline void setIOCtrl(IOCtrl *pIOCtrl){
		m_pIOCtrl = pIOCtrl;
	}
    int CertificationID(bool isTestMode); //身份认证
	bool getCerFromSecModule(); //从安全模块获取证书链
	bool activeSecModule(); //激活安全模块
     llrp_u8_t certificationID_State; //安全模块激活状态标志

public:
	llrp_u8v_t certificatedata;
	llrp_u8v_t userdata;

	llrp_u8v_t bindingRequestData;
	llrp_u8v_t bindingAcceptData;
public:
	int finishCerChain; //收到证书链标记
	bool readyForBindingRequest; //是否准备好发送绑定请求
	//bool recivedForBindingAccept; //是否接收到绑定接受

///////////////////////////////////////////////////////////////////////////
private:
    void sendBindingRequest(llrp_u8v_t &requestdata,Base_Comm *pComm);
private:
		
unsigned long int randNum; //用以产生随机数种子
public:

    int dealMessage(CMessage *pMessage, Base_Comm *pComm); //处理llrp消息
		int dealMfeMessage(CMessage *pMessage,Base_Comm *pComm);
};

#endif /* SM2CERTIFICATION_H_ */
