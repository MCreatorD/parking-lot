#include <String.h>
#include <stdint.h>
#include <stdio.h>

#include "utility.h"
#include "air_interface.h"

#include "rf_oper.h"
#include "EPC.h"
#include "timer.h"
#include "stdbool.h"
#include "LMX2541.h"

//#include "board.h"

#include "rx485_send.h"
#include "rx485_rev.h"
#include "spi1.h"
#include "buzzer_led.h"
#include "testReadTag.h"

#define CAN_TRANSMIT   1
uint8_t  EPC_ResponseRecvComplete  = 0;
uint8_t  EPC_ID_data_Buf[30];
uint16_t Delay_Time;
uint8_t 	g_bFreqRound;
//extern  volatile uint8_t RxBuffer [];
extern volatile bool lo_control;
extern u8 ReadCard_Count;
const unsigned short DB[34]= {0,1,2,3,4,5,
                              6,7,8,9,0,0,
                              0,0,0,0,0,0,
                              0,0,0,0,120,130,
                              140,150,160,170,180,190,
                              200,210,220,230
                             };

void _6D_TOKEN1(uint8_t *data)
{
    uint16_t i = ((data[3]*256)+data[2]);
    uint8_t  j = 0;
    EPC_BitsToSend=(uint8_t)i;
    for(j=0; j<((i+7)/8); j++)
    {
        EPC_Send_Buf[j] = data[6+j];
    }
    EPC_SendCommand();
}
void _6D_TOKEN2(uint8_t *data)
{
    uint16_t i = ((data[3]*256)+data[2]);
    uint8_t  j = 0;
    EPC_BitsToSend=(uint8_t)i;
    for(j=0; j<((i+7)/8); j++)
    {
        EPC_Send_Buf[j] = data[6+j];
    }
    EPC_SendCommand();
}
void _6D_TOKEN3(uint8_t *data)
{
    uint16_t i = ((data[3]*256)+data[2]);
    uint8_t  j = 0;
    EPC_BitsToSend=(uint8_t)i;
    for(j=0; j<((i+7)/8); j++)
    {
        EPC_Send_Buf[j] = data[6+j];
    }
    EPC_SendCommand();
}
void _6D_Query(uint8_t Sel,uint8_t Session,uint8_t Target,uint8_t TRext,uint8_t DR,uint8_t M)
{
    uint16_t crc;
    EPC_BitsToSend=0;
    ClearSendBuf(EPC_Send_Buf,16);
    EPC_Send_Buf[0] |= (_6D_CMD_Query<<0); //8
    EPC_Send_Buf[1] |= (Sel<<6);       //2
    EPC_Send_Buf[1] |= (Session  <<4); //2
    EPC_Send_Buf[1] |= (Target   <<3); //1
    EPC_Send_Buf[1] |= (TRext    <<2); //1
    EPC_Send_Buf[1] |= (DR       >>2); //2
    EPC_Send_Buf[2] |= (DR       <<6); //2
    EPC_Send_Buf[2] |= (M       <<4); // 2
    EPC_BitsToSend =  20;
    crc = Calculate_CRC16_Bits(EPC_CRC,EPC_Send_Buf, EPC_BitsToSend);
    EPC_CRC[0] = (uint8_t)(crc >>8);
    EPC_CRC[1] = (uint8_t)(crc & 0x00FF);
    StuffSendBuf(EPC_CRC[0],8);
    StuffSendBuf(EPC_CRC[1],8);
    TRcal_timer=0;
    EPC_SendCommand();
}
//    8         6            4           2             16                8
void _6D_Sort(uint8_t MemBank,uint8_t Target,uint8_t Action,uint8_t *BitPointer,uint8_t BitLength,uint8_t* Mask)
{
    uint16_t  crc;
    uint32_t i;
    EPC_BitsToSend=0;
    ClearSendBuf(EPC_Send_Buf,16);
    EPC_Send_Buf[0] |= (_6D_CMD_Sort<<0); //8
    EPC_Send_Buf[1] |= (MemBank <<2); //6
    EPC_Send_Buf[1] |= (Target  >>2); //2
    EPC_Send_Buf[2] |= (Target  <<6); //2
    EPC_Send_Buf[2] |= (Action  <<4); //2
    EPC_BitsToSend= 20;
    StuffSendBuf(BitPointer[0], 8);
    StuffSendBuf(BitPointer[1], 8);
    StuffSendBuf(BitLength, 8);
    if(BitLength&0x1)
    {
        BitLength = BitLength+1;
    }
    for(i=0; i<BitLength/8; i++)
    {
        StuffSendBuf(Mask[i],8);
    }
    StuffSendBuf(Mask[i],BitLength%8);
    crc = Calculate_CRC16_Bits(EPC_CRC,EPC_Send_Buf, EPC_BitsToSend);
    EPC_CRC[0] = (uint8_t)(crc >>8);
    EPC_CRC[1] = (uint8_t)(crc & 0x00FF);
    StuffSendBuf(EPC_CRC[0],8);
    StuffSendBuf(EPC_CRC[1],8);
    TRcal_timer=0;
    EPC_SendCommand();
}
//      2           2
void _6D_QueryRep(uint8_t Session)
{
    ClearSendBuf(EPC_Send_Buf,16);
    EPC_Send_Buf[0] |= (_6D_CMD_QueryRep<<6);
    EPC_Send_Buf[0] |= (Session<<4);
    EPC_BitsToSend = 4;
    TRcal_timer=0;
    EPC_SendCommand();
}
// 2            2            2
void _6D_Divide(uint8_t Address,uint8_t Session)
{
    ClearSendBuf(EPC_Send_Buf,16);
    EPC_Send_Buf[0] |= (_6D_CMD_Divide<<6);
    EPC_Send_Buf[0] |= (Address<<4);
    EPC_Send_Buf[0] |= (Session<<2);
    EPC_BitsToSend = 6;
    TRcal_timer=0;
    EPC_SendCommand();
}
//4             2
void _6D_Disperse(uint8_t Session)
{
    ClearSendBuf(EPC_Send_Buf,16);
    EPC_Send_Buf[0] |= (_6D_CMD_QueryRep<<4);
    EPC_Send_Buf[0] |= (Session<<2);
    EPC_BitsToSend = 6;
    TRcal_timer=0;
    EPC_SendCommand();
}
//4            2
void _6D_Shrink(uint8_t Session)
{
    ClearSendBuf(EPC_Send_Buf,16);
    EPC_Send_Buf[0] |= (_6D_CMD_Shrink<<4);
    EPC_Send_Buf[0] |= (Session<<2);
    EPC_BitsToSend = 6;
    TRcal_timer=0;
    EPC_SendCommand();
}
//2         16
void _6D_ACK(uint8_t* Handle)
{
    if(NULL == Handle)
    {
        return ;
    }
    ClearSendBuf(EPC_Send_Buf,16);
    EPC_Send_Buf[0] |= (_6D_CMD_ACK<<6);
    EPC_Send_Buf[0] |= (Handle[0] >> 2);
    EPC_Send_Buf[1] |= (Handle[0] << 6);
    EPC_Send_Buf[1] |= (Handle[1] >> 2);
    EPC_Send_Buf[2] |= (Handle[1] << 6);
    EPC_BitsToSend = 18;
    TRcal_timer=0;
    EPC_SendCommand();
}
//  8
void _6D_NAK(void)
{
    ClearSendBuf(EPC_Send_Buf,16);
    EPC_Send_Buf[0] |= (_6D_CMD_NAK<<0);
    EPC_BitsToSend = 8;
    TRcal_timer=0;
    EPC_SendCommand();
}
//   8           16        16
void _6D_RefreshRN(uint8_t *Handle)
{
    uint16_t crc;
    if(NULL == Handle)
    {
        return ;
    }
    ClearSendBuf(EPC_Send_Buf,16);
    EPC_Send_Buf[0] |= (_6D_CMD_RefreshRN<<0);
    EPC_Send_Buf[1] |= (Handle[0] << 0);
    EPC_Send_Buf[2] |= (Handle[1] << 0);
    EPC_BitsToSend = 24;
    crc = Calculate_CRC16_Bits(EPC_CRC,EPC_Send_Buf, EPC_BitsToSend);
    EPC_CRC[0] = (uint8_t)(crc >>8);
    EPC_CRC[1] = (uint8_t)(crc & 0x00FF);
    StuffSendBuf(EPC_CRC[0],8);
    StuffSendBuf(EPC_CRC[1],8);
    TRcal_timer=0;
    EPC_SendCommand();
}
//8             16        16
void _6D_Get_RN(uint8_t *handle)
{
    uint16_t crc;
    if(NULL == handle)
    {
        return;
    }
    ClearSendBuf(EPC_Send_Buf,16);
    EPC_Send_Buf[0] |= (_6D_CMD_Get_RN<<0);
    EPC_Send_Buf[1] |= (handle[0] << 0);
    EPC_Send_Buf[2] |= (handle[1] << 0);
    EPC_BitsToSend = 24;
    crc = Calculate_CRC16_Bits(EPC_CRC,EPC_Send_Buf, EPC_BitsToSend);
    EPC_CRC[0] = (uint8_t)(crc >>8);
    EPC_CRC[1] = (uint8_t)(crc & 0x00FF);
    StuffSendBuf(EPC_CRC[0],8);
    StuffSendBuf(EPC_CRC[1],8);
    TRcal_timer=0;
    EPC_SendCommand();
}
//8           6               4                 16 (password XOR RN)     16           16         16
void _6D_Access(uint8_t MemBank,uint8_t PassType, const uint8_t *Password,const uint8_t *RN, uint8_t *Handle)
{
    uint16_t crc;
    uint8_t temp;
    if((NULL == Password)||(NULL == RN)||(NULL == Handle))
    {
        return;
    }
    ClearSendBuf(EPC_Send_Buf,16);
    EPC_Send_Buf[0] |= (_6D_CMD_Access<<0); //8
    EPC_Send_Buf[1] |= (MemBank <<2);   //6
    EPC_Send_Buf[1] |= (PassType>>2);   //2
    EPC_Send_Buf[2] |= (PassType<<6);   //2
    EPC_BitsToSend = 18;
    temp = Password[0]^Handle[0];
    StuffSendBuf(temp,8);
    temp = Password[1]^Handle[1];
    StuffSendBuf(temp,8);
    StuffSendBuf(Handle[0],8);
    StuffSendBuf(Handle[1],8);
    crc = Calculate_CRC16_Bits(EPC_CRC,EPC_Send_Buf, EPC_BitsToSend);
    EPC_CRC[0] = (uint8_t)(crc >>8);
    EPC_CRC[1] = (uint8_t)(crc & 0x00FF);
    StuffSendBuf(EPC_CRC[0],8);
    StuffSendBuf(EPC_CRC[1],8);
    TRcal_timer=0;
    EPC_SendCommand();
}
//    8        6               16               16            16            16
void _6D_Read(uint8_t MemBank,uint8_t *WordPointer,uint8_t* Count,uint8_t *Handle)
{
    uint16_t crc;
    if((NULL == WordPointer)||(NULL == Count)||(NULL == Handle))
    {
        return;
    }
    ClearSendBuf(EPC_Send_Buf,16);
    EPC_Send_Buf[0] |=(_6D_CMD_Read<<0);
    EPC_Send_Buf[1] |=(MemBank<<2);
    EPC_BitsToSend =14;
    StuffSendBuf(WordPointer[0],8);
    StuffSendBuf(WordPointer[1],8);
    StuffSendBuf(Count[0],8);
    StuffSendBuf(Count[1],8);
    StuffSendBuf(Handle[0],8);
    StuffSendBuf(Handle[1],8);
    crc = Calculate_CRC16_Bits(EPC_CRC,EPC_Send_Buf, EPC_BitsToSend);
    EPC_CRC[0] = (uint8_t)(crc >>8);
    EPC_CRC[1] = (uint8_t)(crc & 0x00FF);
    StuffSendBuf(EPC_CRC[0],8);
    StuffSendBuf(EPC_CRC[1],8);
    TRcal_timer=0;
    EPC_SendCommand();
}
//8           6               16                16          16*Count    16
void _6D_Write(uint8_t MemBank,uint8_t *WordPointer,uint8_t* Count,uint8_t *Data,uint8_t *Handle)
{
    uint16_t crc;
    uint16_t temp=0,i=0;
    if((NULL == WordPointer)||(NULL == Count)||(NULL == Handle)||NULL==Data)
    {
        return;
    }
    temp = (temp|Count[0]);
    temp = (((temp<<8)|Count[1])<<1); //总字节数
    ClearSendBuf(EPC_Send_Buf,16);
    EPC_Send_Buf[0] |=(_6D_CMD_Write<<0);
    EPC_Send_Buf[1] |=(MemBank<<2);
    EPC_BitsToSend =14;
    StuffSendBuf(WordPointer[0],8);
    StuffSendBuf(WordPointer[1],8);
    StuffSendBuf(Count[0],8);
    StuffSendBuf(Count[1],8);
    for(i=0; i<temp; i++)
    {
        StuffSendBuf(Data[i],8);
    }
    StuffSendBuf(Handle[0],8);
    StuffSendBuf(Handle[1],8);
    crc = Calculate_CRC16_Bits(EPC_CRC,EPC_Send_Buf, EPC_BitsToSend);
    EPC_CRC[0] = (uint8_t)(crc >>8);
    EPC_CRC[1] = (uint8_t)(crc & 0x00FF);
    StuffSendBuf(EPC_CRC[0],8);
    StuffSendBuf(EPC_CRC[1],8);
    TRcal_timer=0;
    EPC_SendCommand();
}
//    8        6               16               16            16            16
void _6D_Erase(uint8_t MemBank,uint8_t *WordPointer,uint8_t* Count,uint8_t *Handle)
{
    uint16_t crc;
    if((NULL == WordPointer)||(NULL == Count)||(NULL == Handle))
    {
        return;
    }
    ClearSendBuf(EPC_Send_Buf,16);
    EPC_Send_Buf[0] |=(_6D_CMD_Erase<<0);
    EPC_Send_Buf[1] |=(MemBank<<2);
    EPC_BitsToSend =14;
    StuffSendBuf(WordPointer[0],8);
    StuffSendBuf(WordPointer[1],8);
    StuffSendBuf(Count[0],8);
    StuffSendBuf(Count[1],8);
    StuffSendBuf(Handle[0],8);
    StuffSendBuf(Handle[1],8);
    crc = Calculate_CRC16_Bits(EPC_CRC,EPC_Send_Buf, EPC_BitsToSend);
    EPC_CRC[0] = (uint8_t)(crc >>8);
    EPC_CRC[1] = (uint8_t)(crc & 0x00FF);
    StuffSendBuf(EPC_CRC[0],8);
    StuffSendBuf(EPC_CRC[1],8);
    TRcal_timer=0;
    EPC_SendCommand();
}
//  8          6             2           2           16
void _6D_Lock(uint8_t MemBank,uint8_t Config,uint8_t Action,uint8_t *Handle)
{
    uint16_t crc ;
    if(NULL == Handle)
    {
        return;
    }
    ClearSendBuf(EPC_Send_Buf,16);
    EPC_Send_Buf[0] |=(_6D_CMD_Lock<<0);
    EPC_Send_Buf[1] |=(MemBank<<2);
    EPC_Send_Buf[1] |=(Config<<0);
    EPC_Send_Buf[2] |=(Action<<6);
    EPC_Send_Buf[2] |=(Handle[0]>>2);
    EPC_Send_Buf[3] |=(Handle[0]<<6);
    EPC_Send_Buf[3] |=(Handle[1]>>2);
    EPC_Send_Buf[4] |=(Handle[1]<<6);
    EPC_BitsToSend =14;
    crc = Calculate_CRC16_Bits(EPC_CRC,EPC_Send_Buf, EPC_BitsToSend);
    EPC_CRC[0] = (uint8_t)(crc >>8);
    EPC_CRC[1] = (uint8_t)(crc & 0x00FF);
    StuffSendBuf(EPC_CRC[0],8);
    StuffSendBuf(EPC_CRC[1],8);
    TRcal_timer=0;
    EPC_SendCommand();
}
// 8         16             16
void _6D_Kill(uint8_t *Handle)
{
    uint16_t crc;
    if(NULL == Handle)
    {
        return;
    }
    ClearSendBuf(EPC_Send_Buf,16);
    EPC_Send_Buf[0] |=(_6D_CMD_Kill<<0);
    EPC_Send_Buf[1] |=(Handle[0]<<0);
    EPC_Send_Buf[2] |=(Handle[1]<<0);
    EPC_BitsToSend = 24;
    crc = Calculate_CRC16_Bits(EPC_CRC,EPC_Send_Buf, EPC_BitsToSend);
    EPC_CRC[0] = (uint8_t)(crc >>8);
    EPC_CRC[1] = (uint8_t)(crc & 0x00FF);
    StuffSendBuf(EPC_CRC[0],8);
    StuffSendBuf(EPC_CRC[1],8);
    TRcal_timer=0;
    EPC_SendCommand();
}
//可选命令
//    8               16         16
void _6D_Get_SecPara(uint8_t *Handle)
{
    uint16_t crc;
    if(NULL == Handle)
    {
        return;
    }
    ClearSendBuf(EPC_Send_Buf,16);
    EPC_Send_Buf[0] |= (_6D_CMD_Get_SecPara<<0);
    EPC_Send_Buf[1] |= (Handle[0] << 0);
    EPC_Send_Buf[2] |= (Handle[1] << 0);
    EPC_BitsToSend = 24;
    crc = Calculate_CRC16_Bits(EPC_CRC,EPC_Send_Buf, EPC_BitsToSend);
    EPC_CRC[0] = (uint8_t)(crc >>8);
    EPC_CRC[1] = (uint8_t)(crc & 0x00FF);
    StuffSendBuf(EPC_CRC[0],8);
    StuffSendBuf(EPC_CRC[1],8);
    TRcal_timer=0;
    EPC_SendCommand();
}
//        8        16          16
void _6D_Req_XAuth(uint8_t *Handle)
{
    uint16_t crc;
    if(NULL == Handle)
    {
        return;
    }
    ClearSendBuf(EPC_Send_Buf,16);
    EPC_Send_Buf[0] |= (_6D_CMD_Req_XAuth<<0);
    EPC_Send_Buf[1] |= (Handle[0] << 0);
    EPC_Send_Buf[2] |= (Handle[1] << 0);
    EPC_BitsToSend = 24;
    crc = Calculate_CRC16_Bits(EPC_CRC,EPC_Send_Buf, EPC_BitsToSend);
    EPC_CRC[0] = (uint8_t)(crc >>8);
    EPC_CRC[1] = (uint8_t)(crc & 0x00FF);
    StuffSendBuf(EPC_CRC[0],8);
    StuffSendBuf(EPC_CRC[1],8);
    TRcal_timer=0;
    EPC_SendCommand();
}
void _6D_XAuth(void)
{
}
void _6D_Get_XAuth(void)
{
}
void _6D_Req_XAuth_Ex(void)
{
}
void _6D_Req_SAuth(void)
{
}
void _6D_SAuth(void)
{
}
void _6D_Get_SAuth(void)
{
}
void _6D_Mul_SAuth(void)
{
}
void _6D_Sec_Com(void)
{
}
uint8_t gbtest  = 0;
uint8_t gbtest1  = 0;
//static u8 buffer1[20]={0};
uint8_t _6D_T1(void)
{
    uint8_t status = GL_ERROR;
    uint8_t temp = 0;
  SPI_I2S_DeInit(SPIx);
  SPI_Cmd(SPIx, ENABLE);
	if(SPI_Send(0x01,EPC_Response_Recv_Buf,2))//将标签数据发往安全模块
	{
	   	  temp=(SPI_Read(19,2));//对串口收取值判断类型，赋值给RxBuffer
        if(0x02==temp)
        {
            _6D_TOKEN1(RxBuffer);
            switch(RxBuffer[7])
            {
            case 0x02:
								Delay_us1(1800);
                Delay_Time = 4260+2200*15; //原始的
                //Delay_Time = 4260+4040*15; //
                break;
            case 0x09:
                Delay_us(180);
                Delay_Time = 4260+15*300; //
                break;
            case 0xC4:
                Delay_ms(6);
                Delay_ms(1);
                Delay_us(780);
                Delay_us(10);
                Delay_us(100);
                Delay_Time = 4260+2740*15; //
                break;
            default:
                Delay_us(180);
                Delay_Time = 4260+15*300; //
                break;
            }
            EPC_Return_Link_Bits = RxBuffer[4]+RxBuffer[5]*256;   //
		      	//GPIO_ResetBits(GPIOA,GPIO_Pin_12);
            GPIO_ResetBits(IFSW_CTR_PORT,IFSW_CTR_PIN);
            status=_6D_TOKEN1Decode();
			      GPIO_SetBits(IFSW_CTR_PORT,IFSW_CTR_PIN);
			
            if(status!=GL_OK)
            {
                SPI_I2S_DeInit(SPIx);
                SPI_Cmd(SPIx, ENABLE);
                if(SPI_Send(0x03,EPC_Response_Recv_Buf,2))
                {
											SPI_Read(19,2);
                }
                SPI_Cmd(SPIx, DISABLE);						
            }
        }
        else if(0x04==temp)//正确
        {
            status = GL_OVER;
        }
        else
        {
            status = GL_ERROR;
            if(temp>=5)
            {
                //sendchar(temp);
            }
        }
    }
    else
    {
        status = GL_ERROR;
    }
    gbtest ++;
    return status;
}
uint8_t _6D_T2(void)
{
    uint8_t status = GL_ERROR;
    uint8_t temp = 0;
	
	SPI_I2S_DeInit(SPIx);
  SPI_Cmd(SPIx, ENABLE);
	if(SPI_Send(0x02,EPC_Response_Recv_Buf,2))
	{
		    temp=(SPI_Read(19,2));	
        if(temp==0x02)
        {
            _6D_TOKEN2(RxBuffer);
            switch(RxBuffer[7])
            {
            case 0x02:              
                Delay_ms(2);
                Delay_ms(1);
                Delay_us(780);
                Delay_us(10);
                Delay_us(100);
                Delay_Time = 4260+2200*15; //
                break;
            case 0x09://指令转发
                Delay_us1(50);
                Delay_Time =60*100;//4260+15*200; //
                break;
            case 0xC4:
                Delay_us1(6758);
                Delay_Time =60*100; //4260+3520*15; //
                break;
            default:
                Delay_us1(100);
                Delay_Time =60*100; //4260+15*200; //
                break;
            }
            EPC_Return_Link_Bits = RxBuffer[4]+RxBuffer[5]*256;   //
            GPIO_ResetBits(IFSW_CTR_PORT,IFSW_CTR_PIN);
            status = _6D_TOKEN1Decode();
		      	GPIO_SetBits(IFSW_CTR_PORT,IFSW_CTR_PIN);
			
            if(status!=GL_OK)//结束盘点
            {
								SPI_Send(0x03,EPC_Response_Recv_Buf,2);
								printf("a");
						  	//				if(SPI_Send(0x03,EPC_Response_Recv_Buf,2))
								//				{
								//					RF_CAN_Receive_SM(19,2);
								//				}
				
            }
            else
            {
							//得到需要转发的数据
            }
        }
        else if(temp ==0x04)
        {
					  status = GL_OVER;
        }
        else
        {
            if(temp>=5)
            {
                //sendchar(temp);
            }
            status = GL_ERROR;
        }
    }
    else
    {
			  status = GL_ERROR;
    }
    gbtest1 ++;
    return status;
}
unsigned char _6D_EPC_ReadOnlyOne_Protcol(unsigned char RFSwitchoffFlag)
{
    unsigned char status;
    unsigned char i,a=0;
    unsigned char RepFlag;
    unsigned char bitaddress[2] = {0x00,0x00};
    unsigned char state = 0;
    gbtest = 0;
    gbtest1 = 0;
    RFPowerON(150);
    Delay_ms(16);
    RepFlag = 1;
    while (RepFlag)
    {
        _6D_Sort(0x10,0x04,0x03,bitaddress,0x0,NULL);
        Delay_us(400);//
        _6D_Query(0x00,0x00,0x00,0x01,0x02,0x01);
        Delay_us(180);//
        IRQDisable();
        EPC_Return_Link_Bits = 16;
        status = _6D_RN16_FM0Decode();
        IRQEnable();
        if (status == GL_RN16_OK)
        {
            status = GL_OK;
            state = 1;
            for (i=0; i<(EPC_Return_Link_Bits/8); i++)
            {
                EPC_RN[i] = EPC_Response_Recv_Buf[i];
            }
            Delay_us(8);
            _6D_ACK(EPC_RN);
            Delay_ms(2);
            Delay_ms(1);
            Delay_us(780);
            Delay_us(10);
            IRQDisable();//
            EPC_Return_Link_Bits = 128;   //16*8
            status = _6D_FM0Decode();
            IRQEnable();
            if (status == GL_OK)
            {
                status = _6D_T1();
                if(status==GL_OK)
                {
                    for(;;)
                    {
                        status = _6D_T2();
                        if(status==GL_OK)
                        {
                        }
                        else if(status ==GL_OVER)
                        {
                            status = GL_OK;
                            //sendchar(0x55);
                            //sendchar(gbtest1);
                            //sendchar(gbtest);  
                            break;
                        }
                        else
                        {
                            //sendchar(0x56);
                            //sendchar(gbtest1);
                            //sendchar(gbtest);
                            break;
                        }
                    }
                }
                else if(status==GL_OVER)
                {
                    status = GL_OK;
                }
            }
        }
        if(status == GL_OK)
        {
            memset(EPC_ID_data_Buf,0,30);
            for(i=0; ((i<((EPC_Response_Recv_Buf[0]<<2)|(EPC_Response_Recv_Buf[1]>>6))*2)&&(i<12)); i++)
            {
                EPC_ID_data_Buf[i] = ((EPC_Response_Recv_Buf[2+i]<<2)|(EPC_Response_Recv_Buf[3+i]>>6));
            }
            //AddMyTagData(EPC_ID_data_Buf);
            RepFlag = 0;
        }
        if(RepFlag == 1)
        {
            if (a<3)
            {
                g_bFreqRound = (g_bFreqRound+1)%5;
							  //g_bFreqRound = (g_bFreqRound+1)%2;
                FreqHopping(0);
                a++;
                if(state==1)
                {
                    RepFlag = 0;
                }
            }
            else
            {
                RepFlag = 0;
            }
            Delay_100us(20);// 1ms
        }
    }  //while
    if (RFSwitchoffFlag)
    {
        RFPowerOFF();
    }
    return(status);
}
extern unsigned char RFAntenna[5];
extern const unsigned short DB[];
//extern Struct_IRP_Parameters irp;
#define     CIN     4
#define     CCN     3
uint16_t count1,count2,delaycount;
//uint16_t count3;
//uint8_t date1[1024],forhead,crcok;
uint8_t forhead,crcok;
unsigned char _6D_EPC_ReadMulti_Protcol2(unsigned char RFSwitchoffFlag)
{
    uint8_t status,status_r=0;
    uint8_t i;
    RFPowerON(DB[15]);/*RF-POWER开*/
	//RFPowerON(DB[irp.power_Set.Channel0_DB]);
    Delay_ms(5);
    _6D_Query(0x00,0x00,0x00,0x01,0x03,0x01);
    Delay_us1(80);
    EPC_Return_Link_Bits = 16;
	Delay_Time =15*75*4-40;// good2
    status = _6D_RN16_FM0Decode();
    switch(status)
    {
    case GL_NO_TAG://空闲
			status_r=0;
          break;
    case GL_TRANSFER_ERROR://发生碰撞
    case GL_CRC_ERROR:
//		UartSendbuf(USART1,date1,count1 );
//		UartSendbuf(USART1,EPC_Response_Recv_Buf,2 );
		status_r=0;
		break;
    case GL_RN16_OK://正确接收
//		UartSendbuf(USART1,date1,count1 );
//		UartSendbuf(USART1,EPC_Response_Recv_Buf,2 );
        for (i=0; i<(EPC_Return_Link_Bits/8); i++)
        {
            EPC_RN[i] = EPC_Response_Recv_Buf[i];
        }
        Delay_us(120);
        _6D_ACK(EPC_RN);
        Delay_Time = (2208-1967)*15*4;//4260+15*600; //
		Delay_us1(1800);
        EPC_Return_Link_Bits = 128;   //16*8
        status = _6D_FM0Decode();
        IRQEnable();
        if (status == GL_OK)
        {
			//UartSendbuf(USART1,EPC_Response_Recv_Buf,16 );
            status = _6D_T1();
            if(status==GL_OK)
            {
                while(1)
                {
                    status = _6D_T2();//???????
                    if(status!=GL_OK)
					{
						status_r=GL_OK;
						break;
					}
					Delay_us1(10);
                }
            }
            else if(status==GL_OVER)
            {
                status_r = GL_OK;
            }
        }
		else
		{
			//UartSendbuf(USART1,EPC_Response_Recv_Buf,16 );
			//UartSendbuf(USART1,date1,count1 );
			status_r=0;
		}
//        Delay_us(8);// 110
//        _6D_QueryRep(0x00);
		break;
    default:
		status_r=0;
        break;
    }
    return(status_r);
}



