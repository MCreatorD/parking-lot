#ifndef __COMMUNICATION_H
#define __COMMUNICATION_H

#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32f2xx.h"
	     
typedef struct
{
	unsigned char Slave_Addr;        //设备地址
	unsigned char RF_Frequency;      //射频频点  
	unsigned short int RF_Power;     //射频功率 16 位 1500 ~ 3700 	
	unsigned char Carrier_flg;       //载波开关状态标识位
	unsigned char Led_Mode;					 //读卡时灯光模式，运行测试
	unsigned short int radar_distance;//测距距离
	unsigned char  read_switch_count;//读卡轮数统计 
	unsigned char  readcarthreshold;//车位在位门槛参数
}Slave_ConfigParam; //设备属性

extern Slave_ConfigParam m_slave;

#define TXBUFFERSIZE   200
#define RXBUFFERSIZE   200

//监听的地址0
#define LISTENING_ADDR 0x00

//通信帧
//0x7e        源地址       目的地址       cpu/rf      消息内容              0x7e
//1. 源地址
#define MASTER_CPU         20  //主控CPU

//3.cpu/rf  
#define CPU_MODE           21
#define RF_MODE            22

//2. 消息内容 通信帧      buf[1]
//主机与主机交互指令

#define ReadCardEnd      	  		 80  //读卡结束 ;RF -> 主控CPU 
#define RD_CARD_ERROR    	  		 81  //读卡错误 ;RF -> 主控CPU 

#define ReadCardEnd      	  		 80  //读卡结束 ;RF -> 主控CPU 
#define RD_CARD_ERROR    	  		 81  //读卡错误 ;RF -> 主控CPU 

#define StartReadCard     	 		 100  //开始读卡 ;主控CPU -> RF
#define StartReadCardAck   			 101  //开始读卡应答

#define StopReadCard      	 		 102  //停止读卡 ;主控CPU -> RF
#define StopReadCardAck    			 103  //停止读卡应答

#define ConfigSlaveAddr    			 104  //配置从机节点的ADDR
#define ConfigSlaveAddrAck 			 105  //配置从机节点地址应答

#define GetSlaveAddr       			 106  //从节点在位检测
#define GetSlaveAddrAck    			 107  //从节点在位检测应答返回地址

#define SetSlaveMessage          108   //设置从节点设备信息
#define SetSlaveMessageAck       109   //设置从节点设备信息应答

#define GetSlaveMessage          110   //从节点设备信息查询
#define GetSlaveMessageAck       111   //从节点设备信息查询应答

#define ConfigRfPower      			 112   //配置射频功率
#define ConfigRfPowerAck   			 113   //配置射频功率应答

#define GetSlaveRfPower    			 114   //查询从节点射频功率值
#define GetSlaveRfPowerAck 			 115   //查询从节点射频功率值应答

#define ConfigFrequency    			 116   //配置射频频点
#define ConfigFrequencyAck 			 117   //配置射频功率应答

#define GetSlaveFrequency    		 118   //查询从节点射频射频频点
#define GetSlaveFrequencyAck 		 119   //查询从节点射频射频功率应答

#define ConfigCarrier     	  	 120    //开载波
#define ConfigCarrierAck   			 121    //开载波应答

#define GetSlaveCarrier     	   122    //查询从节点载波开关状态
#define GetSlaveCarrierAck   		 123    //查询从节点载波开关状态应答

#define ConfigCancellation     	 124    //对消
#define ConfigCancellationAck  	 125    //对消结束应答

#define GetSlaveCancellation     126   //对消值获取
#define GetSlaveCancellationAck  127    //对消值获取应答

#define ConfigLedMode            128    //配置灯光模式
#define ConfigLedModeAck         129    //配置灯光模式应答

#define GetLedMode               130    //查询灯光模式
#define GetLedModeAck            131    //查询灯光模式应答

#define GetRadarDistance         132    //查询雷达测距数值cm
#define GetRadarDistanceAck      133    //查询雷达测距数值cm应答

#define ConfigLedThreshold       134    //车辆在位检测门槛数值
#define ConfigLedThresholdAck    135    //车辆在位检测门槛数值应答

#define GetSlaveLedThreshold     136    //查询车辆在位检测门槛数值
#define GetSlaveLedThresholdAck  137    //查询车辆在位检测门槛数值应答

extern  unsigned char TxBuffer[TXBUFFERSIZE];
extern  unsigned char RxBuffer [RXBUFFERSIZE];

u8 Sm_MessageDeal(u8 count,u8 timeout);
u8 RF_To_SM(u8 bCommand,u8 *data,u8 timeout);

#ifdef __cplusplus
}
#endif
 

#endif

