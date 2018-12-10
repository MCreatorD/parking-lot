
#include <stdio.h>
#include "pcf8563.h"
#include "i2c.h"

//BCD --> 正常数据
unsigned char RTC_BcdToBin(unsigned char BCDValue)
{	
	unsigned char tmp = 0;		
	tmp = ((unsigned char)(BCDValue & (unsigned char)0xF0) >> (unsigned char)0x04) * 10;	
	return (tmp + (BCDValue & (unsigned char)0x0F));
}
//正常数据 --> BCD 
unsigned char RTC_BinToBcd(unsigned char BINValue)
{	
	unsigned char bcdhigh = 0;		
	while (BINValue >= 10)	
	{		
		bcdhigh++;		
		BINValue -= 10;	
	}		
	return ((unsigned char)(bcdhigh << 4) | BINValue);
}
void PrintfPCF8563Set(_PCF8563_Register_Typedef *pcf_temp)
{
  printf( "PCF8563_ContrlStatus__Reg1:%x\n", pcf_temp->Control_Status_1);
	printf( "PCF8563_ContrlStatus__Reg2:%x\n", pcf_temp->Control_Status_2);
	printf( "PCF8563_Years_Reg:%x\n", pcf_temp->Years);
	printf( "PCF8563_Months_Reg:%x\n", pcf_temp->Months_Century);
	printf( "PCF8563_WeekDays_Reg:%x\n", pcf_temp->WeekDays);
	printf( "PCF8563_Days_Reg:%x\n", pcf_temp->Days);
	printf( "PCF8563_Hours_Reg:%x\n", pcf_temp->Hours);
	printf( "PCF8563_Mnuties_Reg:%x\n", pcf_temp->Minutes);
	printf( "PCF8563_Seconds_Reg:%x\n", pcf_temp->Seconds);	
}
void PCF8563_RegisterInit(_PCF8563_Register_Typedef *pcf_temp)
{
	//PrintfPCF8563Set(pcf_temp);
	I2C_Write(I2C1, PCF8563_Write_ADDR, PCF8563_ContrlStatus__Reg1, &pcf_temp->Control_Status_1, 1);
	I2C_Write(I2C1, PCF8563_Write_ADDR, PCF8563_ContrlStatus__Reg2, &pcf_temp->Control_Status_2, 1);	
	I2C_Write(I2C1, PCF8563_Write_ADDR, PCF8563_Years_Reg, &pcf_temp->Years, 1);
	I2C_Write(I2C1, PCF8563_Write_ADDR, PCF8563_Months_Reg, &pcf_temp->Months_Century, 1);
	I2C_Write(I2C1, PCF8563_Write_ADDR, PCF8563_WeekDays_Reg, &pcf_temp->WeekDays, 1);
	I2C_Write(I2C1, PCF8563_Write_ADDR, PCF8563_Days_Reg, &pcf_temp->Days, 1);
	I2C_Write(I2C1, PCF8563_Write_ADDR, PCF8563_Hours_Reg, &pcf_temp->Hours, 1);
	I2C_Write(I2C1, PCF8563_Write_ADDR, PCF8563_Mnuties_Reg, &pcf_temp->Minutes, 1);
	I2C_Write(I2C1, PCF8563_Write_ADDR, PCF8563_Seconds_Reg, &pcf_temp->Seconds, 1);
}

uint8_t PCF8563_Time_Read(uint8_t addr)
{
  uint8_t Status = 0;
	I2C_Read(I2C1, PCF8563_Read_ADDR, addr, &Status, 1);
	return Status;
}

Pcf8563_Time_Typedef readAllPcf8563Time()
{
	uint8_t Status = 0;	
	//定义储存时间的结构体
	Pcf8563_Time_Typedef Pcf8563_Time_Structrue;
	
	Status = PCF8563_Time_Read(PCF8563_Years_Reg);
	Pcf8563_Time_Structrue.Pcf8563_Year = RTC_BcdToBin(Status);

	Status = 0;
	Status = PCF8563_Time_Read(PCF8563_Months_Reg);
	Status&=0x1f;//屏蔽无效位		
	Pcf8563_Time_Structrue.Pcf8563_Months_Century = RTC_BcdToBin(Status);

	Status = 0;
	Status = PCF8563_Time_Read(PCF8563_Days_Reg);
	Status&=0x3f;//屏蔽无效位		
	Pcf8563_Time_Structrue.Pcf8563_Days = RTC_BcdToBin(Status);
	
	Status = 0;
	Status = PCF8563_Time_Read(PCF8563_WeekDays_Reg);	
	Status&=0x07;//屏蔽无效位	
	Pcf8563_Time_Structrue.Pcf8563_WeekDays = RTC_BcdToBin(Status);
	
	Status = 0;
	Status = PCF8563_Time_Read(PCF8563_Hours_Reg);	
	Status&=0x3f;//屏蔽无效位
	Pcf8563_Time_Structrue.Pcf8563_Hours = RTC_BcdToBin(Status);
	
	Status = 0;
	Status = PCF8563_Time_Read(PCF8563_Mnuties_Reg);
	Status&=0x7f;//屏蔽无效位
	Pcf8563_Time_Structrue.Pcf8563_Minutes = RTC_BcdToBin(Status);
	
	Status = 0;
	//6 to 4 SECONS 0 to 5
	//3 to 0 SECONS 0 to 9
	Status = PCF8563_Time_Read(PCF8563_Seconds_Reg);
	Status&=0x7f;//屏蔽无效位
	Pcf8563_Time_Structrue.Pcf8563_Seconds = RTC_BcdToBin(Status);
	
//	printf("\n\rThe set date (Year-Month-Date-WeekDay) is : %0.2d-%0.2d-%0.2d-%0.2d \n"
//																													,Pcf8563_Time_Structrue.Pcf8563_Year
//																													,Pcf8563_Time_Structrue.Pcf8563_Months_Century
//																													,Pcf8563_Time_Structrue.Pcf8563_Days
//																													,Pcf8563_Time_Structrue.Pcf8563_WeekDays
//																													);
	
	return Pcf8563_Time_Structrue;
}

