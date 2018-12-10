/*
 * MCUToSecureComm.h
 *
 *  Created on: 2016-3-22
 *      Author: lijin
 *
 *      用于主控CPU与安全模块之间的通信,IO操作
 */

#ifndef MCUTOSECURECOMM_H_
#define MCUTOSECURECOMM_H_

#include <map>
using namespace std;

#include "SPI_Communication.h"
#include "IOCtrl.h"
#include "HbFrame_Operation.h"

#define M2SEC_APPLYRS_FRAME 0 //主控向安全模块申请随机数帧
#define M2SEC_RESRS_FRAME 1   //安全模块给主控的随机数返回帧
#define M2SEC_CER_FRAME 2	  //主控向安全模块发送认证信息帧
#define M2SEC_RESCER_FRAME 3  //安全模块返回给主控的认证结果帧
#define M2SEC_USERMSG_FRAME 4 //主控发给安全模块的用户信息帧
#define M2SEC_SEC2CA_FRAME 5  //安全模块给服务器的授权申请帧，需主控转发
#define M2SEC_LICENSE_FRAME 6  //主控转发许可证给安全模块的帧
#define M2SEC_CERCHAIN_FRAME 7 //主控向安全模块发送申请到的证书链的帧
#define M2SEC_RESACTIVE_FRAME 8 //安全模块激活结果返回帧
#define M2SEC_SET_FRAME   9 //主控给安全模块的配置帧
#define M2SEC_SETACK_FRAME 10 //安全模块返回的配置应答帧
#define M2SEC_TAGDATA_FRAME 11 //安全模块给主控的标签识别上报帧
#define M2SEC_UPDATE_FRAME 12 //升级安全模块的帧
#define M2SEC_UPDATEACK_FRAME 13 //升级安全模块的响应帧

#define M2SEC_WRITEBANK_FRAME 14 //写分区请求帧
#define M2SEC_WRITEBANKACK_FRAME 15 //写分区请求响应帧

#define M2SEC_READBANK_FRAME 16 //读分区请求帧
#define M2SEC_READBANKACK_FRAME 17 //读分区请求响应帧

#define M2SEC_SECVERSIONACK_FRAME 18//安全模块软硬件版本请求返回帧

#define M2SEC_CERACK_FRAME 19 //安全模块对主控发的证书链响应
#define RF2M_TAGDATA_FRAME 20 //国标标签识别上报帧

#define M2SEC_FILTER_FRAME 21 //安全模块对数据过滤的配置帧
#define M2SEC_FILTERACK_FRAME 22 //配置响应帧

#define M2SEC_SETTEST_FRAME 23 //设置安全模块为测试模式帧
#define M2SEC_SETTESTACK_FRAME 24 //设置安全模块为测试模式的响应帧

//////////////////////////////////////////////////////////////////////////////////
//#define HALF_USER_POINT 5 //用户区半区的起点地址，单位是字
#define START_USER_POINT 4 //用户区有效数据起始地址，单位是字
#define HALF_USER_POINT (START_USER_POINT+5) //用户区半区的起点地址，单位是字

//////////////////////////////////////////////////////////////////////////////////
#define CID_PARAM    0x8801  //卡号
#define FPDH_PARAM   0x8802  //发牌代号
#define SYXZ_PARAM   0x8803  //使用性质
#define CCRQ_PARAM   0x8804  //出厂日期

#define CLLX_PARAM   0x8805  //车辆类型
#define GL_PARAM     0x8806  //功率
#define PL_PARAM     0x8807  //排量
#define HPZL_PARAM   0x8808  //号牌种类

#define HPHMXH_PARAM 0x8809  //号牌号码序号
#define JYYXQ_PARAM  0x880A  //检验有效期
#define QZBFQ_PARAM  0x880B  //强制报废期
#define ZKZL_PARAM   0x880C  //核定载客／总质量
#define CSYS_PARAM   0x880D  //车身颜色
/////////////////////////////////////////////////////////////////////////////////////

typedef struct MCU_TO_SECURE_FRAME{
	uint8_t Head;              //同步头
	uint8_t Type;			         //帧类型和版本号
	uint8_t DataLen[2];        //帧长度,包括OperID和DataBuf的长度
	uint8_t OperId;				     //操作标识号
	uint8_t *DataBuf;		   	   //数据区
	uint8_t BCCCheck;          //异或校验码
} STRUCT_M2SEC_FRAME;

#define MAX_M2SECFRAME_LEN  1024

/**
 * @brief The MCUToSecureComm class
 * 主控CPU和安全模块的通信帧类。
 * 注：通信帧为小端模式，即低地址字节在前，高地址字节在后。
 */

class MCUToSecureComm:public SPI_Communication {
public:
	MCUToSecureComm();
	virtual ~MCUToSecureComm();

private:
	map<int,int> m_FrameTypeToLen; //自定义的帧类型到相应帧长度的映射，只记录要安全模块到主控的帧长度
	IOCtrl *m_pIOCtrl;
    //Rf_Oper *m_pRfOper;
public:
	inline void setIOCtrl(IOCtrl *pIOCtrl){
		m_pIOCtrl = pIOCtrl;
	}

	int waitRfReadyForComm(); //等待射频模块准备好通信

    int waitSecReadyForUpdate(); //等待安全模块准备好升级
    int waitSecReadyForWork(); //等待安全模块准备好工作
	int waitSecReadyForComm(); //等待安全模块准备好通信
	int waitSecReadyForComm(int overtime);
    bool isSecReadyForComm();
	void resetSecMod(); //复位安全模块

    static STRUCT_M2SEC_FRAME * creatFrame(int frametype,uint8_t *contentbuf,int contentlen);
	static void removeFrame(STRUCT_M2SEC_FRAME *pframe);
	static STRUCT_M2SEC_FRAME* copyFrame(STRUCT_M2SEC_FRAME *pframe);
    static uint8_t caluBCCCheck(STRUCT_M2SEC_FRAME *pframe);

	bool sendFrameToSecure(STRUCT_M2SEC_FRAME *pframe);
	STRUCT_M2SEC_FRAME *getFrameFromSecure(int frametype);
    int getFrameContenLen(STRUCT_M2SEC_FRAME *pframe);

public:
    static int caluFrameLen(STRUCT_M2SEC_FRAME *pframe);
    static void putFrameToBuf(STRUCT_M2SEC_FRAME *pframe,uint8_t *buf);
public:
	STRUCT_M2SEC_FRAME * getFrameFromBuf(uint8_t *buf,int buflen);
public:
    static llrp_u8v_t getTIDFromTagFrame(STRUCT_M2SEC_FRAME *pframe);
    static llrp_u16v_t getRightDataFromTagFrame(STRUCT_M2SEC_FRAME *pframe); //从识读信息上传帧中，取出成功读取的数据内容。
    static llrp_u8_t getRightUserFlagFromTagFrame(STRUCT_M2SEC_FRAME *pframe);//从帧出取出有效数据的分区标识（含 分区号，天线号，上下半区标识）
    static llrp_u16v_t getTagDataFromTagFrame(STRUCT_M2SEC_FRAME *pframe,CMemoryBank *pbank);
    static CReadDataInfo * getCustomFromTagFrame(STRUCT_M2SEC_FRAME *pframe);
    static STRUCT_M2SEC_FRAME* genSecVersionRequestFrame();
    static void printfSecFrame(STRUCT_M2SEC_FRAME *pframe);
    static llrp_u8v_t getOrginDataFromTagFrame(STRUCT_M2SEC_FRAME *pframe);
};

#endif /* MCUTOSECURECOMM_H_ */
