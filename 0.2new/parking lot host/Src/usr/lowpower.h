#ifndef __LOWPOWER_H__
#define __LOWPOWER_H__

/* Includes ------------------------------------------------------------------*/
#include "stm32f2xx.h"

	#ifdef __cplusplus
	 extern "C" {
	#endif
		 
	void init_lowpower();		 
	void lowpower();	
	void PWR_STOP();		 
	void SoftReset(void);		
		 
	#ifdef __cplusplus
	}
	#endif	

#endif				 