time_t pcf8563Utc(Pcf8563_Time_Typedef time_tmp)
{
	struct tm *gm_date;
	time_t utc =0;
	gm_date = localtime(&utc);//1970 0 1 000	
	
	gm_date->tm_year=time_tmp.Pcf8563_Year+100;//2018年,+1900就是现在的年
	gm_date->tm_mon=time_tmp.Pcf8563_Months_Century - 1;//10  - 1  9
	gm_date->tm_mday=time_tmp.Pcf8563_Days;
	gm_date->tm_wday=time_tmp.Pcf8563_WeekDays;
	gm_date->tm_hour=time_tmp.Pcf8563_Hours+8;
	gm_date->tm_min=time_tmp.Pcf8563_Minutes;
	gm_date->tm_sec=time_tmp.Pcf8563_Seconds;
	
////将本地时间转为unix timestamp 	
//	printf("\n\rThe current date (Year-Month-Date-WeekDay) is : %0.2d-%0.2d-%0.2d-%0.2d \n"
//																													,gm_date->tm_year-100
//																													,gm_date->tm_mon+1
//																													,gm_date->tm_mday
//																													,gm_date->tm_wday
//																													);	

//  printf("\n\rThe current time (hour-min-sec) is : %0.2d-%0.2d-%0.2d \n"
//																													,gm_date->tm_hour
//																													,gm_date->tm_min
//																													,gm_date->tm_sec																			
//																													);		

	utc = mktime(gm_date);
	//printf("unix timestamp:%d \r\n",utc);
	return utc;
}

int utcTotime(unsigned int utc){
	
	_PCF8563_Register_Typedef PCF8563_Register_Structrue;
	
	printf("utc:%d\n",utc);
	time_t t = utc;
	struct tm *time_date = localtime(&t);//在keil c下直接使用localtime即可转换时间，不可使用gmtime
	printf("tm_year = %d\n",(*time_date).tm_year);
	printf("tm_mon = %d\n",(*time_date).tm_mon);
	printf("tm_mday = %d\n",(*time_date).tm_mday);
	printf("tm_hour = %d\n",(*time_date).tm_hour-8);
	printf("tm_min = %d\n",(*time_date).tm_min);
	printf("tm_sec = %d\n",(*time_date).tm_sec);
	PCF8563_Register_Structrue.Control_Status_1 = 0x00;
	PCF8563_Register_Structrue.Control_Status_2 = 0x00;
	PCF8563_Register_Structrue.Years = RTC_BinToBcd((*time_date).tm_year-100);//年从2000开始算起	
	PCF8563_Register_Structrue.Months_Century = RTC_BinToBcd((*time_date).tm_mon+1);
	PCF8563_Register_Structrue.Days  = RTC_BinToBcd((*time_date).tm_mday);
	//PCF8563_Register_Structrue.WeekDays=
	PCF8563_Register_Structrue.Hours = RTC_BinToBcd((*time_date).tm_hour-8);
	PCF8563_Register_Structrue.Minutes=RTC_BinToBcd((*time_date).tm_min);
	PCF8563_Register_Structrue.Seconds=RTC_BinToBcd((*time_date).tm_sec);

	PCF8563_RegisterInit(&PCF8563_Register_Structrue);
	return 1;
}
void Pcf8563_Init()
{
	uint8_t Status;
	I2C1_Configuration();//初始化IIC PB6 PB7
	
//	_PCF8563_Register_Typedef PCF8563_Register_Structrue;
//	PCF8563_Register_Structrue.Control_Status_1 = 0x00;
//	PCF8563_Register_Structrue.Control_Status_2 = 0x11;
//	//默认时间设置
//	PCF8563_Register_Structrue.Years = 0x18;
//	PCF8563_Register_Structrue.Months_Century=0x10;
//	PCF8563_Register_Structrue.Days=0x24;  
//	PCF8563_Register_Structrue.WeekDays =0x03;                              
//	PCF8563_Register_Structrue.Hours=0x10;
//	PCF8563_Register_Structrue.Minutes=0x38;
//	PCF8563_Register_Structrue.Seconds=0x0;
//	
//	PCF8563_RegisterInit(&PCF8563_Register_Structrue);
//	
//	pcf8563Utc(readAllPcf8563Time());
}

