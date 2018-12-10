#include "testReadTag.h"
#include "systick.h"
//#include "ws_spi.h"
#include <stdio.h>
#include "spi.h"
#include "sm.h"
//读卡结束标志位
uint8_t readTagFlag = 0;

void waitSafeFalling(void)
{
    while(GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_0)==1)
    {
        ;
    }
}

uint8_t CreateReadTagConfig(u8* buff)
{	
	  buff[0]=0xaa; //同步头 接收数据取值0xAA,上报数据取值0xAB
    buff[1]=0x11; //帧类型 0001 配置帧 0001版本号
    buff[2]=9;    //帧长度 9
    buff[3]=0;    //帧长度
    buff[4]=0x06; //帧内容 操作标识 （6）工作模式
    buff[5]=0;    //读分区数量 0 （表示识读TID工作模式，不读取任何分区数据）
    buff[6]=0x00; //分区号 user_0
    buff[7]=0x02; //分区访问指示 行标指令读取全区数据
    buff[8]=0x01; //0000 密文   0001 高速读
    buff[9]=0;    //
    buff[10]=0;
    buff[11]=0;
    buff[12]=0;
    buff[13]=XOR_Cal(&buff[1],12); //校验码
    return 14;
}

uint8_t CreateReaduser0TagConfig(u8* buff)
{
	//aa,11,09,00,06,01,00,02,01,00,00,00,00,1c
	  buff[0]=0xaa; //同步头 接收数据取值0xAA,上报数据取值0xAB
    buff[1]=0x11; //帧类型 0001 配置帧 0001版本号
    buff[2]=0x09;    //帧长度 9
    buff[3]=0x00;    //帧长度
    buff[4]=0x06; //帧内容 操作标识 （6）工作模式
    buff[5]=0x01;    //读分区数量 0 （表示识读TID工作模式，不读取任何分区数据）
    buff[6]=0x00; //分区号 user_0
    buff[7]=0x02; //分区访问指示 行标指令读取全区数据
    buff[8]=0x01; //0000 密文   0001 高速读
    buff[9]=0x00;    //
    buff[10]=0x00;
    buff[11]=0x00;
    buff[12]=0x00;
	  buff[13]=0x1c;
    return 14;
}

uint8_t ConfigSmReadTID()//配置是否完成的标志位   1代表配置成功
{
		uint8_t ConfLen; 
		uint8_t ConfigBuff[50];
	    uint8_t RecSafe[256];
	    u8 tmp = 1;
	 // static uint8_t ConfigFlag = 0;
	 //	if(ConfigFlag == 0)
	 //	{
			//SysTick->CTRL  &= ~SysTick_CTRL_ENABLE_Msk;//配置过程防止干扰关闭滴答定时器
			ConfLen=CreateReadTagConfig(ConfigBuff);//配置识读TID工作模式帧
			SPI2_Send_bytes(ConfigBuff,ConfLen);    //发送到安全模块
			printf("waite SM reback \n");
			rfOper_OvertimerCount = 2000;
			while(tmp &&  rfOper_OvertimerCount)
			{
				//printf("rfOper_OvertimerCount:%d\n",rfOper_OvertimerCount);
				tmp = SM_CTRL;
			}
			SPI2_Receive_bytes(RecSafe,7);//接收安全模块的数据上报
			if(RecSafe[5] == 0)
			printf("SM config success \n");
			else
			printf("SM config fall    \n");
			
			//SysTick->CTRL  |= SysTick_CTRL_ENABLE_Msk;//配置结束 开启滴答定时器
			//ConfigFlag=1;		
		//}

		//return ConfigFlag;
}


uint8_t ConfigSmReadUser0()//配置是否完成的标志位   1代表配置成功
{
		uint8_t ConfLen; 
		uint8_t ConfigBuff[50];
		uint8_t RecSafe[256];
	    u8 tmp = 1;
	  //static uint8_t ConfigFlag = 0;
	  //if(ConfigFlag == 0)
	  //{
			//SysTick->CTRL  &= ~SysTick_CTRL_ENABLE_Msk;//配置过程防止干扰关闭滴答定时器
			ConfLen=CreateReaduser0TagConfig(ConfigBuff);//配置识读TID工作模式帧
			SPI2_Send_bytes(ConfigBuff,ConfLen);    //发送到安全模块
			printf("waite SM reback \n");
			//检测CRTL_OUT 等待安全模块的数据上报 
			rfOper_OvertimerCount = 2000;
			while(tmp &&  rfOper_OvertimerCount)
			{
				//printf("rfOper_OvertimerCount:%d\n",rfOper_OvertimerCount);
				tmp = SM_CTRL;
			}
			
			SPI2_Receive_bytes(RecSafe,7);//接收安全模块的数据上报
			if(RecSafe[5] == 0)
			printf("SM config success \n");
			else
			printf("SM config fall    \n");
			
			//SysTick->CTRL  |= SysTick_CTRL_ENABLE_Msk;//配置结束 开启滴答定时器
	       //ConfigFlag=1;		
	  //}

	  //return ConfigFlag;
}


	


