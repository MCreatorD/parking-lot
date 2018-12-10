#ifndef __READ_LED_H
#define __READ_LED_H
#include "stm32f2xx.h"

	#ifdef __cplusplus
	 extern "C" {
	#endif
	//Ӳ����ԴPC9
	#define READ_LED_Port			     GPIOC	
	#define READ_LED_PIN           GPIO_Pin_9
	#define READ_LED_CLK           RCC_AHB1Periph_GPIOC

	//��ʼ������
	extern void READ_LED_Init(void);

	//��������
	#define READ_LED_H             GPIO_SetBits(READ_LED_Port , READ_LED_PIN)
	#define READ_LED_L             GPIO_ResetBits(READ_LED_Port , READ_LED_PIN)

	/* ֱ�Ӳ����Ĵ����ķ�������IO */
	#define	digitalHi(p,i)			{p->BSRR=i;}			//����Ϊ�ߵ�ƽ		
	#define digitalLo(p,i)			{p->BRR=i;}				//����͵�ƽ
	#define digitalToggle(p,i)		{p->ODR ^=i;}			//�����ת״̬
	/* �������IO�ĺ� */
	#define READ_LED_TOGGLE		digitalToggle(READ_LED_Port,READ_LED_PIN)
	
	#ifdef __cplusplus
	}
	#endif
	
#endif