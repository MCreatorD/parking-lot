#ifndef __LLRP_OPERATION_H__
#define __LLRP_OPERATION_H__

#include "LLRP_General.h"
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
class CHbMatchSpec;
class CHbTargetTag;
class CHbReadSpec;
class CHbWriteSpec;
class CClientRequestSpec;
class CAccessReportSpec;
class CTagReportData;
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
 ** @brief  Global enumeration EAccessCurrentState  for LLRP enumerated field AccessCurrentState
 **




 **/

enum EAccessCurrentState
{
AccessCurrentState_Disabled = 0, /**< Disabled */ AccessCurrentState_Active = 1, /**< Active */
};

extern const SEnumTableEntry
g_estAccessCurrentState[];


/**
 ** @brief  Global enumeration ESelectCurrentState  for LLRP enumerated field SelectCurrentState
 **





 **/

enum ESelectCurrentState
{
SelectCurrentState_Disabled = 0, /**< Disabled */ SelectCurrentState_Inactive = 1, /**< Inactive */ SelectCurrentState_Active = 2, /**< Active */
};

extern const SEnumTableEntry
g_estSelectCurrentState[];


/**
 ** @brief  Global enumeration EPersistence  for LLRP enumerated field Persistence
 **




 **/

enum EPersistence
{
Persistence_Noneed = 0, /**< Noneed */ Persistence_Need = 1, /**< Need */
};

extern const SEnumTableEntry
g_estPersistence[];


/**
 ** @brief  Global enumeration ESelectSpecStartTriggerType  for LLRP enumerated field SelectSpecStartTriggerType
 **






 **/

enum ESelectSpecStartTriggerType
{
SelectSpecStartTriggerType_Unconditional = 0, /**< Unconditional */ SelectSpecStartTriggerType_Immediately = 1, /**< Immediately */ SelectSpecStartTriggerType_Periodic = 2, /**< Periodic */ SelectSpecStartTriggerType_GPI = 3, /**< GPI */
};

extern const SEnumTableEntry
g_estSelectSpecStartTriggerType[];


/**
 ** @brief  Global enumeration ESelectSpecStopTriggerType  for LLRP enumerated field SelectSpecStopTriggerType
 **





 **/

enum ESelectSpecStopTriggerType
{
SelectSpecStopTriggerType_Unconditional = 0, /**< Unconditional */ SelectSpecStopTriggerType_Persistent = 1, /**< Persistent */ SelectSpecStopTriggerType_GPI = 2, /**< GPI */
};

extern const SEnumTableEntry
g_estSelectSpecStopTriggerType[];


/**
 ** @brief  Global enumeration EAntennaSpecStopTriggerType  for LLRP enumerated field AntennaSpecStopTriggerType
 **






 **/

enum EAntennaSpecStopTriggerType
{
AntennaSpecStopTriggerType_SelectSpecStop = 0, /**< SelectSpecStop */ AntennaSpecStopTriggerType_Persistent = 1, /**< Persistent */ AntennaSpecStopTriggerType_GPI = 2, /**< GPI */ AntennaSpecStopTriggerType_LabelRule = 3, /**< LabelRule */
};

extern const SEnumTableEntry
g_estAntennaSpecStopTriggerType[];


/**
 ** @brief  Global enumeration ETriggerType  for LLRP enumerated field TriggerType
 **





 **/

enum ETriggerType
{
TriggerType_NLabels = 0, /**< NLabels */ TriggerType_TMilliseconds = 1, /**< TMilliseconds */ TriggerType_ATimes = 2, /**< ATimes */
};

extern const SEnumTableEntry
g_estTriggerType[];


/**
 ** @brief  Global enumeration EProtocolID  for LLRP enumerated field ProtocolID
 **



 **/

enum EProtocolID
{
ProtocolID_HangBiao = 0, /**< HangBiao */
};

extern const SEnumTableEntry
g_estProtocolID[];


/**
 ** @brief  Global enumeration ESelectType  for LLRP enumerated field SelectType
 **




 **/

enum ESelectType
{
SelectType_Check = 0, /**< Check */ SelectType_Read = 1, /**< Read */
};

extern const SEnumTableEntry
g_estSelectType[];


/**
 ** @brief  Global enumeration ESelectReportTrigger  for LLRP enumerated field SelectReportTrigger
 **






 **/

enum ESelectReportTrigger
{
SelectReportTrigger_Unconditional = 0, /**< Unconditional */ SelectReportTrigger_Antenna = 1, /**< Antenna */ SelectReportTrigger_Label = 2, /**< Label */ SelectReportTrigger_NoReport = 3, /**< NoReport */
};

extern const SEnumTableEntry
g_estSelectReportTrigger[];


/**
 ** @brief  Global enumeration EAccessSpecStopTriggerType  for LLRP enumerated field AccessSpecStopTriggerType
 **




 **/

enum EAccessSpecStopTriggerType
{
AccessSpecStopTriggerType_Unconditional = 0, /**< Unconditional */ AccessSpecStopTriggerType_OperatingTimes = 1, /**< OperatingTimes */
};

extern const SEnumTableEntry
g_estAccessSpecStopTriggerType[];


/**
 ** @brief  Global enumeration EMemoryType  for LLRP enumerated field MemoryType
 **




 **/

enum EMemoryType
{
MemoryType_TID = 0, /**< TID */ MemoryType_User = 1, /**< User */
};

extern const SEnumTableEntry
g_estMemoryType[];


/**
 ** @brief  Global enumeration EMatchType  for LLRP enumerated field MatchType
 **




 **/

enum EMatchType
{
MatchType_Forward = 0, /**< Forward */ MatchType_Reverse = 1, /**< Reverse */
};

extern const SEnumTableEntry
g_estMatchType[];


/**
 ** @brief  Global enumeration EAccessMode for LLRP enumerated field AccessMode
 **






 **/

enum EAccessMode
{
AccessMode_LowerHalf = 0, /**< LowerHalf */ AccessMode_UpperHalf = 1, /**< UpperHalf */ AccessMode_Whole = 2, /**< Whole */ AccessMode_TwoTimes = 3, /**< TwoTimes */
};

extern const SEnumTableEntry
g_estAccessMode[];


/**
 ** @brief  Global enumeration EDataMode for LLRP enumerated field DataMode
 **




 **/

enum EDataMode
{
DataMode_Ciphertext = 0, /**< Ciphertext */ DataMode_Plaintext = 1, /**< Plaintext */
};

extern const SEnumTableEntry
g_estDataMode[];


/**
 ** @brief  Global enumeration EBAKReadMode for LLRP enumerated field BAKReadMode
 **




 **/

enum EBAKReadMode
{
BAKReadMode_NormalRead = 0, /**< NormalRead */ BAKReadMode_FastRead = 1, /**< FastRead */
};

extern const SEnumTableEntry
g_estBAKReadMode[];




/**
 ** @brief  Global enumeration EAccessReportTrigger  for LLRP enumerated field AccessReportTrigger
 **




 **/

enum EAccessReportTrigger
{
AccessReportTrigger_SelectReportCreate = 0, /**< SelectReportCreate */ AccessReportTrigger_AccessSpecStop = 1, /**< AccessSpecStop */
};

extern const SEnumTableEntry
g_estAccessReportTrigger[];


/**
 * \defgroup CoreMessage  Core Message Classes
 * Classes to manipulate the messages defined by the Core LLRP protocol
 */
/*@{*/

/**
 ** @brief  Class Definition CAddSelectSpec for LLRP message AddSelectSpec
 **



 **/

class CAddSelectSpec : public CMessage
{
  public:
    CAddSelectSpec (void);
    ~CAddSelectSpec (void);

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
    CSelectSpec * m_pSelectSpec;

  public:
    /** @brief Get accessor functions for the LLRP SelectSpec sub-parameter */
    inline CSelectSpec *
    getSelectSpec (void)
    {
        return m_pSelectSpec;
    }

    /** @brief Set accessor functions for the LLRP SelectSpec sub-parameter */
    EResultCode
    setSelectSpec (
      CSelectSpec * pValue);


};


/**
 ** @brief  Class Definition CAddSelectSpecAck for LLRP message AddSelectSpecAck
 **



 **/

class CAddSelectSpecAck : public CMessage
{
  public:
    CAddSelectSpecAck (void);
    ~CAddSelectSpecAck (void);

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
 ** @brief  Class Definition CDeleteSelectSpec for LLRP message DeleteSelectSpec
 **



 **/

class CDeleteSelectSpec : public CMessage
{
  public:
    CDeleteSelectSpec (void);
    ~CDeleteSelectSpec (void);

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
    llrp_u32_t m_SelectSpecID;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdSelectSpecID;
//@}

    /** @brief Get accessor functions for the LLRP SelectSpecID field */
    inline llrp_u32_t
    getSelectSpecID (void)
    {
        return m_SelectSpecID;
    }

    /** @brief Set accessor functions for the LLRP SelectSpecID field */
    inline void
    setSelectSpecID (
      llrp_u32_t  value)
    {
        m_SelectSpecID = value;
    }


};


/**
 ** @brief  Class Definition CDeleteSelectSpecAck for LLRP message DeleteSelectSpecAck
 **



 **/

class CDeleteSelectSpecAck : public CMessage
{
  public:
    CDeleteSelectSpecAck (void);
    ~CDeleteSelectSpecAck (void);

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
 ** @brief  Class Definition CStartSelectSpec for LLRP message StartSelectSpec
 **



 **/

class CStartSelectSpec : public CMessage
{
  public:
    CStartSelectSpec (void);
    ~CStartSelectSpec (void);

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
    llrp_u32_t m_SelectSpecID;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdSelectSpecID;
//@}

    /** @brief Get accessor functions for the LLRP SelectSpecID field */
    inline llrp_u32_t
    getSelectSpecID (void)
    {
        return m_SelectSpecID;
    }

    /** @brief Set accessor functions for the LLRP SelectSpecID field */
    inline void
    setSelectSpecID (
      llrp_u32_t  value)
    {
        m_SelectSpecID = value;
    }


};


/**
 ** @brief  Class Definition CStartSelectSpecAck for LLRP message StartSelectSpecAck
 **



 **/

class CStartSelectSpecAck : public CMessage
{
  public:
    CStartSelectSpecAck (void);
    ~CStartSelectSpecAck (void);

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
 ** @brief  Class Definition CStopSelectSpec for LLRP message StopSelectSpec
 **



 **/

class CStopSelectSpec : public CMessage
{
  public:
    CStopSelectSpec (void);
    ~CStopSelectSpec (void);

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
    llrp_u32_t m_SelectSpecID;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdSelectSpecID;
//@}

    /** @brief Get accessor functions for the LLRP SelectSpecID field */
    inline llrp_u32_t
    getSelectSpecID (void)
    {
        return m_SelectSpecID;
    }

    /** @brief Set accessor functions for the LLRP SelectSpecID field */
    inline void
    setSelectSpecID (
      llrp_u32_t  value)
    {
        m_SelectSpecID = value;
    }


};


/**
 ** @brief  Class Definition CStopSelectSpecAck for LLRP message StopSelectSpecAck
 **



 **/

class CStopSelectSpecAck : public CMessage
{
  public:
    CStopSelectSpecAck (void);
    ~CStopSelectSpecAck (void);

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
 ** @brief  Class Definition CEnableSelectSpec for LLRP message EnableSelectSpec
 **



 **/

class CEnableSelectSpec : public CMessage
{
  public:
    CEnableSelectSpec (void);
    ~CEnableSelectSpec (void);

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
    llrp_u32_t m_SelectSpecID;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdSelectSpecID;
//@}

    /** @brief Get accessor functions for the LLRP SelectSpecID field */
    inline llrp_u32_t
    getSelectSpecID (void)
    {
        return m_SelectSpecID;
    }

    /** @brief Set accessor functions for the LLRP SelectSpecID field */
    inline void
    setSelectSpecID (
      llrp_u32_t  value)
    {
        m_SelectSpecID = value;
    }


};


/**
 ** @brief  Class Definition CEnableSelectSpecAck for LLRP message EnableSelectSpecAck
 **



 **/

class CEnableSelectSpecAck : public CMessage
{
  public:
    CEnableSelectSpecAck (void);
    ~CEnableSelectSpecAck (void);

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
 ** @brief  Class Definition CDisableSelectSpec for LLRP message DisableSelectSpec
 **



 **/

class CDisableSelectSpec : public CMessage
{
  public:
    CDisableSelectSpec (void);
    ~CDisableSelectSpec (void);

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
    llrp_u32_t m_SelectSpecID;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdSelectSpecID;
//@}

    /** @brief Get accessor functions for the LLRP SelectSpecID field */
    inline llrp_u32_t
    getSelectSpecID (void)
    {
        return m_SelectSpecID;
    }

