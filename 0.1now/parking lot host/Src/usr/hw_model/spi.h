#ifndef _SPI_H_
#define _SPI_H_

#include "stm32f2xx.h"

	#ifdef __cplusplus
	 extern "C" {
	#endif

		 void SPI1_Init(void);
		 void SPI2_Init(void);
		 void SPI3_Init(void);
		 void SPI1_ReadWriteBuf(uint8_t *writebuf,uint8_t *readbuf,uint16_t buflen);
		 
		 void SPI2_ReadWriteBuf(uint8_t *writebuf,uint8_t *readbuf,uint16_t buflen);
		  
		 uint16_t SPI2_Send_byte(u8 data);
		 u16 SPI2_Receive_byte(void);
		 u8 SPI2_Send_bytes(uint8_t data[],int count);
		 u8 SPI2_Receive_bytes(uint8_t buf[],uint8_t len);
		 
		 u8 SPI3_ReadSend_byte(u8 data);
		 u16 SPI3_Receive_byte(void);
		 #define SPI2_CS_ENABLE GPIO_ResetBits(GPIOB , GPIO_Pin_12)
		 #define SPI2_CS_DISABLE GPIO_SetBits(GPIOB , GPIO_Pin_12)
	#ifdef __cplusplus
	}
	#endif	

#endif

