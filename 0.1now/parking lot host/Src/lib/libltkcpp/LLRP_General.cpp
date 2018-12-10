#include "LLRP_General.h"
#include "LLRP_Capabilities.h"
#include "LLRP_Operation.h"
#include "LLRP_NET.h"

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

  
const CNamespaceDescriptor
g_nsdescllrp =
{
  "llrp",	// m_pPrefix
  "http://www.llrp.org/ltk/schema/core/encoding/xml/1.0",	// m_pURI
  "http://www.llrp.org/ltk/schema/core/encoding/xml/1.0/llrp.xsd",	// m_pSchemaLocation
};


/*
 * Enumeration string tables
 */

  
const SEnumTableEntry
g_estStatusCode[] =
{
  
    {
        "M_Success",
        StatusCode_M_Success,
    },
    {
        "M_ParameterError",
        StatusCode_M_ParameterError,
    },
    {
        "M_FieldError",
        StatusCode_M_FieldError,
    },
    {
        "M_UnexpectedParameter",
        StatusCode_M_UnexpectedParameter,
    },
    {
        "M_MissingParameter",
        StatusCode_M_MissingParameter,
    },
    {
        "M_DuplicateParameter",
        StatusCode_M_DuplicateParameter,
    },
    {
        "M_OverflowParameter",
        StatusCode_M_OverflowParameter,
    },
    {
        "M_OverflowField",
        StatusCode_M_OverflowField,
    },
    {
        "M_UnknownParameter",
        StatusCode_M_UnknownParameter,
    },
    {
        "M_UnknownField",
        StatusCode_M_UnknownField,
    },
    {
        "M_UnsupportedMessage",
        StatusCode_M_UnsupportedMessage,
    },
    {
        "M_UnsupportedVersion",
        StatusCode_M_UnsupportedVersion,
    },
    {
        "M_UnsupportedParameter",
        StatusCode_M_UnsupportedParameter,
    },
    {
        "P_ParameterError",
        StatusCode_P_ParameterError,
    },
    {
        "P_FieldError",
        StatusCode_P_FieldError,
    },
    {
        "P_UnexpectedParameter",
        StatusCode_P_UnexpectedParameter,
    },
    {
        "P_MissingParameter",
        StatusCode_P_MissingParameter,
    },
    {
        "P_DuplicateParameter",
        StatusCode_P_DuplicateParameter,
    },
    {
        "P_OverflowParameter",
        StatusCode_P_OverflowParameter,
    },
    {
        "P_OverflowField",
        StatusCode_P_OverflowField,
    },
    {
        "P_UnknownParameter",
        StatusCode_P_UnknownParameter,
    },
    {
        "P_UnknownField",
        StatusCode_P_UnknownField,
    },
    {
        "P_UnsupportedParameter",
        StatusCode_P_UnsupportedParameter,
    },
    {
        "A_Invalid",
        StatusCode_A_Invalid,
    },
    {
        "A_OutOfRange",
        StatusCode_A_OutOfRange,
    },
    {
        "R_DeviceError",
        StatusCode_R_DeviceError,
    },
    { 0, 0 }
};


const SEnumTableEntry
g_estGPIEvent[] =
{
  
    {
        "DOWN",
        GPIEvent_DOWN,
    },
    {
        "UP",
        GPIEvent_UP,
    },
    { 0, 0 }
};


const SEnumTableEntry
g_estEventType[] =
{
  
    {
        "Start",
        EventType_Start,
    },
    {
        "End",
        EventType_End,
    },
    {
        "Priority",
        EventType_Priority,
    },
    { 0, 0 }
};


const SEnumTableEntry
g_estConnectionStatus[] =
{
  
    {
        "Success",
        ConnectionStatus_Success,
    },
    {
        "ClientConnectExist",
        ConnectionStatus_ClientConnectExist,
    },
    {
        "ServerConnectExist",
        ConnectionStatus_ServerConnectExist,
    },
    {
        "OtherError",
        ConnectionStatus_OtherError,
    },
    { 0, 0 }
};




/*
*****************************************************************
**
** Message Keepalive
**
*****************************************************************
*/ 
  

const CTypeDescriptor
CKeepalive::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "Keepalive",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    300,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CKeepalive::s_apFieldDescriptorTable[] =
{
  
    NULL
};

CKeepalive::CKeepalive (void)
{
    m_pType = &s_typeDescriptor;
  
}

