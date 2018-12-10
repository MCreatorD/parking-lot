#include "rx485_rev.h"
#include "rx485_send.h"
#include "RX485_uart.h"
#include "communication.h"
#include "gpio.h"
#include <string.h>
#include "spi1.h"
#include "systick.h"
#include "testReadTag.h"
#include <stdio.h>
#include "buzzer_led.h"
//#include "main_application.h"
u8  RX485_ReadyForRecv; //标识通信链路已准备好接收帧
u16 RX485_recFrameLen; //当前收到的帧长度
u8 Device_cpu;//动态存储前段节点CPU
u8 Device_rf;//动态存储前段节点射频
u8 Device_end;//读卡结束

/**
*	反转义    头尾0x7E 数据中有7E 换成7D 5e,那有数据7D 换成0x7D 0x5D
*/
unsigned char deEscapeMessage(char* in,int in_len,char* out,int *out_len){
	
	  int i;
   	unsigned short crc;
	  unsigned short crc_get;
    if(in[0] == 0x7E && in[in_len - 1] == 0x7E)//校验数据头尾
    {
		*out_len = 0;
		//以下将对特殊字符的转义反转过来
		for(i = 1; i < in_len-1; i++) //数据
		{
			unsigned char c = in[i];
			if(c == 0x7D)
			{
				if(in[i + 1] == 0x5E)
				{
					out[(*out_len)++] = 0x7E; //连续的0x7D 0x5e 反转义成7E 
					i += 1;
				}
				else if(in[i + 1] == 0x5D)
				{
					out[(*out_len)++] = 0x7D; //连续的0x7D 0x5D 反转义成7D
					i += 1;
				}
				else
				{
					out[(*out_len)++] = c;
				}
			}
			else
			{
					out[(*out_len)++] = c;
			}
		}			

//		//转意 后最后一位 和倒数第二位是 crc校验位			
//    crc = out[(*out_len)-2]<<8|out[(*out_len)-1] ;
//		//不包含传输数据的头尾  0x7E
//		crc_get = getCRC16((unsigned char*)out,(int)((*out_len)-2)); //最后两个字节的CRC码不在计算范围内
//			
//		//发送过来的和接收数据运算得到的 crc 进行比较
//		if(crc != crc_get) {
//			return 0;
//		}
//		//把转义后的前两个字节去除，即串口通信帧中，加上的目标地址和源地址去除。
//		memmove(out,out,(*out_len)-2);
//		(*out_len) = (*out_len) - 2;
		return 1;
    }
    else
    {   
        return 0;
    }
}

unsigned char RX485_recvCommData(unsigned char *buf,int reclen){
		
		unsigned char out_buf[RX485_MAX_RX_LEN];
		int out_len = 0;
		unsigned char ok = deEscapeMessage((char*)buf,reclen,(char*)out_buf,&out_len);
		if(ok == 1) {
			memcpy(RX485_RxMessage,out_buf,out_len);
			RX485_recFrameLen = out_len;
	
			RX485_USART_RX_STA = 0;        //接收完成状态标记
			RX485_ReadyForRecv = 1;        //标识通信链路已准备好接收帧
			return  1;
		}else{
			RX485_USART_RX_STA = 0;
			RX485_ReadyForRecv = 0;   
			RX485_recFrameLen = 0;
			return 0;
		}
}

u8 MCU_MessageDeal(u8 *data,u16 reclen)
{ 
	  //printf("data[0] :%d\n",data[0]);
		switch(data[0])
		{
			case ReadCardEnd:
			{
				//current_dev_count++;//记录当前节点的读卡次数
				Device_end = 1;
				printf("ReadCardEnd \n");
				return ReadCardEnd;
				break;
			}
			case StartReadCardAck:
			{
				return StartReadCardAck;
				break;
			}			
			case StopReadCardAck:
			{
				return StopReadCardAck;
				break;
			}
			case ConfigSlaveAddrAck:
			{
				return ConfigSlaveAddrAck;
				break;
			}					
			case GetSlaveAddrAck:
			{
				return GetSlaveAddrAck;
				break;
			}
			case ConfigRfPowerAck:
			{
				return ConfigRfPowerAck;
				break;
			}
			case GetRadarDistanceAck:
			{ 
				printf("GetRadarDistanceAck ..... \n");
				return GetRadarDistanceAck;
			}
		}		
		return 0;
}


