#include "LLRP_NET.h"

#include "LLRP_General.h"
#include "LLRP_Capabilities.h"
#include "LLRP_Operation.h"
namespace LLRP
{

/*
 * Generated file - DO NOT EDIT
 *
 * This is the header file for the LLRP Tool Kit (LTK)
 * C++ (aka cpp) implementation. It is generated into a .inc file
 * that is included by a platform specific .cpp source file.
 * That .cpp file takes care of prerequisites needed by this file.
 */



/*
 * Vendor descriptors
 */


/*
 * Namespace descriptors
 */


/*
 * Enumeration string tables
 */


const SEnumTableEntry
g_estEventNotificationStateEventType[] =
{

    {
        "GPI",
        EventNotificationStateEventType_GPI,
    },
    {
        "CHOSESPEC",
        EventNotificationStateEventType_CHOSESPEC,
    },
    {
        "ANTENNASPEC",
        EventNotificationStateEventType_ANTENNASPEC,
    },
    {
        "ANTENNASTATE",
        EventNotificationStateEventType_ANTENNASTATE,
    },
    { 0, 0 }
};


const SEnumTableEntry
g_estEventNotificationStateNotificationState[] =
{

    {
        "NOTIFY",
        EventNotificationStateNotificationState_NOTIFY,
    },
    {
        "NOT_NOTIFY",
        EventNotificationStateNotificationState_NOT_NOTIFY,
    },
    { 0, 0 }
};


const SEnumTableEntry
g_estAntennaPropertiesAntennaConnected[] =
{

    {
        "NOT_CONNECT",
        AntennaPropertiesAntennaConnected_NOT_CONNECT,
    },
    {
        "CONNECT",
        AntennaPropertiesAntennaConnected_CONNECT,
    },
    { 0, 0 }
};


const SEnumTableEntry
g_estLinkType[] =
{

    {
        "TCP",
        LinkType_TCP,
    },
    {
        "RS232",
        LinkType_RS232,
    },
    {
        "RS485",
        LinkType_RS485,
    },
    {
        "HTTP",
        LinkType_HTTP,
    },
    { 0, 0 }
};


const SEnumTableEntry
g_estKeepaliveTriggerType[] =
{

    {
        "NON_HEART_BEAT",
        KeepaliveTriggerType_NON_HEART_BEAT,
    },
    {
        "PERIODIC_HEART_BEAT",
        KeepaliveTriggerType_PERIODIC_HEART_BEAT,
    },
    { 0, 0 }
};


const SEnumTableEntry
g_estCommMode[] =
{

    {
        "CLIENT_MODE",
        CommMode_CLIENT_MODE,
    },
    {
        "SERVER_MODE",
        CommMode_SERVER_MODE,
    },
    {
        "MIXED_MODE",
        CommMode_MIXED_MODE,
    },
    { 0, 0 }
};


const SEnumTableEntry
g_estIPAddressVersion[] =
{

    {
        "IPV4",
        IPAddressVersion_IPV4,
    },
    {
        "IPV6",
        IPAddressVersion_IPV6,
    },
    { 0, 0 }
};


const SEnumTableEntry
g_estVersionInfoUsedOrSpare[] =
{

    {
        "PRIMARY_USE",
        VersionInfoUsedOrSpare_PRIMARY_USE,
    },
    {
        "BACK_UP",
        VersionInfoUsedOrSpare_BACK_UP,
    },
    { 0, 0 }
};


const SEnumTableEntry
g_estVersionInfoSetUse[] =
{

    {
        "ACTIVE",
        VersionInfoSetUse_ACTIVE,
    },
    {
        "INACTIVE",
        VersionInfoSetUse_INACTIVE,
    },
    { 0, 0 }
};


const SEnumTableEntry
g_estVersionInfoHasRun[] =
{

    {
        "RUN",
        VersionInfoHasRun_RUN,
    },
    {
        "NOT_RUN",
        VersionInfoHasRun_NOT_RUN,
    },
    { 0, 0 }
};


const SEnumTableEntry
g_estVersionInfoCanRun[] =
{

    {
        "CAN",
        VersionInfoCanRun_CAN,
    },
    {
        "CAN_NOT",
        VersionInfoCanRun_CAN_NOT,
    },
    { 0, 0 }
};


const SEnumTableEntry
g_estVersionDownloadServerType[] =
{

    {
        "FTP",
        VersionDownloadServerType_FTP,
    },
    {
        "TFTP",
        VersionDownloadServerType_TFTP,
    },
    { 0, 0 }
};


const SEnumTableEntry
g_estAlarmReportInfoAlarmReportLevel[] =
{

    {
        "FATAL",
        AlarmReportInfoAlarmReportLevel_FATAL,
    },
    {
        "SEVER",
        AlarmReportInfoAlarmReportLevel_SEVER,
    },
    {
        "GENERAL",
        AlarmReportInfoAlarmReportLevel_GENERAL,
    },
    {
        "SLIGHT",
        AlarmReportInfoAlarmReportLevel_SLIGHT,
    },
    {
        "NOTICE",
        AlarmReportInfoAlarmReportLevel_NOTICE,
    },
    { 0, 0 }
};


const SEnumTableEntry
g_estDiagnosticTestResultAntennaConnected[] =
{

    {
        "NOT_IN",
        DiagnosticTestResultAntennaConnected_NOT_IN,
    },
    {
        "IN",
        DiagnosticTestResultAntennaConnected_IN,
    },
    { 0, 0 }
};


const SEnumTableEntry
g_estUploadTagLogUploadType[] =
{

    {
        "SERIAL_NUMBER",
        UploadTagLogUploadType_SERIAL_NUMBER,
    },
    {
        "TIME",
        UploadTagLogUploadType_TIME,
    },
    { 0, 0 }
};


const SEnumTableEntry
g_estUploadDeviceLogType[] =
{

    {
        "SERIAL_NUMBER",
        UploadDeviceLogType_SERIAL_NUMBER,
    },
    {
        "SERIAL_TIME",
        UploadDeviceLogType_SERIAL_TIME,
    },
    {
        "FIX_TIME",
        UploadDeviceLogType_FIX_TIME,
    },
    { 0, 0 }
};


const SEnumTableEntry
g_estGetDeviceConfigRequestedData[] =
{

    {
        "ALL_CONFIG",
        GetDeviceConfigRequestedData_ALL_CONFIG,
    },
    {
        "DEVICE_UNIQUE_ID",
        GetDeviceConfigRequestedData_DEVICE_UNIQUE_ID,
    },
    {
        "DEVICE_EVENT_NOTICE_CONFIG",
        GetDeviceConfigRequestedData_DEVICE_EVENT_NOTICE_CONFIG,
    },
    {
        "WARN_CONFIG",
        GetDeviceConfigRequestedData_WARN_CONFIG,
    },
    {
        "ANTENNA_ATTRIBUTE_CONFIG",
        GetDeviceConfigRequestedData_ANTENNA_ATTRIBUTE_CONFIG,
    },
    {
        "ANTENNA_PROTOCOL_CONFIG",
        GetDeviceConfigRequestedData_ANTENNA_PROTOCOL_CONFIG,
    },
    {
        "MODULATION_DEPTH_CONFIG",
        GetDeviceConfigRequestedData_MODULATION_DEPTH_CONFIG,
    },
    {
        "TAG_CHOOSE_REPORT_SPEC_CONFIG",
        GetDeviceConfigRequestedData_TAG_CHOOSE_REPORT_SPEC_CONFIG,
    },
    {
        "TAG_OPERATE_REPORT_SPEC_CONFIG",
        GetDeviceConfigRequestedData_TAG_OPERATE_REPORT_SPEC_CONFIG,
    },
    {
        "COMMUNICATE_CONFIG",
        GetDeviceConfigRequestedData_COMMUNICATE_CONFIG,
    },
    { 0, 0 }
};


const SEnumTableEntry
g_estSetDeviceConfigResetToFactoryDefault[] =
{

    {
        "NO_RESTORE",
        SetDeviceConfigResetToFactoryDefault_NO_RESTORE,
    },
    {
        "RESTORE",
        SetDeviceConfigResetToFactoryDefault_RESTORE,
    },
    { 0, 0 }
};


const SEnumTableEntry
g_estGetVersionVerType[] =
{

    {
        "READER_BOOT_VER",
        GetVersionVerType_READER_BOOT_VER,
    },
    {
        "READER_SYSTEM_VER",
        GetVersionVerType_READER_SYSTEM_VER,
    },
    {
        "SECURITY_MODULE_SYSTEM_VER",
        GetVersionVerType_SECURITY_MODULE_SYSTEM_VER,
    },
    {
        "SECURITY_CHIP_SYSTEM_VER",
        GetVersionVerType_SECURITY_CHIP_SYSTEM_VER,
    },
    { 0, 0 }
};


const SEnumTableEntry
g_estSetVersionVerType[] =
{

    {
        "READER_BOOT_VER",
        SetVersionVerType_READER_BOOT_VER,
    },
    {
        "READER_SYSTEM_VER",
        SetVersionVerType_READER_SYSTEM_VER,
    },
    {
        "SECURITY_MODULE_SYSTEM_VER",
        SetVersionVerType_SECURITY_MODULE_SYSTEM_VER,
    },
    {
        "SECURITY_CHIP_SYSTEM_VER",
        SetVersionVerType_SECURITY_CHIP_SYSTEM_VER,
    },
    { 0, 0 }
};


const SEnumTableEntry
g_estActiveVersionVerType[] =
{

    {
        "READER_BOOT_VER",
        ActiveVersionVerType_READER_BOOT_VER,
    },
    {
        "READER_SYSTEM_VER",
        ActiveVersionVerType_READER_SYSTEM_VER,
    },
    {
        "SECURITY_MODULE_SYSTEM_VER",
        ActiveVersionVerType_SECURITY_MODULE_SYSTEM_VER,
    },
    {
        "SECURITY_CHIP_SYSTEM_VER",
        ActiveVersionVerType_SECURITY_CHIP_SYSTEM_VER,
    },
    { 0, 0 }
};


const SEnumTableEntry
g_estUnActiveVersionVerType[] =
{

    {
        "READER_BOOT_VER",
        UnActiveVersionVerType_READER_BOOT_VER,
    },
    {
        "READER_SYSTEM_VER",
        UnActiveVersionVerType_READER_SYSTEM_VER,
    },
    {
        "SECURITY_MODULE_SYSTEM_VER",
        UnActiveVersionVerType_SECURITY_MODULE_SYSTEM_VER,
    },
    {
        "SECURITY_CHIP_SYSTEM_VER",
        UnActiveVersionVerType_SECURITY_CHIP_SYSTEM_VER,
    },
    { 0, 0 }
};


const SEnumTableEntry
g_estLocationType[] =
{

    {
        "GPS",
        LocationType_GPS,
    },
    {
        "BDS",
        LocationType_BDS,
    },
    { 0, 0 }
};




/*
*****************************************************************
**
** Message DeviceBinding
**
*****************************************************************
*/


const CTypeDescriptor
CDeviceBinding::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "DeviceBinding",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    600,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CDeviceBinding::s_apFieldDescriptorTable[] =
{

    &s_fdBindingType,
    &s_fdBindingData,
    NULL
};



const CFieldDescriptor
CDeviceBinding::s_fdBindingType =
{
    CFieldDescriptor::FT_U8,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "BindingType",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CDeviceBinding::s_fdBindingData =
{
    CFieldDescriptor::FT_U8V,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "BindingData",	// m_pName
    NULL	// m_pEnumTable
};
CDeviceBinding::CDeviceBinding (void)
{
    m_pType = &s_typeDescriptor;

    m_BindingType = 0;
}

CDeviceBinding::~CDeviceBinding (void)
{
}


CElement *
CDeviceBinding::s_construct (void)
{
    return (CElement *) new CDeviceBinding();
}


void
CDeviceBinding::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CDeviceBinding * pTarget = (CDeviceBinding *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_BindingType = pDecoderStream->get_u8(&s_fdBindingType);
    }
    else
    {
        pDecoderStream->get_u8(&s_fdBindingType);
    }

    if(NULL != pTarget)
    {
        pTarget->m_BindingData = pDecoderStream->get_u8v(&s_fdBindingData);
    }
    else
    {
        pDecoderStream->get_u8v(&s_fdBindingData);
    }

}


void
CDeviceBinding::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CDeviceBinding::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


void
CDeviceBinding::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u8(m_BindingType, &s_fdBindingType);

    pEncoderStream->put_u8v(m_BindingData, &s_fdBindingData);

}




/*
*****************************************************************
**
** Message DeviceBindingAck
**
*****************************************************************
*/


const CTypeDescriptor
CDeviceBindingAck::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "DeviceBindingAck",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    601,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CDeviceBindingAck::s_apFieldDescriptorTable[] =
{

    &s_fdBindingData,
    NULL
};



const CFieldDescriptor
CDeviceBindingAck::s_fdBindingData =
{
    CFieldDescriptor::FT_U8V,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "BindingData",	// m_pName
    NULL	// m_pEnumTable
};
CDeviceBindingAck::CDeviceBindingAck (void)
{
    m_pType = &s_typeDescriptor;

    m_pStatus = NULL;
}

CDeviceBindingAck::~CDeviceBindingAck (void)
{
}


CElement *
CDeviceBindingAck::s_construct (void)
{
    return (CElement *) new CDeviceBindingAck();
}


void
CDeviceBindingAck::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CDeviceBindingAck * pTarget = (CDeviceBindingAck *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_BindingData = pDecoderStream->get_u8v(&s_fdBindingData);
    }
    else
    {
        pDecoderStream->get_u8v(&s_fdBindingData);
    }

}


void
CDeviceBindingAck::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CDeviceBindingAck::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    // 1 of Status
    pType = &CStatus::s_typeDescriptor;

    if(Cur == End || (*Cur)->m_pType != pType)
    {
        goto missing;
    }
    m_pStatus = (CStatus *)*Cur++;


    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


EResultCode
CDeviceBindingAck::setStatus (
  CStatus *     pValue)
{
    removeSubParameterFromAllList(m_pStatus);
    delete m_pStatus;
    m_pStatus = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CDeviceBindingAck::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u8v(m_BindingData, &s_fdBindingData);

    pType = &CStatus::s_typeDescriptor;

    pEncoderStream->putRequiredSubParameter(m_pStatus, pType);

}




/*
*****************************************************************
**
** Message DeviceCertificateConfig
**
*****************************************************************
*/


const CTypeDescriptor
CDeviceCertificateConfig::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "DeviceCertificateConfig",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    602,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CDeviceCertificateConfig::s_apFieldDescriptorTable[] =
{

    &s_fdCertificateData,
    &s_fdUserData,
    NULL
};



const CFieldDescriptor
CDeviceCertificateConfig::s_fdCertificateData =
{
    CFieldDescriptor::FT_U8V,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "CertificateData",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CDeviceCertificateConfig::s_fdUserData =
{
    CFieldDescriptor::FT_U8V,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "UserData",	// m_pName
    NULL	// m_pEnumTable
};
CDeviceCertificateConfig::CDeviceCertificateConfig (void)
{
    m_pType = &s_typeDescriptor;

}

CDeviceCertificateConfig::~CDeviceCertificateConfig (void)
{
}


CElement *
CDeviceCertificateConfig::s_construct (void)
{
    return (CElement *) new CDeviceCertificateConfig();
}


void
CDeviceCertificateConfig::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CDeviceCertificateConfig * pTarget = (CDeviceCertificateConfig *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_CertificateData = pDecoderStream->get_u8v(&s_fdCertificateData);
    }
    else
    {
        pDecoderStream->get_u8v(&s_fdCertificateData);
    }

    if(NULL != pTarget)
    {
        pTarget->m_UserData = pDecoderStream->get_u8v(&s_fdUserData);
    }
    else
    {
        pDecoderStream->get_u8v(&s_fdUserData);
    }

}


void
CDeviceCertificateConfig::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CDeviceCertificateConfig::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


void
CDeviceCertificateConfig::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u8v(m_CertificateData, &s_fdCertificateData);

    pEncoderStream->put_u8v(m_UserData, &s_fdUserData);

}




/*
*****************************************************************
**
** Message DeviceCertificateConfigAck
**
*****************************************************************
*/


const CTypeDescriptor
CDeviceCertificateConfigAck::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "DeviceCertificateConfigAck",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    603,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CDeviceCertificateConfigAck::s_apFieldDescriptorTable[] =
{

    NULL
};

CDeviceCertificateConfigAck::CDeviceCertificateConfigAck (void)
{
    m_pType = &s_typeDescriptor;

    m_pStatus = NULL;
}

CDeviceCertificateConfigAck::~CDeviceCertificateConfigAck (void)
{
}


CElement *
CDeviceCertificateConfigAck::s_construct (void)
{
    return (CElement *) new CDeviceCertificateConfigAck();
}


void
CDeviceCertificateConfigAck::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CDeviceCertificateConfigAck * pTarget = (CDeviceCertificateConfigAck *) pTargetElement;


}


void
CDeviceCertificateConfigAck::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CDeviceCertificateConfigAck::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    // 1 of Status
    pType = &CStatus::s_typeDescriptor;

    if(Cur == End || (*Cur)->m_pType != pType)
    {
        goto missing;
    }
    m_pStatus = (CStatus *)*Cur++;


    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


EResultCode
CDeviceCertificateConfigAck::setStatus (
  CStatus *     pValue)
{
    removeSubParameterFromAllList(m_pStatus);
    delete m_pStatus;
    m_pStatus = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CDeviceCertificateConfigAck::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pType = &CStatus::s_typeDescriptor;

    pEncoderStream->putRequiredSubParameter(m_pStatus, pType);

}




/*
*****************************************************************
**
** Message DeviceBindingResultNotification
**
*****************************************************************
*/


const CTypeDescriptor
CDeviceBindingResultNotification::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "DeviceBindingResultNotification",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    604,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CDeviceBindingResultNotification::s_apFieldDescriptorTable[] =
{

    NULL
};

CDeviceBindingResultNotification::CDeviceBindingResultNotification (void)
{
    m_pType = &s_typeDescriptor;

    m_pStatus = NULL;
}

CDeviceBindingResultNotification::~CDeviceBindingResultNotification (void)
{
}


CElement *
CDeviceBindingResultNotification::s_construct (void)
{
    return (CElement *) new CDeviceBindingResultNotification();
}


void
CDeviceBindingResultNotification::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CDeviceBindingResultNotification * pTarget = (CDeviceBindingResultNotification *) pTargetElement;


}


void
CDeviceBindingResultNotification::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CDeviceBindingResultNotification::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    // 1 of Status
    pType = &CStatus::s_typeDescriptor;

    if(Cur == End || (*Cur)->m_pType != pType)
    {
        goto missing;
    }
    m_pStatus = (CStatus *)*Cur++;


    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


EResultCode
CDeviceBindingResultNotification::setStatus (
  CStatus *     pValue)
{
    removeSubParameterFromAllList(m_pStatus);
    delete m_pStatus;
    m_pStatus = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CDeviceBindingResultNotification::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pType = &CStatus::s_typeDescriptor;

    pEncoderStream->putRequiredSubParameter(m_pStatus, pType);

}




/*
*****************************************************************
**
** Message UploadTagLog
**
*****************************************************************
*/


const CTypeDescriptor
CUploadTagLog::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "UploadTagLog",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    620,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CUploadTagLog::s_apFieldDescriptorTable[] =
{

    &s_fdUploadType,
    &s_fdUploadCount,
    &s_fdMilliseconds,
    NULL
};



const CFieldDescriptor
CUploadTagLog::s_fdUploadType =
{
    CFieldDescriptor::FT_E8,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "UploadType",	// m_pName
    g_estUploadTagLogUploadType	// m_pEnumTable
};


const CFieldDescriptor
CUploadTagLog::s_fdUploadCount =
{
    CFieldDescriptor::FT_U32,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "UploadCount",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CUploadTagLog::s_fdMilliseconds =
{
    CFieldDescriptor::FT_U32,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "Milliseconds",	// m_pName
    NULL	// m_pEnumTable
};
CUploadTagLog::CUploadTagLog (void)
{
    m_pType = &s_typeDescriptor;

    m_EUploadType = (EUploadTagLogUploadType) 0;
    m_UploadCount = 0;
    m_Milliseconds = 0;
    m_pStartLogTimestamp = NULL;
    m_pEndLogTimestamp = NULL;
}

CUploadTagLog::~CUploadTagLog (void)
{
}


CElement *
CUploadTagLog::s_construct (void)
{
    return (CElement *) new CUploadTagLog();
}


void
CUploadTagLog::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CUploadTagLog * pTarget = (CUploadTagLog *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_EUploadType = (EUploadTagLogUploadType) pDecoderStream->get_e8(&s_fdUploadType);
    }
    else
    {
        pDecoderStream->get_e8(&s_fdUploadType);
    }

    if(NULL != pTarget)
    {
        pTarget->m_UploadCount = pDecoderStream->get_u32(&s_fdUploadCount);
    }
    else
    {
        pDecoderStream->get_u32(&s_fdUploadCount);
    }

    if(NULL != pTarget)
    {
        pTarget->m_Milliseconds = pDecoderStream->get_u32(&s_fdMilliseconds);
    }
    else
    {
        pDecoderStream->get_u32(&s_fdMilliseconds);
    }

}


void
CUploadTagLog::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CUploadTagLog::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    // 0-1 of StartLogTimestamp
    pType = &CStartLogTimestamp::s_typeDescriptor;

    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pStartLogTimestamp = (CStartLogTimestamp *)*Cur++;
    }


    // 0-1 of EndLogTimestamp
    pType = &CEndLogTimestamp::s_typeDescriptor;

    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pEndLogTimestamp = (CEndLogTimestamp *)*Cur++;
    }


    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


EResultCode
CUploadTagLog::setStartLogTimestamp (
  CStartLogTimestamp *     pValue)
{
    removeSubParameterFromAllList(m_pStartLogTimestamp);
    delete m_pStartLogTimestamp;
    m_pStartLogTimestamp = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CUploadTagLog::setEndLogTimestamp (
  CEndLogTimestamp *     pValue)
{
    removeSubParameterFromAllList(m_pEndLogTimestamp);
    delete m_pEndLogTimestamp;
    m_pEndLogTimestamp = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CUploadTagLog::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_e8((int)m_EUploadType, &s_fdUploadType);

    pEncoderStream->put_u32(m_UploadCount, &s_fdUploadCount);

    pEncoderStream->put_u32(m_Milliseconds, &s_fdMilliseconds);

    pType = &CStartLogTimestamp::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameter(m_pStartLogTimestamp, pType);

    pType = &CEndLogTimestamp::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameter(m_pEndLogTimestamp, pType);

}




/*
*****************************************************************
**
** Message UploadTagLogAck
**
*****************************************************************
*/


const CTypeDescriptor
CUploadTagLogAck::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "UploadTagLogAck",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    621,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CUploadTagLogAck::s_apFieldDescriptorTable[] =
{

    &s_fdSequenceId,
    &s_fdIsLastedFrame,
    NULL
};



const CFieldDescriptor
CUploadTagLogAck::s_fdSequenceId =
{
    CFieldDescriptor::FT_U16,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "SequenceId",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CUploadTagLogAck::s_fdIsLastedFrame =
{
    CFieldDescriptor::FT_U8,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "IsLastedFrame",	// m_pName
    NULL	// m_pEnumTable
};
CUploadTagLogAck::CUploadTagLogAck (void)
{
    m_pType = &s_typeDescriptor;

    m_SequenceId = 0;
    m_IsLastedFrame = 0;
    m_pStatus = NULL;
}

CUploadTagLogAck::~CUploadTagLogAck (void)
{
}


CElement *
CUploadTagLogAck::s_construct (void)
{
    return (CElement *) new CUploadTagLogAck();
}


void
CUploadTagLogAck::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CUploadTagLogAck * pTarget = (CUploadTagLogAck *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_SequenceId = pDecoderStream->get_u16(&s_fdSequenceId);
    }
    else
    {
        pDecoderStream->get_u16(&s_fdSequenceId);
    }

    if(NULL != pTarget)
    {
        pTarget->m_IsLastedFrame = pDecoderStream->get_u8(&s_fdIsLastedFrame);
    }
    else
    {
        pDecoderStream->get_u8(&s_fdIsLastedFrame);
    }

}


void
CUploadTagLogAck::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CUploadTagLogAck::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    // 1 of Status
    pType = &CStatus::s_typeDescriptor;

    if(Cur == End || (*Cur)->m_pType != pType)
    {
        goto missing;
    }
    m_pStatus = (CStatus *)*Cur++;


    // 0-N of TagLog
    pType = &CTagLog::s_typeDescriptor;

    while(Cur != End && (*Cur)->m_pType == pType)
    {
        m_listTagLog.push_back((CTagLog *)*Cur);
        Cur++;
    }


    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


EResultCode
CUploadTagLogAck::setStatus (
  CStatus *     pValue)
{
    removeSubParameterFromAllList(m_pStatus);
    delete m_pStatus;
    m_pStatus = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CUploadTagLogAck::addTagLog (
  CTagLog *     pValue)
{
    m_listTagLog.push_back(pValue);
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CUploadTagLogAck::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u16(m_SequenceId, &s_fdSequenceId);

    pEncoderStream->put_u8(m_IsLastedFrame, &s_fdIsLastedFrame);

    pType = &CStatus::s_typeDescriptor;

    pEncoderStream->putRequiredSubParameter(m_pStatus, pType);

    pType = &CTagLog::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameterList((tListOfParameters *) &m_listTagLog, pType);

}




/*
*****************************************************************
**
** Message ClearTagLog
**
*****************************************************************
*/


const CTypeDescriptor
CClearTagLog::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "ClearTagLog",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    622,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CClearTagLog::s_apFieldDescriptorTable[] =
{

    NULL
};

CClearTagLog::CClearTagLog (void)
{
    m_pType = &s_typeDescriptor;

}

CClearTagLog::~CClearTagLog (void)
{
}


CElement *
CClearTagLog::s_construct (void)
{
    return (CElement *) new CClearTagLog();
}


void
CClearTagLog::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CClearTagLog * pTarget = (CClearTagLog *) pTargetElement;


}


void
CClearTagLog::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CClearTagLog::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


void
CClearTagLog::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


}




