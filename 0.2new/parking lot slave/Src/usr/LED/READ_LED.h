#ifndef __READ_LED_H
#define __READ_LED_H
#include "stm32f2xx.h"

	#ifdef __cplusplus
	 extern "C" {
	#endif
	//硬件资源PC9
	#define READ_LED_Port			     GPIOC	
	#define READ_LED_PIN           GPIO_Pin_9
	#define READ_LED_CLK           RCC_AHB1Periph_GPIOC

	//初始化函数
	extern void READ_LED_Init(void);

	//方法函数
	#define READ_LED_H             GPIO_SetBits(READ_LED_Port , READ_LED_PIN)
	#define READ_LED_L             GPIO_ResetBits(READ_LED_Port , READ_LED_PIN)

	/* 直接操作寄存器的方法控制IO */
	#define	digitalHi(p,i)			{p->BSRR=i;}			//设置为高电平		
	#define digitalLo(p,i)			{p->BRR=i;}				//输出低电平
	#define digitalToggle(p,i)		{p->ODR ^=i;}			//输出反转状态
	/* 定义控制IO的宏 */
	#define READ_LED_TOGGLE		digitalToggle(READ_LED_Port,READ_LED_PIN)
	
	#ifdef __cplusplus
	}
	#endif
	
#endif