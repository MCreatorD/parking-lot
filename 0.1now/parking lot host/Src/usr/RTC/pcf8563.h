#ifndef __PFC8563_H
#define __PFC8563_H
#include <time.h>
/*
* 400KHZ 00H  01H  contorl and satus
* 地址 A3 A2
* 寄存器数据全部都是BCD码
*/
//地址 address
#define  PCF8563_Write_ADDR 0xA2
#define  PCF8563_Read_ADDR  0xA3

//寄存器 registers
#define  PCF8563_ContrlStatus__Reg1  0x00
#define  PCF8563_ContrlStatus__Reg2  0x01

#define  PCF8563_Seconds_Reg  0x02
#define  PCF8563_Mnuties_Reg  0x03
#define  PCF8563_Hours_Reg    0x04
#define  PCF8563_Days_Reg     0x05
#define  PCF8563_WeekDays_Reg 0x06
#define  PCF8563_Months_Reg   0x07
#define  PCF8563_Years_Reg    0x08
/** 
  * @brief   _PCF8563_Register_Typedef Init structure definition  
  */ 
typedef struct
{
	unsigned char Control_Status_1;
	unsigned char Control_Status_2;
	unsigned char Years;
	unsigned char Months_Century;
	unsigned char WeekDays;
	unsigned char Days;
	unsigned char Hours;
	unsigned char Minutes;
	unsigned char Seconds;
}_PCF8563_Register_Typedef;

typedef struct
{
	unsigned char Pcf8563_Year;  
	unsigned char Pcf8563_Months_Century;  
	unsigned char Pcf8563_Days;  
	unsigned char Pcf8563_WeekDays;  
	unsigned char Pcf8563_Hours;  
	unsigned char Pcf8563_Minutes;  
	unsigned char Pcf8563_Seconds;  
}Pcf8563_Time_Typedef; 


	#ifdef __cplusplus
	 extern "C" {
	#endif
		Pcf8563_Time_Typedef readAllPcf8563Time(); 
		void Pcf8563_Init();
		time_t pcf8563Utc(Pcf8563_Time_Typedef time_tmp);
		int utcTotime(unsigned int utc);
		 
	#ifdef __cplusplus
	}
	#endif
#endif