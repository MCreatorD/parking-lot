#ifndef __LLRP_GENERAL_H__
#define __LLRP_GENERAL_H__

#include "LLRP_Hb_Classes.h"

/*
*	这里是通用的一些参数
*/

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
class CKeepalive;
class CKeepaliveAck;
class CDeviceEventNotification;
*/
/* Custom messages */


/*
 * Parameter classes - forward decls
 */
/*
class CStatus;
class CUTCTimestamp;
class CGPIEvent;
class CSelectSpecEvent;
class CAntennaSpecEvent;
class CAntennaStatusEvent;
class CConnectionAttemptEvent;
*/
/* Custom parameters */


/*
 * Vendor descriptor declarations.
 */


/*
 * Namespace descriptor declarations.
 */

extern const CNamespaceDescriptor
g_nsdescllrp;


/*
 * Enumeration definitions and declarations of
 * enumeration string tables.
 */


/**
 ** @brief  Global enumeration EStatusCode  for LLRP enumerated field StatusCode
 **
 
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
  
 **/

enum EStatusCode
{
StatusCode_M_Success = 0, /**< M_Success */ StatusCode_M_ParameterError = 100, /**< M_ParameterError */ StatusCode_M_FieldError = 101, /**< M_FieldError */ StatusCode_M_UnexpectedParameter = 102, /**< M_UnexpectedParameter */ StatusCode_M_MissingParameter = 103, /**< M_MissingParameter */ StatusCode_M_DuplicateParameter = 104, /**< M_DuplicateParameter */ StatusCode_M_OverflowParameter = 105, /**< M_OverflowParameter */ StatusCode_M_OverflowField = 106, /**< M_OverflowField */ StatusCode_M_UnknownParameter = 107, /**< M_UnknownParameter */ StatusCode_M_UnknownField = 108, /**< M_UnknownField */ StatusCode_M_UnsupportedMessage = 109, /**< M_UnsupportedMessage */ StatusCode_M_UnsupportedVersion = 110, /**< M_UnsupportedVersion */ StatusCode_M_UnsupportedParameter = 111, /**< M_UnsupportedParameter */ StatusCode_P_ParameterError = 200, /**< P_ParameterError */ StatusCode_P_FieldError = 201, /**< P_FieldError */ StatusCode_P_UnexpectedParameter = 202, /**< P_UnexpectedParameter */ StatusCode_P_MissingParameter = 203, /**< P_MissingParameter */ StatusCode_P_DuplicateParameter = 204, /**< P_DuplicateParameter */ StatusCode_P_OverflowParameter = 205, /**< P_OverflowParameter */ StatusCode_P_OverflowField = 206, /**< P_OverflowField */ StatusCode_P_UnknownParameter = 207, /**< P_UnknownParameter */ StatusCode_P_UnknownField = 208, /**< P_UnknownField */ StatusCode_P_UnsupportedParameter = 209, /**< P_UnsupportedParameter */ StatusCode_A_Invalid = 300, /**< A_Invalid */ StatusCode_A_OutOfRange = 301, /**< A_OutOfRange */ StatusCode_R_DeviceError = 401, /**< R_DeviceError */  
};

extern const SEnumTableEntry
g_estStatusCode[];


/**
 ** @brief  Global enumeration EGPIEvent  for LLRP enumerated field GPIEvent
 **
 
    
    
  
 **/

enum EGPIEvent
{
GPIEvent_DOWN = 0, /**< DOWN */ GPIEvent_UP = 1, /**< UP */  
};

extern const SEnumTableEntry
g_estGPIEvent[];


/**
 ** @brief  Global enumeration EEventType   for LLRP enumerated field EventType
 **
 
    
    
    
  
 **/

enum EEventType
{
EventType_Start = 0, /**< Start */ EventType_End = 1, /**< End */ EventType_Priority = 2, /**< Priority */  
};

extern const SEnumTableEntry
g_estEventType[];


/**
 ** @brief  Global enumeration EConnectionStatus for LLRP enumerated field ConnectionStatus
 **
 
    
    
    
    
  
 **/

enum EConnectionStatus
{
ConnectionStatus_Success = 0, /**< Success */ ConnectionStatus_ClientConnectExist = 1, /**< ClientConnectExist */ ConnectionStatus_ServerConnectExist = 2, /**< ServerConnectExist */ ConnectionStatus_OtherError = 3, /**< OtherError */  
};

extern const SEnumTableEntry
g_estConnectionStatus[];


/** 
 * \defgroup CoreMessage  Core Message Classes
 * Classes to manipulate the messages defined by the Core LLRP protocol
 */
/*@{*/ 

/**
 ** @brief  Class Definition CKeepalive for LLRP message Keepalive
 **
 
  
 **/

