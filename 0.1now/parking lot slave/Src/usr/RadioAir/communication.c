#include "communication.h"
#include "EPC.h"
#include "timer.h"
#include "rx485_rev.h"
#include "rx485_send.h"
#include "RX485_uart.h"
#include "air_interface.h"
#include "utility.h"


#define ERROR_1 0x5
#define ERROR_2 0x6
#define ERROR_3 0x7
#define ERROR_4 0x8
#define ERROR_5 0x9
#define ERROR_6 0xa
#define ERROR_7 0xb
#define ERROR_8 0xc
#define ERROR_9 0xd


unsigned char TxBuffer[TXBUFFERSIZE];
unsigned char RxBuffer[RXBUFFERSIZE];

Slave_ConfigParam m_slave = {0,0,3700,0,1,0,0,10};//Ĭ�ϵ�ַ0 Ƶ��0 ����3700 ,�ز���,����ģʽ�������� ��������ͳ��,��λ����ż�

u8 Sm_MessageDeal(u8 count,u8 timeout) //������ת�ա���Ƶģ����� �������� ��ʵ����������ת ��ȫģ�鷢������Ƶ������
{
    uint8_t ret = 1;
    volatile uint16_t totelLength = 0;
    uint8_t Recv_Stage = 0;
	  Timeout=5;
		while((RX485_ReadyForRecv==0)&&(Timeout!=0))//�ȴ� ��ʶͨ����·��׼���ý���֡
		{
				;	
		}
		//�յ�����֡RxBuffer[]  ���ݳ���stringlen  �ж���������
		if(0xab==RxBuffer[0]) //֡ͷ 0xab
		{
				if(0x02==(RxBuffer[1]>>5))//��д��������
				{
						if(RxBuffer[1]==0x55)//��ȷ
						{
								ret = 4;
						}
						else if(RxBuffer[1] == 0x41)
						{
								ret = ERROR_1;
						}
						else if(RxBuffer[1] == 0x42)
						{
								ret = ERROR_2;
						}
						else if(RxBuffer[1] == 0x43)
						{
								ret = ERROR_3;
						}
						else if(RxBuffer[1] == 0x44)
						{
								ret = ERROR_4;
						}
						else if(RxBuffer[1] == 0x45)
						{
								ret = ERROR_5;
						}
						else if(RxBuffer[1] == 0x46)
						{
								ret = ERROR_6;
						}
						else if(RxBuffer[1] == 0x47)
						{
								ret = ERROR_7;
						}
						else if(RxBuffer[1] == 0x48)
						{
								ret = ERROR_8;
						}
						else if(RxBuffer[1] == 0x5f)
						{
								ret = ERROR_9;
						}
				}
				else if(0x01==(RxBuffer[1]>>5))//ָ��ת������֡
				{
						//У��ת��ָ������֡
//						 if(XOR_Cal(&RxBuffer[1],(uint8_t)(stringlen-2u))==RxBuffer[(uint8_t)(stringlen-1u)])
//							{
//									ret = 0x02;
//							}
//							else
//							{
//									ret = 0x00;
//							}
						ret = 0x02;
				}
				else
				{
						ret = 0;
				}
		}
		RX485_ReadyForRecv = 0;	//���ͨ��֡
    return ret;
}


u8 RF_To_SM(u8 bCommand,u8 *data,u8 timeout)//u8 bCommand,u8 *data,u8 timeout
{
	  uint16_t i;
    uint8_t ret;
	  ret = 1;
    Timeout= timeout;
	
	
    switch(bCommand)
    {
    case 0x01://�̵���֪ͨ֡
		//TxBuffer[0] = QUERY_FRAME;  //����λ
        TxBuffer[0] = 0xAA;
        TxBuffer[1] = 0x20;//����д��Ϊ  ����1
        for(i=0; i<16; i++)
        {
            TxBuffer[2+i] = data[i];
        }
        TxBuffer[18] = EPC_RN[0];
        TxBuffer[19] = EPC_RN[1];
        TxBuffer[20] = XOR_Cal(&TxBuffer[1],19);
       
		    sendCommData(m_slave.Slave_Addr,MASTER_CPU,RF_MODE,TxBuffer,21);
        break;
    case 0x05:  //�д� ������
		//TxBuffer[0] = QUERY_FRAME;
        TxBuffer[0] = 0xAA;
        TxBuffer[1] = 0x20;
        TxBuffer[2] = 0x0;
        TxBuffer[3] = 0x0;
        TxBuffer[4] =0x0;
        TxBuffer[5] =0x01;
        TxBuffer[6] =0x1e;
        TxBuffer[7] =0xad;
        TxBuffer[8] =0xe8;
        TxBuffer[9] =0x36;
        TxBuffer[10] =0x0f;
        TxBuffer[11] =0xc6;
        TxBuffer[12] =0x1b;
        TxBuffer[13] =0x65;
        TxBuffer[14] =0x8e;
        TxBuffer[15] =0x06;
        TxBuffer[16]=0xd3;
        TxBuffer[17] = 0x6b;
        TxBuffer[18] =0xa7;
        TxBuffer[19] = 0xd4;
        TxBuffer[20] = XOR_Cal(&TxBuffer[1],19);
        
	    	sendCommData(m_slave.Slave_Addr,MASTER_CPU,RF_MODE,TxBuffer,21);
		
        break;
    case 0x02://��Ӧ����֡
//		TxBuffer[0] = RESPOND_FRAME;  //����λ
        TxBuffer[0] = 0xAA;
        TxBuffer[1] = 0x40;
        TxBuffer[2] = RxBuffer[4];
        TxBuffer[3] = RxBuffer[5];
        for(i=0; i<((EPC_Return_Link_Bits+7)/8); i++)
        {
            TxBuffer[4+i] = EPC_Response_Recv_Buf[i];
        }
        TxBuffer[4+(EPC_Return_Link_Bits+7)/8] = XOR_Cal(&TxBuffer[1],(3+(EPC_Return_Link_Bits+7)/8));
        
	    	sendCommData(m_slave.Slave_Addr,MASTER_CPU,RF_MODE,TxBuffer,(6+(EPC_Return_Link_Bits+7)/8));
        break;
    case 0x03://֪ͨ��ȫģ�飬���ݴ������
        TxBuffer[0] =0xAA;
        TxBuffer[1] =0x62;
				sendCommData(m_slave.Slave_Addr,MASTER_CPU,RF_MODE,TxBuffer,2);
		
        break;
    case 0x04:
		//TxBuffer[0] = ERR_FRAME;  //����λ
        TxBuffer[0] = 0xAA;
        TxBuffer[1] = 0x95;
        
		    sendCommData(m_slave.Slave_Addr,MASTER_CPU,RF_MODE,TxBuffer,2);
        break;
    default:
        break;
    }

    if(Timeout==0)
    {
        ret = 0;
    }

    return ret;
}
