/*
 * XML_Operation.cpp
 *
 *  Created on: 2016-6-24
 *      Author: root
 */
#include <stdlib.h>
#include <stdio.h>

#include "XML_Operation.h"

//字节流转换为十六进制字符串
void XML_Operation::ByteToHexStr(const unsigned char* source, char* dest, int sourceLen)
{
    short i;
    unsigned char highByte, lowByte;

    for (i = 0; i < sourceLen; i++)
    {
        highByte = source[i] >> 4;
        lowByte = source[i] & 0x0f ;

        highByte += 0x30;

        if (highByte > 0x39)
                dest[i * 2] = highByte + 0x07;
        else
                dest[i * 2] = highByte;

        lowByte += 0x30;
        if (lowByte > 0x39)
            dest[i * 2 + 1] = lowByte + 0x07;
        else
            dest[i * 2 + 1] = lowByte;
    }
    return ;
}

//十六进制字符串转换为字节流
void XML_Operation::HexStrToByte(const char* source, unsigned char* dest, int sourceLen)
{
    short i;
    unsigned char highByte, lowByte;

    for (i = 0; i < sourceLen; i += 2)
    {
        highByte = toupper(source[i]);
        lowByte  = toupper(source[i + 1]);

        if (highByte > 0x39)
            highByte -= 0x37;
        else
            highByte -= 0x30;

        if (lowByte > 0x39)
            lowByte -= 0x37;
        else
            lowByte -= 0x30;

        dest[i / 2] = (highByte << 4) | lowByte;
    }
    return ;
}

XML_Operation::XML_Operation() {
	// TODO Auto-generated constructor stub

}

XML_Operation::~XML_Operation() {
	// TODO Auto-generated destructor stub
}

std::vector<std::string> XML_Operation::split(std::string str,std::string pattern)
{
    std::string::size_type pos;
    std::vector<std::string> result;
    str+=pattern;//扩展字符串以方便操作
    int size=str.size();

    for(int i=0; i<size; i++)
    {
        pos=str.find(pattern,i);
        if(pos<size)
        {
            std::string s=str.substr(i,pos-i);
            result.push_back(s);
            i=pos+pattern.size()-1;
        }
    }
    return result;
}

llrp_utf8v_t XML_Operation::convertCharsToUtf8v(const char *buf){

	if(buf==NULL){
		return llrp_utf8v_t(0);
	}

	int len = strlen(buf);
	llrp_utf8v_t utf8_chars = llrp_utf8v_t(len);
	memcpy(utf8_chars.m_pValue, buf, utf8_chars.m_nValue);
	return utf8_chars;
}

llrp_u32v_t XML_Operation::convertCharsTou32v(const char *buf){
	if(buf==NULL){
		return llrp_u32v_t(0);
	}
	string s(buf);
	vector<string> strs = split(s," ");

	int len = strs.size();
	//printf("len=%d,buf is %s\n",len,buf);
	llrp_u32v_t res = llrp_u32v_t(len);
	for(int i=0;i<len;i++){
		//printf("strs[i].c_str()=%s\n",strs[i].c_str());
		//llrp_u32_t temp = atol(strs[i].c_str());
		//char a[] = "3000000000";
		llrp_u32_t temp = strtoul(strs[i].c_str(),NULL,10);
		res.m_pValue[i] = temp;
		//printf("res.m_pValue[i]=%u\n",temp);
	}
	return res;

}

llrp_u16v_t XML_Operation::convertCharsTou16v(const char *buf){

	if(buf==NULL){
		return llrp_u16v_t(0);
	}

	string s(buf);
	vector<string> strs = split(s," ");

	int len = strs.size();
	llrp_u16v_t res = llrp_u16v_t(len);
	for(int i=0;i<len;i++){
		llrp_u16_t temp = atoi(strs[i].c_str());
		res.m_pValue[i] = temp;
	}

	return res;
}

llrp_u8v_t  XML_Operation::convertCharsTou8v(const char *buf){

	if(buf==NULL){
		return llrp_u8v_t(0);
	}

	string s(buf);
	vector<string> strs = split(s," ");

	int len = strs.size();
	llrp_u8v_t res = llrp_u8v_t(len);
	for(int i=0;i<len;i++){
		llrp_u8_t temp = atoi(strs[i].c_str());
		res.m_pValue[i] = temp;
	}

	return res;
}

llrp_u8v_t  XML_Operation::convertHexCharsTou8v(const char *buf){

	if(buf==NULL){
		return llrp_u8v_t(0);
	}

	int buflen = strlen(buf);
	unsigned char temp[buflen/2];
	HexStrToByte(buf,temp,buflen);

	int len = buflen/2;
	llrp_u8v_t res = llrp_u8v_t(len);
	for(int i=0;i<len;i++){
		res.m_pValue[i] = temp[i];
	}

	return res;
}


llrp_u1_t XML_Operation::convertCharsTou1(const char *buf){
	if(buf==NULL){
		return 0;
	}

	string s(buf);
	if(s=="true"){
		return 1;
	}else{
		return 0;
	}
}

/*
 * 把字符串表示的数据转为u1v
 */
llrp_u1v_t XML_Operation::convertCharsTou1v(const char *buf,int u1_count){

	if(buf==NULL){
		return llrp_u1v_t(0);
	}
	//printf("convertCharsTou1v:buf is %s\n",buf);

	if(u1_count<0||u1_count>1024){
		return llrp_u1v_t(0);
	}

	//先将数值串转为u8V如50 20将会转为0x50,0x20的u8v
	llrp_u8v_t temp = convertHexCharsTou8v(buf);

	/*for(int i=0;i<temp.m_nValue;i++){
		printf("temp.m_pValue[%d]=0x%02x,",i,temp.m_pValue[i]);
	}
	printf("\n");*/

	llrp_u1v_t res = llrp_u1v_t(u1_count);

	//如果数据位数小于所需位数，直接返回
	if(temp.m_nValue*8<res.m_nBit){
		return res;
	}

	for(int i=0;i<(res.m_nBit+7u)/8u;i++){
		llrp_u8_t t = temp.m_pValue[i];
		res.m_pValue[i] = t;
		//printf("res.m_pValue[%d]=0x%02x,",i,res.m_pValue[i]);
	}
	//printf("\n");
	return res;
}


int XML_Operation::lookupEnum(const char *value,const SEnumTableEntry enumTables[]){
	int res = -1;

	int i = 0;
	while(enumTables[i].pName!=0){
		if(strcmp(enumTables[i].pName,value)==0){
			res = enumTables[i].Value;
			return res;
		}
		i++;
	}
	return res;
}


