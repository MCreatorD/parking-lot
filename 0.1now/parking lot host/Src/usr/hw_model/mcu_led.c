#include "mcu_led.h"

//��ʼ��PB1Ϊ�����.��ʹ������ڵ�ʱ��		    
//LED IO��ʼ��
void LED_Init(void)
{
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_AHB1PeriphClockCmd(MCU_LED_CLK, ENABLE);	         //ʹ��PB�˿�ʱ��
	
 GPIO_InitStructure.GPIO_Pin   = MCU_LED_PIN;				   //LED0-->PB.5 �˿�����
 GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;        //���ģʽ  
 GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;        //�������
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;  
 GPIO_InitStructure.GPIO_PuPd  =  GPIO_PuPd_DOWN;      //����
 GPIO_Init(MCU_LED_Port, &GPIO_InitStructure);					       //�����趨������ʼ��GPIOB.1
 GPIO_ResetBits(MCU_LED_Port,MCU_LED_PIN);						 //PB.1 ����� ����
}