void RF_MessageDeal(u8 *data,u16 reclen)
{		
		SPI_I2S_DeInit(SPI1);
		SPI_Cmd(SPI1, ENABLE);
		PA12_H;	
		//前两帧方向和类型帧(除去),长度也减去前两帧						
		if(SPI_Send1(data,reclen) == 4)//把RxMessage消息体透传给安全模块	
		{ //读写操作结束读写正确
			//readTagFlag = hasNewTag;
			printf("success\r\n");	
		}	
		PA12_L;						
		SPI_Cmd(SPI1, DISABLE);				
}
u8 MessageDeal(u8 *data,u16 reclen)
{
	//源地址
	if(data[0] == Device_cpu || data[0] == LISTENING_ADDR)//来自主机与主机通信
	{   
		  //data[1] 目的地址
			if(data[1] == MASTER_CPU)
			{
				//data[2] cpu/rf
				if(data[2] == CPU_MODE)
				{  //从机cpu -> 主机cpu
					return MCU_MessageDeal(data+3,reclen-3);
				}
				else if(data[2] == RF_MODE)
				{  //射频 -> SM安全模块
					 RF_MessageDeal(data+3,reclen-3);
				}
			}		
	}
}

/*
* 消息应答
* SlaveAck ：从设备地址
*/
u8 SlaveAck(unsigned int SlaveAck)
{
		//源地址
		if(RX485_RxMessage[0] == Device_cpu || RX485_RxMessage[0] == LISTENING_ADDR)//来自主机与主机通信
		{   //从机CPU -> 主控CPU 
			//data[1] 目的地址
			if(RX485_RxMessage[1] == MASTER_CPU&& RX485_RxMessage[2] == CPU_MODE)
			{
				if(RX485_RxMessage[3] == SlaveAck)
				{
					//RxMessage[3] = 0;//清空数据位
					return 1;
				}									
			}
		}
		return 0;		
}

/*
* 等待消息应答
* SlaveAck ：从设备地址
* temp_time：超时等待时间
*/

u8 waitSlaveAck(unsigned int SlaveAck,unsigned int temp_time)
{
	slaveack_OvertimeCount = temp_time;
	while(slaveack_OvertimeCount)
	{
		if(RX485_ReadyForRecv == 1)
		{		 		
			RX485_ReadyForRecv = 0;	
			//源地址
			if(RX485_RxMessage[0] == Device_cpu || RX485_RxMessage[0] == LISTENING_ADDR)//来自主机与主机通信
			{   //从机CPU -> 主控CPU 
				//data[1] 目的地址
				if(RX485_RxMessage[1] == MASTER_CPU&& RX485_RxMessage[2] == CPU_MODE)
				{
					if(RX485_RxMessage[3] == SlaveAck)
					{
						return 1;
					}									
				}
			}			
		}
	}
	return 0;	
}

/*
* 等待返回应答含数据值
*Ack 类型  SlaveAck
*返回的数值指针 ack_data
*temp_time 等待时间
*/
u8 waitSlaveAckData(unsigned int SlaveAck,unsigned char *ack_data,unsigned int len,unsigned int temp_time)
{
	slaveack_OvertimeCount = temp_time;
	while(slaveack_OvertimeCount)
	{
		if(RX485_ReadyForRecv == 1)
		{		 
//			for(int i=0;i<4;i++)
//			{
//				printf("%02x",RxMessage[i]);
//			}			
			RX485_ReadyForRecv = 0;	
			//源地址
			if(RX485_RxMessage[0] == Device_cpu || RX485_RxMessage[0] == LISTENING_ADDR)//来自主机与主机通信
			{   //从机CPU -> 主控CPU 
				//data[1] 目的地址
				if(RX485_RxMessage[1] == MASTER_CPU&& RX485_RxMessage[2] == CPU_MODE)
				{
					if(RX485_RxMessage[3] == SlaveAck)
					{
						while(len)
						{
							ack_data[len-1] = RX485_RxMessage[len+3];
							len--;
						}
						return 1;
					}						
					//return MCU_MessageDeal(RxMessage+2,RX485_recFrameLen-2);			
				}
			}			
		}
	}
	return 0;
}
