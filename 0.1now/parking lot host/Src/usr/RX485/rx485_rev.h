#ifndef __RX485_REV_H
#define __RX485_REV_H
#include "stm32f2xx.h"

	#ifdef __cplusplus
	 extern "C" {
	#endif
	extern u8  RX485_ReadyForRecv; //标识通信链路已准备好接收帧
	extern u16 RX485_recFrameLen; //当前收到的帧长度
	extern int cpu_set;	 
	extern u8 Device_cpu;//动态存储前段节点CPU
	extern u8 Device_rf;//动态存储前段节点射频
	extern u8 Device_end;//读卡结束
	//反转义    头尾0x7E 数据中有7E 换成7D 5e,那有数据7D 换成0x7D 0x5D
	unsigned char deEscapeMessage(char* in,int in_len,char* out,int *out_len);
  //unsigned char recvCommData(unsigned char *buf,int reclen);
  unsigned char RX485_recvCommData(unsigned char *buf,int reclen);		
		 
  u8 MCU_MessageDeal(u8 *data,u16 reclen);
	void RF_MessageDeal(u8 *data,u16 reclen);
	u8 MessageDeal(u8 *data,u16 reclen);
	void Switch_DeviceRead();	
	u8 SlaveAck(unsigned int SlaveAck);
	u8 waitSlaveAck(unsigned int SlaveAck,unsigned int temp_time);
	u8 waitSlaveAckData(unsigned int SlaveAck,unsigned char *ack_data,unsigned int len,unsigned int temp_time);
	//u8 waitSlaveAck(unsigned int temp_time);	 
	#ifdef __cplusplus
	}
	#endif

#endif