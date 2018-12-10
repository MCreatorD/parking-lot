/*
 * IOCtrl.cpp
 *
 *  Created on: 2016-3-9
 *      Author: root
 */
#include <stdio.h>
#include "IOCtrl.h"
#include "systick.h"
#include "main_application.h"
IOCtrl::IOCtrl() {
	// TODO Auto-generated constructor stub

}

IOCtrl::~IOCtrl() {
	// TODO Auto-generated destructor stub
}

/**
 * @brief IOCtrl::changeIOin
 * 改变flash片选脚为输出或输入，以消除片选脚对FPGA的影响
 */
void IOCtrl::changeEPCSIOin(){

}

void IOCtrl::changeEPCSIOout(){

}

void IOCtrl::setSMResetHigh(){
	SM_RESET_H;
}

void IOCtrl::setSMResetLow(){
	SM_RESET_L;
}

void IOCtrl::setSMPower(int On_OFF){

}

int IOCtrl::readSMIntLv(int intid){
		int res = 0;
    if(intid==STATUS_INT_VALUE){
      if(SM_STATUS==RESET){ //这里要注意，因为库函数的BUG，这里必须用RESET来判断
				res = 0;
			}else{
				res = 1;
			}
    }else if(intid==CTRLOUT_INT_VALUE){
			if(SM_CTRL==RESET){
				res = 0;
			}else{
				res = 1;
			}
    }
		return res;
}

void IOCtrl::resetSecureModule(){
	SM_RESET_L;
	Delay_ms(500);
	SM_RESET_H;
	Delay_ms(500);
}

/**
*	停止射频操作
*/
void IOCtrl::disableRfModule(){
//	FPGA_START_H;
	// MCU_CAN_Send(MASTER_ID,STOP_RD_CARD,0x00,4) ;
}

/**
* 开启射频操作
*/
void IOCtrl::enableRfModule(){
	//开始读卡
	g_pMainApplication->m_read_manage->start_read();
}

/**
* 禁用FPGA，实际就是关闭FPGA电源
*/
void IOCtrl::disableFPGA(){
//	FPGA_POWER_L;
}

/**
* 启用FPGA，实际就是打开FPGA电源
*/
void IOCtrl::enableFPGA(){
	//FPGA_POWER_H;
}

void IOCtrl::setSPI0_DIR(int dir){

}

void IOCtrl::setSingleEnd(int value){
//		if(value)
//		FPGA_SINGLEEND_H;	
//		else
//		FPGA_SINGLEEND_L;		
}

int IOCtrl::readFPGAIO(int ioid){
	switch(ioid){
		case 0:
	//		return FPGA_TURNEND;
			break;
		case 1:
	//		return FPGA_NEEDCOMM;
			break;
		case 2:
	//		return FPGA_RWOVER;
			break;
	}
	return -1;
}
