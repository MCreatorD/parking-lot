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

Slave_ConfigParam m_slave = {0,0,3700,0,1,0,0,10};//默认地址0 频点0 功放3700 ,载波关,运行模式，测距距离 读卡轮数统计,在位检测门槛

u8 Sm_MessageDeal(u8 count,u8 timeout) //【数据转收】射频模块接收 主控数据 ，实际是主控中转 安全模块发送至射频的数据
{
    uint8_t ret = 1;
    volatile uint16_t totelLength = 0;
    uint8_t Recv_Stage = 0;
	  Timeout=5;
		while((RX485_ReadyForRecv==0)&&(Timeout!=0))//等待 标识通信链路已准备好接收帧
		{
				;	
		}
		//收到数据帧RxBuffer[]  数据长度stringlen  判断数据类型
		if(0xab==RxBuffer[0]) //帧头 0xab
		{
				if(0x02==(RxBuffer[1]>>5))//读写操作结束
				{
						if(RxBuffer[1]==0x55)//正确
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
				else if(0x01==(RxBuffer[1]>>5))//指令转发数据帧
				{
						//校验转发指令数据帧
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
		RX485_ReadyForRecv = 0;	//清空通信帧
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
    case 0x01://盘点结果通知帧
		//TxBuffer[0] = QUERY_FRAME;  //控制位
        TxBuffer[0] = 0xAA;
        TxBuffer[1] = 0x20;//天线写死为  天线1
        for(i=0; i<16; i++)
        {
            TxBuffer[2+i] = data[i];
        }
        TxBuffer[18] = EPC_RN[0];
        TxBuffer[19] = EPC_RN[1];
        TxBuffer[20] = XOR_Cal(&TxBuffer[1],19);
       
		    sendCommData(m_slave.Slave_Addr,MASTER_CPU,RF_MODE,TxBuffer,21);
        break;
    case 0x05:  //有错 ，无用
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
    case 0x02://响应数据帧
//		TxBuffer[0] = RESPOND_FRAME;  //控制位
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
    case 0x03://通知安全模块，数据传输错误，
        TxBuffer[0] =0xAA;
        TxBuffer[1] =0x62;
				sendCommData(m_slave.Slave_Addr,MASTER_CPU,RF_MODE,TxBuffer,2);
		
        break;
    case 0x04:
		//TxBuffer[0] = ERR_FRAME;  //控制位
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
