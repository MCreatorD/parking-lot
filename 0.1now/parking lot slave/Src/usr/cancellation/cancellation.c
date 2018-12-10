
#include "cancellation.h"

#include <math.h>

#include "systick.h"
#include "timer.h"
#include "LMX2541.h"
#include "ADC.h"
#include "DAC1080S.h"
#include "sim_spi.h"
#include "read_led_manage.h"
#define DAC_MAX_DA_2V0 1
#define DAC_VALUE_DF   1861  //采样到的Q,I的共模电压，换算扯对应的采样值。


#define STEP_VALUE   5 //5//24
#define AD_MAX_VALUE   33554432 //16769025
#define AD_TIME   50//30

u8 isneedCancelltion = 0;
void Cancellation_Init(void)
{
	MOS_SW_GPIO_Init(1);       //关闭快速对消
	Cancellation_ADC_Init();  //2路对消ADC初始化
	Sim_SPI_Init();
}

void MOS_SW_GPIO_Init(uint8_t on)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	RCC_AHB1PeriphClockCmd(MOS_SW_RCC, ENABLE);
	GPIO_InitStructure.GPIO_Pin = MOS_SW_PIN;          //快速对消开关
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(MOS_SW_PORT, &GPIO_InitStructure);
	if(on==0){
		MOS_SW_Set();
	}else{
		MOS_SW_Reset();
	}
}


void Cancellation_Deinit(void)
{
	//ADF4360_SetFrequency(Freq_Channel_1);
	//RFPowerOFF();
}





uint16_t setDACValue(uint16_t DACValue,int channel){

	switch(channel){
		case QP_CHANNEL:
			DAC1080S_Write(DACValue,CHANNEL_C); //Q+
			break;
		case QN_CHANNEL:
			DAC1080S_Write(DACValue,CHANNEL_D); //Q-
			break;
		case IP_CHANNEL:
			DAC1080S_Write(DACValue,CHANNEL_A); //I+
			break;
		case IN_CHANNEL:
			DAC1080S_Write(DACValue,CHANNEL_B); //I-
			break;
		
	}
	
}


uint16_t getQADCValue(){
	
	return Get_ADC_Value(ADC_Q);
}

uint16_t getIADCValue(){
	
	return Get_ADC_Value(ADC_I);
}

//uint32_t getSQUValue(){
//	uint16_t ad_q = Get_ADC_Value(ADC_Q);// - DAC_VALUE_DF; 0x718.0x739
//	uint16_t ad_i = Get_ADC_Value(ADC_I);// - DAC_VALUE_DF; 0x71f,0x72A
//	int q = ad_q - DAC_VALUE_DF;
//	int i = ad_i - DAC_VALUE_DF;
//	//printf("ad_q=%d,ad_i=%d,q=%d,i=%d,squ=%d\n",ad_q,ad_i,q,i,q*q + i*i);
//	return q*q + i*i;
//}

uint64_t getSQUValue(int *pqvalue,int *pivalue){
	uint16_t ad_q = 0;//Get_ADC_Value(ADC_Q);// - DAC_VALUE_DF; 0x718.0x739
	uint16_t ad_i = 0;//Get_ADC_Value(ADC_I);// - DAC_VALUE_DF; 0x71f,0x72A
	int q = 0;//ad_q - DAC_VALUE_DF;
	int i = 0;//ad_i - DAC_VALUE_DF;
	
	uint64_t s = 0;
	int c = 1;
	for(int m=0;m<c;m++){
		ad_q = Get_ADC_Value(ADC_Q);
		ad_i = Get_ADC_Value(ADC_I);
		q = ad_q - DAC_VALUE_DF;
		i = ad_i - DAC_VALUE_DF;
		*pqvalue = q;
		*pivalue = i;
				
		s = s + (q*q + i*i);
	}
	s = s/c;
	//printf("ad_q=%f,ad_i=%f,q=%d,i=%d,squ=%lld\n",ad_q/4096.0f*3.3,ad_i/4096.0f*3.3,q,i,s);
	return s;
}

uint16_t Qp_DAValue = 0; //找出的Q+,Q-,I+,I-的DA值
uint16_t Qn_DAValue = 0; //Q-
uint16_t Ip_DAValue = 0; //I+
uint16_t In_DAValue = 0; //I-


#define THRESOLD 0
#define MAX_DAS 1

