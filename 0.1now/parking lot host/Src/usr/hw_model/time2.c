#include "time2.h"
#include "stm32f2xx.h"
#include <stdio.h>
#include "buzzer_led.h"
void TIM2_Configuration(void)
{

		 NVIC_InitTypeDef NVIC_InitStructure1;

		 TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;

		 RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	

		 NVIC_InitStructure1.NVIC_IRQChannel = TIM2_IRQn;

		 NVIC_InitStructure1.NVIC_IRQChannelPreemptionPriority = 2;

		 NVIC_InitStructure1.NVIC_IRQChannelSubPriority = 2;

		 NVIC_InitStructure1.NVIC_IRQChannelCmd = ENABLE;

		 NVIC_Init(&NVIC_InitStructure1);//��ʼ��NVIC�Ĵ���


		 TIM_DeInit(TIM2);
		 TIM_TimeBaseStructure.TIM_Period = (500-1);//50ms
		 TIM_TimeBaseStructure.TIM_Prescaler = 6000-1;
		 TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
		 TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
		 TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
 

		 TIM_ClearFlag(TIM2, TIM_FLAG_Update);

		 TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);//ʹ��ָ����TIM3�ж�,��������ж�

			TIM_Cmd(TIM2, DISABLE);//ʹ��TIMx
		// TIM_Cmd(TIM2, ENABLE);//ʹ��TIMx  

}


void TIM2_IRQHandler(void)   //TIM3?D??
{
	if(TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET) 
	{
			//printf("��˸����\n");
		  BUZZER_LED_TOGGLE;
			TIM_ClearITPendingBit(TIM2, TIM_IT_Update  ); 
	}
} 
