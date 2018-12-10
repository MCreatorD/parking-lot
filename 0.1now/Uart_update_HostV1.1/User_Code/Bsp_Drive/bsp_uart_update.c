#include "bsp_uart_update.h"
#include <string.h>
u8 DownLoad_USART_RX_BUF[DownLoad_USART_RX_LEN];     //接收缓冲,最USART_RX_LEN个字节
u8 DownLoad_USART_TX_BUF[DownLoad_USART_TX_LEN];    //发送缓冲,最大USART_TX_LEN个字节
u8 DownLoad_USART_RX_STA = 0;       //接收完成状态标记
u8 DownLoad_USART_TX_IDLE = 0; //发送空闲状态标记
	 
u16 DownLoad_RX_Posi = 0;      //当前缓冲区接收位置
u16 DownLoad_TX_Posi = 0;
u16 DownLoad_TX_Len  = 0;
u16 DownLoad_RX_Len  = 0;



void DownLoad_USART_NVIC_Config(void)
{
  NVIC_InitTypeDef NVIC_InitStructure;

  /* Enable the USARTx Interrupt */
  NVIC_InitStructure.NVIC_IRQChannel = DownLoad_USARTx_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);

}

/*******************************************************************************
* Function Name  : USART_Configuration
* Description    : Configure DownLoad_USARTx 
* Input          : None
* Output         : None
* Return         : None
* Attention		 : None
*******************************************************************************/
void DownLoad_USART_Configuration(void)
{ 												
  GPIO_InitTypeDef GPIO_InitStructure;
  USART_InitTypeDef USART_InitStructure; 

  RCC_AHB1PeriphClockCmd(DownLoad_USARTx_TX_GPIO_CLK,ENABLE);
  RCC_AHB1PeriphClockCmd(DownLoad_USARTx_RX_GPIO_CLK,ENABLE);

  #if defined DownLoadUSART1 || defined DownLoadUSART6
  	RCC_APB2PeriphClockCmd(DownLoad_USARTx_CLK,ENABLE);
  #else
	RCC_APB1PeriphClockCmd(DownLoad_USARTx_CLK,ENABLE);
  #endif

  GPIO_PinAFConfig(DownLoad_USARTx_TX_GPIO_PORT, DownLoad_USARTx_TX_SOURCE, DownLoad_USARTx_TX_AF);
  GPIO_PinAFConfig(DownLoad_USARTx_RX_GPIO_PORT, DownLoad_USARTx_RX_SOURCE, DownLoad_USARTx_RX_AF);

  /*
  *  DownLoad_USARTx_TX -> PA9 , DownLoad_USARTx_RX -PA10
  */
  GPIO_InitStructure.GPIO_Pin = DownLoad_USARTx_TX_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_Init(DownLoad_USARTx_TX_GPIO_PORT, &GPIO_InitStructure);


  GPIO_InitStructure.GPIO_Pin = DownLoad_USARTx_RX_PIN;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_Init(DownLoad_USARTx_RX_GPIO_PORT, &GPIO_InitStructure);

  #if defined HwFlowControl && !defined DownLoadUART4 && !defined DownLoadUART5 
  	RCC_AHB1PeriphClockCmd(DownLoad_USARTx_RTS_GPIO_CLK,ENABLE);
	RCC_AHB1PeriphClockCmd(DownLoad_USARTx_CTS_GPIO_CLK,ENABLE);
	
	GPIO_PinAFConfig(DownLoad_USARTx_RTS_GPIO_PORT, DownLoad_USARTx_RTS_SOURCE, DownLoad_USARTx_RTS_AF);
	GPIO_PinAFConfig(DownLoad_USARTx_CTS_GPIO_PORT, DownLoad_USARTx_CTS_SOURCE, DownLoad_USARTx_CTS_AF);

	GPIO_InitStructure.GPIO_Pin = DownLoad_USARTx_RTS_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(DownLoad_USARTx_RTS_GPIO_PORT, &GPIO_InitStructure);
	
	
	GPIO_InitStructure.GPIO_Pin   =   DownLoad_USARTx_CTS_PIN;
	GPIO_InitStructure.GPIO_OType =   GPIO_OType_OD;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(DownLoad_USARTx_CTS_GPIO_PORT, &GPIO_InitStructure);
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
  #if defined HwFlowControl && !defined DownLoadUART4 && !defined DownLoadUART5
  	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_RTS_CTS;
  #else
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
  #endif
	
  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
  USART_Init(DownLoad_USARTx, &USART_InitStructure);
  /* Enable the DownLoad_USARTx Transmit interrupt: this interrupt is generated when the 
     DownLoad_USARTx transmit data register is empty */
 // USART_ITConfig(DownLoad_USARTx,USART_IT_RXNE,ENABLE);

  USART_Cmd(DownLoad_USARTx, ENABLE);
  USART_ClearFlag(DownLoad_USARTx,USART_FLAG_TC); //解决第一个字节丢失问题
	
	//配置中断
 // DownLoad_USART_NVIC_Config();

}

int DownLoadUSARTx_SendData(unsigned char *buf,int buflen)
{
		int i;
		if(DownLoad_USART_TX_IDLE==1){
			return -1;
		}
		
		DownLoad_USART_TX_IDLE = 1;
		
		memcpy(DownLoad_USART_TX_BUF,buf,buflen);
		DownLoad_TX_Posi = 0;
		DownLoad_TX_Len = buflen;
		
		for(i=0;i<DownLoad_TX_Len;i++){
			
			USART_SendData(DownLoad_USARTx,DownLoad_USART_TX_BUF[i] );
			while (USART_GetFlagStatus(DownLoad_USARTx, USART_FLAG_TC) == RESET)
			{}
			//while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET){}
		}
		DownLoad_USART_TX_IDLE = 0;
		return 0;
		//////////////////////////////////////


}
#if 0
void DownLoadUSARTx_IRQHANDLER(void)
{	
	//接收
	u8 Res;

	if(USART_GetITStatus(DownLoad_USARTx, USART_IT_RXNE) != RESET)  //接收中断
	{
		
		Res =USART_ReceiveData(DownLoad_USARTx);
		
		//如缓存区为空则读取接收到的数据，否则放弃
		if(DownLoad_USART_RX_STA==0){
			DownLoad_USART_RX_BUF[DownLoad_RX_Posi++]=Res; 
//			if(DownLoad_RX_Posi >= 10&&Res==0x7E)
//			{
//				DownLoad_RX_Len = DownLoad_RX_Posi;
//				DownLoad_RX_Posi = 0;
//				DownLoad_USART_RX_STA = 1;
//				
//			}
		}
	}
	
	//发送
	if( USART_GetITStatus(DownLoad_USARTx, USART_IT_TC) == SET  )
	{
			if(DownLoad_TX_Posi>=DownLoad_TX_Len )
			{
				USART_ClearFlag(DownLoad_USARTx, USART_FLAG_TC);//不然TC一直是set, TCIE也是打开的,导致会不停进入中断. clear掉即可,不用关掉TCIE
				DownLoad_TX_Len = 0;
				DownLoad_USART_TX_IDLE = 0;
			}else
			{
				//printf("TX1_Posi=%d\n",TX1_Posi);
				USART_SendData(DownLoad_USARTx,DownLoad_USART_TX_BUF[DownLoad_TX_Posi++] );
			}
	}
}

#endif
