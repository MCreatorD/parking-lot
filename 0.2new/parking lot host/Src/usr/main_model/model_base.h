#ifndef MODEL_BASE_H
#define MODEL_BASE_H


#include "HbFrame_Operation.h"
#include "base_comm.h"

/**
 * @brief The Model_Base class
 * by lijin,2017.11.23，新加模块基础类。
 */

class Model_Base
{
public:
    Model_Base();
    ~Model_Base();
protected:
		virtual void run()=0; //需要放到线程中运行的程序
    virtual int dealMessage(CMessage *pMessage,Base_Comm *pComm)=0; //纯虚函数，要求返回值-1表示未处理，0表示已处理。
		virtual int dealMfeMessage(CMessage *pMessage,Base_Comm *pComm); //处理厂家自义消息，不要求子类必须实现该类
//protected:
//    bool (*sendMessageFunc_ID)(CMessage *,int,llrp_u32_t) ; //参数为消息，通信链路ID，消息ID，主要用以发送响应消息。
//    bool (*sendMessageFunc)(CMessage *,int) ;//参数为消息，通信链路ID，主要用以发送自发消息。
//public:
//    inline void setSendMessage_ID(bool (*pFunc)(CMessage *,int,llrp_u32_t) ){
//        sendMessageFunc_ID = pFunc;
//    }
//    inline void setSendMessage(bool (*pFunc)(CMessage *,int) ){
//        sendMessageFunc = pFunc;
//    }
};

#endif // MODEL_BASE_H
