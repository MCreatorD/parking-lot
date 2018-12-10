#include "HbFrame_Operation.h"
//#include <stdio.h>
#include "HEXConvert.h"
#include "ExtendLLRP.h"
//#include "XMLDecoder.h"

HbFrame_Operation::HbFrame_Operation(void)
{
}


HbFrame_Operation::~HbFrame_Operation(void)
{
}




CMessage* HbFrame_Operation::genMessage(int messageType,int messageID){
    CMessage * pmessage = NULL;
    switch(messageType){
    case Keepalive:
        pmessage = new CKeepalive();
        break;
    case KeepaliveAck:
        pmessage = new CKeepaliveAck();
        break;
    case DeviceEventNotification:
        pmessage = new CDeviceEventNotification();
        break;
    case GetDeviceCapabilities:
        pmessage = new CGetDeviceCapabilities;
        break;
    case GetDeviceCapabilitiesAck:
        pmessage = new CGetDeviceCapabilitiesAck;
        break;
    case AddSelectSpec:
        pmessage = new CAddSelectSpec;
        break;
    case AddSelectSpecAck:
        pmessage = new CAddSelectSpecAck;
        break;
    case DeleteSelectSpec:
        pmessage = new CDeleteSelectSpec;
        break;
    case DeleteSelectSpecAck:
        pmessage = new CDeleteSelectSpecAck;
        break;
    case StartSelectSpec:
        pmessage = new CStartSelectSpec;
        break;
    case StartSelectSpecAck:
        pmessage = new CStartSelectSpecAck;
        break;
    case StopSelectSpec:
        pmessage = new CStopSelectSpec;
        break;
    case StopSelectSpecAck:
        pmessage = new CStopSelectSpecAck;
        break;
    case EnableSelectSpec:
        pmessage = new CEnableSelectSpec;
        break;
    case EnableSelectSpecAck:
        pmessage = new CEnableSelectSpecAck;
        break;
    case DisableSelectSpec:
        pmessage = new CDisableSelectSpec;
        break;
    case DisableSelectSpecAck:
        pmessage = new CDisableSelectSpecAck;
        break;
    case GetSelectSpec:
        pmessage = new CGetSelectSpec;
        break;
    case GetSelectSpecAck:
        pmessage = new CGetSelectSpecAck;
        break;
    case AddAccessSpec:
        pmessage = new CAddAccessSpec;
        break;
    case AddAccessSpecAck:
        pmessage = new CAddAccessSpecAck;
        break;
    case DeleteAccessSpec:
        pmessage = new CDeleteAccessSpec;
        break;
    case DeleteAccessSpecAck:
        pmessage = new CDeleteAccessSpecAck;
        break;
    case EnableAccessSpec:
        pmessage = new CEnableAccessSpec;
        break;
    case EnableAccessSpecAck:
        pmessage = new CEnableAccessSpecAck;
        break;
    case DisableAccessSpec:
        pmessage = new CDisableAccessSpec;
        break;
    case DisableAccessSpecAck:
        pmessage = new CDisableAccessSpecAck;
        break;
    case GetAccessSpec:
        pmessage = new CGetAccessSpec;
        break;
    case GetAccessSpecAck:
        pmessage = new CGetAccessSpecAck;
        break;
    case TagSelectAccessReport:
        pmessage = new CTagSelectAccessReport;
        break;
    case ClientRequestOp:
        pmessage = new CClientRequestOp();
        break;
    case ClientRequestOpAck:
        pmessage = new CClientRequestOpAck;
        break;
    case DeviceBinding:
        pmessage = new CDeviceBinding;
        break;
    case DeviceBindingAck:
        pmessage = new CDeviceBindingAck;
        break;
    case UploadTagLog:
        pmessage = new CUploadTagLog;
        break;
    case UploadTagLogAck:
        pmessage = new CUploadTagLogAck;
        break;
    case ClearTagLog:
        pmessage = new CClearTagLog;
        break;
    case ClearTagLogAck:
        pmessage = new CClearTagLogAck;
        break;
    case UploadDeviceLog:
        pmessage = new CUploadDeviceLog;
        break;
    case UploadDeviceLogAck:
        pmessage = new CUploadDeviceLogAck;
        break;
    case ClearDeviceLog:
        pmessage = new CClearDeviceLog;
        break;
    case ClearDeviceLogAck:
        pmessage = new CClearDeviceLogAck;
        break;
    case GetDeviceConfig:
        pmessage = new CGetDeviceConfig;
        break;
    case GetDeviceConfigAck:
        pmessage = new CGetDeviceConfigAck;
        break;
    case SetDeviceConfig:
        pmessage = new CSetDeviceConfig;
        break;
    case SetDeviceConfigAck:
        pmessage = new CSetDeviceConfigAck;
        break;
    case GetVersion:
        pmessage = new CGetVersion;
        break;
    case GetVersionAck:
        pmessage = new CGetVersionAck;
        break;
    case SetVersion:
        pmessage = new CSetVersion;
        break;
    case SetVersionAck:
        pmessage = new CSetVersionAck;
        break;
    case ActiveVersion:
        pmessage = new CActiveVersion;
        break;
    case ActiveVersionAck:
        pmessage = new CActiveVersionAck;
        break;
    case UnActiveVersion:
        pmessage = new CUnActiveVersion;
        break;
    case UnActiveVersionAck:
        pmessage = new CUnActiveVersionAck;
        break;
    case AlarmReport:
        pmessage = new CAlarmReport;
        break;
    case AlarmRestore:
        pmessage = new CAlarmRestore;
        break;
    case AlarmDelete:
        pmessage = new CAlarmDelete;
        break;
    case AlarmSync:
        pmessage = new CAlarmSync;
        break;
    case DiagnosticTest:
        pmessage = new CDiagnosticTest;
        break;
    case DiagnosticTestAck:
        pmessage = new CDiagnosticTestAck;
        break;
    case ResetDevice:
        pmessage = new CResetDevice;
        break;
    case ResetDeviceAck:
        pmessage = new CResetDeviceAck;
        break;
    case DeviceCertificateConfig:
        pmessage = new CDeviceCertificateConfig;
        break;
    case DeviceCertificateConfigAck:
        pmessage = new CDeviceCertificateConfigAck;
        break;
    case DeviceBindingResultNotification:
        pmessage = new CDeviceBindingResultNotification;
        break;
    case UploadTagLogConfirm:
        pmessage = new CUploadTagLogConfirm;
        break;
    case TagLogCount:
        pmessage = new CTagLogCount;
        break;
    case TagLogCountAck:
        pmessage = new CTagLogCountAck;
        break;
    case UploadDeviceLogConfirm:
        pmessage = new CUploadDeviceLogConfirm;
        break;
    case DeviceLogCount:
        pmessage = new CDeviceLogCount;
        break;
    case DeviceLogCountAck:
        pmessage = new CDeviceLogCountAck;
        break;
    case EnableCachedEventsAndReport:
        pmessage = new CEnableCachedEventsAndReport;
        break;
    case CachedSelectAccessReport:
        pmessage = new CCachedSelectAccessReport;
        break;
    case CachedSelectAccessReportAck:
        pmessage = new CCachedSelectAccessReportAck;
        break;

    }//end of switch
    pmessage->setMessageID(messageID);
    pmessage->setDeviceSN(0x424c120A1E1402);//(0x1234567887654321);

    return pmessage;
}



