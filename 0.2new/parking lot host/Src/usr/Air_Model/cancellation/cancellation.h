#ifndef _cancellation_H
#define _cancellation_H

#include <stdarg.h>
#include "stm32f2xx.h"
#include "stdio.h"
#include "stdlib.h"

#define QP_CHANNEL 0
#define QN_CHANNEL 1
#define IP_CHANNEL 2
#define IN_CHANNEL 3

#define MOS_SW_PORT    GPIOD      //快速对消开关
#define MOS_SW_PIN     GPIO_Pin_10
#define MOS_SW_RCC     RCC_AHB1Periph_GPIOD
#define MOS_SW_Reset() GPIO_ResetBits(MOS_SW_PORT,MOS_SW_PIN)
#define MOS_SW_Set()   GPIO_SetBits(MOS_SW_PORT,MOS_SW_PIN)

#define ANGLE_DIV 20
#define PI 3.1415926
struct SQU_DA_Value{
	uint16_t Qp_DAValue;
	uint16_t Qn_DAValue;
	uint16_t Ip_DAValue;
	uint16_t In_DAValue;
	uint64_t Squ_Value;
};

	#ifdef __cplusplus
	 extern "C" {
	#endif
	extern struct SQU_DA_Value min_SquDAValue;
		 
	void Cancellation_Init(void);
	void Cancellation_Deinit(void);
	void Cancellation(void);
	void MOS_SW_GPIO_Init(uint8_t on);
	uint16_t setDACValue(uint16_t DACValue,int channel);			 
	#ifdef __cplusplus
	}
	#endif



#endif /*_cancellation_H*/
