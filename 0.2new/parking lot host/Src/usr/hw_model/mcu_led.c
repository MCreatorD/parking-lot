#include "mcu_led.h"

//初始化PB1为输出口.并使能这个口的时钟		    
//LED IO初始化
void LED_Init(void)
{
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_AHB1PeriphClockCmd(MCU_LED_CLK, ENABLE);	         //使能PB端口时钟
	
 GPIO_InitStructure.GPIO_Pin   = MCU_LED_PIN;				   //LED0-->PB.5 端口配置
 GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;        //输出模式  
 GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;        //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;  
 GPIO_InitStructure.GPIO_PuPd  =  GPIO_PuPd_DOWN;      //下拉
 GPIO_Init(MCU_LED_Port, &GPIO_InitStructure);					       //根据设定参数初始化GPIOB.1
 GPIO_ResetBits(MCU_LED_Port,MCU_LED_PIN);						 //PB.1 输出低 灯灭
}