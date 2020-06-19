#include "base_comm.h"
#include <stdio.h>
#include <time.h>
#include "read_manage.h"
#include "main_application.h"
//#include "extendllrp/ExtendLLRP.h"
//#include "param_manager.h"

Base_Comm::Base_Comm(int commid)
{
    commID = commid;

    keepaliveAckOverTime = 0;
    //gettimeofday(&lasttime,NULL);
    m_KeepaliveTriggerType = KeepaliveTriggerType_NON_HEART_BEAT; //通信链路默认无心跳

    //recFrameBuf = new unsigned char [MAX_RX_LEN];

    m_ReadyForRecv = false;
    //m_ReadyForSend = false;
    //m_ImmSendMessage = NULL;
    
		m_pRecvMessage = NULL;
		m_MessageID = 0;

}

Base_Comm::~Base_Comm(){

}

void Base_Comm::KeepAlive(){
    keepaliveAckOverTime++;
    if(keepaliveAckOverTime>3){ //心跳包超时，则重置连接
        keepaliveAckOverTime = 0;
        printf("Comm %d : keepaliveAck overtime!\n",commID);
        this->stopCommLink();
    }else{
        CKeepalive * pkeepalive = (CKeepalive*)HbFrame_Operation::genMessage(Keepalive,0);
        if(immediateSendMessage(pkeepalive)){
            //printf("Comm %d : send keepalive success!\n",commID);
        }else{
            //printf("Comm %d :send keepalive fail!\n",commID);
        }
        delete pkeepalive;
    }
}

/**
 * @brief Base_Comm::sendConnectionEvent
 * 注意，这里的发送只是放入缓存，并未实际发送。
 */
void Base_Comm::sendConnectionEvent(){
    //2017.07.08新加，建链日志
    string des = "Comm ";
    //des = des + to_string(commID);
    //des = des + " connected!";
    //g_pMainApplication->logProcess.addLog(LOGTYPE_RUN_LOG,COMM_LINK_LIVE,des.c_str());
    ////////////////////////////////////////////////////////////////////////////////////////////////////////


    CMessage *pmessage = (CMessage*)HbFrame_Operation::genMessage(DeviceEventNotification,0);

    CUTCTimestamp *ptimestamp = (CUTCTimestamp*)HbFrame_Operation::genParam(UTCTimestamp,0,NULL);
    //struct timeval now;
    //gettimeofday(&now,NULL);
    //llrp_u64_t utcmsecs = now.tv_sec*1000llu + now.tv_usec/1000llu;
    //ptimestamp->setMicroseconds(utcmsecs);

    CConnectionAttemptEvent *pconnectevent = (CConnectionAttemptEvent*)HbFrame_Operation::genParam(ConnectionAttemptEvent,0,NULL);
    pconnectevent->setConnectionStatus(ConnectionStatus_Success);

    HbFrame_Operation::addParamToMessage(ptimestamp,pmessage);
    HbFrame_Operation::addParamToMessage(pconnectevent,pmessage);

    //printf("C0....................\n");
    if(!immediateSendMessage(pmessage)){
        printf("Send connection event fail!\n");
    }else{
        printf("Send connection event success!\n");
        this->clearKeepOverTimer();//2016-12-29新加，一旦发送键链通知成功，则清零心跳超时。
    }
    //printf("a0......................\n");
    //delete pmessage;
    //printf("a1......................\n");
}


/**
 * @brief Base_Comm::sendFrame
 * @param pmessage
 * @return
 * 将消息以通信帧形式发送出去。发送完毕后，即删除消息
 */
bool Base_Comm::sendFrame(CMessage *pmessage){
    if(pmessage==NULL){
        return false;
    }
//    //printf("Sended Message name is %s\n",pmessage->m_pType->m_pName);
//		uint8_t versionnum[60];
//		uint8_t numL = 15;
//		//printf("numl :%d",numL);					
//		g_pMainApplication->m_read_manage->GetDerviceVersion(versionnum,numL);
//		//uint8_t p[] = "BL1810302002";
//    llrp_u64_t sn = strToHex(versionnum+3);//"BL1810302002";//0x424c120A1E140200;//Param_Manager::convertDeviceSN(g_pMainApplication->deviceSN);
//		             
    pmessage->setDeviceSN(g_pMainApplication->Devicesn);

    unsigned char sendbuf[MAX_TX_LEN];
    CFrameEncoder frameencoder(sendbuf,MAX_TX_LEN);
    frameencoder.encodeElement(pmessage);
    int msglen = frameencoder.getLength();

    return sendCommData(sendbuf,msglen);
}


