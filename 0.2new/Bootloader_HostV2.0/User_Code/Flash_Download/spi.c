#include "spi.h"


/**
* SPI1 暂未使用
*/
void SPI1_Init(void)
{
	SPI_InitTypeDef SPI_InitStruct;	 
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB | RCC_AHB1Periph_GPIOB | RCC_AHB1Periph_GPIOB,ENABLE);

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1,ENABLE);
	
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource3,  GPIO_AF_SPI1);
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource4, GPIO_AF_SPI1);
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource5, GPIO_AF_SPI1);
  GPIO_PinAFConfig(GPIOB, GPIO_PinSource15, GPIO_AF_SPI1);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_DOWN;  
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	SPI_I2S_DeInit(SPI1);
	
	SPI_InitStruct.SPI_Direction= SPI_Direction_2Lines_FullDuplex;
	SPI_InitStruct.SPI_DataSize = SPI_DataSize_8b; 
	
	SPI_InitStruct.SPI_Mode = SPI_Mode_Slave;
	SPI_InitStruct.SPI_CPOL = SPI_CPOL_Low ;
	SPI_InitStruct.SPI_CPHA = SPI_CPHA_1Edge;
  SPI_InitStruct.SPI_NSS = SPI_NSS_Hard;
	
	SPI_InitStruct.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_8;
	SPI_InitStruct.SPI_FirstBit = SPI_FirstBit_MSB;
	SPI_InitStruct.SPI_CRCPolynomial = 7;
	SPI_Init(SPI1, &SPI_InitStruct);

	SPI_Cmd(SPI1, ENABLE);
}

/**
* SPI2用作于安全模块通信
*/
void SPI2_Init(void)
{
	SPI_InitTypeDef SPI_InitStruct;	 
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB | RCC_AHB1Periph_GPIOB | RCC_AHB1Periph_GPIOB,ENABLE);

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI2,ENABLE);

	
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource13,  GPIO_AF_SPI2);
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource14, GPIO_AF_SPI2);
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource15, GPIO_AF_SPI2);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_DOWN;  
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	SPI_I2S_DeInit(SPI2);
	SPI_InitStruct.SPI_Direction= SPI_Direction_2Lines_FullDuplex;
	SPI_InitStruct.SPI_DataSize = SPI_DataSize_8b; 
	SPI_InitStruct.SPI_Mode = SPI_Mode_Master;
	SPI_InitStruct.SPI_CPOL = SPI_CPOL_Low ; //工作于spimode0,即数据线平时低电平，上升沿时采样
	SPI_InitStruct.SPI_CPHA = SPI_CPHA_1Edge;
	SPI_InitStruct.SPI_NSS = SPI_NSS_Soft ;
	SPI_InitStruct.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_2; //2分频，约18mhz
	SPI_InitStruct.SPI_FirstBit = SPI_FirstBit_MSB;
	SPI_InitStruct.SPI_CRCPolynomial = 7;
	SPI_Init(SPI2, &SPI_InitStruct);

	SPI_Cmd(SPI2, ENABLE);

}

/**
* SPI3用作于读写FLASH
*/
void SPI3_Init(void)
{
	SPI_InitTypeDef SPI_InitStruct;	 
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC | RCC_AHB1Periph_GPIOC | RCC_AHB1Periph_GPIOC,ENABLE);

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI3,ENABLE);

	
	GPIO_PinAFConfig(GPIOC, GPIO_PinSource10,  GPIO_AF_SPI3);
	GPIO_PinAFConfig(GPIOC, GPIO_PinSource11,  GPIO_AF_SPI3);
	GPIO_PinAFConfig(GPIOC, GPIO_PinSource12,  GPIO_AF_SPI3);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_DOWN;  
	GPIO_Init(GPIOC, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
	GPIO_Init(GPIOC, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
	GPIO_Init(GPIOC, &GPIO_InitStructure);

	SPI_I2S_DeInit(SPI3);
	SPI_InitStruct.SPI_Direction= SPI_Direction_2Lines_FullDuplex;
	SPI_InitStruct.SPI_DataSize = SPI_DataSize_8b; 
	SPI_InitStruct.SPI_Mode = SPI_Mode_Master;
	SPI_InitStruct.SPI_CPOL = SPI_CPOL_Low ;
	SPI_InitStruct.SPI_CPHA = SPI_CPHA_1Edge;
	SPI_InitStruct.SPI_NSS = SPI_NSS_Soft ;
	SPI_InitStruct.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_4;
	SPI_InitStruct.SPI_FirstBit = SPI_FirstBit_MSB;
	SPI_InitStruct.SPI_CRCPolynomial = 7;
	SPI_Init(SPI3, &SPI_InitStruct);

	SPI_Cmd(SPI3, ENABLE);

}


//SPIx 读写一个字节
//TxData:要写入的字节
//返回值:读取到的字节
u8 SPI1_ReadWrite_byte(u8 data)
{
	while(SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_TXE)==RESET);
	SPI_I2S_SendData(SPI1,data);
	
	while(SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_RXNE)==RESET);
	return SPI_I2S_ReceiveData(SPI1);
}

