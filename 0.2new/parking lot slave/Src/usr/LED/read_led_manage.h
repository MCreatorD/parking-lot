#ifndef __READLEDMANAGE_H
#define __READLEDMANAGE_H

#include "READ_LED.h"
#include "ws2812b.h"

#define road_read
//#define top_read

#ifdef road_read 
	//方法函数
	#define led_init          READ_LED_Init()
	#define led_h             READ_LED_H
	#define led_l             READ_LED_L
	#define led_toggle		    READ_LED_TOGGLE	
#endif

#ifdef top_read
	//方法函数
	#define led_init          WS2812_LED_Init()
	#define led_h             setLED_RED()
	#define led_l		          setLED_Green()
	#define WS2812_toggle(i)		  WS2812_TOGGLE(i)	
#endif	

#endif