#ifndef __COMMUNICATION_H
#define __COMMUNICATION_H

#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32f2xx.h"
	     
typedef struct
{
	unsigned char Slave_Addr;        //�豸��ַ
	unsigned char RF_Frequency;      //��ƵƵ��  
	unsigned short int RF_Power;     //��Ƶ���� 16 λ 1500 ~ 3700 	
	unsigned char Carrier_flg;       //�ز�����״̬��ʶλ
	unsigned char Led_Mode;					 //����ʱ�ƹ�ģʽ�����в���
	unsigned short int radar_distance;//������
	unsigned char  read_switch_count;//��������ͳ�� 
	unsigned char  readcarthreshold;//��λ��λ�ż�����
}Slave_ConfigParam; //�豸����

extern Slave_ConfigParam m_slave;

#define TXBUFFERSIZE   200
#define RXBUFFERSIZE   200

//�����ĵ�ַ0
#define LISTENING_ADDR 0x00

//ͨ��֡
//0x7e        Դ��ַ       Ŀ�ĵ�ַ       cpu/rf      ��Ϣ����              0x7e
//1. Դ��ַ
#define MASTER_CPU         20  //����CPU

//3.cpu/rf  
#define CPU_MODE           21
#define RF_MODE            22

//2. ��Ϣ���� ͨ��֡      buf[1]
//��������������ָ��

#define ReadCardEnd      	  		 80  //�������� ;RF -> ����CPU 
#define RD_CARD_ERROR    	  		 81  //�������� ;RF -> ����CPU 

#define ReadCardEnd      	  		 80  //�������� ;RF -> ����CPU 
#define RD_CARD_ERROR    	  		 81  //�������� ;RF -> ����CPU 

#define StartReadCard     	 		 100  //��ʼ���� ;����CPU -> RF
#define StartReadCardAck   			 101  //��ʼ����Ӧ��

#define StopReadCard      	 		 102  //ֹͣ���� ;����CPU -> RF
#define StopReadCardAck    			 103  //ֹͣ����Ӧ��

#define ConfigSlaveAddr    			 104  //���ôӻ��ڵ��ADDR
#define ConfigSlaveAddrAck 			 105  //���ôӻ��ڵ��ַӦ��

#define GetSlaveAddr       			 106  //�ӽڵ���λ���
#define GetSlaveAddrAck    			 107  //�ӽڵ���λ���Ӧ�𷵻ص�ַ

#define SetSlaveMessage          108   //���ôӽڵ��豸��Ϣ
#define SetSlaveMessageAck       109   //���ôӽڵ��豸��ϢӦ��

#define GetSlaveMessage          110   //�ӽڵ��豸��Ϣ��ѯ
#define GetSlaveMessageAck       111   //�ӽڵ��豸��Ϣ��ѯӦ��

#define ConfigRfPower      			 112   //������Ƶ����
#define ConfigRfPowerAck   			 113   //������Ƶ����Ӧ��

#define GetSlaveRfPower    			 114   //��ѯ�ӽڵ���Ƶ����ֵ
#define GetSlaveRfPowerAck 			 115   //��ѯ�ӽڵ���Ƶ����ֵӦ��

#define ConfigFrequency    			 116   //������ƵƵ��
#define ConfigFrequencyAck 			 117   //������Ƶ����Ӧ��

#define GetSlaveFrequency    		 118   //��ѯ�ӽڵ���Ƶ��ƵƵ��
#define GetSlaveFrequencyAck 		 119   //��ѯ�ӽڵ���Ƶ��Ƶ����Ӧ��

#define ConfigCarrier     	  	 120    //���ز�
#define ConfigCarrierAck   			 121    //���ز�Ӧ��

#define GetSlaveCarrier     	   122    //��ѯ�ӽڵ��ز�����״̬
#define GetSlaveCarrierAck   		 123    //��ѯ�ӽڵ��ز�����״̬Ӧ��

#define ConfigCancellation     	 124    //����
#define ConfigCancellationAck  	 125    //��������Ӧ��

#define GetSlaveCancellation     126   //����ֵ��ȡ
#define GetSlaveCancellationAck  127    //����ֵ��ȡӦ��

#define ConfigLedMode            128    //���õƹ�ģʽ
#define ConfigLedModeAck         129    //���õƹ�ģʽӦ��

#define GetLedMode               130    //��ѯ�ƹ�ģʽ
#define GetLedModeAck            131    //��ѯ�ƹ�ģʽӦ��

#define GetRadarDistance         132    //��ѯ�״�����ֵcm
#define GetRadarDistanceAck      133    //��ѯ�״�����ֵcmӦ��

#define ConfigLedThreshold       134    //������λ����ż���ֵ
#define ConfigLedThresholdAck    135    //������λ����ż���ֵӦ��

#define GetSlaveLedThreshold     136    //��ѯ������λ����ż���ֵ
#define GetSlaveLedThresholdAck  137    //��ѯ������λ����ż���ֵӦ��

extern  unsigned char TxBuffer[TXBUFFERSIZE];
extern  unsigned char RxBuffer [RXBUFFERSIZE];

u8 Sm_MessageDeal(u8 count,u8 timeout);
u8 RF_To_SM(u8 bCommand,u8 *data,u8 timeout);

#ifdef __cplusplus
}
#endif
 

#endif

