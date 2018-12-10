#ifndef __KEY_EXTI_H
#define __KEY_EXTI_H	 
#include "stm32f2xx.h"
#include "config.h"
	#ifdef __cplusplus
	 extern "C" {
	#endif
		 
	 
	#define KEY0_PRES 	1	//KEY0����
	#define KEY1_PRES	2	//KEY1����
	#define KEY2_PRES	3	//KEY2����
	#define WKUP_PRES   4	//KEY_UP����(��WK_UP/KEY_UP)
	#define TRIG_DOWN   6
	#define read_start  7	
	#define TRIG_UP     0	//�ж϶��ΰ���	
		 
	extern volatile unsigned char  KEY_TYPE;		  //��ǰ���µļ�ֵ���� 
		 		 
	void SW_Key_Exit_Init(void);//�ⲿ�жϳ�ʼ��		
	void WKUP_Key_Exit_Init(void);//POWER_KEY	
	void Key1_Oled_Exit_Init(void);//KEY1_OLED PD6
    void Key2_Oled_Exit_Init(void);//KEY2_OLED PD5		 
	void Key3_Oled_Exit_Init(void);//KEY3_OLED PD4	


	void ConfigureOledKey(void);
	u8 KEY_Scan(u8);  	//����ɨ�躯��	
	#define SW_Key GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_9)//��ȡ����0(����)(ͼ�ϵ�λ�ã�����ʵ��λ��)
	#define KEY0   GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_6)//��ȡ����0(����)(ͼ�ϵ�λ�ã�����ʵ��λ��)
	#define KEY1   GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_5)//��ȡ����1(��)
	#define KEY2   GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_4)//��ȡ����2(��)
	#define WK_UP  GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)//��ȡ����3(�س�) 			 
			 

	#ifdef __cplusplus
	}
	#endif	 
#endif
