#ifndef __TIMER_H
#define __TIMER_H

#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32f2xx.h"

//extern volatile u32 Uart_Rec_Delay;
extern volatile u8 Timeout;
extern volatile u32 TimingDelay;

void TimingDelay_Decrement(void);
void delay(__IO u32 nCount);
void delay_ms(u32 c);
	 
void Delay_us(volatile unsigned short iTime);
void Delay_10us(volatile unsigned int iTime);
void Delay_100us(volatile unsigned int  iTime);
void Delay_ms1(volatile unsigned int iTime);
void Delay_us1(unsigned int  nus);	 
 
#ifdef __cplusplus
}
#endif
 
#endif
