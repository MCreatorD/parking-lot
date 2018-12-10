#include "LLRP_Operation.h"
#include "LLRP_NET.h"
#include "LLRP_General.h"


namespace LLRP {


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
g_estAccessCurrentState[] =
{

    {
        "Disabled",
        AccessCurrentState_Disabled,
    },
    {
        "Active",
        AccessCurrentState_Active,
    },
    { 0, 0 }
};


const SEnumTableEntry
g_estSelectCurrentState[] =
{

    {
        "Disabled",
        SelectCurrentState_Disabled,
    },
    {
        "Inactive",
        SelectCurrentState_Inactive,
    },
    {
        "Active",
        SelectCurrentState_Active,
    },
    { 0, 0 }
};


const SEnumTableEntry
g_estPersistence[] =
{

    {
        "Noneed",
        Persistence_Noneed,
    },
    {
        "Need",
        Persistence_Need,
    },
    { 0, 0 }
};


const SEnumTableEntry
g_estSelectSpecStartTriggerType[] =
{

    {
        "Unconditional",
        SelectSpecStartTriggerType_Unconditional,
    },
    {
        "Immediately",
        SelectSpecStartTriggerType_Immediately,
    },
    {
        "Periodic",
        SelectSpecStartTriggerType_Periodic,
    },
    {
        "GPI",
        SelectSpecStartTriggerType_GPI,
    },
    { 0, 0 }
};


const SEnumTableEntry
g_estSelectSpecStopTriggerType[] =
{

    {
        "Unconditional",
        SelectSpecStopTriggerType_Unconditional,
    },
    {
        "Persistent",
        SelectSpecStopTriggerType_Persistent,
    },
    {
        "GPI",
        SelectSpecStopTriggerType_GPI,
    },
    { 0, 0 }
};


const SEnumTableEntry
g_estAntennaSpecStopTriggerType[] =
{

    {
        "SelectSpecStop",
        AntennaSpecStopTriggerType_SelectSpecStop,
    },
    {
        "Persistent",
        AntennaSpecStopTriggerType_Persistent,
    },
    {
        "GPI",
        AntennaSpecStopTriggerType_GPI,
    },
    {
        "LabelRule",
        AntennaSpecStopTriggerType_LabelRule,
    },
    { 0, 0 }
};


const SEnumTableEntry
g_estTriggerType[] =
{

    {
        "NLabels",
        TriggerType_NLabels,
    },
    {
        "TMilliseconds",
        TriggerType_TMilliseconds,
    },
    {
        "ATimes",
        TriggerType_ATimes,
    },
    { 0, 0 }
};


const SEnumTableEntry
g_estProtocolID[] =
{

    {
        "HangBiao",
        ProtocolID_HangBiao,
    },
    { 0, 0 }
};


const SEnumTableEntry
g_estSelectType[] =
{

    {
        "Check",
        SelectType_Check,
    },
    {
        "Read",
        SelectType_Read,
    },
    { 0, 0 }
};


const SEnumTableEntry
g_estSelectReportTrigger[] =
{

    {
        "Unconditional",
        SelectReportTrigger_Unconditional,
    },
    {
        "Antenna",
        SelectReportTrigger_Antenna,
    },
    {
        "Label",
        SelectReportTrigger_Label,
    },
    {
        "NoReport",
        SelectReportTrigger_NoReport,
    },
    { 0, 0 }
};


const SEnumTableEntry
g_estAccessSpecStopTriggerType[] =
{

    {
        "Unconditional",
        AccessSpecStopTriggerType_Unconditional,
    },
    {
        "OperatingTimes",
        AccessSpecStopTriggerType_OperatingTimes,
    },
    { 0, 0 }
};


const SEnumTableEntry
g_estMemoryType[] =
{

    {
        "TID",
        MemoryType_TID,
    },
    {
        "User",
        MemoryType_User,
    },
    { 0, 0 }
};


const SEnumTableEntry
g_estMatchType[] =
{

    {
        "Forward",
        MatchType_Forward,
    },
    {
        "Reverse",
        MatchType_Reverse,
    },
    { 0, 0 }
};


const SEnumTableEntry
g_estAccessMode[] =
{

    {
        "LowerHalf",
        AccessMode_LowerHalf,
    },
    {
        "UpperHalf",
        AccessMode_UpperHalf,
    },
    {
        "Whole",
        AccessMode_Whole,
    },
    {
        "TwoTimes",
        AccessMode_TwoTimes,
    },
    { 0, 0 }
};


const SEnumTableEntry
g_estDataMode[] =
{

    {
        "Ciphertext",
        DataMode_Ciphertext,
    },
    {
        "Plaintext",
        DataMode_Plaintext,
    },
    { 0, 0 }
};


const SEnumTableEntry
g_estBAKReadMode[] =
{

    {
        "NormalRead",
        BAKReadMode_NormalRead,
    },
    {
        "FastRead",
        BAKReadMode_FastRead,
    },
    { 0, 0 }
};




const SEnumTableEntry
g_estAccessReportTrigger[] =
{

    {
        "SelectReportCreate",
        AccessReportTrigger_SelectReportCreate,
    },
    {
        "AccessSpecStop",
        AccessReportTrigger_AccessSpecStop,
    },
    { 0, 0 }
};




/*
*****************************************************************
**
** Message AddSelectSpec
**
*****************************************************************
*/


const CTypeDescriptor
CAddSelectSpec::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "AddSelectSpec",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    400,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CAddSelectSpec::s_apFieldDescriptorTable[] =
{

    NULL
};

CAddSelectSpec::CAddSelectSpec (void)
{
    m_pType = &s_typeDescriptor;

    m_pSelectSpec = NULL;
}

CAddSelectSpec::~CAddSelectSpec (void)
{
}


CElement *
CAddSelectSpec::s_construct (void)
{
    return (CElement *) new CAddSelectSpec();
}


void
CAddSelectSpec::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CAddSelectSpec * pTarget = (CAddSelectSpec *) pTargetElement;


}


void
CAddSelectSpec::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CAddSelectSpec::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    // 1 of SelectSpec
    pType = &CSelectSpec::s_typeDescriptor;

    if(Cur == End || (*Cur)->m_pType != pType)
    {
        goto missing;
    }
    m_pSelectSpec = (CSelectSpec *)*Cur++;


    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


EResultCode
CAddSelectSpec::setSelectSpec (
  CSelectSpec *     pValue)
{
    removeSubParameterFromAllList(m_pSelectSpec);
    delete m_pSelectSpec;
    m_pSelectSpec = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CAddSelectSpec::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pType = &CSelectSpec::s_typeDescriptor;

    pEncoderStream->putRequiredSubParameter(m_pSelectSpec, pType);

}




/*
*****************************************************************
**
** Message AddSelectSpecAck
**
*****************************************************************
*/


const CTypeDescriptor
CAddSelectSpecAck::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "AddSelectSpecAck",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    401,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CAddSelectSpecAck::s_apFieldDescriptorTable[] =
{

    NULL
};

CAddSelectSpecAck::CAddSelectSpecAck (void)
{
    m_pType = &s_typeDescriptor;

    m_pStatus = NULL;
}

CAddSelectSpecAck::~CAddSelectSpecAck (void)
{
}


CElement *
CAddSelectSpecAck::s_construct (void)
{
    return (CElement *) new CAddSelectSpecAck();
}


void
CAddSelectSpecAck::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CAddSelectSpecAck * pTarget = (CAddSelectSpecAck *) pTargetElement;


}


void
CAddSelectSpecAck::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CAddSelectSpecAck::assimilateSubParameters (
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
CAddSelectSpecAck::setStatus (
  CStatus *     pValue)
{
    removeSubParameterFromAllList(m_pStatus);
    delete m_pStatus;
    m_pStatus = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CAddSelectSpecAck::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pType = &CStatus::s_typeDescriptor;

    pEncoderStream->putRequiredSubParameter(m_pStatus, pType);

}




/*
*****************************************************************
**
** Message DeleteSelectSpec
**
*****************************************************************
*/


const CTypeDescriptor
CDeleteSelectSpec::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "DeleteSelectSpec",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    402,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CDeleteSelectSpec::s_apFieldDescriptorTable[] =
{

    &s_fdSelectSpecID,
    NULL
};



const CFieldDescriptor
CDeleteSelectSpec::s_fdSelectSpecID =
{
    CFieldDescriptor::FT_U32,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "SelectSpecID",	// m_pName
    NULL	// m_pEnumTable
};
CDeleteSelectSpec::CDeleteSelectSpec (void)
{
    m_pType = &s_typeDescriptor;

    m_SelectSpecID = 0;
}

CDeleteSelectSpec::~CDeleteSelectSpec (void)
{
}


CElement *
CDeleteSelectSpec::s_construct (void)
{
    return (CElement *) new CDeleteSelectSpec();
}


void
CDeleteSelectSpec::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CDeleteSelectSpec * pTarget = (CDeleteSelectSpec *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_SelectSpecID = pDecoderStream->get_u32(&s_fdSelectSpecID);
    }
    else
    {
        pDecoderStream->get_u32(&s_fdSelectSpecID);
    }

}


void
CDeleteSelectSpec::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CDeleteSelectSpec::assimilateSubParameters (
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
CDeleteSelectSpec::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u32(m_SelectSpecID, &s_fdSelectSpecID);

}




/*
*****************************************************************
**
** Message DeleteSelectSpecAck
**
*****************************************************************
*/


const CTypeDescriptor
CDeleteSelectSpecAck::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "DeleteSelectSpecAck",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    403,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CDeleteSelectSpecAck::s_apFieldDescriptorTable[] =
{

    NULL
};

CDeleteSelectSpecAck::CDeleteSelectSpecAck (void)
{
    m_pType = &s_typeDescriptor;

    m_pStatus = NULL;
}

CDeleteSelectSpecAck::~CDeleteSelectSpecAck (void)
{
}


CElement *
CDeleteSelectSpecAck::s_construct (void)
{
    return (CElement *) new CDeleteSelectSpecAck();
}


void
CDeleteSelectSpecAck::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CDeleteSelectSpecAck * pTarget = (CDeleteSelectSpecAck *) pTargetElement;


}


void
CDeleteSelectSpecAck::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CDeleteSelectSpecAck::assimilateSubParameters (
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
CDeleteSelectSpecAck::setStatus (
  CStatus *     pValue)
{
    removeSubParameterFromAllList(m_pStatus);
    delete m_pStatus;
    m_pStatus = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CDeleteSelectSpecAck::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pType = &CStatus::s_typeDescriptor;

    pEncoderStream->putRequiredSubParameter(m_pStatus, pType);

}




/*
*****************************************************************
**
** Message StartSelectSpec
**
*****************************************************************
*/


const CTypeDescriptor
CStartSelectSpec::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "StartSelectSpec",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    404,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CStartSelectSpec::s_apFieldDescriptorTable[] =
{

    &s_fdSelectSpecID,
    NULL
};



const CFieldDescriptor
CStartSelectSpec::s_fdSelectSpecID =
{
    CFieldDescriptor::FT_U32,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "SelectSpecID",	// m_pName
    NULL	// m_pEnumTable
};
CStartSelectSpec::CStartSelectSpec (void)
{
    m_pType = &s_typeDescriptor;

    m_SelectSpecID = 0;
}

CStartSelectSpec::~CStartSelectSpec (void)
{
}


CElement *
CStartSelectSpec::s_construct (void)
{
    return (CElement *) new CStartSelectSpec();
}


void
CStartSelectSpec::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CStartSelectSpec * pTarget = (CStartSelectSpec *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_SelectSpecID = pDecoderStream->get_u32(&s_fdSelectSpecID);
    }
    else
    {
        pDecoderStream->get_u32(&s_fdSelectSpecID);
    }

}


void
CStartSelectSpec::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CStartSelectSpec::assimilateSubParameters (
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
CStartSelectSpec::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u32(m_SelectSpecID, &s_fdSelectSpecID);

}




/*
*****************************************************************
**
** Message StartSelectSpecAck
**
*****************************************************************
*/


const CTypeDescriptor
CStartSelectSpecAck::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "StartSelectSpecAck",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    405,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CStartSelectSpecAck::s_apFieldDescriptorTable[] =
{

    NULL
};

CStartSelectSpecAck::CStartSelectSpecAck (void)
{
    m_pType = &s_typeDescriptor;

    m_pStatus = NULL;
}

CStartSelectSpecAck::~CStartSelectSpecAck (void)
{
}


CElement *
CStartSelectSpecAck::s_construct (void)
{
    return (CElement *) new CStartSelectSpecAck();
}


void
CStartSelectSpecAck::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CStartSelectSpecAck * pTarget = (CStartSelectSpecAck *) pTargetElement;


}


void
CStartSelectSpecAck::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CStartSelectSpecAck::assimilateSubParameters (
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
CStartSelectSpecAck::setStatus (
  CStatus *     pValue)
{
    removeSubParameterFromAllList(m_pStatus);
    delete m_pStatus;
    m_pStatus = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CStartSelectSpecAck::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pType = &CStatus::s_typeDescriptor;

    pEncoderStream->putRequiredSubParameter(m_pStatus, pType);

}




/*
*****************************************************************
**
** Message StopSelectSpec
**
*****************************************************************
*/


const CTypeDescriptor
CStopSelectSpec::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "StopSelectSpec",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    406,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CStopSelectSpec::s_apFieldDescriptorTable[] =
{

    &s_fdSelectSpecID,
    NULL
};



const CFieldDescriptor
CStopSelectSpec::s_fdSelectSpecID =
{
    CFieldDescriptor::FT_U32,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "SelectSpecID",	// m_pName
    NULL	// m_pEnumTable
};
CStopSelectSpec::CStopSelectSpec (void)
{
    m_pType = &s_typeDescriptor;

    m_SelectSpecID = 0;
}

CStopSelectSpec::~CStopSelectSpec (void)
{
}


CElement *
CStopSelectSpec::s_construct (void)
{
    return (CElement *) new CStopSelectSpec();
}


void
CStopSelectSpec::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CStopSelectSpec * pTarget = (CStopSelectSpec *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_SelectSpecID = pDecoderStream->get_u32(&s_fdSelectSpecID);
    }
    else
    {
        pDecoderStream->get_u32(&s_fdSelectSpecID);
    }

}


void
CStopSelectSpec::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CStopSelectSpec::assimilateSubParameters (
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
CStopSelectSpec::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u32(m_SelectSpecID, &s_fdSelectSpecID);

}




/*
*****************************************************************
**
** Message StopSelectSpecAck
**
*****************************************************************
*/


const CTypeDescriptor
CStopSelectSpecAck::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "StopSelectSpecAck",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    407,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CStopSelectSpecAck::s_apFieldDescriptorTable[] =
{

    NULL
};

CStopSelectSpecAck::CStopSelectSpecAck (void)
{
    m_pType = &s_typeDescriptor;

    m_pStatus = NULL;
}

CStopSelectSpecAck::~CStopSelectSpecAck (void)
{
}


CElement *
CStopSelectSpecAck::s_construct (void)
{
    return (CElement *) new CStopSelectSpecAck();
}


void
CStopSelectSpecAck::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CStopSelectSpecAck * pTarget = (CStopSelectSpecAck *) pTargetElement;


}


void
CStopSelectSpecAck::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CStopSelectSpecAck::assimilateSubParameters (
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
CStopSelectSpecAck::setStatus (
  CStatus *     pValue)
{
    removeSubParameterFromAllList(m_pStatus);
    delete m_pStatus;
    m_pStatus = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CStopSelectSpecAck::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pType = &CStatus::s_typeDescriptor;

    pEncoderStream->putRequiredSubParameter(m_pStatus, pType);

}




/*
*****************************************************************
**
** Message EnableSelectSpec
**
*****************************************************************
*/


const CTypeDescriptor
CEnableSelectSpec::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "EnableSelectSpec",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    408,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CEnableSelectSpec::s_apFieldDescriptorTable[] =
{

    &s_fdSelectSpecID,
    NULL
};



const CFieldDescriptor
CEnableSelectSpec::s_fdSelectSpecID =
{
    CFieldDescriptor::FT_U32,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "SelectSpecID",	// m_pName
    NULL	// m_pEnumTable
};
CEnableSelectSpec::CEnableSelectSpec (void)
{
    m_pType = &s_typeDescriptor;

    m_SelectSpecID = 0;
}

CEnableSelectSpec::~CEnableSelectSpec (void)
{
}


CElement *
CEnableSelectSpec::s_construct (void)
{
    return (CElement *) new CEnableSelectSpec();
}


void
CEnableSelectSpec::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CEnableSelectSpec * pTarget = (CEnableSelectSpec *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_SelectSpecID = pDecoderStream->get_u32(&s_fdSelectSpecID);
    }
    else
    {
        pDecoderStream->get_u32(&s_fdSelectSpecID);
    }

}


void
CEnableSelectSpec::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CEnableSelectSpec::assimilateSubParameters (
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
CEnableSelectSpec::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u32(m_SelectSpecID, &s_fdSelectSpecID);

}




/*
*****************************************************************
**
** Message EnableSelectSpecAck
**
*****************************************************************
*/


const CTypeDescriptor
CEnableSelectSpecAck::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "EnableSelectSpecAck",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    409,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CEnableSelectSpecAck::s_apFieldDescriptorTable[] =
{

    NULL
};

CEnableSelectSpecAck::CEnableSelectSpecAck (void)
{
    m_pType = &s_typeDescriptor;

    m_pStatus = NULL;
}

CEnableSelectSpecAck::~CEnableSelectSpecAck (void)
{
}


CElement *
CEnableSelectSpecAck::s_construct (void)
{
    return (CElement *) new CEnableSelectSpecAck();
}


void
CEnableSelectSpecAck::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CEnableSelectSpecAck * pTarget = (CEnableSelectSpecAck *) pTargetElement;


}


void
CEnableSelectSpecAck::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CEnableSelectSpecAck::assimilateSubParameters (
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
CEnableSelectSpecAck::setStatus (
  CStatus *     pValue)
{
    removeSubParameterFromAllList(m_pStatus);
    delete m_pStatus;
    m_pStatus = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CEnableSelectSpecAck::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pType = &CStatus::s_typeDescriptor;

    pEncoderStream->putRequiredSubParameter(m_pStatus, pType);

}




/*
*****************************************************************
**
** Message DisableSelectSpec
**
*****************************************************************
*/


const CTypeDescriptor
CDisableSelectSpec::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "DisableSelectSpec",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    410,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CDisableSelectSpec::s_apFieldDescriptorTable[] =
{

    &s_fdSelectSpecID,
    NULL
};



const CFieldDescriptor
CDisableSelectSpec::s_fdSelectSpecID =
{
    CFieldDescriptor::FT_U32,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "SelectSpecID",	// m_pName
    NULL	// m_pEnumTable
};
CDisableSelectSpec::CDisableSelectSpec (void)
{
    m_pType = &s_typeDescriptor;

    m_SelectSpecID = 0;
}

CDisableSelectSpec::~CDisableSelectSpec (void)
{
}


CElement *
CDisableSelectSpec::s_construct (void)
{
    return (CElement *) new CDisableSelectSpec();
}


void
CDisableSelectSpec::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CDisableSelectSpec * pTarget = (CDisableSelectSpec *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_SelectSpecID = pDecoderStream->get_u32(&s_fdSelectSpecID);
    }
    else
    {
        pDecoderStream->get_u32(&s_fdSelectSpecID);
    }

}


void
CDisableSelectSpec::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CDisableSelectSpec::assimilateSubParameters (
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
CDisableSelectSpec::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u32(m_SelectSpecID, &s_fdSelectSpecID);

}




/*
*****************************************************************
**
** Message DisableSelectSpecAck
**
*****************************************************************
*/


const CTypeDescriptor
CDisableSelectSpecAck::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "DisableSelectSpecAck",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    411,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CDisableSelectSpecAck::s_apFieldDescriptorTable[] =
{

    NULL
};

CDisableSelectSpecAck::CDisableSelectSpecAck (void)
{
    m_pType = &s_typeDescriptor;

    m_pStatus = NULL;
}

CDisableSelectSpecAck::~CDisableSelectSpecAck (void)
{
}


CElement *
CDisableSelectSpecAck::s_construct (void)
{
    return (CElement *) new CDisableSelectSpecAck();
}


void
CDisableSelectSpecAck::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CDisableSelectSpecAck * pTarget = (CDisableSelectSpecAck *) pTargetElement;


}


void
CDisableSelectSpecAck::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CDisableSelectSpecAck::assimilateSubParameters (
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
CDisableSelectSpecAck::setStatus (
  CStatus *     pValue)
{
    removeSubParameterFromAllList(m_pStatus);
    delete m_pStatus;
    m_pStatus = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CDisableSelectSpecAck::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pType = &CStatus::s_typeDescriptor;

    pEncoderStream->putRequiredSubParameter(m_pStatus, pType);

}




/*
*****************************************************************
**
** Message GetSelectSpec
**
*****************************************************************
*/


const CTypeDescriptor
CGetSelectSpec::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "GetSelectSpec",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    412,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CGetSelectSpec::s_apFieldDescriptorTable[] =
{

    NULL
};

CGetSelectSpec::CGetSelectSpec (void)
{
    m_pType = &s_typeDescriptor;

}

CGetSelectSpec::~CGetSelectSpec (void)
{
}


CElement *
CGetSelectSpec::s_construct (void)
{
    return (CElement *) new CGetSelectSpec();
}


void
CGetSelectSpec::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CGetSelectSpec * pTarget = (CGetSelectSpec *) pTargetElement;


}


void
CGetSelectSpec::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CGetSelectSpec::assimilateSubParameters (
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
CGetSelectSpec::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


}




/*
*****************************************************************
**
** Message GetSelectSpecAck
**
*****************************************************************
*/


const CTypeDescriptor
CGetSelectSpecAck::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "GetSelectSpecAck",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    413,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CGetSelectSpecAck::s_apFieldDescriptorTable[] =
{

    NULL
};

CGetSelectSpecAck::CGetSelectSpecAck (void)
{
    m_pType = &s_typeDescriptor;

    m_pStatus = NULL;
}

CGetSelectSpecAck::~CGetSelectSpecAck (void)
{
}


CElement *
CGetSelectSpecAck::s_construct (void)
{
    return (CElement *) new CGetSelectSpecAck();
}


