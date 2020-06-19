#include "banister.h"

void BanisterIoInit(void)
{
	 GPIO_InitTypeDef  GPIO_InitStructure;
		
	 RCC_AHB1PeriphClockCmd(Banister_CLK, ENABLE);	         
		
	 GPIO_InitStructure.GPIO_Pin   = Banister_PIN;				   
	 GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;           
	 GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;          //�������
	 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;  
	 GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;         //
	 GPIO_Init(Banister_Port, &GPIO_InitStructure);         
	 //Banister_L;//��ɫ
	 ContrlBanister(!Baister_EN);
}

//���Ƶ�բ��
void ContrlBanister(int value)
{
	if(value)
	{
		Banister_H;
	}else{
		Banister_L;
	}
}

