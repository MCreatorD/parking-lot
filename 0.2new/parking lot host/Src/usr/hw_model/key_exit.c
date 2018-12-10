#include "key_exit.h"
#include <stdio.h>
//#include "gui_menu.h"
#include "main_application.h"
extern "C"  void EXTI1_IRQHandler(void);
extern "C"  void EXTI0_IRQHandler(void);
extern "C"  void EXTI9_5_IRQHandler(void);
extern "C"  void EXTI4_IRQHandler(void);



unsigned char  volatile KEY_TYPE=0;		  //当前按下的键值类型

void SW_Key_Exit_Init(void)//修改为PB9
{
	//PA1 扳机按钮 SW_KEY 按下到地
    EXTI_InitTypeDef EXTI_InitStructure;
    GPIO_InitTypeDef GPIO_InitStructure;	
 	NVIC_InitTypeDef NVIC_InitStructure;
	
	/* Enable GPIOA clock */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);								  
	/* Enable SYSCFG clock */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);	
	
	/* Configure PA1 pin as input floating */
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;	 //选择输入模式
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;     //选择上拉
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;		 //选择io
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	/* Connect EXTI Line1 to PA1 pin */
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOB, EXTI_PinSource9);

	/* Configure EXTI Line1 */
	EXTI_InitStructure.EXTI_Line    = EXTI_Line9;			   //选择路径1
	EXTI_InitStructure.EXTI_Mode    = EXTI_Mode_Interrupt;	   //选择中断模式
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising_Falling;  //选择边沿触发
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;				   //使能中断
	EXTI_Init(&EXTI_InitStructure);

	

	/* Enable and set EXTI Line1 Interrupt to the lowest priority */
	NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;   //
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);	

}


void WKUP_Key_Exit_Init(void)//POWER_KEY
{
	
    //PA0 回车按钮 POWER_KEY 按下VCC
    EXTI_InitTypeDef EXTI_InitStructure;
    GPIO_InitTypeDef GPIO_InitStructure;	
 	NVIC_InitTypeDef NVIC_InitStructure;
	
	/* Enable GPIOA clock */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);								  
	/* Enable SYSCFG clock */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);	
	
	/* Configure PA0 pin as input floating */
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;	 //选择输入模式
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;   //选择下拉
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;		 //选择io
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	/* Connect EXTI Line1 to PA0 pin */
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource0);

	/* Configure EXTI Line1 */
	EXTI_InitStructure.EXTI_Line = EXTI_Line0;			   //选择路径0
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	   //选择中断模式
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;  //选择上升沿触发
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;				   //使能中断
	EXTI_Init(&EXTI_InitStructure);

//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);

	/* Enable and set EXTI Line0 Interrupt to the lowest priority */
	NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;   //
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);	
		
}

void Key1_Oled_Exit_Init(void)//KEY1_OLED PD6
{
	//PD6 返回按钮 KEY1_OLED 按下到地
    EXTI_InitTypeDef EXTI_InitStructure;
    GPIO_InitTypeDef GPIO_InitStructure;	
 	NVIC_InitTypeDef NVIC_InitStructure;
	
	/* Enable GPIOD clock */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);								  
	/* Enable SYSCFG clock */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);	
	
	/* Configure PD6 pin as input floating */
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;	 //选择输入模式
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;     //选择上拉
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;		 //选择io
	GPIO_Init(GPIOD, &GPIO_InitStructure);
	
	/* Connect EXTI Line6 to PD6 pin */
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOD, EXTI_PinSource6);

	/* Configure EXTI Line6 */
	EXTI_InitStructure.EXTI_Line = EXTI_Line6;			   //选择路径6
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	   //选择中断模式
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;  //选择下降沿触发
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;				   //使能中断
	EXTI_Init(&EXTI_InitStructure);

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);

	/* Enable and set EXTI Line6 Interrupt to the lowest priority */
	NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;   //
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);		
}

void Key2_Oled_Exit_Init(void)//KEY2_OLED PD5
{
	//PD5 返回按钮 KEY1_OLED 按下到地
    EXTI_InitTypeDef EXTI_InitStructure;
    GPIO_InitTypeDef GPIO_InitStructure;	
 	NVIC_InitTypeDef NVIC_InitStructure;
	
	/* Enable GPIOD clock */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);								  
	/* Enable SYSCFG clock */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);	
	
	/* Configure PD6 pin as input floating */
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;	 //选择输入模式
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;     //选择上拉
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;		 //选择io
	GPIO_Init(GPIOD, &GPIO_InitStructure);
	
	/* Connect EXTI Line5 to PD5 pin */
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOD, EXTI_PinSource5);

	/* Configure EXTI Line5 */
	EXTI_InitStructure.EXTI_Line = EXTI_Line5;			   //选择路径5
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	   //选择中断模式
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;  //选择下降沿触发
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;				   //使能中断
	EXTI_Init(&EXTI_InitStructure);

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);

	/* Enable and set EXTI Line5 Interrupt to the lowest priority */
	NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;   //
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);		
}


