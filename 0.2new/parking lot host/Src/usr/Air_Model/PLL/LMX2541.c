/***************************************************************************//**
 *   @file   LMX2541.c
 *   @brief  Implementation of LMX2541 Driver.
 *   @author Dan Nechita
********************************************************************************
 * Copyright 2012(c) Analog Devices, Inc.
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *  - Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  - Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *  - Neither the name of Analog Devices, Inc. nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *  - The use of this software may or may not infringe the patent rights
 *    of one or more patent holders.  This license does not release you
 *    from the requirement that you obtain separate licenses from these
 *    patent holders to use this software.
 *  - Use of the software either in source or binary form, must be run
 *    on or directly connected to an Analog Devices Inc. component.
 *
 * THIS SOFTWARE IS PROVIDED BY ANALOG DEVICES "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, NON-INFRINGEMENT,
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL ANALOG DEVICES BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, INTELLECTUAL PROPERTY RIGHTS, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
********************************************************************************

*******************************************************************************/

/******************************************************************************/
/***************************** Include Files **********************************/
/******************************************************************************/
#include "LMX2541.h"
#include "timer.h"

/*
//外部晶振40M
uint32_t REG_R7=0x00000017;
uint32_t REG_R13=0x0000008D;
uint32_t REG_R12=0x0000001C;
uint32_t REG_R9=0x28001409;
uint32_t REG_R8=0x0111CE58;
uint32_t REG_R6=0x001F3326;
uint32_t REG_R5=0xA0000005;
uint32_t REG_R4=0x88043284;
//uint32_t REG_R4=0xFF003284;     //Modify R3/R4/C3/C4
uint32_t REG_R3=0x0D806003;
uint32_t REG_R2=0x04000642;
uint32_t REG_R1=0x00051401;  //R=320
//uint32_t REG_R1=0x00050A01;    //R=160
uint32_t REG_R0=0x00006430;   //920.125MHz
*/
/***************************************************************************//**
 * @brief Write data into a register.
 *
 * @param data - Data value to write.
 *
 * @return None.
*******************************************************************************/


void PLL_IO_Configure(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	RCC_AHB1PeriphClockCmd(PLL_LE_RCC, ENABLE);
	GPIO_InitStructure.GPIO_Pin = PLL_LE_Pin;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(PLL_LE_GPIO, &GPIO_InitStructure);
	Clr_PLL_LE();

	RCC_AHB1PeriphClockCmd(PLL_DATA_RCC, ENABLE);	
	GPIO_InitStructure.GPIO_Pin = PLL_DATA_Pin;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(PLL_DATA_GPIO, &GPIO_InitStructure);
	Clr_PLL_DATA();
	
	RCC_AHB1PeriphClockCmd(PLL_CLK_RCC, ENABLE);		
	GPIO_InitStructure.GPIO_Pin = PLL_CLK_Pin;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(PLL_CLK_GPIO, &GPIO_InitStructure);
	Clr_PLL_CLK();
	

}


void ConfigPLL(unsigned int Freq,unsigned char Bits)
{
    unsigned char  i;
    unsigned int temp_freq;
    temp_freq = Freq<<(32-Bits);
    Clr_PLL_CLK();
    Clr_PLL_LE();
    Delay_us(2);
    for(i=0; i<Bits; i++)
    {
        if((temp_freq & 0x80000000) == 0)
        {
            Clr_PLL_DATA();
        }
        else
        {
            Set_PLL_DATA();
        }
        Delay_us(2);
        Set_PLL_CLK();
        Delay_us(2);
        Clr_PLL_CLK();
        temp_freq <<=1;
    }
    Delay_us(2);
    Set_PLL_LE();
    Delay_us(2);
    Clr_PLL_LE();
    Delay_100us(20);
}
void StartPLL(void)
{
    unsigned int temp;
    temp = 200;
    temp = (temp<<1) +1;
    ConfigPLL(temp,16);
}
void ConfigFreqPoint(unsigned char FreqPoint, unsigned short iBaseFreq)
{
    unsigned int k=0;
    unsigned int Pll_buf;
    unsigned short PLL_B;
    unsigned char PLL_A;
    if(FreqPoint > 20)
    {
        FreqPoint = 1;
    }
    k=(iBaseFreq+5*FreqPoint);
    PLL_A=(unsigned char)(k%64);
    PLL_B=(unsigned short)((k-PLL_A)/64);
    Pll_buf = PLL_B<<7;
    Pll_buf = Pll_buf+PLL_A;
    Pll_buf = Pll_buf<<1;
    ConfigPLL(Pll_buf,19);
}
void FreqHopping(unsigned char bFreqValue)
{
    ConfigFreqPoint(bFreqValue,900*10);
}