/*
*	��ɲ���˷�������һ���ղ����ָ��
*	paramType:����������롣parentParam:����ĸ�����Ϊ�����ʾ����Ϣ��ֱ�Ӳ���
*/
CParameter*HbFrame_Operation:: genParam(int paramType,int contentCount,void *content...){
    CParameter *pparam = NULL;

    //va_list arglist;
    //va_start(arglist,contentCount);
    //va_end(arglist);

    switch(paramType){
    case Status:
        pparam = new CStatus;
        break;
    case UTCTimestamp:
        pparam = new CUTCTimestamp;
        break;
    case GPIEvent:
        pparam = new CGPIEvent();
        break;
    case SelectSpecEvent:
        pparam = new CSelectSpecEvent();
        break;
    case AntennaSpecEvent:
        pparam = new CAntennaSpecEvent();
        break;
    case AntennaStatusEvent:
        pparam = new CAntennaStatusEvent();
        break;
    case ConnectionAttemptEvent:
        pparam = new CConnectionAttemptEvent();
        break;
    case GenaralCapabilities:
        pparam = new CGenaralCapabilities;
        break;
    case GPIOCapabilities:
        pparam = new CGPIOCapabilities;
        break;
    case CommunicationCapabilities:
        pparam = new CCommunicationCapabilities;
        break;
    case SupportRS232:
        pparam = new CSupportRS232;
        break;
    case SerialAttribute:
        pparam = new CSerialAttribute;
        break;
    case SupportRS485:
        pparam = new CSupportRS485;
        break;
    case SpecCapabilities:
        pparam = new CSpecCapabilities;
        break;
    case RfCapabilities:
        pparam = new CRfCapabilities;
        break;
    case TransmitPowerLevelTable:
        pparam = new CTransmitPowerLevelTable;
        break;
    case FrequencyInformation:
        pparam = new CFrequencyInformation;
        break;
    case FrequencyTable:
        pparam = new CFrequencyTable;
        break;
    case ForDataRateTable:
        pparam = new CForDataRateTable;
        break;
    case RevDataRateTable:
        pparam = new CRevDataRateTable;
        break;
    case ForModulationTable:
        pparam = new CForModulationTable;
        break;
    case RevDataEncodingTable:
        pparam = new CRevDataEncodingTable;
        break;
    case ModuleDepthTable:
        pparam = new CModuleDepthTable;
        break;
    case AirProtocolCapabilities:
        pparam = new CAirProtocolCapabilities;
        break;
    case PerAntennaAirProtocol:
        pparam = new CPerAntennaAirProtocol;
        break;
    case HbProtocolCapabilities:
        pparam = new CHbProtocolCapabilities;
        break;
    //case SecurityModuleCapabilities:
        //pparam = new CSecurityModuleCapabilities;
        //break;
    case SelectSpec:
        pparam = new CSelectSpec;
        break;
    case SelectSpecStartTrigger:
        pparam = new CSelectSpecStartTrigger;
        break;
    case PeriodicTrigger:
        pparam = new CPeriodicTrigger;
        break;
    case GPITrigger:
        pparam = new CGPITrigger;
        break;
    case SelectSpecStopTrigger:
        pparam = new CSelectSpecStopTrigger;
        break;
    case AntennaSpec:
        pparam = new CAntennaSpec;
        break;
    case AntennaSpecStopTrigger:
        pparam = new CAntennaSpecStopTrigger;
        break;
    case TagObservationTrigger:
        pparam = new CTagObservationTrigger;
        break;
    case RfSpec:
        pparam = new CRfSpec;
        break;
    case MemoryBank:
        pparam = new CMemoryBank;
        break;
    case SelectReportSpec:
        pparam = new CSelectReportSpec;
        break;
    case ReportDestination:
        pparam = new CReportDestination;
        break;
    case AccessSpec:
        pparam = new CAccessSpec;
        break;
    case AccessSpecStopTrigger:
        pparam = new CAccessSpecStopTrigger;
        break;
    case AccessCommand:
        pparam = new CAccessCommand;
        break;
    case HbMatchSpec:
        pparam = new CHbMatchSpec;
        break;
    case HbTargetTag:
        pparam = new CHbTargetTag;
        break;
    case HbReadSpec:
        pparam = new CHbReadSpec;
        break;
    case HbWriteSpec:
        pparam = new CHbWriteSpec;
        break;
    case ClientRequestSpec:
        pparam = new CClientRequestSpec;
        break;
    case AccessReportSpec:
        pparam = new CAccessReportSpec;
        break;
    case TagReportData:
        pparam = new CTagReportData;
        break;
    case SelectSpecID:
        pparam = new CSelectSpecID;
        break;
    case SpecIndex:
        pparam = new CSpecIndex;
        break;
    case RfSpecID:
        pparam = new CRfSpecID;
        break;
    case AntennaID:
        pparam = new CAntennaID;
        break;
    case PeakRSSI:
        pparam = new CPeakRSSI;
        break;
    case FirstSeenTimestampUTC:
        pparam = new CFirstSeenTimestampUTC;
        break;
    case LastSeenTimestampUTC:
        pparam = new CLastSeenTimestampUTC;
        break;
    case TagSeenCount:
        pparam = new CTagSeenCount;
        break;
    case AccessSpecID:
        pparam = new CAccessSpecID;
        break;
    case GenaralSelectSpecResult:
        pparam = new CGenaralSelectSpecResult;
        break;
    case HbReadSpecResult:
        pparam = new CHbReadSpecResult;
        break;
    case HbWriteSpecResult:
        pparam = new CHbWriteSpecResult;
        break;
    case ClientRequestSpecResult:
        pparam = new CClientRequestSpecResult;
        break;
    case ClientRequestAck:
        pparam = new CClientRequestAck;
        break;
    case TagLog:
        pparam = new CTagLog;
        break;
    case StartLogTimestamp:
        pparam = new CStartLogTimestamp;
        break;
    case EndLogTimestamp:
        pparam = new CEndLogTimestamp;
        break;
    case DeviceLog:
        pparam = new CDeviceLog;
        break;
    case DeviceEventNotificationSpec:
        pparam = new CDeviceEventNotificationSpec;
        break;
    case EventNotificationState:
        pparam = new CEventNotificationState;
        break;
    case AntennaProperties:
        pparam = new CAntennaProperties;
        break;
    case AntennaConfiguration:
        pparam = new CAntennaConfiguration;
        break;
    case ModuleDepth:
        pparam = new CModuleDepth;
        break;
    case Identification:
        pparam = new CIdentification;
        break;
    case AlarmConfiguration:
        pparam = new CAlarmConfiguration;
        break;
    case AlarmThreshod:
        pparam = new CAlarmThreshod;
        break;
    case CommunicationConfiguration:
        pparam = new CCommunicationConfiguration;
        break;
    case CommLinkConfiguration:
        pparam = new CCommLinkConfiguration;
        break;
    case KeepaliveSpec:
        pparam = new CKeepaliveSpec;
        break;
    case TcpLinkConfiguration:
        pparam = new CTcpLinkConfiguration;
        break;
    case ClientModeConfiguration:
        pparam = new CClientModeConfiguration;
        break;
    case IPAddress:
        pparam = new CIPAddress;
        break;
    case ServerModeConfiguration:
        pparam = new CServerModeConfiguration;
        break;
    case SerialLinkConfiguration:
        pparam = new CSerialLinkConfiguration;
        break;
    case HttpLinkConfiguration:
        pparam = new CHttpLinkConfiguration;
        break;
    case EthernetIpv4Configuration:
        pparam = new CEthernetIpv4Configuration;
        break;
    case EthernetIpv6Configuration:
        pparam = new CEthernetIpv6Configuration;
        break;
    case NTPConfiguration:
        pparam = new CNTPConfiguration;
        break;
    case SerialPortConfiguration:
        pparam = new CSerialPortConfiguration;
        break;
    case VersionInfo:
        pparam = new CVersionInfo;
        break;
    case VersionDownload:
        pparam = new CVersionDownload;
        break;
    case AlarmReportInfo:
        pparam = new CAlarmReportInfo;
        break;
    case AlarmRestoreInfo:
        pparam = new CAlarmRestoreInfo;
        break;
    case AlarmSyncInfo:
        pparam = new CAlarmSyncInfo;
        break;
    case DiagnosticTestItem:
        pparam = new CDiagnosticTestItem;
        break;
    case DiagnosticTestResultItem:
        pparam = new CDiagnosticTestResultItem;
        break;
    case DiagnosticTestResultAntennaConnected:
        pparam = new CDiagnosticTestResultAntennaConnected;
        break;
    case DiagnosticTestResultAntennaVSWR:
        pparam = new CDiagnosticTestResultAntennaVSWR;
        break;
    case LocationConfiguration:
        pparam = new CLocationConfiguration;
        break;
    case GpsLocation:
        pparam = new CGpsLocation;
        break;
    case BdsLocation:
        pparam = new CBdsLocation;
        break;
    case SecurityModuleConfiguration:
        pparam = new CSecurityModuleConfiguration;
        break;
    case GenaralConfigData:
        pparam = new CGenaralConfigData;
        break;
    case RTCTime:
        pparam = new CRTCTime;
        break;
    case SecurityModuleSN:
        pparam = new CSecurityModuleSN;
        break;
    case ReadMode:
        pparam = new CReadMode;
        break;
    case SecurityModuleSpec:
        pparam = new CSecurityModuleSpec;
        break;
    case CustomizedSelectSpecResult:
        pparam = new CCustomizedSelectSpecResult;
        break;
    case HbCustomizedReadSpecResult:
        pparam = new CHbCustomizedReadSpecResult;
        break;
    case ReadDataInfo:
        pparam = new CReadDataInfo;
        break;
    case CID:
        pparam = new CCID;
        break;
    case FPDH:
        pparam = new CFPDH;
        break;
    case SYXZ:
        pparam = new CSYXZ;
        break;
    case CCRQ:
        pparam = new CCCRQ;
        break;
    case CLLX:
        pparam = new CCLLX;
        break;
    case GL:
        pparam = new CGL;
        break;
    case PL:
        pparam = new CPL;
        break;
    case HPZL:
        pparam = new CHPZL;
        break;
    case HPHMXH:
        pparam = new CHPHMXH;
        break;
    case JYYXQ:
        pparam = new CJYYXQ;
        break;
    case QZBFQ:
        pparam = new CQZBFQ;
        break;
    case ZKZL:
        pparam = new CZKZL;
        break;
    case CSYS:
        pparam = new CCSYS;
        break;
    //case PasswordVersion:
        //pparam = new CPasswordVersion;
        //break;

    }
    return pparam;
}




