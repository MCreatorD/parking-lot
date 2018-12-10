#ifndef __LMX2541_H__
#define __LMX2541_H__
#ifdef __cplusplus
 extern "C" {
#endif
	 
#include "stm32f2xx.h"
/******************************************************************************/
/************************ Functions Declarations ******************************/
/******************************************************************************/
#define Freq_Channel_1   0
#define Freq_Channel_2   1
#define Freq_Channel_3   2
#define Freq_Channel_4   3
#define Freq_Channel_5   4
#define Freq_Channel_6   5
#define Freq_Channel_7   6
#define Freq_Channel_8   7
#define Freq_Channel_9   8
#define Freq_Channel_10  9
#define Freq_Channel_11  10
#define Freq_Channel_12  11
#define Freq_Channel_13  12
#define Freq_Channel_14  13
#define Freq_Channel_15  14
#define Freq_Channel_16  15
#define Freq_Channel_17  16
#define Freq_Channel_18  17
#define Freq_Channel_19  18
#define Freq_Channel_20  19

//锁相环口线
#define PLL_LE_GPIO           GPIOC      
#define PLL_LE_Pin            GPIO_Pin_1
#define PLL_LE_RCC            RCC_AHB1Periph_GPIOC

#define PLL_DATA_GPIO         GPIOC      
#define PLL_DATA_Pin          GPIO_Pin_2
#define PLL_DATA_RCC          RCC_AHB1Periph_GPIOC

#define PLL_CLK_GPIO          GPIOC      
#define PLL_CLK_Pin           GPIO_Pin_3
#define PLL_CLK_RCC           RCC_AHB1Periph_GPIOC

	
#define Set_PLL_CLK()           ((GPIOC->BSRRL) = GPIO_Pin_3)
#define Clr_PLL_CLK()           ((GPIOC->BSRRH) = GPIO_Pin_3)
#define Set_PLL_DATA()          ((GPIOC->BSRRL) = GPIO_Pin_2)
#define Clr_PLL_DATA()          ((GPIOC->BSRRH) = GPIO_Pin_2)
#define Set_PLL_LE()            ((GPIOC->BSRRL) = GPIO_Pin_1)
#define Clr_PLL_LE()            ((GPIOC->BSRRH) = GPIO_Pin_1)	

void LMX2541_Write(uint32_t data);
void LMX2541_SetFrequency(unsigned char channel);

void ConfigPLL(unsigned int Freq,unsigned char Bits);
void StartPLL(void);
void ConfigFreqPoint(unsigned char FreqPoint, unsigned short iBaseFreq);
void FreqHopping(unsigned char bFreqValue);
void PLL_IO_Configure(void);

#ifdef __cplusplus
}
#endif
#endif //__LMX2541_H__
