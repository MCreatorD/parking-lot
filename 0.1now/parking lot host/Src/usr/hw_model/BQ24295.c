#include "BQ24295.h"
#include "i2c.h"

uint8_t REG_TEMP = 0;
void Battery_Charge_CE_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOE, &GPIO_InitStructure);//PE8 充电使能脚
}

	

uint8_t BQ24295_Read_Status(uint8_t Reg)
{
    uint8_t Status;
	I2C_Read(I2C1, BQ24295_Address_R, Reg, &Status, 1);
	return Status;
}

void BQ24295_Boost_Disable(void)
{  
	REG_TEMP = Command_Boost_Disable;       //Boost Disable
	I2C_Write(I2C1, BQ24295_Address_W, BQ24295_Power_On_Conf_Reg, &REG_TEMP, 1);  //01   1b
	GPIO_SetBits(GPIOE , GPIO_Pin_8); //不充电
}
/*
* 			Boost Mode Operation from Battery
*@ BAT above BATLOWV threshold (VBATLOWV set by REG04[1])
*@ VBUS less than VBAT + VSLEEP (in sleep mode
*@ Boost mode operation is enabled (OTG pin HIGH and REG01[5:4] = 10)
*@ 
*/
void BQ24295_Mode_VBAT()
{
	
}

void BQ24295_Init(void)
{
	I2C1_Configuration();//BQ24295由IIC1协议控制所以先初始化IIC1
	Battery_Charge_CE_Init(); //充电使能脚初始化
	
	REG_TEMP = Command_Watchdog;
	I2C_Write(I2C1, BQ24295_Address_W, BQ24295_Charge_Term_Timer_Ctrl_Reg, &REG_TEMP, 1);
	
	REG_TEMP = Command_Tmonitor_Disable;
	I2C_Write(I2C1, BQ24295_Address_W, BQ24295_Boost_Voltage_Thermal_Regulation_Ctrl_Reg, &REG_TEMP, 1);
	
	REG_TEMP = Command_Input_Current;
  I2C_Write(I2C1, BQ24295_Address_W, BQ24295_In_Source_Ctrl_Reg, &REG_TEMP, 1);
	
	REG_TEMP = Command_Charge_Current;
  I2C_Write(I2C1, BQ24295_Address_W, BQ24295_Charge_Current_Ctrl_Reg, &REG_TEMP, 1);

//Battery charging is enabled by I2C register bit (REG01[5:4]) = 01 and CE is low
//	REG_TEMP = Command_Boost_Enable;
	REG_TEMP = Battery_charge_enable;
	I2C_Write(I2C1, BQ24295_Address_W, BQ24295_Power_On_Conf_Reg, &REG_TEMP, 1);
	GPIO_ResetBits(GPIOE , GPIO_Pin_8); //充电使能
//  Charger_System_Status=Charger_Read_Status(System_Status_Reg);
//	Charger_System_Status=(Charger_System_Status>>4)&0x03;
//	if((Charger_System_Status==0x00)||(Charger_System_Status==0x03))
//	{
//  GPIO_SetBits(POWER_LED_PORT,POWER_LED_PIN);
//	Charge_Flash=false;
//	}
//	else{
//  Charge_Flash=true;
//	}
}