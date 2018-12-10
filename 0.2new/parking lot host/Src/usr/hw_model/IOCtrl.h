/*
 * IOCtrl.h
 *
 *  Created on: 2016-3-9
 *      Author: root
 */

#ifndef IOCTRL_H_
#define IOCTRL_H_

#include "general.h"
#include "gpio.h"
#include "sm.h"

#define STATUS_INT_VALUE 100   //在1.0硬件中，对应gpio(0,29)脚
#define CTRLOUT_INT_VALUE 101 //在1.0硬件中，对应gpio(3,0)脚




/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
*	by lijin,2018.01.08
*	IO口控制类
*/


class IOCtrl {
public:
	IOCtrl();
	virtual ~IOCtrl();

public:
	void changeEPCSIOin();
	void changeEPCSIOout();

	void resetSecureModule();
	void setSMResetHigh();
	void setSMResetLow();

	int readSMIntLv(int intid);
  void setSMPower(int On_OFF);

	void disableRfModule();
	void enableRfModule();

	void disableFPGA();
	void enableFPGA();

  void setSPI0_DIR(int dir); //2.0新加，用以选择SPI0数据口是连至FPGA，还是FGPA的程序存贮器,0为输出到FPGA

	void setSingleEnd(int value);

public:
	//2017.07.26新增，读取FPGA IO脚
	int readFPGAIO(int ioid);
};

#endif /* IOCTRL_H_ */
