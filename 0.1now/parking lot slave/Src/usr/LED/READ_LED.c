#include "READ_LED.h"

//��ʼ��PC9Ϊ�����.��ʹ������ڵ�ʱ��		    
//READ_LED IO��ʼ��
void READ_LED_Init(void)
{
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_AHB1PeriphClockCmd(READ_LED_CLK, ENABLE);	         
	
 GPIO_InitStructure.GPIO_Pin   = READ_LED_PIN;				   
 GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;           
 GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;          //�������
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;  
 GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;         //
 GPIO_Init(READ_LED_Port, &GPIO_InitStructure);         
 //GPIO_ResetBits(READ_LED_Port,READ_LED_PIN);					 //�����
}