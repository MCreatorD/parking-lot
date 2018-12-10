#include <stdlib.h>
#include <string.h>
#include "EPC.h"
#include "timer.h"

uint8_t  EPC_RN[2];
uint8_t  EPC_RN1[2];
uint8_t  EPC_RN2[2];

uint8_t  EPC_Send_Buf[16];
uint8_t EPC_BitsToSend;
uint8_t TRcal_timer;
uint8_t EPC_CRC[2];
uint8_t EPC_Response_Recv_Buf[512];
uint16_t EPC_ResponseRecvBits ;
uint16_t EPC_Recv_Byte_Index;
uint8_t EPC_Recv_Bit_Index;
uint8_t EPC_Temp_Recv_Byte;

uint8_t EPC_Recv_Stage;
uint8_t EPC_Recv_Bit_Indexx;
uint8_t EPC_Temp_Recv_Bytex;

uint8_t EPC_Response_Recv_Bufx[512];
uint16_t EPC_ResponseRecvBitsx ;
uint16_t EPC_Recv_Byte_Indexx;
uint8_t EPC_Recv_Bit_Indexx;
uint8_t EPC_Temp_Recv_Bytex;

uint8_t EPC_Recv_Stagex;
uint16_t EPC_Premablex;
u32 EPC_periodx;
uint16_t EPC_Return_Link_Bits;
uint16_t EPC_Premable;
u32 EPC_period;

void EPC_IO_Configure(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);		 //前向命令
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_Init(GPIOC, &GPIO_InitStructure);
	//Set_ASK_DATA();
	
//	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
//    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
//    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
//    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
//    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//    GPIO_Init(GPIOD, &GPIO_InitStructure);
//    Set_RFOUT_DATA();
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);   //前后相隔离
	GPIO_InitStructure.GPIO_Pin = IFSW_CTR_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(IFSW_CTR_PORT, &GPIO_InitStructure);
	GPIO_ResetBits(IFSW_CTR_PORT,IFSW_CTR_PIN);
	
}
void StuffSendBuf(unsigned char Data, unsigned char len)  //将数据按一定格式打包进EPC_Send_Buf待发送至标签
{
    signed char  i,j;
    unsigned char  current_bytes;
    unsigned char  current_bits;
    if(0==len)
    {
        return;
    }
    current_bytes = EPC_BitsToSend /8;
    current_bits  = EPC_BitsToSend %8;
    i = 8 - current_bits-len;
    if(i >= 0)
    {
        EPC_Send_Buf[current_bytes] |= Data<<i;
    }
    else
    {
        i = abs(i);
        j = 8-i;
        EPC_Send_Buf[current_bytes] |= Data>>i;
        current_bytes++;
        EPC_Send_Buf[current_bytes] |= Data<<j;
    }
    EPC_BitsToSend += len;
}
void ClearSendBuf(unsigned char *Buff, unsigned char len)
{
    memset(Buff, 0 , len);
}


