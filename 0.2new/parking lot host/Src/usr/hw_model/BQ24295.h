#ifndef __BQ24295_H
#define __BQ24295_H
#include "stm32f2xx.h"

	#ifdef __cplusplus
	 extern "C" {
	#endif
		 
	#define BQ24295_Address_W                  									0xD6 			//I2C Registers Address  6B is 7 addr need add (lsb)one R/W(0 w)   -->110 1011 (0 w  , 1  r )
	#define BQ24295_Address_R                  									0xD7 
    #define System_Status_Reg                                                   0x08		  //需要读的寄存器
		 
	#define BQ24295_In_Source_Ctrl_Reg      									0x00      //reset = 01011000, or 0x58
	#define BQ24295_Power_On_Conf_Reg        									0x01   		//reset = 00011011, or 0x1B
	#define BQ24295_Charge_Current_Ctrl_Reg  									0x02      //reset = 00100000, or 0x20
	#define BQ24295_Pre_Charge_Termination_Current_Ctrol_Reg 					0x03      //reset = 00010001, or 0x11
	#define BQ24295_Charge_Voltage Control Register REG04 						0x04      //reset = 10110010, or 0xB2
	#define BQ24295_Charge_Term_Timer_Ctrl_Reg         							0x05      //reset = 10011100, or 0x9C
	#define BQ24295_Boost_Voltage_Thermal_Regulation_Ctrl_Reg   				0x06 			//reset = 10010011, or 0x93
	#define BQ24295_Misc_Operation_Control_Register            				    0x07      //reset = 01001011, or 0x4B
	#define BQ24295_System_Status_Register 										0x08
	#define BQ24295_New_Fault_Register 											0x09
	#define BQ24295_Revision_Status_Register 									0x0A

		 
	#define Command_Watchdog 0x8a    //Watchdog disable,Charger timer is 8 hrs

    #define Command_Input_Current 0x17   //Input Voltage Limit is 4.04V,Input Current Limit is 3A  17

	#define Command_Charge_Current 0x9C  //Fast Charge Current is 2A  C0  60 

	#define Command_Boost_Enable 0x3b  //Boost Enable 11 1011 Boost mode operation is enabled (OTG pin HIGH and REG01[5:4] = 10)

	#define Command_Boost_Disable 0x1b  //Boost Disable 01 1011

	#define Battery_charge_Disable	0x0b  //Battery charging is enabled by I2C register bit (REG01[5:4]) = 01 and CE is low

	#define Battery_charge_enable	0x1b  //Battery charging is enabled by I2C register bit (REG01[5:4]) = 01 and CE is low

	#define Command_Tmonitor_Disable 0xf3  //Boost Mode temperature monitor threshold disable 1001 1111   0x9f	 

	//硬件资源PB0
	#define BQ24295_Port			    GPIOB	
	#define BQ24295_PIN           GPIO_Pin_0 
	#define BQ24295_CLK           RCC_AHB1Periph_GPIOB

	//初始化函数
	void BQ24295_Port_Init(void);
	uint8_t BQ24295_Read_Status(uint8_t Reg);
	void BQ24295_Boost_Disable(void);
	void BQ24295_Init(void);

	//方法函数
	#define BQ24295_Port_H             GPIO_SetBits(BQ24295_Port , BQ24295_PIN)
	#define BQ24295_Port_L             GPIO_ResetBits(BQ24295_Port , BQ24295_PIN)


	#ifdef __cplusplus
	}
	#endif
#endif