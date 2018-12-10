#include "RX485_uart.h"
#include <string.h>
#include "rx485_rev.h"
#include "rx485_send.h"
#include "communication.h"
u8 RX485_USART_RX_BUF[RX485_USART_RX_LEN];     //接收缓冲,最USART_RX_LEN个字节
u8 RX485_USART_TX_BUF[RX485_USART_TX_LEN];     //发送缓冲,最大USART_TX_LEN个字节
u8 RX485_USART_RX_STA = 0;       //接收完成状态标记
u8 RX485_USART_TX_IDLE = 0;      //发送空闲状态标记
	 
u16 RX485_RX_Posi = 0; //当前缓冲区接收位置
u16 RX485_TX_Posi = 0; //当前缓冲区发送位置
u16 RX485_TX_Len = 0;  //需要发送的数据长度
u16 RX485_RX_Len = 0;  //接收到的数据长度

void RX485_USART_NVIC_Config(void)
{
  NVIC_InitTypeDef NVIC_InitStructure;

  /* Enable the USARTx Interrupt */
  NVIC_InitStructure.NVIC_IRQChannel = RX485_USARTx_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);

}

/*******************************************************************************
* Function Name  : USART_Configuration
* Description    : Configure RX485_USARTx 
* Input          : None
* Output         : None
* Return         : None
* Attention		 : None
*******************************************************************************/
void RX485_USART_Configuration(void)
{ 												
  GPIO_InitTypeDef GPIO_InitStructure;
  USART_InitTypeDef USART_InitStructure; 

  RCC_AHB1PeriphClockCmd(RX485_USARTx_TX_GPIO_CLK,ENABLE);
  RCC_AHB1PeriphClockCmd(RX485_USARTx_RX_GPIO_CLK,ENABLE);

  #if defined RX485USART1 || defined RX485USART6
  	RCC_APB2PeriphClockCmd(RX485_USARTx_CLK,ENABLE);
  #else
	RCC_APB1PeriphClockCmd(RX485_USARTx_CLK,ENABLE);
  #endif

  GPIO_PinAFConfig(RX485_USARTx_TX_GPIO_PORT, RX485_USARTx_TX_SOURCE, RX485_USARTx_TX_AF);
  GPIO_PinAFConfig(RX485_USARTx_RX_GPIO_PORT, RX485_USARTx_RX_SOURCE, RX485_USARTx_RX_AF);

  /*
  *  RX485_USARTx_TX -> PA9 , RX485_USARTx_RX -PA10
  */
  GPIO_InitStructure.GPIO_Pin = RX485_USARTx_TX_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_Init(RX485_USARTx_TX_GPIO_PORT, &GPIO_InitStructure);


  GPIO_InitStructure.GPIO_Pin = RX485_USARTx_RX_PIN;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_Init(RX485_USARTx_RX_GPIO_PORT, &GPIO_InitStructure);

  #if defined HwFlowControl && !defined RX485UART4 && !defined RX485UART5 
  	RCC_AHB1PeriphClockCmd(RX485_USARTx_RTS_GPIO_CLK,ENABLE);
	RCC_AHB1PeriphClockCmd(RX485_USARTx_CTS_GPIO_CLK,ENABLE);
	
	GPIO_PinAFConfig(RX485_USARTx_RTS_GPIO_PORT, RX485_USARTx_RTS_SOURCE, RX485_USARTx_RTS_AF);
	GPIO_PinAFConfig(RX485_USARTx_CTS_GPIO_PORT, RX485_USARTx_CTS_SOURCE, RX485_USARTx_CTS_AF);

	GPIO_InitStructure.GPIO_Pin = RX485_USARTx_RTS_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(RX485_USARTx_RTS_GPIO_PORT, &GPIO_InitStructure);
	
	
	GPIO_InitStructure.GPIO_Pin   =   RX485_USARTx_CTS_PIN;
	GPIO_InitStructure.GPIO_OType =   GPIO_OType_OD;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(RX485_USARTx_CTS_GPIO_PORT, &GPIO_InitStructure);
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

  USART_InitStructure.USART_BaudRate = 1800000;
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
  USART_InitStructure.USART_StopBits = USART_StopBits_1;
  USART_InitStructure.USART_Parity = USART_Parity_No;
  #if defined HwFlowControl && !defined RX485UART4 && !defined RX485UART5
  	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_RTS_CTS;
  #else
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
  #endif
	
  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
  USART_Init(RX485_USARTx, &USART_InitStructure);
  /* Enable the RX485_USARTx Transmit interrupt: this interrupt is generated when the 
     RX485_USARTx transmit data register is empty */
  USART_ITConfig(RX485_USARTx,USART_IT_RXNE,ENABLE);
  USART_Cmd(RX485_USARTx, ENABLE);
  while(USART_GetFlagStatus(RX485_USARTx, USART_FLAG_TC)==RESET);//
  RX485_USART_NVIC_Config();
	
	RS485_IO_Init();

}

