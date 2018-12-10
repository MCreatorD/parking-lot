#include "power_led.h"

//��ʼ��PB0Ϊ�����.��ʹ������ڵ�ʱ��		    
//POWER_LED IO��ʼ��
void POWER_LED_Init(void)
{
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_AHB1PeriphClockCmd(POWER_LED_CLK, ENABLE);	         
	
 GPIO_InitStructure.GPIO_Pin   = POWER_LED_PIN;				   
 GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;           
 GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;          //�������
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;  
 GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;         //����
 GPIO_Init(POWER_LED_Port, &GPIO_InitStructure);         
 GPIO_SetBits(POWER_LED_Port,POWER_LED_PIN);					 //�����
}