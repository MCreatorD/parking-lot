#ifndef __SOFT_SPI_H
#define __SOFT_SPI_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f2xx.h"
#include <stdint.h>

	#ifdef __cplusplus
	 extern "C" {
	#endif

		#define SOFT_SPI_SCK_PIN                     GPIO_Pin_2
		#define SOFT_SPI_SCK_GPIO_PORT               GPIOD
		#define SOFT_SPI_MOSI_PIN                    GPIO_Pin_10
		#define SOFT_SPI_MOSI_GPIO_PORT              GPIOC
		#define SOFT_SPI_MISO_PIN                    GPIO_Pin_11
		#define SOFT_SPI_MISO_GPIO_PORT              GPIOC
		#define SOFT_SPI_NSS_PIN                     GPIO_Pin_12
		#define SOFT_SPI_NSS_GPIO_PORT               GPIOC


		#define SOFT_SPI_SCK_GPIO_CLK_ENABLE()       RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE)
		#define SOFT_SPI_MISO_GPIO_CLK_ENABLE()      RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE)
		#define SOFT_SPI_MOSI_GPIO_CLK_ENABLE()      RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE)
		#define SOFT_SPI_NSS_GPIO_CLK_ENABLE()       RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE)
	

		#define MOSI_H  GPIO_SetBits(SOFT_SPI_MOSI_GPIO_PORT , SOFT_SPI_MOSI_PIN) 
		#define MOSI_L  GPIO_ResetBits(SOFT_SPI_MOSI_GPIO_PORT , SOFT_SPI_MOSI_PIN) 
		#define SCK_H   GPIO_SetBits(SOFT_SPI_SCK_GPIO_PORT , SOFT_SPI_SCK_PIN)  
		#define SCK_L   GPIO_ResetBits(SOFT_SPI_SCK_GPIO_PORT , SOFT_SPI_SCK_PIN)  
		#define MISO    GPIO_ReadInputDataBit(SOFT_SPI_MISO_GPIO_PORT,SOFT_SPI_MISO_PIN)
		#define NSS_H   GPIO_SetBits(SOFT_SPI_NSS_GPIO_PORT , SOFT_SPI_NSS_PIN)
		#define NSS_L   GPIO_ResetBits(SOFT_SPI_NSS_GPIO_PORT , SOFT_SPI_NSS_PIN)  

//		#define EEPROM_DAC_START_ADDR   DATA_EEPROM_BASE+6             /* Start @ of user EEPROM area */
//		#define EEPROM_DAC_END_ADDR     (EEPROM_BIAS_START_ADDR + 16)   /* End @ of user EEPROM area */
//		#define IS_DAC_DATA_ADDRESS(__ADDRESS__)          (((__ADDRESS__) >= EEPROM_DAC_START_ADDR) && ((__ADDRESS__) <= EEPROM_DAC_END_ADDR))
//		#define IS_DAC_CH_ADDRESS(__ADDRESS__)          (((__ADDRESS__) >= 1) && ((__ADDRESS__) <= 4))

		void Soft_SPI_Init(void);
		uint8_t Soft_SPI_ReadWrite_Byte(uint8_t data);
		void Soft_SPI_ReadWriteBuf(uint8_t *writebuf,uint8_t *readbuf,uint16_t buflen);

	#ifdef __cplusplus
	}
	#endif	

#endif