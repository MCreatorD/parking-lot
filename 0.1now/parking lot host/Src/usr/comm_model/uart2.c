#include "uart2.h"
#include <string.h>

	u8 USART2_RX_BUF[USART2_RX_LEN];     //接收缓冲,最USART_RX_LEN个字节
	u8 USART2_TX_BUF[USART2_TX_LEN]; //发送缓冲,最大USART_TX_LEN个字节
	u8 USART2_RX_STA = 0;       //接收完成状态标记
	u8 USART2_TX_IDLE = 0; //发送空闲状态标记
	 
	u16 RX2_Posi = 0; //当前缓冲区接收位置
	u16 TX2_Posi = 0;
	u16 TX2_Len = 0;
	u16 RX2_Len = 0;

void USART2_NVIC_Config(void)
{
  NVIC_InitTypeDef NVIC_InitStructure;

  /* Enable the USARTx Interrupt */
  NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0              ;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);

}

void USART2_Configuration(void)
{ 												
  GPIO_InitTypeDef GPIO_InitStructure;
  USART_InitTypeDef USART_InitStructure; 

  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE); //发
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE); //收

  RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2,ENABLE);


  GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_USART2); //发
  GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_USART2); //收

  /*
  *  Open205R_USARTx_TX -> PA9 , Open205R_USARTx_RX -PA10
  */
	//先配置发送脚
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

	//再配置接收脚
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(GPIOA, &GPIO_InitStructure);


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

	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;

	
  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
  USART_Init(USART2, &USART_InitStructure);
  /* Enable the Open205R_USARTx Transmit interrupt: this interrupt is generated when the 
     Open205R_USARTx transmit data register is empty */
  USART_ITConfig(USART2,USART_IT_RXNE,ENABLE);
	
	//因Usart_SendData有问题，暂时关闭中断发送
	//USART_ITConfig(USART1, USART_IT_TC, ENABLE);//Tramsimssion Complete后，才产生中断. 开TC中断必须放在这里,否则还是会丢失第一字节

  USART_Cmd(USART2, ENABLE);
  USART2_NVIC_Config();
}

/**
*	注意：中断函数，不能写在C++类型的文件中，否则会失效，
*	会导致中断后，找不到中断函数
*/
//串口2中断服务程序
void USART2_IRQHandler(void)                  
{
	
	//接收
	u8 Res;

	if(USART_GetITStatus(USART2, USART_IT_RXNE) != RESET)  //接收中断
	{
		
		Res =USART_ReceiveData(USART2);
		
		//如缓存区为空则读取接收到的数据，否则放弃
		if(USART2_RX_STA==0){
			USART2_RX_BUF[RX2_Posi++]=Res; 
			if(RX2_Posi >= 10&&Res==0x7E)
			{
				RX2_Len = RX2_Posi;
				RX2_Posi = 0;
				USART2_RX_STA = 1;
				
			}
		}
	}
	
	//发送
	if( USART_GetITStatus(USART2, USART_IT_TC) == SET  )
	{
			if(TX2_Posi>=TX2_Len )
			{
				USART_ClearFlag(USART2, USART_FLAG_TC);//不然TC一直是set, TCIE也是打开的,导致会不停进入中断. clear掉即可,不用关掉TCIE
				TX2_Len = 0;
				USART2_TX_IDLE = 0;
			}else
			{
				//printf("TX1_Posi=%d\n",TX1_Posi);
				USART_SendData(USART2,USART2_TX_BUF[TX2_Posi++] );
			}
	}
}

int  USART2_SendData(unsigned char *buf,int buflen)
{
		int i;
		if(USART2_TX_IDLE==1){
			return -1;
		}
		
		USART2_TX_IDLE = 1;
		
		memcpy(USART2_TX_BUF,buf,buflen);
    TX2_Posi = 0;
		TX2_Len = buflen;
		
		/*printf("TX1_Len=%d\n",TX1_Len);
		
		for(i=0;i<TX1_Len;i++){
			printf("0x%02x,",USART1_TX_BUF[i]);
			
		}
		printf("\n");*/
  
    //USART_ClearFlag(USART1, USART_FLAG_TC);//清除传输完成标志位,否则可能会丢失第1个字节的数据.网友提供.
    
    //USART_SendData(USART1, USART1_TX_BUF[TX1_Posi++] ); //必须要++，不然会把第一个字符t发送两次
		
		//return 0;
		////////////////////////////////
		for(i=0;i<TX2_Len;i++){
			
			USART_SendData(USART2,USART2_TX_BUF[i] );
			while (USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET)
			{}
			//while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET){}
		}
		USART2_TX_IDLE = 0;
		return 0;
		//////////////////////////////////////
		/*u8 a = 'A';
		USART_SendData(USART1,a );
	  while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET)
		{}*/

}


