#ifndef __SM_H__
#define __SM_H__

/* Includes ------------------------------------------------------------------*/
#include "stm32f2xx.h"
//#include "board.h"
//GPIO口

	#ifdef __cplusplus
	 extern "C" {
	#endif
		 
//以下是安全模块信号线IO口		
		#define SM_RESET_Port			      GPIOD
		#define SM_RESET_OUT_IO         GPIO_Pin_1 

		#define SM_STATUS_Port			    GPIOD
		#define SM_STATUS_IN_IO         GPIO_Pin_2 

		#define SM_CTRL_Port			      GPIOD
		#define SM_CTRL_IN_IO           GPIO_Pin_0
	
//安全模块的时钟使能		 
		#define SM_RESET_ENABLE()       RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE)
		#define SM_STATUS_ENABLE()      RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE)		 		
		#define SM_CTRL_ENABLE()        RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	
//安全模块信号线操作		 
		#define SM_RESET_H             GPIO_SetBits(SM_RESET_Port , SM_RESET_OUT_IO)
		#define SM_RESET_L             GPIO_ResetBits(SM_RESET_Port , SM_RESET_OUT_IO)
		
//		#define SM_RESET_H             Board_EXIO_Init(0x0C)
//		#define SM_RESET_L             Board_EXIO_Init(0x08)

		#define SM_STATUS              GPIO_ReadInputDataBit(SM_STATUS_Port,SM_STATUS_IN_IO)
	
		#define SM_CTRL                GPIO_ReadInputDataBit(SM_CTRL_Port,SM_CTRL_IN_IO)
		
		void SM_GPIO_Init();
			 
	#ifdef __cplusplus
	}
	#endif	

#endif	