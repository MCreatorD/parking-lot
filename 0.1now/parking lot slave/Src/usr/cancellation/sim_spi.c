#include "sim_spi.h"
#include "systick.h"

//此SPI用作MCU和DAC通信

void Sim_SPL_nop(){
	for(int i=0;i<10;i++){
		__NOP();
		__NOP();
		__NOP();
		__NOP();
		__NOP();
		__NOP();
		__NOP();
		__NOP();
		__NOP();
		__NOP();
	}
	
	//Delay_ms(1);
}

void Sim_SPI_Init(void)
{  
  /*##-1- Enable peripherals and GPIO Clocks #################################*/
  /*##-2- Configure peripheral GPIO ##########################################*/
  /* SPI SCK GPIO pin configuration  */
  GPIO_InitTypeDef GPIO_InitStruct;
	
		/* Enable GPIO TX/RX clock */
  SPI_SCK_GPIO_CLK_ENABLE();
  SPI_MISO_GPIO_CLK_ENABLE();
  SPI_MOSI_GPIO_CLK_ENABLE();
  SPI_NSS_GPIO_CLK_ENABLE();
  
  GPIO_InitStruct.GPIO_Pin       = SPI_SCK_PIN;
  GPIO_InitStruct.GPIO_Mode      = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
  //GPIO_InitStruct.Pull      = GPIO_PULLDOWN;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStruct.GPIO_Speed     = GPIO_Speed_100MHz;
	GPIO_Init(SPI_SCK_GPIO_PORT, &GPIO_InitStruct);	
	
  /* SPI MOSI GPIO pin configuration  */
	GPIO_InitStruct.GPIO_Pin       = SPI_MOSI_PIN;
  GPIO_InitStruct.GPIO_Mode      = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStruct.GPIO_PuPd      = GPIO_PuPd_UP;
	//GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStruct.GPIO_Speed     = GPIO_Speed_100MHz;
	GPIO_Init(SPI_MOSI_GPIO_PORT, &GPIO_InitStruct);	
  
	/* SPI NSS GPIO pin configuration  */
	GPIO_InitStruct.GPIO_Pin       = SPI_NSS_PIN;
  GPIO_InitStruct.GPIO_Mode      = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
  //GPIO_InitStruct.Pull      = GPIO_PULLDOWN;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStruct.GPIO_Speed     = GPIO_Speed_100MHz;
	GPIO_Init(SPI_NSS_GPIO_PORT, &GPIO_InitStruct);
//	
	MOSI_H;
	SCK_H;
	NSS_H;

	Sim_SPL_nop();
	
}



/**
*	 按字节模拟读写SPI数据，主机模式，SPIMODE = 0，即CPOL = 0,CPHA = 0
*	 传送字宽为8位。
*	 由SPI的特性，在写入一个字节的同时，也会读取一个字节
*/
uint8_t Sim_SPI_ReadWrite_Byte(uint8_t data)
{  
  uint8_t temp=0;
	uint8_t i = 0;
	
	for(i=0;i<8;i++)
	{ 
		SCK_H;
		
		//先将要输出的数据放到总线上去
		if(data&0x80) 
		{
			MOSI_H;          //若最高位为高，则输出高
		}
		else
		{
			MOSI_L;          //若最高位为低，则输出低   
		}    
		data <<= 1;
		
		Sim_SPL_nop(); 
		
		SCK_L; //送出数据
		
		Sim_SPL_nop();

	} //end of for
  
	MOSI_H;
  
  return temp;
}

void Sim_SPI_ReadWriteBuf(uint16_t writebuf){
	uint16_t i = 0;
	
	u8 temp[2]={0};
	temp[0]=(writebuf&0xff00)>>8;
	temp[1]=(writebuf&0x00ff);
	
	SCK_H;
	NSS_L;
	Sim_SPL_nop();
	
	for(i=0;i<2;i++){
		Sim_SPI_ReadWrite_Byte(temp[i]);
	}
	
	Sim_SPL_nop();
	SCK_H;
	Sim_SPL_nop(); //注意，这里的时钟先后顺序不能弄反。SCK要在NSS后操作。
	NSS_H;
	
}
