#include "testReadTag.h"
#include "systick.h"
//#include "ws_spi.h"
#include <stdio.h>
#include "spi.h"
#include "sm.h"
//����������־λ
uint8_t readTagFlag = 0;

void waitSafeFalling(void)
{
    while(GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_0)==1)
    {
        ;
    }
}

uint8_t CreateReadTagConfig(u8* buff)
{	
	  buff[0]=0xaa; //ͬ��ͷ ��������ȡֵ0xAA,�ϱ�����ȡֵ0xAB
    buff[1]=0x11; //֡���� 0001 ����֡ 0001�汾��
    buff[2]=9;    //֡���� 9
    buff[3]=0;    //֡����
    buff[4]=0x06; //֡���� ������ʶ ��6������ģʽ
    buff[5]=0;    //���������� 0 ����ʾʶ��TID����ģʽ������ȡ�κη������ݣ�
    buff[6]=0x00; //������ user_0
    buff[7]=0x02; //��������ָʾ �б�ָ���ȡȫ������
    buff[8]=0x01; //0000 ����   0001 ���ٶ�
    buff[9]=0;    //
    buff[10]=0;
    buff[11]=0;
    buff[12]=0;
    buff[13]=XOR_Cal(&buff[1],12); //У����
    return 14;
}

uint8_t CreateReaduser0TagConfig(u8* buff)
{
	//aa,11,09,00,06,01,00,02,01,00,00,00,00,1c
	  buff[0]=0xaa; //ͬ��ͷ ��������ȡֵ0xAA,�ϱ�����ȡֵ0xAB
    buff[1]=0x11; //֡���� 0001 ����֡ 0001�汾��
    buff[2]=0x09;    //֡���� 9
    buff[3]=0x00;    //֡����
    buff[4]=0x06; //֡���� ������ʶ ��6������ģʽ
    buff[5]=0x01;    //���������� 0 ����ʾʶ��TID����ģʽ������ȡ�κη������ݣ�
    buff[6]=0x00; //������ user_0
    buff[7]=0x02; //��������ָʾ �б�ָ���ȡȫ������
    buff[8]=0x01; //0000 ����   0001 ���ٶ�
    buff[9]=0x00;    //
    buff[10]=0x00;
    buff[11]=0x00;
    buff[12]=0x00;
	  buff[13]=0x1c;
    return 14;
}

uint8_t ConfigSmReadTID()//�����Ƿ���ɵı�־λ   1�������óɹ�
{
		uint8_t ConfLen; 
		uint8_t ConfigBuff[50];
	    uint8_t RecSafe[256];
	    u8 tmp = 1;
	 // static uint8_t ConfigFlag = 0;
	 //	if(ConfigFlag == 0)
	 //	{
			//SysTick->CTRL  &= ~SysTick_CTRL_ENABLE_Msk;//���ù��̷�ֹ���Źرյδ�ʱ��
			ConfLen=CreateReadTagConfig(ConfigBuff);//����ʶ��TID����ģʽ֡
			SPI2_Send_bytes(ConfigBuff,ConfLen);    //���͵���ȫģ��
			printf("waite SM reback \n");
			rfOper_OvertimerCount = 2000;
			while(tmp &&  rfOper_OvertimerCount)
			{
				//printf("rfOper_OvertimerCount:%d\n",rfOper_OvertimerCount);
				tmp = SM_CTRL;
			}
			SPI2_Receive_bytes(RecSafe,7);//���հ�ȫģ��������ϱ�
			if(RecSafe[5] == 0)
			printf("SM config success \n");
			else
			printf("SM config fall    \n");
			
			//SysTick->CTRL  |= SysTick_CTRL_ENABLE_Msk;//���ý��� �����δ�ʱ��
			//ConfigFlag=1;		
		//}

		//return ConfigFlag;
}


uint8_t ConfigSmReadUser0()//�����Ƿ���ɵı�־λ   1�������óɹ�
{
		uint8_t ConfLen; 
		uint8_t ConfigBuff[50];
		uint8_t RecSafe[256];
	    u8 tmp = 1;
	  //static uint8_t ConfigFlag = 0;
	  //if(ConfigFlag == 0)
	  //{
			//SysTick->CTRL  &= ~SysTick_CTRL_ENABLE_Msk;//���ù��̷�ֹ���Źرյδ�ʱ��
			ConfLen=CreateReaduser0TagConfig(ConfigBuff);//����ʶ��TID����ģʽ֡
			SPI2_Send_bytes(ConfigBuff,ConfLen);    //���͵���ȫģ��
			printf("waite SM reback \n");
			//���CRTL_OUT �ȴ���ȫģ��������ϱ� 
			rfOper_OvertimerCount = 2000;
			while(tmp &&  rfOper_OvertimerCount)
			{
				//printf("rfOper_OvertimerCount:%d\n",rfOper_OvertimerCount);
				tmp = SM_CTRL;
			}
			
			SPI2_Receive_bytes(RecSafe,7);//���հ�ȫģ��������ϱ�
			if(RecSafe[5] == 0)
			printf("SM config success \n");
			else
			printf("SM config fall    \n");
			
			//SysTick->CTRL  |= SysTick_CTRL_ENABLE_Msk;//���ý��� �����δ�ʱ��
	       //ConfigFlag=1;		
	  //}

	  //return ConfigFlag;
}


	


