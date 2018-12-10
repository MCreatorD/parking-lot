#include "DAC1080S.h"
#include "sim_spi.h"
void DAC1080S_SPI2_Configure(void)
{
	/**
* SPI2用作于DAC1080通信
*/
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
	SPI_InitStruct.SPI_DataSize = SPI_DataSize_16b; 
	SPI_InitStruct.SPI_Mode = SPI_Mode_Master;
	SPI_InitStruct.SPI_CPOL = SPI_CPOL_Low ; //工作于spimode0,即数据线平时低电平，上升沿时采样
	SPI_InitStruct.SPI_CPHA = SPI_CPHA_1Edge;
	SPI_InitStruct.SPI_NSS = SPI_NSS_Soft ;
	SPI_InitStruct.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_4; //2分频，约18mhz
	SPI_InitStruct.SPI_FirstBit = SPI_FirstBit_MSB;
	SPI_InitStruct.SPI_CRCPolynomial = 7;
	SPI_Init(SPI2, &SPI_InitStruct);

	SPI_Cmd(SPI2, ENABLE);

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

u16 SPI2_send_byte(u16 data)
{
	u16 i=0;
	u16 rev=0;
	
	SPI2_CS_ENABLE;
	while(SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_TXE)==RESET);
	SPI_I2S_SendData(SPI2,data);
	
	while(SPI_I2S_GetFlagStatus(SPI2, SPI_I2S_FLAG_RXNE)==RESET);
	rev= SPI_I2S_ReceiveData(SPI2);
	
	for(i = 100; i>0; i--);
	SPI2_CS_DISABLE;
	
	return rev;
}

void Set_WTM(void)
{
	Sim_SPI_ReadWriteBuf(0x9000);
}

void Set_WRM(void)
{
	u16 wrm=0x8000;
	Sim_SPI_ReadWriteBuf(wrm);
	
}

void DAC1080S_Write(u16 value,u8 channel)
{
	u16 WriteValue=0;
	
	Set_WTM();
	
	WriteValue =channel<<12;
	WriteValue |=value<<2;
	Sim_SPI_ReadWriteBuf(WriteValue);
	Set_WTM();
	
}

void DAC1080S_Write_Value2(u16 value1,u16 value2,u8 channel_1,u8 channel_2)
{

	u16 WriteValue[2]={0};
	u16 contrl=0xa000;
	
	Set_WTM();
	
	WriteValue[0] =channel_1<<12;
	WriteValue[0] |=value1<<2;
	Sim_SPI_ReadWriteBuf(WriteValue[0]);
	
	WriteValue[1] =channel_2<<12;
	WriteValue[1] |=value2<<2;
	Sim_SPI_ReadWriteBuf(WriteValue[1]);
	
	contrl |=(1<<channel_1)+(1<<channel_2);
	Sim_SPI_ReadWriteBuf(contrl);
	
	
	
}




