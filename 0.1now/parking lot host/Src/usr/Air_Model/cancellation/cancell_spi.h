#ifndef __Cancell_SPI_H
#define __Cancell_SPI_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f2xx.h"
#include <stdint.h>

	#ifdef __cplusplus
	 extern "C" {
	#endif

		#define Cancell_SPI_MOSI_PIN                    GPIO_Pin_7
		#define Cancell_SPI_MOSI_GPIO_PORT              GPIOE
		 
		#define Cancell_SPI_SCK_PIN                     GPIO_Pin_8
		#define Cancell_SPI_SCK_GPIO_PORT               GPIOE
		 		 
	//	#define Cancell_SPI_MISO_PIN                    GPIO_Pin_8
	//	#define Cancell_SPI_MISO_GPIO_PORT              GPIOD
		 
		#define Cancell_SPI_NSS_PIN                     GPIO_Pin_9
		#define Cancell_SPI_NSS_GPIO_PORT               GPIOE


		#define Cancell_SPI_SCK_GPIO_CLK_ENABLE()       RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE)
		//#define Cancell_SPI_MISO_GPIO_CLK_ENABLE()      RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE)
		#define Cancell_SPI_MOSI_GPIO_CLK_ENABLE()      RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE)
		#define Cancell_SPI_NSS_GPIO_CLK_ENABLE()       RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE)
	

		#define Cancell_MOSI_H  GPIO_SetBits(Cancell_SPI_MOSI_GPIO_PORT , Cancell_SPI_MOSI_PIN) 
		#define Cancell_MOSI_L  GPIO_ResetBits(Cancell_SPI_MOSI_GPIO_PORT , Cancell_SPI_MOSI_PIN) 
		#define Cancell_SCK_H   GPIO_SetBits(Cancell_SPI_SCK_GPIO_PORT , Cancell_SPI_SCK_PIN)  
		#define Cancell_SCK_L   GPIO_ResetBits(Cancell_SPI_SCK_GPIO_PORT , Cancell_SPI_SCK_PIN)  
		//#define Cancell_MISO    GPIO_ReadInputDataBit(Cancell_SPI_MISO_GPIO_PORT,Cancell_SPI_MISO_PIN)
		#define Cancell_NSS_H   GPIO_SetBits(Cancell_SPI_NSS_GPIO_PORT , Cancell_SPI_NSS_PIN)
		#define Cancell_NSS_L   GPIO_ResetBits(Cancell_SPI_NSS_GPIO_PORT , Cancell_SPI_NSS_PIN)  

		void Cancell_SPI_Init(void);
		//uint16_t Cancell_SPI_ReadWrite_Byte(uint8_t data);
		void Cancell_SPI_ReadWriteBuf(uint16_t writebuf);

	#ifdef __cplusplus
	}
	#endif	

#endif