void HbFrame_Operation::addParamToMessage(CParameter *pParam,CMessage *pMessage){
    int messageid = pMessage->m_pType->m_TypeNum;
    int paramid = PARAM_BASE + pParam->m_pType->m_TypeNum;
    switch(messageid){
    case Keepalive:
        break;
    case KeepaliveAck:
        break;
    case DeviceEventNotification:
        switch(paramid){
        case UTCTimestamp:
            ((CDeviceEventNotification*)pMessage)->setUTCTimestamp((CUTCTimestamp*)pParam);
            break;
        case GPIEvent:
            ((CDeviceEventNotification*)pMessage)->setGPIEvent((CGPIEvent*)pParam);
            break;
        case SelectSpecEvent:
            ((CDeviceEventNotification*)pMessage)->setSelectSpecEvent((CSelectSpecEvent*)pParam);
            break;
        case AntennaSpecEvent:
            ((CDeviceEventNotification*)pMessage)->setAntennaSpecEvent((CAntennaSpecEvent*)pParam);
            break;
        case AntennaStatusEvent:
            ((CDeviceEventNotification*)pMessage)->setAntennaStatusEvent((CAntennaStatusEvent*)pParam);
            break;
        case ConnectionAttemptEvent:
            ((CDeviceEventNotification*)pMessage)->setConnectionAttemptEvent((CConnectionAttemptEvent*)pParam);
            break;
        }
        break;
    case GetDeviceCapabilities:
        break;
    case GetDeviceCapabilitiesAck:
        switch(paramid){
        case Status:
            ((CGetDeviceCapabilitiesAck*)pMessage)->setStatus((CStatus*)pParam);
            break;
        case GenaralCapabilities:
            ((CGetDeviceCapabilitiesAck*)pMessage)->setGenaralCapabilities((CGenaralCapabilities*)pParam);
            break;
        case CommunicationCapabilities:
            ((CGetDeviceCapabilitiesAck*)pMessage)->setCommunicationCapabilities((CCommunicationCapabilities*)pParam);
            break;
        case SpecCapabilities:
            ((CGetDeviceCapabilitiesAck*)pMessage)->setSpecCapabilities((CSpecCapabilities*)pParam);
            break;
        case RfCapabilities:
            ((CGetDeviceCapabilitiesAck*)pMessage)->setRfCapabilities((CRfCapabilities*)pParam);
            break;
        case AirProtocolCapabilities:
            ((CGetDeviceCapabilitiesAck*)pMessage)->setAirProtocolCapabilities((CAirProtocolCapabilities*)pParam);
            break;
        //case SecurityModuleCapabilities:
            //((CGetDeviceCapabilitiesAck*)pMessage)->setSecurityModuleCapabilities((CSecurityModuleCapabilities*)pParam);
            //break;
        }
        break;
    case AddSelectSpec:
        ((CAddSelectSpec*)pMessage)->setSelectSpec((CSelectSpec*)pParam);
        break;
    case AddSelectSpecAck:
        ((CAddSelectSpecAck*)pMessage)->setStatus((CStatus*)pParam);
        //((CAddSelectSpecAck*)pMessage)->setStatus((CStatus*)pParam);
        break;
    case DeleteSelectSpec:
        break;
    case DeleteSelectSpecAck:
        ((CDeleteSelectSpecAck*)pMessage)->setStatus((CStatus*)pParam);
        break;
    case StartSelectSpec:
        break;
    case StartSelectSpecAck:
        ((CStartSelectSpecAck*)pMessage)->setStatus((CStatus*)pParam);
        break;
    case StopSelectSpec:
        break;
    case StopSelectSpecAck:
        ((CStopSelectSpecAck*)pMessage)->setStatus((CStatus*)pParam);
        break;
    case EnableSelectSpec:
        break;
    case EnableSelectSpecAck:
        ((CEnableSelectSpecAck*)pMessage)->setStatus((CStatus*)pParam);
        break;
    case DisableSelectSpec:
        break;
    case DisableSelectSpecAck:
        ((CDisableSelectSpecAck*)pMessage)->setStatus((CStatus*)pParam);
        break;
    case GetSelectSpec:
        break;
    case GetSelectSpecAck:
        switch(paramid){
        case Status:
            ((CGetSelectSpecAck*)pMessage)->setStatus((CStatus*)pParam);
            break;
        case SelectSpec:
            ((CGetSelectSpecAck*)pMessage)->addSelectSpec((CSelectSpec*)pParam);
            break;
        }

        break;
    case AddAccessSpec:
        ((CAddAccessSpec*)pMessage)->setAccessSpec((CAccessSpec*)pParam);
        break;
    case AddAccessSpecAck:
        ((CAddAccessSpecAck*)pMessage)->setStatus((CStatus*)pParam);
        break;
    case DeleteAccessSpec:
        break;
    case DeleteAccessSpecAck:
        ((CDeleteAccessSpecAck*)pMessage)->setStatus((CStatus*)pParam);
        break;
    case EnableAccessSpec:
        break;
    case EnableAccessSpecAck:
        ((CEnableAccessSpecAck*)pMessage)->setStatus((CStatus*)pParam);
        break;
    case DisableAccessSpec:
        break;
    case DisableAccessSpecAck:
        ((CDisableAccessSpecAck*)pMessage)->setStatus((CStatus*)pParam);
        break;
    case GetAccessSpec:
        break;
    case GetAccessSpecAck:
        switch(paramid){
        case Status:
            ((CGetAccessSpecAck*)pMessage)->setStatus((CStatus*)pParam);
            break;
        case AccessSpec:
            ((CGetAccessSpecAck*)pMessage)->addAccessSpec((CAccessSpec*)pParam);
            break;
        }
        break;
    case TagSelectAccessReport:
        ((CTagSelectAccessReport*)pMessage)->addTagReportData((CTagReportData*)pParam);
        break;
    case ClientRequestOp:
        ((CClientRequestOp*)pMessage)->setTagReportData((CTagReportData*)pParam);
        break;
    case ClientRequestOpAck:
        ((CClientRequestOpAck*)pMessage)->setClientRequestAck((CClientRequestAck*)pParam);
        break;

    //========================================================//
    case DeviceBinding:
        break;
    case DeviceBindingAck:
        ((CDeviceBindingAck*)pMessage)->setStatus((CStatus*)pParam);
        break;
    case UploadTagLog:
        switch(paramid){
        case StartLogTimestamp:
            ((CUploadTagLog*)pMessage)->setStartLogTimestamp((CStartLogTimestamp*)pParam);
            break;
        case EndLogTimestamp:
            ((CUploadTagLog*)pMessage)->setEndLogTimestamp((CEndLogTimestamp*)pParam);
            break;
        }
        break;
    case UploadTagLogAck:
        switch(paramid){
        case Status:
            ((CUploadTagLogAck*)pMessage)->setStatus((CStatus*)pParam);
            break;
        case TagLog:
            ((CUploadTagLogAck*)pMessage)->addTagLog((CTagLog*)pParam);
            break;
        }
        break;
    case ClearTagLogAck:
        ((CClearTagLogAck*)pMessage)->setStatus((CStatus*)pParam);
        break;
    case UploadDeviceLog:
        switch(paramid){
        case StartLogTimestamp:
            ((CUploadDeviceLog*)pMessage)->setStartLogTimestamp((CStartLogTimestamp*)pParam);
            break;
        case EndLogTimestamp:
            ((CUploadDeviceLog*)pMessage)->setEndLogTimestamp((CEndLogTimestamp*)pParam);
            break;
        }
        break;
    case UploadDeviceLogAck:
        switch(paramid){
        case Status:
            ((CUploadDeviceLogAck*)pMessage)->setStatus((CStatus*)pParam);
            break;
        case TagLog:
            ((CUploadDeviceLogAck*)pMessage)->addDeviceLog((CDeviceLog*)pParam);
            break;
        }
        break;
    case ClearDeviceLog:
        break;
    case ClearDeviceLogAck:
        ((CClearDeviceLogAck*)pMessage)->setStatus((CStatus*)pParam);
        break;
    case GetDeviceConfig:
        break;
    case GetDeviceConfigAck:
        switch(paramid){
        case Status:
            ((CGetDeviceConfigAck*)pMessage)->setStatus((CStatus*)pParam);
            break;
        case Identification:
            ((CGetDeviceConfigAck*)pMessage)->setIdentification((CIdentification*)pParam);
            break;
        case DeviceEventNotificationSpec:
            ((CGetDeviceConfigAck*)pMessage)->setDeviceEventNotificationSpec((CDeviceEventNotificationSpec*)pParam);
            break;
        case AlarmConfiguration:
            ((CGetDeviceConfigAck*)pMessage)->setAlarmConfiguration((CAlarmConfiguration*)pParam);
            break;
        case AntennaProperties:
            ((CGetDeviceConfigAck*)pMessage)->addAntennaProperties((CAntennaProperties*)pParam);
            break;
        case AntennaConfiguration:
            ((CGetDeviceConfigAck*)pMessage)->addAntennaConfiguration((CAntennaConfiguration*)pParam);
            break;
        case ModuleDepth:
            ((CGetDeviceConfigAck*)pMessage)->setModuleDepth((CModuleDepth*)pParam);
            break;
        case SelectReportSpec:
            ((CGetDeviceConfigAck*)pMessage)->setSelectReportSpec((CSelectReportSpec*)pParam);
            break;
        case AccessReportSpec:
            ((CGetDeviceConfigAck*)pMessage)->setAccessReportSpec((CAccessReportSpec*)pParam);
            break;
        case CommunicationConfiguration:
            ((CGetDeviceConfigAck*)pMessage)->setCommunicationConfiguration((CCommunicationConfiguration*)pParam);
            break;
        case LocationConfiguration:
            ((CGetDeviceConfigAck*)pMessage)->setLocationConfiguration((CLocationConfiguration*)pParam);
            break;
        case SecurityModuleConfiguration:
            ((CGetDeviceConfigAck*)pMessage)->setSecurityModuleConfiguration((CSecurityModuleConfiguration*)pParam);
            break;
        }
        break;
    case SetDeviceConfig:
        switch(paramid){
        case Identification:
            ((CSetDeviceConfig*)pMessage)->setIdentification((CIdentification*)pParam);
            break;
        case DeviceEventNotificationSpec:
            ((CSetDeviceConfig*)pMessage)->setDeviceEventNotificationSpec((CDeviceEventNotificationSpec*)pParam);
            break;
        case AlarmConfiguration:
            ((CSetDeviceConfig*)pMessage)->setAlarmConfiguration((CAlarmConfiguration*)pParam);
            break;
        case AntennaConfiguration:
            ((CSetDeviceConfig*)pMessage)->addAntennaConfiguration((CAntennaConfiguration*)pParam);
            break;
        case ModuleDepth:
            ((CSetDeviceConfig*)pMessage)->setModuleDepth((CModuleDepth*)pParam);
            break;
        case SelectReportSpec:
            ((CSetDeviceConfig*)pMessage)->setSelectReportSpec((CSelectReportSpec*)pParam);
            break;
        case AccessReportSpec:
            ((CSetDeviceConfig*)pMessage)->setAccessReportSpec((CAccessReportSpec*)pParam);
            break;
        case CommunicationConfiguration:
            ((CSetDeviceConfig*)pMessage)->setCommunicationConfiguration((CCommunicationConfiguration*)pParam);
            break;
        case LocationConfiguration:
            ((CSetDeviceConfig*)pMessage)->setLocationConfiguration((CLocationConfiguration*)pParam);
            break;
        case SecurityModuleConfiguration:
            ((CSetDeviceConfig*)pMessage)->setSecurityModuleConfiguration ((CSecurityModuleConfiguration*)pParam);
            break;
        }
        break;
    case SetDeviceConfigAck:
        ((CSetDeviceConfigAck*)pMessage)->setStatus((CStatus*)pParam);
        break;
    case GetVersion:
        break;
    case GetVersionAck:
        switch(paramid){
        case Status:
            ((CGetVersionAck*)pMessage)->setStatus((CStatus*)pParam);
            break;
        case VersionInfo:
            ((CGetVersionAck*)pMessage)->addVersionInfo((CVersionInfo*)pParam);
            break;
        }

        break;
    case SetVersion:
        ((CSetVersion*)pMessage)->setVersionDownload((CVersionDownload*)pParam);
        break;
    case SetVersionAck:
        ((CSetVersionAck*)pMessage)->setStatus((CStatus*)pParam);
        break;
    case ActiveVersion:
        break;
    case ActiveVersionAck:
        ((CActiveVersionAck*)pMessage)->setStatus((CStatus*)pParam);
        break;
    case UnActiveVersion:
        break;
    case UnActiveVersionAck:
        ((CUnActiveVersionAck*)pMessage)->setStatus((CStatus*)pParam);
        break;
    case AlarmReport:
        ((CAlarmReport*)pMessage)->setAlarmReportInfo((CAlarmReportInfo*)pParam);
        break;
    case AlarmRestore:
        ((CAlarmRestore*)pMessage)->setAlarmRestoreInfo((CAlarmRestoreInfo*)pParam);
        break;
    case AlarmDelete:
        break;
    case AlarmSync:
        ((CAlarmSync*)pMessage)->setAlarmSyncInfo((CAlarmSyncInfo*)pParam);
        break;
    case DiagnosticTest:
        ((CDiagnosticTest*)pMessage)->addDiagnosticTestItem((CDiagnosticTestItem*)pParam);
        break;
    case DiagnosticTestAck:
        switch(paramid){
        case Status:
            ((CDiagnosticTestAck*)pMessage)->setStatus((CStatus*)pParam);
            break;
        case DiagnosticTestResultItem:
            ((CDiagnosticTestAck*)pMessage)->addDiagnosticTestResultItem((CDiagnosticTestResultItem*)pParam);
            break;
        }
        break;
    case ResetDevice:
        break;
    case ResetDeviceAck:
        ((CResetDeviceAck*)pMessage)->setStatus((CStatus*)pParam);
        break;
    case DeviceCertificateConfig:
        break;
    case DeviceCertificateConfigAck:
        ((CDeviceCertificateConfigAck*)pMessage)->setStatus((CStatus*)pParam);
        break;
    case DeviceBindingResultNotification:
        ((CDeviceBindingResultNotification*)pMessage)->setStatus((CStatus*)pParam);
        break;
    case TagLogCountAck:
        ((CTagLogCountAck*)pMessage)->setStatus((CStatus*)pParam);
        break;
    case DeviceLogCountAck:
        ((CDeviceLogCountAck*)pMessage)->setStatus((CStatus*)pParam);
        break;

    }//end of switch(messageid)


}