void Send_Delimiter(void)
{
    Set_ASK_DATA();
    TIM_SetCounter(TIM3,0);
    TIM_SetAutoreload(TIM3,690);
    TIM_Cmd(TIM3, ENABLE);
    while(TIM_GetFlagStatus(TIM3,TIM_FLAG_Update)==RESET)
    {
        ;
    }
    TIM_ClearFlag(TIM3,TIM_FLAG_Update);
    TIM_Cmd(TIM3, DISABLE);
    Clr_ASK_DATA();
    TIM_SetCounter(TIM3,0);
    TIM_SetAutoreload(TIM3,2573);
    TIM_Cmd(TIM3, ENABLE);
    while(TIM_GetFlagStatus(TIM3,TIM_FLAG_Update)==RESET)
    {
        ;
    }
    {
    }
    TIM_ClearFlag(TIM3,TIM_FLAG_Update);
    TIM_Cmd(TIM3, DISABLE);
    Set_ASK_DATA();
    TIM_SetCounter(TIM3,0);
    TIM_SetAutoreload(TIM3,321);
    TIM_Cmd(TIM3, ENABLE);
    while(TIM_GetFlagStatus(TIM3,TIM_FLAG_Update)==RESET)
    {
        ;
    }
    TIM_ClearFlag(TIM3,TIM_FLAG_Update);
    TIM_Cmd(TIM3, DISABLE);
    Clr_ASK_DATA();
    TIM_SetCounter(TIM3,0);
    TIM_SetAutoreload(TIM3,315);
    TIM_Cmd(TIM3, ENABLE);
    while(TIM_GetFlagStatus(TIM3,TIM_FLAG_Update)==RESET)
    {
        ;
    }
    TIM_ClearFlag(TIM3,TIM_FLAG_Update);
    TIM_Cmd(TIM3, DISABLE);
    Set_ASK_DATA();
    TIM_SetCounter(TIM3,0);
    TIM_SetAutoreload(TIM3,321);
    TIM_Cmd(TIM3, ENABLE);
    while(TIM_GetFlagStatus(TIM3,TIM_FLAG_Update)==RESET)
    {
        ;
    }
    TIM_ClearFlag(TIM3,TIM_FLAG_Update);
    TIM_Cmd(TIM3, DISABLE);
    Clr_ASK_DATA();
}
void  Send_Data(uint16_t Time)
{
    Clr_ASK_DATA();
    TIM_SetCounter(TIM3,0);
    switch(Time)
    {
    case _6D_TIME_2TC:
        TIM_SetAutoreload(TIM3,289);
        break;
    case _6D_TIME_3TC:
        TIM_SetAutoreload(TIM3,672);
        break;
    case _6D_TIME_4TC:
        TIM_SetAutoreload(TIM3,1041);
        break;
    case _6D_TIME_5TC:
        TIM_SetAutoreload(TIM3,1416);
        break;
    default:
        break;
    }
    TIM_Cmd(TIM3, ENABLE);
    while(TIM_GetFlagStatus(TIM3,TIM_FLAG_Update)==RESET)
    {
        ;
    }
    TIM_ClearFlag(TIM3,TIM_FLAG_Update);
    TIM_Cmd(TIM3, DISABLE);
    Set_ASK_DATA();
    TIM_SetCounter(TIM3,0);
    TIM_SetAutoreload(TIM3,323);
    TIM_Cmd(TIM3, ENABLE);
    while(TIM_GetFlagStatus(TIM3,TIM_FLAG_Update)==RESET)
    {
        ;
    }
    TIM_ClearFlag(TIM3,TIM_FLAG_Update);
    TIM_Cmd(TIM3, DISABLE);
    Clr_ASK_DATA();
}
void EPC_SendCommand(void)
{
    uint8_t i,j;
    uint8_t data;
    uint8_t send_byte_len;
    uint8_t c;
    uint16_t count=0;
    if(EPC_BitsToSend&0x01)
    {
        StuffSendBuf(0x0,1);
    }
    send_byte_len = EPC_BitsToSend/8+1;
    Send_Delimiter();
    for (i=0; i<send_byte_len; i++)
    {
        data = EPC_Send_Buf[i];
        for (j=0; ((j<4)&&(count<EPC_BitsToSend)); j++)
        {
            c=data&0xC0;
            switch(c)
            {
            case 0x00:
                Send_Data(_6D_TIME_2TC);
                break;
            case 0x40:
                Send_Data(_6D_TIME_3TC);
                break;
            case 0xC0:
                Send_Data(_6D_TIME_4TC);
                break;
            case 0x80:
                Send_Data(_6D_TIME_5TC);
                break;
            default:
                break;
            }
            data =data<<2;
            count +=2;
        }
    }
    Clr_ASK_DATA();
    TIM_Cmd(TIM3, DISABLE);
}
