#include "stmflash.h"
#include "stm32f2xx.h"
#include "BspTime.h"
#include "common.h"
#include "bsp_uart_update.h"
#include "delay.h"

/*************外部变量****************/
extern pFunction Jump_To_Application;
extern uint32_t JumpAddress;
/***********************************/
int main(void) 	
{  
	DownLoad_USART_Configuration();	
	BspTim2Init();
	delay_init();
  SerialPutString("进入bootloader V1.1\r\n");//116k
  Main_Menu ();       
	if (((*(__IO uint32_t*)ApplicationAddress) & 0x2FFE0000 ) == 0x20000000)
	{
      //SerialPutString("Execute user Program\r\n\n");
			BspTim2Close();
			//跳转至用户代码
			JumpAddress = *(__IO uint32_t*) (ApplicationAddress + 4);
			Jump_To_Application = (pFunction) JumpAddress;

		
			__set_MSP(*(__IO uint32_t*) ApplicationAddress);
			Jump_To_Application();
	}
	else
	{
			SerialPutString("no user Program\r\n\n");
	}
	
  while(1); 
}