void RS485_IO_Init(void)//485 收发控制脚
{
	 GPIO_InitTypeDef  GPIO_InitStructure;
		
	 RCC_AHB1PeriphClockCmd(RS485_RX_EN_CLK, ENABLE);	         //使能PB端口时钟
		
	 GPIO_InitStructure.GPIO_Pin   = RS485_RX_EN_PIN;				   //LED0-->PB.5 端口配置
	 GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;        //输出模式  
	 GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;        //推挽输出
	 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;  
	 GPIO_InitStructure.GPIO_PuPd  =  GPIO_PuPd_DOWN;      //下拉
	 GPIO_Init(RS485_RX_EN_Port, &GPIO_InitStructure);					       //根据设定参数初始化GPIOB.1
	// GPIO_ResetBits(RS485_RX_EN_Port,RS485_RX_EN_PIN);						 //PB.1 输出低 灯灭

	//-----------------------------------------------------------	
	 RCC_AHB1PeriphClockCmd(RS485_TX_EN_CLK, ENABLE);	         //使能PB端口时钟
		
	 GPIO_InitStructure.GPIO_Pin   = RS485_TX_EN_PIN;				   //LED0-->PB.5 端口配置
	 GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;        //输出模式  
	 GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;        //推挽输出
	 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;  
	 GPIO_InitStructure.GPIO_PuPd  =  GPIO_PuPd_DOWN;      //下拉
	 GPIO_Init(RS485_TX_EN_Port, &GPIO_InitStructure);					       //根据设定参数初始化GPIOB.1
	 //GPIO_ResetBits(RS485_TX_EN_Port,RS485_RX_EN_PIN);						 //PB.1 输出低 灯灭
	RS485_TX_L; //DE
	RS485_RX_L; //REn	
}

void rs_485_send(unsigned char *buf,int buflen)
{
	RS485_TX_H;
	RS485_RX_H;
	//1 .发
	RX485USARTx_SendData(buf,buflen);
  //2 .收
	RS485_TX_L; //DE
	RS485_RX_L; //REn		
}



int RX485USARTx_SendData(unsigned char *buf,int buflen)
{
		int i;
		if(RX485_USART_TX_IDLE==1){
			return -1;
		}
		
		RX485_USART_TX_IDLE = 1;
		RS485_TX_H;
	  RS485_RX_H;
		
		memcpy(RX485_USART_TX_BUF,buf,buflen);
		RX485_TX_Posi = 0;
		RX485_TX_Len = buflen;
		
		for(i=0;i<RX485_TX_Len;i++){
			
			USART_SendData(RX485_USARTx,RX485_USART_TX_BUF[i] );
			while (USART_GetFlagStatus(RX485_USARTx, USART_FLAG_TC) == RESET)
			{}
			//while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET){}
		}
		RX485_USART_TX_IDLE = 0;
		RS485_TX_L; //DE
	    RS485_RX_L; //REn		
		return 0;
		//////////////////////////////////////


}

void DealRs485Message()
{
	if(RX485_USART_RX_STA == 1)
	{
		//RX485_recvCommData(RX485_USART_RX_BUF,RX485_RX_Len);
		if(RX485_recvCommData(RX485_USART_RX_BUF,RX485_RX_Len) == 1)
		{
			MessageDeal(RxMessage,RX485_recFrameLen);//消息体还包含开头的地址信息
		}		
			memset(RX485_USART_RX_BUF,0,RX485_RX_Len);
	}	
}


void RX485USARTx_IRQHANDLER(void)
{	
	//接收
	u8 Res;

	if(USART_GetITStatus(RX485_USARTx, USART_IT_RXNE) != RESET)  //接收中断
	{
		
		Res =USART_ReceiveData(RX485_USARTx);
		
		//如缓存区为空则读取接收到的数据，否则放弃
		if(RX485_USART_RX_STA==0){
			RX485_USART_RX_BUF[RX485_RX_Posi++]=Res; 
			if( RX485_USART_RX_BUF[0]==0x7E)
			{
				if(RX485_RX_Posi >= 4&&Res==0x7E)
				{
					RX485_RX_Len = RX485_RX_Posi;
					RX485_RX_Posi = 0;
					RX485_USART_RX_STA = 1;
					
				}				
			}else{
				RX485_USART_RX_STA = 0;
				RX485_RX_Posi = 0;
			}
		}
		if(RX485_USART_RX_STA == 1)
		{
			//RX485_recvCommData(RX485_USART_RX_BUF,RX485_RX_Len);
			if(RX485_recvCommData(RX485_USART_RX_BUF,RX485_RX_Len) == 1)
			{
				MessageDeal(RxMessage,RX485_recFrameLen);//消息体还包含开头的地址信息
			}		
				memset(RX485_USART_RX_BUF,0,RX485_RX_Len);
		}

	}
	
	//发送
//	if( USART_GetITStatus(RX485_USARTx, USART_IT_TC) == SET  )
//	{
//			if(RX485_TX_Posi>=RX485_TX_Len )
//			{
//				USART_ClearFlag(RX485_USARTx, USART_FLAG_TC);//不然TC一直是set, TCIE也是打开的,导致会不停进入中断. clear掉即可,不用关掉TCIE
//				RX485_TX_Len = 0;
//				RX485_USART_TX_IDLE = 0;
//			}else
//			{
//				//printf("TX1_Posi=%d\n",TX1_Posi);
//				USART_SendData(RX485_USARTx,RX485_USART_TX_BUF[RX485_TX_Posi++] );
//			}
//	}
}