void
CGetSelectSpecAck::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CGetSelectSpecAck * pTarget = (CGetSelectSpecAck *) pTargetElement;


}


void
CGetSelectSpecAck::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CGetSelectSpecAck::assimilateSubParameters (
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


    // 0-N of SelectSpec
    pType = &CSelectSpec::s_typeDescriptor;

    while(Cur != End && (*Cur)->m_pType == pType)
    {
        m_listSelectSpec.push_back((CSelectSpec *)*Cur);
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
CGetSelectSpecAck::setStatus (
  CStatus *     pValue)
{
    removeSubParameterFromAllList(m_pStatus);
    delete m_pStatus;
    m_pStatus = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CGetSelectSpecAck::addSelectSpec (
  CSelectSpec *     pValue)
{
    m_listSelectSpec.push_back(pValue);
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CGetSelectSpecAck::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pType = &CStatus::s_typeDescriptor;

    pEncoderStream->putRequiredSubParameter(m_pStatus, pType);

    pType = &CSelectSpec::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameterList((tListOfParameters *) &m_listSelectSpec, pType);

}




/*
*****************************************************************
**
** Message AddAccessSpec
**
*****************************************************************
*/


const CTypeDescriptor
CAddAccessSpec::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "AddAccessSpec",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    450,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CAddAccessSpec::s_apFieldDescriptorTable[] =
{

    NULL
};

CAddAccessSpec::CAddAccessSpec (void)
{
    m_pType = &s_typeDescriptor;

    m_pAccessSpec = NULL;
}

CAddAccessSpec::~CAddAccessSpec (void)
{
}


CElement *
CAddAccessSpec::s_construct (void)
{
    return (CElement *) new CAddAccessSpec();
}


void
CAddAccessSpec::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CAddAccessSpec * pTarget = (CAddAccessSpec *) pTargetElement;


}


void
CAddAccessSpec::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CAddAccessSpec::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    // 1 of AccessSpec
    pType = &CAccessSpec::s_typeDescriptor;

    if(Cur == End || (*Cur)->m_pType != pType)
    {
        goto missing;
    }
    m_pAccessSpec = (CAccessSpec *)*Cur++;


    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


EResultCode
CAddAccessSpec::setAccessSpec (
  CAccessSpec *     pValue)
{
    removeSubParameterFromAllList(m_pAccessSpec);
    delete m_pAccessSpec;
    m_pAccessSpec = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CAddAccessSpec::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pType = &CAccessSpec::s_typeDescriptor;

    pEncoderStream->putRequiredSubParameter(m_pAccessSpec, pType);

}




/*
*****************************************************************
**
** Message AddAccessSpecAck
**
*****************************************************************
*/


const CTypeDescriptor
CAddAccessSpecAck::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "AddAccessSpecAck",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    451,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CAddAccessSpecAck::s_apFieldDescriptorTable[] =
{

    NULL
};

CAddAccessSpecAck::CAddAccessSpecAck (void)
{
    m_pType = &s_typeDescriptor;

    m_pStatus = NULL;
}

CAddAccessSpecAck::~CAddAccessSpecAck (void)
{
}


CElement *
CAddAccessSpecAck::s_construct (void)
{
    return (CElement *) new CAddAccessSpecAck();
}


void
CAddAccessSpecAck::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CAddAccessSpecAck * pTarget = (CAddAccessSpecAck *) pTargetElement;


}


void
CAddAccessSpecAck::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CAddAccessSpecAck::assimilateSubParameters (
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
CAddAccessSpecAck::setStatus (
  CStatus *     pValue)
{
    removeSubParameterFromAllList(m_pStatus);
    delete m_pStatus;
    m_pStatus = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CAddAccessSpecAck::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pType = &CStatus::s_typeDescriptor;

    pEncoderStream->putRequiredSubParameter(m_pStatus, pType);

}




/*
*****************************************************************
**
** Message DeleteAccessSpec
**
*****************************************************************
*/


const CTypeDescriptor
CDeleteAccessSpec::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "DeleteAccessSpec",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    452,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CDeleteAccessSpec::s_apFieldDescriptorTable[] =
{

    &s_fdAccessSpecID,
    NULL
};



const CFieldDescriptor
CDeleteAccessSpec::s_fdAccessSpecID =
{
    CFieldDescriptor::FT_U32,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "AccessSpecID",	// m_pName
    NULL	// m_pEnumTable
};
CDeleteAccessSpec::CDeleteAccessSpec (void)
{
    m_pType = &s_typeDescriptor;

    m_AccessSpecID = 0;
}

CDeleteAccessSpec::~CDeleteAccessSpec (void)
{
}


CElement *
CDeleteAccessSpec::s_construct (void)
{
    return (CElement *) new CDeleteAccessSpec();
}


void
CDeleteAccessSpec::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CDeleteAccessSpec * pTarget = (CDeleteAccessSpec *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_AccessSpecID = pDecoderStream->get_u32(&s_fdAccessSpecID);
    }
    else
    {
        pDecoderStream->get_u32(&s_fdAccessSpecID);
    }

}


void
CDeleteAccessSpec::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CDeleteAccessSpec::assimilateSubParameters (
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
CDeleteAccessSpec::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u32(m_AccessSpecID, &s_fdAccessSpecID);

}




/*
*****************************************************************
**
** Message DeleteAccessSpecAck
**
*****************************************************************
*/


const CTypeDescriptor
CDeleteAccessSpecAck::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "DeleteAccessSpecAck",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    453,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CDeleteAccessSpecAck::s_apFieldDescriptorTable[] =
{

    NULL
};

CDeleteAccessSpecAck::CDeleteAccessSpecAck (void)
{
    m_pType = &s_typeDescriptor;

    m_pStatus = NULL;
}

CDeleteAccessSpecAck::~CDeleteAccessSpecAck (void)
{
}


CElement *
CDeleteAccessSpecAck::s_construct (void)
{
    return (CElement *) new CDeleteAccessSpecAck();
}


void
CDeleteAccessSpecAck::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CDeleteAccessSpecAck * pTarget = (CDeleteAccessSpecAck *) pTargetElement;


}


void
CDeleteAccessSpecAck::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CDeleteAccessSpecAck::assimilateSubParameters (
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
CDeleteAccessSpecAck::setStatus (
  CStatus *     pValue)
{
    removeSubParameterFromAllList(m_pStatus);
    delete m_pStatus;
    m_pStatus = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CDeleteAccessSpecAck::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pType = &CStatus::s_typeDescriptor;

    pEncoderStream->putRequiredSubParameter(m_pStatus, pType);

}




/*
*****************************************************************
**
** Message EnableAccessSpec
**
*****************************************************************
*/


const CTypeDescriptor
CEnableAccessSpec::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "EnableAccessSpec",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    454,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CEnableAccessSpec::s_apFieldDescriptorTable[] =
{

    &s_fdAccessSpecID,
    NULL
};



const CFieldDescriptor
CEnableAccessSpec::s_fdAccessSpecID =
{
    CFieldDescriptor::FT_U32,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "AccessSpecID",	// m_pName
    NULL	// m_pEnumTable
};
CEnableAccessSpec::CEnableAccessSpec (void)
{
    m_pType = &s_typeDescriptor;

    m_AccessSpecID = 0;
}

CEnableAccessSpec::~CEnableAccessSpec (void)
{
}


CElement *
CEnableAccessSpec::s_construct (void)
{
    return (CElement *) new CEnableAccessSpec();
}


void
CEnableAccessSpec::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CEnableAccessSpec * pTarget = (CEnableAccessSpec *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_AccessSpecID = pDecoderStream->get_u32(&s_fdAccessSpecID);
    }
    else
    {
        pDecoderStream->get_u32(&s_fdAccessSpecID);
    }

}


void
CEnableAccessSpec::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CEnableAccessSpec::assimilateSubParameters (
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
CEnableAccessSpec::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u32(m_AccessSpecID, &s_fdAccessSpecID);

}




/*
*****************************************************************
**
** Message EnableAccessSpecAck
**
*****************************************************************
*/


const CTypeDescriptor
CEnableAccessSpecAck::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "EnableAccessSpecAck",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    455,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CEnableAccessSpecAck::s_apFieldDescriptorTable[] =
{

    NULL
};

CEnableAccessSpecAck::CEnableAccessSpecAck (void)
{
    m_pType = &s_typeDescriptor;

    m_pStatus = NULL;
}

CEnableAccessSpecAck::~CEnableAccessSpecAck (void)
{
}


CElement *
CEnableAccessSpecAck::s_construct (void)
{
    return (CElement *) new CEnableAccessSpecAck();
}


void
CEnableAccessSpecAck::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CEnableAccessSpecAck * pTarget = (CEnableAccessSpecAck *) pTargetElement;


}


void
CEnableAccessSpecAck::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CEnableAccessSpecAck::assimilateSubParameters (
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
CEnableAccessSpecAck::setStatus (
  CStatus *     pValue)
{
    removeSubParameterFromAllList(m_pStatus);
    delete m_pStatus;
    m_pStatus = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CEnableAccessSpecAck::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pType = &CStatus::s_typeDescriptor;

    pEncoderStream->putRequiredSubParameter(m_pStatus, pType);

}




/*
*****************************************************************
**
** Message DisableAccessSpec
**
*****************************************************************
*/


const CTypeDescriptor
CDisableAccessSpec::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "DisableAccessSpec",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    456,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CDisableAccessSpec::s_apFieldDescriptorTable[] =
{

    &s_fdAccessSpecID,
    NULL
};



const CFieldDescriptor
CDisableAccessSpec::s_fdAccessSpecID =
{
    CFieldDescriptor::FT_U32,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "AccessSpecID",	// m_pName
    NULL	// m_pEnumTable
};
CDisableAccessSpec::CDisableAccessSpec (void)
{
    m_pType = &s_typeDescriptor;

    m_AccessSpecID = 0;
}

CDisableAccessSpec::~CDisableAccessSpec (void)
{
}


CElement *
CDisableAccessSpec::s_construct (void)
{
    return (CElement *) new CDisableAccessSpec();
}


void
CDisableAccessSpec::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CDisableAccessSpec * pTarget = (CDisableAccessSpec *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_AccessSpecID = pDecoderStream->get_u32(&s_fdAccessSpecID);
    }
    else
    {
        pDecoderStream->get_u32(&s_fdAccessSpecID);
    }

}


void
CDisableAccessSpec::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CDisableAccessSpec::assimilateSubParameters (
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
CDisableAccessSpec::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u32(m_AccessSpecID, &s_fdAccessSpecID);

}




/*
*****************************************************************
**
** Message DisableAccessSpecAck
**
*****************************************************************
*/


const CTypeDescriptor
CDisableAccessSpecAck::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "DisableAccessSpecAck",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    457,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CDisableAccessSpecAck::s_apFieldDescriptorTable[] =
{

    NULL
};

CDisableAccessSpecAck::CDisableAccessSpecAck (void)
{
    m_pType = &s_typeDescriptor;

    m_pStatus = NULL;
}

CDisableAccessSpecAck::~CDisableAccessSpecAck (void)
{
}


CElement *
CDisableAccessSpecAck::s_construct (void)
{
    return (CElement *) new CDisableAccessSpecAck();
}


void
CDisableAccessSpecAck::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CDisableAccessSpecAck * pTarget = (CDisableAccessSpecAck *) pTargetElement;


}


void
CDisableAccessSpecAck::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CDisableAccessSpecAck::assimilateSubParameters (
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
CDisableAccessSpecAck::setStatus (
  CStatus *     pValue)
{
    removeSubParameterFromAllList(m_pStatus);
    delete m_pStatus;
    m_pStatus = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CDisableAccessSpecAck::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pType = &CStatus::s_typeDescriptor;

    pEncoderStream->putRequiredSubParameter(m_pStatus, pType);

}




/*
*****************************************************************
**
** Message GetAccessSpec
**
*****************************************************************
*/


const CTypeDescriptor
CGetAccessSpec::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "GetAccessSpec",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    458,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CGetAccessSpec::s_apFieldDescriptorTable[] =
{

    NULL
};

CGetAccessSpec::CGetAccessSpec (void)
{
    m_pType = &s_typeDescriptor;

}

CGetAccessSpec::~CGetAccessSpec (void)
{
}


CElement *
CGetAccessSpec::s_construct (void)
{
    return (CElement *) new CGetAccessSpec();
}


void
CGetAccessSpec::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CGetAccessSpec * pTarget = (CGetAccessSpec *) pTargetElement;


}


void
CGetAccessSpec::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CGetAccessSpec::assimilateSubParameters (
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
CGetAccessSpec::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


}




/*
*****************************************************************
**
** Message GetAccessSpecAck
**
*****************************************************************
*/


const CTypeDescriptor
CGetAccessSpecAck::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "GetAccessSpecAck",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    459,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CGetAccessSpecAck::s_apFieldDescriptorTable[] =
{

    NULL
};

CGetAccessSpecAck::CGetAccessSpecAck (void)
{
    m_pType = &s_typeDescriptor;

    m_pStatus = NULL;
}

CGetAccessSpecAck::~CGetAccessSpecAck (void)
{
}


CElement *
CGetAccessSpecAck::s_construct (void)
{
    return (CElement *) new CGetAccessSpecAck();
}


void
CGetAccessSpecAck::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CGetAccessSpecAck * pTarget = (CGetAccessSpecAck *) pTargetElement;


}


