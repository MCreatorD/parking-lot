#ifndef __GPIO_H__
#define __GPIO_H__

/* Includes ------------------------------------------------------------------*/
#include "stm32f2xx.h"
#include <stdint.h>

//GPIO��

	#ifdef __cplusplus
	 extern "C" {
	#endif
		//PCF8574 ��չIO
		void Board_EXIO_Init(uint8_t IO_ST);
		void GPIO_Configuration(void);
		
		 
		//��������
		#define PA12_H             GPIO_SetBits(GPIOA , GPIO_Pin_12)
		#define PA12_L             GPIO_ResetBits(GPIOA , GPIO_Pin_12)
		 
	#ifdef __cplusplus
	}
	#endif	

#endif