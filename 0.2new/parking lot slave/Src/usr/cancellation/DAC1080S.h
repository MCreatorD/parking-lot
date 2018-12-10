#ifndef __DAC1080S_H
#define __DAC1080S_H

#include "stm32f2xx.h"

	#ifdef __cplusplus
	 extern "C" {
	#endif
		 
	#define AD_DA_REF    5070
		 
	#define DAC1080S_CLK_GPOI     GPIOB        //DAC1080S_CLK
	#define DAC1080S_CLK_Pin      GPIO_Pin_13
	#define DAC1080S_DATA_GPOI    GPIOB        //DAC1080S_DATA
	#define DAC1080S_DATA_Pin     GPIO_Pin_14
	#define DAC1080S_SYNC_GPOI    GPIOB        //DAC1080S_SYNC
	#define DAC1080S_SYNC_Pin     GPIO_Pin_12
	#define DAC1080S_RCC          RCC_AHB1Periph_GPIOB	
 
	#define SPI2_CS_ENABLE		  GPIO_ResetBits(DAC1080S_SYNC_GPOI,DAC1080S_SYNC_Pin) 
	#define SPI2_CS_DISABLE		  GPIO_SetBits(DAC1080S_SYNC_GPOI,DAC1080S_SYNC_Pin) 
	#define CHANNEL_A             0
	#define CHANNEL_B             1
	#define CHANNEL_C             2
	#define CHANNEL_D             3
	#define CHANNEL_E             4
	#define CHANNEL_F             5
	#define CHANNEL_G             6
	#define CHANNEL_H             7
		 
	
	void DAC1080S_SPI2_Configure(void);
	u8 SPI2_ReadWrite_byte(u8 data);
	void SPI2_ReadWriteBuf(uint8_t *writebuf,uint8_t *readbuf,uint16_t buflen);	

	u16 SPI2_send_byte(u16 data);
	void DAC1080S_Write(u16 value,u8 channel);		 
	void Set_WTM(void);
	void Set_WRM(void);	
	void DAC1080S_Write_Value2(u16 value1,u16 value2,u8 channel_1,u8 channel_2);	
		 		 
	#ifdef __cplusplus
	}
	#endif
	

	
#endif 