void
CGetAccessSpecAck::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CGetAccessSpecAck::assimilateSubParameters (
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


    // 0-N of AccessSpec
    pType = &CAccessSpec::s_typeDescriptor;

    while(Cur != End && (*Cur)->m_pType == pType)
    {
        m_listAccessSpec.push_back((CAccessSpec *)*Cur);
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
CGetAccessSpecAck::setStatus (
  CStatus *     pValue)
{
    removeSubParameterFromAllList(m_pStatus);
    delete m_pStatus;
    m_pStatus = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CGetAccessSpecAck::addAccessSpec (
  CAccessSpec *     pValue)
{
    m_listAccessSpec.push_back(pValue);
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CGetAccessSpecAck::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pType = &CStatus::s_typeDescriptor;

    pEncoderStream->putRequiredSubParameter(m_pStatus, pType);

    pType = &CAccessSpec::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameterList((tListOfParameters *) &m_listAccessSpec, pType);

}




/*
*****************************************************************
**
** Message TagSelectAccessReport
**
*****************************************************************
*/


const CTypeDescriptor
CTagSelectAccessReport::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "TagSelectAccessReport",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    500,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CTagSelectAccessReport::s_apFieldDescriptorTable[] =
{

    NULL
};

CTagSelectAccessReport::CTagSelectAccessReport (void)
{
    m_pType = &s_typeDescriptor;

}

CTagSelectAccessReport::~CTagSelectAccessReport (void)
{
}


CElement *
CTagSelectAccessReport::s_construct (void)
{
    return (CElement *) new CTagSelectAccessReport();
}


void
CTagSelectAccessReport::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CTagSelectAccessReport * pTarget = (CTagSelectAccessReport *) pTargetElement;


}


void
CTagSelectAccessReport::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CTagSelectAccessReport::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    // 0-N of TagReportData
    pType = &CTagReportData::s_typeDescriptor;

    while(Cur != End && (*Cur)->m_pType == pType)
    {
        m_listTagReportData.push_back((CTagReportData *)*Cur);
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
CTagSelectAccessReport::addTagReportData (
  CTagReportData *     pValue)
{
    m_listTagReportData.push_back(pValue);
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CTagSelectAccessReport::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pType = &CTagReportData::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameterList((tListOfParameters *) &m_listTagReportData, pType);

}




/*
*****************************************************************
**
** Message ClientRequestOp
**
*****************************************************************
*/


const CTypeDescriptor
CClientRequestOp::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "ClientRequestOp",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    590,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CClientRequestOp::s_apFieldDescriptorTable[] =
{

    NULL
};

CClientRequestOp::CClientRequestOp (void)
{
    m_pType = &s_typeDescriptor;

    m_pTagReportData = NULL;
}

CClientRequestOp::~CClientRequestOp (void)
{
}


CElement *
CClientRequestOp::s_construct (void)
{
    return (CElement *) new CClientRequestOp();
}


void
CClientRequestOp::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CClientRequestOp * pTarget = (CClientRequestOp *) pTargetElement;


}


void
CClientRequestOp::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CClientRequestOp::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    // 1 of TagReportData
    pType = &CTagReportData::s_typeDescriptor;

    if(Cur == End || (*Cur)->m_pType != pType)
    {
        goto missing;
    }
    m_pTagReportData = (CTagReportData *)*Cur++;


    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


EResultCode
CClientRequestOp::setTagReportData (
  CTagReportData *     pValue)
{
    removeSubParameterFromAllList(m_pTagReportData);
    delete m_pTagReportData;
    m_pTagReportData = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CClientRequestOp::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pType = &CTagReportData::s_typeDescriptor;

    pEncoderStream->putRequiredSubParameter(m_pTagReportData, pType);

}




/*
*****************************************************************
**
** Message ClientRequestOpAck
**
*****************************************************************
*/


const CTypeDescriptor
CClientRequestOpAck::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "ClientRequestOpAck",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    591,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CClientRequestOpAck::s_apFieldDescriptorTable[] =
{

    NULL
};

CClientRequestOpAck::CClientRequestOpAck (void)
{
    m_pType = &s_typeDescriptor;

    m_pClientRequestAck = NULL;
}

CClientRequestOpAck::~CClientRequestOpAck (void)
{
}


CElement *
CClientRequestOpAck::s_construct (void)
{
    return (CElement *) new CClientRequestOpAck();
}


void
CClientRequestOpAck::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CClientRequestOpAck * pTarget = (CClientRequestOpAck *) pTargetElement;


}


void
CClientRequestOpAck::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CClientRequestOpAck::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    // 1 of ClientRequestAck
    pType = &CClientRequestAck::s_typeDescriptor;

    if(Cur == End || (*Cur)->m_pType != pType)
    {
        goto missing;
    }
    m_pClientRequestAck = (CClientRequestAck *)*Cur++;


    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


EResultCode
CClientRequestOpAck::setClientRequestAck (
  CClientRequestAck *     pValue)
{
    removeSubParameterFromAllList(m_pClientRequestAck);
    delete m_pClientRequestAck;
    m_pClientRequestAck = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CClientRequestOpAck::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pType = &CClientRequestAck::s_typeDescriptor;

    pEncoderStream->putRequiredSubParameter(m_pClientRequestAck, pType);

}




/*
*****************************************************************
**
** Parameter SelectSpec
**
*****************************************************************
*/


const CTypeDescriptor
CSelectSpec::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "SelectSpec",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    400,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CSelectSpec::s_apFieldDescriptorTable[] =
{

    &s_fdSelectSpecID,
    &s_fdPriority,
    &s_fdSelectCurrentState,
    &s_fdPersistence,
    NULL
};



const CFieldDescriptor
CSelectSpec::s_fdSelectSpecID =
{
    CFieldDescriptor::FT_U32,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "SelectSpecID",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CSelectSpec::s_fdPriority =
{
    CFieldDescriptor::FT_U8,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "Priority",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CSelectSpec::s_fdSelectCurrentState =
{
    CFieldDescriptor::FT_E8,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "SelectCurrentState",	// m_pName
    g_estSelectCurrentState	// m_pEnumTable
};


const CFieldDescriptor
CSelectSpec::s_fdPersistence =
{
    CFieldDescriptor::FT_E1,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "Persistence",	// m_pName
    g_estPersistence	// m_pEnumTable
};
CSelectSpec::CSelectSpec (void)
{
    m_pType = &s_typeDescriptor;

    m_SelectSpecID = 0;
    m_Priority = 0;
    m_ESelectCurrentState = (ESelectCurrentState) 0;
    m_EPersistence = (EPersistence) 0;
    m_pSelectSpecStartTrigger = NULL;
    m_pSelectSpecStopTrigger = NULL;
    m_pSelectReportSpec = NULL;
}

CSelectSpec::~CSelectSpec (void)
{
}


CElement *
CSelectSpec::s_construct (void)
{
    return (CElement *) new CSelectSpec();
}


void
CSelectSpec::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CSelectSpec * pTarget = (CSelectSpec *) pTargetElement;


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
        pTarget->m_Priority = pDecoderStream->get_u8(&s_fdPriority);
    }
    else
    {
        pDecoderStream->get_u8(&s_fdPriority);
    }

    if(NULL != pTarget)
    {
        pTarget->m_ESelectCurrentState = (ESelectCurrentState) pDecoderStream->get_e8(&s_fdSelectCurrentState);
    }
    else
    {
        pDecoderStream->get_e8(&s_fdSelectCurrentState);
    }

    if(NULL != pTarget)
    {
        pTarget->m_EPersistence = (EPersistence) pDecoderStream->get_e1(&s_fdPersistence);
    }
    else
    {
        pDecoderStream->get_e1(&s_fdPersistence);
    }

    pDecoderStream->get_reserved(7);

}


void
CSelectSpec::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CSelectSpec::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    // 1 of SelectSpecStartTrigger
    pType = &CSelectSpecStartTrigger::s_typeDescriptor;

    if(Cur == End || (*Cur)->m_pType != pType)
    {
        goto missing;
    }
    m_pSelectSpecStartTrigger = (CSelectSpecStartTrigger *)*Cur++;


    // 1 of SelectSpecStopTrigger
    pType = &CSelectSpecStopTrigger::s_typeDescriptor;

    if(Cur == End || (*Cur)->m_pType != pType)
    {
        goto missing;
    }
    m_pSelectSpecStopTrigger = (CSelectSpecStopTrigger *)*Cur++;


    // 1-N of AntennaSpec
    pType = &CAntennaSpec::s_typeDescriptor;

    if(Cur == End || (*Cur)->m_pType != pType)
    {
        goto missing;
    }
    while(Cur != End && (*Cur)->m_pType == pType)
    {
        m_listAntennaSpec.push_back((CAntennaSpec *)*Cur);
        Cur++;
    }


    // 0-1 of SelectReportSpec
    pType = &CSelectReportSpec::s_typeDescriptor;

    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pSelectReportSpec = (CSelectReportSpec *)*Cur++;
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
CSelectSpec::setSelectSpecStartTrigger (
  CSelectSpecStartTrigger *     pValue)
{
    removeSubParameterFromAllList(m_pSelectSpecStartTrigger);
    delete m_pSelectSpecStartTrigger;
    m_pSelectSpecStartTrigger = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CSelectSpec::setSelectSpecStopTrigger (
  CSelectSpecStopTrigger *     pValue)
{
    removeSubParameterFromAllList(m_pSelectSpecStopTrigger);
    delete m_pSelectSpecStopTrigger;
    m_pSelectSpecStopTrigger = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CSelectSpec::addAntennaSpec (
  CAntennaSpec *     pValue)
{
    m_listAntennaSpec.push_back(pValue);
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CSelectSpec::setSelectReportSpec (
  CSelectReportSpec *     pValue)
{
    removeSubParameterFromAllList(m_pSelectReportSpec);
    delete m_pSelectReportSpec;
    m_pSelectReportSpec = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CSelectSpec::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u32(m_SelectSpecID, &s_fdSelectSpecID);

    pEncoderStream->put_u8(m_Priority, &s_fdPriority);

    pEncoderStream->put_e8((int)m_ESelectCurrentState, &s_fdSelectCurrentState);

    pEncoderStream->put_e1((int)m_EPersistence, &s_fdPersistence);

    pEncoderStream->put_reserved(7);

    pType = &CSelectSpecStartTrigger::s_typeDescriptor;

    pEncoderStream->putRequiredSubParameter(m_pSelectSpecStartTrigger, pType);

    pType = &CSelectSpecStopTrigger::s_typeDescriptor;

    pEncoderStream->putRequiredSubParameter(m_pSelectSpecStopTrigger, pType);

    pType = &CAntennaSpec::s_typeDescriptor;

    pEncoderStream->putRequiredSubParameterList((tListOfParameters *) &m_listAntennaSpec, pType);

    pType = &CSelectReportSpec::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameter(m_pSelectReportSpec, pType);

}




/*
*****************************************************************
**
** Parameter SelectSpecStartTrigger
**
*****************************************************************
*/


const CTypeDescriptor
CSelectSpecStartTrigger::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "SelectSpecStartTrigger",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    401,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CSelectSpecStartTrigger::s_apFieldDescriptorTable[] =
{

    &s_fdSelectSpecStartTriggerType,
    NULL
};



const CFieldDescriptor
CSelectSpecStartTrigger::s_fdSelectSpecStartTriggerType =
{
    CFieldDescriptor::FT_E8,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "SelectSpecStartTriggerType",	// m_pName
    g_estSelectSpecStartTriggerType	// m_pEnumTable
};
CSelectSpecStartTrigger::CSelectSpecStartTrigger (void)
{
    m_pType = &s_typeDescriptor;

    m_ESelectSpecStartTriggerType = (ESelectSpecStartTriggerType) 0;
    m_pPeriodicTrigger = NULL;
    m_pGPITrigger = NULL;
}

CSelectSpecStartTrigger::~CSelectSpecStartTrigger (void)
{
}


CElement *
CSelectSpecStartTrigger::s_construct (void)
{
    return (CElement *) new CSelectSpecStartTrigger();
}


void
CSelectSpecStartTrigger::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CSelectSpecStartTrigger * pTarget = (CSelectSpecStartTrigger *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_ESelectSpecStartTriggerType = (ESelectSpecStartTriggerType) pDecoderStream->get_e8(&s_fdSelectSpecStartTriggerType);
    }
    else
    {
        pDecoderStream->get_e8(&s_fdSelectSpecStartTriggerType);
    }

}


void
CSelectSpecStartTrigger::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CSelectSpecStartTrigger::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    // 0-1 of PeriodicTrigger
    pType = &CPeriodicTrigger::s_typeDescriptor;

    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pPeriodicTrigger = (CPeriodicTrigger *)*Cur++;
    }


    // 0-1 of GPITrigger
    pType = &CGPITrigger::s_typeDescriptor;

    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pGPITrigger = (CGPITrigger *)*Cur++;
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
CSelectSpecStartTrigger::setPeriodicTrigger (
  CPeriodicTrigger *     pValue)
{
    removeSubParameterFromAllList(m_pPeriodicTrigger);
    delete m_pPeriodicTrigger;
    m_pPeriodicTrigger = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CSelectSpecStartTrigger::setGPITrigger (
  CGPITrigger *     pValue)
{
    removeSubParameterFromAllList(m_pGPITrigger);
    delete m_pGPITrigger;
    m_pGPITrigger = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CSelectSpecStartTrigger::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_e8((int)m_ESelectSpecStartTriggerType, &s_fdSelectSpecStartTriggerType);

    pType = &CPeriodicTrigger::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameter(m_pPeriodicTrigger, pType);

    pType = &CGPITrigger::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameter(m_pGPITrigger, pType);

}




/*
*****************************************************************
**
** Parameter PeriodicTrigger
**
*****************************************************************
*/


const CTypeDescriptor
CPeriodicTrigger::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "PeriodicTrigger",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    402,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CPeriodicTrigger::s_apFieldDescriptorTable[] =
{

    &s_fdOffset,
    &s_fdPeriod,
    NULL
};



const CFieldDescriptor
CPeriodicTrigger::s_fdOffset =
{
    CFieldDescriptor::FT_U32,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "Offset",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CPeriodicTrigger::s_fdPeriod =
{
    CFieldDescriptor::FT_U32,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "Period",	// m_pName
    NULL	// m_pEnumTable
};
CPeriodicTrigger::CPeriodicTrigger (void)
{
    m_pType = &s_typeDescriptor;

    m_Offset = 0;
    m_Period = 0;
    m_pUTCTimestamp = NULL;
}

CPeriodicTrigger::~CPeriodicTrigger (void)
{
}


CElement *
CPeriodicTrigger::s_construct (void)
{
    return (CElement *) new CPeriodicTrigger();
}


void
CPeriodicTrigger::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CPeriodicTrigger * pTarget = (CPeriodicTrigger *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_Offset = pDecoderStream->get_u32(&s_fdOffset);
    }
    else
    {
        pDecoderStream->get_u32(&s_fdOffset);
    }

    if(NULL != pTarget)
    {
        pTarget->m_Period = pDecoderStream->get_u32(&s_fdPeriod);
    }
    else
    {
        pDecoderStream->get_u32(&s_fdPeriod);
    }

}


void
CPeriodicTrigger::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CPeriodicTrigger::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    // 0-1 of UTCTimestamp
    pType = &CUTCTimestamp::s_typeDescriptor;

    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pUTCTimestamp = (CUTCTimestamp *)*Cur++;
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
CPeriodicTrigger::setUTCTimestamp (
  CUTCTimestamp *     pValue)
{
    removeSubParameterFromAllList(m_pUTCTimestamp);
    delete m_pUTCTimestamp;
    m_pUTCTimestamp = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CPeriodicTrigger::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u32(m_Offset, &s_fdOffset);

    pEncoderStream->put_u32(m_Period, &s_fdPeriod);

    pType = &CUTCTimestamp::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameter(m_pUTCTimestamp, pType);

}




/*
*****************************************************************
**
** Parameter GPITrigger
**
*****************************************************************
*/


const CTypeDescriptor
CGPITrigger::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "GPITrigger",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    403,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CGPITrigger::s_apFieldDescriptorTable[] =
{

    &s_fdGPIPortNum,
    &s_fdGPIEvent,
    &s_fdTimeout,
    NULL
};



const CFieldDescriptor
CGPITrigger::s_fdGPIPortNum =
{
    CFieldDescriptor::FT_U8,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "GPIPortNum",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CGPITrigger::s_fdGPIEvent =
{
    CFieldDescriptor::FT_E1,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "GPIEvent",	// m_pName
    g_estGPIEvent	// m_pEnumTable
};


const CFieldDescriptor
CGPITrigger::s_fdTimeout =
{
    CFieldDescriptor::FT_U32,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "Timeout",	// m_pName
    NULL	// m_pEnumTable
};
CGPITrigger::CGPITrigger (void)
{
    m_pType = &s_typeDescriptor;

    m_GPIPortNum = 0;
    m_EGPIEvent = (EGPIEvent) 0;
    m_Timeout = 0;
}

CGPITrigger::~CGPITrigger (void)
{
}


CElement *
CGPITrigger::s_construct (void)
{
    return (CElement *) new CGPITrigger();
}


void
CGPITrigger::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CGPITrigger * pTarget = (CGPITrigger *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_GPIPortNum = pDecoderStream->get_u8(&s_fdGPIPortNum);
    }
    else
    {
        pDecoderStream->get_u8(&s_fdGPIPortNum);
    }

    if(NULL != pTarget)
    {
        pTarget->m_EGPIEvent = (EGPIEvent) pDecoderStream->get_e1(&s_fdGPIEvent);
    }
    else
    {
        pDecoderStream->get_e1(&s_fdGPIEvent);
    }

    pDecoderStream->get_reserved(7);

    if(NULL != pTarget)
    {
        pTarget->m_Timeout = pDecoderStream->get_u32(&s_fdTimeout);
    }
    else
    {
        pDecoderStream->get_u32(&s_fdTimeout);
    }

}


void
CGPITrigger::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CGPITrigger::assimilateSubParameters (
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
CGPITrigger::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u8(m_GPIPortNum, &s_fdGPIPortNum);

    pEncoderStream->put_e1((int)m_EGPIEvent, &s_fdGPIEvent);

    pEncoderStream->put_reserved(7);

    pEncoderStream->put_u32(m_Timeout, &s_fdTimeout);

}




/*
*****************************************************************
**
** Parameter SelectSpecStopTrigger
**
*****************************************************************
*/


const CTypeDescriptor
CSelectSpecStopTrigger::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "SelectSpecStopTrigger",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    404,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CSelectSpecStopTrigger::s_apFieldDescriptorTable[] =
{

    &s_fdSelectSpecStopTriggerType,
    &s_fdDurationValue,
    NULL
};



const CFieldDescriptor
CSelectSpecStopTrigger::s_fdSelectSpecStopTriggerType =
{
    CFieldDescriptor::FT_E8,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "SelectSpecStopTriggerType",	// m_pName
    g_estSelectSpecStopTriggerType	// m_pEnumTable
};


const CFieldDescriptor
CSelectSpecStopTrigger::s_fdDurationValue =
{
    CFieldDescriptor::FT_U32,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "DurationValue",	// m_pName
    NULL	// m_pEnumTable
};
CSelectSpecStopTrigger::CSelectSpecStopTrigger (void)
{
    m_pType = &s_typeDescriptor;

    m_ESelectSpecStopTriggerType = (ESelectSpecStopTriggerType) 0;
    m_DurationValue = 0;
    m_pGPITrigger = NULL;
}

CSelectSpecStopTrigger::~CSelectSpecStopTrigger (void)
{
}


CElement *
CSelectSpecStopTrigger::s_construct (void)
{
    return (CElement *) new CSelectSpecStopTrigger();
}


void
CSelectSpecStopTrigger::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CSelectSpecStopTrigger * pTarget = (CSelectSpecStopTrigger *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_ESelectSpecStopTriggerType = (ESelectSpecStopTriggerType) pDecoderStream->get_e8(&s_fdSelectSpecStopTriggerType);
    }
    else
    {
        pDecoderStream->get_e8(&s_fdSelectSpecStopTriggerType);
    }

    if(NULL != pTarget)
    {
        pTarget->m_DurationValue = pDecoderStream->get_u32(&s_fdDurationValue);
    }
    else
    {
        pDecoderStream->get_u32(&s_fdDurationValue);
    }

}


void
CSelectSpecStopTrigger::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CSelectSpecStopTrigger::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    // 0-1 of GPITrigger
    pType = &CGPITrigger::s_typeDescriptor;

    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pGPITrigger = (CGPITrigger *)*Cur++;
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
CSelectSpecStopTrigger::setGPITrigger (
  CGPITrigger *     pValue)
{
    removeSubParameterFromAllList(m_pGPITrigger);
    delete m_pGPITrigger;
    m_pGPITrigger = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CSelectSpecStopTrigger::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_e8((int)m_ESelectSpecStopTriggerType, &s_fdSelectSpecStopTriggerType);

    pEncoderStream->put_u32(m_DurationValue, &s_fdDurationValue);

    pType = &CGPITrigger::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameter(m_pGPITrigger, pType);

}




/*
*****************************************************************
**
** Parameter AntennaSpec
**
*****************************************************************
*/


const CTypeDescriptor
CAntennaSpec::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "AntennaSpec",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    405,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CAntennaSpec::s_apFieldDescriptorTable[] =
{

    &s_fdAntennaIDs,
    NULL
};



const CFieldDescriptor
CAntennaSpec::s_fdAntennaIDs =
{
    CFieldDescriptor::FT_U8V,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "AntennaIDs",	// m_pName
    NULL	// m_pEnumTable
};
CAntennaSpec::CAntennaSpec (void)
{
    m_pType = &s_typeDescriptor;

    m_pAntennaSpecStopTrigger = NULL;
}

CAntennaSpec::~CAntennaSpec (void)
{
}


CElement *
CAntennaSpec::s_construct (void)
{
    return (CElement *) new CAntennaSpec();
}


void
CAntennaSpec::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CAntennaSpec * pTarget = (CAntennaSpec *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_AntennaIDs = pDecoderStream->get_u8v(&s_fdAntennaIDs);
    }
    else
    {
        pDecoderStream->get_u8v(&s_fdAntennaIDs);
    }

}


void
CAntennaSpec::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CAntennaSpec::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    // 1 of AntennaSpecStopTrigger
    pType = &CAntennaSpecStopTrigger::s_typeDescriptor;

    if(Cur == End || (*Cur)->m_pType != pType)
    {
        goto missing;
    }
    m_pAntennaSpecStopTrigger = (CAntennaSpecStopTrigger *)*Cur++;


    // 1-N of RfSpec
    pType = &CRfSpec::s_typeDescriptor;

    if(Cur == End || (*Cur)->m_pType != pType)
    {
        goto missing;
    }
    while(Cur != End && (*Cur)->m_pType == pType)
    {
        m_listRfSpec.push_back((CRfSpec *)*Cur);
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
CAntennaSpec::setAntennaSpecStopTrigger (
  CAntennaSpecStopTrigger *     pValue)
{
    removeSubParameterFromAllList(m_pAntennaSpecStopTrigger);
    delete m_pAntennaSpecStopTrigger;
    m_pAntennaSpecStopTrigger = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CAntennaSpec::addRfSpec (
  CRfSpec *     pValue)
{
    m_listRfSpec.push_back(pValue);
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CAntennaSpec::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u8v(m_AntennaIDs, &s_fdAntennaIDs);

    pType = &CAntennaSpecStopTrigger::s_typeDescriptor;

    pEncoderStream->putRequiredSubParameter(m_pAntennaSpecStopTrigger, pType);

    pType = &CRfSpec::s_typeDescriptor;

    pEncoderStream->putRequiredSubParameterList((tListOfParameters *) &m_listRfSpec, pType);

}




/*
*****************************************************************
**
** Parameter AntennaSpecStopTrigger
**
*****************************************************************
*/


const CTypeDescriptor
CAntennaSpecStopTrigger::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "AntennaSpecStopTrigger",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    406,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CAntennaSpecStopTrigger::s_apFieldDescriptorTable[] =
{

    &s_fdAntennaSpecStopTriggerType,
    &s_fdDurationValue,
    NULL
};



const CFieldDescriptor
CAntennaSpecStopTrigger::s_fdAntennaSpecStopTriggerType =
{
    CFieldDescriptor::FT_E8,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "AntennaSpecStopTriggerType",	// m_pName
    g_estAntennaSpecStopTriggerType	// m_pEnumTable
};


const CFieldDescriptor
CAntennaSpecStopTrigger::s_fdDurationValue =
{
    CFieldDescriptor::FT_U32,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "DurationValue",	// m_pName
    NULL	// m_pEnumTable
};
CAntennaSpecStopTrigger::CAntennaSpecStopTrigger (void)
{
    m_pType = &s_typeDescriptor;

    m_EAntennaSpecStopTriggerType = (EAntennaSpecStopTriggerType) 0;
    m_DurationValue = 0;
    m_pGPITrigger = NULL;
    m_pTagObservationTrigger = NULL;
}

CAntennaSpecStopTrigger::~CAntennaSpecStopTrigger (void)
{
}


CElement *
CAntennaSpecStopTrigger::s_construct (void)
{
    return (CElement *) new CAntennaSpecStopTrigger();
}


void
CAntennaSpecStopTrigger::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CAntennaSpecStopTrigger * pTarget = (CAntennaSpecStopTrigger *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_EAntennaSpecStopTriggerType = (EAntennaSpecStopTriggerType) pDecoderStream->get_e8(&s_fdAntennaSpecStopTriggerType);
    }
    else
    {
        pDecoderStream->get_e8(&s_fdAntennaSpecStopTriggerType);
    }

    if(NULL != pTarget)
    {
        pTarget->m_DurationValue = pDecoderStream->get_u32(&s_fdDurationValue);
    }
    else
    {
        pDecoderStream->get_u32(&s_fdDurationValue);
    }

}


void
CAntennaSpecStopTrigger::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CAntennaSpecStopTrigger::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    // 0-1 of GPITrigger
    pType = &CGPITrigger::s_typeDescriptor;

    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pGPITrigger = (CGPITrigger *)*Cur++;
    }


    // 0-1 of TagObservationTrigger
    pType = &CTagObservationTrigger::s_typeDescriptor;

    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pTagObservationTrigger = (CTagObservationTrigger *)*Cur++;
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
CAntennaSpecStopTrigger::setGPITrigger (
  CGPITrigger *     pValue)
{
    removeSubParameterFromAllList(m_pGPITrigger);
    delete m_pGPITrigger;
    m_pGPITrigger = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CAntennaSpecStopTrigger::setTagObservationTrigger (
  CTagObservationTrigger *     pValue)
{
    removeSubParameterFromAllList(m_pTagObservationTrigger);
    delete m_pTagObservationTrigger;
    m_pTagObservationTrigger = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CAntennaSpecStopTrigger::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_e8((int)m_EAntennaSpecStopTriggerType, &s_fdAntennaSpecStopTriggerType);

    pEncoderStream->put_u32(m_DurationValue, &s_fdDurationValue);

    pType = &CGPITrigger::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameter(m_pGPITrigger, pType);

    pType = &CTagObservationTrigger::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameter(m_pTagObservationTrigger, pType);

}




/*
*****************************************************************
**
** Parameter TagObservationTrigger
**
*****************************************************************
*/


const CTypeDescriptor
CTagObservationTrigger::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "TagObservationTrigger",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    407,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CTagObservationTrigger::s_apFieldDescriptorTable[] =
{

    &s_fdTriggerType,
    &s_fdNumberOfTags,
    &s_fdNumberOfAttempts,
    &s_fdTValue,
    &s_fdTimeout,
    NULL
};



const CFieldDescriptor
CTagObservationTrigger::s_fdTriggerType =
{
    CFieldDescriptor::FT_E8,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "TriggerType",	// m_pName
    g_estTriggerType	// m_pEnumTable
};


const CFieldDescriptor
CTagObservationTrigger::s_fdNumberOfTags =
{
    CFieldDescriptor::FT_U16,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "NumberOfTags",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CTagObservationTrigger::s_fdNumberOfAttempts =
{
    CFieldDescriptor::FT_U16,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "NumberOfAttempts",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CTagObservationTrigger::s_fdTValue =
{
    CFieldDescriptor::FT_U16,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "TValue",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CTagObservationTrigger::s_fdTimeout =
{
    CFieldDescriptor::FT_U32,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "Timeout",	// m_pName
    NULL	// m_pEnumTable
};
CTagObservationTrigger::CTagObservationTrigger (void)
{
    m_pType = &s_typeDescriptor;

    m_ETriggerType = (ETriggerType) 0;
    m_NumberOfTags = 0;
    m_NumberOfAttempts = 0;
    m_TValue = 0;
    m_Timeout = 0;
}

CTagObservationTrigger::~CTagObservationTrigger (void)
{
}


CElement *
CTagObservationTrigger::s_construct (void)
{
    return (CElement *) new CTagObservationTrigger();
}


void
CTagObservationTrigger::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CTagObservationTrigger * pTarget = (CTagObservationTrigger *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_ETriggerType = (ETriggerType) pDecoderStream->get_e8(&s_fdTriggerType);
    }
    else
    {
        pDecoderStream->get_e8(&s_fdTriggerType);
    }

    if(NULL != pTarget)
    {
        pTarget->m_NumberOfTags = pDecoderStream->get_u16(&s_fdNumberOfTags);
    }
    else
    {
        pDecoderStream->get_u16(&s_fdNumberOfTags);
    }

    if(NULL != pTarget)
    {
        pTarget->m_NumberOfAttempts = pDecoderStream->get_u16(&s_fdNumberOfAttempts);
    }
    else
    {
        pDecoderStream->get_u16(&s_fdNumberOfAttempts);
    }

    if(NULL != pTarget)
    {
        pTarget->m_TValue = pDecoderStream->get_u16(&s_fdTValue);
    }
    else
    {
        pDecoderStream->get_u16(&s_fdTValue);
    }

    if(NULL != pTarget)
    {
        pTarget->m_Timeout = pDecoderStream->get_u32(&s_fdTimeout);
    }
    else
    {
        pDecoderStream->get_u32(&s_fdTimeout);
    }

}


void
CTagObservationTrigger::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CTagObservationTrigger::assimilateSubParameters (
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
CTagObservationTrigger::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_e8((int)m_ETriggerType, &s_fdTriggerType);

    pEncoderStream->put_u16(m_NumberOfTags, &s_fdNumberOfTags);

    pEncoderStream->put_u16(m_NumberOfAttempts, &s_fdNumberOfAttempts);

    pEncoderStream->put_u16(m_TValue, &s_fdTValue);

    pEncoderStream->put_u32(m_Timeout, &s_fdTimeout);

}




/*
*****************************************************************
**
** Parameter RfSpec
**
*****************************************************************
*/


const CTypeDescriptor
CRfSpec::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "RfSpec",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    408,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CRfSpec::s_apFieldDescriptorTable[] =
{

    &s_fdRfSpecID,
    &s_fdProtocolID,
    &s_fdSelectType,
    NULL
};



const CFieldDescriptor
CRfSpec::s_fdRfSpecID =
{
    CFieldDescriptor::FT_U16,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "RfSpecID",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CRfSpec::s_fdProtocolID =
{
    CFieldDescriptor::FT_E8,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "ProtocolID",	// m_pName
    g_estProtocolID	// m_pEnumTable
};


const CFieldDescriptor
CRfSpec::s_fdSelectType =
{
    CFieldDescriptor::FT_E8,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "SelectType",	// m_pName
    g_estSelectType	// m_pEnumTable
};
CRfSpec::CRfSpec (void)
{
    m_pType = &s_typeDescriptor;

    m_RfSpecID = 0;
    m_EProtocolID = (EProtocolID) 0;
    m_ESelectType = (ESelectType) 0;
    m_pMemoryBank = NULL;
}

CRfSpec::~CRfSpec (void)
{
}


CElement *
CRfSpec::s_construct (void)
{
    return (CElement *) new CRfSpec();
}


void
CRfSpec::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CRfSpec * pTarget = (CRfSpec *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_RfSpecID = pDecoderStream->get_u16(&s_fdRfSpecID);
    }
    else
    {
        pDecoderStream->get_u16(&s_fdRfSpecID);
    }

    if(NULL != pTarget)
    {
        pTarget->m_EProtocolID = (EProtocolID) pDecoderStream->get_e8(&s_fdProtocolID);
    }
    else
    {
        pDecoderStream->get_e8(&s_fdProtocolID);
    }

    if(NULL != pTarget)
    {
        pTarget->m_ESelectType = (ESelectType) pDecoderStream->get_e8(&s_fdSelectType);
    }
    else
    {
        pDecoderStream->get_e8(&s_fdSelectType);
    }

}


void
CRfSpec::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CRfSpec::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    // 0-1 of MemoryBank
    pType = &CMemoryBank::s_typeDescriptor;

    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pMemoryBank = (CMemoryBank *)*Cur++;
    }


    // 0-N of AntennaConfiguration
    pType = &CAntennaConfiguration::s_typeDescriptor;

    while(Cur != End && (*Cur)->m_pType == pType)
    {
        m_listAntennaConfiguration.push_back((CAntennaConfiguration *)*Cur);
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
CRfSpec::setMemoryBank (
  CMemoryBank *     pValue)
{
    removeSubParameterFromAllList(m_pMemoryBank);
    delete m_pMemoryBank;
    m_pMemoryBank = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CRfSpec::addAntennaConfiguration (
  CAntennaConfiguration *     pValue)
{
    m_listAntennaConfiguration.push_back(pValue);
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CRfSpec::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u16(m_RfSpecID, &s_fdRfSpecID);

    pEncoderStream->put_e8((int)m_EProtocolID, &s_fdProtocolID);

    pEncoderStream->put_e8((int)m_ESelectType, &s_fdSelectType);

    pType = &CMemoryBank::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameter(m_pMemoryBank, pType);

    pType = &CAntennaConfiguration::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameterList((tListOfParameters *) &m_listAntennaConfiguration, pType);

}




/*
*****************************************************************
**
** Parameter MemoryBank
**
*****************************************************************
*/


const CTypeDescriptor
CMemoryBank::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "MemoryBank",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    409,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CMemoryBank::s_apFieldDescriptorTable[] =
{

    &s_fdMemoryBankID,
    &s_fdReadType,
    &s_fdPointer,
    &s_fdCount,
    &s_fdBankType,
    NULL
};



const CFieldDescriptor
CMemoryBank::s_fdMemoryBankID =
{
    CFieldDescriptor::FT_U8,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "MemoryBankID",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CMemoryBank::s_fdReadType =
{
    CFieldDescriptor::FT_U8,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "ReadType",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CMemoryBank::s_fdPointer =
{
    CFieldDescriptor::FT_U16,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "Pointer",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CMemoryBank::s_fdCount =
{
    CFieldDescriptor::FT_U16,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "Count",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CMemoryBank::s_fdBankType =
{
    CFieldDescriptor::FT_U8,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "BankType",	// m_pName
    NULL	// m_pEnumTable
};
CMemoryBank::CMemoryBank (void)
{
    m_pType = &s_typeDescriptor;

    m_MemoryBankID = 0;
    m_ReadType = 0;
    m_Pointer = 0;
    m_Count = 0;
    m_BankType = 0;
}

CMemoryBank::~CMemoryBank (void)
{
}


CElement *
CMemoryBank::s_construct (void)
{
    return (CElement *) new CMemoryBank();
}


void
CMemoryBank::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CMemoryBank * pTarget = (CMemoryBank *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_MemoryBankID = pDecoderStream->get_u8(&s_fdMemoryBankID);
    }
    else
    {
        pDecoderStream->get_u8(&s_fdMemoryBankID);
    }

    if(NULL != pTarget)
    {
        pTarget->m_ReadType = pDecoderStream->get_u8(&s_fdReadType);
    }
    else
    {
        pDecoderStream->get_u8(&s_fdReadType);
    }

    if(NULL != pTarget)
    {
        pTarget->m_Pointer = pDecoderStream->get_u16(&s_fdPointer);
    }
    else
    {
        pDecoderStream->get_u16(&s_fdPointer);
    }

    if(NULL != pTarget)
    {
        pTarget->m_Count = pDecoderStream->get_u16(&s_fdCount);
    }
    else
    {
        pDecoderStream->get_u16(&s_fdCount);
    }

    if(NULL != pTarget)
    {
        pTarget->m_BankType = pDecoderStream->get_u8(&s_fdBankType);
    }
    else
    {
        pDecoderStream->get_u8(&s_fdBankType);
    }

}


void
CMemoryBank::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CMemoryBank::assimilateSubParameters (
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
CMemoryBank::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u8(m_MemoryBankID, &s_fdMemoryBankID);

    pEncoderStream->put_u8(m_ReadType, &s_fdReadType);

    pEncoderStream->put_u16(m_Pointer, &s_fdPointer);

    pEncoderStream->put_u16(m_Count, &s_fdCount);

    pEncoderStream->put_u8(m_BankType, &s_fdBankType);

}




/*
*****************************************************************
**
** Parameter SelectReportSpec
**
*****************************************************************
*/


const CTypeDescriptor
CSelectReportSpec::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "SelectReportSpec",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    410,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CSelectReportSpec::s_apFieldDescriptorTable[] =
{

    &s_fdSelectReportTrigger,
    &s_fdNValue,
    &s_fdEnableSelectSpecID,
    &s_fdEnableSpecIndex,
    &s_fdEnableRfSpecID,
    &s_fdEnableAntennaID,
    &s_fdEnablePeakRSSI,
    &s_fdEnableFirstSeenTimestamp,
    &s_fdEnableLastSeenTimestamp,
    &s_fdEnableTagSeenCount,
    &s_fdEnableAccessSpecID,
    NULL
};



const CFieldDescriptor
CSelectReportSpec::s_fdSelectReportTrigger =
{
    CFieldDescriptor::FT_E8,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "SelectReportTrigger",	// m_pName
    g_estSelectReportTrigger	// m_pEnumTable
};


const CFieldDescriptor
CSelectReportSpec::s_fdNValue =
{
    CFieldDescriptor::FT_U16,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "NValue",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CSelectReportSpec::s_fdEnableSelectSpecID =
{
    CFieldDescriptor::FT_U1,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "EnableSelectSpecID",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CSelectReportSpec::s_fdEnableSpecIndex =
{
    CFieldDescriptor::FT_U1,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "EnableSpecIndex",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CSelectReportSpec::s_fdEnableRfSpecID =
{
    CFieldDescriptor::FT_U1,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "EnableRfSpecID",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CSelectReportSpec::s_fdEnableAntennaID =
{
    CFieldDescriptor::FT_U1,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "EnableAntennaID",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CSelectReportSpec::s_fdEnablePeakRSSI =
{
    CFieldDescriptor::FT_U1,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "EnablePeakRSSI",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CSelectReportSpec::s_fdEnableFirstSeenTimestamp =
{
    CFieldDescriptor::FT_U1,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "EnableFirstSeenTimestamp",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CSelectReportSpec::s_fdEnableLastSeenTimestamp =
{
    CFieldDescriptor::FT_U1,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "EnableLastSeenTimestamp",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CSelectReportSpec::s_fdEnableTagSeenCount =
{
    CFieldDescriptor::FT_U1,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "EnableTagSeenCount",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CSelectReportSpec::s_fdEnableAccessSpecID =
{
    CFieldDescriptor::FT_U1,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "EnableAccessSpecID",	// m_pName
    NULL	// m_pEnumTable
};
CSelectReportSpec::CSelectReportSpec (void)
{
    m_pType = &s_typeDescriptor;

    m_ESelectReportTrigger = (ESelectReportTrigger) 0;
    m_NValue = 0;
    m_EnableSelectSpecID = 0;
    m_EnableSpecIndex = 0;
    m_EnableRfSpecID = 0;
    m_EnableAntennaID = 0;
    m_EnablePeakRSSI = 0;
    m_EnableFirstSeenTimestamp = 0;
    m_EnableLastSeenTimestamp = 0;
    m_EnableTagSeenCount = 0;
    m_EnableAccessSpecID = 0;
    m_pReportDestination = NULL;
}

CSelectReportSpec::~CSelectReportSpec (void)
{
}


CElement *
CSelectReportSpec::s_construct (void)
{
    return (CElement *) new CSelectReportSpec();
}


void
CSelectReportSpec::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CSelectReportSpec * pTarget = (CSelectReportSpec *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_ESelectReportTrigger = (ESelectReportTrigger) pDecoderStream->get_e8(&s_fdSelectReportTrigger);
    }
    else
    {
        pDecoderStream->get_e8(&s_fdSelectReportTrigger);
    }

    if(NULL != pTarget)
    {
        pTarget->m_NValue = pDecoderStream->get_u16(&s_fdNValue);
    }
    else
    {
        pDecoderStream->get_u16(&s_fdNValue);
    }

    if(NULL != pTarget)
    {
        pTarget->m_EnableSelectSpecID = pDecoderStream->get_u1(&s_fdEnableSelectSpecID);
    }
    else
    {
        pDecoderStream->get_u1(&s_fdEnableSelectSpecID);
    }

    if(NULL != pTarget)
    {
        pTarget->m_EnableSpecIndex = pDecoderStream->get_u1(&s_fdEnableSpecIndex);
    }
    else
    {
        pDecoderStream->get_u1(&s_fdEnableSpecIndex);
    }

    if(NULL != pTarget)
    {
        pTarget->m_EnableRfSpecID = pDecoderStream->get_u1(&s_fdEnableRfSpecID);
    }
    else
    {
        pDecoderStream->get_u1(&s_fdEnableRfSpecID);
    }

    if(NULL != pTarget)
    {
        pTarget->m_EnableAntennaID = pDecoderStream->get_u1(&s_fdEnableAntennaID);
    }
    else
    {
        pDecoderStream->get_u1(&s_fdEnableAntennaID);
    }

    if(NULL != pTarget)
    {
        pTarget->m_EnablePeakRSSI = pDecoderStream->get_u1(&s_fdEnablePeakRSSI);
    }
    else
    {
        pDecoderStream->get_u1(&s_fdEnablePeakRSSI);
    }

    if(NULL != pTarget)
    {
        pTarget->m_EnableFirstSeenTimestamp = pDecoderStream->get_u1(&s_fdEnableFirstSeenTimestamp);
    }
    else
    {
        pDecoderStream->get_u1(&s_fdEnableFirstSeenTimestamp);
    }

    if(NULL != pTarget)
    {
        pTarget->m_EnableLastSeenTimestamp = pDecoderStream->get_u1(&s_fdEnableLastSeenTimestamp);
    }
    else
    {
        pDecoderStream->get_u1(&s_fdEnableLastSeenTimestamp);
    }

    if(NULL != pTarget)
    {
        pTarget->m_EnableTagSeenCount = pDecoderStream->get_u1(&s_fdEnableTagSeenCount);
    }
    else
    {
        pDecoderStream->get_u1(&s_fdEnableTagSeenCount);
    }

    if(NULL != pTarget)
    {
        pTarget->m_EnableAccessSpecID = pDecoderStream->get_u1(&s_fdEnableAccessSpecID);
    }
    else
    {
        pDecoderStream->get_u1(&s_fdEnableAccessSpecID);
    }

    pDecoderStream->get_reserved(7);

}


void
CSelectReportSpec::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CSelectReportSpec::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    // 0-1 of ReportDestination
    pType = &CReportDestination::s_typeDescriptor;

    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pReportDestination = (CReportDestination *)*Cur++;
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
CSelectReportSpec::setReportDestination (
  CReportDestination *     pValue)
{
    removeSubParameterFromAllList(m_pReportDestination);
    delete m_pReportDestination;
    m_pReportDestination = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CSelectReportSpec::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_e8((int)m_ESelectReportTrigger, &s_fdSelectReportTrigger);

    pEncoderStream->put_u16(m_NValue, &s_fdNValue);

    pEncoderStream->put_u1(m_EnableSelectSpecID, &s_fdEnableSelectSpecID);

    pEncoderStream->put_u1(m_EnableSpecIndex, &s_fdEnableSpecIndex);

    pEncoderStream->put_u1(m_EnableRfSpecID, &s_fdEnableRfSpecID);

    pEncoderStream->put_u1(m_EnableAntennaID, &s_fdEnableAntennaID);

    pEncoderStream->put_u1(m_EnablePeakRSSI, &s_fdEnablePeakRSSI);

    pEncoderStream->put_u1(m_EnableFirstSeenTimestamp, &s_fdEnableFirstSeenTimestamp);

    pEncoderStream->put_u1(m_EnableLastSeenTimestamp, &s_fdEnableLastSeenTimestamp);

    pEncoderStream->put_u1(m_EnableTagSeenCount, &s_fdEnableTagSeenCount);

    pEncoderStream->put_u1(m_EnableAccessSpecID, &s_fdEnableAccessSpecID);

    pEncoderStream->put_reserved(7);

    pType = &CReportDestination::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameter(m_pReportDestination, pType);

}




/*
*****************************************************************
**
** Parameter ReportDestination
**
*****************************************************************
*/


const CTypeDescriptor
CReportDestination::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "ReportDestination",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    411,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CReportDestination::s_apFieldDescriptorTable[] =
{

    NULL
};

CReportDestination::CReportDestination (void)
{
    m_pType = &s_typeDescriptor;

}

CReportDestination::~CReportDestination (void)
{
}


CElement *
CReportDestination::s_construct (void)
{
    return (CElement *) new CReportDestination();
}


void
CReportDestination::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CReportDestination * pTarget = (CReportDestination *) pTargetElement;


}


void
CReportDestination::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CReportDestination::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    // 1-N of CommLinkConfiguration
    pType = &CCommLinkConfiguration::s_typeDescriptor;

    if(Cur == End || (*Cur)->m_pType != pType)
    {
        goto missing;
    }
    while(Cur != End && (*Cur)->m_pType == pType)
    {
        m_listCommLinkConfiguration.push_back((CCommLinkConfiguration *)*Cur);
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
CReportDestination::addCommLinkConfiguration (
  CCommLinkConfiguration *     pValue)
{
    m_listCommLinkConfiguration.push_back(pValue);
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CReportDestination::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pType = &CCommLinkConfiguration::s_typeDescriptor;

    pEncoderStream->putRequiredSubParameterList((tListOfParameters *) &m_listCommLinkConfiguration, pType);

}




/*
*****************************************************************
**
** Parameter AccessSpec
**
*****************************************************************
*/


const CTypeDescriptor
CAccessSpec::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "AccessSpec",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    450,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CAccessSpec::s_apFieldDescriptorTable[] =
{

    &s_fdAccessSpecID,
    &s_fdSelectSpecID,
    &s_fdAntennaID,
    &s_fdProtocolID,
    &s_fdAccessCurrentState,
    &s_fdPersistence,
    NULL
};



const CFieldDescriptor
CAccessSpec::s_fdAccessSpecID =
{
    CFieldDescriptor::FT_U32,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "AccessSpecID",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CAccessSpec::s_fdSelectSpecID =
{
    CFieldDescriptor::FT_U32,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "SelectSpecID",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CAccessSpec::s_fdAntennaID =
{
    CFieldDescriptor::FT_U8,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "AntennaID",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CAccessSpec::s_fdProtocolID =
{
    CFieldDescriptor::FT_E8,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "ProtocolID",	// m_pName
    g_estProtocolID	// m_pEnumTable
};


const CFieldDescriptor
CAccessSpec::s_fdAccessCurrentState =
{
    CFieldDescriptor::FT_E1,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "AccessCurrentState",	// m_pName
    g_estAccessCurrentState	// m_pEnumTable
};


const CFieldDescriptor
CAccessSpec::s_fdPersistence =
{
    CFieldDescriptor::FT_E1,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "Persistence",	// m_pName
    g_estPersistence	// m_pEnumTable
};
CAccessSpec::CAccessSpec (void)
{
    m_pType = &s_typeDescriptor;

    m_AccessSpecID = 0;
    m_SelectSpecID = 0;
    m_AntennaID = 0;
    m_EProtocolID = (EProtocolID) 0;
    m_EAccessCurrentState = (EAccessCurrentState) 0;
    m_EPersistence = (EPersistence) 0;
    m_pAccessSpecStopTrigger = NULL;
    m_pAccessCommand = NULL;
    m_pAccessReportSpec = NULL;
}

CAccessSpec::~CAccessSpec (void)
{
}


CElement *
CAccessSpec::s_construct (void)
{
    return (CElement *) new CAccessSpec();
}


void
CAccessSpec::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CAccessSpec * pTarget = (CAccessSpec *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_AccessSpecID = pDecoderStream->get_u32(&s_fdAccessSpecID);
    }
    else
    {
        pDecoderStream->get_u32(&s_fdAccessSpecID);
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
        pTarget->m_AntennaID = pDecoderStream->get_u8(&s_fdAntennaID);
    }
    else
    {
        pDecoderStream->get_u8(&s_fdAntennaID);
    }

    if(NULL != pTarget)
    {
        pTarget->m_EProtocolID = (EProtocolID) pDecoderStream->get_e8(&s_fdProtocolID);
    }
    else
    {
        pDecoderStream->get_e8(&s_fdProtocolID);
    }

    if(NULL != pTarget)
    {
        pTarget->m_EAccessCurrentState = (EAccessCurrentState) pDecoderStream->get_e1(&s_fdAccessCurrentState);
    }
    else
    {
        pDecoderStream->get_e1(&s_fdAccessCurrentState);
    }

    if(NULL != pTarget)
    {
        pTarget->m_EPersistence = (EPersistence) pDecoderStream->get_e1(&s_fdPersistence);
    }
    else
    {
        pDecoderStream->get_e1(&s_fdPersistence);
    }

    pDecoderStream->get_reserved(6);

}


void
CAccessSpec::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CAccessSpec::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    // 1 of AccessSpecStopTrigger
    pType = &CAccessSpecStopTrigger::s_typeDescriptor;

    if(Cur == End || (*Cur)->m_pType != pType)
    {
        goto missing;
    }
    m_pAccessSpecStopTrigger = (CAccessSpecStopTrigger *)*Cur++;


    // 1 of AccessCommand
    pType = &CAccessCommand::s_typeDescriptor;

    if(Cur == End || (*Cur)->m_pType != pType)
    {
        goto missing;
    }
    m_pAccessCommand = (CAccessCommand *)*Cur++;


    // 0-1 of AccessReportSpec
    pType = &CAccessReportSpec::s_typeDescriptor;

    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pAccessReportSpec = (CAccessReportSpec *)*Cur++;
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
CAccessSpec::setAccessSpecStopTrigger (
  CAccessSpecStopTrigger *     pValue)
{
    removeSubParameterFromAllList(m_pAccessSpecStopTrigger);
    delete m_pAccessSpecStopTrigger;
    m_pAccessSpecStopTrigger = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CAccessSpec::setAccessCommand (
  CAccessCommand *     pValue)
{
    removeSubParameterFromAllList(m_pAccessCommand);
    delete m_pAccessCommand;
    m_pAccessCommand = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CAccessSpec::setAccessReportSpec (
  CAccessReportSpec *     pValue)
{
    removeSubParameterFromAllList(m_pAccessReportSpec);
    delete m_pAccessReportSpec;
    m_pAccessReportSpec = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CAccessSpec::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u32(m_AccessSpecID, &s_fdAccessSpecID);

    pEncoderStream->put_u32(m_SelectSpecID, &s_fdSelectSpecID);

    pEncoderStream->put_u8(m_AntennaID, &s_fdAntennaID);

    pEncoderStream->put_e8((int)m_EProtocolID, &s_fdProtocolID);

    pEncoderStream->put_e1((int)m_EAccessCurrentState, &s_fdAccessCurrentState);

    pEncoderStream->put_e1((int)m_EPersistence, &s_fdPersistence);

    pEncoderStream->put_reserved(6);

    pType = &CAccessSpecStopTrigger::s_typeDescriptor;

    pEncoderStream->putRequiredSubParameter(m_pAccessSpecStopTrigger, pType);

    pType = &CAccessCommand::s_typeDescriptor;

    pEncoderStream->putRequiredSubParameter(m_pAccessCommand, pType);

    pType = &CAccessReportSpec::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameter(m_pAccessReportSpec, pType);

}




/*
*****************************************************************
**
** Parameter AccessSpecStopTrigger
**
*****************************************************************
*/


const CTypeDescriptor
CAccessSpecStopTrigger::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "AccessSpecStopTrigger",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    451,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CAccessSpecStopTrigger::s_apFieldDescriptorTable[] =
{

    &s_fdAccessSpecStopTriggerType,
    &s_fdOperationCountValue,
    NULL
};



const CFieldDescriptor
CAccessSpecStopTrigger::s_fdAccessSpecStopTriggerType =
{
    CFieldDescriptor::FT_E8,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "AccessSpecStopTriggerType",	// m_pName
    g_estAccessSpecStopTriggerType	// m_pEnumTable
};


const CFieldDescriptor
CAccessSpecStopTrigger::s_fdOperationCountValue =
{
    CFieldDescriptor::FT_U16,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "OperationCountValue",	// m_pName
    NULL	// m_pEnumTable
};
CAccessSpecStopTrigger::CAccessSpecStopTrigger (void)
{
    m_pType = &s_typeDescriptor;

    m_EAccessSpecStopTriggerType = (EAccessSpecStopTriggerType) 0;
    m_OperationCountValue = 0;
}

CAccessSpecStopTrigger::~CAccessSpecStopTrigger (void)
{
}


CElement *
CAccessSpecStopTrigger::s_construct (void)
{
    return (CElement *) new CAccessSpecStopTrigger();
}


void
CAccessSpecStopTrigger::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CAccessSpecStopTrigger * pTarget = (CAccessSpecStopTrigger *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_EAccessSpecStopTriggerType = (EAccessSpecStopTriggerType) pDecoderStream->get_e8(&s_fdAccessSpecStopTriggerType);
    }
    else
    {
        pDecoderStream->get_e8(&s_fdAccessSpecStopTriggerType);
    }

    if(NULL != pTarget)
    {
        pTarget->m_OperationCountValue = pDecoderStream->get_u16(&s_fdOperationCountValue);
    }
    else
    {
        pDecoderStream->get_u16(&s_fdOperationCountValue);
    }

}


void
CAccessSpecStopTrigger::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CAccessSpecStopTrigger::assimilateSubParameters (
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
CAccessSpecStopTrigger::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_e8((int)m_EAccessSpecStopTriggerType, &s_fdAccessSpecStopTriggerType);

    pEncoderStream->put_u16(m_OperationCountValue, &s_fdOperationCountValue);

}




/*
*****************************************************************
**
** Parameter AccessCommand
**
*****************************************************************
*/


const CTypeDescriptor
CAccessCommand::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "AccessCommand",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    452,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CAccessCommand::s_apFieldDescriptorTable[] =
{

    NULL
};

CAccessCommand::CAccessCommand (void)
{
    m_pType = &s_typeDescriptor;

    m_pHbMatchSpec = NULL;
    m_pSecurityModuleSpec = NULL;
}

CAccessCommand::~CAccessCommand (void)
{
}


CElement *
CAccessCommand::s_construct (void)
{
    return (CElement *) new CAccessCommand();
}


void
CAccessCommand::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CAccessCommand * pTarget = (CAccessCommand *) pTargetElement;


}


void
CAccessCommand::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CAccessCommand::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    // 1 of HbMatchSpec
    pType = &CHbMatchSpec::s_typeDescriptor;

    if(Cur == End || (*Cur)->m_pType != pType)
    {
        goto missing;
    }
    m_pHbMatchSpec = (CHbMatchSpec *)*Cur++;


    // 1-N of choice OpSpec
    pType = NULL;

    if(Cur == End || !COpSpec::isMember(*Cur))
    {
        goto missing;
    }
    while(Cur != End && COpSpec::isMember(*Cur))
    {
        m_listOpSpec.push_back(*Cur);
        Cur++;
    }


    // 0-1 of SecurityModuleSpec
    pType = &CSecurityModuleSpec::s_typeDescriptor;

    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pSecurityModuleSpec = (CSecurityModuleSpec *)*Cur++;
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
CAccessCommand::setHbMatchSpec (
  CHbMatchSpec *     pValue)
{
    removeSubParameterFromAllList(m_pHbMatchSpec);
    delete m_pHbMatchSpec;
    m_pHbMatchSpec = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CAccessCommand::addOpSpec (
  CParameter *                  pValue)
{
    if(!COpSpec::isMember(pValue))
    {
        return RC_InvalidChoiceMember;
    }

    m_listOpSpec.push_back(pValue);
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CAccessCommand::setSecurityModuleSpec (
  CSecurityModuleSpec *     pValue)
{
    removeSubParameterFromAllList(m_pSecurityModuleSpec);
    delete m_pSecurityModuleSpec;
    m_pSecurityModuleSpec = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CAccessCommand::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pType = &CHbMatchSpec::s_typeDescriptor;

    pEncoderStream->putRequiredSubParameter(m_pHbMatchSpec, pType);

    pType = NULL;

    pEncoderStream->putRequiredSubParameterList((tListOfParameters *) &m_listOpSpec, pType);

    pType = &CSecurityModuleSpec::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameter(m_pSecurityModuleSpec, pType);

}




/*
*****************************************************************
**
** Parameter SecurityModuleSpec
**
*****************************************************************
*/


const CTypeDescriptor
CSecurityModuleSpec::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "SecurityModuleSpec",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    460,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CSecurityModuleSpec::s_apFieldDescriptorTable[] =
{

    NULL
};

CSecurityModuleSpec::CSecurityModuleSpec (void)
{
    m_pType = &s_typeDescriptor;

    m_pReadMode = NULL;
}

CSecurityModuleSpec::~CSecurityModuleSpec (void)
{
}


CElement *
CSecurityModuleSpec::s_construct (void)
{
    return (CElement *) new CSecurityModuleSpec();
}


void
CSecurityModuleSpec::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CSecurityModuleSpec * pTarget = (CSecurityModuleSpec *) pTargetElement;


}


void
CSecurityModuleSpec::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CSecurityModuleSpec::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    // 1 of ReadMode
    pType = &CReadMode::s_typeDescriptor;

    if(Cur == End || (*Cur)->m_pType != pType)
    {
        goto missing;
    }
    m_pReadMode = (CReadMode *)*Cur++;


    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


EResultCode
CSecurityModuleSpec::setReadMode (
  CReadMode *     pValue)
{
    removeSubParameterFromAllList(m_pReadMode);
    delete m_pReadMode;
    m_pReadMode = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CSecurityModuleSpec::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pType = &CReadMode::s_typeDescriptor;

    pEncoderStream->putRequiredSubParameter(m_pReadMode, pType);

}




/*
*****************************************************************
**
** Parameter HbMatchSpec
**
*****************************************************************
*/


const CTypeDescriptor
CHbMatchSpec::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "HbMatchSpec",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    453,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CHbMatchSpec::s_apFieldDescriptorTable[] =
{

    NULL
};

CHbMatchSpec::CHbMatchSpec (void)
{
    m_pType = &s_typeDescriptor;

}

CHbMatchSpec::~CHbMatchSpec (void)
{
}


CElement *
CHbMatchSpec::s_construct (void)
{
    return (CElement *) new CHbMatchSpec();
}


void
CHbMatchSpec::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CHbMatchSpec * pTarget = (CHbMatchSpec *) pTargetElement;


}


void
CHbMatchSpec::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CHbMatchSpec::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    // 1-N of HbTargetTag
    pType = &CHbTargetTag::s_typeDescriptor;

    if(Cur == End || (*Cur)->m_pType != pType)
    {
        goto missing;
    }
    while(Cur != End && (*Cur)->m_pType == pType)
    {
        m_listHbTargetTag.push_back((CHbTargetTag *)*Cur);
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
CHbMatchSpec::addHbTargetTag (
  CHbTargetTag *     pValue)
{
    m_listHbTargetTag.push_back(pValue);
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CHbMatchSpec::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pType = &CHbTargetTag::s_typeDescriptor;

    pEncoderStream->putRequiredSubParameterList((tListOfParameters *) &m_listHbTargetTag, pType);

}




/*
*****************************************************************
**
** Parameter HbTargetTag
**
*****************************************************************
*/


const CTypeDescriptor
CHbTargetTag::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "HbTargetTag",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    454,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CHbTargetTag::s_apFieldDescriptorTable[] =
{

    &s_fdMemoryType,
    &s_fdMatchType,
    &s_fdPointer,
    &s_fdTagMask,
    &s_fdTagData,
    NULL
};



const CFieldDescriptor
CHbTargetTag::s_fdMemoryType =
{
    CFieldDescriptor::FT_E8,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "MemoryType",	// m_pName
    g_estMemoryType	// m_pEnumTable
};


const CFieldDescriptor
CHbTargetTag::s_fdMatchType =
{
    CFieldDescriptor::FT_E1,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "MatchType",	// m_pName
    g_estMatchType	// m_pEnumTable
};


const CFieldDescriptor
CHbTargetTag::s_fdPointer =
{
    CFieldDescriptor::FT_U16,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "Pointer",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CHbTargetTag::s_fdTagMask =
{
    CFieldDescriptor::FT_U1V,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "TagMask",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CHbTargetTag::s_fdTagData =
{
    CFieldDescriptor::FT_U1V,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "TagData",	// m_pName
    NULL	// m_pEnumTable
};
CHbTargetTag::CHbTargetTag (void)
{
    m_pType = &s_typeDescriptor;

    m_EMemoryType = (EMemoryType) 0;
    m_EMatchType = (EMatchType) 0;
    m_Pointer = 0;
}

CHbTargetTag::~CHbTargetTag (void)
{
}


CElement *
CHbTargetTag::s_construct (void)
{
    return (CElement *) new CHbTargetTag();
}


void
CHbTargetTag::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CHbTargetTag * pTarget = (CHbTargetTag *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_EMemoryType = (EMemoryType) pDecoderStream->get_e8(&s_fdMemoryType);
    }
    else
    {
        pDecoderStream->get_e8(&s_fdMemoryType);
    }

    if(NULL != pTarget)
    {
        pTarget->m_EMatchType = (EMatchType) pDecoderStream->get_e1(&s_fdMatchType);
    }
    else
    {
        pDecoderStream->get_e1(&s_fdMatchType);
    }

    pDecoderStream->get_reserved(7);

    if(NULL != pTarget)
    {
        pTarget->m_Pointer = pDecoderStream->get_u16(&s_fdPointer);
    }
    else
    {
        pDecoderStream->get_u16(&s_fdPointer);
    }

    if(NULL != pTarget)
    {
        pTarget->m_TagMask = pDecoderStream->get_u1v(&s_fdTagMask);
    }
    else
    {
        pDecoderStream->get_u1v(&s_fdTagMask);
    }

    if(NULL != pTarget)
    {
        pTarget->m_TagData = pDecoderStream->get_u1v(&s_fdTagData);
    }
    else
    {
        pDecoderStream->get_u1v(&s_fdTagData);
    }

}


void
CHbTargetTag::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CHbTargetTag::assimilateSubParameters (
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
CHbTargetTag::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_e8((int)m_EMemoryType, &s_fdMemoryType);

    pEncoderStream->put_e1((int)m_EMatchType, &s_fdMatchType);

    pEncoderStream->put_reserved(7);

    pEncoderStream->put_u16(m_Pointer, &s_fdPointer);

    pEncoderStream->put_u1v(m_TagMask, &s_fdTagMask);

    pEncoderStream->put_u1v(m_TagData, &s_fdTagData);

}




/*
*****************************************************************
**
** Parameter HbReadSpec
**
*****************************************************************
*/


const CTypeDescriptor
CHbReadSpec::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "HbReadSpec",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    455,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CHbReadSpec::s_apFieldDescriptorTable[] =
{

    &s_fdOpSpecID,
    NULL
};



const CFieldDescriptor
CHbReadSpec::s_fdOpSpecID =
{
    CFieldDescriptor::FT_U16,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "OpSpecID",	// m_pName
    NULL	// m_pEnumTable
};
CHbReadSpec::CHbReadSpec (void)
{
    m_pType = &s_typeDescriptor;

    m_OpSpecID = 0;
    m_pMemoryBank = NULL;
}

CHbReadSpec::~CHbReadSpec (void)
{
}


CElement *
CHbReadSpec::s_construct (void)
{
    return (CElement *) new CHbReadSpec();
}


void
CHbReadSpec::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CHbReadSpec * pTarget = (CHbReadSpec *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_OpSpecID = pDecoderStream->get_u16(&s_fdOpSpecID);
    }
    else
    {
        pDecoderStream->get_u16(&s_fdOpSpecID);
    }

}


void
CHbReadSpec::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CHbReadSpec::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    // 1 of MemoryBank
    pType = &CMemoryBank::s_typeDescriptor;

    if(Cur == End || (*Cur)->m_pType != pType)
    {
        goto missing;
    }
    m_pMemoryBank = (CMemoryBank *)*Cur++;


    if(Cur != End)
    {
        pError->unexpectedParameter(*Cur);
    }

    return;

  missing:
    pError->missingParameter(pType);
}


EResultCode
CHbReadSpec::setMemoryBank (
  CMemoryBank *     pValue)
{
    removeSubParameterFromAllList(m_pMemoryBank);
    delete m_pMemoryBank;
    m_pMemoryBank = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CHbReadSpec::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u16(m_OpSpecID, &s_fdOpSpecID);

    pType = &CMemoryBank::s_typeDescriptor;

    pEncoderStream->putRequiredSubParameter(m_pMemoryBank, pType);

}




/*
*****************************************************************
**
** Parameter HbWriteSpec
**
*****************************************************************
*/


const CTypeDescriptor
CHbWriteSpec::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "HbWriteSpec",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    458,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CHbWriteSpec::s_apFieldDescriptorTable[] =
{

    &s_fdOpSpecID,
    &s_fdMemoryBankID,
    &s_fdPointer,
    &s_fdData,
    NULL
};



const CFieldDescriptor
CHbWriteSpec::s_fdOpSpecID =
{
    CFieldDescriptor::FT_U16,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "OpSpecID",	// m_pName
    NULL	// m_pEnumTable
};




const CFieldDescriptor
CHbWriteSpec::s_fdMemoryBankID =
{
    CFieldDescriptor::FT_U8,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "MemoryBankID",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CHbWriteSpec::s_fdPointer =
{
    CFieldDescriptor::FT_U16,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "Pointer",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CHbWriteSpec::s_fdData =
{
    CFieldDescriptor::FT_U16V,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "Data",	// m_pName
    NULL	// m_pEnumTable
};
CHbWriteSpec::CHbWriteSpec (void)
{
    m_pType = &s_typeDescriptor;

    m_OpSpecID = 0;
    m_MemoryBankID = 0;
    m_Pointer = 0;
}

CHbWriteSpec::~CHbWriteSpec (void)
{
}


CElement *
CHbWriteSpec::s_construct (void)
{
    return (CElement *) new CHbWriteSpec();
}


void
CHbWriteSpec::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CHbWriteSpec * pTarget = (CHbWriteSpec *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_OpSpecID = pDecoderStream->get_u16(&s_fdOpSpecID);
    }
    else
    {
        pDecoderStream->get_u16(&s_fdOpSpecID);
    }


    if(NULL != pTarget)
    {
        pTarget->m_MemoryBankID = pDecoderStream->get_u8(&s_fdMemoryBankID);
    }
    else
    {
        pDecoderStream->get_u8(&s_fdMemoryBankID);
    }

    if(NULL != pTarget)
    {
        pTarget->m_Pointer = pDecoderStream->get_u16(&s_fdPointer);
    }
    else
    {
        pDecoderStream->get_u16(&s_fdPointer);
    }

    if(NULL != pTarget)
    {
        pTarget->m_Data = pDecoderStream->get_u16v(&s_fdData);
    }
    else
    {
        pDecoderStream->get_u16v(&s_fdData);
    }

}


void
CHbWriteSpec::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CHbWriteSpec::assimilateSubParameters (
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
CHbWriteSpec::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u16(m_OpSpecID, &s_fdOpSpecID);


    pEncoderStream->put_u8(m_MemoryBankID, &s_fdMemoryBankID);

    pEncoderStream->put_u16(m_Pointer, &s_fdPointer);

    pEncoderStream->put_u16v(m_Data, &s_fdData);

}




/*
*****************************************************************
**
** Parameter ClientRequestSpec
**
*****************************************************************
*/


const CTypeDescriptor
CClientRequestSpec::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "ClientRequestSpec",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    456,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CClientRequestSpec::s_apFieldDescriptorTable[] =
{

    &s_fdOpSpecID,
    NULL
};



const CFieldDescriptor
CClientRequestSpec::s_fdOpSpecID =
{
    CFieldDescriptor::FT_U16,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "OpSpecID",	// m_pName
    NULL	// m_pEnumTable
};
CClientRequestSpec::CClientRequestSpec (void)
{
    m_pType = &s_typeDescriptor;

    m_OpSpecID = 0;
}

CClientRequestSpec::~CClientRequestSpec (void)
{
}


CElement *
CClientRequestSpec::s_construct (void)
{
    return (CElement *) new CClientRequestSpec();
}


void
CClientRequestSpec::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CClientRequestSpec * pTarget = (CClientRequestSpec *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_OpSpecID = pDecoderStream->get_u16(&s_fdOpSpecID);
    }
    else
    {
        pDecoderStream->get_u16(&s_fdOpSpecID);
    }

}


void
CClientRequestSpec::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CClientRequestSpec::assimilateSubParameters (
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
CClientRequestSpec::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u16(m_OpSpecID, &s_fdOpSpecID);

}




/*
*****************************************************************
**
** Parameter AccessReportSpec
**
*****************************************************************
*/


const CTypeDescriptor
CAccessReportSpec::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "AccessReportSpec",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    457,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CAccessReportSpec::s_apFieldDescriptorTable[] =
{

    &s_fdAccessReportTrigger,
    NULL
};



const CFieldDescriptor
CAccessReportSpec::s_fdAccessReportTrigger =
{
    CFieldDescriptor::FT_E8,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "AccessReportTrigger",	// m_pName
    g_estAccessReportTrigger	// m_pEnumTable
};
CAccessReportSpec::CAccessReportSpec (void)
{
    m_pType = &s_typeDescriptor;

    m_EAccessReportTrigger = (EAccessReportTrigger) 0;
    m_pReportDestination = NULL;
}

CAccessReportSpec::~CAccessReportSpec (void)
{
}


CElement *
CAccessReportSpec::s_construct (void)
{
    return (CElement *) new CAccessReportSpec();
}


void
CAccessReportSpec::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CAccessReportSpec * pTarget = (CAccessReportSpec *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_EAccessReportTrigger = (EAccessReportTrigger) pDecoderStream->get_e8(&s_fdAccessReportTrigger);
    }
    else
    {
        pDecoderStream->get_e8(&s_fdAccessReportTrigger);
    }

}


void
CAccessReportSpec::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CAccessReportSpec::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    // 0-1 of ReportDestination
    pType = &CReportDestination::s_typeDescriptor;

    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pReportDestination = (CReportDestination *)*Cur++;
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
CAccessReportSpec::setReportDestination (
  CReportDestination *     pValue)
{
    removeSubParameterFromAllList(m_pReportDestination);
    delete m_pReportDestination;
    m_pReportDestination = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CAccessReportSpec::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_e8((int)m_EAccessReportTrigger, &s_fdAccessReportTrigger);

    pType = &CReportDestination::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameter(m_pReportDestination, pType);

}




/*
*****************************************************************
**
** Parameter TagReportData
**
*****************************************************************
*/


const CTypeDescriptor
CTagReportData::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "TagReportData",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    500,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CTagReportData::s_apFieldDescriptorTable[] =
{

    &s_fdTID,
    NULL
};



const CFieldDescriptor
CTagReportData::s_fdTID =
{
    CFieldDescriptor::FT_U8V,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "TID",	// m_pName
    NULL	// m_pEnumTable
};
CTagReportData::CTagReportData (void)
{
    m_pType = &s_typeDescriptor;

    m_pSelectSpecID = NULL;
    m_pSpecIndex = NULL;
    m_pRfSpecID = NULL;
    m_pAntennaID = NULL;
    m_pPeakRSSI = NULL;
    m_pFirstSeenTimestampUTC = NULL;
    m_pLastSeenTimestampUTC = NULL;
    m_pTagSeenCount = NULL;
    m_pAccessSpecID = NULL;
    m_pSelectSpecResult = NULL;
}

CTagReportData::~CTagReportData (void)
{
}


CElement *
CTagReportData::s_construct (void)
{
    return (CElement *) new CTagReportData();
}


void
CTagReportData::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CTagReportData * pTarget = (CTagReportData *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_TID = pDecoderStream->get_u8v(&s_fdTID);
    }
    else
    {
        pDecoderStream->get_u8v(&s_fdTID);
    }

}


void
CTagReportData::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CTagReportData::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    // 0-1 of SelectSpecID
    pType = &CSelectSpecID::s_typeDescriptor;

    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pSelectSpecID = (CSelectSpecID *)*Cur++;
    }


    // 0-1 of SpecIndex
    pType = &CSpecIndex::s_typeDescriptor;

    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pSpecIndex = (CSpecIndex *)*Cur++;
    }


    // 0-1 of RfSpecID
    pType = &CRfSpecID::s_typeDescriptor;

    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pRfSpecID = (CRfSpecID *)*Cur++;
    }


    // 0-1 of AntennaID
    pType = &CAntennaID::s_typeDescriptor;

    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pAntennaID = (CAntennaID *)*Cur++;
    }


    // 0-1 of PeakRSSI
    pType = &CPeakRSSI::s_typeDescriptor;

    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pPeakRSSI = (CPeakRSSI *)*Cur++;
    }


    // 0-1 of FirstSeenTimestampUTC
    pType = &CFirstSeenTimestampUTC::s_typeDescriptor;

    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pFirstSeenTimestampUTC = (CFirstSeenTimestampUTC *)*Cur++;
    }


    // 0-1 of LastSeenTimestampUTC
    pType = &CLastSeenTimestampUTC::s_typeDescriptor;

    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pLastSeenTimestampUTC = (CLastSeenTimestampUTC *)*Cur++;
    }


    // 0-1 of TagSeenCount
    pType = &CTagSeenCount::s_typeDescriptor;

    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pTagSeenCount = (CTagSeenCount *)*Cur++;
    }


    // 0-1 of AccessSpecID
    pType = &CAccessSpecID::s_typeDescriptor;

    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pAccessSpecID = (CAccessSpecID *)*Cur++;
    }


    // 0-1 of choice SelectSpecResult
    pType = NULL;

    if(Cur != End && CSelectSpecResult::isMember(*Cur))
    {
        m_pSelectSpecResult = *Cur++;
    }


    // 0-N of choice AccessSpecResult
    pType = NULL;

    while(Cur != End && CAccessSpecResult::isMember(*Cur))
    {
        m_listAccessSpecResult.push_back(*Cur);
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
CTagReportData::setSelectSpecID (
  CSelectSpecID *     pValue)
{
    removeSubParameterFromAllList(m_pSelectSpecID);
    delete m_pSelectSpecID;
    m_pSelectSpecID = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CTagReportData::setSpecIndex (
  CSpecIndex *     pValue)
{
    removeSubParameterFromAllList(m_pSpecIndex);
    delete m_pSpecIndex;
    m_pSpecIndex = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CTagReportData::setRfSpecID (
  CRfSpecID *     pValue)
{
    removeSubParameterFromAllList(m_pRfSpecID);
    delete m_pRfSpecID;
    m_pRfSpecID = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CTagReportData::setAntennaID (
  CAntennaID *     pValue)
{
    removeSubParameterFromAllList(m_pAntennaID);
    delete m_pAntennaID;
    m_pAntennaID = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CTagReportData::setPeakRSSI (
  CPeakRSSI *     pValue)
{
    removeSubParameterFromAllList(m_pPeakRSSI);
    delete m_pPeakRSSI;
    m_pPeakRSSI = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CTagReportData::setFirstSeenTimestampUTC (
  CFirstSeenTimestampUTC *     pValue)
{
    removeSubParameterFromAllList(m_pFirstSeenTimestampUTC);
    delete m_pFirstSeenTimestampUTC;
    m_pFirstSeenTimestampUTC = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CTagReportData::setLastSeenTimestampUTC (
  CLastSeenTimestampUTC *     pValue)
{
    removeSubParameterFromAllList(m_pLastSeenTimestampUTC);
    delete m_pLastSeenTimestampUTC;
    m_pLastSeenTimestampUTC = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CTagReportData::setTagSeenCount (
  CTagSeenCount *     pValue)
{
    removeSubParameterFromAllList(m_pTagSeenCount);
    delete m_pTagSeenCount;
    m_pTagSeenCount = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CTagReportData::setAccessSpecID (
  CAccessSpecID *     pValue)
{
    removeSubParameterFromAllList(m_pAccessSpecID);
    delete m_pAccessSpecID;
    m_pAccessSpecID = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CTagReportData::setSelectSpecResult (
  CParameter *                  pValue)
{
    if(!CSelectSpecResult::isMember(pValue))
    {
        return RC_InvalidChoiceMember;
    }

    removeSubParameterFromAllList(m_pSelectSpecResult);
    delete m_pSelectSpecResult;
    m_pSelectSpecResult = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CTagReportData::addAccessSpecResult (
  CParameter *                  pValue)
{
    if(!CAccessSpecResult::isMember(pValue))
    {
        return RC_InvalidChoiceMember;
    }

    m_listAccessSpecResult.push_back(pValue);
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CTagReportData::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u8v(m_TID, &s_fdTID);

    pType = &CSelectSpecID::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameter(m_pSelectSpecID, pType);

    pType = &CSpecIndex::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameter(m_pSpecIndex, pType);

    pType = &CRfSpecID::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameter(m_pRfSpecID, pType);

    pType = &CAntennaID::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameter(m_pAntennaID, pType);

    pType = &CPeakRSSI::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameter(m_pPeakRSSI, pType);

    pType = &CFirstSeenTimestampUTC::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameter(m_pFirstSeenTimestampUTC, pType);

    pType = &CLastSeenTimestampUTC::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameter(m_pLastSeenTimestampUTC, pType);

    pType = &CTagSeenCount::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameter(m_pTagSeenCount, pType);

    pType = &CAccessSpecID::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameter(m_pAccessSpecID, pType);

    pType = NULL;

    pEncoderStream->putOptionalSubParameter(m_pSelectSpecResult, pType);

    pType = NULL;

    pEncoderStream->putOptionalSubParameterList((tListOfParameters *) &m_listAccessSpecResult, pType);

}




/*
*****************************************************************
**
** Parameter SelectSpecID
**
*****************************************************************
*/


const CTypeDescriptor
CSelectSpecID::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "SelectSpecID",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    501,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CSelectSpecID::s_apFieldDescriptorTable[] =
{

    &s_fdSelectSpecID,
    NULL
};



const CFieldDescriptor
CSelectSpecID::s_fdSelectSpecID =
{
    CFieldDescriptor::FT_U32,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "SelectSpecID",	// m_pName
    NULL	// m_pEnumTable
};
CSelectSpecID::CSelectSpecID (void)
{
    m_pType = &s_typeDescriptor;

    m_SelectSpecID = 0;
}

CSelectSpecID::~CSelectSpecID (void)
{
}


CElement *
CSelectSpecID::s_construct (void)
{
    return (CElement *) new CSelectSpecID();
}


void
CSelectSpecID::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CSelectSpecID * pTarget = (CSelectSpecID *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_SelectSpecID = pDecoderStream->get_u32(&s_fdSelectSpecID);
    }
    else
    {
        pDecoderStream->get_u32(&s_fdSelectSpecID);
    }

}


void
CSelectSpecID::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CSelectSpecID::assimilateSubParameters (
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
CSelectSpecID::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u32(m_SelectSpecID, &s_fdSelectSpecID);

}




/*
*****************************************************************
**
** Parameter SpecIndex
**
*****************************************************************
*/


const CTypeDescriptor
CSpecIndex::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "SpecIndex",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    502,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CSpecIndex::s_apFieldDescriptorTable[] =
{

    &s_fdSpecIndex,
    NULL
};



const CFieldDescriptor
CSpecIndex::s_fdSpecIndex =
{
    CFieldDescriptor::FT_U16,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "SpecIndex",	// m_pName
    NULL	// m_pEnumTable
};
CSpecIndex::CSpecIndex (void)
{
    m_pType = &s_typeDescriptor;

    m_SpecIndex = 0;
}

CSpecIndex::~CSpecIndex (void)
{
}


CElement *
CSpecIndex::s_construct (void)
{
    return (CElement *) new CSpecIndex();
}


void
CSpecIndex::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CSpecIndex * pTarget = (CSpecIndex *) pTargetElement;


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
CSpecIndex::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CSpecIndex::assimilateSubParameters (
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
CSpecIndex::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u16(m_SpecIndex, &s_fdSpecIndex);

}




/*
*****************************************************************
**
** Parameter RfSpecID
**
*****************************************************************
*/


const CTypeDescriptor
CRfSpecID::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "RfSpecID",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    503,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CRfSpecID::s_apFieldDescriptorTable[] =
{

    &s_fdRfSpecID,
    NULL
};



const CFieldDescriptor
CRfSpecID::s_fdRfSpecID =
{
    CFieldDescriptor::FT_U16,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "RfSpecID",	// m_pName
    NULL	// m_pEnumTable
};
CRfSpecID::CRfSpecID (void)
{
    m_pType = &s_typeDescriptor;

    m_RfSpecID = 0;
}

CRfSpecID::~CRfSpecID (void)
{
}


CElement *
CRfSpecID::s_construct (void)
{
    return (CElement *) new CRfSpecID();
}


void
CRfSpecID::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CRfSpecID * pTarget = (CRfSpecID *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_RfSpecID = pDecoderStream->get_u16(&s_fdRfSpecID);
    }
    else
    {
        pDecoderStream->get_u16(&s_fdRfSpecID);
    }

}


void
CRfSpecID::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CRfSpecID::assimilateSubParameters (
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
CRfSpecID::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u16(m_RfSpecID, &s_fdRfSpecID);

}




/*
*****************************************************************
**
** Parameter AntennaID
**
*****************************************************************
*/


const CTypeDescriptor
CAntennaID::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "AntennaID",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    504,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CAntennaID::s_apFieldDescriptorTable[] =
{

    &s_fdAntennaID,
    NULL
};



const CFieldDescriptor
CAntennaID::s_fdAntennaID =
{
    CFieldDescriptor::FT_U8,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "AntennaID",	// m_pName
    NULL	// m_pEnumTable
};
CAntennaID::CAntennaID (void)
{
    m_pType = &s_typeDescriptor;

    m_AntennaID = 0;
}

CAntennaID::~CAntennaID (void)
{
}


CElement *
CAntennaID::s_construct (void)
{
    return (CElement *) new CAntennaID();
}


void
CAntennaID::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CAntennaID * pTarget = (CAntennaID *) pTargetElement;


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
CAntennaID::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CAntennaID::assimilateSubParameters (
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
CAntennaID::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u8(m_AntennaID, &s_fdAntennaID);

}




/*
*****************************************************************
**
** Parameter PeakRSSI
**
*****************************************************************
*/


const CTypeDescriptor
CPeakRSSI::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "PeakRSSI",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    505,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CPeakRSSI::s_apFieldDescriptorTable[] =
{

    &s_fdPeakRSSI,
    NULL
};



const CFieldDescriptor
CPeakRSSI::s_fdPeakRSSI =
{
    CFieldDescriptor::FT_S8,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "PeakRSSI",	// m_pName
    NULL	// m_pEnumTable
};
CPeakRSSI::CPeakRSSI (void)
{
    m_pType = &s_typeDescriptor;

    m_PeakRSSI = 0;
}

CPeakRSSI::~CPeakRSSI (void)
{
}


CElement *
CPeakRSSI::s_construct (void)
{
    return (CElement *) new CPeakRSSI();
}


void
CPeakRSSI::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CPeakRSSI * pTarget = (CPeakRSSI *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_PeakRSSI = pDecoderStream->get_s8(&s_fdPeakRSSI);
    }
    else
    {
        pDecoderStream->get_s8(&s_fdPeakRSSI);
    }

}


void
CPeakRSSI::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CPeakRSSI::assimilateSubParameters (
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
CPeakRSSI::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_s8(m_PeakRSSI, &s_fdPeakRSSI);

}




/*
*****************************************************************
**
** Parameter FirstSeenTimestampUTC
**
*****************************************************************
*/


const CTypeDescriptor
CFirstSeenTimestampUTC::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "FirstSeenTimestampUTC",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    506,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CFirstSeenTimestampUTC::s_apFieldDescriptorTable[] =
{

    &s_fdMicroseconds,
    NULL
};



const CFieldDescriptor
CFirstSeenTimestampUTC::s_fdMicroseconds =
{
    CFieldDescriptor::FT_U64,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "Microseconds",	// m_pName
    NULL	// m_pEnumTable
};
CFirstSeenTimestampUTC::CFirstSeenTimestampUTC (void)
{
    m_pType = &s_typeDescriptor;

    m_Microseconds = 0;
}

CFirstSeenTimestampUTC::~CFirstSeenTimestampUTC (void)
{
}


CElement *
CFirstSeenTimestampUTC::s_construct (void)
{
    return (CElement *) new CFirstSeenTimestampUTC();
}


void
CFirstSeenTimestampUTC::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CFirstSeenTimestampUTC * pTarget = (CFirstSeenTimestampUTC *) pTargetElement;


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
CFirstSeenTimestampUTC::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CFirstSeenTimestampUTC::assimilateSubParameters (
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
CFirstSeenTimestampUTC::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u64(m_Microseconds, &s_fdMicroseconds);

}




/*
*****************************************************************
**
** Parameter LastSeenTimestampUTC
**
*****************************************************************
*/


const CTypeDescriptor
CLastSeenTimestampUTC::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "LastSeenTimestampUTC",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    507,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CLastSeenTimestampUTC::s_apFieldDescriptorTable[] =
{

    &s_fdMicroseconds,
    NULL
};



const CFieldDescriptor
CLastSeenTimestampUTC::s_fdMicroseconds =
{
    CFieldDescriptor::FT_U64,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "Microseconds",	// m_pName
    NULL	// m_pEnumTable
};
CLastSeenTimestampUTC::CLastSeenTimestampUTC (void)
{
    m_pType = &s_typeDescriptor;

    m_Microseconds = 0;
}

CLastSeenTimestampUTC::~CLastSeenTimestampUTC (void)
{
}


CElement *
CLastSeenTimestampUTC::s_construct (void)
{
    return (CElement *) new CLastSeenTimestampUTC();
}


void
CLastSeenTimestampUTC::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CLastSeenTimestampUTC * pTarget = (CLastSeenTimestampUTC *) pTargetElement;


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
CLastSeenTimestampUTC::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CLastSeenTimestampUTC::assimilateSubParameters (
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
CLastSeenTimestampUTC::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u64(m_Microseconds, &s_fdMicroseconds);

}




/*
*****************************************************************
**
** Parameter TagSeenCount
**
*****************************************************************
*/


const CTypeDescriptor
CTagSeenCount::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "TagSeenCount",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    508,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CTagSeenCount::s_apFieldDescriptorTable[] =
{

    &s_fdTagCount,
    NULL
};



const CFieldDescriptor
CTagSeenCount::s_fdTagCount =
{
    CFieldDescriptor::FT_U16,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "TagCount",	// m_pName
    NULL	// m_pEnumTable
};
CTagSeenCount::CTagSeenCount (void)
{
    m_pType = &s_typeDescriptor;

    m_TagCount = 0;
}

CTagSeenCount::~CTagSeenCount (void)
{
}


CElement *
CTagSeenCount::s_construct (void)
{
    return (CElement *) new CTagSeenCount();
}


void
CTagSeenCount::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CTagSeenCount * pTarget = (CTagSeenCount *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_TagCount = pDecoderStream->get_u16(&s_fdTagCount);
    }
    else
    {
        pDecoderStream->get_u16(&s_fdTagCount);
    }

}


void
CTagSeenCount::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CTagSeenCount::assimilateSubParameters (
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
CTagSeenCount::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u16(m_TagCount, &s_fdTagCount);

}




/*
*****************************************************************
**
** Parameter AccessSpecID
**
*****************************************************************
*/


const CTypeDescriptor
CAccessSpecID::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "AccessSpecID",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    509,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CAccessSpecID::s_apFieldDescriptorTable[] =
{

    &s_fdAccessSpecID,
    NULL
};



const CFieldDescriptor
CAccessSpecID::s_fdAccessSpecID =
{
    CFieldDescriptor::FT_U32,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "AccessSpecID",	// m_pName
    NULL	// m_pEnumTable
};
CAccessSpecID::CAccessSpecID (void)
{
    m_pType = &s_typeDescriptor;

    m_AccessSpecID = 0;
}

CAccessSpecID::~CAccessSpecID (void)
{
}


CElement *
CAccessSpecID::s_construct (void)
{
    return (CElement *) new CAccessSpecID();
}


void
CAccessSpecID::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CAccessSpecID * pTarget = (CAccessSpecID *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_AccessSpecID = pDecoderStream->get_u32(&s_fdAccessSpecID);
    }
    else
    {
        pDecoderStream->get_u32(&s_fdAccessSpecID);
    }

}


void
CAccessSpecID::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CAccessSpecID::assimilateSubParameters (
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
CAccessSpecID::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u32(m_AccessSpecID, &s_fdAccessSpecID);

}




/*
*****************************************************************
**
** Parameter GenaralSelectSpecResult
**
*****************************************************************
*/


const CTypeDescriptor
CGenaralSelectSpecResult::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "GenaralSelectSpecResult",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    510,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CGenaralSelectSpecResult::s_apFieldDescriptorTable[] =
{

    &s_fdResult,
    &s_fdTagData,
    NULL
};



const CFieldDescriptor
CGenaralSelectSpecResult::s_fdResult =
{
    CFieldDescriptor::FT_U8,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "Result",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CGenaralSelectSpecResult::s_fdTagData =
{
    CFieldDescriptor::FT_U16V,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "TagData",	// m_pName
    NULL	// m_pEnumTable
};
CGenaralSelectSpecResult::CGenaralSelectSpecResult (void)
{
    m_pType = &s_typeDescriptor;

    m_Result = 0;
}

CGenaralSelectSpecResult::~CGenaralSelectSpecResult (void)
{
}


CElement *
CGenaralSelectSpecResult::s_construct (void)
{
    return (CElement *) new CGenaralSelectSpecResult();
}


void
CGenaralSelectSpecResult::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CGenaralSelectSpecResult * pTarget = (CGenaralSelectSpecResult *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_Result = pDecoderStream->get_u8(&s_fdResult);
    }
    else
    {
        pDecoderStream->get_u8(&s_fdResult);
    }

    if(NULL != pTarget)
    {
        pTarget->m_TagData = pDecoderStream->get_u16v(&s_fdTagData);
    }
    else
    {
        pDecoderStream->get_u16v(&s_fdTagData);
    }

}


void
CGenaralSelectSpecResult::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CGenaralSelectSpecResult::assimilateSubParameters (
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
CGenaralSelectSpecResult::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u8(m_Result, &s_fdResult);

    pEncoderStream->put_u16v(m_TagData, &s_fdTagData);

}




/*
*****************************************************************
**
** Parameter CustomizedSelectSpecResult
**
*****************************************************************
*/


const CTypeDescriptor
CCustomizedSelectSpecResult::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "CustomizedSelectSpecResult",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    517,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CCustomizedSelectSpecResult::s_apFieldDescriptorTable[] =
{

    &s_fdResult,
    NULL
};



const CFieldDescriptor
CCustomizedSelectSpecResult::s_fdResult =
{
    CFieldDescriptor::FT_U8,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "Result",	// m_pName
    NULL	// m_pEnumTable
};
CCustomizedSelectSpecResult::CCustomizedSelectSpecResult (void)
{
    m_pType = &s_typeDescriptor;

    m_Result = 0;
    m_pReadDataInfo = NULL;
}

CCustomizedSelectSpecResult::~CCustomizedSelectSpecResult (void)
{
}


CElement *
CCustomizedSelectSpecResult::s_construct (void)
{
    return (CElement *) new CCustomizedSelectSpecResult();
}


void
CCustomizedSelectSpecResult::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CCustomizedSelectSpecResult * pTarget = (CCustomizedSelectSpecResult *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_Result = pDecoderStream->get_u8(&s_fdResult);
    }
    else
    {
        pDecoderStream->get_u8(&s_fdResult);
    }

}


void
CCustomizedSelectSpecResult::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CCustomizedSelectSpecResult::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    // 0-1 of ReadDataInfo
    pType = &CReadDataInfo::s_typeDescriptor;

    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pReadDataInfo = (CReadDataInfo *)*Cur++;
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
CCustomizedSelectSpecResult::setReadDataInfo (
  CReadDataInfo *     pValue)
{
    removeSubParameterFromAllList(m_pReadDataInfo);
    delete m_pReadDataInfo;
    m_pReadDataInfo = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CCustomizedSelectSpecResult::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u8(m_Result, &s_fdResult);

    pType = &CReadDataInfo::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameter(m_pReadDataInfo, pType);

}




/*
*****************************************************************
**
** Parameter HbCustomizedReadSpecResult
**
*****************************************************************
*/


const CTypeDescriptor
CHbCustomizedReadSpecResult::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "HbCustomizedReadSpecResult",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    515,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CHbCustomizedReadSpecResult::s_apFieldDescriptorTable[] =
{

    &s_fdResult,
    &s_fdOpSpecID,
    NULL
};



const CFieldDescriptor
CHbCustomizedReadSpecResult::s_fdResult =
{
    CFieldDescriptor::FT_U8,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "Result",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CHbCustomizedReadSpecResult::s_fdOpSpecID =
{
    CFieldDescriptor::FT_U16,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "OpSpecID",	// m_pName
    NULL	// m_pEnumTable
};
CHbCustomizedReadSpecResult::CHbCustomizedReadSpecResult (void)
{
    m_pType = &s_typeDescriptor;

    m_Result = 0;
    m_OpSpecID = 0;
    m_pReadDataInfo = NULL;
}

CHbCustomizedReadSpecResult::~CHbCustomizedReadSpecResult (void)
{
}


CElement *
CHbCustomizedReadSpecResult::s_construct (void)
{
    return (CElement *) new CHbCustomizedReadSpecResult();
}


void
CHbCustomizedReadSpecResult::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CHbCustomizedReadSpecResult * pTarget = (CHbCustomizedReadSpecResult *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_Result = pDecoderStream->get_u8(&s_fdResult);
    }
    else
    {
        pDecoderStream->get_u8(&s_fdResult);
    }

    if(NULL != pTarget)
    {
        pTarget->m_OpSpecID = pDecoderStream->get_u16(&s_fdOpSpecID);
    }
    else
    {
        pDecoderStream->get_u16(&s_fdOpSpecID);
    }

}


void
CHbCustomizedReadSpecResult::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CHbCustomizedReadSpecResult::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    // 0-1 of ReadDataInfo
    pType = &CReadDataInfo::s_typeDescriptor;

    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pReadDataInfo = (CReadDataInfo *)*Cur++;
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
CHbCustomizedReadSpecResult::setReadDataInfo (
  CReadDataInfo *     pValue)
{
    removeSubParameterFromAllList(m_pReadDataInfo);
    delete m_pReadDataInfo;
    m_pReadDataInfo = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CHbCustomizedReadSpecResult::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u8(m_Result, &s_fdResult);

    pEncoderStream->put_u16(m_OpSpecID, &s_fdOpSpecID);

    pType = &CReadDataInfo::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameter(m_pReadDataInfo, pType);

}




/*
*****************************************************************
**
** Parameter ReadDataInfo
**
*****************************************************************
*/


const CTypeDescriptor
CReadDataInfo::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "ReadDataInfo",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    516,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CReadDataInfo::s_apFieldDescriptorTable[] =
{

    NULL
};

CReadDataInfo::CReadDataInfo (void)
{
    m_pType = &s_typeDescriptor;

    m_pCID = NULL;
    m_pFPDH = NULL;
    m_pSYXZ = NULL;
    m_pCCRQ = NULL;
    m_pCLLX = NULL;
    m_pPL = NULL;
    m_pGL = NULL;
    m_pHPZL = NULL;
    m_pHPHMXH = NULL;
    m_pJYYXQ = NULL;
    m_pQZBFQ = NULL;
    m_pCSYS = NULL;
    m_pZKZL = NULL;
}

CReadDataInfo::~CReadDataInfo (void)
{
}


CElement *
CReadDataInfo::s_construct (void)
{
    return (CElement *) new CReadDataInfo();
}


void
CReadDataInfo::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CReadDataInfo * pTarget = (CReadDataInfo *) pTargetElement;


}


void
CReadDataInfo::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CReadDataInfo::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    // 0-1 of CID
    pType = &CCID::s_typeDescriptor;

    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pCID = (CCID *)*Cur++;
    }


    // 0-1 of FPDH
    pType = &CFPDH::s_typeDescriptor;

    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pFPDH = (CFPDH *)*Cur++;
    }


    // 0-1 of SYXZ
    pType = &CSYXZ::s_typeDescriptor;

    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pSYXZ = (CSYXZ *)*Cur++;
    }


    // 0-1 of CCRQ
    pType = &CCCRQ::s_typeDescriptor;

    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pCCRQ = (CCCRQ *)*Cur++;
    }


    // 0-1 of CLLX
    pType = &CCLLX::s_typeDescriptor;

    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pCLLX = (CCLLX *)*Cur++;
    }


    // 0-1 of PL
    pType = &CPL::s_typeDescriptor;

    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pPL = (CPL *)*Cur++;
    }


    // 0-1 of GL
    pType = &CGL::s_typeDescriptor;

    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pGL = (CGL *)*Cur++;
    }


    // 0-1 of HPZL
    pType = &CHPZL::s_typeDescriptor;

    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pHPZL = (CHPZL *)*Cur++;
    }


    // 0-1 of HPHMXH
    pType = &CHPHMXH::s_typeDescriptor;

    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pHPHMXH = (CHPHMXH *)*Cur++;
    }


    // 0-1 of JYYXQ
    pType = &CJYYXQ::s_typeDescriptor;

    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pJYYXQ = (CJYYXQ *)*Cur++;
    }


    // 0-1 of QZBFQ
    pType = &CQZBFQ::s_typeDescriptor;

    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pQZBFQ = (CQZBFQ *)*Cur++;
    }


    // 0-1 of CSYS
    pType = &CCSYS::s_typeDescriptor;

    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pCSYS = (CCSYS *)*Cur++;
    }


    // 0-1 of ZKZL
    pType = &CZKZL::s_typeDescriptor;

    if(Cur != End && (*Cur)->m_pType == pType)
    {
        m_pZKZL = (CZKZL *)*Cur++;
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
CReadDataInfo::setCID (
  CCID *     pValue)
{
    removeSubParameterFromAllList(m_pCID);
    delete m_pCID;
    m_pCID = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CReadDataInfo::setFPDH (
  CFPDH *     pValue)
{
    removeSubParameterFromAllList(m_pFPDH);
    delete m_pFPDH;
    m_pFPDH = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CReadDataInfo::setSYXZ (
  CSYXZ *     pValue)
{
    removeSubParameterFromAllList(m_pSYXZ);
    delete m_pSYXZ;
    m_pSYXZ = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CReadDataInfo::setCCRQ (
  CCCRQ *     pValue)
{
    removeSubParameterFromAllList(m_pCCRQ);
    delete m_pCCRQ;
    m_pCCRQ = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CReadDataInfo::setCLLX (
  CCLLX *     pValue)
{
    removeSubParameterFromAllList(m_pCLLX);
    delete m_pCLLX;
    m_pCLLX = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CReadDataInfo::setPL (
  CPL *     pValue)
{
    removeSubParameterFromAllList(m_pPL);
    delete m_pPL;
    m_pPL = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CReadDataInfo::setGL (
  CGL *     pValue)
{
    removeSubParameterFromAllList(m_pGL);
    delete m_pGL;
    m_pGL = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CReadDataInfo::setHPZL (
  CHPZL *     pValue)
{
    removeSubParameterFromAllList(m_pHPZL);
    delete m_pHPZL;
    m_pHPZL = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CReadDataInfo::setHPHMXH (
  CHPHMXH *     pValue)
{
    removeSubParameterFromAllList(m_pHPHMXH);
    delete m_pHPHMXH;
    m_pHPHMXH = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CReadDataInfo::setJYYXQ (
  CJYYXQ *     pValue)
{
    removeSubParameterFromAllList(m_pJYYXQ);
    delete m_pJYYXQ;
    m_pJYYXQ = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CReadDataInfo::setQZBFQ (
  CQZBFQ *     pValue)
{
    removeSubParameterFromAllList(m_pQZBFQ);
    delete m_pQZBFQ;
    m_pQZBFQ = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CReadDataInfo::setCSYS (
  CCSYS *     pValue)
{
    removeSubParameterFromAllList(m_pCSYS);
    delete m_pCSYS;
    m_pCSYS = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CReadDataInfo::setZKZL (
  CZKZL *     pValue)
{
    removeSubParameterFromAllList(m_pZKZL);
    delete m_pZKZL;
    m_pZKZL = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CReadDataInfo::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pType = &CCID::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameter(m_pCID, pType);

    pType = &CFPDH::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameter(m_pFPDH, pType);

    pType = &CSYXZ::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameter(m_pSYXZ, pType);

    pType = &CCCRQ::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameter(m_pCCRQ, pType);

    pType = &CCLLX::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameter(m_pCLLX, pType);

    pType = &CPL::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameter(m_pPL, pType);

    pType = &CGL::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameter(m_pGL, pType);

    pType = &CHPZL::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameter(m_pHPZL, pType);

    pType = &CHPHMXH::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameter(m_pHPHMXH, pType);

    pType = &CJYYXQ::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameter(m_pJYYXQ, pType);

    pType = &CQZBFQ::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameter(m_pQZBFQ, pType);

    pType = &CCSYS::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameter(m_pCSYS, pType);

    pType = &CZKZL::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameter(m_pZKZL, pType);

}




/*
*****************************************************************
**
** Parameter HbReadSpecResult
**
*****************************************************************
*/


const CTypeDescriptor
CHbReadSpecResult::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "HbReadSpecResult",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    511,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CHbReadSpecResult::s_apFieldDescriptorTable[] =
{

    &s_fdResult,
    &s_fdOpSpecID,
    &s_fdReadData,
    NULL
};



const CFieldDescriptor
CHbReadSpecResult::s_fdResult =
{
    CFieldDescriptor::FT_U8,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "Result",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CHbReadSpecResult::s_fdOpSpecID =
{
    CFieldDescriptor::FT_U16,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "OpSpecID",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CHbReadSpecResult::s_fdReadData =
{
    CFieldDescriptor::FT_U16V,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "ReadData",	// m_pName
    NULL	// m_pEnumTable
};
CHbReadSpecResult::CHbReadSpecResult (void)
{
    m_pType = &s_typeDescriptor;

    m_Result = 0;
    m_OpSpecID = 0;
}

CHbReadSpecResult::~CHbReadSpecResult (void)
{
}


CElement *
CHbReadSpecResult::s_construct (void)
{
    return (CElement *) new CHbReadSpecResult();
}


void
CHbReadSpecResult::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CHbReadSpecResult * pTarget = (CHbReadSpecResult *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_Result = pDecoderStream->get_u8(&s_fdResult);
    }
    else
    {
        pDecoderStream->get_u8(&s_fdResult);
    }

    if(NULL != pTarget)
    {
        pTarget->m_OpSpecID = pDecoderStream->get_u16(&s_fdOpSpecID);
    }
    else
    {
        pDecoderStream->get_u16(&s_fdOpSpecID);
    }

    if(NULL != pTarget)
    {
        pTarget->m_ReadData = pDecoderStream->get_u16v(&s_fdReadData);
    }
    else
    {
        pDecoderStream->get_u16v(&s_fdReadData);
    }

}


void
CHbReadSpecResult::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CHbReadSpecResult::assimilateSubParameters (
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
CHbReadSpecResult::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u8(m_Result, &s_fdResult);

    pEncoderStream->put_u16(m_OpSpecID, &s_fdOpSpecID);

    pEncoderStream->put_u16v(m_ReadData, &s_fdReadData);

}




/*
*****************************************************************
**
** Parameter CID
**
*****************************************************************
*/


const CTypeDescriptor
CCID::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "CID",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    1001,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CCID::s_apFieldDescriptorTable[] =
{

    &s_fdCIDData,
    NULL
};



const CFieldDescriptor
CCID::s_fdCIDData =
{
    CFieldDescriptor::FT_U8V,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "CIDData",	// m_pName
    NULL	// m_pEnumTable
};
CCID::CCID (void)
{
    m_pType = &s_typeDescriptor;

}

CCID::~CCID (void)
{
}


CElement *
CCID::s_construct (void)
{
    return (CElement *) new CCID();
}


void
CCID::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CCID * pTarget = (CCID *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_CIDData = pDecoderStream->get_u8v(&s_fdCIDData);
    }
    else
    {
        pDecoderStream->get_u8v(&s_fdCIDData);
    }

}


void
CCID::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CCID::assimilateSubParameters (
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
CCID::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u8v(m_CIDData, &s_fdCIDData);

}




/*
*****************************************************************
**
** Parameter FPDH
**
*****************************************************************
*/


const CTypeDescriptor
CFPDH::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "FPDH",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    1002,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CFPDH::s_apFieldDescriptorTable[] =
{

    &s_fdFPDHData,
    NULL
};



const CFieldDescriptor
CFPDH::s_fdFPDHData =
{
    CFieldDescriptor::FT_U8V,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "FPDHData",	// m_pName
    NULL	// m_pEnumTable
};
CFPDH::CFPDH (void)
{
    m_pType = &s_typeDescriptor;

}

CFPDH::~CFPDH (void)
{
}


CElement *
CFPDH::s_construct (void)
{
    return (CElement *) new CFPDH();
}


void
CFPDH::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CFPDH * pTarget = (CFPDH *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_FPDHData = pDecoderStream->get_u8v(&s_fdFPDHData);
    }
    else
    {
        pDecoderStream->get_u8v(&s_fdFPDHData);
    }

}


void
CFPDH::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CFPDH::assimilateSubParameters (
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
CFPDH::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u8v(m_FPDHData, &s_fdFPDHData);

}




/*
*****************************************************************
**
** Parameter SYXZ
**
*****************************************************************
*/


const CTypeDescriptor
CSYXZ::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "SYXZ",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    1003,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CSYXZ::s_apFieldDescriptorTable[] =
{

    &s_fdSYXZData,
    NULL
};



const CFieldDescriptor
CSYXZ::s_fdSYXZData =
{
    CFieldDescriptor::FT_U8V,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "SYXZData",	// m_pName
    NULL	// m_pEnumTable
};
CSYXZ::CSYXZ (void)
{
    m_pType = &s_typeDescriptor;

}

CSYXZ::~CSYXZ (void)
{
}


CElement *
CSYXZ::s_construct (void)
{
    return (CElement *) new CSYXZ();
}


void
CSYXZ::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CSYXZ * pTarget = (CSYXZ *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_SYXZData = pDecoderStream->get_u8v(&s_fdSYXZData);
    }
    else
    {
        pDecoderStream->get_u8v(&s_fdSYXZData);
    }

}


void
CSYXZ::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CSYXZ::assimilateSubParameters (
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
CSYXZ::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u8v(m_SYXZData, &s_fdSYXZData);

}




/*
*****************************************************************
**
** Parameter CCRQ
**
*****************************************************************
*/


const CTypeDescriptor
CCCRQ::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "CCRQ",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    1004,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CCCRQ::s_apFieldDescriptorTable[] =
{

    &s_fdCCRQData,
    NULL
};



const CFieldDescriptor
CCCRQ::s_fdCCRQData =
{
    CFieldDescriptor::FT_U8V,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "CCRQData",	// m_pName
    NULL	// m_pEnumTable
};
CCCRQ::CCCRQ (void)
{
    m_pType = &s_typeDescriptor;

}

CCCRQ::~CCCRQ (void)
{
}


CElement *
CCCRQ::s_construct (void)
{
    return (CElement *) new CCCRQ();
}


void
CCCRQ::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CCCRQ * pTarget = (CCCRQ *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_CCRQData = pDecoderStream->get_u8v(&s_fdCCRQData);
    }
    else
    {
        pDecoderStream->get_u8v(&s_fdCCRQData);
    }

}


void
CCCRQ::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CCCRQ::assimilateSubParameters (
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
CCCRQ::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u8v(m_CCRQData, &s_fdCCRQData);

}




/*
*****************************************************************
**
** Parameter CLLX
**
*****************************************************************
*/


const CTypeDescriptor
CCLLX::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "CLLX",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    1005,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CCLLX::s_apFieldDescriptorTable[] =
{

    &s_fdCLLXData,
    NULL
};



const CFieldDescriptor
CCLLX::s_fdCLLXData =
{
    CFieldDescriptor::FT_U8V,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "CLLXData",	// m_pName
    NULL	// m_pEnumTable
};
CCLLX::CCLLX (void)
{
    m_pType = &s_typeDescriptor;

}

CCLLX::~CCLLX (void)
{
}


CElement *
CCLLX::s_construct (void)
{
    return (CElement *) new CCLLX();
}


void
CCLLX::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CCLLX * pTarget = (CCLLX *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_CLLXData = pDecoderStream->get_u8v(&s_fdCLLXData);
    }
    else
    {
        pDecoderStream->get_u8v(&s_fdCLLXData);
    }

}


void
CCLLX::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CCLLX::assimilateSubParameters (
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
CCLLX::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u8v(m_CLLXData, &s_fdCLLXData);

}




/*
*****************************************************************
**
** Parameter GL
**
*****************************************************************
*/


const CTypeDescriptor
CGL::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "GL",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    1006,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CGL::s_apFieldDescriptorTable[] =
{

    &s_fdGLData,
    NULL
};



const CFieldDescriptor
CGL::s_fdGLData =
{
    CFieldDescriptor::FT_U8V,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "GLData",	// m_pName
    NULL	// m_pEnumTable
};
CGL::CGL (void)
{
    m_pType = &s_typeDescriptor;

}

CGL::~CGL (void)
{
}


CElement *
CGL::s_construct (void)
{
    return (CElement *) new CGL();
}


void
CGL::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CGL * pTarget = (CGL *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_GLData = pDecoderStream->get_u8v(&s_fdGLData);
    }
    else
    {
        pDecoderStream->get_u8v(&s_fdGLData);
    }

}


void
CGL::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CGL::assimilateSubParameters (
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
CGL::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u8v(m_GLData, &s_fdGLData);

}




/*
*****************************************************************
**
** Parameter PL
**
*****************************************************************
*/


const CTypeDescriptor
CPL::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "PL",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    1007,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CPL::s_apFieldDescriptorTable[] =
{

    &s_fdPLData,
    NULL
};



const CFieldDescriptor
CPL::s_fdPLData =
{
    CFieldDescriptor::FT_U8V,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "PLData",	// m_pName
    NULL	// m_pEnumTable
};
CPL::CPL (void)
{
    m_pType = &s_typeDescriptor;

}

CPL::~CPL (void)
{
}


CElement *
CPL::s_construct (void)
{
    return (CElement *) new CPL();
}


void
CPL::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CPL * pTarget = (CPL *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_PLData = pDecoderStream->get_u8v(&s_fdPLData);
    }
    else
    {
        pDecoderStream->get_u8v(&s_fdPLData);
    }

}


void
CPL::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CPL::assimilateSubParameters (
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
CPL::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u8v(m_PLData, &s_fdPLData);

}




/*
*****************************************************************
**
** Parameter HPZL
**
*****************************************************************
*/


const CTypeDescriptor
CHPZL::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "HPZL",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    1008,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CHPZL::s_apFieldDescriptorTable[] =
{

    &s_fdHPZLData,
    NULL
};



const CFieldDescriptor
CHPZL::s_fdHPZLData =
{
    CFieldDescriptor::FT_U8V,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "HPZLData",	// m_pName
    NULL	// m_pEnumTable
};
CHPZL::CHPZL (void)
{
    m_pType = &s_typeDescriptor;

}

CHPZL::~CHPZL (void)
{
}


CElement *
CHPZL::s_construct (void)
{
    return (CElement *) new CHPZL();
}


void
CHPZL::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CHPZL * pTarget = (CHPZL *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_HPZLData = pDecoderStream->get_u8v(&s_fdHPZLData);
    }
    else
    {
        pDecoderStream->get_u8v(&s_fdHPZLData);
    }

}


void
CHPZL::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CHPZL::assimilateSubParameters (
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
CHPZL::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u8v(m_HPZLData, &s_fdHPZLData);

}




/*
*****************************************************************
**
** Parameter HPHMXH
**
*****************************************************************
*/


const CTypeDescriptor
CHPHMXH::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "HPHMXH",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    1009,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CHPHMXH::s_apFieldDescriptorTable[] =
{

    &s_fdHPHMXHData,
    NULL
};



const CFieldDescriptor
CHPHMXH::s_fdHPHMXHData =
{
    CFieldDescriptor::FT_U8V,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "HPHMXHData",	// m_pName
    NULL	// m_pEnumTable
};
CHPHMXH::CHPHMXH (void)
{
    m_pType = &s_typeDescriptor;

}

CHPHMXH::~CHPHMXH (void)
{
}


CElement *
CHPHMXH::s_construct (void)
{
    return (CElement *) new CHPHMXH();
}


void
CHPHMXH::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CHPHMXH * pTarget = (CHPHMXH *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_HPHMXHData = pDecoderStream->get_u8v(&s_fdHPHMXHData);
    }
    else
    {
        pDecoderStream->get_u8v(&s_fdHPHMXHData);
    }

}


void
CHPHMXH::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CHPHMXH::assimilateSubParameters (
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
CHPHMXH::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u8v(m_HPHMXHData, &s_fdHPHMXHData);

}




/*
*****************************************************************
**
** Parameter JYYXQ
**
*****************************************************************
*/


const CTypeDescriptor
CJYYXQ::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "JYYXQ",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    1010,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CJYYXQ::s_apFieldDescriptorTable[] =
{

    &s_fdJYYXQData,
    NULL
};



const CFieldDescriptor
CJYYXQ::s_fdJYYXQData =
{
    CFieldDescriptor::FT_U8V,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "JYYXQData",	// m_pName
    NULL	// m_pEnumTable
};
CJYYXQ::CJYYXQ (void)
{
    m_pType = &s_typeDescriptor;

}

CJYYXQ::~CJYYXQ (void)
{
}


CElement *
CJYYXQ::s_construct (void)
{
    return (CElement *) new CJYYXQ();
}


void
CJYYXQ::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CJYYXQ * pTarget = (CJYYXQ *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_JYYXQData = pDecoderStream->get_u8v(&s_fdJYYXQData);
    }
    else
    {
        pDecoderStream->get_u8v(&s_fdJYYXQData);
    }

}


void
CJYYXQ::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CJYYXQ::assimilateSubParameters (
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
CJYYXQ::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u8v(m_JYYXQData, &s_fdJYYXQData);

}




/*
*****************************************************************
**
** Parameter QZBFQ
**
*****************************************************************
*/


const CTypeDescriptor
CQZBFQ::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "QZBFQ",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    1011,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CQZBFQ::s_apFieldDescriptorTable[] =
{

    &s_fdQZBFQData,
    NULL
};



const CFieldDescriptor
CQZBFQ::s_fdQZBFQData =
{
    CFieldDescriptor::FT_U8V,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "QZBFQData",	// m_pName
    NULL	// m_pEnumTable
};
CQZBFQ::CQZBFQ (void)
{
    m_pType = &s_typeDescriptor;

}

CQZBFQ::~CQZBFQ (void)
{
}


CElement *
CQZBFQ::s_construct (void)
{
    return (CElement *) new CQZBFQ();
}


void
CQZBFQ::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CQZBFQ * pTarget = (CQZBFQ *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_QZBFQData = pDecoderStream->get_u8v(&s_fdQZBFQData);
    }
    else
    {
        pDecoderStream->get_u8v(&s_fdQZBFQData);
    }

}


void
CQZBFQ::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CQZBFQ::assimilateSubParameters (
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
CQZBFQ::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u8v(m_QZBFQData, &s_fdQZBFQData);

}




/*
*****************************************************************
**
** Parameter ZKZL
**
*****************************************************************
*/


const CTypeDescriptor
CZKZL::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "ZKZL",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    1012,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CZKZL::s_apFieldDescriptorTable[] =
{

    &s_fdZKZLData,
    NULL
};



const CFieldDescriptor
CZKZL::s_fdZKZLData =
{
    CFieldDescriptor::FT_U8V,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "ZKZLData",	// m_pName
    NULL	// m_pEnumTable
};
CZKZL::CZKZL (void)
{
    m_pType = &s_typeDescriptor;

}

CZKZL::~CZKZL (void)
{
}


CElement *
CZKZL::s_construct (void)
{
    return (CElement *) new CZKZL();
}


void
CZKZL::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CZKZL * pTarget = (CZKZL *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_ZKZLData = pDecoderStream->get_u8v(&s_fdZKZLData);
    }
    else
    {
        pDecoderStream->get_u8v(&s_fdZKZLData);
    }

}


void
CZKZL::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CZKZL::assimilateSubParameters (
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
CZKZL::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u8v(m_ZKZLData, &s_fdZKZLData);

}




/*
*****************************************************************
**
** Parameter CSYS
**
*****************************************************************
*/


const CTypeDescriptor
CCSYS::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "CSYS",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    1013,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CCSYS::s_apFieldDescriptorTable[] =
{

    &s_fdCSYSData,
    NULL
};



const CFieldDescriptor
CCSYS::s_fdCSYSData =
{
    CFieldDescriptor::FT_U8V,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "CSYSData",	// m_pName
    NULL	// m_pEnumTable
};
CCSYS::CCSYS (void)
{
    m_pType = &s_typeDescriptor;

}

CCSYS::~CCSYS (void)
{
}


CElement *
CCSYS::s_construct (void)
{
    return (CElement *) new CCSYS();
}


void
CCSYS::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CCSYS * pTarget = (CCSYS *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_CSYSData = pDecoderStream->get_u8v(&s_fdCSYSData);
    }
    else
    {
        pDecoderStream->get_u8v(&s_fdCSYSData);
    }

}


void
CCSYS::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CCSYS::assimilateSubParameters (
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
CCSYS::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u8v(m_CSYSData, &s_fdCSYSData);

}




/*
*****************************************************************
**
** Parameter HbWriteSpecResult
**
*****************************************************************
*/


const CTypeDescriptor
CHbWriteSpecResult::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "HbWriteSpecResult",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    513,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CHbWriteSpecResult::s_apFieldDescriptorTable[] =
{

    &s_fdResult,
    &s_fdResultDescription,
    &s_fdOpSpecID,
    NULL
};



const CFieldDescriptor
CHbWriteSpecResult::s_fdResult =
{
    CFieldDescriptor::FT_U8,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "Result",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CHbWriteSpecResult::s_fdResultDescription =
{
    CFieldDescriptor::FT_U8V,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "ResultDescription",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CHbWriteSpecResult::s_fdOpSpecID =
{
    CFieldDescriptor::FT_U16,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "OpSpecID",	// m_pName
    NULL	// m_pEnumTable
};
CHbWriteSpecResult::CHbWriteSpecResult (void)
{
    m_pType = &s_typeDescriptor;

    m_Result = 0;
    m_OpSpecID = 0;
}

CHbWriteSpecResult::~CHbWriteSpecResult (void)
{
}


CElement *
CHbWriteSpecResult::s_construct (void)
{
    return (CElement *) new CHbWriteSpecResult();
}


void
CHbWriteSpecResult::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CHbWriteSpecResult * pTarget = (CHbWriteSpecResult *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_Result = pDecoderStream->get_u8(&s_fdResult);
    }
    else
    {
        pDecoderStream->get_u8(&s_fdResult);
    }

    if(NULL != pTarget)
    {
        pTarget->m_ResultDescription = pDecoderStream->get_u8v(&s_fdResultDescription);
    }
    else
    {
        pDecoderStream->get_u8v(&s_fdResultDescription);
    }

    if(NULL != pTarget)
    {
        pTarget->m_OpSpecID = pDecoderStream->get_u16(&s_fdOpSpecID);
    }
    else
    {
        pDecoderStream->get_u16(&s_fdOpSpecID);
    }

}


void
CHbWriteSpecResult::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CHbWriteSpecResult::assimilateSubParameters (
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
CHbWriteSpecResult::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u8(m_Result, &s_fdResult);

    pEncoderStream->put_u8v(m_ResultDescription, &s_fdResultDescription);

    pEncoderStream->put_u16(m_OpSpecID, &s_fdOpSpecID);

}




/*
*****************************************************************
**
** Parameter ClientRequestSpecResult
**
*****************************************************************
*/


const CTypeDescriptor
CClientRequestSpecResult::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "ClientRequestSpecResult",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    512,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CClientRequestSpecResult::s_apFieldDescriptorTable[] =
{

    &s_fdOpSpecID,
    NULL
};



const CFieldDescriptor
CClientRequestSpecResult::s_fdOpSpecID =
{
    CFieldDescriptor::FT_U16,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "OpSpecID",	// m_pName
    NULL	// m_pEnumTable
};
CClientRequestSpecResult::CClientRequestSpecResult (void)
{
    m_pType = &s_typeDescriptor;

    m_OpSpecID = 0;
}

CClientRequestSpecResult::~CClientRequestSpecResult (void)
{
}


CElement *
CClientRequestSpecResult::s_construct (void)
{
    return (CElement *) new CClientRequestSpecResult();
}


void
CClientRequestSpecResult::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CClientRequestSpecResult * pTarget = (CClientRequestSpecResult *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_OpSpecID = pDecoderStream->get_u16(&s_fdOpSpecID);
    }
    else
    {
        pDecoderStream->get_u16(&s_fdOpSpecID);
    }

}


void
CClientRequestSpecResult::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CClientRequestSpecResult::assimilateSubParameters (
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
CClientRequestSpecResult::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u16(m_OpSpecID, &s_fdOpSpecID);

}




/*
*****************************************************************
**
** Message EnableCachedEventsAndReport
**
*****************************************************************
*/


const CTypeDescriptor
CEnableCachedEventsAndReport::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "EnableCachedEventsAndReport",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    580,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CEnableCachedEventsAndReport::s_apFieldDescriptorTable[] =
{

    NULL
};

CEnableCachedEventsAndReport::CEnableCachedEventsAndReport (void)
{
    m_pType = &s_typeDescriptor;

}

CEnableCachedEventsAndReport::~CEnableCachedEventsAndReport (void)
{
}


CElement *
CEnableCachedEventsAndReport::s_construct (void)
{
    return (CElement *) new CEnableCachedEventsAndReport();
}


void
CEnableCachedEventsAndReport::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CEnableCachedEventsAndReport * pTarget = (CEnableCachedEventsAndReport *) pTargetElement;


}


