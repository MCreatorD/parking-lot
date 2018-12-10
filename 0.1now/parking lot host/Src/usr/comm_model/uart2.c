#include "uart2.h"
#include <string.h>

	u8 USART2_RX_BUF[USART2_RX_LEN];     //���ջ���,��USART_RX_LEN���ֽ�
	u8 USART2_TX_BUF[USART2_TX_LEN]; //���ͻ���,���USART_TX_LEN���ֽ�
	u8 USART2_RX_STA = 0;       //�������״̬���
	u8 USART2_TX_IDLE = 0; //���Ϳ���״̬���
	 
	u16 RX2_Posi = 0; //��ǰ����������λ��
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

  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE); //��
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE); //��

  RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2,ENABLE);


  GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_USART2); //��
  GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_USART2); //��

  /*
  *  Open205R_USARTx_TX -> PA9 , Open205R_USARTx_RX -PA10
  */
	//�����÷��ͽ�
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

	//�����ý��ս�
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
	
	//��Usart_SendData�����⣬��ʱ�ر��жϷ���
	//USART_ITConfig(USART1, USART_IT_TC, ENABLE);//Tramsimssion Complete�󣬲Ų����ж�. ��TC�жϱ����������,�����ǻᶪʧ��һ�ֽ�

  USART_Cmd(USART2, ENABLE);
  USART2_NVIC_Config();
}

/**
*	ע�⣺�жϺ���������д��C++���͵��ļ��У������ʧЧ��
*	�ᵼ���жϺ��Ҳ����жϺ���
*/
//����2�жϷ������
void USART2_IRQHandler(void)                  
{
	
	//����
	u8 Res;

	if(USART_GetITStatus(USART2, USART_IT_RXNE) != RESET)  //�����ж�
	{
		
		Res =USART_ReceiveData(USART2);
		
		//�绺����Ϊ�����ȡ���յ������ݣ��������
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
	
	//����
	if( USART_GetITStatus(USART2, USART_IT_TC) == SET  )
	{
			if(TX2_Posi>=TX2_Len )
			{
				USART_ClearFlag(USART2, USART_FLAG_TC);//��ȻTCһֱ��set, TCIEҲ�Ǵ򿪵�,���»᲻ͣ�����ж�. clear������,���ùص�TCIE
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
  
    //USART_ClearFlag(USART1, USART_FLAG_TC);//���������ɱ�־λ,������ܻᶪʧ��1���ֽڵ�����.�����ṩ.
    
    //USART_SendData(USART1, USART1_TX_BUF[TX1_Posi++] ); //����Ҫ++����Ȼ��ѵ�һ���ַ�t��������
		
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

  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC,ENABLE); //��
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC,ENABLE); //��

  RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3,ENABLE);


  GPIO_PinAFConfig(GPIOC, GPIO_PinSource10, GPIO_AF_USART3); //��
  GPIO_PinAFConfig(GPIOC, GPIO_PinSource11, GPIO_AF_USART3); //��

  /*
  *  Open205R_USARTx_TX -> PA9 , Open205R_USARTx_RX -PA10
  */
	//�����÷��ͽ�
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_Init(GPIOC, &GPIO_InitStructure);

	//�����ý��ս�
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
	
	//��Usart_SendData�����⣬��ʱ�ر��жϷ���
	//USART_ITConfig(USART1, USART_IT_TC, ENABLE);//Tramsimssion Complete�󣬲Ų����ж�. ��TC�жϱ����������,�����ǻᶪʧ��һ�ֽ�

  USART_Cmd(USART3, ENABLE);
	USART3_NVIC_Config();
}

/**
*	ע�⣺�жϺ���������д��C++���͵��ļ��У������ʧЧ��
*	�ᵼ���жϺ��Ҳ����жϺ���
*/
//����2�жϷ������
void USART3_IRQHandler(void)                  
{
	
	//����
	u8 Res;

	if(USART_GetITStatus(USART3, USART_IT_RXNE) != RESET)  //�����ж�
	{
		
		Res =USART_ReceiveData(USART3);
		
		//�绺����Ϊ�����ȡ���յ������ݣ��������
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
	
	//����
	if( USART_GetITStatus(USART3, USART_IT_TC) == SET  )
	{
			if(TX2_Posi>=TX2_Len )
			{
				USART_ClearFlag(USART3, USART_FLAG_TC);//��ȻTCһֱ��set, TCIEҲ�Ǵ򿪵�,���»᲻ͣ�����ж�. clear������,���ùص�TCIE
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
  
    //USART_ClearFlag(USART1, USART_FLAG_TC);//���������ɱ�־λ,������ܻᶪʧ��1���ֽڵ�����.�����ṩ.
    
    //USART_SendData(USART1, USART1_TX_BUF[TX1_Posi++] ); //����Ҫ++����Ȼ��ѵ�һ���ַ�t��������
		
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


