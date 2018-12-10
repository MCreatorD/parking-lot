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

		 NVIC_Init(&NVIC_InitStructure1);//初始化NVIC寄存器


		 TIM_DeInit(TIM2);
		 TIM_TimeBaseStructure.TIM_Period = (500-1);//50ms
		 TIM_TimeBaseStructure.TIM_Prescaler = 6000-1;
		 TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
		 TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
		 TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
 

		 TIM_ClearFlag(TIM2, TIM_FLAG_Update);

		 TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);//使能指定的TIM3中断,允许更新中断

			TIM_Cmd(TIM2, DISABLE);//使能TIMx
		// TIM_Cmd(TIM2, ENABLE);//使能TIMx  

}


void TIM2_IRQHandler(void)   //TIM3?D??
{
	if(TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET) 
	{
			//printf("闪烁。。\n");
		  BUZZER_LED_TOGGLE;
			TIM_ClearITPendingBit(TIM2, TIM_IT_Update  ); 
	}
} 
