#ifndef _RF_OPER_H_
#define _RF_OPER_H_

#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32f2xx.h"

#define RF_PWR_STB1_PORT                        GPIOC
#define RF_PWR_STB1_PIN                         GPIO_Pin_5
#define RF_PWR_STB2_PORT                        GPIOC
#define RF_PWR_STB2_PIN                         GPIO_Pin_8
#define RF_PWR_SLP_PORT                         GPIOC
#define RF_PWR_SLP_PIN                          GPIO_Pin_12

#define PA_CTR_GPOI           GPIOA      //功放功率控制
#define PA_CTR_Pin            GPIO_Pin_4
#define PA_CTR_RCC            RCC_AHB1Periph_GPIOA

#define PA_EN_GPOI            GPIOC      //功放使能
#define PA_EN_Pin             GPIO_Pin_6
#define PA_EN_RCC             RCC_AHB1Periph_GPIOC

#define PA_POWER     3700

void RFPowerON(uint16_t x);
void RFPowerOFF(void);

void Rf_GPIO_Init();

#ifdef __cplusplus
}
#endif

#endif