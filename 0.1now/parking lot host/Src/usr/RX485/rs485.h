#ifndef __MCU_RS485_H
#define __MCU_RS485_H
#include "stm32f2xx.h"

	#ifdef __cplusplus
	 extern "C" {
	#endif
	//硬件资源    *****************SR PB5 PB4: REn DE***************************
		 
		 
	#define RS485_RX_EN_Port			    GPIOB	                //GPIOB     //GPIOC	
	#define RS485_RX_EN_PIN                 GPIO_Pin_5              //GPIO_Pin_5 //GPIO_Pin_7
	#define RS485_RX_EN_CLK                 RCC_AHB1Periph_GPIOB     //RCC_AHB1Periph_GPIOB    //RCC_AHB1Periph_GPIOC

	#define RS485_TX_EN_Port			    GPIOA//GPIOB	     //GPIOC
	#define RS485_TX_EN_PIN                 GPIO_Pin_15//GPIO_Pin_4    //'GPIO_Pin_8
	#define RS485_TX_EN_CLK                 RCC_AHB1Periph_GPIOA //RCC_AHB1Periph_GPIOB		 //RCC_AHB1Periph_GPIOC 
	//初始化函数
	extern void RS485_Init(void);

	//方法函数		 
	#define RS485_RX_H             GPIO_SetBits(RS485_RX_EN_Port , RS485_RX_EN_PIN)      //SR PB5
	#define RS485_RX_L             GPIO_ResetBits(RS485_RX_EN_Port , RS485_RX_EN_PIN) 
		 
	#define RS485_TX_H             GPIO_SetBits(RS485_TX_EN_Port , RS485_TX_EN_PIN)
	#define RS485_TX_L             GPIO_ResetBits(RS485_TX_EN_Port , RS485_TX_EN_PIN) 	//SR PB4	 

		 #ifdef __cplusplus
	}
	#endif	
#endif