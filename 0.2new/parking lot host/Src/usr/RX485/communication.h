#ifndef __COMMUNICATION_H
#define __COMMUNICATION_H
#include "stm32f2xx.h"

#define LISTENING_ADDR 	0x00
#define hasNewTag 			0xAA

//通信帧
//0x7e           源地址          目的地址       cpu/rf      消息内容              0x7e
//1. 源地址
#define MASTER_CPU         20  //主控CPU

//3.cpu/rf  
#define CPU_MODE           21
#define RF_MODE            22


//2. 消息内容 通信帧      buf[1]
//主机与主机交互指令

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

#define Updateslavehandle     	 138    //升级从机程序握手
#define UpdateslavehandleAck     139    //升级从机程序握手应答

#define Updateslave     				 140    //升级从机程序
#define UpdateslaveAck           141    //升级从机程序应答

#define RD_Time 100

#endif