CKeepalive::~CKeepalive (void)
{
}


CElement *
CKeepalive::s_construct (void)
{
    return (CElement *) new CKeepalive();
}


void
CKeepalive::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CKeepalive * pTarget = (CKeepalive *) pTargetElement;

  
}


void
CKeepalive::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CKeepalive::assimilateSubParameters (
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
CKeepalive::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;

  
}




/*
*****************************************************************
**
** Message KeepaliveAck
**
*****************************************************************
*/ 
  

const CTypeDescriptor
CKeepaliveAck::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "KeepaliveAck",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    301,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CKeepaliveAck::s_apFieldDescriptorTable[] =
{
  
    NULL
};

CKeepaliveAck::CKeepaliveAck (void)
{
    m_pType = &s_typeDescriptor;
  
}

CKeepaliveAck::~CKeepaliveAck (void)
{
}


CElement *
CKeepaliveAck::s_construct (void)
{
    return (CElement *) new CKeepaliveAck();
}


void
CKeepaliveAck::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CKeepaliveAck * pTarget = (CKeepaliveAck *) pTargetElement;

  
}


void
CKeepaliveAck::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CKeepaliveAck::assimilateSubParameters (
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
CKeepaliveAck::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;

  
}




/*
*****************************************************************
**
** Message DeviceEventNotification
**
*****************************************************************
*/ 
  

const CTypeDescriptor
CDeviceEventNotification::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "DeviceEventNotification",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    302,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CDeviceEventNotification::s_apFieldDescriptorTable[] =
{
  
    NULL
};

CDeviceEventNotification::CDeviceEventNotification (void)
{
    m_pType = &s_typeDescriptor;
  
    m_pUTCTimestamp = NULL;
    m_pGPIEvent = NULL;
    m_pSelectSpecEvent = NULL;
    m_pAntennaSpecEvent = NULL;
    m_pAntennaStatusEvent = NULL;
    m_pConnectionAttemptEvent = NULL;
}

CDeviceEventNotification::~CDeviceEventNotification (void)
{
}


CElement *
CDeviceEventNotification::s_construct (void)
{
    return (CElement *) new CDeviceEventNotification();
}


void
CDeviceEventNotification::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CDeviceEventNotification * pTarget = (CDeviceEventNotification *) pTargetElement;

  
}


