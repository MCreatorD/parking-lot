/*
 * DeviceEvent.h
 *
 *  Created on: 2016-5-5
 *      Author: zhipengp
 */

#ifndef DEVICEEVENT_H_
#define DEVICEEVENT_H_

#include "base_comm.h"
//#include "sys/time.h"


using namespace std;

class DeviceEvent{
public:
	DeviceEvent();
	virtual ~DeviceEvent();

public:
    void SendGPIEvent(Base_Comm *pComm,llrp_u8_t gpiportnumber,llrp_u8_t gpievent);
    void SendSelectSpecEvent(Base_Comm *pComm,llrp_u8_t eventtype,llrp_u32_t selectspecid,llrp_u32_t preemptingselectspecid);
    void SendAntennaSpecEvent(Base_Comm *pComm,llrp_u8_t eventtype,llrp_u32_t selectspecid,llrp_u16_t specindex);
    void SendAntennaStatusEvent(Base_Comm *pComm,llrp_u8_t eventtype,llrp_u8_t antennaid);

};


#endif /* DEVICEEVENT_H_ */
