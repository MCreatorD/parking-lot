#include "rs485.h"
#include "stm32f2xx.h"
void RS485_Init(void)//485 收发控制脚
{
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_AHB1PeriphClockCmd(RS485_RX_EN_CLK, ENABLE);	         //使能PB端口时钟
	
 GPIO_InitStructure.GPIO_Pin   = RS485_RX_EN_PIN;				   //LED0-->PB.5 端口配置
 GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;        //输出模式  
 GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;        //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;  
 GPIO_InitStructure.GPIO_PuPd  =  GPIO_PuPd_DOWN;      //下拉
 GPIO_Init(RS485_RX_EN_Port, &GPIO_InitStructure);					       //根据设定参数初始化GPIOB.1
// GPIO_ResetBits(RS485_RX_EN_Port,RS485_RX_EN_PIN);						 //PB.1 输出低 灯灭

//-----------------------------------------------------------	
 RCC_AHB1PeriphClockCmd(RS485_TX_EN_CLK, ENABLE);	         //使能PB端口时钟
	
 GPIO_InitStructure.GPIO_Pin   = RS485_TX_EN_PIN;				   //LED0-->PB.5 端口配置
 GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;        //输出模式  
 GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;        //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;  
 GPIO_InitStructure.GPIO_PuPd  =  GPIO_PuPd_DOWN;      //下拉
 GPIO_Init(RS485_TX_EN_Port, &GPIO_InitStructure);					       //根据设定参数初始化GPIOB.1
 //GPIO_ResetBits(RS485_TX_EN_Port,RS485_RX_EN_PIN);						 //PB.1 输出低 灯灭

}
