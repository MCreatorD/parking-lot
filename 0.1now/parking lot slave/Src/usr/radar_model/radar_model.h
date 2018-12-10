#ifndef __RADAR_MODEL_H
#define __RADAR_MODEL_H
#include "stm32f2xx.h"

//硬件资源
//主机 PB9输出 PB8采样   TIM10  通道1
//从机 PB6输出 PB7采样   TIM4   通道2
//雷达模块初始化 定时器输入捕获
//#define radar_host
#define rader_slave

#ifdef radar_host
	#define RADAR_PIN_T_Port			     GPIOB	
	#define RADAR_PIN_T                GPIO_Pin_9
	#define RADAR_PIN_T_CLK            RCC_AHB1Periph_GPIOB
	
	//方法函数
	#define RADAR_T_H                  GPIO_SetBits(RADAR_PIN_T_Port , RADAR_PIN_T)
	#define RADAR_T_L                  GPIO_ResetBits(RADAR_PIN_T_Port , RADAR_PIN_T)	

	#define RADAR_PIN_R_Port			     GPIOB	
	#define RADAR_PIN_R                GPIO_Pin_8
	#define RADAR_PIN_R_CLK            RCC_AHB1Periph_GPIOB

	#define RADAR_TIM 								 TIM10
	#define RADAR_TIM_PinSource 	     GPIO_PinSource8
	#define RADAR_AF_TIM 	             GPIO_AF_TIM10	
	#define RADAR_TIM_Channel				   TIM_Channel_1
	#define RADAR_TIM_CLK              RCC_APB2Periph_TIM10
	#define RADAR_TIM_RCC_APBxPeriphClockCmd  RCC_APB2PeriphClockCmd
	#define RADAR_TIM_IRQn       			 TIM1_UP_TIM10_IRQn
	#define RADAR_TIM_IRQHandler 			 TIM1_UP_TIM10_IRQHandler
	#define RADAR_TIM_Prescaler        120
  //输入捕获的通道
	#define RADAR_TIM_IT_CC       			TIM_IT_CC1
	#define RADAR_TIM_GetCapture        TIM_GetCapture1
	#define RADAR_TIM_FLAG	            TIM_FLAG_CC1
	
	#define	RADAR_TIM_TIM_OCxPolarityConfig  TIM_OC1PolarityConfig
#endif




#ifdef rader_slave

	#define RADAR_PIN_T_Port			     GPIOB	
	#define RADAR_PIN_T                GPIO_Pin_6
	#define RADAR_PIN_T_CLK            RCC_AHB1Periph_GPIOB
	
	//方法函数
	#define RADAR_T_H                  GPIO_SetBits(RADAR_PIN_T_Port , RADAR_PIN_T)
	#define RADAR_T_L                  GPIO_ResetBits(RADAR_PIN_T_Port , RADAR_PIN_T)	

	#define RADAR_PIN_R_Port			     GPIOB	
	#define RADAR_PIN_R                GPIO_Pin_7
	#define RADAR_PIN_R_CLK            RCC_AHB1Periph_GPIOB

	#define RADAR_TIM 								 TIM4
	#define RADAR_TIM_PinSource 	     GPIO_PinSource7
	#define RADAR_AF_TIM 	             GPIO_AF_TIM4	
	#define RADAR_TIM_Channel				   TIM_Channel_2
	#define RADAR_TIM_CLK              RCC_APB1Periph_TIM4	
	#define RADAR_TIM_RCC_APBxPeriphClockCmd  RCC_APB1PeriphClockCmd	
	#define RADAR_TIM_IRQn       			TIM4_IRQn
	#define RADAR_TIM_IRQHandler 			TIM4_IRQHandler
	#define RADAR_TIM_Prescaler        60	
	
  //输入捕获的通道
	#define RADAR_TIM_IT_CC       			TIM_IT_CC2
	#define RADAR_TIM_GetCapture        TIM_GetCapture2
	#define RADAR_TIM_FLAG	            TIM_FLAG_CC2
	
	#define	RADAR_TIM_TIM_OCxPolarityConfig  TIM_OC2PolarityConfig
#endif	
	extern u8   RADAR_TIM_CAPTURE_STA;	//输入捕获状态		    				
  extern u32	RADAR_TIM_CAPTURE_VAL;	  //输入捕获值(TIM2/TIM5是32位)
	
	
	
	void radar_init();
	//雷达模块发出脉冲 ,检测脉宽,输出数据
	unsigned short int radar_read();
#endif