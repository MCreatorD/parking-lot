#ifndef _USART1_H
#define _USART1_H

	#ifdef __cplusplus
	 extern "C" {
	#endif

#include <stdio.h>
#include "stm32f2xx.h"
//#include "config.h"

#define USART_RX_LEN 1000
#define USART_TX_LEN 1000
		 
	extern u8 USART1_RX_BUF[USART_RX_LEN];     //接收缓冲,最USART_RX_LEN个字节
	extern u8 USART1_TX_BUF[USART_TX_LEN]; //发送缓冲,最大USART_TX_LEN个字节
	extern u8 USART1_RX_STA;       //接收完成状态标记
	extern u8 USART1_TX_IDLE;    //发送空闲状态标记
	 
	extern u16 RX1_Posi; //当前缓冲区接收位置
	extern u16 TX1_Posi;
	extern u16 TX1_Len;
	extern u16 RX1_Len;
		 
	void USART1_Configuration(void);
	void USART1_NVIC_Config(void);
			 
	int USART1_SendData(unsigned char *buf,int buflen);
	 
	#ifdef __cplusplus
	}
	#endif

#endif /*_USART1_H*/