void LMX2541_Write(uint32_t data)
{
	  unsigned char i;
    Clr_PLL_CLK();
    Clr_PLL_LE();
    Delay_us(2);
    for(i=0; i<32; i++)
    {
        if((data & 0x80000000) == 0)
        {
            Clr_PLL_DATA();
        }
        else
        {
            Set_PLL_DATA();
        }
        Delay_us(2);
        Set_PLL_CLK();
        Delay_us(2);
        Clr_PLL_CLK();
        data <<=1;
    }
    Delay_us(2);
    Set_PLL_LE();
    Delay_us(2);
    Clr_PLL_LE();
//    Delay_100us(20);
		Delay_us(2);
}

/***************************************************************************//**
 * @brief Sets the LMX2541 frequency.
 *
 * @param frequency - The desired frequency value.
 *
 * @return calculatedFrequency - The actual frequency value that was set.
*******************************************************************************/
/*
//外部晶振10M
uint32_t REG_R7=0x00000017;
uint32_t REG_R13=0x0000008D;
uint32_t REG_R12=0x0000001C;
uint32_t REG_R9=0x28001409;
uint32_t REG_R8=0x0111CE58;
uint32_t REG_R6=0x001F3326;
uint32_t REG_R5=0xA0000005;
//uint32_t REG_R4=0x88043284;
uint32_t REG_R4=0xFF003284;     //Modify R3/R4/C3/C4
uint32_t REG_R3=0x0D806003;
uint32_t REG_R2=0x04000642;
//uint32_t REG_R1=0x00051401;  //R=320
uint32_t REG_R1=0x00050A01;    //R=160
uint32_t REG_R0=0x00006430;   //920.125MHz
*/
void LMX2541_SetFrequency(unsigned char channel)         //第一个channel从零开始
{
	//外部晶振40M
uint32_t REG_R7=0x00000017;
uint32_t REG_R13=0x0000008D;
uint32_t REG_R12=0x0000001C;
uint32_t REG_R9=0x28001409;
uint32_t REG_R8=0x0111CE58;
uint32_t REG_R6=0x001F3326;
uint32_t REG_R5=0xA0000005;
uint32_t REG_R4=0x88043284;
//uint32_t REG_R4=0xFF003284;     //Modify R3/R4/C3/C4
uint32_t REG_R3=0x0D806003;
uint32_t REG_R2=0x04000642;
uint32_t REG_R1=0x00051401;  //R=320
//uint32_t REG_R1=0x00050A01;    //R=160
uint32_t REG_R0=0x00006430;   //920.125MHz
	
	

//    uint32_t temp=0x56400000;     
//		temp=temp+((channel*6+3)<<4);
	  uint32_t temp=0x00006430;
    temp=temp+((channel*6)<<4);
	  LMX2541_Write(REG_R7);  
    LMX2541_Write(REG_R13);
		LMX2541_Write(REG_R12);  
    LMX2541_Write(REG_R9); 
		LMX2541_Write(REG_R8);  
    LMX2541_Write(REG_R6);
		LMX2541_Write(REG_R5);  
    LMX2541_Write(REG_R4);
  	LMX2541_Write(REG_R3);  
//    LMX2541_Write(REG_R2);      //PLL_DEN=1
//		LMX2541_Write(REG_R1);      //PLL_R=320
//    LMX2541_Write(REG_R0);      //PLL_NUM=22080;PLL_N=3
//    LMX2541_Write(temp);      //PLL_NUM=22080;PLL_N=3,9,15,21……
	
    LMX2541_Write(REG_R2);      //PLL_DEN=100
		LMX2541_Write(REG_R1);      //PLL_R=160
//    LMX2541_Write(REG_R0);      //PLL_NUM=0;PLL_N=22083
    LMX2541_Write(temp);      //PLL_NUM=0;PLL_N=22083,22089……

}
