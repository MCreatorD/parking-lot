#ifndef __SIM_SPI1_H
#define __SIM_SPI1_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f2xx.h"
#include <stdint.h>

//模拟SPI口1，用于与EPCS通信

	#ifdef __cplusplus
	 extern "C" {
	#endif

		#define SPI1_SCK_PIN                     GPIO_Pin_15
		#define SPI1_SCK_GPIO_PORT               GPIOD
		#define SPI1_MOSI_PIN                    GPIO_Pin_13
		#define SPI1_MOSI_GPIO_PORT              GPIOD
		#define SPI1_MISO_PIN                    GPIO_Pin_6
		#define SPI1_MISO_GPIO_PORT              GPIOC
		#define SPI1_NSS_PIN                     GPIO_Pin_14
		#define SPI1_NSS_GPIO_PORT               GPIOD


		#define SPI1_SCK_GPIO_CLK_ENABLE()       RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE)
		#define SPI1_MISO_GPIO_CLK_ENABLE()      RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE)
		#define SPI1_MOSI_GPIO_CLK_ENABLE()      RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE)
		#define SPI1_NSS_GPIO_CLK_ENABLE()       RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE)
	

		#define MOSI1_H  GPIO_SetBits(SPI1_MOSI_GPIO_PORT , SPI1_MOSI_PIN) 
		#define MOSI1_L  GPIO_ResetBits(SPI1_MOSI_GPIO_PORT , SPI1_MOSI_PIN) 
		#define SCK1_H   GPIO_SetBits(SPI1_SCK_GPIO_PORT , SPI1_SCK_PIN)  
		#define SCK1_L   GPIO_ResetBits(SPI1_SCK_GPIO_PORT , SPI1_SCK_PIN)  
		#define MISO1    GPIO_ReadInputDataBit(SPI1_MISO_GPIO_PORT,SPI1_MISO_PIN)
		#define NSS1_H   GPIO_SetBits(SPI1_NSS_GPIO_PORT , SPI1_NSS_PIN)
		#define NSS1_L   GPIO_ResetBits(SPI1_NSS_GPIO_PORT , SPI1_NSS_PIN)  


		uint8_t Sim_SPI1_ReadWrite_Byte(uint8_t data);
		void Sim_SPI1_Init(void);
		//uint16_t Sim_SPI_ReadWrite_Byte(uint8_t data);
		void Sim_SPI1_ReadWriteBuf(uint8_t *writebuf,uint8_t *readbuf,uint16_t buflen);

	#ifdef __cplusplus
	}
	#endif	

#endif