/*
*****************************************************************
**
** Message ClearTagLogAck
**
*****************************************************************
*/


const CTypeDescriptor
CClearTagLogAck::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "ClearTagLogAck",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    623,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CClearTagLogAck::s_apFieldDescriptorTable[] =
{

    NULL
};

CClearTagLogAck::CClearTagLogAck (void)
{
    m_pType = &s_typeDescriptor;

    m_pStatus = NULL;
}

CClearTagLogAck::~CClearTagLogAck (void)
{
}


CElement *
CClearTagLogAck::s_construct (void)
{
    return (CElement *) new CClearTagLogAck();
}


void
CClearTagLogAck::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CClearTagLogAck * pTarget = (CClearTagLogAck *) pTargetElement;


}


void
CClearTagLogAck::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CClearTagLogAck::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    // 1 of Status
    pType = &CStatus::s_typeDescriptor;

    if(Cur == End || (*Cur)->m_pType != pType)
    {
        goto missing;
    }
    m_pStatus = (CStatus *)*Cur++;


    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


EResultCode
CClearTagLogAck::setStatus (
  CStatus *     pValue)
{
    removeSubParameterFromAllList(m_pStatus);
    delete m_pStatus;
    m_pStatus = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CClearTagLogAck::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pType = &CStatus::s_typeDescriptor;

    pEncoderStream->putRequiredSubParameter(m_pStatus, pType);

}




/*
*****************************************************************
**
** Message TagLogCount
**
*****************************************************************
*/


const CTypeDescriptor
CTagLogCount::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "TagLogCount",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    624,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CTagLogCount::s_apFieldDescriptorTable[] =
{

    NULL
};

CTagLogCount::CTagLogCount (void)
{
    m_pType = &s_typeDescriptor;

}

CTagLogCount::~CTagLogCount (void)
{
}


CElement *
CTagLogCount::s_construct (void)
{
    return (CElement *) new CTagLogCount();
}


void
CTagLogCount::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CTagLogCount * pTarget = (CTagLogCount *) pTargetElement;


}


void
CTagLogCount::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CTagLogCount::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


void
CTagLogCount::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


}




/*
*****************************************************************
**
** Message TagLogCountAck
**
*****************************************************************
*/


const CTypeDescriptor
CTagLogCountAck::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "TagLogCountAck",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    625,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CTagLogCountAck::s_apFieldDescriptorTable[] =
{

    &s_fdLogCount,
    NULL
};



const CFieldDescriptor
CTagLogCountAck::s_fdLogCount =
{
    CFieldDescriptor::FT_U32,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "LogCount",	// m_pName
    NULL	// m_pEnumTable
};
CTagLogCountAck::CTagLogCountAck (void)
{
    m_pType = &s_typeDescriptor;

    m_LogCount = 0;
    m_pStatus = NULL;
}

CTagLogCountAck::~CTagLogCountAck (void)
{
}


CElement *
CTagLogCountAck::s_construct (void)
{
    return (CElement *) new CTagLogCountAck();
}


void
CTagLogCountAck::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CTagLogCountAck * pTarget = (CTagLogCountAck *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_LogCount = pDecoderStream->get_u32(&s_fdLogCount);
    }
    else
    {
        pDecoderStream->get_u32(&s_fdLogCount);
    }

}


void
CTagLogCountAck::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CTagLogCountAck::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    // 1 of Status
    pType = &CStatus::s_typeDescriptor;

    if(Cur == End || (*Cur)->m_pType != pType)
    {
        goto missing;
    }
    m_pStatus = (CStatus *)*Cur++;


    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


EResultCode
CTagLogCountAck::setStatus (
  CStatus *     pValue)
{
    removeSubParameterFromAllList(m_pStatus);
    delete m_pStatus;
    m_pStatus = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CTagLogCountAck::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u32(m_LogCount, &s_fdLogCount);

    pType = &CStatus::s_typeDescriptor;

    pEncoderStream->putRequiredSubParameter(m_pStatus, pType);

}




/*
*****************************************************************
**
** Message UploadTagLogConfirm
**
*****************************************************************
*/


const CTypeDescriptor
CUploadTagLogConfirm::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "UploadTagLogConfirm",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    626,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CUploadTagLogConfirm::s_apFieldDescriptorTable[] =
{

    &s_fdSequenceId,
    NULL
};



const CFieldDescriptor
CUploadTagLogConfirm::s_fdSequenceId =
{
    CFieldDescriptor::FT_U16,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "SequenceId",	// m_pName
    NULL	// m_pEnumTable
};
CUploadTagLogConfirm::CUploadTagLogConfirm (void)
{
    m_pType = &s_typeDescriptor;

    m_SequenceId = 0;
}

CUploadTagLogConfirm::~CUploadTagLogConfirm (void)
{
}


CElement *
CUploadTagLogConfirm::s_construct (void)
{
    return (CElement *) new CUploadTagLogConfirm();
}


void
CUploadTagLogConfirm::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CUploadTagLogConfirm * pTarget = (CUploadTagLogConfirm *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_SequenceId = pDecoderStream->get_u16(&s_fdSequenceId);
    }
    else
    {
        pDecoderStream->get_u16(&s_fdSequenceId);
    }

}


void
CUploadTagLogConfirm::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CUploadTagLogConfirm::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


void
CUploadTagLogConfirm::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u16(m_SequenceId, &s_fdSequenceId);

}




/*
*****************************************************************
**
** Message UploadDeviceLog
**
*****************************************************************
*/


const CTypeDescriptor
CUploadDeviceLog::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "UploadDeviceLog",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    640,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CUploadDeviceLog::s_apFieldDescriptorTable[] =
{

    &s_fdUploadType,
    &s_fdUploadCount,
    &s_fdMilliseconds,
    NULL
};



const CFieldDescriptor
CUploadDeviceLog::s_fdUploadType =
{
    CFieldDescriptor::FT_E8,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "UploadType",	// m_pName
    g_estUploadDeviceLogType	// m_pEnumTable
};


const CFieldDescriptor
CUploadDeviceLog::s_fdUploadCount =
{
    CFieldDescriptor::FT_U32,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "UploadCount",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CUploadDeviceLog::s_fdMilliseconds =
{
    CFieldDescriptor::FT_U32,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "Milliseconds",	// m_pName
    NULL	// m_pEnumTable
};
CUploadDeviceLog::CUploadDeviceLog (void)
{
    m_pType = &s_typeDescriptor;

    m_EUploadType = (EUploadDeviceLogType) 0;
    m_UploadCount = 0;
    m_Milliseconds = 0;
    m_pStartLogTimestamp = NULL;
    m_pEndLogTimestamp = NULL;
}

CUploadDeviceLog::~CUploadDeviceLog (void)
{
}


CElement *
CUploadDeviceLog::s_construct (void)
{
    return (CElement *) new CUploadDeviceLog();
}


void
CUploadDeviceLog::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CUploadDeviceLog * pTarget = (CUploadDeviceLog *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_EUploadType = (EUploadDeviceLogType) pDecoderStream->get_e8(&s_fdUploadType);
    }
    else
    {
        pDecoderStream->get_e8(&s_fdUploadType);
    }

    if(NULL != pTarget)
    {
        pTarget->m_UploadCount = pDecoderStream->get_u32(&s_fdUploadCount);
    }
    else
    {
        pDecoderStream->get_u32(&s_fdUploadCount);
    }

    if(NULL != pTarget)
    {
        pTarget->m_Milliseconds = pDecoderStream->get_u32(&s_fdMilliseconds);
    }
    else
    {
        pDecoderStream->get_u32(&s_fdMilliseconds);
    }

}


void
CUploadDeviceLog::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CUploadDeviceLog::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    // 0-1 of StartLogTimestamp
    pType = &CStartLogTimestamp::s_typeDescriptor;

    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pStartLogTimestamp = (CStartLogTimestamp *)*Cur++;
    }


    // 0-1 of EndLogTimestamp
    pType = &CEndLogTimestamp::s_typeDescriptor;

    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pEndLogTimestamp = (CEndLogTimestamp *)*Cur++;
    }


    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


EResultCode
CUploadDeviceLog::setStartLogTimestamp (
  CStartLogTimestamp *     pValue)
{
    removeSubParameterFromAllList(m_pStartLogTimestamp);
    delete m_pStartLogTimestamp;
    m_pStartLogTimestamp = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CUploadDeviceLog::setEndLogTimestamp (
  CEndLogTimestamp *     pValue)
{
    removeSubParameterFromAllList(m_pEndLogTimestamp);
    delete m_pEndLogTimestamp;
    m_pEndLogTimestamp = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CUploadDeviceLog::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_e8((int)m_EUploadType, &s_fdUploadType);

    pEncoderStream->put_u32(m_UploadCount, &s_fdUploadCount);

    pEncoderStream->put_u32(m_Milliseconds, &s_fdMilliseconds);

    pType = &CStartLogTimestamp::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameter(m_pStartLogTimestamp, pType);

    pType = &CEndLogTimestamp::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameter(m_pEndLogTimestamp, pType);

}




/*
*****************************************************************
**
** Message UploadDeviceLogAck
**
*****************************************************************
*/


const CTypeDescriptor
CUploadDeviceLogAck::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "UploadDeviceLogAck",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    641,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CUploadDeviceLogAck::s_apFieldDescriptorTable[] =
{

    &s_fdSequenceId,
    &s_fdIsLastedFrame,
    NULL
};



const CFieldDescriptor
CUploadDeviceLogAck::s_fdSequenceId =
{
    CFieldDescriptor::FT_U16,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "SequenceId",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CUploadDeviceLogAck::s_fdIsLastedFrame =
{
    CFieldDescriptor::FT_U8,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "IsLastedFrame",	// m_pName
    NULL	// m_pEnumTable
};
CUploadDeviceLogAck::CUploadDeviceLogAck (void)
{
    m_pType = &s_typeDescriptor;

    m_SequenceId = 0;
    m_IsLastedFrame = 0;
    m_pStatus = NULL;
}

CUploadDeviceLogAck::~CUploadDeviceLogAck (void)
{
}


CElement *
CUploadDeviceLogAck::s_construct (void)
{
    return (CElement *) new CUploadDeviceLogAck();
}


void
CUploadDeviceLogAck::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CUploadDeviceLogAck * pTarget = (CUploadDeviceLogAck *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_SequenceId = pDecoderStream->get_u16(&s_fdSequenceId);
    }
    else
    {
        pDecoderStream->get_u16(&s_fdSequenceId);
    }

    if(NULL != pTarget)
    {
        pTarget->m_IsLastedFrame = pDecoderStream->get_u8(&s_fdIsLastedFrame);
    }
    else
    {
        pDecoderStream->get_u8(&s_fdIsLastedFrame);
    }

}


void
CUploadDeviceLogAck::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CUploadDeviceLogAck::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    // 1 of Status
    pType = &CStatus::s_typeDescriptor;

    if(Cur == End || (*Cur)->m_pType != pType)
    {
        goto missing;
    }
    m_pStatus = (CStatus *)*Cur++;


    // 0-N of DeviceLog
    pType = &CDeviceLog::s_typeDescriptor;

    while(Cur != End && (*Cur)->m_pType == pType)
    {
        m_listDeviceLog.push_back((CDeviceLog *)*Cur);
        Cur++;
    }


    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


EResultCode
CUploadDeviceLogAck::setStatus (
  CStatus *     pValue)
{
    removeSubParameterFromAllList(m_pStatus);
    delete m_pStatus;
    m_pStatus = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CUploadDeviceLogAck::addDeviceLog (
  CDeviceLog *     pValue)
{
    m_listDeviceLog.push_back(pValue);
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CUploadDeviceLogAck::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u16(m_SequenceId, &s_fdSequenceId);

    pEncoderStream->put_u8(m_IsLastedFrame, &s_fdIsLastedFrame);

    pType = &CStatus::s_typeDescriptor;

    pEncoderStream->putRequiredSubParameter(m_pStatus, pType);

    pType = &CDeviceLog::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameterList((tListOfParameters *) &m_listDeviceLog, pType);

}




/*
*****************************************************************
**
** Message ClearDeviceLog
**
*****************************************************************
*/


const CTypeDescriptor
CClearDeviceLog::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "ClearDeviceLog",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    642,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CClearDeviceLog::s_apFieldDescriptorTable[] =
{

    NULL
};

CClearDeviceLog::CClearDeviceLog (void)
{
    m_pType = &s_typeDescriptor;

}

CClearDeviceLog::~CClearDeviceLog (void)
{
}


CElement *
CClearDeviceLog::s_construct (void)
{
    return (CElement *) new CClearDeviceLog();
}


void
CClearDeviceLog::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CClearDeviceLog * pTarget = (CClearDeviceLog *) pTargetElement;


}


void
CClearDeviceLog::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CClearDeviceLog::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


void
CClearDeviceLog::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


}




/*
*****************************************************************
**
** Message ClearDeviceLogAck
**
*****************************************************************
*/


const CTypeDescriptor
CClearDeviceLogAck::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "ClearDeviceLogAck",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    643,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CClearDeviceLogAck::s_apFieldDescriptorTable[] =
{

    NULL
};

CClearDeviceLogAck::CClearDeviceLogAck (void)
{
    m_pType = &s_typeDescriptor;

    m_pStatus = NULL;
}

CClearDeviceLogAck::~CClearDeviceLogAck (void)
{
}


CElement *
CClearDeviceLogAck::s_construct (void)
{
    return (CElement *) new CClearDeviceLogAck();
}


void
CClearDeviceLogAck::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CClearDeviceLogAck * pTarget = (CClearDeviceLogAck *) pTargetElement;


}


void
CClearDeviceLogAck::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CClearDeviceLogAck::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    // 1 of Status
    pType = &CStatus::s_typeDescriptor;

    if(Cur == End || (*Cur)->m_pType != pType)
    {
        goto missing;
    }
    m_pStatus = (CStatus *)*Cur++;


    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


EResultCode
CClearDeviceLogAck::setStatus (
  CStatus *     pValue)
{
    removeSubParameterFromAllList(m_pStatus);
    delete m_pStatus;
    m_pStatus = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CClearDeviceLogAck::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pType = &CStatus::s_typeDescriptor;

    pEncoderStream->putRequiredSubParameter(m_pStatus, pType);

}




/*
*****************************************************************
**
** Message DeviceLogCount
**
*****************************************************************
*/


const CTypeDescriptor
CDeviceLogCount::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "DeviceLogCount",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    644,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CDeviceLogCount::s_apFieldDescriptorTable[] =
{

    NULL
};

CDeviceLogCount::CDeviceLogCount (void)
{
    m_pType = &s_typeDescriptor;

}

CDeviceLogCount::~CDeviceLogCount (void)
{
}


CElement *
CDeviceLogCount::s_construct (void)
{
    return (CElement *) new CDeviceLogCount();
}


void
CDeviceLogCount::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CDeviceLogCount * pTarget = (CDeviceLogCount *) pTargetElement;


}


void
CDeviceLogCount::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CDeviceLogCount::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


void
CDeviceLogCount::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


}




/*
*****************************************************************
**
** Message DeviceLogCountAck
**
*****************************************************************
*/


const CTypeDescriptor
CDeviceLogCountAck::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "DeviceLogCountAck",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    645,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CDeviceLogCountAck::s_apFieldDescriptorTable[] =
{

    &s_fdLogCount,
    NULL
};



const CFieldDescriptor
CDeviceLogCountAck::s_fdLogCount =
{
    CFieldDescriptor::FT_U32,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "LogCount",	// m_pName
    NULL	// m_pEnumTable
};
CDeviceLogCountAck::CDeviceLogCountAck (void)
{
    m_pType = &s_typeDescriptor;

    m_LogCount = 0;
    m_pStatus = NULL;
}

CDeviceLogCountAck::~CDeviceLogCountAck (void)
{
}


CElement *
CDeviceLogCountAck::s_construct (void)
{
    return (CElement *) new CDeviceLogCountAck();
}


void
CDeviceLogCountAck::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CDeviceLogCountAck * pTarget = (CDeviceLogCountAck *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_LogCount = pDecoderStream->get_u32(&s_fdLogCount);
    }
    else
    {
        pDecoderStream->get_u32(&s_fdLogCount);
    }

}


void
CDeviceLogCountAck::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CDeviceLogCountAck::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    // 1 of Status
    pType = &CStatus::s_typeDescriptor;

    if(Cur == End || (*Cur)->m_pType != pType)
    {
        goto missing;
    }
    m_pStatus = (CStatus *)*Cur++;


    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


EResultCode
CDeviceLogCountAck::setStatus (
  CStatus *     pValue)
{
    removeSubParameterFromAllList(m_pStatus);
    delete m_pStatus;
    m_pStatus = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CDeviceLogCountAck::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u32(m_LogCount, &s_fdLogCount);

    pType = &CStatus::s_typeDescriptor;

    pEncoderStream->putRequiredSubParameter(m_pStatus, pType);

}




/*
*****************************************************************
**
** Message UploadDeviceLogConfirm
**
*****************************************************************
*/


const CTypeDescriptor
CUploadDeviceLogConfirm::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "UploadDeviceLogConfirm",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    646,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CUploadDeviceLogConfirm::s_apFieldDescriptorTable[] =
{

    &s_fdSequenceId,
    NULL
};



const CFieldDescriptor
CUploadDeviceLogConfirm::s_fdSequenceId =
{
    CFieldDescriptor::FT_U16,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "SequenceId",	// m_pName
    NULL	// m_pEnumTable
};
CUploadDeviceLogConfirm::CUploadDeviceLogConfirm (void)
{
    m_pType = &s_typeDescriptor;

    m_SequenceId = 0;
}

CUploadDeviceLogConfirm::~CUploadDeviceLogConfirm (void)
{
}


CElement *
CUploadDeviceLogConfirm::s_construct (void)
{
    return (CElement *) new CUploadDeviceLogConfirm();
}


void
CUploadDeviceLogConfirm::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CUploadDeviceLogConfirm * pTarget = (CUploadDeviceLogConfirm *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_SequenceId = pDecoderStream->get_u16(&s_fdSequenceId);
    }
    else
    {
        pDecoderStream->get_u16(&s_fdSequenceId);
    }

}


void
CUploadDeviceLogConfirm::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CUploadDeviceLogConfirm::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


void
CUploadDeviceLogConfirm::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u16(m_SequenceId, &s_fdSequenceId);

}




/*
*****************************************************************
**
** Message GetDeviceConfig
**
*****************************************************************
*/


const CTypeDescriptor
CGetDeviceConfig::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "GetDeviceConfig",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    660,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CGetDeviceConfig::s_apFieldDescriptorTable[] =
{

    &s_fdRequestedData,
    &s_fdAntennaID,
    NULL
};



const CFieldDescriptor
CGetDeviceConfig::s_fdRequestedData =
{
    CFieldDescriptor::FT_E8,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "RequestedData",	// m_pName
    g_estGetDeviceConfigRequestedData	// m_pEnumTable
};


const CFieldDescriptor
CGetDeviceConfig::s_fdAntennaID =
{
    CFieldDescriptor::FT_U8,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "AntennaID",	// m_pName
    NULL	// m_pEnumTable
};
CGetDeviceConfig::CGetDeviceConfig (void)
{
    m_pType = &s_typeDescriptor;

    m_ERequestedData = (EGetDeviceConfigRequestedData) 0;
    m_AntennaID = 0;
}

CGetDeviceConfig::~CGetDeviceConfig (void)
{
}


CElement *
CGetDeviceConfig::s_construct (void)
{
    return (CElement *) new CGetDeviceConfig();
}


void
CGetDeviceConfig::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CGetDeviceConfig * pTarget = (CGetDeviceConfig *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_ERequestedData = (EGetDeviceConfigRequestedData) pDecoderStream->get_e8(&s_fdRequestedData);
    }
    else
    {
        pDecoderStream->get_e8(&s_fdRequestedData);
    }

    if(NULL != pTarget)
    {
        pTarget->m_AntennaID = pDecoderStream->get_u8(&s_fdAntennaID);
    }
    else
    {
        pDecoderStream->get_u8(&s_fdAntennaID);
    }

}


void
CGetDeviceConfig::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CGetDeviceConfig::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


void
CGetDeviceConfig::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_e8((int)m_ERequestedData, &s_fdRequestedData);

    pEncoderStream->put_u8(m_AntennaID, &s_fdAntennaID);

}




/*
*****************************************************************
**
** Message GetDeviceConfigAck
**
*****************************************************************
*/


const CTypeDescriptor
CGetDeviceConfigAck::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "GetDeviceConfigAck",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    661,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CGetDeviceConfigAck::s_apFieldDescriptorTable[] =
{

    NULL
};

CGetDeviceConfigAck::CGetDeviceConfigAck (void)
{
    m_pType = &s_typeDescriptor;

    m_pStatus = NULL;
    m_pIdentification = NULL;
    m_pDeviceEventNotificationSpec = NULL;
    m_pAlarmConfiguration = NULL;
    m_pModuleDepth = NULL;
    m_pSelectReportSpec = NULL;
    m_pAccessReportSpec = NULL;
    m_pCommunicationConfiguration = NULL;
    m_pLocationConfiguration = NULL;
    m_pSecurityModuleConfiguration = NULL;
}

CGetDeviceConfigAck::~CGetDeviceConfigAck (void)
{
}


CElement *
CGetDeviceConfigAck::s_construct (void)
{
    return (CElement *) new CGetDeviceConfigAck();
}


void
CGetDeviceConfigAck::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CGetDeviceConfigAck * pTarget = (CGetDeviceConfigAck *) pTargetElement;


}


void
CGetDeviceConfigAck::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CGetDeviceConfigAck::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    // 1 of Status
    pType = &CStatus::s_typeDescriptor;

    if(Cur == End || (*Cur)->m_pType != pType)
    {
        goto missing;
    }
    m_pStatus = (CStatus *)*Cur++;


    // 0-1 of Identification
    pType = &CIdentification::s_typeDescriptor;

    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pIdentification = (CIdentification *)*Cur++;
    }


    // 0-1 of DeviceEventNotificationSpec
    pType = &CDeviceEventNotificationSpec::s_typeDescriptor;

    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pDeviceEventNotificationSpec = (CDeviceEventNotificationSpec *)*Cur++;
    }


    // 0-1 of AlarmConfiguration
    pType = &CAlarmConfiguration::s_typeDescriptor;

    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pAlarmConfiguration = (CAlarmConfiguration *)*Cur++;
    }


    // 0-N of AntennaProperties
    pType = &CAntennaProperties::s_typeDescriptor;

    while(Cur != End && (*Cur)->m_pType == pType)
    {
        m_listAntennaProperties.push_back((CAntennaProperties *)*Cur);
        Cur++;
    }


    // 0-N of AntennaConfiguration
    pType = &CAntennaConfiguration::s_typeDescriptor;

    while(Cur != End && (*Cur)->m_pType == pType)
    {
        m_listAntennaConfiguration.push_back((CAntennaConfiguration *)*Cur);
        Cur++;
    }


    // 0-1 of ModuleDepth
    pType = &CModuleDepth::s_typeDescriptor;

    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pModuleDepth = (CModuleDepth *)*Cur++;
    }


    // 0-1 of SelectReportSpec
    pType = &CSelectReportSpec::s_typeDescriptor;

    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pSelectReportSpec = (CSelectReportSpec *)*Cur++;
    }


    // 0-1 of AccessReportSpec
    pType = &CAccessReportSpec::s_typeDescriptor;

    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pAccessReportSpec = (CAccessReportSpec *)*Cur++;
    }


    // 0-1 of CommunicationConfiguration
    pType = &CCommunicationConfiguration::s_typeDescriptor;

    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pCommunicationConfiguration = (CCommunicationConfiguration *)*Cur++;
    }


    // 0-1 of LocationConfiguration
    pType = &CLocationConfiguration::s_typeDescriptor;

    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pLocationConfiguration = (CLocationConfiguration *)*Cur++;
    }


    // 0-1 of SecurityModuleConfiguration
    pType = &CSecurityModuleConfiguration::s_typeDescriptor;

    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pSecurityModuleConfiguration = (CSecurityModuleConfiguration *)*Cur++;
    }


    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


