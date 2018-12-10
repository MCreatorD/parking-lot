#ifndef __SPI_H
#define __SPI_H

#include"stm32f2xx_conf.h"
#include "stdbool.h"
#define OpenSPI2

#ifdef OpenSPI1
#define Open207V_SPIx                           SPI1
#define Open207V_SPIx_CLK                       RCC_APB2Periph_SPI1
#define Open207V_SPIx_IRQn                      SPI1_IRQn
#define Open207V_SPIx_IRQHANDLER                SPI1_IRQHandler
#define Open207V_SPIx_SCK_PIN                   GPIO_Pin_5
#define Open207V_SPIx_SCK_GPIO_PORT             GPIOA
#define Open207V_SPIx_SCK_GPIO_CLK              RCC_AHB1Periph_GPIOA
#define Open207V_SPIx_SCK_SOURCE                GPIO_PinSource5
#define Open207V_SPIx_SCK_AF                    GPIO_AF_SPI1
#define Open207V_SPIx_MISO_PIN                  GPIO_Pin_6
#define Open207V_SPIx_MISO_GPIO_PORT            GPIOA
#define Open207V_SPIx_MISO_GPIO_CLK             RCC_AHB1Periph_GPIOA
#define Open207V_SPIx_MISO_SOURCE               GPIO_PinSource6
#define Open207V_SPIx_MISO_AF                   GPIO_AF_SPI1
#define Open207V_SPIx_MOSI_PIN                  GPIO_Pin_7
#define Open207V_SPIx_MOSI_GPIO_PORT            GPIOA
#define Open207V_SPIx_MOSI_GPIO_CLK             RCC_AHB1Periph_GPIOA
#define Open207V_SPIx_MOSI_SOURCE               GPIO_PinSource7
#define Open207V_SPIx_MOSI_AF                   GPIO_AF_SPI1
#endif
#ifdef OpenSPI2
#define Open207V_SPIx                           SPI2
#define Open207V_SPIx_CLK                       RCC_APB1Periph_SPI2
#define Open207V_SPIx_IRQn                      SPI2_IRQn
#define Open207V_SPIx_IRQHANDLER                SPI2_IRQHandler
#define Open207V_SPIx_SCK_PIN                   GPIO_Pin_13
#define Open207V_SPIx_SCK_GPIO_PORT             GPIOB
#define Open207V_SPIx_SCK_GPIO_CLK              RCC_AHB1Periph_GPIOB
#define Open207V_SPIx_SCK_SOURCE                GPIO_PinSource13
#define Open207V_SPIx_SCK_AF                    GPIO_AF_SPI2
#define Open207V_SPIx_MISO_PIN                  GPIO_Pin_14
#define Open207V_SPIx_MISO_GPIO_PORT            GPIOB
#define Open207V_SPIx_MISO_GPIO_CLK             RCC_AHB1Periph_GPIOB
#define Open207V_SPIx_MISO_SOURCE               GPIO_PinSource14
#define Open207V_SPIx_MISO_AF                   GPIO_AF_SPI2
#define Open207V_SPIx_MOSI_PIN                  GPIO_Pin_15
#define Open207V_SPIx_MOSI_GPIO_PORT            GPIOB
#define Open207V_SPIx_MOSI_GPIO_CLK             RCC_AHB1Periph_GPIOB
#define Open207V_SPIx_MOSI_SOURCE               GPIO_PinSource15
#define Open207V_SPIx_MOSI_AF                   GPIO_AF_SPI2
#endif
#ifdef OpenSPI3
#define Open207V_SPIx                           SPI3
#define Open207V_SPIx_CLK                       RCC_APB1Periph_SPI3
#define Open207V_SPIx_IRQn                      SPI3_IRQn
#define Open207V_SPIx_IRQHANDLER                SPI3_IRQHandler
#define Open207V_SPIx_SCK_PIN                   GPIO_Pin_3
#define Open207V_SPIx_SCK_GPIO_PORT             GPIOB
#define Open207V_SPIx_SCK_GPIO_CLK              RCC_AHB1Periph_GPIOB
#define Open207V_SPIx_SCK_SOURCE                GPIO_PinSource3
#define Open207V_SPIx_SCK_AF                    GPIO_AF_SPI3
#define Open207V_SPIx_MISO_PIN                  GPIO_Pin_4
#define Open207V_SPIx_MISO_GPIO_PORT            GPIOB
#define Open207V_SPIx_MISO_GPIO_CLK             RCC_AHB1Periph_GPIOB
#define Open207V_SPIx_MISO_SOURCE               GPIO_PinSource4
#define Open207V_SPIx_MISO_AF                   GPIO_AF_SPI3
#define Open207V_SPIx_MOSI_PIN                  GPIO_Pin_5
#define Open207V_SPIx_MOSI_GPIO_PORT            GPIOB
#define Open207V_SPIx_MOSI_GPIO_CLK             RCC_AHB1Periph_GPIOB
#define Open207V_SPIx_MOSI_SOURCE               GPIO_PinSource5
#define Open207V_SPIx_MOSI_AF                   GPIO_AF_SPI3
#endif


#define CS_Enable()     GPIO_ResetBits(GPIOB,GPIO_Pin_12)
#define CS_Disable()    GPIO_SetBits(GPIOB,GPIO_Pin_12)
#define u16 uint16_t
#define u8  uint8_t

#ifdef __cplusplus
extern "C" {
#endif	
    void SPI_Configuration(void);
    uint16_t SPIx_Send_byte(u8 data);
    bool SPIx_Send_bytes(uint8_t data[],int count);
    u16 SPIx_Receive_byte(void);
    bool SPIx_Receive_bytes(uint8_t buf[],uint8_t len);
	//bool SPIx_Receive_bytes(uint8_t buf[],uint8_t len)
#ifdef __cplusplus
}
#endif
#endif
