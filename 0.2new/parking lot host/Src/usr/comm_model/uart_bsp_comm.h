#ifndef _UART_BSP_COMM_H
#define _UART_BSP_COMM_H
#include "stm32f2xx.h"
/*--------------------USART----------------------------*/
//#define CommUSART1
#define CommUSART2
//#define CommUSART3
//#define CommUSART4
//#define CommUSART5

#ifdef CommUSART1  
	#define Comm_USARTx                        	USART1	
	
	#define Comm_USARTx_CLK                    	RCC_APB2Periph_USART1
	
	#define Comm_USARTx_TX_PIN                 	GPIO_Pin_9
	#define Comm_USARTx_TX_GPIO_PORT           	GPIOA
	#define Comm_USARTx_TX_GPIO_CLK            	RCC_AHB1Periph_GPIOA
	#define Comm_USARTx_TX_SOURCE              	GPIO_PinSource9
	#define Comm_USARTx_TX_AF                  	GPIO_AF_USART1
	
	#define Comm_USARTx_RX_PIN                 	GPIO_Pin_10
	#define Comm_USARTx_RX_GPIO_PORT           	GPIOA
	#define Comm_USARTx_RX_GPIO_CLK            	RCC_AHB1Periph_GPIOA
	#define Comm_USARTx_RX_SOURCE              	GPIO_PinSource10
	#define Comm_USARTx_RX_AF                  	GPIO_AF_USART1
	
	#define Comm_USARTx_CTS_PIN                 GPIO_Pin_11
	#define Comm_USARTx_CTS_GPIO_PORT           GPIOA
	#define Comm_USARTx_CTS_GPIO_CLK            RCC_AHB1Periph_GPIOA
	#define Comm_USARTx_CTS_SOURCE              GPIO_PinSource11
	#define Comm_USARTx_CTS_AF                  GPIO_AF_USART1
	
	#define Comm_USARTx_RTS_PIN                 GPIO_Pin_12
	#define Comm_USARTx_RTS_GPIO_PORT           GPIOA
	#define Comm_USARTx_RTS_GPIO_CLK            RCC_AHB1Periph_GPIOA
	#define Comm_USARTx_RTS_SOURCE              GPIO_PinSource12
	#define Comm_USARTx_RTS_AF                  GPIO_AF_USART1
	
	#define Comm_USARTx_IRQn                   	USART1_IRQn
	#define CommUSARTx_SendData									USART1_SendData
	#define CommUSARTx_IRQHANDLER   USART1_IRQHandler	
#endif

#ifdef CommUSART2
	#define Comm_USARTx                        	USART2
	#define Comm_USARTx_CLK                    	RCC_APB1Periph_USART2
	
	#define Comm_USARTx_TX_PIN                 	GPIO_Pin_2
	#define Comm_USARTx_TX_GPIO_PORT           	GPIOA
	#define Comm_USARTx_TX_GPIO_CLK            	RCC_AHB1Periph_GPIOA
	#define Comm_USARTx_TX_SOURCE              	GPIO_PinSource2
	#define Comm_USARTx_TX_AF                  	GPIO_AF_USART2
	
	
	#define Comm_USARTx_RX_PIN                 	GPIO_Pin_3
	#define Comm_USARTx_RX_GPIO_PORT           	GPIOA
	#define Comm_USARTx_RX_GPIO_CLK            	RCC_AHB1Periph_GPIOA
	#define Comm_USARTx_RX_SOURCE              	GPIO_PinSource3
	#define Comm_USARTx_RX_AF                  	GPIO_AF_USART2
	
	#define Comm_USARTx_CTS_PIN                 GPIO_Pin_3
	#define Comm_USARTx_CTS_GPIO_PORT           GPIOD
	#define Comm_USARTx_CTS_GPIO_CLK            RCC_AHB1Periph_GPIOD
	#define Comm_USARTx_CTS_SOURCE              GPIO_PinSource3
	#define Comm_USARTx_CTS_AF                  GPIO_AF_USART2
	
	#define Comm_USARTx_RTS_PIN                 GPIO_Pin_4
	#define Comm_USARTx_RTS_GPIO_PORT           GPIOD
	#define Comm_USARTx_RTS_GPIO_CLK            RCC_AHB1Periph_GPIOD
	#define Comm_USARTx_RTS_SOURCE              GPIO_PinSource4
	#define Comm_USARTx_RTS_AF                  GPIO_AF_USART2
	
	#define Comm_USARTx_IRQn                    USART2_IRQn
	#define CommUSARTx_SendData					USART2_SendData
	#define CommUSARTx_IRQHANDLER   			USART2_IRQHandler	
#endif