EResultCode
CGetDeviceConfigAck::setStatus (
  CStatus *     pValue)
{
    removeSubParameterFromAllList(m_pStatus);
    delete m_pStatus;
    m_pStatus = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CGetDeviceConfigAck::setIdentification (
  CIdentification *     pValue)
{
    removeSubParameterFromAllList(m_pIdentification);
    delete m_pIdentification;
    m_pIdentification = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CGetDeviceConfigAck::setDeviceEventNotificationSpec (
  CDeviceEventNotificationSpec *     pValue)
{
    removeSubParameterFromAllList(m_pDeviceEventNotificationSpec);
    delete m_pDeviceEventNotificationSpec;
    m_pDeviceEventNotificationSpec = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CGetDeviceConfigAck::setAlarmConfiguration (
  CAlarmConfiguration *     pValue)
{
    removeSubParameterFromAllList(m_pAlarmConfiguration);
    delete m_pAlarmConfiguration;
    m_pAlarmConfiguration = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CGetDeviceConfigAck::addAntennaProperties (
  CAntennaProperties *     pValue)
{
    m_listAntennaProperties.push_back(pValue);
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CGetDeviceConfigAck::addAntennaConfiguration (
  CAntennaConfiguration *     pValue)
{
    m_listAntennaConfiguration.push_back(pValue);
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CGetDeviceConfigAck::setModuleDepth (
  CModuleDepth *     pValue)
{
    removeSubParameterFromAllList(m_pModuleDepth);
    delete m_pModuleDepth;
    m_pModuleDepth = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CGetDeviceConfigAck::setSelectReportSpec (
  CSelectReportSpec *     pValue)
{
    removeSubParameterFromAllList(m_pSelectReportSpec);
    delete m_pSelectReportSpec;
    m_pSelectReportSpec = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CGetDeviceConfigAck::setAccessReportSpec (
  CAccessReportSpec *     pValue)
{
    removeSubParameterFromAllList(m_pAccessReportSpec);
    delete m_pAccessReportSpec;
    m_pAccessReportSpec = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CGetDeviceConfigAck::setCommunicationConfiguration (
  CCommunicationConfiguration *     pValue)
{
    removeSubParameterFromAllList(m_pCommunicationConfiguration);
    delete m_pCommunicationConfiguration;
    m_pCommunicationConfiguration = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CGetDeviceConfigAck::setLocationConfiguration (
  CLocationConfiguration *     pValue)
{
    removeSubParameterFromAllList(m_pLocationConfiguration);
    delete m_pLocationConfiguration;
    m_pLocationConfiguration = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CGetDeviceConfigAck::setSecurityModuleConfiguration (
  CSecurityModuleConfiguration *     pValue)
{
    removeSubParameterFromAllList(m_pSecurityModuleConfiguration);
    delete m_pSecurityModuleConfiguration;
    m_pSecurityModuleConfiguration = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CGetDeviceConfigAck::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pType = &CStatus::s_typeDescriptor;

    pEncoderStream->putRequiredSubParameter(m_pStatus, pType);

    pType = &CIdentification::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameter(m_pIdentification, pType);

    pType = &CDeviceEventNotificationSpec::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameter(m_pDeviceEventNotificationSpec, pType);

    pType = &CAlarmConfiguration::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameter(m_pAlarmConfiguration, pType);

    pType = &CAntennaProperties::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameterList((tListOfParameters *) &m_listAntennaProperties, pType);

    pType = &CAntennaConfiguration::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameterList((tListOfParameters *) &m_listAntennaConfiguration, pType);

    pType = &CModuleDepth::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameter(m_pModuleDepth, pType);

    pType = &CSelectReportSpec::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameter(m_pSelectReportSpec, pType);

    pType = &CAccessReportSpec::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameter(m_pAccessReportSpec, pType);

    pType = &CCommunicationConfiguration::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameter(m_pCommunicationConfiguration, pType);

    pType = &CLocationConfiguration::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameter(m_pLocationConfiguration, pType);

    pType = &CSecurityModuleConfiguration::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameter(m_pSecurityModuleConfiguration, pType);

}




/*
*****************************************************************
**
** Message SetDeviceConfig
**
*****************************************************************
*/


const CTypeDescriptor
CSetDeviceConfig::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "SetDeviceConfig",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    662,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CSetDeviceConfig::s_apFieldDescriptorTable[] =
{

    &s_fdResetToFactoryDefault,
    NULL
};



const CFieldDescriptor
CSetDeviceConfig::s_fdResetToFactoryDefault =
{
    CFieldDescriptor::FT_E1,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "ResetToFactoryDefault",	// m_pName
    g_estSetDeviceConfigResetToFactoryDefault	// m_pEnumTable
};
CSetDeviceConfig::CSetDeviceConfig (void)
{
    m_pType = &s_typeDescriptor;

    m_EResetToFactoryDefault = (ESetDeviceConfigResetToFactoryDefault) 0;
    m_pIdentification = NULL;
    m_pDeviceEventNotificationSpec = NULL;
    m_pAlarmConfiguration = NULL;
    m_pModuleDepth = NULL;
    m_pSelectReportSpec = NULL;
    m_pAccessReportSpec = NULL;
    m_pCommunicationConfiguration = NULL;
    m_pLocationConfiguration = NULL;
    m_pSecurityModuleConfiguration = NULL;
}

CSetDeviceConfig::~CSetDeviceConfig (void)
{
}


CElement *
CSetDeviceConfig::s_construct (void)
{
    return (CElement *) new CSetDeviceConfig();
}


void
CSetDeviceConfig::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CSetDeviceConfig * pTarget = (CSetDeviceConfig *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_EResetToFactoryDefault = (ESetDeviceConfigResetToFactoryDefault) pDecoderStream->get_e1(&s_fdResetToFactoryDefault);
    }
    else
    {
        pDecoderStream->get_e1(&s_fdResetToFactoryDefault);
    }

    pDecoderStream->get_reserved(7);

}


void
CSetDeviceConfig::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CSetDeviceConfig::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    // 0-1 of Identification
    pType = &CIdentification::s_typeDescriptor;

    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pIdentification = (CIdentification *)*Cur++;
    }


    // 0-1 of DeviceEventNotificationSpec
    pType = &CDeviceEventNotificationSpec::s_typeDescriptor;

    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pDeviceEventNotificationSpec = (CDeviceEventNotificationSpec *)*Cur++;
    }


    // 0-1 of AlarmConfiguration
    pType = &CAlarmConfiguration::s_typeDescriptor;

    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pAlarmConfiguration = (CAlarmConfiguration *)*Cur++;
    }


    // 0-N of AntennaConfiguration
    pType = &CAntennaConfiguration::s_typeDescriptor;

    while(Cur != End && (*Cur)->m_pType == pType)
    {
        m_listAntennaConfiguration.push_back((CAntennaConfiguration *)*Cur);
        Cur++;
    }


    // 0-1 of ModuleDepth
    pType = &CModuleDepth::s_typeDescriptor;

    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pModuleDepth = (CModuleDepth *)*Cur++;
    }


    // 0-1 of SelectReportSpec
    pType = &CSelectReportSpec::s_typeDescriptor;

    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pSelectReportSpec = (CSelectReportSpec *)*Cur++;
    }


    // 0-1 of AccessReportSpec
    pType = &CAccessReportSpec::s_typeDescriptor;

    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pAccessReportSpec = (CAccessReportSpec *)*Cur++;
    }


    // 0-1 of CommunicationConfiguration
    pType = &CCommunicationConfiguration::s_typeDescriptor;

    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pCommunicationConfiguration = (CCommunicationConfiguration *)*Cur++;
    }


    // 0-1 of LocationConfiguration
    pType = &CLocationConfiguration::s_typeDescriptor;

    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pLocationConfiguration = (CLocationConfiguration *)*Cur++;
    }


    // 0-1 of SecurityModuleConfiguration
    pType = &CSecurityModuleConfiguration::s_typeDescriptor;

    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pSecurityModuleConfiguration = (CSecurityModuleConfiguration *)*Cur++;
    }


    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


EResultCode
CSetDeviceConfig::setIdentification (
  CIdentification *     pValue)
{
    removeSubParameterFromAllList(m_pIdentification);
    delete m_pIdentification;
    m_pIdentification = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CSetDeviceConfig::setDeviceEventNotificationSpec (
  CDeviceEventNotificationSpec *     pValue)
{
    removeSubParameterFromAllList(m_pDeviceEventNotificationSpec);
    delete m_pDeviceEventNotificationSpec;
    m_pDeviceEventNotificationSpec = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CSetDeviceConfig::setAlarmConfiguration (
  CAlarmConfiguration *     pValue)
{
    removeSubParameterFromAllList(m_pAlarmConfiguration);
    delete m_pAlarmConfiguration;
    m_pAlarmConfiguration = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CSetDeviceConfig::addAntennaConfiguration (
  CAntennaConfiguration *     pValue)
{
    m_listAntennaConfiguration.push_back(pValue);
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CSetDeviceConfig::setModuleDepth (
  CModuleDepth *     pValue)
{
    removeSubParameterFromAllList(m_pModuleDepth);
    delete m_pModuleDepth;
    m_pModuleDepth = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CSetDeviceConfig::setSelectReportSpec (
  CSelectReportSpec *     pValue)
{
    removeSubParameterFromAllList(m_pSelectReportSpec);
    delete m_pSelectReportSpec;
    m_pSelectReportSpec = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CSetDeviceConfig::setAccessReportSpec (
  CAccessReportSpec *     pValue)
{
    removeSubParameterFromAllList(m_pAccessReportSpec);
    delete m_pAccessReportSpec;
    m_pAccessReportSpec = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CSetDeviceConfig::setCommunicationConfiguration (
  CCommunicationConfiguration *     pValue)
{
    removeSubParameterFromAllList(m_pCommunicationConfiguration);
    delete m_pCommunicationConfiguration;
    m_pCommunicationConfiguration = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CSetDeviceConfig::setLocationConfiguration (
  CLocationConfiguration *     pValue)
{
    removeSubParameterFromAllList(m_pLocationConfiguration);
    delete m_pLocationConfiguration;
    m_pLocationConfiguration = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CSetDeviceConfig::setSecurityModuleConfiguration (
  CSecurityModuleConfiguration *     pValue)
{
    removeSubParameterFromAllList(m_pSecurityModuleConfiguration);
    delete m_pSecurityModuleConfiguration;
    m_pSecurityModuleConfiguration = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CSetDeviceConfig::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_e1((int)m_EResetToFactoryDefault, &s_fdResetToFactoryDefault);

    pEncoderStream->put_reserved(7);

    pType = &CIdentification::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameter(m_pIdentification, pType);

    pType = &CDeviceEventNotificationSpec::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameter(m_pDeviceEventNotificationSpec, pType);

    pType = &CAlarmConfiguration::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameter(m_pAlarmConfiguration, pType);

    pType = &CAntennaConfiguration::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameterList((tListOfParameters *) &m_listAntennaConfiguration, pType);

    pType = &CModuleDepth::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameter(m_pModuleDepth, pType);

    pType = &CSelectReportSpec::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameter(m_pSelectReportSpec, pType);

    pType = &CAccessReportSpec::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameter(m_pAccessReportSpec, pType);

    pType = &CCommunicationConfiguration::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameter(m_pCommunicationConfiguration, pType);

    pType = &CLocationConfiguration::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameter(m_pLocationConfiguration, pType);

    pType = &CSecurityModuleConfiguration::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameter(m_pSecurityModuleConfiguration, pType);

}




/*
*****************************************************************
**
** Message SetDeviceConfigAck
**
*****************************************************************
*/


const CTypeDescriptor
CSetDeviceConfigAck::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "SetDeviceConfigAck",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    663,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CSetDeviceConfigAck::s_apFieldDescriptorTable[] =
{

    NULL
};

CSetDeviceConfigAck::CSetDeviceConfigAck (void)
{
    m_pType = &s_typeDescriptor;

    m_pStatus = NULL;
}

CSetDeviceConfigAck::~CSetDeviceConfigAck (void)
{
}


CElement *
CSetDeviceConfigAck::s_construct (void)
{
    return (CElement *) new CSetDeviceConfigAck();
}


void
CSetDeviceConfigAck::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CSetDeviceConfigAck * pTarget = (CSetDeviceConfigAck *) pTargetElement;


}


void
CSetDeviceConfigAck::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CSetDeviceConfigAck::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    // 1 of Status
    pType = &CStatus::s_typeDescriptor;

    if(Cur == End || (*Cur)->m_pType != pType)
    {
        goto missing;
    }
    m_pStatus = (CStatus *)*Cur++;


    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


EResultCode
CSetDeviceConfigAck::setStatus (
  CStatus *     pValue)
{
    removeSubParameterFromAllList(m_pStatus);
    delete m_pStatus;
    m_pStatus = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CSetDeviceConfigAck::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pType = &CStatus::s_typeDescriptor;

    pEncoderStream->putRequiredSubParameter(m_pStatus, pType);

}




/*
*****************************************************************
**
** Message GetVersion
**
*****************************************************************
*/


const CTypeDescriptor
CGetVersion::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "GetVersion",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    700,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CGetVersion::s_apFieldDescriptorTable[] =
{

    &s_fdVerType,
    NULL
};



const CFieldDescriptor
CGetVersion::s_fdVerType =
{
    CFieldDescriptor::FT_E8,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "VerType",	// m_pName
    g_estGetVersionVerType	// m_pEnumTable
};
CGetVersion::CGetVersion (void)
{
    m_pType = &s_typeDescriptor;

    m_EVerType = (EGetVersionVerType) 0;
}

CGetVersion::~CGetVersion (void)
{
}


CElement *
CGetVersion::s_construct (void)
{
    return (CElement *) new CGetVersion();
}


void
CGetVersion::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CGetVersion * pTarget = (CGetVersion *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_EVerType = (EGetVersionVerType) pDecoderStream->get_e8(&s_fdVerType);
    }
    else
    {
        pDecoderStream->get_e8(&s_fdVerType);
    }

}


void
CGetVersion::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CGetVersion::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


void
CGetVersion::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_e8((int)m_EVerType, &s_fdVerType);

}




/*
*****************************************************************
**
** Message GetVersionAck
**
*****************************************************************
*/


const CTypeDescriptor
CGetVersionAck::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "GetVersionAck",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    701,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CGetVersionAck::s_apFieldDescriptorTable[] =
{

    NULL
};

CGetVersionAck::CGetVersionAck (void)
{
    m_pType = &s_typeDescriptor;

    m_pStatus = NULL;
}

CGetVersionAck::~CGetVersionAck (void)
{
}


CElement *
CGetVersionAck::s_construct (void)
{
    return (CElement *) new CGetVersionAck();
}


void
CGetVersionAck::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CGetVersionAck * pTarget = (CGetVersionAck *) pTargetElement;


}


void
CGetVersionAck::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CGetVersionAck::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    // 1 of Status
    pType = &CStatus::s_typeDescriptor;

    if(Cur == End || (*Cur)->m_pType != pType)
    {
        goto missing;
    }
    m_pStatus = (CStatus *)*Cur++;


    // 0-N of VersionInfo
    pType = &CVersionInfo::s_typeDescriptor;

    while(Cur != End && (*Cur)->m_pType == pType)
    {
        m_listVersionInfo.push_back((CVersionInfo *)*Cur);
        Cur++;
    }


    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


EResultCode
CGetVersionAck::setStatus (
  CStatus *     pValue)
{
    removeSubParameterFromAllList(m_pStatus);
    delete m_pStatus;
    m_pStatus = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CGetVersionAck::addVersionInfo (
  CVersionInfo *     pValue)
{
    m_listVersionInfo.push_back(pValue);
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CGetVersionAck::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pType = &CStatus::s_typeDescriptor;

    pEncoderStream->putRequiredSubParameter(m_pStatus, pType);

    pType = &CVersionInfo::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameterList((tListOfParameters *) &m_listVersionInfo, pType);

}




/*
*****************************************************************
**
** Message SetVersion
**
*****************************************************************
*/


const CTypeDescriptor
CSetVersion::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "SetVersion",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    702,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CSetVersion::s_apFieldDescriptorTable[] =
{

    &s_fdVerType,
    NULL
};



const CFieldDescriptor
CSetVersion::s_fdVerType =
{
    CFieldDescriptor::FT_E8,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "VerType",	// m_pName
    g_estSetVersionVerType	// m_pEnumTable
};
CSetVersion::CSetVersion (void)
{
    m_pType = &s_typeDescriptor;

    m_EVerType = (ESetVersionVerType) 0;
    m_pVersionDownload = NULL;
}

CSetVersion::~CSetVersion (void)
{
}


CElement *
CSetVersion::s_construct (void)
{
    return (CElement *) new CSetVersion();
}


void
CSetVersion::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CSetVersion * pTarget = (CSetVersion *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_EVerType = (ESetVersionVerType) pDecoderStream->get_e8(&s_fdVerType);
    }
    else
    {
        pDecoderStream->get_e8(&s_fdVerType);
    }

}


void
CSetVersion::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CSetVersion::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    // 1 of VersionDownload
    pType = &CVersionDownload::s_typeDescriptor;

    if(Cur == End || (*Cur)->m_pType != pType)
    {
        goto missing;
    }
    m_pVersionDownload = (CVersionDownload *)*Cur++;


    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


EResultCode
CSetVersion::setVersionDownload (
  CVersionDownload *     pValue)
{
    removeSubParameterFromAllList(m_pVersionDownload);
    delete m_pVersionDownload;
    m_pVersionDownload = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CSetVersion::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_e8((int)m_EVerType, &s_fdVerType);

    pType = &CVersionDownload::s_typeDescriptor;

    pEncoderStream->putRequiredSubParameter(m_pVersionDownload, pType);

}




/*
*****************************************************************
**
** Message SetVersionAck
**
*****************************************************************
*/


const CTypeDescriptor
CSetVersionAck::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "SetVersionAck",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    703,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CSetVersionAck::s_apFieldDescriptorTable[] =
{

    NULL
};

CSetVersionAck::CSetVersionAck (void)
{
    m_pType = &s_typeDescriptor;

    m_pStatus = NULL;
}

CSetVersionAck::~CSetVersionAck (void)
{
}


CElement *
CSetVersionAck::s_construct (void)
{
    return (CElement *) new CSetVersionAck();
}


void
CSetVersionAck::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CSetVersionAck * pTarget = (CSetVersionAck *) pTargetElement;


}


void
CSetVersionAck::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CSetVersionAck::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    // 1 of Status
    pType = &CStatus::s_typeDescriptor;

    if(Cur == End || (*Cur)->m_pType != pType)
    {
        goto missing;
    }
    m_pStatus = (CStatus *)*Cur++;


    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


EResultCode
CSetVersionAck::setStatus (
  CStatus *     pValue)
{
    removeSubParameterFromAllList(m_pStatus);
    delete m_pStatus;
    m_pStatus = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CSetVersionAck::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pType = &CStatus::s_typeDescriptor;

    pEncoderStream->putRequiredSubParameter(m_pStatus, pType);

}




/*
*****************************************************************
**
** Message ActiveVersion
**
*****************************************************************
*/


const CTypeDescriptor
CActiveVersion::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "ActiveVersion",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    704,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CActiveVersion::s_apFieldDescriptorTable[] =
{

    &s_fdVerType,
    NULL
};



const CFieldDescriptor
CActiveVersion::s_fdVerType =
{
    CFieldDescriptor::FT_E8,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "VerType",	// m_pName
    g_estActiveVersionVerType	// m_pEnumTable
};
CActiveVersion::CActiveVersion (void)
{
    m_pType = &s_typeDescriptor;

    m_EVerType = (EActiveVersionVerType) 0;
}

CActiveVersion::~CActiveVersion (void)
{
}


CElement *
CActiveVersion::s_construct (void)
{
    return (CElement *) new CActiveVersion();
}


void
CActiveVersion::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CActiveVersion * pTarget = (CActiveVersion *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_EVerType = (EActiveVersionVerType) pDecoderStream->get_e8(&s_fdVerType);
    }
    else
    {
        pDecoderStream->get_e8(&s_fdVerType);
    }

}


void
CActiveVersion::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CActiveVersion::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


void
CActiveVersion::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_e8((int)m_EVerType, &s_fdVerType);

}




/*
*****************************************************************
**
** Message ActiveVersionAck
**
*****************************************************************
*/


const CTypeDescriptor
CActiveVersionAck::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "ActiveVersionAck",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    705,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CActiveVersionAck::s_apFieldDescriptorTable[] =
{

    NULL
};

CActiveVersionAck::CActiveVersionAck (void)
{
    m_pType = &s_typeDescriptor;

    m_pStatus = NULL;
}

CActiveVersionAck::~CActiveVersionAck (void)
{
}


CElement *
CActiveVersionAck::s_construct (void)
{
    return (CElement *) new CActiveVersionAck();
}


void
CActiveVersionAck::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CActiveVersionAck * pTarget = (CActiveVersionAck *) pTargetElement;


}


void
CActiveVersionAck::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CActiveVersionAck::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    // 1 of Status
    pType = &CStatus::s_typeDescriptor;

    if(Cur == End || (*Cur)->m_pType != pType)
    {
        goto missing;
    }
    m_pStatus = (CStatus *)*Cur++;


    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


EResultCode
CActiveVersionAck::setStatus (
  CStatus *     pValue)
{
    removeSubParameterFromAllList(m_pStatus);
    delete m_pStatus;
    m_pStatus = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CActiveVersionAck::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pType = &CStatus::s_typeDescriptor;

    pEncoderStream->putRequiredSubParameter(m_pStatus, pType);

}




/*
*****************************************************************
**
** Message UnActiveVersion
**
*****************************************************************
*/


const CTypeDescriptor
CUnActiveVersion::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "UnActiveVersion",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    706,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CUnActiveVersion::s_apFieldDescriptorTable[] =
{

    &s_fdVerType,
    NULL
};



const CFieldDescriptor
CUnActiveVersion::s_fdVerType =
{
    CFieldDescriptor::FT_E8,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "VerType",	// m_pName
    g_estUnActiveVersionVerType	// m_pEnumTable
};
CUnActiveVersion::CUnActiveVersion (void)
{
    m_pType = &s_typeDescriptor;

    m_EVerType = (EUnActiveVersionVerType) 0;
}

CUnActiveVersion::~CUnActiveVersion (void)
{
}


CElement *
CUnActiveVersion::s_construct (void)
{
    return (CElement *) new CUnActiveVersion();
}


void
CUnActiveVersion::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CUnActiveVersion * pTarget = (CUnActiveVersion *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_EVerType = (EUnActiveVersionVerType) pDecoderStream->get_e8(&s_fdVerType);
    }
    else
    {
        pDecoderStream->get_e8(&s_fdVerType);
    }

}


void
CUnActiveVersion::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CUnActiveVersion::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


void
CUnActiveVersion::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_e8((int)m_EVerType, &s_fdVerType);

}




/*
*****************************************************************
**
** Message UnActiveVersionAck
**
*****************************************************************
*/


const CTypeDescriptor
CUnActiveVersionAck::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "UnActiveVersionAck",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    707,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CUnActiveVersionAck::s_apFieldDescriptorTable[] =
{

    NULL
};

CUnActiveVersionAck::CUnActiveVersionAck (void)
{
    m_pType = &s_typeDescriptor;

    m_pStatus = NULL;
}

CUnActiveVersionAck::~CUnActiveVersionAck (void)
{
}


CElement *
CUnActiveVersionAck::s_construct (void)
{
    return (CElement *) new CUnActiveVersionAck();
}


void
CUnActiveVersionAck::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CUnActiveVersionAck * pTarget = (CUnActiveVersionAck *) pTargetElement;


}


void
CUnActiveVersionAck::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CUnActiveVersionAck::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    // 1 of Status
    pType = &CStatus::s_typeDescriptor;

    if(Cur == End || (*Cur)->m_pType != pType)
    {
        goto missing;
    }
    m_pStatus = (CStatus *)*Cur++;


    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


