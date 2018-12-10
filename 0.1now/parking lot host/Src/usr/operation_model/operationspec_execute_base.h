#ifndef OPERATIONSPEC_EXECUTE_BASE_H
#define OPERATIONSPEC_EXECUTE_BASE_H

#include <queue>
using namespace std;

#include "tag_selectspec.h"
#include "tag_accessspec.h"
#include "OpspecResult.h"
#include "tag_selectaccessresult.h"
#include "rf_oper_base.h"


//上报消息数量管理
#define resualt_num  5


/**
 * @brief The OperationSpec_Execute_Base class
 * 2017.10.16,by lijin
 * 规则执行类的基类
 */

class OperationSpec_Execute_Base
{
public:
    OperationSpec_Execute_Base();
    ~OperationSpec_Execute_Base();

protected:
    Tag_SelectSpec *m_pExecSelectSpec;
    queue<OpspecResult*> m_OpResults;
    queue<Tag_SelectAccessResult*> m_SelectAccessResults;


		Rf_Oper_Base *m_pRfOper;

public:
	  inline Rf_Oper_Base * getRfOper(){
			return m_pRfOper;
		}

protected:
    MCUToSecureComm *m_pMCUToSecureComm;
    bool isIdle; //当前是否空闲的标记

public:
		int m_SelectStep;   //Select操作步进记数

public:
    virtual void run();

protected:

    STRUCT_M2SEC_FRAME *getSimFrame();
    void pushOpResult(OpspecResult *pOpResult);
    void pushSelectAccessResult(Tag_SelectAccessResult *pSelectAccessResult);
    bool isSelectStop();
    bool isAntennaStop(CAntennaSpec *pAntennaSpec);
    void updateSelectSpecState(Tag_SelectSpec *pTagSelectSpec);
    void updateAccessSpecState(Tag_AccessSpec *pTagAccessSpec);
public:
		
		inline void setMCUToSecComm(MCUToSecureComm *pMCUToSec){
			m_pMCUToSecureComm = pMCUToSec;
		}
    inline int getOpResultSize(){
        return this->m_OpResults.size();
    }

    inline int getSelectAccessResultSize(){
        return this->m_SelectAccessResults.size();
    }

    inline bool isExecIdle(){
        return isIdle;
    }

    OpspecResult* frontOpResult();
    void popOpResult();
    Tag_SelectAccessResult* frontSelectAccessResult();
    void popSelectAccessResult();

protected:
    vector<OpspecResult*>*  genSelectResult(STRUCT_M2SEC_FRAME *pframe,Tag_SelectSpec *pTagSelectSpec);
    void  genAccessResult(STRUCT_M2SEC_FRAME *pframe,Tag_SelectSpec *pTagSelectSpec,CParameter *popspec,vector<OpspecResult*>* pAccessResult );

protected:
    bool forceExitExecute; //2017.11.13新加，可强制退出当前执行循环。
public:
    virtual void execSelectSpec();
    virtual bool singleSelectAccess(Tag_SelectSpec *pTagSelectSpec,Tag_AccessSpec *pTagAccessSpec,CAntennaSpec *pAntennaSpec,llrp_u16_t antSpecIndex,CRfSpec *pRfSpec);
public:
    virtual void startSelectSpec(Tag_SelectSpec *pSpec);
    virtual void endSelectSpec();

protected:
    llrp_u64_t m_AntennaStartUTC; //当前AntennaSpec的开始时间
    llrp_u64_t m_TagObTrgStartUTC; //当前AntennaSpec所含的标签触发规则中，超时计时的开始时间
    llrp_u16_t  m_TagObTagNCount; //当前AntennaSpec读到几个标签的计数
    llrp_u16_t m_TagObTryCount; //当前AntennaSpec发现标签的尝次次数计数
    llrp_u64_t m_TagObTLastUTC; //当前AntennaSpec最后一次发现标签的时间


protected:
		//以下是用以控制selectspec,accessspec执行流程的各个变量
		llrp_u16_t antSpecIndex; 
		list<CAntennaSpec*>::iterator antSpec_It;
		list<CRfSpec *>::iterator RfSpec_It;
		int accessSpecIndex;
};

#endif // OPERATIONSPEC_EXECUTE_BASE_H
