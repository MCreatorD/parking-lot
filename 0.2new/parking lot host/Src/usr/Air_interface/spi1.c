#include "spi1.h"
#include "timer.h"
#include "utility.h"
#include "rx485_send.h"
#include "communication.h"
#include <string.h>
#include "systick.h"
#include "rx485_rev.h"
#include "epc.h"
unsigned char TxBuffer[TXBUFFERSIZE];
unsigned char RxBuffer [RXBUFFERSIZE];
//unsigned char  error= 0;
void rf_out_init(void)
{
		GPIO_InitTypeDef  GPIO_InitStructure;
	  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOD, &GPIO_InitStructure);
    Set_RFOUT_DATA();//默认输出高 ， 低代表有射频数据传给安全模块
}

void Board_SPI1_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    SPI_InitTypeDef  SPI_InitStructure;
    DMA_InitTypeDef  DMA_InitStructure;
    SPIx_CLK_INIT(SPIx_CLK, ENABLE);
    RCC_AHB1PeriphClockCmd(SPIx_SCK_GPIO_CLK | SPIx_MISO_GPIO_CLK | SPIx_MOSI_GPIO_CLK|SPIx_NSS_GPIO_CLK, ENABLE);
    GPIO_PinAFConfig(SPIx_SCK_GPIO_PORT, SPIx_SCK_SOURCE, SPIx_SCK_AF);
    GPIO_PinAFConfig(SPIx_MOSI_GPIO_PORT, SPIx_MOSI_SOURCE, SPIx_MOSI_AF);
    GPIO_PinAFConfig(SPIx_NSS_GPIO_PORT, SPIx_NSS_SOURCE, SPIx_NSS_AF);
    GPIO_PinAFConfig(SPIx_MISO_GPIO_PORT, SPIx_MISO_SOURCE, SPIx_MISO_AF);
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;
    GPIO_InitStructure.GPIO_Pin = SPIx_SCK_PIN;
    GPIO_Init(SPIx_SCK_GPIO_PORT, &GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin =  SPIx_MISO_PIN;
    GPIO_Init(SPIx_MISO_GPIO_PORT, &GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin =  SPIx_MOSI_PIN;
    GPIO_Init(SPIx_MOSI_GPIO_PORT, &GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin =  SPIx_NSS_PIN;
    GPIO_Init(SPIx_NSS_GPIO_PORT, &GPIO_InitStructure);
    SPI_I2S_DeInit(SPIx);
    SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
    SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;
    SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;
    SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge;
    SPI_InitStructure.SPI_NSS = SPI_NSS_Hard;
    SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_4;
    SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
    SPI_InitStructure.SPI_CRCPolynomial = 7;
    RCC_AHB1PeriphClockCmd(DMAx_CLK, ENABLE);
    DMA_ClearFlag(SPI1_DMA_STREAM_TX, SPI1_TX_DMA_TCFLAG | SPI1_TX_DMA_FEIFLAG | SPI1_TX_DMA_DMEIFLAG | \
                  SPI1_TX_DMA_TEIFLAG | SPI1_TX_DMA_HTIFLAG);
    DMA_ClearFlag(SPI1_DMA_STREAM_RX, SPI1_RX_DMA_TCFLAG | SPI1_RX_DMA_FEIFLAG | SPI1_RX_DMA_DMEIFLAG | \
                  SPI1_RX_DMA_TEIFLAG | SPI1_RX_DMA_HTIFLAG);
    DMA_Cmd(SPI1_DMA_STREAM_TX, DISABLE);
    DMA_DeInit(SPI1_DMA_STREAM_TX);
    DMA_Cmd(SPI1_DMA_STREAM_RX, DISABLE);
    DMA_DeInit(SPI1_DMA_STREAM_RX);
    DMA_InitStructure.DMA_Channel = SPI1_DMA_CHANNEL;
    DMA_InitStructure.DMA_PeripheralBaseAddr = SPI1_DR_ADDRESS;
    DMA_InitStructure.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
    DMA_InitStructure.DMA_MemoryInc = DMA_MemoryInc_Enable;
    DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
    DMA_InitStructure.DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
    DMA_InitStructure.DMA_Mode = DMA_Mode_Normal;
    DMA_InitStructure.DMA_Priority = DMA_Priority_VeryHigh;
    DMA_InitStructure.DMA_FIFOMode = DMA_FIFOMode_Disable;
    DMA_InitStructure.DMA_FIFOThreshold = DMA_FIFOThreshold_Full;
    DMA_InitStructure.DMA_MemoryBurst = DMA_MemoryBurst_Single;
    DMA_InitStructure.DMA_PeripheralBurst = DMA_PeripheralBurst_Single;
    DMA_InitStructure.DMA_DIR = DMA_DIR_PeripheralToMemory;
    DMA_InitStructure.DMA_Memory0BaseAddr = (uint32_t)RxBuffer;
    DMA_InitStructure.DMA_BufferSize = RXBUFFERSIZE;
    DMA_DeInit(SPI1_DMA_STREAM_RX);
    DMA_Init(SPI1_DMA_STREAM_RX, &DMA_InitStructure);
    DMA_InitStructure.DMA_DIR = DMA_DIR_MemoryToPeripheral;
    DMA_InitStructure.DMA_Memory0BaseAddr = (uint32_t)TxBuffer;
    DMA_InitStructure.DMA_BufferSize =TXBUFFERSIZE;
    DMA_DeInit(SPI1_DMA_STREAM_TX);
    DMA_Init(SPI1_DMA_STREAM_TX, &DMA_InitStructure);
    SPI_I2S_DeInit(SPIx);
    SPI_InitStructure.SPI_Mode = SPI_Mode_Slave;
    SPI_Init(SPIx, &SPI_InitStructure);
}
#if 1
uint8_t SPI_Read(uint8_t count,uint8_t timeout)
{
    uint8_t ret = 1;
    volatile uint16_t temp;
    volatile uint16_t totelLength = 0;
    uint8_t Recv_Stage = 0;
    SPI1->DR;
    Timeout= timeout;
	  Timeout= 20;
    DMA_SetCurrDataCounter(SPI1_DMA_STREAM_RX, 0);
    DMA_SetCurrDataCounter(SPI1_DMA_STREAM_RX, RXBUFFERSIZE);
    SPI_DMACmd(SPI1,SPI_I2S_DMAReq_Rx,ENABLE);
    DMA_Cmd(SPI1_DMA_STREAM_RX, ENABLE);
    while (DMA_GetCmdStatus(SPI1_DMA_STREAM_RX)!= ENABLE)
    {
        ;
    }
    while((DMA_GetFlagStatus(SPI1_DMA_STREAM_RX,SPI1_RX_DMA_TCFLAG) == RESET)&&(Timeout!=0))
    {
        if(ret!=1)
        {
            break;
        }
        if(Timeout==0)
        {
            ret = 0;
        }
        else
        {
            temp = RXBUFFERSIZE-DMA_GetCurrDataCounter(SPI1_DMA_STREAM_RX);
            switch(Recv_Stage)
            {
            case 0:
                if(temp>=2)
                {
                    if(0xab==RxBuffer[0])
                    {
                        Recv_Stage =1;
                    }
                    else
                    {
                        ret = 0;
                    }
                }
                break;
            case 1:
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
                    Recv_Stage = 0x02;
                }
                else
                {
                    ret = 0;
                }
                break;
            case 2:
                if(temp>=6)
                {
                    totelLength = (7+RxBuffer[2]+RxBuffer[3]*256)/8+7;
                    Recv_Stage = 0x03;
                }
                break;
            case 3:
                if(temp>=totelLength)
                {
                    if(XOR_Cal(&RxBuffer[1],(uint8_t)(totelLength-2u))==RxBuffer[(uint8_t)(totelLength-1u)])
                    {
                        ret = 0x02;
                    }
                    else
                    {
                        ret = 0x00;
                    }
                    ret = 0x02;
                }
                break;
            default:
                break;
            }
        }
    }
    DMA_Cmd(SPI1_DMA_STREAM_RX, DISABLE);
    while(DMA_GetCmdStatus(SPI1_DMA_STREAM_RX)!= DISABLE)
    {
        ;
    }
    DMA_ClearFlag(SPI1_DMA_STREAM_RX, SPI1_RX_DMA_TCFLAG | SPI1_RX_DMA_FEIFLAG | SPI1_RX_DMA_DMEIFLAG | \
                  SPI1_RX_DMA_TEIFLAG | SPI1_RX_DMA_HTIFLAG);
    DMA_Cmd(SPI1_DMA_STREAM_RX, DISABLE);
    return ret;
}


uint8_t SPI_Send(uint8_t bCommand,uint8_t *data,uint8_t timeout)
{
    uint16_t i;
    uint8_t ret;
	  ret = 1;
    Timeout= timeout;
  	Timeout = 20;	
    DMA_SetCurrDataCounter(SPI1_DMA_STREAM_TX, 0);
    switch(bCommand)
    {
    case 0x01://盘点结果通知帧
        TxBuffer[0] = 0xAA;
        TxBuffer[1] = 0x20;
        for(i=0; i<16; i++)
        {
            TxBuffer[2+i] = data[i];
        }
        TxBuffer[18] = EPC_RN[0];
        TxBuffer[19] = EPC_RN[1];
        TxBuffer[20] = XOR_Cal(&TxBuffer[1],19);
        DMA_SetCurrDataCounter(SPI1_DMA_STREAM_TX, 21);
        break;
				
    case 0x05:
        TxBuffer[0] = 0xAA;
        TxBuffer[1] = 0x20;
        TxBuffer[2] = 0x0;
        TxBuffer[3] = 0x0;
        TxBuffer[4] =0xff;
        TxBuffer[5] =0xff;
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
        DMA_SetCurrDataCounter(SPI1_DMA_STREAM_TX, 21);
        break;
				
    case 0x02://响应数据帧
        TxBuffer[0] = 0xAA;
        TxBuffer[1] = 0x40;
        TxBuffer[2] = RxBuffer[4];
        TxBuffer[3] = RxBuffer[5];
        for(i=0; i<((EPC_Return_Link_Bits+7)/8); i++)
        {
            TxBuffer[4+i] = EPC_Response_Recv_Buf[i];
        }
        TxBuffer[4+(EPC_Return_Link_Bits+7)/8] = XOR_Cal(&TxBuffer[1],(3+(EPC_Return_Link_Bits+7)/8));
        DMA_SetCurrDataCounter(SPI1_DMA_STREAM_TX,(5+(EPC_Return_Link_Bits+7)/8));
        break;
    case 0x03://通知安全模块，数据传输错误，
        TxBuffer[0] =0xAA;
        TxBuffer[1] =0x62;
        DMA_SetCurrDataCounter(SPI1_DMA_STREAM_TX, 2);
        break;
    case 0x04:
        TxBuffer[0] = 0xAA;
        TxBuffer[1] = 0x95;
        DMA_SetCurrDataCounter(SPI1_DMA_STREAM_TX, 2);
        break;
    default:
        DMA_SetCurrDataCounter(SPI1_DMA_STREAM_TX, 0);
        break;
    }
		
		Timeout=20;	
    SPI_DMACmd(SPI1,SPI_I2S_DMAReq_Tx,ENABLE);
    DMA_Cmd(SPI1_DMA_STREAM_TX, ENABLE);
    while (DMA_GetCmdStatus(SPI1_DMA_STREAM_TX)!= ENABLE)
    {
        ;
    }
		
    Clr_RFOUT_DATA();	
    while((DMA_GetFlagStatus(SPI1_DMA_STREAM_TX,SPI1_TX_DMA_TCFLAG) == RESET) &&(Timeout!=0))
    //while((DMA_GetFlagStatus(SPI1_DMA_STREAM_TX,SPI1_TX_DMA_TCFLAG) == RESET))
    {
    }
		//if(Timeout== 0) error = 44;
		
    DMA_Cmd(SPI1_DMA_STREAM_TX, DISABLE);
    while(DMA_GetCmdStatus(SPI1_DMA_STREAM_TX)!= DISABLE)
    {
        ;
    }
    DMA_ClearFlag(SPI1_DMA_STREAM_TX, SPI1_TX_DMA_TCFLAG | SPI1_TX_DMA_FEIFLAG | SPI1_TX_DMA_DMEIFLAG | \
                  SPI1_TX_DMA_TEIFLAG | SPI1_TX_DMA_HTIFLAG);
    DMA_Cmd(SPI1_DMA_STREAM_TX, DISABLE);
		
   		
		Set_RFOUT_DATA();		
    return ret;
	
}
#endif

uint8_t SPI_Read1(void)
{
	
	//RxBuffer  转发到 485 
	
    uint8_t ret = 1;
    volatile uint16_t temp;
    volatile uint16_t totelLength = 0;
	  uint8_t Recv_Stage = 0;
    SPI1->DR;
	
    DMA_SetCurrDataCounter(SPI1_DMA_STREAM_RX, RXBUFFERSIZE);//设置传输数据长度,重装填,并让接收地址偏址从0开始
    SPI_DMACmd(SPI1,SPI_I2S_DMAReq_Rx,ENABLE);
    DMA_Cmd(SPI1_DMA_STREAM_RX, ENABLE);
	
    while (DMA_GetCmdStatus(SPI1_DMA_STREAM_RX)!= ENABLE)
    {
        ;
    }
	  Timeout = 20;		
    while((DMA_GetFlagStatus(SPI1_DMA_STREAM_RX,SPI1_RX_DMA_TCFLAG) == RESET)&&(Timeout!=0))
		//while(DMA_GetFlagStatus(SPI1_DMA_STREAM_RX,SPI1_RX_DMA_TCFLAG) == RESET)
    {
        if(ret!=1)
        {
            break;
        }
				
        if(Timeout==0)
        {
            ret = 0;
				//	  error = 2;
					break;
        }
        else
        {
            temp = RXBUFFERSIZE-DMA_GetCurrDataCounter(SPI1_DMA_STREAM_RX);//计算接收的字节数
            switch(Recv_Stage)
            {
								case 0:
										if(temp>=2)//收取两帧数据后判断
										{
												if(0xab==RxBuffer[0])
												{
														Recv_Stage =1;
												}
												else
												{
														ret = 0;
												}
										}
										break;
								case 1:
										if(0x02==(RxBuffer[1]>>5))//读写操作结束 010
										{
												if(RxBuffer[1]==0x55)//正确
												{
														ret = 4;
												}
												else//错误帧数据
												{
														ret = 0;
												}
										}
										else if(0x01==(RxBuffer[1]>>5))//指令转发数据帧 001
										{
												Recv_Stage = 0x02;
										}
										else
										{
												ret = 0;
										}
										break;
								case 2:
										if(temp>=6)
										{
												totelLength = (7+RxBuffer[2]+RxBuffer[3]*256)/8+7;
												Recv_Stage = 0x03;
										}
										break;
								case 3:
										if(temp>=totelLength)
										{
												ret = 0x02;		
										}
										break;
								default:
										break;
            }
        }
    }
//		if(Timeout== 0) error = 44;
		
		SM_To_RF(Device_rf,RxBuffer);
		
    DMA_Cmd(SPI1_DMA_STREAM_RX, DISABLE);
    while(DMA_GetCmdStatus(SPI1_DMA_STREAM_RX)!= DISABLE)
    {
        ;
    }
    DMA_ClearFlag(SPI1_DMA_STREAM_RX, SPI1_RX_DMA_TCFLAG | SPI1_RX_DMA_FEIFLAG | SPI1_RX_DMA_DMEIFLAG | \
                  SPI1_RX_DMA_TEIFLAG | SPI1_RX_DMA_HTIFLAG);
    DMA_Cmd(SPI1_DMA_STREAM_RX, DISABLE);

	//	memset(RxBuffer,0,totelLength+10);
		
	//	memset(TxMessage,0,totelLength+10);
    return ret;
}

uint8_t SPI_Send1(uint8_t *data,uint16_t rfcount)
{
	  //完全接收can数据 ，完全转发
    uint8_t ret;
	  memcpy(TxBuffer,data,rfcount);
	
		SysTick->CTRL  |= SysTick_CTRL_ENABLE_Msk;//开启滴答定时器 

		Timeout=20;	
	
    DMA_SetCurrDataCounter(SPI1_DMA_STREAM_TX, rfcount);	
	
    SPI_DMACmd(SPI1,SPI_I2S_DMAReq_Tx,ENABLE);
    DMA_Cmd(SPI1_DMA_STREAM_TX, ENABLE);
    while (DMA_GetCmdStatus(SPI1_DMA_STREAM_TX)!= ENABLE)
    {
        ;
    }
		
    Clr_RFOUT_DATA();	
    while((DMA_GetFlagStatus(SPI1_DMA_STREAM_TX,SPI1_TX_DMA_TCFLAG) == RESET) &&(Timeout!=0))
    //while((DMA_GetFlagStatus(SPI1_DMA_STREAM_TX,SPI1_TX_DMA_TCFLAG) == RESET))
    {
    }
//		if(Timeout== 0) error = 44;
		
    DMA_Cmd(SPI1_DMA_STREAM_TX, DISABLE);
    while(DMA_GetCmdStatus(SPI1_DMA_STREAM_TX)!= DISABLE)
    {
        ;
    }
    DMA_ClearFlag(SPI1_DMA_STREAM_TX, SPI1_TX_DMA_TCFLAG | SPI1_TX_DMA_FEIFLAG | SPI1_TX_DMA_DMEIFLAG | \
                  SPI1_TX_DMA_TEIFLAG | SPI1_TX_DMA_HTIFLAG);
    DMA_Cmd(SPI1_DMA_STREAM_TX, DISABLE);
		
   		
		Set_RFOUT_DATA();

		ret = SPI_Read1();
	  //memset(TxBuffer,0,rfcount);	
    return ret;
	
}