void
CEnableCachedEventsAndReport::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CEnableCachedEventsAndReport::assimilateSubParameters (
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
CEnableCachedEventsAndReport::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


}




/*
*****************************************************************
**
** Parameter CachedSelectAccessReport
**
*****************************************************************
*/


const CTypeDescriptor
CCachedSelectAccessReport::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "CachedSelectAccessReport",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    581,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CCachedSelectAccessReport::s_apFieldDescriptorTable[] =
{

    &s_fdSequenceID,
    &s_fdIsLastedFrame,
    NULL
};



const CFieldDescriptor
CCachedSelectAccessReport::s_fdSequenceID =
{
    CFieldDescriptor::FT_U16,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "SequenceID",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CCachedSelectAccessReport::s_fdIsLastedFrame =
{
    CFieldDescriptor::FT_U8,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "IsLastedFrame",	// m_pName
    NULL	// m_pEnumTable
};
CCachedSelectAccessReport::CCachedSelectAccessReport (void)
{
    m_pType = &s_typeDescriptor;

    m_SequenceID = 0;
    m_IsLastedFrame = 0;
    m_pStatus = NULL;
}

CCachedSelectAccessReport::~CCachedSelectAccessReport (void)
{
}


CElement *
CCachedSelectAccessReport::s_construct (void)
{
    return (CElement *) new CCachedSelectAccessReport();
}


void
CCachedSelectAccessReport::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CCachedSelectAccessReport * pTarget = (CCachedSelectAccessReport *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_SequenceID = pDecoderStream->get_u16(&s_fdSequenceID);
    }
    else
    {
        pDecoderStream->get_u16(&s_fdSequenceID);
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
CCachedSelectAccessReport::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CCachedSelectAccessReport::assimilateSubParameters (
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


    // 0-N of TagReportData
    pType = &CTagReportData::s_typeDescriptor;

    while(Cur != End && (*Cur)->m_pType == pType)
    {
        m_listTagReportData.push_back((CTagReportData *)*Cur);
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
CCachedSelectAccessReport::setStatus (
  CStatus *     pValue)
{
    removeSubParameterFromAllList(m_pStatus);
    delete m_pStatus;
    m_pStatus = pValue;
    addSubParameterToAllList(pValue);
    return RC_OK;
}

EResultCode
CCachedSelectAccessReport::addTagReportData (
  CTagReportData *     pValue)
{
    m_listTagReportData.push_back(pValue);
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CCachedSelectAccessReport::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u16(m_SequenceID, &s_fdSequenceID);

    pEncoderStream->put_u8(m_IsLastedFrame, &s_fdIsLastedFrame);

    pType = &CStatus::s_typeDescriptor;

    pEncoderStream->putRequiredSubParameter(m_pStatus, pType);

    pType = &CTagReportData::s_typeDescriptor;

    pEncoderStream->putOptionalSubParameterList((tListOfParameters *) &m_listTagReportData, pType);

}




/*
*****************************************************************
**
** Message CachedSelectAccessReportAck
**
*****************************************************************
*/


const CTypeDescriptor
CCachedSelectAccessReportAck::s_typeDescriptor =
{
    TRUE,		// m_bIsMessage
    "CachedSelectAccessReportAck",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    582,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CCachedSelectAccessReportAck::s_apFieldDescriptorTable[] =
{

    &s_fdSequenceID,
    NULL
};



const CFieldDescriptor
CCachedSelectAccessReportAck::s_fdSequenceID =
{
    CFieldDescriptor::FT_U16,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "SequenceID",	// m_pName
    NULL	// m_pEnumTable
};
CCachedSelectAccessReportAck::CCachedSelectAccessReportAck (void)
{
    m_pType = &s_typeDescriptor;

    m_SequenceID = 0;
}

CCachedSelectAccessReportAck::~CCachedSelectAccessReportAck (void)
{
}


CElement *
CCachedSelectAccessReportAck::s_construct (void)
{
    return (CElement *) new CCachedSelectAccessReportAck();
}


void
CCachedSelectAccessReportAck::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CCachedSelectAccessReportAck * pTarget = (CCachedSelectAccessReportAck *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_SequenceID = pDecoderStream->get_u16(&s_fdSequenceID);
    }
    else
    {
        pDecoderStream->get_u16(&s_fdSequenceID);
    }

}


void
CCachedSelectAccessReportAck::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CCachedSelectAccessReportAck::assimilateSubParameters (
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
CCachedSelectAccessReportAck::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u16(m_SequenceID, &s_fdSequenceID);

}




/*
*****************************************************************
**
** Parameter ClientRequestAck
**
*****************************************************************
*/


const CTypeDescriptor
CClientRequestAck::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "ClientRequestAck",	// m_pName
    NULL,	// m_pVendorDescriptor
    &g_nsdescllrp,	// m_pNamespaceDescriptor
    590,	// m_TypeNum
    NULL,    // m_pResponseType

    s_apFieldDescriptorTable,   // m_ppFieldDescriptorTable
    s_construct,                // m_pfConstruct
    s_decodeFields,             // m_pfDecodeFields
};



const CFieldDescriptor * const
CClientRequestAck::s_apFieldDescriptorTable[] =
{

    &s_fdAccessSpecID,
    &s_fdTID,
    NULL
};



const CFieldDescriptor
CClientRequestAck::s_fdAccessSpecID =
{
    CFieldDescriptor::FT_U32,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "AccessSpecID",	// m_pName
    NULL	// m_pEnumTable
};


const CFieldDescriptor
CClientRequestAck::s_fdTID =
{
    CFieldDescriptor::FT_U8V,	// m_EFieldType
    CFieldDescriptor::FMT_NORMAL,	// m_EFieldFormat
    "TID",	// m_pName
    NULL	// m_pEnumTable
};
CClientRequestAck::CClientRequestAck (void)
{
    m_pType = &s_typeDescriptor;

    m_AccessSpecID = 0;
}

CClientRequestAck::~CClientRequestAck (void)
{
}


CElement *
CClientRequestAck::s_construct (void)
{
    return (CElement *) new CClientRequestAck();
}


void
CClientRequestAck::s_decodeFields (
  CDecoderStream *              pDecoderStream,
  CElement *                    pTargetElement)
{
    CClientRequestAck * pTarget = (CClientRequestAck *) pTargetElement;


    if(NULL != pTarget)
    {
        pTarget->m_AccessSpecID = pDecoderStream->get_u32(&s_fdAccessSpecID);
    }
    else
    {
        pDecoderStream->get_u32(&s_fdAccessSpecID);
    }

    if(NULL != pTarget)
    {
        pTarget->m_TID = pDecoderStream->get_u8v(&s_fdTID);
    }
    else
    {
        pDecoderStream->get_u8v(&s_fdTID);
    }

}


void
CClientRequestAck::decodeFields (
  CDecoderStream *              pDecoderStream)
{
    s_decodeFields(pDecoderStream, (CElement *)this);
}


void
CClientRequestAck::assimilateSubParameters (
  CErrorDetails *               pError)
{
    tListOfParameters::iterator Cur = m_listAllSubParameters.begin();
    tListOfParameters::iterator End = m_listAllSubParameters.end();
    const CTypeDescriptor *     pType;



    // 0-N of choice OpSpec
    pType = NULL;

    while(Cur != End && COpSpec::isMember(*Cur))
    {
        m_listOpSpec.push_back(*Cur);
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
CClientRequestAck::addOpSpec (
  CParameter *                  pValue)
{
    if(!COpSpec::isMember(pValue))
    {
        return RC_InvalidChoiceMember;
    }

    m_listOpSpec.push_back(pValue);
    addSubParameterToAllList(pValue);
    return RC_OK;
}

void
CClientRequestAck::encode (
  CEncoderStream *              pEncoderStream) const
{
    const CTypeDescriptor *     pType;


    pEncoderStream->put_u32(m_AccessSpecID, &s_fdAccessSpecID);

    pEncoderStream->put_u8v(m_TID, &s_fdTID);

    pType = NULL;

    pEncoderStream->putOptionalSubParameterList((tListOfParameters *) &m_listOpSpec, pType);

}




/*
*****************************************************************
**
** Choice OpSpec
**
*****************************************************************
*/


const CTypeDescriptor
COpSpec::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "OpSpec",	// m_pName
    NULL,	// m_pVendorDescriptor
    NULL,	// m_pNamespaceDescriptor
    (llrp_u32_t)(-1),	// m_TypeNum
    NULL,   // m_ppFieldDescriptorTable
    NULL,                // m_pfConstruct
    NULL,             // m_pfDecodeFields
};

llrp_bool_t
COpSpec::isMember (
  CParameter *                  pParameter)
{
    const CTypeDescriptor *     pType;

    pType = pParameter->m_pType;


    if(&CHbReadSpec::s_typeDescriptor == pType)
    {
        return TRUE;
    }

    if(&CHbWriteSpec::s_typeDescriptor == pType)
    {
        return TRUE;
    }

    if(&CClientRequestSpec::s_typeDescriptor == pType)
    {
        return TRUE;
    }


    return FALSE;
}




/*
*****************************************************************
**
** Choice SelectSpecResult
**
*****************************************************************
*/


const CTypeDescriptor
CSelectSpecResult::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "SelectSpecResult",	// m_pName
    NULL,	// m_pVendorDescriptor
    NULL,	// m_pNamespaceDescriptor
    (llrp_u32_t)(-1),	// m_TypeNum
    NULL,   // m_ppFieldDescriptorTable
    NULL,                // m_pfConstruct
    NULL,             // m_pfDecodeFields
};

llrp_bool_t
CSelectSpecResult::isMember (
  CParameter *                  pParameter)
{
    const CTypeDescriptor *     pType;

    pType = pParameter->m_pType;


    if(&CGenaralSelectSpecResult::s_typeDescriptor == pType)
    {
        return TRUE;
    }

    if(&CCustomizedSelectSpecResult::s_typeDescriptor == pType)
    {
        return TRUE;
    }


    return FALSE;
}




/*
*****************************************************************
**
** Choice AccessSpecResult
**
*****************************************************************
*/


const CTypeDescriptor
CAccessSpecResult::s_typeDescriptor =
{
    FALSE,		// m_bIsMessage
    "AccessSpecResult",	// m_pName
    NULL,	// m_pVendorDescriptor
    NULL,	// m_pNamespaceDescriptor
    (llrp_u32_t)(-1),	// m_TypeNum
    NULL,   // m_ppFieldDescriptorTable
    NULL,                // m_pfConstruct
    NULL,             // m_pfDecodeFields
};

llrp_bool_t
CAccessSpecResult::isMember (
  CParameter *                  pParameter)
{
    const CTypeDescriptor *     pType;

    pType = pParameter->m_pType;


    if(&CHbReadSpecResult::s_typeDescriptor == pType)
    {
        return TRUE;
    }

    if(&CHbCustomizedReadSpecResult::s_typeDescriptor == pType)
    {
        return TRUE;
    }

    if(&CHbWriteSpecResult::s_typeDescriptor == pType)
    {
        return TRUE;
    }

    if(&CClientRequestSpecResult::s_typeDescriptor == pType)
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

    pTypeRegistry->enroll(&CSelectSpec::s_typeDescriptor);

    pTypeRegistry->enroll(&CSelectSpecStartTrigger::s_typeDescriptor);

    pTypeRegistry->enroll(&CPeriodicTrigger::s_typeDescriptor);

    pTypeRegistry->enroll(&CGPITrigger::s_typeDescriptor);

    pTypeRegistry->enroll(&CSelectSpecStopTrigger::s_typeDescriptor);

    pTypeRegistry->enroll(&CAntennaSpec::s_typeDescriptor);

    pTypeRegistry->enroll(&CAntennaSpecStopTrigger::s_typeDescriptor);

    pTypeRegistry->enroll(&CTagObservationTrigger::s_typeDescriptor);

    pTypeRegistry->enroll(&CRfSpec::s_typeDescriptor);

    pTypeRegistry->enroll(&CMemoryBank::s_typeDescriptor);

    pTypeRegistry->enroll(&CSelectReportSpec::s_typeDescriptor);

    pTypeRegistry->enroll(&CReportDestination::s_typeDescriptor);

    pTypeRegistry->enroll(&CAccessSpec::s_typeDescriptor);

    pTypeRegistry->enroll(&CAccessSpecStopTrigger::s_typeDescriptor);

    pTypeRegistry->enroll(&CAccessCommand::s_typeDescriptor);

    pTypeRegistry->enroll(&CSecurityModuleSpec::s_typeDescriptor);

    pTypeRegistry->enroll(&CHbMatchSpec::s_typeDescriptor);

    pTypeRegistry->enroll(&CHbTargetTag::s_typeDescriptor);

    pTypeRegistry->enroll(&CHbReadSpec::s_typeDescriptor);

    pTypeRegistry->enroll(&CHbWriteSpec::s_typeDescriptor);

    pTypeRegistry->enroll(&CClientRequestSpec::s_typeDescriptor);

    pTypeRegistry->enroll(&CAccessReportSpec::s_typeDescriptor);

    pTypeRegistry->enroll(&CTagReportData::s_typeDescriptor);

    pTypeRegistry->enroll(&CSelectSpecID::s_typeDescriptor);

    pTypeRegistry->enroll(&CSpecIndex::s_typeDescriptor);

    pTypeRegistry->enroll(&CRfSpecID::s_typeDescriptor);

    pTypeRegistry->enroll(&CAntennaID::s_typeDescriptor);

    pTypeRegistry->enroll(&CPeakRSSI::s_typeDescriptor);

    pTypeRegistry->enroll(&CFirstSeenTimestampUTC::s_typeDescriptor);

    pTypeRegistry->enroll(&CLastSeenTimestampUTC::s_typeDescriptor);

    pTypeRegistry->enroll(&CTagSeenCount::s_typeDescriptor);

    pTypeRegistry->enroll(&CAccessSpecID::s_typeDescriptor);

    pTypeRegistry->enroll(&CGenaralSelectSpecResult::s_typeDescriptor);

    pTypeRegistry->enroll(&CCustomizedSelectSpecResult::s_typeDescriptor);

    pTypeRegistry->enroll(&CHbCustomizedReadSpecResult::s_typeDescriptor);

    pTypeRegistry->enroll(&CReadDataInfo::s_typeDescriptor);

    pTypeRegistry->enroll(&CHbReadSpecResult::s_typeDescriptor);

    pTypeRegistry->enroll(&CCID::s_typeDescriptor);

    pTypeRegistry->enroll(&CFPDH::s_typeDescriptor);

    pTypeRegistry->enroll(&CSYXZ::s_typeDescriptor);

    pTypeRegistry->enroll(&CCCRQ::s_typeDescriptor);

    pTypeRegistry->enroll(&CCLLX::s_typeDescriptor);

    pTypeRegistry->enroll(&CGL::s_typeDescriptor);

    pTypeRegistry->enroll(&CPL::s_typeDescriptor);

    pTypeRegistry->enroll(&CHPZL::s_typeDescriptor);

    pTypeRegistry->enroll(&CHPHMXH::s_typeDescriptor);

    pTypeRegistry->enroll(&CJYYXQ::s_typeDescriptor);

    pTypeRegistry->enroll(&CQZBFQ::s_typeDescriptor);

    pTypeRegistry->enroll(&CZKZL::s_typeDescriptor);

    pTypeRegistry->enroll(&CCSYS::s_typeDescriptor);

    pTypeRegistry->enroll(&CHbWriteSpecResult::s_typeDescriptor);

    pTypeRegistry->enroll(&CClientRequestSpecResult::s_typeDescriptor);

    pTypeRegistry->enroll(&CEnableCachedEventsAndReport::s_typeDescriptor);

    pTypeRegistry->enroll(&CCachedSelectAccessReport::s_typeDescriptor);

    pTypeRegistry->enroll(&CCachedSelectAccessReportAck::s_typeDescriptor);

    pTypeRegistry->enroll(&CClientRequestAck::s_typeDescriptor);

    pTypeRegistry->enroll(&CAddSelectSpec::s_typeDescriptor);

    pTypeRegistry->enroll(&CAddSelectSpecAck::s_typeDescriptor);

    pTypeRegistry->enroll(&CDeleteSelectSpec::s_typeDescriptor);

    pTypeRegistry->enroll(&CDeleteSelectSpecAck::s_typeDescriptor);

    pTypeRegistry->enroll(&CStartSelectSpec::s_typeDescriptor);

    pTypeRegistry->enroll(&CStartSelectSpecAck::s_typeDescriptor);

    pTypeRegistry->enroll(&CStopSelectSpec::s_typeDescriptor);

    pTypeRegistry->enroll(&CStopSelectSpecAck::s_typeDescriptor);

    pTypeRegistry->enroll(&CEnableSelectSpec::s_typeDescriptor);

    pTypeRegistry->enroll(&CEnableSelectSpecAck::s_typeDescriptor);

    pTypeRegistry->enroll(&CDisableSelectSpec::s_typeDescriptor);

    pTypeRegistry->enroll(&CDisableSelectSpecAck::s_typeDescriptor);

    pTypeRegistry->enroll(&CGetSelectSpec::s_typeDescriptor);

    pTypeRegistry->enroll(&CGetSelectSpecAck::s_typeDescriptor);

    pTypeRegistry->enroll(&CAddAccessSpec::s_typeDescriptor);

    pTypeRegistry->enroll(&CAddAccessSpecAck::s_typeDescriptor);

    pTypeRegistry->enroll(&CDeleteAccessSpec::s_typeDescriptor);

    pTypeRegistry->enroll(&CDeleteAccessSpecAck::s_typeDescriptor);

    pTypeRegistry->enroll(&CEnableAccessSpec::s_typeDescriptor);

    pTypeRegistry->enroll(&CEnableAccessSpecAck::s_typeDescriptor);

    pTypeRegistry->enroll(&CDisableAccessSpec::s_typeDescriptor);

    pTypeRegistry->enroll(&CDisableAccessSpecAck::s_typeDescriptor);

    pTypeRegistry->enroll(&CGetAccessSpec::s_typeDescriptor);

    pTypeRegistry->enroll(&CGetAccessSpecAck::s_typeDescriptor);

    pTypeRegistry->enroll(&CTagSelectAccessReport::s_typeDescriptor);

    pTypeRegistry->enroll(&CClientRequestOp::s_typeDescriptor);

    pTypeRegistry->enroll(&CClientRequestOpAck::s_typeDescriptor);

}
*/


};//end of namespace LLRP

