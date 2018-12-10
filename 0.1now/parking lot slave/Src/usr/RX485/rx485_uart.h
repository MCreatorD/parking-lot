#ifndef __RX485_UART_H
#define __RX485_UART_H
#include "stm32f2xx.h"
/*--------------------USART----------------------------*/
//#define RX485USART1
//#define RX485USART2
#define RX485USART3
//#define RX485USART4
//#define RX485USART5

#ifdef RX485USART1  
	#define RX485_USARTx                        	USART1	
	
	#define RX485_USARTx_CLK                    	RCC_APB2Periph_USART1
	
	#define RX485_USARTx_TX_PIN                 	GPIO_Pin_9
	#define RX485_USARTx_TX_GPIO_PORT           	GPIOA
	#define RX485_USARTx_TX_GPIO_CLK            	RCC_AHB1Periph_GPIOA
	#define RX485_USARTx_TX_SOURCE              	GPIO_PinSource9
	#define RX485_USARTx_TX_AF                  	GPIO_AF_USART1
	
	#define RX485_USARTx_RX_PIN                 	GPIO_Pin_10
	#define RX485_USARTx_RX_GPIO_PORT           	GPIOA
	#define RX485_USARTx_RX_GPIO_CLK            	RCC_AHB1Periph_GPIOA
	#define RX485_USARTx_RX_SOURCE              	GPIO_PinSource10
	#define RX485_USARTx_RX_AF                  	GPIO_AF_USART1
	
	#define RX485_USARTx_CTS_PIN                 GPIO_Pin_11
	#define RX485_USARTx_CTS_GPIO_PORT           GPIOA
	#define RX485_USARTx_CTS_GPIO_CLK            RCC_AHB1Periph_GPIOA
	#define RX485_USARTx_CTS_SOURCE              GPIO_PinSource11
	#define RX485_USARTx_CTS_AF                  GPIO_AF_USART1
	
	#define RX485_USARTx_RTS_PIN                 GPIO_Pin_12
	#define RX485_USARTx_RTS_GPIO_PORT           GPIOA
	#define RX485_USARTx_RTS_GPIO_CLK            RCC_AHB1Periph_GPIOA
	#define RX485_USARTx_RTS_SOURCE              GPIO_PinSource12
	#define RX485_USARTx_RTS_AF                  GPIO_AF_USART1
	
	#define RX485_USARTx_IRQn                   	USART1_IRQn
	#define RX485USARTx_SendData					USART1_SendData
	#define RX485USARTx_IRQHANDLER   USART1_IRQHandler	
#endif

#ifdef RX485USART2
	#define RX485_USARTx                        	USART2
	#define RX485_USARTx_CLK                    	RCC_APB1Periph_USART2
	
	#define RX485_USARTx_TX_PIN                 	GPIO_Pin_2
	#define RX485_USARTx_TX_GPIO_PORT           	GPIOA
	#define RX485_USARTx_TX_GPIO_CLK            	RCC_AHB1Periph_GPIOA
	#define RX485_USARTx_TX_SOURCE              	GPIO_PinSource2
	#define RX485_USARTx_TX_AF                  	GPIO_AF_USART2
	
	
	#define RX485_USARTx_RX_PIN                 	GPIO_Pin_3
	#define RX485_USARTx_RX_GPIO_PORT           	GPIOA
	#define RX485_USARTx_RX_GPIO_CLK            	RCC_AHB1Periph_GPIOA
	#define RX485_USARTx_RX_SOURCE              	GPIO_PinSource3
	#define RX485_USARTx_RX_AF                  	GPIO_AF_USART2
	
	#define RX485_USARTx_CTS_PIN                 GPIO_Pin_3
	#define RX485_USARTx_CTS_GPIO_PORT           GPIOD
	#define RX485_USARTx_CTS_GPIO_CLK            RCC_AHB1Periph_GPIOD
	#define RX485_USARTx_CTS_SOURCE              GPIO_PinSource3
	#define RX485_USARTx_CTS_AF                  GPIO_AF_USART2
	
	#define RX485_USARTx_RTS_PIN                 GPIO_Pin_4
	#define RX485_USARTx_RTS_GPIO_PORT           GPIOD
	#define RX485_USARTx_RTS_GPIO_CLK            RCC_AHB1Periph_GPIOD
	#define RX485_USARTx_RTS_SOURCE              GPIO_PinSource4
	#define RX485_USARTx_RTS_AF                  GPIO_AF_USART2
	
	#define RX485_USARTx_IRQn                    USART2_IRQn
	#define RX485USARTx_SendData				   USART2_SendData
	#define RX485USARTx_IRQHANDLER   			   USART2_IRQHandler	
