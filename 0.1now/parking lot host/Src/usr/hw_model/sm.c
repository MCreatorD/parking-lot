#include "sm.h"
#include "gpio.h"
#include "systick.h"
void SM_GPIO_Init(void)
{  
  GPIO_InitTypeDef GPIO_InitStruct;
	
	/* Enable GPIO TX/RX clock */
	
	SM_RESET_ENABLE();
	SM_STATUS_ENABLE();
	SM_CTRL_ENABLE();
	
	GPIO_InitStruct.GPIO_Pin       = SM_RESET_OUT_IO;
  GPIO_InitStruct.GPIO_Mode      = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_InitStruct.GPIO_Speed     = GPIO_Speed_100MHz;
	GPIO_Init(SM_RESET_Port, &GPIO_InitStruct);	
  
	GPIO_InitStruct.GPIO_Pin       = SM_STATUS_IN_IO;
  GPIO_InitStruct.GPIO_Mode      = GPIO_Mode_IN;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;//GPIO_PuPd_NOPULL;
  GPIO_InitStruct.GPIO_Speed     = GPIO_Speed_100MHz;
	GPIO_Init(SM_STATUS_Port, &GPIO_InitStruct);	
	
	GPIO_InitStruct.GPIO_Pin       = SM_CTRL_IN_IO;
  GPIO_InitStruct.GPIO_Mode      = GPIO_Mode_IN;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;//GPIO_PuPd_NOPULL;
  GPIO_InitStruct.GPIO_Speed     = GPIO_Speed_100MHz;
	GPIO_Init(SM_CTRL_Port, &GPIO_InitStruct);	
	
	
	__nop();
	
}

////安全模块复位
//void Safe_module_Init()
//{
//    Board_EXIO_Init(0x08); //1000 0000
//    Delay_ms(4);
//    Board_EXIO_Init(0x0C); //0000 1100
//}