void
CDeviceEventNotification::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CDeviceEventNotification::assimilateSubParameters (
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
    

    // 0-1 of GPIEvent
    pType = &CGPIEvent::s_typeDescriptor;
  
    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pGPIEvent = (CGPIEvent *)*Cur++;
    }
    

    // 0-1 of SelectSpecEvent
    pType = &CSelectSpecEvent::s_typeDescriptor;
  
    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pSelectSpecEvent = (CSelectSpecEvent *)*Cur++;
    }
    

    // 0-1 of AntennaSpecEvent
    pType = &CAntennaSpecEvent::s_typeDescriptor;
  
    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pAntennaSpecEvent = (CAntennaSpecEvent *)*Cur++;
    }
    

    // 0-1 of AntennaStatusEvent
    pType = &CAntennaStatusEvent::s_typeDescriptor;
  
    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pAntennaStatusEvent = (CAntennaStatusEvent *)*Cur++;
    }
    

    // 0-1 of ConnectionAttemptEvent
    pType = &CConnectionAttemptEvent::s_typeDescriptor;
  
    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pConnectionAttemptEvent = (CConnectionAttemptEvent *)*Cur++;
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
CDeviceEventNotification::setUTCTimestamp (
  CUTCTimestamp *     pValue)
{
    removeSubParameterFromAllList(m_pUTCTimestamp);
    delete m_pUTCTimestamp;
    m_pUTCTimestamp = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CDeviceEventNotification::setGPIEvent (
  CGPIEvent *     pValue)
{
    removeSubParameterFromAllList(m_pGPIEvent);
    delete m_pGPIEvent;
    m_pGPIEvent = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CDeviceEventNotification::setSelectSpecEvent (
  CSelectSpecEvent *     pValue)
{
    removeSubParameterFromAllList(m_pSelectSpecEvent);
    delete m_pSelectSpecEvent;
    m_pSelectSpecEvent = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CDeviceEventNotification::setAntennaSpecEvent (
  CAntennaSpecEvent *     pValue)
{
    removeSubParameterFromAllList(m_pAntennaSpecEvent);
    delete m_pAntennaSpecEvent;
    m_pAntennaSpecEvent = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CDeviceEventNotification::setAntennaStatusEvent (
  CAntennaStatusEvent *     pValue)
{
    removeSubParameterFromAllList(m_pAntennaStatusEvent);
    delete m_pAntennaStatusEvent;
    m_pAntennaStatusEvent = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CDeviceEventNotification::setConnectionAttemptEvent (
  CConnectionAttemptEvent *     pValue)
{
    removeSubParameterFromAllList(m_pConnectionAttemptEvent);
    delete m_pConnectionAttemptEvent;
    m_pConnectionAttemptEvent = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CDeviceEventNotification::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;

  
    pType = &CUTCTimestamp::s_typeDescriptor;
      
    pEncoderStream->putRequiredSubParameter(m_pUTCTimestamp, pType);
      
    pType = &CGPIEvent::s_typeDescriptor;
      
    pEncoderStream->putOptionalSubParameter(m_pGPIEvent, pType);
      
    pType = &CSelectSpecEvent::s_typeDescriptor;
      
    pEncoderStream->putOptionalSubParameter(m_pSelectSpecEvent, pType);
      
    pType = &CAntennaSpecEvent::s_typeDescriptor;
      
    pEncoderStream->putOptionalSubParameter(m_pAntennaSpecEvent, pType);
      
    pType = &CAntennaStatusEvent::s_typeDescriptor;
      
    pEncoderStream->putOptionalSubParameter(m_pAntennaStatusEvent, pType);
      
    pType = &CConnectionAttemptEvent::s_typeDescriptor;
      
    pEncoderStream->putOptionalSubParameter(m_pConnectionAttemptEvent, pType);
      
}




/*
*****************************************************************
**
** Parameter Status
**
*****************************************************************
*/ 
  

const CTypeDescriptor
CStatus::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "Status",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    300,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CStatus::s_apFieldDescriptorTable[] =
{
  
    &s_fdStatusCode,
    &s_fdErrorDescription,
    NULL
};



const CFieldDescriptor
CStatus::s_fdStatusCode =
{
    CFieldDescriptor::FT_E32,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "StatusCode",	// m_pName
    g_estStatusCode	// m_pEnumTable
};


const CFieldDescriptor
CStatus::s_fdErrorDescription =
{
    CFieldDescriptor::FT_UTF8V,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "ErrorDescription",	// m_pName
    NULL	// m_pEnumTable
};
CStatus::CStatus (void)
{
    m_pType = &s_typeDescriptor;
  
    m_eStatusCode = (EStatusCode) 0;
}

CStatus::~CStatus (void)
{
}


CElement *
CStatus::s_construct (void)
{
    return (CElement *) new CStatus();
}


void
CStatus::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CStatus * pTarget = (CStatus *) pTargetElement;

  
    if(NULL != pTarget)
    {
        pTarget->m_eStatusCode = (EStatusCode) pDecoderStream->get_e32(&s_fdStatusCode);
    }
    else
    {
        pDecoderStream->get_e32(&s_fdStatusCode);
    }

    if(NULL != pTarget)
    {
        pTarget->m_ErrorDescription = pDecoderStream->get_utf8v(&s_fdErrorDescription);
    }
    else
    {
        pDecoderStream->get_utf8v(&s_fdErrorDescription);
    }
    
}


void
CStatus::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CStatus::assimilateSubParameters (
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
CStatus::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;

  
    pEncoderStream->put_e32((int)m_eStatusCode, &s_fdStatusCode);

    pEncoderStream->put_utf8v(m_ErrorDescription, &s_fdErrorDescription);

}




/*
*****************************************************************
**
** Parameter UTCTimestamp
**
*****************************************************************
*/ 
  

const CTypeDescriptor
CUTCTimestamp::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "UTCTimestamp",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    301,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CUTCTimestamp::s_apFieldDescriptorTable[] =
{
  
    &s_fdMicroseconds,
    NULL
};



const CFieldDescriptor
CUTCTimestamp::s_fdMicroseconds =
{
    CFieldDescriptor::FT_U64,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "Microseconds",	// m_pName
    NULL	// m_pEnumTable
};
CUTCTimestamp::CUTCTimestamp (void)
{
    m_pType = &s_typeDescriptor;
  
    m_Microseconds = 0;
}

CUTCTimestamp::~CUTCTimestamp (void)
{
}


CElement *
CUTCTimestamp::s_construct (void)
{
    return (CElement *) new CUTCTimestamp();
}


void
CUTCTimestamp::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CUTCTimestamp * pTarget = (CUTCTimestamp *) pTargetElement;

  
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
CUTCTimestamp::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CUTCTimestamp::assimilateSubParameters (
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
CUTCTimestamp::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;

  
    pEncoderStream->put_u64(m_Microseconds, &s_fdMicroseconds);

}




/*
*****************************************************************
**
** Parameter GPIEvent
**
*****************************************************************
*/ 
  

const CTypeDescriptor
CGPIEvent::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "GPIEvent",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    302,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CGPIEvent::s_apFieldDescriptorTable[] =
{
  
    &s_fdGPIPortNumber,
    &s_fdGPIEvent,
    NULL
};



const CFieldDescriptor
CGPIEvent::s_fdGPIPortNumber =
{
    CFieldDescriptor::FT_U8,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "GPIPortNumber",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CGPIEvent::s_fdGPIEvent =
{
    CFieldDescriptor::FT_E1,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "GPIEvent",	// m_pName
    g_estGPIEvent	// m_pEnumTable
};
CGPIEvent::CGPIEvent (void)
{
    m_pType = &s_typeDescriptor;
  
    m_GPIPortNumber = 0;
    m_eGPIEvent = (EGPIEvent) 0;
}

CGPIEvent::~CGPIEvent (void)
{
}


CElement *
CGPIEvent::s_construct (void)
{
    return (CElement *) new CGPIEvent();
}


void
CGPIEvent::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CGPIEvent * pTarget = (CGPIEvent *) pTargetElement;

  
    if(NULL != pTarget)
    {
        pTarget->m_GPIPortNumber = pDecoderStream->get_u8(&s_fdGPIPortNumber);
    }
    else
    {
        pDecoderStream->get_u8(&s_fdGPIPortNumber);
    }
    
    if(NULL != pTarget)
    {
        pTarget->m_eGPIEvent = (EGPIEvent) pDecoderStream->get_e1(&s_fdGPIEvent);
    }
    else
    {
        pDecoderStream->get_e1(&s_fdGPIEvent);
    }

    pDecoderStream->get_reserved(7);

}


void
CGPIEvent::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CGPIEvent::assimilateSubParameters (
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
CGPIEvent::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;

  
    pEncoderStream->put_u8(m_GPIPortNumber, &s_fdGPIPortNumber);

    pEncoderStream->put_e1((int)m_eGPIEvent, &s_fdGPIEvent);

    pEncoderStream->put_reserved(7);

}




/*
*****************************************************************
**
** Parameter SelectSpecEvent
**
*****************************************************************
*/ 
  

const CTypeDescriptor
CSelectSpecEvent::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "SelectSpecEvent",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    303,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CSelectSpecEvent::s_apFieldDescriptorTable[] =
{
  
    &s_fdEventType,
    &s_fdSelectSpecID,
    &s_fdPreemptingSelectSpecID,
    NULL
};



const CFieldDescriptor
CSelectSpecEvent::s_fdEventType =
{
    CFieldDescriptor::FT_E8,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "EventType",	// m_pName
    g_estEventType	// m_pEnumTable
};


const CFieldDescriptor
CSelectSpecEvent::s_fdSelectSpecID =
{
    CFieldDescriptor::FT_U32,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "SelectSpecID",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CSelectSpecEvent::s_fdPreemptingSelectSpecID =
{
    CFieldDescriptor::FT_U32,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "PreemptingSelectSpecID",	// m_pName
    NULL	// m_pEnumTable
};
CSelectSpecEvent::CSelectSpecEvent (void)
{
    m_pType = &s_typeDescriptor;
  
    m_eEventType = (EEventType) 0;
    m_SelectSpecID = 0;
    m_PreemptingSelectSpecID = 0;
}

CSelectSpecEvent::~CSelectSpecEvent (void)
{
}


CElement *
CSelectSpecEvent::s_construct (void)
{
    return (CElement *) new CSelectSpecEvent();
}


void
CSelectSpecEvent::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CSelectSpecEvent * pTarget = (CSelectSpecEvent *) pTargetElement;

  
    if(NULL != pTarget)
    {
        pTarget->m_eEventType = (EEventType) pDecoderStream->get_e8(&s_fdEventType);
    }
    else
    {
        pDecoderStream->get_e8(&s_fdEventType);
    }

    if(NULL != pTarget)
    {
        pTarget->m_SelectSpecID = pDecoderStream->get_u32(&s_fdSelectSpecID);
    }
    else
    {
        pDecoderStream->get_u32(&s_fdSelectSpecID);
    }
    
    if(NULL != pTarget)
    {
        pTarget->m_PreemptingSelectSpecID = pDecoderStream->get_u32(&s_fdPreemptingSelectSpecID);
    }
    else
    {
        pDecoderStream->get_u32(&s_fdPreemptingSelectSpecID);
    }
    
}


void
CSelectSpecEvent::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CSelectSpecEvent::assimilateSubParameters (
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
CSelectSpecEvent::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;

  
    pEncoderStream->put_e8((int)m_eEventType, &s_fdEventType);

    pEncoderStream->put_u32(m_SelectSpecID, &s_fdSelectSpecID);

    pEncoderStream->put_u32(m_PreemptingSelectSpecID, &s_fdPreemptingSelectSpecID);

}




/*
*****************************************************************
**
** Parameter AntennaSpecEvent
**
*****************************************************************
*/ 
  

const CTypeDescriptor
CAntennaSpecEvent::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "AntennaSpecEvent",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    304,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CAntennaSpecEvent::s_apFieldDescriptorTable[] =
{
  
    &s_fdEventType,
    &s_fdSelectSpecID,
    &s_fdSpecIndex,
    NULL
};



const CFieldDescriptor
CAntennaSpecEvent::s_fdEventType =
{
    CFieldDescriptor::FT_E8,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "EventType",	// m_pName
    g_estEventType	// m_pEnumTable
};


const CFieldDescriptor
CAntennaSpecEvent::s_fdSelectSpecID =
{
    CFieldDescriptor::FT_U32,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "SelectSpecID",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CAntennaSpecEvent::s_fdSpecIndex =
{
    CFieldDescriptor::FT_U16,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "SpecIndex",	// m_pName
    NULL	// m_pEnumTable
};
CAntennaSpecEvent::CAntennaSpecEvent (void)
{
    m_pType = &s_typeDescriptor;
  
    m_eEventType = (EEventType) 0;
    m_SelectSpecID = 0;
    m_SpecIndex = 0;
}

CAntennaSpecEvent::~CAntennaSpecEvent (void)
{
}


CElement *
CAntennaSpecEvent::s_construct (void)
{
    return (CElement *) new CAntennaSpecEvent();
}


void
CAntennaSpecEvent::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CAntennaSpecEvent * pTarget = (CAntennaSpecEvent *) pTargetElement;

  
    if(NULL != pTarget)
    {
        pTarget->m_eEventType = (EEventType) pDecoderStream->get_e8(&s_fdEventType);
    }
    else
    {
        pDecoderStream->get_e8(&s_fdEventType);
    }

    if(NULL != pTarget)
    {
        pTarget->m_SelectSpecID = pDecoderStream->get_u32(&s_fdSelectSpecID);
    }
    else
    {
        pDecoderStream->get_u32(&s_fdSelectSpecID);
    }
    
    if(NULL != pTarget)
    {
        pTarget->m_SpecIndex = pDecoderStream->get_u16(&s_fdSpecIndex);
    }
    else
    {
        pDecoderStream->get_u16(&s_fdSpecIndex);
    }
    
}


void
CAntennaSpecEvent::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CAntennaSpecEvent::assimilateSubParameters (
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
CAntennaSpecEvent::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;

  
    pEncoderStream->put_e8((int)m_eEventType, &s_fdEventType);

    pEncoderStream->put_u32(m_SelectSpecID, &s_fdSelectSpecID);

    pEncoderStream->put_u16(m_SpecIndex, &s_fdSpecIndex);

}




/*
*****************************************************************
**
** Parameter AntennaStatusEvent
**
*****************************************************************
*/ 
  

const CTypeDescriptor
CAntennaStatusEvent::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "AntennaStatusEvent",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    305,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CAntennaStatusEvent::s_apFieldDescriptorTable[] =
{
  
    &s_fdEventType,
    &s_fdAntennaID,
    NULL
};



const CFieldDescriptor
CAntennaStatusEvent::s_fdEventType =
{
    CFieldDescriptor::FT_E8,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "EventType",	// m_pName
    g_estEventType	// m_pEnumTable
};


const CFieldDescriptor
CAntennaStatusEvent::s_fdAntennaID =
{
    CFieldDescriptor::FT_U8,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "AntennaID",	// m_pName
    NULL	// m_pEnumTable
};
CAntennaStatusEvent::CAntennaStatusEvent (void)
{
    m_pType = &s_typeDescriptor;
  
    m_eEventType = (EEventType) 0;
    m_AntennaID = 0;
}

CAntennaStatusEvent::~CAntennaStatusEvent (void)
{
}


CElement *
CAntennaStatusEvent::s_construct (void)
{
    return (CElement *) new CAntennaStatusEvent();
}


void
CAntennaStatusEvent::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CAntennaStatusEvent * pTarget = (CAntennaStatusEvent *) pTargetElement;

  
    if(NULL != pTarget)
    {
        pTarget->m_eEventType = (EEventType) pDecoderStream->get_e8(&s_fdEventType);
    }
    else
    {
        pDecoderStream->get_e8(&s_fdEventType);
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
CAntennaStatusEvent::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CAntennaStatusEvent::assimilateSubParameters (
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
CAntennaStatusEvent::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;

  
    pEncoderStream->put_e8((int)m_eEventType, &s_fdEventType);

    pEncoderStream->put_u8(m_AntennaID, &s_fdAntennaID);

}




/*
*****************************************************************
**
** Parameter ConnectionAttemptEvent
**
*****************************************************************
*/ 
  

const CTypeDescriptor
CConnectionAttemptEvent::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "ConnectionAttemptEvent",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    306,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CConnectionAttemptEvent::s_apFieldDescriptorTable[] =
{
  
    &s_fdConnectionStatus,
    NULL
};



const CFieldDescriptor
CConnectionAttemptEvent::s_fdConnectionStatus =
{
    CFieldDescriptor::FT_E16,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "ConnectionStatus",	// m_pName
    g_estConnectionStatus	// m_pEnumTable
};
CConnectionAttemptEvent::CConnectionAttemptEvent (void)
{
    m_pType = &s_typeDescriptor;
  
    m_eConnectionStatus = (EConnectionStatus) 0;
}

CConnectionAttemptEvent::~CConnectionAttemptEvent (void)
{
}


CElement *
CConnectionAttemptEvent::s_construct (void)
{
    return (CElement *) new CConnectionAttemptEvent();
}


void
CConnectionAttemptEvent::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CConnectionAttemptEvent * pTarget = (CConnectionAttemptEvent *) pTargetElement;

  
    if(NULL != pTarget)
    {
        pTarget->m_eConnectionStatus = (EConnectionStatus) pDecoderStream->get_e16(&s_fdConnectionStatus);
    }
    else
    {
        pDecoderStream->get_e16(&s_fdConnectionStatus);
    }

}


void
CConnectionAttemptEvent::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CConnectionAttemptEvent::assimilateSubParameters (
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
CConnectionAttemptEvent::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;

  
    pEncoderStream->put_e16((int)m_eConnectionStatus, &s_fdConnectionStatus);

}

/*
void
enrollCoreTypesIntoRegistry (
  CTypeRegistry *               pTypeRegistry)
{
  
    pTypeRegistry->enroll(&CStatus::s_typeDescriptor);
  
    pTypeRegistry->enroll(&CKeepalive::s_typeDescriptor);
  
    pTypeRegistry->enroll(&CKeepaliveAck::s_typeDescriptor);
  
    pTypeRegistry->enroll(&CDeviceEventNotification::s_typeDescriptor);
  
    pTypeRegistry->enroll(&CUTCTimestamp::s_typeDescriptor);
  
    pTypeRegistry->enroll(&CGPIEvent::s_typeDescriptor);
  
    pTypeRegistry->enroll(&CSelectSpecEvent::s_typeDescriptor);
  
    pTypeRegistry->enroll(&CAntennaSpecEvent::s_typeDescriptor);
  
    pTypeRegistry->enroll(&CAntennaStatusEvent::s_typeDescriptor);
  
    pTypeRegistry->enroll(&CConnectionAttemptEvent::s_typeDescriptor);
  
}
*/

};//end of namespace llrp
