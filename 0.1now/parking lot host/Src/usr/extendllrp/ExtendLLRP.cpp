#include "ExtendLLRP.h"
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

  


/*
*****************************************************************
**
** Message ManufacturerCommand
**
*****************************************************************
*/ 
  

const CTypeDescriptor
CManufacturerCommand::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "ManufacturerCommand",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    1000,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CManufacturerCommand::s_apFieldDescriptorTable[] =
{
  
    &s_fdByteStream,
    NULL
};



const CFieldDescriptor
CManufacturerCommand::s_fdByteStream =
{
    CFieldDescriptor::FT_U8V,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "ByteStream",	// m_pName
    NULL	// m_pEnumTable
};
CManufacturerCommand::CManufacturerCommand (void)
{
    m_pType = &s_typeDescriptor;
  
}

CManufacturerCommand::~CManufacturerCommand (void)
{
}


CElement *
CManufacturerCommand::s_construct (void)
{
    return (CElement *) new CManufacturerCommand();
}


void
CManufacturerCommand::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CManufacturerCommand * pTarget = (CManufacturerCommand *) pTargetElement;

  
    if(NULL != pTarget)
    {
        pTarget->m_ByteStream = pDecoderStream->get_u8v(&s_fdByteStream);
    }
    else
    {
        pDecoderStream->get_u8v(&s_fdByteStream);
    }
    
}


void
CManufacturerCommand::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CManufacturerCommand::assimilateSubParameters (
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
CManufacturerCommand::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;

  
    pEncoderStream->put_u8v(m_ByteStream, &s_fdByteStream);

}




/*
*****************************************************************
**
** Message ManufacturerCommandAck
**
*****************************************************************
*/ 
  

const CTypeDescriptor
CManufacturerCommandAck::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "ManufacturerCommandAck",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    1001,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CManufacturerCommandAck::s_apFieldDescriptorTable[] =
{
  
    NULL
};

CManufacturerCommandAck::CManufacturerCommandAck (void)
{
    m_pType = &s_typeDescriptor;
  
    m_pStatus = NULL;
}

CManufacturerCommandAck::~CManufacturerCommandAck (void)
{
}


CElement *
CManufacturerCommandAck::s_construct (void)
{
    return (CElement *) new CManufacturerCommandAck();
}


void
CManufacturerCommandAck::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CManufacturerCommandAck * pTarget = (CManufacturerCommandAck *) pTargetElement;

  
}


void
CManufacturerCommandAck::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CManufacturerCommandAck::assimilateSubParameters (
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
CManufacturerCommandAck::setStatus (
  CStatus *     pValue)
{
    removeSubParameterFromAllList(m_pStatus);
    delete m_pStatus;
    m_pStatus = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CManufacturerCommandAck::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;

  
    pType = &CStatus::s_typeDescriptor;
      
    pEncoderStream->putRequiredSubParameter(m_pStatus, pType);
      
}




/*
*****************************************************************
**
** Message ManufacturerReport
**
*****************************************************************
*/ 
  

const CTypeDescriptor
CManufacturerReport::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "ManufacturerReport",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    1002,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CManufacturerReport::s_apFieldDescriptorTable[] =
{
  
    &s_fdByteStream,
    NULL
};



const CFieldDescriptor
CManufacturerReport::s_fdByteStream =
{
    CFieldDescriptor::FT_U8V,	// m_eFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_eFieldFormat
    "ByteStream",	// m_pName
    NULL	// m_pEnumTable
};
CManufacturerReport::CManufacturerReport (void)
{
    m_pType = &s_typeDescriptor;
  
}

CManufacturerReport::~CManufacturerReport (void)
{
}


CElement *
CManufacturerReport::s_construct (void)
{
    return (CElement *) new CManufacturerReport();
}


void
CManufacturerReport::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CManufacturerReport * pTarget = (CManufacturerReport *) pTargetElement;

  
    if(NULL != pTarget)
    {
        pTarget->m_ByteStream = pDecoderStream->get_u8v(&s_fdByteStream);
    }
    else
    {
        pDecoderStream->get_u8v(&s_fdByteStream);
    }
    
}


void
CManufacturerReport::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CManufacturerReport::assimilateSubParameters (
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
CManufacturerReport::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;

  
    pEncoderStream->put_u8v(m_ByteStream, &s_fdByteStream);

}




/*
*****************************************************************
**
** Message ManufacturerReportAck
**
*****************************************************************
*/ 
  

const CTypeDescriptor
CManufacturerReportAck::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "ManufacturerReportAck",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    1003,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CManufacturerReportAck::s_apFieldDescriptorTable[] =
{
  
    NULL
};

CManufacturerReportAck::CManufacturerReportAck (void)
{
    m_pType = &s_typeDescriptor;
  
    m_pStatus = NULL;
}

CManufacturerReportAck::~CManufacturerReportAck (void)
{
}


CElement *
CManufacturerReportAck::s_construct (void)
{
    return (CElement *) new CManufacturerReportAck();
}


void
CManufacturerReportAck::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CManufacturerReportAck * pTarget = (CManufacturerReportAck *) pTargetElement;

  
}


void
CManufacturerReportAck::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CManufacturerReportAck::assimilateSubParameters (
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
CManufacturerReportAck::setStatus (
  CStatus *     pValue)
{
    removeSubParameterFromAllList(m_pStatus);
    delete m_pStatus;
    m_pStatus = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CManufacturerReportAck::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;

  
    pType = &CStatus::s_typeDescriptor;
      
    pEncoderStream->putRequiredSubParameter(m_pStatus, pType);
      
}


void
tmp_enrollCoreTypesIntoRegistry (
  CTypeRegistry *               pTypeRegistry)
{
  
    pTypeRegistry->enroll(&CManufacturerCommand::s_typeDescriptor);
  
    pTypeRegistry->enroll(&CManufacturerCommandAck::s_typeDescriptor);
  
    pTypeRegistry->enroll(&CManufacturerReport::s_typeDescriptor);
  
    pTypeRegistry->enroll(&CManufacturerReportAck::s_typeDescriptor);
  
}

