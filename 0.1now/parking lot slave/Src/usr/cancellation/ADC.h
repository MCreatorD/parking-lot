#ifndef __ADC_H
#define __ADC_H


#ifdef __cplusplus
 extern "C" {
#endif
	 
#include "stm32f2xx.h"
	 
#define ADC_I  ADC1
#define ADC_Q  ADC2

void Cancellation_ADC_Init(void);
uint16_t Get_ADC_Value(ADC_TypeDef* ADCx);
	 
	 

#ifdef __cplusplus
}
#endif

#endif
