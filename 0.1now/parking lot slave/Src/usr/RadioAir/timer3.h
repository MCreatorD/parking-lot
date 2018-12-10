#ifndef __TIMER3_H
#define __TIMER3_H

#include "stm32f2xx.h"

	#ifdef __cplusplus
	 extern "C" {
	#endif
		 
void Timer3_Init(void);
void Set_Timer3_Channel(uint16_t Current_TIM_Channel);
void Set_Timer3_Channe2(uint16_t Current_TIM_Channe2);
void RadioAir_GPIO_Init(void);
		 
		 
	#ifdef __cplusplus
	}
	#endif	
	
#endif 

	