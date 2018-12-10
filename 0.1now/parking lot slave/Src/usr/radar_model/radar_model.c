/**
*     �״��⳵λ�Ƿ��г�ʶ��
*/
#include "radar_model.h"
#include "systick.h"
#include <stdio.h>

//�״�ģ���ʼ�� ��ʱ�����벶��
//arr���Զ���װֵ(TIM2,TIM5��32λ��!!)
//psc��ʱ��Ԥ��Ƶ��
void radar_init()
{
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	TIM_ICInitTypeDef  TIM_ICInitStructure;
	
	RADAR_TIM_RCC_APBxPeriphClockCmd(RADAR_TIM_CLK,ENABLE);  	//TIM5ʱ��ʹ��    
	RCC_AHB1PeriphClockCmd(RADAR_PIN_R_CLK, ENABLE); 	//ʹ��PORTAʱ��	
	RCC_AHB1PeriphClockCmd(RADAR_PIN_T_CLK, ENABLE); 	//ʹ��PORTAʱ��	
	
	GPIO_InitStructure.GPIO_Pin = RADAR_PIN_R; //GPIOA0
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;//���ù���
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//�ٶ�100MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; //���츴�����
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN; //����
	GPIO_Init(RADAR_PIN_R_Port,&GPIO_InitStructure); //��ʼ��PA0

	GPIO_PinAFConfig(RADAR_PIN_R_Port,RADAR_TIM_PinSource,RADAR_AF_TIM); //PA0����λ��ʱ��5
	//�״�ģ���ʼ�� ��ʱ��������
	GPIO_InitStructure.GPIO_Pin =  RADAR_PIN_T;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;           
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;  //�������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;  
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_DOWN;   //
	GPIO_Init(RADAR_PIN_T_Port, &GPIO_InitStructure);	  
	  
	
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; //���ϼ���ģʽ
	//TIM_TimeBaseStructure.TIM_Period=arr;   //�Զ���װ��ֵ
	//TIM_TimeBaseStructure.TIM_Prescaler=psc;  //��ʱ����Ƶ	
  TIM_TimeBaseStructure.TIM_Period = 0XFFFFFFFF;
  TIM_TimeBaseStructure.TIM_Prescaler = RADAR_TIM_Prescaler-1;	
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
	
	TIM_TimeBaseInit(RADAR_TIM,&TIM_TimeBaseStructure);
	

	//��ʼ��TIM5���벶�����
	TIM_ICInitStructure.TIM_Channel = RADAR_TIM_Channel; //CC1S=01 	ѡ������� IC1ӳ�䵽TI1��
  TIM_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;	//�����ز���
  TIM_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI; //ӳ�䵽TI1��
  TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;	 //���������Ƶ,����Ƶ 
  TIM_ICInitStructure.TIM_ICFilter = 0x00;//IC1F=0000 ���������˲��� ���˲�
  TIM_ICInit(RADAR_TIM, &TIM_ICInitStructure);
		
	TIM_ITConfig(RADAR_TIM,TIM_IT_Update|RADAR_TIM_IT_CC,ENABLE);//��������ж� ,����CC1IE�����ж�	
	
  //TIM_Cmd(RADAR_TIM,ENABLE ); 	//ʹ�ܶ�ʱ��5

 
  NVIC_InitStructure.NVIC_IRQChannel = RADAR_TIM_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=2;//��ռ���ȼ�3
	NVIC_InitStructure.NVIC_IRQChannelSubPriority =0;		//�����ȼ�3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);	//����ָ���Ĳ�����ʼ��VIC�Ĵ�����
	
	
}
static void delay(unsigned int time)
{
	while(time--);
}

void send_pwm()
{
	delay(0x20000);	
	RADAR_T_H;
	delay(0x20000);
	RADAR_T_L;
	delay(0x11200);
}



//����״̬
//[7]:0,û�гɹ��Ĳ���;1,�ɹ�����һ��.
//[6]:0,��û���񵽵͵�ƽ;1,�Ѿ����񵽵͵�ƽ��.
//[5:0]:����͵�ƽ������Ĵ���(����32λ��ʱ����˵,1us��������1,���ʱ��:4294��)
u8  RADAR_TIM_CAPTURE_STA=0;	//���벶��״̬		    				
u32	RADAR_TIM_CAPTURE_VAL;	//���벶��ֵ(TIM2/TIM5��32λ)