class CKeepalive : public CMessage
{
  public:
    CKeepalive (void);
    ~CKeepalive (void);

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
 ** @brief  Class Definition CKeepaliveAck for LLRP message KeepaliveAck
 **
 
  
 **/

class CKeepaliveAck : public CMessage
{
  public:
    CKeepaliveAck (void);
    ~CKeepaliveAck (void);

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
 ** @brief  Class Definition CDeviceEventNotification for LLRP message DeviceEventNotification
 **
 
    
    
    
    
    
    
  
 **/

class CDeviceEventNotification : public CMessage
{
  public:
    CDeviceEventNotification (void);
    ~CDeviceEventNotification (void);

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


  protected:
    CGPIEvent * m_pGPIEvent;

  public:
    /** @brief Get accessor functions for the LLRP GPIEvent sub-parameter */  
    inline CGPIEvent *
    getGPIEvent (void)
    {
        return m_pGPIEvent;
    }

    /** @brief Set accessor functions for the LLRP GPIEvent sub-parameter */  
    EResultCode
    setGPIEvent (
      CGPIEvent * pValue);


  protected:
    CSelectSpecEvent * m_pSelectSpecEvent;

  public:
    /** @brief Get accessor functions for the LLRP SelectSpecEvent sub-parameter */  
    inline CSelectSpecEvent *
    getSelectSpecEvent (void)
    {
        return m_pSelectSpecEvent;
    }

    /** @brief Set accessor functions for the LLRP SelectSpecEvent sub-parameter */  
    EResultCode
    setSelectSpecEvent (
      CSelectSpecEvent * pValue);


  protected:
    CAntennaSpecEvent * m_pAntennaSpecEvent;

  public:
    /** @brief Get accessor functions for the LLRP AntennaSpecEvent sub-parameter */  
    inline CAntennaSpecEvent *
    getAntennaSpecEvent (void)
    {
        return m_pAntennaSpecEvent;
    }

    /** @brief Set accessor functions for the LLRP AntennaSpecEvent sub-parameter */  
    EResultCode
    setAntennaSpecEvent (
      CAntennaSpecEvent * pValue);


  protected:
    CAntennaStatusEvent * m_pAntennaStatusEvent;

  public:
    /** @brief Get accessor functions for the LLRP AntennaStatusEvent sub-parameter */  
    inline CAntennaStatusEvent *
    getAntennaStatusEvent (void)
    {
        return m_pAntennaStatusEvent;
    }

    /** @brief Set accessor functions for the LLRP AntennaStatusEvent sub-parameter */  
    EResultCode
    setAntennaStatusEvent (
      CAntennaStatusEvent * pValue);


  protected:
    CConnectionAttemptEvent * m_pConnectionAttemptEvent;

  public:
    /** @brief Get accessor functions for the LLRP ConnectionAttemptEvent sub-parameter */  
    inline CConnectionAttemptEvent *
    getConnectionAttemptEvent (void)
    {
        return m_pConnectionAttemptEvent;
    }

    /** @brief Set accessor functions for the LLRP ConnectionAttemptEvent sub-parameter */  
    EResultCode
    setConnectionAttemptEvent (
      CConnectionAttemptEvent * pValue);


};


/*@}*/

/** 
 * \defgroup CoreParameter Core Parameter Classes
 * Classes to manipulate the parameters defined by the Core LLRP protocol
 */
/*@{*/ 

/**
 ** @brief  Class Definition CStatus for LLRP parameter Status
 **
 
    
    
  
 **/

class CStatus : public CParameter
{
  public:
    CStatus (void);
    ~CStatus (void);

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
    EStatusCode  m_eStatusCode ;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdStatusCode;
//@}

    /** @brief Get accessor functions for the LLRP StatusCode field */
    inline EStatusCode
    getStatusCode (void)
    {
        return m_eStatusCode ;
    }

    /** @brief Set accessor functions for the LLRP StatusCode field */
    inline void
    setStatusCode (
      EStatusCode  value)
    {
        m_eStatusCode  = value;
    }


  protected:
    llrp_utf8v_t  m_ErrorDescription;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdErrorDescription;
//@}

    /** @brief Get accessor functions for the LLRP ErrorDescription field */
    inline llrp_utf8v_t
    getErrorDescription (void)
    {
        return m_ErrorDescription;
    }

    /** @brief Set accessor functions for the LLRP ErrorDescription field */
    inline void
    setErrorDescription (
      llrp_utf8v_t  value)
    {
        m_ErrorDescription = value;
    }


};


/**
 ** @brief  Class Definition CUTCTimestamp for LLRP parameter UTCTimestamp
 **
 
    
  
 **/

class CUTCTimestamp : public CParameter
{
  public:
    CUTCTimestamp (void);
    ~CUTCTimestamp (void);

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
    llrp_u64_t  m_Microseconds;

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
 ** @brief  Class Definition CGPIEvent for LLRP parameter GPIEvent
 **
 
    
    
    
  
