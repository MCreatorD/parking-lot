#ifndef _CHARGE_H_
#define _CHARGE_H_

#include "stm32f2xx.h"

	#ifdef __cplusplus
	 extern "C" {
	#endif

		 uint8_t Charger_Read_Status(uint8_t Reg);
		 void Charger_Boost_Disable(void);
		 void Charger_Init(void);
		 int charger_status(int Status_Reg);
		 void charger_07_enable(void);

	#ifdef __cplusplus
	}
	#endif	

#endif