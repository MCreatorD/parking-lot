/**
*     雷达监测车位是否有车识别
*/
#include "radar_model.h"
#include "systick.h"
#include <stdio.h>

//雷达模块初始化 定时器输入捕获
//arr：自动重装值(TIM2,TIM5是32位的!!)
//psc：时钟预分频数
void radar_init()
{
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	TIM_ICInitTypeDef  TIM_ICInitStructure;
	
	RADAR_TIM_RCC_APBxPeriphClockCmd(RADAR_TIM_CLK,ENABLE);  	//TIM5时钟使能    
	RCC_AHB1PeriphClockCmd(RADAR_PIN_R_CLK, ENABLE); 	//使能PORTA时钟	
	RCC_AHB1PeriphClockCmd(RADAR_PIN_T_CLK, ENABLE); 	//使能PORTA时钟	
	
	GPIO_InitStructure.GPIO_Pin = RADAR_PIN_R; //GPIOA0
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;//复用功能
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	//速度100MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; //推挽复用输出
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN; //下拉
	GPIO_Init(RADAR_PIN_R_Port,&GPIO_InitStructure); //初始化PA0

	GPIO_PinAFConfig(RADAR_PIN_R_Port,RADAR_TIM_PinSource,RADAR_AF_TIM); //PA0复用位定时器5
	//雷达模块初始化 延时产生脉冲
	GPIO_InitStructure.GPIO_Pin =  RADAR_PIN_T;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;           
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;  //推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;  
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_DOWN;   //
	GPIO_Init(RADAR_PIN_T_Port, &GPIO_InitStructure);	  
	  
	
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up; //向上计数模式
	//TIM_TimeBaseStructure.TIM_Period=arr;   //自动重装载值
	//TIM_TimeBaseStructure.TIM_Prescaler=psc;  //定时器分频	
  TIM_TimeBaseStructure.TIM_Period = 0XFFFFFFFF;
  TIM_TimeBaseStructure.TIM_Prescaler = RADAR_TIM_Prescaler-1;	
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
	
	TIM_TimeBaseInit(RADAR_TIM,&TIM_TimeBaseStructure);
	

	//初始化TIM5输入捕获参数
	TIM_ICInitStructure.TIM_Channel = RADAR_TIM_Channel; //CC1S=01 	选择输入端 IC1映射到TI1上
  TIM_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;	//上升沿捕获
  TIM_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI; //映射到TI1上
  TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;	 //配置输入分频,不分频 
  TIM_ICInitStructure.TIM_ICFilter = 0x00;//IC1F=0000 配置输入滤波器 不滤波
  TIM_ICInit(RADAR_TIM, &TIM_ICInitStructure);
		
	TIM_ITConfig(RADAR_TIM,TIM_IT_Update|RADAR_TIM_IT_CC,ENABLE);//允许更新中断 ,允许CC1IE捕获中断	
	
  //TIM_Cmd(RADAR_TIM,ENABLE ); 	//使能定时器5

 
  NVIC_InitStructure.NVIC_IRQChannel = RADAR_TIM_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=2;//抢占优先级3
	NVIC_InitStructure.NVIC_IRQChannelSubPriority =0;		//子优先级3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);	//根据指定的参数初始化VIC寄存器、
	
	
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



//捕获状态
//[7]:0,没有成功的捕获;1,成功捕获到一次.
//[6]:0,还没捕获到低电平;1,已经捕获到低电平了.
//[5:0]:捕获低电平后溢出的次数(对于32位定时器来说,1us计数器加1,溢出时间:4294秒)
u8  RADAR_TIM_CAPTURE_STA=0;	//输入捕获状态		    				
u32	RADAR_TIM_CAPTURE_VAL;	//输入捕获值(TIM2/TIM5是32位)


//雷达模块发出脉冲 ,检测脉宽,输出数据
unsigned short int radar_read()
{
		long long temp=0; 	
	  unsigned short int s= 0;
	  unsigned int overTime = 0;
	  printf("send pwm\n");	
    TIM_Cmd(RADAR_TIM,ENABLE ); 	//使能定时器5	
		send_pwm();
		//发出脉冲后等待高脉冲数据的采样完成
		while((!(RADAR_TIM_CAPTURE_STA&0X80)) && (overTime<0xff))
		{
			delay(0x0fff);//延时检测是否完成脉冲采样
			overTime++; //大于一定时间超时
		}
		if(RADAR_TIM_CAPTURE_STA&0X80)        //成功捕获到了一次高电平
		{
			temp=RADAR_TIM_CAPTURE_STA&0X3F; 
			temp*=0XFFFFFFFF;		 		         //溢出时间总和
			temp+=RADAR_TIM_CAPTURE_VAL;		   //得到总的高电平时间
			//printf("HIGH:%lld us\r\n",temp); //打印总的高点平时间
			s=temp/58;
			printf("s= %d cm\r\n",s);       //打印测量距离
			RADAR_TIM_CAPTURE_STA=0;			     //开启下一次捕获
		  TIM_Cmd(RADAR_TIM,DISABLE ); 	//失能定时器5				
			return s;
		}	
		TIM_Cmd(RADAR_TIM,DISABLE ); 	//失能定时器5			
		return 0;
}


//定时器5中断服务程序	 
void RADAR_TIM_IRQHandler(void)
{ 		    
 	if((RADAR_TIM_CAPTURE_STA&0X80)==0)//还未成功捕获	
	{
		if(TIM_GetITStatus(RADAR_TIM, TIM_IT_Update) != RESET)//溢出
		{	     
			if(RADAR_TIM_CAPTURE_STA&0X40)//已经捕获到高电平了
			{
				if((RADAR_TIM_CAPTURE_STA&0X3F)==0X3F)//高电平太长了
				{
					RADAR_TIM_CAPTURE_STA|=0X80;		//标记成功捕获了一次
					RADAR_TIM_CAPTURE_VAL=0XFFFFFFFF;
				}else RADAR_TIM_CAPTURE_STA++;
			}	 
		}
		if(TIM_GetITStatus(RADAR_TIM, RADAR_TIM_IT_CC) != RESET)//捕获1发生捕获事件
		{	
			if(RADAR_TIM_CAPTURE_STA&0X40)		//捕获到一个下降沿 		
			{	  			
				RADAR_TIM_CAPTURE_STA|=0X80;		//标记成功捕获到一次高电平脉宽
			  RADAR_TIM_CAPTURE_VAL=RADAR_TIM_GetCapture(RADAR_TIM);//获取当前的捕获值.
	 			RADAR_TIM_TIM_OCxPolarityConfig(RADAR_TIM,TIM_ICPolarity_Rising); //CC1P=0 设置为上升沿捕获
			}else  								//还未开始,第一次捕获上升沿
			{
				RADAR_TIM_CAPTURE_STA=0;			//清空
				RADAR_TIM_CAPTURE_VAL=0;
				RADAR_TIM_CAPTURE_STA|=0X40;		//标记捕获到了上升沿
				TIM_Cmd(RADAR_TIM,DISABLE ); 	//关闭定时器5
	 			TIM_SetCounter(RADAR_TIM,0);
	 			RADAR_TIM_TIM_OCxPolarityConfig(RADAR_TIM,TIM_ICPolarity_Falling);		//CC1P=1 设置为下降沿捕获
				TIM_Cmd(RADAR_TIM,ENABLE ); 	//使能定时器5
			}		    
		}			     	    					   
 	}
	TIM_ClearITPendingBit(RADAR_TIM, RADAR_TIM_IT_CC|TIM_IT_Update); //清除中断标志位
}