uint64_t Squ_Value_Min = AD_MAX_VALUE;
uint16_t DA_Values[MAX_DAS];

void searchMinPoint(uint16_t startPoint,uint16_t endPoint,int step,int channel,uint16_t *pResValue){
	uint64_t squ = 0;
	uint16_t davalue = startPoint;
	int res = 0;
	for(int m=0;m<MAX_DAS;m++){
		for(int j=startPoint;j<endPoint;j+=step){
			
			setDACValue(j,channel);
			Delay_ms(AD_TIME);
			int q;
			int i;
			squ = getSQUValue(&q,&i);
			if(squ+THRESOLD<Squ_Value_Min){
				Squ_Value_Min = squ;
				davalue = j;
				res = 1;
				printf("Squ_Value_Min=%lld,J=%d\n",Squ_Value_Min,j);
			}
		}
		DA_Values[m] = davalue;
	}
	int s = 0;
	for(int m=0;m<MAX_DAS;m++){
		s = DA_Values[m] + s;
	}
	davalue = s/MAX_DAS;
	if(res==1){ //有找到结果，才改变值
		*pResValue = davalue;
	}
	return;
}

void modifyQpChannel(uint16_t startPoint,uint16_t endPoint){
	printf("Modify Q+..........\n");
	searchMinPoint(startPoint,endPoint,STEP_VALUE,QP_CHANNEL,&Qp_DAValue);
	setDACValue(Qp_DAValue,QP_CHANNEL);  //固定Q+为一输出值.
	Delay_ms(AD_TIME);
}

void modifyQnChannel(uint16_t startPoint,uint16_t endPoint){
	printf("Modify Q-..........\n");
	searchMinPoint(startPoint,endPoint,STEP_VALUE,QN_CHANNEL,&Qn_DAValue);
	setDACValue(Qn_DAValue,QN_CHANNEL);  //固定Q-为一输出值.	
	Delay_ms(AD_TIME);
}

void modifyIpChannel(uint16_t startPoint,uint16_t endPoint){
	printf("Modify I+..........\n");
	searchMinPoint(startPoint,endPoint,STEP_VALUE,IP_CHANNEL,&Ip_DAValue);
	setDACValue(Ip_DAValue,IP_CHANNEL); 
	Delay_ms(AD_TIME);	
}

void modifyInChannel(uint16_t startPoint,uint16_t endPoint){
	printf("Modify I-..........\n");
	searchMinPoint(startPoint,endPoint,STEP_VALUE,IN_CHANNEL,&In_DAValue);
	setDACValue(In_DAValue,IN_CHANNEL);  //固定I-为一输出值.
	Delay_ms(AD_TIME);	
}


