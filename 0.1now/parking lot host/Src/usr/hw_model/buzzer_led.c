#include "buzzer_led.h"

//初始化PC5为输出口.并使能这个口的时钟		    
//BUZZER_LED IO初始化
void BUZZER_LED_Init(void)
{
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_AHB1PeriphClockCmd(BUZZER_LED_CLK, ENABLE);	         
	
 GPIO_InitStructure.GPIO_Pin   = BUZZER_LED_PIN;				   
 GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;           
 GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;          //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;  
 GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;         //
 GPIO_Init(BUZZER_LED_Port, &GPIO_InitStructure);         
 BUZZER_LED_H;//绿色	
}