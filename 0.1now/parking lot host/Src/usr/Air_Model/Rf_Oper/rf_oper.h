#ifndef _RF_OPER_H_
#define _RF_OPER_H_

#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32f2xx.h"

//#define RF_PWR_STB1_PORT                        GPIOC
//#define RF_PWR_STB1_PIN                         GPIO_Pin_5
//#define RF_PWR_STB2_PORT                        GPIOC
//#define RF_PWR_STB2_PIN                         GPIO_Pin_8
//#define RF_PWR_SLP_PORT                         GPIOC
//#define RF_PWR_SLP_PIN                          GPIO_Pin_12

#define PA_CTR_GPOI           GPIOA      //功放功率控制
#define PA_CTR_Pin            GPIO_Pin_5
#define PA_CTR_RCC            RCC_AHB1Periph_GPIOA

#define PA_EN_GPOI            GPIOD      //功放使能
#define PA_EN_Pin             GPIO_Pin_9
#define PA_EN_RCC             RCC_AHB1Periph_GPIOD

#define PA_POWER     2960

void RFPowerON(uint16_t x);
void RFPowerOFF(void);
u8 RFPowerRead(void);
void Rf_GPIO_Init();

#ifdef __cplusplus
}
#endif

#endif