/*
 * DeviceEvent.cpp
 *
 *  Created on: 2016-5-5
 *      Author: zhipengp
 */
#include "DeviceEvent.h"
#include <stdio.h>

DeviceEvent::DeviceEvent(){}

DeviceEvent::~DeviceEvent(){}

void DeviceEvent::SendGPIEvent(Base_Comm *pComm,llrp_u8_t gpiportnumber,llrp_u8_t gpievent)
{
	CMessage *pmessage = (CMessage*)HbFrame_Operation::genMessage(DeviceEventNotification,0);

	CUTCTimestamp *ptimestamp = (CUTCTimestamp*)HbFrame_Operation::genParam(UTCTimestamp,0,NULL);
	//struct timeval currenttime;
	//gettimeofday(&currenttime,NULL);
	//ptimestamp->setMicroseconds(currenttime.tv_sec*1000000+currenttime.tv_usec);

	CGPIEvent *pgpievent = (CGPIEvent*)HbFrame_Operation::genParam(GPIEvent,0,NULL);
	pgpievent->setGPIPortNumber(gpiportnumber);
	if(gpievent == 0)
	{
		pgpievent->setGPIEvent(GPIEvent_DOWN);
	}
	else if(gpievent == 1)
	{
		pgpievent->setGPIPortNumber(GPIEvent_UP);
	}

	HbFrame_Operation::addParamToMessage(ptimestamp,pmessage);
	HbFrame_Operation::addParamToMessage(pgpievent,pmessage);

	//if(!pComm->sendFrame(pmessage)){
    if(!pComm->immediateSendMessage(pmessage)){
		printf("Send GPI event fail!\n");
	}
	delete pmessage;
}

void DeviceEvent::SendSelectSpecEvent(Base_Comm *pComm,llrp_u8_t eventtype,llrp_u32_t selectspecid,llrp_u32_t preemptingselectspecid)
{
	CMessage *pmessage = (CMessage*)HbFrame_Operation::genMessage(DeviceEventNotification,0);

	CUTCTimestamp *ptimestamp = (CUTCTimestamp*)HbFrame_Operation::genParam(UTCTimestamp,0,NULL);
	//struct timeval currenttime;
	//gettimeofday(&currenttime,NULL);
	//ptimestamp->setMicroseconds(currenttime.tv_sec*1000000+currenttime.tv_usec);

	CSelectSpecEvent *pselectspecevent = (CSelectSpecEvent*)HbFrame_Operation::genParam(SelectSpecEvent,0,NULL);
	if(eventtype == 0)
	{
		pselectspecevent->setEventType(EventType_Start);
	}
	else if(eventtype == 1)
	{
		pselectspecevent->setEventType(EventType_End);
	}
	else if(eventtype == 2)
	{
		pselectspecevent->setEventType(EventType_Priority);
	}
	pselectspecevent->setSelectSpecID(selectspecid);
	pselectspecevent->setPreemptingSelectSpecID(preemptingselectspecid);

	HbFrame_Operation::addParamToMessage(ptimestamp,pmessage);
	HbFrame_Operation::addParamToMessage(pselectspecevent,pmessage);

	//if(!pComm->sendFrame(pmessage)){
    if(!pComm->immediateSendMessage(pmessage)){
		printf("Send SelectSpec event fail!\n");
	}
	delete pmessage;
}

void DeviceEvent::SendAntennaSpecEvent(Base_Comm *pComm,llrp_u8_t eventtype,llrp_u32_t selectspecid,llrp_u16_t specindex)
{
	CMessage *pmessage = (CMessage*)HbFrame_Operation::genMessage(DeviceEventNotification,0);

	CUTCTimestamp *ptimestamp = (CUTCTimestamp*)HbFrame_Operation::genParam(UTCTimestamp,0,NULL);
	//struct timeval currenttime;
	//gettimeofday(&currenttime,NULL);
	//ptimestamp->setMicroseconds(currenttime.tv_sec*1000000+currenttime.tv_usec);

	CAntennaSpecEvent *pantennaspecevent = (CAntennaSpecEvent*)HbFrame_Operation::genParam(AntennaSpecEvent,0,NULL);
	if(eventtype == 0)
	{
		pantennaspecevent->setEventType(EventType_Start);
	}
	pantennaspecevent->setSelectSpecID(selectspecid);
	pantennaspecevent->setSpecIndex(specindex);

	HbFrame_Operation::addParamToMessage(ptimestamp,pmessage);
	HbFrame_Operation::addParamToMessage(pantennaspecevent,pmessage);

	//if(!pComm->sendFrame(pmessage)){
    if(!pComm->immediateSendMessage(pmessage)){
		printf("Send AntennaSpec event fail!\n");
	}
	delete pmessage;
}

void DeviceEvent::SendAntennaStatusEvent(Base_Comm *pComm,llrp_u8_t eventtype,llrp_u8_t antennaid)
{
	CMessage *pmessage = (CMessage*)HbFrame_Operation::genMessage(DeviceEventNotification,0);

	CUTCTimestamp *ptimestamp = (CUTCTimestamp*)HbFrame_Operation::genParam(UTCTimestamp,0,NULL);
	//struct timeval currenttime;
	//gettimeofday(&currenttime,NULL);
	//ptimestamp->setMicroseconds(currenttime.tv_sec*1000000+currenttime.tv_usec);

	CAntennaStatusEvent *pantennastatusevent = (CAntennaStatusEvent*)HbFrame_Operation::genParam(AntennaStatusEvent,0,NULL);
	if(eventtype == 0)
	{
		pantennastatusevent->setEventType(EventType_Start);
	}
	else if(eventtype == 1)
	{
		pantennastatusevent->setEventType(EventType_End);
	}
	pantennastatusevent->setAntennaID(antennaid);

	HbFrame_Operation::addParamToMessage(ptimestamp,pmessage);
	HbFrame_Operation::addParamToMessage(pantennastatusevent,pmessage);

	//if(!pComm->sendFrame(pmessage)){
    if(!pComm->immediateSendMessage(pmessage)){
		printf("Send AntennaStatus event fail!\n");
	}
	delete pmessage;
}

