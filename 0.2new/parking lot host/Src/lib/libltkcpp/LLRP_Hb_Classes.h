#ifndef __LLRP_HB_CLASSES_H__
#define __LLRP_HB_CLASSES_H__

#include "ltkcpp_platform.h"
#include "ltkcpp_base.h"
#include "ltkcpp_frame.h"
#include "ltkcpp_xmltext.h"

namespace LLRP{

extern const CNamespaceDescriptor g_nsdescllrp;

// Operation
/*
 * Message classes - forward decls
 */

class CAddSelectSpec;
class CAddSelectSpecAck;
class CDeleteSelectSpec;
class CDeleteSelectSpecAck;
class CStartSelectSpec;
class CStartSelectSpecAck;
class CStopSelectSpec;
class CStopSelectSpecAck;
class CEnableSelectSpec;
class CEnableSelectSpecAck;
class CDisableSelectSpec;
class CDisableSelectSpecAck;
class CGetSelectSpec;
class CGetSelectSpecAck;
class CAddAccessSpec;
class CAddAccessSpecAck;
class CDeleteAccessSpec;
class CDeleteAccessSpecAck;
class CEnableAccessSpec;
class CEnableAccessSpecAck;
class CDisableAccessSpec;
class CDisableAccessSpecAck;
class CGetAccessSpec;
class CGetAccessSpecAck;
class CTagSelectAccessReport;
class CClientRequestOp;
class CClientRequestOpAck;

/* Custom messages */


/*
 * Parameter classes - forward decls
 */

class CSelectSpec;
class CSelectSpecStartTrigger;
class CPeriodicTrigger;
class CGPITrigger;
class CSelectSpecStopTrigger;
class CAntennaSpec;
class CAntennaSpecStopTrigger;
class CTagObservationTrigger;
class CRfSpec;
class CMemoryBank;
class CSelectReportSpec;
class CReportDestination;
class CAccessSpec;
class CAccessSpecStopTrigger;
class CAccessCommand;
class CSecurityModuleSpec;
class COpSpec;
class CHbMatchSpec;
class CHbTargetTag;
class CHbReadSpec;
class CHbWriteSpec;
class CClientRequestSpec;
class CAccessReportSpec;
class CTagReportData;
//class CSelectSpecResult;
//class CAccessSpecResult;
class CSelectSpecID;
class CSpecIndex;
class CRfSpecID;
class CAntennaID;
class CPeakRSSI;
class CFirstSeenTimestampUTC;
class CLastSeenTimestampUTC;
class CTagSeenCount;
class CAccessSpecID;
class CGenaralSelectSpecResult;
class CCustomizedSelectSpecResult;
class CHbCustomizedReadSpecResult;
class CReadDataInfo;
class CHbReadSpecResult;
class CCID;
class CFPDH;
class CSYXZ;
class CCCRQ;
class CCLLX;
class CGL;
class CPL;
class CHPZL;
class CHPHMXH;
class CJYYXQ;
class CQZBFQ;
class CZKZL;
class CCSYS;
class CHbWriteSpecResult;
class CClientRequestSpecResult;
class CEnableCachedEventsAndReport;
class CCachedSelectAccessReport;
class CCachedSelectAccessReportAck;
class CClientRequestAck;


// Net
/*
 * Message classes - forward decls
 */

class CDeviceBinding;
class CDeviceBindingAck;
class CDeviceCertificateConfig;
class CDeviceCertificateConfigAck;
class CDeviceBindingResultNotification;
class CUploadTagLog;
class CUploadTagLogAck;
class CClearTagLog;
class CClearTagLogAck;
class CTagLogCount;
class CTagLogCountAck;
class CUploadTagLogConfirm;
class CUploadDeviceLog;
class CUploadDeviceLogAck;
class CClearDeviceLog;
class CClearDeviceLogAck;
class CDeviceLogCount;
class CDeviceLogCountAck;
class CUploadDeviceLogConfirm;
class CGetDeviceConfig;
class CGetDeviceConfigAck;
class CSetDeviceConfig;
class CSetDeviceConfigAck;
class CGetVersion;
class CGetVersionAck;
class CSetVersion;
class CSetVersionAck;
class CActiveVersion;
class CActiveVersionAck;
class CUnActiveVersion;
class CUnActiveVersionAck;
class CAlarmReport;
class CAlarmRestore;
class CAlarmDelete;
class CAlarmSync;
class CDiagnosticTest;
class CDiagnosticTestAck;
class CResetDevice;
class CResetDeviceAck;

/* Custom messages */


/*
 * Parameter classes - forward decls
 */

class CTagLog;
class CStartLogTimestamp;
class CEndLogTimestamp;
class CDeviceLog;
class CDeviceEventNotificationSpec;
class CEventNotificationState;
class CAntennaProperties;
class CAntennaConfiguration;
class CModuleDepth;
class CIdentification;
class CAlarmConfiguration;
class CAlarmThreshod;
class CCommunicationConfiguration;
class CEthernetConfiguration;
class CCommLinkConfiguration;
class CKeepaliveSpec;
class CTcpLinkConfiguration;
class CClientModeConfiguration;
class CIPAddress;
class CServerModeConfiguration;
class CSerialLinkConfiguration;
class CHttpLinkConfiguration;
class CEthernetIpv4Configuration;
class CEthernetIpv6Configuration;
class CNTPConfiguration;
class CSerialPortConfiguration;
class CSecurityModuleConfiguration;
class CGenaralConfigData;
class CRTCTime;
class CSecurityModuleSN;
class CReadMode;
class CPasswordVersion;
class CVersionInfo;
class CVersionDownload;
class CAlarmReportInfo;
class CAlarmRestoreInfo;
class CAlarmSyncInfo;
class CDiagnosticTestItem;
class CDiagnosticTestData;
class CDiagnosticTestResultItem;
class CDiagnosticTestResultData;
class CDiagnosticTestResultAntennaConnected;
class CDiagnosticTestResultAntennaVSWR;
class CLocationConfiguration;
class CLocationInfo;
class CGpsLocation;
class CBdsLocation;

/* Custom parameters */
// General

/*
 * Message classes - forward decls
 */

class CKeepalive;
class CKeepaliveAck;
class CDeviceEventNotification;

/* Custom messages */


/*
 * Parameter classes - forward decls
 */

class CStatus;
class CUTCTimestamp;
class CGPIEvent;
class CSelectSpecEvent;
class CAntennaSpecEvent;
class CAntennaStatusEvent;
class CConnectionAttemptEvent;

/* Custom parameters */


// Capabilities
/*
 * Message classes - forward decls
 */

class CGetDeviceCapabilities;
class CGetDeviceCapabilitiesAck;

/* Custom messages */


/*
 * Parameter classes - forward decls
 */

class CGenaralCapabilities;
class CGPIOCapabilities;
class CCommunicationCapabilities;
class CSupportRS232;
class CSerialAttribute;
class CSupportRS485;
class CSpecCapabilities;
class CRfCapabilities;
class CTransmitPowerLevelTable;
class CFrequencyInformation;
class CFrequencyTable;
class CForDataRateTable;
class CRevDataRateTable;
class CForModulationTable;
class CRevDataEncodingTable;
class CModuleDepthTable;
class CAirProtocolCapabilities;
class CPerAntennaAirProtocol;
class CHbProtocolCapabilities;
class CSecurityModuleCapabilities;

/* Custom parameters */



}; //end of namespace LLRP

#endif
