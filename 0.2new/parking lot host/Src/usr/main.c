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
//IO�ڳ�ʼ��
void init_gpio(void)
{
	POWER_LED_Init();//PB0 ��Դָʾ��
	BUZZER_LED_Init();//PC5	������ʾ��LED + Beep��
	GPIO_Configuration();
	
	POWER_LED_H;//��Դָʾ��
}
//�����ʼ��
void init_StdPeriph(void)
{
	//���жϷ��� 1 bits for pre-emption priority  3 bits for subpriority
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	//����printf�������õĴ��ڣ�����1��
	Printf_USART_Configuration();
	//����ͨ���õĴ��ڣ�����2��
	Comm_USART_Configuration(); 
	//������3��
	RX485_USART_Configuration();
	//��ʱ��2�ƹ���˸
  TIM2_Configuration();		       
	configMsTick();//�趨1ms��ϵͳʱ�ӵδ�
	Pcf8563_Init();
}

//5. ��FPGA �� ��ȫģ��ͨ�ſڳ�ʼ��
void init_Sm(void)
{
	//����spi
	SPI2_Init();    //��ȫģ��ͨ�ſڳ�ʼ�� Ӳ��SPI2
	SM_GPIO_Init(); //���ư�ȫģ���IO��
	//��Ƶspi
	rf_out_init();  //
	Board_SPI1_Init();	
}

//��������ʾ����
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
  EN25Q256_Init();//FLASH��ʼ��
	Rf_GPIO_Init(); //
	Cancellation_Init();
}



/*
*	main������
*/

int main(void)
{	
	//1. IO�ڳ�ʼ��
	init_gpio();
	//2. �����ʼ��
	init_StdPeriph();
	//5. ��ȫģ��ͨ�ſڳ�ʼ��
	init_Sm();	
	//7. ��ʾ���ϰ��� ��ѯģʽ
	Board_Init();
	radar_init();
	/*---------���������ϵ���ز�����ɫ��-------------*/
	LMX2541_SetFrequency(0); 
	RFPowerOFF();	
	BUZZER_LED_H;//��ɫ	
	BanisterIoInit();
	//8. ע��C++��صĳ��� NEW��ʼ�� 
	Main_Application m_MainApp;
	//---------------------ǰ������ͨ��------------------------------//		 
	printf("The system into while(1)\n");
	//printf("runing\n");
	while(1)
	{	
		m_MainApp.run();//����llrp����λ������
	}
}