struct SQU_DA_Value min_SquDAValue;
void Cancellation(void)
{

	uint16_t DA_1V0,DA_2V0,DA_4V0,DA_4V5,DA_2V5,DA_0V5;
	uint32_t temp = 0;

	#ifdef top_read
		static u8 taggle = 0;
	#endif	
	
	int Q_value = 0;
	int I_value = 0;
	
//	uint32_t Squ_ADValue;
//	uint16_t Q_ADValue;
//	uint16_t I_ADValue;
//	
//	uint32_t squ = 0;

	///////////////////////////////////////
	GPIO_ResetBits(GPIOC,GPIO_Pin_4);

	Delay_ms(5);
	
	////////////////////////////////////////
	
	DA_0V5=(uint16_t)temp;
	
//	temp=1000*4096/AD_DA_REF;2960
	temp=1000*(1024.0f/AD_DA_REF);
	DA_1V0=(uint16_t)temp;
	
	
//	temp=2000*4096/AD_DA_REF;
	temp=2000*(1024.0f/AD_DA_REF);
	DA_2V0=(uint16_t)temp;
	
	temp=2500*(1024.0f/AD_DA_REF);
	DA_2V5=(uint16_t)temp;
	
	
	temp=4000*(1024.0f/AD_DA_REF);
	DA_4V0=(uint16_t)temp;
	temp=4500*(1024.0f/AD_DA_REF);
	DA_4V5=(uint16_t)temp;
	//LMX2541_SetFrequency(0);
	
	/////////////////////////////////////////////////////
	
	//对消过程是先将Q+,Q-，I+，I-分别做为一对消分信号来处理。
	//先将I+,I-固定为一初值，调节Q+，Q-的信号值。
	//取得Q，I的采样值。做Q*Q+I*I的运算求得SQU。持续调节Q+，Q-至SQU最小。
	//再固定Q+，Q-不变，持续调节I+,I-,至SQU最小。


	Qp_DAValue = 0;//DA_2V5;
	Qn_DAValue = 0;//DA_2V5;
	Ip_DAValue = 0;//DA_2V5;
	In_DAValue = 0;//DA_2V5;

	///////////////////////////////////////////////////////
//	while(1){
//		getSQUValue();
//		Delay_ms(1000);
//	}
//	uint16_t a0,b0,c0,d0;
//	a0 = 580;
//	b0 = 625;
//	c0 = 590;
//	d0 = 510;
//	a0 = 768;
//	b0 = 768;
//	c0 = 768;
//	d0 = 768;
//	while(1){
//		setDACValue(a0,QP_CHANNEL);
//		setDACValue(b0,QN_CHANNEL);
//		setDACValue(c0,IP_CHANNEL);
//		setDACValue(d0,IN_CHANNEL);
//		Delay_ms(AD_TIME);
//		Squ_Value_Min = getSQUValue();
//		printf("SQU = %lld\n",Squ_Value_Min);
//		Delay_ms(1000);
//	}
	
	setDACValue(Qp_DAValue,QP_CHANNEL);
	setDACValue(Qn_DAValue,QN_CHANNEL);
	setDACValue(Ip_DAValue,IP_CHANNEL);
	setDACValue(In_DAValue,IN_CHANNEL);
	Delay_ms(AD_TIME);
	Squ_Value_Min = getSQUValue(&Q_value,&I_value);

	
//	for(int i=0;i<4;i++){
//		
//		//modifyQnChannel(DA_2V5,DA_4V5);
//		//modifyQpChannel(DA_2V5,DA_4V5);
//		//Squ_Value_Min = AD_MAX_VALUE;
//		modifyQpChannel(DA_2V5,DA_4V5);
//		//Squ_Value_Min = AD_MAX_VALUE;
//		modifyQnChannel(DA_2V5,DA_4V5);
//		//Squ_Value_Min = AD_MAX_VALUE;
//		modifyIpChannel(DA_2V5,DA_4V5);
//		//Squ_Value_Min = AD_MAX_VALUE;
//		modifyInChannel(DA_2V5,DA_4V5);
//		
//		//modifyQnChannel(DA_2V5,DA_4V5);
//		//Qn_DAValue = DA_2V5;
//		//setDACValue(Qn_DAValue,QN_CHANNEL);
//		
//		//modifyQpChannel(DA_2V5,DA_4V5);
//		//Qp_DAValue = DA_2V5;
//		//setDACValue(Qp_DAValue,QP_CHANNEL);
//		
//		//modifyInChannel(DA_2V5,DA_4V5);
//		//In_DAValue = DA_2V5;
//		//setDACValue(In_DAValue,IP_CHANNEL);
//		
//		//modifyIpChannel(DA_2V5,DA_4V5);
//		//Ip_DAValue = DA_2V5;
//		//setDACValue(Ip_DAValue,IN_CHANNEL);
//				
//		Delay_ms(5000);
//		
//		
//		
//	}
	/////////////////////////////////////////////////
//	uint64_t squ = 0;
//	for(int qp=DA_2V5;qp<DA_4V5;qp++){
//		setDACValue(qp,QP_CHANNEL);
//		Delay_ms(AD_TIME);
//		squ = getSQUValue();
//		if(squ<Squ_Value_Min){
//			Squ_Value_Min = squ;
//			Qp_DAValue = qp;		
//		}
//		for(int qn=DA_2V5;qn<DA_4V5;qn++){
//			setDACValue(qn,QN_CHANNEL);
//			Delay_ms(AD_TIME);
//			squ = getSQUValue();
//			if(squ<Squ_Value_Min){
//				Squ_Value_Min = squ;
//				Qn_DAValue = qn;		
//			}
//			for(int ip=DA_2V5;ip<DA_4V5;ip++){
//				setDACValue(ip,IP_CHANNEL);
//				Delay_ms(AD_TIME);
//				squ = getSQUValue();
//				if(squ<Squ_Value_Min){
//					Squ_Value_Min = squ;
//					Ip_DAValue = ip;		
//				}
//				for(int in=DA_2V5;in<DA_4V5;in++){
//					setDACValue(in,IN_CHANNEL);
//					Delay_ms(AD_TIME);
//					squ = getSQUValue();
//					if(squ<Squ_Value_Min){
//						Squ_Value_Min = squ;
//						In_DAValue = in;		
//					}
//				}
//			}
//		}
//		
//	}

	int angle_step = 360.0f/ANGLE_DIV;

	min_SquDAValue.Squ_Value = AD_MAX_VALUE;
	min_SquDAValue.Qp_DAValue = DA_2V5;
	min_SquDAValue.Qn_DAValue = DA_2V5;
	min_SquDAValue.Ip_DAValue = DA_2V5;
	min_SquDAValue.In_DAValue = DA_2V5;
	
	uint16_t Ipini = DA_2V5;
	uint16_t Inini = DA_2V5;
	uint16_t Qpini = DA_2V5;
	uint16_t Qnini = DA_2V5;
	for(int angle=0;angle<360;angle+=angle_step){
		for(int i=0;i<50;i++){
			Delay_ms(AD_TIME);
			
		  #ifdef road_read
				led_toggle;
			#endif
		
			#ifdef top_read
				  taggle++;
				  WS2812_toggle(taggle%2);
			#endif			

			uint64_t squ = getSQUValue(&Q_value,&I_value);
			float x = angle/360.0f*(2*PI);
			//squ = squ>>16;
			int32_t delta_I = (I_value*cos(x)+Q_value*sin(x))/100.0f;
			int32_t delta_Q = (Q_value*cos(x)-I_value*sin(x))/100.0f;
			Qp_DAValue = Qpini + delta_Q;
			Qn_DAValue = Qnini - delta_Q;
			Ip_DAValue = Ipini + delta_I;
			In_DAValue = Inini - delta_I;
			Qpini = Qp_DAValue;
			Qnini = Qn_DAValue;
			Ipini = Ip_DAValue;
			Inini = In_DAValue;
			setDACValue(Qp_DAValue,QP_CHANNEL);
			setDACValue(Qn_DAValue,QN_CHANNEL);
			setDACValue(Ip_DAValue,IP_CHANNEL);
			setDACValue(In_DAValue,IN_CHANNEL);
			
		}
		Delay_ms(AD_TIME);
		uint64_t squ = getSQUValue(&Q_value,&I_value);
		//squ = squ>>16;
		if(squ<min_SquDAValue.Squ_Value){
			min_SquDAValue.Squ_Value = squ;
			min_SquDAValue.Qp_DAValue = Qp_DAValue;
			min_SquDAValue.Qn_DAValue = Qn_DAValue;
			min_SquDAValue.Ip_DAValue = Ip_DAValue;
			min_SquDAValue.In_DAValue = In_DAValue;
			printf("min_SquDAValue.Squ_Value=%lld,Qp_DA=%d,Qn_DA=%d,Ip_DA=%d,In_DA=%d\n",
				min_SquDAValue.Squ_Value,min_SquDAValue.Qp_DAValue,min_SquDAValue.Qn_DAValue,min_SquDAValue.Ip_DAValue,min_SquDAValue.In_DAValue);
		}
	}

	/////////////////////////////////////////////////
	printf("end.....................\n");
	//将结果置入。
	Qp_DAValue = min_SquDAValue.Qp_DAValue;
	Qn_DAValue = min_SquDAValue.Qn_DAValue;
	Ip_DAValue = min_SquDAValue.Ip_DAValue;
	In_DAValue = min_SquDAValue.In_DAValue;
	
	printf("Qp_DAValue=%d\n",Qp_DAValue);
	printf("Qn_DAValue=%d\n",Qn_DAValue);
	printf("Ip_DAValue=%d\n",Ip_DAValue);
	printf("In_DAValue=%d\n",In_DAValue);
	setDACValue(Qp_DAValue,QP_CHANNEL);
	setDACValue(Qn_DAValue,QN_CHANNEL);
	setDACValue(Ip_DAValue,IP_CHANNEL);
	setDACValue(In_DAValue,IN_CHANNEL);
	Delay_ms(AD_TIME);
	uint32_t a = getSQUValue(&Q_value,&I_value);
	printf("SQU = %d,SQU_min_Value = %lld\n",a,min_SquDAValue.Squ_Value);
	/////////////////////////////////////////////////
	
}