void HbFrame_Operation::addParamToParameter(CParameter *pChild,CParameter *pParent){

    int parentid = PARAM_BASE+pParent->m_pType->m_TypeNum;
    int childid = PARAM_BASE+pChild->m_pType->m_TypeNum;
    switch(parentid){
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
        switch(childid){
        case GPIOCapabilities:
            ((CGenaralCapabilities*)pParent)->setGPIOCapabilities((CGPIOCapabilities *)pChild);
            break;
        }
        break;
    case CommunicationCapabilities:
        switch(childid){
        case SupportRS232:
            ((CCommunicationCapabilities*)pParent)->setSupportRS232((CSupportRS232*)pChild);
            break;
        case SupportRS485:
            ((CCommunicationCapabilities*)pParent)->setSupportRS485((CSupportRS485*)pChild);
            break;
        }
        break;
    case SupportRS232:
        ((CSupportRS232*)pParent)->addSerialAttribute((CSerialAttribute*)pChild);
        break;
    case SupportRS485:
        ((CSupportRS485*)pParent)->addSerialAttribute((CSerialAttribute*)pChild);
        break;
    case RfCapabilities:
        switch(childid){
        case TransmitPowerLevelTable:
            ((CRfCapabilities*)pParent)->addTransmitPowerLevelTable((CTransmitPowerLevelTable*)pChild);
            break;
        case FrequencyInformation:
            ((CRfCapabilities*)pParent)->setFrequencyInformation((CFrequencyInformation*)pChild);
            break;
        case ForDataRateTable:
            ((CRfCapabilities*)pParent)->addForDataRateTable((CForDataRateTable*)pChild);
            break;
        case RevDataRateTable:
            ((CRfCapabilities*)pParent)->addRevDataRateTable((CRevDataRateTable*)pChild);
            break;
        case ForModulationTable:
            ((CRfCapabilities*)pParent)->addForModulationTable((CForModulationTable*)pChild);
            break;
        case RevDataEncodingTable:
            ((CRfCapabilities*)pParent)->addRevDataEncodingTable((CRevDataEncodingTable*)pChild);
            break;
        case ModuleDepthTable:
            ((CRfCapabilities*)pParent)->addModuleDepthTable((CModuleDepthTable*)pChild);
            break;
        }

        break;
    case FrequencyInformation:
        ((CFrequencyInformation*)pParent)->addFrequencyTable((CFrequencyTable*)pChild);
        break;
    case AirProtocolCapabilities:

        switch(childid){
        case PerAntennaAirProtocol:
            ((CAirProtocolCapabilities*)pParent)->addPerAntennaAirProtocol((CPerAntennaAirProtocol*)pChild);
            break;
        case HbProtocolCapabilities:
            ((CAirProtocolCapabilities*)pParent)->addHbProtocolCapabilities((CHbProtocolCapabilities*)pChild);
            break;
        }
    //===================ҵ��ӿڲ���======================//
    case SelectSpec:
        switch(childid){
        case SelectSpecStartTrigger:
            ((CSelectSpec*)pParent)->setSelectSpecStartTrigger((CSelectSpecStartTrigger*)pChild);
            break;
        case SelectSpecStopTrigger:
            ((CSelectSpec*)pParent)->setSelectSpecStopTrigger((CSelectSpecStopTrigger*)pChild);
            break;
        case AntennaSpec:
            ((CSelectSpec*)pParent)->addAntennaSpec((CAntennaSpec*)pChild);
            break;
        case SelectReportSpec:
            ((CSelectSpec*)pParent)->setSelectReportSpec((CSelectReportSpec*)pChild);
            break;
        }
        break;
    case SelectSpecStartTrigger:
        switch(childid){
        case PeriodicTrigger:
            ((CSelectSpecStartTrigger*)pParent)->setPeriodicTrigger((CPeriodicTrigger*)pChild);
            break;
        case GPITrigger:
            ((CSelectSpecStartTrigger*)pParent)->setGPITrigger((CGPITrigger*)pChild);
            break;
        }
        break;
    case SelectSpecStopTrigger:
        ((CSelectSpecStartTrigger*)pParent)->setGPITrigger((CGPITrigger*)pChild);
        break;
    case AntennaSpec:
        switch(childid){
        case AntennaSpecStopTrigger:
            ((CAntennaSpec*)pParent)->setAntennaSpecStopTrigger((CAntennaSpecStopTrigger*)pChild);
            break;
        case RfSpec:
            ((CAntennaSpec*)pParent)->addRfSpec((CRfSpec*)pChild);
            break;
        }
        break;
    case SelectReportSpec:
        ((CSelectReportSpec*)pParent)->setReportDestination((CReportDestination*)pChild);
        break;
    case PeriodicTrigger:
        ((CPeriodicTrigger*)pParent)->setUTCTimestamp((CUTCTimestamp*)pChild);
        break;
    case AntennaSpecStopTrigger:
        switch(childid){
        case GPITrigger:
            ((CAntennaSpecStopTrigger*)pParent)->setGPITrigger((CGPITrigger*)pChild);
            break;
        case TagObservationTrigger:
            ((CAntennaSpecStopTrigger*)pParent)->setTagObservationTrigger((CTagObservationTrigger*)pChild);
            break;
        }
        break;
    case RfSpec:
        switch(childid){
        case MemoryBank:
            ((CRfSpec*)pParent)->setMemoryBank((CMemoryBank*)pChild);
            break;
        case AntennaConfiguration:
            ((CRfSpec*)pParent)->addAntennaConfiguration((CAntennaConfiguration*)pChild);
            break;
        }
        break;
    case ReportDestination:
        ((CReportDestination*)pParent)->addCommLinkConfiguration((CCommLinkConfiguration*)pChild);
        break;
    case CommLinkConfiguration:
        switch(childid){
        case KeepaliveSpec:
            ((CCommLinkConfiguration*)pParent)->setKeepaliveSpec((CKeepaliveSpec*)pChild);
            break;
        case TcpLinkConfiguration:
            ((CCommLinkConfiguration*)pParent)->setTcpLinkConfiguration((CTcpLinkConfiguration*)pChild);
            break;
        case SerialLinkConfiguration:
            ((CCommLinkConfiguration*)pParent)->setSerialLinkConfiguration((CSerialLinkConfiguration*)pChild);
            break;
        case HttpLinkConfiguration:
            ((CCommLinkConfiguration*)pParent)->setHttpLinkConfiguration((CHttpLinkConfiguration*)pChild);
            break;
        }

        break;
    case TcpLinkConfiguration:
        switch(childid){
        case ClientModeConfiguration:
            ((CTcpLinkConfiguration*)pParent)->setClientModeConfiguration((CClientModeConfiguration*)pChild);
            break;
        case ServerModeConfiguration:
            ((CTcpLinkConfiguration*)pParent)->setServerModeConfiguration((CServerModeConfiguration*)pChild);
            break;
        }
        break;
    case ClientModeConfiguration:
        ((CClientModeConfiguration*)pParent)->setIPAddress((CIPAddress*)pChild);
        break;
    case AccessSpec:
        switch(childid){
        case AccessSpecStopTrigger:
            ((CAccessSpec*)pParent)->setAccessSpecStopTrigger((CAccessSpecStopTrigger*)pChild);
            break;
        case AccessCommand:
            ((CAccessSpec*)pParent)->setAccessCommand((CAccessCommand*)pChild);
            break;
        case AccessReportSpec:
            ((CAccessSpec*)pParent)->setAccessReportSpec((CAccessReportSpec*)pChild);
            break;
        }
        break;
    case AccessSpecStopTrigger:
        break;
    case AccessCommand:
        switch(childid){
        case HbMatchSpec:
            ((CAccessCommand*)pParent)->setHbMatchSpec((CHbMatchSpec*)pChild);
            break;
        case HbReadSpec:
            ((CAccessCommand*)pParent)->addOpSpec((CParameter*)pChild);
            break;
        case HbWriteSpec:
            ((CAccessCommand*)pParent)->addOpSpec((CParameter*)pChild);
            break;
        case ClientRequestSpec :
            ((CAccessCommand*)pParent)->addOpSpec((CParameter*)pChild);
            break;
        case SecurityModuleSpec :
            ((CAccessCommand*)pParent)->setSecurityModuleSpec((CSecurityModuleSpec*)pChild);
        }
        break;
    case HbMatchSpec:
        ((CHbMatchSpec*)pParent)->addHbTargetTag((CHbTargetTag*)pChild);
        break;
    case HbTargetTag:
        break;
    case HbReadSpec:
        switch(childid){
        case MemoryBank:
            ((CHbReadSpec*)pParent)->setMemoryBank((CMemoryBank*)pChild);
            break;
        }
        break;
    case HbWriteSpec:
        break;
    case ClientRequestSpec:
        break;
    case AccessReportSpec:
        ((CAccessReportSpec*)pParent)->setReportDestination((CReportDestination*)pChild);
        break;
    case TagReportData:
        switch(childid){
        case SelectSpecID:
            ((CTagReportData*)pParent)->setSelectSpecID((CSelectSpecID*)pChild);
            break;
        case SpecIndex:
            ((CTagReportData*)pParent)->setSpecIndex((CSpecIndex*)pChild);
            break;
        case RfSpecID:
            ((CTagReportData*)pParent)->setRfSpecID((CRfSpecID*)pChild);
            break;
        case AntennaID:
            ((CTagReportData*)pParent)->setAntennaID((CAntennaID*)pChild);
            break;
        case PeakRSSI:
            ((CTagReportData*)pParent)->setPeakRSSI((CPeakRSSI*)pChild);
            break;
        case FirstSeenTimestampUTC:
            ((CTagReportData*)pParent)->setFirstSeenTimestampUTC((CFirstSeenTimestampUTC*)pChild);
            break;
        case LastSeenTimestampUTC:
            ((CTagReportData*)pParent)->setLastSeenTimestampUTC((CLastSeenTimestampUTC*)pChild);
            break;
        case TagSeenCount:
            ((CTagReportData*)pParent)->setTagSeenCount((CTagSeenCount*)pChild);
            break;
        case AccessSpecID:
            ((CTagReportData*)pParent)->setAccessSpecID((CAccessSpecID*)pChild);
            break;
        case GenaralSelectSpecResult:
            ((CTagReportData*)pParent)->setSelectSpecResult((CParameter*)pChild);
            break;
        case CustomizedSelectSpecResult:
            ((CTagReportData*)pParent)->setSelectSpecResult((CParameter*)pChild);
            break;
        case HbReadSpecResult:
            ((CTagReportData*)pParent)->addAccessSpecResult((CParameter*)pChild);
            break;
        case HbCustomizedReadSpecResult:
            ((CTagReportData*)pParent)->addAccessSpecResult((CParameter*)pChild);
            break;
        case HbWriteSpecResult:
            ((CTagReportData*)pParent)->addAccessSpecResult((CParameter*)pChild);
            break;
        case ClientRequestSpecResult:
            ((CTagReportData*)pParent)->addAccessSpecResult((CParameter*)pChild);
            break;
        }
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
    case GenaralSelectSpecResult:
        break;
    case HbReadSpecResult:
        break;
    case HbWriteSpecResult:
        break;
    case ClientRequestSpecResult:
        break;
    case ClientRequestAck:
        //�����
        break;
    //================================================//
    case TagLog:
        ((CTagLog*)pParent)->setUTCTimestamp((CUTCTimestamp*)pChild);
        break;
    case StartLogTimestamp:
        break;
    case EndLogTimestamp:
        break;
    case DeviceLog:
        ((CDeviceLog*)pParent)->setUTCTimestamp((CUTCTimestamp*)pChild);
        break;
    case DeviceEventNotificationSpec:
        ((CDeviceEventNotificationSpec*)pParent)->addEventNotificationState((CEventNotificationState*)pChild);
        break;
    case EventNotificationState:
        break;
    case AntennaProperties:
        break;
    case AntennaConfiguration:
        break;
    case ModuleDepth:
        break;
    case Identification:
        break;
    case AlarmConfiguration:
        ((CAlarmConfiguration*)pParent)->setAlarmThreshod((CAlarmThreshod*)pChild);
        break;
    case AlarmThreshod:
        break;
    case CommunicationConfiguration:
        switch(childid)	{
        case CommLinkConfiguration:
            ((CCommunicationConfiguration*)pParent)->addCommLinkConfiguration((CCommLinkConfiguration*)pChild);
            break;
        case EthernetIpv4Configuration:
        case EthernetIpv6Configuration:
            ((CCommunicationConfiguration*)pParent)->addEthernetConfiguration((CParameter*)pChild);
            break;
        case SerialPortConfiguration:
            ((CCommunicationConfiguration*)pParent)->addSerialPortConfiguration((CSerialPortConfiguration*)pChild);
            break;
        case NTPConfiguration:
            ((CCommunicationConfiguration*)pParent)->setNTPConfiguration((CNTPConfiguration*)pChild);
            break;
        }
        break;
    case ServerModeConfiguration:
        break;
    case SerialLinkConfiguration:
        break;
    case HttpLinkConfiguration:
        break;
    case EthernetIpv4Configuration:
        break;
    case EthernetIpv6Configuration:
        break;
    case NTPConfiguration:
        ((CNTPConfiguration*)pParent)->addIPAddress((CIPAddress*)pChild);
        break;
    case SerialPortConfiguration:
        break;
    case VersionInfo:
        break;
    case VersionDownload:
        ((CVersionDownload*)pParent)->setIPAddress((CIPAddress*)pChild);
        break;
    case AlarmReportInfo:
        break;
    case AlarmRestoreInfo:
        break;
    case AlarmSyncInfo:
        break;
    case DiagnosticTestItem:
        //((CDiagnosticTestItem*)pMessage);//Э��˵���У�������һ����δ�����ȷ��
        break;
    case DiagnosticTestResultItem:
        ((CDiagnosticTestResultItem*)pParent)->setDiagnosticTestResultData((CParameter*)pChild);
        break;
    case DiagnosticTestResultAntennaConnected:
        break;
    case DiagnosticTestResultAntennaVSWR:
        break;
    case LocationConfiguration:
        ((CLocationConfiguration*)pParent)->setLocationInfo((CGpsLocation*)pChild);
        break;
    case SecurityModuleSpec:
        ((CSecurityModuleSpec*)pParent)->setReadMode((CReadMode*)pChild);
        break;
    case CustomizedSelectSpecResult:
        ((CCustomizedSelectSpecResult*)pParent)->setReadDataInfo((CReadDataInfo*)pChild);
        break;
    case HbCustomizedReadSpecResult:
        ((CHbCustomizedReadSpecResult*)pParent)->setReadDataInfo((CReadDataInfo*)pChild);
        break;
    case ReadDataInfo:
        switch(childid)	{
        case CID:
            ((CReadDataInfo*)pParent)->setCID((CCID*)pChild);
            break;
        case FPDH:
            ((CReadDataInfo*)pParent)->setFPDH((CFPDH*)pChild);
            break;
        case SYXZ:
            ((CReadDataInfo*)pParent)->setSYXZ((CSYXZ*)pChild);
            break;
        case CCRQ:
            ((CReadDataInfo*)pParent)->setCCRQ((CCCRQ*)pChild);
            break;
        case CLLX:
            ((CReadDataInfo*)pParent)->setCLLX((CCLLX*)pChild);
            break;
        case GL:
            ((CReadDataInfo*)pParent)->setGL((CGL*)pChild);
            break;
        case PL:
            ((CReadDataInfo*)pParent)->setPL((CPL*)pChild);
            break;
        case HPZL:
            ((CReadDataInfo*)pParent)->setHPZL((CHPZL*)pChild);
            break;
        case HPHMXH:
            ((CReadDataInfo*)pParent)->setHPHMXH((CHPHMXH*)pChild);
            break;
        case JYYXQ:
            ((CReadDataInfo*)pParent)->setJYYXQ((CJYYXQ*)pChild);
            break;
        case QZBFQ:
            ((CReadDataInfo*)pParent)->setQZBFQ((CQZBFQ*)pChild);
            break;
        case ZKZL:
            ((CReadDataInfo*)pParent)->setZKZL((CZKZL*)pChild);
            break;
        case CSYS:
            ((CReadDataInfo*)pParent)->setCSYS((CCSYS*)pChild);
            break;
        }
        break;
    case CachedSelectAccessReport:
        ((CCachedSelectAccessReport*)pParent)->addTagReportData((CTagReportData*)pChild);
        break;
    case SecurityModuleConfiguration:
        ((CSecurityModuleConfiguration*)pParent)->setGenaralConfigData((CGenaralConfigData*)pChild);
        break;
    case GenaralConfigData:
        switch(childid)	{
        case RTCTime:
            ((CGenaralConfigData*)pParent)->setRTCTime((CRTCTime*)pChild);
            break;
        case SecurityModuleSN:
            ((CGenaralConfigData*)pParent)->setSecurityModuleSN((CSecurityModuleSN*)pChild);
            break;
        case ReadMode:
            ((CGenaralConfigData*)pParent)->setReadMode((CReadMode*)pChild);
            break;
        //case PasswordVersion:
            //((CGenaralConfigData*)pParent)->setPasswordVersion((CPasswordVersion*)pChild);
            //break;

        }
        break;

    }//end of switch(parentid)

}