    /** @brief Set accessor functions for the LLRP SelectSpecID field */
    inline void
    setSelectSpecID (
      llrp_u32_t  value)
    {
        m_SelectSpecID = value;
    }


};


/**
 ** @brief  Class Definition CDisableSelectSpecAck for LLRP message DisableSelectSpecAck
 **



 **/

class CDisableSelectSpecAck : public CMessage
{
  public:
    CDisableSelectSpecAck (void);
    ~CDisableSelectSpecAck (void);

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
 ** @brief  Class Definition CGetSelectSpec for LLRP message GetSelectSpec
 **


 **/

class CGetSelectSpec : public CMessage
{
  public:
    CGetSelectSpec (void);
    ~CGetSelectSpec (void);

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
 ** @brief  Class Definition CGetSelectSpecAck for LLRP message GetSelectSpecAck
 **




 **/

class CGetSelectSpecAck : public CMessage
{
  public:
    CGetSelectSpecAck (void);
    ~CGetSelectSpecAck (void);

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
    std::list<CSelectSpec *> m_listSelectSpec;

  public:
     /** @brief  Returns the first element of the SelectSpec sub-parameter list*/
    inline std::list<CSelectSpec *>::iterator
    beginSelectSpec (void)
    {
        return m_listSelectSpec.begin();
    }

     /** @brief  Returns the last element of the SelectSpec sub-parameter list*/
    inline std::list<CSelectSpec *>::iterator
    endSelectSpec (void)
    {
        return m_listSelectSpec.end();
    }

     /** @brief  Clears the LLRP SelectSpec sub-parameter list*/
    inline void
    clearSelectSpec (void)
    {
        clearSubParameterList ((tListOfParameters *) &m_listSelectSpec);
    }

    EResultCode
     /** @brief  Add a SelectSpec to the LLRP sub-parameter list*/
    addSelectSpec (
      CSelectSpec * pValue);


};


/**
 ** @brief  Class Definition CAddAccessSpec for LLRP message AddAccessSpec
 **



 **/

class CAddAccessSpec : public CMessage
{
  public:
    CAddAccessSpec (void);
    ~CAddAccessSpec (void);

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
    CAccessSpec * m_pAccessSpec;

  public:
    /** @brief Get accessor functions for the LLRP AccessSpec sub-parameter */
    inline CAccessSpec *
    getAccessSpec (void)
    {
        return m_pAccessSpec;
    }

    /** @brief Set accessor functions for the LLRP AccessSpec sub-parameter */
    EResultCode
    setAccessSpec (
      CAccessSpec * pValue);


};


/**
 ** @brief  Class Definition CAddAccessSpecAck for LLRP message AddAccessSpecAck
 **



 **/

class CAddAccessSpecAck : public CMessage
{
  public:
    CAddAccessSpecAck (void);
    ~CAddAccessSpecAck (void);

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
 ** @brief  Class Definition CDeleteAccessSpec for LLRP message DeleteAccessSpec
 **



 **/

class CDeleteAccessSpec : public CMessage
{
  public:
    CDeleteAccessSpec (void);
    ~CDeleteAccessSpec (void);

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
    llrp_u32_t m_AccessSpecID;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdAccessSpecID;
//@}

    /** @brief Get accessor functions for the LLRP AccessSpecID field */
    inline llrp_u32_t
    getAccessSpecID (void)
    {
        return m_AccessSpecID;
    }

    /** @brief Set accessor functions for the LLRP AccessSpecID field */
    inline void
    setAccessSpecID (
      llrp_u32_t  value)
    {
        m_AccessSpecID = value;
    }


};


/**
 ** @brief  Class Definition CDeleteAccessSpecAck for LLRP message DeleteAccessSpecAck
 **



 **/

class CDeleteAccessSpecAck : public CMessage
{
  public:
    CDeleteAccessSpecAck (void);
    ~CDeleteAccessSpecAck (void);

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
 ** @brief  Class Definition CEnableAccessSpec for LLRP message EnableAccessSpec
 **



 **/

class CEnableAccessSpec : public CMessage
{
  public:
    CEnableAccessSpec (void);
    ~CEnableAccessSpec (void);

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
    llrp_u32_t m_AccessSpecID;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdAccessSpecID;
//@}

    /** @brief Get accessor functions for the LLRP AccessSpecID field */
    inline llrp_u32_t
    getAccessSpecID (void)
    {
        return m_AccessSpecID;
    }

    /** @brief Set accessor functions for the LLRP AccessSpecID field */
    inline void
    setAccessSpecID (
      llrp_u32_t  value)
    {
        m_AccessSpecID = value;
    }


};


/**
 ** @brief  Class Definition CEnableAccessSpecAck for LLRP message EnableAccessSpecAck
 **



 **/

class CEnableAccessSpecAck : public CMessage
{
  public:
    CEnableAccessSpecAck (void);
    ~CEnableAccessSpecAck (void);

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
 ** @brief  Class Definition CDisableAccessSpec for LLRP message DisableAccessSpec
 **



 **/

class CDisableAccessSpec : public CMessage
{
  public:
    CDisableAccessSpec (void);
    ~CDisableAccessSpec (void);

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
    llrp_u32_t m_AccessSpecID;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdAccessSpecID;
//@}

    /** @brief Get accessor functions for the LLRP AccessSpecID field */
    inline llrp_u32_t
    getAccessSpecID (void)
    {
        return m_AccessSpecID;
    }

    /** @brief Set accessor functions for the LLRP AccessSpecID field */
    inline void
    setAccessSpecID (
      llrp_u32_t  value)
    {
        m_AccessSpecID = value;
    }


};


/**
 ** @brief  Class Definition CDisableAccessSpecAck for LLRP message DisableAccessSpecAck
 **



 **/

class CDisableAccessSpecAck : public CMessage
{
  public:
    CDisableAccessSpecAck (void);
    ~CDisableAccessSpecAck (void);

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
 ** @brief  Class Definition CGetAccessSpec for LLRP message GetAccessSpec
 **


 **/

class CGetAccessSpec : public CMessage
{
  public:
    CGetAccessSpec (void);
    ~CGetAccessSpec (void);

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
 ** @brief  Class Definition CGetAccessSpecAck for LLRP message GetAccessSpecAck
 **




 **/

class CGetAccessSpecAck : public CMessage
{
  public:
    CGetAccessSpecAck (void);
    ~CGetAccessSpecAck (void);

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
    std::list<CAccessSpec *> m_listAccessSpec;

  public:
     /** @brief  Returns the first element of the AccessSpec sub-parameter list*/
    inline std::list<CAccessSpec *>::iterator
    beginAccessSpec (void)
    {
        return m_listAccessSpec.begin();
    }

     /** @brief  Returns the last element of the AccessSpec sub-parameter list*/
    inline std::list<CAccessSpec *>::iterator
    endAccessSpec (void)
    {
        return m_listAccessSpec.end();
    }

     /** @brief  Clears the LLRP AccessSpec sub-parameter list*/
    inline void
    clearAccessSpec (void)
    {
        clearSubParameterList ((tListOfParameters *) &m_listAccessSpec);
    }

    EResultCode
     /** @brief  Add a AccessSpec to the LLRP sub-parameter list*/
    addAccessSpec (
      CAccessSpec * pValue);


};


/**
 ** @brief  Class Definition CTagSelectAccessReport for LLRP message TagSelectAccessReport
 **



 **/

class CTagSelectAccessReport : public CMessage
{
  public:
    CTagSelectAccessReport (void);
    ~CTagSelectAccessReport (void);

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
    std::list<CTagReportData *> m_listTagReportData;

  public:
     /** @brief  Returns the first element of the TagReportData sub-parameter list*/
    inline std::list<CTagReportData *>::iterator
    beginTagReportData (void)
    {
        return m_listTagReportData.begin();
    }

     /** @brief  Returns the last element of the TagReportData sub-parameter list*/
    inline std::list<CTagReportData *>::iterator
    endTagReportData (void)
    {
        return m_listTagReportData.end();
    }

     /** @brief  Clears the LLRP TagReportData sub-parameter list*/
    inline void
    clearTagReportData (void)
    {
        clearSubParameterList ((tListOfParameters *) &m_listTagReportData);
    }

    EResultCode
     /** @brief  Add a TagReportData to the LLRP sub-parameter list*/
    addTagReportData (
      CTagReportData * pValue);


};


/**
 ** @brief  Class Definition CClientRequestOp for LLRP message ClientRequestOp
 **



 **/

class CClientRequestOp : public CMessage
{
  public:
    CClientRequestOp (void);
    ~CClientRequestOp (void);

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
    CTagReportData * m_pTagReportData;

  public:
    /** @brief Get accessor functions for the LLRP TagReportData sub-parameter */
    inline CTagReportData *
    getTagReportData (void)
    {
        return m_pTagReportData;
    }

    /** @brief Set accessor functions for the LLRP TagReportData sub-parameter */
    EResultCode
    setTagReportData (
      CTagReportData * pValue);


};


/**
 ** @brief  Class Definition CClientRequestOpAck for LLRP message ClientRequestOpAck
 **



 **/

class CClientRequestOpAck : public CMessage
{
  public:
    CClientRequestOpAck (void);
    ~CClientRequestOpAck (void);

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
    CClientRequestAck * m_pClientRequestAck;

  public:
    /** @brief Get accessor functions for the LLRP ClientRequestAck sub-parameter */
    inline CClientRequestAck *
    getClientRequestAck (void)
    {
        return m_pClientRequestAck;
    }

    /** @brief Set accessor functions for the LLRP ClientRequestAck sub-parameter */
    EResultCode
    setClientRequestAck (
      CClientRequestAck * pValue);


};


/*@}*/

/**
 * \defgroup CoreParameter Core Parameter Classes
 * Classes to manipulate the parameters defined by the Core LLRP protocol
 */
/*@{*/

/**
 ** @brief  Class Definition CSelectSpec for LLRP parameter SelectSpec
 **











 **/

class CSelectSpec : public CParameter
{
  public:
    CSelectSpec (void);
    ~CSelectSpec (void);

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
    llrp_u32_t m_SelectSpecID;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdSelectSpecID;
//@}

    /** @brief Get accessor functions for the LLRP SelectSpecID field */
    inline llrp_u32_t
    getSelectSpecID (void)
    {
        return m_SelectSpecID;
    }

    /** @brief Set accessor functions for the LLRP SelectSpecID field */
    inline void
    setSelectSpecID (
      llrp_u32_t  value)
    {
        m_SelectSpecID = value;
    }


  protected:
    llrp_u8_t  m_Priority;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdPriority;
//@}

    /** @brief Get accessor functions for the LLRP Priority field */
    inline llrp_u8_t
    getPriority (void)
    {
        return m_Priority;
    }

    /** @brief Set accessor functions for the LLRP Priority field */
    inline void
    setPriority (
      llrp_u8_t   value)
    {
        m_Priority = value;
    }


  protected:
    ESelectCurrentState m_ESelectCurrentState ;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdSelectCurrentState;
//@}

    /** @brief Get accessor functions for the LLRP SelectCurrentState field */
    inline ESelectCurrentState
    getSelectCurrentState (void)
    {
        return m_ESelectCurrentState ;
    }

    /** @brief Set accessor functions for the LLRP SelectCurrentState field */
    inline void
    setSelectCurrentState (
      ESelectCurrentState  value)
    {
        m_ESelectCurrentState  = value;
    }


  protected:
    EPersistence m_EPersistence ;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdPersistence;
//@}

    /** @brief Get accessor functions for the LLRP Persistence field */
    inline EPersistence
    getPersistence (void)
    {
        return m_EPersistence ;
    }

    /** @brief Set accessor functions for the LLRP Persistence field */
    inline void
    setPersistence (
      EPersistence  value)
    {
        m_EPersistence  = value;
    }


  protected:
    CSelectSpecStartTrigger * m_pSelectSpecStartTrigger;

  public:
    /** @brief Get accessor functions for the LLRP SelectSpecStartTrigger sub-parameter */
    inline CSelectSpecStartTrigger *
    getSelectSpecStartTrigger (void)
    {
        return m_pSelectSpecStartTrigger;
    }

    /** @brief Set accessor functions for the LLRP SelectSpecStartTrigger sub-parameter */
    EResultCode
    setSelectSpecStartTrigger (
      CSelectSpecStartTrigger * pValue);


  protected:
    CSelectSpecStopTrigger * m_pSelectSpecStopTrigger;

  public:
    /** @brief Get accessor functions for the LLRP SelectSpecStopTrigger sub-parameter */
    inline CSelectSpecStopTrigger *
    getSelectSpecStopTrigger (void)
    {
        return m_pSelectSpecStopTrigger;
    }

