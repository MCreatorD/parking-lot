#ifndef __LLRP_NET_H__
#define __LLRP_NET_H__

//#include "LLRP_General.h"
#include "LLRP_Hb_Classes.h"

namespace LLRP
{

/*
 * Generated file - DO NOT EDIT
 *
 * This is the header file for the LLRP Tool Kit (LTK)
 * C++ (aka cpp) implementation. It is generated into a .inc file
 * that is included by a platform specific .h header file.
 * That .h file takes care of prerequisites needed by this file.
 */


/*
 * Message classes - forward decls
 */
/*
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
*/
/* Custom messages */


/*
 * Parameter classes - forward decls
 */
/*
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
class CDiagnosticTestResultItem;
class CDiagnosticTestResultAntennaConnected;
class CDiagnosticTestResultAntennaVSWR;
class CLocationConfiguration;
class CGpsLocation;
class CBdsLocation;
*/
/* Custom parameters */


/*
 * Vendor descriptor declarations.
 */


/*
 * Namespace descriptor declarations.
 */


/*
 * Enumeration definitions and declarations of
 * enumeration string tables.
 */


/**
 ** @brief  Global enumeration EEventNotificationStateEventType  for LLRP enumerated field EventNotificationStateEventType
 **






 **/

enum EEventNotificationStateEventType
{
EventNotificationStateEventType_GPI = 0, /**< GPI */ EventNotificationStateEventType_CHOSESPEC = 1, /**< CHOSESPEC */ EventNotificationStateEventType_ANTENNASPEC = 2, /**< ANTENNASPEC */ EventNotificationStateEventType_ANTENNASTATE = 3, /**< ANTENNASTATE */
};

extern const SEnumTableEntry
g_estEventNotificationStateEventType[];


/**
 ** @brief  Global enumeration EEventNotificationStateNotificationState  for LLRP enumerated field EventNotificationStateNotificationState
 **




 **/

enum EEventNotificationStateNotificationState
{
EventNotificationStateNotificationState_NOT_NOTIFY = 0, /**< NOTIFY */ EventNotificationStateNotificationState_NOTIFY = 1, /**< NOT_NOTIFY */
};

extern const SEnumTableEntry
g_estEventNotificationStateNotificationState[];


/**
 ** @brief  Global enumeration EAntennaPropertiesAntennaConnected  for LLRP enumerated field AntennaPropertiesAntennaConnected
 **




 **/

enum EAntennaPropertiesAntennaConnected
{
AntennaPropertiesAntennaConnected_NOT_CONNECT = 0, /**< NOT_CONNECT */ AntennaPropertiesAntennaConnected_CONNECT = 1, /**< CONNECT */
};

extern const SEnumTableEntry
g_estAntennaPropertiesAntennaConnected[];


/**
 ** @brief  Global enumeration ELinkType  for LLRP enumerated field LinkType
 **






 **/

enum ELinkType
{
LinkType_TCP = 0, /**< TCP */ LinkType_RS232 = 1, /**< RS232 */ LinkType_RS485 = 2, /**< RS485 */ LinkType_HTTP = 3, /**< HTTP */
};

extern const SEnumTableEntry
g_estLinkType[];


/**
 ** @brief  Global enumeration EKeepaliveTriggerType  for LLRP enumerated field KeepaliveTriggerType
 **




 **/

enum EKeepaliveTriggerType
{
KeepaliveTriggerType_NON_HEART_BEAT = 0, /**< NON_HEART_BEAT */ KeepaliveTriggerType_PERIODIC_HEART_BEAT = 1, /**< PERIODIC_HEART_BEAT */
};

extern const SEnumTableEntry
g_estKeepaliveTriggerType[];


/**
 ** @brief  Global enumeration ECommMode  for LLRP enumerated field CommMode
 **





 **/

enum ECommMode
{
CommMode_CLIENT_MODE = 0, /**< CLIENT_MODE */ CommMode_SERVER_MODE = 1, /**< SERVER_MODE */ CommMode_MIXED_MODE = 2, /**< MIXED_MODE */
};

extern const SEnumTableEntry
g_estCommMode[];


/**
 ** @brief  Global enumeration EIPAddressVersion  for LLRP enumerated field IPAddressVersion
 **




 **/

enum EIPAddressVersion
{
IPAddressVersion_IPV4 = 0, /**< IPV4 */ IPAddressVersion_IPV6 = 1, /**< IPV6 */
};

extern const SEnumTableEntry
g_estIPAddressVersion[];


/**
 ** @brief  Global enumeration EVersionInfoUsedOrSpare   for LLRP enumerated field VersionInfoUsedOrSpare
 **




 **/

enum EVersionInfoUsedOrSpare
{
VersionInfoUsedOrSpare_PRIMARY_USE = 0, /**< PRIMARY_USE */ VersionInfoUsedOrSpare_BACK_UP = 1, /**< BACK_UP */
};

extern const SEnumTableEntry
g_estVersionInfoUsedOrSpare[];


/**
 ** @brief  Global enumeration EVersionInfoSetUse   for LLRP enumerated field VersionInfoSetUse
 **




 **/

enum EVersionInfoSetUse
{
VersionInfoSetUse_ACTIVE = 0, /**< ACTIVE */ VersionInfoSetUse_INACTIVE = 1, /**< INACTIVE */
};

extern const SEnumTableEntry
g_estVersionInfoSetUse[];


/**
 ** @brief  Global enumeration EVersionInfoHasRun   for LLRP enumerated field VersionInfoHasRun
 **




 **/

enum EVersionInfoHasRun
{
VersionInfoHasRun_RUN = 0, /**< RUN */ VersionInfoHasRun_NOT_RUN = 1, /**< NOT_RUN */
};

extern const SEnumTableEntry
g_estVersionInfoHasRun[];


/**
 ** @brief  Global enumeration EVersionInfoCanRun   for LLRP enumerated field VersionInfoCanRun
 **




 **/

enum EVersionInfoCanRun
{
VersionInfoCanRun_CAN = 0, /**< CAN */ VersionInfoCanRun_CAN_NOT = 1, /**< CAN_NOT */
};

extern const SEnumTableEntry
g_estVersionInfoCanRun[];


/**
 ** @brief  Global enumeration EVersionDownloadServerType  for LLRP enumerated field VersionDownloadServerType
 **




 **/

enum EVersionDownloadServerType
{
VersionDownloadServerType_FTP = 0, /**< FTP */ VersionDownloadServerType_TFTP = 1, /**< TFTP */
};

extern const SEnumTableEntry
g_estVersionDownloadServerType[];


/**
 ** @brief  Global enumeration EAlarmReportInfoAlarmReportLevel  for LLRP enumerated field AlarmReportInfoAlarmReportLevel
 **







 **/

enum EAlarmReportInfoAlarmReportLevel
{
AlarmReportInfoAlarmReportLevel_FATAL = 0, /**< FATAL */ AlarmReportInfoAlarmReportLevel_SEVER = 1, /**< SEVER */ AlarmReportInfoAlarmReportLevel_GENERAL = 2, /**< GENERAL */ AlarmReportInfoAlarmReportLevel_SLIGHT = 3, /**< SLIGHT */ AlarmReportInfoAlarmReportLevel_NOTICE = 4, /**< NOTICE */
};

extern const SEnumTableEntry
g_estAlarmReportInfoAlarmReportLevel[];


/**
 ** @brief  Global enumeration EDiagnosticTestResultAntennaConnected  for LLRP enumerated field DiagnosticTestResultAntennaConnected
 **




 **/

enum EDiagnosticTestResultAntennaConnected
{
DiagnosticTestResultAntennaConnected_NOT_IN = 0, /**< NOT_IN */ DiagnosticTestResultAntennaConnected_IN = 1, /**< IN */
};

extern const SEnumTableEntry
g_estDiagnosticTestResultAntennaConnected[];


/**
 ** @brief  Global enumeration EUploadTagLogUploadType  for LLRP enumerated field UploadTagLogUploadType
 **




 **/

enum EUploadTagLogUploadType
{
UploadTagLogUploadType_SERIAL_NUMBER = 0, /**< SERIAL_NUMBER */ UploadTagLogUploadType_TIME = 1, /**< TIME */
};

extern const SEnumTableEntry
g_estUploadTagLogUploadType[];


/**
 ** @brief  Global enumeration EUploadDeviceLogType  for LLRP enumerated field UploadDeviceLogType
 **





 **/

enum EUploadDeviceLogType
{
UploadDeviceLogType_SERIAL_NUMBER = 0, /**< SERIAL_NUMBER */ UploadDeviceLogType_SERIAL_TIME = 1, /**< SERIAL_TIME */ UploadDeviceLogType_FIX_TIME = 2, /**< FIX_TIME */
};

extern const SEnumTableEntry
g_estUploadDeviceLogType[];


/**
 ** @brief  Global enumeration EGetDeviceConfigRequestedData  for LLRP enumerated field GetDeviceConfigRequestedData
 **












 **/

enum EGetDeviceConfigRequestedData
{
GetDeviceConfigRequestedData_ALL_CONFIG = 0, /**< ALL_CONFIG */ GetDeviceConfigRequestedData_DEVICE_UNIQUE_ID = 1, /**< DEVICE_UNIQUE_ID */ GetDeviceConfigRequestedData_DEVICE_EVENT_NOTICE_CONFIG = 2, /**< DEVICE_EVENT_NOTICE_CONFIG */ GetDeviceConfigRequestedData_WARN_CONFIG = 3, /**< WARN_CONFIG */ GetDeviceConfigRequestedData_ANTENNA_ATTRIBUTE_CONFIG = 4, /**< ANTENNA_ATTRIBUTE_CONFIG */ GetDeviceConfigRequestedData_ANTENNA_PROTOCOL_CONFIG = 5, /**< ANTENNA_PROTOCOL_CONFIG */ GetDeviceConfigRequestedData_MODULATION_DEPTH_CONFIG = 6, /**< MODULATION_DEPTH_CONFIG */ GetDeviceConfigRequestedData_TAG_CHOOSE_REPORT_SPEC_CONFIG = 7, /**< TAG_CHOOSE_REPORT_SPEC_CONFIG */ GetDeviceConfigRequestedData_TAG_OPERATE_REPORT_SPEC_CONFIG = 8, /**< TAG_OPERATE_REPORT_SPEC_CONFIG */ GetDeviceConfigRequestedData_COMMUNICATE_CONFIG = 9, /**< COMMUNICATE_CONFIG */
};

extern const SEnumTableEntry
g_estGetDeviceConfigRequestedData[];


/**
 ** @brief  Global enumeration ESetDeviceConfigResetToFactoryDefault  for LLRP enumerated field SetDeviceConfigResetToFactoryDefault
 **




 **/

enum ESetDeviceConfigResetToFactoryDefault
{
SetDeviceConfigResetToFactoryDefault_NO_RESTORE = 0, /**< NO_RESTORE */ SetDeviceConfigResetToFactoryDefault_RESTORE = 1, /**< RESTORE */
};

extern const SEnumTableEntry
g_estSetDeviceConfigResetToFactoryDefault[];


/**
 ** @brief  Global enumeration EGetVersionVerType  for LLRP enumerated field GetVersionVerType
 **






 **/

enum EGetVersionVerType
{
GetVersionVerType_READER_BOOT_VER = 0, /**< READER_BOOT_VER */ GetVersionVerType_READER_SYSTEM_VER = 1, /**< READER_SYSTEM_VER */ GetVersionVerType_SECURITY_MODULE_SYSTEM_VER = 2, /**< SECURITY_MODULE_SYSTEM_VER */ GetVersionVerType_SECURITY_CHIP_SYSTEM_VER = 3, /**< SECURITY_CHIP_SYSTEM_VER */
};

extern const SEnumTableEntry
g_estGetVersionVerType[];


/**
 ** @brief  Global enumeration ESetVersionVerType  for LLRP enumerated field SetVersionVerType
 **






 **/

enum ESetVersionVerType
{
SetVersionVerType_READER_BOOT_VER = 0, /**< READER_BOOT_VER */ SetVersionVerType_READER_SYSTEM_VER = 1, /**< READER_SYSTEM_VER */ SetVersionVerType_SECURITY_MODULE_SYSTEM_VER = 2, /**< SECURITY_MODULE_SYSTEM_VER */ SetVersionVerType_SECURITY_CHIP_SYSTEM_VER = 3, /**< SECURITY_CHIP_SYSTEM_VER */
};

extern const SEnumTableEntry
g_estSetVersionVerType[];


/**
 ** @brief  Global enumeration EActiveVersionVerType  for LLRP enumerated field ActiveVersionVerType
 **






 **/

enum EActiveVersionVerType
{
ActiveVersionVerType_READER_BOOT_VER = 0, /**< READER_BOOT_VER */ ActiveVersionVerType_READER_SYSTEM_VER = 1, /**< READER_SYSTEM_VER */ ActiveVersionVerType_SECURITY_MODULE_SYSTEM_VER = 2, /**< SECURITY_MODULE_SYSTEM_VER */ ActiveVersionVerType_SECURITY_CHIP_SYSTEM_VER = 3, /**< SECURITY_CHIP_SYSTEM_VER */
};

extern const SEnumTableEntry
g_estActiveVersionVerType[];


/**
 ** @brief  Global enumeration EUnActiveVersionVerType  for LLRP enumerated field UnActiveVersionVerType
 **






 **/

enum EUnActiveVersionVerType
{
UnActiveVersionVerType_READER_BOOT_VER = 0, /**< READER_BOOT_VER */ UnActiveVersionVerType_READER_SYSTEM_VER = 1, /**< READER_SYSTEM_VER */ UnActiveVersionVerType_SECURITY_MODULE_SYSTEM_VER = 2, /**< SECURITY_MODULE_SYSTEM_VER */ UnActiveVersionVerType_SECURITY_CHIP_SYSTEM_VER = 3, /**< SECURITY_CHIP_SYSTEM_VER */
};

extern const SEnumTableEntry
g_estUnActiveVersionVerType[];


/**
 ** @brief  Global enumeration ELocationType  for LLRP enumerated field LocationType
 **




 **/

enum ELocationType
{
LocationType_GPS = 0, /**< GPS */ LocationType_BDS = 1, /**< BDS */
};

extern const SEnumTableEntry
g_estLocationType[];


/**
 * \defgroup CoreMessage  Core Message Classes
 * Classes to manipulate the messages defined by the Core LLRP protocol
 */
/*@{*/

/**
 ** @brief  Class Definition CDeviceBinding for LLRP message DeviceBinding
 **




 **/

class CDeviceBinding : public CMessage
{
  public:
    CDeviceBinding (void);
    ~CDeviceBinding (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    llrp_u8_t m_BindingType;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdBindingType;
//@}

    /** @brief Get accessor functions for the LLRP BindingType field */
    inline llrp_u8_t
    getBindingType (void)
    {
        return m_BindingType;
    }

    /** @brief Set accessor functions for the LLRP BindingType field */
    inline void
    setBindingType (
      llrp_u8_t  value)
    {
        m_BindingType = value;
    }


  protected:
    llrp_u8v_t  m_BindingData;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdBindingData;
//@}

    /** @brief Get accessor functions for the LLRP BindingData field */
    inline llrp_u8v_t
    getBindingData (void)
    {
        return m_BindingData;
    }

    /** @brief Set accessor functions for the LLRP BindingData field */
    inline void
    setBindingData (
      llrp_u8v_t   value)
    {
        m_BindingData = value;
    }


};


/**
 ** @brief  Class Definition CDeviceBindingAck for LLRP message DeviceBindingAck
 **




 **/

class CDeviceBindingAck : public CMessage
{
  public:
    CDeviceBindingAck (void);
    ~CDeviceBindingAck (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    llrp_u8v_t  m_BindingData;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdBindingData;
//@}

    /** @brief Get accessor functions for the LLRP BindingData field */
    inline llrp_u8v_t
    getBindingData (void)
    {
        return m_BindingData;
    }

    /** @brief Set accessor functions for the LLRP BindingData field */
    inline void
    setBindingData (
      llrp_u8v_t   value)
    {
        m_BindingData = value;
    }


  protected:
    CStatus * m_pStatus;

  public:
    /** @brief Get accessor functions for the LLRP Status sub-parameter */
    inline CStatus *
    getStatus (void)
    {
        return m_pStatus;
    }

    /** @brief Set accessor functions for the LLRP Status sub-parameter */
    EResultCode
    setStatus (
      CStatus * pValue);


};


/**
 ** @brief  Class Definition CDeviceCertificateConfig for LLRP message DeviceCertificateConfig
 **




 **/

class CDeviceCertificateConfig : public CMessage
{
  public:
    CDeviceCertificateConfig (void);
    ~CDeviceCertificateConfig (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    llrp_u8v_t  m_CertificateData;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdCertificateData;
//@}

    /** @brief Get accessor functions for the LLRP CertificateData field */
    inline llrp_u8v_t
    getCertificateData (void)
    {
        return m_CertificateData;
    }

    /** @brief Set accessor functions for the LLRP CertificateData field */
    inline void
    setCertificateData (
      llrp_u8v_t   value)
    {
        m_CertificateData = value;
    }


  protected:
    llrp_u8v_t  m_UserData;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdUserData;
//@}

    /** @brief Get accessor functions for the LLRP UserData field */
    inline llrp_u8v_t
    getUserData (void)
    {
        return m_UserData;
    }

    /** @brief Set accessor functions for the LLRP UserData field */
    inline void
    setUserData (
      llrp_u8v_t   value)
    {
        m_UserData = value;
    }


};


/**
 ** @brief  Class Definition CDeviceCertificateConfigAck for LLRP message DeviceCertificateConfigAck
 **



 **/

class CDeviceCertificateConfigAck : public CMessage
{
  public:
    CDeviceCertificateConfigAck (void);
    ~CDeviceCertificateConfigAck (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    CStatus * m_pStatus;

  public:
    /** @brief Get accessor functions for the LLRP Status sub-parameter */
    inline CStatus *
    getStatus (void)
    {
        return m_pStatus;
    }

    /** @brief Set accessor functions for the LLRP Status sub-parameter */
    EResultCode
    setStatus (
      CStatus * pValue);


};


/**
 ** @brief  Class Definition CDeviceBindingResultNotification for LLRP message DeviceBindingResultNotification
 **



 **/

class CDeviceBindingResultNotification : public CMessage
{
  public:
    CDeviceBindingResultNotification (void);
    ~CDeviceBindingResultNotification (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    CStatus * m_pStatus;

  public:
    /** @brief Get accessor functions for the LLRP Status sub-parameter */
    inline CStatus *
    getStatus (void)
    {
        return m_pStatus;
    }

    /** @brief Set accessor functions for the LLRP Status sub-parameter */
    EResultCode
    setStatus (
      CStatus * pValue);


};


/**
 ** @brief  Class Definition CUploadTagLog for LLRP message UploadTagLog
 **







 **/

class CUploadTagLog : public CMessage
{
  public:
    CUploadTagLog (void);
    ~CUploadTagLog (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    EUploadTagLogUploadType m_EUploadType;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdUploadType;
//@}

    /** @brief Get accessor functions for the LLRP UploadType field */
    inline EUploadTagLogUploadType
    getUploadType (void)
    {
        return m_EUploadType;
    }

    /** @brief Set accessor functions for the LLRP UploadType field */
    inline void
    setUploadType (
      EUploadTagLogUploadType  value)
    {
        m_EUploadType = value;
    }


  protected:
    llrp_u32_t m_UploadCount;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdUploadCount;
//@}

    /** @brief Get accessor functions for the LLRP UploadCount field */
    inline llrp_u32_t
    getUploadCount (void)
    {
        return m_UploadCount;
    }

    /** @brief Set accessor functions for the LLRP UploadCount field */
    inline void
    setUploadCount (
      llrp_u32_t  value)
    {
        m_UploadCount = value;
    }


  protected:
    llrp_u32_t m_Milliseconds;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdMilliseconds;
//@}

    /** @brief Get accessor functions for the LLRP Milliseconds field */
    inline llrp_u32_t
    getMilliseconds (void)
    {
        return m_Milliseconds;
    }

    /** @brief Set accessor functions for the LLRP Milliseconds field */
    inline void
    setMilliseconds (
      llrp_u32_t  value)
    {
        m_Milliseconds = value;
    }


  protected:
    CStartLogTimestamp * m_pStartLogTimestamp;

  public:
    /** @brief Get accessor functions for the LLRP StartLogTimestamp sub-parameter */
    inline CStartLogTimestamp *
    getStartLogTimestamp (void)
    {
        return m_pStartLogTimestamp;
    }

    /** @brief Set accessor functions for the LLRP StartLogTimestamp sub-parameter */
    EResultCode
    setStartLogTimestamp (
      CStartLogTimestamp * pValue);


  protected:
    CEndLogTimestamp * m_pEndLogTimestamp;

  public:
    /** @brief Get accessor functions for the LLRP EndLogTimestamp sub-parameter */
    inline CEndLogTimestamp *
    getEndLogTimestamp (void)
    {
        return m_pEndLogTimestamp;
    }

    /** @brief Set accessor functions for the LLRP EndLogTimestamp sub-parameter */
    EResultCode
    setEndLogTimestamp (
      CEndLogTimestamp * pValue);


};


/**
 ** @brief  Class Definition CUploadTagLogAck for LLRP message UploadTagLogAck
 **






 **/

class CUploadTagLogAck : public CMessage
{
  public:
    CUploadTagLogAck (void);
    ~CUploadTagLogAck (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    llrp_u16_t m_SequenceId;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdSequenceId;
//@}

    /** @brief Get accessor functions for the LLRP SequenceId field */
    inline llrp_u16_t
    getSequenceId (void)
    {
        return m_SequenceId;
    }

    /** @brief Set accessor functions for the LLRP SequenceId field */
    inline void
    setSequenceId (
      llrp_u16_t  value)
    {
        m_SequenceId = value;
    }


  protected:
    llrp_u8_t m_IsLastedFrame;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdIsLastedFrame;
//@}

    /** @brief Get accessor functions for the LLRP IsLastedFrame field */
    inline llrp_u8_t
    getIsLastedFrame (void)
    {
        return m_IsLastedFrame;
    }

    /** @brief Set accessor functions for the LLRP IsLastedFrame field */
    inline void
    setIsLastedFrame (
      llrp_u8_t  value)
    {
        m_IsLastedFrame = value;
    }


  protected:
    CStatus * m_pStatus;

  public:
    /** @brief Get accessor functions for the LLRP Status sub-parameter */
    inline CStatus *
    getStatus (void)
    {
        return m_pStatus;
    }

    /** @brief Set accessor functions for the LLRP Status sub-parameter */
    EResultCode
    setStatus (
      CStatus * pValue);


  protected:
    std::list<CTagLog *> m_listTagLog;

  public:
     /** @brief  Returns the first element of the TagLog sub-parameter list*/
    inline std::list<CTagLog *>::iterator
    beginTagLog (void)
    {
        return m_listTagLog.begin();
    }

     /** @brief  Returns the last element of the TagLog sub-parameter list*/
    inline std::list<CTagLog *>::iterator
    endTagLog (void)
    {
        return m_listTagLog.end();
    }

     /** @brief  Clears the LLRP TagLog sub-parameter list*/
    inline void
    clearTagLog (void)
    {
        clearSubParameterList ((tListOfParameters *) &m_listTagLog);
    }

    EResultCode
     /** @brief  Add a TagLog to the LLRP sub-parameter list*/
    addTagLog (
      CTagLog * pValue);


};


/**
 ** @brief  Class Definition CClearTagLog for LLRP message ClearTagLog
 **


 **/

class CClearTagLog : public CMessage
{
  public:
    CClearTagLog (void);
    ~CClearTagLog (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


};


/**
 ** @brief  Class Definition CClearTagLogAck for LLRP message ClearTagLogAck
 **



 **/

class CClearTagLogAck : public CMessage
{
  public:
    CClearTagLogAck (void);
    ~CClearTagLogAck (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    CStatus * m_pStatus;

  public:
    /** @brief Get accessor functions for the LLRP Status sub-parameter */
    inline CStatus *
    getStatus (void)
    {
        return m_pStatus;
    }

    /** @brief Set accessor functions for the LLRP Status sub-parameter */
    EResultCode
    setStatus (
      CStatus * pValue);


};


/**
 ** @brief  Class Definition CTagLogCount for LLRP message TagLogCount
 **


 **/

class CTagLogCount : public CMessage
{
  public:
    CTagLogCount (void);
    ~CTagLogCount (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


};


/**
 ** @brief  Class Definition CTagLogCountAck for LLRP message TagLogCountAck
 **




 **/

class CTagLogCountAck : public CMessage
{
  public:
    CTagLogCountAck (void);
    ~CTagLogCountAck (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    llrp_u32_t m_LogCount;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdLogCount;
//@}

    /** @brief Get accessor functions for the LLRP LogCount field */
    inline llrp_u32_t
    getLogCount (void)
    {
        return m_LogCount;
    }

    /** @brief Set accessor functions for the LLRP LogCount field */
    inline void
    setLogCount (
      llrp_u32_t  value)
    {
        m_LogCount = value;
    }


  protected:
    CStatus * m_pStatus;

  public:
    /** @brief Get accessor functions for the LLRP Status sub-parameter */
    inline CStatus *
    getStatus (void)
    {
        return m_pStatus;
    }

    /** @brief Set accessor functions for the LLRP Status sub-parameter */
    EResultCode
    setStatus (
      CStatus * pValue);


};


/**
 ** @brief  Class Definition CUploadTagLogConfirm for LLRP message UploadTagLogConfirm
 **



 **/

class CUploadTagLogConfirm : public CMessage
{
  public:
    CUploadTagLogConfirm (void);
    ~CUploadTagLogConfirm (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    llrp_u16_t m_SequenceId;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdSequenceId;
//@}

    /** @brief Get accessor functions for the LLRP SequenceId field */
    inline llrp_u16_t
    getSequenceId (void)
    {
        return m_SequenceId;
    }

    /** @brief Set accessor functions for the LLRP SequenceId field */
    inline void
    setSequenceId (
      llrp_u16_t  value)
    {
        m_SequenceId = value;
    }


};


/**
 ** @brief  Class Definition CUploadDeviceLog for LLRP message UploadDeviceLog
 **







 **/

class CUploadDeviceLog : public CMessage
{
  public:
    CUploadDeviceLog (void);
    ~CUploadDeviceLog (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    EUploadDeviceLogType m_EUploadType;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdUploadType;
//@}

    /** @brief Get accessor functions for the LLRP UploadType field */
    inline EUploadDeviceLogType
    getUploadType (void)
    {
        return m_EUploadType;
    }

    /** @brief Set accessor functions for the LLRP UploadType field */
    inline void
    setUploadType (
      EUploadDeviceLogType  value)
    {
        m_EUploadType = value;
    }


  protected:
    llrp_u32_t m_UploadCount;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdUploadCount;
//@}

    /** @brief Get accessor functions for the LLRP UploadCount field */
    inline llrp_u32_t
    getUploadCount (void)
    {
        return m_UploadCount;
    }

    /** @brief Set accessor functions for the LLRP UploadCount field */
    inline void
    setUploadCount (
      llrp_u32_t  value)
    {
        m_UploadCount = value;
    }


  protected:
    llrp_u32_t m_Milliseconds;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdMilliseconds;
//@}

    /** @brief Get accessor functions for the LLRP Milliseconds field */
    inline llrp_u32_t
    getMilliseconds (void)
    {
        return m_Milliseconds;
    }

    /** @brief Set accessor functions for the LLRP Milliseconds field */
    inline void
    setMilliseconds (
      llrp_u32_t  value)
    {
        m_Milliseconds = value;
    }


  protected:
    CStartLogTimestamp * m_pStartLogTimestamp;

  public:
    /** @brief Get accessor functions for the LLRP StartLogTimestamp sub-parameter */
    inline CStartLogTimestamp *
    getStartLogTimestamp (void)
    {
        return m_pStartLogTimestamp;
    }

    /** @brief Set accessor functions for the LLRP StartLogTimestamp sub-parameter */
    EResultCode
    setStartLogTimestamp (
      CStartLogTimestamp * pValue);


  protected:
    CEndLogTimestamp * m_pEndLogTimestamp;

  public:
    /** @brief Get accessor functions for the LLRP EndLogTimestamp sub-parameter */
    inline CEndLogTimestamp *
    getEndLogTimestamp (void)
    {
        return m_pEndLogTimestamp;
    }

    /** @brief Set accessor functions for the LLRP EndLogTimestamp sub-parameter */
    EResultCode
    setEndLogTimestamp (
      CEndLogTimestamp * pValue);


};


/**
 ** @brief  Class Definition CUploadDeviceLogAck for LLRP message UploadDeviceLogAck
 **






 **/

class CUploadDeviceLogAck : public CMessage
{
  public:
    CUploadDeviceLogAck (void);
    ~CUploadDeviceLogAck (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    llrp_u16_t m_SequenceId;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdSequenceId;
//@}

    /** @brief Get accessor functions for the LLRP SequenceId field */
    inline llrp_u16_t
    getSequenceId (void)
    {
        return m_SequenceId;
    }

    /** @brief Set accessor functions for the LLRP SequenceId field */
    inline void
    setSequenceId (
      llrp_u16_t  value)
    {
        m_SequenceId = value;
    }


  protected:
    llrp_u8_t m_IsLastedFrame;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdIsLastedFrame;
//@}

    /** @brief Get accessor functions for the LLRP IsLastedFrame field */
    inline llrp_u8_t
    getIsLastedFrame (void)
    {
        return m_IsLastedFrame;
    }

    /** @brief Set accessor functions for the LLRP IsLastedFrame field */
    inline void
    setIsLastedFrame (
      llrp_u8_t  value)
    {
        m_IsLastedFrame = value;
    }


  protected:
    CStatus * m_pStatus;

  public:
    /** @brief Get accessor functions for the LLRP Status sub-parameter */
    inline CStatus *
    getStatus (void)
    {
        return m_pStatus;
    }

    /** @brief Set accessor functions for the LLRP Status sub-parameter */
    EResultCode
    setStatus (
      CStatus * pValue);


  protected:
    std::list<CDeviceLog *> m_listDeviceLog;

  public:
     /** @brief  Returns the first element of the DeviceLog sub-parameter list*/
    inline std::list<CDeviceLog *>::iterator
    beginDeviceLog (void)
    {
        return m_listDeviceLog.begin();
    }

     /** @brief  Returns the last element of the DeviceLog sub-parameter list*/
    inline std::list<CDeviceLog *>::iterator
    endDeviceLog (void)
    {
        return m_listDeviceLog.end();
    }

     /** @brief  Clears the LLRP DeviceLog sub-parameter list*/
    inline void
    clearDeviceLog (void)
    {
        clearSubParameterList ((tListOfParameters *) &m_listDeviceLog);
    }

    EResultCode
     /** @brief  Add a DeviceLog to the LLRP sub-parameter list*/
    addDeviceLog (
      CDeviceLog * pValue);


};


/**
 ** @brief  Class Definition CClearDeviceLog for LLRP message ClearDeviceLog
 **


 **/

class CClearDeviceLog : public CMessage
{
  public:
    CClearDeviceLog (void);
    ~CClearDeviceLog (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


};


/**
 ** @brief  Class Definition CClearDeviceLogAck for LLRP message ClearDeviceLogAck
 **



 **/

class CClearDeviceLogAck : public CMessage
{
  public:
    CClearDeviceLogAck (void);
    ~CClearDeviceLogAck (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    CStatus * m_pStatus;

  public:
    /** @brief Get accessor functions for the LLRP Status sub-parameter */
    inline CStatus *
    getStatus (void)
    {
        return m_pStatus;
    }

    /** @brief Set accessor functions for the LLRP Status sub-parameter */
    EResultCode
    setStatus (
      CStatus * pValue);


};


/**
 ** @brief  Class Definition CDeviceLogCount for LLRP message DeviceLogCount
 **


 **/

class CDeviceLogCount : public CMessage
{
  public:
    CDeviceLogCount (void);
    ~CDeviceLogCount (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


};


/**
 ** @brief  Class Definition CDeviceLogCountAck for LLRP message DeviceLogCountAck
 **




 **/

class CDeviceLogCountAck : public CMessage
{
  public:
    CDeviceLogCountAck (void);
    ~CDeviceLogCountAck (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    llrp_u32_t m_LogCount;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdLogCount;
//@}

    /** @brief Get accessor functions for the LLRP LogCount field */
    inline llrp_u32_t
    getLogCount (void)
    {
        return m_LogCount;
    }

    /** @brief Set accessor functions for the LLRP LogCount field */
    inline void
    setLogCount (
      llrp_u32_t  value)
    {
        m_LogCount = value;
    }


  protected:
    CStatus * m_pStatus;

  public:
    /** @brief Get accessor functions for the LLRP Status sub-parameter */
    inline CStatus *
    getStatus (void)
    {
        return m_pStatus;
    }

    /** @brief Set accessor functions for the LLRP Status sub-parameter */
    EResultCode
    setStatus (
      CStatus * pValue);


};


/**
 ** @brief  Class Definition CUploadDeviceLogConfirm for LLRP message UploadDeviceLogConfirm
 **



 **/

class CUploadDeviceLogConfirm : public CMessage
{
  public:
    CUploadDeviceLogConfirm (void);
    ~CUploadDeviceLogConfirm (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    llrp_u16_t m_SequenceId;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdSequenceId;
//@}

    /** @brief Get accessor functions for the LLRP SequenceId field */
    inline llrp_u16_t
    getSequenceId (void)
    {
        return m_SequenceId;
    }

    /** @brief Set accessor functions for the LLRP SequenceId field */
    inline void
    setSequenceId (
      llrp_u16_t  value)
    {
        m_SequenceId = value;
    }


};


/**
 ** @brief  Class Definition CGetDeviceConfig for LLRP message GetDeviceConfig
 **




 **/

class CGetDeviceConfig : public CMessage
{
  public:
    CGetDeviceConfig (void);
    ~CGetDeviceConfig (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    EGetDeviceConfigRequestedData m_ERequestedData;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdRequestedData;
//@}

    /** @brief Get accessor functions for the LLRP RequestedData field */
    inline EGetDeviceConfigRequestedData
    getRequestedData (void)
    {
        return m_ERequestedData;
    }

    /** @brief Set accessor functions for the LLRP RequestedData field */
    inline void
    setRequestedData (
      EGetDeviceConfigRequestedData  value)
    {
        m_ERequestedData = value;
    }


  protected:
    llrp_u8_t m_AntennaID;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdAntennaID;
//@}

    /** @brief Get accessor functions for the LLRP AntennaID field */
    inline llrp_u8_t
    getAntennaID (void)
    {
        return m_AntennaID;
    }

    /** @brief Set accessor functions for the LLRP AntennaID field */
    inline void
    setAntennaID (
      llrp_u8_t  value)
    {
        m_AntennaID = value;
    }


};


/**
 ** @brief  Class Definition CGetDeviceConfigAck for LLRP message GetDeviceConfigAck
 **














 **/

class CGetDeviceConfigAck : public CMessage
{
  public:
    CGetDeviceConfigAck (void);
    ~CGetDeviceConfigAck (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    CStatus * m_pStatus;

  public:
    /** @brief Get accessor functions for the LLRP Status sub-parameter */
    inline CStatus *
    getStatus (void)
    {
        return m_pStatus;
    }

    /** @brief Set accessor functions for the LLRP Status sub-parameter */
    EResultCode
    setStatus (
      CStatus * pValue);


  protected:
    CIdentification * m_pIdentification;

  public:
    /** @brief Get accessor functions for the LLRP Identification sub-parameter */
    inline CIdentification *
    getIdentification (void)
    {
        return m_pIdentification;
    }

    /** @brief Set accessor functions for the LLRP Identification sub-parameter */
    EResultCode
    setIdentification (
      CIdentification * pValue);


  protected:
    CDeviceEventNotificationSpec * m_pDeviceEventNotificationSpec;

  public:
    /** @brief Get accessor functions for the LLRP DeviceEventNotificationSpec sub-parameter */
    inline CDeviceEventNotificationSpec *
    getDeviceEventNotificationSpec (void)
    {
        return m_pDeviceEventNotificationSpec;
    }

    /** @brief Set accessor functions for the LLRP DeviceEventNotificationSpec sub-parameter */
    EResultCode
    setDeviceEventNotificationSpec (
      CDeviceEventNotificationSpec * pValue);


  protected:
    CAlarmConfiguration * m_pAlarmConfiguration;

  public:
    /** @brief Get accessor functions for the LLRP AlarmConfiguration sub-parameter */
    inline CAlarmConfiguration *
    getAlarmConfiguration (void)
    {
        return m_pAlarmConfiguration;
    }

    /** @brief Set accessor functions for the LLRP AlarmConfiguration sub-parameter */
    EResultCode
    setAlarmConfiguration (
      CAlarmConfiguration * pValue);


  protected:
    std::list<CAntennaProperties *> m_listAntennaProperties;

  public:
     /** @brief  Returns the first element of the AntennaProperties sub-parameter list*/
    inline std::list<CAntennaProperties *>::iterator
    beginAntennaProperties (void)
    {
        return m_listAntennaProperties.begin();
    }

     /** @brief  Returns the last element of the AntennaProperties sub-parameter list*/
    inline std::list<CAntennaProperties *>::iterator
    endAntennaProperties (void)
    {
        return m_listAntennaProperties.end();
    }

     /** @brief  Clears the LLRP AntennaProperties sub-parameter list*/
    inline void
    clearAntennaProperties (void)
    {
        clearSubParameterList ((tListOfParameters *) &m_listAntennaProperties);
    }

    EResultCode
     /** @brief  Add a AntennaProperties to the LLRP sub-parameter list*/
    addAntennaProperties (
      CAntennaProperties * pValue);


  protected:
    std::list<CAntennaConfiguration *> m_listAntennaConfiguration;

  public:
     /** @brief  Returns the first element of the AntennaConfiguration sub-parameter list*/
    inline std::list<CAntennaConfiguration *>::iterator
    beginAntennaConfiguration (void)
    {
        return m_listAntennaConfiguration.begin();
    }

     /** @brief  Returns the last element of the AntennaConfiguration sub-parameter list*/
    inline std::list<CAntennaConfiguration *>::iterator
    endAntennaConfiguration (void)
    {
        return m_listAntennaConfiguration.end();
    }

     /** @brief  Clears the LLRP AntennaConfiguration sub-parameter list*/
    inline void
    clearAntennaConfiguration (void)
    {
        clearSubParameterList ((tListOfParameters *) &m_listAntennaConfiguration);
    }

    EResultCode
     /** @brief  Add a AntennaConfiguration to the LLRP sub-parameter list*/
    addAntennaConfiguration (
      CAntennaConfiguration * pValue);


  protected:
    CModuleDepth * m_pModuleDepth;

  public:
    /** @brief Get accessor functions for the LLRP ModuleDepth sub-parameter */
    inline CModuleDepth *
    getModuleDepth (void)
    {
        return m_pModuleDepth;
    }

    /** @brief Set accessor functions for the LLRP ModuleDepth sub-parameter */
    EResultCode
    setModuleDepth (
      CModuleDepth * pValue);


  protected:
    CSelectReportSpec * m_pSelectReportSpec;

  public:
    /** @brief Get accessor functions for the LLRP SelectReportSpec sub-parameter */
    inline CSelectReportSpec *
    getSelectReportSpec (void)
    {
        return m_pSelectReportSpec;
    }

    /** @brief Set accessor functions for the LLRP SelectReportSpec sub-parameter */
    EResultCode
    setSelectReportSpec (
      CSelectReportSpec * pValue);


  protected:
    CAccessReportSpec * m_pAccessReportSpec;

  public:
    /** @brief Get accessor functions for the LLRP AccessReportSpec sub-parameter */
    inline CAccessReportSpec *
    getAccessReportSpec (void)
    {
        return m_pAccessReportSpec;
    }

    /** @brief Set accessor functions for the LLRP AccessReportSpec sub-parameter */
    EResultCode
    setAccessReportSpec (
      CAccessReportSpec * pValue);


  protected:
    CCommunicationConfiguration * m_pCommunicationConfiguration;

  public:
    /** @brief Get accessor functions for the LLRP CommunicationConfiguration sub-parameter */
    inline CCommunicationConfiguration *
    getCommunicationConfiguration (void)
    {
        return m_pCommunicationConfiguration;
    }

    /** @brief Set accessor functions for the LLRP CommunicationConfiguration sub-parameter */
    EResultCode
    setCommunicationConfiguration (
      CCommunicationConfiguration * pValue);


  protected:
    CLocationConfiguration * m_pLocationConfiguration;

  public:
    /** @brief Get accessor functions for the LLRP LocationConfiguration sub-parameter */
    inline CLocationConfiguration *
    getLocationConfiguration (void)
    {
        return m_pLocationConfiguration;
    }

    /** @brief Set accessor functions for the LLRP LocationConfiguration sub-parameter */
    EResultCode
    setLocationConfiguration (
      CLocationConfiguration * pValue);


  protected:
    CSecurityModuleConfiguration * m_pSecurityModuleConfiguration;

  public:
    /** @brief Get accessor functions for the LLRP SecurityModuleConfiguration sub-parameter */
    inline CSecurityModuleConfiguration *
    getSecurityModuleConfiguration (void)
    {
        return m_pSecurityModuleConfiguration;
    }

    /** @brief Set accessor functions for the LLRP SecurityModuleConfiguration sub-parameter */
    EResultCode
    setSecurityModuleConfiguration (
      CSecurityModuleConfiguration * pValue);


};


/**
 ** @brief  Class Definition CSetDeviceConfig for LLRP message SetDeviceConfig
 **














 **/

class CSetDeviceConfig : public CMessage
{
  public:
    CSetDeviceConfig (void);
    ~CSetDeviceConfig (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    ESetDeviceConfigResetToFactoryDefault m_EResetToFactoryDefault;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdResetToFactoryDefault;
//@}

    /** @brief Get accessor functions for the LLRP ResetToFactoryDefault field */
    inline ESetDeviceConfigResetToFactoryDefault
    getResetToFactoryDefault (void)
    {
        return m_EResetToFactoryDefault;
    }

    /** @brief Set accessor functions for the LLRP ResetToFactoryDefault field */
    inline void
    setResetToFactoryDefault (
      ESetDeviceConfigResetToFactoryDefault  value)
    {
        m_EResetToFactoryDefault = value;
    }


  protected:
    CIdentification * m_pIdentification;

  public:
    /** @brief Get accessor functions for the LLRP Identification sub-parameter */
    inline CIdentification *
    getIdentification (void)
    {
        return m_pIdentification;
    }

    /** @brief Set accessor functions for the LLRP Identification sub-parameter */
    EResultCode
    setIdentification (
      CIdentification * pValue);


  protected:
    CDeviceEventNotificationSpec * m_pDeviceEventNotificationSpec;

  public:
    /** @brief Get accessor functions for the LLRP DeviceEventNotificationSpec sub-parameter */
    inline CDeviceEventNotificationSpec *
    getDeviceEventNotificationSpec (void)
    {
        return m_pDeviceEventNotificationSpec;
    }

    /** @brief Set accessor functions for the LLRP DeviceEventNotificationSpec sub-parameter */
    EResultCode
    setDeviceEventNotificationSpec (
      CDeviceEventNotificationSpec * pValue);


  protected:
    CAlarmConfiguration * m_pAlarmConfiguration;

  public:
    /** @brief Get accessor functions for the LLRP AlarmConfiguration sub-parameter */
    inline CAlarmConfiguration *
    getAlarmConfiguration (void)
    {
        return m_pAlarmConfiguration;
    }

    /** @brief Set accessor functions for the LLRP AlarmConfiguration sub-parameter */
    EResultCode
    setAlarmConfiguration (
      CAlarmConfiguration * pValue);


  protected:
    std::list<CAntennaConfiguration *> m_listAntennaConfiguration;

  public:
     /** @brief  Returns the first element of the AntennaConfiguration sub-parameter list*/
    inline std::list<CAntennaConfiguration *>::iterator
    beginAntennaConfiguration (void)
    {
        return m_listAntennaConfiguration.begin();
    }

     /** @brief  Returns the last element of the AntennaConfiguration sub-parameter list*/
    inline std::list<CAntennaConfiguration *>::iterator
    endAntennaConfiguration (void)
    {
        return m_listAntennaConfiguration.end();
    }

     /** @brief  Clears the LLRP AntennaConfiguration sub-parameter list*/
    inline void
    clearAntennaConfiguration (void)
    {
        clearSubParameterList ((tListOfParameters *) &m_listAntennaConfiguration);
    }

    EResultCode
     /** @brief  Add a AntennaConfiguration to the LLRP sub-parameter list*/
    addAntennaConfiguration (
      CAntennaConfiguration * pValue);


  protected:
    CModuleDepth * m_pModuleDepth;

  public:
    /** @brief Get accessor functions for the LLRP ModuleDepth sub-parameter */
    inline CModuleDepth *
    getModuleDepth (void)
    {
        return m_pModuleDepth;
    }

    /** @brief Set accessor functions for the LLRP ModuleDepth sub-parameter */
    EResultCode
    setModuleDepth (
      CModuleDepth * pValue);


  protected:
    CSelectReportSpec * m_pSelectReportSpec;

  public:
    /** @brief Get accessor functions for the LLRP SelectReportSpec sub-parameter */
    inline CSelectReportSpec *
    getSelectReportSpec (void)
    {
        return m_pSelectReportSpec;
    }

    /** @brief Set accessor functions for the LLRP SelectReportSpec sub-parameter */
    EResultCode
    setSelectReportSpec (
      CSelectReportSpec * pValue);


  protected:
    CAccessReportSpec * m_pAccessReportSpec;

  public:
    /** @brief Get accessor functions for the LLRP AccessReportSpec sub-parameter */
    inline CAccessReportSpec *
    getAccessReportSpec (void)
    {
        return m_pAccessReportSpec;
    }

    /** @brief Set accessor functions for the LLRP AccessReportSpec sub-parameter */
    EResultCode
    setAccessReportSpec (
      CAccessReportSpec * pValue);


  protected:
    CCommunicationConfiguration * m_pCommunicationConfiguration;

  public:
    /** @brief Get accessor functions for the LLRP CommunicationConfiguration sub-parameter */
    inline CCommunicationConfiguration *
    getCommunicationConfiguration (void)
    {
        return m_pCommunicationConfiguration;
    }

    /** @brief Set accessor functions for the LLRP CommunicationConfiguration sub-parameter */
    EResultCode
    setCommunicationConfiguration (
      CCommunicationConfiguration * pValue);


  protected:
    CLocationConfiguration * m_pLocationConfiguration;

  public:
    /** @brief Get accessor functions for the LLRP LocationConfiguration sub-parameter */
    inline CLocationConfiguration *
    getLocationConfiguration (void)
    {
        return m_pLocationConfiguration;
    }

    /** @brief Set accessor functions for the LLRP LocationConfiguration sub-parameter */
    EResultCode
    setLocationConfiguration (
      CLocationConfiguration * pValue);


  protected:
    CSecurityModuleConfiguration * m_pSecurityModuleConfiguration;

  public:
    /** @brief Get accessor functions for the LLRP SecurityModuleConfiguration sub-parameter */
    inline CSecurityModuleConfiguration *
    getSecurityModuleConfiguration (void)
    {
        return m_pSecurityModuleConfiguration;
    }

    /** @brief Set accessor functions for the LLRP SecurityModuleConfiguration sub-parameter */
    EResultCode
    setSecurityModuleConfiguration (
      CSecurityModuleConfiguration * pValue);


};


/**
 ** @brief  Class Definition CSetDeviceConfigAck for LLRP message SetDeviceConfigAck
 **



 **/

class CSetDeviceConfigAck : public CMessage
{
  public:
    CSetDeviceConfigAck (void);
    ~CSetDeviceConfigAck (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    CStatus * m_pStatus;

  public:
    /** @brief Get accessor functions for the LLRP Status sub-parameter */
    inline CStatus *
    getStatus (void)
    {
        return m_pStatus;
    }

    /** @brief Set accessor functions for the LLRP Status sub-parameter */
    EResultCode
    setStatus (
      CStatus * pValue);


};


/**
 ** @brief  Class Definition CGetVersion for LLRP message GetVersion
 **



 **/

class CGetVersion : public CMessage
{
  public:
    CGetVersion (void);
    ~CGetVersion (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    EGetVersionVerType m_EVerType;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdVerType;
//@}

    /** @brief Get accessor functions for the LLRP VerType field */
    inline EGetVersionVerType
    getVerType (void)
    {
        return m_EVerType;
    }

    /** @brief Set accessor functions for the LLRP VerType field */
    inline void
    setVerType (
      EGetVersionVerType  value)
    {
        m_EVerType = value;
    }


};


/**
 ** @brief  Class Definition CGetVersionAck for LLRP message GetVersionAck
 **




 **/

class CGetVersionAck : public CMessage
{
  public:
    CGetVersionAck (void);
    ~CGetVersionAck (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    CStatus * m_pStatus;

  public:
    /** @brief Get accessor functions for the LLRP Status sub-parameter */
    inline CStatus *
    getStatus (void)
    {
        return m_pStatus;
    }

    /** @brief Set accessor functions for the LLRP Status sub-parameter */
    EResultCode
    setStatus (
      CStatus * pValue);


  protected:
    std::list<CVersionInfo *> m_listVersionInfo;

  public:
     /** @brief  Returns the first element of the VersionInfo sub-parameter list*/
    inline std::list<CVersionInfo *>::iterator
    beginVersionInfo (void)
    {
        return m_listVersionInfo.begin();
    }

     /** @brief  Returns the last element of the VersionInfo sub-parameter list*/
    inline std::list<CVersionInfo *>::iterator
    endVersionInfo (void)
    {
        return m_listVersionInfo.end();
    }

     /** @brief  Clears the LLRP VersionInfo sub-parameter list*/
    inline void
    clearVersionInfo (void)
    {
        clearSubParameterList ((tListOfParameters *) &m_listVersionInfo);
    }

    EResultCode
     /** @brief  Add a VersionInfo to the LLRP sub-parameter list*/
    addVersionInfo (
      CVersionInfo * pValue);


};


/**
 ** @brief  Class Definition CSetVersion for LLRP message SetVersion
 **




 **/

class CSetVersion : public CMessage
{
  public:
    CSetVersion (void);
    ~CSetVersion (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    ESetVersionVerType m_EVerType;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdVerType;
//@}

    /** @brief Get accessor functions for the LLRP VerType field */
    inline ESetVersionVerType
    getVerType (void)
    {
        return m_EVerType;
    }

    /** @brief Set accessor functions for the LLRP VerType field */
    inline void
    setVerType (
      ESetVersionVerType  value)
    {
        m_EVerType = value;
    }


  protected:
    CVersionDownload * m_pVersionDownload;

  public:
    /** @brief Get accessor functions for the LLRP VersionDownload sub-parameter */
    inline CVersionDownload *
    getVersionDownload (void)
    {
        return m_pVersionDownload;
    }

    /** @brief Set accessor functions for the LLRP VersionDownload sub-parameter */
    EResultCode
    setVersionDownload (
      CVersionDownload * pValue);


};


/**
 ** @brief  Class Definition CSetVersionAck for LLRP message SetVersionAck
 **



 **/

class CSetVersionAck : public CMessage
{
  public:
    CSetVersionAck (void);
    ~CSetVersionAck (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    CStatus * m_pStatus;

  public:
    /** @brief Get accessor functions for the LLRP Status sub-parameter */
    inline CStatus *
    getStatus (void)
    {
        return m_pStatus;
    }

    /** @brief Set accessor functions for the LLRP Status sub-parameter */
    EResultCode
    setStatus (
      CStatus * pValue);


};


/**
 ** @brief  Class Definition CActiveVersion for LLRP message ActiveVersion
 **



 **/

class CActiveVersion : public CMessage
{
  public:
    CActiveVersion (void);
    ~CActiveVersion (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    EActiveVersionVerType m_EVerType;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdVerType;
//@}

    /** @brief Get accessor functions for the LLRP VerType field */
    inline EActiveVersionVerType
    getVerType (void)
    {
        return m_EVerType;
    }

    /** @brief Set accessor functions for the LLRP VerType field */
    inline void
    setVerType (
      EActiveVersionVerType  value)
    {
        m_EVerType = value;
    }


};


/**
 ** @brief  Class Definition CActiveVersionAck for LLRP message ActiveVersionAck
 **



 **/

class CActiveVersionAck : public CMessage
{
  public:
    CActiveVersionAck (void);
    ~CActiveVersionAck (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    CStatus * m_pStatus;

  public:
    /** @brief Get accessor functions for the LLRP Status sub-parameter */
    inline CStatus *
    getStatus (void)
    {
        return m_pStatus;
    }

    /** @brief Set accessor functions for the LLRP Status sub-parameter */
    EResultCode
    setStatus (
      CStatus * pValue);


};


/**
 ** @brief  Class Definition CUnActiveVersion for LLRP message UnActiveVersion
 **



 **/

class CUnActiveVersion : public CMessage
{
  public:
    CUnActiveVersion (void);
    ~CUnActiveVersion (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    EUnActiveVersionVerType m_EVerType;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdVerType;
//@}

    /** @brief Get accessor functions for the LLRP VerType field */
    inline EUnActiveVersionVerType
    getVerType (void)
    {
        return m_EVerType;
    }

    /** @brief Set accessor functions for the LLRP VerType field */
    inline void
    setVerType (
      EUnActiveVersionVerType  value)
    {
        m_EVerType = value;
    }


};


/**
 ** @brief  Class Definition CUnActiveVersionAck for LLRP message UnActiveVersionAck
 **



 **/

class CUnActiveVersionAck : public CMessage
{
  public:
    CUnActiveVersionAck (void);
    ~CUnActiveVersionAck (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    CStatus * m_pStatus;

  public:
    /** @brief Get accessor functions for the LLRP Status sub-parameter */
    inline CStatus *
    getStatus (void)
    {
        return m_pStatus;
    }

    /** @brief Set accessor functions for the LLRP Status sub-parameter */
    EResultCode
    setStatus (
      CStatus * pValue);


};


/**
 ** @brief  Class Definition CAlarmReport for LLRP message AlarmReport
 **




 **/

class CAlarmReport : public CMessage
{
  public:
    CAlarmReport (void);
    ~CAlarmReport (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    llrp_u32_t m_AlarmID;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdAlarmID;
//@}

    /** @brief Get accessor functions for the LLRP AlarmID field */
    inline llrp_u32_t
    getAlarmID (void)
    {
        return m_AlarmID;
    }

    /** @brief Set accessor functions for the LLRP AlarmID field */
    inline void
    setAlarmID (
      llrp_u32_t  value)
    {
        m_AlarmID = value;
    }


  protected:
    CAlarmReportInfo * m_pAlarmReportInfo;

  public:
    /** @brief Get accessor functions for the LLRP AlarmReportInfo sub-parameter */
    inline CAlarmReportInfo *
    getAlarmReportInfo (void)
    {
        return m_pAlarmReportInfo;
    }

    /** @brief Set accessor functions for the LLRP AlarmReportInfo sub-parameter */
    EResultCode
    setAlarmReportInfo (
      CAlarmReportInfo * pValue);


};


/**
 ** @brief  Class Definition CAlarmRestore for LLRP message AlarmRestore
 **




 **/

class CAlarmRestore : public CMessage
{
  public:
    CAlarmRestore (void);
    ~CAlarmRestore (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    llrp_u32_t m_AlarmID;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdAlarmID;
//@}

    /** @brief Get accessor functions for the LLRP AlarmID field */
    inline llrp_u32_t
    getAlarmID (void)
    {
        return m_AlarmID;
    }

    /** @brief Set accessor functions for the LLRP AlarmID field */
    inline void
    setAlarmID (
      llrp_u32_t  value)
    {
        m_AlarmID = value;
    }


  protected:
    CAlarmRestoreInfo * m_pAlarmRestoreInfo;

  public:
    /** @brief Get accessor functions for the LLRP AlarmRestoreInfo sub-parameter */
    inline CAlarmRestoreInfo *
    getAlarmRestoreInfo (void)
    {
        return m_pAlarmRestoreInfo;
    }

    /** @brief Set accessor functions for the LLRP AlarmRestoreInfo sub-parameter */
    EResultCode
    setAlarmRestoreInfo (
      CAlarmRestoreInfo * pValue);


};


/**
 ** @brief  Class Definition CAlarmDelete for LLRP message AlarmDelete
 **



 **/

class CAlarmDelete : public CMessage
{
  public:
    CAlarmDelete (void);
    ~CAlarmDelete (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    llrp_u32_t m_AlarmID;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdAlarmID;
//@}

    /** @brief Get accessor functions for the LLRP AlarmID field */
    inline llrp_u32_t
    getAlarmID (void)
    {
        return m_AlarmID;
    }

    /** @brief Set accessor functions for the LLRP AlarmID field */
    inline void
    setAlarmID (
      llrp_u32_t  value)
    {
        m_AlarmID = value;
    }


};


/**
 ** @brief  Class Definition CAlarmSync for LLRP message AlarmSync
 **



 **/

class CAlarmSync : public CMessage
{
  public:
    CAlarmSync (void);
    ~CAlarmSync (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    CAlarmSyncInfo * m_pAlarmSyncInfo;

  public:
    /** @brief Get accessor functions for the LLRP AlarmSyncInfo sub-parameter */
    inline CAlarmSyncInfo *
    getAlarmSyncInfo (void)
    {
        return m_pAlarmSyncInfo;
    }

    /** @brief Set accessor functions for the LLRP AlarmSyncInfo sub-parameter */
    EResultCode
    setAlarmSyncInfo (
      CAlarmSyncInfo * pValue);


};


/**
 ** @brief  Class Definition CDiagnosticTest for LLRP message DiagnosticTest
 **



 **/

class CDiagnosticTest : public CMessage
{
  public:
    CDiagnosticTest (void);
    ~CDiagnosticTest (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    std::list<CDiagnosticTestItem *> m_listDiagnosticTestItem;

  public:
     /** @brief  Returns the first element of the DiagnosticTestItem sub-parameter list*/
    inline std::list<CDiagnosticTestItem *>::iterator
    beginDiagnosticTestItem (void)
    {
        return m_listDiagnosticTestItem.begin();
    }

     /** @brief  Returns the last element of the DiagnosticTestItem sub-parameter list*/
    inline std::list<CDiagnosticTestItem *>::iterator
    endDiagnosticTestItem (void)
    {
        return m_listDiagnosticTestItem.end();
    }

     /** @brief  Clears the LLRP DiagnosticTestItem sub-parameter list*/
    inline void
    clearDiagnosticTestItem (void)
    {
        clearSubParameterList ((tListOfParameters *) &m_listDiagnosticTestItem);
    }

    EResultCode
     /** @brief  Add a DiagnosticTestItem to the LLRP sub-parameter list*/
    addDiagnosticTestItem (
      CDiagnosticTestItem * pValue);


};


/**
 ** @brief  Class Definition CDiagnosticTestAck for LLRP message DiagnosticTestAck
 **




 **/

class CDiagnosticTestAck : public CMessage
{
  public:
    CDiagnosticTestAck (void);
    ~CDiagnosticTestAck (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    CStatus * m_pStatus;

  public:
    /** @brief Get accessor functions for the LLRP Status sub-parameter */
    inline CStatus *
    getStatus (void)
    {
        return m_pStatus;
    }

    /** @brief Set accessor functions for the LLRP Status sub-parameter */
    EResultCode
    setStatus (
      CStatus * pValue);


  protected:
    std::list<CDiagnosticTestResultItem *> m_listDiagnosticTestResultItem;

  public:
     /** @brief  Returns the first element of the DiagnosticTestResultItem sub-parameter list*/
    inline std::list<CDiagnosticTestResultItem *>::iterator
    beginDiagnosticTestResultItem (void)
    {
        return m_listDiagnosticTestResultItem.begin();
    }

     /** @brief  Returns the last element of the DiagnosticTestResultItem sub-parameter list*/
    inline std::list<CDiagnosticTestResultItem *>::iterator
    endDiagnosticTestResultItem (void)
    {
        return m_listDiagnosticTestResultItem.end();
    }

     /** @brief  Clears the LLRP DiagnosticTestResultItem sub-parameter list*/
    inline void
    clearDiagnosticTestResultItem (void)
    {
        clearSubParameterList ((tListOfParameters *) &m_listDiagnosticTestResultItem);
    }

    EResultCode
     /** @brief  Add a DiagnosticTestResultItem to the LLRP sub-parameter list*/
    addDiagnosticTestResultItem (
      CDiagnosticTestResultItem * pValue);


};


/**
 ** @brief  Class Definition CResetDevice for LLRP message ResetDevice
 **


 **/

class CResetDevice : public CMessage
{
  public:
    CResetDevice (void);
    ~CResetDevice (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


};


/**
 ** @brief  Class Definition CResetDeviceAck for LLRP message ResetDeviceAck
 **



 **/

class CResetDeviceAck : public CMessage
{
  public:
    CResetDeviceAck (void);
    ~CResetDeviceAck (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    CStatus * m_pStatus;

  public:
    /** @brief Get accessor functions for the LLRP Status sub-parameter */
    inline CStatus *
    getStatus (void)
    {
        return m_pStatus;
    }

    /** @brief Set accessor functions for the LLRP Status sub-parameter */
    EResultCode
    setStatus (
      CStatus * pValue);


};


/*@}*/

/**
 * \defgroup CoreParameter Core Parameter Classes
 * Classes to manipulate the parameters defined by the Core LLRP protocol
 */
/*@{*/

/**
 ** @brief  Class Definition CTagLog for LLRP parameter TagLog
 **







 **/

class CTagLog : public CParameter
{
  public:
    CTagLog (void);
    ~CTagLog (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    llrp_u64_t m_LogSequence;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdLogSequence;
//@}

    /** @brief Get accessor functions for the LLRP LogSequence field */
    inline llrp_u64_t
    getLogSequence (void)
    {
        return m_LogSequence;
    }

    /** @brief Set accessor functions for the LLRP LogSequence field */
    inline void
    setLogSequence (
      llrp_u64_t  value)
    {
        m_LogSequence = value;
    }


  protected:
    llrp_u8v_t  m_TID;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdTID;
//@}

    /** @brief Get accessor functions for the LLRP TID field */
    inline llrp_u8v_t
    getTID (void)
    {
        return m_TID;
    }

    /** @brief Set accessor functions for the LLRP TID field */
    inline void
    setTID (
      llrp_u8v_t   value)
    {
        m_TID = value;
    }


  protected:
    llrp_u8v_t  m_CardID;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdCardID;
//@}

    /** @brief Get accessor functions for the LLRP CardID field */
    inline llrp_u8v_t
    getCardID (void)
    {
        return m_CardID;
    }

    /** @brief Set accessor functions for the LLRP CardID field */
    inline void
    setCardID (
      llrp_u8v_t   value)
    {
        m_CardID = value;
    }


  protected:
    llrp_u32_t m_OpNum;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdOpNum;
//@}

    /** @brief Get accessor functions for the LLRP OpNum field */
    inline llrp_u32_t
    getOpNum (void)
    {
        return m_OpNum;
    }

    /** @brief Set accessor functions for the LLRP OpNum field */
    inline void
    setOpNum (
      llrp_u32_t  value)
    {
        m_OpNum = value;
    }


  protected:
    CUTCTimestamp * m_pUTCTimestamp;

  public:
    /** @brief Get accessor functions for the LLRP UTCTimestamp sub-parameter */
    inline CUTCTimestamp *
    getUTCTimestamp (void)
    {
        return m_pUTCTimestamp;
    }

    /** @brief Set accessor functions for the LLRP UTCTimestamp sub-parameter */
    EResultCode
    setUTCTimestamp (
      CUTCTimestamp * pValue);


};


/**
 ** @brief  Class Definition CStartLogTimestamp for LLRP parameter StartLogTimestamp
 **



 **/

class CStartLogTimestamp : public CParameter
{
  public:
    CStartLogTimestamp (void);
    ~CStartLogTimestamp (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    llrp_u64_t m_Microseconds;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdMicroseconds;
//@}

    /** @brief Get accessor functions for the LLRP Microseconds field */
    inline llrp_u64_t
    getMicroseconds (void)
    {
        return m_Microseconds;
    }

    /** @brief Set accessor functions for the LLRP Microseconds field */
    inline void
    setMicroseconds (
      llrp_u64_t  value)
    {
        m_Microseconds = value;
    }


};


/**
 ** @brief  Class Definition CEndLogTimestamp for LLRP parameter EndLogTimestamp
 **



 **/

class CEndLogTimestamp : public CParameter
{
  public:
    CEndLogTimestamp (void);
    ~CEndLogTimestamp (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    llrp_u64_t m_Microseconds;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdMicroseconds;
//@}

    /** @brief Get accessor functions for the LLRP Microseconds field */
    inline llrp_u64_t
    getMicroseconds (void)
    {
        return m_Microseconds;
    }

    /** @brief Set accessor functions for the LLRP Microseconds field */
    inline void
    setMicroseconds (
      llrp_u64_t  value)
    {
        m_Microseconds = value;
    }


};


/**
 ** @brief  Class Definition CDeviceLog for LLRP parameter DeviceLog
 **







 **/

class CDeviceLog : public CParameter
{
  public:
    CDeviceLog (void);
    ~CDeviceLog (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    llrp_u64_t m_LogSequence;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdLogSequence;
//@}

    /** @brief Get accessor functions for the LLRP LogSequence field */
    inline llrp_u64_t
    getLogSequence (void)
    {
        return m_LogSequence;
    }

    /** @brief Set accessor functions for the LLRP LogSequence field */
    inline void
    setLogSequence (
      llrp_u64_t  value)
    {
        m_LogSequence = value;
    }


  protected:
    llrp_u8_t m_LogType;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdLogType;
//@}

    /** @brief Get accessor functions for the LLRP LogType field */
    inline llrp_u8_t
    getLogType (void)
    {
        return m_LogType;
    }

    /** @brief Set accessor functions for the LLRP LogType field */
    inline void
    setLogType (
      llrp_u8_t  value)
    {
        m_LogType = value;
    }


  protected:
    llrp_u32_t m_LogCode;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdLogCode;
//@}

    /** @brief Get accessor functions for the LLRP LogCode field */
    inline llrp_u32_t
    getLogCode (void)
    {
        return m_LogCode;
    }

    /** @brief Set accessor functions for the LLRP LogCode field */
    inline void
    setLogCode (
      llrp_u32_t  value)
    {
        m_LogCode = value;
    }


  protected:
    llrp_utf8v_t  m_LogDescInfo;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdLogDescInfo;
//@}

    /** @brief Get accessor functions for the LLRP LogDescInfo field */
    inline llrp_utf8v_t
    getLogDescInfo (void)
    {
        return m_LogDescInfo;
    }

    /** @brief Set accessor functions for the LLRP LogDescInfo field */
    inline void
    setLogDescInfo (
      llrp_utf8v_t   value)
    {
        m_LogDescInfo = value;
    }


  protected:
    CUTCTimestamp * m_pUTCTimestamp;

  public:
    /** @brief Get accessor functions for the LLRP UTCTimestamp sub-parameter */
    inline CUTCTimestamp *
    getUTCTimestamp (void)
    {
        return m_pUTCTimestamp;
    }

    /** @brief Set accessor functions for the LLRP UTCTimestamp sub-parameter */
    EResultCode
    setUTCTimestamp (
      CUTCTimestamp * pValue);


};


/**
 ** @brief  Class Definition CDeviceEventNotificationSpec for LLRP parameter DeviceEventNotificationSpec
 **



 **/

class CDeviceEventNotificationSpec : public CParameter
{
  public:
    CDeviceEventNotificationSpec (void);
    ~CDeviceEventNotificationSpec (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    std::list<CEventNotificationState *> m_listEventNotificationState;

  public:
     /** @brief  Returns the first element of the EventNotificationState sub-parameter list*/
    inline std::list<CEventNotificationState *>::iterator
    beginEventNotificationState (void)
    {
        return m_listEventNotificationState.begin();
    }

     /** @brief  Returns the last element of the EventNotificationState sub-parameter list*/
    inline std::list<CEventNotificationState *>::iterator
    endEventNotificationState (void)
    {
        return m_listEventNotificationState.end();
    }

     /** @brief  Clears the LLRP EventNotificationState sub-parameter list*/
    inline void
    clearEventNotificationState (void)
    {
        clearSubParameterList ((tListOfParameters *) &m_listEventNotificationState);
    }

    EResultCode
     /** @brief  Add a EventNotificationState to the LLRP sub-parameter list*/
    addEventNotificationState (
      CEventNotificationState * pValue);


};


/**
 ** @brief  Class Definition CEventNotificationState for LLRP parameter EventNotificationState
 **





 **/

class CEventNotificationState : public CParameter
{
  public:
    CEventNotificationState (void);
    ~CEventNotificationState (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    EEventNotificationStateEventType m_EEventType;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdEventType;
//@}

    /** @brief Get accessor functions for the LLRP EventType field */
    inline EEventNotificationStateEventType
    getEventType (void)
    {
        return m_EEventType;
    }

    /** @brief Set accessor functions for the LLRP EventType field */
    inline void
    setEventType (
      EEventNotificationStateEventType  value)
    {
        m_EEventType = value;
    }


  protected:
    EEventNotificationStateNotificationState m_ENotificationState;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdNotificationState;
//@}

    /** @brief Get accessor functions for the LLRP NotificationState field */
    inline EEventNotificationStateNotificationState
    getNotificationState (void)
    {
        return m_ENotificationState;
    }

    /** @brief Set accessor functions for the LLRP NotificationState field */
    inline void
    setNotificationState (
      EEventNotificationStateNotificationState  value)
    {
        m_ENotificationState = value;
    }


};


/**
 ** @brief  Class Definition CAntennaProperties for LLRP parameter AntennaProperties
 **






 **/

class CAntennaProperties : public CParameter
{
  public:
    CAntennaProperties (void);
    ~CAntennaProperties (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    EAntennaPropertiesAntennaConnected m_EAntennaConnected;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdAntennaConnected;
//@}

    /** @brief Get accessor functions for the LLRP AntennaConnected field */
    inline EAntennaPropertiesAntennaConnected
    getAntennaConnected (void)
    {
        return m_EAntennaConnected;
    }

    /** @brief Set accessor functions for the LLRP AntennaConnected field */
    inline void
    setAntennaConnected (
      EAntennaPropertiesAntennaConnected  value)
    {
        m_EAntennaConnected = value;
    }


  protected:
    llrp_u8_t m_AntennaID;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdAntennaID;
//@}

    /** @brief Get accessor functions for the LLRP AntennaID field */
    inline llrp_u8_t
    getAntennaID (void)
    {
        return m_AntennaID;
    }

    /** @brief Set accessor functions for the LLRP AntennaID field */
    inline void
    setAntennaID (
      llrp_u8_t  value)
    {
        m_AntennaID = value;
    }


  protected:
    llrp_s16_t m_AntennaGain;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdAntennaGain;
//@}

    /** @brief Get accessor functions for the LLRP AntennaGain field */
    inline llrp_s16_t
    getAntennaGain (void)
    {
        return m_AntennaGain;
    }

    /** @brief Set accessor functions for the LLRP AntennaGain field */
    inline void
    setAntennaGain (
      llrp_s16_t  value)
    {
        m_AntennaGain = value;
    }


};


/**
 ** @brief  Class Definition CAntennaConfiguration for LLRP parameter AntennaConfiguration
 **









 **/

class CAntennaConfiguration : public CParameter
{
  public:
    CAntennaConfiguration (void);
    ~CAntennaConfiguration (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    llrp_u8_t m_AntennaID;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdAntennaID;
//@}

    /** @brief Get accessor functions for the LLRP AntennaID field */
    inline llrp_u8_t
    getAntennaID (void)
    {
        return m_AntennaID;
    }

    /** @brief Set accessor functions for the LLRP AntennaID field */
    inline void
    setAntennaID (
      llrp_u8_t  value)
    {
        m_AntennaID = value;
    }


  protected:
    llrp_u16_t m_TransmitPowerIndex;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdTransmitPowerIndex;
//@}

    /** @brief Get accessor functions for the LLRP TransmitPowerIndex field */
    inline llrp_u16_t
    getTransmitPowerIndex (void)
    {
        return m_TransmitPowerIndex;
    }

    /** @brief Set accessor functions for the LLRP TransmitPowerIndex field */
    inline void
    setTransmitPowerIndex (
      llrp_u16_t  value)
    {
        m_TransmitPowerIndex = value;
    }


  protected:
    llrp_u16v_t m_FrequencyIndexes;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdFrequencyIndexes;
//@}

    /** @brief Get accessor functions for the LLRP FrequencyIndexes field */
    inline llrp_u16v_t
    getFrequencyIndexes (void)
    {
        return m_FrequencyIndexes;
    }

    /** @brief Set accessor functions for the LLRP FrequencyIndexes field */
    inline void
    setFrequencyIndexes (
      llrp_u16v_t  value)
    {
        m_FrequencyIndexes = value;
    }


  protected:
    llrp_u16_t m_ForDataRateIndex;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdForDataRateIndex;
//@}

    /** @brief Get accessor functions for the LLRP ForDataRateIndex field */
    inline llrp_u16_t
    getForDataRateIndex (void)
    {
        return m_ForDataRateIndex;
    }

    /** @brief Set accessor functions for the LLRP ForDataRateIndex field */
    inline void
    setForDataRateIndex (
      llrp_u16_t  value)
    {
        m_ForDataRateIndex = value;
    }


  protected:
    llrp_u16_t m_RevDataRateIndex;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdRevDataRateIndex;
//@}

    /** @brief Get accessor functions for the LLRP RevDataRateIndex field */
    inline llrp_u16_t
    getRevDataRateIndex (void)
    {
        return m_RevDataRateIndex;
    }

    /** @brief Set accessor functions for the LLRP RevDataRateIndex field */
    inline void
    setRevDataRateIndex (
      llrp_u16_t  value)
    {
        m_RevDataRateIndex = value;
    }


  protected:
    llrp_u16_t m_ForModulationIndex;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdForModulationIndex;
//@}

    /** @brief Get accessor functions for the LLRP ForModulationIndex field */
    inline llrp_u16_t
    getForModulationIndex (void)
    {
        return m_ForModulationIndex;
    }

    /** @brief Set accessor functions for the LLRP ForModulationIndex field */
    inline void
    setForModulationIndex (
      llrp_u16_t  value)
    {
        m_ForModulationIndex = value;
    }


  protected:
    llrp_u16_t m_RevDataEncodingIndex;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdRevDataEncodingIndex;
//@}

    /** @brief Get accessor functions for the LLRP RevDataEncodingIndex field */
    inline llrp_u16_t
    getRevDataEncodingIndex (void)
    {
        return m_RevDataEncodingIndex;
    }

    /** @brief Set accessor functions for the LLRP RevDataEncodingIndex field */
    inline void
    setRevDataEncodingIndex (
      llrp_u16_t  value)
    {
        m_RevDataEncodingIndex = value;
    }


};


/**
 ** @brief  Class Definition CModuleDepth for LLRP parameter ModuleDepth
 **



 **/

class CModuleDepth : public CParameter
{
  public:
    CModuleDepth (void);
    ~CModuleDepth (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    llrp_u16_t m_Index;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdIndex;
//@}

    /** @brief Get accessor functions for the LLRP Index field */
    inline llrp_u16_t
    getIndex (void)
    {
        return m_Index;
    }

    /** @brief Set accessor functions for the LLRP Index field */
    inline void
    setIndex (
      llrp_u16_t  value)
    {
        m_Index = value;
    }


};


/**
 ** @brief  Class Definition CIdentification for LLRP parameter Identification
 **



 **/

class CIdentification : public CParameter
{
  public:
    CIdentification (void);
    ~CIdentification (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    llrp_utf8v_t  m_DeviceName;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdDeviceName;
//@}

    /** @brief Get accessor functions for the LLRP DeviceName field */
    inline llrp_utf8v_t
    getDeviceName (void)
    {
        return m_DeviceName;
    }

    /** @brief Set accessor functions for the LLRP DeviceName field */
    inline void
    setDeviceName (
      llrp_utf8v_t   value)
    {
        m_DeviceName = value;
    }


};


/**
 ** @brief  Class Definition CAlarmConfiguration for LLRP parameter AlarmConfiguration
 **




 **/

class CAlarmConfiguration : public CParameter
{
  public:
    CAlarmConfiguration (void);
    ~CAlarmConfiguration (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    llrp_u8_t m_AlarmMask;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdAlarmMask;
//@}

    /** @brief Get accessor functions for the LLRP AlarmMask field */
    inline llrp_u8_t
    getAlarmMask (void)
    {
        return m_AlarmMask;
    }

    /** @brief Set accessor functions for the LLRP AlarmMask field */
    inline void
    setAlarmMask (
      llrp_u8_t  value)
    {
        m_AlarmMask = value;
    }


  protected:
    CAlarmThreshod * m_pAlarmThreshod;

  public:
    /** @brief Get accessor functions for the LLRP AlarmThreshod sub-parameter */
    inline CAlarmThreshod *
    getAlarmThreshod (void)
    {
        return m_pAlarmThreshod;
    }

    /** @brief Set accessor functions for the LLRP AlarmThreshod sub-parameter */
    EResultCode
    setAlarmThreshod (
      CAlarmThreshod * pValue);


};


/**
 ** @brief  Class Definition CAlarmThreshod for LLRP parameter AlarmThreshod
 **




 **/

class CAlarmThreshod : public CParameter
{
  public:
    CAlarmThreshod (void);
    ~CAlarmThreshod (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    llrp_s8_t m_TemperatureMaxValue;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdTemperatureMaxValue;
//@}

    /** @brief Get accessor functions for the LLRP TemperatureMaxValue field */
    inline llrp_s8_t
    getTemperatureMaxValue (void)
    {
        return m_TemperatureMaxValue;
    }

    /** @brief Set accessor functions for the LLRP TemperatureMaxValue field */
    inline void
    setTemperatureMaxValue (
      llrp_s8_t  value)
    {
        m_TemperatureMaxValue = value;
    }


  protected:
    llrp_s8_t m_TemperatureMinValue;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdTemperatureMinValue;
//@}

    /** @brief Get accessor functions for the LLRP TemperatureMinValue field */
    inline llrp_s8_t
    getTemperatureMinValue (void)
    {
        return m_TemperatureMinValue;
    }

    /** @brief Set accessor functions for the LLRP TemperatureMinValue field */
    inline void
    setTemperatureMinValue (
      llrp_s8_t  value)
    {
        m_TemperatureMinValue = value;
    }


};


/**
 ** @brief  Class Definition CCommunicationConfiguration for LLRP parameter CommunicationConfiguration
 **






 **/

class CCommunicationConfiguration : public CParameter
{
  public:
    CCommunicationConfiguration (void);
    ~CCommunicationConfiguration (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    std::list<CCommLinkConfiguration *> m_listCommLinkConfiguration;

  public:
     /** @brief  Returns the first element of the CommLinkConfiguration sub-parameter list*/
    inline std::list<CCommLinkConfiguration *>::iterator
    beginCommLinkConfiguration (void)
    {
        return m_listCommLinkConfiguration.begin();
    }

     /** @brief  Returns the last element of the CommLinkConfiguration sub-parameter list*/
    inline std::list<CCommLinkConfiguration *>::iterator
    endCommLinkConfiguration (void)
    {
        return m_listCommLinkConfiguration.end();
    }

     /** @brief  Clears the LLRP CommLinkConfiguration sub-parameter list*/
    inline void
    clearCommLinkConfiguration (void)
    {
        clearSubParameterList ((tListOfParameters *) &m_listCommLinkConfiguration);
    }

    EResultCode
     /** @brief  Add a CommLinkConfiguration to the LLRP sub-parameter list*/
    addCommLinkConfiguration (
      CCommLinkConfiguration * pValue);


  protected:
    std::list<CParameter *> m_listEthernetConfiguration;

  public:
     /** @brief  Returns the first element of the EthernetConfiguration sub-parameter list*/
    inline std::list<CParameter *>::iterator
    beginEthernetConfiguration (void)
    {
        return m_listEthernetConfiguration.begin();
    }

     /** @brief  Returns the last element of the EthernetConfiguration sub-parameter list*/
    inline std::list<CParameter *>::iterator
    endEthernetConfiguration (void)
    {
        return m_listEthernetConfiguration.end();
    }

     /** @brief  Clears the LLRP EthernetConfiguration sub-parameter list*/
    inline void
    clearEthernetConfiguration (void)
    {
        clearSubParameterList ((tListOfParameters *) &m_listEthernetConfiguration);
    }

    EResultCode
     /** @brief  Add a EthernetConfiguration to the LLRP sub-parameter list*/
    addEthernetConfiguration (
      CParameter * pValue);


  protected:
    std::list<CSerialPortConfiguration *> m_listSerialPortConfiguration;

  public:
     /** @brief  Returns the first element of the SerialPortConfiguration sub-parameter list*/
    inline std::list<CSerialPortConfiguration *>::iterator
    beginSerialPortConfiguration (void)
    {
        return m_listSerialPortConfiguration.begin();
    }

     /** @brief  Returns the last element of the SerialPortConfiguration sub-parameter list*/
    inline std::list<CSerialPortConfiguration *>::iterator
    endSerialPortConfiguration (void)
    {
        return m_listSerialPortConfiguration.end();
    }

     /** @brief  Clears the LLRP SerialPortConfiguration sub-parameter list*/
    inline void
    clearSerialPortConfiguration (void)
    {
        clearSubParameterList ((tListOfParameters *) &m_listSerialPortConfiguration);
    }

    EResultCode
     /** @brief  Add a SerialPortConfiguration to the LLRP sub-parameter list*/
    addSerialPortConfiguration (
      CSerialPortConfiguration * pValue);


  protected:
    CNTPConfiguration * m_pNTPConfiguration;

  public:
    /** @brief Get accessor functions for the LLRP NTPConfiguration sub-parameter */
    inline CNTPConfiguration *
    getNTPConfiguration (void)
    {
        return m_pNTPConfiguration;
    }

    /** @brief Set accessor functions for the LLRP NTPConfiguration sub-parameter */
    EResultCode
    setNTPConfiguration (
      CNTPConfiguration * pValue);


};


/**
 ** @brief  Class Definition CCommLinkConfiguration for LLRP parameter CommLinkConfiguration
 **







 **/

class CCommLinkConfiguration : public CParameter
{
  public:
    CCommLinkConfiguration (void);
    ~CCommLinkConfiguration (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    ELinkType m_ELinkType ;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdLinkType;
//@}

    /** @brief Get accessor functions for the LLRP LinkType field */
    inline ELinkType
    getLinkType (void)
    {
        return m_ELinkType ;
    }

    /** @brief Set accessor functions for the LLRP LinkType field */
    inline void
    setLinkType (
      ELinkType  value)
    {
        m_ELinkType  = value;
    }


  protected:
    CKeepaliveSpec * m_pKeepaliveSpec;

  public:
    /** @brief Get accessor functions for the LLRP KeepaliveSpec sub-parameter */
    inline CKeepaliveSpec *
    getKeepaliveSpec (void)
    {
        return m_pKeepaliveSpec;
    }

    /** @brief Set accessor functions for the LLRP KeepaliveSpec sub-parameter */
    EResultCode
    setKeepaliveSpec (
      CKeepaliveSpec * pValue);


  protected:
    CTcpLinkConfiguration * m_pTcpLinkConfiguration;

  public:
    /** @brief Get accessor functions for the LLRP TcpLinkConfiguration sub-parameter */
    inline CTcpLinkConfiguration *
    getTcpLinkConfiguration (void)
    {
        return m_pTcpLinkConfiguration;
    }

    /** @brief Set accessor functions for the LLRP TcpLinkConfiguration sub-parameter */
    EResultCode
    setTcpLinkConfiguration (
      CTcpLinkConfiguration * pValue);


  protected:
    CSerialLinkConfiguration * m_pSerialLinkConfiguration;

  public:
    /** @brief Get accessor functions for the LLRP SerialLinkConfiguration sub-parameter */
    inline CSerialLinkConfiguration *
    getSerialLinkConfiguration (void)
    {
        return m_pSerialLinkConfiguration;
    }

    /** @brief Set accessor functions for the LLRP SerialLinkConfiguration sub-parameter */
    EResultCode
    setSerialLinkConfiguration (
      CSerialLinkConfiguration * pValue);


  protected:
    CHttpLinkConfiguration * m_pHttpLinkConfiguration;

  public:
    /** @brief Get accessor functions for the LLRP HttpLinkConfiguration sub-parameter */
    inline CHttpLinkConfiguration *
    getHttpLinkConfiguration (void)
    {
        return m_pHttpLinkConfiguration;
    }

    /** @brief Set accessor functions for the LLRP HttpLinkConfiguration sub-parameter */
    EResultCode
    setHttpLinkConfiguration (
      CHttpLinkConfiguration * pValue);


};


/**
 ** @brief  Class Definition CKeepaliveSpec for LLRP parameter KeepaliveSpec
 **




 **/

class CKeepaliveSpec : public CParameter
{
  public:
    CKeepaliveSpec (void);
    ~CKeepaliveSpec (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    EKeepaliveTriggerType m_EKeepaliveTriggerType ;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdKeepaliveTriggerType;
//@}

    /** @brief Get accessor functions for the LLRP KeepaliveTriggerType field */
    inline EKeepaliveTriggerType
    getKeepaliveTriggerType (void)
    {
        return m_EKeepaliveTriggerType ;
    }

    /** @brief Set accessor functions for the LLRP KeepaliveTriggerType field */
    inline void
    setKeepaliveTriggerType (
      EKeepaliveTriggerType  value)
    {
        m_EKeepaliveTriggerType  = value;
    }


  protected:
    llrp_u32_t m_PeriodicTriggerValue;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdPeriodicTriggerValue;
//@}

    /** @brief Get accessor functions for the LLRP PeriodicTriggerValue field */
    inline llrp_u32_t
    getPeriodicTriggerValue (void)
    {
        return m_PeriodicTriggerValue;
    }

    /** @brief Set accessor functions for the LLRP PeriodicTriggerValue field */
    inline void
    setPeriodicTriggerValue (
      llrp_u32_t  value)
    {
        m_PeriodicTriggerValue = value;
    }


};


/**
 ** @brief  Class Definition CTcpLinkConfiguration for LLRP parameter TcpLinkConfiguration
 **







 **/

class CTcpLinkConfiguration : public CParameter
{
  public:
    CTcpLinkConfiguration (void);
    ~CTcpLinkConfiguration (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    ECommMode m_ECommMode ;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdCommMode;
//@}

    /** @brief Get accessor functions for the LLRP CommMode field */
    inline ECommMode
    getCommMode (void)
    {
        return m_ECommMode ;
    }

    /** @brief Set accessor functions for the LLRP CommMode field */
    inline void
    setCommMode (
      ECommMode  value)
    {
        m_ECommMode  = value;
    }


  protected:
    llrp_u1_t m_IsSSL;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdIsSSL;
//@}

    /** @brief Get accessor functions for the LLRP IsSSL field */
    inline llrp_u1_t
    getIsSSL (void)
    {
        return m_IsSSL;
    }

    /** @brief Set accessor functions for the LLRP IsSSL field */
    inline void
    setIsSSL (
      llrp_u1_t  value)
    {
        m_IsSSL = value;
    }


  protected:
    CClientModeConfiguration * m_pClientModeConfiguration;

  public:
    /** @brief Get accessor functions for the LLRP ClientModeConfiguration sub-parameter */
    inline CClientModeConfiguration *
    getClientModeConfiguration (void)
    {
        return m_pClientModeConfiguration;
    }

    /** @brief Set accessor functions for the LLRP ClientModeConfiguration sub-parameter */
    EResultCode
    setClientModeConfiguration (
      CClientModeConfiguration * pValue);


  protected:
    CServerModeConfiguration * m_pServerModeConfiguration;

  public:
    /** @brief Get accessor functions for the LLRP ServerModeConfiguration sub-parameter */
    inline CServerModeConfiguration *
    getServerModeConfiguration (void)
    {
        return m_pServerModeConfiguration;
    }

    /** @brief Set accessor functions for the LLRP ServerModeConfiguration sub-parameter */
    EResultCode
    setServerModeConfiguration (
      CServerModeConfiguration * pValue);


};


/**
 ** @brief  Class Definition CClientModeConfiguration for LLRP parameter ClientModeConfiguration
 **




 **/

class CClientModeConfiguration : public CParameter
{
  public:
    CClientModeConfiguration (void);
    ~CClientModeConfiguration (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    llrp_u16_t m_Port;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdPort;
//@}

    /** @brief Get accessor functions for the LLRP Port field */
    inline llrp_u16_t
    getPort (void)
    {
        return m_Port;
    }

    /** @brief Set accessor functions for the LLRP Port field */
    inline void
    setPort (
      llrp_u16_t  value)
    {
        m_Port = value;
    }


  protected:
    CIPAddress * m_pIPAddress;

  public:
    /** @brief Get accessor functions for the LLRP IPAddress sub-parameter */
    inline CIPAddress *
    getIPAddress (void)
    {
        return m_pIPAddress;
    }

    /** @brief Set accessor functions for the LLRP IPAddress sub-parameter */
    EResultCode
    setIPAddress (
      CIPAddress * pValue);


};


/**
 ** @brief  Class Definition CIPAddress for LLRP parameter IPAddress
 **





 **/

class CIPAddress : public CParameter
{
  public:
    CIPAddress (void);
    ~CIPAddress (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    EIPAddressVersion m_EVersion;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdVersion;
//@}

    /** @brief Get accessor functions for the LLRP Version field */
    inline EIPAddressVersion
    getVersion (void)
    {
        return m_EVersion;
    }

    /** @brief Set accessor functions for the LLRP Version field */
    inline void
    setVersion (
      EIPAddressVersion  value)
    {
        m_EVersion = value;
    }


  protected:
    llrp_u32v_t m_Address;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdAddress;
//@}

    /** @brief Get accessor functions for the LLRP Address field */
    inline llrp_u32v_t
    getAddress (void)
    {
        return m_Address;
    }

    /** @brief Set accessor functions for the LLRP Address field */
    inline void
    setAddress (
      llrp_u32v_t  value)
    {
        m_Address = value;
    }


};


/**
 ** @brief  Class Definition CServerModeConfiguration for LLRP parameter ServerModeConfiguration
 **



 **/

class CServerModeConfiguration : public CParameter
{
  public:
    CServerModeConfiguration (void);
    ~CServerModeConfiguration (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    llrp_u16_t m_Port;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdPort;
//@}

    /** @brief Get accessor functions for the LLRP Port field */
    inline llrp_u16_t
    getPort (void)
    {
        return m_Port;
    }

    /** @brief Set accessor functions for the LLRP Port field */
    inline void
    setPort (
      llrp_u16_t  value)
    {
        m_Port = value;
    }


};


/**
 ** @brief  Class Definition CSerialLinkConfiguration for LLRP parameter SerialLinkConfiguration
 **





 **/

class CSerialLinkConfiguration : public CParameter
{
  public:
    CSerialLinkConfiguration (void);
    ~CSerialLinkConfiguration (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    llrp_u8_t m_IfIndex;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdIfIndex;
//@}

    /** @brief Get accessor functions for the LLRP IfIndex field */
    inline llrp_u8_t
    getIfIndex (void)
    {
        return m_IfIndex;
    }

    /** @brief Set accessor functions for the LLRP IfIndex field */
    inline void
    setIfIndex (
      llrp_u8_t  value)
    {
        m_IfIndex = value;
    }


  protected:
    llrp_u8_t m_SrcAddr;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdSrcAddr;
//@}

    /** @brief Get accessor functions for the LLRP SrcAddr field */
    inline llrp_u8_t
    getSrcAddr (void)
    {
        return m_SrcAddr;
    }

    /** @brief Set accessor functions for the LLRP SrcAddr field */
    inline void
    setSrcAddr (
      llrp_u8_t  value)
    {
        m_SrcAddr = value;
    }


  protected:
    llrp_u8_t m_DstAddr;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdDstAddr;
//@}

    /** @brief Get accessor functions for the LLRP DstAddr field */
    inline llrp_u8_t
    getDstAddr (void)
    {
        return m_DstAddr;
    }

    /** @brief Set accessor functions for the LLRP DstAddr field */
    inline void
    setDstAddr (
      llrp_u8_t  value)
    {
        m_DstAddr = value;
    }


};


/**
 ** @brief  Class Definition CHttpLinkConfiguration for LLRP parameter HttpLinkConfiguration
 **



 **/

class CHttpLinkConfiguration : public CParameter
{
  public:
    CHttpLinkConfiguration (void);
    ~CHttpLinkConfiguration (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    llrp_utf8v_t  m_ServerUrl;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdServerUrl;
//@}

    /** @brief Get accessor functions for the LLRP ServerUrl field */
    inline llrp_utf8v_t
    getServerUrl (void)
    {
        return m_ServerUrl;
    }

    /** @brief Set accessor functions for the LLRP ServerUrl field */
    inline void
    setServerUrl (
      llrp_utf8v_t   value)
    {
        m_ServerUrl = value;
    }


};


/**
 ** @brief  Class Definition CEthernetIpv4Configuration for LLRP parameter EthernetIpv4Configuration
 **









 **/

class CEthernetIpv4Configuration : public CParameter
{
  public:
    CEthernetIpv4Configuration (void);
    ~CEthernetIpv4Configuration (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    llrp_u8_t m_IfIndex;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdIfIndex;
//@}

    /** @brief Get accessor functions for the LLRP IfIndex field */
    inline llrp_u8_t
    getIfIndex (void)
    {
        return m_IfIndex;
    }

    /** @brief Set accessor functions for the LLRP IfIndex field */
    inline void
    setIfIndex (
      llrp_u8_t  value)
    {
        m_IfIndex = value;
    }


  protected:
    llrp_u32_t m_IPAddress;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdIPAddress;
//@}

    /** @brief Get accessor functions for the LLRP IPAddress field */
    inline llrp_u32_t
    getIPAddress (void)
    {
        return m_IPAddress;
    }

    /** @brief Set accessor functions for the LLRP IPAddress field */
    inline void
    setIPAddress (
      llrp_u32_t  value)
    {
        m_IPAddress = value;
    }


  protected:
    llrp_u32_t m_IPMask;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdIPMask;
//@}

    /** @brief Get accessor functions for the LLRP IPMask field */
    inline llrp_u32_t
    getIPMask (void)
    {
        return m_IPMask;
    }

    /** @brief Set accessor functions for the LLRP IPMask field */
    inline void
    setIPMask (
      llrp_u32_t  value)
    {
        m_IPMask = value;
    }


  protected:
    llrp_u32_t m_GateWayAddr;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdGateWayAddr;
//@}

    /** @brief Get accessor functions for the LLRP GateWayAddr field */
    inline llrp_u32_t
    getGateWayAddr (void)
    {
        return m_GateWayAddr;
    }

    /** @brief Set accessor functions for the LLRP GateWayAddr field */
    inline void
    setGateWayAddr (
      llrp_u32_t  value)
    {
        m_GateWayAddr = value;
    }


  protected:
    llrp_u32_t m_DNSAddr;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdDNSAddr;
//@}

    /** @brief Get accessor functions for the LLRP DNSAddr field */
    inline llrp_u32_t
    getDNSAddr (void)
    {
        return m_DNSAddr;
    }

    /** @brief Set accessor functions for the LLRP DNSAddr field */
    inline void
    setDNSAddr (
      llrp_u32_t  value)
    {
        m_DNSAddr = value;
    }


  protected:
    llrp_u1_t m_IsDHCP;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdIsDHCP;
//@}

    /** @brief Get accessor functions for the LLRP IsDHCP field */
    inline llrp_u1_t
    getIsDHCP (void)
    {
        return m_IsDHCP;
    }

    /** @brief Set accessor functions for the LLRP IsDHCP field */
    inline void
    setIsDHCP (
      llrp_u1_t  value)
    {
        m_IsDHCP = value;
    }


};


/**
 ** @brief  Class Definition CEthernetIpv6Configuration for LLRP parameter EthernetIpv6Configuration
 **









 **/

class CEthernetIpv6Configuration : public CParameter
{
  public:
    CEthernetIpv6Configuration (void);
    ~CEthernetIpv6Configuration (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    llrp_u8_t m_IfIndex;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdIfIndex;
//@}

    /** @brief Get accessor functions for the LLRP IfIndex field */
    inline llrp_u8_t
    getIfIndex (void)
    {
        return m_IfIndex;
    }

    /** @brief Set accessor functions for the LLRP IfIndex field */
    inline void
    setIfIndex (
      llrp_u8_t  value)
    {
        m_IfIndex = value;
    }


  protected:
    llrp_u32v_t m_IPAddress;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdIPAddress;
//@}

    /** @brief Get accessor functions for the LLRP IPAddress field */
    inline llrp_u32v_t
    getIPAddress (void)
    {
        return m_IPAddress;
    }

    /** @brief Set accessor functions for the LLRP IPAddress field */
    inline void
    setIPAddress (
      llrp_u32v_t  value)
    {
        m_IPAddress = value;
    }


  protected:
    llrp_u8_t m_IPMask;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdIPMask;
//@}

    /** @brief Get accessor functions for the LLRP IPMask field */
    inline llrp_u8_t
    getIPMask (void)
    {
        return m_IPMask;
    }

    /** @brief Set accessor functions for the LLRP IPMask field */
    inline void
    setIPMask (
      llrp_u8_t  value)
    {
        m_IPMask = value;
    }


  protected:
    llrp_u32v_t m_GateWayAddr;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdGateWayAddr;
//@}

    /** @brief Get accessor functions for the LLRP GateWayAddr field */
    inline llrp_u32v_t
    getGateWayAddr (void)
    {
        return m_GateWayAddr;
    }

    /** @brief Set accessor functions for the LLRP GateWayAddr field */
    inline void
    setGateWayAddr (
      llrp_u32v_t  value)
    {
        m_GateWayAddr = value;
    }


  protected:
    llrp_u32v_t m_DNSAddr;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdDNSAddr;
//@}

    /** @brief Get accessor functions for the LLRP DNSAddr field */
    inline llrp_u32v_t
    getDNSAddr (void)
    {
        return m_DNSAddr;
    }

    /** @brief Set accessor functions for the LLRP DNSAddr field */
    inline void
    setDNSAddr (
      llrp_u32v_t  value)
    {
        m_DNSAddr = value;
    }


  protected:
    llrp_u1_t m_IsDHCP;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdIsDHCP;
//@}

    /** @brief Get accessor functions for the LLRP IsDHCP field */
    inline llrp_u1_t
    getIsDHCP (void)
    {
        return m_IsDHCP;
    }

    /** @brief Set accessor functions for the LLRP IsDHCP field */
    inline void
    setIsDHCP (
      llrp_u1_t  value)
    {
        m_IsDHCP = value;
    }


};


/**
 ** @brief  Class Definition CNTPConfiguration for LLRP parameter NTPConfiguration
 **




 **/

class CNTPConfiguration : public CParameter
{
  public:
    CNTPConfiguration (void);
    ~CNTPConfiguration (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    llrp_u32_t m_NtpPeriodicTime;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdNtpPeriodicTime;
//@}

    /** @brief Get accessor functions for the LLRP NtpPeriodicTime field */
    inline llrp_u32_t
    getNtpPeriodicTime (void)
    {
        return m_NtpPeriodicTime;
    }

    /** @brief Set accessor functions for the LLRP NtpPeriodicTime field */
    inline void
    setNtpPeriodicTime (
      llrp_u32_t  value)
    {
        m_NtpPeriodicTime = value;
    }


  protected:
    std::list<CIPAddress *> m_listIPAddress;

  public:
     /** @brief  Returns the first element of the IPAddress sub-parameter list*/
    inline std::list<CIPAddress *>::iterator
    beginIPAddress (void)
    {
        return m_listIPAddress.begin();
    }

     /** @brief  Returns the last element of the IPAddress sub-parameter list*/
    inline std::list<CIPAddress *>::iterator
    endIPAddress (void)
    {
        return m_listIPAddress.end();
    }

     /** @brief  Clears the LLRP IPAddress sub-parameter list*/
    inline void
    clearIPAddress (void)
    {
        clearSubParameterList ((tListOfParameters *) &m_listIPAddress);
    }

    EResultCode
     /** @brief  Add a IPAddress to the LLRP sub-parameter list*/
    addIPAddress (
      CIPAddress * pValue);


};


/**
 ** @brief  Class Definition CSerialPortConfiguration for LLRP parameter SerialPortConfiguration
 **




 **/

class CSerialPortConfiguration : public CParameter
{
  public:
    CSerialPortConfiguration (void);
    ~CSerialPortConfiguration (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    llrp_u8_t m_IfIndex;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdIfIndex;
//@}

    /** @brief Get accessor functions for the LLRP IfIndex field */
    inline llrp_u8_t
    getIfIndex (void)
    {
        return m_IfIndex;
    }

    /** @brief Set accessor functions for the LLRP IfIndex field */
    inline void
    setIfIndex (
      llrp_u8_t  value)
    {
        m_IfIndex = value;
    }


  protected:
    llrp_u8_t m_AttributeIndex;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdAttributeIndex;
//@}

    /** @brief Get accessor functions for the LLRP AttributeIndex field */
    inline llrp_u8_t
    getAttributeIndex (void)
    {
        return m_AttributeIndex;
    }

    /** @brief Set accessor functions for the LLRP AttributeIndex field */
    inline void
    setAttributeIndex (
      llrp_u8_t  value)
    {
        m_AttributeIndex = value;
    }


};


/**
 ** @brief  Class Definition CSecurityModuleConfiguration for LLRP parameter SecurityModuleConfiguration
 **



 **/

class CSecurityModuleConfiguration : public CParameter
{
  public:
    CSecurityModuleConfiguration (void);
    ~CSecurityModuleConfiguration (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    CGenaralConfigData * m_pGenaralConfigData;

  public:
    /** @brief Get accessor functions for the LLRP GenaralConfigData sub-parameter */
    inline CGenaralConfigData *
    getGenaralConfigData (void)
    {
        return m_pGenaralConfigData;
    }

    /** @brief Set accessor functions for the LLRP GenaralConfigData sub-parameter */
    EResultCode
    setGenaralConfigData (
      CGenaralConfigData * pValue);


};



/**
 ** @brief  Class Definition CGenaralConfigData for LLRP parameter GenaralConfigData
 **





 **/

class CGenaralConfigData : public CParameter
{
  public:
    CGenaralConfigData (void);
    ~CGenaralConfigData (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    CRTCTime * m_pRTCTime;

  public:
    /** @brief Get accessor functions for the LLRP RTCTime sub-parameter */
    inline CRTCTime *
    getRTCTime (void)
    {
        return m_pRTCTime;
    }

    /** @brief Set accessor functions for the LLRP RTCTime sub-parameter */
    EResultCode
    setRTCTime (
      CRTCTime * pValue);


  protected:
    CSecurityModuleSN * m_pSecurityModuleSN;

  public:
    /** @brief Get accessor functions for the LLRP SecurityModuleSN sub-parameter */
    inline CSecurityModuleSN *
    getSecurityModuleSN (void)
    {
        return m_pSecurityModuleSN;
    }

    /** @brief Set accessor functions for the LLRP SecurityModuleSN sub-parameter */
    EResultCode
    setSecurityModuleSN (
      CSecurityModuleSN * pValue);


  protected:
    CReadMode * m_pReadMode;

  public:
    /** @brief Get accessor functions for the LLRP ReadMode sub-parameter */
    inline CReadMode *
    getReadMode (void)
    {
        return m_pReadMode;
    }

    /** @brief Set accessor functions for the LLRP ReadMode sub-parameter */
    EResultCode
    setReadMode (
      CReadMode * pValue);


};



/**
 ** @brief  Class Definition CRTCTime for LLRP parameter RTCTime
 **



 **/

class CRTCTime : public CParameter
{
  public:
    CRTCTime (void);
    ~CRTCTime (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    llrp_u64_t m_Seconds;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdSeconds;
//@}

    /** @brief Get accessor functions for the LLRP Seconds field */
    inline llrp_u64_t
    getSeconds (void)
    {
        return m_Seconds;
    }

    /** @brief Set accessor functions for the LLRP Seconds field */
    inline void
    setSeconds (
      llrp_u64_t  value)
    {
        m_Seconds = value;
    }


};


/**
 ** @brief  Class Definition CSecurityModuleSN for LLRP parameter SecurityModuleSN
 **



 **/

class CSecurityModuleSN : public CParameter
{
  public:
    CSecurityModuleSN (void);
    ~CSecurityModuleSN (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    llrp_u8v_t  m_SerialNumber;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdSerialNumber;
//@}

    /** @brief Get accessor functions for the LLRP SerialNumber field */
    inline llrp_u8v_t
    getSerialNumber (void)
    {
        return m_SerialNumber;
    }

    /** @brief Set accessor functions for the LLRP SerialNumber field */
    inline void
    setSerialNumber (
      llrp_u8v_t   value)
    {
        m_SerialNumber = value;
    }


};


/**
 ** @brief  Class Definition CReadMode for LLRP parameter ReadMode
 **





 **/

class CReadMode : public CParameter
{
  public:
    CReadMode (void);
    ~CReadMode (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    llrp_u1_t m_RepeatReadFlag;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdRepeatReadFlag;
//@}

    /** @brief Get accessor functions for the LLRP RepeatReadFlag field */
    inline llrp_u1_t
    getRepeatReadFlag (void)
    {
        return m_RepeatReadFlag;
    }

    /** @brief Set accessor functions for the LLRP RepeatReadFlag field */
    inline void
    setRepeatReadFlag (
      llrp_u1_t  value)
    {
        m_RepeatReadFlag = value;
    }


  protected:
    llrp_u32_t m_Timer;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdTimer;
//@}

    /** @brief Get accessor functions for the LLRP Timer field */
    inline llrp_u32_t
    getTimer (void)
    {
        return m_Timer;
    }

    /** @brief Set accessor functions for the LLRP Timer field */
    inline void
    setTimer (
      llrp_u32_t  value)
    {
        m_Timer = value;
    }


};




/**
 ** @brief  Class Definition CVersionInfo for LLRP parameter VersionInfo
 **









 **/

class CVersionInfo : public CParameter
{
  public:
    CVersionInfo (void);
    ~CVersionInfo (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    llrp_u8v_t m_VersionData;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdVersionData;
//@}

    /** @brief Get accessor functions for the LLRP VersionData field */
    inline llrp_u8v_t
    getVersionData (void)
    {
        return m_VersionData;
    }

    /** @brief Set accessor functions for the LLRP VersionData field */
    inline void
    setVersionData (
      llrp_u8v_t  value)
    {
        m_VersionData = value;
    }


  protected:
    EVersionInfoUsedOrSpare m_eUsedOrSpare;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdUsedOrSpare;
//@}

    /** @brief Get accessor functions for the LLRP UsedOrSpare field */
    inline EVersionInfoUsedOrSpare
    getUsedOrSpare (void)
    {
        return m_eUsedOrSpare;
    }

    /** @brief Set accessor functions for the LLRP UsedOrSpare field */
    inline void
    setUsedOrSpare (
      EVersionInfoUsedOrSpare  value)
    {
        m_eUsedOrSpare = value;
    }


  protected:
    EVersionInfoSetUse m_eSetUse;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdSetUse;
//@}

    /** @brief Get accessor functions for the LLRP SetUse field */
    inline EVersionInfoSetUse
    getSetUse (void)
    {
        return m_eSetUse;
    }

    /** @brief Set accessor functions for the LLRP SetUse field */
    inline void
    setSetUse (
      EVersionInfoSetUse  value)
    {
        m_eSetUse = value;
    }


  protected:
    EVersionInfoHasRun m_eHasRun;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdHasRun;
//@}

    /** @brief Get accessor functions for the LLRP HasRun field */
    inline EVersionInfoHasRun
    getHasRun (void)
    {
        return m_eHasRun;
    }

    /** @brief Set accessor functions for the LLRP HasRun field */
    inline void
    setHasRun (
      EVersionInfoHasRun  value)
    {
        m_eHasRun = value;
    }


  protected:
    EVersionInfoCanRun m_eCanRun;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdCanRun;
//@}

    /** @brief Get accessor functions for the LLRP CanRun field */
    inline EVersionInfoCanRun
    getCanRun (void)
    {
        return m_eCanRun;
    }

    /** @brief Set accessor functions for the LLRP CanRun field */
    inline void
    setCanRun (
      EVersionInfoCanRun  value)
    {
        m_eCanRun = value;
    }


  protected:
    llrp_utf8v_t m_VerDescInfo;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdVerDescInfo;
//@}

    /** @brief Get accessor functions for the LLRP VerDescInfo field */
    inline llrp_utf8v_t
    getVerDescInfo (void)
    {
        return m_VerDescInfo;
    }

    /** @brief Set accessor functions for the LLRP VerDescInfo field */
    inline void
    setVerDescInfo (
      llrp_utf8v_t  value)
    {
        m_VerDescInfo = value;
    }


};


/**
 ** @brief  Class Definition CVersionDownload for LLRP parameter VersionDownload
 **








 **/

class CVersionDownload : public CParameter
{
  public:
    CVersionDownload (void);
    ~CVersionDownload (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    EVersionDownloadServerType m_EServerType;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdServerType;
//@}

    /** @brief Get accessor functions for the LLRP ServerType field */
    inline EVersionDownloadServerType
    getServerType (void)
    {
        return m_EServerType;
    }

    /** @brief Set accessor functions for the LLRP ServerType field */
    inline void
    setServerType (
      EVersionDownloadServerType  value)
    {
        m_EServerType = value;
    }


  protected:
    llrp_utf8v_t  m_UserName;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdUserName;
//@}

    /** @brief Get accessor functions for the LLRP UserName field */
    inline llrp_utf8v_t
    getUserName (void)
    {
        return m_UserName;
    }

    /** @brief Set accessor functions for the LLRP UserName field */
    inline void
    setUserName (
      llrp_utf8v_t   value)
    {
        m_UserName = value;
    }


  protected:
    llrp_utf8v_t  m_UserPass;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdUserPass;
//@}

    /** @brief Get accessor functions for the LLRP UserPass field */
    inline llrp_utf8v_t
    getUserPass (void)
    {
        return m_UserPass;
    }

    /** @brief Set accessor functions for the LLRP UserPass field */
    inline void
    setUserPass (
      llrp_utf8v_t   value)
    {
        m_UserPass = value;
    }


  protected:
    llrp_utf8v_t  m_VersionPath;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdVersionPath;
//@}

    /** @brief Get accessor functions for the LLRP VersionPath field */
    inline llrp_utf8v_t
    getVersionPath (void)
    {
        return m_VersionPath;
    }

    /** @brief Set accessor functions for the LLRP VersionPath field */
    inline void
    setVersionPath (
      llrp_utf8v_t   value)
    {
        m_VersionPath = value;
    }


  protected:
    llrp_u16_t m_ServerPort;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdServerPort;
//@}

    /** @brief Get accessor functions for the LLRP ServerPort field */
    inline llrp_u16_t
    getServerPort (void)
    {
        return m_ServerPort;
    }

    /** @brief Set accessor functions for the LLRP ServerPort field */
    inline void
    setServerPort (
      llrp_u16_t  value)
    {
        m_ServerPort = value;
    }


  protected:
    CIPAddress * m_pIPAddress;

  public:
    /** @brief Get accessor functions for the LLRP IPAddress sub-parameter */
    inline CIPAddress *
    getIPAddress (void)
    {
        return m_pIPAddress;
    }

    /** @brief Set accessor functions for the LLRP IPAddress sub-parameter */
    EResultCode
    setIPAddress (
      CIPAddress * pValue);


};


/**
 ** @brief  Class Definition CAlarmReportInfo for LLRP parameter AlarmReportInfo
 **







 **/

class CAlarmReportInfo : public CParameter
{
  public:
    CAlarmReportInfo (void);
    ~CAlarmReportInfo (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    llrp_u32_t m_AlarmReportCode;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdAlarmReportCode;
//@}

    /** @brief Get accessor functions for the LLRP AlarmReportCode field */
    inline llrp_u32_t
    getAlarmReportCode (void)
    {
        return m_AlarmReportCode;
    }

    /** @brief Set accessor functions for the LLRP AlarmReportCode field */
    inline void
    setAlarmReportCode (
      llrp_u32_t  value)
    {
        m_AlarmReportCode = value;
    }


  protected:
    llrp_u32_t m_AlarmReportReason;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdAlarmReportReason;
//@}

    /** @brief Get accessor functions for the LLRP AlarmReportReason field */
    inline llrp_u32_t
    getAlarmReportReason (void)
    {
        return m_AlarmReportReason;
    }

    /** @brief Set accessor functions for the LLRP AlarmReportReason field */
    inline void
    setAlarmReportReason (
      llrp_u32_t  value)
    {
        m_AlarmReportReason = value;
    }


  protected:
    EAlarmReportInfoAlarmReportLevel m_EAlarmReportLevel;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdAlarmReportLevel;
//@}

    /** @brief Get accessor functions for the LLRP AlarmReportLevel field */
    inline EAlarmReportInfoAlarmReportLevel
    getAlarmReportLevel (void)
    {
        return m_EAlarmReportLevel;
    }

    /** @brief Set accessor functions for the LLRP AlarmReportLevel field */
    inline void
    setAlarmReportLevel (
      EAlarmReportInfoAlarmReportLevel  value)
    {
        m_EAlarmReportLevel = value;
    }


  protected:
    llrp_u32_t m_AlarmReportSeconds;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdAlarmReportSeconds;
//@}

    /** @brief Get accessor functions for the LLRP AlarmReportSeconds field */
    inline llrp_u32_t
    getAlarmReportSeconds (void)
    {
        return m_AlarmReportSeconds;
    }

    /** @brief Set accessor functions for the LLRP AlarmReportSeconds field */
    inline void
    setAlarmReportSeconds (
      llrp_u32_t  value)
    {
        m_AlarmReportSeconds = value;
    }


  protected:
    llrp_utf8v_t  m_AlarmReportDescription;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdAlarmReportDescription;
//@}

    /** @brief Get accessor functions for the LLRP AlarmReportDescription field */
    inline llrp_utf8v_t
    getAlarmReportDescription (void)
    {
        return m_AlarmReportDescription;
    }

    /** @brief Set accessor functions for the LLRP AlarmReportDescription field */
    inline void
    setAlarmReportDescription (
      llrp_utf8v_t   value)
    {
        m_AlarmReportDescription = value;
    }


};


/**
 ** @brief  Class Definition CAlarmRestoreInfo for LLRP parameter AlarmRestoreInfo
 **




 **/

class CAlarmRestoreInfo : public CParameter
{
  public:
    CAlarmRestoreInfo (void);
    ~CAlarmRestoreInfo (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    llrp_u8_t m_AlarmRestoreType;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdAlarmRestoreType;
//@}

    /** @brief Get accessor functions for the LLRP AlarmRestoreType field */
    inline llrp_u8_t
    getAlarmRestoreType (void)
    {
        return m_AlarmRestoreType;
    }

    /** @brief Set accessor functions for the LLRP AlarmRestoreType field */
    inline void
    setAlarmRestoreType (
      llrp_u8_t  value)
    {
        m_AlarmRestoreType = value;
    }


  protected:
    llrp_u32_t m_AlarmRestoreSeconds;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdAlarmRestoreSeconds;
//@}

    /** @brief Get accessor functions for the LLRP AlarmRestoreSeconds field */
    inline llrp_u32_t
    getAlarmRestoreSeconds (void)
    {
        return m_AlarmRestoreSeconds;
    }

    /** @brief Set accessor functions for the LLRP AlarmRestoreSeconds field */
    inline void
    setAlarmRestoreSeconds (
      llrp_u32_t  value)
    {
        m_AlarmRestoreSeconds = value;
    }


};


/**
 ** @brief  Class Definition CAlarmSyncInfo for LLRP parameter AlarmSyncInfo
 **







 **/

class CAlarmSyncInfo : public CParameter
{
  public:
    CAlarmSyncInfo (void);
    ~CAlarmSyncInfo (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    llrp_u32_t m_AlarmSyncSeq;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdAlarmSyncSeq;
//@}

    /** @brief Get accessor functions for the LLRP AlarmSyncSeq field */
    inline llrp_u32_t
    getAlarmSyncSeq (void)
    {
        return m_AlarmSyncSeq;
    }

    /** @brief Set accessor functions for the LLRP AlarmSyncSeq field */
    inline void
    setAlarmSyncSeq (
      llrp_u32_t  value)
    {
        m_AlarmSyncSeq = value;
    }


  protected:
    llrp_u8_t m_AlarmSyncType;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdAlarmSyncType;
//@}

    /** @brief Get accessor functions for the LLRP AlarmSyncType field */
    inline llrp_u8_t
    getAlarmSyncType (void)
    {
        return m_AlarmSyncType;
    }

    /** @brief Set accessor functions for the LLRP AlarmSyncType field */
    inline void
    setAlarmSyncType (
      llrp_u8_t  value)
    {
        m_AlarmSyncType = value;
    }


  protected:
    llrp_u16_t m_AlarmSyncPackageNo;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdAlarmSyncPackageNo;
//@}

    /** @brief Get accessor functions for the LLRP AlarmSyncPackageNo field */
    inline llrp_u16_t
    getAlarmSyncPackageNo (void)
    {
        return m_AlarmSyncPackageNo;
    }

    /** @brief Set accessor functions for the LLRP AlarmSyncPackageNo field */
    inline void
    setAlarmSyncPackageNo (
      llrp_u16_t  value)
    {
        m_AlarmSyncPackageNo = value;
    }


  protected:
    llrp_u16_t m_AlarmSyncPackageNum;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdAlarmSyncPackageNum;
//@}

    /** @brief Get accessor functions for the LLRP AlarmSyncPackageNum field */
    inline llrp_u16_t
    getAlarmSyncPackageNum (void)
    {
        return m_AlarmSyncPackageNum;
    }

    /** @brief Set accessor functions for the LLRP AlarmSyncPackageNum field */
    inline void
    setAlarmSyncPackageNum (
      llrp_u16_t  value)
    {
        m_AlarmSyncPackageNum = value;
    }


  protected:
    llrp_u32v_t m_AlarmIDs;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdAlarmIDs;
//@}

    /** @brief Get accessor functions for the LLRP AlarmIDs field */
    inline llrp_u32v_t
    getAlarmIDs (void)
    {
        return m_AlarmIDs;
    }

    /** @brief Set accessor functions for the LLRP AlarmIDs field */
    inline void
    setAlarmIDs (
      llrp_u32v_t  value)
    {
        m_AlarmIDs = value;
    }


};


/**
 ** @brief  Class Definition CDiagnosticTestItem for LLRP parameter DiagnosticTestItem
 **



 **/

class CDiagnosticTestItem : public CParameter
{
  public:
    CDiagnosticTestItem (void);
    ~CDiagnosticTestItem (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    llrp_u16_t m_DiagnosticTestID;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdDiagnosticTestID;
//@}

    /** @brief Get accessor functions for the LLRP DiagnosticTestID field */
    inline llrp_u16_t
    getDiagnosticTestID (void)
    {
        return m_DiagnosticTestID;
    }

    /** @brief Set accessor functions for the LLRP DiagnosticTestID field */
    inline void
    setDiagnosticTestID (
      llrp_u16_t  value)
    {
        m_DiagnosticTestID = value;
    }


};


/**
 ** @brief  Class Definition CDiagnosticTestResultItem for LLRP parameter DiagnosticTestResultItem
 **





 **/

class CDiagnosticTestResultItem : public CParameter
{
  public:
    CDiagnosticTestResultItem (void);
    ~CDiagnosticTestResultItem (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    llrp_u16_t m_DiagnosticTestID;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdDiagnosticTestID;
//@}

    /** @brief Get accessor functions for the LLRP DiagnosticTestID field */
    inline llrp_u16_t
    getDiagnosticTestID (void)
    {
        return m_DiagnosticTestID;
    }

    /** @brief Set accessor functions for the LLRP DiagnosticTestID field */
    inline void
    setDiagnosticTestID (
      llrp_u16_t  value)
    {
        m_DiagnosticTestID = value;
    }


  protected:
    llrp_u32_t m_DiagnosticTestResultCode;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdDiagnosticTestResultCode;
//@}

    /** @brief Get accessor functions for the LLRP DiagnosticTestResultCode field */
    inline llrp_u32_t
    getDiagnosticTestResultCode (void)
    {
        return m_DiagnosticTestResultCode;
    }

    /** @brief Set accessor functions for the LLRP DiagnosticTestResultCode field */
    inline void
    setDiagnosticTestResultCode (
      llrp_u32_t  value)
    {
        m_DiagnosticTestResultCode = value;
    }


  protected:
    CParameter * m_pDiagnosticTestResultData;

  public:
    /** @brief Get accessor functions for the LLRP DiagnosticTestResultData sub-parameter */
    inline CParameter *
    getDiagnosticTestResultData (void)
    {
        return m_pDiagnosticTestResultData;
    }

    /** @brief Set accessor functions for the LLRP DiagnosticTestResultData sub-parameter */
    EResultCode
    setDiagnosticTestResultData (
      CParameter * pValue);


};


/**
 ** @brief  Class Definition CDiagnosticTestResultAntennaConnected for LLRP parameter DiagnosticTestResultAntennaConnected
 **





 **/

class CDiagnosticTestResultAntennaConnected : public CParameter
{
  public:
    CDiagnosticTestResultAntennaConnected (void);
    ~CDiagnosticTestResultAntennaConnected (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    llrp_u8_t m_AntennaID;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdAntennaID;
//@}

    /** @brief Get accessor functions for the LLRP AntennaID field */
    inline llrp_u8_t
    getAntennaID (void)
    {
        return m_AntennaID;
    }

    /** @brief Set accessor functions for the LLRP AntennaID field */
    inline void
    setAntennaID (
      llrp_u8_t  value)
    {
        m_AntennaID = value;
    }


  protected:
    EDiagnosticTestResultAntennaConnected m_EAntennaConnected;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdAntennaConnected;
//@}

    /** @brief Get accessor functions for the LLRP AntennaConnected field */
    inline EDiagnosticTestResultAntennaConnected
    getAntennaConnected (void)
    {
        return m_EAntennaConnected;
    }

    /** @brief Set accessor functions for the LLRP AntennaConnected field */
    inline void
    setAntennaConnected (
      EDiagnosticTestResultAntennaConnected  value)
    {
        m_EAntennaConnected = value;
    }


};


/**
 ** @brief  Class Definition CDiagnosticTestResultAntennaVSWR for LLRP parameter DiagnosticTestResultAntennaVSWR
 **




 **/

class CDiagnosticTestResultAntennaVSWR : public CParameter
{
  public:
    CDiagnosticTestResultAntennaVSWR (void);
    ~CDiagnosticTestResultAntennaVSWR (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    llrp_u8_t m_AntennaID;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdAntennaID;
//@}

    /** @brief Get accessor functions for the LLRP AntennaID field */
    inline llrp_u8_t
    getAntennaID (void)
    {
        return m_AntennaID;
    }

    /** @brief Set accessor functions for the LLRP AntennaID field */
    inline void
    setAntennaID (
      llrp_u8_t  value)
    {
        m_AntennaID = value;
    }


  protected:
    llrp_u16_t m_AntennaVSWR;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdAntennaVSWR;
//@}

    /** @brief Get accessor functions for the LLRP AntennaVSWR field */
    inline llrp_u16_t
    getAntennaVSWR (void)
    {
        return m_AntennaVSWR;
    }

    /** @brief Set accessor functions for the LLRP AntennaVSWR field */
    inline void
    setAntennaVSWR (
      llrp_u16_t  value)
    {
        m_AntennaVSWR = value;
    }


};


/**
 ** @brief  Class Definition CLocationConfiguration for LLRP parameter LocationConfiguration
 **




 **/

class CLocationConfiguration : public CParameter
{
  public:
    CLocationConfiguration (void);
    ~CLocationConfiguration (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    ELocationType m_ELocationType ;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdLocationType;
//@}

    /** @brief Get accessor functions for the LLRP LocationType field */
    inline ELocationType
    getLocationType (void)
    {
        return m_ELocationType ;
    }

    /** @brief Set accessor functions for the LLRP LocationType field */
    inline void
    setLocationType (
      ELocationType  value)
    {
        m_ELocationType  = value;
    }


  protected:
    CParameter * m_pLocationInfo;

  public:
    /** @brief Get accessor functions for the LLRP LocationInfo sub-parameter */
    inline CParameter *
    getLocationInfo (void)
    {
        return m_pLocationInfo;
    }

    /** @brief Set accessor functions for the LLRP LocationInfo sub-parameter */
    EResultCode
    setLocationInfo (
      CParameter * pValue);


};


/**
 ** @brief  Class Definition CGpsLocation for LLRP parameter GpsLocation
 **





 **/

class CGpsLocation : public CParameter
{
  public:
    CGpsLocation (void);
    ~CGpsLocation (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    llrp_s32_t m_Longitude;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdLongitude;
//@}

    /** @brief Get accessor functions for the LLRP Longitude field */
    inline llrp_s32_t
    getLongitude (void)
    {
        return m_Longitude;
    }

    /** @brief Set accessor functions for the LLRP Longitude field */
    inline void
    setLongitude (
      llrp_s32_t  value)
    {
        m_Longitude = value;
    }


  protected:
    llrp_s32_t m_Latitude;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdLatitude;
//@}

    /** @brief Get accessor functions for the LLRP Latitude field */
    inline llrp_s32_t
    getLatitude (void)
    {
        return m_Latitude;
    }

    /** @brief Set accessor functions for the LLRP Latitude field */
    inline void
    setLatitude (
      llrp_s32_t  value)
    {
        m_Latitude = value;
    }


  protected:
    llrp_s32_t m_Altitude;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdAltitude;
//@}

    /** @brief Get accessor functions for the LLRP Altitude field */
    inline llrp_s32_t
    getAltitude (void)
    {
        return m_Altitude;
    }

    /** @brief Set accessor functions for the LLRP Altitude field */
    inline void
    setAltitude (
      llrp_s32_t  value)
    {
        m_Altitude = value;
    }


};


/**
 ** @brief  Class Definition CBdsLocation for LLRP parameter BdsLocation
 **





 **/

class CBdsLocation : public CParameter
{
  public:
    CBdsLocation (void);
    ~CBdsLocation (void);

/** @name Internal Framework Functions */
//@{

