#ifndef SYSTICK_H
#define SYSTICK_H

	#ifdef __cplusplus
	 extern "C" {
	#endif
		 
		#include <stddef.h>
		#include "stm32f2xx.h"

		//extern u16 runLed_Count;
		extern u16 simRun_Count;
		extern u16 rfOper_OvertimerCount; //������Ƶ�����ĳ�ʱ��
		extern u16 rfOper_DelayCount; //������Ƶ��������ʱ���� 
		extern u32 slaveack_OvertimeCount;//�����ӻ�Ӧ��ʱ
		 
		 
		void configMsTick();
		void Delay_ms(u16 time);
		 
		 
	#ifdef __cplusplus
	}
	#endif
	
#endif