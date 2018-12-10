#include "rs485.h"
#include "stm32f2xx.h"
void RS485_Init(void)//485 �շ����ƽ�
{
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_AHB1PeriphClockCmd(RS485_RX_EN_CLK, ENABLE);	         //ʹ��PB�˿�ʱ��
	
 GPIO_InitStructure.GPIO_Pin   = RS485_RX_EN_PIN;				   //LED0-->PB.5 �˿�����
 GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;        //���ģʽ  
 GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;        //�������
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;  
 GPIO_InitStructure.GPIO_PuPd  =  GPIO_PuPd_DOWN;      //����
 GPIO_Init(RS485_RX_EN_Port, &GPIO_InitStructure);					       //�����趨������ʼ��GPIOB.1
// GPIO_ResetBits(RS485_RX_EN_Port,RS485_RX_EN_PIN);						 //PB.1 ����� ����

//-----------------------------------------------------------	
 RCC_AHB1PeriphClockCmd(RS485_TX_EN_CLK, ENABLE);	         //ʹ��PB�˿�ʱ��
	
 GPIO_InitStructure.GPIO_Pin   = RS485_TX_EN_PIN;				   //LED0-->PB.5 �˿�����
 GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;        //���ģʽ  
 GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;        //�������
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;  
 GPIO_InitStructure.GPIO_PuPd  =  GPIO_PuPd_DOWN;      //����
 GPIO_Init(RS485_TX_EN_Port, &GPIO_InitStructure);					       //�����趨������ʼ��GPIOB.1
 //GPIO_ResetBits(RS485_TX_EN_Port,RS485_RX_EN_PIN);						 //PB.1 ����� ����

}
