#ifndef BASE_COMM_H
#define BASE_COMM_H

#include <queue>
using namespace std;

#include "HbFrame_Operation.h"
#include <time.h>

#define MAX_RECQUEUE_SIZE 10
#define MAX_SENDQUEUE_SIZE 10

/**
 * @brief The Base_Comm class
 * by lijin 2017.02.17
 * 通信类的基础类，主要完成通信协议的解析，打包功能，
 * 完成通信链路的建立，断开等操作。
 * 并对收到和待发的通信数据进行以缓存方式进行管理。
 */

class Base_Comm
{
public:
    Base_Comm(int commid);
    ~Base_Comm();

    int commID;
protected:
	CMessage *m_pRecvMessage; //收到的消息，为空时表示没有消息。
    //queue<CMessage *> m_RecvMessages; //待处理消息帧队列
    //queue<CMessage *> m_SendMessages;//待发送消息帧队列
    //CMessage *m_ImmSendMessage;

protected: //以下是子类必须实现的纯虚函数
    virtual bool sendCommData(unsigned char *sendbuf,int sendlen)=0; //该函数应对Ready状态做相应改变
    //virtual bool immediateSendCommData(unsigned char *sendbuf,int sendlen)=0; //因为可通过在队列头插入数据，来实现立即发送，故不再需要该函数
    virtual int recvCommData(unsigned char *recbuf,int reclen)=0;//该函数应对Ready状态做相应改变
public:
    virtual void startCommLink()=0;
    virtual void stopCommLink()=0;
protected:
    void sendConnectionEvent();
    void KeepAlive();
    int keepaliveAckOverTime; //心跳超时记数，单位是心跳包的单位间隔，即几个心路间隔

protected:
    //unsigned char *recFrameBuf; //收到的数据帧数据，配合recvFrame使用
    unsigned char recFrameBuf[MAX_RX_LEN];
		int recFrameLen; //当前收到的帧长度
		//int currentBufIndex; //当前缓存位置索引，用以指示收到的数据应放在缓存的那个位置，总是指向缓存的未尾

protected:
    //bool m_ReadyForSend; //标识通信链路已准备好发送帧
    bool m_ReadyForRecv; //标识通信链路已准备好接收帧
public:
    /*bool isReadyForSend(){
        return m_ReadyForSend;
    }*/
    bool isReadyForRecv(){
        return m_ReadyForRecv;
    }

private:
    llrp_u32_t m_MessageID;
    bool sendFrame(CMessage *pmessage);
    CMessage* recvFrame();
    //int reorganizeFrameBuf(); /*重组缓存区内的数据，返回重组后缓存区内的完整消息帧*/
    //bool hasNeedmore; //标示当前有needmore架构
    ///int needmoreCount; //对needmore计数，用以控制needmore超时

    //CMessage *getMessageFromBuf(unsigned char *buf,int messageLength); //从BUF中获取消息

    /*inline void needmoreInc(){
      if(hasNeedmore==true&&needmoreCount<10000){
          needmoreCount++;
      }
    };*/
public:
    bool immediateSendMessage(CMessage *pmessage); //通过在队列头插入数据，来实现立即发送
    bool immediateSendMessage(CMessage *pmessage,llrp_u32_t messageID); //通过在队列头插入数据，来实现立即发送
		bool sendMessage(CMessage *pMessage);
    bool sendMessage(CMessage *pMessage,llrp_u32_t messageID);
    //CMessage *popRecvMessages();
    int getIdleSendBufCount();
private:
    //CMessage * frontSendMessages();
    //void popSendMessages();
    //void pushRecvMessage(CMessage *pMessage);

private:
    EKeepaliveTriggerType m_KeepaliveTriggerType;
    llrp_u32_t m_KeepalivePeriodicTriggerValue; //心跳周期，单位毫秒
    //struct timeval currenttime; //用于心跳的全局变量
    //struct timeval lasttime; //用于心跳的全局变量
    void keepaliveprocess(); //心跳
public:
    inline void setKeepaliveType(EKeepaliveTriggerType triggertype,llrp_u32_t period){
        this->m_KeepaliveTriggerType = triggertype;
        this->m_KeepalivePeriodicTriggerValue = period;
    }
    inline void clearKeepOverTimer(){
        this->keepaliveAckOverTime = 0;
    }
		
protected:
		//virtual bool isRecFinish()=0;
    //virtual bool isSendReady()=0;
		virtual void run();

public:
		CMessage *getRecMessage(){
			return m_pRecvMessage;
		}
		void deleteRecMessage(){
			delete m_pRecvMessage;
			m_pRecvMessage = NULL;
		}

};

#endif // BASE_COMM_H
