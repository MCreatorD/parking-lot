#ifndef __TESTREADTAG_H
#define __TESTREADTAG_H

#include "stm32f2xx.h"

#ifdef __cplusplus
 extern "C" {
#endif
extern uint8_t readTagFlag;
	 
uint8_t ConfigSmReadTID();//�����Ƿ���ɵı�־λ   1�������óɹ�
uint8_t ConfigSmReadUser0();	 
uint8_t  frequencyTag(void);//��Ƶ����
void stopFrequencyTag(void);//ֹͣ����
#ifdef __cplusplus
}
#endif

#endif