#endif

#ifdef RX485USART3
	#define RX485_USARTx                        	USART3
	#define RX485_USARTx_CLK                    	RCC_APB1Periph_USART3
	
	#define RX485_USARTx_TX_PIN                 	GPIO_Pin_10
	#define RX485_USARTx_TX_GPIO_PORT           	GPIOB
	#define RX485_USARTx_TX_GPIO_CLK            	RCC_AHB1Periph_GPIOB
	#define RX485_USARTx_TX_SOURCE              	GPIO_PinSource10
	#define RX485_USARTx_TX_AF                  	GPIO_AF_USART3
	
	
	#define RX485_USARTx_RX_PIN                 	GPIO_Pin_11
	#define RX485_USARTx_RX_GPIO_PORT           	GPIOB
	#define RX485_USARTx_RX_GPIO_CLK            	RCC_AHB1Periph_GPIOB
	#define RX485_USARTx_RX_SOURCE              	GPIO_PinSource11
	#define RX485_USARTx_RX_AF                  	GPIO_AF_USART3
	
	#define RX485_USARTx_CTS_PIN                 GPIO_Pin_13
	#define RX485_USARTx_CTS_GPIO_PORT           GPIOB
	#define RX485_USARTx_CTS_GPIO_CLK            RCC_AHB1Periph_GPIOB
	#define RX485_USARTx_CTS_SOURCE              GPIO_PinSource13
	#define RX485_USARTx_CTS_AF                  GPIO_AF_USART3
	
	#define RX485_USARTx_RTS_PIN                 GPIO_Pin_14
	#define RX485_USARTx_RTS_GPIO_PORT           GPIOB
	#define RX485_USARTx_RTS_GPIO_CLK            RCC_AHB1Periph_GPIOB
	#define RX485_USARTx_RTS_SOURCE              GPIO_PinSource14
	#define RX485_USARTx_RTS_AF                  GPIO_AF_USART3
	
	#define RX485_USARTx_IRQn                    USART3_IRQn
	#define RX485USARTx_SendData				   USART3_SendData
	#define RX485USARTx_IRQHANDLER   			   USART3_IRQHandler	
#endif
#ifdef RX485USART4
	#define RX485_USARTx                        	UART4
	#define RX485_USARTx_CLK                    	RCC_APB1Periph_UART4
	
	#define RX485_USARTx_TX_PIN                 	GPIO_Pin_10
	#define RX485_USARTx_TX_GPIO_PORT           	GPIOC
	#define RX485_USARTx_TX_GPIO_CLK            	RCC_AHB1Periph_GPIOC
	#define RX485_USARTx_TX_SOURCE              	GPIO_PinSource10
	#define RX485_USARTx_TX_AF                  	GPIO_AF_UART4
	
	
	#define RX485_USARTx_RX_PIN                 	GPIO_Pin_11
	#define RX485_USARTx_RX_GPIO_PORT           	GPIOC
	#define RX485_USARTx_RX_GPIO_CLK            	RCC_AHB1Periph_GPIOC
	#define RX485_USARTx_RX_SOURCE              	GPIO_PinSource11
	#define RX485_USARTx_RX_AF                  	GPIO_AF_UART4
	
	#define RX485_USARTx_IRQn                    UART4_IRQn
	#define RX485USARTx_SendData				   USART4_SendData
	#define RX485USARTx_IRQHANDLER   			   UART4_IRQHandler	
