#ifndef RF_OPER_BASE_H
#define RF_OPER_BASE_H

#include "SPI_Communication.h"
#include "IOCtrl.h"
#include "ManufacturerFrame.h"
#include "tag_selectspec.h"
#include "tag_accessspec.h"
#include "MCUToSecureComm.h"

#define DEFAULT_POWERID 15

#define PARAM_AA     00
#define PARAM_AB     01
#define PARAM_AC     02

#define SETRFWORK_FREQ  0x00 //配置射频工作频率
#define SETRFWORK_ANT    0x01 //配置射频工作天线
#define SETRFWORK_CAN    0x04 //进行对消
#define SETRFWORK_POWER 0x07 //功率配置
#define SETRFWORK_POWINC 0x02 //功率粗调加
#define SETRFWORK_POWDEC 0x03 //功率粗调减
#define SETRFWORK_FINEINC  0x12 //功率细调加
#define SETRFWORK_FINEDEC 0x013 //功率细调减
#define SETRFWORK_SAVEPOW 0x05 //功率字存贮

#define SWITCHANT_DELAY 10
#define SWITCHFREQ_DELAY 10

/**
 * @brief The Rf_Oper_Base class
 * 2018.02.02 ,by lijin
 * 射频操作类的基类
 */
 
 
typedef struct{
    llrp_u8_t BankNum;   //用户区编号0～5
    llrp_u8_t BankReadFlag; //读操作标识，0表示读下半区，1表示读上半区，2表示读全区，3表示分两次读全区，4表示用国标读分区（未用）
    llrp_u8_t BankCryptFlag; //用7～4位的数值来表示是否加密，0表示密文，1表示明文。（实际上和下面的合为一个字节配置）
    llrp_u8_t BankReadSpeedFlag; //用3~0位的数值来表示是高速度，还是普通读。0表示普通读，1表示高速读
    llrp_u16_t BankReadPoint;  //行标读时，固定为0。国标读时，表示起始字地址。
    llrp_u16_t BankReadCount;  //行标读时，固定为0，国标读时，表示读多少个字。
}Struct_TagBank_RWInfo;

typedef struct {
    llrp_u8v_t TID;
    llrp_u8_t UserFlag;
    llrp_u16v_t Data;
    llrp_u64_t StartFilterUTCms;
} STRUCT_FILTER_DATA;

typedef struct{
    llrp_u8_t  AntID; //天线ID,从0开始编号
    llrp_u16_t PowerIndex;
    llrp_u16v_t FreqIndexes;
    llrp_u16_t ForRateIndex;
    llrp_u16_t RevRateIndex;
    llrp_u16_t ForModeIndex;
    llrp_u16_t RevEncodingIndex;
    llrp_u16_t CurrentFreqIndex; //当前频率数列的序号，用以控制跳频用
}STRUCT_ANTCFG_DATA; //用以记录每条天线AntennaConfiguration有相关变量

class Rf_Oper_Base:public SPI_Communication
{
public:
    Rf_Oper_Base();
    ~Rf_Oper_Base();

public:
    MCUToSecureComm* m_pM2SecComm;

protected:
    IOCtrl *m_pIOCtrl;

public:
	inline void setIOCtrl(IOCtrl *pIOCtrl){
		m_pIOCtrl = pIOCtrl;
	}
	inline void setM2SecComm(MCUToSecureComm *pM2SecComm){
		m_pM2SecComm = pM2SecComm;
	}

protected:
	llrp_u64_t AA_ConfigParam;
	llrp_u64_t AB_ConfigParam;
	llrp_u64_t AC_ConfigParam;
	llrp_u64_t AD_ConfigParam;
	llrp_u64_t AE_ConfigParam;
	llrp_u64_t AF_ConfigParam;

	llrp_u64_t BA_ConfigAck;
	llrp_u64_t BB_ConfigAck;

protected:
    list<STRUCT_FILTER_DATA*> m_FilterDataList; //过滤比对数据列表
    llrp_u32_t m_Filterms; //过滤时间，单位毫秒

protected:
    CHbWriteSpec *pCurrentHbWriteSpec;

//=====================================//
protected:
    llrp_u8_t calcCrc8(llrp_u64_t data);