EResultCode
CUnActiveVersionAck::setStatus (
  CStatus *     pValue)
{
    removeSubParameterFromAllList(m_pStatus);
    delete m_pStatus;
    m_pStatus = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CUnActiveVersionAck::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pType = &CStatus::s_typeDescriptor;

    pEncoderStream->putRequiredSubParameter(m_pStatus, pType);

}




/*
*****************************************************************
**
** Message AlarmReport
**
*****************************************************************
*/


const CTypeDescriptor
CAlarmReport::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "AlarmReport",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    720,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CAlarmReport::s_apFieldDescriptorTable[] =
{

    &s_fdAlarmID,
    NULL
};



const CFieldDescriptor
CAlarmReport::s_fdAlarmID =
{
    CFieldDescriptor::FT_U32,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "AlarmID",	// m_pName
    NULL	// m_pEnumTable
};
CAlarmReport::CAlarmReport (void)
{
    m_pType = &s_typeDescriptor;

    m_AlarmID = 0;
    m_pAlarmReportInfo = NULL;
}

CAlarmReport::~CAlarmReport (void)
{
}


CElement *
CAlarmReport::s_construct (void)
{
    return (CElement *) new CAlarmReport();
}


void
CAlarmReport::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CAlarmReport * pTarget = (CAlarmReport *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_AlarmID = pDecoderStream->get_u32(&s_fdAlarmID);
    }
    else
    {
        pDecoderStream->get_u32(&s_fdAlarmID);
    }

}


void
CAlarmReport::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CAlarmReport::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    // 1 of AlarmReportInfo
    pType = &CAlarmReportInfo::s_typeDescriptor;

    if(Cur == End || (*Cur)->m_pType != pType)
    {
        goto missing;
    }
    m_pAlarmReportInfo = (CAlarmReportInfo *)*Cur++;


    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


EResultCode
CAlarmReport::setAlarmReportInfo (
  CAlarmReportInfo *     pValue)
{
    removeSubParameterFromAllList(m_pAlarmReportInfo);
    delete m_pAlarmReportInfo;
    m_pAlarmReportInfo = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CAlarmReport::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u32(m_AlarmID, &s_fdAlarmID);

    pType = &CAlarmReportInfo::s_typeDescriptor;

    pEncoderStream->putRequiredSubParameter(m_pAlarmReportInfo, pType);

}




/*
*****************************************************************
**
** Message AlarmRestore
**
*****************************************************************
*/


const CTypeDescriptor
CAlarmRestore::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "AlarmRestore",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    721,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CAlarmRestore::s_apFieldDescriptorTable[] =
{

    &s_fdAlarmID,
    NULL
};



const CFieldDescriptor
CAlarmRestore::s_fdAlarmID =
{
    CFieldDescriptor::FT_U32,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "AlarmID",	// m_pName
    NULL	// m_pEnumTable
};
CAlarmRestore::CAlarmRestore (void)
{
    m_pType = &s_typeDescriptor;

    m_AlarmID = 0;
    m_pAlarmRestoreInfo = NULL;
}

CAlarmRestore::~CAlarmRestore (void)
{
}


CElement *
CAlarmRestore::s_construct (void)
{
    return (CElement *) new CAlarmRestore();
}


void
CAlarmRestore::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CAlarmRestore * pTarget = (CAlarmRestore *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_AlarmID = pDecoderStream->get_u32(&s_fdAlarmID);
    }
    else
    {
        pDecoderStream->get_u32(&s_fdAlarmID);
    }

}


void
CAlarmRestore::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CAlarmRestore::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    // 1 of AlarmRestoreInfo
    pType = &CAlarmRestoreInfo::s_typeDescriptor;

    if(Cur == End || (*Cur)->m_pType != pType)
    {
        goto missing;
    }
    m_pAlarmRestoreInfo = (CAlarmRestoreInfo *)*Cur++;


    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


EResultCode
CAlarmRestore::setAlarmRestoreInfo (
  CAlarmRestoreInfo *     pValue)
{
    removeSubParameterFromAllList(m_pAlarmRestoreInfo);
    delete m_pAlarmRestoreInfo;
    m_pAlarmRestoreInfo = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CAlarmRestore::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u32(m_AlarmID, &s_fdAlarmID);

    pType = &CAlarmRestoreInfo::s_typeDescriptor;

    pEncoderStream->putRequiredSubParameter(m_pAlarmRestoreInfo, pType);

}




/*
*****************************************************************
**
** Message AlarmDelete
**
*****************************************************************
*/


const CTypeDescriptor
CAlarmDelete::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "AlarmDelete",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    722,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CAlarmDelete::s_apFieldDescriptorTable[] =
{

    &s_fdAlarmID,
    NULL
};



const CFieldDescriptor
CAlarmDelete::s_fdAlarmID =
{
    CFieldDescriptor::FT_U32,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "AlarmID",	// m_pName
    NULL	// m_pEnumTable
};
CAlarmDelete::CAlarmDelete (void)
{
    m_pType = &s_typeDescriptor;

    m_AlarmID = 0;
}

CAlarmDelete::~CAlarmDelete (void)
{
}


CElement *
CAlarmDelete::s_construct (void)
{
    return (CElement *) new CAlarmDelete();
}


void
CAlarmDelete::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CAlarmDelete * pTarget = (CAlarmDelete *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_AlarmID = pDecoderStream->get_u32(&s_fdAlarmID);
    }
    else
    {
        pDecoderStream->get_u32(&s_fdAlarmID);
    }

}


void
CAlarmDelete::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CAlarmDelete::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


void
CAlarmDelete::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u32(m_AlarmID, &s_fdAlarmID);

}




/*
*****************************************************************
**
** Message AlarmSync
**
*****************************************************************
*/


const CTypeDescriptor
CAlarmSync::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "AlarmSync",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    723,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CAlarmSync::s_apFieldDescriptorTable[] =
{

    NULL
};

CAlarmSync::CAlarmSync (void)
{
    m_pType = &s_typeDescriptor;

    m_pAlarmSyncInfo = NULL;
}

CAlarmSync::~CAlarmSync (void)
{
}


CElement *
CAlarmSync::s_construct (void)
{
    return (CElement *) new CAlarmSync();
}


void
CAlarmSync::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CAlarmSync * pTarget = (CAlarmSync *) pTargetElement;


}


void
CAlarmSync::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CAlarmSync::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    // 1 of AlarmSyncInfo
    pType = &CAlarmSyncInfo::s_typeDescriptor;

    if(Cur == End || (*Cur)->m_pType != pType)
    {
        goto missing;
    }
    m_pAlarmSyncInfo = (CAlarmSyncInfo *)*Cur++;


    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


EResultCode
CAlarmSync::setAlarmSyncInfo (
  CAlarmSyncInfo *     pValue)
{
    removeSubParameterFromAllList(m_pAlarmSyncInfo);
    delete m_pAlarmSyncInfo;
    m_pAlarmSyncInfo = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CAlarmSync::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pType = &CAlarmSyncInfo::s_typeDescriptor;

    pEncoderStream->putRequiredSubParameter(m_pAlarmSyncInfo, pType);

}




/*
*****************************************************************
**
** Message DiagnosticTest
**
*****************************************************************
*/


const CTypeDescriptor
CDiagnosticTest::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "DiagnosticTest",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    740,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CDiagnosticTest::s_apFieldDescriptorTable[] =
{

    NULL
};

CDiagnosticTest::CDiagnosticTest (void)
{
    m_pType = &s_typeDescriptor;

}

CDiagnosticTest::~CDiagnosticTest (void)
{
}


CElement *
CDiagnosticTest::s_construct (void)
{
    return (CElement *) new CDiagnosticTest();
}


void
CDiagnosticTest::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CDiagnosticTest * pTarget = (CDiagnosticTest *) pTargetElement;


}


void
CDiagnosticTest::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CDiagnosticTest::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    // 1-N of DiagnosticTestItem
    pType = &CDiagnosticTestItem::s_typeDescriptor;

    if(Cur == End || (*Cur)->m_pType != pType)
    {
        goto missing;
    }
    while(Cur != End && (*Cur)->m_pType == pType)
    {
        m_listDiagnosticTestItem.push_back((CDiagnosticTestItem *)*Cur);
        Cur++;
    }


    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


EResultCode
CDiagnosticTest::addDiagnosticTestItem (
  CDiagnosticTestItem *     pValue)
{
    m_listDiagnosticTestItem.push_back(pValue);
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CDiagnosticTest::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pType = &CDiagnosticTestItem::s_typeDescriptor;

    pEncoderStream->putRequiredSubParameterList((tListOfParameters *) &m_listDiagnosticTestItem, pType);

}




/*
*****************************************************************
**
** Message DiagnosticTestAck
**
*****************************************************************
*/


const CTypeDescriptor
CDiagnosticTestAck::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "DiagnosticTestAck",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    741,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CDiagnosticTestAck::s_apFieldDescriptorTable[] =
{

    NULL
};

CDiagnosticTestAck::CDiagnosticTestAck (void)
{
    m_pType = &s_typeDescriptor;

    m_pStatus = NULL;
}

CDiagnosticTestAck::~CDiagnosticTestAck (void)
{
}


CElement *
CDiagnosticTestAck::s_construct (void)
{
    return (CElement *) new CDiagnosticTestAck();
}


void
CDiagnosticTestAck::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CDiagnosticTestAck * pTarget = (CDiagnosticTestAck *) pTargetElement;


}


void
CDiagnosticTestAck::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CDiagnosticTestAck::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    // 1 of Status
    pType = &CStatus::s_typeDescriptor;

    if(Cur == End || (*Cur)->m_pType != pType)
    {
        goto missing;
    }
    m_pStatus = (CStatus *)*Cur++;


    // 0-N of DiagnosticTestResultItem
    pType = &CDiagnosticTestResultItem::s_typeDescriptor;

    while(Cur != End && (*Cur)->m_pType == pType)
    {
        m_listDiagnosticTestResultItem.push_back((CDiagnosticTestResultItem *)*Cur);
        Cur++;
    }


    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


EResultCode
CDiagnosticTestAck::setStatus (
  CStatus *     pValue)
{
    removeSubParameterFromAllList(m_pStatus);
    delete m_pStatus;
    m_pStatus = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CDiagnosticTestAck::addDiagnosticTestResultItem (
  CDiagnosticTestResultItem *     pValue)
{
    m_listDiagnosticTestResultItem.push_back(pValue);
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CDiagnosticTestAck::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pType = &CStatus::s_typeDescriptor;

    pEncoderStream->putRequiredSubParameter(m_pStatus, pType);

    pType = &CDiagnosticTestResultItem::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameterList((tListOfParameters *) &m_listDiagnosticTestResultItem, pType);

}




/*
*****************************************************************
**
** Message ResetDevice
**
*****************************************************************
*/


const CTypeDescriptor
CResetDevice::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "ResetDevice",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    760,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CResetDevice::s_apFieldDescriptorTable[] =
{

    NULL
};

CResetDevice::CResetDevice (void)
{
    m_pType = &s_typeDescriptor;

}

CResetDevice::~CResetDevice (void)
{
}


CElement *
CResetDevice::s_construct (void)
{
    return (CElement *) new CResetDevice();
}


void
CResetDevice::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CResetDevice * pTarget = (CResetDevice *) pTargetElement;


}


void
CResetDevice::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CResetDevice::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


void
CResetDevice::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


}




/*
*****************************************************************
**
** Message ResetDeviceAck
**
*****************************************************************
*/


const CTypeDescriptor
CResetDeviceAck::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "ResetDeviceAck",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    761,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CResetDeviceAck::s_apFieldDescriptorTable[] =
{

    NULL
};

CResetDeviceAck::CResetDeviceAck (void)
{
    m_pType = &s_typeDescriptor;

    m_pStatus = NULL;
}

CResetDeviceAck::~CResetDeviceAck (void)
{
}


CElement *
CResetDeviceAck::s_construct (void)
{
    return (CElement *) new CResetDeviceAck();
}


void
CResetDeviceAck::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CResetDeviceAck * pTarget = (CResetDeviceAck *) pTargetElement;


}


void
CResetDeviceAck::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CResetDeviceAck::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    // 1 of Status
    pType = &CStatus::s_typeDescriptor;

    if(Cur == End || (*Cur)->m_pType != pType)
    {
        goto missing;
    }
    m_pStatus = (CStatus *)*Cur++;


    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


EResultCode
CResetDeviceAck::setStatus (
  CStatus *     pValue)
{
    removeSubParameterFromAllList(m_pStatus);
    delete m_pStatus;
    m_pStatus = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CResetDeviceAck::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pType = &CStatus::s_typeDescriptor;

    pEncoderStream->putRequiredSubParameter(m_pStatus, pType);

}




/*
*****************************************************************
**
** Parameter TagLog
**
*****************************************************************
*/


const CTypeDescriptor
CTagLog::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "TagLog",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    620,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CTagLog::s_apFieldDescriptorTable[] =
{

    &s_fdLogSequence,
    &s_fdTID,
    &s_fdCardID,
    &s_fdOpNum,
    NULL
};



const CFieldDescriptor
CTagLog::s_fdLogSequence =
{
    CFieldDescriptor::FT_U64,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "LogSequence",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CTagLog::s_fdTID =
{
    CFieldDescriptor::FT_U8V,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "TID",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CTagLog::s_fdCardID =
{
    CFieldDescriptor::FT_U8V,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "CardID",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CTagLog::s_fdOpNum =
{
    CFieldDescriptor::FT_U32,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "OpNum",	// m_pName
    NULL	// m_pEnumTable
};
CTagLog::CTagLog (void)
{
    m_pType = &s_typeDescriptor;

    m_LogSequence = 0;
    m_OpNum = 0;
    m_pUTCTimestamp = NULL;
}

CTagLog::~CTagLog (void)
{
}


CElement *
CTagLog::s_construct (void)
{
    return (CElement *) new CTagLog();
}


void
CTagLog::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CTagLog * pTarget = (CTagLog *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_LogSequence = pDecoderStream->get_u64(&s_fdLogSequence);
    }
    else
    {
        pDecoderStream->get_u64(&s_fdLogSequence);
    }

    if(NULL != pTarget)
    {
        pTarget->m_TID = pDecoderStream->get_u8v(&s_fdTID);
    }
    else
    {
        pDecoderStream->get_u8v(&s_fdTID);
    }

    if(NULL != pTarget)
    {
        pTarget->m_CardID = pDecoderStream->get_u8v(&s_fdCardID);
    }
    else
    {
        pDecoderStream->get_u8v(&s_fdCardID);
    }

    if(NULL != pTarget)
    {
        pTarget->m_OpNum = pDecoderStream->get_u32(&s_fdOpNum);
    }
    else
    {
        pDecoderStream->get_u32(&s_fdOpNum);
    }

}


void
CTagLog::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CTagLog::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    // 1 of UTCTimestamp
    pType = &CUTCTimestamp::s_typeDescriptor;

    if(Cur == End || (*Cur)->m_pType != pType)
    {
        goto missing;
    }
    m_pUTCTimestamp = (CUTCTimestamp *)*Cur++;


    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


EResultCode
CTagLog::setUTCTimestamp (
  CUTCTimestamp *     pValue)
{
    removeSubParameterFromAllList(m_pUTCTimestamp);
    delete m_pUTCTimestamp;
    m_pUTCTimestamp = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CTagLog::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u64(m_LogSequence, &s_fdLogSequence);

    pEncoderStream->put_u8v(m_TID, &s_fdTID);

    pEncoderStream->put_u8v(m_CardID, &s_fdCardID);

    pEncoderStream->put_u32(m_OpNum, &s_fdOpNum);

    pType = &CUTCTimestamp::s_typeDescriptor;

    pEncoderStream->putRequiredSubParameter(m_pUTCTimestamp, pType);

}




/*
*****************************************************************
**
** Parameter StartLogTimestamp
**
*****************************************************************
*/


const CTypeDescriptor
CStartLogTimestamp::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "StartLogTimestamp",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    621,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CStartLogTimestamp::s_apFieldDescriptorTable[] =
{

    &s_fdMicroseconds,
    NULL
};



const CFieldDescriptor
CStartLogTimestamp::s_fdMicroseconds =
{
    CFieldDescriptor::FT_U64,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "Microseconds",	// m_pName
    NULL	// m_pEnumTable
};
CStartLogTimestamp::CStartLogTimestamp (void)
{
    m_pType = &s_typeDescriptor;

    m_Microseconds = 0;
}

CStartLogTimestamp::~CStartLogTimestamp (void)
{
}


CElement *
CStartLogTimestamp::s_construct (void)
{
    return (CElement *) new CStartLogTimestamp();
}


void
CStartLogTimestamp::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CStartLogTimestamp * pTarget = (CStartLogTimestamp *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_Microseconds = pDecoderStream->get_u64(&s_fdMicroseconds);
    }
    else
    {
        pDecoderStream->get_u64(&s_fdMicroseconds);
    }

}


void
CStartLogTimestamp::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CStartLogTimestamp::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


void
CStartLogTimestamp::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u64(m_Microseconds, &s_fdMicroseconds);

}




/*
*****************************************************************
**
** Parameter EndLogTimestamp
**
*****************************************************************
*/


const CTypeDescriptor
CEndLogTimestamp::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "EndLogTimestamp",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    622,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CEndLogTimestamp::s_apFieldDescriptorTable[] =
{

    &s_fdMicroseconds,
    NULL
};



const CFieldDescriptor
CEndLogTimestamp::s_fdMicroseconds =
{
    CFieldDescriptor::FT_U64,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "Microseconds",	// m_pName
    NULL	// m_pEnumTable
};
CEndLogTimestamp::CEndLogTimestamp (void)
{
    m_pType = &s_typeDescriptor;

    m_Microseconds = 0;
}

CEndLogTimestamp::~CEndLogTimestamp (void)
{
}


CElement *
CEndLogTimestamp::s_construct (void)
{
    return (CElement *) new CEndLogTimestamp();
}


void
CEndLogTimestamp::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CEndLogTimestamp * pTarget = (CEndLogTimestamp *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_Microseconds = pDecoderStream->get_u64(&s_fdMicroseconds);
    }
    else
    {
        pDecoderStream->get_u64(&s_fdMicroseconds);
    }

}


void
CEndLogTimestamp::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CEndLogTimestamp::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


void
CEndLogTimestamp::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u64(m_Microseconds, &s_fdMicroseconds);

}




/*
*****************************************************************
**
** Parameter DeviceLog
**
*****************************************************************
*/


const CTypeDescriptor
CDeviceLog::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "DeviceLog",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    640,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CDeviceLog::s_apFieldDescriptorTable[] =
{

    &s_fdLogSequence,
    &s_fdLogType,
    &s_fdLogCode,
    &s_fdLogDescInfo,
    NULL
};



const CFieldDescriptor
CDeviceLog::s_fdLogSequence =
{
    CFieldDescriptor::FT_U64,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "LogSequence",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CDeviceLog::s_fdLogType =
{
    CFieldDescriptor::FT_U8,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "LogType",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CDeviceLog::s_fdLogCode =
{
    CFieldDescriptor::FT_U32,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "LogCode",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CDeviceLog::s_fdLogDescInfo =
{
    CFieldDescriptor::FT_UTF8V,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "LogDescInfo",	// m_pName
    NULL	// m_pEnumTable
};
CDeviceLog::CDeviceLog (void)
{
    m_pType = &s_typeDescriptor;

    m_LogSequence = 0;
    m_LogType = 0;
    m_LogCode = 0;
    m_pUTCTimestamp = NULL;
}

CDeviceLog::~CDeviceLog (void)
{
}


CElement *
CDeviceLog::s_construct (void)
{
    return (CElement *) new CDeviceLog();
}


void
CDeviceLog::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CDeviceLog * pTarget = (CDeviceLog *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_LogSequence = pDecoderStream->get_u64(&s_fdLogSequence);
    }
    else
    {
        pDecoderStream->get_u64(&s_fdLogSequence);
    }

    if(NULL != pTarget)
    {
        pTarget->m_LogType = pDecoderStream->get_u8(&s_fdLogType);
    }
    else
    {
        pDecoderStream->get_u8(&s_fdLogType);
    }

    if(NULL != pTarget)
    {
        pTarget->m_LogCode = pDecoderStream->get_u32(&s_fdLogCode);
    }
    else
    {
        pDecoderStream->get_u32(&s_fdLogCode);
    }

    if(NULL != pTarget)
    {
        pTarget->m_LogDescInfo = pDecoderStream->get_utf8v(&s_fdLogDescInfo);
    }
    else
    {
        pDecoderStream->get_utf8v(&s_fdLogDescInfo);
    }

}


void
CDeviceLog::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CDeviceLog::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    // 1 of UTCTimestamp
    pType = &CUTCTimestamp::s_typeDescriptor;

    if(Cur == End || (*Cur)->m_pType != pType)
    {
        goto missing;
    }
    m_pUTCTimestamp = (CUTCTimestamp *)*Cur++;


    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


EResultCode
CDeviceLog::setUTCTimestamp (
  CUTCTimestamp *     pValue)
{
    removeSubParameterFromAllList(m_pUTCTimestamp);
    delete m_pUTCTimestamp;
    m_pUTCTimestamp = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CDeviceLog::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u64(m_LogSequence, &s_fdLogSequence);

    pEncoderStream->put_u8(m_LogType, &s_fdLogType);

    pEncoderStream->put_u32(m_LogCode, &s_fdLogCode);

    pEncoderStream->put_utf8v(m_LogDescInfo, &s_fdLogDescInfo);

    pType = &CUTCTimestamp::s_typeDescriptor;

    pEncoderStream->putRequiredSubParameter(m_pUTCTimestamp, pType);

}




/*
*****************************************************************
**
** Parameter DeviceEventNotificationSpec
**
*****************************************************************
*/


const CTypeDescriptor
CDeviceEventNotificationSpec::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "DeviceEventNotificationSpec",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    660,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CDeviceEventNotificationSpec::s_apFieldDescriptorTable[] =
{

    NULL
};

CDeviceEventNotificationSpec::CDeviceEventNotificationSpec (void)
{
    m_pType = &s_typeDescriptor;

}

CDeviceEventNotificationSpec::~CDeviceEventNotificationSpec (void)
{
}


CElement *
CDeviceEventNotificationSpec::s_construct (void)
{
    return (CElement *) new CDeviceEventNotificationSpec();
}


void
CDeviceEventNotificationSpec::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CDeviceEventNotificationSpec * pTarget = (CDeviceEventNotificationSpec *) pTargetElement;


}


void
CDeviceEventNotificationSpec::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CDeviceEventNotificationSpec::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    // 1-N of EventNotificationState
    pType = &CEventNotificationState::s_typeDescriptor;

    if(Cur == End || (*Cur)->m_pType != pType)
    {
        goto missing;
    }
    while(Cur != End && (*Cur)->m_pType == pType)
    {
        m_listEventNotificationState.push_back((CEventNotificationState *)*Cur);
        Cur++;
    }


    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


EResultCode
CDeviceEventNotificationSpec::addEventNotificationState (
  CEventNotificationState *     pValue)
{
    m_listEventNotificationState.push_back(pValue);
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CDeviceEventNotificationSpec::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pType = &CEventNotificationState::s_typeDescriptor;

    pEncoderStream->putRequiredSubParameterList((tListOfParameters *) &m_listEventNotificationState, pType);

}




/*
*****************************************************************
**
** Parameter EventNotificationState
**
*****************************************************************
*/


const CTypeDescriptor
CEventNotificationState::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "EventNotificationState",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    661,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CEventNotificationState::s_apFieldDescriptorTable[] =
{

    &s_fdEventType,
    &s_fdNotificationState,
    NULL
};



const CFieldDescriptor
CEventNotificationState::s_fdEventType =
{
    CFieldDescriptor::FT_E16,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "EventType",	// m_pName
    g_estEventNotificationStateEventType	// m_pEnumTable
};


const CFieldDescriptor
CEventNotificationState::s_fdNotificationState =
{
    CFieldDescriptor::FT_E1,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "NotificationState",	// m_pName
    g_estEventNotificationStateNotificationState	// m_pEnumTable
};
CEventNotificationState::CEventNotificationState (void)
{
    m_pType = &s_typeDescriptor;

    m_EEventType = (EEventNotificationStateEventType) 0;
    m_ENotificationState = (EEventNotificationStateNotificationState) 0;
}

CEventNotificationState::~CEventNotificationState (void)
{
}


CElement *
CEventNotificationState::s_construct (void)
{
    return (CElement *) new CEventNotificationState();
}


void
CEventNotificationState::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CEventNotificationState * pTarget = (CEventNotificationState *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_EEventType = (EEventNotificationStateEventType) pDecoderStream->get_e16(&s_fdEventType);
    }
    else
    {
        pDecoderStream->get_e16(&s_fdEventType);
    }

    if(NULL != pTarget)
    {
        pTarget->m_ENotificationState = (EEventNotificationStateNotificationState) pDecoderStream->get_e1(&s_fdNotificationState);
    }
    else
    {
        pDecoderStream->get_e1(&s_fdNotificationState);
    }

    pDecoderStream->get_reserved(7);

}


