#include "sim_spi.h"
#include "systick.h"

//��SPI����MCU��DACͨ��

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
*	 ���ֽ�ģ���дSPI���ݣ�����ģʽ��SPIMODE = 0����CPOL = 0,CPHA = 0
*	 �����ֿ�Ϊ8λ��
*	 ��SPI�����ԣ���д��һ���ֽڵ�ͬʱ��Ҳ���ȡһ���ֽ�
*/
uint8_t Sim_SPI_ReadWrite_Byte(uint8_t data)
{  
  uint8_t temp=0;
	uint8_t i = 0;
	
	for(i=0;i<8;i++)
	{ 
		SCK_H;
		
		//�Ƚ�Ҫ��������ݷŵ�������ȥ
		if(data&0x80) 
		{
			MOSI_H;          //�����λΪ�ߣ��������
		}
		else
		{
			MOSI_L;          //�����λΪ�ͣ��������   
		}    
		data <<= 1;
		
		Sim_SPL_nop(); 
		
		SCK_L; //�ͳ�����
		
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
	Sim_SPL_nop(); //ע�⣬�����ʱ���Ⱥ�˳����Ū����SCKҪ��NSS�������
	NSS_H;
	
}
