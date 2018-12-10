#include "rx485_rev.h"
#include "rx485_send.h"
#include "RX485_uart.h"
#include "communication.h"
#include "timer.h"
#include "EN25Q256.h"
#include "utility.h"
#include "rf_oper.h"
#include "LMX2541.h"
#include "cancellation.h"
#include <string.h>
#include <stdio.h>
#include "flashmanage.h"
#include "radar_model.h"
#include "read_led_manage.h"
#include "update.h"
volatile u8  RX485_ReadyForRecv=0; //标识通信链路已准备好接收帧
volatile int RX485_recFrameLen=0; //当前收到的帧长度

extern u8  ReadCard_Flg;
extern u32 ReadCard_Count;
volatile u8 stringlen=0;
/**
*	反转义    头尾0x7E 数据中有7E 换成7D 5e,那有数据7D 换成0x7D 0x5D
*/
unsigned char deEscapeMessage(char* in,int in_len,char* out,int *out_len)
{
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

		//转意 后最后一位 和倒数第二位是 crc校验位			
//    crc = out[(*out_len)-2]<<8|out[(*out_len)-1] ;
//		//不包含传输数据的头尾  0x7E
//		crc_get = getCRC16((unsigned char*)out,(int)((*out_len)-2)); //最后两个字节的CRC码不在计算范围内
//			
//		//发送过来的和接收数据运算得到的 crc 进行比较
//		if(crc != crc_get) {
//			return 0;
//		}
		//把转义后的前两个字节去除，即串口通信帧中，加上的目标地址和源地址去除。
		//memmove(out,out,(*out_len)-2);
		//(*out_len) = (*out_len) - 2;
		return 1;
    }
    else
    {   
        return 0;
    }
}

unsigned char RX485_recvCommData(unsigned char *buf,int reclen){
		
		unsigned char out_buf[MAX_RX_LEN];
		int out_len = 0;
		unsigned char ok = deEscapeMessage((char*)buf,reclen,(char*)out_buf,&out_len);
		if(ok == 1) {
			memcpy(RxMessage,out_buf,out_len);
			RX485_recFrameLen = out_len;
	
			RX485_USART_RX_STA = 0;        //接收完成状态标记  接收到数据到完整到数据被反转义后销毁
			RX485_ReadyForRecv = 1;        //标识通信链路已准备好接收帧
			return  1;
		}else{
			RX485_USART_RX_STA = 0;
			RX485_ReadyForRecv = 0;   
			RX485_recFrameLen = 0;
			return 0;
		}
}