unsigned char _6D_TOKEN1Decode(void)//_6D_MyFM0Decode1  _6D_MyFM0Decode
{
    return _6D_MyFM0Decode( 180*EPC_Return_Link_Bits+Delay_Time, 2);
}
unsigned char _6D_TOKEN2Decode(void)
{
    return _6D_MyFM0Decode( 180*EPC_Return_Link_Bits+Delay_Time, 3);
}
unsigned char _6D_TOKEN3Decode(void)
{
    return _6D_MyFM0Decode( 180*EPC_Return_Link_Bits+Delay_Time, 4);
}
unsigned char _6D_RN16_FM0Decode(void)
{
    return _6D_MyFM0Decode( (180*EPC_Return_Link_Bits)+Delay_Time, 0);  //12us +236us+14us
}
unsigned char _6D_FM0Decode(void)
{
    return _6D_MyFM0Decode( (180*EPC_Return_Link_Bits)+Delay_Time, 1);
}
//#define BIG_P    65//110 //7.3
//#define SMALL_P  35//60   //4.
#define BIG_P    119
#define SMALL_P  64
uint8_t gtest[8];

//判断是否有前导码
u8 ishasHead(u32 elect_time,unsigned int *T_Numx)//高低的电平时间
{
	u8 hashead = 0;
	if ((elect_time >= SMALL_P)&&(elect_time < BIG_P))//连续两个
	{
			//左移低位补1
			*T_Numx <<=0x01;
			*T_Numx |= 0x01;
			if(*T_Numx==0x00424902)
			{
					hashead=1;
			}
	}
	else if((elect_time<SMALL_P))
	{
		  //左移低位补0
			*T_Numx<<=0x01;
			if(*T_Numx==0x00424902)
			{
					EPC_Recv_Stagex = 0x02;
					hashead=1;
			}
	}
	else
	{
			*T_Numx = 0;
	}
	return hashead;
}

