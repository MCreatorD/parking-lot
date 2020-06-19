#ifndef __BANISTER_H
#define __BANISTER_H

	#include "stm32f2xx.h"

	#ifdef __cplusplus
	 extern "C" {
	#endif
		 
	#define Baister_EN 1
		 
	//硬件资源PC6 --> IO1
	#define Banister_Port		   GPIOC	
	#define Banister_PIN           GPIO_Pin_7
	#define Banister_CLK           RCC_AHB1Periph_GPIOC

	//方法函数
	#define Banister_H             GPIO_SetBits(Banister_Port , Banister_PIN)
	#define Banister_L             GPIO_ResetBits(Banister_Port , Banister_PIN)

	//初始化函数
	extern void BanisterIoInit(void);
	extern void ContrlBanister(int value);	

		 
	#ifdef __cplusplus
	}
	#endif	
#endif