#ifndef __EN25Q256_H
#define __EN25Q256_H

#include "stm32f2xx.h"
#include "printf_usart.h"
#include "spi.h"

	#ifdef __cplusplus
	 extern "C" {
	#endif

#define EN25Q256_ID 0x1c18

extern u16 EN25Q256_TYPE;					//定义W25QXX芯片型号

#define EN25Q256_SPIx_CS_PIN                   GPIO_Pin_15
#define EN25Q256_SPIx_CS_GPIO_PORT             GPIOA
#define EN25Q256_SPIx_CS_GPIO_CLK              RCC_AHB1Periph_GPIOA

		 
//W25QXX的片选信号
#define EN25Q256_Enable 	GPIO_ResetBits(EN25Q256_SPIx_CS_GPIO_PORT,EN25Q256_SPIx_CS_PIN)
#define EN25Q256_Disable 	GPIO_SetBits(EN25Q256_SPIx_CS_GPIO_PORT,EN25Q256_SPIx_CS_PIN)
     		
				 
////////////////////////////////////////////////////////////////////////////
 
//指令表
#define EN25Q256_WriteEnable		 	    0x06 
#define EN25Q256_WriteDisable		 		0x04 
#define EN25Q256_ReadStatusReg	  			0x05 
#define EN25Q256_WriteStatusReg	  			0x01 
#define EN25Q256_ReadData		      		0x03 
#define EN25Q256_FastReadData		    	0x0B 
#define EN25Q256_FastReadDual			 	0x3B 
#define EN25Q256_PageProgram				0x02 
#define EN25Q256_BlockErase					0xD8 
#define EN25Q256_SectorErase				0x20 
#define EN25Q256_ChipErase					0xC7 
#define EN25Q256_PowerDn					0xB9 
#define EN25Q256_ReleasePowerDown		    0xAB 
#define EN25Q256_DeviceID					0xAB 
#define EN25Q256_ManufactDeviceID			0x90 
#define EN25Q256_JedecDeviceID				0x9F 

void FLASH_TEST(void);
void EN25Q256_Init(void);
u32  EN25Q256_ReadID(void);  	    		//读取FLASH ID
u8	 EN25Q256_ReadSR(void);        		//读取状态寄存器 
void EN25Q256_Write_SR(u8 sr);  			//写状态寄存器
void EN25Q256_Write_Enable(void);  		//写使能 
void EN25Q256_Write_Disable(void);		//写保护
void EN25Q256_Write_NoCheck(u8* pBuffer,u32 WriteAddr,u16 NumByteToWrite);
void EN25Q256_Read(u8* pBuffer,u32 ReadAddr,u16 NumByteToRead);   //读取flash
void EN25Q256_Write(u8* pBuffer,u32 WriteAddr,u16 NumByteToWrite);//写入flash
void EN25Q256_Erase_Chip(void);    	  	//整片擦除
void EN25Q256_Erase_Sector(u32 Dst_Addr);	//扇区擦除
void EN25Q256_Wait_Busy(void);           	//等待空闲
void EN25Q256_PowerDown(void);        	//进入掉电模式
void EN25Q256_WAKEUP(void);				//唤醒


	#ifdef __cplusplus
	}
	#endif
	
#endif 