void SPI1_ReadWriteBuf(uint8_t *writebuf,uint8_t *readbuf,uint16_t buflen){
	uint16_t i = 0;
	
//	SPI1_CS_ENABLE;
	for(i=0;i<buflen;i++){
		readbuf[i] = SPI1_ReadWrite_byte(writebuf[i]);
	}
//	SPI1_CS_DISABLE;
	
}




u8 SPI2_ReadWrite_byte(u8 data)
{
	while(SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_TXE)==RESET);
	SPI_I2S_SendData(SPI2,data);
	
	while(SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_RXNE)==RESET);
	return SPI_I2S_ReceiveData(SPI2);
}

void SPI2_ReadWriteBuf(uint8_t *writebuf,uint8_t *readbuf,uint16_t buflen){
	uint16_t i = 0;
	
	SPI2_CS_ENABLE;
	for(i=0;i<buflen;i++){
		readbuf[i] = SPI2_ReadWrite_byte(writebuf[i]);
	}
	SPI2_CS_DISABLE;
	
}
uint16_t SPI2_Send_byte(u8 data)
{
    while(SPI_I2S_GetFlagStatus( SPI2, SPI_I2S_FLAG_TXE)==RESET)
    {
        ;
    }
    SPI_I2S_SendData( SPI2,data);
    while(SPI_I2S_GetFlagStatus( SPI2, SPI_I2S_FLAG_RXNE)==RESET)
    {
        ;
    }
    return SPI_I2S_ReceiveData( SPI2);
}

u16 SPI2_Receive_byte(void)
{
	while(SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_TXE)==RESET);
	SPI_I2S_SendData(SPI2,0x00);//发送一个空的 然后 判断接受
	
	while(SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_RXNE)==RESET);
	return SPI_I2S_ReceiveData(SPI2);
}

u8 SPI2_Send_bytes(uint8_t data[],int count)
{
    int i;
    SPI2_CS_ENABLE;
    for(i=0; i<count; i++)
    {
        SPI2_Send_byte(data[i]);
    }
    SPI2_CS_DISABLE;
    if(1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

u8 SPI2_Receive_bytes(uint8_t buf[],uint8_t len)
{
    uint8_t i;
    SPI2_CS_ENABLE;
    for(i=0; i<len; i++)
    {
        while(SPI_I2S_GetFlagStatus( SPI2, SPI_I2S_FLAG_TXE)==RESET)
        {
            ;
        }
        SPI_I2S_SendData( SPI2,0x00);
        while(SPI_I2S_GetFlagStatus( SPI2, SPI_I2S_FLAG_RXNE)==RESET)
        {
            ;
        }
        buf[i]= SPI_I2S_ReceiveData( SPI2);
    }
    SPI2_CS_DISABLE;
    if(1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


u8 SPI3_ReadSend_byte(u8 data)
{
	u8 SPI_Wait_TimeOut = 200;
	
	while(SPI_I2S_GetFlagStatus(SPI3, SPI_I2S_FLAG_TXE)==RESET)//检查发送缓存空标志位
	{
		if(!(SPI_Wait_TimeOut--)) return 0; 
	}
	SPI_I2S_SendData(SPI3,data);
	
	SPI_Wait_TimeOut = 200;
	while(SPI_I2S_GetFlagStatus(SPI3, SPI_I2S_FLAG_RXNE)==RESET)//检查接收缓存空标志位
	{
		if(!(SPI_Wait_TimeOut--)) return 0; 
	}
	return SPI_I2S_ReceiveData(SPI3);
}

u16 SPI3_Receive_byte(void)
{
	while(SPI_I2S_GetFlagStatus(SPI3, SPI_I2S_FLAG_TXE)==RESET);
	SPI_I2S_SendData(SPI3,0x00);//发送一个空的 然后 判断接受
	
	while(SPI_I2S_GetFlagStatus(SPI3, SPI_I2S_FLAG_RXNE)==RESET);
	return SPI_I2S_ReceiveData(SPI3);
}
