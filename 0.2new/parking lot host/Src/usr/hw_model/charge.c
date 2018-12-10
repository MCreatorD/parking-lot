
#include "charge.h"
#include "i2c.h"
#include <stdio.h>

uint8_t Charger_Add=0xD6;

uint8_t System_Status_Reg=0x08;

volatile uint8_t Charger_System_Status;

uint8_t Command_Watchdog=0x8a;    //Watchdog disable,Charger timer is 8 hrs

uint8_t Command_Input_Current=0x17;   //Input Voltage Limit is 4.04V,Input Current Limit is 3A

uint8_t Command_Charge_Current=0x60;  //Fast Charge Current is 2A

uint8_t Command_Boost_Enable=0x3b;  //Boost Enable

uint8_t Command_Boost_Disable=0x1b;  //Boost Disable

uint8_t Command_Tmonitor_Disable=0x9f;  //Boost Mode temperature monitor threshold disable

//extern volatile bool Power_On;
//extern volatile bool Charge_Flash;



uint8_t Charger_Read_Status(uint8_t Reg)
{
  uint8_t Status;
	I2C_Read(I2C1, Charger_Add+1, Reg, &Status, 1);
	return Status;
}

void Charger_Boost_Disable(void)
{
	I2C_Write(I2C1, Charger_Add, 0x01, &Command_Boost_Disable, 1);
}

void Charger_Init(void)
{
	I2C_Write(I2C1, Charger_Add, 0x05, &Command_Watchdog, 1);
	I2C_Write(I2C1, Charger_Add, 0x06, &Command_Tmonitor_Disable, 1);
    I2C_Write(I2C1, Charger_Add, 0x00, &Command_Input_Current, 1);
    I2C_Write(I2C1, Charger_Add, 0x02, &Command_Charge_Current, 1);
	I2C_Write(I2C1, Charger_Add, 0x01, &Command_Boost_Enable, 1);

	Charger_System_Status=Charger_Read_Status(System_Status_Reg);
	printf("\n 08×´Ì¬¼Ä´æÆ÷£º%x\n",Charger_System_Status);
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

void charger_07_enable(void)
{
	uint8_t charger_Enable=0x4b; 
	I2C_Write(I2C1, Charger_Add, 0x07, &charger_Enable, 1);

}

int charger_status(int Status_Reg)
{
	Charger_System_Status = 0;
	Charger_System_Status=Charger_Read_Status(Status_Reg);
	return Charger_System_Status;
}
