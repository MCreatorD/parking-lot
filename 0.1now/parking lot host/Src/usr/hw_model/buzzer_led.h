#ifndef __BUZZER_LED_H
#define __BUZZER_LED_H
#include "stm32f2xx.h"

	#ifdef __cplusplus
	 extern "C" {
	#endif
	//Ӳ����ԴPC5 --> PD12
	#define BUZZER_LED_Port			     GPIOD	
	#define BUZZER_LED_PIN           GPIO_Pin_12
	#define BUZZER_LED_CLK           RCC_AHB1Periph_GPIOD

	//��ʼ������
	extern void BUZZER_LED_Init(void);

	//��������
	#define BUZZER_LED_H             GPIO_SetBits(BUZZER_LED_Port , BUZZER_LED_PIN)
	#define BUZZER_LED_L             GPIO_ResetBits(BUZZER_LED_Port , BUZZER_LED_PIN)

	/* ֱ�Ӳ����Ĵ����ķ�������IO */
	#define	digitalHi(p,i)			{p->BSRR=i;}			//����Ϊ�ߵ�ƽ		
	#define digitalLo(p,i)			{p->BRR=i;}				//����͵�ƽ
	#define digitalToggle(p,i)		{p->ODR ^=i;}			//�����ת״̬
	/* �������IO�ĺ� */
	#define BUZZER_LED_TOGGLE		digitalToggle(BUZZER_LED_Port,BUZZER_LED_PIN)
	
	#ifdef __cplusplus
	}
	#endif
#endif