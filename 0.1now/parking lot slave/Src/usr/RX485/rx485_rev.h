#ifndef __RX485_REV_H
#define __RX485_REV_H
#include "stm32f2xx.h"

	#ifdef __cplusplus
	 extern "C" {
	#endif
	extern volatile u8  RX485_ReadyForRecv; //标识通信链路已准备好接收帧
	extern volatile int RX485_recFrameLen; //当前收到的帧长度
	extern volatile u8 stringlen;
		 
	//反转义    头尾0x7E 数据中有7E 换成7D 5e,那有数据7D 换成0x7D 0x5D
	unsigned char deEscapeMessage(char* in,int in_len,char* out,int *out_len);
  //unsigned char recvCommData(unsigned char *buf,int reclen);
	unsigned char RX485_recvCommData(unsigned char *buf,int reclen);	
	u8 MessageDeal(u8 *data,u16 MCU_CanRecLen);		 
	u8 Sm_MessageDeal(u8 count,u8 timeout); //【数据转收】射频模块接收 主控数据 ，实际是主控中转 安全模块发送至射频的数据
		 //u8 MessageDeal(u8 *data,u16 MCU_CanRecLen);
	#ifdef __cplusplus
	}
	#endif

#endif
