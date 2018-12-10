#include "gpio.h"
#include "i2c.h"

void Board_EXIO_Init(uint8_t IO_ST)
{
	uint8_t PCF8574_Add = 0x40;
	
  I2C_Write(I2C1, PCF8574_Add, 0x20, &IO_ST, 1);
}
 
//can tx �� PA12
void GPIO_Configuration(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);	
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	PA12_L;
}



//void GPIO_Configuration(void)
//{
//	GPIO_InitTypeDef  GPIO_InitStructure;
//  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
//	//GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable , ENABLE);
//	
//	//���½���EPCS�����ļ�����ȫ����Ϊ���״̬����ʹ��FPGA������������
//	
//	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);


//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
//	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
//	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
//	GPIO_Init(GPIOD, &GPIO_InitStructure);//EPCS_SPI_MO EPCS_NCS EPCS_SPI_CLK
//	


//	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);


//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7; //EPCS_SPI_MI,FPGA_nSTATUS
//	//GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7 ; //FPGA_nSTATUS
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
//	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
//	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
//	GPIO_Init(GPIOC, &GPIO_InitStructure);
//	
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9|GPIO_Pin_8; //FPGA_nCE,FPGA_nCONFIG
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
//	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
//	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
//	GPIO_Init(GPIOC, &GPIO_InitStructure);
////�޸� 2018/5/10 FPGA���ز���	
//	GPIO_ResetBits(GPIOC , GPIO_Pin_9); //FPGAƬѡ��Ϊ0
//	GPIO_SetBits(GPIOC , GPIO_Pin_8);   //FPGA_nCONFIG��Ϊ1
//	
//	
//	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
//	
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8; //FPGA_CONF_DONE
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN; 
//	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
//	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
//	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	/////////////////////////////////////////////////////////////
//	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
//	
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10; //������Դ
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT; 
//	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
//	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
//	GPIO_Init(GPIOE, &GPIO_InitStructure);
//	
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11; //�������Դ
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT; 
//	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
//	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
//	GPIO_Init(GPIOE, &GPIO_InitStructure);
//	
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12; //��������Դ
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT; 
//	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
//	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
//	GPIO_Init(GPIOE, &GPIO_InitStructure);
//	
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9; //��Ƶ���ص�Դ
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT; 
//	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
//	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
//	GPIO_Init(GPIOE, &GPIO_InitStructure);
//	
//	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14; //PAʹ�ùܽ�
//	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT; 
//	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
//	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
//	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
//	GPIO_Init(GPIOE, &GPIO_InitStructure);
	

//}