    /** @brief Set accessor functions for the LLRP SelectSpecStopTrigger sub-parameter */
    EResultCode
    setSelectSpecStopTrigger (
      CSelectSpecStopTrigger * pValue);


  protected:
    std::list<CAntennaSpec *> m_listAntennaSpec;

  public:
     /** @brief  Returns the first element of the AntennaSpec sub-parameter list*/
    inline std::list<CAntennaSpec *>::iterator
    beginAntennaSpec (void)
    {
        return m_listAntennaSpec.begin();
    }

     /** @brief  Returns the last element of the AntennaSpec sub-parameter list*/
    inline std::list<CAntennaSpec *>::iterator
    endAntennaSpec (void)
    {
        return m_listAntennaSpec.end();
    }

     /** @brief  Clears the LLRP AntennaSpec sub-parameter list*/
    inline void
    clearAntennaSpec (void)
    {
        clearSubParameterList ((tListOfParameters *) &m_listAntennaSpec);
    }

    EResultCode
     /** @brief  Add a AntennaSpec to the LLRP sub-parameter list*/
    addAntennaSpec (
      CAntennaSpec * pValue);


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


};


/**
 ** @brief  Class Definition CSelectSpecStartTrigger for LLRP parameter SelectSpecStartTrigger
 **





 **/

class CSelectSpecStartTrigger : public CParameter
{
  public:
    CSelectSpecStartTrigger (void);
    ~CSelectSpecStartTrigger (void);

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
    ESelectSpecStartTriggerType m_ESelectSpecStartTriggerType ;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdSelectSpecStartTriggerType;
//@}

    /** @brief Get accessor functions for the LLRP SelectSpecStartTriggerType field */
    inline ESelectSpecStartTriggerType
    getSelectSpecStartTriggerType (void)
    {
        return m_ESelectSpecStartTriggerType ;
    }

    /** @brief Set accessor functions for the LLRP SelectSpecStartTriggerType field */
    inline void
    setSelectSpecStartTriggerType (
      ESelectSpecStartTriggerType  value)
    {
        m_ESelectSpecStartTriggerType  = value;
    }


  protected:
    CPeriodicTrigger * m_pPeriodicTrigger;

  public:
    /** @brief Get accessor functions for the LLRP PeriodicTrigger sub-parameter */
    inline CPeriodicTrigger *
    getPeriodicTrigger (void)
    {
        return m_pPeriodicTrigger;
    }

    /** @brief Set accessor functions for the LLRP PeriodicTrigger sub-parameter */
    EResultCode
    setPeriodicTrigger (
      CPeriodicTrigger * pValue);


  protected:
    CGPITrigger * m_pGPITrigger;

  public:
    /** @brief Get accessor functions for the LLRP GPITrigger sub-parameter */
    inline CGPITrigger *
    getGPITrigger (void)
    {
        return m_pGPITrigger;
    }

    /** @brief Set accessor functions for the LLRP GPITrigger sub-parameter */
    EResultCode
    setGPITrigger (
      CGPITrigger * pValue);


};


/**
 ** @brief  Class Definition CPeriodicTrigger for LLRP parameter PeriodicTrigger
 **





 **/

class CPeriodicTrigger : public CParameter
{
  public:
    CPeriodicTrigger (void);
    ~CPeriodicTrigger (void);

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
    llrp_u32_t m_Offset;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdOffset;
//@}

    /** @brief Get accessor functions for the LLRP Offset field */
    inline llrp_u32_t
    getOffset (void)
    {
        return m_Offset;
    }

    /** @brief Set accessor functions for the LLRP Offset field */
    inline void
    setOffset (
      llrp_u32_t  value)
    {
        m_Offset = value;
    }


  protected:
    llrp_u32_t m_Period;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdPeriod;
//@}

    /** @brief Get accessor functions for the LLRP Period field */
    inline llrp_u32_t
    getPeriod (void)
    {
        return m_Period;
    }

