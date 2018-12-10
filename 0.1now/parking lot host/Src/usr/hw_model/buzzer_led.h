#ifndef __BUZZER_LED_H
#define __BUZZER_LED_H
#include "stm32f2xx.h"

	#ifdef __cplusplus
	 extern "C" {
	#endif
	//硬件资源PC5 --> PD12
	#define BUZZER_LED_Port			     GPIOD	
	#define BUZZER_LED_PIN           GPIO_Pin_12
	#define BUZZER_LED_CLK           RCC_AHB1Periph_GPIOD

	//初始化函数
	extern void BUZZER_LED_Init(void);

	//方法函数
	#define BUZZER_LED_H             GPIO_SetBits(BUZZER_LED_Port , BUZZER_LED_PIN)
	#define BUZZER_LED_L             GPIO_ResetBits(BUZZER_LED_Port , BUZZER_LED_PIN)

	/* 直接操作寄存器的方法控制IO */
	#define	digitalHi(p,i)			{p->BSRR=i;}			//设置为高电平		
	#define digitalLo(p,i)			{p->BRR=i;}				//输出低电平
	#define digitalToggle(p,i)		{p->ODR ^=i;}			//输出反转状态
	/* 定义控制IO的宏 */
	#define BUZZER_LED_TOGGLE		digitalToggle(BUZZER_LED_Port,BUZZER_LED_PIN)
	
	#ifdef __cplusplus
	}
	#endif
#endif