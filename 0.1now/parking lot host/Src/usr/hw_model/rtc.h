#ifndef _RTC_H_
#define _RTC_H_

#include "stm32f2xx.h"

	#ifdef __cplusplus
	 extern "C" {
	#endif
		 
  unsigned int getUtc();
	int setRtc(unsigned int utc);
	void RTC_TimeStampShow(void);
	void initRtc();

	#ifdef __cplusplus
	}
	#endif		 
		 
#endif