    static const CFieldDescriptor * const
    s_apFieldDescriptorTable[];

    static const CTypeDescriptor
    s_typeDescriptor;

    void
    decodeFields (
      CDecoderStream *          pDecoderStream);

    void
    assimilateSubParameters (
      CErrorDetails *           pError);

    void
    encode (
      CEncoderStream *          pEncoderStream) const;



    static CElement *
    s_construct (void);

    static void
    s_decodeFields (
      CDecoderStream *          pDecoderStream,
      CElement *                pElement);
//@}


  protected:
    llrp_s32_t m_Longitude;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdLongitude;
//@}

    /** @brief Get accessor functions for the LLRP Longitude field */
    inline llrp_s32_t
    getLongitude (void)
    {
        return m_Longitude;
    }

    /** @brief Set accessor functions for the LLRP Longitude field */
    inline void
    setLongitude (
      llrp_s32_t  value)
    {
        m_Longitude = value;
    }


  protected:
    llrp_s32_t m_Latitude;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdLatitude;
//@}

    /** @brief Get accessor functions for the LLRP Latitude field */
    inline llrp_s32_t
    getLatitude (void)
    {
        return m_Latitude;
    }

    /** @brief Set accessor functions for the LLRP Latitude field */
    inline void
    setLatitude (
      llrp_s32_t  value)
    {
        m_Latitude = value;
    }


