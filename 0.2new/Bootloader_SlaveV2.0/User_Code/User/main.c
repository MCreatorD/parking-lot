#include "stmflash.h"
#include "stm32f2xx.h"
#include "BspTime.h"
#include "common.h"
#include "bsp_uart_update.h"
#include "delay.h"
#include "iap.h"
#include "flash_download.h"
/*************外部变量****************/
extern pFunction Jump_To_Application;
extern uint32_t JumpAddress;
/***********************************/
int main(void) 	
{  
	DownLoad_USART_Configuration();	
	EN25Q256_Init();
	BspTim2Init();
	delay_init();
    SerialPutString("Slave bootloader V2.0\r\n");//116k
    Main_Menu ();  
	BspTim2Close();//关闭倒计时
	iap_load_app(ApplicationAddress);
	SerialPutString("no user Program\r\n\n");	
	while(1); 
}
