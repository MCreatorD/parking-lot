#include "uart_bsp_comm.h"
//#include "config.h"
u8 Comm_USART_RX_BUF[Comm_USART_RX_LEN];     //接收缓冲,最USART_RX_LEN个字节
u8 Comm_USART_TX_BUF[Comm_USART_TX_LEN];    //发送缓冲,最大USART_TX_LEN个字节
u8 Comm_USART_RX_STA = 0;       //接收完成状态标记
u8 Comm_USART_TX_IDLE = 0; //发送空闲状态标记
	 
u16 Comm_RX_Posi = 0; //当前缓冲区接收位置
u16 Comm_TX_Posi = 0;
u16 Comm_TX_Len = 0;
u16 Comm_RX_Len = 0;



void Comm_USART_NVIC_Config(void)
{
  NVIC_InitTypeDef NVIC_InitStructure;

  /* Enable the USARTx Interrupt */
  NVIC_InitStructure.NVIC_IRQChannel = Comm_USARTx_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);

}

/*******************************************************************************
* Function Name  : USART_Configuration
* Description    : Configure Comm_USARTx 
* Input          : None
* Output         : None
* Return         : None
* Attention		 : None
*******************************************************************************/
void Comm_USART_Configuration(void)
{ 												
  GPIO_InitTypeDef GPIO_InitStructure;
  USART_InitTypeDef USART_InitStructure; 

  RCC_AHB1PeriphClockCmd(Comm_USARTx_TX_GPIO_CLK,ENABLE);
  RCC_AHB1PeriphClockCmd(Comm_USARTx_RX_GPIO_CLK,ENABLE);

  #if defined CommUSART1 || defined CommUSART6
  	RCC_APB2PeriphClockCmd(Comm_USARTx_CLK,ENABLE);
  #else
	RCC_APB1PeriphClockCmd(Comm_USARTx_CLK,ENABLE);
  #endif

  GPIO_PinAFConfig(Comm_USARTx_TX_GPIO_PORT, Comm_USARTx_TX_SOURCE, Comm_USARTx_TX_AF);
  GPIO_PinAFConfig(Comm_USARTx_RX_GPIO_PORT, Comm_USARTx_RX_SOURCE, Comm_USARTx_RX_AF);

  /*
  *  Comm_USARTx_TX -> PA9 , Comm_USARTx_RX -PA10
  */
  GPIO_InitStructure.GPIO_Pin = Comm_USARTx_TX_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_Init(Comm_USARTx_TX_GPIO_PORT, &GPIO_InitStructure);


  GPIO_InitStructure.GPIO_Pin = Comm_USARTx_RX_PIN;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_Init(Comm_USARTx_RX_GPIO_PORT, &GPIO_InitStructure);

  #if defined HwFlowControl && !defined CommUART4 && !defined CommUART5 
  	RCC_AHB1PeriphClockCmd(Comm_USARTx_RTS_GPIO_CLK,ENABLE);
	RCC_AHB1PeriphClockCmd(Comm_USARTx_CTS_GPIO_CLK,ENABLE);
	
	GPIO_PinAFConfig(Comm_USARTx_RTS_GPIO_PORT, Comm_USARTx_RTS_SOURCE, Comm_USARTx_RTS_AF);
	GPIO_PinAFConfig(Comm_USARTx_CTS_GPIO_PORT, Comm_USARTx_CTS_SOURCE, Comm_USARTx_CTS_AF);

	GPIO_InitStructure.GPIO_Pin = Comm_USARTx_RTS_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(Comm_USARTx_RTS_GPIO_PORT, &GPIO_InitStructure);
	
	
	GPIO_InitStructure.GPIO_Pin   =   Comm_USARTx_CTS_PIN;
	GPIO_InitStructure.GPIO_OType =   GPIO_OType_OD;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(Comm_USARTx_CTS_GPIO_PORT, &GPIO_InitStructure);
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

  USART_InitStructure.USART_BaudRate = 115200;//115200  921600  921600 20000000
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
  USART_InitStructure.USART_StopBits = USART_StopBits_1;
  USART_InitStructure.USART_Parity = USART_Parity_No;
  #if defined HwFlowControl && !defined CommUART4 && !defined CommUART5
  	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_RTS_CTS;
  #else
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
  #endif
	
  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
  USART_Init(Comm_USARTx, &USART_InitStructure);
  /* Enable the Comm_USARTx Transmit interrupt: this interrupt is generated when the 
     Comm_USARTx transmit data register is empty */
  USART_ITConfig(Comm_USARTx,USART_IT_RXNE,ENABLE);

  USART_Cmd(Comm_USARTx, ENABLE);
  while(USART_GetFlagStatus(Comm_USARTx, USART_FLAG_TC)==RESET);//解决第一个字节丢失问题
  Comm_USART_NVIC_Config();
	//第一个字节发送丢失问题
   //USART_ClearFlag(USART3, USART_FLAG_TC); /*清发送完成标志，Transmission Complete flag */

}

int CommUSARTx_SendData(unsigned char *buf,int buflen)
{
		int i;
		if(Comm_USART_TX_IDLE==1){
			return -1;
		}
		
		Comm_USART_TX_IDLE = 1;
		
		memcpy(Comm_USART_TX_BUF,buf,buflen);
		Comm_TX_Posi = 0;
		Comm_TX_Len = buflen;
		
		for(i=0;i<Comm_TX_Len;i++){
			
			USART_SendData(Comm_USARTx,Comm_USART_TX_BUF[i] );
			while (USART_GetFlagStatus(Comm_USARTx, USART_FLAG_TC) == RESET)
			{}
			//while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET){}
		}
		Comm_USART_TX_IDLE = 0;
		return 0;
		//////////////////////////////////////


}

void CommUSARTx_IRQHANDLER(void)
{	
	//接收
	u8 Res;

	if(USART_GetITStatus(Comm_USARTx, USART_IT_RXNE) != RESET)  //接收中断
	{
		
		Res =USART_ReceiveData(Comm_USARTx);
		
		//如缓存区为空则读取接收到的数据，否则放弃
		if(Comm_USART_RX_STA==0){
			Comm_USART_RX_BUF[Comm_RX_Posi++]=Res; 
			if(Comm_RX_Posi >= 10&&Res==0x7E)
			{
				Comm_RX_Len = Comm_RX_Posi;
				Comm_RX_Posi = 0;
				Comm_USART_RX_STA = 1;
				
			}
		}
	}
	
	//发送
	if( USART_GetITStatus(Comm_USARTx, USART_IT_TC) == SET  )
	{
			if(Comm_TX_Posi>=Comm_TX_Len )
			{
				USART_ClearFlag(Comm_USARTx, USART_FLAG_TC);//不然TC一直是set, TCIE也是打开的,导致会不停进入中断. clear掉即可,不用关掉TCIE
				Comm_TX_Len = 0;
				Comm_USART_TX_IDLE = 0;
			}else
			{
				//printf("TX1_Posi=%d\n",TX1_Posi);
				USART_SendData(Comm_USARTx,Comm_USART_TX_BUF[Comm_TX_Posi++] );
			}
	}
}