#endif
#ifdef RX485USART5	
	#define RX485_USARTx                        	UART5
	#define RX485_USARTx_CLK                    	RCC_APB1Periph_UART5
	
	#define RX485_USARTx_TX_PIN                 	GPIO_Pin_12
	#define RX485_USARTx_TX_GPIO_PORT           	GPIOC
	#define RX485_USARTx_TX_GPIO_CLK            	RCC_AHB1Periph_GPIOC
	#define RX485_USARTx_TX_SOURCE              	GPIO_PinSource12
	#define RX485_USARTx_TX_AF                  	GPIO_AF_UART5
	
	
	#define RX485_USARTx_RX_PIN                 	GPIO_Pin_2
	#define RX485_USARTx_RX_GPIO_PORT           	GPIOD
	#define RX485_USARTx_RX_GPIO_CLK            	RCC_AHB1Periph_GPIOD
	#define RX485_USARTx_RX_SOURCE              	GPIO_PinSource2
	#define RX485_USARTx_RX_AF                  	GPIO_AF_UART5
	
	#define RX485_USARTx_IRQn                    UART5_IRQn
	#define RX485USARTx_SendData									USART5_SendData	
	#define RX485USARTx_IRQHANDLER   						UART5_IRQHandler	
#endif

	//硬件资源    *****************SR PB5 PB4: REn DE***************************
	//主机 	RX_EN  PC6 	   TX_EN    PC8
	//从机  RX_EN  PB5 	   TX_EN    PA15
		 
	#define RS485_RX_EN_Port			          GPIOB	               
	#define RS485_RX_EN_PIN                 GPIO_Pin_5             
	#define RS485_RX_EN_CLK                 RCC_AHB1Periph_GPIOB    
	
	#define RS485_TX_EN_Port			          GPIOA
	#define RS485_TX_EN_PIN                 GPIO_Pin_15
	#define RS485_TX_EN_CLK                 RCC_AHB1Periph_GPIOA
	//初始化函数
	extern void RS485_IO_Init(void);

	//方法函数		 
	#define RS485_RX_H             GPIO_SetBits(RS485_RX_EN_Port , RS485_RX_EN_PIN)      //SR PB5
	#define RS485_RX_L             GPIO_ResetBits(RS485_RX_EN_Port , RS485_RX_EN_PIN) 
		 
	#define RS485_TX_H             GPIO_SetBits(RS485_TX_EN_Port , RS485_TX_EN_PIN)
	#define RS485_TX_L             GPIO_ResetBits(RS485_TX_EN_Port , RS485_TX_EN_PIN) 	//SR PB4	 
	
	#ifdef __cplusplus
	 extern "C" {
	#endif
	#define RX485_USART_RX_LEN 1000
	#define RX485_USART_TX_LEN 1000
	extern u8 RX485_USART_RX_BUF[RX485_USART_RX_LEN];     //接收缓冲,最USART_RX_LEN个字节
	extern u8 RX485_USART_TX_BUF[RX485_USART_TX_LEN];    //发送缓冲,最大USART_TX_LEN个字节
	extern u8 RX485_USART_RX_STA;       //接收完成状态标记
	extern u8 RX485_USART_TX_IDLE; //发送空闲状态标记
		 
	extern u16 RX485_RX_Posi; //当前缓冲区接收位置
	extern u16 RX485_TX_Posi;
	extern u16 RX485_TX_Len;
	extern u16 RX485_RX_Len;	
		 
	void RX485_USART_Configuration(void);
	void RX485_USART_NVIC_Config(void);		 
	int RX485USARTx_SendData(unsigned char *buf,int buflen);	
	
	#ifdef __cplusplus
	}
	#endif

#endif /*uart_RX485_RX485*/	 
