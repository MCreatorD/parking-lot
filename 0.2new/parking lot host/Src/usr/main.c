	#include <stddef.h>
//	#include <rt_heap.h>  //_init_alloc 

	#include "main.h"
	#include <string.h>
	#include "stm32f2xx.h"
	#include "system_stm32f2xx.h"
	#include "sim_spi.h"
	#include "sim_spi1.h"
	#include "spi.h"

	#include "printf_usart.h"
	#include "config.h"
	#include "systick.h"

	#include "main_application.h"
	#include "uart_bsp_comm.h"
	#include "rtc.h"
	#include "i2c.h"
	#include "charge.h"
	
	#include "buzzer_led.h"
	#include "power_led.h"
	#include "mcu_led.h"
//	#include "rt9167.h"
	#include "sm.h"
	#include "rtc.h"
	#include "EN25Q256.h"
	#include "key_exit.h"
	#include "lowpower.h"
	#include "main.h"
//	#include "ws_spi.h"
  #include "spi1.h"
  #include "testReadTag.h"
  #include "uart_bsp_comm.h"
  #include "gpio.h"
  #include "timer.h"
  #include "rx485_rev.h"
  #include "rx485_send.h"
  #include "RX485_uart.h"
  #include "communication.h"
  #include "LMX2541.h"	
  #include "rf_oper.h"	
  #include "air_interface.h"	

  #include "pcf8563.h"		
  #include "cancellation.h"
	#include <time.h>
	#include "time2.h"
	#include "radar_model.h"
	#include "banister.h"
//////////////////////////////////////////////
//IO口初始化
void init_gpio(void)
{
	POWER_LED_Init();//PB0 电源指示灯
	BUZZER_LED_Init();//PC5	读卡提示（LED + Beep）
	GPIO_Configuration();
	
	POWER_LED_H;//电源指示灯
}
//外设初始化
void init_StdPeriph(void)
{
	//总中断分组 1 bits for pre-emption priority  3 bits for subpriority
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	//配置printf命令所用的串口（串口1）
	Printf_USART_Configuration();
	//配置通信用的串口（串口2）
	Comm_USART_Configuration(); 
	//（串口3）
	RX485_USART_Configuration();
	//定时器2灯光闪烁
  TIM2_Configuration();		       
	configMsTick();//设定1ms的系统时钟滴答
	Pcf8563_Init();
}

//5. 与FPGA 和 安全模块通信口初始化
void init_Sm(void)
{
	//主控spi
	SPI2_Init();    //安全模块通信口初始化 硬件SPI2
	SM_GPIO_Init(); //控制安全模块的IO口
	//射频spi
	rf_out_init();  //
	Board_SPI1_Init();	
}

//蜂鸣器提示函数
void Beep_Times(u8 n_times)
{
	while(n_times--)
	{
		BUZZER_LED_H;	
		Delay_ms(10);
		BUZZER_LED_L;
		Delay_ms(10);		
	}
}


void Board_Init(void)
{
  EN25Q256_Init();//FLASH初始化
	Rf_GPIO_Init(); //
	Cancellation_Init();
}



/*
*	main函数。
*/

int main(void)
{	
	//1. IO口初始化
	init_gpio();
	//2. 外设初始化
	init_StdPeriph();
	//5. 安全模块通信口初始化
	init_Sm();	
	//7. 显示屏上按键 查询模式
	Board_Init();
	radar_init();
	/*---------配置主机上电关载波，绿色灯-------------*/
	LMX2541_SetFrequency(0); 
	RFPowerOFF();	
	BUZZER_LED_H;//绿色	
	BanisterIoInit();
	//8. 注册C++相关的程序 NEW初始化 
	Main_Application m_MainApp;
	//---------------------前方测试通过------------------------------//		 
	printf("The system into while(1)\n");
	//printf("runing\n");
	while(1)
	{	
		m_MainApp.run();//进行llrp的上位机控制
	}
}
