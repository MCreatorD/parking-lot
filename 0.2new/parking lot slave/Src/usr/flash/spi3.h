#ifndef __SPI3_H
#define __SPI3_H


#ifdef __cplusplus
 extern "C" {
#endif
	 
#include "stm32f2xx.h"

void SPI3_Init(void);
u8 SPI3_ReadSend_byte(u8 data);
u16 SPI3_Receive_byte(void);

#ifdef __cplusplus
}
#endif

#endif