/**
 * @brief HbFrame_Operation::getMessageFromBuf
 * @param buf
 * @param messageLength，可比实际消息长度长
 * @return
 * 从Buf中获取消息。输入的消息二进制码长度是包插消息头在内的整个消息长度。
 */
CMessage *HbFrame_Operation::getMessageFromBuf(unsigned char *buf,int messageLength){
    CTypeRegistry * ptyperegistry = getTheTypeRegistry();

		//为自定义消息添加
    tmp_enrollCoreTypesIntoRegistry (ptyperegistry);

    CFrameDecoder framedecoder(ptyperegistry,buf,messageLength);
    CMessage* decodemessage = framedecoder.decodeMessage();

    /*if(decodemessage==NULL){
        printf("decode message error,errcode =%d\n",framedecoder.m_ErrorDetails.m_eResultCode);
    }*/
    delete ptyperegistry;

    return decodemessage;

}

/**
 * @brief HbFrame_Operation::putMessageToBuf
 * @param pmessage
 * @param buf，缓存区
 * @param buflen，缓存区长度
 * @return，消息的二进制流长度，注意，此长度已含消息头19字节的长度
 * 将消息变为二进制流放入缓存中。
 */
int HbFrame_Operation::putMessageToBuf(CMessage *pmessage,unsigned char *buf,int buflen){
    if(pmessage==NULL){
        return 0;
    }
    CFrameEncoder frameencoder(buf,buflen);
    frameencoder.encodeElement(pmessage);
    int msglen = frameencoder.getLength();
    return msglen;
}

