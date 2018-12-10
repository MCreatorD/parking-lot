#include "LLRP_Capabilities.h"

#include "LLRP_General.h"
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

  
/*
 * Enumeration string tables
 */

const SEnumTableEntry
g_estGetDeviceCapabilitiesRequestedData[] =
{

    {
        "All",
        GetDeviceCapabilitiesRequestedData_All,
    },
    {
        "GenaralCapabilities",
        GetDeviceCapabilitiesRequestedData_GenaralCapabilities,
    },
    {
        "CommunicationCapabilities",
        GetDeviceCapabilitiesRequestedData_CommunicationCapabilities,
    },
    {
        "SpecCapabilities",
        GetDeviceCapabilitiesRequestedData_SpecCapabilities,
    },
    {
        "RfCapabilities",
        GetDeviceCapabilitiesRequestedData_RfCapabilities,
    },
    {
        "AirProtocolCapabilities",
        GetDeviceCapabilitiesRequestedData_AirProtocolCapabilities,
    },
    { 0, 0 }
};




/*
*****************************************************************
**
** Message GetDeviceCapabilities
**
*****************************************************************
*/ 
  

const CTypeDescriptor
CGetDeviceCapabilities::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "GetDeviceCapabilities",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    350,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CGetDeviceCapabilities::s_apFieldDescriptorTable[] =
{
  
    &s_fdRequestedData,
    NULL
};



const CFieldDescriptor
CGetDeviceCapabilities::s_fdRequestedData =
{
    CFieldDescriptor::FT_E8,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "RequestedData",	// m_pName
    g_estGetDeviceCapabilitiesRequestedData	// m_pEnumTable
};
CGetDeviceCapabilities::CGetDeviceCapabilities (void)
{
    m_pType = &s_typeDescriptor;
  
    m_eRequestedData = (EGetDeviceCapabilitiesRequestedData) 0;
}

CGetDeviceCapabilities::~CGetDeviceCapabilities (void)
{
}


CElement *
CGetDeviceCapabilities::s_construct (void)
{
    return (CElement *) new CGetDeviceCapabilities();
}


void
CGetDeviceCapabilities::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CGetDeviceCapabilities * pTarget = (CGetDeviceCapabilities *) pTargetElement;

  
    if(NULL != pTarget)
    {
        pTarget->m_eRequestedData = (EGetDeviceCapabilitiesRequestedData) pDecoderStream->get_e8(&s_fdRequestedData);
    }
    else
    {
        pDecoderStream->get_e8(&s_fdRequestedData);
    }

}


void
CGetDeviceCapabilities::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CGetDeviceCapabilities::assimilateSubParameters (
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
CGetDeviceCapabilities::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;

  
    pEncoderStream->put_e8((int)m_eRequestedData, &s_fdRequestedData);

}




/*
*****************************************************************
**
** Message GetDeviceCapabilitiesAck
**
*****************************************************************
*/


const CTypeDescriptor
CGetDeviceCapabilitiesAck::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "GetDeviceCapabilitiesAck",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    351,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CGetDeviceCapabilitiesAck::s_apFieldDescriptorTable[] =
{

    NULL
};

CGetDeviceCapabilitiesAck::CGetDeviceCapabilitiesAck (void)
{
    m_pType = &s_typeDescriptor;

    m_pStatus = NULL;
    m_pGenaralCapabilities = NULL;
    m_pCommunicationCapabilities = NULL;
    m_pSpecCapabilities = NULL;
    m_pRfCapabilities = NULL;
    m_pAirProtocolCapabilities = NULL;
}

CGetDeviceCapabilitiesAck::~CGetDeviceCapabilitiesAck (void)
{
}


CElement *
CGetDeviceCapabilitiesAck::s_construct (void)
{
    return (CElement *) new CGetDeviceCapabilitiesAck();
}


void
CGetDeviceCapabilitiesAck::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CGetDeviceCapabilitiesAck * pTarget = (CGetDeviceCapabilitiesAck *) pTargetElement;


}