void
CEventNotificationState::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CEventNotificationState::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


void
CEventNotificationState::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_e16((int)m_EEventType, &s_fdEventType);

    pEncoderStream->put_e1((int)m_ENotificationState, &s_fdNotificationState);

    pEncoderStream->put_reserved(7);

}




/*
*****************************************************************
**
** Parameter AntennaProperties
**
*****************************************************************
*/


const CTypeDescriptor
CAntennaProperties::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "AntennaProperties",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    662,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CAntennaProperties::s_apFieldDescriptorTable[] =
{

    &s_fdAntennaConnected,
    &s_fdAntennaID,
    &s_fdAntennaGain,
    NULL
};



const CFieldDescriptor
CAntennaProperties::s_fdAntennaConnected =
{
    CFieldDescriptor::FT_E1,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "AntennaConnected",	// m_pName
    g_estAntennaPropertiesAntennaConnected	// m_pEnumTable
};


const CFieldDescriptor
CAntennaProperties::s_fdAntennaID =
{
    CFieldDescriptor::FT_U8,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "AntennaID",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CAntennaProperties::s_fdAntennaGain =
{
    CFieldDescriptor::FT_S16,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "AntennaGain",	// m_pName
    NULL	// m_pEnumTable
};
CAntennaProperties::CAntennaProperties (void)
{
    m_pType = &s_typeDescriptor;

    m_EAntennaConnected = (EAntennaPropertiesAntennaConnected) 0;
    m_AntennaID = 0;
    m_AntennaGain = 0;
}

CAntennaProperties::~CAntennaProperties (void)
{
}


CElement *
CAntennaProperties::s_construct (void)
{
    return (CElement *) new CAntennaProperties();
}


void
CAntennaProperties::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CAntennaProperties * pTarget = (CAntennaProperties *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_EAntennaConnected = (EAntennaPropertiesAntennaConnected) pDecoderStream->get_e1(&s_fdAntennaConnected);
    }
    else
    {
        pDecoderStream->get_e1(&s_fdAntennaConnected);
    }

    pDecoderStream->get_reserved(7);

    if(NULL != pTarget)
    {
        pTarget->m_AntennaID = pDecoderStream->get_u8(&s_fdAntennaID);
    }
    else
    {
        pDecoderStream->get_u8(&s_fdAntennaID);
    }

    if(NULL != pTarget)
    {
        pTarget->m_AntennaGain = pDecoderStream->get_s16(&s_fdAntennaGain);
    }
    else
    {
        pDecoderStream->get_s16(&s_fdAntennaGain);
    }

}


void
CAntennaProperties::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CAntennaProperties::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


void
CAntennaProperties::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_e1((int)m_EAntennaConnected, &s_fdAntennaConnected);

    pEncoderStream->put_reserved(7);

    pEncoderStream->put_u8(m_AntennaID, &s_fdAntennaID);

    pEncoderStream->put_s16(m_AntennaGain, &s_fdAntennaGain);

}




/*
*****************************************************************
**
** Parameter AntennaConfiguration
**
*****************************************************************
*/


const CTypeDescriptor
CAntennaConfiguration::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "AntennaConfiguration",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    663,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CAntennaConfiguration::s_apFieldDescriptorTable[] =
{

    &s_fdAntennaID,
    &s_fdTransmitPowerIndex,
    &s_fdFrequencyIndexes,
    &s_fdForDataRateIndex,
    &s_fdRevDataRateIndex,
    &s_fdForModulationIndex,
    &s_fdRevDataEncodingIndex,
    NULL
};



const CFieldDescriptor
CAntennaConfiguration::s_fdAntennaID =
{
    CFieldDescriptor::FT_U8,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "AntennaID",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CAntennaConfiguration::s_fdTransmitPowerIndex =
{
    CFieldDescriptor::FT_U16,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "TransmitPowerIndex",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CAntennaConfiguration::s_fdFrequencyIndexes =
{
    CFieldDescriptor::FT_U16V,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "FrequencyIndexes",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CAntennaConfiguration::s_fdForDataRateIndex =
{
    CFieldDescriptor::FT_U16,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "ForDataRateIndex",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CAntennaConfiguration::s_fdRevDataRateIndex =
{
    CFieldDescriptor::FT_U16,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "RevDataRateIndex",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CAntennaConfiguration::s_fdForModulationIndex =
{
    CFieldDescriptor::FT_U16,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "ForModulationIndex",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CAntennaConfiguration::s_fdRevDataEncodingIndex =
{
    CFieldDescriptor::FT_U16,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "RevDataEncodingIndex",	// m_pName
    NULL	// m_pEnumTable
};
CAntennaConfiguration::CAntennaConfiguration (void)
{
    m_pType = &s_typeDescriptor;

    m_AntennaID = 0;
    m_TransmitPowerIndex = 0;
    m_ForDataRateIndex = 0;
    m_RevDataRateIndex = 0;
    m_ForModulationIndex = 0;
    m_RevDataEncodingIndex = 0;
}

CAntennaConfiguration::~CAntennaConfiguration (void)
{
}


CElement *
CAntennaConfiguration::s_construct (void)
{
    return (CElement *) new CAntennaConfiguration();
}


void
CAntennaConfiguration::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CAntennaConfiguration * pTarget = (CAntennaConfiguration *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_AntennaID = pDecoderStream->get_u8(&s_fdAntennaID);
    }
    else
    {
        pDecoderStream->get_u8(&s_fdAntennaID);
    }

    if(NULL != pTarget)
    {
        pTarget->m_TransmitPowerIndex = pDecoderStream->get_u16(&s_fdTransmitPowerIndex);
    }
    else
    {
        pDecoderStream->get_u16(&s_fdTransmitPowerIndex);
    }

    if(NULL != pTarget)
    {
        pTarget->m_FrequencyIndexes = pDecoderStream->get_u16v(&s_fdFrequencyIndexes);
    }
    else
    {
        pDecoderStream->get_u16v(&s_fdFrequencyIndexes);
    }

    if(NULL != pTarget)
    {
        pTarget->m_ForDataRateIndex = pDecoderStream->get_u16(&s_fdForDataRateIndex);
    }
    else
    {
        pDecoderStream->get_u16(&s_fdForDataRateIndex);
    }

    if(NULL != pTarget)
    {
        pTarget->m_RevDataRateIndex = pDecoderStream->get_u16(&s_fdRevDataRateIndex);
    }
    else
    {
        pDecoderStream->get_u16(&s_fdRevDataRateIndex);
    }

    if(NULL != pTarget)
    {
        pTarget->m_ForModulationIndex = pDecoderStream->get_u16(&s_fdForModulationIndex);
    }
    else
    {
        pDecoderStream->get_u16(&s_fdForModulationIndex);
    }

    if(NULL != pTarget)
    {
        pTarget->m_RevDataEncodingIndex = pDecoderStream->get_u16(&s_fdRevDataEncodingIndex);
    }
    else
    {
        pDecoderStream->get_u16(&s_fdRevDataEncodingIndex);
    }

}


void
CAntennaConfiguration::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CAntennaConfiguration::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


void
CAntennaConfiguration::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u8(m_AntennaID, &s_fdAntennaID);

    pEncoderStream->put_u16(m_TransmitPowerIndex, &s_fdTransmitPowerIndex);

    pEncoderStream->put_u16v(m_FrequencyIndexes, &s_fdFrequencyIndexes);

    pEncoderStream->put_u16(m_ForDataRateIndex, &s_fdForDataRateIndex);

    pEncoderStream->put_u16(m_RevDataRateIndex, &s_fdRevDataRateIndex);

    pEncoderStream->put_u16(m_ForModulationIndex, &s_fdForModulationIndex);

    pEncoderStream->put_u16(m_RevDataEncodingIndex, &s_fdRevDataEncodingIndex);

}




/*
*****************************************************************
**
** Parameter ModuleDepth
**
*****************************************************************
*/


const CTypeDescriptor
CModuleDepth::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "ModuleDepth",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    664,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CModuleDepth::s_apFieldDescriptorTable[] =
{

    &s_fdIndex,
    NULL
};



const CFieldDescriptor
CModuleDepth::s_fdIndex =
{
    CFieldDescriptor::FT_U16,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "Index",	// m_pName
    NULL	// m_pEnumTable
};
CModuleDepth::CModuleDepth (void)
{
    m_pType = &s_typeDescriptor;

    m_Index = 0;
}

CModuleDepth::~CModuleDepth (void)
{
}


CElement *
CModuleDepth::s_construct (void)
{
    return (CElement *) new CModuleDepth();
}


void
CModuleDepth::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CModuleDepth * pTarget = (CModuleDepth *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_Index = pDecoderStream->get_u16(&s_fdIndex);
    }
    else
    {
        pDecoderStream->get_u16(&s_fdIndex);
    }

}


void
CModuleDepth::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CModuleDepth::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


void
CModuleDepth::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u16(m_Index, &s_fdIndex);

}




/*
*****************************************************************
**
** Parameter Identification
**
*****************************************************************
*/


const CTypeDescriptor
CIdentification::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "Identification",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    665,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CIdentification::s_apFieldDescriptorTable[] =
{

    &s_fdDeviceName,
    NULL
};



const CFieldDescriptor
CIdentification::s_fdDeviceName =
{
    CFieldDescriptor::FT_UTF8V,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "DeviceName",	// m_pName
    NULL	// m_pEnumTable
};
CIdentification::CIdentification (void)
{
    m_pType = &s_typeDescriptor;

}

CIdentification::~CIdentification (void)
{
}


CElement *
CIdentification::s_construct (void)
{
    return (CElement *) new CIdentification();
}


void
CIdentification::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CIdentification * pTarget = (CIdentification *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_DeviceName = pDecoderStream->get_utf8v(&s_fdDeviceName);
    }
    else
    {
        pDecoderStream->get_utf8v(&s_fdDeviceName);
    }

}


void
CIdentification::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CIdentification::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


void
CIdentification::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_utf8v(m_DeviceName, &s_fdDeviceName);

}




/*
*****************************************************************
**
** Parameter AlarmConfiguration
**
*****************************************************************
*/


const CTypeDescriptor
CAlarmConfiguration::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "AlarmConfiguration",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    666,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CAlarmConfiguration::s_apFieldDescriptorTable[] =
{

    &s_fdAlarmMask,
    NULL
};



const CFieldDescriptor
CAlarmConfiguration::s_fdAlarmMask =
{
    CFieldDescriptor::FT_U8,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "AlarmMask",	// m_pName
    NULL	// m_pEnumTable
};
CAlarmConfiguration::CAlarmConfiguration (void)
{
    m_pType = &s_typeDescriptor;

    m_AlarmMask = 0;
    m_pAlarmThreshod = NULL;
}

CAlarmConfiguration::~CAlarmConfiguration (void)
{
}


CElement *
CAlarmConfiguration::s_construct (void)
{
    return (CElement *) new CAlarmConfiguration();
}


void
CAlarmConfiguration::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CAlarmConfiguration * pTarget = (CAlarmConfiguration *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_AlarmMask = pDecoderStream->get_u8(&s_fdAlarmMask);
    }
    else
    {
        pDecoderStream->get_u8(&s_fdAlarmMask);
    }

}


void
CAlarmConfiguration::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CAlarmConfiguration::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    // 0-1 of AlarmThreshod
    pType = &CAlarmThreshod::s_typeDescriptor;

    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pAlarmThreshod = (CAlarmThreshod *)*Cur++;
    }


    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


EResultCode
CAlarmConfiguration::setAlarmThreshod (
  CAlarmThreshod *     pValue)
{
    removeSubParameterFromAllList(m_pAlarmThreshod);
    delete m_pAlarmThreshod;
    m_pAlarmThreshod = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CAlarmConfiguration::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u8(m_AlarmMask, &s_fdAlarmMask);

    pType = &CAlarmThreshod::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameter(m_pAlarmThreshod, pType);

}




/*
*****************************************************************
**
** Parameter AlarmThreshod
**
*****************************************************************
*/


const CTypeDescriptor
CAlarmThreshod::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "AlarmThreshod",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    667,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CAlarmThreshod::s_apFieldDescriptorTable[] =
{

    &s_fdTemperatureMaxValue,
    &s_fdTemperatureMinValue,
    NULL
};



const CFieldDescriptor
CAlarmThreshod::s_fdTemperatureMaxValue =
{
    CFieldDescriptor::FT_S8,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "TemperatureMaxValue",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CAlarmThreshod::s_fdTemperatureMinValue =
{
    CFieldDescriptor::FT_S8,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "TemperatureMinValue",	// m_pName
    NULL	// m_pEnumTable
};
CAlarmThreshod::CAlarmThreshod (void)
{
    m_pType = &s_typeDescriptor;

    m_TemperatureMaxValue = 0;
    m_TemperatureMinValue = 0;
}

CAlarmThreshod::~CAlarmThreshod (void)
{
}


CElement *
CAlarmThreshod::s_construct (void)
{
    return (CElement *) new CAlarmThreshod();
}


void
CAlarmThreshod::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CAlarmThreshod * pTarget = (CAlarmThreshod *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_TemperatureMaxValue = pDecoderStream->get_s8(&s_fdTemperatureMaxValue);
    }
    else
    {
        pDecoderStream->get_s8(&s_fdTemperatureMaxValue);
    }

    if(NULL != pTarget)
    {
        pTarget->m_TemperatureMinValue = pDecoderStream->get_s8(&s_fdTemperatureMinValue);
    }
    else
    {
        pDecoderStream->get_s8(&s_fdTemperatureMinValue);
    }

}


void
CAlarmThreshod::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CAlarmThreshod::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


void
CAlarmThreshod::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_s8(m_TemperatureMaxValue, &s_fdTemperatureMaxValue);

    pEncoderStream->put_s8(m_TemperatureMinValue, &s_fdTemperatureMinValue);

}




/*
*****************************************************************
**
** Parameter CommunicationConfiguration
**
*****************************************************************
*/


const CTypeDescriptor
CCommunicationConfiguration::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "CommunicationConfiguration",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    668,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CCommunicationConfiguration::s_apFieldDescriptorTable[] =
{

    NULL
};

CCommunicationConfiguration::CCommunicationConfiguration (void)
{
    m_pType = &s_typeDescriptor;

    m_pNTPConfiguration = NULL;
}

CCommunicationConfiguration::~CCommunicationConfiguration (void)
{
}


CElement *
CCommunicationConfiguration::s_construct (void)
{
    return (CElement *) new CCommunicationConfiguration();
}


void
CCommunicationConfiguration::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CCommunicationConfiguration * pTarget = (CCommunicationConfiguration *) pTargetElement;


}


void
CCommunicationConfiguration::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CCommunicationConfiguration::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    // 0-N of CommLinkConfiguration
    pType = &CCommLinkConfiguration::s_typeDescriptor;

    while(Cur != End && (*Cur)->m_pType == pType)
    {
        m_listCommLinkConfiguration.push_back((CCommLinkConfiguration *)*Cur);
        Cur++;
    }


    // 0-N of choice EthernetConfiguration
    pType = NULL;

    while(Cur != End && CEthernetConfiguration::isMember(*Cur))
    {
        m_listEthernetConfiguration.push_back(*Cur);
        Cur++;
    }


    // 0-N of SerialPortConfiguration
    pType = &CSerialPortConfiguration::s_typeDescriptor;

    while(Cur != End && (*Cur)->m_pType == pType)
    {
        m_listSerialPortConfiguration.push_back((CSerialPortConfiguration *)*Cur);
        Cur++;
    }


    // 0-1 of NTPConfiguration
    pType = &CNTPConfiguration::s_typeDescriptor;

    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pNTPConfiguration = (CNTPConfiguration *)*Cur++;
    }


    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


EResultCode
CCommunicationConfiguration::addCommLinkConfiguration (
  CCommLinkConfiguration *     pValue)
{
    m_listCommLinkConfiguration.push_back(pValue);
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CCommunicationConfiguration::addEthernetConfiguration (
  CParameter *                  pValue)
{
    if(!CEthernetConfiguration::isMember(pValue))
    {
        return RC_InvalidChoiceMember;
    }

    m_listEthernetConfiguration.push_back(pValue);
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CCommunicationConfiguration::addSerialPortConfiguration (
  CSerialPortConfiguration *     pValue)
{
    m_listSerialPortConfiguration.push_back(pValue);
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CCommunicationConfiguration::setNTPConfiguration (
  CNTPConfiguration *     pValue)
{
    removeSubParameterFromAllList(m_pNTPConfiguration);
    delete m_pNTPConfiguration;
    m_pNTPConfiguration = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CCommunicationConfiguration::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pType = &CCommLinkConfiguration::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameterList((tListOfParameters *) &m_listCommLinkConfiguration, pType);

    pType = NULL;

    pEncoderStream->putOptionalSubParameterList((tListOfParameters *) &m_listEthernetConfiguration, pType);

    pType = &CSerialPortConfiguration::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameterList((tListOfParameters *) &m_listSerialPortConfiguration, pType);

    pType = &CNTPConfiguration::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameter(m_pNTPConfiguration, pType);

}




/*
*****************************************************************
**
** Parameter CommLinkConfiguration
**
*****************************************************************
*/


const CTypeDescriptor
CCommLinkConfiguration::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "CommLinkConfiguration",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    669,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CCommLinkConfiguration::s_apFieldDescriptorTable[] =
{

    &s_fdLinkType,
    NULL
};



const CFieldDescriptor
CCommLinkConfiguration::s_fdLinkType =
{
    CFieldDescriptor::FT_E8,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "LinkType",	// m_pName
    g_estLinkType	// m_pEnumTable
};
CCommLinkConfiguration::CCommLinkConfiguration (void)
{
    m_pType = &s_typeDescriptor;

    m_ELinkType = (ELinkType) 0;
    m_pKeepaliveSpec = NULL;
    m_pTcpLinkConfiguration = NULL;
    m_pSerialLinkConfiguration = NULL;
    m_pHttpLinkConfiguration = NULL;
}

CCommLinkConfiguration::~CCommLinkConfiguration (void)
{
}


CElement *
CCommLinkConfiguration::s_construct (void)
{
    return (CElement *) new CCommLinkConfiguration();
}


void
CCommLinkConfiguration::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CCommLinkConfiguration * pTarget = (CCommLinkConfiguration *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_ELinkType = (ELinkType) pDecoderStream->get_e8(&s_fdLinkType);
    }
    else
    {
        pDecoderStream->get_e8(&s_fdLinkType);
    }

}


void
CCommLinkConfiguration::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CCommLinkConfiguration::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    // 1 of KeepaliveSpec
    pType = &CKeepaliveSpec::s_typeDescriptor;

    if(Cur == End || (*Cur)->m_pType != pType)
    {
        goto missing;
    }
    m_pKeepaliveSpec = (CKeepaliveSpec *)*Cur++;


    // 0-1 of TcpLinkConfiguration
    pType = &CTcpLinkConfiguration::s_typeDescriptor;

    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pTcpLinkConfiguration = (CTcpLinkConfiguration *)*Cur++;
    }


    // 0-1 of SerialLinkConfiguration
    pType = &CSerialLinkConfiguration::s_typeDescriptor;

    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pSerialLinkConfiguration = (CSerialLinkConfiguration *)*Cur++;
    }


    // 0-1 of HttpLinkConfiguration
    pType = &CHttpLinkConfiguration::s_typeDescriptor;

    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pHttpLinkConfiguration = (CHttpLinkConfiguration *)*Cur++;
    }


    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


EResultCode
CCommLinkConfiguration::setKeepaliveSpec (
  CKeepaliveSpec *     pValue)
{
    removeSubParameterFromAllList(m_pKeepaliveSpec);
    delete m_pKeepaliveSpec;
    m_pKeepaliveSpec = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CCommLinkConfiguration::setTcpLinkConfiguration (
  CTcpLinkConfiguration *     pValue)
{
    removeSubParameterFromAllList(m_pTcpLinkConfiguration);
    delete m_pTcpLinkConfiguration;
    m_pTcpLinkConfiguration = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CCommLinkConfiguration::setSerialLinkConfiguration (
  CSerialLinkConfiguration *     pValue)
{
    removeSubParameterFromAllList(m_pSerialLinkConfiguration);
    delete m_pSerialLinkConfiguration;
    m_pSerialLinkConfiguration = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CCommLinkConfiguration::setHttpLinkConfiguration (
  CHttpLinkConfiguration *     pValue)
{
    removeSubParameterFromAllList(m_pHttpLinkConfiguration);
    delete m_pHttpLinkConfiguration;
    m_pHttpLinkConfiguration = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CCommLinkConfiguration::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_e8((int)m_ELinkType, &s_fdLinkType);

    pType = &CKeepaliveSpec::s_typeDescriptor;

    pEncoderStream->putRequiredSubParameter(m_pKeepaliveSpec, pType);

    pType = &CTcpLinkConfiguration::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameter(m_pTcpLinkConfiguration, pType);

    pType = &CSerialLinkConfiguration::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameter(m_pSerialLinkConfiguration, pType);

    pType = &CHttpLinkConfiguration::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameter(m_pHttpLinkConfiguration, pType);

}




/*
*****************************************************************
**
** Parameter KeepaliveSpec
**
*****************************************************************
*/


const CTypeDescriptor
CKeepaliveSpec::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "KeepaliveSpec",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    670,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CKeepaliveSpec::s_apFieldDescriptorTable[] =
{

    &s_fdKeepaliveTriggerType,
    &s_fdPeriodicTriggerValue,
    NULL
};



const CFieldDescriptor
CKeepaliveSpec::s_fdKeepaliveTriggerType =
{
    CFieldDescriptor::FT_E8,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "KeepaliveTriggerType",	// m_pName
    g_estKeepaliveTriggerType	// m_pEnumTable
};


const CFieldDescriptor
CKeepaliveSpec::s_fdPeriodicTriggerValue =
{
    CFieldDescriptor::FT_U32,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "PeriodicTriggerValue",	// m_pName
    NULL	// m_pEnumTable
};
CKeepaliveSpec::CKeepaliveSpec (void)
{
    m_pType = &s_typeDescriptor;

    m_EKeepaliveTriggerType = (EKeepaliveTriggerType) 0;
    m_PeriodicTriggerValue = 0;
}

CKeepaliveSpec::~CKeepaliveSpec (void)
{
}


CElement *
CKeepaliveSpec::s_construct (void)
{
    return (CElement *) new CKeepaliveSpec();
}


void
CKeepaliveSpec::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CKeepaliveSpec * pTarget = (CKeepaliveSpec *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_EKeepaliveTriggerType = (EKeepaliveTriggerType) pDecoderStream->get_e8(&s_fdKeepaliveTriggerType);
    }
    else
    {
        pDecoderStream->get_e8(&s_fdKeepaliveTriggerType);
    }

    if(NULL != pTarget)
    {
        pTarget->m_PeriodicTriggerValue = pDecoderStream->get_u32(&s_fdPeriodicTriggerValue);
    }
    else
    {
        pDecoderStream->get_u32(&s_fdPeriodicTriggerValue);
    }

}


void
CKeepaliveSpec::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CKeepaliveSpec::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


void
CKeepaliveSpec::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_e8((int)m_EKeepaliveTriggerType, &s_fdKeepaliveTriggerType);

    pEncoderStream->put_u32(m_PeriodicTriggerValue, &s_fdPeriodicTriggerValue);

}




/*
*****************************************************************
**
** Parameter TcpLinkConfiguration
**
*****************************************************************
*/


const CTypeDescriptor
CTcpLinkConfiguration::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "TcpLinkConfiguration",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    671,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CTcpLinkConfiguration::s_apFieldDescriptorTable[] =
{

    &s_fdCommMode,
    &s_fdIsSSL,
    NULL
};



const CFieldDescriptor
CTcpLinkConfiguration::s_fdCommMode =
{
    CFieldDescriptor::FT_E8,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "CommMode",	// m_pName
    g_estCommMode	// m_pEnumTable
};


const CFieldDescriptor
CTcpLinkConfiguration::s_fdIsSSL =
{
    CFieldDescriptor::FT_U1,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "IsSSL",	// m_pName
    NULL	// m_pEnumTable
};
CTcpLinkConfiguration::CTcpLinkConfiguration (void)
{
    m_pType = &s_typeDescriptor;

    m_ECommMode = (ECommMode) 0;
    m_IsSSL = 0;
    m_pClientModeConfiguration = NULL;
    m_pServerModeConfiguration = NULL;
}

CTcpLinkConfiguration::~CTcpLinkConfiguration (void)
{
}


CElement *
CTcpLinkConfiguration::s_construct (void)
{
    return (CElement *) new CTcpLinkConfiguration();
}


void
CTcpLinkConfiguration::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CTcpLinkConfiguration * pTarget = (CTcpLinkConfiguration *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_ECommMode = (ECommMode) pDecoderStream->get_e8(&s_fdCommMode);
    }
    else
    {
        pDecoderStream->get_e8(&s_fdCommMode);
    }

    if(NULL != pTarget)
    {
        pTarget->m_IsSSL = pDecoderStream->get_u1(&s_fdIsSSL);
    }
    else
    {
        pDecoderStream->get_u1(&s_fdIsSSL);
    }

    pDecoderStream->get_reserved(7);

}


