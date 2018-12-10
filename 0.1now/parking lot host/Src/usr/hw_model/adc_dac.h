#ifndef _BOARD_H_
#define _BOARD_H_

#include "stm32f2xx.h"

	#ifdef __cplusplus
	 extern "C" {
	#endif
		 void Board_DAC_Init1(void);
		 void Board_ADC_Init1(void);
		 uint16_t Get_ADC_Value1(ADC_TypeDef* ADCx);

	#ifdef __cplusplus
	}
	#endif	

#endif
	