/**
 * @brief HbFrame_Operation::convertMessageToHex
 * @param pMessage
 * @return
 * 将消息改为hex字符串。
 */
char *HbFrame_Operation::convertMessageToHex(CMessage *pMessage){
    unsigned char buf[MAX_TX_LEN];
    int msglen = putMessageToBuf(pMessage,buf,MAX_TX_LEN);
    if(msglen==0){
        return NULL;
    }else{
        char *hex = new char[msglen*2+1];
        HEXConvert::byteTohex(hex,buf,msglen);
        hex[msglen*2] = 0x00; //将最后一位置为零
        return hex;
    }
}

/**
 * @brief HbFrame_Operation::convertHexToMessage
 * @param hexBuf，hex字符串，要求最后一字符为0x00
 * @return
 * 将hex字符串转为消息
 */
CMessage *HbFrame_Operation::convertHexToMessage(char *hexBuf){
    unsigned char *bytes = new unsigned char[strlen(hexBuf)]; //简单处理为缓存区比实际所需大一倍
    int msglen = HEXConvert::hexTobyte(bytes,hexBuf,strlen(hexBuf));

    CMessage *pmessage = getMessageFromBuf(bytes,msglen);
    if(pmessage==NULL){
        printf("convertHexToMessage fail!\n");
        printf("error hex = %s\n", hexBuf);
    }
    delete [] bytes;
    return pmessage;
}

