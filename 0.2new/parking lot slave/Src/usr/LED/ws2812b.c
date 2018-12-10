#include "ws2812b.h"
void WS2812_LED_Init(void)
{
	 GPIO_InitTypeDef  GPIO_InitStructure;
		
	 RCC_AHB1PeriphClockCmd(WS2812_LED_CLK, ENABLE);	         
		
	 GPIO_InitStructure.GPIO_Pin   = WS2812_LED_PIN;				   
	 GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;           
	 GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;  
	 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;  
	 GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_DOWN;      
	 GPIO_Init(WS2812_LED_PORT, &GPIO_InitStructure);         
	 //GPIO_SetBits(WS2812_LED_PORT,WS2812_LED_PIN);					
}

static void delay_200ns(unsigned int delay_ns)
{
	  __nop();__nop();__nop();
		do
		{
			__nop();__nop();__nop();__nop();
		}while(delay_ns--);
}
/* ws2812_H
*  输出1码
*  1码，  高电平时间 0.7 μs ±150ns 
*  1码，  低电平时间 0.6 μs ±150ns
*/
static void ws2812_H(void)
{
	WS2812_LED_H;
	delay_200ns(5);
	WS2812_LED_L;
	delay_200ns(2);
}

/* ws2812_L
*  输出0码
*  0码，  高电平时间 0.35μs ±150ns 
*  0码，  低电平时间 0.8μs  ±150ns 
*/
static void ws2812_L(void)
{
	WS2812_LED_H;
	delay_200ns(2);
	WS2812_LED_L;
	delay_200ns(5);
}
void ResetRGB()
{
	WS2812_LED_L;
	delay_200ns(500);	
}

void setRGBLed(u24 RGB)
{
	u8 i,j;
	u8 tmp = 0;
	for(j=0;j<3;j++)
	{
		tmp = 0;
		if(j==0)
		{
			tmp = (RGB>>8)&0xff;		
		}
		else if(j==1)
		{
			tmp = (RGB>>16)&0xff;
		}
		else if(j==2)
		{
			tmp = RGB&0xff;
		}

		for(i = 0;i < 8;i++)
		{
			if(tmp &0x80)//取高位
			{
				ws2812_H();
			}else{
				ws2812_L();
			}
			tmp = tmp<<1;		
		}		
	}
}

void setRGBLed_num(int num ,u24 RGB)
{
	for(;num>0;num--)
	{
		setRGBLed(RGB);
	}
}

void setLED_RED()
{
	setRGBLed_num(25,0xff0000);
}

void setLED_Green()
{
	setRGBLed_num(25,0x00ff00);	
}

void WS2812_TOGGLE(u8 taggle)
{
	if(taggle == 1)
	{
		setLED_RED();
	}
	else{
	  setLED_Green();		
	}
	ResetRGB();
}