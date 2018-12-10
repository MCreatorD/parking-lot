/*
 * Update_SM_Firmware.h
 *
 *  Created on: 2016-6-12
 *      Author: lij
 */

#ifndef UPDATE_SM_FIRMWARE_H_
#define UPDATE_SM_FIRMWARE_H_


#include <stdint.h>
#include <string>
using namespace std;

#include "MCUToSecureComm.h"



class Update_SM_Firmware{
public:
	Update_SM_Firmware();
	virtual ~Update_SM_Firmware();

private:
	MCUToSecureComm* m_pM2SecComm;
	IOCtrl *m_pIOCtrl;
public:
	bool enterUpateState();
	bool sendUpdateBlockToSM(unsigned char *contentbuf,unsigned int contentlen);
public:
	inline void setIOCtrl(IOCtrl *pioctrl){
		m_pIOCtrl  = pioctrl;
	}
	inline void setM2SComm(MCUToSecureComm *pcomm){
		m_pM2SecComm = pcomm;
	}
};

#endif /* UPDATE_SM_FIRMWARE_H_ */
