#ifndef _USART2_H
#define _USART2_H

	#ifdef __cplusplus
	 extern "C" {
	#endif

#include <stdio.h>
#include "stm32f2xx.h"
//#include "config.h"

#define USART2_RX_LEN 1000
#define USART2_TX_LEN 1000
		 
	extern u8 USART2_RX_BUF[USART2_RX_LEN];     //接收缓冲,最USART_RX_LEN个字节
	extern u8 USART2_TX_BUF[USART2_TX_LEN]; //发送缓冲,最大USART_TX_LEN个字节
	extern u8 USART2_RX_STA;       //接收完成状态标记
	extern u8 USART2_TX_IDLE;    //发送空闲状态标记
	 
	extern u16 RX2_Posi; //当前缓冲区接收位置
	extern u16 TX2_Posi;
	extern u16 TX2_Len;
	extern u16 RX2_Len;
		 
	void USART2_Configuration(void);
	void USART2_NVIC_Config(void);
	
	void USART3_Configuration(void);
	int  USART3_SendData(unsigned char *buf,int buflen);		 
	int USART2_SendData(unsigned char *buf,int buflen);
	 
	#ifdef __cplusplus
	}
	#endif

#endif /*_USART1_H*/