 **/

class CGPIEvent : public CParameter
{
  public:
    CGPIEvent (void);
    ~CGPIEvent (void);

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
    llrp_u8_t  m_GPIPortNumber;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdGPIPortNumber;
//@}

    /** @brief Get accessor functions for the LLRP GPIPortNumber field */
    inline llrp_u8_t
    getGPIPortNumber (void)
    {
        return m_GPIPortNumber;
    }

    /** @brief Set accessor functions for the LLRP GPIPortNumber field */
    inline void
    setGPIPortNumber (
      llrp_u8_t  value)
    {
        m_GPIPortNumber = value;
    }


  protected:
    EGPIEvent  m_eGPIEvent ;

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
        return m_eGPIEvent ;
    }

    /** @brief Set accessor functions for the LLRP GPIEvent field */
    inline void
    setGPIEvent (
      EGPIEvent  value)
    {
        m_eGPIEvent  = value;
    }


};


/**
 ** @brief  Class Definition CSelectSpecEvent for LLRP parameter SelectSpecEvent
 **
 
    
    
    
  
 **/

class CSelectSpecEvent : public CParameter
{
  public:
    CSelectSpecEvent (void);
    ~CSelectSpecEvent (void);

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
    EEventType   m_eEventType  ;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdEventType;
//@}

    /** @brief Get accessor functions for the LLRP EventType field */
    inline EEventType
    getEventType (void)
    {
        return m_eEventType  ;
    }

    /** @brief Set accessor functions for the LLRP EventType field */
    inline void
    setEventType (
      EEventType   value)
    {
        m_eEventType   = value;
    }


  protected:
    llrp_u32_t  m_SelectSpecID;

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
    llrp_u32_t m_PreemptingSelectSpecID;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdPreemptingSelectSpecID;
//@}

    /** @brief Get accessor functions for the LLRP PreemptingSelectSpecID field */
    inline llrp_u32_t
    getPreemptingSelectSpecID (void)
    {
        return m_PreemptingSelectSpecID;
    }

    /** @brief Set accessor functions for the LLRP PreemptingSelectSpecID field */
    inline void
    setPreemptingSelectSpecID (
      llrp_u32_t  value)
    {
        m_PreemptingSelectSpecID = value;
    }


};


/**
 ** @brief  Class Definition CAntennaSpecEvent for LLRP parameter AntennaSpecEvent
 **
 
    
    
    
  
 **/

class CAntennaSpecEvent : public CParameter
{
  public:
    CAntennaSpecEvent (void);
    ~CAntennaSpecEvent (void);

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
    EEventType  m_eEventType  ;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdEventType;
//@}

    /** @brief Get accessor functions for the LLRP EventType field */
    inline EEventType
    getEventType (void)
    {
        return m_eEventType  ;
    }

    /** @brief Set accessor functions for the LLRP EventType field */
    inline void
    setEventType (
      EEventType   value)
    {
        m_eEventType   = value;
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
    llrp_u16_t   m_SpecIndex;

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
 ** @brief  Class Definition CAntennaStatusEvent for LLRP parameter AntennaStatusEvent
 **
 
    
    
  
 **/

class CAntennaStatusEvent : public CParameter
{
  public:
    CAntennaStatusEvent (void);
    ~CAntennaStatusEvent (void);

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
    EEventType  m_eEventType  ;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdEventType;
//@}

    /** @brief Get accessor functions for the LLRP EventType field */
    inline EEventType
    getEventType (void)
    {
        return m_eEventType  ;
    }

    /** @brief Set accessor functions for the LLRP EventType field */
    inline void
    setEventType (
      EEventType   value)
    {
        m_eEventType   = value;
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
 ** @brief  Class Definition CConnectionAttemptEvent for LLRP parameter ConnectionAttemptEvent
 **
 
    
  
 **/

class CConnectionAttemptEvent : public CParameter
{
  public:
    CConnectionAttemptEvent (void);
    ~CConnectionAttemptEvent (void);

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
    EConnectionStatus m_eConnectionStatus;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdConnectionStatus;
//@}

    /** @brief Get accessor functions for the LLRP ConnectionStatus field */
    inline EConnectionStatus
    getConnectionStatus (void)
    {
        return m_eConnectionStatus;
    }

    /** @brief Set accessor functions for the LLRP ConnectionStatus field */
    inline void
    setConnectionStatus (
      EConnectionStatus value)
    {
        m_eConnectionStatus = value;
    }


};


/*@}*/ 


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
