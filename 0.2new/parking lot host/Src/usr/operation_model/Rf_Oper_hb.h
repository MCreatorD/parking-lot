#ifndef Rf_Oper_HB_H_
#define Rf_Oper_HB_H_

#include "MCUToSecureComm.h"
#include "rf_oper_base.h"

/**
 * @brief The Rf_Oper class
 * by lijin 2018.02.02
 * 用以进行国标操作的类
 */
 class Rf_Oper_HB :public Rf_Oper_Base{
public:
    Rf_Oper_HB();
    ~Rf_Oper_HB();
public:
	bool isSkippingAnt;
public:
	bool isRfOperStart;
	int ADRetryCount; //对消重试次数

private:
    vector<int> m_AvailableAntIDs; //当前selectspec中可用的天线号组，天线号0~3
    int m_CurrentAntIDIndex; //当前的天线号索引
public:
    int m_AntChangeDelay; //天线切换计数
private:
    int m_FreqChangeDelay; //频率切换计数

protected:
    //以下几个为记录当前正在工作的几个参数，目的是参数不变时，不重复配置射频和安全模块
    Tag_SelectSpec *m_pCurrentSelectSpec;
    Tag_AccessSpec *m_pCurrentAccessSpec;
    CRfSpec *m_pCurrentRfSpec;
    CAntennaSpec *m_pCurrentAntSpec;
    bool needSendParam;



private:
	STRUCT_M2SEC_FRAME* genSecReadSetFrame(Struct_TagBank_RWInfo *pBankInfos,int infoCount);
  bool setContinueOpParam(CRfSpec *pSpec,Tag_SelectSpec *pTagSelectSpec);
  bool setNoContinueOpParam(CRfSpec *pRfSpec,CAccessSpec *pAccessSpec,Tag_SelectSpec *pTagSelectSpec);

protected:
	CMemoryBank * getDefaultMemoryBank();
public:
  bool setSelectAccessParam(Tag_SelectSpec *pTagSelectSpec,Tag_AccessSpec *pTagAccessSpec,llrp_u16_t antSpecIndex,CRfSpec *pRfSpec);
	STRUCT_M2SEC_FRAME *readTagData();
	map<int,CHbReadSpec*> currentUserIDToReadReslt; //当前读卡操作流程中，标签分区号到相应HbReadSpec的映射，主要是为了能取出指定数据而新加

	int currentAccessBankCount ; //当前的多分区操作需要读取的分区数。

public:
	STRUCT_M2SEC_FRAME* readTagBankData(llrp_u8v_t targettid,CHbReadSpec *spec);
	STRUCT_M2SEC_FRAME* writeTagBankData(llrp_u8v_t targettid,CHbWriteSpec *spec);
};

#endif
