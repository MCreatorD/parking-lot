#ifndef BSP_UART_UPDATE_H
#define BSP_UART_UPDATE_H
#include "stm32f2xx.h"
/*--------------------USART----------------------------*/
#define DownLoadUSART1
//#define DownLoadUSART2
//#define DownLoadUSART3
//#define DownLoadUSART4
//#define DownLoadUSART5

#ifdef DownLoadUSART1  
	#define DownLoad_USARTx                        	USART1	
	
	#define DownLoad_USARTx_CLK                    	RCC_APB2Periph_USART1
	
	#define DownLoad_USARTx_TX_PIN                 	GPIO_Pin_9
	#define DownLoad_USARTx_TX_GPIO_PORT           	GPIOA
	#define DownLoad_USARTx_TX_GPIO_CLK            	RCC_AHB1Periph_GPIOA
	#define DownLoad_USARTx_TX_SOURCE              	GPIO_PinSource9
	#define DownLoad_USARTx_TX_AF                  	GPIO_AF_USART1
	
	#define DownLoad_USARTx_RX_PIN                 	GPIO_Pin_10
	#define DownLoad_USARTx_RX_GPIO_PORT           	GPIOA
	#define DownLoad_USARTx_RX_GPIO_CLK            	RCC_AHB1Periph_GPIOA
	#define DownLoad_USARTx_RX_SOURCE              	GPIO_PinSource10
	#define DownLoad_USARTx_RX_AF                  	GPIO_AF_USART1
	
	#define DownLoad_USARTx_CTS_PIN                 GPIO_Pin_11
	#define DownLoad_USARTx_CTS_GPIO_PORT           GPIOA
	#define DownLoad_USARTx_CTS_GPIO_CLK            RCC_AHB1Periph_GPIOA
	#define DownLoad_USARTx_CTS_SOURCE              GPIO_PinSource11
	#define DownLoad_USARTx_CTS_AF                  GPIO_AF_USART1
	
	#define DownLoad_USARTx_RTS_PIN                 GPIO_Pin_12
	#define DownLoad_USARTx_RTS_GPIO_PORT           GPIOA
	#define DownLoad_USARTx_RTS_GPIO_CLK            RCC_AHB1Periph_GPIOA
	#define DownLoad_USARTx_RTS_SOURCE              GPIO_PinSource12
	#define DownLoad_USARTx_RTS_AF                  GPIO_AF_USART1
	
	#define DownLoad_USARTx_IRQn                   	USART1_IRQn
	#define DownLoadUSARTx_SendData									USART1_SendData
	#define DownLoadUSARTx_IRQHANDLER               USART1_IRQHandler	
#endif

#ifdef DownLoadUSART2
	#define DownLoad_USARTx                        	USART2
	#define DownLoad_USARTx_CLK                    	RCC_APB1Periph_USART2
	
	#define DownLoad_USARTx_TX_PIN                 	GPIO_Pin_2
	#define DownLoad_USARTx_TX_GPIO_PORT           	GPIOA
	#define DownLoad_USARTx_TX_GPIO_CLK            	RCC_AHB1Periph_GPIOA
	#define DownLoad_USARTx_TX_SOURCE              	GPIO_PinSource2
	#define DownLoad_USARTx_TX_AF                  	GPIO_AF_USART2
	
	
	#define DownLoad_USARTx_RX_PIN                 	GPIO_Pin_3
	#define DownLoad_USARTx_RX_GPIO_PORT           	GPIOA
	#define DownLoad_USARTx_RX_GPIO_CLK            	RCC_AHB1Periph_GPIOA
	#define DownLoad_USARTx_RX_SOURCE              	GPIO_PinSource3
	#define DownLoad_USARTx_RX_AF                  	GPIO_AF_USART2
	
	#define DownLoad_USARTx_CTS_PIN                 GPIO_Pin_3
	#define DownLoad_USARTx_CTS_GPIO_PORT           GPIOD
	#define DownLoad_USARTx_CTS_GPIO_CLK            RCC_AHB1Periph_GPIOD
	#define DownLoad_USARTx_CTS_SOURCE              GPIO_PinSource3
	#define DownLoad_USARTx_CTS_AF                  GPIO_AF_USART2
	
	#define DownLoad_USARTx_RTS_PIN                 GPIO_Pin_4
	#define DownLoad_USARTx_RTS_GPIO_PORT           GPIOD
	#define DownLoad_USARTx_RTS_GPIO_CLK            RCC_AHB1Periph_GPIOD
	#define DownLoad_USARTx_RTS_SOURCE              GPIO_PinSource4
	#define DownLoad_USARTx_RTS_AF                  GPIO_AF_USART2
	
	#define DownLoad_USARTx_IRQn                    USART2_IRQn
	#define DownLoadUSARTx_SendData					USART2_SendData
	#define DownLoadUSARTx_IRQHANDLER   			USART2_IRQHandler	
#endif

