#include "systick.h"
#include "timer.h"

u16 nTime = 0;
u16 tenms = 10;

u16 runLed_Count = 0; //��������ָʾ��
u16 simRun_Count = 0; //����ģ����������
u16 rfOper_OvertimerCount = 0; //������Ƶ�����ĳ�ʱ��
u16 rfOper_DelayCount = 0; //������Ƶ��������ʱ����

void SysTick_Handler(void)
{
	if(tenms>0){
		tenms--;
	}else{
		TimingDelay_Decrement();
		tenms = 10;
	}
		
	
	
	if(nTime>0){
		nTime--;
	}
	
	if(runLed_Count>0){
		runLed_Count--;
	}
	
	if(simRun_Count>0){
		simRun_Count--;
	}
	
	if(rfOper_OvertimerCount>0){
		rfOper_OvertimerCount--;
	}
	
	if(rfOper_DelayCount>0){
		rfOper_DelayCount--;
	}
	
}

void Delay_ms(u16 time)
{
	 nTime = time;
	 while(nTime);
}

void configMsTick(){
	SysTick_Config(SystemCoreClock/1000);//1ms�ж�һ�Σ�ϵͳʱ��120M��
}