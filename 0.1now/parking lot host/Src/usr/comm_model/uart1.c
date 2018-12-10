#include "uart1.h"
#include <string.h>

	u8 USART1_RX_BUF[USART_RX_LEN];     //���ջ���,��USART_RX_LEN���ֽ�
	u8 USART1_TX_BUF[USART_TX_LEN]; //���ͻ���,���USART_TX_LEN���ֽ�
	u8 USART1_RX_STA = 0;       //�������״̬���
	u8 USART1_TX_IDLE = 0; //���Ϳ���״̬���
	 
	u16 RX1_Posi = 0; //��ǰ����������λ��
	u16 TX1_Posi = 0;
	u16 TX1_Len = 0;
	u16 RX1_Len = 0;

void USART1_NVIC_Config(void)
{
  NVIC_InitTypeDef NVIC_InitStructure;

  /* Enable the USARTx Interrupt */
  NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);

}

void USART1_Configuration(void)
{ 												
  GPIO_InitTypeDef GPIO_InitStructure;
  USART_InitTypeDef USART_InitStructure; 

  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE); //��
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE); //��

  RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);


  GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_USART1);
  GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_USART1);

  /*
  *  Open205R_USARTx_TX -> PA9 , Open205R_USARTx_RX -PA10
  */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_Init(GPIOA, &GPIO_InitStructure);


  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
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
  USART_Init(USART1, &USART_InitStructure);
  /* Enable the Open205R_USARTx Transmit interrupt: this interrupt is generated when the 
     Open205R_USARTx transmit data register is empty */
  USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);
	
	//��Usart_SendData�����⣬��ʱ�ر��жϷ���
	//USART_ITConfig(USART1, USART_IT_TC, ENABLE);//Tramsimssion Complete�󣬲Ų����ж�. ��TC�жϱ����������,�����ǻᶪʧ��һ�ֽ�

  USART_Cmd(USART1, ENABLE);

}

/**
*	ע�⣺�жϺ���������д��C++���͵��ļ��У������ʧЧ��
*	�ᵼ���жϺ��Ҳ����жϺ���
*/
/*void USART1_IRQHandler(void)
{
  if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)
  { 
		//USART_ReceiveData(USART1);
		printf("\n\rUSART1 Interrupts Receive a word: %c\n\r",USART_ReceiveData(USART1));
  }
}*/

//����1�жϷ������
void USART1_IRQHandler(void)                  
{
	
	//����
	u8 Res;

	if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)  //�����ж�(���յ������ݱ�����0x0d 0x0a��β)
	{
		
		Res =USART_ReceiveData(USART1);
		
		//�绺����Ϊ�����ȡ���յ������ݣ��������
		if(USART1_RX_STA==0){
			USART1_RX_BUF[RX1_Posi++]=Res; 
			if(RX1_Posi >= 10&&Res==0x7E)
			{
				RX1_Len = RX1_Posi;
				RX1_Posi = 0;
				USART1_RX_STA = 1;
				
			}
		}
	}
	
	//����
	if( USART_GetITStatus(USART1, USART_IT_TC) == SET  )
	{
			if(TX1_Posi>=TX1_Len )
			{
				USART_ClearFlag(USART1, USART_FLAG_TC);//��ȻTCһֱ��set, TCIEҲ�Ǵ򿪵�,���»᲻ͣ�����ж�. clear������,���ùص�TCIE
				TX1_Len = 0;
				USART1_TX_IDLE = 0;
			}else
			{
				//printf("TX1_Posi=%d\n",TX1_Posi);
				USART_SendData(USART1,USART1_TX_BUF[TX1_Posi++] );
			}
	}
}

int  USART1_SendData(unsigned char *buf,int buflen)
{
		int i;
		if(USART1_TX_IDLE==1){
			return -1;
		}
		
		USART1_TX_IDLE = 1;
		
		memcpy(USART1_TX_BUF,buf,buflen);
    TX1_Posi = 0;
		TX1_Len = buflen;
		
		/*printf("TX1_Len=%d\n",TX1_Len);
		
		for(i=0;i<TX1_Len;i++){
			printf("0x%02x,",USART1_TX_BUF[i]);
			
		}
		printf("\n");*/
  
    //USART_ClearFlag(USART1, USART_FLAG_TC);//���������ɱ�־λ,������ܻᶪʧ��1���ֽڵ�����.�����ṩ.
    
    //USART_SendData(USART1, USART1_TX_BUF[TX1_Posi++] ); //����Ҫ++����Ȼ��ѵ�һ���ַ�t��������
		
		//return 0;
		////////////////////////////////
		for(i=0;i<TX1_Len;i++){
			
			USART_SendData(USART1,USART1_TX_BUF[i] );
			while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET)
			{}
			//while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET){}
		}
		USART1_TX_IDLE = 0;
		return 0;
		//////////////////////////////////////
		/*u8 a = 'A';
		USART_SendData(USART1,a );
	  while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET)
		{}*/

}