void
CGetDeviceCapabilitiesAck::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CGetDeviceCapabilitiesAck::assimilateSubParameters (
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


    // 0-1 of GenaralCapabilities
    pType = &CGenaralCapabilities::s_typeDescriptor;

    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pGenaralCapabilities = (CGenaralCapabilities *)*Cur++;
    }


    // 0-1 of CommunicationCapabilities
    pType = &CCommunicationCapabilities::s_typeDescriptor;

    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pCommunicationCapabilities = (CCommunicationCapabilities *)*Cur++;
    }


    // 0-1 of SpecCapabilities
    pType = &CSpecCapabilities::s_typeDescriptor;

    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pSpecCapabilities = (CSpecCapabilities *)*Cur++;
    }


    // 0-1 of RfCapabilities
    pType = &CRfCapabilities::s_typeDescriptor;

    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pRfCapabilities = (CRfCapabilities *)*Cur++;
    }


    // 0-1 of AirProtocolCapabilities
    pType = &CAirProtocolCapabilities::s_typeDescriptor;

    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pAirProtocolCapabilities = (CAirProtocolCapabilities *)*Cur++;
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
CGetDeviceCapabilitiesAck::setStatus (
  CStatus *     pValue)
{
    removeSubParameterFromAllList(m_pStatus);
    delete m_pStatus;
    m_pStatus = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CGetDeviceCapabilitiesAck::setGenaralCapabilities (
  CGenaralCapabilities *     pValue)
{
    removeSubParameterFromAllList(m_pGenaralCapabilities);
    delete m_pGenaralCapabilities;
    m_pGenaralCapabilities = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CGetDeviceCapabilitiesAck::setCommunicationCapabilities (
  CCommunicationCapabilities *     pValue)
{
    removeSubParameterFromAllList(m_pCommunicationCapabilities);
    delete m_pCommunicationCapabilities;
    m_pCommunicationCapabilities = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CGetDeviceCapabilitiesAck::setSpecCapabilities (
  CSpecCapabilities *     pValue)
{
    removeSubParameterFromAllList(m_pSpecCapabilities);
    delete m_pSpecCapabilities;
    m_pSpecCapabilities = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CGetDeviceCapabilitiesAck::setRfCapabilities (
  CRfCapabilities *     pValue)
{
    removeSubParameterFromAllList(m_pRfCapabilities);
    delete m_pRfCapabilities;
    m_pRfCapabilities = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CGetDeviceCapabilitiesAck::setAirProtocolCapabilities (
  CAirProtocolCapabilities *     pValue)
{
    removeSubParameterFromAllList(m_pAirProtocolCapabilities);
    delete m_pAirProtocolCapabilities;
    m_pAirProtocolCapabilities = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CGetDeviceCapabilitiesAck::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pType = &CStatus::s_typeDescriptor;

    pEncoderStream->putRequiredSubParameter(m_pStatus, pType);

    pType = &CGenaralCapabilities::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameter(m_pGenaralCapabilities, pType);

    pType = &CCommunicationCapabilities::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameter(m_pCommunicationCapabilities, pType);

    pType = &CSpecCapabilities::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameter(m_pSpecCapabilities, pType);

    pType = &CRfCapabilities::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameter(m_pRfCapabilities, pType);

    pType = &CAirProtocolCapabilities::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameter(m_pAirProtocolCapabilities, pType);

}




/*
*****************************************************************
**
** Parameter GenaralCapabilities
**
*****************************************************************
*/ 
  

const CTypeDescriptor
CGenaralCapabilities::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "GenaralCapabilities",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    350,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CGenaralCapabilities::s_apFieldDescriptorTable[] =
{

    &s_fdDeviceManufacturerName,
    &s_fdDeviceSN,
    &s_fdDeviceModelType,
    &s_fdDeviceSpecificationType,
    &s_fdMaxNumberOfAntennaSupported,
    &s_fdHasUTCClockCapability,
    &s_fdHasLocationCapability,
    &s_fdIsDeviceBinded,
    NULL
};



const CFieldDescriptor
CGenaralCapabilities::s_fdDeviceManufacturerName =
{
    CFieldDescriptor::FT_UTF8V,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "DeviceManufacturerName",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CGenaralCapabilities::s_fdDeviceSN =
{
    CFieldDescriptor::FT_U8V,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "DeviceSN",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CGenaralCapabilities::s_fdDeviceModelType =
{
    CFieldDescriptor::FT_U16,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "DeviceModelType",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CGenaralCapabilities::s_fdDeviceSpecificationType =
{
    CFieldDescriptor::FT_U16,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "DeviceSpecificationType",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CGenaralCapabilities::s_fdMaxNumberOfAntennaSupported =
{
    CFieldDescriptor::FT_U8,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "MaxNumberOfAntennaSupported",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CGenaralCapabilities::s_fdHasUTCClockCapability =
{
    CFieldDescriptor::FT_U1,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "HasUTCClockCapability",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CGenaralCapabilities::s_fdHasLocationCapability =
{
    CFieldDescriptor::FT_U1,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "HasLocationCapability",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CGenaralCapabilities::s_fdIsDeviceBinded =
{
    CFieldDescriptor::FT_U1,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "IsDeviceBinded",	// m_pName
    NULL	// m_pEnumTable
};
CGenaralCapabilities::CGenaralCapabilities (void)
{
    m_pType = &s_typeDescriptor;

    m_DeviceModelType = 0;
    m_DeviceSpecificationType = 0;
    m_MaxNumberOfAntennaSupported = 0;
    m_HasUTCClockCapability = 0;
    m_HasLocationCapability = 0;
    m_IsDeviceBinded = 0;
    m_pGPIOCapabilities = NULL;
}

CGenaralCapabilities::~CGenaralCapabilities (void)
{
}


CElement *
CGenaralCapabilities::s_construct (void)
{
    return (CElement *) new CGenaralCapabilities();
}


void
CGenaralCapabilities::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CGenaralCapabilities * pTarget = (CGenaralCapabilities *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_DeviceManufacturerName = pDecoderStream->get_utf8v(&s_fdDeviceManufacturerName);
    }
    else
    {
        pDecoderStream->get_utf8v(&s_fdDeviceManufacturerName);
    }

    if(NULL != pTarget)
    {
        pTarget->m_DeviceSN = pDecoderStream->get_u8v(&s_fdDeviceSN);
    }
    else
    {
        pDecoderStream->get_u8v(&s_fdDeviceSN);
    }

    if(NULL != pTarget)
    {
        pTarget->m_DeviceModelType = pDecoderStream->get_u16(&s_fdDeviceModelType);
    }
    else
    {
        pDecoderStream->get_u16(&s_fdDeviceModelType);
    }

    if(NULL != pTarget)
    {
        pTarget->m_DeviceSpecificationType = pDecoderStream->get_u16(&s_fdDeviceSpecificationType);
    }
    else
    {
        pDecoderStream->get_u16(&s_fdDeviceSpecificationType);
    }

    if(NULL != pTarget)
    {
        pTarget->m_MaxNumberOfAntennaSupported = pDecoderStream->get_u8(&s_fdMaxNumberOfAntennaSupported);
    }
    else
    {
        pDecoderStream->get_u8(&s_fdMaxNumberOfAntennaSupported);
    }

    if(NULL != pTarget)
    {
        pTarget->m_HasUTCClockCapability = pDecoderStream->get_u1(&s_fdHasUTCClockCapability);
    }
    else
    {
        pDecoderStream->get_u1(&s_fdHasUTCClockCapability);
    }

    if(NULL != pTarget)
    {
        pTarget->m_HasLocationCapability = pDecoderStream->get_u1(&s_fdHasLocationCapability);
    }
    else
    {
        pDecoderStream->get_u1(&s_fdHasLocationCapability);
    }

    if(NULL != pTarget)
    {
        pTarget->m_IsDeviceBinded = pDecoderStream->get_u1(&s_fdIsDeviceBinded);
    }
    else
    {
        pDecoderStream->get_u1(&s_fdIsDeviceBinded);
    }

    pDecoderStream->get_reserved(5);

}


void
CGenaralCapabilities::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CGenaralCapabilities::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    // 1 of GPIOCapabilities
    pType = &CGPIOCapabilities::s_typeDescriptor;

    if(Cur == End || (*Cur)->m_pType != pType)
    {
        goto missing;
    }
    m_pGPIOCapabilities = (CGPIOCapabilities *)*Cur++;


    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


EResultCode
CGenaralCapabilities::setGPIOCapabilities (
  CGPIOCapabilities *     pValue)
{
    removeSubParameterFromAllList(m_pGPIOCapabilities);
    delete m_pGPIOCapabilities;
    m_pGPIOCapabilities = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CGenaralCapabilities::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_utf8v(m_DeviceManufacturerName, &s_fdDeviceManufacturerName);

    pEncoderStream->put_u8v(m_DeviceSN, &s_fdDeviceSN);

    pEncoderStream->put_u16(m_DeviceModelType, &s_fdDeviceModelType);

    pEncoderStream->put_u16(m_DeviceSpecificationType, &s_fdDeviceSpecificationType);

    pEncoderStream->put_u8(m_MaxNumberOfAntennaSupported, &s_fdMaxNumberOfAntennaSupported);

    pEncoderStream->put_u1(m_HasUTCClockCapability, &s_fdHasUTCClockCapability);

    pEncoderStream->put_u1(m_HasLocationCapability, &s_fdHasLocationCapability);

    pEncoderStream->put_u1(m_IsDeviceBinded, &s_fdIsDeviceBinded);

    pEncoderStream->put_reserved(5);

    pType = &CGPIOCapabilities::s_typeDescriptor;

    pEncoderStream->putRequiredSubParameter(m_pGPIOCapabilities, pType);

}






/*
*****************************************************************
**
** Parameter GPIOCapabilities
**
*****************************************************************
*/ 
  

const CTypeDescriptor
CGPIOCapabilities::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "GPIOCapabilities",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    351,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CGPIOCapabilities::s_apFieldDescriptorTable[] =
{
  
    &s_fdNumGPIs,
    &s_fdNumGPOs,
    NULL
};



const CFieldDescriptor
CGPIOCapabilities::s_fdNumGPIs =
{
    CFieldDescriptor::FT_U8,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "NumGPIs",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CGPIOCapabilities::s_fdNumGPOs =
{
    CFieldDescriptor::FT_U8,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "NumGPOs",	// m_pName
    NULL	// m_pEnumTable
};
CGPIOCapabilities::CGPIOCapabilities (void)
{
    m_pType = &s_typeDescriptor;
  
    m_NumGPIs = 0;
    m_NumGPOs = 0;
}

CGPIOCapabilities::~CGPIOCapabilities (void)
{
}


CElement *
CGPIOCapabilities::s_construct (void)
{
    return (CElement *) new CGPIOCapabilities();
}


void
CGPIOCapabilities::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CGPIOCapabilities * pTarget = (CGPIOCapabilities *) pTargetElement;

  
    if(NULL != pTarget)
    {
        pTarget->m_NumGPIs = pDecoderStream->get_u8(&s_fdNumGPIs);
    }
    else
    {
        pDecoderStream->get_u8(&s_fdNumGPIs);
    }
    
    if(NULL != pTarget)
    {
        pTarget->m_NumGPOs = pDecoderStream->get_u8(&s_fdNumGPOs);
    }
    else
    {
        pDecoderStream->get_u8(&s_fdNumGPOs);
    }
    
}


void
CGPIOCapabilities::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CGPIOCapabilities::assimilateSubParameters (
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
CGPIOCapabilities::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;

  
    pEncoderStream->put_u8(m_NumGPIs, &s_fdNumGPIs);

    pEncoderStream->put_u8(m_NumGPOs, &s_fdNumGPOs);

}




/*
*****************************************************************
**
** Parameter CommunicationCapabilities
**
*****************************************************************
*/ 
  

const CTypeDescriptor
CCommunicationCapabilities::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "CommunicationCapabilities",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    352,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CCommunicationCapabilities::s_apFieldDescriptorTable[] =
{
  
    &s_fdSupportEthernet,
    &s_fdSupportWIFI,
    &s_fdSupportMobile,
    &s_fdSupportUSB,
    &s_fdSupportHttpLink,
    &s_fdSupportIPV6,
    &s_fdSupportSSL,
    &s_fdSupportTcpLinkNum,
    NULL
};



const CFieldDescriptor
CCommunicationCapabilities::s_fdSupportEthernet =
{
    CFieldDescriptor::FT_U1,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "SupportEthernet",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CCommunicationCapabilities::s_fdSupportWIFI =
{
    CFieldDescriptor::FT_U1,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "SupportWIFI",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CCommunicationCapabilities::s_fdSupportMobile =
{
    CFieldDescriptor::FT_U1,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "SupportMobile",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CCommunicationCapabilities::s_fdSupportUSB =
{
    CFieldDescriptor::FT_U1,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "SupportUSB",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CCommunicationCapabilities::s_fdSupportHttpLink =
{
    CFieldDescriptor::FT_U1,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "SupportHttpLink",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CCommunicationCapabilities::s_fdSupportIPV6 =
{
    CFieldDescriptor::FT_U1,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "SupportIPV6",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CCommunicationCapabilities::s_fdSupportSSL =
{
    CFieldDescriptor::FT_U1,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "SupportSSL",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CCommunicationCapabilities::s_fdSupportTcpLinkNum =
{
    CFieldDescriptor::FT_U8,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "SupportTcpLinkNum",	// m_pName
    NULL	// m_pEnumTable
};
CCommunicationCapabilities::CCommunicationCapabilities (void)
{
    m_pType = &s_typeDescriptor;
  
    m_SupportEthernet = 0;
    m_SupportWIFI = 0;
    m_SupportMobile = 0;
    m_SupportUSB = 0;
    m_SupportHttpLink = 0;
    m_SupportIPV6 = 0;
    m_SupportSSL = 0;
    m_SupportTcpLinkNum = 0;
    m_pSupportRS232 = NULL;
    m_pSupportRS485 = NULL;
}

CCommunicationCapabilities::~CCommunicationCapabilities (void)
{
}


CElement *
CCommunicationCapabilities::s_construct (void)
{
    return (CElement *) new CCommunicationCapabilities();
}


void
CCommunicationCapabilities::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CCommunicationCapabilities * pTarget = (CCommunicationCapabilities *) pTargetElement;

  
    if(NULL != pTarget)
    {
        pTarget->m_SupportEthernet = pDecoderStream->get_u1(&s_fdSupportEthernet);
    }
    else
    {
        pDecoderStream->get_u1(&s_fdSupportEthernet);
    }
    
    if(NULL != pTarget)
    {
        pTarget->m_SupportWIFI = pDecoderStream->get_u1(&s_fdSupportWIFI);
    }
    else
    {
        pDecoderStream->get_u1(&s_fdSupportWIFI);
    }
    
    if(NULL != pTarget)
    {
        pTarget->m_SupportMobile = pDecoderStream->get_u1(&s_fdSupportMobile);
    }
    else
    {
        pDecoderStream->get_u1(&s_fdSupportMobile);
    }
    
    if(NULL != pTarget)
    {
        pTarget->m_SupportUSB = pDecoderStream->get_u1(&s_fdSupportUSB);
    }
    else
    {
        pDecoderStream->get_u1(&s_fdSupportUSB);
    }
    
    if(NULL != pTarget)
    {
        pTarget->m_SupportHttpLink = pDecoderStream->get_u1(&s_fdSupportHttpLink);
    }
    else
    {
        pDecoderStream->get_u1(&s_fdSupportHttpLink);
    }
    
    if(NULL != pTarget)
    {
        pTarget->m_SupportIPV6 = pDecoderStream->get_u1(&s_fdSupportIPV6);
    }
    else
    {
        pDecoderStream->get_u1(&s_fdSupportIPV6);
    }
    
    if(NULL != pTarget)
    {
        pTarget->m_SupportSSL = pDecoderStream->get_u1(&s_fdSupportSSL);
    }
    else
    {
        pDecoderStream->get_u1(&s_fdSupportSSL);
    }
    
    pDecoderStream->get_reserved(1);

    if(NULL != pTarget)
    {
        pTarget->m_SupportTcpLinkNum = pDecoderStream->get_u8(&s_fdSupportTcpLinkNum);
    }
    else
    {
        pDecoderStream->get_u8(&s_fdSupportTcpLinkNum);
    }
    
}


void
CCommunicationCapabilities::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CCommunicationCapabilities::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;

  

    // 0-1 of SupportRS232
    pType = &CSupportRS232::s_typeDescriptor;
  
    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pSupportRS232 = (CSupportRS232 *)*Cur++;
    }
    

    // 0-1 of SupportRS485
    pType = &CSupportRS485::s_typeDescriptor;
  
    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pSupportRS485 = (CSupportRS485 *)*Cur++;
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
CCommunicationCapabilities::setSupportRS232 (
  CSupportRS232 *     pValue)
{
    removeSubParameterFromAllList(m_pSupportRS232);
    delete m_pSupportRS232;
    m_pSupportRS232 = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CCommunicationCapabilities::setSupportRS485 (
  CSupportRS485 *     pValue)
{
    removeSubParameterFromAllList(m_pSupportRS485);
    delete m_pSupportRS485;
    m_pSupportRS485 = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CCommunicationCapabilities::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;

  
    pEncoderStream->put_u1(m_SupportEthernet, &s_fdSupportEthernet);

    pEncoderStream->put_u1(m_SupportWIFI, &s_fdSupportWIFI);

    pEncoderStream->put_u1(m_SupportMobile, &s_fdSupportMobile);

    pEncoderStream->put_u1(m_SupportUSB, &s_fdSupportUSB);

    pEncoderStream->put_u1(m_SupportHttpLink, &s_fdSupportHttpLink);

    pEncoderStream->put_u1(m_SupportIPV6, &s_fdSupportIPV6);

    pEncoderStream->put_u1(m_SupportSSL, &s_fdSupportSSL);

    pEncoderStream->put_reserved(1);

    pEncoderStream->put_u8(m_SupportTcpLinkNum, &s_fdSupportTcpLinkNum);

    pType = &CSupportRS232::s_typeDescriptor;
      
    pEncoderStream->putOptionalSubParameter(m_pSupportRS232, pType);
      
    pType = &CSupportRS485::s_typeDescriptor;
      
    pEncoderStream->putOptionalSubParameter(m_pSupportRS485, pType);
      
}




/*
*****************************************************************
**
** Parameter SupportRS232
**
*****************************************************************
*/ 
  

const CTypeDescriptor
CSupportRS232::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "SupportRS232",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    353,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CSupportRS232::s_apFieldDescriptorTable[] =
{
  
    &s_fdPortNum,
    NULL
};



const CFieldDescriptor
CSupportRS232::s_fdPortNum =
{
    CFieldDescriptor::FT_U8,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "PortNum",	// m_pName
    NULL	// m_pEnumTable
};
CSupportRS232::CSupportRS232 (void)
{
    m_pType = &s_typeDescriptor;
  
    m_PortNum = 0;
}

CSupportRS232::~CSupportRS232 (void)
{
}


CElement *
CSupportRS232::s_construct (void)
{
    return (CElement *) new CSupportRS232();
}


void
CSupportRS232::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CSupportRS232 * pTarget = (CSupportRS232 *) pTargetElement;

  
    if(NULL != pTarget)
    {
        pTarget->m_PortNum = pDecoderStream->get_u8(&s_fdPortNum);
    }
    else
    {
        pDecoderStream->get_u8(&s_fdPortNum);
    }
    
}


void
CSupportRS232::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CSupportRS232::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;

  

    // 1-N of SerialAttribute
    pType = &CSerialAttribute::s_typeDescriptor;
  
    if(Cur == End || (*Cur)->m_pType != pType)
    {
        goto missing;
    }
    while(Cur != End && (*Cur)->m_pType == pType)
    {
        m_listSerialAttribute.push_back((CSerialAttribute *)*Cur);
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
CSupportRS232::addSerialAttribute (
  CSerialAttribute *     pValue)
{
    m_listSerialAttribute.push_back(pValue);
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CSupportRS232::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;

  
    pEncoderStream->put_u8(m_PortNum, &s_fdPortNum);

    pType = &CSerialAttribute::s_typeDescriptor;
      
    pEncoderStream->putRequiredSubParameterList((tListOfParameters *) &m_listSerialAttribute, pType);
      
}




/*
*****************************************************************
**
** Parameter SerialAttribute
**
*****************************************************************
*/ 
  

const CTypeDescriptor
CSerialAttribute::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "SerialAttribute",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    354,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CSerialAttribute::s_apFieldDescriptorTable[] =
{
  
    &s_fdBaudRate,
    &s_fdDataBit,
    &s_fdStopBit,
    &s_fdParity,
    &s_fdFlowControl,
    NULL
};



const CFieldDescriptor
CSerialAttribute::s_fdBaudRate =
{
    CFieldDescriptor::FT_U32,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "BaudRate",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CSerialAttribute::s_fdDataBit =
{
    CFieldDescriptor::FT_U8,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "DataBit",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CSerialAttribute::s_fdStopBit =
{
    CFieldDescriptor::FT_U8,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "StopBit",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CSerialAttribute::s_fdParity =
{
    CFieldDescriptor::FT_U8,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "Parity",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CSerialAttribute::s_fdFlowControl =
{
    CFieldDescriptor::FT_U8,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "FlowControl",	// m_pName
    NULL	// m_pEnumTable
};
CSerialAttribute::CSerialAttribute (void)
{
    m_pType = &s_typeDescriptor;
  
    m_BaudRate = 0;
    m_DataBit = 0;
    m_StopBit = 0;
    m_Parity = 0;
    m_FlowControl = 0;
}

CSerialAttribute::~CSerialAttribute (void)
{
}


CElement *
CSerialAttribute::s_construct (void)
{
    return (CElement *) new CSerialAttribute();
}


void
CSerialAttribute::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CSerialAttribute * pTarget = (CSerialAttribute *) pTargetElement;

  
    if(NULL != pTarget)
    {
        pTarget->m_BaudRate = pDecoderStream->get_u32(&s_fdBaudRate);
    }
    else
    {
        pDecoderStream->get_u32(&s_fdBaudRate);
    }
    
    if(NULL != pTarget)
    {
        pTarget->m_DataBit = pDecoderStream->get_u8(&s_fdDataBit);
    }
    else
    {
        pDecoderStream->get_u8(&s_fdDataBit);
    }
    
    if(NULL != pTarget)
    {
        pTarget->m_StopBit = pDecoderStream->get_u8(&s_fdStopBit);
    }
    else
    {
        pDecoderStream->get_u8(&s_fdStopBit);
    }
    
    if(NULL != pTarget)
    {
        pTarget->m_Parity = pDecoderStream->get_u8(&s_fdParity);
    }
    else
    {
        pDecoderStream->get_u8(&s_fdParity);
    }
    
    if(NULL != pTarget)
    {
        pTarget->m_FlowControl = pDecoderStream->get_u8(&s_fdFlowControl);
    }
    else
    {
        pDecoderStream->get_u8(&s_fdFlowControl);
    }
    
}


void
CSerialAttribute::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CSerialAttribute::assimilateSubParameters (
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
CSerialAttribute::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;

  
    pEncoderStream->put_u32(m_BaudRate, &s_fdBaudRate);

    pEncoderStream->put_u8(m_DataBit, &s_fdDataBit);

    pEncoderStream->put_u8(m_StopBit, &s_fdStopBit);

    pEncoderStream->put_u8(m_Parity, &s_fdParity);

    pEncoderStream->put_u8(m_FlowControl, &s_fdFlowControl);

}




/*
*****************************************************************
**
** Parameter SupportRS485
**
*****************************************************************
*/ 
  

const CTypeDescriptor
CSupportRS485::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "SupportRS485",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    355,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CSupportRS485::s_apFieldDescriptorTable[] =
{
  
    &s_fdPortNum,
    NULL
};



const CFieldDescriptor
CSupportRS485::s_fdPortNum =
{
    CFieldDescriptor::FT_U8,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "PortNum",	// m_pName
    NULL	// m_pEnumTable
};
CSupportRS485::CSupportRS485 (void)
{
    m_pType = &s_typeDescriptor;
  
    m_PortNum = 0;
}

CSupportRS485::~CSupportRS485 (void)
{
}


CElement *
CSupportRS485::s_construct (void)
{
    return (CElement *) new CSupportRS485();
}


void
CSupportRS485::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CSupportRS485 * pTarget = (CSupportRS485 *) pTargetElement;

  
    if(NULL != pTarget)
    {
        pTarget->m_PortNum = pDecoderStream->get_u8(&s_fdPortNum);
    }
    else
    {
        pDecoderStream->get_u8(&s_fdPortNum);
    }
    
}


void
CSupportRS485::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CSupportRS485::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;

  

    // 1-N of SerialAttribute
    pType = &CSerialAttribute::s_typeDescriptor;
  
    if(Cur == End || (*Cur)->m_pType != pType)
    {
        goto missing;
    }
    while(Cur != End && (*Cur)->m_pType == pType)
    {
        m_listSerialAttribute.push_back((CSerialAttribute *)*Cur);
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
CSupportRS485::addSerialAttribute (
  CSerialAttribute *     pValue)
{
    m_listSerialAttribute.push_back(pValue);
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CSupportRS485::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;

  
    pEncoderStream->put_u8(m_PortNum, &s_fdPortNum);

    pType = &CSerialAttribute::s_typeDescriptor;
      
    pEncoderStream->putRequiredSubParameterList((tListOfParameters *) &m_listSerialAttribute, pType);
      
}




/*
*****************************************************************
**
** Parameter SpecCapabilities
**
*****************************************************************
*/ 
  

const CTypeDescriptor
CSpecCapabilities::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "SpecCapabilities",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    356,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CSpecCapabilities::s_apFieldDescriptorTable[] =
{
  
    &s_fdSupportsClientRequestOpSpec,
    &s_fdSupportsEventAndReportHolding,
    &s_fdClientRequestOpSpecTimeout,
    &s_fdMaxPriorityLevelSupported,
    &s_fdMaxNumSelectSpecs,
    &s_fdMaxNumAntennaSpecsPerSelectSpec,
    &s_fdMaxNumRfSpecsPerAntennaSpec,
    &s_fdMaxNumAccessSpecs,
    &s_fdMaxNumOperationSpecsPerAccessSpec,
    NULL
};



const CFieldDescriptor
CSpecCapabilities::s_fdSupportsClientRequestOpSpec =
{
    CFieldDescriptor::FT_U1,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "SupportsClientRequestOpSpec",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CSpecCapabilities::s_fdSupportsEventAndReportHolding =
{
    CFieldDescriptor::FT_U1,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "SupportsEventAndReportHolding",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CSpecCapabilities::s_fdClientRequestOpSpecTimeout =
{
    CFieldDescriptor::FT_U16,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "ClientRequestOpSpecTimeout",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CSpecCapabilities::s_fdMaxPriorityLevelSupported =
{
    CFieldDescriptor::FT_U8,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "MaxPriorityLevelSupported",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CSpecCapabilities::s_fdMaxNumSelectSpecs =
{
    CFieldDescriptor::FT_U8,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "MaxNumSelectSpecs",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CSpecCapabilities::s_fdMaxNumAntennaSpecsPerSelectSpec =
{
    CFieldDescriptor::FT_U8,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "MaxNumAntennaSpecsPerSelectSpec",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CSpecCapabilities::s_fdMaxNumRfSpecsPerAntennaSpec =
{
    CFieldDescriptor::FT_U8,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "MaxNumRfSpecsPerAntennaSpec",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CSpecCapabilities::s_fdMaxNumAccessSpecs =
{
    CFieldDescriptor::FT_U8,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "MaxNumAccessSpecs",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CSpecCapabilities::s_fdMaxNumOperationSpecsPerAccessSpec =
{
    CFieldDescriptor::FT_U8,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "MaxNumOperationSpecsPerAccessSpec",	// m_pName
    NULL	// m_pEnumTable
};
CSpecCapabilities::CSpecCapabilities (void)
{
    m_pType = &s_typeDescriptor;
  
    m_SupportsClientRequestOpSpec = 0;
    m_SupportsEventAndReportHolding = 0;
    m_ClientRequestOpSpecTimeout = 0;
    m_MaxPriorityLevelSupported = 0;
    m_MaxNumSelectSpecs = 0;
    m_MaxNumAntennaSpecsPerSelectSpec = 0;
    m_MaxNumRfSpecsPerAntennaSpec = 0;
    m_MaxNumAccessSpecs = 0;
    m_MaxNumOperationSpecsPerAccessSpec = 0;
}

CSpecCapabilities::~CSpecCapabilities (void)
{
}


CElement *
CSpecCapabilities::s_construct (void)
{
    return (CElement *) new CSpecCapabilities();
}


void
CSpecCapabilities::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CSpecCapabilities * pTarget = (CSpecCapabilities *) pTargetElement;

  
    if(NULL != pTarget)
    {
        pTarget->m_SupportsClientRequestOpSpec = pDecoderStream->get_u1(&s_fdSupportsClientRequestOpSpec);
    }
    else
    {
        pDecoderStream->get_u1(&s_fdSupportsClientRequestOpSpec);
    }
    
    if(NULL != pTarget)
    {
        pTarget->m_SupportsEventAndReportHolding = pDecoderStream->get_u1(&s_fdSupportsEventAndReportHolding);
    }
    else
    {
        pDecoderStream->get_u1(&s_fdSupportsEventAndReportHolding);
    }
    
    pDecoderStream->get_reserved(6);

    if(NULL != pTarget)
    {
        pTarget->m_ClientRequestOpSpecTimeout = pDecoderStream->get_u16(&s_fdClientRequestOpSpecTimeout);
    }
    else
    {
        pDecoderStream->get_u16(&s_fdClientRequestOpSpecTimeout);
    }
    
    if(NULL != pTarget)
    {
        pTarget->m_MaxPriorityLevelSupported = pDecoderStream->get_u8(&s_fdMaxPriorityLevelSupported);
    }
    else
    {
        pDecoderStream->get_u8(&s_fdMaxPriorityLevelSupported);
    }
    
    if(NULL != pTarget)
    {
        pTarget->m_MaxNumSelectSpecs = pDecoderStream->get_u8(&s_fdMaxNumSelectSpecs);
    }
    else
    {
        pDecoderStream->get_u8(&s_fdMaxNumSelectSpecs);
    }
    
    if(NULL != pTarget)
    {
        pTarget->m_MaxNumAntennaSpecsPerSelectSpec = pDecoderStream->get_u8(&s_fdMaxNumAntennaSpecsPerSelectSpec);
    }
    else
    {
        pDecoderStream->get_u8(&s_fdMaxNumAntennaSpecsPerSelectSpec);
    }
    
    if(NULL != pTarget)
    {
        pTarget->m_MaxNumRfSpecsPerAntennaSpec = pDecoderStream->get_u8(&s_fdMaxNumRfSpecsPerAntennaSpec);
    }
    else
    {
        pDecoderStream->get_u8(&s_fdMaxNumRfSpecsPerAntennaSpec);
    }
    
    if(NULL != pTarget)
    {
        pTarget->m_MaxNumAccessSpecs = pDecoderStream->get_u8(&s_fdMaxNumAccessSpecs);
    }
    else
    {
        pDecoderStream->get_u8(&s_fdMaxNumAccessSpecs);
    }
    
    if(NULL != pTarget)
    {
        pTarget->m_MaxNumOperationSpecsPerAccessSpec = pDecoderStream->get_u8(&s_fdMaxNumOperationSpecsPerAccessSpec);
    }
    else
    {
        pDecoderStream->get_u8(&s_fdMaxNumOperationSpecsPerAccessSpec);
    }
    
}


void
CSpecCapabilities::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CSpecCapabilities::assimilateSubParameters (
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
CSpecCapabilities::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;

  
    pEncoderStream->put_u1(m_SupportsClientRequestOpSpec, &s_fdSupportsClientRequestOpSpec);

    pEncoderStream->put_u1(m_SupportsEventAndReportHolding, &s_fdSupportsEventAndReportHolding);

    pEncoderStream->put_reserved(6);

    pEncoderStream->put_u16(m_ClientRequestOpSpecTimeout, &s_fdClientRequestOpSpecTimeout);

    pEncoderStream->put_u8(m_MaxPriorityLevelSupported, &s_fdMaxPriorityLevelSupported);

    pEncoderStream->put_u8(m_MaxNumSelectSpecs, &s_fdMaxNumSelectSpecs);

    pEncoderStream->put_u8(m_MaxNumAntennaSpecsPerSelectSpec, &s_fdMaxNumAntennaSpecsPerSelectSpec);

    pEncoderStream->put_u8(m_MaxNumRfSpecsPerAntennaSpec, &s_fdMaxNumRfSpecsPerAntennaSpec);

    pEncoderStream->put_u8(m_MaxNumAccessSpecs, &s_fdMaxNumAccessSpecs);

    pEncoderStream->put_u8(m_MaxNumOperationSpecsPerAccessSpec, &s_fdMaxNumOperationSpecsPerAccessSpec);

}




/*
*****************************************************************
**
** Parameter RfCapabilities
**
*****************************************************************
*/ 
  

const CTypeDescriptor
CRfCapabilities::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "RfCapabilities",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    357,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CRfCapabilities::s_apFieldDescriptorTable[] =
{
  
    &s_fdCountryCode,
    &s_fdCommunicationsStandard,
    NULL
};



const CFieldDescriptor
CRfCapabilities::s_fdCountryCode =
{
    CFieldDescriptor::FT_U16,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "CountryCode",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CRfCapabilities::s_fdCommunicationsStandard =
{
    CFieldDescriptor::FT_U16,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "CommunicationsStandard",	// m_pName
    NULL	// m_pEnumTable
};
CRfCapabilities::CRfCapabilities (void)
{
    m_pType = &s_typeDescriptor;
  
    m_CountryCode = 0;
    m_CommunicationsStandard = 0;
    m_pFrequencyInformation = NULL;
}

CRfCapabilities::~CRfCapabilities (void)
{
}


CElement *
CRfCapabilities::s_construct (void)
{
    return (CElement *) new CRfCapabilities();
}


void
CRfCapabilities::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CRfCapabilities * pTarget = (CRfCapabilities *) pTargetElement;

  
    if(NULL != pTarget)
    {
        pTarget->m_CountryCode = pDecoderStream->get_u16(&s_fdCountryCode);
    }
    else
    {
        pDecoderStream->get_u16(&s_fdCountryCode);
    }
    
    if(NULL != pTarget)
    {
        pTarget->m_CommunicationsStandard = pDecoderStream->get_u16(&s_fdCommunicationsStandard);
    }
    else
    {
        pDecoderStream->get_u16(&s_fdCommunicationsStandard);
    }
    
}


void
CRfCapabilities::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CRfCapabilities::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;

  

    // 1-N of TransmitPowerLevelTable
    pType = &CTransmitPowerLevelTable::s_typeDescriptor;
  
    if(Cur == End || (*Cur)->m_pType != pType)
    {
        goto missing;
    }
    while(Cur != End && (*Cur)->m_pType == pType)
    {
        m_listTransmitPowerLevelTable.push_back((CTransmitPowerLevelTable *)*Cur);
        Cur++;
    }
    

    // 1 of FrequencyInformation
    pType = &CFrequencyInformation::s_typeDescriptor;
  
    if(Cur == End || (*Cur)->m_pType != pType)
    {
        goto missing;
    }
    m_pFrequencyInformation = (CFrequencyInformation *)*Cur++;
    

    // 1-N of ForDataRateTable
    pType = &CForDataRateTable::s_typeDescriptor;
  
    if(Cur == End || (*Cur)->m_pType != pType)
    {
        goto missing;
    }
    while(Cur != End && (*Cur)->m_pType == pType)
    {
        m_listForDataRateTable.push_back((CForDataRateTable *)*Cur);
        Cur++;
    }
    

    // 1-N of RevDataRateTable
    pType = &CRevDataRateTable::s_typeDescriptor;
  
    if(Cur == End || (*Cur)->m_pType != pType)
    {
        goto missing;
    }
    while(Cur != End && (*Cur)->m_pType == pType)
    {
        m_listRevDataRateTable.push_back((CRevDataRateTable *)*Cur);
        Cur++;
    }
    

    // 1-N of ForModulationTable
    pType = &CForModulationTable::s_typeDescriptor;
  
    if(Cur == End || (*Cur)->m_pType != pType)
    {
        goto missing;
    }
    while(Cur != End && (*Cur)->m_pType == pType)
    {
        m_listForModulationTable.push_back((CForModulationTable *)*Cur);
        Cur++;
    }
    

    // 1-N of RevDataEncodingTable
    pType = &CRevDataEncodingTable::s_typeDescriptor;
  
    if(Cur == End || (*Cur)->m_pType != pType)
    {
        goto missing;
    }
    while(Cur != End && (*Cur)->m_pType == pType)
    {
        m_listRevDataEncodingTable.push_back((CRevDataEncodingTable *)*Cur);
        Cur++;
    }
    

    // 1-N of ModuleDepthTable
    pType = &CModuleDepthTable::s_typeDescriptor;
  
    if(Cur == End || (*Cur)->m_pType != pType)
    {
        goto missing;
    }
    while(Cur != End && (*Cur)->m_pType == pType)
    {
        m_listModuleDepthTable.push_back((CModuleDepthTable *)*Cur);
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
CRfCapabilities::addTransmitPowerLevelTable (
  CTransmitPowerLevelTable *     pValue)
{
    m_listTransmitPowerLevelTable.push_back(pValue);
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CRfCapabilities::setFrequencyInformation (
  CFrequencyInformation *     pValue)
{
    removeSubParameterFromAllList(m_pFrequencyInformation);
    delete m_pFrequencyInformation;
    m_pFrequencyInformation = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CRfCapabilities::addForDataRateTable (
  CForDataRateTable *     pValue)
{
    m_listForDataRateTable.push_back(pValue);
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CRfCapabilities::addRevDataRateTable (
  CRevDataRateTable *     pValue)
{
    m_listRevDataRateTable.push_back(pValue);
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CRfCapabilities::addForModulationTable (
  CForModulationTable *     pValue)
{
    m_listForModulationTable.push_back(pValue);
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CRfCapabilities::addRevDataEncodingTable (
  CRevDataEncodingTable *     pValue)
{
    m_listRevDataEncodingTable.push_back(pValue);
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CRfCapabilities::addModuleDepthTable (
  CModuleDepthTable *     pValue)
{
    m_listModuleDepthTable.push_back(pValue);
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CRfCapabilities::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;

  
    pEncoderStream->put_u16(m_CountryCode, &s_fdCountryCode);

    pEncoderStream->put_u16(m_CommunicationsStandard, &s_fdCommunicationsStandard);

    pType = &CTransmitPowerLevelTable::s_typeDescriptor;
      
    pEncoderStream->putRequiredSubParameterList((tListOfParameters *) &m_listTransmitPowerLevelTable, pType);
      
    pType = &CFrequencyInformation::s_typeDescriptor;
      
    pEncoderStream->putRequiredSubParameter(m_pFrequencyInformation, pType);
      
    pType = &CForDataRateTable::s_typeDescriptor;
      
    pEncoderStream->putRequiredSubParameterList((tListOfParameters *) &m_listForDataRateTable, pType);
      
    pType = &CRevDataRateTable::s_typeDescriptor;
      
    pEncoderStream->putRequiredSubParameterList((tListOfParameters *) &m_listRevDataRateTable, pType);
      
    pType = &CForModulationTable::s_typeDescriptor;
      
    pEncoderStream->putRequiredSubParameterList((tListOfParameters *) &m_listForModulationTable, pType);
      
    pType = &CRevDataEncodingTable::s_typeDescriptor;
      
    pEncoderStream->putRequiredSubParameterList((tListOfParameters *) &m_listRevDataEncodingTable, pType);
      
    pType = &CModuleDepthTable::s_typeDescriptor;
      
    pEncoderStream->putRequiredSubParameterList((tListOfParameters *) &m_listModuleDepthTable, pType);
      
}




/*
*****************************************************************
**
** Parameter TransmitPowerLevelTable
**
*****************************************************************
*/ 
  

const CTypeDescriptor
CTransmitPowerLevelTable::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "TransmitPowerLevelTable",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    358,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CTransmitPowerLevelTable::s_apFieldDescriptorTable[] =
{
  
    &s_fdIndex,
    &s_fdTransmitPowerValue,
    NULL
};



const CFieldDescriptor
CTransmitPowerLevelTable::s_fdIndex =
{
    CFieldDescriptor::FT_U16,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "Index",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CTransmitPowerLevelTable::s_fdTransmitPowerValue =
{
    CFieldDescriptor::FT_S16,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "TransmitPowerValue",	// m_pName
    NULL	// m_pEnumTable
};
CTransmitPowerLevelTable::CTransmitPowerLevelTable (void)
{
    m_pType = &s_typeDescriptor;
  
    m_Index = 0;
    m_TransmitPowerValue = 0;
}

CTransmitPowerLevelTable::~CTransmitPowerLevelTable (void)
{
}


CElement *
CTransmitPowerLevelTable::s_construct (void)
{
    return (CElement *) new CTransmitPowerLevelTable();
}


void
CTransmitPowerLevelTable::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CTransmitPowerLevelTable * pTarget = (CTransmitPowerLevelTable *) pTargetElement;

  
    if(NULL != pTarget)
    {
        pTarget->m_Index = pDecoderStream->get_u16(&s_fdIndex);
    }
    else
    {
        pDecoderStream->get_u16(&s_fdIndex);
    }
    
    if(NULL != pTarget)
    {
        pTarget->m_TransmitPowerValue = pDecoderStream->get_s16(&s_fdTransmitPowerValue);
    }
    else
    {
        pDecoderStream->get_s16(&s_fdTransmitPowerValue);
    }
    
}


void
CTransmitPowerLevelTable::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CTransmitPowerLevelTable::assimilateSubParameters (
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
CTransmitPowerLevelTable::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;

  
    pEncoderStream->put_u16(m_Index, &s_fdIndex);

    pEncoderStream->put_s16(m_TransmitPowerValue, &s_fdTransmitPowerValue);

}




/*
*****************************************************************
**
** Parameter FrequencyInformation
**
*****************************************************************
*/ 
  

const CTypeDescriptor
CFrequencyInformation::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "FrequencyInformation",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    359,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CFrequencyInformation::s_apFieldDescriptorTable[] =
{
  
    &s_fdHopping,
    NULL
};



const CFieldDescriptor
CFrequencyInformation::s_fdHopping =
{
    CFieldDescriptor::FT_U1,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "Hopping",	// m_pName
    NULL	// m_pEnumTable
};
CFrequencyInformation::CFrequencyInformation (void)
{
    m_pType = &s_typeDescriptor;
  
    m_Hopping = 0;
}

CFrequencyInformation::~CFrequencyInformation (void)
{
}


CElement *
CFrequencyInformation::s_construct (void)
{
    return (CElement *) new CFrequencyInformation();
}


void
CFrequencyInformation::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CFrequencyInformation * pTarget = (CFrequencyInformation *) pTargetElement;

  
    if(NULL != pTarget)
    {
        pTarget->m_Hopping = pDecoderStream->get_u1(&s_fdHopping);
    }
    else
    {
        pDecoderStream->get_u1(&s_fdHopping);
    }
    
    pDecoderStream->get_reserved(7);

}


void
CFrequencyInformation::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CFrequencyInformation::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;

  

    // 1-N of FrequencyTable
    pType = &CFrequencyTable::s_typeDescriptor;
  
    if(Cur == End || (*Cur)->m_pType != pType)
    {
        goto missing;
    }
    while(Cur != End && (*Cur)->m_pType == pType)
    {
        m_listFrequencyTable.push_back((CFrequencyTable *)*Cur);
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
CFrequencyInformation::addFrequencyTable (
  CFrequencyTable *     pValue)
{
    m_listFrequencyTable.push_back(pValue);
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CFrequencyInformation::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;

  
    pEncoderStream->put_u1(m_Hopping, &s_fdHopping);

    pEncoderStream->put_reserved(7);

    pType = &CFrequencyTable::s_typeDescriptor;
      
    pEncoderStream->putRequiredSubParameterList((tListOfParameters *) &m_listFrequencyTable, pType);
      
}




/*
*****************************************************************
**
** Parameter FrequencyTable
**
*****************************************************************
*/ 
  

const CTypeDescriptor
CFrequencyTable::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "FrequencyTable",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    360,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CFrequencyTable::s_apFieldDescriptorTable[] =
{
  
    &s_fdIndex,
    &s_fdFrequency,
    NULL
};



const CFieldDescriptor
CFrequencyTable::s_fdIndex =
{
    CFieldDescriptor::FT_U16,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "Index",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CFrequencyTable::s_fdFrequency =
{
    CFieldDescriptor::FT_U32,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "Frequency",	// m_pName
    NULL	// m_pEnumTable
};
CFrequencyTable::CFrequencyTable (void)
{
    m_pType = &s_typeDescriptor;
  
    m_Index = 0;
    m_Frequency = 0;
}

CFrequencyTable::~CFrequencyTable (void)
{
}


CElement *
CFrequencyTable::s_construct (void)
{
    return (CElement *) new CFrequencyTable();
}


void
CFrequencyTable::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CFrequencyTable * pTarget = (CFrequencyTable *) pTargetElement;

  
    if(NULL != pTarget)
    {
        pTarget->m_Index = pDecoderStream->get_u16(&s_fdIndex);
    }
    else
    {
        pDecoderStream->get_u16(&s_fdIndex);
    }
    
    if(NULL != pTarget)
    {
        pTarget->m_Frequency = pDecoderStream->get_u32(&s_fdFrequency);
    }
    else
    {
        pDecoderStream->get_u32(&s_fdFrequency);
    }
    
}


void
CFrequencyTable::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CFrequencyTable::assimilateSubParameters (
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
CFrequencyTable::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;

  
    pEncoderStream->put_u16(m_Index, &s_fdIndex);

    pEncoderStream->put_u32(m_Frequency, &s_fdFrequency);

}




/*
*****************************************************************
**
** Parameter ForDataRateTable
**
*****************************************************************
*/ 
  

const CTypeDescriptor
CForDataRateTable::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "ForDataRateTable",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    361,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CForDataRateTable::s_apFieldDescriptorTable[] =
{
  
    &s_fdIndex,
    &s_fdForDataRate,
    NULL
};



const CFieldDescriptor
CForDataRateTable::s_fdIndex =
{
    CFieldDescriptor::FT_U16,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "Index",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CForDataRateTable::s_fdForDataRate =
{
    CFieldDescriptor::FT_U32,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "ForDataRate",	// m_pName
    NULL	// m_pEnumTable
};
CForDataRateTable::CForDataRateTable (void)
{
    m_pType = &s_typeDescriptor;
  
    m_Index = 0;
    m_ForDataRate = 0;
}

CForDataRateTable::~CForDataRateTable (void)
{
}


CElement *
CForDataRateTable::s_construct (void)
{
    return (CElement *) new CForDataRateTable();
}


void
CForDataRateTable::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CForDataRateTable * pTarget = (CForDataRateTable *) pTargetElement;

  
    if(NULL != pTarget)
    {
        pTarget->m_Index = pDecoderStream->get_u16(&s_fdIndex);
    }
    else
    {
        pDecoderStream->get_u16(&s_fdIndex);
    }
    
    if(NULL != pTarget)
    {
        pTarget->m_ForDataRate = pDecoderStream->get_u32(&s_fdForDataRate);
    }
    else
    {
        pDecoderStream->get_u32(&s_fdForDataRate);
    }
    
}


void
CForDataRateTable::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CForDataRateTable::assimilateSubParameters (
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
CForDataRateTable::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;

  
    pEncoderStream->put_u16(m_Index, &s_fdIndex);

    pEncoderStream->put_u32(m_ForDataRate, &s_fdForDataRate);

}




/*
*****************************************************************
**
** Parameter RevDataRateTable
**
*****************************************************************
*/ 
  

const CTypeDescriptor
CRevDataRateTable::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "RevDataRateTable",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    362,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CRevDataRateTable::s_apFieldDescriptorTable[] =
{
  
    &s_fdIndex,
    &s_fdRevDataRate,
    NULL
};



const CFieldDescriptor
CRevDataRateTable::s_fdIndex =
{
    CFieldDescriptor::FT_U16,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "Index",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CRevDataRateTable::s_fdRevDataRate =
{
    CFieldDescriptor::FT_U32,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "RevDataRate",	// m_pName
    NULL	// m_pEnumTable
};
CRevDataRateTable::CRevDataRateTable (void)
{
    m_pType = &s_typeDescriptor;
  
    m_Index = 0;
    m_RevDataRate = 0;
}

CRevDataRateTable::~CRevDataRateTable (void)
{
}


CElement *
CRevDataRateTable::s_construct (void)
{
    return (CElement *) new CRevDataRateTable();
}


void
CRevDataRateTable::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CRevDataRateTable * pTarget = (CRevDataRateTable *) pTargetElement;

  
    if(NULL != pTarget)
    {
        pTarget->m_Index = pDecoderStream->get_u16(&s_fdIndex);
    }
    else
    {
        pDecoderStream->get_u16(&s_fdIndex);
    }
    
    if(NULL != pTarget)
    {
        pTarget->m_RevDataRate = pDecoderStream->get_u32(&s_fdRevDataRate);
    }
    else
    {
        pDecoderStream->get_u32(&s_fdRevDataRate);
    }
    
}


void
CRevDataRateTable::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CRevDataRateTable::assimilateSubParameters (
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
CRevDataRateTable::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;

  
    pEncoderStream->put_u16(m_Index, &s_fdIndex);

    pEncoderStream->put_u32(m_RevDataRate, &s_fdRevDataRate);

}




/*
*****************************************************************
**
** Parameter ForModulationTable
**
*****************************************************************
*/ 
  

const CTypeDescriptor
CForModulationTable::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "ForModulationTable",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    363,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CForModulationTable::s_apFieldDescriptorTable[] =
{
  
    &s_fdIndex,
    &s_fdModulationType,
    NULL
};



const CFieldDescriptor
CForModulationTable::s_fdIndex =
{
    CFieldDescriptor::FT_U16,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "Index",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CForModulationTable::s_fdModulationType =
{
    CFieldDescriptor::FT_U8,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "ModulationType",	// m_pName
    NULL	// m_pEnumTable
};
CForModulationTable::CForModulationTable (void)
{
    m_pType = &s_typeDescriptor;
  
    m_Index = 0;
    m_ModulationType = 0;
}

CForModulationTable::~CForModulationTable (void)
{
}


CElement *
CForModulationTable::s_construct (void)
{
    return (CElement *) new CForModulationTable();
}


void
CForModulationTable::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CForModulationTable * pTarget = (CForModulationTable *) pTargetElement;

  
    if(NULL != pTarget)
    {
        pTarget->m_Index = pDecoderStream->get_u16(&s_fdIndex);
    }
    else
    {
        pDecoderStream->get_u16(&s_fdIndex);
    }
    
    if(NULL != pTarget)
    {
        pTarget->m_ModulationType = pDecoderStream->get_u8(&s_fdModulationType);
    }
    else
    {
        pDecoderStream->get_u8(&s_fdModulationType);
    }
    
}


void
CForModulationTable::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CForModulationTable::assimilateSubParameters (
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
CForModulationTable::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;

  
    pEncoderStream->put_u16(m_Index, &s_fdIndex);

    pEncoderStream->put_u8(m_ModulationType, &s_fdModulationType);

}




/*
*****************************************************************
**
** Parameter RevDataEncodingTable
**
*****************************************************************
*/ 
  

const CTypeDescriptor
CRevDataEncodingTable::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "RevDataEncodingTable",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    364,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CRevDataEncodingTable::s_apFieldDescriptorTable[] =
{
  
    &s_fdIndex,
    &s_fdDataEncodingType,
    NULL
};



const CFieldDescriptor
CRevDataEncodingTable::s_fdIndex =
{
    CFieldDescriptor::FT_U16,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "Index",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CRevDataEncodingTable::s_fdDataEncodingType =
{
    CFieldDescriptor::FT_U8,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "DataEncodingType",	// m_pName
    NULL	// m_pEnumTable
};
CRevDataEncodingTable::CRevDataEncodingTable (void)
{
    m_pType = &s_typeDescriptor;
  
    m_Index = 0;
    m_DataEncodingType = 0;
}

CRevDataEncodingTable::~CRevDataEncodingTable (void)
{
}


CElement *
CRevDataEncodingTable::s_construct (void)
{
    return (CElement *) new CRevDataEncodingTable();
}


void
CRevDataEncodingTable::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CRevDataEncodingTable * pTarget = (CRevDataEncodingTable *) pTargetElement;

  
    if(NULL != pTarget)
    {
        pTarget->m_Index = pDecoderStream->get_u16(&s_fdIndex);
    }
    else
    {
        pDecoderStream->get_u16(&s_fdIndex);
    }
    
    if(NULL != pTarget)
    {
        pTarget->m_DataEncodingType = pDecoderStream->get_u8(&s_fdDataEncodingType);
    }
    else
    {
        pDecoderStream->get_u8(&s_fdDataEncodingType);
    }
    
}


void
CRevDataEncodingTable::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CRevDataEncodingTable::assimilateSubParameters (
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
CRevDataEncodingTable::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;

  
    pEncoderStream->put_u16(m_Index, &s_fdIndex);

    pEncoderStream->put_u8(m_DataEncodingType, &s_fdDataEncodingType);

}




/*
*****************************************************************
**
** Parameter ModuleDepthTable
**
*****************************************************************
*/ 
  

const CTypeDescriptor
CModuleDepthTable::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "ModuleDepthTable",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    365,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CModuleDepthTable::s_apFieldDescriptorTable[] =
{
  
    &s_fdIndex,
    &s_fdModuleDepthValue,
    NULL
};



const CFieldDescriptor
CModuleDepthTable::s_fdIndex =
{
    CFieldDescriptor::FT_U16,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "Index",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CModuleDepthTable::s_fdModuleDepthValue =
{
    CFieldDescriptor::FT_U16,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "ModuleDepthValue",	// m_pName
    NULL	// m_pEnumTable
};
CModuleDepthTable::CModuleDepthTable (void)
{
    m_pType = &s_typeDescriptor;
  
    m_Index = 0;
    m_ModuleDepthValue = 0;
}

CModuleDepthTable::~CModuleDepthTable (void)
{
}


CElement *
CModuleDepthTable::s_construct (void)
{
    return (CElement *) new CModuleDepthTable();
}


void
CModuleDepthTable::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CModuleDepthTable * pTarget = (CModuleDepthTable *) pTargetElement;

  
    if(NULL != pTarget)
    {
        pTarget->m_Index = pDecoderStream->get_u16(&s_fdIndex);
    }
    else
    {
        pDecoderStream->get_u16(&s_fdIndex);
    }
    
    if(NULL != pTarget)
    {
        pTarget->m_ModuleDepthValue = pDecoderStream->get_u16(&s_fdModuleDepthValue);
    }
    else
    {
        pDecoderStream->get_u16(&s_fdModuleDepthValue);
    }
    
}


void
CModuleDepthTable::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CModuleDepthTable::assimilateSubParameters (
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
CModuleDepthTable::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;

  
    pEncoderStream->put_u16(m_Index, &s_fdIndex);

    pEncoderStream->put_u16(m_ModuleDepthValue, &s_fdModuleDepthValue);

}




/*
*****************************************************************
**
** Parameter AirProtocolCapabilities
**
*****************************************************************
*/ 
  

const CTypeDescriptor
CAirProtocolCapabilities::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "AirProtocolCapabilities",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    366,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CAirProtocolCapabilities::s_apFieldDescriptorTable[] =
{
  
    NULL
};

CAirProtocolCapabilities::CAirProtocolCapabilities (void)
{
    m_pType = &s_typeDescriptor;
  
}

CAirProtocolCapabilities::~CAirProtocolCapabilities (void)
{
}


CElement *
CAirProtocolCapabilities::s_construct (void)
{
    return (CElement *) new CAirProtocolCapabilities();
}


void
CAirProtocolCapabilities::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CAirProtocolCapabilities * pTarget = (CAirProtocolCapabilities *) pTargetElement;

  
}


void
CAirProtocolCapabilities::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CAirProtocolCapabilities::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;

  

    // 0-N of PerAntennaAirProtocol
    pType = &CPerAntennaAirProtocol::s_typeDescriptor;
  
    while(Cur != End && (*Cur)->m_pType == pType)
    {
        m_listPerAntennaAirProtocol.push_back((CPerAntennaAirProtocol *)*Cur);
        Cur++;
    }
    

    // 0-N of HbProtocolCapabilities
    pType = &CHbProtocolCapabilities::s_typeDescriptor;
  
    while(Cur != End && (*Cur)->m_pType == pType)
    {
        m_listHbProtocolCapabilities.push_back((CHbProtocolCapabilities *)*Cur);
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
CAirProtocolCapabilities::addPerAntennaAirProtocol (
  CPerAntennaAirProtocol *     pValue)
{
    m_listPerAntennaAirProtocol.push_back(pValue);
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CAirProtocolCapabilities::addHbProtocolCapabilities (
  CHbProtocolCapabilities *     pValue)
{
    m_listHbProtocolCapabilities.push_back(pValue);
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CAirProtocolCapabilities::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;

  
    pType = &CPerAntennaAirProtocol::s_typeDescriptor;
      
    pEncoderStream->putOptionalSubParameterList((tListOfParameters *) &m_listPerAntennaAirProtocol, pType);
      
    pType = &CHbProtocolCapabilities::s_typeDescriptor;
      
    pEncoderStream->putOptionalSubParameterList((tListOfParameters *) &m_listHbProtocolCapabilities, pType);
      
}




/*
*****************************************************************
**
** Parameter PerAntennaAirProtocol
**
*****************************************************************
*/ 
  

const CTypeDescriptor
CPerAntennaAirProtocol::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "PerAntennaAirProtocol",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    367,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CPerAntennaAirProtocol::s_apFieldDescriptorTable[] =
{
  
    &s_fdAntennaID,
    &s_fdProtocolIDs,
    NULL
};



const CFieldDescriptor
CPerAntennaAirProtocol::s_fdAntennaID =
{
    CFieldDescriptor::FT_U8,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "AntennaID",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CPerAntennaAirProtocol::s_fdProtocolIDs =
{
    CFieldDescriptor::FT_U8V,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "ProtocolIDs",	// m_pName
    NULL	// m_pEnumTable
};
CPerAntennaAirProtocol::CPerAntennaAirProtocol (void)
{
    m_pType = &s_typeDescriptor;
  
    m_AntennaID = 0;
}

CPerAntennaAirProtocol::~CPerAntennaAirProtocol (void)
{
}


CElement *
CPerAntennaAirProtocol::s_construct (void)
{
    return (CElement *) new CPerAntennaAirProtocol();
}


void
CPerAntennaAirProtocol::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CPerAntennaAirProtocol * pTarget = (CPerAntennaAirProtocol *) pTargetElement;

  
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
        pTarget->m_ProtocolIDs = pDecoderStream->get_u8v(&s_fdProtocolIDs);
    }
    else
    {
        pDecoderStream->get_u8v(&s_fdProtocolIDs);
    }
    
}


void
CPerAntennaAirProtocol::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CPerAntennaAirProtocol::assimilateSubParameters (
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
CPerAntennaAirProtocol::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;

  
    pEncoderStream->put_u8(m_AntennaID, &s_fdAntennaID);

    pEncoderStream->put_u8v(m_ProtocolIDs, &s_fdProtocolIDs);

}




/*
*****************************************************************
**
** Parameter HbProtocolCapabilities
**
*****************************************************************
*/ 
  

const CTypeDescriptor
CHbProtocolCapabilities::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "HbProtocolCapabilities",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    368,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CHbProtocolCapabilities::s_apFieldDescriptorTable[] =
{
  
    &s_fdSupportQuery,
    &s_fdSupportReadData,
    &s_fdSupportWriteData,
    &s_fdSupportWriteKey,
    NULL
};



const CFieldDescriptor
CHbProtocolCapabilities::s_fdSupportQuery =
{
    CFieldDescriptor::FT_U1,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "SupportQuery",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CHbProtocolCapabilities::s_fdSupportReadData =
{
    CFieldDescriptor::FT_U1,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "SupportReadData",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CHbProtocolCapabilities::s_fdSupportWriteData =
{
    CFieldDescriptor::FT_U1,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "SupportWriteData",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CHbProtocolCapabilities::s_fdSupportWriteKey =
{
    CFieldDescriptor::FT_U1,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "SupportWriteKey",	// m_pName
    NULL	// m_pEnumTable
};
CHbProtocolCapabilities::CHbProtocolCapabilities (void)
{
    m_pType = &s_typeDescriptor;
  
    m_SupportQuery = 0;
    m_SupportReadData = 0;
    m_SupportWriteData = 0;
    m_SupportWriteKey = 0;
}

CHbProtocolCapabilities::~CHbProtocolCapabilities (void)
{
}


CElement *
CHbProtocolCapabilities::s_construct (void)
{
    return (CElement *) new CHbProtocolCapabilities();
}


void
CHbProtocolCapabilities::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CHbProtocolCapabilities * pTarget = (CHbProtocolCapabilities *) pTargetElement;

  
    if(NULL != pTarget)
    {
        pTarget->m_SupportQuery = pDecoderStream->get_u1(&s_fdSupportQuery);
    }
    else
    {
        pDecoderStream->get_u1(&s_fdSupportQuery);
    }
    
    if(NULL != pTarget)
    {
        pTarget->m_SupportReadData = pDecoderStream->get_u1(&s_fdSupportReadData);
    }
    else
    {
        pDecoderStream->get_u1(&s_fdSupportReadData);
    }
    
    if(NULL != pTarget)
    {
        pTarget->m_SupportWriteData = pDecoderStream->get_u1(&s_fdSupportWriteData);
    }
    else
    {
        pDecoderStream->get_u1(&s_fdSupportWriteData);
    }
    
    if(NULL != pTarget)
    {
        pTarget->m_SupportWriteKey = pDecoderStream->get_u1(&s_fdSupportWriteKey);
    }
    else
    {
        pDecoderStream->get_u1(&s_fdSupportWriteKey);
    }
    
    pDecoderStream->get_reserved(4);

}


void
CHbProtocolCapabilities::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CHbProtocolCapabilities::assimilateSubParameters (
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
CHbProtocolCapabilities::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;

  
    pEncoderStream->put_u1(m_SupportQuery, &s_fdSupportQuery);

    pEncoderStream->put_u1(m_SupportReadData, &s_fdSupportReadData);

    pEncoderStream->put_u1(m_SupportWriteData, &s_fdSupportWriteData);

    pEncoderStream->put_u1(m_SupportWriteKey, &s_fdSupportWriteKey);

    pEncoderStream->put_reserved(4);

}





/*
void
enrollCoreTypesIntoRegistry (
  CTypeRegistry *               pTypeRegistry)
{
  
    pTypeRegistry->enroll(&CGetDeviceCapabilities::s_typeDescriptor);
  
    pTypeRegistry->enroll(&CGetDeviceCapabilitiesAck::s_typeDescriptor);
  
    pTypeRegistry->enroll(&CGenaralCapabilities::s_typeDescriptor);
  
    pTypeRegistry->enroll(&CGPIOCapabilities::s_typeDescriptor);
  
    pTypeRegistry->enroll(&CCommunicationCapabilities::s_typeDescriptor);
  
    pTypeRegistry->enroll(&CSupportRS232::s_typeDescriptor);
  
    pTypeRegistry->enroll(&CSerialAttribute::s_typeDescriptor);
  
    pTypeRegistry->enroll(&CSupportRS485::s_typeDescriptor);
  
    pTypeRegistry->enroll(&CSpecCapabilities::s_typeDescriptor);
  
    pTypeRegistry->enroll(&CRfCapabilities::s_typeDescriptor);
  
    pTypeRegistry->enroll(&CTransmitPowerLevelTable::s_typeDescriptor);
  
    pTypeRegistry->enroll(&CFrequencyInformation::s_typeDescriptor);
  
    pTypeRegistry->enroll(&CFrequencyTable::s_typeDescriptor);
  
    pTypeRegistry->enroll(&CForDataRateTable::s_typeDescriptor);
  
    pTypeRegistry->enroll(&CRevDataRateTable::s_typeDescriptor);
  
    pTypeRegistry->enroll(&CForModulationTable::s_typeDescriptor);
  
    pTypeRegistry->enroll(&CRevDataEncodingTable::s_typeDescriptor);
  
    pTypeRegistry->enroll(&CModuleDepthTable::s_typeDescriptor);
  
    pTypeRegistry->enroll(&CAirProtocolCapabilities::s_typeDescriptor);
  
    pTypeRegistry->enroll(&CPerAntennaAirProtocol::s_typeDescriptor);
  
    pTypeRegistry->enroll(&CHbProtocolCapabilities::s_typeDescriptor);
  
    pTypeRegistry->enroll(&CSecurityModuleCapabilities::s_typeDescriptor);
  
}
*/

}; //end of namespace LLRP
