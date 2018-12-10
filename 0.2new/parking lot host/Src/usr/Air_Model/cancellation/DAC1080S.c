#include "DAC1080S.h"
#include "cancell_spi.h"

void Set_WTM(void)
{
	Cancell_SPI_ReadWriteBuf(0x9000);
}

void Set_WRM(void)
{
	u16 wrm=0x8000;
	Cancell_SPI_ReadWriteBuf(wrm);
	
}

void DAC1080S_Write(u16 value,u8 channel)
{
	u16 WriteValue=0;
	
	Set_WTM();
	
	WriteValue =channel<<12;
	WriteValue |=value<<2;
	Cancell_SPI_ReadWriteBuf(WriteValue);
	Set_WTM();
	
}

void DAC1080S_Write_Value2(u16 value1,u16 value2,u8 channel_1,u8 channel_2)
{

	u16 WriteValue[2]={0};
	u16 contrl=0xa000;
	
	Set_WTM();
	
	WriteValue[0] =channel_1<<12;
	WriteValue[0] |=value1<<2;
	Cancell_SPI_ReadWriteBuf(WriteValue[0]);
	
	WriteValue[1] =channel_2<<12;
	WriteValue[1] |=value2<<2;
	Cancell_SPI_ReadWriteBuf(WriteValue[1]);
	
	contrl |=(1<<channel_1)+(1<<channel_2);
	Cancell_SPI_ReadWriteBuf(contrl);
	
	
	
}




