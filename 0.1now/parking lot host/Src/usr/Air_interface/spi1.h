#ifndef __SPI1_H
#define __SPI1_H

#ifdef __cplusplus
 extern "C" {
#endif
	 
#include "stm32f2xx.h"
	 
#define TXBUFFERSIZE   100
#define RXBUFFERSIZE   100

extern  unsigned char TxBuffer[TXBUFFERSIZE];
extern  unsigned char RxBuffer [RXBUFFERSIZE];

#define SPIx                           SPI1
#define SPIx_CLK                       RCC_APB2Periph_SPI1
#define SPIx_CLK_INIT                  RCC_APB2PeriphClockCmd
#define SPIx_IRQn                      SPI1_IRQn
#define SPIx_IRQHANDLER                SPI1_IRQHandler
	 
#define SPIx_SCK_PIN                   GPIO_Pin_3
#define SPIx_SCK_GPIO_PORT             GPIOB
#define SPIx_SCK_GPIO_CLK              RCC_AHB1Periph_GPIOB
#define SPIx_SCK_SOURCE                GPIO_PinSource3
#define SPIx_SCK_AF                    GPIO_AF_SPI1
	 
#define SPIx_MISO_PIN                  GPIO_Pin_4
#define SPIx_MISO_GPIO_PORT            GPIOB
#define SPIx_MISO_GPIO_CLK             RCC_AHB1Periph_GPIOB
#define SPIx_MISO_SOURCE               GPIO_PinSource4
#define SPIx_MISO_AF                   GPIO_AF_SPI1

#define SPIx_MOSI_PIN                  GPIO_Pin_5
#define SPIx_MOSI_GPIO_PORT            GPIOB
#define SPIx_MOSI_GPIO_CLK             RCC_AHB1Periph_GPIOB
#define SPIx_MOSI_SOURCE               GPIO_PinSource5
#define SPIx_MOSI_AF                   GPIO_AF_SPI1

#define SPIx_NSS_PIN                   GPIO_Pin_4
#define SPIx_NSS_GPIO_PORT             GPIOA
#define SPIx_NSS_GPIO_CLK              RCC_AHB1Periph_GPIOA
#define SPIx_NSS_SOURCE                GPIO_PinSource4
#define SPIx_NSS_AF                    GPIO_AF_SPI1

#define SPI1_DMA                      DMA2
#define SPI1_DMA_CHANNEL              DMA_Channel_3
#define SPI1_DR_ADDRESS               ((uint32_t)0x4001300C)
#define SPI1_DMA_STREAM_TX            DMA2_Stream3
#define SPI1_DMA_STREAM_RX            DMA2_Stream0
#define SPI1_TX_DMA_TCFLAG            DMA_FLAG_TCIF3
#define SPI1_TX_DMA_FEIFLAG           DMA_FLAG_FEIF3
#define SPI1_TX_DMA_DMEIFLAG          DMA_FLAG_DMEIF3
#define SPI1_TX_DMA_TEIFLAG           DMA_FLAG_TEIF3
#define SPI1_TX_DMA_HTIFLAG           DMA_FLAG_HTIF3
#define SPI1_RX_DMA_TCFLAG            DMA_FLAG_TCIF0
#define SPI1_RX_DMA_FEIFLAG           DMA_FLAG_FEIF0
#define SPI1_RX_DMA_DMEIFLAG          DMA_FLAG_DMEIF0
#define SPI1_RX_DMA_TEIFLAG           DMA_FLAG_TEIF0
#define SPI1_RX_DMA_HTIFLAG           DMA_FLAG_HTIF0
#define DMAx_CLK                      RCC_AHB1Periph_DMA2


#define ERROR_1 0x5
#define ERROR_2 0x6
#define ERROR_3 0x7
#define ERROR_4 0x8
#define ERROR_5 0x9
#define ERROR_6 0xa
#define ERROR_7 0xb
#define ERROR_8 0xc
#define ERROR_9 0xd

#define Set_RFOUT_DATA()              ((GPIOD->BSRRL) = GPIO_Pin_3)
#define Clr_RFOUT_DATA()              ((GPIOD->BSRRH) = GPIO_Pin_3)

void rf_out_init(void);
void Board_SPI1_Init(void);

uint8_t SPI_Send(uint8_t bCommand,uint8_t *data,uint8_t timeout);
uint8_t SPI_Read(uint8_t count,uint8_t timeout);

uint8_t SPI_Send1(uint8_t *data,uint16_t rfcount);
uint8_t SPI_Read1(void);


#ifdef __cplusplus
}
#endif

#endif
