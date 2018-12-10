#include <String.h>
#include <stdint.h>
#include <stdio.h>
#include "printf_usart.h"
#include "systick.h"
#include "LMX2541.h"
#include "cancellation.h"
#include "epc.h"
#include "ADC.h"
#include "rf_oper.h"
#include "READ_LED.h"
#include "EN25Q256.h"
#include "air_interface.h"
#include "rx485_send.h"
#include "RX485_uart.h"
#include "communication.h"
#include "time2.h"
#include "flashmanage.h"
#include "read_led_manage.h"
#include "radar_model.h"
#include "main.h"
u8  ReadCard_Flg=0;
u32 ReadCard_Count=0;
//外设初始化
void init_StdPeriph(void)
{
	//总中断分组 1 bits for pre-emption priority  3 bits for subpriority
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	
	//配置printf命令所用的串口（串口3）
	Printf_USART_Configuration();  //1   3
	      
	configMsTick();//设定1ms的系统时钟滴答	
	//printf("Printf_USART_Configuration finish!\n");	
}
u8 SelectStep = 0;
u8 hasCar = 0;
void  isturehasTag(u8 bState)
{
	//第一次读取到标签
	//开始倒计时，1s检测一次是否有标签有则闪烁，
	//5s后依旧可以读到确定有车,5s后没有则认为是车经过
	switch(SelectStep)
	{
		case 0: 
		{ //第一次读取到标签
			if( bState == GL_OK ||bState == GL_OVER )
			{
				printf("....................Has car coming....................\n");
				//启动定时器
		    TIM_Cmd(TIM2, ENABLE);//使能TIMx 
				hasCar = 0;
				//算第一次轮询
				ReadCard_Count = 0;
				SelectStep = 1;
			}	
		}		
		break;
		case 1:
		{
			if(ReadCard_Count <= m_slave.readcarthreshold)//10轮之后 在连续 连续读取到的次数作为判别依据
			{
				if( bState == GL_OK ||GL_OVER == bState)
				{			
          hasCar++;				
				}		
			  printf("ReadCard_Count :%d,hasCar:%d\n",ReadCard_Count,hasCar);		
	  	}
			if((ReadCard_Count>=m_slave.readcarthreshold) || hasCar >= 1)//(m_slave.readcarthreshold/2))//10轮之后统计下次数是否满足要求
			{
			  TIM_Cmd(TIM2, DISABLE);//失能TIMx 
				if(hasCar >= 1)//(m_slave.readcarthreshold/2))//10次读取到一半就算在
				{
					led_h;//红色
					SelectStep = 2;		
					ReadCard_Count = 0;
					printf("....................Have car standby....................\n");
			    printf("ReadCard_Count :%d,hasCar:%d\n",ReadCard_Count,hasCar);					
				}else{
			  	led_l;//绿色						  //没有车显示绿色
					SelectStep = 0;	//重新等待	
					printf("....................Don't have car....................\n");	
				}			
			}
	  }
		break;
		
		case 2://确定有车后检测是否依旧在
		{
				printf("ReadCard_Count :%d\n",ReadCard_Count);
				//从有车后每5次都不在则认为真的离开了
				if( (bState == GL_OK ||GL_OVER == bState) && ReadCard_Count<m_slave.readcarthreshold)//认为在
				{	
					ReadCard_Count = 0;
					led_h;//红色
					printf("....................The car still....................\n");			
				}
				else if(ReadCard_Count >= m_slave.readcarthreshold)
				{
					printf("....................The car leave....................\n");							
				  //没有车显示绿色
			  	led_l;//绿色
		  		SelectStep = 0;									
				}
		}
		break;
	}
}

void runModeChange(u8 runmode,u8 bState)
{
		if (runmode == 0)//运行的灯光模式判断
		{
			//1.关闭定时器
			TIM_Cmd(TIM2, DISABLE);//使能TIMx 
			//2.清空标志位
			SelectStep = 0;//正式模式下来控制灯光确定流程控制变量
			hasCar = 0;		 //第二步的确定有车或者确定没有车
			
			if( bState == GL_OK ||bState == GL_OVER)
			{
					//读取到显示红色
					led_h;//红色
			}
			else
			{
					led_l;//绿色
			}					
		}else{
			isturehasTag(bState);//车位在位检测
		}	
}

void needcancell()
{
	if(isneedCancelltion == 1)
	{
		printf("Cancellation..\n");
		//开启功放，进行一次对消
		RFPowerON(m_slave.RF_Power);	
		//设定锁相环
		LMX2541_SetFrequency(m_slave.RF_Frequency);   
		Cancellation();
		RFPowerOFF();		
		isneedCancelltion = 0;
		configcancellparam(min_SquDAValue);
		MCU_To_MCU(m_slave.Slave_Addr,ConfigCancellationAck);//对消结束应答
		printf("Cancellation.. RFPowerOFF \n");
	}	
}
int main(void)
{
	//板上资源初始化
	init_StdPeriph();
	Rf_GPIO_Init(); //射频单元初始化
	RX485_USART_Configuration();		
	Cancellation_Init();       //对消部分的初始化
	led_init;                //读卡指示灯
	radar_init();
	printf("Reader head start...\n");		
	EN25Q256_Init();               //外部FLASH定义		
	flashmanageinit();

	////////////////////////////////////////////
	//设定锁相环
	LMX2541_SetFrequency(m_slave.RF_Frequency);   
	led_l;//关闭读卡指示灯
	RFPowerOFF();//关载波	
	TIM2_Configuration();
	
	uint8_t bState = 0;
	uint8_t s_cm = 0; 
  uint8_t send_radar = 0;
	while(1)
	{
		if(ReadCard_Flg==1)  //主机下发从机开始读卡
		{
			if(send_radar == 1)
			{
				send_radar = 0;
				#ifdef __radar
				MCU_To_MCU(m_slave.Slave_Addr,GetRadarDistanceAck);//查询雷达测距数值cm应答	
				#endif
			}
						
			bState = ReadTag();		
			ReadCard_Flg = 0;//从机只读一次		
			runModeChange(m_slave.Led_Mode,bState);				
		}else{
			if(send_radar == 0)
			{
				send_radar = 1;//有雷达数据
				#ifdef __radar
				m_slave.radar_distance	=	radar_read();
				#endif				
			}
		}
		needcancell();//是否需要对消
		RS485_TX_L; //DE
		RS485_RX_L; //REn			
 }
}