void XML_Operation::addParamToElement(CParameter *pParam,CElement *pElement){
	if(pElement->m_pType->m_bIsMessage){
		HbFrame_Operation::addParamToMessage(pParam,(CMessage *)pElement);
	}else{
		HbFrame_Operation::addParamToParameter(pParam,(CParameter *)pElement);
	}
}

const CFieldDescriptor* XML_Operation::lookupFieldDescriptors(const char *propertyName,const CFieldDescriptor * const fieldDescriptors[]){

	int i = 0;
	while(fieldDescriptors[i]!=NULL){
		if(strcmp(propertyName,fieldDescriptors[i]->m_pName)==0){
			return fieldDescriptors[i];
		}
		i++;
	}
	return NULL;
}

void XML_Operation::addPropertyToMessage(const char *propertyName,const char * propertyValue,CMessage *pMessage){
	addPropertyToMessage(propertyName,propertyValue,NULL,NULL,pMessage);
}

/*
 * 添加属性（即数值参数）到消息。
 */
void XML_Operation::addPropertyToMessage(const char *propertyName,const char * propertyValue,const char *attrName,const char *attrValue,CMessage *pMessage){


	int id = pMessage->m_pType->m_TypeNum;
	switch (id){
	case Keepalive:
		break;
	case KeepaliveAck:
		break;
	case DeviceEventNotification:
		break;
	case GetDeviceCapabilities:
		break;
	case GetDeviceCapabilitiesAck:
		break;
	case AddSelectSpec:
		break;
	case AddSelectSpecAck:
		break;
	case DeleteSelectSpec:
		break;
	case DeleteSelectSpecAck:
		break;
	case StartSelectSpec:
		break;
	case StartSelectSpecAck:
		break;
	case StopSelectSpec:
		break;
	case StopSelectSpecAck:
		break;
	case EnableSelectSpec:
		break;
	case EnableSelectSpecAck:
		break;
	case DisableSelectSpec:
		break;
	case DisableSelectSpecAck:
		break;
	case GetSelectSpec:
		break;
	case GetSelectSpecAck:
		break;
	case AddAccessSpec:
		break;
	case AddAccessSpecAck:
		break;
	case DeleteAccessSpec:
		break;
	case DeleteAccessSpecAck:
		break;
	case EnableAccessSpec:
		break;
	case EnableAccessSpecAck:
		break;
	case DisableAccessSpec:
		break;
	case DisableAccessSpecAck:
		break;
	case GetAccessSpec:
		break;
	case GetAccessSpecAck:
		break;
	case TagSelectAccessReport:
		break;
	case ClientRequestOp:
		break;
	case ClientRequestOpAck:
		break;
	case DeviceBinding:
		break;
	case DeviceBindingAck:
		break;
	case UploadTagLog:
		break;
	case UploadTagLogAck:
		break;
	case ClearTagLog:
		break;
	case ClearTagLogAck:
		break;
	case UploadDeviceLog:
		break;
	case UploadDeviceLogAck:
		break;
	case ClearDeviceLog:
		break;
	case ClearDeviceLogAck:
		break;
	case GetDeviceConfig:
		break;
	case GetDeviceConfigAck:
		break;
	case SetDeviceConfig:
	{
		const CFieldDescriptor *field = lookupFieldDescriptors(propertyName, ((CSetDeviceConfig*)pMessage)->s_apFieldDescriptorTable);
		if (strcmp(field->m_pName, S_ResetToFactoryDefault) == 0){
			//string tmp(propertyName);
			//llrp_u1_t a = atoi(tmp.c_str());
			ESetDeviceConfigResetToFactoryDefault a = (ESetDeviceConfigResetToFactoryDefault)lookupEnum(propertyValue, field->m_pEnumTable);
			((CSetDeviceConfig*)pMessage)->setResetToFactoryDefault(a);
		}
	}
		break;
	case SetDeviceConfigAck:
		break;
	case GetVersion:
		break;
	case GetVersionAck:
		break;
	case SetVersion:
		break;
	case SetVersionAck:
		break;
	case ActiveVersion:
		{
			const CFieldDescriptor *field = lookupFieldDescriptors(propertyName,((CActiveVersion*)pMessage)->s_apFieldDescriptorTable);
			if(strcmp(field->m_pName,S_VerType)==0){
				EActiveVersionVerType type = (EActiveVersionVerType)lookupEnum(propertyValue,field->m_pEnumTable);
				((CActiveVersion*)pMessage)->setVerType(type);
			}
		}
		break;
	case ActiveVersionAck:
		break;
	case UnActiveVersion:
		break;
	case UnActiveVersionAck:
		break;
	case AlarmReport:
		break;
	case AlarmRestore:
		break;
	case AlarmDelete:
		break;
	case AlarmSync:
		break;
	case DiagnosticTest:
		break;
	case DiagnosticTestAck:
		break;
	case ResetDevice:
		break;
	case ResetDeviceAck:
		break;

	}

}

void XML_Operation::addPropertyToParameter(const char *propertyName,const char * propertyValue,CParameter *pParameter){
	addPropertyToParameter(propertyName,propertyValue,pParameter);
}

