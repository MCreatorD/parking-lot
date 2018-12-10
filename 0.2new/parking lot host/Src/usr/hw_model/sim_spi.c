#include "sim_spi.h"
#include "systick.h"

//此SPI用作MCU和FPGA通信

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
	
	//GPIO_SetBits(GPIOD , GPIO_Pin_9);

  /* SPI MISO GPIO pin configuration  */
	GPIO_InitStruct.GPIO_Pin       = SPI_MISO_PIN;
  GPIO_InitStruct.GPIO_Mode      = GPIO_Mode_IN;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
  //GPIO_InitStruct.Pull      = GPIO_PULLDOWN;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;//GPIO_PuPd_NOPULL;
  GPIO_InitStruct.GPIO_Speed     = GPIO_Speed_100MHz;
	GPIO_Init(SPI_MISO_GPIO_PORT, &GPIO_InitStruct);	

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
	SCK_L;
	NSS_H;
//	GPIO_SetBits(GPIOD , GPIO_Pin_8);
//	GPIO_SetBits(GPIOD , GPIO_Pin_9);
//	GPIO_SetBits(GPIOD , GPIO_Pin_11);
	__nop();
	
}

void Sim_SPL_nop(){
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
	//Delay_ms(1);
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
		
		Sim_SPL_nop();
	
		SCK_L;
		
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
		
		//先采样数据
		
		temp <<= 1;        //将上一次的数据左移1位
		if(MISO)
		{
			temp++;          //若从从机接收到高电平，数据自加一
		}
		SCK_H; //产生上升沿，送出数据
		
//		Sim_SPL_nop();
//	
//		SCK_L; //不能在这里置为低，否则会导致下一帧数据的首个bit在这时就被送上总线，而导致正式读取时，会丢这个bit

	} //end of for
  
	MOSI_H;
  
  return temp;
}

//uint8_t Sim_SPI_ReadWrite_Byte(uint8_t data)
//{  
//  uint8_t temp=0;
//	uint8_t i = 0;
//  //SPI_Init();
//  //NSS_L;   //SPI NSS信号置为低
//  SCK_L;    
//	for(i=0;i<8;i++)
//	{ 
//		//先将要输出的数据放到总线上去
//		if(data&0x80) 
//		{
//			MOSI_H;          /*若最高位为高，则输出高*/
//		}
//		else
//		{
//			MOSI_L;          /*若最高位为低，则输出低*/    
//		}    
//		data <<= 1;
//		
//		Sim_SPL_nop(); 
//		
//		SCK_H; //产生上升沿，送出数据，同时采样数据
//		
//		temp <<= 1;        /*将上一次的数据左移1位*/
//		if(MISO)
//		{
//			temp++;          /*若从从机接收到高电平，数据自加一*/
//		}
//		
//		Sim_SPL_nop();
//		
//		SCK_L;
//	} 
//    
//  //NSS_H;
//  //MOSI_H; 
//  return temp;
//}

void Sim_SPI_ReadWriteBuf(uint8_t *writebuf,uint8_t *readbuf,uint16_t buflen){
	uint16_t i = 0;
	
	SCK_L;
	NSS_L;
	
	
	for(i=0;i<buflen;i++){
		readbuf[i] = Sim_SPI_ReadWrite_Byte(writebuf[i]);
	}
	
	Sim_SPL_nop();
	NSS_H;
	Sim_SPL_nop(); //注意，这里的时钟先后顺序不能弄反。SCK要在NSS后操作。
	SCK_L;
	
}
