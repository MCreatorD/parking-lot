#include "cancell_spi.h"
#include "systick.h"

//��SPI����MCU��DACͨ��

void Cancell_SPL_nop(){
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

void Cancell_SPI_Init(void)
{  
  /* SPI SCK GPIO pin configuration  */
  GPIO_InitTypeDef GPIO_InitStruct;
	
		/* Enable GPIO TX/RX clock */
  Cancell_SPI_SCK_GPIO_CLK_ENABLE();
  //Cancell_SPI_MISO_GPIO_CLK_ENABLE();
  Cancell_SPI_MOSI_GPIO_CLK_ENABLE();
  Cancell_SPI_NSS_GPIO_CLK_ENABLE();
  
  GPIO_InitStruct.GPIO_Pin       = Cancell_SPI_SCK_PIN;
  GPIO_InitStruct.GPIO_Mode      = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
  //GPIO_InitStruct.Pull      = GPIO_PULLDOWN;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStruct.GPIO_Speed     = GPIO_Speed_100MHz;
	GPIO_Init(Cancell_SPI_SCK_GPIO_PORT, &GPIO_InitStruct);	
	
  /* SPI MOSI GPIO pin configuration  */
	GPIO_InitStruct.GPIO_Pin       = Cancell_SPI_MOSI_PIN;
  GPIO_InitStruct.GPIO_Mode      = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStruct.GPIO_PuPd      = GPIO_PuPd_UP;
	//GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStruct.GPIO_Speed     = GPIO_Speed_100MHz;
	GPIO_Init(Cancell_SPI_MOSI_GPIO_PORT, &GPIO_InitStruct);	
  
	/* SPI NSS GPIO pin configuration  */
	GPIO_InitStruct.GPIO_Pin       = Cancell_SPI_NSS_PIN;
  GPIO_InitStruct.GPIO_Mode      = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
  //GPIO_InitStruct.Pull      = GPIO_PULLDOWN;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStruct.GPIO_Speed     = GPIO_Speed_100MHz;
	GPIO_Init(Cancell_SPI_NSS_GPIO_PORT, &GPIO_InitStruct);
//	
	Cancell_MOSI_H;
	Cancell_SCK_H;
	Cancell_NSS_H;

	Cancell_SPL_nop();
	
}



/**
*	 ���ֽ�ģ���дSPI���ݣ�����ģʽ��SPIMODE = 0����CPOL = 0,CPHA = 0
*	 �����ֿ�Ϊ8λ��
*	 ��SPI�����ԣ���д��һ���ֽڵ�ͬʱ��Ҳ���ȡһ���ֽ�
*/
uint8_t Cancell_SPI_ReadWrite_Byte(uint8_t data)
{  
  uint8_t temp=0;
	uint8_t i = 0;
	
	for(i=0;i<8;i++)
	{ 
		Cancell_SCK_H;
		
		//�Ƚ�Ҫ��������ݷŵ�������ȥ
		if(data&0x80) 
		{
			Cancell_MOSI_H;          //�����λΪ�ߣ��������
		}
		else
		{
			Cancell_MOSI_L;          //�����λΪ�ͣ��������   
		}    
		data <<= 1;
		
		Cancell_SPL_nop(); 
		
		Cancell_SCK_L; //�ͳ�����
		
		Cancell_SPL_nop();

	} //end of for
  
	Cancell_MOSI_H;
  
  return temp;
}

void Cancell_SPI_ReadWriteBuf(uint16_t writebuf){
	uint16_t i = 0;
	
	u8 temp[2]={0};
	temp[0]=(writebuf&0xff00)>>8;
	temp[1]=(writebuf&0x00ff);
	
	Cancell_SCK_H;
	Cancell_NSS_L;
	Cancell_SPL_nop();
	
	for(i=0;i<2;i++){
		Cancell_SPI_ReadWrite_Byte(temp[i]);
	}
	
	Cancell_SPL_nop();
	Cancell_SCK_H;
	Cancell_SPL_nop(); //ע�⣬�����ʱ���Ⱥ�˳����Ū����SCKҪ��NSS�������
	Cancell_NSS_H;
	
}