void
CTcpLinkConfiguration::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CTcpLinkConfiguration::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    // 0-1 of ClientModeConfiguration
    pType = &CClientModeConfiguration::s_typeDescriptor;

    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pClientModeConfiguration = (CClientModeConfiguration *)*Cur++;
    }


    // 0-1 of ServerModeConfiguration
    pType = &CServerModeConfiguration::s_typeDescriptor;

    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pServerModeConfiguration = (CServerModeConfiguration *)*Cur++;
    }


    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


EResultCode
CTcpLinkConfiguration::setClientModeConfiguration (
  CClientModeConfiguration *     pValue)
{
    removeSubParameterFromAllList(m_pClientModeConfiguration);
    delete m_pClientModeConfiguration;
    m_pClientModeConfiguration = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CTcpLinkConfiguration::setServerModeConfiguration (
  CServerModeConfiguration *     pValue)
{
    removeSubParameterFromAllList(m_pServerModeConfiguration);
    delete m_pServerModeConfiguration;
    m_pServerModeConfiguration = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CTcpLinkConfiguration::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_e8((int)m_ECommMode, &s_fdCommMode);

    pEncoderStream->put_u1(m_IsSSL, &s_fdIsSSL);

    pEncoderStream->put_reserved(7);

    pType = &CClientModeConfiguration::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameter(m_pClientModeConfiguration, pType);

    pType = &CServerModeConfiguration::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameter(m_pServerModeConfiguration, pType);

}




/*
*****************************************************************
**
** Parameter ClientModeConfiguration
**
*****************************************************************
*/


const CTypeDescriptor
CClientModeConfiguration::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "ClientModeConfiguration",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    672,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CClientModeConfiguration::s_apFieldDescriptorTable[] =
{

    &s_fdPort,
    NULL
};



const CFieldDescriptor
CClientModeConfiguration::s_fdPort =
{
    CFieldDescriptor::FT_U16,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "Port",	// m_pName
    NULL	// m_pEnumTable
};
CClientModeConfiguration::CClientModeConfiguration (void)
{
    m_pType = &s_typeDescriptor;

    m_Port = 0;
    m_pIPAddress = NULL;
}

CClientModeConfiguration::~CClientModeConfiguration (void)
{
}


CElement *
CClientModeConfiguration::s_construct (void)
{
    return (CElement *) new CClientModeConfiguration();
}


void
CClientModeConfiguration::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CClientModeConfiguration * pTarget = (CClientModeConfiguration *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_Port = pDecoderStream->get_u16(&s_fdPort);
    }
    else
    {
        pDecoderStream->get_u16(&s_fdPort);
    }

}


void
CClientModeConfiguration::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CClientModeConfiguration::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    // 1 of IPAddress
    pType = &CIPAddress::s_typeDescriptor;

    if(Cur == End || (*Cur)->m_pType != pType)
    {
        goto missing;
    }
    m_pIPAddress = (CIPAddress *)*Cur++;


    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


EResultCode
CClientModeConfiguration::setIPAddress (
  CIPAddress *     pValue)
{
    removeSubParameterFromAllList(m_pIPAddress);
    delete m_pIPAddress;
    m_pIPAddress = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CClientModeConfiguration::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u16(m_Port, &s_fdPort);

    pType = &CIPAddress::s_typeDescriptor;

    pEncoderStream->putRequiredSubParameter(m_pIPAddress, pType);

}




/*
*****************************************************************
**
** Parameter IPAddress
**
*****************************************************************
*/


const CTypeDescriptor
CIPAddress::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "IPAddress",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    673,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CIPAddress::s_apFieldDescriptorTable[] =
{

    &s_fdVersion,
    &s_fdAddress,
    NULL
};



const CFieldDescriptor
CIPAddress::s_fdVersion =
{
    CFieldDescriptor::FT_E8,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "Version",	// m_pName
    g_estIPAddressVersion	// m_pEnumTable
};


const CFieldDescriptor
CIPAddress::s_fdAddress =
{
    CFieldDescriptor::FT_U32V,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "Address",	// m_pName
    NULL	// m_pEnumTable
};
CIPAddress::CIPAddress (void)
{
    m_pType = &s_typeDescriptor;

    m_EVersion = (EIPAddressVersion) 0;
}

CIPAddress::~CIPAddress (void)
{
}


CElement *
CIPAddress::s_construct (void)
{
    return (CElement *) new CIPAddress();
}


void
CIPAddress::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CIPAddress * pTarget = (CIPAddress *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_EVersion = (EIPAddressVersion) pDecoderStream->get_e8(&s_fdVersion);
    }
    else
    {
        pDecoderStream->get_e8(&s_fdVersion);
    }

    if(NULL != pTarget)
    {
        pTarget->m_Address = pDecoderStream->get_u32v(&s_fdAddress);
    }
    else
    {
        pDecoderStream->get_u32v(&s_fdAddress);
    }

}


void
CIPAddress::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CIPAddress::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


void
CIPAddress::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_e8((int)m_EVersion, &s_fdVersion);

    pEncoderStream->put_u32v(m_Address, &s_fdAddress);

}




/*
*****************************************************************
**
** Parameter ServerModeConfiguration
**
*****************************************************************
*/


const CTypeDescriptor
CServerModeConfiguration::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "ServerModeConfiguration",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    674,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CServerModeConfiguration::s_apFieldDescriptorTable[] =
{

    &s_fdPort,
    NULL
};



const CFieldDescriptor
CServerModeConfiguration::s_fdPort =
{
    CFieldDescriptor::FT_U16,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "Port",	// m_pName
    NULL	// m_pEnumTable
};
CServerModeConfiguration::CServerModeConfiguration (void)
{
    m_pType = &s_typeDescriptor;

    m_Port = 0;
}

CServerModeConfiguration::~CServerModeConfiguration (void)
{
}


CElement *
CServerModeConfiguration::s_construct (void)
{
    return (CElement *) new CServerModeConfiguration();
}


void
CServerModeConfiguration::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CServerModeConfiguration * pTarget = (CServerModeConfiguration *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_Port = pDecoderStream->get_u16(&s_fdPort);
    }
    else
    {
        pDecoderStream->get_u16(&s_fdPort);
    }

}


void
CServerModeConfiguration::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CServerModeConfiguration::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


void
CServerModeConfiguration::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u16(m_Port, &s_fdPort);

}




/*
*****************************************************************
**
** Parameter SerialLinkConfiguration
**
*****************************************************************
*/


const CTypeDescriptor
CSerialLinkConfiguration::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "SerialLinkConfiguration",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    675,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CSerialLinkConfiguration::s_apFieldDescriptorTable[] =
{

    &s_fdIfIndex,
    &s_fdSrcAddr,
    &s_fdDstAddr,
    NULL
};



const CFieldDescriptor
CSerialLinkConfiguration::s_fdIfIndex =
{
    CFieldDescriptor::FT_U8,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "IfIndex",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CSerialLinkConfiguration::s_fdSrcAddr =
{
    CFieldDescriptor::FT_U8,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "SrcAddr",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CSerialLinkConfiguration::s_fdDstAddr =
{
    CFieldDescriptor::FT_U8,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "DstAddr",	// m_pName
    NULL	// m_pEnumTable
};
CSerialLinkConfiguration::CSerialLinkConfiguration (void)
{
    m_pType = &s_typeDescriptor;

    m_IfIndex = 0;
    m_SrcAddr = 0;
    m_DstAddr = 0;
}

CSerialLinkConfiguration::~CSerialLinkConfiguration (void)
{
}


CElement *
CSerialLinkConfiguration::s_construct (void)
{
    return (CElement *) new CSerialLinkConfiguration();
}


void
CSerialLinkConfiguration::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CSerialLinkConfiguration * pTarget = (CSerialLinkConfiguration *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_IfIndex = pDecoderStream->get_u8(&s_fdIfIndex);
    }
    else
    {
        pDecoderStream->get_u8(&s_fdIfIndex);
    }

    if(NULL != pTarget)
    {
        pTarget->m_SrcAddr = pDecoderStream->get_u8(&s_fdSrcAddr);
    }
    else
    {
        pDecoderStream->get_u8(&s_fdSrcAddr);
    }

    if(NULL != pTarget)
    {
        pTarget->m_DstAddr = pDecoderStream->get_u8(&s_fdDstAddr);
    }
    else
    {
        pDecoderStream->get_u8(&s_fdDstAddr);
    }

}


void
CSerialLinkConfiguration::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CSerialLinkConfiguration::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


void
CSerialLinkConfiguration::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u8(m_IfIndex, &s_fdIfIndex);

    pEncoderStream->put_u8(m_SrcAddr, &s_fdSrcAddr);

    pEncoderStream->put_u8(m_DstAddr, &s_fdDstAddr);

}




/*
*****************************************************************
**
** Parameter HttpLinkConfiguration
**
*****************************************************************
*/


const CTypeDescriptor
CHttpLinkConfiguration::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "HttpLinkConfiguration",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    676,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CHttpLinkConfiguration::s_apFieldDescriptorTable[] =
{

    &s_fdServerUrl,
    NULL
};



const CFieldDescriptor
CHttpLinkConfiguration::s_fdServerUrl =
{
    CFieldDescriptor::FT_UTF8V,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "ServerUrl",	// m_pName
    NULL	// m_pEnumTable
};
CHttpLinkConfiguration::CHttpLinkConfiguration (void)
{
    m_pType = &s_typeDescriptor;

}

CHttpLinkConfiguration::~CHttpLinkConfiguration (void)
{
}


CElement *
CHttpLinkConfiguration::s_construct (void)
{
    return (CElement *) new CHttpLinkConfiguration();
}


void
CHttpLinkConfiguration::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CHttpLinkConfiguration * pTarget = (CHttpLinkConfiguration *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_ServerUrl = pDecoderStream->get_utf8v(&s_fdServerUrl);
    }
    else
    {
        pDecoderStream->get_utf8v(&s_fdServerUrl);
    }

}


void
CHttpLinkConfiguration::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CHttpLinkConfiguration::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


void
CHttpLinkConfiguration::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_utf8v(m_ServerUrl, &s_fdServerUrl);

}




/*
*****************************************************************
**
** Parameter EthernetIpv4Configuration
**
*****************************************************************
*/


const CTypeDescriptor
CEthernetIpv4Configuration::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "EthernetIpv4Configuration",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    677,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CEthernetIpv4Configuration::s_apFieldDescriptorTable[] =
{

    &s_fdIfIndex,
    &s_fdIPAddress,
    &s_fdIPMask,
    &s_fdGateWayAddr,
    &s_fdDNSAddr,
    &s_fdIsDHCP,
    NULL
};



const CFieldDescriptor
CEthernetIpv4Configuration::s_fdIfIndex =
{
    CFieldDescriptor::FT_U8,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "IfIndex",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CEthernetIpv4Configuration::s_fdIPAddress =
{
    CFieldDescriptor::FT_U32,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "IPAddress",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CEthernetIpv4Configuration::s_fdIPMask =
{
    CFieldDescriptor::FT_U32,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "IPMask",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CEthernetIpv4Configuration::s_fdGateWayAddr =
{
    CFieldDescriptor::FT_U32,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "GateWayAddr",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CEthernetIpv4Configuration::s_fdDNSAddr =
{
    CFieldDescriptor::FT_U32,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "DNSAddr",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CEthernetIpv4Configuration::s_fdIsDHCP =
{
    CFieldDescriptor::FT_U1,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "IsDHCP",	// m_pName
    NULL	// m_pEnumTable
};
CEthernetIpv4Configuration::CEthernetIpv4Configuration (void)
{
    m_pType = &s_typeDescriptor;

    m_IfIndex = 0;
    m_IPAddress = 0;
    m_IPMask = 0;
    m_GateWayAddr = 0;
    m_DNSAddr = 0;
    m_IsDHCP = 0;
}

CEthernetIpv4Configuration::~CEthernetIpv4Configuration (void)
{
}


CElement *
CEthernetIpv4Configuration::s_construct (void)
{
    return (CElement *) new CEthernetIpv4Configuration();
}


void
CEthernetIpv4Configuration::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CEthernetIpv4Configuration * pTarget = (CEthernetIpv4Configuration *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_IfIndex = pDecoderStream->get_u8(&s_fdIfIndex);
    }
    else
    {
        pDecoderStream->get_u8(&s_fdIfIndex);
    }

    if(NULL != pTarget)
    {
        pTarget->m_IPAddress = pDecoderStream->get_u32(&s_fdIPAddress);
    }
    else
    {
        pDecoderStream->get_u32(&s_fdIPAddress);
    }

    if(NULL != pTarget)
    {
        pTarget->m_IPMask = pDecoderStream->get_u32(&s_fdIPMask);
    }
    else
    {
        pDecoderStream->get_u32(&s_fdIPMask);
    }

    if(NULL != pTarget)
    {
        pTarget->m_GateWayAddr = pDecoderStream->get_u32(&s_fdGateWayAddr);
    }
    else
    {
        pDecoderStream->get_u32(&s_fdGateWayAddr);
    }

    if(NULL != pTarget)
    {
        pTarget->m_DNSAddr = pDecoderStream->get_u32(&s_fdDNSAddr);
    }
    else
    {
        pDecoderStream->get_u32(&s_fdDNSAddr);
    }

    if(NULL != pTarget)
    {
        pTarget->m_IsDHCP = pDecoderStream->get_u1(&s_fdIsDHCP);
    }
    else
    {
        pDecoderStream->get_u1(&s_fdIsDHCP);
    }

    pDecoderStream->get_reserved(7);

}


void
CEthernetIpv4Configuration::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CEthernetIpv4Configuration::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


void
CEthernetIpv4Configuration::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u8(m_IfIndex, &s_fdIfIndex);

    pEncoderStream->put_u32(m_IPAddress, &s_fdIPAddress);

    pEncoderStream->put_u32(m_IPMask, &s_fdIPMask);

    pEncoderStream->put_u32(m_GateWayAddr, &s_fdGateWayAddr);

    pEncoderStream->put_u32(m_DNSAddr, &s_fdDNSAddr);

    pEncoderStream->put_u1(m_IsDHCP, &s_fdIsDHCP);

    pEncoderStream->put_reserved(7);

}




/*
*****************************************************************
**
** Parameter EthernetIpv6Configuration
**
*****************************************************************
*/


const CTypeDescriptor
CEthernetIpv6Configuration::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "EthernetIpv6Configuration",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    678,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CEthernetIpv6Configuration::s_apFieldDescriptorTable[] =
{

    &s_fdIfIndex,
    &s_fdIPAddress,
    &s_fdIPMask,
    &s_fdGateWayAddr,
    &s_fdDNSAddr,
    &s_fdIsDHCP,
    NULL
};



const CFieldDescriptor
CEthernetIpv6Configuration::s_fdIfIndex =
{
    CFieldDescriptor::FT_U8,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "IfIndex",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CEthernetIpv6Configuration::s_fdIPAddress =
{
    CFieldDescriptor::FT_U32V,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "IPAddress",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CEthernetIpv6Configuration::s_fdIPMask =
{
    CFieldDescriptor::FT_U8,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "IPMask",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CEthernetIpv6Configuration::s_fdGateWayAddr =
{
    CFieldDescriptor::FT_U32V,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "GateWayAddr",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CEthernetIpv6Configuration::s_fdDNSAddr =
{
    CFieldDescriptor::FT_U32V,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "DNSAddr",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CEthernetIpv6Configuration::s_fdIsDHCP =
{
    CFieldDescriptor::FT_U1,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "IsDHCP",	// m_pName
    NULL	// m_pEnumTable
};
CEthernetIpv6Configuration::CEthernetIpv6Configuration (void)
{
    m_pType = &s_typeDescriptor;

    m_IfIndex = 0;
    m_IPMask = 0;
    m_IsDHCP = 0;
}

CEthernetIpv6Configuration::~CEthernetIpv6Configuration (void)
{
}


CElement *
CEthernetIpv6Configuration::s_construct (void)
{
    return (CElement *) new CEthernetIpv6Configuration();
}


void
CEthernetIpv6Configuration::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CEthernetIpv6Configuration * pTarget = (CEthernetIpv6Configuration *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_IfIndex = pDecoderStream->get_u8(&s_fdIfIndex);
    }
    else
    {
        pDecoderStream->get_u8(&s_fdIfIndex);
    }

    if(NULL != pTarget)
    {
        pTarget->m_IPAddress = pDecoderStream->get_u32v(&s_fdIPAddress);
    }
    else
    {
        pDecoderStream->get_u32v(&s_fdIPAddress);
    }

    if(NULL != pTarget)
    {
        pTarget->m_IPMask = pDecoderStream->get_u8(&s_fdIPMask);
    }
    else
    {
        pDecoderStream->get_u8(&s_fdIPMask);
    }

    if(NULL != pTarget)
    {
        pTarget->m_GateWayAddr = pDecoderStream->get_u32v(&s_fdGateWayAddr);
    }
    else
    {
        pDecoderStream->get_u32v(&s_fdGateWayAddr);
    }

    if(NULL != pTarget)
    {
        pTarget->m_DNSAddr = pDecoderStream->get_u32v(&s_fdDNSAddr);
    }
    else
    {
        pDecoderStream->get_u32v(&s_fdDNSAddr);
    }

    if(NULL != pTarget)
    {
        pTarget->m_IsDHCP = pDecoderStream->get_u1(&s_fdIsDHCP);
    }
    else
    {
        pDecoderStream->get_u1(&s_fdIsDHCP);
    }

    pDecoderStream->get_reserved(7);

}


void
CEthernetIpv6Configuration::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CEthernetIpv6Configuration::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


void
CEthernetIpv6Configuration::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u8(m_IfIndex, &s_fdIfIndex);

    pEncoderStream->put_u32v(m_IPAddress, &s_fdIPAddress);

    pEncoderStream->put_u8(m_IPMask, &s_fdIPMask);

    pEncoderStream->put_u32v(m_GateWayAddr, &s_fdGateWayAddr);

    pEncoderStream->put_u32v(m_DNSAddr, &s_fdDNSAddr);

    pEncoderStream->put_u1(m_IsDHCP, &s_fdIsDHCP);

    pEncoderStream->put_reserved(7);

}




/*
*****************************************************************
**
** Parameter NTPConfiguration
**
*****************************************************************
*/


const CTypeDescriptor
CNTPConfiguration::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "NTPConfiguration",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    679,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CNTPConfiguration::s_apFieldDescriptorTable[] =
{

    &s_fdNtpPeriodicTime,
    NULL
};



const CFieldDescriptor
CNTPConfiguration::s_fdNtpPeriodicTime =
{
    CFieldDescriptor::FT_U32,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "NtpPeriodicTime",	// m_pName
    NULL	// m_pEnumTable
};
CNTPConfiguration::CNTPConfiguration (void)
{
    m_pType = &s_typeDescriptor;

    m_NtpPeriodicTime = 0;
}

CNTPConfiguration::~CNTPConfiguration (void)
{
}


CElement *
CNTPConfiguration::s_construct (void)
{
    return (CElement *) new CNTPConfiguration();
}


void
CNTPConfiguration::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CNTPConfiguration * pTarget = (CNTPConfiguration *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_NtpPeriodicTime = pDecoderStream->get_u32(&s_fdNtpPeriodicTime);
    }
    else
    {
        pDecoderStream->get_u32(&s_fdNtpPeriodicTime);
    }

}


void
CNTPConfiguration::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CNTPConfiguration::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    // 1-N of IPAddress
    pType = &CIPAddress::s_typeDescriptor;

    if(Cur == End || (*Cur)->m_pType != pType)
    {
        goto missing;
    }
    while(Cur != End && (*Cur)->m_pType == pType)
    {
        m_listIPAddress.push_back((CIPAddress *)*Cur);
        Cur++;
    }


    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


EResultCode
CNTPConfiguration::addIPAddress (
  CIPAddress *     pValue)
{
    m_listIPAddress.push_back(pValue);
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CNTPConfiguration::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u32(m_NtpPeriodicTime, &s_fdNtpPeriodicTime);

    pType = &CIPAddress::s_typeDescriptor;

    pEncoderStream->putRequiredSubParameterList((tListOfParameters *) &m_listIPAddress, pType);

}




/*
*****************************************************************
**
** Parameter SerialPortConfiguration
**
*****************************************************************
*/


const CTypeDescriptor
CSerialPortConfiguration::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "SerialPortConfiguration",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    680,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CSerialPortConfiguration::s_apFieldDescriptorTable[] =
{

    &s_fdIfIndex,
    &s_fdAttributeIndex,
    NULL
};



const CFieldDescriptor
CSerialPortConfiguration::s_fdIfIndex =
{
    CFieldDescriptor::FT_U8,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "IfIndex",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CSerialPortConfiguration::s_fdAttributeIndex =
{
    CFieldDescriptor::FT_U8,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "AttributeIndex",	// m_pName
    NULL	// m_pEnumTable
};
CSerialPortConfiguration::CSerialPortConfiguration (void)
{
    m_pType = &s_typeDescriptor;

    m_IfIndex = 0;
    m_AttributeIndex = 0;
}

CSerialPortConfiguration::~CSerialPortConfiguration (void)
{
}


CElement *
CSerialPortConfiguration::s_construct (void)
{
    return (CElement *) new CSerialPortConfiguration();
}


void
CSerialPortConfiguration::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CSerialPortConfiguration * pTarget = (CSerialPortConfiguration *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_IfIndex = pDecoderStream->get_u8(&s_fdIfIndex);
    }
    else
    {
        pDecoderStream->get_u8(&s_fdIfIndex);
    }

    if(NULL != pTarget)
    {
        pTarget->m_AttributeIndex = pDecoderStream->get_u8(&s_fdAttributeIndex);
    }
    else
    {
        pDecoderStream->get_u8(&s_fdAttributeIndex);
    }

}


void
CSerialPortConfiguration::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CSerialPortConfiguration::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


void
CSerialPortConfiguration::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u8(m_IfIndex, &s_fdIfIndex);

    pEncoderStream->put_u8(m_AttributeIndex, &s_fdAttributeIndex);

}




/*
*****************************************************************
**
** Parameter SecurityModuleConfiguration
**
*****************************************************************
*/


const CTypeDescriptor
CSecurityModuleConfiguration::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "SecurityModuleConfiguration",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    684,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CSecurityModuleConfiguration::s_apFieldDescriptorTable[] =
{

    NULL
};

CSecurityModuleConfiguration::CSecurityModuleConfiguration (void)
{
    m_pType = &s_typeDescriptor;

    m_pGenaralConfigData = NULL;
}

CSecurityModuleConfiguration::~CSecurityModuleConfiguration (void)
{
}


CElement *
CSecurityModuleConfiguration::s_construct (void)
{
    return (CElement *) new CSecurityModuleConfiguration();
}


void
CSecurityModuleConfiguration::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CSecurityModuleConfiguration * pTarget = (CSecurityModuleConfiguration *) pTargetElement;


}


void
CSecurityModuleConfiguration::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CSecurityModuleConfiguration::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    // 0-1 of GenaralConfigData
    pType = &CGenaralConfigData::s_typeDescriptor;

    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pGenaralConfigData = (CGenaralConfigData *)*Cur++;
    }


    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


EResultCode
CSecurityModuleConfiguration::setGenaralConfigData (
  CGenaralConfigData *     pValue)
{
    removeSubParameterFromAllList(m_pGenaralConfigData);
    delete m_pGenaralConfigData;
    m_pGenaralConfigData = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CSecurityModuleConfiguration::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pType = &CGenaralConfigData::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameter(m_pGenaralConfigData, pType);

}





/*
*****************************************************************
**
** Parameter GenaralConfigData
**
*****************************************************************
*/


const CTypeDescriptor
CGenaralConfigData::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "GenaralConfigData",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    685,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CGenaralConfigData::s_apFieldDescriptorTable[] =
{

    NULL
};

CGenaralConfigData::CGenaralConfigData (void)
{
    m_pType = &s_typeDescriptor;

    m_pRTCTime = NULL;
    m_pSecurityModuleSN = NULL;
    m_pReadMode = NULL;
}

CGenaralConfigData::~CGenaralConfigData (void)
{
}


CElement *
CGenaralConfigData::s_construct (void)
{
    return (CElement *) new CGenaralConfigData();
}


void
CGenaralConfigData::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CGenaralConfigData * pTarget = (CGenaralConfigData *) pTargetElement;


}


void
CGenaralConfigData::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CGenaralConfigData::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    // 0-1 of RTCTime
    pType = &CRTCTime::s_typeDescriptor;

    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pRTCTime = (CRTCTime *)*Cur++;
    }


    // 0-1 of SecurityModuleSN
    pType = &CSecurityModuleSN::s_typeDescriptor;

    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pSecurityModuleSN = (CSecurityModuleSN *)*Cur++;
    }


    // 0-1 of ReadMode
    pType = &CReadMode::s_typeDescriptor;

    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pReadMode = (CReadMode *)*Cur++;
    }


    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