    map<int,vector<int>* > m_DoneCancellationSets; //已做过对消的频点集合
    bool isDoneCancellation(int antennaid,int freqindex);
    void putDoeCancellation(llrp_u8_t antennaid,int freqindex);
		string convertADDataToString();
	
public:
		bool isMatchMask(CHbTargetTag *pHbTargetTag,llrp_u8v_t TID,llrp_u16v_t userTagData);

public:
    vector<int> currentReadSpecIDs; //当前Access操作中，读卡操作ID的集合，按指定的先后顺序存放，是为了能顺序上传所准备的
    map<int,int> currentUserIDtoSpecID; //当前读卡操作流程中，标签分区号到相应AccessSpec中的ReadSpec或WirteSpec的ID号的映射
    CAccessSpec *pCurrentActiveAccessSpec; //当前工作中的AccessSpec
    CRfSpec *pCurrentRfSpec; //当前工作中的RfSpec

public:
		virtual bool setSelectAccessParam(Tag_SelectSpec *pTagSelectSpec,Tag_AccessSpec *pTagAccessSpec,llrp_u16_t antSpecIndex,CRfSpec *pRfSpec)=0;

protected:

    CAntennaConfiguration *findAntennaConfig(list<CAntennaConfiguration*>::iterator beginit,list<CAntennaConfiguration*>::iterator endit,llrp_u8_t antennaid);

    Struct_TagBank_RWInfo getBankinfoFromMemBank(CMemoryBank *pMemoryBank);
public:
    void printU1VData(llrp_u1v_t &data);

public:

    void startRfOper();
    void stopRfOper();
		
	
		bool setADParam(CAntennaConfiguration * pAntennaCfg); //配置单个天线的泄漏对消

		bool setAllADParam(CAntennaSpec * pAntennaSpec);//配置指定的所有天线的泄漏对消，注意如果已配置过，就不会再配置

		bool setNewADRparam(CAntennaConfiguration * pAntennaCfg);//配置新的需对消的天线和频点

		bool sendAEToRf(unsigned char antennaid,unsigned char datt,unsigned char ctrl); //发送定标帧给FPGA



    bool switchCarrier(int antid,int freqid,bool on_off);

    

////////////////////////////////////////////////////////////
public:
    bool isRfOperStart;

protected:
    //以下几个为记录当前正在工作的几个参数，目的是参数不变时，不重复配置射频和安全模块
    Tag_SelectSpec *m_pCurrentSelectSpec;
    Tag_AccessSpec *m_pCurrentAccessSpec;
    CRfSpec *m_pCurrentRfSpec;
    CAntennaSpec *m_pCurrentAntSpec;
    bool needSendParam;

protected:
    CReadMode *getDefaultReadMode();
    void setTagDataFilter(CReadMode *pReadMode);
    STRUCT_M2SEC_FRAME* doTagDataFilter(STRUCT_M2SEC_FRAME *pFrame);

public:
    bool isFPGATurnEnd();
    bool waitFPGATurnEnd();
    bool waitFPGANeedComm(int overtime);

    void setFPGASingleEnd();
    void setFPGASingleStart();

    bool waitFPGARWOver();

    //以下是为了实现cpu控制天线切换，跳频等新功能
private:
    vector<int> m_AvailableAntIDs; //当前selectspec中可用的天线号组，天线号0~3
    int m_CurrentAntIDIndex; //当前的天线号索引
    map<int,STRUCT_ANTCFG_DATA> m_AntIDToAntCFG; //当前selectspec中，相应天线的设置。每次操作应保证每个在用的天线都有一个设置

public:
    int m_AntChangeDelay; //天线切换计数
private:
    int m_FreqChangeDelay; //频率切换计数

    llrp_u64_t m_LastAA; //用以控制是否需要重发AA，下同
    llrp_u64_t m_LastACs[10];
    llrp_u64_t m_LastAB;

private:
    void setACParam(int antid,int freqid,int powerid,int worktype); //设置AC参数值
    void setACParam(int antid,int freqid,int worktype);
public:
    void setAntCFG(CAntennaSpec *pSpec,CRfSpec *pRfSpec);//配置射频工作参数。
    bool setSelectRfParam(); //配置射频参数，每次盘点应执行一次。
    bool sendSelectRfParam(unsigned char work_mode);

    bool sendParamToRf(int paramtype,int ac_worktype );

    inline void resetAA(){
        m_LastAA = 0;
        m_LastAB = 0;
        for(int i=0;i<10;i++ ){
            m_LastACs[i] = 0;
        }
    }

    inline void resetCurrentSpec(){
        printf("reset CurrentSpec.........................................\n");
        m_pCurrentSelectSpec = NULL;
        m_pCurrentAccessSpec = NULL;
        m_pCurrentRfSpec = NULL;
    }

    bool isFPGARWOver();

private:
    STRUCT_ANTCFG_DATA getAntCfgStruct(CAntennaConfiguration *pAntcfg);
    void requestTokForNextAnt();

public:
    inline void initAntSwitch(){
        m_AntChangeDelay = SWITCHANT_DELAY*3;
    }

		llrp_u64_t getFPGAVersion();
};

#endif // RF_OPER_BASE_H
