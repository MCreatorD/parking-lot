#include "rf_oper.h"
#include "LMX2541.h"
#include "systick.h"
#include "EPC.h"
#include "timer3.h"
#include "DAC.h"
#include <stdio.h>
void RFPower_GPIO_Init()
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	
//	RCC_AHB1PeriphClockCmd(PA_CTR_RCC, ENABLE);  //功放功率控制
//	GPIO_InitStructure.GPIO_Pin = PA_CTR_Pin;
//  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
//  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
//  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
//  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//  GPIO_Init(PA_CTR_GPOI, &GPIO_InitStructure);
//	GPIO_SetBits(PA_CTR_GPOI,PA_CTR_Pin);

	
	RCC_AHB1PeriphClockCmd(PA_EN_RCC, ENABLE);	 //功放使能
	GPIO_InitStructure.GPIO_Pin = PA_EN_Pin;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(PA_EN_GPOI, &GPIO_InitStructure);
	GPIO_SetBits(PA_EN_GPOI,PA_EN_Pin);

}

void Rf_GPIO_Init(){
	Board_DAC_Init();
	Timer3_Init();  //Q
	Timer3_Init_I();//I
	EPC_IO_Configure(); 
	RFPower_GPIO_Init();
	PLL_IO_Configure();
}
	
void RFPowerON(uint16_t x)
{
	//GPIO_SetBits(PA_CTR_GPOI,PA_CTR_Pin);	
	DAC_SetChannel2Data(DAC_Align_12b_R, x);//功放功率控制
	GPIO_SetBits(PA_EN_GPOI,PA_EN_Pin);
	GPIO_ResetBits(GPIOC,GPIO_Pin_4);
}
void RFPowerOFF(void)
{	
	//GPIO_ResetBits(PA_CTR_GPOI,PA_CTR_Pin);	
	GPIO_ResetBits(PA_EN_GPOI,PA_EN_Pin);
	GPIO_SetBits(GPIOC,GPIO_Pin_4);

}
u8 RFPowerRead(void)
{
	u8 temp = 0;
	temp = GPIO_ReadOutputDataBit(PA_EN_GPOI,PA_EN_Pin); //读取输出口PA_EN值
	printf("PA_EN：%d\n",temp);
	return temp;
}