    /** @brief Set accessor functions for the LLRP Period field */
    inline void
    setPeriod (
      llrp_u32_t  value)
    {
        m_Period = value;
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
 ** @brief  Class Definition CGPITrigger for LLRP parameter GPITrigger
 **






 **/

class CGPITrigger : public CParameter
{
  public:
    CGPITrigger (void);
    ~CGPITrigger (void);

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
    llrp_u8_t  m_GPIPortNum;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdGPIPortNum;
//@}

    /** @brief Get accessor functions for the LLRP GPIPortNum field */
    inline llrp_u8_t
    getGPIPortNum (void)
    {
        return m_GPIPortNum;
    }

    /** @brief Set accessor functions for the LLRP GPIPortNum field */
    inline void
    setGPIPortNum (
      llrp_u8_t   value)
    {
        m_GPIPortNum = value;
    }


  protected:
    EGPIEvent m_EGPIEvent ;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdGPIEvent;
//@}

    /** @brief Get accessor functions for the LLRP GPIEvent field */
    inline EGPIEvent
    getGPIEvent (void)
    {
        return m_EGPIEvent ;
    }

    /** @brief Set accessor functions for the LLRP GPIEvent field */
    inline void
    setGPIEvent (
      EGPIEvent  value)
    {
        m_EGPIEvent  = value;
    }


  protected:
    llrp_u32_t m_Timeout;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdTimeout;
//@}

    /** @brief Get accessor functions for the LLRP Timeout field */
    inline llrp_u32_t
    getTimeout (void)
    {
        return m_Timeout;
    }

    /** @brief Set accessor functions for the LLRP Timeout field */
    inline void
    setTimeout (
      llrp_u32_t  value)
    {
        m_Timeout = value;
    }


};


/**
 ** @brief  Class Definition CSelectSpecStopTrigger for LLRP parameter SelectSpecStopTrigger
 **





 **/

class CSelectSpecStopTrigger : public CParameter
{
  public:
    CSelectSpecStopTrigger (void);
    ~CSelectSpecStopTrigger (void);

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
    ESelectSpecStopTriggerType m_ESelectSpecStopTriggerType ;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdSelectSpecStopTriggerType;
//@}

    /** @brief Get accessor functions for the LLRP SelectSpecStopTriggerType field */
    inline ESelectSpecStopTriggerType
    getSelectSpecStopTriggerType (void)
    {
        return m_ESelectSpecStopTriggerType ;
    }

    /** @brief Set accessor functions for the LLRP SelectSpecStopTriggerType field */
    inline void
    setSelectSpecStopTriggerType (
      ESelectSpecStopTriggerType  value)
    {
        m_ESelectSpecStopTriggerType  = value;
    }


  protected:
    llrp_u32_t m_DurationValue;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdDurationValue;
//@}

    /** @brief Get accessor functions for the LLRP DurationValue field */
    inline llrp_u32_t
    getDurationValue (void)
    {
        return m_DurationValue;
    }

    /** @brief Set accessor functions for the LLRP DurationValue field */
    inline void
    setDurationValue (
      llrp_u32_t  value)
    {
        m_DurationValue = value;
    }


  protected:
    CGPITrigger * m_pGPITrigger;

  public:
    /** @brief Get accessor functions for the LLRP GPITrigger sub-parameter */
    inline CGPITrigger *
    getGPITrigger (void)
    {
        return m_pGPITrigger;
    }

    /** @brief Set accessor functions for the LLRP GPITrigger sub-parameter */
    EResultCode
    setGPITrigger (
      CGPITrigger * pValue);


};


/**
 ** @brief  Class Definition CAntennaSpec for LLRP parameter AntennaSpec
 **





 **/

class CAntennaSpec : public CParameter
{
  public:
    CAntennaSpec (void);
    ~CAntennaSpec (void);

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
    llrp_u8v_t m_AntennaIDs;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdAntennaIDs;
//@}

    /** @brief Get accessor functions for the LLRP AntennaIDs field */
    inline llrp_u8v_t
    getAntennaIDs (void)
    {
        return m_AntennaIDs;
    }

    /** @brief Set accessor functions for the LLRP AntennaIDs field */
    inline void
    setAntennaIDs (
      llrp_u8v_t  value)
    {
        m_AntennaIDs = value;
    }


  protected:
    CAntennaSpecStopTrigger * m_pAntennaSpecStopTrigger;

  public:
    /** @brief Get accessor functions for the LLRP AntennaSpecStopTrigger sub-parameter */
    inline CAntennaSpecStopTrigger *
    getAntennaSpecStopTrigger (void)
    {
        return m_pAntennaSpecStopTrigger;
    }

    /** @brief Set accessor functions for the LLRP AntennaSpecStopTrigger sub-parameter */
    EResultCode
    setAntennaSpecStopTrigger (
      CAntennaSpecStopTrigger * pValue);


  protected:
    std::list<CRfSpec *> m_listRfSpec;

  public:
     /** @brief  Returns the first element of the RfSpec sub-parameter list*/
    inline std::list<CRfSpec *>::iterator
    beginRfSpec (void)
    {
        return m_listRfSpec.begin();
    }

     /** @brief  Returns the last element of the RfSpec sub-parameter list*/
    inline std::list<CRfSpec *>::iterator
    endRfSpec (void)
    {
        return m_listRfSpec.end();
    }

     /** @brief  Clears the LLRP RfSpec sub-parameter list*/
    inline void
    clearRfSpec (void)
    {
        clearSubParameterList ((tListOfParameters *) &m_listRfSpec);
    }

    EResultCode
     /** @brief  Add a RfSpec to the LLRP sub-parameter list*/
    addRfSpec (
      CRfSpec * pValue);


};


/**
 ** @brief  Class Definition CAntennaSpecStopTrigger for LLRP parameter AntennaSpecStopTrigger
 **






 **/

class CAntennaSpecStopTrigger : public CParameter
{
  public:
    CAntennaSpecStopTrigger (void);
    ~CAntennaSpecStopTrigger (void);

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
    EAntennaSpecStopTriggerType m_EAntennaSpecStopTriggerType ;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdAntennaSpecStopTriggerType;
//@}

    /** @brief Get accessor functions for the LLRP AntennaSpecStopTriggerType field */
    inline EAntennaSpecStopTriggerType
    getAntennaSpecStopTriggerType (void)
    {
        return m_EAntennaSpecStopTriggerType ;
    }

    /** @brief Set accessor functions for the LLRP AntennaSpecStopTriggerType field */
    inline void
    setAntennaSpecStopTriggerType (
      EAntennaSpecStopTriggerType  value)
    {
        m_EAntennaSpecStopTriggerType  = value;
    }


  protected:
    llrp_u32_t m_DurationValue;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdDurationValue;
//@}

    /** @brief Get accessor functions for the LLRP DurationValue field */
    inline llrp_u32_t
    getDurationValue (void)
    {
        return m_DurationValue;
    }

    /** @brief Set accessor functions for the LLRP DurationValue field */
    inline void
    setDurationValue (
      llrp_u32_t  value)
    {
        m_DurationValue = value;
    }


  protected:
    CGPITrigger * m_pGPITrigger;

  public:
    /** @brief Get accessor functions for the LLRP GPITrigger sub-parameter */
    inline CGPITrigger *
    getGPITrigger (void)
    {
        return m_pGPITrigger;
    }

    /** @brief Set accessor functions for the LLRP GPITrigger sub-parameter */
    EResultCode
    setGPITrigger (
      CGPITrigger * pValue);


  protected:
    CTagObservationTrigger * m_pTagObservationTrigger;

  public:
    /** @brief Get accessor functions for the LLRP TagObservationTrigger sub-parameter */
    inline CTagObservationTrigger *
    getTagObservationTrigger (void)
    {
        return m_pTagObservationTrigger;
    }

    /** @brief Set accessor functions for the LLRP TagObservationTrigger sub-parameter */
    EResultCode
    setTagObservationTrigger (
      CTagObservationTrigger * pValue);


};


/**
 ** @brief  Class Definition CTagObservationTrigger for LLRP parameter TagObservationTrigger
 **







 **/

class CTagObservationTrigger : public CParameter
{
  public:
    CTagObservationTrigger (void);
    ~CTagObservationTrigger (void);

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
    ETriggerType m_ETriggerType ;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdTriggerType;
//@}

    /** @brief Get accessor functions for the LLRP TriggerType field */
    inline ETriggerType
    getTriggerType (void)
    {
        return m_ETriggerType ;
    }

    /** @brief Set accessor functions for the LLRP TriggerType field */
    inline void
    setTriggerType (
      ETriggerType  value)
    {
        m_ETriggerType  = value;
    }


  protected:
    llrp_u16_t  m_NumberOfTags;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdNumberOfTags;
//@}

    /** @brief Get accessor functions for the LLRP NumberOfTags field */
    inline llrp_u16_t
    getNumberOfTags (void)
    {
        return m_NumberOfTags;
    }

    /** @brief Set accessor functions for the LLRP NumberOfTags field */
    inline void
    setNumberOfTags (
      llrp_u16_t   value)
    {
        m_NumberOfTags = value;
    }


  protected:
    llrp_u16_t  m_NumberOfAttempts;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdNumberOfAttempts;
//@}

    /** @brief Get accessor functions for the LLRP NumberOfAttempts field */
    inline llrp_u16_t
    getNumberOfAttempts (void)
    {
        return m_NumberOfAttempts;
    }

    /** @brief Set accessor functions for the LLRP NumberOfAttempts field */
    inline void
    setNumberOfAttempts (
      llrp_u16_t   value)
    {
        m_NumberOfAttempts = value;
    }


  protected:
    llrp_u16_t  m_TValue;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdTValue;
//@}

    /** @brief Get accessor functions for the LLRP TValue field */
    inline llrp_u16_t
    getTValue (void)
    {
        return m_TValue;
    }

    /** @brief Set accessor functions for the LLRP TValue field */
    inline void
    setTValue (
      llrp_u16_t   value)
    {
        m_TValue = value;
    }


  protected:
    llrp_u32_t m_Timeout;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdTimeout;
//@}

    /** @brief Get accessor functions for the LLRP Timeout field */
    inline llrp_u32_t
    getTimeout (void)
    {
        return m_Timeout;
    }

    /** @brief Set accessor functions for the LLRP Timeout field */
    inline void
    setTimeout (
      llrp_u32_t  value)
    {
        m_Timeout = value;
    }


};


/**
 ** @brief  Class Definition CRfSpec for LLRP parameter RfSpec
 **







 **/

class CRfSpec : public CParameter
{
  public:
    CRfSpec (void);
    ~CRfSpec (void);

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
    llrp_u16_t  m_RfSpecID;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdRfSpecID;
//@}

    /** @brief Get accessor functions for the LLRP RfSpecID field */
    inline llrp_u16_t
    getRfSpecID (void)
    {
        return m_RfSpecID;
    }

    /** @brief Set accessor functions for the LLRP RfSpecID field */
    inline void
    setRfSpecID (
      llrp_u16_t   value)
    {
        m_RfSpecID = value;
    }


  protected:
    EProtocolID m_EProtocolID ;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdProtocolID;
//@}

    /** @brief Get accessor functions for the LLRP ProtocolID field */
    inline EProtocolID
    getProtocolID (void)
    {
        return m_EProtocolID ;
    }

    /** @brief Set accessor functions for the LLRP ProtocolID field */
    inline void
    setProtocolID (
      EProtocolID  value)
    {
        m_EProtocolID  = value;
    }


  protected:
    ESelectType m_ESelectType ;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdSelectType;
//@}

    /** @brief Get accessor functions for the LLRP SelectType field */
    inline ESelectType
    getSelectType (void)
    {
        return m_ESelectType ;
    }

    /** @brief Set accessor functions for the LLRP SelectType field */
    inline void
    setSelectType (
      ESelectType  value)
    {
        m_ESelectType  = value;
    }


  protected:
    CMemoryBank * m_pMemoryBank;

  public:
    /** @brief Get accessor functions for the LLRP MemoryBank sub-parameter */
    inline CMemoryBank *
    getMemoryBank (void)
    {
        return m_pMemoryBank;
    }

    /** @brief Set accessor functions for the LLRP MemoryBank sub-parameter */
    EResultCode
    setMemoryBank (
      CMemoryBank * pValue);


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


};


/**
 ** @brief  Class Definition CMemoryBank for LLRP parameter MemoryBank
 **







 **/

class CMemoryBank : public CParameter
{
  public:
    CMemoryBank (void);
    ~CMemoryBank (void);

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
    llrp_u8_t  m_MemoryBankID;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdMemoryBankID;
//@}

    /** @brief Get accessor functions for the LLRP MemoryBankID field */
    inline llrp_u8_t
    getMemoryBankID (void)
    {
        return m_MemoryBankID;
    }

    /** @brief Set accessor functions for the LLRP MemoryBankID field */
    inline void
    setMemoryBankID (
      llrp_u8_t   value)
    {
        m_MemoryBankID = value;
    }


  protected:
    llrp_u8_t  m_ReadType;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdReadType;
//@}

    /** @brief Get accessor functions for the LLRP ReadType field */
    inline llrp_u8_t
    getReadType (void)
    {
        return m_ReadType;
    }

    /** @brief Set accessor functions for the LLRP ReadType field */
    inline void
    setReadType (
      llrp_u8_t   value)
    {
        m_ReadType = value;
    }


  protected:
    llrp_u16_t  m_Pointer;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdPointer;
//@}

    /** @brief Get accessor functions for the LLRP Pointer field */
    inline llrp_u16_t
    getPointer (void)
    {
        return m_Pointer;
    }

    /** @brief Set accessor functions for the LLRP Pointer field */
    inline void
    setPointer (
      llrp_u16_t   value)
    {
        m_Pointer = value;
    }


  protected:
    llrp_u16_t  m_Count;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdCount;
//@}

    /** @brief Get accessor functions for the LLRP Count field */
    inline llrp_u16_t
    getCount (void)
    {
        return m_Count;
    }

    /** @brief Set accessor functions for the LLRP Count field */
    inline void
    setCount (
      llrp_u16_t   value)
    {
        m_Count = value;
    }


  protected:
    llrp_u8_t  m_BankType;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdBankType;
//@}

    /** @brief Get accessor functions for the LLRP BankType field */
    inline llrp_u8_t
    getBankType (void)
    {
        return m_BankType;
    }

    /** @brief Set accessor functions for the LLRP BankType field */
    inline void
    setBankType (
      llrp_u8_t   value)
    {
        m_BankType = value;
    }


};


/**
 ** @brief  Class Definition CSelectReportSpec for LLRP parameter SelectReportSpec
 **















 **/

class CSelectReportSpec : public CParameter
{
  public:
    CSelectReportSpec (void);
    ~CSelectReportSpec (void);

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
    ESelectReportTrigger m_ESelectReportTrigger ;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdSelectReportTrigger;
//@}

    /** @brief Get accessor functions for the LLRP SelectReportTrigger field */
    inline ESelectReportTrigger
    getSelectReportTrigger (void)
    {
        return m_ESelectReportTrigger ;
    }

    /** @brief Set accessor functions for the LLRP SelectReportTrigger field */
    inline void
    setSelectReportTrigger (
      ESelectReportTrigger  value)
    {
        m_ESelectReportTrigger  = value;
    }


  protected:
    llrp_u16_t  m_NValue;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdNValue;
//@}

    /** @brief Get accessor functions for the LLRP NValue field */
    inline llrp_u16_t
    getNValue (void)
    {
        return m_NValue;
    }

    /** @brief Set accessor functions for the LLRP NValue field */
    inline void
    setNValue (
      llrp_u16_t   value)
    {
        m_NValue = value;
    }


  protected:
    llrp_u1_t m_EnableSelectSpecID;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdEnableSelectSpecID;
//@}

    /** @brief Get accessor functions for the LLRP EnableSelectSpecID field */
    inline llrp_u1_t
    getEnableSelectSpecID (void)
    {
        return m_EnableSelectSpecID;
    }

    /** @brief Set accessor functions for the LLRP EnableSelectSpecID field */
    inline void
    setEnableSelectSpecID (
      llrp_u1_t  value)
    {
        m_EnableSelectSpecID = value;
    }


  protected:
    llrp_u1_t m_EnableSpecIndex;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdEnableSpecIndex;
//@}

    /** @brief Get accessor functions for the LLRP EnableSpecIndex field */
    inline llrp_u1_t
    getEnableSpecIndex (void)
    {
        return m_EnableSpecIndex;
    }

    /** @brief Set accessor functions for the LLRP EnableSpecIndex field */
    inline void
    setEnableSpecIndex (
      llrp_u1_t  value)
    {
        m_EnableSpecIndex = value;
    }


  protected:
    llrp_u1_t m_EnableRfSpecID;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdEnableRfSpecID;
//@}

    /** @brief Get accessor functions for the LLRP EnableRfSpecID field */
    inline llrp_u1_t
    getEnableRfSpecID (void)
    {
        return m_EnableRfSpecID;
    }

    /** @brief Set accessor functions for the LLRP EnableRfSpecID field */
    inline void
    setEnableRfSpecID (
      llrp_u1_t  value)
    {
        m_EnableRfSpecID = value;
    }


  protected:
    llrp_u1_t m_EnableAntennaID;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdEnableAntennaID;
//@}

    /** @brief Get accessor functions for the LLRP EnableAntennaID field */
    inline llrp_u1_t
    getEnableAntennaID (void)
    {
        return m_EnableAntennaID;
    }

    /** @brief Set accessor functions for the LLRP EnableAntennaID field */
    inline void
    setEnableAntennaID (
      llrp_u1_t  value)
    {
        m_EnableAntennaID = value;
    }


  protected:
    llrp_u1_t m_EnablePeakRSSI;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdEnablePeakRSSI;
//@}

    /** @brief Get accessor functions for the LLRP EnablePeakRSSI field */
    inline llrp_u1_t
    getEnablePeakRSSI (void)
    {
        return m_EnablePeakRSSI;
    }

    /** @brief Set accessor functions for the LLRP EnablePeakRSSI field */
    inline void
    setEnablePeakRSSI (
      llrp_u1_t  value)
    {
        m_EnablePeakRSSI = value;
    }


  protected:
    llrp_u1_t m_EnableFirstSeenTimestamp;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdEnableFirstSeenTimestamp;
//@}

    /** @brief Get accessor functions for the LLRP EnableFirstSeenTimestamp field */
    inline llrp_u1_t
    getEnableFirstSeenTimestamp (void)
    {
        return m_EnableFirstSeenTimestamp;
    }

    /** @brief Set accessor functions for the LLRP EnableFirstSeenTimestamp field */
    inline void
    setEnableFirstSeenTimestamp (
      llrp_u1_t  value)
    {
        m_EnableFirstSeenTimestamp = value;
    }


  protected:
    llrp_u1_t m_EnableLastSeenTimestamp;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdEnableLastSeenTimestamp;
//@}

    /** @brief Get accessor functions for the LLRP EnableLastSeenTimestamp field */
    inline llrp_u1_t
    getEnableLastSeenTimestamp (void)
    {
        return m_EnableLastSeenTimestamp;
    }

    /** @brief Set accessor functions for the LLRP EnableLastSeenTimestamp field */
    inline void
    setEnableLastSeenTimestamp (
      llrp_u1_t  value)
    {
        m_EnableLastSeenTimestamp = value;
    }


  protected:
    llrp_u1_t m_EnableTagSeenCount;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdEnableTagSeenCount;
//@}

    /** @brief Get accessor functions for the LLRP EnableTagSeenCount field */
    inline llrp_u1_t
    getEnableTagSeenCount (void)
    {
        return m_EnableTagSeenCount;
    }

    /** @brief Set accessor functions for the LLRP EnableTagSeenCount field */
    inline void
    setEnableTagSeenCount (
      llrp_u1_t  value)
    {
        m_EnableTagSeenCount = value;
    }


  protected:
    llrp_u1_t m_EnableAccessSpecID;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdEnableAccessSpecID;
//@}

    /** @brief Get accessor functions for the LLRP EnableAccessSpecID field */
    inline llrp_u1_t
    getEnableAccessSpecID (void)
    {
        return m_EnableAccessSpecID;
    }

    /** @brief Set accessor functions for the LLRP EnableAccessSpecID field */
    inline void
    setEnableAccessSpecID (
      llrp_u1_t  value)
    {
        m_EnableAccessSpecID = value;
    }


  protected:
    CReportDestination * m_pReportDestination;

  public:
    /** @brief Get accessor functions for the LLRP ReportDestination sub-parameter */
    inline CReportDestination *
    getReportDestination (void)
    {
        return m_pReportDestination;
    }

    /** @brief Set accessor functions for the LLRP ReportDestination sub-parameter */
    EResultCode
    setReportDestination (
      CReportDestination * pValue);


};


/**
 ** @brief  Class Definition CReportDestination for LLRP parameter ReportDestination
 **



 **/

class CReportDestination : public CParameter
{
  public:
    CReportDestination (void);
    ~CReportDestination (void);

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


};


/**
 ** @brief  Class Definition CAccessSpec for LLRP parameter AccessSpec
 **












 **/

class CAccessSpec : public CParameter
{
  public:
    CAccessSpec (void);
    ~CAccessSpec (void);

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
    llrp_u32_t m_AccessSpecID;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdAccessSpecID;
//@}

    /** @brief Get accessor functions for the LLRP AccessSpecID field */
    inline llrp_u32_t
    getAccessSpecID (void)
    {
        return m_AccessSpecID;
    }

    /** @brief Set accessor functions for the LLRP AccessSpecID field */
    inline void
    setAccessSpecID (
      llrp_u32_t  value)
    {
        m_AccessSpecID = value;
    }


  protected:
    llrp_u32_t m_SelectSpecID;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdSelectSpecID;
//@}

    /** @brief Get accessor functions for the LLRP SelectSpecID field */
    inline llrp_u32_t
    getSelectSpecID (void)
    {
        return m_SelectSpecID;
    }

    /** @brief Set accessor functions for the LLRP SelectSpecID field */
    inline void
    setSelectSpecID (
      llrp_u32_t  value)
    {
        m_SelectSpecID = value;
    }


  protected:
    llrp_u8_t  m_AntennaID;

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
      llrp_u8_t   value)
    {
        m_AntennaID = value;
    }


  protected:
    EProtocolID m_EProtocolID ;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdProtocolID;
//@}

    /** @brief Get accessor functions for the LLRP ProtocolID field */
    inline EProtocolID
    getProtocolID (void)
    {
        return m_EProtocolID ;
    }

    /** @brief Set accessor functions for the LLRP ProtocolID field */
    inline void
    setProtocolID (
      EProtocolID  value)
    {
        m_EProtocolID  = value;
    }


  protected:
    EAccessCurrentState m_EAccessCurrentState ;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdAccessCurrentState;
//@}

    /** @brief Get accessor functions for the LLRP AccessCurrentState field */
    inline EAccessCurrentState
    getAccessCurrentState (void)
    {
        return m_EAccessCurrentState ;
    }

    /** @brief Set accessor functions for the LLRP AccessCurrentState field */
    inline void
    setAccessCurrentState (
      EAccessCurrentState  value)
    {
        m_EAccessCurrentState  = value;
    }


  protected:
    EPersistence m_EPersistence ;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdPersistence;
//@}

    /** @brief Get accessor functions for the LLRP Persistence field */
    inline EPersistence
    getPersistence (void)
    {
        return m_EPersistence ;
    }

    /** @brief Set accessor functions for the LLRP Persistence field */
    inline void
    setPersistence (
      EPersistence  value)
    {
        m_EPersistence  = value;
    }


  protected:
    CAccessSpecStopTrigger * m_pAccessSpecStopTrigger;

  public:
    /** @brief Get accessor functions for the LLRP AccessSpecStopTrigger sub-parameter */
    inline CAccessSpecStopTrigger *
    getAccessSpecStopTrigger (void)
    {
        return m_pAccessSpecStopTrigger;
    }

    /** @brief Set accessor functions for the LLRP AccessSpecStopTrigger sub-parameter */
    EResultCode
    setAccessSpecStopTrigger (
      CAccessSpecStopTrigger * pValue);


  protected:
    CAccessCommand * m_pAccessCommand;

  public:
    /** @brief Get accessor functions for the LLRP AccessCommand sub-parameter */
    inline CAccessCommand *
    getAccessCommand (void)
    {
        return m_pAccessCommand;
    }

    /** @brief Set accessor functions for the LLRP AccessCommand sub-parameter */
    EResultCode
    setAccessCommand (
      CAccessCommand * pValue);


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


};


/**
 ** @brief  Class Definition CAccessSpecStopTrigger for LLRP parameter AccessSpecStopTrigger
 **




 **/

class CAccessSpecStopTrigger : public CParameter
{
  public:
    CAccessSpecStopTrigger (void);
    ~CAccessSpecStopTrigger (void);

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
    EAccessSpecStopTriggerType m_EAccessSpecStopTriggerType ;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdAccessSpecStopTriggerType;
//@}