/**
 * @brief HbFrame_Operation::copyMessage
 * @param pMessage
 * @return
 * 采用二进制流为过渡层，复制一个消息
 */
CMessage * HbFrame_Operation::copyMessage(CMessage *pMessage){
    unsigned char buf[MAX_TX_LEN];
    int msglen = putMessageToBuf(pMessage,buf,MAX_TX_LEN);
    if(msglen==0){
        return NULL;
    }else{
        //CFrameExtract extract = CFrameExtract(buf,msglen);
        //printf("msglen=%d,extract=%d\n",msglen,extract.m_MessageLength+19u);
        CMessage *pmsg = getMessageFromBuf(buf,msglen);
        if(pmsg==NULL){
            printf("copy message fail!\n");
        }
        return pmsg;
    }
}

CMessage *HbFrame_Operation::getMessageFromXml(string xmlstring){

    /*const CTypeRegistry *pTyperegistry = getTheTypeRegistry();

    CXMLDecoder decoder(pTyperegistry,(char *)xmlstring.c_str(),xmlstring.length());
    CMessage *pmessage = decoder.decodeMessage();

    delete pTyperegistry;

    if(pmessage==NULL){
        printf("Get Message from xml fail!\n");
        return NULL;
    }else{
        printf("Get Message from xml success!\n");
        return pmessage;
    }*/
}