#ifdef DownLoadUSART3
	#define DownLoad_USARTx                        	USART3
	#define DownLoad_USARTx_CLK                    	RCC_APB1Periph_USART3
	
	#define DownLoad_USARTx_TX_PIN                 	GPIO_Pin_10
	#define DownLoad_USARTx_TX_GPIO_PORT           	GPIOC
	#define DownLoad_USARTx_TX_GPIO_CLK            	RCC_AHB1Periph_GPIOC
	#define DownLoad_USARTx_TX_SOURCE              	GPIO_PinSource10
	#define DownLoad_USARTx_TX_AF                  	GPIO_AF_USART3
	
	
	#define DownLoad_USARTx_RX_PIN                 	GPIO_Pin_11
	#define DownLoad_USARTx_RX_GPIO_PORT           	GPIOC
	#define DownLoad_USARTx_RX_GPIO_CLK            	RCC_AHB1Periph_GPIOC
	#define DownLoad_USARTx_RX_SOURCE              	GPIO_PinSource11
	#define DownLoad_USARTx_RX_AF                  	GPIO_AF_USART3
	
	#define DownLoad_USARTx_CTS_PIN                 GPIO_Pin_13
	#define DownLoad_USARTx_CTS_GPIO_PORT           GPIOB
	#define DownLoad_USARTx_CTS_GPIO_CLK            RCC_AHB1Periph_GPIOB
	#define DownLoad_USARTx_CTS_SOURCE              GPIO_PinSource13
	#define DownLoad_USARTx_CTS_AF                  GPIO_AF_USART3
	
	#define DownLoad_USARTx_RTS_PIN                 GPIO_Pin_14
	#define DownLoad_USARTx_RTS_GPIO_PORT           GPIOB
	#define DownLoad_USARTx_RTS_GPIO_CLK            RCC_AHB1Periph_GPIOB
	#define DownLoad_USARTx_RTS_SOURCE              GPIO_PinSource14
	#define DownLoad_USARTx_RTS_AF                  GPIO_AF_USART3
	
	#define DownLoad_USARTx_IRQn                    USART3_IRQn
	#define DownLoadUSARTx_SendData					USART3_SendData
	#define DownLoadUSARTx_IRQHANDLER   			USART3_IRQHandler	
#endif
#ifdef DownLoadUSART4
	#define DownLoad_USARTx                        	UART4
	#define DownLoad_USARTx_CLK                    	RCC_APB1Periph_UART4
	
	#define DownLoad_USARTx_TX_PIN                 	GPIO_Pin_10
	#define DownLoad_USARTx_TX_GPIO_PORT           	GPIOC
	#define DownLoad_USARTx_TX_GPIO_CLK            	RCC_AHB1Periph_GPIOC
	#define DownLoad_USARTx_TX_SOURCE              	GPIO_PinSource10
	#define DownLoad_USARTx_TX_AF                  	GPIO_AF_UART4
	
	
	#define DownLoad_USARTx_RX_PIN                 	GPIO_Pin_11
	#define DownLoad_USARTx_RX_GPIO_PORT           	GPIOC
	#define DownLoad_USARTx_RX_GPIO_CLK            	RCC_AHB1Periph_GPIOC
	#define DownLoad_USARTx_RX_SOURCE              	GPIO_PinSource11
	#define DownLoad_USARTx_RX_AF                  	GPIO_AF_UART4
	
	#define DownLoad_USARTx_IRQn                    UART4_IRQn
	#define DownLoadUSARTx_SendData									USART4_SendData
	#define DownLoadUSARTx_IRQHANDLER   						UART4_IRQHandler	
#endif
#ifdef DownLoadUSART5	
	#define DownLoad_USARTx                        	UART5
	#define DownLoad_USARTx_CLK                    	RCC_APB1Periph_UART5
	
	#define DownLoad_USARTx_TX_PIN                 	GPIO_Pin_12
	#define DownLoad_USARTx_TX_GPIO_PORT           	GPIOC
	#define DownLoad_USARTx_TX_GPIO_CLK            	RCC_AHB1Periph_GPIOC
	#define DownLoad_USARTx_TX_SOURCE              	GPIO_PinSource12
	#define DownLoad_USARTx_TX_AF                  	GPIO_AF_UART5
	
	
	#define DownLoad_USARTx_RX_PIN                 	GPIO_Pin_2
	#define DownLoad_USARTx_RX_GPIO_PORT           	GPIOD
	#define DownLoad_USARTx_RX_GPIO_CLK            	RCC_AHB1Periph_GPIOD
	#define DownLoad_USARTx_RX_SOURCE              	GPIO_PinSource2
	#define DownLoad_USARTx_RX_AF                  	GPIO_AF_UART5
	
	#define DownLoad_USARTx_IRQn                    UART5_IRQn
	#define DownLoadUSARTx_SendData					USART5_SendData	
	#define DownLoadUSARTx_IRQHANDLER   			UART5_IRQHandler	
#endif

	#ifdef __cplusplus
	 extern "C" {
	#endif
	#define DownLoad_USART_RX_LEN 1
	#define DownLoad_USART_TX_LEN 1
	extern u8 DownLoad_USART_RX_BUF[DownLoad_USART_RX_LEN];     //接收缓冲,最USART_RX_LEN个字节
	extern u8 DownLoad_USART_TX_BUF[DownLoad_USART_TX_LEN];    //发送缓冲,最大USART_TX_LEN个字节
	extern u8 DownLoad_USART_RX_STA;       //接收完成状态标记
	extern u8 DownLoad_USART_TX_IDLE; //发送空闲状态标记
		 
	extern u16 DownLoad_RX_Posi; //当前缓冲区接收位置
	extern u16 DownLoad_TX_Posi;
	extern u16 DownLoad_TX_Len;
	extern u16 DownLoad_RX_Len;	
		 
	void DownLoad_USART_Configuration(void);
	void DownLoad_USART_NVIC_Config(void);		 
	int DownLoadUSARTx_SendData(unsigned char *buf,int buflen);

	#ifdef __cplusplus
	}
	#endif

#endif /*uart_bsp_DownLoad*/	 