EResultCode
CGenaralConfigData::setRTCTime (
  CRTCTime *     pValue)
{
    removeSubParameterFromAllList(m_pRTCTime);
    delete m_pRTCTime;
    m_pRTCTime = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CGenaralConfigData::setSecurityModuleSN (
  CSecurityModuleSN *     pValue)
{
    removeSubParameterFromAllList(m_pSecurityModuleSN);
    delete m_pSecurityModuleSN;
    m_pSecurityModuleSN = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CGenaralConfigData::setReadMode (
  CReadMode *     pValue)
{
    removeSubParameterFromAllList(m_pReadMode);
    delete m_pReadMode;
    m_pReadMode = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CGenaralConfigData::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pType = &CRTCTime::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameter(m_pRTCTime, pType);

    pType = &CSecurityModuleSN::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameter(m_pSecurityModuleSN, pType);

    pType = &CReadMode::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameter(m_pReadMode, pType);

}




/*
*****************************************************************
**
** Parameter RTCTime
**
*****************************************************************
*/


const CTypeDescriptor
CRTCTime::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "RTCTime",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    686,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CRTCTime::s_apFieldDescriptorTable[] =
{

    &s_fdSeconds,
    NULL
};



const CFieldDescriptor
CRTCTime::s_fdSeconds =
{
    CFieldDescriptor::FT_U64,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "Seconds",	// m_pName
    NULL	// m_pEnumTable
};
CRTCTime::CRTCTime (void)
{
    m_pType = &s_typeDescriptor;

    m_Seconds = 0;
}

CRTCTime::~CRTCTime (void)
{
}


CElement *
CRTCTime::s_construct (void)
{
    return (CElement *) new CRTCTime();
}


void
CRTCTime::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CRTCTime * pTarget = (CRTCTime *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_Seconds = pDecoderStream->get_u64(&s_fdSeconds);
    }
    else
    {
        pDecoderStream->get_u64(&s_fdSeconds);
    }

}


void
CRTCTime::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CRTCTime::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


void
CRTCTime::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u64(m_Seconds, &s_fdSeconds);

}




/*
*****************************************************************
**
** Parameter SecurityModuleSN
**
*****************************************************************
*/


const CTypeDescriptor
CSecurityModuleSN::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "SecurityModuleSN",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    687,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CSecurityModuleSN::s_apFieldDescriptorTable[] =
{

    &s_fdSerialNumber,
    NULL
};



const CFieldDescriptor
CSecurityModuleSN::s_fdSerialNumber =
{
    CFieldDescriptor::FT_U8V,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "SerialNumber",	// m_pName
    NULL	// m_pEnumTable
};
CSecurityModuleSN::CSecurityModuleSN (void)
{
    m_pType = &s_typeDescriptor;

}

CSecurityModuleSN::~CSecurityModuleSN (void)
{
}


CElement *
CSecurityModuleSN::s_construct (void)
{
    return (CElement *) new CSecurityModuleSN();
}


void
CSecurityModuleSN::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CSecurityModuleSN * pTarget = (CSecurityModuleSN *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_SerialNumber = pDecoderStream->get_u8v(&s_fdSerialNumber);
    }
    else
    {
        pDecoderStream->get_u8v(&s_fdSerialNumber);
    }

}


void
CSecurityModuleSN::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CSecurityModuleSN::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


void
CSecurityModuleSN::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u8v(m_SerialNumber, &s_fdSerialNumber);

}




/*
*****************************************************************
**
** Parameter ReadMode
**
*****************************************************************
*/


const CTypeDescriptor
CReadMode::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "ReadMode",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    688,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CReadMode::s_apFieldDescriptorTable[] =
{

    &s_fdRepeatReadFlag,
    &s_fdTimer,
    NULL
};



const CFieldDescriptor
CReadMode::s_fdRepeatReadFlag =
{
    CFieldDescriptor::FT_U1,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "RepeatReadFlag",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CReadMode::s_fdTimer =
{
    CFieldDescriptor::FT_U32,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "Timer",	// m_pName
    NULL	// m_pEnumTable
};
CReadMode::CReadMode (void)
{
    m_pType = &s_typeDescriptor;

    m_RepeatReadFlag = 0;
    m_Timer = 0;
}

CReadMode::~CReadMode (void)
{
}


CElement *
CReadMode::s_construct (void)
{
    return (CElement *) new CReadMode();
}


void
CReadMode::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CReadMode * pTarget = (CReadMode *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_RepeatReadFlag = pDecoderStream->get_u1(&s_fdRepeatReadFlag);
    }
    else
    {
        pDecoderStream->get_u1(&s_fdRepeatReadFlag);
    }

    pDecoderStream->get_reserved(7);

    if(NULL != pTarget)
    {
        pTarget->m_Timer = pDecoderStream->get_u32(&s_fdTimer);
    }
    else
    {
        pDecoderStream->get_u32(&s_fdTimer);
    }

}


void
CReadMode::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CReadMode::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


void
CReadMode::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u1(m_RepeatReadFlag, &s_fdRepeatReadFlag);

    pEncoderStream->put_reserved(7);

    pEncoderStream->put_u32(m_Timer, &s_fdTimer);

}






/*
*****************************************************************
**
** Parameter VersionInfo
**
*****************************************************************
*/


const CTypeDescriptor
CVersionInfo::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "VersionInfo",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    700,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CVersionInfo::s_apFieldDescriptorTable[] =
{

    &s_fdVersionData,
    &s_fdUsedOrSpare,
    &s_fdSetUse,
    &s_fdHasRun,
    &s_fdCanRun,
    &s_fdVerDescInfo,
    NULL
};



const CFieldDescriptor
CVersionInfo::s_fdVersionData =
{
    CFieldDescriptor::FT_U8V,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "VersionData",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CVersionInfo::s_fdUsedOrSpare =
{
    CFieldDescriptor::FT_E1,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "UsedOrSpare",	// m_pName
    g_estVersionInfoUsedOrSpare	// m_pEnumTable
};


const CFieldDescriptor
CVersionInfo::s_fdSetUse =
{
    CFieldDescriptor::FT_E1,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "SetUse",	// m_pName
    g_estVersionInfoSetUse	// m_pEnumTable
};


const CFieldDescriptor
CVersionInfo::s_fdHasRun =
{
    CFieldDescriptor::FT_E1,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "HasRun",	// m_pName
    g_estVersionInfoHasRun	// m_pEnumTable
};


const CFieldDescriptor
CVersionInfo::s_fdCanRun =
{
    CFieldDescriptor::FT_E1,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "CanRun",	// m_pName
    g_estVersionInfoCanRun	// m_pEnumTable
};


const CFieldDescriptor
CVersionInfo::s_fdVerDescInfo =
{
    CFieldDescriptor::FT_UTF8V,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "VerDescInfo",	// m_pName
    NULL	// m_pEnumTable
};
CVersionInfo::CVersionInfo (void)
{
    m_pType = &s_typeDescriptor;

    m_eUsedOrSpare = (EVersionInfoUsedOrSpare) 0;
    m_eSetUse = (EVersionInfoSetUse) 0;
    m_eHasRun = (EVersionInfoHasRun) 0;
    m_eCanRun = (EVersionInfoCanRun) 0;
}

CVersionInfo::~CVersionInfo (void)
{
}


CElement *
CVersionInfo::s_construct (void)
{
    return (CElement *) new CVersionInfo();
}


void
CVersionInfo::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CVersionInfo * pTarget = (CVersionInfo *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_VersionData = pDecoderStream->get_u8v(&s_fdVersionData);
    }
    else
    {
        pDecoderStream->get_u8v(&s_fdVersionData);
    }

    if(NULL != pTarget)
    {
        pTarget->m_eUsedOrSpare = (EVersionInfoUsedOrSpare) pDecoderStream->get_e1(&s_fdUsedOrSpare);
    }
    else
    {
        pDecoderStream->get_e1(&s_fdUsedOrSpare);
    }

    if(NULL != pTarget)
    {
        pTarget->m_eSetUse = (EVersionInfoSetUse) pDecoderStream->get_e1(&s_fdSetUse);
    }
    else
    {
        pDecoderStream->get_e1(&s_fdSetUse);
    }

    if(NULL != pTarget)
    {
        pTarget->m_eHasRun = (EVersionInfoHasRun) pDecoderStream->get_e1(&s_fdHasRun);
    }
    else
    {
        pDecoderStream->get_e1(&s_fdHasRun);
    }

    if(NULL != pTarget)
    {
        pTarget->m_eCanRun = (EVersionInfoCanRun) pDecoderStream->get_e1(&s_fdCanRun);
    }
    else
    {
        pDecoderStream->get_e1(&s_fdCanRun);
    }

    pDecoderStream->get_reserved(4);

    if(NULL != pTarget)
    {
        pTarget->m_VerDescInfo = pDecoderStream->get_utf8v(&s_fdVerDescInfo);
    }
    else
    {
        pDecoderStream->get_utf8v(&s_fdVerDescInfo);
    }

}


void
CVersionInfo::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CVersionInfo::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


void
CVersionInfo::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u8v(m_VersionData, &s_fdVersionData);

    pEncoderStream->put_e1((int)m_eUsedOrSpare, &s_fdUsedOrSpare);

    pEncoderStream->put_e1((int)m_eSetUse, &s_fdSetUse);

    pEncoderStream->put_e1((int)m_eHasRun, &s_fdHasRun);

    pEncoderStream->put_e1((int)m_eCanRun, &s_fdCanRun);

    pEncoderStream->put_reserved(4);

    pEncoderStream->put_utf8v(m_VerDescInfo, &s_fdVerDescInfo);

}


/*
*****************************************************************
**
** Parameter VersionDownload
**
*****************************************************************
*/


const CTypeDescriptor
CVersionDownload::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "VersionDownload",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    701,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CVersionDownload::s_apFieldDescriptorTable[] =
{

    &s_fdServerType,
    &s_fdUserName,
    &s_fdUserPass,
    &s_fdVersionPath,
    &s_fdServerPort,
    NULL
};



const CFieldDescriptor
CVersionDownload::s_fdServerType =
{
    CFieldDescriptor::FT_E8,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "ServerType",	// m_pName
    g_estVersionDownloadServerType	// m_pEnumTable
};


const CFieldDescriptor
CVersionDownload::s_fdUserName =
{
    CFieldDescriptor::FT_UTF8V,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "UserName",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CVersionDownload::s_fdUserPass =
{
    CFieldDescriptor::FT_UTF8V,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "UserPass",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CVersionDownload::s_fdVersionPath =
{
    CFieldDescriptor::FT_UTF8V,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "VersionPath",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CVersionDownload::s_fdServerPort =
{
    CFieldDescriptor::FT_U16,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "ServerPort",	// m_pName
    NULL	// m_pEnumTable
};
CVersionDownload::CVersionDownload (void)
{
    m_pType = &s_typeDescriptor;

    m_EServerType = (EVersionDownloadServerType) 0;
    m_ServerPort = 0;
    m_pIPAddress = NULL;
}

CVersionDownload::~CVersionDownload (void)
{
}


CElement *
CVersionDownload::s_construct (void)
{
    return (CElement *) new CVersionDownload();
}


void
CVersionDownload::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CVersionDownload * pTarget = (CVersionDownload *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_EServerType = (EVersionDownloadServerType) pDecoderStream->get_e8(&s_fdServerType);
    }
    else
    {
        pDecoderStream->get_e8(&s_fdServerType);
    }

    if(NULL != pTarget)
    {
        pTarget->m_UserName = pDecoderStream->get_utf8v(&s_fdUserName);
    }
    else
    {
        pDecoderStream->get_utf8v(&s_fdUserName);
    }

    if(NULL != pTarget)
    {
        pTarget->m_UserPass = pDecoderStream->get_utf8v(&s_fdUserPass);
    }
    else
    {
        pDecoderStream->get_utf8v(&s_fdUserPass);
    }

    if(NULL != pTarget)
    {
        pTarget->m_VersionPath = pDecoderStream->get_utf8v(&s_fdVersionPath);
    }
    else
    {
        pDecoderStream->get_utf8v(&s_fdVersionPath);
    }

    if(NULL != pTarget)
    {
        pTarget->m_ServerPort = pDecoderStream->get_u16(&s_fdServerPort);
    }
    else
    {
        pDecoderStream->get_u16(&s_fdServerPort);
    }

}


void
CVersionDownload::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CVersionDownload::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    // 1 of IPAddress
    pType = &CIPAddress::s_typeDescriptor;

    if(Cur == End || (*Cur)->m_pType != pType)
    {
        goto missing;
    }
    m_pIPAddress = (CIPAddress *)*Cur++;


    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


EResultCode
CVersionDownload::setIPAddress (
  CIPAddress *     pValue)
{
    removeSubParameterFromAllList(m_pIPAddress);
    delete m_pIPAddress;
    m_pIPAddress = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CVersionDownload::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_e8((int)m_EServerType, &s_fdServerType);

    pEncoderStream->put_utf8v(m_UserName, &s_fdUserName);

    pEncoderStream->put_utf8v(m_UserPass, &s_fdUserPass);

    pEncoderStream->put_utf8v(m_VersionPath, &s_fdVersionPath);

    pEncoderStream->put_u16(m_ServerPort, &s_fdServerPort);

    pType = &CIPAddress::s_typeDescriptor;

    pEncoderStream->putRequiredSubParameter(m_pIPAddress, pType);

}




/*
*****************************************************************
**
** Parameter AlarmReportInfo
**
*****************************************************************
*/


const CTypeDescriptor
CAlarmReportInfo::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "AlarmReportInfo",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    720,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CAlarmReportInfo::s_apFieldDescriptorTable[] =
{

    &s_fdAlarmReportCode,
    &s_fdAlarmReportReason,
    &s_fdAlarmReportLevel,
    &s_fdAlarmReportSeconds,
    &s_fdAlarmReportDescription,
    NULL
};



const CFieldDescriptor
CAlarmReportInfo::s_fdAlarmReportCode =
{
    CFieldDescriptor::FT_U32,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "AlarmReportCode",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CAlarmReportInfo::s_fdAlarmReportReason =
{
    CFieldDescriptor::FT_U32,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "AlarmReportReason",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CAlarmReportInfo::s_fdAlarmReportLevel =
{
    CFieldDescriptor::FT_E8,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "AlarmReportLevel",	// m_pName
    g_estAlarmReportInfoAlarmReportLevel	// m_pEnumTable
};


const CFieldDescriptor
CAlarmReportInfo::s_fdAlarmReportSeconds =
{
    CFieldDescriptor::FT_U32,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "AlarmReportSeconds",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CAlarmReportInfo::s_fdAlarmReportDescription =
{
    CFieldDescriptor::FT_UTF8V,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "AlarmReportDescription",	// m_pName
    NULL	// m_pEnumTable
};
CAlarmReportInfo::CAlarmReportInfo (void)
{
    m_pType = &s_typeDescriptor;

    m_AlarmReportCode = 0;
    m_AlarmReportReason = 0;
    m_EAlarmReportLevel = (EAlarmReportInfoAlarmReportLevel) 0;
    m_AlarmReportSeconds = 0;
}

CAlarmReportInfo::~CAlarmReportInfo (void)
{
}


CElement *
CAlarmReportInfo::s_construct (void)
{
    return (CElement *) new CAlarmReportInfo();
}


void
CAlarmReportInfo::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CAlarmReportInfo * pTarget = (CAlarmReportInfo *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_AlarmReportCode = pDecoderStream->get_u32(&s_fdAlarmReportCode);
    }
    else
    {
        pDecoderStream->get_u32(&s_fdAlarmReportCode);
    }

    if(NULL != pTarget)
    {
        pTarget->m_AlarmReportReason = pDecoderStream->get_u32(&s_fdAlarmReportReason);
    }
    else
    {
        pDecoderStream->get_u32(&s_fdAlarmReportReason);
    }

    if(NULL != pTarget)
    {
        pTarget->m_EAlarmReportLevel = (EAlarmReportInfoAlarmReportLevel) pDecoderStream->get_e8(&s_fdAlarmReportLevel);
    }
    else
    {
        pDecoderStream->get_e8(&s_fdAlarmReportLevel);
    }

    if(NULL != pTarget)
    {
        pTarget->m_AlarmReportSeconds = pDecoderStream->get_u32(&s_fdAlarmReportSeconds);
    }
    else
    {
        pDecoderStream->get_u32(&s_fdAlarmReportSeconds);
    }

    if(NULL != pTarget)
    {
        pTarget->m_AlarmReportDescription = pDecoderStream->get_utf8v(&s_fdAlarmReportDescription);
    }
    else
    {
        pDecoderStream->get_utf8v(&s_fdAlarmReportDescription);
    }

}


void
CAlarmReportInfo::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CAlarmReportInfo::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


void
CAlarmReportInfo::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u32(m_AlarmReportCode, &s_fdAlarmReportCode);

    pEncoderStream->put_u32(m_AlarmReportReason, &s_fdAlarmReportReason);

    pEncoderStream->put_e8((int)m_EAlarmReportLevel, &s_fdAlarmReportLevel);

    pEncoderStream->put_u32(m_AlarmReportSeconds, &s_fdAlarmReportSeconds);

    pEncoderStream->put_utf8v(m_AlarmReportDescription, &s_fdAlarmReportDescription);

}




/*
*****************************************************************
**
** Parameter AlarmRestoreInfo
**
*****************************************************************
*/


const CTypeDescriptor
CAlarmRestoreInfo::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "AlarmRestoreInfo",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    721,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CAlarmRestoreInfo::s_apFieldDescriptorTable[] =
{

    &s_fdAlarmRestoreType,
    &s_fdAlarmRestoreSeconds,
    NULL
};



const CFieldDescriptor
CAlarmRestoreInfo::s_fdAlarmRestoreType =
{
    CFieldDescriptor::FT_U8,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "AlarmRestoreType",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CAlarmRestoreInfo::s_fdAlarmRestoreSeconds =
{
    CFieldDescriptor::FT_U32,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "AlarmRestoreSeconds",	// m_pName
    NULL	// m_pEnumTable
};
CAlarmRestoreInfo::CAlarmRestoreInfo (void)
{
    m_pType = &s_typeDescriptor;

    m_AlarmRestoreType = 0;
    m_AlarmRestoreSeconds = 0;
}

CAlarmRestoreInfo::~CAlarmRestoreInfo (void)
{
}


CElement *
CAlarmRestoreInfo::s_construct (void)
{
    return (CElement *) new CAlarmRestoreInfo();
}


void
CAlarmRestoreInfo::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CAlarmRestoreInfo * pTarget = (CAlarmRestoreInfo *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_AlarmRestoreType = pDecoderStream->get_u8(&s_fdAlarmRestoreType);
    }
    else
    {
        pDecoderStream->get_u8(&s_fdAlarmRestoreType);
    }

    if(NULL != pTarget)
    {
        pTarget->m_AlarmRestoreSeconds = pDecoderStream->get_u32(&s_fdAlarmRestoreSeconds);
    }
    else
    {
        pDecoderStream->get_u32(&s_fdAlarmRestoreSeconds);
    }

}


void
CAlarmRestoreInfo::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CAlarmRestoreInfo::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


void
CAlarmRestoreInfo::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u8(m_AlarmRestoreType, &s_fdAlarmRestoreType);

    pEncoderStream->put_u32(m_AlarmRestoreSeconds, &s_fdAlarmRestoreSeconds);

}




/*
*****************************************************************
**
** Parameter AlarmSyncInfo
**
*****************************************************************
*/


const CTypeDescriptor
CAlarmSyncInfo::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "AlarmSyncInfo",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    722,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CAlarmSyncInfo::s_apFieldDescriptorTable[] =
{

    &s_fdAlarmSyncSeq,
    &s_fdAlarmSyncType,
    &s_fdAlarmSyncPackageNo,
    &s_fdAlarmSyncPackageNum,
    &s_fdAlarmIDs,
    NULL
};



const CFieldDescriptor
CAlarmSyncInfo::s_fdAlarmSyncSeq =
{
    CFieldDescriptor::FT_U32,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "AlarmSyncSeq",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CAlarmSyncInfo::s_fdAlarmSyncType =
{
    CFieldDescriptor::FT_U8,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "AlarmSyncType",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CAlarmSyncInfo::s_fdAlarmSyncPackageNo =
{
    CFieldDescriptor::FT_U16,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "AlarmSyncPackageNo",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CAlarmSyncInfo::s_fdAlarmSyncPackageNum =
{
    CFieldDescriptor::FT_U16,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "AlarmSyncPackageNum",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CAlarmSyncInfo::s_fdAlarmIDs =
{
    CFieldDescriptor::FT_U32V,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "AlarmIDs",	// m_pName
    NULL	// m_pEnumTable
};
CAlarmSyncInfo::CAlarmSyncInfo (void)
{
    m_pType = &s_typeDescriptor;

    m_AlarmSyncSeq = 0;
    m_AlarmSyncType = 0;
    m_AlarmSyncPackageNo = 0;
    m_AlarmSyncPackageNum = 0;
}

CAlarmSyncInfo::~CAlarmSyncInfo (void)
{
}


CElement *
CAlarmSyncInfo::s_construct (void)
{
    return (CElement *) new CAlarmSyncInfo();
}


void
CAlarmSyncInfo::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CAlarmSyncInfo * pTarget = (CAlarmSyncInfo *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_AlarmSyncSeq = pDecoderStream->get_u32(&s_fdAlarmSyncSeq);
    }
    else
    {
        pDecoderStream->get_u32(&s_fdAlarmSyncSeq);
    }

    if(NULL != pTarget)
    {
        pTarget->m_AlarmSyncType = pDecoderStream->get_u8(&s_fdAlarmSyncType);
    }
    else
    {
        pDecoderStream->get_u8(&s_fdAlarmSyncType);
    }

    if(NULL != pTarget)
    {
        pTarget->m_AlarmSyncPackageNo = pDecoderStream->get_u16(&s_fdAlarmSyncPackageNo);
    }
    else
    {
        pDecoderStream->get_u16(&s_fdAlarmSyncPackageNo);
    }

    if(NULL != pTarget)
    {
        pTarget->m_AlarmSyncPackageNum = pDecoderStream->get_u16(&s_fdAlarmSyncPackageNum);
    }
    else
    {
        pDecoderStream->get_u16(&s_fdAlarmSyncPackageNum);
    }

    if(NULL != pTarget)
    {
        pTarget->m_AlarmIDs = pDecoderStream->get_u32v(&s_fdAlarmIDs);
    }
    else
    {
        pDecoderStream->get_u32v(&s_fdAlarmIDs);
    }

}


void
CAlarmSyncInfo::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CAlarmSyncInfo::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


void
CAlarmSyncInfo::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u32(m_AlarmSyncSeq, &s_fdAlarmSyncSeq);

    pEncoderStream->put_u8(m_AlarmSyncType, &s_fdAlarmSyncType);

    pEncoderStream->put_u16(m_AlarmSyncPackageNo, &s_fdAlarmSyncPackageNo);

    pEncoderStream->put_u16(m_AlarmSyncPackageNum, &s_fdAlarmSyncPackageNum);

    pEncoderStream->put_u32v(m_AlarmIDs, &s_fdAlarmIDs);

}




/*
*****************************************************************
**
** Parameter DiagnosticTestItem
**
*****************************************************************
*/


const CTypeDescriptor
CDiagnosticTestItem::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "DiagnosticTestItem",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    740,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CDiagnosticTestItem::s_apFieldDescriptorTable[] =
{

    &s_fdDiagnosticTestID,
    NULL
};



const CFieldDescriptor
CDiagnosticTestItem::s_fdDiagnosticTestID =
{
    CFieldDescriptor::FT_U16,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "DiagnosticTestID",	// m_pName
    NULL	// m_pEnumTable
};
CDiagnosticTestItem::CDiagnosticTestItem (void)
{
    m_pType = &s_typeDescriptor;

    m_DiagnosticTestID = 0;
}

CDiagnosticTestItem::~CDiagnosticTestItem (void)
{
}


CElement *
CDiagnosticTestItem::s_construct (void)
{
    return (CElement *) new CDiagnosticTestItem();
}


void
CDiagnosticTestItem::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CDiagnosticTestItem * pTarget = (CDiagnosticTestItem *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_DiagnosticTestID = pDecoderStream->get_u16(&s_fdDiagnosticTestID);
    }
    else
    {
        pDecoderStream->get_u16(&s_fdDiagnosticTestID);
    }

}


void
CDiagnosticTestItem::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CDiagnosticTestItem::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


void
CDiagnosticTestItem::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u16(m_DiagnosticTestID, &s_fdDiagnosticTestID);

}




/*
*****************************************************************
**
** Parameter DiagnosticTestResultItem
**
*****************************************************************
*/


const CTypeDescriptor
CDiagnosticTestResultItem::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "DiagnosticTestResultItem",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    741,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CDiagnosticTestResultItem::s_apFieldDescriptorTable[] =
{

    &s_fdDiagnosticTestID,
    &s_fdDiagnosticTestResultCode,
    NULL
};



const CFieldDescriptor
CDiagnosticTestResultItem::s_fdDiagnosticTestID =
{
    CFieldDescriptor::FT_U16,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "DiagnosticTestID",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CDiagnosticTestResultItem::s_fdDiagnosticTestResultCode =
{
    CFieldDescriptor::FT_U32,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "DiagnosticTestResultCode",	// m_pName
    NULL	// m_pEnumTable
};
CDiagnosticTestResultItem::CDiagnosticTestResultItem (void)
{
    m_pType = &s_typeDescriptor;

    m_DiagnosticTestID = 0;
    m_DiagnosticTestResultCode = 0;
    m_pDiagnosticTestResultData = NULL;
}

CDiagnosticTestResultItem::~CDiagnosticTestResultItem (void)
{
}


CElement *
CDiagnosticTestResultItem::s_construct (void)
{
    return (CElement *) new CDiagnosticTestResultItem();
}


void
CDiagnosticTestResultItem::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CDiagnosticTestResultItem * pTarget = (CDiagnosticTestResultItem *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_DiagnosticTestID = pDecoderStream->get_u16(&s_fdDiagnosticTestID);
    }
    else
    {
        pDecoderStream->get_u16(&s_fdDiagnosticTestID);
    }

    if(NULL != pTarget)
    {
        pTarget->m_DiagnosticTestResultCode = pDecoderStream->get_u32(&s_fdDiagnosticTestResultCode);
    }
    else
    {
        pDecoderStream->get_u32(&s_fdDiagnosticTestResultCode);
    }

}


void
CDiagnosticTestResultItem::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CDiagnosticTestResultItem::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    // 0-1 of choice DiagnosticTestResultData
    pType = NULL;

    if(Cur != End && CDiagnosticTestResultData::isMember(*Cur))
    {
        m_pDiagnosticTestResultData = *Cur++;
    }


    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


EResultCode
CDiagnosticTestResultItem::setDiagnosticTestResultData (
  CParameter *                  pValue)
{
    if(!CDiagnosticTestResultData::isMember(pValue))
    {
        return RC_InvalidChoiceMember;
    }

    removeSubParameterFromAllList(m_pDiagnosticTestResultData);
    delete m_pDiagnosticTestResultData;
    m_pDiagnosticTestResultData = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CDiagnosticTestResultItem::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u16(m_DiagnosticTestID, &s_fdDiagnosticTestID);

    pEncoderStream->put_u32(m_DiagnosticTestResultCode, &s_fdDiagnosticTestResultCode);

    pType = NULL;

    pEncoderStream->putOptionalSubParameter(m_pDiagnosticTestResultData, pType);

}




/*
*****************************************************************
**
** Parameter DiagnosticTestResultAntennaConnected
**
*****************************************************************
*/


const CTypeDescriptor
CDiagnosticTestResultAntennaConnected::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "DiagnosticTestResultAntennaConnected",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    742,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CDiagnosticTestResultAntennaConnected::s_apFieldDescriptorTable[] =
{

    &s_fdAntennaID,
    &s_fdAntennaConnected,
    NULL
};



const CFieldDescriptor
CDiagnosticTestResultAntennaConnected::s_fdAntennaID =
{
    CFieldDescriptor::FT_U8,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "AntennaID",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CDiagnosticTestResultAntennaConnected::s_fdAntennaConnected =
{
    CFieldDescriptor::FT_E1,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "AntennaConnected",	// m_pName
    g_estDiagnosticTestResultAntennaConnected	// m_pEnumTable
};
CDiagnosticTestResultAntennaConnected::CDiagnosticTestResultAntennaConnected (void)
{
    m_pType = &s_typeDescriptor;

    m_AntennaID = 0;
    m_EAntennaConnected = (EDiagnosticTestResultAntennaConnected) 0;
}

CDiagnosticTestResultAntennaConnected::~CDiagnosticTestResultAntennaConnected (void)
{
}


CElement *
CDiagnosticTestResultAntennaConnected::s_construct (void)
{
    return (CElement *) new CDiagnosticTestResultAntennaConnected();
}


void
CDiagnosticTestResultAntennaConnected::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CDiagnosticTestResultAntennaConnected * pTarget = (CDiagnosticTestResultAntennaConnected *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_AntennaID = pDecoderStream->get_u8(&s_fdAntennaID);
    }
    else
    {
        pDecoderStream->get_u8(&s_fdAntennaID);
    }

    if(NULL != pTarget)
    {
        pTarget->m_EAntennaConnected = (EDiagnosticTestResultAntennaConnected) pDecoderStream->get_e1(&s_fdAntennaConnected);
    }
    else
    {
        pDecoderStream->get_e1(&s_fdAntennaConnected);
    }

    pDecoderStream->get_reserved(7);

}


void
CDiagnosticTestResultAntennaConnected::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CDiagnosticTestResultAntennaConnected::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


void
CDiagnosticTestResultAntennaConnected::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u8(m_AntennaID, &s_fdAntennaID);

    pEncoderStream->put_e1((int)m_EAntennaConnected, &s_fdAntennaConnected);

    pEncoderStream->put_reserved(7);

}




/*
*****************************************************************
**
** Parameter DiagnosticTestResultAntennaVSWR
**
*****************************************************************
*/


const CTypeDescriptor
CDiagnosticTestResultAntennaVSWR::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "DiagnosticTestResultAntennaVSWR",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    743,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CDiagnosticTestResultAntennaVSWR::s_apFieldDescriptorTable[] =
{

    &s_fdAntennaID,
    &s_fdAntennaVSWR,
    NULL
};



const CFieldDescriptor
CDiagnosticTestResultAntennaVSWR::s_fdAntennaID =
{
    CFieldDescriptor::FT_U8,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "AntennaID",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CDiagnosticTestResultAntennaVSWR::s_fdAntennaVSWR =
{
    CFieldDescriptor::FT_U16,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "AntennaVSWR",	// m_pName
    NULL	// m_pEnumTable
};
CDiagnosticTestResultAntennaVSWR::CDiagnosticTestResultAntennaVSWR (void)
{
    m_pType = &s_typeDescriptor;

    m_AntennaID = 0;
    m_AntennaVSWR = 0;
}

CDiagnosticTestResultAntennaVSWR::~CDiagnosticTestResultAntennaVSWR (void)
{
}


CElement *
CDiagnosticTestResultAntennaVSWR::s_construct (void)
{
    return (CElement *) new CDiagnosticTestResultAntennaVSWR();
}


void
CDiagnosticTestResultAntennaVSWR::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CDiagnosticTestResultAntennaVSWR * pTarget = (CDiagnosticTestResultAntennaVSWR *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_AntennaID = pDecoderStream->get_u8(&s_fdAntennaID);
    }
    else
    {
        pDecoderStream->get_u8(&s_fdAntennaID);
    }

    if(NULL != pTarget)
    {
        pTarget->m_AntennaVSWR = pDecoderStream->get_u16(&s_fdAntennaVSWR);
    }
    else
    {
        pDecoderStream->get_u16(&s_fdAntennaVSWR);
    }

}


void
CDiagnosticTestResultAntennaVSWR::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CDiagnosticTestResultAntennaVSWR::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


void
CDiagnosticTestResultAntennaVSWR::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u8(m_AntennaID, &s_fdAntennaID);

    pEncoderStream->put_u16(m_AntennaVSWR, &s_fdAntennaVSWR);

}