//
u8 MCU_MessageDeal(u8 *data,u16 RecLen)
{
	//static u8 start_read = 0;
	u8 tmp_addr = 0;
	switch(data[0])
	{
		case StartReadCard://开始读卡 ;主控MCU -> 射频MCU
		{
			//响应应答
			//MCU_To_MCU(m_slave.Slave_Addr,Comm_OK);
			printf("start\n");
			ReadCard_Flg=1;	
			//MCU_To_MCU(m_slave.Slave_Addr,GetRadarDistanceAck);//查询雷达测距数值cm应答	
			//控制轮数
			ReadCard_Count++;
			m_slave.read_switch_count++;//每次开始读卡时统计下切换轮数
			break;			
		}

		case StopReadCard://停止读卡 ;主控MCU -> 射频MCU
		{
		  //TIM_Cmd(TIM2, DISABLE);//使能TIMx 	
      //led_l;//切换成绿色			
			printf("stop\n");
			ReadCard_Flg=0;
			break;
		}
		case GetSlaveAddr : //从节点在位检测
		{
			MCU_To_MCU(m_slave.Slave_Addr,GetSlaveAddrAck);
			printf("GetSlaveAddrAck:%d\n",m_slave.Slave_Addr);		
			break;
		}
		case ConfigSlaveAddr://配置从机地址
		{
			printf("config ...\n");
			tmp_addr = data[1];//从机地址 更新到ram tmp_addr中
			if(flash_Dev_ok == flash_Isok)//flash 设备正常
			{
				EN25Q256_Write(&tmp_addr,flash_dev_addr,1);
				EN25Q256_Read(&tmp_addr,flash_dev_addr,1);//数据校验
				if(tmp_addr == data[1])
				{
					m_slave.Slave_Addr = tmp_addr;                //更新ram 状态标志位和 flash 标志位
					//flash存储正常 更新到全局变量
					flash_flag.Slave_Addr_flag = flash_Isok;//0x0A:正常					
					EN25Q256_Write(&flash_flag.Slave_Addr_flag,addrMessage_flag,1);
					MCU_To_MCU(m_slave.Slave_Addr,ConfigSlaveAddrAck);//ConfigSlaveAddrAck
					printf("salve addr %d config ok \n",tmp_addr);
				}
			}			
			break;
		}
		case SetSlaveMessage://设置从节点设备信息
		{
		 //u8 datatemp[70];		
		  printf("config ...\n");		
			int num = strlen((const char *)&data[1]);
			printf("strlen :%d\n",num);
			 printf("TxMessage :%s\n",&data[1]);
			if(flash_Dev_ok == flash_Isok)//flash 设备正常
			{
				SetDerviceVersion((u8 *)&data[1],num);
				//GetDerviceVersion(datatemp);
			}			
			//	m_slave.Slave_Addr		
			MCU_To_MCU(0,SetSlaveMessageAck);			
			break;
		}
		case GetSlaveMessage://从节点设备信息查询
		{
			printf("GetSlaveMessage \n");
			MCU_To_MCU(0,GetSlaveMessageAck);
			break;
		}		
		case ConfigRfPower://配置射频功率 ;  主控MCU -> 射频MCU
		{
			m_slave.RF_Power = data[1]<<8|data[2];
			configrfparam(m_slave.RF_Power,m_slave.RF_Frequency);			
			MCU_To_MCU(m_slave.Slave_Addr,ConfigRfPowerAck);//ConfigRfPowerAck
			printf("%d,ConfigRfPowerAck \n",m_slave.RF_Power);
			break;
		}
		case GetSlaveRfPower://查询从节点射频功率值 ;  主控MCU -> 射频MCU
		{
			MCU_To_MCU(m_slave.Slave_Addr,GetSlaveRfPowerAck);//查询从节点射频功率值应答
			printf("%d,GetSlaveRfPowerAck \n",m_slave.RF_Power);
			break;
		}		
		case ConfigFrequency://配置射频频点 ;  主控MCU -> 射频MCU
		{
			m_slave.RF_Frequency = data[1];
			LMX2541_SetFrequency(m_slave.RF_Frequency);
			configrfparam(m_slave.RF_Power,m_slave.RF_Frequency);
			MCU_To_MCU(m_slave.Slave_Addr,ConfigFrequencyAck);//ConfigFrequencyAck
			printf("%d,ConfigFrequencyAck \n",m_slave.RF_Frequency);
			break;
		}		
		case GetSlaveFrequency://查询从节点射频射频频点 ;  主控MCU -> 射频MCU
		{
			MCU_To_MCU(m_slave.Slave_Addr,GetSlaveFrequencyAck);//查询从节点射频射频功率应答
			printf("%d,GetSlaveFrequencyAck \n",m_slave.RF_Frequency);
			break;
		}		
		case ConfigCarrier://开关载波 ;  主控MCU -> 射频MCU
		{
			if(1 == data[1])
			{
				  m_slave.Carrier_flg = 1;//载波开启标志位
					RFPowerON(m_slave.RF_Power);//开载波		
					printf("RFPowerON(%d)\n",m_slave.RF_Power);				
			}else
			{
				  m_slave.Carrier_flg = 0;//载波开启标志位
					RFPowerOFF();//关载波	
					printf("RFPowerOFF \n");
			}
			MCU_To_MCU(m_slave.Slave_Addr,ConfigCarrierAck);//开载波应答
			break;
		}
		case GetSlaveCarrier:     	       //查询从节点载波开关状态
		{
			printf("GetSlaveCarrier ack \n");
			MCU_To_MCU(m_slave.Slave_Addr,GetSlaveCarrier);//查询从节点载波开关状态应答
			break;
		}
		case ConfigCancellation://对消 ;  主控MCU -> 射频MCU
		{
			printf("Cancellation.. RFPowerON(%d)\n",m_slave.RF_Power);		
			isneedCancelltion = 1;
			break;
		}	
		
		case GetSlaveCancellation://对消值查询
		{
			printf("GetSlaveCancellation");
			MCU_To_MCU(m_slave.Slave_Addr,GetSlaveCancellationAck);//对消值查询应答
			break;
		}
		case ConfigLedMode://配置灯光模式 ;  主控MCU -> 射频MCU
		{
			//1.关闭定时器
			TIM_Cmd(TIM2, DISABLE);//使能TIMx 
			u8 SelectStep = 0;
			u8 hasCar = 0;			
			
      led_l;//切换成绿色			
			m_slave.Led_Mode = data[1];//配置灯光模式		
			printf("m_slave.Led_Mode %d\n",m_slave.Led_Mode);				
			MCU_To_MCU(m_slave.Slave_Addr,ConfigLedModeAck);//配置灯光模式应答
			break;
		}
		
		case GetLedMode://查询灯光模式 ;  主控MCU -> 射频MCU
		{	
			MCU_To_MCU(m_slave.Slave_Addr,GetLedModeAck);//查询灯光模式应答
			printf("GetLedMode：%d\n",m_slave.Led_Mode);	
			break;
		}	
		case ConfigLedThreshold://车辆在位检测门槛数值
		{
			m_slave.readcarthreshold = data[1];//配置车辆在位检测门槛数值		
			printf("m_slave.readcarthreshold %d\n",m_slave.readcarthreshold);	
			MCU_To_MCU(m_slave.Slave_Addr,ConfigLedThresholdAck);//配置车辆在位检测门槛数值应答	
			break;
		}
		
		case GetSlaveLedThreshold://查询车辆在位检测门槛数值
		{	
			MCU_To_MCU(m_slave.Slave_Addr,GetSlaveLedThresholdAck);//配置车辆在位检测门槛数值应答	
			printf("GetSlaveLedThresholdAck：%d\n",m_slave.readcarthreshold);	
			break;
		}		
		
		case GetRadarDistance://查询雷达测距数值cm ;  主控MCU -> 射频MCU
		{	
      m_slave.radar_distance =	radar_read();
			MCU_To_MCU(m_slave.Slave_Addr,GetRadarDistanceAck);//查询雷达测距数值cm应答	
			break;
		}
		case Updateslavehandle://升级从机程序握手
		{
			handleupdate(data[1]<<8|data[2]);
			printf("handleupdate\n");
			MCU_To_MCU(m_slave.Slave_Addr,UpdateslavehandleAck);
			break;			
		}		
		case Updateslave:
		{
			uint16_t num = data[1]<<8|data[2];//当前是第几包
			uint16_t len = data[3]<<8|data[4];//当前数据长度 
			printf("update blcok[%d] to slave mcu success,block len is %d !\n",num,len);
			
//			if(num == 1||num == m_UpdateTotalPack)
//			{
//				printf("bytes is ");
//				for(int i=0;i<len;i++){
//						printf("0x%02x,",data[5+i]);
//				}
//				printf("\n");
//			}	
			
			sendFrameToSlavemcu(data+5,len);
			binlen += len;//记录文件接收文件大小

			TxMessage[0] = UpdateslaveAck;
			TxMessage[1] = data[1];
			TxMessage[2] = data[2];
			sendCommData(m_slave.Slave_Addr ,MASTER_CPU ,CPU_MODE,TxMessage,3);
			if(m_UpdateTotalPack == num)//接收到最后一包更新标志位
			{
					char *p= "slve20181204V1.bin";
					FLASH_Message(binlen,p,flash_Isok);
					printf("update has get sucess \n");
				  printf("binlen:%x \n",binlen);
					SoftReset();
			}
			break;
		}
	}
	return 0;
}

u8 MessageDeal(u8 *data,u16 MCU_CanRecLen)
{
	u8 ret=1;
	//源地址
	if(data[0] == MASTER_CPU)//来自主机与主机通信
	{   //data[1] 目的地址
		if(data[1] == m_slave.Slave_Addr || data[1] == LISTENING_ADDR) //从机ID号配对上 或者是监听地址
		{
			//data[2] cpu/rf
			if(data[2] == CPU_MODE)
			{
				//printf("get some message\n");
				RX485_ReadyForRecv = 0;          //通信链路接收帧 被 处理了 
				MCU_MessageDeal(data+3,MCU_CanRecLen-3);				
			}
			else if(data[2] == RF_MODE)
			{
				//SM安全模块 -> 射频 
				//ret=Sm_MessageDeal(data+2,MCU_CanRecLen-2);//去除头部的方向和
				stringlen=MCU_CanRecLen-3;
				memcpy(RxBuffer,data+3,stringlen);	
			}
		}				
	}
	return ret;		
}