void USART3_NVIC_Config(void)
{
  NVIC_InitTypeDef NVIC_InitStructure;

  /* Enable the USARTx Interrupt */
  NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);

}

void USART3_Configuration(void)
{ 												
  GPIO_InitTypeDef GPIO_InitStructure;
  USART_InitTypeDef USART_InitStructure; 

  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC,ENABLE); //发
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC,ENABLE); //收

  RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3,ENABLE);


  GPIO_PinAFConfig(GPIOC, GPIO_PinSource10, GPIO_AF_USART3); //发
  GPIO_PinAFConfig(GPIOC, GPIO_PinSource11, GPIO_AF_USART3); //收

  /*
  *  Open205R_USARTx_TX -> PA9 , Open205R_USARTx_RX -PA10
  */
	//先配置发送脚
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_Init(GPIOC, &GPIO_InitStructure);

	//再配置接收脚
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(GPIOC, &GPIO_InitStructure);


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

	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;

	
  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
  USART_Init(USART3, &USART_InitStructure);
  /* Enable the Open205R_USARTx Transmit interrupt: this interrupt is generated when the 
     Open205R_USARTx transmit data register is empty */
  USART_ITConfig(USART3,USART_IT_RXNE,ENABLE);
	
	//因Usart_SendData有问题，暂时关闭中断发送
	//USART_ITConfig(USART1, USART_IT_TC, ENABLE);//Tramsimssion Complete后，才产生中断. 开TC中断必须放在这里,否则还是会丢失第一字节

  USART_Cmd(USART3, ENABLE);
	USART3_NVIC_Config();
}

/**
*	注意：中断函数，不能写在C++类型的文件中，否则会失效，
*	会导致中断后，找不到中断函数
*/
//串口2中断服务程序
void USART3_IRQHandler(void)                  
{
	
	//接收
	u8 Res;

	if(USART_GetITStatus(USART3, USART_IT_RXNE) != RESET)  //接收中断
	{
		
		Res =USART_ReceiveData(USART3);
		
		//如缓存区为空则读取接收到的数据，否则放弃
		if(USART2_RX_STA==0){
			USART2_RX_BUF[RX2_Posi++]=Res; 
			if(RX2_Posi >= 10&&Res==0x7E)
			{
				RX2_Len = RX2_Posi;
				RX2_Posi = 0;
				USART2_RX_STA = 1;
				
			}
		}
	}
	
	//发送
	if( USART_GetITStatus(USART3, USART_IT_TC) == SET  )
	{
			if(TX2_Posi>=TX2_Len )
			{
				USART_ClearFlag(USART3, USART_FLAG_TC);//不然TC一直是set, TCIE也是打开的,导致会不停进入中断. clear掉即可,不用关掉TCIE
				TX2_Len = 0;
				USART2_TX_IDLE = 0;
			}else
			{
				//printf("TX1_Posi=%d\n",TX1_Posi);
				USART_SendData(USART3,USART2_TX_BUF[TX2_Posi++] );
			}
	}
}

int  USART3_SendData(unsigned char *buf,int buflen)
{
		int i;
		if(USART2_TX_IDLE==1){
			return -1;
		}
		
		USART2_TX_IDLE = 1;
		
		memcpy(USART2_TX_BUF,buf,buflen);
		TX2_Posi = 0;
		TX2_Len = buflen;
		
		/*printf("TX1_Len=%d\n",TX1_Len);
		
		for(i=0;i<TX1_Len;i++){
			printf("0x%02x,",USART1_TX_BUF[i]);
			
		}
		printf("\n");*/
  
    //USART_ClearFlag(USART1, USART_FLAG_TC);//清除传输完成标志位,否则可能会丢失第1个字节的数据.网友提供.
    
    //USART_SendData(USART1, USART1_TX_BUF[TX1_Posi++] ); //必须要++，不然会把第一个字符t发送两次
		
		//return 0;
		////////////////////////////////
		for(i=0;i<TX2_Len;i++){
			
			USART_SendData(USART3,USART2_TX_BUF[i] );
			while (USART_GetFlagStatus(USART3, USART_FLAG_TC) == RESET)
			{}
			//while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET){}
		}
		USART2_TX_IDLE = 0;
		return 0;
		//////////////////////////////////////
		/*u8 a = 'A';
		USART_SendData(USART1,a );
	  while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET)
		{}*/

}