    /** @brief Get accessor functions for the LLRP AccessSpecStopTriggerType field */
    inline EAccessSpecStopTriggerType
    getAccessSpecStopTriggerType (void)
    {
        return m_EAccessSpecStopTriggerType ;
    }

    /** @brief Set accessor functions for the LLRP AccessSpecStopTriggerType field */
    inline void
    setAccessSpecStopTriggerType (
      EAccessSpecStopTriggerType  value)
    {
        m_EAccessSpecStopTriggerType  = value;
    }


  protected:
    llrp_u16_t  m_OperationCountValue;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdOperationCountValue;
//@}

    /** @brief Get accessor functions for the LLRP OperationCountValue field */
    inline llrp_u16_t
    getOperationCountValue (void)
    {
        return m_OperationCountValue;
    }

    /** @brief Set accessor functions for the LLRP OperationCountValue field */
    inline void
    setOperationCountValue (
      llrp_u16_t   value)
    {
        m_OperationCountValue = value;
    }


};


/**
 ** @brief  Class Definition CAccessCommand for LLRP parameter AccessCommand
 **





 **/

class CAccessCommand : public CParameter
{
  public:
    CAccessCommand (void);
    ~CAccessCommand (void);

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
    CHbMatchSpec * m_pHbMatchSpec;

  public:
    /** @brief Get accessor functions for the LLRP HbMatchSpec sub-parameter */
    inline CHbMatchSpec *
    getHbMatchSpec (void)
    {
        return m_pHbMatchSpec;
    }

    /** @brief Set accessor functions for the LLRP HbMatchSpec sub-parameter */
    EResultCode
    setHbMatchSpec (
      CHbMatchSpec * pValue);


  protected:
    std::list<CParameter *> m_listOpSpec;

  public:
     /** @brief  Returns the first element of the OpSpec sub-parameter list*/
    inline std::list<CParameter *>::iterator
    beginOpSpec (void)
    {
        return m_listOpSpec.begin();
    }

     /** @brief  Returns the last element of the OpSpec sub-parameter list*/
    inline std::list<CParameter *>::iterator
    endOpSpec (void)
    {
        return m_listOpSpec.end();
    }

     /** @brief  Clears the LLRP OpSpec sub-parameter list*/
    inline void
    clearOpSpec (void)
    {
        clearSubParameterList ((tListOfParameters *) &m_listOpSpec);
    }

    EResultCode
     /** @brief  Add a OpSpec to the LLRP sub-parameter list*/
    addOpSpec (
      CParameter * pValue);


  protected:
    CSecurityModuleSpec * m_pSecurityModuleSpec;

  public:
    /** @brief Get accessor functions for the LLRP SecurityModuleSpec sub-parameter */
    inline CSecurityModuleSpec *
    getSecurityModuleSpec (void)
    {
        return m_pSecurityModuleSpec;
    }

    /** @brief Set accessor functions for the LLRP SecurityModuleSpec sub-parameter */
    EResultCode
    setSecurityModuleSpec (
      CSecurityModuleSpec * pValue);


};


/**
 ** @brief  Class Definition CSecurityModuleSpec for LLRP parameter SecurityModuleSpec
 **



 **/

class CSecurityModuleSpec : public CParameter
{
  public:
    CSecurityModuleSpec (void);
    ~CSecurityModuleSpec (void);

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
 ** @brief  Class Definition CHbMatchSpec for LLRP parameter HbMatchSpec
 **



 **/

class CHbMatchSpec : public CParameter
{
  public:
    CHbMatchSpec (void);
    ~CHbMatchSpec (void);

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
    std::list<CHbTargetTag *> m_listHbTargetTag;

  public:
     /** @brief  Returns the first element of the HbTargetTag sub-parameter list*/
    inline std::list<CHbTargetTag *>::iterator
    beginHbTargetTag (void)
    {
        return m_listHbTargetTag.begin();
    }

     /** @brief  Returns the last element of the HbTargetTag sub-parameter list*/
    inline std::list<CHbTargetTag *>::iterator
    endHbTargetTag (void)
    {
        return m_listHbTargetTag.end();
    }

     /** @brief  Clears the LLRP HbTargetTag sub-parameter list*/
    inline void
    clearHbTargetTag (void)
    {
        clearSubParameterList ((tListOfParameters *) &m_listHbTargetTag);
    }

    EResultCode
     /** @brief  Add a HbTargetTag to the LLRP sub-parameter list*/
    addHbTargetTag (
      CHbTargetTag * pValue);


};


/**
 ** @brief  Class Definition CHbTargetTag for LLRP parameter HbTargetTag
 **








 **/

class CHbTargetTag : public CParameter
{
  public:
    CHbTargetTag (void);
    ~CHbTargetTag (void);

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
    EMemoryType m_EMemoryType ;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdMemoryType;
//@}

    /** @brief Get accessor functions for the LLRP MemoryType field */
    inline EMemoryType
    getMemoryType (void)
    {
        return m_EMemoryType ;
    }

    /** @brief Set accessor functions for the LLRP MemoryType field */
    inline void
    setMemoryType (
      EMemoryType  value)
    {
        m_EMemoryType  = value;
    }


  protected:
    EMatchType m_EMatchType ;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdMatchType;
//@}

    /** @brief Get accessor functions for the LLRP MatchType field */
    inline EMatchType
    getMatchType (void)
    {
        return m_EMatchType ;
    }

    /** @brief Set accessor functions for the LLRP MatchType field */
    inline void
    setMatchType (
      EMatchType  value)
    {
        m_EMatchType  = value;
    }


  protected:
    llrp_u16_t  m_Pointer;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdPointer;
//@}

    /** @brief Get accessor functions for the LLRP Pointer field */
    inline llrp_u16_t
    getPointer (void)
    {
        return m_Pointer;
    }

    /** @brief Set accessor functions for the LLRP Pointer field */
    inline void
    setPointer (
      llrp_u16_t   value)
    {
        m_Pointer = value;
    }


  protected:
    llrp_u1v_t m_TagMask;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdTagMask;
//@}

    /** @brief Get accessor functions for the LLRP TagMask field */
    inline llrp_u1v_t
    getTagMask (void)
    {
        return m_TagMask;
    }

    /** @brief Set accessor functions for the LLRP TagMask field */
    inline void
    setTagMask (
      llrp_u1v_t  value)
    {
        m_TagMask = value;
    }


  protected:
    llrp_u1v_t m_TagData;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdTagData;
//@}

    /** @brief Get accessor functions for the LLRP TagData field */
    inline llrp_u1v_t
    getTagData (void)
    {
        return m_TagData;
    }

    /** @brief Set accessor functions for the LLRP TagData field */
    inline void
    setTagData (
      llrp_u1v_t  value)
    {
        m_TagData = value;
    }


};


/**
 ** @brief  Class Definition CHbReadSpec for LLRP parameter HbReadSpec
 **




 **/

class CHbReadSpec : public CParameter
{
  public:
    CHbReadSpec (void);
    ~CHbReadSpec (void);

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
    llrp_u16_t  m_OpSpecID;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdOpSpecID;
//@}

    /** @brief Get accessor functions for the LLRP OpSpecID field */
    inline llrp_u16_t
    getOpSpecID (void)
    {
        return m_OpSpecID;
    }

    /** @brief Set accessor functions for the LLRP OpSpecID field */
    inline void
    setOpSpecID (
      llrp_u16_t   value)
    {
        m_OpSpecID = value;
    }


  protected:
    CMemoryBank * m_pMemoryBank;

  public:
    /** @brief Get accessor functions for the LLRP MemoryBank sub-parameter */
    inline CMemoryBank *
    getMemoryBank (void)
    {
        return m_pMemoryBank;
    }

    /** @brief Set accessor functions for the LLRP MemoryBank sub-parameter */
    EResultCode
    setMemoryBank (
      CMemoryBank * pValue);


};


/**
 ** @brief  Class Definition CHbWriteSpec for LLRP parameter HbWriteSpec
 **







 **/

class CHbWriteSpec : public CParameter
{
  public:
    CHbWriteSpec (void);
    ~CHbWriteSpec (void);

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
    llrp_u16_t  m_OpSpecID;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdOpSpecID;
//@}

    /** @brief Get accessor functions for the LLRP OpSpecID field */
    inline llrp_u16_t
    getOpSpecID (void)
    {
        return m_OpSpecID;
    }

    /** @brief Set accessor functions for the LLRP OpSpecID field */
    inline void
    setOpSpecID (
      llrp_u16_t   value)
    {
        m_OpSpecID = value;
    }


  protected:
    llrp_u8_t  m_MemoryBankID;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdMemoryBankID;
//@}

    /** @brief Get accessor functions for the LLRP MemoryBankID field */
    inline llrp_u8_t
    getMemoryBankID (void)
    {
        return m_MemoryBankID;
    }

    /** @brief Set accessor functions for the LLRP MemoryBankID field */
    inline void
    setMemoryBankID (
      llrp_u8_t   value)
    {
        m_MemoryBankID = value;
    }


  protected:
    llrp_u16_t  m_Pointer;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdPointer;
//@}

    /** @brief Get accessor functions for the LLRP Pointer field */
    inline llrp_u16_t
    getPointer (void)
    {
        return m_Pointer;
    }

    /** @brief Set accessor functions for the LLRP Pointer field */
    inline void
    setPointer (
      llrp_u16_t   value)
    {
        m_Pointer = value;
    }