CParameter *HbFrame_Operation::getParameterFromXml(string xmlstring){

    /*const CTypeRegistry *pTyperegistry = getTheTypeRegistry();

    CXMLDecoder decoder(pTyperegistry,(char *)xmlstring.c_str(),xmlstring.length());
    //printf("decode xml parameter!\n");
    CParameter *parameter = decoder.decodeParameter();

    delete pTyperegistry;

    if(parameter==NULL){
        printf("Get CParameter from xml fail!\n");
        return NULL;
    }else{
        printf("Get CParameter from xml success!\n");
        return parameter;
    }*/
}

string HbFrame_Operation::getXmlFromMessage(CMessage *pmessage){
    char buf[4*1024];
		int s = sizeof(buf);
    memset(buf,0,sizeof(buf));

		s = sizeof buf;
    CXMLTextEncoder  XMLEncoder(buf, sizeof buf);

    XMLEncoder.encodeElement(pmessage);
    string xmlstring;
    if(!XMLEncoder.m_bOverflow)
    {
        xmlstring = buf;
    }
    else
    {
        xmlstring = "";
    }

    return xmlstring;

}

string HbFrame_Operation::getXmlFromParameter(CParameter *pParameter){
    char buf[4*1024];
    memset(buf,0,sizeof(buf));

    CXMLTextEncoder  XMLEncoder(buf, sizeof buf);

    XMLEncoder.encodeElement(pParameter);
    string xmlstring;
    if(!XMLEncoder.m_bOverflow)
    {
        xmlstring = buf;
    }
    else
    {
        xmlstring = "";
    }

    return xmlstring;

}


void HbFrame_Operation::printMessage(CMessage *pMessage){
    std::string xmlstring = getXmlFromMessage(pMessage);
		const char *a = xmlstring.c_str();
    printf("%s\n",a);
//		int len = xmlstring.length();
//		for(int i=0;i<(len/100);i++){
//			char t[110] = {0x00};
//			memcpy(t,a+i*100,100);
//			printf("%s",t);
//		}
//		char tt[110] = {0x00};
//		int c = len/100;
//		int d = len%100;
//		memcpy(tt,a+c,d);
//		printf("%s",tt);
}

