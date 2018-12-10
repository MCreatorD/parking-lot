#include "sim_spi1.h"
#include "systick.h"

void Sim_SPI1_Init(void)
{  
  /*##-1- Enable peripherals and GPIO Clocks #################################*/



  /*##-2- Configure peripheral GPIO ##########################################*/
  /* SPI SCK GPIO pin configuration  */
  GPIO_InitTypeDef GPIO_InitStruct;
	
		/* Enable GPIO TX/RX clock */
  SPI1_SCK_GPIO_CLK_ENABLE();
  SPI1_MISO_GPIO_CLK_ENABLE();
  SPI1_MOSI_GPIO_CLK_ENABLE();
  SPI1_NSS_GPIO_CLK_ENABLE();
  
  GPIO_InitStruct.GPIO_Pin       = SPI1_SCK_PIN;
  GPIO_InitStruct.GPIO_Mode      = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
  //GPIO_InitStruct.Pull      = GPIO_PULLDOWN;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStruct.GPIO_Speed     = GPIO_Speed_50MHz;
	GPIO_Init(SPI1_SCK_GPIO_PORT, &GPIO_InitStruct);	
	
	//GPIO_SetBits(GPIOD , GPIO_Pin_9);

  /* SPI MISO GPIO pin configuration  */
	GPIO_InitStruct.GPIO_Pin       = SPI1_MISO_PIN;
  GPIO_InitStruct.GPIO_Mode      = GPIO_Mode_IN;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
  //GPIO_InitStruct.Pull      = GPIO_PULLDOWN;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;//GPIO_PuPd_NOPULL;
  GPIO_InitStruct.GPIO_Speed     = GPIO_Speed_50MHz;
	GPIO_Init(SPI1_MISO_GPIO_PORT, &GPIO_InitStruct);	

  /* SPI MOSI GPIO pin configuration  */
	GPIO_InitStruct.GPIO_Pin       = SPI1_MOSI_PIN;
  GPIO_InitStruct.GPIO_Mode      = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStruct.GPIO_PuPd      = GPIO_PuPd_UP;
	//GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStruct.GPIO_Speed     = GPIO_Speed_50MHz;
	GPIO_Init(SPI1_MOSI_GPIO_PORT, &GPIO_InitStruct);	
  
	/* SPI NSS GPIO pin configuration  */
	GPIO_InitStruct.GPIO_Pin       = SPI1_NSS_PIN;
  GPIO_InitStruct.GPIO_Mode      = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
  //GPIO_InitStruct.Pull      = GPIO_PULLDOWN;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStruct.GPIO_Speed     = GPIO_Speed_50MHz;
	GPIO_Init(SPI1_NSS_GPIO_PORT, &GPIO_InitStruct);
//	
	MOSI1_H;
	SCK1_L;
	NSS1_H;
//	GPIO_SetBits(GPIOD , GPIO_Pin_8);
//	GPIO_SetBits(GPIOD , GPIO_Pin_9);
//	GPIO_SetBits(GPIOD , GPIO_Pin_11);
	__nop();
	
}

void Sim_SPL1_nop(){
	__NOP();
//	__NOP();
//	__NOP();
//	__NOP();
//	__NOP();
//	__NOP();
//	__NOP();
//	__NOP();
//	__NOP();
//	__NOP();
	//Delay_ms(1);
}

/**
*	 按字节模拟读写SPI数据，主机模式，SPIMODE = 0，即CPOL = 0,CPHA = 0
*	 传送字宽为8位。
*	 由SPI的特性，在写入一个字节的同时，也会读取一个字节
*/
uint8_t Sim_SPI1_ReadWrite_Byte(uint8_t data)
{  
  uint8_t temp=0;
	uint8_t i = 0;
  //SPI_Init();
  //NSS_L;   //SPI NSS信号置为低
  SCK1_L;    
	for(i=0;i<8;i++)
	{ 
		//先将要输出的数据放到总线上去
		if(data&0x80) 
		{
			MOSI1_H;          /*若最高位为高，则输出高*/
		}
		else
		{
			MOSI1_L;          /*若最高位为低，则输出低*/    
		}    
		data <<= 1;
		
		Sim_SPL1_nop(); 
		
		SCK1_H; //产生上升沿，送出数据，同时采样数据
		
		temp <<= 1;        /*将上一次的数据左移1位*/
		if(MISO1)
		{
			temp++;          /*若从从机接收到高电平，数据自加一*/
		}
		
		Sim_SPL1_nop();
		
		SCK1_L;
	} 
    
  //NSS_H;
  //MOSI_H; 
  return temp;
}

void Sim_SPI1_ReadWriteBuf(uint8_t *writebuf,uint8_t *readbuf,uint16_t buflen){
	uint16_t i = 0;
	
	SCK1_L;
	Sim_SPL1_nop();
	NSS1_L;
	
	Sim_SPL1_nop();
	
	for(i=0;i<buflen;i++){
		readbuf[i] = Sim_SPI1_ReadWrite_Byte(writebuf[i]);
	}
	
	Sim_SPL1_nop();
	NSS1_H;
	Sim_SPL1_nop();
	SCK1_L;
}
