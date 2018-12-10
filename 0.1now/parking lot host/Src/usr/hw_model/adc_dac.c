#include "adc_dac.h"

//////////////////////////////////////////////////////////

void Board_DAC_Init1(void)//设置
{
    GPIO_InitTypeDef GPIO_InitStructure;
    DAC_InitTypeDef  DAC_InitStructure;
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_DAC, ENABLE);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 ;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5 ;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    DAC_InitStructure.DAC_Trigger = DAC_Trigger_None;
    DAC_InitStructure.DAC_WaveGeneration = DAC_WaveGeneration_None ;
    DAC_InitStructure.DAC_LFSRUnmask_TriangleAmplitude = DAC_LFSRUnmask_Bit0;
    DAC_InitStructure.DAC_OutputBuffer = DAC_OutputBuffer_Enable;
    DAC_Init(DAC_Channel_1, &DAC_InitStructure);
	  DAC_Init(DAC_Channel_2, &DAC_InitStructure);
    DAC_Cmd(DAC_Channel_1, ENABLE);
	  DAC_Cmd(DAC_Channel_2, ENABLE);
    DAC_SetChannel1Data(DAC_Align_12b_R, 1448);
		DAC_SetChannel2Data(DAC_Align_12b_R, 1116);

}

void Board_ADC_Init1(void)
{
    ADC_InitTypeDef       ADC_InitStructure;
    ADC_CommonInitTypeDef ADC_CommonInitStructure;
    GPIO_InitTypeDef      GPIO_InitStructure;
	  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE); //对消采样
	  RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC2, ENABLE); 
	  RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC3, ENABLE); //电池采样
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL ;
    GPIO_Init(GPIOC, &GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL ;
    GPIO_Init(GPIOC, &GPIO_InitStructure);
	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL ;
    GPIO_Init(GPIOC, &GPIO_InitStructure);
    ADC_CommonInitStructure.ADC_Mode = ADC_Mode_Independent;
    ADC_CommonInitStructure.ADC_Prescaler = ADC_Prescaler_Div2;
    ADC_CommonInitStructure.ADC_DMAAccessMode = ADC_DMAAccessMode_Disabled;
    ADC_CommonInitStructure.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_5Cycles;
    ADC_CommonInit(&ADC_CommonInitStructure);
    ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b;
    ADC_InitStructure.ADC_ScanConvMode = DISABLE;
    ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;
    ADC_InitStructure.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None;
    ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
    ADC_InitStructure.ADC_NbrOfConversion = 1;
    ADC_Init(ADC1, &ADC_InitStructure);
		ADC_Init(ADC2, &ADC_InitStructure);
		ADC_Init(ADC3, &ADC_InitStructure);
		ADC_RegularChannelConfig(ADC1, ADC_Channel_10, 1, ADC_SampleTime_15Cycles);
		ADC_RegularChannelConfig(ADC2, ADC_Channel_11, 1, ADC_SampleTime_15Cycles);
		ADC_RegularChannelConfig(ADC3, ADC_Channel_12, 1, ADC_SampleTime_15Cycles);
		ADC_Cmd(ADC1, ENABLE);
		ADC_Cmd(ADC2, ENABLE);
		ADC_Cmd(ADC3, ENABLE);
}

uint16_t Get_ADC_Value1(ADC_TypeDef* ADCx)
{
	#define ADC_Value_len	20
  uint16_t temp[ADC_Value_len]={0};
	uint16_t value = 0;
	uint8_t i;
	uint8_t j;
	uint16_t temp1;
    for(i=0; i<ADC_Value_len; i++)
    {
        ADC_ClearFlag(ADCx,ADC_FLAG_EOC);
        ADC_ClearFlag(ADCx,ADC_FLAG_OVR);
        ADC_SoftwareStartConv(ADCx);
        while(!ADC_GetFlagStatus(ADCx, ADC_FLAG_EOC ))
        {
            ;
        }
        if(ADC_GetFlagStatus(ADCx, ADC_FLAG_OVR))
        {
            ADC_ClearFlag(ADCx,ADC_FLAG_OVR);
            break;
        }
        else
        {
            ADC_ClearFlag(ADCx,ADC_FLAG_EOC);
            temp[i]=ADC_GetConversionValue(ADCx);
        }
    }
	
	//排序去除头尾
	for(i =1;i < ADC_Value_len;i++)  
    {  
        for(j = 0;j < ADC_Value_len -i;j++)// j开始等于0，  
        {  
                if(temp[j] < temp[j+1])  
                {  
                    temp1 = temp[j];  
                    temp[j] = temp[j+1];  
                    temp[j+1] = temp1;  
                }  
            }  
     }  
	//求取平均值  去除头尾各两位
		 for(i = 0+2;i<ADC_Value_len-2;i++)
		 {
				(uint64_t)value += temp[i];//在累加和的时候扩大容器 求平均数再还原回来
		 }
		value=value/(ADC_Value_len - 4);
		return value;
}