//读取数据段内容
/*
* M2 TRext = 1
* 一个电平宽度 0 两个电平宽度是1
* 四个电平一个数据编码
* 0:0000    1:010
*/
u8 readAirData(     u32 elect_time, unsigned char *el_data_bit ,
                    unsigned char *M2_data,unsigned char *M2_data_bit,unsigned char *M2_data_byte,
                    uint16_t *ALL_num,
                    uint8_t *EPC_data,uint16_t *EPC_num)
{
    u8 err = 0;
//  static unsigned char *el_data_bit=0;//电平数据位
 // unsigned char *M2_data = 0;//米勒2编码数据

//  static unsigned char **M2_data_bit=0;//编码数据位    
//  static unsigned char **M2_data_byte = 0;//编码数据
    
   if ((elect_time >= SMALL_P)&&(elect_time < BIG_P))
    {
        if(*el_data_bit==1)
        {
            *M2_data=1;
        }
        *el_data_bit=(*el_data_bit)+2;//1 3 5 两个数据计算 高低
        if(*el_data_bit==5)
        {
            *el_data_bit = 1;
            (*M2_data_byte) <<= 1;
            (*M2_data_byte) |= *M2_data;
            (*M2_data_bit)++;
            (*ALL_num)++;
            if ((*M2_data_bit) == 8u)
            {
                EPC_data[(*EPC_num)] = (*M2_data_byte);
                *M2_data_byte = 0x00;
                *M2_data_bit = 0;
                (*EPC_num) ++;
            }
        }
        else if(*el_data_bit>=6)
        {
            err = 2;
        }
              //  count3++;
    }
    else if(elect_time<SMALL_P)
    {
        if(*el_data_bit==1)
        {
            *M2_data=0;
        }
        *el_data_bit=*el_data_bit+1;
        if(*el_data_bit==4)
        {
            *el_data_bit = 0;
            (*M2_data_byte) <<= 1;
            (*M2_data_byte) |= *M2_data;
            (*M2_data_bit)++;
            (*ALL_num)++;
            if (*M2_data_bit == 8u)
            {
                EPC_data[*EPC_num] = *M2_data_byte;
                *M2_data_byte = 0x00;
                *M2_data_bit = 0;
                (*EPC_num)++;
            }
        }
        else if(*el_data_bit>=5)
        {
            err = 2;
        }
    }
    else
    {
        err = 2;
    }

    return err;
}

