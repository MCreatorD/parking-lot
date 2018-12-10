#include "stm32f2xx.h"
#include "config.h"
#include "stdbool.h"
#include "ws_spi.h"
//#include "sys.h"
//#include "myinclude.h"

#if 0

void SPI_Configuration(void)
{
    SPI_InitTypeDef SPI_InitStruct;
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_AHB1PeriphClockCmd( Open207V_SPIx_SCK_GPIO_CLK |  Open207V_SPIx_MISO_GPIO_CLK |  Open207V_SPIx_MOSI_GPIO_CLK,ENABLE);
#ifdef OpenSPI1
    RCC_APB2PeriphClockCmd( Open207V_SPIx_CLK,ENABLE);
#else
    RCC_APB1PeriphClockCmd( Open207V_SPIx_CLK,ENABLE);
#endif
    GPIO_PinAFConfig( Open207V_SPIx_SCK_GPIO_PORT,  Open207V_SPIx_SCK_SOURCE,   Open207V_SPIx_SCK_AF);
    GPIO_PinAFConfig( Open207V_SPIx_MISO_GPIO_PORT, Open207V_SPIx_MISO_SOURCE,  Open207V_SPIx_MISO_AF);
    GPIO_PinAFConfig( Open207V_SPIx_MOSI_GPIO_PORT,  Open207V_SPIx_MOSI_SOURCE,  Open207V_SPIx_MOSI_AF);
    GPIO_InitStructure.GPIO_Pin =  Open207V_SPIx_SCK_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd  =  GPIO_PuPd_DOWN;  ;
    GPIO_Init( Open207V_SPIx_SCK_GPIO_PORT, &GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin =  Open207V_SPIx_MISO_PIN;
    GPIO_Init( Open207V_SPIx_MISO_GPIO_PORT, &GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin =  Open207V_SPIx_MOSI_PIN;
    GPIO_Init( Open207V_SPIx_MOSI_GPIO_PORT, &GPIO_InitStructure);
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB,ENABLE);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    SPI_I2S_DeInit( Open207V_SPIx);
    SPI_InitStruct.SPI_Direction= SPI_Direction_2Lines_FullDuplex;
    SPI_InitStruct.SPI_DataSize = SPI_DataSize_8b;
    SPI_InitStruct.SPI_Mode = SPI_Mode_Master;
    SPI_InitStruct.SPI_CPOL = SPI_CPOL_Low ;
    SPI_InitStruct.SPI_CPHA = SPI_CPHA_1Edge;
    SPI_InitStruct.SPI_NSS = SPI_NSS_Soft ;
    SPI_InitStruct.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_2;
    SPI_InitStruct.SPI_FirstBit = SPI_FirstBit_MSB;
    SPI_InitStruct.SPI_CRCPolynomial = 7;
    SPI_Init( Open207V_SPIx, &SPI_InitStruct);
    SPI_Cmd( Open207V_SPIx, ENABLE);
}
uint16_t SPIx_Send_byte(u8 data)
{
    while(SPI_I2S_GetFlagStatus( Open207V_SPIx, SPI_I2S_FLAG_TXE)==RESET)
    {
        ;
    }
    SPI_I2S_SendData( Open207V_SPIx,data);
    while(SPI_I2S_GetFlagStatus( Open207V_SPIx, SPI_I2S_FLAG_RXNE)==RESET)
    {
        ;
    }
    return SPI_I2S_ReceiveData( Open207V_SPIx);
}
u16 SPIx_Receive_byte(void)
{
    while(SPI_I2S_GetFlagStatus( Open207V_SPIx, SPI_I2S_FLAG_TXE)==RESET)
    {
        ;
    }
    SPI_I2S_SendData( Open207V_SPIx,0x00);
    while(SPI_I2S_GetFlagStatus( Open207V_SPIx, SPI_I2S_FLAG_RXNE)==RESET)
    {
        ;
    }
    return SPI_I2S_ReceiveData( Open207V_SPIx);
}
bool SPIx_Receive_bytes(uint8_t buf[],uint8_t len)
{
    uint8_t i;
    CS_Enable();
    for(i=0; i<len; i++)
    {
        while(SPI_I2S_GetFlagStatus( Open207V_SPIx, SPI_I2S_FLAG_TXE)==RESET)
        {
            ;
        }
        SPI_I2S_SendData( Open207V_SPIx,0x00);
        while(SPI_I2S_GetFlagStatus( Open207V_SPIx, SPI_I2S_FLAG_RXNE)==RESET)
        {
            ;
        }
        buf[i]= SPI_I2S_ReceiveData( Open207V_SPIx);
    }
    CS_Disable();
    if(1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool SPIx_Send_bytes(uint8_t data[],int count)
{
    int i;
    CS_Enable();
    for(i=0; i<count; i++)
    {
        SPIx_Send_byte(data[i]);
    }
    CS_Disable();
    if(1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif