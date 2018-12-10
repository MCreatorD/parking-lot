#include "systick.h"
#include "timer.h"

u16 nTime = 0;
u16 tenms = 10;

u16 runLed_Count = 0; //用作运行指示灯
u16 simRun_Count = 0; //用作模拟数据运行
u16 rfOper_OvertimerCount = 0; //用作射频操作的超时。
u16 rfOper_DelayCount = 0; //用作射频操作的延时控制

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
	SysTick_Config(SystemCoreClock/1000);//1ms中断一次（系统时钟120M）
}