uint8_t channelSwitchCount = 0;
uint8_t _6D_MyFM0Decode(uint32_t iTimeOut,uint8_t bType)
{
    volatile unsigned char Rep_Flag;
    unsigned int TestNumx= 0;
    unsigned int last_timex;
    unsigned char Rep_Flagx;
    unsigned int cTempx;
    unsigned char testx=0;
    unsigned char test1x = 0;
    unsigned char g_mu=0;
    g_mu=0;
    EPC_ResponseRecvBits = 0;
//	EPC_ResponseRecvBits_Q = 0;
    EPC_Recv_Byte_Index = 0;
    EPC_Recv_Bit_Index = 0;
    EPC_Temp_Recv_Byte = 0x00;
    EPC_Recv_Stage = 0x00;
    EPC_Premable = 0;
    EPC_ResponseRecvBitsx = 0;
//	EPC_ResponseRecvBitsx_Q = 0;
    EPC_Recv_Byte_Indexx = 0;
//    EPC_Recv_Byte_Indexx_Q = 0;	
    EPC_Recv_Bit_Indexx = 0;
//	EPC_Recv_Bit_Indexx_Q = 0;
    EPC_Temp_Recv_Bytex = 0x00;
    EPC_Recv_Stagex = 0x00;
//	EPC_Recv_Stagex_Q = 0x00;
    Rep_Flagx = 8;
    EPC_Premablex = 0;
    last_timex = 0;
		
    TIM_PrescalerConfig(TIM3,3,TIM_PSCReloadMode_Immediate);
    /* Enable the CC1 Interrupt Request */
    TIM_SetCounter(TIM3,0);
    TIM_SetAutoreload(TIM3,iTimeOut);
    TIM_ClearFlag(TIM3,TIM_FLAG_Update);
    TIM_ClearFlag(TIM3,TIM_FLAG_CC2);
    TIM_ClearFlag(TIM3,TIM_FLAG_CC1);
    TIM_Cmd(TIM3, ENABLE);
	  //count1=0;
	  count2=0;
	  //count3=0;
	  forhead=0;
	  crcok=0;
		
		
    while (Rep_Flag)
    {
        if(Rep_Flagx!=2)
        {
					if(channelSwitchCount)
					{
							if (TIM_GetFlagStatus(TIM3, TIM_FLAG_CC1) == SET)
							{
									TIM_ClearFlag(TIM3,TIM_FLAG_CC1);
									cTempx = TIM_GetCapture1(TIM3);
									EPC_periodx = cTempx -last_timex;
									last_timex = cTempx;
									switch (EPC_Recv_Stagex)
									{
									case 0x00:
										EPC_Recv_Stagex = 0x01;
										break;
									case 0x01://判断是否有前导码
										if(ishasHead(EPC_periodx,&TestNumx) == 1)
										{
											EPC_Recv_Stagex = 0x02;
										} 	
										break;			
									case 0x02://读取数据段内容
										if(readAirData(EPC_periodx,&testx,&test1x,
													&EPC_Recv_Bit_Indexx,&EPC_Temp_Recv_Bytex,
													&EPC_ResponseRecvBitsx,
													EPC_Response_Recv_Bufx,&EPC_Recv_Byte_Indexx) == 2)
										{
													Rep_Flagx = 2;
													//goto Exit1;
										}
										if (EPC_ResponseRecvBitsx >= EPC_Return_Link_Bits)
										{
													Rep_Flagx = 4;
													//goto Exit1;
										}
										
										break;
									}//end of switch								
							}
					}
					else
					{
							if (TIM_GetFlagStatus(TIM3, TIM_FLAG_CC2) == SET)
							{

									TIM_ClearFlag(TIM3,TIM_FLAG_CC2);
									cTempx = TIM_GetCapture2(TIM3);
									EPC_periodx = cTempx -last_timex;
									last_timex = cTempx;
									switch (EPC_Recv_Stagex)
									{
									case 0x00:
										EPC_Recv_Stagex = 0x01;
										break;
									case 0x01://判断是否有前导码
										if(ishasHead(EPC_periodx,&TestNumx) == 1)
										{
											EPC_Recv_Stagex = 0x02;
										} 	
										break;			
									case 0x02://读取数据段内容
										if(readAirData(EPC_periodx,&testx,&test1x,
													&EPC_Recv_Bit_Indexx,&EPC_Temp_Recv_Bytex,
													&EPC_ResponseRecvBitsx,
													EPC_Response_Recv_Bufx,&EPC_Recv_Byte_Indexx) == 2)
										{
													Rep_Flagx = 2;
													//goto Exit1;
										}
										if (EPC_ResponseRecvBitsx >= EPC_Return_Link_Bits)
										{
													Rep_Flagx = 4;
													//goto Exit1;
										}
										
										break;
									}//end of switch								
							}			
					}
        }
		
Exit1:
        if(Rep_Flagx==4)
        {
            EPC_ResponseRecvBits =EPC_ResponseRecvBitsx;
            memcpy(EPC_Response_Recv_Buf,EPC_Response_Recv_Bufx,(EPC_Return_Link_Bits+7)/8);
            Rep_Flag=0;
        }
				
				delaycount=TIM_GetCounter(TIM3);
        if(delaycount>Delay_Time)//不同解码函数不同时间限制 超时
        {
            if(EPC_Recv_Stagex<2)
            {
                Rep_Flagx= 2;	
            }
        }
        if(TIM_GetFlagStatus(TIM3,TIM_FLAG_Update)==SET)//定时器到时间了
        {
            Rep_Flag = 0;
        }		
		
    }	
    TIM_PrescalerConfig(TIM3,0,TIM_PSCReloadMode_Immediate);
    TIM_ClearFlag(TIM3,TIM_FLAG_Update);
    TIM_Cmd(TIM3, DISABLE);
			
		
    if(bType == 0)
    {	
        if ((EPC_ResponseRecvBits == 0)&&(g_mu==0))
        {
            return GL_NO_TAG;
        }
        if (EPC_ResponseRecvBits < EPC_Return_Link_Bits)
        {
						crcok=2;
						//UartSendbuf(USART1,date1,count1 );
            return GL_TRANSFER_ERROR;
        }
        if ((EPC_ResponseRecvBits == EPC_Return_Link_Bits)&&(Crc5Bit(EPC_Response_Recv_Buf,EPC_Return_Link_Bits)==0))
        {
		
						crcok=0;
						//UartSendbuf(USART1,date1,count1 );
            return GL_RN16_OK;
        }
        else
        {
						crcok=1;
						//UartSendbuf(USART1,date1,count1 );
            return GL_CRC_ERROR;
        }
    }
    else
    {
        if ((EPC_ResponseRecvBits == 0)&&(g_mu==0))
        {
			crcok=1;
            return GL_NO_TAG;
        }
        if (EPC_ResponseRecvBits < EPC_Return_Link_Bits)
        {
			crcok=0;
            return GL_TRANSFER_ERROR;
        }
        else
        {
			crcok=2;
            return GL_OK;
        }
    }
}