  protected:
    llrp_s32_t m_Altitude;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdAltitude;
//@}

    /** @brief Get accessor functions for the LLRP Altitude field */
    inline llrp_s32_t
    getAltitude (void)
    {
        return m_Altitude;
    }

    /** @brief Set accessor functions for the LLRP Altitude field */
    inline void
    setAltitude (
      llrp_s32_t  value)
    {
        m_Altitude = value;
    }


};


/*@}*/

class CEthernetConfiguration
{
/** @name Internal Framework Functions */
//@{
  public:
    static const CTypeDescriptor
    s_typeDescriptor;

    static llrp_bool_t
    isMember (
      CParameter *              pParameter);
//@}

};

class CDiagnosticTestResultData
{
/** @name Internal Framework Functions */
//@{
  public:
    static const CTypeDescriptor
    s_typeDescriptor;

    static llrp_bool_t
    isMember (
      CParameter *              pParameter);
//@}

};

class CLocationInfo
{
/** @name Internal Framework Functions */
//@{
  public:
    static const CTypeDescriptor
    s_typeDescriptor;

    static llrp_bool_t
    isMember (
      CParameter *              pParameter);
//@}

};


/** @brief Enrolls the types for Core into the LTKCPP registry
 **
 ** LTKCPP needs an internal registry for storing all the type information.  This function
 ** is required to enroll the types for the Core into
 ** the operating registry.
 **
 ** For example -- in order to decode and encode packets from the core LLRP specification
 ** The user must EnrollCoreTypesIntoRegistry.
 **
 ** @ingroup LTKCoreElement
 */
extern void
enrollCoreTypesIntoRegistry (
  CTypeRegistry *               pTypeRegistry);

  
}; //end of namespace LLRP

#endif 
