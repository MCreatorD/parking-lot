#ifndef __DAC1080S_H
#define __DAC1080S_H

#include "stm32f2xx.h"

	#ifdef __cplusplus
	 extern "C" {
	#endif
		 
	#define AD_DA_REF    5070
		 
	#define CHANNEL_A             0
	#define CHANNEL_B             1
	#define CHANNEL_C             2
	#define CHANNEL_D             3
	#define CHANNEL_E             4
	#define CHANNEL_F             5
	#define CHANNEL_G             6
	#define CHANNEL_H             7
		 

	void DAC1080S_Write(u16 value,u8 channel);		 
	void Set_WTM(void);
	void Set_WRM(void);	
	void DAC1080S_Write_Value2(u16 value1,u16 value2,u8 channel_1,u8 channel_2);	
		 		 
	#ifdef __cplusplus
	}
	#endif
	

	
#endif 

