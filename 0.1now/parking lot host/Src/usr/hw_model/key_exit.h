#ifndef __KEY_EXTI_H
#define __KEY_EXTI_H	 
#include "stm32f2xx.h"
#include "config.h"
	#ifdef __cplusplus
	 extern "C" {
	#endif
		 
	 
	#define KEY0_PRES 	1	//KEY0按下
	#define KEY1_PRES	2	//KEY1按下
	#define KEY2_PRES	3	//KEY2按下
	#define WKUP_PRES   4	//KEY_UP按下(即WK_UP/KEY_UP)
	#define TRIG_DOWN   6
	#define read_start  7	
	#define TRIG_UP     0	//中断二次按下	
		 
	extern volatile unsigned char  KEY_TYPE;		  //当前按下的键值类型 
		 		 
	void SW_Key_Exit_Init(void);//外部中断初始化		
	void WKUP_Key_Exit_Init(void);//POWER_KEY	
	void Key1_Oled_Exit_Init(void);//KEY1_OLED PD6
    void Key2_Oled_Exit_Init(void);//KEY2_OLED PD5		 
	void Key3_Oled_Exit_Init(void);//KEY3_OLED PD4	


	void ConfigureOledKey(void);
	u8 KEY_Scan(u8);  	//按键扫描函数	
	#define SW_Key GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_9)//读取按键0(返回)(图上的位置，不是实际位置)
	#define KEY0   GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_6)//读取按键0(返回)(图上的位置，不是实际位置)
	#define KEY1   GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_5)//读取按键1(左)
	#define KEY2   GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_4)//读取按键2(右)
	#define WK_UP  GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)//读取按键3(回车) 			 
			 

	#ifdef __cplusplus
	}
	#endif	 
#endif
