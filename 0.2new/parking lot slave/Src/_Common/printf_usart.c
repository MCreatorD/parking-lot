#include "printf_usart.h"

#ifdef PrintfUSART1
	#define USARTx_IRQHANDLER   USART1_IRQHandler
#endif
#ifdef PrintfUSART2
	#define USARTx_IRQHANDLER   USART2_IRQHandler
#endif
#ifdef PrintfUSART3
	#define USARTx_IRQHANDLER   USART3_IRQHandler
#endif
#ifdef PrintfUSART4
	#define USARTx_IRQHANDLER   UART4_IRQHandler
#endif
#ifdef PrintfUSART5
	#define USARTx_IRQHANDLER   UART5_IRQHandler
#endif
#ifdef PrintfUSART6
	#define USARTx_IRQHANDLER   USART6_IRQHandler
#endif

/*设置是否使用硬件流控制*/
//#define HwFlowControl

/*******************************************************************************
* Function Name  : USART_Configuration
* Description    : Configure Printf_USARTx 
* Input          : None
* Output         : None
* Return         : None
* Attention		 : None
*******************************************************************************/
void Printf_USART_Configuration(void)
{ 												
  GPIO_InitTypeDef GPIO_InitStructure;
  USART_InitTypeDef USART_InitStructure; 

  RCC_AHB1PeriphClockCmd(Printf_USARTx_TX_GPIO_CLK,ENABLE);
  RCC_AHB1PeriphClockCmd(Printf_USARTx_RX_GPIO_CLK,ENABLE);

  #if defined PrintfUSART1 || defined PrintfUSART6
  	RCC_APB2PeriphClockCmd(Printf_USARTx_CLK,ENABLE);
  #else
	RCC_APB1PeriphClockCmd(Printf_USARTx_CLK,ENABLE);
  #endif

  GPIO_PinAFConfig(Printf_USARTx_TX_GPIO_PORT, Printf_USARTx_TX_SOURCE, Printf_USARTx_TX_AF);
  GPIO_PinAFConfig(Printf_USARTx_RX_GPIO_PORT, Printf_USARTx_RX_SOURCE, Printf_USARTx_RX_AF);

  /*
  *  Printf_USARTx_TX -> PA9 , Printf_USARTx_RX -PA10
  */
  GPIO_InitStructure.GPIO_Pin = Printf_USARTx_TX_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_Init(Printf_USARTx_TX_GPIO_PORT, &GPIO_InitStructure);


  GPIO_InitStructure.GPIO_Pin = Printf_USARTx_RX_PIN;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_Init(Printf_USARTx_RX_GPIO_PORT, &GPIO_InitStructure);

  #if defined HwFlowControl && !defined PrintfUART4 && !defined PrintfUART5 
  	RCC_AHB1PeriphClockCmd(Printf_USARTx_RTS_GPIO_CLK,ENABLE);
	RCC_AHB1PeriphClockCmd(Printf_USARTx_CTS_GPIO_CLK,ENABLE);
	
	GPIO_PinAFConfig(Printf_USARTx_RTS_GPIO_PORT, Printf_USARTx_RTS_SOURCE, Printf_USARTx_RTS_AF);
	GPIO_PinAFConfig(Printf_USARTx_CTS_GPIO_PORT, Printf_USARTx_CTS_SOURCE, Printf_USARTx_CTS_AF);

	GPIO_InitStructure.GPIO_Pin = Printf_USARTx_RTS_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(Printf_USARTx_RTS_GPIO_PORT, &GPIO_InitStructure);
	
	
	GPIO_InitStructure.GPIO_Pin = Printf_USARTx_CTS_PIN;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(Printf_USARTx_CTS_GPIO_PORT, &GPIO_InitStructure);
  #endif
/*
   		 USARTx configured as follow:
         - BaudRate = 115200 baud  
		 - Word Length = 8 Bits
         - One Stop Bit
         - No parity
         - Hardware flow control disabled (RTS and CTS signals)
         - Receive and transmit    
 */

  USART_InitStructure.USART_BaudRate = 115200;
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
  USART_InitStructure.USART_StopBits = USART_StopBits_1;
  USART_InitStructure.USART_Parity = USART_Parity_No;
  #if defined HwFlowControl && !defined PrintfUART4 && !defined PrintfUART5
  	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_RTS_CTS;
  #else
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
  #endif
	USART_InitStructure.USART_Mode = USART_Mode_Tx;
  //USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
  USART_Init(Printf_USARTx, &USART_InitStructure);
  /* Enable the Printf_USARTx Transmit interrupt: this interrupt is generated when the 
     Printf_USARTx transmit data register is empty */
  //USART_ITConfig(Printf_USARTx,USART_IT_RXNE,ENABLE);

  USART_Cmd(Printf_USARTx, ENABLE);
  while(USART_GetFlagStatus(Printf_USARTx, USART_FLAG_TC)==RESET);//解决第一个字节丢失问题
  //Printf_USART_NVIC_Config();

}

void Printf_USART_NVIC_Config(void)
{
  NVIC_InitTypeDef NVIC_InitStructure;

  /* Enable the USARTx Interrupt */
  NVIC_InitStructure.NVIC_IRQChannel = Printf_USARTx_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);

}

#if 0
/*使用microLib的方法*/
int fputc(int ch, FILE *f)
{
	USART_SendData(USART1, (uint8_t) ch);

	while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET) {}	
   
    return ch;
}
int GetKey (void)  { 

    while (!(USART1->SR & USART_FLAG_RXNE));

    return ((int)(USART1->DR & 0x1FF));
}
#endif


#if 1

int sendchar(int ch)//Retarget.c 中int fgetc(FILE *f) 调用
{
    /*while(!(USART3->SR & USART_FLAG_TXE));
    USART3->DR = (ch & 0x1FF);

    return ch;*/
	 /* 清SR寄存器中的TC标志 */
		USART_ClearFlag(Printf_USARTx,USART_FLAG_TC);
	
	  USART_SendData(Printf_USARTx, (uint8_t) ch);


  while (USART_GetFlagStatus(Printf_USARTx, USART_FLAG_TC) == RESET)
  {}

  return ch;
}

int getkey(void)
{
    /*while(!(USART3->SR & USART_FLAG_RXNE));
    return ((int)(USART3->DR & 0X1FF));*/
	return 0;
}

void USARTx_IRQHANDLER(void)
{
  if(USART_GetITStatus(Printf_USARTx, USART_IT_RXNE) != RESET)
  { 
		printf("\n\rUSART1 Hyperterminal Interrupts Receive a word: %c\n\r",USART_ReceiveData(Printf_USARTx));
  }
}
#endif