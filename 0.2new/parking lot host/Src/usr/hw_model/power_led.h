#ifndef __POWER_LED_H
#define __POWER_LED_H
#include "stm32f2xx.h"
	#ifdef __cplusplus
	 extern "C" {
	#endif
		 
	//硬件资源PB0  --> 主机PD11
	#define POWER_LED_Port			    GPIOD
	#define POWER_LED_PIN           GPIO_Pin_11
	#define POWER_LED_CLK           RCC_AHB1Periph_GPIOD

	//初始化函数
	extern void POWER_LED_Init(void);

	//方法函数
	#define POWER_LED_H             GPIO_SetBits(POWER_LED_Port , POWER_LED_PIN)
	#define POWER_LED_L             GPIO_ResetBits(POWER_LED_Port , POWER_LED_PIN)
	#ifdef __cplusplus
	}
	#endif
#endif
