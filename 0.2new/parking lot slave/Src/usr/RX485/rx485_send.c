#include "rx485_send.h"
#include "RX485_uart.h"
#include <stdlib.h>
#include <string.h>
#include "communication.h"
#include "EPC.h"
#include "timer.h"
#include "utility.h"
#include <stdio.h>
#include "cancellation.h"
#include "flashmanage.h"
//消息缓冲区
u8 TxMessage[MAX_TX_LEN]={0}; 
u8 RxMessage[MAX_RX_LEN]={0};

//获取crc
unsigned short getCRC16(unsigned char *q, int len)
{
    unsigned short const ccittTable[256] = {
    0x0000, 0x1021, 0x2042, 0x3063, 0x4084, 0x50A5, 0x60C6, 0x70E7,
    0x8108, 0x9129, 0xA14A, 0xB16B, 0xC18C, 0xD1AD, 0xE1CE, 0xF1EF,
    0x1231, 0x0210, 0x3273, 0x2252, 0x52B5, 0x4294, 0x72F7, 0x62D6,
    0x9339, 0x8318, 0xB37B, 0xA35A, 0xD3BD, 0xC39C, 0xF3FF, 0xE3DE,
    0x2462, 0x3443, 0x0420, 0x1401, 0x64E6, 0x74C7, 0x44A4, 0x5485,
    0xA56A, 0xB54B, 0x8528, 0x9509, 0xE5EE, 0xF5CF, 0xC5AC, 0xD58D,
    0x3653, 0x2672, 0x1611, 0x0630, 0x76D7, 0x66F6, 0x5695, 0x46B4,
    0xB75B, 0xA77A, 0x9719, 0x8738, 0xF7DF, 0xE7FE, 0xD79D, 0xC7BC,
    0x48C4, 0x58E5, 0x6886, 0x78A7, 0x0840, 0x1861, 0x2802, 0x3823,
    0xC9CC, 0xD9ED, 0xE98E, 0xF9AF, 0x8948, 0x9969, 0xA90A, 0xB92B,
    0x5AF5, 0x4AD4, 0x7AB7, 0x6A96, 0x1A71, 0x0A50, 0x3A33, 0x2A12,
    0xDBFD, 0xCBDC, 0xFBBF, 0xEB9E, 0x9B79, 0x8B58, 0xBB3B, 0xAB1A,
    0x6CA6, 0x7C87, 0x4CE4, 0x5CC5, 0x2C22, 0x3C03, 0x0C60, 0x1C41,
    0xEDAE, 0xFD8F, 0xCDEC, 0xDDCD, 0xAD2A, 0xBD0B, 0x8D68, 0x9D49,
    0x7E97, 0x6EB6, 0x5ED5, 0x4EF4, 0x3E13, 0x2E32, 0x1E51, 0x0E70,
    0xFF9F, 0xEFBE, 0xDFDD, 0xCFFC, 0xBF1B, 0xAF3A, 0x9F59, 0x8F78,
    0x9188, 0x81A9, 0xB1CA, 0xA1EB, 0xD10C, 0xC12D, 0xF14E, 0xE16F,
    0x1080, 0x00A1, 0x30C2, 0x20E3, 0x5004, 0x4025, 0x7046, 0x6067,
    0x83B9, 0x9398, 0xA3FB, 0xB3DA, 0xC33D, 0xD31C, 0xE37F, 0xF35E,
    0x02B1, 0x1290, 0x22F3, 0x32D2, 0x4235, 0x5214, 0x6277, 0x7256,
    0xB5EA, 0xA5CB, 0x95A8, 0x8589, 0xF56E, 0xE54F, 0xD52C, 0xC50D,
    0x34E2, 0x24C3, 0x14A0, 0x0481, 0x7466, 0x6447, 0x5424, 0x4405,
    0xA7DB, 0xB7FA, 0x8799, 0x97B8, 0xE75F, 0xF77E, 0xC71D, 0xD73C,
    0x26D3, 0x36F2, 0x0691, 0x16B0, 0x6657, 0x7676, 0x4615, 0x5634,
    0xD94C, 0xC96D, 0xF90E, 0xE92F, 0x99C8, 0x89E9, 0xB98A, 0xA9AB,
    0x5844, 0x4865, 0x7806, 0x6827, 0x18C0, 0x08E1, 0x3882, 0x28A3,
    0xCB7D, 0xDB5C, 0xEB3F, 0xFB1E, 0x8BF9, 0x9BD8, 0xABBB, 0xBB9A,
    0x4A75, 0x5A54, 0x6A37, 0x7A16, 0x0AF1, 0x1AD0, 0x2AB3, 0x3A92,
    0xFD2E, 0xED0F, 0xDD6C, 0xCD4D, 0xBDAA, 0xAD8B, 0x9DE8, 0x8DC9,
    0x7C26, 0x6C07, 0x5C64, 0x4C45, 0x3CA2, 0x2C83, 0x1CE0, 0x0CC1,
    0xEF1F, 0xFF3E, 0xCF5D, 0xDF7C, 0xAF9B, 0xBFBA, 0x8FD9, 0x9FF8,
    0x6E17, 0x7E36, 0x4E55, 0x5E74, 0x2E93, 0x3EB2, 0x0ED1, 0x1EF0
    };
    unsigned short crc = 0;
    while (len-- > 0)
    crc = ccittTable[(crc >> 8 ^ *q++) & 0xff] ^ (crc << 8);
    return ~crc;
}