//�״�ģ�鷢������ ,�������,�������
unsigned short int radar_read()
{
		long long temp=0; 	
	  unsigned short int s= 0;
	  unsigned int overTime = 0;
	  printf("send pwm\n");	
    TIM_Cmd(RADAR_TIM,ENABLE ); 	//ʹ�ܶ�ʱ��5	
		send_pwm();
		//���������ȴ����������ݵĲ������
		while((!(RADAR_TIM_CAPTURE_STA&0X80)) && (overTime<0xff))
		{
			delay(0x0fff);//��ʱ����Ƿ�����������
			overTime++; //����һ��ʱ�䳬ʱ
		}
		if(RADAR_TIM_CAPTURE_STA&0X80)        //�ɹ�������һ�θߵ�ƽ
		{
			temp=RADAR_TIM_CAPTURE_STA&0X3F; 
			temp*=0XFFFFFFFF;		 		         //���ʱ���ܺ�
			temp+=RADAR_TIM_CAPTURE_VAL;		   //�õ��ܵĸߵ�ƽʱ��
			//printf("HIGH:%lld us\r\n",temp); //��ӡ�ܵĸߵ�ƽʱ��
			s=temp/58;
			printf("s= %d cm\r\n",s);       //��ӡ��������
			RADAR_TIM_CAPTURE_STA=0;			     //������һ�β���
		  TIM_Cmd(RADAR_TIM,DISABLE ); 	//ʧ�ܶ�ʱ��5				
			return s;
		}	
		TIM_Cmd(RADAR_TIM,DISABLE ); 	//ʧ�ܶ�ʱ��5			
		return 0;
}


//��ʱ��5�жϷ������	 
void RADAR_TIM_IRQHandler(void)
{ 		    
 	if((RADAR_TIM_CAPTURE_STA&0X80)==0)//��δ�ɹ�����	
	{
		if(TIM_GetITStatus(RADAR_TIM, TIM_IT_Update) != RESET)//���
		{	     
			if(RADAR_TIM_CAPTURE_STA&0X40)//�Ѿ����񵽸ߵ�ƽ��
			{
				if((RADAR_TIM_CAPTURE_STA&0X3F)==0X3F)//�ߵ�ƽ̫����
				{
					RADAR_TIM_CAPTURE_STA|=0X80;		//��ǳɹ�������һ��
					RADAR_TIM_CAPTURE_VAL=0XFFFFFFFF;
				}else RADAR_TIM_CAPTURE_STA++;
			}	 
		}
		if(TIM_GetITStatus(RADAR_TIM, RADAR_TIM_IT_CC) != RESET)//����1���������¼�
		{	
			if(RADAR_TIM_CAPTURE_STA&0X40)		//����һ���½��� 		
			{	  			
				RADAR_TIM_CAPTURE_STA|=0X80;		//��ǳɹ�����һ�θߵ�ƽ����
			  RADAR_TIM_CAPTURE_VAL=RADAR_TIM_GetCapture(RADAR_TIM);//��ȡ��ǰ�Ĳ���ֵ.
	 			RADAR_TIM_TIM_OCxPolarityConfig(RADAR_TIM,TIM_ICPolarity_Rising); //CC1P=0 ����Ϊ�����ز���
			}else  								//��δ��ʼ,��һ�β���������
			{
				RADAR_TIM_CAPTURE_STA=0;			//���
				RADAR_TIM_CAPTURE_VAL=0;
				RADAR_TIM_CAPTURE_STA|=0X40;		//��ǲ�����������
				TIM_Cmd(RADAR_TIM,DISABLE ); 	//�رն�ʱ��5
	 			TIM_SetCounter(RADAR_TIM,0);
	 			RADAR_TIM_TIM_OCxPolarityConfig(RADAR_TIM,TIM_ICPolarity_Falling);		//CC1P=1 ����Ϊ�½��ز���
				TIM_Cmd(RADAR_TIM,ENABLE ); 	//ʹ�ܶ�ʱ��5
			}		    
		}			     	    					   
 	}
	TIM_ClearITPendingBit(RADAR_TIM, RADAR_TIM_IT_CC|TIM_IT_Update); //����жϱ�־λ
}










