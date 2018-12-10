#ifndef __TESTREADTAG_H
#define __TESTREADTAG_H

#include "stm32f2xx.h"

#ifdef __cplusplus
 extern "C" {
#endif
extern uint8_t readTagFlag;
	 
uint8_t ConfigSmReadTID();//配置是否完成的标志位   1代表配置成功
uint8_t ConfigSmReadUser0();	 
uint8_t  frequencyTag(void);//跳频读卡
void stopFrequencyTag(void);//停止读卡
#ifdef __cplusplus
}
#endif

#endif