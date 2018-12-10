
#include "timer.h"

volatile u32 Uart_Rec_Delay=0;
volatile u8 Timeout=0;
volatile u32 TimingDelay=0;

 void TimingDelay_Decrement(void)
{
    if (TimingDelay > 0x00)
    {
        TimingDelay--;
    }
    if(Timeout > 0)
    {
        Timeout--;
    }
	//Uart_Rec_Delay++;
}

void delay(__IO u32 nCount)
{
    for(; nCount != 0; nCount--)
    {
        ;
    }
}
void delay_ms(u32 c)
{
    uint32_t i;
    for(i=0; i<c; i++)
    {
        delay(30000);
    }
}

void Delay_us(volatile unsigned short iTime)
{
    volatile unsigned int i,j;
    for(i=0; i<iTime; i++)
    {
        for (j=0; j<13; j++)
        {
            ;
        }
    }
}
void Delay_10us(volatile unsigned int iTime)
{
    volatile unsigned int i,j;
    for(i=0; i<iTime; i++)
    {
       for (j=0; j<165; j++)
       {
            ;
       }
    }
}
void Delay_100us(volatile unsigned int  iTime)
{
    volatile unsigned int i,j;
    for(i=0; i<iTime; i++)
    {
        for (j=0; j<1700; j++)
        {
            ;
        }
    }
}
void Delay_ms1(volatile unsigned int iTime)
{
    while(iTime--)
    {
        Delay_100us(10) ;
    }
}
void Delay_us1(unsigned int  nus)
{
    uint32_t temp;
    SysTick->LOAD = 15*nus;
    SysTick->VAL=0X00;
    SysTick->CTRL=0X01;
    do
    {
        temp=SysTick->CTRL;
    }
    while((temp&0x01)&&(!(temp&(1<<16))));
    SysTick->CTRL=0x00;
    SysTick->VAL =0X00;
    SysTick_Config(SystemCoreClock/1000);//延时完 恢复滴答定时器中断1ms
}