  protected:
    llrp_u16v_t m_Data;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdData;
//@}

    /** @brief Get accessor functions for the LLRP Data field */
    inline llrp_u16v_t
    getData (void)
    {
        return m_Data;
    }

    /** @brief Set accessor functions for the LLRP Data field */
    inline void
    setData (
      llrp_u16v_t  value)
    {
        m_Data = value;
    }


};


/**
 ** @brief  Class Definition CClientRequestSpec for LLRP parameter ClientRequestSpec
 **



 **/

class CClientRequestSpec : public CParameter
{
  public:
    CClientRequestSpec (void);
    ~CClientRequestSpec (void);

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
    llrp_u16_t  m_OpSpecID;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdOpSpecID;
//@}

    /** @brief Get accessor functions for the LLRP OpSpecID field */
    inline llrp_u16_t
    getOpSpecID (void)
    {
        return m_OpSpecID;
    }

    /** @brief Set accessor functions for the LLRP OpSpecID field */
    inline void
    setOpSpecID (
      llrp_u16_t   value)
    {
        m_OpSpecID = value;
    }


};


/**
 ** @brief  Class Definition CAccessReportSpec for LLRP parameter AccessReportSpec
 **




 **/

class CAccessReportSpec : public CParameter
{
  public:
    CAccessReportSpec (void);
    ~CAccessReportSpec (void);

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
    EAccessReportTrigger m_EAccessReportTrigger ;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdAccessReportTrigger;
//@}

    /** @brief Get accessor functions for the LLRP AccessReportTrigger field */
    inline EAccessReportTrigger
    getAccessReportTrigger (void)
    {
        return m_EAccessReportTrigger ;
    }

    /** @brief Set accessor functions for the LLRP AccessReportTrigger field */
    inline void
    setAccessReportTrigger (
      EAccessReportTrigger  value)
    {
        m_EAccessReportTrigger  = value;
    }


  protected:
    CReportDestination * m_pReportDestination;

  public:
    /** @brief Get accessor functions for the LLRP ReportDestination sub-parameter */
    inline CReportDestination *
    getReportDestination (void)
    {
        return m_pReportDestination;
    }

    /** @brief Set accessor functions for the LLRP ReportDestination sub-parameter */
    EResultCode
    setReportDestination (
      CReportDestination * pValue);


};


/**
 ** @brief  Class Definition CTagReportData for LLRP parameter TagReportData
 **














 **/

class CTagReportData : public CParameter
{
  public:
    CTagReportData (void);
    ~CTagReportData (void);

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
    llrp_u8v_t m_TID;

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
      llrp_u8v_t  value)
    {
        m_TID = value;
    }


  protected:
    CSelectSpecID * m_pSelectSpecID;

  public:
    /** @brief Get accessor functions for the LLRP SelectSpecID sub-parameter */
    inline CSelectSpecID *
    getSelectSpecID (void)
    {
        return m_pSelectSpecID;
    }

    /** @brief Set accessor functions for the LLRP SelectSpecID sub-parameter */
    EResultCode
    setSelectSpecID (
      CSelectSpecID * pValue);


  protected:
    CSpecIndex * m_pSpecIndex;

  public:
    /** @brief Get accessor functions for the LLRP SpecIndex sub-parameter */
    inline CSpecIndex *
    getSpecIndex (void)
    {
        return m_pSpecIndex;
    }

    /** @brief Set accessor functions for the LLRP SpecIndex sub-parameter */
    EResultCode
    setSpecIndex (
      CSpecIndex * pValue);


  protected:
    CRfSpecID * m_pRfSpecID;

  public:
    /** @brief Get accessor functions for the LLRP RfSpecID sub-parameter */
    inline CRfSpecID *
    getRfSpecID (void)
    {
        return m_pRfSpecID;
    }

    /** @brief Set accessor functions for the LLRP RfSpecID sub-parameter */
    EResultCode
    setRfSpecID (
      CRfSpecID * pValue);


  protected:
    CAntennaID * m_pAntennaID;

  public:
    /** @brief Get accessor functions for the LLRP AntennaID sub-parameter */
    inline CAntennaID *
    getAntennaID (void)
    {
        return m_pAntennaID;
    }

    /** @brief Set accessor functions for the LLRP AntennaID sub-parameter */
    EResultCode
    setAntennaID (
      CAntennaID * pValue);


  protected:
    CPeakRSSI * m_pPeakRSSI;

  public:
    /** @brief Get accessor functions for the LLRP PeakRSSI sub-parameter */
    inline CPeakRSSI *
    getPeakRSSI (void)
    {
        return m_pPeakRSSI;
    }

    /** @brief Set accessor functions for the LLRP PeakRSSI sub-parameter */
    EResultCode
    setPeakRSSI (
      CPeakRSSI * pValue);


  protected:
    CFirstSeenTimestampUTC * m_pFirstSeenTimestampUTC;

  public:
    /** @brief Get accessor functions for the LLRP FirstSeenTimestampUTC sub-parameter */
    inline CFirstSeenTimestampUTC *
    getFirstSeenTimestampUTC (void)
    {
        return m_pFirstSeenTimestampUTC;
    }

    /** @brief Set accessor functions for the LLRP FirstSeenTimestampUTC sub-parameter */
    EResultCode
    setFirstSeenTimestampUTC (
      CFirstSeenTimestampUTC * pValue);


  protected:
    CLastSeenTimestampUTC * m_pLastSeenTimestampUTC;

  public:
    /** @brief Get accessor functions for the LLRP LastSeenTimestampUTC sub-parameter */
    inline CLastSeenTimestampUTC *
    getLastSeenTimestampUTC (void)
    {
        return m_pLastSeenTimestampUTC;
    }

    /** @brief Set accessor functions for the LLRP LastSeenTimestampUTC sub-parameter */
    EResultCode
    setLastSeenTimestampUTC (
      CLastSeenTimestampUTC * pValue);


  protected:
    CTagSeenCount * m_pTagSeenCount;

  public:
    /** @brief Get accessor functions for the LLRP TagSeenCount sub-parameter */
    inline CTagSeenCount *
    getTagSeenCount (void)
    {
        return m_pTagSeenCount;
    }

    /** @brief Set accessor functions for the LLRP TagSeenCount sub-parameter */
    EResultCode
    setTagSeenCount (
      CTagSeenCount * pValue);


  protected:
    CAccessSpecID * m_pAccessSpecID;

  public:
    /** @brief Get accessor functions for the LLRP AccessSpecID sub-parameter */
    inline CAccessSpecID *
    getAccessSpecID (void)
    {
        return m_pAccessSpecID;
    }

    /** @brief Set accessor functions for the LLRP AccessSpecID sub-parameter */
    EResultCode
    setAccessSpecID (
      CAccessSpecID * pValue);


  protected:
    CParameter * m_pSelectSpecResult;

  public:
    /** @brief Get accessor functions for the LLRP SelectSpecResult sub-parameter */
    inline CParameter *
    getSelectSpecResult (void)
    {
        return m_pSelectSpecResult;
    }

    /** @brief Set accessor functions for the LLRP SelectSpecResult sub-parameter */
    EResultCode
    setSelectSpecResult (
      CParameter * pValue);


  protected:
    std::list<CParameter *> m_listAccessSpecResult;

  public:
     /** @brief  Returns the first element of the AccessSpecResult sub-parameter list*/
    inline std::list<CParameter *>::iterator
    beginAccessSpecResult (void)
    {
        return m_listAccessSpecResult.begin();
    }

     /** @brief  Returns the last element of the AccessSpecResult sub-parameter list*/
    inline std::list<CParameter *>::iterator
    endAccessSpecResult (void)
    {
        return m_listAccessSpecResult.end();
    }

     /** @brief  Clears the LLRP AccessSpecResult sub-parameter list*/
    inline void
    clearAccessSpecResult (void)
    {
        clearSubParameterList ((tListOfParameters *) &m_listAccessSpecResult);
    }

    EResultCode
     /** @brief  Add a AccessSpecResult to the LLRP sub-parameter list*/
    addAccessSpecResult (
      CParameter * pValue);


};


/**
 ** @brief  Class Definition CSelectSpecID for LLRP parameter SelectSpecID
 **



 **/

class CSelectSpecID : public CParameter
{
  public:
    CSelectSpecID (void);
    ~CSelectSpecID (void);

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
    llrp_u32_t m_SelectSpecID;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdSelectSpecID;
//@}

    /** @brief Get accessor functions for the LLRP SelectSpecID field */
    inline llrp_u32_t
    getSelectSpecID (void)
    {
        return m_SelectSpecID;
    }

    /** @brief Set accessor functions for the LLRP SelectSpecID field */
    inline void
    setSelectSpecID (
      llrp_u32_t  value)
    {
        m_SelectSpecID = value;
    }


};


/**
 ** @brief  Class Definition CSpecIndex for LLRP parameter SpecIndex
 **



 **/

class CSpecIndex : public CParameter
{
  public:
    CSpecIndex (void);
    ~CSpecIndex (void);

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
    llrp_u16_t  m_SpecIndex;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdSpecIndex;
//@}

    /** @brief Get accessor functions for the LLRP SpecIndex field */
    inline llrp_u16_t
    getSpecIndex (void)
    {
        return m_SpecIndex;
    }

    /** @brief Set accessor functions for the LLRP SpecIndex field */
    inline void
    setSpecIndex (
      llrp_u16_t   value)
    {
        m_SpecIndex = value;
    }


};


/**
 ** @brief  Class Definition CRfSpecID for LLRP parameter RfSpecID
 **



 **/

class CRfSpecID : public CParameter
{
  public:
    CRfSpecID (void);
    ~CRfSpecID (void);

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
    llrp_u16_t  m_RfSpecID;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdRfSpecID;
//@}

    /** @brief Get accessor functions for the LLRP RfSpecID field */
    inline llrp_u16_t
    getRfSpecID (void)
    {
        return m_RfSpecID;
    }

    /** @brief Set accessor functions for the LLRP RfSpecID field */
    inline void
    setRfSpecID (
      llrp_u16_t   value)
    {
        m_RfSpecID = value;
    }


};


/**
 ** @brief  Class Definition CAntennaID for LLRP parameter AntennaID
 **



 **/

class CAntennaID : public CParameter
{
  public:
    CAntennaID (void);
    ~CAntennaID (void);

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
    llrp_u8_t  m_AntennaID;

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
      llrp_u8_t   value)
    {
        m_AntennaID = value;
    }


};


/**
 ** @brief  Class Definition CPeakRSSI for LLRP parameter PeakRSSI
 **



 **/

class CPeakRSSI : public CParameter
{
  public:
    CPeakRSSI (void);
    ~CPeakRSSI (void);

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
    llrp_s8_t m_PeakRSSI;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdPeakRSSI;
//@}

    /** @brief Get accessor functions for the LLRP PeakRSSI field */
    inline llrp_s8_t
    getPeakRSSI (void)
    {
        return m_PeakRSSI;
    }

    /** @brief Set accessor functions for the LLRP PeakRSSI field */
    inline void
    setPeakRSSI (
      llrp_s8_t  value)
    {
        m_PeakRSSI = value;
    }


};


/**
 ** @brief  Class Definition CFirstSeenTimestampUTC for LLRP parameter FirstSeenTimestampUTC
 **



 **/

class CFirstSeenTimestampUTC : public CParameter
{
  public:
    CFirstSeenTimestampUTC (void);
    ~CFirstSeenTimestampUTC (void);

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
 ** @brief  Class Definition CLastSeenTimestampUTC for LLRP parameter LastSeenTimestampUTC
 **



 **/

class CLastSeenTimestampUTC : public CParameter
{
  public:
    CLastSeenTimestampUTC (void);
    ~CLastSeenTimestampUTC (void);

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
 ** @brief  Class Definition CTagSeenCount for LLRP parameter TagSeenCount
 **



 **/

class CTagSeenCount : public CParameter
{
  public:
    CTagSeenCount (void);
    ~CTagSeenCount (void);

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
    llrp_u16_t  m_TagCount;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdTagCount;
//@}

    /** @brief Get accessor functions for the LLRP TagCount field */
    inline llrp_u16_t
    getTagCount (void)
    {
        return m_TagCount;
    }

    /** @brief Set accessor functions for the LLRP TagCount field */
    inline void
    setTagCount (
      llrp_u16_t   value)
    {
        m_TagCount = value;
    }


};


/**
 ** @brief  Class Definition CAccessSpecID for LLRP parameter AccessSpecID
 **



 **/

class CAccessSpecID : public CParameter
{
  public:
    CAccessSpecID (void);
    ~CAccessSpecID (void);

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
    llrp_u32_t m_AccessSpecID;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdAccessSpecID;
//@}

