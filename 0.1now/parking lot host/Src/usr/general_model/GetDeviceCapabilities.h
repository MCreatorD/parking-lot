#ifndef GETDEVICECAPABILITIES_H
#define GETDEVICECAPABILITIES_H
#include "HbFrame_Operation.h"

#define DEVICE_MODEL_TYPE 001   //设备型号
#define DEVICE_SPECIFICATION_TYPE 001   //设备规格
#define MAX_NUMBER_OF_ANTENNA_SUPPORTED 4   //最大天线个数
#define HAS_UTC_CLOCK_CAPABILITY 1  //是否有UTC时钟
#define NUM_GPIS 0  //GPI个数
#define NUM_GPOS 0  //GPO个数
#define HAS_LOCATION_CAPABILITY 1  // 是否有位置信息
#define IS_DEVICE_BINDED 1  //设备是否激活
#define ANTENNA_ID 1  // 天线编号
#define SUPPORT_QUERY 1  //是否支持盘点
#define SUPPORT_READ_DATA 1  //是否支持读数据
#define SUPPORT_WRITE_DATA 1  //是否支持写数据
#define SUPPORT_WRITE_KEY 1   //是否持有密钥
#define  SUPPORT_ETHERNET 1  //是否支持以太网通信
#define SUPPORT_HTTP_LINK 0 // 是否支持http通信协议链路
#define SUPPORT_IPV6  1 // 是否支持IPV6
#define SUPPORT_MOBILE  1 //是否支持移动通信（3G ，4G）
#define SUPPORT_SSL 1 //是否支持SSL
#define SUPPORT_TCP_LINK_NUM 5 //支持的TCP协议通信链路的个数
#define SUPPORT_USB 1 //是否支持USB 通信
#define SUPPORT_WIFI 1 // 是否支持WIFI通信
#define PORT_NUM  0 //端口个数
#define BAUD_RATE 115200 // 232 波特率
#define BAUD_RATE1 115200 // 485 波特率
#define PORT_NUM485  1  // 端口个数
#define COMMUNICATIONS_STANDARD 1   //空口通信标准
#define COUNTRY_CODE  1   //区域代码
#define TRANSMIT_POWER_VALUE 1 // 功率值
#define  HOP_PING  1 //是否支持调频
#define  FREQUENCY 1 //频率值 乘100表示
#define FORDATA_RATE  1 //前向速率 乘100表示
#define INDEX_MODULATION_TABLE   1 //  前向链路调制参数索引号
#define INDEX_REVDATA   1// 反向编码索引号
#define FOR_MODULATION_TABLE  1  //前向调制方式表索引号
#define INDEX_ENCODING_TABLE 1 //反向编码表索引号
#define MODULE_DEPTH_VALUE 1 //调制深度值
 #define  MODULE_DEDPTH_TABLE_INDEX  1 // 调制深度参数索引号
#define MODULE_LATION_TABLE 1 //前向链路调制参数方式索引号
#define REV_DATA_ENCODING_TABLE_INDEX  1  // 反向编码调制表索引号
#define CLIENT_REQUEST_OPSPEC_TIME_OUT 100000 //上位机请求OP超时时间 单位：毫秒
#define MAX_NUM_ACCESSSPECS   1  //最大标签存取规则个数
#define MAX_NUM_ANTENNA_SPECS_PER_SELECT_SPEC 1  //每个标签算选择规则中包含最大天线规则个数
#define MAX_NUM_OPERATION_PECS_PER_ACCESSSPEC 1 //每个标签算选择规则中包含最大操作规则个数
#define MAX_NUM_RFSPECS_PER_ANTENNA_SPEC  1// 每个标签算选择规则中包含最大射频参数个数
#define  MAX_NUM_SELECT_SPECS  1 //最大标签选择个数
#define  MAX_PRIORITY_LEVEL_SUPPORTED  1 //最高优先级
#define SUPPORTS_CLIENT_REQUESTOP_SPEC  1 //是否支持上位机请求OP
#define SUPPORTS_EVENT_AND_REPORT_HOLDING   1  //是否支持段链路断链缓存
#define DATA_ENCODING_TYPE   0   //编码方式
#define INDEX_FRE_INFO  1  //发射功率索引号
#define INDEX_FRE_TABLE  1 //频率表参数索引值
#define  INDEX_FOR_DATA_RATE_TABLE 1//前向链路参数索引号
#define MODULATION_TYPE   0  //前向链路调制方式
#define REV_DATA_TABLE_INDEX  1  //  反向速率表索引号
#define REV_DATA_RATE   1  //      反向速率 乘100 表示
#define INDEX_MODULE_DEPTH  1  //调制深度参数索引号

class GetDeviceCapabilitiesFuction{
public:
    GetDeviceCapabilitiesFuction();
    ~GetDeviceCapabilitiesFuction();

public:
    CMessage *getDeviceCapabilitiesRequestedDataMessage(llrp_u8_t datatype);

private:

   CParameter *m_pCommunicationCapabilities;
   CParameter *m_pSupportRS232;
//    CParameter *m_pSupportRS485;    //不支持RS485
   CParameter *m_pSerialAttribute;

   CParameter *m_pSpecCapabilities;

   CParameter *m_pRfCapabilities;
   CParameter *m_pTransmitPowerLevelTable;
   CParameter *m_pFrequencyInformation;
   CParameter *m_pFrequencyTable;
   CParameter *m_pForDataRateTable;
   CParameter *m_pRevDataRateTable;
   CParameter *m_pForModulationTable;
   CParameter *m_pRevDataEncodingTable;
   CParameter *m_pModuleDepthTable;

   CParameter *m_pAirProtocolCapabilities;
   CParameter *m_pPerAntennaAirProtocol;
   CParameter *m_pDeviceAirProtocolCapabilities;

  //行标支持的空口协议表

};

#endif // GETDEVICECAPABILITIES_H
