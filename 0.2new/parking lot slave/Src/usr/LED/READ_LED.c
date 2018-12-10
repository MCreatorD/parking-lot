#include "READ_LED.h"

//初始化PC9为输出口.并使能这个口的时钟		    
//READ_LED IO初始化
void READ_LED_Init(void)
{
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_AHB1PeriphClockCmd(READ_LED_CLK, ENABLE);	         
	
 GPIO_InitStructure.GPIO_Pin   = READ_LED_PIN;				   
 GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;           
 GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;          //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;  
 GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;         //
 GPIO_Init(READ_LED_Port, &GPIO_InitStructure);         
 //GPIO_ResetBits(READ_LED_Port,READ_LED_PIN);					 //输出低
}