/**
 * @brief Base_Comm::recvFrame
 * @return
 * 接收数据帧，接收时，会自动对缓存区内的多帧数据进行分割处理。
 * 返回缓存区内第一个数据帧
 */
CMessage* Base_Comm::recvFrame(){
		
		CFrameExtract lastframeextract(recFrameBuf,recFrameLen);  //从最后一次收到的数据缓冲区中，看看能否提取一条完整的消息
		if(lastframeextract.m_eStatus==CFrameExtract::READY){

				llrp_u32_t messageLength = lastframeextract.m_MessageLength + 19u;  //保存要从缓冲区取多少个字节的数据
				if(messageLength>recFrameLen){
					return NULL;
				}
				
		
				CMessage * pmessage = HbFrame_Operation::getMessageFromBuf(recFrameBuf,messageLength); //注意这里返回的消息也有可能是NULL
				
				//printf("message id is %d\n:",pmessage->getMessageID());
				//printf("%s\n",pmessage->m_pType->m_pName);
				
				if(pmessage!=NULL){ //确实能解出
					//HbFrame_Operation::printMessage(pmessage);
					return pmessage;
				}
		}else{
				printf("lastframeextract.m_eStatus :%d",lastframeextract.m_eStatus);
				printf("received part message!\n");
				//printf("currentBufIndex=%d\n",currentBufIndex);
		}
		///////////////////////////////////////////////////////////////////////////////////////////////////////////

    return NULL;
}

/*CMessage *Base_Comm::getMessageFromBuf(unsigned char *buf,int messageLength){
    CTypeRegistry * ptyperegistry = getTheTypeRegistry();

    //为自定义消息添加
    tmp_enrollCoreTypesIntoRegistry (ptyperegistry);

    CFrameDecoder framedecoder(ptyperegistry,buf,messageLength);
    CMessage* decodemessage = framedecoder.decodeMessage();

    if(decodemessage==NULL){
        printf("Comm %d : decode message error,errcode =%d\n",framedecoder.m_ErrorDetails.m_eResultCode);
    }

    delete ptyperegistry;

    return decodemessage;
}*/

/**
 * @brief Base_Comm::immediateSendMessage
 * @param pmessage
 * @return
 * 立即发送消息。发送时，会复制一个消息。原消息需手工删除
 */
bool Base_Comm::immediateSendMessage(CMessage *pmessage){

	return this->sendMessage(pmessage);
}

bool Base_Comm::immediateSendMessage(CMessage *pmessage,llrp_u32_t messageID){

	return this->sendMessage(pmessage,messageID);
}

bool Base_Comm::sendMessage(CMessage *pMessage){
	return this->sendMessage(pMessage,0);
}

/**
 * @brief Base_Comm::sendMessage
 * @param pMessage
 * @param messageID
 * @return
 */
bool Base_Comm::sendMessage(CMessage *pMessage,llrp_u32_t messageID){

    pMessage->setMessageID(messageID);

    if(this->sendFrame(pMessage)==true){
				return true;
		 }else{
				return false;
		 }
}

/**
 * @brief Base_Comm::getIdleSendBufCount
 * @return
 * 获取空闲的发送缓存条数。
 */
int Base_Comm::getIdleSendBufCount(){
	return 0;
}

void Base_Comm::keepaliveprocess(){

    //心跳
    if(this->m_KeepaliveTriggerType==KeepaliveTriggerType_PERIODIC_HEART_BEAT){
        /*gettimeofday(&currenttime,NULL);
        if(((currenttime.tv_sec*1000000+currenttime.tv_usec)-(lasttime.tv_sec*1000000+lasttime.tv_usec)) >= this->m_KeepalivePeriodicTriggerValue*1000)
        {
            lasttime = currenttime;
            this->KeepAlive();
        }*/
    }

}


void Base_Comm::run(){
    if(this->isReadyForRecv()==true){
					
				this->m_ReadyForRecv = false;
			
        CMessage *pmessage = this->recvFrame();
				m_pRecvMessage = pmessage;
				/*if(pmessage->m_pType->m_TypeNum==KeepaliveAck){//是心跳包直接处理，非心跳包放入帧缓存
						printf("Comm %d : received keep alive ack!\n",commID);
						this->clearKeepOverTimer();
						delete pmessage;
				}else{
						m_pRecvMessage = pmessage;
				}*/

    }
    //////////////////////////////////////////////////////////
    //this->keepaliveprocess();
}
