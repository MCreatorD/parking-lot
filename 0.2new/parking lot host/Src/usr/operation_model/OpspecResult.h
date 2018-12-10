#ifndef OPSPECRESULT_H_
#define OPSPECRESULT_H_

#include "HbFrame_Operation.h"
#include "tag_selectspec.h"
#include <stdio.h>
#include "MCUToSecureComm.h"

/**
 * @brief The OpspecResult class
 * by lijin 2017.03.06
 * 用以记录安全模块返回帧及相关信息的类
 */

class OpspecResult {
public:
	OpspecResult();
	virtual ~OpspecResult();

public:
	STRUCT_M2SEC_FRAME *pOpResultFrame;

    //以下几个变量在生成报告时会用到
	CSelectSpec *pSelectSpec;
	CAccessSpec *pAccessSpec;
	CParameter *pOpSpec;

    //////////////////////////////

    ////////////////////////////////////
    /// \brief operTagTID
    ///有待删除
	llrp_u8v_t operTagTID; //所操作的标签的TID号
	llrp_u8_t operAntennaID;//操作所用的天线号

private:
    Tag_SelectSpec *m_pTagSelectSpec;
public:
//    inline void setTagSelectSpec(Tag_SelectSpec *pSpec){
//        m_pSelectSpec = pSpec;
//    }
    inline Tag_SelectSpec * getTagSelectSpec(){
        return m_pTagSelectSpec;
    }

public:
    llrp_u32_t Op_SelectSpecID;
    llrp_u16_t Op_RfSpecID;
    llrp_u16_t Op_AntennaSpecIndex;
    vector<int> Op_BankIDs; //当前操作的多分区号集合。
public:
    void setOpParams(Tag_SelectSpec *pTagSelectSpec);
    void setOpParams(Tag_SelectSpec *pTagSelectSpec,CParameter *pOpspec);
    void setOpParams(Tag_SelectSpec *pTagSelectSpec,Tag_AccessSpec *pTagAccessSpec,CParameter *pOpspec);
    inline void releaseTagSelectSpec(){
        m_pTagSelectSpec->release();
    }

};

#endif /* OPSPECRESULT_H_ */
