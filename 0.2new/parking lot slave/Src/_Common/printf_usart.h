#ifndef _USART_H
#define _USART_H
		 
#include <stdio.h>
#include "stm32f2xx.h"

/*--------------------USART----------------------------*/
#define PrintfUSART1
//#define PrintfUSART2
//#define   PrintfUSART3
//#define PrintfUSART4
//#define PrintfUSART5
//#define PrintfUSART6
/*----------------------------------------------------*/


#ifdef PrintfUSART1  
	#define Printf_USARTx                        	USART1
	
	#define Printf_USARTx_CLK                    	RCC_APB2Periph_USART1
	
	#define Printf_USARTx_TX_PIN                 	GPIO_Pin_9
	#define Printf_USARTx_TX_GPIO_PORT           	GPIOA
	#define Printf_USARTx_TX_GPIO_CLK            	RCC_AHB1Periph_GPIOA
	#define Printf_USARTx_TX_SOURCE              	GPIO_PinSource9
	#define Printf_USARTx_TX_AF                  	GPIO_AF_USART1
	
	#define Printf_USARTx_RX_PIN                 	GPIO_Pin_10
	#define Printf_USARTx_RX_GPIO_PORT           	GPIOA
	#define Printf_USARTx_RX_GPIO_CLK            	RCC_AHB1Periph_GPIOA
	#define Printf_USARTx_RX_SOURCE              	GPIO_PinSource10
	#define Printf_USARTx_RX_AF                  	GPIO_AF_USART1
	
	#define Printf_USARTx_CTS_PIN                 GPIO_Pin_11
	#define Printf_USARTx_CTS_GPIO_PORT           GPIOA
	#define Printf_USARTx_CTS_GPIO_CLK            RCC_AHB1Periph_GPIOA
	#define Printf_USARTx_CTS_SOURCE              GPIO_PinSource11
	#define Printf_USARTx_CTS_AF                  GPIO_AF_USART1
	
	#define Printf_USARTx_RTS_PIN                 GPIO_Pin_12
	#define Printf_USARTx_RTS_GPIO_PORT           GPIOA
	#define Printf_USARTx_RTS_GPIO_CLK            RCC_AHB1Periph_GPIOA
	#define Printf_USARTx_RTS_SOURCE              GPIO_PinSource12
	#define Printf_USARTx_RTS_AF                  GPIO_AF_USART1
	
	#define Printf_USARTx_IRQn                   	USART1_IRQn
#endif

#ifdef PrintfUSART2
	#define Printf_USARTx                        	USART2
	#define Printf_USARTx_CLK                    	RCC_APB1Periph_USART2
	
	#define Printf_USARTx_TX_PIN                 	GPIO_Pin_2
	#define Printf_USARTx_TX_GPIO_PORT           	GPIOA
	#define Printf_USARTx_TX_GPIO_CLK            	RCC_AHB1Periph_GPIOA
	#define Printf_USARTx_TX_SOURCE              	GPIO_PinSource2
	#define Printf_USARTx_TX_AF                  	GPIO_AF_USART2
	
	
	#define Printf_USARTx_RX_PIN                 	GPIO_Pin_3
	#define Printf_USARTx_RX_GPIO_PORT           	GPIOA
	#define Printf_USARTx_RX_GPIO_CLK            	RCC_AHB1Periph_GPIOA
	#define Printf_USARTx_RX_SOURCE              	GPIO_PinSource3
	#define Printf_USARTx_RX_AF                  	GPIO_AF_USART2
	
	#define Printf_USARTx_CTS_PIN                 GPIO_Pin_3
	#define Printf_USARTx_CTS_GPIO_PORT           GPIOD
	#define Printf_USARTx_CTS_GPIO_CLK            RCC_AHB1Periph_GPIOD
	#define Printf_USARTx_CTS_SOURCE              GPIO_PinSource3
	#define Printf_USARTx_CTS_AF                  GPIO_AF_USART2
	
	#define Printf_USARTx_RTS_PIN                 GPIO_Pin_4
	#define Printf_USARTx_RTS_GPIO_PORT           GPIOD
	#define Printf_USARTx_RTS_GPIO_CLK            RCC_AHB1Periph_GPIOD
	#define Printf_USARTx_RTS_SOURCE              GPIO_PinSource4
	#define Printf_USARTx_RTS_AF                  GPIO_AF_USART2
	
	#define Printf_USARTx_IRQn                    USART2_IRQn
#endif