void XML_Operation::addPropertyToParameter(const char *propertyName,const char * propertyValue,const char *attrName,const char *attrValue,CParameter *pParameter){
	int id = PARAM_BASE + pParameter->m_pType->m_TypeNum;
	switch (id){
	case Status:
		break;
	case UTCTimestamp:
		break;
	case GPIEvent:
		break;
	case SelectSpecEvent:
		break;
	case AntennaSpecEvent:
		break;
	case AntennaStatusEvent:
		break;
	case ConnectionAttemptEvent:
		break;
	case GenaralCapabilities:
		break;
	case GPIOCapabilities:
		break;
	case CommunicationCapabilities:
		break;
	case SupportRS232:
		break;
	case SerialAttribute:
		break;
	case SupportRS485:
		break;
	case SpecCapabilities:
		break;
	case RfCapabilities:
		break;
	case TransmitPowerLevelTable:
		break;
	case FrequencyInformation:
		break;
	case FrequencyTable:
		break;
	case ForDataRateTable:
		break;
	case RevDataRateTable:
		break;
	case ForModulationTable:
		break;
	case RevDataEncodingTable:
		break;
	case ModuleDepthTable:
		break;
	case AirProtocolCapabilities:
		break;
	case PerAntennaAirProtocol:
		break;
	case HbProtocolCapabilities:
		break;
	case SelectSpec:
	{
		const CFieldDescriptor *field = lookupFieldDescriptors(propertyName, ((CSelectSpec*)pParameter)->s_apFieldDescriptorTable);
		if (strcmp(field->m_pName, S_SelectSpecID) == 0){
			llrp_u32_t v = atoi(propertyValue);
			((CSelectSpec*)pParameter)->setSelectSpecID(v);
		}else if (strcmp(field->m_pName, S_Priority) == 0){
			llrp_u8_t v = atoi(propertyValue);
			((CSelectSpec*)pParameter)->setPriority(v);
		}else if (strcmp(field->m_pName, S_CurrentState) == 0){
			//llrp_u8_t v = atoi(propertyValue);
			//printf("propertyValue is %s\n",propertyValue);
			ESelectCurrentState e = (ESelectCurrentState)lookupEnum(propertyValue, field->m_pEnumTable);
			((CSelectSpec*)pParameter)->setSelectCurrentState(e);
		}else if (strcmp(field->m_pName, S_Persistence) == 0){
			//llrp_u32_t v = atoi(propertyValue);
			EPersistence e = (EPersistence)lookupEnum(propertyValue, field->m_pEnumTable);
			((CSelectSpec*)pParameter)->setPersistence(e);
		}
	}
		break;
	case SelectSpecStartTrigger:
	{
		const CFieldDescriptor *field = lookupFieldDescriptors(propertyName, ((CSelectSpecStartTrigger*)pParameter)->s_apFieldDescriptorTable);
		if (strcmp(field->m_pName, S_SelectSpecStartTriggerType) == 0){
			//llrp_u32_t v = atoi(propertyValue);
			ESelectSpecStartTriggerType e = (ESelectSpecStartTriggerType)lookupEnum(propertyValue, field->m_pEnumTable);
			((CSelectSpecStartTrigger*)pParameter)->setSelectSpecStartTriggerType(e);
		}
	}
		break;
	case PeriodicTrigger:
	{
		const CFieldDescriptor *field = lookupFieldDescriptors(propertyName, ((CPeriodicTrigger*)pParameter)->s_apFieldDescriptorTable);
		if (strcmp(field->m_pName, S_Offset) == 0){
			llrp_u32_t v = atoi(propertyValue);
			//ESelectSpecStartTriggerType e = (ESelectSpecStartTriggerType)lookupEnum(propertyValue, field->m_pEnumTable);
			((CPeriodicTrigger*)pParameter)->setOffset(v);
		}else if (strcmp(field->m_pName, S_Period) == 0){
			llrp_u32_t v = atoi(propertyValue);
			//ESelectSpecStartTriggerType e = (ESelectSpecStartTriggerType)lookupEnum(propertyValue, field->m_pEnumTable);
			((CPeriodicTrigger*)pParameter)->setPeriod(v);
		}
	}
		break;
	case GPITrigger:
	{
		const CFieldDescriptor *field = lookupFieldDescriptors(propertyName, ((CGPITrigger*)pParameter)->s_apFieldDescriptorTable);
		if (strcmp(field->m_pName, S_GPIPortNum) == 0){
			llrp_u8_t v = atoi(propertyValue);
			//ESelectSpecStartTriggerType e = (ESelectSpecStartTriggerType)lookupEnum(propertyValue, field->m_pEnumTable);
			((CGPITrigger*)pParameter)->setGPIPortNum(v);
		}else if (strcmp(field->m_pName, S_GPIEvent) == 0){
			//llrp_u32_t v = atoi(propertyValue);
			EGPIEvent e = (EGPIEvent)lookupEnum(propertyValue, field->m_pEnumTable);
			((CGPITrigger*)pParameter)->setGPIEvent(e);
		}else if (strcmp(field->m_pName, S_Timeout) == 0){
			llrp_u32_t v = atoi(propertyValue);
			//ESelectSpecStartTriggerType e = (ESelectSpecStartTriggerType)lookupEnum(propertyValue, field->m_pEnumTable);
			((CGPITrigger*)pParameter)->setTimeout(v);
		}
	}
		break;
	case SelectSpecStopTrigger:
	{
		const CFieldDescriptor *field = lookupFieldDescriptors(propertyName, ((CSelectSpecStopTrigger*)pParameter)->s_apFieldDescriptorTable);
		if (strcmp(field->m_pName, S_SelectSpecStopTriggerType) == 0){
			//llrp_u32_t v = atoi(propertyValue);
			ESelectSpecStopTriggerType e = (ESelectSpecStopTriggerType)lookupEnum(propertyValue, field->m_pEnumTable);
			((CSelectSpecStopTrigger*)pParameter)->setSelectSpecStopTriggerType(e);
		}else if (strcmp(field->m_pName, S_DurationValue) == 0){
			llrp_u32_t v = atoi(propertyValue);
			//ESelectSpecStartTriggerType e = (ESelectSpecStartTriggerType)lookupEnum(propertyValue, field->m_pEnumTable);
			((CSelectSpecStopTrigger*)pParameter)->setDurationValue(v) ;
		}
	}
	break;
	case AntennaSpec:
	{
		const CFieldDescriptor *field = lookupFieldDescriptors(propertyName, ((CAntennaSpec*)pParameter)->s_apFieldDescriptorTable);
		if (strcmp(field->m_pName, S_AntennaIDs) == 0){
			llrp_u8v_t v = convertCharsTou8v(propertyValue);
			((CAntennaSpec*)pParameter)->setAntennaIDs(v);
		}
	}
		break;
	case AntennaSpecStopTrigger:
	{
		const CFieldDescriptor *field = lookupFieldDescriptors(propertyName, ((CAntennaSpecStopTrigger*)pParameter)->s_apFieldDescriptorTable);
		if (strcmp(field->m_pName, S_AntennaSpecStopTriggerType) == 0){
			//llrp_u32_t v = atoi(propertyValue);
			EAntennaSpecStopTriggerType e = (EAntennaSpecStopTriggerType)lookupEnum(propertyValue, field->m_pEnumTable);
			((CAntennaSpecStopTrigger*)pParameter)->setAntennaSpecStopTriggerType(e);
		}else if (strcmp(field->m_pName, S_DurationValue) == 0){
			llrp_u32_t v = atoi(propertyValue);
			//ESelectSpecStartTriggerType e = (ESelectSpecStartTriggerType)lookupEnum(propertyValue, field->m_pEnumTable);
			((CAntennaSpecStopTrigger*)pParameter)->setDurationValue(v) ;
		}
	}
		break;
	case TagObservationTrigger:
	{
		const CFieldDescriptor *field = lookupFieldDescriptors(propertyName, ((CTagObservationTrigger*)pParameter)->s_apFieldDescriptorTable);
		if (strcmp(field->m_pName, S_TriggerType) == 0){
			//llrp_u32_t v = atoi(propertyValue);
			ETriggerType e = (ETriggerType)lookupEnum(propertyValue, field->m_pEnumTable);
			((CTagObservationTrigger*)pParameter)->setTriggerType(e);
		}else if (strcmp(field->m_pName, S_NumberOfTags) == 0){
			llrp_u16_t v = atoi(propertyValue);
			//ESelectSpecStartTriggerType e = (ESelectSpecStartTriggerType)lookupEnum(propertyValue, field->m_pEnumTable);
			((CTagObservationTrigger*)pParameter)->setNumberOfTags(v) ;
		}else if (strcmp(field->m_pName, S_NumberOfAttempts) == 0){
			llrp_u16_t v = atoi(propertyValue);
			//ESelectSpecStartTriggerType e = (ESelectSpecStartTriggerType)lookupEnum(propertyValue, field->m_pEnumTable);
			((CTagObservationTrigger*)pParameter)->setNumberOfAttempts(v) ;
		}else if (strcmp(field->m_pName, S_TValue) == 0){
			llrp_u16_t v = atoi(propertyValue);
			//ESelectSpecStartTriggerType e = (ESelectSpecStartTriggerType)lookupEnum(propertyValue, field->m_pEnumTable);
			((CTagObservationTrigger*)pParameter)->setTValue(v) ;
		}else if (strcmp(field->m_pName, S_Timeout) == 0){
			llrp_u32_t v = atoi(propertyValue);
			//ESelectSpecStartTriggerType e = (ESelectSpecStartTriggerType)lookupEnum(propertyValue, field->m_pEnumTable);
			((CTagObservationTrigger*)pParameter)->setTimeout(v) ;
		}
	}
		break;
	case RfSpec:
	{
		const CFieldDescriptor *field = lookupFieldDescriptors(propertyName, ((CRfSpec*)pParameter)->s_apFieldDescriptorTable);
		if (strcmp(field->m_pName, S_RfSpecID) == 0){
			llrp_u16_t v = atoi(propertyValue);
			//EAntennaSpecStopTriggerType e = (EAntennaSpecStopTriggerType)lookupEnum(propertyValue, field->m_pEnumTable);
			((CRfSpec*)pParameter)->setRfSpecID(v);
		}else if (strcmp(field->m_pName, S_ProtocolID) == 0){
			//llrp_u8_t v = atoi(propertyValue);
			EProtocolID e = (EProtocolID)lookupEnum(propertyValue, field->m_pEnumTable);
			((CRfSpec*)pParameter)->setProtocolID(e) ;
		}else if (strcmp(field->m_pName, S_SelectType) == 0){
			//llrp_u8_t v = atoi(propertyValue);
			ESelectType e = (ESelectType)lookupEnum(propertyValue, field->m_pEnumTable);
			((CRfSpec*)pParameter)->setSelectType(e) ;
		}
	}
		break;
	case MemoryBank:
	{
		const CFieldDescriptor *field = lookupFieldDescriptors(propertyName, ((CMemoryBank*)pParameter)->s_apFieldDescriptorTable);
		if (strcmp(field->m_pName, S_MemoryBankID) == 0){
			llrp_u16_t v = atoi(propertyValue);
			//EAntennaSpecStopTriggerType e = (EAntennaSpecStopTriggerType)lookupEnum(propertyValue, field->m_pEnumTable);
			((CMemoryBank*)pParameter)->setMemoryBankID(v);
		}else if (strcmp(field->m_pName, S_ReadType) == 0){
			llrp_u8_t v = atoi(propertyValue);
			//EProtocolID e = (EProtocolID)lookupEnum(propertyValue, field->m_pEnumTable);
			((CMemoryBank*)pParameter)->setReadType(v) ;
		}else if (strcmp(field->m_pName, S_Pointer) == 0){
			llrp_u16_t v = atoi(propertyValue);
			//ESelectType e = (ESelectType)lookupEnum(propertyValue, field->m_pEnumTable);
			((CMemoryBank*)pParameter)->setPointer(v) ;
		}else if (strcmp(field->m_pName, S_Count) == 0){
			llrp_u16_t v = atoi(propertyValue);
			//ESelectType e = (ESelectType)lookupEnum(propertyValue, field->m_pEnumTable);
			((CMemoryBank*)pParameter)->setCount(v) ;
		}else if (strcmp(field->m_pName, S_BankType) == 0){
			llrp_u8_t v = atoi(propertyValue);
			//ESelectType e = (ESelectType)lookupEnum(propertyValue, field->m_pEnumTable);
			((CMemoryBank*)pParameter)->setBankType(v) ;
		}
	}
		break;
	case SelectReportSpec:
	{
		const CFieldDescriptor *field = lookupFieldDescriptors(propertyName, ((CSelectReportSpec*)pParameter)->s_apFieldDescriptorTable);
		if (strcmp(field->m_pName, S_SelectReportTrigger) == 0){
			//llrp_u16_t v = atoi(propertyValue);
			ESelectReportTrigger e = (ESelectReportTrigger)lookupEnum(propertyValue, field->m_pEnumTable);
			((CSelectReportSpec*)pParameter)->setSelectReportTrigger(e);
		}else if (strcmp(field->m_pName, S_NValue) == 0){
			llrp_u16_t v = atoi(propertyValue);
			((CSelectReportSpec*)pParameter)->setNValue(v);
		}else if (strcmp(field->m_pName, S_EnableSelectSpecID) == 0){
			llrp_u1_t v = convertCharsTou1(propertyValue);
			((CSelectReportSpec*)pParameter)->setEnableSelectSpecID(v);
		}else if (strcmp(field->m_pName, S_EnableSpecIndex) == 0){
			llrp_u1_t v = convertCharsTou1(propertyValue);
			((CSelectReportSpec*)pParameter)->setEnableSpecIndex(v);
		}else if (strcmp(field->m_pName, S_EnableRfSpecID) == 0){
			llrp_u1_t v = convertCharsTou1(propertyValue);
			((CSelectReportSpec*)pParameter)->setEnableRfSpecID(v);
		}else if (strcmp(field->m_pName, S_EnableAntennaID) == 0){
			llrp_u1_t v = convertCharsTou1(propertyValue);
			((CSelectReportSpec*)pParameter)->setEnableAntennaID(v);
		}else if (strcmp(field->m_pName, S_EnablePeakRSSI) == 0){
			llrp_u1_t v = convertCharsTou1(propertyValue);
			((CSelectReportSpec*)pParameter)->setEnablePeakRSSI(v);
		}else if (strcmp(field->m_pName, S_EnableFirstSeenTimestamp) == 0){
			llrp_u1_t v = convertCharsTou1(propertyValue);
			((CSelectReportSpec*)pParameter)->setEnableFirstSeenTimestamp(v);
		}else if (strcmp(field->m_pName, S_EnableLastSeenTimestamp) == 0){
			llrp_u1_t v = convertCharsTou1(propertyValue);
			((CSelectReportSpec*)pParameter)->setEnableLastSeenTimestamp(v);
		}else if (strcmp(field->m_pName, S_EnableTagSeenCount) == 0){
			llrp_u1_t v = convertCharsTou1(propertyValue);
			((CSelectReportSpec*)pParameter)->setEnableTagSeenCount(v);
		}else if (strcmp(field->m_pName, S_EnableAccessSpecID) == 0){
			llrp_u1_t v = convertCharsTou1(propertyValue);
			((CSelectReportSpec*)pParameter)->setEnableAccessSpecID(v);
		}
	}
		break;
	case ReportDestination:
		break;
	case AccessSpec:
	{
		const CFieldDescriptor *field = lookupFieldDescriptors(propertyName, ((CAccessSpec*)pParameter)->s_apFieldDescriptorTable);
		if (strcmp(field->m_pName, S_AccessSpecID) == 0){
			llrp_u32_t v = atoi(propertyValue);
			//EAntennaSpecStopTriggerType e = (EAntennaSpecStopTriggerType)lookupEnum(propertyValue, field->m_pEnumTable);
			((CAccessSpec*)pParameter)->setAccessSpecID(v);
		}else if (strcmp(field->m_pName, S_SelectSpecID) == 0){
			llrp_u32_t v = atoi(propertyValue);
			//EAntennaSpecStopTriggerType e = (EAntennaSpecStopTriggerType)lookupEnum(propertyValue, field->m_pEnumTable);
			((CAccessSpec*)pParameter)->setSelectSpecID(v);
		}else if (strcmp(field->m_pName, S_AntennaID) == 0){
			llrp_u8_t v = atoi(propertyValue);
			//EAntennaSpecStopTriggerType e = (EAntennaSpecStopTriggerType)lookupEnum(propertyValue, field->m_pEnumTable);
			((CAccessSpec*)pParameter)->setAntennaID(v);
		}else if (strcmp(field->m_pName, S_ProtocolID) == 0){
			//llrp_u16_t v = atoi(propertyValue);
			EProtocolID e = (EProtocolID)lookupEnum(propertyValue, field->m_pEnumTable);
			((CAccessSpec*)pParameter)->setProtocolID(e);
		}else if (strcmp(field->m_pName, S_AccessCurrentState) == 0){
			//llrp_u16_t v = atoi(propertyValue);
			EAccessCurrentState e = (EAccessCurrentState)lookupEnum(propertyValue, field->m_pEnumTable);
			((CAccessSpec*)pParameter)->setAccessCurrentState(e);
		}else if (strcmp(field->m_pName, S_Persistence) == 0){
			//llrp_u16_t v = atoi(propertyValue);
			EPersistence e = (EPersistence)lookupEnum(propertyValue, field->m_pEnumTable);
			((CAccessSpec*)pParameter)->setPersistence(e);
		}
	}


		break;
	case AccessSpecStopTrigger:
	{
		const CFieldDescriptor *field = lookupFieldDescriptors(propertyName, ((CAccessSpecStopTrigger*)pParameter)->s_apFieldDescriptorTable);
		if (strcmp(field->m_pName, S_AccessSpecStopTriggerType) == 0){
			//llrp_u32_t v = atoi(propertyValue);
			EAccessSpecStopTriggerType e = (EAccessSpecStopTriggerType)lookupEnum(propertyValue, field->m_pEnumTable);
			((CAccessSpecStopTrigger*)pParameter)->setAccessSpecStopTriggerType(e);
		}else if (strcmp(field->m_pName, S_OperationCountValue) == 0){
			llrp_u16_t v = atoi(propertyValue);
			//EAntennaSpecStopTriggerType e = (EAntennaSpecStopTriggerType)lookupEnum(propertyValue, field->m_pEnumTable);
			((CAccessSpecStopTrigger*)pParameter)->setOperationCountValue(v);
		}
	}
		break;
	case AccessCommand:
		break;
	case HbMatchSpec:
		break;
	case HbTargetTag:
	{
		const CFieldDescriptor *field = lookupFieldDescriptors(propertyName, ((CHbTargetTag*)pParameter)->s_apFieldDescriptorTable);
		if (strcmp(field->m_pName, S_MemoryType) == 0){
			//llrp_u32_t v = atoi(propertyValue);
			EMemoryType e = (EMemoryType)lookupEnum(propertyValue, field->m_pEnumTable);
			((CHbTargetTag*)pParameter)->setMemoryType(e);
		}else if (strcmp(field->m_pName, S_MatchType) == 0){
			//llrp_u32_t v = atoi(propertyValue);
			EMatchType e = (EMatchType)lookupEnum(propertyValue, field->m_pEnumTable);
			((CHbTargetTag*)pParameter)->setMatchType(e);
		}else if (strcmp(field->m_pName, S_Pointer) == 0){
			llrp_u16_t v = atoi(propertyValue);
			//EAccessSpecStopTriggerType e = (EAccessSpecStopTriggerType)lookupEnum(propertyValue, field->m_pEnumTable);
			((CHbTargetTag*)pParameter)->setPointer(v);
		}else if (strcmp(field->m_pName, S_TagMask) == 0){
			llrp_u32_t count = 0;
			if(memcmp(attrName,"Count",strlen(attrValue))==0){
				sscanf(attrValue,"%4u",&count);
			}
			//printf("count=%d\n",count);
			llrp_u1v_t v = convertCharsTou1v(propertyValue,count);
			((CHbTargetTag*)pParameter)->setTagMask(v);
			/*printf("v is:");
			for(int i=0;i<(v.m_nBit+7u/8u);i++){
				printf("0x%02x,",v.m_pValue[i]);
			}
			printf("\n");*/

		}else if (strcmp(field->m_pName, S_TagData) == 0){
			llrp_u32_t count = 0;
			if(memcmp(attrName,"Count",strlen(attrValue))==0){
				sscanf(attrValue,"%4u",&count);
			}
			llrp_u1v_t v = convertCharsTou1v(propertyValue,count);
			((CHbTargetTag*)pParameter)->setTagData(v);
		}
	}
		break;
	case HbReadSpec:
	{
		const CFieldDescriptor *field = lookupFieldDescriptors(propertyName, ((CHbReadSpec*)pParameter)->s_apFieldDescriptorTable);
		if (strcmp(field->m_pName, S_OpSpecID) == 0){
			llrp_u16_t v = atoi(propertyValue);
			//EMemoryType e = (EMemoryType)lookupEnum(propertyValue, field->m_pEnumTable);
			((CHbReadSpec*)pParameter)->setOpSpecID(v);
		}
	}
		break;
	case HbWriteSpec:
	{
		const CFieldDescriptor *field = lookupFieldDescriptors(propertyName, ((CHbWriteSpec*)pParameter)->s_apFieldDescriptorTable);
		if (strcmp(field->m_pName, S_OpSpecID) == 0){
			llrp_u16_t v = atoi(propertyValue);
			//EMemoryType e = (EMemoryType)lookupEnum(propertyValue, field->m_pEnumTable);
			((CHbWriteSpec*)pParameter)->setOpSpecID(v);
		}else if (strcmp(field->m_pName, S_MemoryBankID) == 0){
			llrp_u8_t v = atoi(propertyValue);
			//EMemoryType e = (EMemoryType)lookupEnum(propertyValue, field->m_pEnumTable);
			((CHbWriteSpec*)pParameter)->setMemoryBankID(v);
		}else if (strcmp(field->m_pName, S_Pointer) == 0){
			llrp_u16_t v = atoi(propertyValue);
			//EMemoryType e = (EMemoryType)lookupEnum(propertyValue, field->m_pEnumTable);
			((CHbWriteSpec*)pParameter)->setPointer(v);
		}else if (strcmp(field->m_pName, S_Data) == 0){
			llrp_u16v_t v = convertCharsTou16v(propertyValue);
			((CHbWriteSpec*)pParameter)->setData(v);
		}
	}
		break;
	case ReadMode:
	{
		const CFieldDescriptor *field = lookupFieldDescriptors(propertyName, ((CReadMode*)pParameter)->s_apFieldDescriptorTable);
		if (strcmp(field->m_pName, S_RepeatReadFlag) == 0){
			llrp_u1_t v = convertCharsTou1(propertyValue);
			//EMemoryType e = (EMemoryType)lookupEnum(propertyValue, field->m_pEnumTable);
			((CReadMode*)pParameter)->setRepeatReadFlag(v);
		}else if (strcmp(field->m_pName, S_Timer) == 0){
			llrp_u32_t v = atoi(propertyValue);
			//EMemoryType e = (EMemoryType)lookupEnum(propertyValue, field->m_pEnumTable);
			((CReadMode*)pParameter)->setTimer(v);
		}
	}
		break;
	case ClientRequestSpec:
		break;
	case AccessReportSpec:
	{
		const CFieldDescriptor *field = lookupFieldDescriptors(propertyName, ((CAccessReportSpec*)pParameter)->s_apFieldDescriptorTable);
		if (strcmp(field->m_pName, S_AccessReportTrigger) == 0){
			//llrp_u1_t v = convertCharsTou1(propertyValue);
			EAccessReportTrigger e = (EAccessReportTrigger)lookupEnum(propertyValue, field->m_pEnumTable);
			((CAccessReportSpec*)pParameter)->setAccessReportTrigger(e);
		}
	}
		break;
	case TagReportData:
		break;
	case SelectSpecID:
		break;
	case SpecIndex:
		break;
	case RfSpecID:
		break;
	case AntennaID:
		break;
	case PeakRSSI:
		break;
	case FirstSeenTimestampUTC:
		break;
	case LastSeenTimestampUTC:
		break;
	case TagSeenCount:
		break;
	case AccessSpecID:
		break;
/*	case SelectSpecResult:
		break;
	case HbReadSpecResult:
		break;
	case HbWriteSpecResult:
		break;*/
	case ClientRequestSpecResult:
		break;
	case ClientRequestAck:
		break;
	case TagLog:
		break;
	case StartLogTimestamp:
		break;
	case EndLogTimestamp:
		break;
	case DeviceLog:
		break;
	case DeviceEventNotificationSpec:
		break;
	case EventNotificationState:
	{
		const CFieldDescriptor *field = lookupFieldDescriptors(propertyName, ((CEventNotificationState*)pParameter)->s_apFieldDescriptorTable);
		if (strcmp(field->m_pName, S_EventType) == 0){
		   EEventNotificationStateEventType type = (EEventNotificationStateEventType)lookupEnum(propertyValue, field->m_pEnumTable);
		   ((CEventNotificationState*)pParameter)->setEventType(type);
		}
		else if (strcmp(field->m_pName, S_NotificationState) == 0){
		   EEventNotificationStateNotificationState state = (EEventNotificationStateNotificationState)lookupEnum(propertyValue, field->m_pEnumTable);
		   ((CEventNotificationState*)pParameter)->setNotificationState(state);
		}
	}
		break;
	case AntennaProperties:
	{
		const CFieldDescriptor *field = lookupFieldDescriptors(propertyName, ((CAntennaProperties*)pParameter)->s_apFieldDescriptorTable);
		if (strcmp(field->m_pName, S_AntennaConnected) == 0){
		  EAntennaPropertiesAntennaConnected s = (EAntennaPropertiesAntennaConnected)lookupEnum(propertyValue, field->m_pEnumTable);
		  ((CAntennaProperties*)pParameter)->setAntennaConnected(s);
		}
		else if (strcmp(field->m_pName, S_AntennaID) == 0){
		  llrp_u8_t v = atoi(propertyValue);
		  ((CAntennaProperties*)pParameter)->setAntennaID(v);
		}
		else if (strcmp(field->m_pName, S_AntennaGain) == 0){
		  llrp_s16_t v = atoi(propertyValue);
		  ((CAntennaProperties*)pParameter)->setAntennaID(v);
		}
	}
		break;
	case AntennaConfiguration:
	{
		const CFieldDescriptor *field = lookupFieldDescriptors(propertyName, ((CAntennaConfiguration*)pParameter)->s_apFieldDescriptorTable);
		//printf("field->m_pName is %s\n",field->m_pName);
		if (strcmp(field->m_pName, S_AntennaID) == 0){
			//printf("propertyValue is%s\n",propertyValue);
		 llrp_u8_t v = atoi(propertyValue);
		 ((CAntennaConfiguration*)pParameter)->setAntennaID(v);
		}
		else if (strcmp(field->m_pName, S_TransmitPowerIndex) == 0){
		 llrp_u16_t v = atoi(propertyValue);
		 ((CAntennaConfiguration*)pParameter)->setTransmitPowerIndex(v);
		}
		else if (strcmp(field->m_pName, S_FrequencyIndexes) == 0){
			llrp_u16v_t v = convertCharsTou16v(propertyValue);
			((CAntennaConfiguration*)pParameter)->setFrequencyIndexes(v);
		}
		else if (strcmp(field->m_pName, S_ForDataRateIndex) == 0){
		 llrp_u16_t v = atoi(propertyValue);
		 ((CAntennaConfiguration*)pParameter)->setForDataRateIndex(v);
		}
		else if (strcmp(field->m_pName, S_RevDataRateIndex) == 0){
		 llrp_u16_t v = atoi(propertyValue);
		 ((CAntennaConfiguration*)pParameter)->setRevDataRateIndex(v);
		}
		else if (strcmp(field->m_pName, S_ForModulationIndex) == 0){
		 llrp_u16_t v = atoi(propertyValue);
		 ((CAntennaConfiguration*)pParameter)->setForModulationIndex(v);
		}
		else if (strcmp(field->m_pName, S_RevDataEncodingIndex) == 0){
		 llrp_u16_t v = atoi(propertyValue);
		 ((CAntennaConfiguration*)pParameter)->setRevDataEncodingIndex(v);
		}
	}
		break;
	case ModuleDepth:
	{
		const CFieldDescriptor *field = lookupFieldDescriptors(propertyName, ((CModuleDepth*)pParameter)->s_apFieldDescriptorTable);
		if (strcmp(field->m_pName, S_Index) == 0){
			llrp_u16_t v = atoi(propertyValue);
			((CModuleDepth*)pParameter)->setIndex(v);
		}
	}
		break;
	case Identification:
	{
		const CFieldDescriptor *field = lookupFieldDescriptors(propertyName, ((CIdentification*)pParameter)->s_apFieldDescriptorTable);
		if (strcmp(field->m_pName, S_DeviceName) == 0){
			llrp_utf8v_t name = convertCharsToUtf8v(propertyValue);
			((CIdentification*)pParameter)->setDeviceName(name);
		}
	}
		break;
	case AlarmConfiguration:
	{
		const CFieldDescriptor *field = lookupFieldDescriptors(propertyName, ((CAlarmConfiguration*)pParameter)->s_apFieldDescriptorTable);
		if (strcmp(field->m_pName, S_AlarmMask) == 0){
			//(EAl) lookupEnum(propertyValue, field->m_pEnumTable);
			llrp_u8_t v = atoi(propertyValue);
			((CAlarmConfiguration*)pParameter)->setAlarmMask(v);
		}
	}
		break;
	case AlarmThreshod:
	{
		const CFieldDescriptor *field = lookupFieldDescriptors(propertyName, ((CAlarmThreshod*)pParameter)->s_apFieldDescriptorTable);
		if (strcmp(field->m_pName, S_TemperatureMaxValue) == 0){
			//(EAl) lookupEnum(propertyValue, field->m_pEnumTable);
			llrp_s8_t v = atoi(propertyValue);
			((CAlarmThreshod*)pParameter)->setTemperatureMaxValue(v);
		}
		else if (strcmp(field->m_pName, S_TemperatureMinValue) == 0){
			//(EAl) lookupEnum(propertyValue, field->m_pEnumTable);
			llrp_s8_t v = atoi(propertyValue);
			((CAlarmThreshod*)pParameter)->setTemperatureMinValue(v);
		}
	}
		break;
	case CommunicationConfiguration:
		break;
	case CommLinkConfiguration:
	{
		const CFieldDescriptor *field = lookupFieldDescriptors(propertyName, ((CCommLinkConfiguration*)pParameter)->s_apFieldDescriptorTable);
		if (strcmp(field->m_pName, S_LinkType) == 0){
			ELinkType e = (ELinkType) lookupEnum(propertyValue, field->m_pEnumTable);
			((CCommLinkConfiguration*)pParameter)->setLinkType(e);
		}
	}
		break;
	case KeepaliveSpec:
	{
		const CFieldDescriptor *field = lookupFieldDescriptors(propertyName, ((CKeepaliveSpec*)pParameter)->s_apFieldDescriptorTable);
		if (strcmp(field->m_pName, S_KeepaliveTriggerType) == 0){
			EKeepaliveTriggerType e = (EKeepaliveTriggerType)lookupEnum(propertyValue, field->m_pEnumTable);
			((CKeepaliveSpec*)pParameter)->setKeepaliveTriggerType(e);
		}
		else if (strcmp(field->m_pName, S_PeriodicTriggerValue) == 0){
			llrp_u32_t v = atoi(propertyValue);
			((CKeepaliveSpec*)pParameter)->setPeriodicTriggerValue(v);
		}
	}
		break;
	case TcpLinkConfiguration:
	{
		const CFieldDescriptor *field = lookupFieldDescriptors(propertyName, ((CTcpLinkConfiguration*)pParameter)->s_apFieldDescriptorTable);
		if (strcmp(field->m_pName, S_CommMode) == 0){
			ECommMode e = (ECommMode)lookupEnum(propertyValue, field->m_pEnumTable);
			((CTcpLinkConfiguration*)pParameter)->setCommMode(e);
		}
		else if (strcmp(field->m_pName, S_IsSSL) == 0){
			llrp_u1_t v = atoi(propertyValue);
			((CTcpLinkConfiguration*)pParameter)->setIsSSL(v);
		}
	}
		break;
	case ClientModeConfiguration:
	{
		const CFieldDescriptor *field = lookupFieldDescriptors(propertyName, ((CClientModeConfiguration*)pParameter)->s_apFieldDescriptorTable);
		if (strcmp(field->m_pName, S_Port) == 0){
			llrp_u16_t v = atoi(propertyValue);
			((CClientModeConfiguration*)pParameter)->setPort(v);
		}
	}
		break;
	case IPAddress:
	{
		const CFieldDescriptor *field = lookupFieldDescriptors(propertyName, ((CIPAddress*)pParameter)->s_apFieldDescriptorTable);
		if (strcmp(field->m_pName, S_Version) == 0){
			EIPAddressVersion e = (EIPAddressVersion)lookupEnum(propertyValue, field->m_pEnumTable);
			((CIPAddress*)pParameter)->setVersion(e);
		}
		else if (strcmp(field->m_pName, S_Address) == 0){
			llrp_u32v_t v = convertCharsTou32v(propertyValue);
			((CIPAddress*)pParameter)->setAddress(v);
		}
	}
		break;
	case ServerModeConfiguration:
	{
		const CFieldDescriptor *field = lookupFieldDescriptors(propertyName, ((CServerModeConfiguration*)pParameter)->s_apFieldDescriptorTable);
		if (strcmp(field->m_pName, S_Port) == 0){
			llrp_u16_t v = atoi(propertyValue);
			((CServerModeConfiguration*)pParameter)->setPort(v);
		}
	}
		break;
	case SerialLinkConfiguration:
	{
		const CFieldDescriptor *field = lookupFieldDescriptors(propertyName, ((CSerialLinkConfiguration*)pParameter)->s_apFieldDescriptorTable);
		if (strcmp(field->m_pName, S_IfIndex) == 0){
			llrp_u8_t v = atoi(propertyValue);
			((CSerialLinkConfiguration*)pParameter)->setIfIndex(v);
		}
		else if (strcmp(field->m_pName, S_SrcAddr) == 0){
			llrp_u8_t v = atoi(propertyValue);
			((CSerialLinkConfiguration*)pParameter)->setSrcAddr(v);
		}
		else if (strcmp(field->m_pName, S_DstAddr) == 0){
			llrp_u8_t v = atoi(propertyValue);
			((CSerialLinkConfiguration*)pParameter)->setDstAddr(v);
		}
	}
		break;
	case HttpLinkConfiguration:
	{
		const CFieldDescriptor *field = lookupFieldDescriptors(propertyName, ((CHttpLinkConfiguration*)pParameter)->s_apFieldDescriptorTable);
		if (strcmp(field->m_pName, S_ServerUrl) == 0){
			llrp_utf8v_t v = convertCharsToUtf8v(propertyValue);
			//((CHttpLinkConfiguration*)pParameter)->setServerUrl(v);;
		}
	}
		break;
	case EthernetIpv4Configuration:
	{
		const CFieldDescriptor *field = lookupFieldDescriptors(propertyName, ((CEthernetIpv4Configuration*)pParameter)->s_apFieldDescriptorTable);
		if (strcmp(field->m_pName, S_IfIndex) == 0){
			llrp_u8_t v = atoi(propertyValue);
			((CEthernetIpv4Configuration*)pParameter)->setIfIndex(v);
		}
		else if (strcmp(field->m_pName, S_IPAddress) == 0){
			llrp_u32_t v = strtoul(propertyValue,NULL,10);
			((CEthernetIpv4Configuration*)pParameter)->setIPAddress(v);
		}
		else if (strcmp(field->m_pName, S_IPMask) == 0){
			llrp_u32_t v = strtoul(propertyValue,NULL,10);
			((CEthernetIpv4Configuration*)pParameter)->setIPMask(v);
		}
		else if (strcmp(field->m_pName, S_GateWayAddr) == 0){
			llrp_u32_t v = strtoul(propertyValue,NULL,10);
			((CEthernetIpv4Configuration*)pParameter)->setGateWayAddr(v);
		}
		else if (strcmp(field->m_pName, S_DNSAddr) == 0){
			llrp_u32_t v = strtoul(propertyValue,NULL,10);
			((CEthernetIpv4Configuration*)pParameter)->setDNSAddr(v);
		}
		else if (strcmp(field->m_pName, S_IsDHCP) == 0){
			llrp_u1_t v = atoi(propertyValue);
			((CEthernetIpv4Configuration*)pParameter)->setIsDHCP(v);
		}
	}
		break;
	case EthernetIpv6Configuration:
		break;
	case NTPConfiguration:
	{
		const CFieldDescriptor *field = lookupFieldDescriptors(propertyName, ((CNTPConfiguration*)pParameter)->s_apFieldDescriptorTable);
		if (strcmp(field->m_pName, S_NtpPeriodicTime) == 0){
			llrp_u32_t v = atoi(propertyValue);
			((CNTPConfiguration*)pParameter)->setNtpPeriodicTime(v);
		}
	}
		break;
	case SerialPortConfiguration:
	{
		const CFieldDescriptor *field = lookupFieldDescriptors(propertyName, ((CSerialPortConfiguration*)pParameter)->s_apFieldDescriptorTable);
		if (strcmp(field->m_pName, S_IfIndex) == 0){
			llrp_u8_t v = atoi(propertyValue);
			((CSerialPortConfiguration*)pParameter)->setIfIndex(v);
		}
		else if (strcmp(field->m_pName, S_AttributeIndex) == 0){
			llrp_u8_t v = atoi(propertyValue);
			((CSerialPortConfiguration*)pParameter)->setAttributeIndex(v);
		}
	}
		break;
	case LocationConfiguration:
	{
		const CFieldDescriptor *field = lookupFieldDescriptors(propertyName, ((CLocationConfiguration*)pParameter)->s_apFieldDescriptorTable);
		if (strcmp(field->m_pName, S_LocationType) == 0){
			ELocationType e =  (ELocationType)lookupEnum(propertyValue, field->m_pEnumTable);
			((CLocationConfiguration*)pParameter)->setLocationType(e);
		}

	}
		break;
	case GpsLocation:
	{
		const CFieldDescriptor *field = lookupFieldDescriptors(propertyName, ((CGpsLocation*)pParameter)->s_apFieldDescriptorTable);
		if (strcmp(field->m_pName, S_Longitude) == 0){
			//ELocationType e =  (ELocationType)lookupEnum(propertyValue, field->m_pEnumTable);
			llrp_s32_t v = atoi(propertyValue);
			((CGpsLocation*)pParameter)->setLongitude(v);
		}else if (strcmp(field->m_pName, S_Latitude) == 0){
			//ELocationType e =  (ELocationType)lookupEnum(propertyValue, field->m_pEnumTable);
			llrp_s32_t v = atoi(propertyValue);
			((CGpsLocation*)pParameter)->setLatitude(v);
		}else if (strcmp(field->m_pName, S_Altitude) == 0){
			//ELocationType e =  (ELocationType)lookupEnum(propertyValue, field->m_pEnumTable);
			llrp_s32_t v = atoi(propertyValue);
			((CGpsLocation*)pParameter)->setAltitude(v);
		}

	}
		break;
	case BdsLocation:
	{
		const CFieldDescriptor *field = lookupFieldDescriptors(propertyName, ((CBdsLocation*)pParameter)->s_apFieldDescriptorTable);
		if (strcmp(field->m_pName, S_Longitude) == 0){
			llrp_s32_t v = atoi(propertyValue);
			((CBdsLocation*)pParameter)->setLongitude(v);
		}else if (strcmp(field->m_pName, S_Latitude) == 0){
			llrp_s32_t v = atoi(propertyValue);
			((CBdsLocation*)pParameter)->setLatitude(v);
		}else if (strcmp(field->m_pName, S_Altitude) == 0){
			llrp_s32_t v = atoi(propertyValue);
			((CBdsLocation*)pParameter)->setAltitude(v);
		}

	}
		break;
	case VersionInfo:
		break;
	case VersionDownload:
		break;
	case AlarmReportInfo:
		break;
	case AlarmRestoreInfo:
		break;
	case AlarmSyncInfo:
		break;
	case DiagnosticTestItem:
		break;
	case DiagnosticTestResultItem:
		break;
	case DiagnosticTestResultAntennaConnected:
		break;
	case DiagnosticTestResultAntennaVSWR:
		break;

	}

}

void XML_Operation::addPropertyToElement(const char *propertyName,const char * propertyValue,CElement *pElement){
	addPropertyToElement(propertyName,propertyValue,NULL,NULL,pElement);
}

void XML_Operation::addPropertyToElement(const char *propertyName,const char * propertyValue,const char *attrName,const char *attrValue,CElement *pElement){
	if(pElement->m_pType->m_bIsMessage){
		addPropertyToMessage( propertyName,propertyValue,attrName,attrValue,(CMessage*)pElement);
	}else{
		addPropertyToParameter(propertyName,propertyValue,attrName,attrValue,(CParameter*)pElement);
	}
}