/**
 * @brief Serial_Comm::escapeMessage
 * @param buf
 * @param len
 * @return
 * 对要发送的数据中的特殊字符进行转义处理
 */
Message escapeMessage(unsigned char *buf,int len)
{
	Message res;
	int i;
	unsigned char escapebuf[2*(MAX_TX_LEN+4)];
    //unsigned char escapebuf[2*(MAX_TX_LEN+4)]; //转义后的字节流大小按每个字节都需转义的最大需求考虑
    int index = 0;
    for(i=0;i<len;i++)
    {
        if(buf[i] == 0x7E)
        {
            escapebuf[index++] = 0x7D;
            escapebuf[index++] = 0x5E;
        }
        else if(buf[i] == 0x7D)
        {
            escapebuf[index++] = 0x7D;
            escapebuf[index++] = 0x5D;
        }
        else
        {
            escapebuf[index++] = buf[i];
        }
    }
    res.num = index;//转义后最终的数据长度
    memcpy(res.Value,escapebuf,res.num);
	
	 
    return res;
}

unsigned char sendSerialData(unsigned char sour_addr,unsigned char des_addr ,unsigned char cpu_rf ,unsigned char *message,int len){
    //int messagelen = len;
		Message escapedata;
		unsigned short crc16 ;
		unsigned char serialmessage[MAX_TX_LEN+4];
		unsigned char senddata[MAX_TX_LEN+2];
    int posi = 0;
	  int res;
	
    serialmessage[posi++] = sour_addr; //源地址暂定为全0
    serialmessage[posi++] = des_addr; //目的地址暂定为全 1
	  serialmessage[posi++] = cpu_rf;    //方向判断
    memcpy(serialmessage+posi,message,len);
//    crc16 = getCRC16(serialmessage,len+posi);
    posi += len;
//    serialmessage[posi++] = crc16>>8;
//    serialmessage[posi++] = crc16;
    escapedata = escapeMessage(serialmessage,posi);
    //printf("escapedata.m_nValue=%d\n",escapedata.m_nValue);


    senddata[0] = 0x7E; //加上帧头
    memcpy(senddata+1,escapedata.Value,escapedata.num);
    senddata[escapedata.num+1] = 0x7E; //加上帧尾

    //串口为非阻塞式写，所以返回的字节数不一定等要发送的字节数
    //int res = write(m_SerialFd,senddata,sizeof(senddata));
	  //int buflen = sizeof(senddata)/sizeof(unsigned char);
//		for(int i=0;i<escapedata.num+2;i++)
//		{
//				printf("%02x",senddata[i]);
//		}
    res = RX485USARTx_SendData(senddata,escapedata.num+2);		
    //printf("sendlen= %d\n",sendlen,res,posi);
    if(res<0){
        return 0;
    }
    //printf("send serial data finish!\n");
    return 1;
}

