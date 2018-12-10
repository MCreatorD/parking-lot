/*
*���ģ��SPI ��дFLASH
*/
#include "soft_spi.h"

//��SPI����MCU��FPGAͨ��

void Soft_SPI_Init(void)
{  
	/*##-2- Configure peripheral GPIO ##########################################*/
  /* SPI SCK GPIO pin configuration  */
  GPIO_InitTypeDef GPIO_InitStruct;
	
		/* Enable GPIO TX/RX clock */
  SOFT_SPI_SCK_GPIO_CLK_ENABLE();
  SOFT_SPI_MISO_GPIO_CLK_ENABLE();
  SOFT_SPI_MOSI_GPIO_CLK_ENABLE();
  SOFT_SPI_NSS_GPIO_CLK_ENABLE();
  
  GPIO_InitStruct.GPIO_Pin       = SOFT_SPI_SCK_PIN;
  GPIO_InitStruct.GPIO_Mode      = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
  //GPIO_InitStruct.Pull      = GPIO_PULLDOWN;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStruct.GPIO_Speed     = GPIO_Speed_100MHz;
	GPIO_Init(SOFT_SPI_SCK_GPIO_PORT, &GPIO_InitStruct);	
	
	//GPIO_SetBits(GPIOD , GPIO_Pin_9);

  /* SPI MISO GPIO pin configuration  */
	GPIO_InitStruct.GPIO_Pin       = SOFT_SPI_MISO_PIN;
  GPIO_InitStruct.GPIO_Mode      = GPIO_Mode_IN;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
  //GPIO_InitStruct.Pull      = GPIO_PULLDOWN;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;//GPIO_PuPd_NOPULL;
  GPIO_InitStruct.GPIO_Speed     = GPIO_Speed_100MHz;
	GPIO_Init(SOFT_SPI_MISO_GPIO_PORT, &GPIO_InitStruct);	

  /* SPI MOSI GPIO pin configuration  */
	GPIO_InitStruct.GPIO_Pin       = SOFT_SPI_MOSI_PIN;
  GPIO_InitStruct.GPIO_Mode      = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStruct.GPIO_PuPd      = GPIO_PuPd_UP;
	//GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStruct.GPIO_Speed     = GPIO_Speed_100MHz;
	GPIO_Init(SOFT_SPI_MOSI_GPIO_PORT, &GPIO_InitStruct);	
  
	/* SPI NSS GPIO pin configuration  */
	GPIO_InitStruct.GPIO_Pin       = SOFT_SPI_NSS_PIN;
  GPIO_InitStruct.GPIO_Mode      = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
  //GPIO_InitStruct.Pull      = GPIO_PULLDOWN;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStruct.GPIO_Speed     = GPIO_Speed_100MHz;
	GPIO_Init(SOFT_SPI_NSS_GPIO_PORT, &GPIO_InitStruct);
//	
	MOSI_H;
	SCK_L;
	NSS_H;
	
	__nop();
	
}

void Soft_SPL_nop(){
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
*	 ���ֽ�ģ���дSPI���ݣ�����ģʽ��SPIMODE = 0����CPOL = 0,CPHA = 0
*	 �����ֿ�Ϊ8λ��
*	 ��SPI�����ԣ���д��һ���ֽڵ�ͬʱ��Ҳ���ȡһ���ֽ�
*/
uint8_t Soft_SPI_ReadWrite_Byte(uint8_t data)
{  
  uint8_t temp=0;
	uint8_t i = 0;
	
	for(i=0;i<8;i++)
	{ 
		
		Soft_SPL_nop();
	
		SCK_L;
		
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
		
		Soft_SPL_nop(); 
		
		//�Ȳ�������
		
		temp <<= 1;        //����һ�ε���������1λ
		if(MISO)
		{
			temp++;          //���Ӵӻ����յ��ߵ�ƽ�������Լ�һ
		}
		SCK_H; //���������أ��ͳ�����
		
//		Soft_SPL_nop();
//	
//		SCK_L; //������������Ϊ�ͣ�����ᵼ����һ֡���ݵ��׸�bit����ʱ�ͱ��������ߣ���������ʽ��ȡʱ���ᶪ���bit

	} //end of for
  
	MOSI_H;
  
  return temp;
}


void Soft_SPI_ReadWriteBuf(uint8_t *writebuf,uint8_t *readbuf,uint16_t buflen){
	uint16_t i = 0;
	
	SCK_L;
	NSS_L;
	
	
	for(i=0;i<buflen;i++){
		readbuf[i] = Soft_SPI_ReadWrite_Byte(writebuf[i]);
	}
	
	Soft_SPL_nop();
	NSS_H;
	Soft_SPL_nop(); //ע�⣬�����ʱ���Ⱥ�˳����Ū����SCKҪ��NSS�������
	SCK_L;
	
}

