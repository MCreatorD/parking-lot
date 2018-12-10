#ifndef _I2C_H_
#define _I2C_H_

#include "stm32f2xx.h"

	#ifdef __cplusplus
	 extern "C" {
	#endif
		 
/*ÐÅÏ¢Êä³ö*/
#define IIC_DEBUG_ON         0

#define IIC_INFO(fmt,arg...)           printf("<<-IIC-INFO->> "fmt"\n",##arg)
#define IIC_ERROR(fmt,arg...)          printf("<<-IIC-ERROR->> "fmt"\n",##arg)
#define IIC_DEBUG(fmt,arg...)          do{\
                                          if(IIC_DEBUG_ON)\
                                          printf("<<-IIC-DEBUG->> [%d]"fmt"\n",__LINE__, ##arg);\
                                          }while(0)		 
		 
		 
	void I2C1_Configuration(void);
	void I2C2_Configuration(void);	 
	uint8_t I2C_Read(I2C_TypeDef *I2Cx,uint8_t I2C_Addr,uint8_t addr,uint8_t *buf,uint16_t num);
	uint8_t I2C_Write(I2C_TypeDef *I2Cx,uint8_t I2C_Addr,uint8_t addr,uint8_t *buf,uint16_t num);

	uint8_t I2C_WriteOneByte(I2C_TypeDef *I2Cx,uint8_t I2C_Addr,uint8_t addr,uint8_t value);		 
	#ifdef __cplusplus
	}
	#endif	

#endif