#ifdef PrintfUSART3
	#define Printf_USARTx                        	USART3
	#define Printf_USARTx_CLK                    	RCC_APB1Periph_USART3
	
	#define Printf_USARTx_TX_PIN                 	GPIO_Pin_10
	#define Printf_USARTx_TX_GPIO_PORT           	GPIOB
	#define Printf_USARTx_TX_GPIO_CLK            	RCC_AHB1Periph_GPIOB
	#define Printf_USARTx_TX_SOURCE              	GPIO_PinSource10
	#define Printf_USARTx_TX_AF                  	GPIO_AF_USART3
	
	
	#define Printf_USARTx_RX_PIN                 	GPIO_Pin_11
	#define Printf_USARTx_RX_GPIO_PORT           	GPIOB
	#define Printf_USARTx_RX_GPIO_CLK            	RCC_AHB1Periph_GPIOB
	#define Printf_USARTx_RX_SOURCE              	GPIO_PinSource11
	#define Printf_USARTx_RX_AF                  	GPIO_AF_USART3
	
	#define Printf_USARTx_CTS_PIN                 GPIO_Pin_13
	#define Printf_USARTx_CTS_GPIO_PORT           GPIOB
	#define Printf_USARTx_CTS_GPIO_CLK            RCC_AHB1Periph_GPIOB
	#define Printf_USARTx_CTS_SOURCE              GPIO_PinSource13
	#define Printf_USARTx_CTS_AF                  GPIO_AF_USART3
	
	#define Printf_USARTx_RTS_PIN                 GPIO_Pin_14
	#define Printf_USARTx_RTS_GPIO_PORT           GPIOB
	#define Printf_USARTx_RTS_GPIO_CLK            RCC_AHB1Periph_GPIOB
	#define Printf_USARTx_RTS_SOURCE              GPIO_PinSource14
	#define Printf_USARTx_RTS_AF                  GPIO_AF_USART3
	
	#define Printf_USARTx_IRQn                    USART3_IRQn
#endif
#ifdef PrintfUART4
	#define Printf_USARTx                        	UART4
	#define Printf_USARTx_CLK                    	RCC_APB1Periph_UART4
	
	#define Printf_USARTx_TX_PIN                 	GPIO_Pin_0
	#define Printf_USARTx_TX_GPIO_PORT           	GPIOA
	#define Printf_USARTx_TX_GPIO_CLK            	RCC_AHB1Periph_GPIOA
	#define Printf_USARTx_TX_SOURCE              	GPIO_PinSource0
	#define Printf_USARTx_TX_AF                  	GPIO_AF_UART4
	
	
	#define Printf_USARTx_RX_PIN                 	GPIO_Pin_1
	#define Printf_USARTx_RX_GPIO_PORT           	GPIOA
	#define Printf_USARTx_RX_GPIO_CLK            	RCC_AHB1Periph_GPIOA
	#define Printf_USARTx_RX_SOURCE              	GPIO_PinSource1
	#define Printf_USARTx_RX_AF                  	GPIO_AF_UART4
	
	#define Printf_USARTx_IRQn                    UART4_IRQn
#endif
#ifdef PrintfUART5
	#define Printf_USARTx                        	UART5
	#define Printf_USARTx_CLK                    	RCC_APB1Periph_UART5
	
	#define Printf_USARTx_TX_PIN                 	GPIO_Pin_12
	#define Printf_USARTx_TX_GPIO_PORT           	GPIOC
	#define Printf_USARTx_TX_GPIO_CLK            	RCC_AHB1Periph_GPIOC
	#define Printf_USARTx_TX_SOURCE              	GPIO_PinSource12
	#define Printf_USARTx_TX_AF                  	GPIO_AF_UART5
	
	
	#define Printf_USARTx_RX_PIN                 	GPIO_Pin_2
	#define Printf_USARTx_RX_GPIO_PORT           	GPIOD
	#define Printf_USARTx_RX_GPIO_CLK            	RCC_AHB1Periph_GPIOD
	#define Printf_USARTx_RX_SOURCE              	GPIO_PinSource2
	#define Printf_USARTx_RX_AF                  	GPIO_AF_UART5
	
	#define Printf_USARTx_IRQn                    UART5_IRQn
#endif

	#ifdef __cplusplus
	 extern "C" {
	#endif
		 
	void Printf_USART_Configuration(void);
	void Printf_USART_NVIC_Config(void);

	#ifdef __cplusplus
	}
	#endif

#endif /*_USART_H*/
