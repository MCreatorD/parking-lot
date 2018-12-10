#include "lowpower.h"

//待机模式和PA0唤醒

void init_lowpower()
{
    //开启电源管理的单元的时钟
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR, ENABLE);	
    /*清除WU状态位*/
    PWR_ClearFlag (PWR_FLAG_WU);
    /* 使能WKUP引脚的唤醒功能 ，使能PA0  WKUP引脚上升沿*/
    PWR_WakeUpPinCmd (ENABLE);	
}

void lowpower()//进入待机模式
{
       /* 进入待机模式 WKUP引脚上升沿唤醒*/
	   //关闭其他器件的电源
	   //1.关闭FPGA电
//	   FPGA_PWR_EN_L;//相关射频电也就断了
     PWR_EnterSTANDBYMode();	
}

void PWR_STOP()//停止模式
{
	//关闭其他器件的电源
	//1.关闭FPGA电
//	FPGA_PWR_EN_L;//相关射频电也就断了
	PWR_EnterSTOPMode(PWR_Regulator_ON, PWR_STOPEntry_WFI);  //停机模式
	SystemInit();//退出低功耗后的时钟重新配
	
}

//软件复位
void SoftReset(void)
{
	__set_FAULTMASK(1); // 关闭所有中断
	NVIC_SystemReset(); // 复位
}

            

            
