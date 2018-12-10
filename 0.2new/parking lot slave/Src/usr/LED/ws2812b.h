#ifndef __WS2812B_H
#define __WS2812B_H
#include "stm32f2xx.h"
	#ifdef __cplusplus
	 extern "C" {
	#endif
		 
	//Ӳ����ԴPB0  --> ����PD11
	#define WS2812_LED_PORT			     GPIOC
	#define WS2812_LED_PIN           GPIO_Pin_9
	#define WS2812_LED_CLK           RCC_AHB1Periph_GPIOC

	//��������
	#define  WS2812_LED_H             GPIO_SetBits(WS2812_LED_PORT , WS2812_LED_PIN)
	#define  WS2812_LED_L             GPIO_ResetBits(WS2812_LED_PORT , WS2812_LED_PIN)
	#define u24 u32
	//��ʼ������
	extern void  WS2812_LED_Init(void);
  extern void setRGBLed(u24 RGB);
	extern void ResetRGB();
	extern void setRGBLed_num(int num ,u24 RGB);
	extern void setLED_RED();
	extern void setLED_Green();
	extern void WS2812_TOGGLE(u8 taggle);
	#ifdef __cplusplus
	}
	#endif
#endif