uint8_t _6D_MyFM0Decode1(uint32_t iTimeOut,uint8_t bType)
{
    unsigned int last_time;
    unsigned char Rep_Flag;
    unsigned int cTemp;
    unsigned char test=0;
    unsigned char test1 = 0;
    unsigned char co=0;
    unsigned char co1=0;
    unsigned int last_timex;
    unsigned char Rep_Flagx;
    unsigned int cTempx;
    unsigned char testx=0;
    unsigned char test1x = 0;
    unsigned char g_mu=0;
    g_mu=0;
    EPC_ResponseRecvBits = 0;
    EPC_Recv_Byte_Index = 0;
    EPC_Recv_Bit_Index = 0;
    EPC_Temp_Recv_Byte = 0x00;
    Rep_Flag = 8;
    EPC_Recv_Stage = 0x00;
    EPC_Premable = 0;
    last_time = 0;
    EPC_ResponseRecvBitsx = 0;
    EPC_Recv_Byte_Indexx = 0;
    EPC_Recv_Bit_Indexx = 0;
    EPC_Temp_Recv_Bytex = 0x00;
    EPC_Recv_Stagex = 0x00;
    Rep_Flagx = 8;
    EPC_Premablex = 0;
    last_timex = 0;
    TIM_PrescalerConfig(TIM3,3,TIM_PSCReloadMode_Immediate);
    /* Enable the CC2 Interrupt Request */
    TIM_SetCounter(TIM3,0);
    TIM_SetAutoreload(TIM3,iTimeOut);
    TIM_ClearFlag(TIM3,TIM_FLAG_Update);
    TIM_ClearFlag(TIM3,TIM_FLAG_CC2);
    TIM_ClearFlag(TIM3,TIM_FLAG_CC1);
    TIM_Cmd(TIM3, ENABLE);
    EPC_Recv_Stage= 0;
    while (Rep_Flag)
    {
        if(Rep_Flag!=1)
        {
            if (TIM_GetFlagStatus(TIM3, TIM_FLAG_CC1) == SET)
            {
                TIM_ClearFlag(TIM3,TIM_FLAG_CC1);
                cTemp = TIM_GetCapture1(TIM3);
                EPC_period = cTemp -last_time;
                last_time = cTemp;
                switch (EPC_Recv_Stage)
                {
                case 0x00:
                    EPC_Recv_Stage = 0x01;
                    break;
                case 0x01:
                    if(EPC_period<SMALL_P)
                    {
                        co++;
                        if(co>30)
                        {
                            g_mu = 1;
                            EPC_Recv_Stage = 0x02;
                        }
                    }
                    else
                    {
                        Rep_Flag = 1;/*recv over flag*/
                        goto Exit1;
                    }
                    break;
                case 0x02:
                    if ((EPC_period < BIG_P) && (EPC_period > SMALL_P))
                    {
                        EPC_Recv_Stage = 0x03;
                        test = 1;
                    }
                    break;
                case 0x03:
                    if ((EPC_period >= SMALL_P)&&(EPC_period < BIG_P))
                    {
                        if(test==1)
                        {
                            test1=1;
                        }
                        test=test+2;
                        if(test==5)
                        {
                            test = 1;
                            EPC_Temp_Recv_Byte <<= 1;
                            EPC_Temp_Recv_Byte |= test1;
                            EPC_Recv_Bit_Index ++;
                            if (EPC_Recv_Bit_Index == 7u)
                            {
                                if(EPC_Temp_Recv_Byte==0x3D)
                                {
                                    g_mu = 1;
                                    EPC_Recv_Stage=0x04;
                                    EPC_Temp_Recv_Byte = 0x00;
                                    EPC_Recv_Bit_Index = 0;
                                }
                                else
                                {
                                    Rep_Flag = 1;/*recv over flag*/
                                    goto Exit1;
                                }
                            }
                        }
                        else if(test>=6)
                        {
                            Rep_Flag = 1;/*recv over flag*/
                            goto Exit1;
                        }
                    }
                    else if(EPC_period<SMALL_P)
                    {
                        if(test==1)
                        {
                            test1=0;
                        }
                        test=test+1;
                        if(test==4)
                        {
                            test = 0;
                            EPC_Temp_Recv_Byte <<= 1;
                            EPC_Temp_Recv_Byte |= test1;
                            EPC_Recv_Bit_Index ++;
                            if (EPC_Recv_Bit_Index == 7u)
                            {
                                if(EPC_Temp_Recv_Byte==0x3D)
                                {
                                    g_mu=1;
                                    EPC_Recv_Stage=0x04;
                                    EPC_Temp_Recv_Byte = 0x00;
                                    EPC_Recv_Bit_Index = 0;
                                }
                                else
                                {
                                    Rep_Flag = 1;/*recv over flag*/
                                    goto Exit1;
                                }
                            }
                        }
                        else if(test>=5)
                        {
                            Rep_Flag = 1;/*recv over flag*/
                            goto Exit1;
                        }
                    }
                    else
                    {
                        Rep_Flag = 1;/*recv over flag*/
                        goto Exit1;
                    }
                    break;
                case 0x04:
                    if ((EPC_period >= SMALL_P)&&(EPC_period < BIG_P))
                    {
                        if(test==1)
                        {
                            test1=1;
                        }
                        test=test+2;
                        if(test==5)
                        {
                            test = 1;
                            EPC_Temp_Recv_Byte <<= 1;
                            EPC_Temp_Recv_Byte |= test1;
                            EPC_Recv_Bit_Index ++;
                            EPC_ResponseRecvBits++;
                            if (EPC_Recv_Bit_Index == 8u)
                            {
                                EPC_Response_Recv_Buf[EPC_Recv_Byte_Index] = EPC_Temp_Recv_Byte;/*?箨??狴瓯陏?Y?龛?Response_Recv_Buf[]*/
                                EPC_Temp_Recv_Byte = 0x00;
                                EPC_Recv_Bit_Index = 0;
                                EPC_Recv_Byte_Index ++;
                            }
                        }
                        else if(test>=6)
                        {
                            Rep_Flag = 1;/*recv over flag*/
                            goto Exit1;
                        }
                    }
                    else if(EPC_period<SMALL_P)
                    {
                        if(test==1)
                        {
                            test1=0;
                        }
                        test=test+1;
                        if(test==4)
                        {
                            test = 0;
                            EPC_Temp_Recv_Byte <<= 1;
                            EPC_Temp_Recv_Byte |= test1;
                            EPC_Recv_Bit_Index ++;
                            EPC_ResponseRecvBits++;
                            if (EPC_Recv_Bit_Index == 8u)
                            {
                                EPC_Response_Recv_Buf[EPC_Recv_Byte_Index] = EPC_Temp_Recv_Byte;/*?箨??狴瓯陏?Y?龛?Response_Recv_Buf[]*/
                                EPC_Temp_Recv_Byte = 0x00;
                                EPC_Recv_Bit_Index = 0;
                                EPC_Recv_Byte_Index ++;
                            }
                        }
                        else if(test>=5)
                        {
                            Rep_Flag = 0;/*recv over flag*/
                            goto Exit1;
                        }
                    }
                    else
                    {
                        Rep_Flag = 1;/*recv over flag*/
                        goto Exit1;
                    }
                    if (EPC_ResponseRecvBits >= EPC_Return_Link_Bits)/*rate recv over*/
                    {
                        Rep_Flag = 3;/*recv over flag*/
                        goto Exit1;
                    }
                    break;
                }
            }
        }
        if(Rep_Flagx!=2)
        {
            if (TIM_GetFlagStatus(TIM3, TIM_FLAG_CC2) == SET)
            {
                TIM_ClearFlag(TIM3,TIM_FLAG_CC2);
                cTempx = TIM_GetCapture2(TIM3);
                EPC_periodx = cTempx -last_timex;
                last_timex = cTempx;
                switch (EPC_Recv_Stagex)
                {
                case 0x00:
                    EPC_Recv_Stagex = 0x01;
                    break;
                case 0x01:
                    if(EPC_periodx<SMALL_P)
                    {
                        co1++;
                        if(co1>30)
                        {
                            g_mu = 1;
                            EPC_Recv_Stagex = 0x02;
                        }
                    }
                    else
                    {
                        Rep_Flagx= 2;/*recv over flag*/
                        goto Exit1;
                    }
                case 0x02:
                    if ((EPC_periodx < BIG_P) && (EPC_periodx > SMALL_P))
                    {
                        EPC_Recv_Stagex = 0x03;
                        testx = 1;
                    }
                    break;
                case 0x03:
                    if ((EPC_periodx >= SMALL_P)&&(EPC_periodx < BIG_P))
                    {
                        if(testx==1)
                        {
                            test1x=1;
                        }
                        testx=testx+2;
                        if(testx==5)
                        {
                            testx = 1;
                            EPC_Temp_Recv_Bytex <<= 1;
                            EPC_Temp_Recv_Bytex |= test1x;
                            EPC_Recv_Bit_Indexx ++;
                            if (EPC_Recv_Bit_Indexx == 7u)
                            {
                                if(EPC_Temp_Recv_Bytex==0x3D)
                                {
                                    g_mu = 1;
                                    EPC_Recv_Stagex=0x04;
                                    EPC_Temp_Recv_Bytex = 0x00;
                                    EPC_Recv_Bit_Indexx = 0;
                                }
                                else
                                {
                                    Rep_Flagx = 2;/*recv over flag*/
                                    goto Exit1;
                                }
                            }
                        }
                        else if(testx>=6)
                        {
                            Rep_Flagx = 2;/*recv over flag*/
                            goto Exit1;
                        }
                    }
                    else if(EPC_periodx<SMALL_P)
                    {
                        if(testx==1)
                        {
                            test1x=0;
                        }
                        testx=testx+1;
                        if(testx==4)
                        {
                            testx = 0;
                            EPC_Temp_Recv_Bytex <<= 1;
                            EPC_Temp_Recv_Bytex |= test1x;
                            EPC_Recv_Bit_Indexx ++;
                            if (EPC_Recv_Bit_Indexx == 7u)
                            {
                                if(EPC_Temp_Recv_Bytex==0x3D)
                                {
                                    EPC_Recv_Stagex=0x04;
                                    EPC_Temp_Recv_Bytex = 0x00;
                                    EPC_Recv_Bit_Indexx = 0;
                                }
                                else
                                {
                                    Rep_Flagx = 2;/*recv over flag*/
                                    goto Exit1;
                                }
                            }
                        }
                        else if(testx>=5)
                        {
                            Rep_Flagx = 2;/*recv over flag*/
                            goto Exit1;
                        }
                    }
                    else
                    {
                        Rep_Flagx = 2;/*recv over flag*/
                        goto Exit1;
                    }
                    break;
                case 0x04:
                    if ((EPC_periodx >= SMALL_P)&&(EPC_periodx < BIG_P))
                    {
                        if(testx==1)
                        {
                            test1x=1;
                        }
                        testx=testx+2;
                        if(testx==5)
                        {
                            testx = 1;
                            EPC_Temp_Recv_Bytex <<= 1;
                            EPC_Temp_Recv_Bytex |= test1x;
                            EPC_Recv_Bit_Indexx ++;
                            EPC_ResponseRecvBitsx++;
                            if (EPC_Recv_Bit_Indexx == 8u)
                            {
                                EPC_Response_Recv_Bufx[EPC_Recv_Byte_Indexx] = EPC_Temp_Recv_Bytex;/*?箨??狴瓯陏?Y?龛?Response_Recv_Buf[]*/
                                EPC_Temp_Recv_Bytex = 0x00;
                                EPC_Recv_Bit_Indexx = 0;
                                EPC_Recv_Byte_Indexx ++;
                            }
                        }
                        else if(testx>=6)
                        {
                            Rep_Flagx = 2;/*recv over flag*/
                            goto Exit1;
                        }
                    }
                    else if(EPC_periodx<SMALL_P)
                    {
                        if(testx==1)
                        {
                            test1x=0;
                        }
                        testx=testx+1;
                        if(testx==4)
                        {
                            testx = 0;
                            EPC_Temp_Recv_Bytex <<= 1;
                            EPC_Temp_Recv_Bytex |= test1x;
                            EPC_Recv_Bit_Indexx ++;
                            EPC_ResponseRecvBitsx++;
                            if (EPC_Recv_Bit_Indexx == 8u)
                            {
                                EPC_Response_Recv_Bufx[EPC_Recv_Byte_Indexx] = EPC_Temp_Recv_Bytex;/*?箨??狴瓯陏?Y?龛?Response_Recv_Buf[]*/
                                EPC_Temp_Recv_Bytex = 0x00;
                                EPC_Recv_Bit_Indexx = 0;
                                EPC_Recv_Byte_Indexx ++;
                            }
                        }
                        else if(testx>=5)
                        {
                            Rep_Flagx = 2;/*recv over flag*/
                            goto Exit1;
                        }
                    }
                    else
                    {
                        Rep_Flagx = 2;/*recv over flag*/
                        goto Exit1;
                    }
                    if (EPC_ResponseRecvBitsx >= EPC_Return_Link_Bits)/*rate recv over*/
                    {
                        Rep_Flagx = 4;/*recv over flag*/
                        goto Exit1;
                    }
                    break;
                }
            }
        }
Exit1:
        if(Rep_Flag==3)
        {
            Rep_Flag=0;
        }
        if(Rep_Flagx==4)
        {
            EPC_ResponseRecvBits =EPC_ResponseRecvBitsx;
            memcpy(EPC_Response_Recv_Buf,EPC_Response_Recv_Bufx,(EPC_Return_Link_Bits+7)/8);
            Rep_Flag=0;
        }
        if((Rep_Flagx==2)&&(Rep_Flag==1))
        {
            Rep_Flag = 0;
        }
        if(TIM_GetFlagStatus(TIM3,TIM_FLAG_Update)==SET)
        {
            Rep_Flag = 0;
        }
    }
    TIM_PrescalerConfig(TIM3,0,TIM_PSCReloadMode_Immediate);
    TIM_ClearFlag(TIM3,TIM_FLAG_Update);
    TIM_Cmd(TIM3, DISABLE);
    if(bType == 0)
    {
        if ((EPC_ResponseRecvBits == 0)&&(g_mu==0))
        {
            return GL_NO_TAG;
        }
        if (EPC_ResponseRecvBits < EPC_Return_Link_Bits)
        {
            return GL_TRANSFER_ERROR;
        }
        if ((EPC_ResponseRecvBits == EPC_Return_Link_Bits)&&(Crc5Bit(EPC_Response_Recv_Buf,EPC_Return_Link_Bits)==0))
        {
            return GL_RN16_OK;
        }
        else
        {
            return GL_CRC_ERROR;
        }
    }
    else
    {
        if ((EPC_ResponseRecvBits == 0)&&(g_mu==0))
        {
            return GL_NO_TAG;
        }
        if (EPC_ResponseRecvBits < EPC_Return_Link_Bits)
        {
            return GL_TRANSFER_ERROR;
        }
        else
        {
            return GL_OK;
        }
    }
}
uint8_t _6D_FM0Decode1(void)
{
    return _6D_MyFM0Decode( (600*EPC_Return_Link_Bits)+600, 1);
}
unsigned char _6D_TEST_EPC_ReadOnlyOne_Protcol(void)
{
    unsigned char status;
    unsigned char i;
    unsigned char bitaddress[2] = {0x00,0x00};
    RFPowerON(150);/*RF-POWER开*/
    FreqHopping(0);
    Delay_ms(4);// 20ms
    _6D_Sort(0x10,0x04,0x03,bitaddress,0x0,NULL);
    Delay_us(200);// 110
    _6D_Query(0x00,0x00,0x00,0x01,0x02,0x00);
    Delay_us(130); // 20us
    IRQDisable();
    EPC_Return_Link_Bits = 16;/*set Receive data len*/
    status = _6D_RN16_FM0Decode();/*status为RF接收状态信息*/
    IRQEnable();/*IRQ中断使能开*/
    if (status == GL_RN16_OK)
    {
        for (i=0; i<(EPC_Return_Link_Bits/8); i++)
        {
            EPC_RN[i] = EPC_Response_Recv_Buf[i];
        }
        _6D_ACK(EPC_RN);
        Delay_us(130);
        IRQDisable();
        EPC_Return_Link_Bits = 34;
        status = _6D_FM0Decode1();
        IRQEnable();/*IRQ中断使能开*/
        if(status!=GL_OK)
        {
            _6D_NAK();
        }
    }
    return status;
}
unsigned char _6D_EPC_Read_Protcol(unsigned char RFSwitchoffFlag,unsigned char MemBank, unsigned char *WordPtr, unsigned char WordCount)
{
    unsigned char status;
    unsigned char i;
    unsigned char count[2];
    count[0] = 0x0;
    count[1] = WordCount;
    EPC_ResponseRecvComplete = 1;
    while (EPC_ResponseRecvComplete)
    {
        status = _6D_TEST_EPC_ReadOnlyOne_Protcol();
        if (status == GL_OK)
        {
            _6D_RefreshRN(EPC_RN);
            Delay_us(130);
            IRQDisable();/*IRQ INT CLOSE*/
            EPC_Return_Link_Bits = 16;
            status = _6D_RN16_FM0Decode();
            IRQEnable();
            if (status == GL_RN16_OK)
            {
                for (i=0; i<2; i++)
                {
                    EPC_RN[i] = EPC_Response_Recv_Buf[i];
                }
                _6D_Read(MemBank,WordPtr,count,EPC_RN);
                Delay_us(130);
                IRQDisable();/*IRQ INT CLOSE*/
                EPC_Return_Link_Bits = (40+(WordCount*16));
                status = _6D_FM0Decode();
                IRQEnable();
                if (status == GL_OK)
                {
                    EPC_ResponseRecvComplete = 0;
                    for (i=0; i<(WordCount*2); i++)
                    {
                        EPC_ID_data_Buf[i] = EPC_Response_Recv_Buf[i+1];
                    }
                }
            }
            EPC_ResponseRecvComplete = 0;
        }
        else
        {
            EPC_ResponseRecvComplete = 0;
        }
    }
    if (RFSwitchoffFlag)
    {
        RFPowerOFF();
    }
    return status;
}
unsigned char _6D_EPC_WriterOnlyOne_Protcol(unsigned char RFSwitchoffFlag,unsigned char MemBank, unsigned char *WordPtr, unsigned char *Data)
{
    unsigned char status;
    unsigned char i;
    unsigned char count[2];
    count[0] = 0x0;
    count[1] = 0x01;
    EPC_ResponseRecvComplete = 1;
    while (EPC_ResponseRecvComplete)
    {
        status = _6D_TEST_EPC_ReadOnlyOne_Protcol();
        if (status == GL_OK)
        {
            _6D_RefreshRN(EPC_RN);
            Delay_us(130);
            IRQDisable();/*IRQ INT CLOSE*/
            EPC_Return_Link_Bits = 16;
            status = _6D_RN16_FM0Decode();
            IRQEnable();
            if (status == GL_RN16_OK)
            {
                for (i=0; i<2; i++)
                {
                    EPC_RN[i] = EPC_Response_Recv_Buf[i];
                }
                _6D_Write(MemBank,WordPtr,count,Data,EPC_RN);
                Delay_us(130);
                IRQDisable();/*IRQ INT CLOSE*/
                EPC_Return_Link_Bits = 40;
                status = _6D_FM0Decode();
                IRQEnable();
                if (status == GL_OK)
                {
                    EPC_ResponseRecvComplete = 0;
                }
            }
            EPC_ResponseRecvComplete = 0;
        }
        else
        {
            EPC_ResponseRecvComplete = 0;
        }
    }
    if (RFSwitchoffFlag)
    {
        RFPowerOFF();
    }
    return status;
}
unsigned char _6D_EPC_Write_Protcol(unsigned char RFSwitchoffFlag,unsigned char MemBank, unsigned char *WordPtr, unsigned char *Data,unsigned char WordCount)
{
    unsigned char status;
    unsigned char i;
    unsigned char count[2];
    count[0] = 0x0;
    count[1] = WordCount;
    EPC_ResponseRecvComplete = 1;
    while (EPC_ResponseRecvComplete)
    {
        status = _6D_TEST_EPC_ReadOnlyOne_Protcol();
        if (status == GL_OK)
        {
            _6D_RefreshRN(EPC_RN);
            Delay_us(130);
            IRQDisable();/*IRQ INT CLOSE*/
            EPC_Return_Link_Bits = 16;
            status = _6D_RN16_FM0Decode();
            IRQEnable();
            if (status == GL_RN16_OK)
            {
                for (i=0; i<2; i++)
                {
                    EPC_RN[i] = EPC_Response_Recv_Buf[i];
                }
                _6D_Write(MemBank,WordPtr,count,Data,EPC_RN);
                Delay_us(130);
                IRQDisable();/*IRQ INT CLOSE*/
                Delay_ms(20);
                _6D_Read(MemBank,WordPtr,count,EPC_RN);
                Delay_us(130);
                IRQDisable();/*IRQ INT CLOSE*/
                EPC_Return_Link_Bits = (40+(WordCount*16));
                status = _6D_FM0Decode();
                IRQEnable();
                if (status == GL_OK)
                {
                    EPC_ResponseRecvComplete = 0;
                    for (i=0; i<(WordCount*2); i++)
                    {
                        if(EPC_Response_Recv_Buf[i+1]!= Data[i])
                        {
                            status = GL_ERROR;
                        }
                    }
                    //  if(status==GL_OK)
                    // SetWorkLedState(1);
                }
            }
            EPC_ResponseRecvComplete = 0;
        }
        else
        {
            EPC_ResponseRecvComplete = 0;
        }
    }
    if (RFSwitchoffFlag)
    {
        RFPowerOFF();
    }
    return status;
}
unsigned char _6D_EPC_LockTag_Protcol(uint8_t RFSwitchoffFlag,uint8_t MemBank,uint8_t Config,uint8_t Action)
{
    unsigned char status;
    unsigned char i;
    unsigned char temp=0;
    EPC_ResponseRecvComplete = 1;
    while (EPC_ResponseRecvComplete)
    {
        status = _6D_TEST_EPC_ReadOnlyOne_Protcol();
        if (status == GL_OK)
        {
            _6D_RefreshRN(EPC_RN);
            Delay_us(130); // 20us
            IRQDisable();
            EPC_Return_Link_Bits = 16;
            status = _6D_RN16_FM0Decode();
            IRQEnable();
            if (status == GL_RN16_OK)
            {
                for (i=0; i<2; i++)
                {
                    EPC_RN[i] = EPC_Response_Recv_Buf[i];
                }
                _6D_Lock(MemBank,Config,Action,EPC_RN);
                Delay_ms(3);
                IRQDisable();
                EPC_Return_Link_Bits = 40;
                status = _6D_FM0Decode();
                IRQEnable();
                if (status == GL_OK)
                {
                    // SetWorkLedState(1);
                }
                temp ++;
                if (temp >= 4)
                {
                    EPC_ResponseRecvComplete = 0;
                }
            }
        }
    }
    if (RFSwitchoffFlag)
    {
        RFPowerOFF();
    }
    return status;
}
unsigned char _6D_EPC_KillTag_Protcol(unsigned char RFSwitchoffFlag,unsigned char RFU_Buff, unsigned char Password1, unsigned char Password2,unsigned char Password3,unsigned char Password4)
{
    unsigned char status=0;
    unsigned char i;
    unsigned char Rep_Flag;
    EPC_ID_data_Buf[0] = 0x00;
    EPC_ID_data_Buf[1] = 0x00;
    Rep_Flag = 1;
    while (Rep_Flag)
    {
        status = _6D_TEST_EPC_ReadOnlyOne_Protcol();
        if (status == GL_OK)
        {
            _6D_RefreshRN(EPC_RN);
            Delay_us(130); // 20us
            IRQDisable();
            EPC_Return_Link_Bits = 16;
            status = _6D_RN16_FM0Decode();
            IRQEnable();
            if (status == GL_RN16_OK)
            {
                for (i=0; i<2; i++)
                {
                    EPC_RN[i] = EPC_Response_Recv_Buf[i];
                }
                _6D_Kill(EPC_RN);
                Delay_ms(3);
                IRQDisable();
                EPC_Return_Link_Bits = 40;
                status = _6D_FM0Decode();
                IRQEnable();
                if (status == GL_OK)
                {
                    // SetWorkLedState(1);
                }
            }
            Rep_Flag = 0;
        }
    }
    if (RFSwitchoffFlag)
    {
        RFPowerOFF();
    }
    return status;
}
unsigned char _6D_EPC_EraseTag_Protcol(unsigned char RFSwitchoffFlag,unsigned char MemBank, unsigned char *WordPtr, unsigned char *Data,unsigned char WordCount)
{
    unsigned char status=0;
    unsigned char i;
    unsigned char Rep_Flag;
    unsigned char Count[2];
    Count[0] = 0x00;
    Count[1] = WordCount;
    EPC_ID_data_Buf[0] = 0x00;
    EPC_ID_data_Buf[1] = 0x00;
    Rep_Flag = 1;
    while (Rep_Flag)
    {
        status = _6D_TEST_EPC_ReadOnlyOne_Protcol();
        if (status == GL_OK)
        {
            _6D_RefreshRN(EPC_RN);
            Delay_us(130); // 20us
            IRQDisable();
            EPC_Return_Link_Bits = 16;
            status = _6D_RN16_FM0Decode();
            IRQEnable();
            if (status == GL_RN16_OK)
            {
                for (i=0; i<2; i++)
                {
                    EPC_RN[i] = EPC_Response_Recv_Buf[i];
                }
                _6D_Erase(MemBank,WordPtr,Count,EPC_RN);
                Delay_ms(3);
                IRQDisable();
                EPC_Return_Link_Bits = 40;
                status = _6D_FM0Decode();
                IRQEnable();
                if (status == GL_OK)
                {
                    //SetWorkLedState(1);
                }
            }
            Rep_Flag = 0;
        }
    }
    if (RFSwitchoffFlag)
    {
        RFPowerOFF();
    }
    return status;
}
unsigned char _6D_EPC_AccessTag_Protcol(unsigned char RFSwitchoffFlag,unsigned char MemBank,unsigned char PassType,unsigned char *Password)
{
    unsigned char status=0;
    unsigned char i;
    unsigned char Rep_Flag;
    EPC_ID_data_Buf[0] = 0x00;
    EPC_ID_data_Buf[1] = 0x00;
    Rep_Flag = 1;
    while (Rep_Flag)
    {
        status = _6D_TEST_EPC_ReadOnlyOne_Protcol();
        if (status == GL_OK)
        {
            _6D_RefreshRN(EPC_RN);
            Delay_us(130); // 20us
            IRQDisable();
            EPC_Return_Link_Bits = 16;
            status = _6D_RN16_FM0Decode();
            IRQEnable();
            if (status == GL_RN16_OK)
            {
                for (i=0; i<2; i++)
                {
                    EPC_RN[i] = EPC_Response_Recv_Buf[i];
                }
                _6D_Get_RN(EPC_RN);
                Delay_us(130);
                IRQDisable();
                EPC_Return_Link_Bits = 48;
                status = _6D_FM0Decode();
                IRQEnable();
                for(i=0; i<2; i++)
                {
                    EPC_RN1[i] = EPC_Response_Recv_Buf[i];
                }
                _6D_Access(MemBank,PassType,Password,EPC_RN1, EPC_RN) ;
                Delay_ms(3);
                IRQDisable();
                EPC_Return_Link_Bits = 40;
                status = _6D_FM0Decode();
                IRQEnable();
                if (status == GL_OK)
                {
                    _6D_Get_RN(EPC_RN);
                    Delay_us(130);
                    IRQDisable();
                    EPC_Return_Link_Bits = 48;
                    status = _6D_FM0Decode();
                    IRQEnable();
                    for(i=0; i<2; i++)
                    {
                        EPC_RN2[i] = EPC_Response_Recv_Buf[i];
                    }
                    _6D_Access(MemBank,PassType,&Password[2],EPC_RN2, EPC_RN) ;
                    Delay_ms(3);
                    IRQDisable();
                    EPC_Return_Link_Bits = 40;
                    status = _6D_FM0Decode();
                    IRQEnable();
                }
            }
            Rep_Flag = 0;
        }
    }
    if (RFSwitchoffFlag)
    {
        RFPowerOFF();
    }
    return status;
}