#ifdef CommUSART3
	#define Comm_USARTx                        	USART3
	#define Comm_USARTx_CLK                    	RCC_APB1Periph_USART3
	
	#define Comm_USARTx_TX_PIN                 	GPIO_Pin_10
	#define Comm_USARTx_TX_GPIO_PORT           	GPIOB
	#define Comm_USARTx_TX_GPIO_CLK            	RCC_AHB1Periph_GPIOB
	#define Comm_USARTx_TX_SOURCE              	GPIO_PinSource10
	#define Comm_USARTx_TX_AF                  	GPIO_AF_USART3
	
	
	#define Comm_USARTx_RX_PIN                 	GPIO_Pin_11
	#define Comm_USARTx_RX_GPIO_PORT           	GPIOB
	#define Comm_USARTx_RX_GPIO_CLK            	RCC_AHB1Periph_GPIOB
	#define Comm_USARTx_RX_SOURCE              	GPIO_PinSource11
	#define Comm_USARTx_RX_AF                  	GPIO_AF_USART3
	
	#define Comm_USARTx_CTS_PIN                 GPIO_Pin_13
	#define Comm_USARTx_CTS_GPIO_PORT           GPIOB
	#define Comm_USARTx_CTS_GPIO_CLK            RCC_AHB1Periph_GPIOB
	#define Comm_USARTx_CTS_SOURCE              GPIO_PinSource13
	#define Comm_USARTx_CTS_AF                  GPIO_AF_USART3
	
	#define Comm_USARTx_RTS_PIN                 GPIO_Pin_14
	#define Comm_USARTx_RTS_GPIO_PORT           GPIOB
	#define Comm_USARTx_RTS_GPIO_CLK            RCC_AHB1Periph_GPIOB
	#define Comm_USARTx_RTS_SOURCE              GPIO_PinSource14
	#define Comm_USARTx_RTS_AF                  GPIO_AF_USART3
	
	#define Comm_USARTx_IRQn                    USART3_IRQn
	#define CommUSARTx_SendData					USART3_SendData
	#define CommUSARTx_IRQHANDLER   			USART3_IRQHandler	
#endif
#ifdef CommUSART4
	#define Comm_USARTx                        	UART4
	#define Comm_USARTx_CLK                    	RCC_APB1Periph_UART4
	
	#define Comm_USARTx_TX_PIN                 	GPIO_Pin_10
	#define Comm_USARTx_TX_GPIO_PORT           	GPIOC
	#define Comm_USARTx_TX_GPIO_CLK            	RCC_AHB1Periph_GPIOC
	#define Comm_USARTx_TX_SOURCE              	GPIO_PinSource10
	#define Comm_USARTx_TX_AF                  	GPIO_AF_UART4
	
	
	#define Comm_USARTx_RX_PIN                 	GPIO_Pin_11
	#define Comm_USARTx_RX_GPIO_PORT           	GPIOC
	#define Comm_USARTx_RX_GPIO_CLK            	RCC_AHB1Periph_GPIOC
	#define Comm_USARTx_RX_SOURCE              	GPIO_PinSource11
	#define Comm_USARTx_RX_AF                  	GPIO_AF_UART4
	
	#define Comm_USARTx_IRQn                    UART4_IRQn
	#define CommUSARTx_SendData									USART4_SendData
	#define CommUSARTx_IRQHANDLER   						UART4_IRQHandler	
#endif
#ifdef CommUSART5	
	#define Comm_USARTx                        	UART5
	#define Comm_USARTx_CLK                    	RCC_APB1Periph_UART5
	
	#define Comm_USARTx_TX_PIN                 	GPIO_Pin_12
	#define Comm_USARTx_TX_GPIO_PORT           	GPIOC
	#define Comm_USARTx_TX_GPIO_CLK            	RCC_AHB1Periph_GPIOC
	#define Comm_USARTx_TX_SOURCE              	GPIO_PinSource12
	#define Comm_USARTx_TX_AF                  	GPIO_AF_UART5
	
	
	#define Comm_USARTx_RX_PIN                 	GPIO_Pin_2
	#define Comm_USARTx_RX_GPIO_PORT           	GPIOD
	#define Comm_USARTx_RX_GPIO_CLK            	RCC_AHB1Periph_GPIOD
	#define Comm_USARTx_RX_SOURCE              	GPIO_PinSource2
	#define Comm_USARTx_RX_AF                  	GPIO_AF_UART5
	
	#define Comm_USARTx_IRQn                    UART5_IRQn
	#define CommUSARTx_SendData					USART5_SendData	
	#define CommUSARTx_IRQHANDLER   			UART5_IRQHandler	
#endif

	#ifdef __cplusplus
	 extern "C" {
	#endif
	#define Comm_USART_RX_LEN 4096 + 1024
	#define Comm_USART_TX_LEN 2048
	extern u8 Comm_USART_RX_BUF[Comm_USART_RX_LEN];     //接收缓冲,最USART_RX_LEN个字节
	extern u8 Comm_USART_TX_BUF[Comm_USART_TX_LEN];    //发送缓冲,最大USART_TX_LEN个字节
	extern u8 Comm_USART_RX_STA;       //接收完成状态标记
	extern u8 Comm_USART_TX_IDLE; //发送空闲状态标记
		 
	extern u16 Comm_RX_Posi; //当前缓冲区接收位置
	extern u16 Comm_TX_Posi;
	extern u16 Comm_TX_Len;
	extern u16 Comm_RX_Len;	
		 
	void Comm_USART_Configuration(void);
	void Comm_USART_NVIC_Config(void);		 
	int CommUSARTx_SendData(unsigned char *buf,int buflen);		 
	#ifdef __cplusplus
	}
	#endif

#endif /*uart_bsp_comm*/	 