void Key3_Oled_Exit_Init(void)//KEY3_OLED PD4
{
	//PD4 返回按钮 KEY3_OLED 按下到地
    EXTI_InitTypeDef EXTI_InitStructure;
    GPIO_InitTypeDef GPIO_InitStructure;	
 	NVIC_InitTypeDef NVIC_InitStructure;
	
	/* Enable GPIOD clock */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);								  
	/* Enable SYSCFG clock */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);	
	
	/* Configure PD4 pin as input floating */
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;	 //选择输入模式
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;     //选择上拉
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;		 //选择io
	GPIO_Init(GPIOD, &GPIO_InitStructure);
	
	/* Connect EXTI Line4 to PD4 pin */
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOD, EXTI_PinSource4);

	/* Configure EXTI Line4 */
	EXTI_InitStructure.EXTI_Line = EXTI_Line4;			   //选择路径4
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;	   //选择中断模式
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;  //选择下降沿触发
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;				   //使能中断
	EXTI_Init(&EXTI_InitStructure);

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);

	/* Enable and set EXTI Line4 Interrupt to the lowest priority */
	NVIC_InitStructure.NVIC_IRQChannel = EXTI4_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;   //
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);		
}



void ConfigureOledKey(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);								  
	/* Enable SYSCFG clock */
	//RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);	
	
	/* Configure PA1 pin as input floating */
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;	 //选择输入模式  PA1--SW
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;     //选择上拉
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;		 //选择io
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;	 //选择输入模式  PA0--POWN KEY
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;   //选择下拉
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;		 //选择io
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;	 //选择输入模式     PD6,PD5.PD4
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;     //选择上拉
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_5|GPIO_Pin_4;		 //选择io
	GPIO_Init(GPIOD, &GPIO_InitStructure);
}

//按键处理函数
//返回按键值
//mode:0,不支持连续按;1,支持连续按;
//0，没有任何按键按下
//1，KEY0按下
//2，KEY1按下
//3，KEY2按下 
//4，KEY3按下 WK_UP
//注意此函数有响应优先级,KEY0>KEY1>KEY2>KEY3!!

u8 KEY_Scan(u8 mode)
{	 
	static u8 key_up=1;//按键按松开标志
	if(mode)key_up=1;  //支持连按		  
	if(key_up&&(SW_Key==0||KEY0==0||KEY1==0||KEY2==0||WK_UP==1))
	{
//		Delay_ms(8);//去抖动 
		key_up=0;
		if(SW_Key==0)	return TRIG_DOWN;
		else if(KEY0==0)return KEY0_PRES;
		else if(KEY1==0)return KEY1_PRES;
		else if(KEY2==0)return KEY2_PRES;
		else if(WK_UP==1)return WKUP_PRES;
	}else if(SW_Key==1&&KEY0==1&&KEY1==1&&KEY2==1&&WK_UP==0)key_up=1; 	    
 	return 0;// 无按键按下
}


//void EXTI1_IRQHandler(void)//Key_Exit_Init PA1 SW_KEY
//{
//	if(EXTI_GetITStatus(EXTI_Line1) != RESET)//确保是否产生了EXTI Line中断
//	{		
//		if(SW_Key==0)
//		{
//			KEY_TYPE = TRIG_DOWN;
//			printf(" KEY_TYPE = TRIG_DOWN; \n");
//		}
//		else
//		{
//			KEY_TYPE = TRIG_UP;
//			printf("KEY_TYPE = TRIG_UP && open TIM3 \n");				
//			TIM_Cmd(TIM3, ENABLE);//读卡结束打开闭定时器
//			
//		}
////		printf("--------------EXTI1_IRQHandler------------------\n");	
//		EXTI_ClearITPendingBit(EXTI_Line1); //清除中断标志位    
//	}
//}

void EXTI0_IRQHandler(void)//Key_Exit_Init PA0 SW_KEY
{
	if(EXTI_GetITStatus(EXTI_Line0) != RESET)//确保是否产生了EXTI Line中断
	{
		KEY_TYPE = WKUP_PRES;
		EXTI_ClearITPendingBit(EXTI_Line0); //清除中断标志位    
	}	
}

void EXTI9_5_IRQHandler(void)//KEY1_OLED PD6  KEY2_OLED PD5 
{
	if(EXTI_GetITStatus(EXTI_Line5) != RESET)//确保是否产生了EXTI Line中断
	{
		KEY_TYPE = KEY1_PRES;
		EXTI_ClearITPendingBit(EXTI_Line5); //清除中断标志位    
	}	
	else if(EXTI_GetITStatus(EXTI_Line6) != RESET)
	{
		KEY_TYPE = KEY0_PRES;
		EXTI_ClearITPendingBit(EXTI_Line6); //清除中断标志位
	}
	else if(EXTI_GetITStatus(EXTI_Line9) != RESET)
	{
		if(SW_Key==0)
		{
			KEY_TYPE = TRIG_DOWN;
			printf(" KEY_TYPE = TRIG_DOWN; \n");
		}
		else
		{
			KEY_TYPE = TRIG_UP;
			printf("KEY_TYPE = TRIG_UP && open TIM3 \n");					
		}
//		printf("--------------EXTI1_IRQHandler------------------\n");	
		EXTI_ClearITPendingBit(EXTI_Line9); //清除中断标志位  		
	}
}

void EXTI4_IRQHandler(void)//KEY3_OLED PD4
{
	if(EXTI_GetITStatus(EXTI_Line4) != RESET)//确保是否产生了EXTI Line中断
	{
		KEY_TYPE = KEY2_PRES;
		EXTI_ClearITPendingBit(EXTI_Line4); //清除中断标志位    
	}	
}
