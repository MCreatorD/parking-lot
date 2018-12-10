#ifndef __SIM_SPI_H
#define __SIM_SPI_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f2xx.h"
#include <stdint.h>

	#ifdef __cplusplus
	 extern "C" {
	#endif

		#define SPI_SCK_PIN                     GPIO_Pin_9
		#define SPI_SCK_GPIO_PORT               GPIOD
		#define SPI_MOSI_PIN                    GPIO_Pin_10
		#define SPI_MOSI_GPIO_PORT              GPIOD
		#define SPI_MISO_PIN                    GPIO_Pin_8
		#define SPI_MISO_GPIO_PORT              GPIOD
		#define SPI_NSS_PIN                     GPIO_Pin_11
		#define SPI_NSS_GPIO_PORT               GPIOD


		#define SPI_SCK_GPIO_CLK_ENABLE()       RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE)
		#define SPI_MISO_GPIO_CLK_ENABLE()      RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE)
		#define SPI_MOSI_GPIO_CLK_ENABLE()      RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE)
		#define SPI_NSS_GPIO_CLK_ENABLE()       RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE)
	

		#define MOSI_H  GPIO_SetBits(SPI_MOSI_GPIO_PORT , SPI_MOSI_PIN) 
		#define MOSI_L  GPIO_ResetBits(SPI_MOSI_GPIO_PORT , SPI_MOSI_PIN) 
		#define SCK_H   GPIO_SetBits(SPI_SCK_GPIO_PORT , SPI_SCK_PIN)  
		#define SCK_L   GPIO_ResetBits(SPI_SCK_GPIO_PORT , SPI_SCK_PIN)  
		#define MISO    GPIO_ReadInputDataBit(SPI_MISO_GPIO_PORT,SPI_MISO_PIN)
		#define NSS_H   GPIO_SetBits(SPI_NSS_GPIO_PORT , SPI_NSS_PIN)
		#define NSS_L   GPIO_ResetBits(SPI_NSS_GPIO_PORT , SPI_NSS_PIN)  

		#define EEPROM_DAC_START_ADDR   DATA_EEPROM_BASE+6             /* Start @ of user EEPROM area */
		#define EEPROM_DAC_END_ADDR     (EEPROM_BIAS_START_ADDR + 16)   /* End @ of user EEPROM area */
		#define IS_DAC_DATA_ADDRESS(__ADDRESS__)          (((__ADDRESS__) >= EEPROM_DAC_START_ADDR) && ((__ADDRESS__) <= EEPROM_DAC_END_ADDR))
		#define IS_DAC_CH_ADDRESS(__ADDRESS__)          (((__ADDRESS__) >= 1) && ((__ADDRESS__) <= 4))

		void Sim_SPI_Init(void);
		//uint16_t Sim_SPI_ReadWrite_Byte(uint8_t data);
		void Sim_SPI_ReadWriteBuf(uint8_t *writebuf,uint8_t *readbuf,uint16_t buflen);

	#ifdef __cplusplus
	}
	#endif	

#endif