    /** @brief Get accessor functions for the LLRP AccessSpecID field */
    inline llrp_u32_t
    getAccessSpecID (void)
    {
        return m_AccessSpecID;
    }

    /** @brief Set accessor functions for the LLRP AccessSpecID field */
    inline void
    setAccessSpecID (
      llrp_u32_t  value)
    {
        m_AccessSpecID = value;
    }


};


/**
 ** @brief  Class Definition CGenaralSelectSpecResult for LLRP parameter GenaralSelectSpecResult
 **




 **/

class CGenaralSelectSpecResult : public CParameter
{
  public:
    CGenaralSelectSpecResult (void);
    ~CGenaralSelectSpecResult (void);

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
    llrp_u8_t  m_Result;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdResult;
//@}

    /** @brief Get accessor functions for the LLRP Result field */
    inline llrp_u8_t
    getResult (void)
    {
        return m_Result;
    }

    /** @brief Set accessor functions for the LLRP Result field */
    inline void
    setResult (
      llrp_u8_t   value)
    {
        m_Result = value;
    }


  protected:
    llrp_u16v_t m_TagData;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdTagData;
//@}

    /** @brief Get accessor functions for the LLRP TagData field */
    inline llrp_u16v_t
    getTagData (void)
    {
        return m_TagData;
    }

    /** @brief Set accessor functions for the LLRP TagData field */
    inline void
    setTagData (
      llrp_u16v_t  value)
    {
        m_TagData = value;
    }


};


/**
 ** @brief  Class Definition CCustomizedSelectSpecResult for LLRP parameter CustomizedSelectSpecResult
 **




 **/

class CCustomizedSelectSpecResult : public CParameter
{
  public:
    CCustomizedSelectSpecResult (void);
    ~CCustomizedSelectSpecResult (void);

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
    llrp_u8_t  m_Result;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdResult;
//@}

    /** @brief Get accessor functions for the LLRP Result field */
    inline llrp_u8_t
    getResult (void)
    {
        return m_Result;
    }

    /** @brief Set accessor functions for the LLRP Result field */
    inline void
    setResult (
      llrp_u8_t   value)
    {
        m_Result = value;
    }


  protected:
    CReadDataInfo * m_pReadDataInfo;

  public:
    /** @brief Get accessor functions for the LLRP ReadDataInfo sub-parameter */
    inline CReadDataInfo *
    getReadDataInfo (void)
    {
        return m_pReadDataInfo;
    }

    /** @brief Set accessor functions for the LLRP ReadDataInfo sub-parameter */
    EResultCode
    setReadDataInfo (
      CReadDataInfo * pValue);


};


/**
 ** @brief  Class Definition CHbCustomizedReadSpecResult for LLRP parameter HbCustomizedReadSpecResult
 **





 **/

class CHbCustomizedReadSpecResult : public CParameter
{
  public:
    CHbCustomizedReadSpecResult (void);
    ~CHbCustomizedReadSpecResult (void);

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
    llrp_u8_t  m_Result;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdResult;
//@}

    /** @brief Get accessor functions for the LLRP Result field */
    inline llrp_u8_t
    getResult (void)
    {
        return m_Result;
    }

    /** @brief Set accessor functions for the LLRP Result field */
    inline void
    setResult (
      llrp_u8_t   value)
    {
        m_Result = value;
    }


  protected:
    llrp_u16_t  m_OpSpecID;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdOpSpecID;
//@}

    /** @brief Get accessor functions for the LLRP OpSpecID field */
    inline llrp_u16_t
    getOpSpecID (void)
    {
        return m_OpSpecID;
    }

    /** @brief Set accessor functions for the LLRP OpSpecID field */
    inline void
    setOpSpecID (
      llrp_u16_t   value)
    {
        m_OpSpecID = value;
    }


  protected:
    CReadDataInfo * m_pReadDataInfo;

  public:
    /** @brief Get accessor functions for the LLRP ReadDataInfo sub-parameter */
    inline CReadDataInfo *
    getReadDataInfo (void)
    {
        return m_pReadDataInfo;
    }

    /** @brief Set accessor functions for the LLRP ReadDataInfo sub-parameter */
    EResultCode
    setReadDataInfo (
      CReadDataInfo * pValue);


};


/**
 ** @brief  Class Definition CReadDataInfo for LLRP parameter ReadDataInfo
 **















 **/

class CReadDataInfo : public CParameter
{
  public:
    CReadDataInfo (void);
    ~CReadDataInfo (void);

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
    CCID * m_pCID;

  public:
    /** @brief Get accessor functions for the LLRP CID sub-parameter */
    inline CCID *
    getCID (void)
    {
        return m_pCID;
    }

    /** @brief Set accessor functions for the LLRP CID sub-parameter */
    EResultCode
    setCID (
      CCID * pValue);


  protected:
    CFPDH * m_pFPDH;

  public:
    /** @brief Get accessor functions for the LLRP FPDH sub-parameter */
    inline CFPDH *
    getFPDH (void)
    {
        return m_pFPDH;
    }

    /** @brief Set accessor functions for the LLRP FPDH sub-parameter */
    EResultCode
    setFPDH (
      CFPDH * pValue);


  protected:
    CSYXZ * m_pSYXZ;

  public:
    /** @brief Get accessor functions for the LLRP SYXZ sub-parameter */
    inline CSYXZ *
    getSYXZ (void)
    {
        return m_pSYXZ;
    }

    /** @brief Set accessor functions for the LLRP SYXZ sub-parameter */
    EResultCode
    setSYXZ (
      CSYXZ * pValue);


  protected:
    CCCRQ * m_pCCRQ;

  public:
    /** @brief Get accessor functions for the LLRP CCRQ sub-parameter */
    inline CCCRQ *
    getCCRQ (void)
    {
        return m_pCCRQ;
    }

    /** @brief Set accessor functions for the LLRP CCRQ sub-parameter */
    EResultCode
    setCCRQ (
      CCCRQ * pValue);


  protected:
    CCLLX * m_pCLLX;

  public:
    /** @brief Get accessor functions for the LLRP CLLX sub-parameter */
    inline CCLLX *
    getCLLX (void)
    {
        return m_pCLLX;
    }

    /** @brief Set accessor functions for the LLRP CLLX sub-parameter */
    EResultCode
    setCLLX (
      CCLLX * pValue);


  protected:
    CPL * m_pPL;

  public:
    /** @brief Get accessor functions for the LLRP PL sub-parameter */
    inline CPL *
    getPL (void)
    {
        return m_pPL;
    }

    /** @brief Set accessor functions for the LLRP PL sub-parameter */
    EResultCode
    setPL (
      CPL * pValue);


  protected:
    CGL * m_pGL;

  public:
    /** @brief Get accessor functions for the LLRP GL sub-parameter */
    inline CGL *
    getGL (void)
    {
        return m_pGL;
    }

    /** @brief Set accessor functions for the LLRP GL sub-parameter */
    EResultCode
    setGL (
      CGL * pValue);


  protected:
    CHPZL * m_pHPZL;

  public:
    /** @brief Get accessor functions for the LLRP HPZL sub-parameter */
    inline CHPZL *
    getHPZL (void)
    {
        return m_pHPZL;
    }

    /** @brief Set accessor functions for the LLRP HPZL sub-parameter */
    EResultCode
    setHPZL (
      CHPZL * pValue);


  protected:
    CHPHMXH * m_pHPHMXH;

  public:
    /** @brief Get accessor functions for the LLRP HPHMXH sub-parameter */
    inline CHPHMXH *
    getHPHMXH (void)
    {
        return m_pHPHMXH;
    }

    /** @brief Set accessor functions for the LLRP HPHMXH sub-parameter */
    EResultCode
    setHPHMXH (
      CHPHMXH * pValue);


  protected:
    CJYYXQ * m_pJYYXQ;

  public:
    /** @brief Get accessor functions for the LLRP JYYXQ sub-parameter */
    inline CJYYXQ *
    getJYYXQ (void)
    {
        return m_pJYYXQ;
    }

    /** @brief Set accessor functions for the LLRP JYYXQ sub-parameter */
    EResultCode
    setJYYXQ (
      CJYYXQ * pValue);


  protected:
    CQZBFQ * m_pQZBFQ;

  public:
    /** @brief Get accessor functions for the LLRP QZBFQ sub-parameter */
    inline CQZBFQ *
    getQZBFQ (void)
    {
        return m_pQZBFQ;
    }

    /** @brief Set accessor functions for the LLRP QZBFQ sub-parameter */
    EResultCode
    setQZBFQ (
      CQZBFQ * pValue);


  protected:
    CCSYS * m_pCSYS;

  public:
    /** @brief Get accessor functions for the LLRP CSYS sub-parameter */
    inline CCSYS *
    getCSYS (void)
    {
        return m_pCSYS;
    }

    /** @brief Set accessor functions for the LLRP CSYS sub-parameter */
    EResultCode
    setCSYS (
      CCSYS * pValue);


  protected:
    CZKZL * m_pZKZL;

  public:
    /** @brief Get accessor functions for the LLRP ZKZL sub-parameter */
    inline CZKZL *
    getZKZL (void)
    {
        return m_pZKZL;
    }

    /** @brief Set accessor functions for the LLRP ZKZL sub-parameter */
    EResultCode
    setZKZL (
      CZKZL * pValue);


};


/**
 ** @brief  Class Definition CHbReadSpecResult for LLRP parameter HbReadSpecResult
 **





 **/

class CHbReadSpecResult : public CParameter
{
  public:
    CHbReadSpecResult (void);
    ~CHbReadSpecResult (void);

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
    llrp_u8_t  m_Result;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdResult;
//@}

    /** @brief Get accessor functions for the LLRP Result field */
    inline llrp_u8_t
    getResult (void)
    {
        return m_Result;
    }

    /** @brief Set accessor functions for the LLRP Result field */
    inline void
    setResult (
      llrp_u8_t   value)
    {
        m_Result = value;
    }


  protected:
    llrp_u16_t  m_OpSpecID;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdOpSpecID;
//@}

    /** @brief Get accessor functions for the LLRP OpSpecID field */
    inline llrp_u16_t
    getOpSpecID (void)
    {
        return m_OpSpecID;
    }

    /** @brief Set accessor functions for the LLRP OpSpecID field */
    inline void
    setOpSpecID (
      llrp_u16_t   value)
    {
        m_OpSpecID = value;
    }


  protected:
    llrp_u16v_t m_ReadData;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdReadData;
//@}

    /** @brief Get accessor functions for the LLRP ReadData field */
    inline llrp_u16v_t
    getReadData (void)
    {
        return m_ReadData;
    }

    /** @brief Set accessor functions for the LLRP ReadData field */
    inline void
    setReadData (
      llrp_u16v_t  value)
    {
        m_ReadData = value;
    }


};


/**
 ** @brief  Class Definition CCID for LLRP parameter CID
 **



 **/

class CCID : public CParameter
{
  public:
    CCID (void);
    ~CCID (void);

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
    llrp_u8v_t m_CIDData;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdCIDData;
//@}

    /** @brief Get accessor functions for the LLRP CIDData field */
    inline llrp_u8v_t
    getCIDData (void)
    {
        return m_CIDData;
    }

    /** @brief Set accessor functions for the LLRP CIDData field */
    inline void
    setCIDData (
      llrp_u8v_t  value)
    {
        m_CIDData = value;
    }


};


/**
 ** @brief  Class Definition CFPDH for LLRP parameter FPDH
 **



 **/

class CFPDH : public CParameter
{
  public:
    CFPDH (void);
    ~CFPDH (void);

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
    llrp_u8v_t m_FPDHData;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdFPDHData;
//@}

    /** @brief Get accessor functions for the LLRP FPDHData field */
    inline llrp_u8v_t
    getFPDHData (void)
    {
        return m_FPDHData;
    }

    /** @brief Set accessor functions for the LLRP FPDHData field */
    inline void
    setFPDHData (
      llrp_u8v_t  value)
    {
        m_FPDHData = value;
    }


};


/**
 ** @brief  Class Definition CSYXZ for LLRP parameter SYXZ
 **



 **/

class CSYXZ : public CParameter
{
  public:
    CSYXZ (void);
    ~CSYXZ (void);

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
    llrp_u8v_t m_SYXZData;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdSYXZData;
//@}

    /** @brief Get accessor functions for the LLRP SYXZData field */
    inline llrp_u8v_t
    getSYXZData (void)
    {
        return m_SYXZData;
    }

    /** @brief Set accessor functions for the LLRP SYXZData field */
    inline void
    setSYXZData (
      llrp_u8v_t  value)
    {
        m_SYXZData = value;
    }


};


/**
 ** @brief  Class Definition CCCRQ for LLRP parameter CCRQ
 **



 **/

class CCCRQ : public CParameter
{
  public:
    CCCRQ (void);
    ~CCCRQ (void);

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
    llrp_u8v_t m_CCRQData;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdCCRQData;
//@}