/*
*****************************************************************
**
** Parameter LocationConfiguration
**
*****************************************************************
*/


const CTypeDescriptor
CLocationConfiguration::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "LocationConfiguration",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    681,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CLocationConfiguration::s_apFieldDescriptorTable[] =
{

    &s_fdLocationType,
    NULL
};



const CFieldDescriptor
CLocationConfiguration::s_fdLocationType =
{
    CFieldDescriptor::FT_E8,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "LocationType",	// m_pName
    g_estLocationType	// m_pEnumTable
};
CLocationConfiguration::CLocationConfiguration (void)
{
    m_pType = &s_typeDescriptor;

    m_ELocationType = (ELocationType) 0;
    m_pLocationInfo = NULL;
}

CLocationConfiguration::~CLocationConfiguration (void)
{
}


CElement *
CLocationConfiguration::s_construct (void)
{
    return (CElement *) new CLocationConfiguration();
}


void
CLocationConfiguration::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CLocationConfiguration * pTarget = (CLocationConfiguration *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_ELocationType = (ELocationType) pDecoderStream->get_e8(&s_fdLocationType);
    }
    else
    {
        pDecoderStream->get_e8(&s_fdLocationType);
    }

}


void
CLocationConfiguration::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CLocationConfiguration::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    // 1 of choice LocationInfo
    pType = NULL;

    if(Cur == End || !CLocationInfo::isMember(*Cur))
    {
        goto missing;
    }
    m_pLocationInfo = *Cur++;


    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


EResultCode
CLocationConfiguration::setLocationInfo (
  CParameter *                  pValue)
{
    if(!CLocationInfo::isMember(pValue))
    {
        return RC_InvalidChoiceMember;
    }

    removeSubParameterFromAllList(m_pLocationInfo);
    delete m_pLocationInfo;
    m_pLocationInfo = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CLocationConfiguration::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_e8((int)m_ELocationType, &s_fdLocationType);

    pType = NULL;

    pEncoderStream->putRequiredSubParameter(m_pLocationInfo, pType);

}




/*
*****************************************************************
**
** Parameter GpsLocation
**
*****************************************************************
*/


const CTypeDescriptor
CGpsLocation::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "GpsLocation",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    682,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CGpsLocation::s_apFieldDescriptorTable[] =
{

    &s_fdLongitude,
    &s_fdLatitude,
    &s_fdAltitude,
    NULL
};



const CFieldDescriptor
CGpsLocation::s_fdLongitude =
{
    CFieldDescriptor::FT_S32,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "Longitude",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CGpsLocation::s_fdLatitude =
{
    CFieldDescriptor::FT_S32,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "Latitude",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CGpsLocation::s_fdAltitude =
{
    CFieldDescriptor::FT_S32,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "Altitude",	// m_pName
    NULL	// m_pEnumTable
};
CGpsLocation::CGpsLocation (void)
{
    m_pType = &s_typeDescriptor;

    m_Longitude = 0;
    m_Latitude = 0;
    m_Altitude = 0;
}

CGpsLocation::~CGpsLocation (void)
{
}


CElement *
CGpsLocation::s_construct (void)
{
    return (CElement *) new CGpsLocation();
}


void
CGpsLocation::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CGpsLocation * pTarget = (CGpsLocation *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_Longitude = pDecoderStream->get_s32(&s_fdLongitude);
    }
    else
    {
        pDecoderStream->get_s32(&s_fdLongitude);
    }

    if(NULL != pTarget)
    {
        pTarget->m_Latitude = pDecoderStream->get_s32(&s_fdLatitude);
    }
    else
    {
        pDecoderStream->get_s32(&s_fdLatitude);
    }

    if(NULL != pTarget)
    {
        pTarget->m_Altitude = pDecoderStream->get_s32(&s_fdAltitude);
    }
    else
    {
        pDecoderStream->get_s32(&s_fdAltitude);
    }

}


void
CGpsLocation::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CGpsLocation::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


void
CGpsLocation::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_s32(m_Longitude, &s_fdLongitude);

    pEncoderStream->put_s32(m_Latitude, &s_fdLatitude);

    pEncoderStream->put_s32(m_Altitude, &s_fdAltitude);

}




/*
*****************************************************************
**
** Parameter BdsLocation
**
*****************************************************************
*/


const CTypeDescriptor
CBdsLocation::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "BdsLocation",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    683,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CBdsLocation::s_apFieldDescriptorTable[] =
{

    &s_fdLongitude,
    &s_fdLatitude,
    &s_fdAltitude,
    NULL
};



const CFieldDescriptor
CBdsLocation::s_fdLongitude =
{
    CFieldDescriptor::FT_S32,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "Longitude",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CBdsLocation::s_fdLatitude =
{
    CFieldDescriptor::FT_S32,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "Latitude",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CBdsLocation::s_fdAltitude =
{
    CFieldDescriptor::FT_S32,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "Altitude",	// m_pName
    NULL	// m_pEnumTable
};
CBdsLocation::CBdsLocation (void)
{
    m_pType = &s_typeDescriptor;

    m_Longitude = 0;
    m_Latitude = 0;
    m_Altitude = 0;
}

CBdsLocation::~CBdsLocation (void)
{
}


CElement *
CBdsLocation::s_construct (void)
{
    return (CElement *) new CBdsLocation();
}


void
CBdsLocation::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CBdsLocation * pTarget = (CBdsLocation *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_Longitude = pDecoderStream->get_s32(&s_fdLongitude);
    }
    else
    {
        pDecoderStream->get_s32(&s_fdLongitude);
    }

    if(NULL != pTarget)
    {
        pTarget->m_Latitude = pDecoderStream->get_s32(&s_fdLatitude);
    }
    else
    {
        pDecoderStream->get_s32(&s_fdLatitude);
    }

    if(NULL != pTarget)
    {
        pTarget->m_Altitude = pDecoderStream->get_s32(&s_fdAltitude);
    }
    else
    {
        pDecoderStream->get_s32(&s_fdAltitude);
    }

}


void
CBdsLocation::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CBdsLocation::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


void
CBdsLocation::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_s32(m_Longitude, &s_fdLongitude);

    pEncoderStream->put_s32(m_Latitude, &s_fdLatitude);

    pEncoderStream->put_s32(m_Altitude, &s_fdAltitude);

}




/*
*****************************************************************
**
** Choice EthernetConfiguration
**
*****************************************************************
*/


const CTypeDescriptor
CEthernetConfiguration::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "EthernetConfiguration",	// m_pName
    NULL,	// m_pVendorDescriptor
    NULL,	// m_pNamespaceDescriptor
    (llrp_u32_t)(-1),	// m_TypeNum
    NULL,   // m_ppFieldDescriptorTable
    NULL,                // m_pfConstruct
    NULL,             // m_pfDecodeFields
};

llrp_bool_t
CEthernetConfiguration::isMember (
  CParameter *                  pParameter)
{
    const CTypeDescriptor *     pType;

    pType = pParameter->m_pType;


    if(&CEthernetIpv4Configuration::s_typeDescriptor == pType)
    {
        return TRUE;
    }

    if(&CEthernetIpv6Configuration::s_typeDescriptor == pType)
    {
        return TRUE;
    }


    return FALSE;
}




/*
*****************************************************************
**
** Choice DiagnosticTestResultData
**
*****************************************************************
*/


const CTypeDescriptor
CDiagnosticTestResultData::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "DiagnosticTestResultData",	// m_pName
    NULL,	// m_pVendorDescriptor
    NULL,	// m_pNamespaceDescriptor
    (llrp_u32_t)(-1),	// m_TypeNum
    NULL,   // m_ppFieldDescriptorTable
    NULL,                // m_pfConstruct
    NULL,             // m_pfDecodeFields
};

llrp_bool_t
CDiagnosticTestResultData::isMember (
  CParameter *                  pParameter)
{
    const CTypeDescriptor *     pType;

    pType = pParameter->m_pType;


    if(&CDiagnosticTestResultAntennaConnected::s_typeDescriptor == pType)
    {
        return TRUE;
    }

    if(&CDiagnosticTestResultAntennaVSWR::s_typeDescriptor == pType)
    {
        return TRUE;
    }


    return FALSE;
}




/*
*****************************************************************
**
** Choice LocationInfo
**
*****************************************************************
*/


const CTypeDescriptor
CLocationInfo::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "LocationInfo",	// m_pName
    NULL,	// m_pVendorDescriptor
    NULL,	// m_pNamespaceDescriptor
    (llrp_u32_t)(-1),	// m_TypeNum
    NULL,   // m_ppFieldDescriptorTable
    NULL,                // m_pfConstruct
    NULL,             // m_pfDecodeFields
};

llrp_bool_t
CLocationInfo::isMember (
  CParameter *                  pParameter)
{
    const CTypeDescriptor *     pType;

    pType = pParameter->m_pType;


    if(&CGpsLocation::s_typeDescriptor == pType)
    {
        return TRUE;
    }

    if(&CBdsLocation::s_typeDescriptor == pType)
    {
        return TRUE;
    }


    return FALSE;
}

/*
void
enrollCoreTypesIntoRegistry (
  CTypeRegistry *               pTypeRegistry)
{

    pTypeRegistry->enroll(&CTagLog::s_typeDescriptor);

    pTypeRegistry->enroll(&CStartLogTimestamp::s_typeDescriptor);

    pTypeRegistry->enroll(&CEndLogTimestamp::s_typeDescriptor);

    pTypeRegistry->enroll(&CDeviceLog::s_typeDescriptor);

    pTypeRegistry->enroll(&CDeviceEventNotificationSpec::s_typeDescriptor);

    pTypeRegistry->enroll(&CEventNotificationState::s_typeDescriptor);

    pTypeRegistry->enroll(&CAntennaProperties::s_typeDescriptor);

    pTypeRegistry->enroll(&CAntennaConfiguration::s_typeDescriptor);

    pTypeRegistry->enroll(&CModuleDepth::s_typeDescriptor);

    pTypeRegistry->enroll(&CIdentification::s_typeDescriptor);

    pTypeRegistry->enroll(&CAlarmConfiguration::s_typeDescriptor);

    pTypeRegistry->enroll(&CAlarmThreshod::s_typeDescriptor);

    pTypeRegistry->enroll(&CCommunicationConfiguration::s_typeDescriptor);

    pTypeRegistry->enroll(&CCommLinkConfiguration::s_typeDescriptor);

    pTypeRegistry->enroll(&CKeepaliveSpec::s_typeDescriptor);

    pTypeRegistry->enroll(&CTcpLinkConfiguration::s_typeDescriptor);

    pTypeRegistry->enroll(&CClientModeConfiguration::s_typeDescriptor);

    pTypeRegistry->enroll(&CIPAddress::s_typeDescriptor);

    pTypeRegistry->enroll(&CServerModeConfiguration::s_typeDescriptor);

    pTypeRegistry->enroll(&CSerialLinkConfiguration::s_typeDescriptor);

    pTypeRegistry->enroll(&CHttpLinkConfiguration::s_typeDescriptor);

    pTypeRegistry->enroll(&CEthernetIpv4Configuration::s_typeDescriptor);

    pTypeRegistry->enroll(&CEthernetIpv6Configuration::s_typeDescriptor);

    pTypeRegistry->enroll(&CNTPConfiguration::s_typeDescriptor);

    pTypeRegistry->enroll(&CSerialPortConfiguration::s_typeDescriptor);

    pTypeRegistry->enroll(&CSecurityModuleConfiguration::s_typeDescriptor);

    pTypeRegistry->enroll(&CGenaralConfigData::s_typeDescriptor);

    pTypeRegistry->enroll(&CRTCTime::s_typeDescriptor);

    pTypeRegistry->enroll(&CSecurityModuleSN::s_typeDescriptor);

    pTypeRegistry->enroll(&CReadMode::s_typeDescriptor);

    pTypeRegistry->enroll(&CPasswordVersion::s_typeDescriptor);

    pTypeRegistry->enroll(&CVersionInfo::s_typeDescriptor);

    pTypeRegistry->enroll(&CVersionDownload::s_typeDescriptor);

    pTypeRegistry->enroll(&CAlarmReportInfo::s_typeDescriptor);

    pTypeRegistry->enroll(&CAlarmRestoreInfo::s_typeDescriptor);

    pTypeRegistry->enroll(&CAlarmSyncInfo::s_typeDescriptor);

    pTypeRegistry->enroll(&CDiagnosticTestItem::s_typeDescriptor);

    pTypeRegistry->enroll(&CDiagnosticTestResultItem::s_typeDescriptor);

    pTypeRegistry->enroll(&CDiagnosticTestResultAntennaConnected::s_typeDescriptor);

    pTypeRegistry->enroll(&CDiagnosticTestResultAntennaVSWR::s_typeDescriptor);

    pTypeRegistry->enroll(&CLocationConfiguration::s_typeDescriptor);

    pTypeRegistry->enroll(&CGpsLocation::s_typeDescriptor);

    pTypeRegistry->enroll(&CBdsLocation::s_typeDescriptor);

    pTypeRegistry->enroll(&CDeviceBinding::s_typeDescriptor);

    pTypeRegistry->enroll(&CDeviceBindingAck::s_typeDescriptor);

    pTypeRegistry->enroll(&CDeviceCertificateConfig::s_typeDescriptor);

    pTypeRegistry->enroll(&CDeviceCertificateConfigAck::s_typeDescriptor);

    pTypeRegistry->enroll(&CDeviceBindingResultNotification::s_typeDescriptor);

    pTypeRegistry->enroll(&CUploadTagLog::s_typeDescriptor);

    pTypeRegistry->enroll(&CUploadTagLogAck::s_typeDescriptor);

    pTypeRegistry->enroll(&CClearTagLog::s_typeDescriptor);

    pTypeRegistry->enroll(&CClearTagLogAck::s_typeDescriptor);

    pTypeRegistry->enroll(&CTagLogCount::s_typeDescriptor);

    pTypeRegistry->enroll(&CTagLogCountAck::s_typeDescriptor);

    pTypeRegistry->enroll(&CUploadTagLogConfirm::s_typeDescriptor);

    pTypeRegistry->enroll(&CUploadDeviceLog::s_typeDescriptor);

    pTypeRegistry->enroll(&CUploadDeviceLogAck::s_typeDescriptor);

    pTypeRegistry->enroll(&CClearDeviceLog::s_typeDescriptor);

    pTypeRegistry->enroll(&CClearDeviceLogAck::s_typeDescriptor);

    pTypeRegistry->enroll(&CDeviceLogCount::s_typeDescriptor);

    pTypeRegistry->enroll(&CDeviceLogCountAck::s_typeDescriptor);

    pTypeRegistry->enroll(&CUploadDeviceLogConfirm::s_typeDescriptor);

    pTypeRegistry->enroll(&CGetDeviceConfig::s_typeDescriptor);

    pTypeRegistry->enroll(&CGetDeviceConfigAck::s_typeDescriptor);

    pTypeRegistry->enroll(&CSetDeviceConfig::s_typeDescriptor);

    pTypeRegistry->enroll(&CSetDeviceConfigAck::s_typeDescriptor);

    pTypeRegistry->enroll(&CGetVersion::s_typeDescriptor);

    pTypeRegistry->enroll(&CGetVersionAck::s_typeDescriptor);

    pTypeRegistry->enroll(&CSetVersion::s_typeDescriptor);

    pTypeRegistry->enroll(&CSetVersionAck::s_typeDescriptor);

    pTypeRegistry->enroll(&CActiveVersion::s_typeDescriptor);

    pTypeRegistry->enroll(&CActiveVersionAck::s_typeDescriptor);

    pTypeRegistry->enroll(&CUnActiveVersion::s_typeDescriptor);

    pTypeRegistry->enroll(&CUnActiveVersionAck::s_typeDescriptor);

    pTypeRegistry->enroll(&CAlarmReport::s_typeDescriptor);

    pTypeRegistry->enroll(&CAlarmRestore::s_typeDescriptor);

    pTypeRegistry->enroll(&CAlarmDelete::s_typeDescriptor);

    pTypeRegistry->enroll(&CAlarmSync::s_typeDescriptor);

    pTypeRegistry->enroll(&CDiagnosticTest::s_typeDescriptor);

    pTypeRegistry->enroll(&CDiagnosticTestAck::s_typeDescriptor);

    pTypeRegistry->enroll(&CResetDevice::s_typeDescriptor);

    pTypeRegistry->enroll(&CResetDeviceAck::s_typeDescriptor);

}
*/

};//end of namespace llrp
