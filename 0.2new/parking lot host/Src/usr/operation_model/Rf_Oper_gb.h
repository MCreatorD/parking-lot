#ifndef RF_OPER_GB_H_
#define RF_OPER_GB_H_

#include "rf_oper_base.h"

typedef struct GBRf_ToMcu_FRAME{
    uint8_t Head[2];    //帧头
    uint8_t FrameLen[2]; //不含帧头帧长度，注意，是字长度
    uint8_t CpuCommand[2]; //当前CPU命令
    uint8_t AntId[2];//天线号
    uint8_t SuccessMark[2]; //成功标志
    uint8_t DataLen[2]; //数据长度(编码加用户区数据长)，注意，是字节长度，是去除前面帧头的数据长度
    uint8_t *DataBuf; //编码长度＋CODE区编码 + 用户区数据长度 + 用户区数据
} STRUCT_RF2M_FRAME;

/**
 * @brief The Rf_Oper class
 * by lijin 2018.02.02
 * 用以进行国标操作的类
 */
 class Rf_Oper_GB :public Rf_Oper_Base{
public:
    Rf_Oper_GB();
    ~Rf_Oper_GB();

private:
    llrp_u64_t C1_ConfigParam;
    llrp_u64_t C2_ConfigParam;
    llrp_u64_t C3_ConfigParam;
    llrp_u64_t C4_ConfigParam;
    llrp_u64_t C5_ConfigParam;
    llrp_u64_t  C6_ConfigParam;

    vector<llrp_u64_t> m_GBTagdatas;   
public:
    bool setNoContinueOpParam(CRfSpec *pRfSpec,CAccessSpec *pAccessSpec,Tag_SelectSpec *pTagSelectSpec);
 	bool setSelectAccessParam(Tag_SelectSpec *pTagSelectSpec,Tag_AccessSpec *pTagAccessSpec,llrp_u16_t antSpecIndex,CRfSpec *pRfSpec);


private:
    STRUCT_RF2M_FRAME * getFrameFromRf();
    STRUCT_RF2M_FRAME * getGBDataFromBuf(uint8_t *buf,int buflen);

public:
	bool sendGBParamToRf(llrp_u64_t param);
	bool isRfNeedComm();
	void removeGBFrame(STRUCT_RF2M_FRAME *pframe);
	STRUCT_RF2M_FRAME *readGBTag();
    void setFPGAWriteGBEnable();
    void setFPGAWriteGBDisable();
};

#endif