unsigned char _6D_EPC_ReadMulti_Protcol(unsigned char RFSwitchoffFlag,unsigned short int rfpower)
{
    uint8_t status,status_r;
    uint8_t i=0;
    uint8_t count=0;
	  uint8_t lo_count=0;
    uint8_t RepFlag=1;
	  u8 noTag = 0;
    gbtest = 0;
    gbtest1 = 0;
	//uint8_t RecSafe[120];
    uint32_t X = 2;
    uint32_t CC = 0;//连续碰撞次数
    uint32_t CI = 0;//连续空闲次数
    uint8_t LastCommandDivideFlag = 0;
    //  AntennaSwitch(RFAntenna[(1+g_bRFSwitch)%RFAntenna[0]]);
    RFPowerON(rfpower);/*RF-POWER开*/
    Delay_ms(5);
    RepFlag = 1;
	
	  GPIO_SetBits(IFSW_CTR_PORT,IFSW_CTR_PIN);
	  printf("\n1");
    _6D_Query(0x00,0x00,0x00,0x01,0x02,0x01);
    LastCommandDivideFlag = 0;
Decode:
    count++;

    if(count>10)
    {
        goto Over;
    }
    Delay_us1(120);
    EPC_Return_Link_Bits = 16;
	  Delay_Time =15*75*4-40;// good2
	  GPIO_ResetBits(IFSW_CTR_PORT,IFSW_CTR_PIN);
    status = _6D_RN16_FM0Decode();
	  GPIO_SetBits(IFSW_CTR_PORT,IFSW_CTR_PIN);
	
    switch(status)
    {
    case GL_NO_TAG://空闲	
        CC = 0;
        CI++;
		    lo_count++;
        if(0==X)
        {
            goto Over;			
        }
        else
        {
            if(CI<CIN)
            {
                if(LastCommandDivideFlag)
                {
                    _6D_Divide(0x01,0x00);
                    LastCommandDivideFlag = 1;
                    goto Decode;
                }
                else
                {
                    _6D_QueryRep(0x00);
                    X = X-1;
                    LastCommandDivideFlag = 0;
                    goto Decode;
                }
            }
            else
            {
                _6D_Shrink(0x00);
                X = X/2;
                LastCommandDivideFlag = 0;
                goto Decode;
            }
        }
          //break;
    case GL_TRANSFER_ERROR://发生碰撞
    case GL_CRC_ERROR:
			//printf("b");
        CI = 0;
        CC++;
		    lo_count++;
        if(CC<CCN)
        {
            _6D_Divide(0x00,0x00);
            X = X+1;
            LastCommandDivideFlag = 1;
            goto Decode;
        }
        else
        {
            _6D_Disperse(0x00);
            X = 2*X +1;
            LastCommandDivideFlag = 0;
            goto Decode;
        }
		//break;
    case GL_RN16_OK://正确接收
		  printf("2");
        CI = 0;
        CC = 0;
        for (i=0; i<(EPC_Return_Link_Bits/8); i++)
        {
            EPC_RN[i] = EPC_Response_Recv_Buf[i];
        }
        Delay_us(120);
        _6D_ACK(EPC_RN);
        Delay_Time = (2208-1967)*15*4;//4260+15*600; //
	    	Delay_us1(1800);
        EPC_Return_Link_Bits = 128;   //16*8
		
        GPIO_ResetBits(IFSW_CTR_PORT,IFSW_CTR_PIN);	
        status = _6D_FM0Decode();   //从射频模块 EPC
		    GPIO_SetBits(IFSW_CTR_PORT,IFSW_CTR_PIN);

        if (status == GL_OK)
        {
            status_r = _6D_T1();   //读标签EPC 转发到安全模块 ---》 射频
					  printf("3");
						if(status_r==GL_OK)
						{
							for(;;)
              {
								status = _6D_T2(); //响应数据帧 
								printf("4");
								if(status==GL_OK)
								{
										printf("7");
								}
								else if(status ==GL_OVER)//读用户区结束
								{
									readTagFlag = hasNewTag;
									//BUZZER_LED_L;//红色
									printf("5");	
									//printf("status_r1111111: %X\n",status_r);	
									break;
								}
								else
								{
									printf("8");
									//BUZZER_LED_H;//绿色
									break;
								}

              }
            }
            else if(status_r==GL_OVER)//盘点结束
            {
				      readTagFlag = hasNewTag;
							printf("9");
							//status_r = GL_OK;
           }
        }
				else
				{
					//BUZZER_LED_H;//绿色
				}
        Delay_us(8);// 110
        _6D_QueryRep(0x00);
        X = X-1;
        LastCommandDivideFlag = 0;
        goto Decode;
    default:
        break;
    }

	Over:
        RFPowerOFF();
				printf("c\n");
    return(status_r);
}

uint8_t ReadTag(unsigned short int rfpower)
{
    uint8_t bState = 0;
    bState =_6D_EPC_ReadMulti_Protcol(1,rfpower);//
		if( bState != GL_OK && bState != GL_OVER)
		{
			channelSwitchCount = !channelSwitchCount;//读取不对了才切换解码通道	
		}				 
		printf("channelSwitchCount:%d\n",channelSwitchCount);		
	  ReadCard_Count++;
		Delay_ms(3);
    return bState;
}