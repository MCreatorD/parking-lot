#include "buzzer_led.h"

//��ʼ��PC5Ϊ�����.��ʹ������ڵ�ʱ��		    
//BUZZER_LED IO��ʼ��
void BUZZER_LED_Init(void)
{
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_AHB1PeriphClockCmd(BUZZER_LED_CLK, ENABLE);	         
	
 GPIO_InitStructure.GPIO_Pin   = BUZZER_LED_PIN;				   
 GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;           
 GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;          //�������
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;  
 GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;         //
 GPIO_Init(BUZZER_LED_Port, &GPIO_InitStructure);         
 BUZZER_LED_H;//��ɫ	
}