u8 sendCommData(unsigned char sour_addr,unsigned char des_addr  ,unsigned char cpu_rf ,unsigned char *buf,int buflen){
    u8 res;
    if(RX485_USART_TX_IDLE==1){
       // printf("Serial comm is not ready!\n");
        return 0;
    }
       // printf("Serial comm is ready!\n");
  
    res = sendSerialData(sour_addr,des_addr,cpu_rf,buf,buflen);
	  //printf("sendSerialData(buf,buflen) is ready!\n");
    return res;
}

//从机CPU -> 主控CPU
void MCU_To_MCU(u8 slave_id,u8 cmd) 
{
	switch(cmd)
	{
		case ReadCardEnd://读卡结束 射频MCU -> 主控MCU
		{
			TxMessage[0]=ReadCardEnd;
			sendCommData(slave_id ,MASTER_CPU ,CPU_MODE,TxMessage,1);
			break;
		}
		case StartReadCardAck://开始读卡应答
		{
			TxMessage[0]=StartReadCardAck;
			sendCommData(slave_id ,MASTER_CPU ,CPU_MODE,TxMessage,1);
			break;
		}
		case StopReadCardAck://停止读卡应答
		{
			TxMessage[0]=StopReadCardAck;
			sendCommData(slave_id ,MASTER_CPU ,CPU_MODE,TxMessage,1);
			break;
		}
		case ConfigSlaveAddrAck://配置从机节点地址应答
		{
			TxMessage[0]=ConfigSlaveAddrAck;	
		  TxMessage[1]=flash_flag.Slave_Addr_flag;// 1成功  0失败				
			sendCommData(slave_id ,MASTER_CPU ,CPU_MODE,TxMessage,2);
			break;
		}
		case GetSlaveAddrAck://从节点在位检测应答返回地址
		{
			TxMessage[0]=GetSlaveAddrAck;
			sendCommData(slave_id ,MASTER_CPU ,CPU_MODE,TxMessage,1);
			break;
		}
		case SetSlaveMessageAck:
		{
			TxMessage[0]=SetSlaveMessageAck;
			sendCommData(slave_id ,MASTER_CPU ,CPU_MODE,TxMessage,1);				
			break;
		}
		case GetSlaveMessageAck:
		{		
			u8 datatemp[70] = {0};
			printf("Start GetDerviceVersion....: \r\n");
		  GetDerviceVersion(datatemp);				
			TxMessage[0]=GetSlaveMessageAck;
			memcpy(TxMessage+1,datatemp,56);
			sendCommData(slave_id ,MASTER_CPU ,CPU_MODE,TxMessage,57);						
			break;
		}		
		case ConfigRfPowerAck://配置射频功率应答
		{
			TxMessage[0]=ConfigRfPowerAck;
			sendCommData(slave_id ,MASTER_CPU ,CPU_MODE,TxMessage,60);
			break;
		}
		case GetSlaveRfPowerAck://查询从节点射频功率值应答
		{
			TxMessage[0]=GetSlaveRfPowerAck;
			TxMessage[1]= (m_slave.RF_Power>>8)&0xff;//取高位
			TxMessage[2]=  m_slave.RF_Power & 0xff;  //取低位
			sendCommData(slave_id ,MASTER_CPU ,CPU_MODE,TxMessage,3);
			break;
		}		
		case ConfigFrequencyAck://配置射频频点应答
		{
			TxMessage[0]=ConfigFrequencyAck;
			sendCommData(slave_id ,MASTER_CPU ,CPU_MODE,TxMessage,1);
			break;
		}		
		case GetSlaveFrequencyAck://查询从节点射频射频功率应答
		{
			printf("GetSlaveFrequencyAck: %d\n",m_slave.RF_Frequency);
			TxMessage[0]=GetSlaveFrequencyAck;
			TxMessage[1]= m_slave.RF_Frequency;
			sendCommData(slave_id ,MASTER_CPU ,CPU_MODE,TxMessage,2);
			break;
		}		
		case ConfigCarrierAck://开载波应答
		{
			TxMessage[0]=ConfigCarrierAck;
			sendCommData(slave_id ,MASTER_CPU ,CPU_MODE,TxMessage,1);
			break;
		}	
		case GetSlaveCarrierAck://查询从节点载波开关状态应答
		{
			TxMessage[0]=GetSlaveCarrierAck;//消息头
			TxMessage[1]=m_slave.Carrier_flg;//载波开启标志位;//载波开关状态
			sendCommData(slave_id ,MASTER_CPU ,CPU_MODE,TxMessage,1);			
			break;
		}
		
		case ConfigCancellationAck://对消结束应答
		{
			TxMessage[0]=ConfigCancellationAck;
			//组帧 还原64为对消值
			for(int i=0;i<9;i++)
			{
				TxMessage[i+1] =min_SquDAValue.Squ_Value  >>(8*(7-i))&0xff;
			}	
			sendCommData(slave_id ,MASTER_CPU ,CPU_MODE,TxMessage,9);
			break;
		}		
		case GetSlaveCancellationAck://对消值应答
		{
			printf("GetSlaveCancellationAck \n");
			TxMessage[0]=GetSlaveCancellationAck;
			
			//组帧 还原64为对消值
			for(int i=0;i<9;i++)
			{
				TxMessage[i+1] =min_SquDAValue.Squ_Value  >>(8*(7-i))&0xff;
			}	
			sendCommData(slave_id ,MASTER_CPU ,CPU_MODE,TxMessage,9);	
			break;
		}
		case ConfigLedModeAck://配置灯光模式应答
		{
			TxMessage[0]=ConfigLedModeAck;
			sendCommData(slave_id ,MASTER_CPU ,CPU_MODE,TxMessage,1);
			break;
		}
		case GetLedModeAck://查询灯光模式应答
		{
			TxMessage[0]=GetLedModeAck;
			TxMessage[1]=m_slave.Led_Mode;
			sendCommData(slave_id ,MASTER_CPU ,CPU_MODE,TxMessage,2);
			break;
		}	
		case ConfigLedThresholdAck://配置门槛数值应答
		{
			TxMessage[0]=ConfigLedThresholdAck;
			sendCommData(slave_id ,MASTER_CPU ,CPU_MODE,TxMessage,1);	
			break;
		}
		case GetSlaveLedThresholdAck://查询门槛数值应答
		{
			TxMessage[0]=GetSlaveLedThresholdAck;
			TxMessage[1]=m_slave.readcarthreshold;
			sendCommData(slave_id ,MASTER_CPU ,CPU_MODE,TxMessage,2);	
			break;
		}
		case GetRadarDistanceAck: //查询雷达测距数值cm应答
		{
			TxMessage[0]=GetRadarDistanceAck;
			TxMessage[1]=(m_slave.radar_distance>>8)&0xff;//高8位
			TxMessage[2]= m_slave.radar_distance&0xff;//低8位
			sendCommData(slave_id ,MASTER_CPU ,CPU_MODE,TxMessage,3);
			printf("GetRadarDistance：%d\n",m_slave.radar_distance);
			break;
		}	
		case UpdateslavehandleAck:
		{
			TxMessage[0]=UpdateslavehandleAck;
			sendCommData(slave_id ,MASTER_CPU ,CPU_MODE,TxMessage,1);	
		}
			
		default:break;
	}
}

//从机RF到安全模块



