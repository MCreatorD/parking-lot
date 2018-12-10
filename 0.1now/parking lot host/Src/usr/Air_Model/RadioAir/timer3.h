#ifndef __DAC1080S_H
#define __DAC1080S_H

#include "stm32f2xx.h"

	#ifdef __cplusplus
	 extern "C" {
	#endif
		 
void Timer3_Init(void);
void Timer3_Init_I(void);
void Set_Timer3_Channel(uint16_t Current_TIM_Channel);
void Set_Timer3_Channe2(uint16_t Current_TIM_Channe2);
void RadioAir_GPIO_Init(void);
		 
		 
	#ifdef __cplusplus
	}
	#endif	
	
#endif 

	