    /** @brief Get accessor functions for the LLRP CCRQData field */
    inline llrp_u8v_t
    getCCRQData (void)
    {
        return m_CCRQData;
    }

    /** @brief Set accessor functions for the LLRP CCRQData field */
    inline void
    setCCRQData (
      llrp_u8v_t  value)
    {
        m_CCRQData = value;
    }


};


/**
 ** @brief  Class Definition CCLLX for LLRP parameter CLLX
 **



 **/

class CCLLX : public CParameter
{
  public:
    CCLLX (void);
    ~CCLLX (void);

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
    llrp_u8v_t m_CLLXData;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdCLLXData;
//@}

    /** @brief Get accessor functions for the LLRP CLLXData field */
    inline llrp_u8v_t
    getCLLXData (void)
    {
        return m_CLLXData;
    }

    /** @brief Set accessor functions for the LLRP CLLXData field */
    inline void
    setCLLXData (
      llrp_u8v_t  value)
    {
        m_CLLXData = value;
    }


};


/**
 ** @brief  Class Definition CGL for LLRP parameter GL
 **



 **/

class CGL : public CParameter
{
  public:
    CGL (void);
    ~CGL (void);

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
    llrp_u8v_t m_GLData;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdGLData;
//@}

    /** @brief Get accessor functions for the LLRP GLData field */
    inline llrp_u8v_t
    getGLData (void)
    {
        return m_GLData;
    }

    /** @brief Set accessor functions for the LLRP GLData field */
    inline void
    setGLData (
      llrp_u8v_t  value)
    {
        m_GLData = value;
    }


};


/**
 ** @brief  Class Definition CPL for LLRP parameter PL
 **



 **/

class CPL : public CParameter
{
  public:
    CPL (void);
    ~CPL (void);

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
    llrp_u8v_t m_PLData;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdPLData;
//@}

    /** @brief Get accessor functions for the LLRP PLData field */
    inline llrp_u8v_t
    getPLData (void)
    {
        return m_PLData;
    }

    /** @brief Set accessor functions for the LLRP PLData field */
    inline void
    setPLData (
      llrp_u8v_t  value)
    {
        m_PLData = value;
    }


};


/**
 ** @brief  Class Definition CHPZL for LLRP parameter HPZL
 **



 **/

class CHPZL : public CParameter
{
  public:
    CHPZL (void);
    ~CHPZL (void);

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
    llrp_u8v_t m_HPZLData;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdHPZLData;
//@}

    /** @brief Get accessor functions for the LLRP HPZLData field */
    inline llrp_u8v_t
    getHPZLData (void)
    {
        return m_HPZLData;
    }

    /** @brief Set accessor functions for the LLRP HPZLData field */
    inline void
    setHPZLData (
      llrp_u8v_t  value)
    {
        m_HPZLData = value;
    }


};


/**
 ** @brief  Class Definition CHPHMXH for LLRP parameter HPHMXH
 **



 **/

class CHPHMXH : public CParameter
{
  public:
    CHPHMXH (void);
    ~CHPHMXH (void);

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
    llrp_u8v_t m_HPHMXHData;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdHPHMXHData;
//@}

    /** @brief Get accessor functions for the LLRP HPHMXHData field */
    inline llrp_u8v_t
    getHPHMXHData (void)
    {
        return m_HPHMXHData;
    }

    /** @brief Set accessor functions for the LLRP HPHMXHData field */
    inline void
    setHPHMXHData (
      llrp_u8v_t  value)
    {
        m_HPHMXHData = value;
    }


};


/**
 ** @brief  Class Definition CJYYXQ for LLRP parameter JYYXQ
 **



 **/

class CJYYXQ : public CParameter
{
  public:
    CJYYXQ (void);
    ~CJYYXQ (void);

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
    llrp_u8v_t m_JYYXQData;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdJYYXQData;
//@}

    /** @brief Get accessor functions for the LLRP JYYXQData field */
    inline llrp_u8v_t
    getJYYXQData (void)
    {
        return m_JYYXQData;
    }

    /** @brief Set accessor functions for the LLRP JYYXQData field */
    inline void
    setJYYXQData (
      llrp_u8v_t  value)
    {
        m_JYYXQData = value;
    }


};


/**
 ** @brief  Class Definition CQZBFQ for LLRP parameter QZBFQ
 **



 **/

class CQZBFQ : public CParameter
{
  public:
    CQZBFQ (void);
    ~CQZBFQ (void);

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
    llrp_u8v_t m_QZBFQData;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdQZBFQData;
//@}

    /** @brief Get accessor functions for the LLRP QZBFQData field */
    inline llrp_u8v_t
    getQZBFQData (void)
    {
        return m_QZBFQData;
    }

    /** @brief Set accessor functions for the LLRP QZBFQData field */
    inline void
    setQZBFQData (
      llrp_u8v_t  value)
    {
        m_QZBFQData = value;
    }


};


/**
 ** @brief  Class Definition CZKZL for LLRP parameter ZKZL
 **



 **/

class CZKZL : public CParameter
{
  public:
    CZKZL (void);
    ~CZKZL (void);

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
    llrp_u8v_t m_ZKZLData;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdZKZLData;
//@}

    /** @brief Get accessor functions for the LLRP ZKZLData field */
    inline llrp_u8v_t
    getZKZLData (void)
    {
        return m_ZKZLData;
    }

    /** @brief Set accessor functions for the LLRP ZKZLData field */
    inline void
    setZKZLData (
      llrp_u8v_t  value)
    {
        m_ZKZLData = value;
    }


};


/**
 ** @brief  Class Definition CCSYS for LLRP parameter CSYS
 **



 **/

class CCSYS : public CParameter
{
  public:
    CCSYS (void);
    ~CCSYS (void);

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
    llrp_u8v_t m_CSYSData;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdCSYSData;
//@}

    /** @brief Get accessor functions for the LLRP CSYSData field */
    inline llrp_u8v_t
    getCSYSData (void)
    {
        return m_CSYSData;
    }

    /** @brief Set accessor functions for the LLRP CSYSData field */
    inline void
    setCSYSData (
      llrp_u8v_t  value)
    {
        m_CSYSData = value;
    }


};


/**
 ** @brief  Class Definition CHbWriteSpecResult for LLRP parameter HbWriteSpecResult
 **





 **/

class CHbWriteSpecResult : public CParameter
{
  public:
    CHbWriteSpecResult (void);
    ~CHbWriteSpecResult (void);

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
    llrp_u8_t  m_Result;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdResult;
//@}

    /** @brief Get accessor functions for the LLRP Result field */
    inline llrp_u8_t
    getResult (void)
    {
        return m_Result;
    }

    /** @brief Set accessor functions for the LLRP Result field */
    inline void
    setResult (
      llrp_u8_t   value)
    {
        m_Result = value;
    }


  protected:
    llrp_u8v_t m_ResultDescription;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdResultDescription;
//@}

    /** @brief Get accessor functions for the LLRP ResultDescription field */
    inline llrp_u8v_t
    getResultDescription (void)
    {
        return m_ResultDescription;
    }

    /** @brief Set accessor functions for the LLRP ResultDescription field */
    inline void
    setResultDescription (
      llrp_u8v_t  value)
    {
        m_ResultDescription = value;
    }


  protected:
    llrp_u16_t  m_OpSpecID;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdOpSpecID;
//@}

    /** @brief Get accessor functions for the LLRP OpSpecID field */
    inline llrp_u16_t
    getOpSpecID (void)
    {
        return m_OpSpecID;
    }

    /** @brief Set accessor functions for the LLRP OpSpecID field */
    inline void
    setOpSpecID (
      llrp_u16_t   value)
    {
        m_OpSpecID = value;
    }


};


/**
 ** @brief  Class Definition CClientRequestSpecResult for LLRP parameter ClientRequestSpecResult
 **



 **/

class CClientRequestSpecResult : public CParameter
{
  public:
    CClientRequestSpecResult (void);
    ~CClientRequestSpecResult (void);

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
    llrp_u16_t  m_OpSpecID;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdOpSpecID;
//@}

    /** @brief Get accessor functions for the LLRP OpSpecID field */
    inline llrp_u16_t
    getOpSpecID (void)
    {
        return m_OpSpecID;
    }

    /** @brief Set accessor functions for the LLRP OpSpecID field */
    inline void
    setOpSpecID (
      llrp_u16_t   value)
    {
        m_OpSpecID = value;
    }


};



/**
 ** @brief  Class Definition CEnableCachedEventsAndReport for LLRP message EnableCachedEventsAndReport
 **


 **/

class CEnableCachedEventsAndReport : public CMessage
{
  public:
    CEnableCachedEventsAndReport (void);
    ~CEnableCachedEventsAndReport (void);

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
 ** @brief  Class Definition CCachedSelectAccessReport for LLRP message CachedSelectAccessReport
 **






 **/

class CCachedSelectAccessReport : public CMessage
{
  public:
    CCachedSelectAccessReport (void);
    ~CCachedSelectAccessReport (void);

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
    llrp_u16_t m_SequenceID;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdSequenceID;
//@}

    /** @brief Get accessor functions for the LLRP SequenceID field */
    inline llrp_u16_t
    getSequenceID (void)
    {
        return m_SequenceID;
    }

    /** @brief Set accessor functions for the LLRP SequenceID field */
    inline void
    setSequenceID (
      llrp_u16_t  value)
    {
        m_SequenceID = value;
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
    std::list<CTagReportData *> m_listTagReportData;

  public:
     /** @brief  Returns the first element of the TagReportData sub-parameter list*/
    inline std::list<CTagReportData *>::iterator
    beginTagReportData (void)
    {
        return m_listTagReportData.begin();
    }

     /** @brief  Returns the last element of the TagReportData sub-parameter list*/
    inline std::list<CTagReportData *>::iterator
    endTagReportData (void)
    {
        return m_listTagReportData.end();
    }

     /** @brief  Clears the LLRP TagReportData sub-parameter list*/
    inline void
    clearTagReportData (void)
    {
        clearSubParameterList ((tListOfParameters *) &m_listTagReportData);
    }

    EResultCode
     /** @brief  Add a TagReportData to the LLRP sub-parameter list*/
    addTagReportData (
      CTagReportData * pValue);


};


/**
 ** @brief  Class Definition CCachedSelectAccessReportAck for LLRP message CachedSelectAccessReportAck
 **



 **/

class CCachedSelectAccessReportAck : public CMessage
{
  public:
    CCachedSelectAccessReportAck (void);
    ~CCachedSelectAccessReportAck (void);

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
    llrp_u16_t m_SequenceID;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdSequenceID;
//@}

    /** @brief Get accessor functions for the LLRP SequenceID field */
    inline llrp_u16_t
    getSequenceID (void)
    {
        return m_SequenceID;
    }

    /** @brief Set accessor functions for the LLRP SequenceID field */
    inline void
    setSequenceID (
      llrp_u16_t  value)
    {
        m_SequenceID = value;
    }


};


/**
 ** @brief  Class Definition CClientRequestAck for LLRP parameter ClientRequestAck
 **





 **/

class CClientRequestAck : public CParameter
{
  public:
    CClientRequestAck (void);
    ~CClientRequestAck (void);

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
    llrp_u32_t m_AccessSpecID;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdAccessSpecID;
//@}

    /** @brief Get accessor functions for the LLRP AccessSpecID field */
    inline llrp_u32_t
    getAccessSpecID (void)
    {
        return m_AccessSpecID;
    }

    /** @brief Set accessor functions for the LLRP AccessSpecID field */
    inline void
    setAccessSpecID (
      llrp_u32_t  value)
    {
        m_AccessSpecID = value;
    }


  protected:
    llrp_u8v_t m_TID;

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
      llrp_u8v_t  value)
    {
        m_TID = value;
    }


  protected:
    std::list<CParameter *> m_listOpSpec;

  public:
     /** @brief  Returns the first element of the OpSpec sub-parameter list*/
    inline std::list<CParameter *>::iterator
    beginOpSpec (void)
    {
        return m_listOpSpec.begin();
    }

     /** @brief  Returns the last element of the OpSpec sub-parameter list*/
    inline std::list<CParameter *>::iterator
    endOpSpec (void)
    {
        return m_listOpSpec.end();
    }

     /** @brief  Clears the LLRP OpSpec sub-parameter list*/
    inline void
    clearOpSpec (void)
    {
        clearSubParameterList ((tListOfParameters *) &m_listOpSpec);
    }

    EResultCode
     /** @brief  Add a OpSpec to the LLRP sub-parameter list*/
    addOpSpec (
      CParameter * pValue);


};


/*@}*/

class COpSpec
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

class CSelectSpecResult
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

class CAccessSpecResult
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
