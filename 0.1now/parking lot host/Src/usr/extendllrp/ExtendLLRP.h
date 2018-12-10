#ifndef __EXTENDLLRP_H__
#define __EXTENDLLRP_H__
#include "HbFrame_Operation.h"
#include "ExtendLLRP_Message_ID.h"
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

class CManufacturerCommand;
class CManufacturerCommandAck;
class CManufacturerReport;
class CManufacturerReportAck;

/* Custom messages */


/*
 * Parameter classes - forward decls
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
 * \defgroup CoreMessage  Core Message Classes
 * Classes to manipulate the messages defined by the Core LLRP protocol
 */
/*@{*/ 

/**
 ** @brief  Class Definition CManufacturerCommand for LLRP message ManufacturerCommand
 **
 
    
  
 **/

class CManufacturerCommand : public CMessage
{
  public:
    CManufacturerCommand (void);
    ~CManufacturerCommand (void);

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
    llrp_u8v_t m_ByteStream;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdByteStream;
//@}

    /** @brief Get accessor functions for the LLRP ByteStream field */
    inline llrp_u8v_t
    getByteStream (void)
    {
        return m_ByteStream;
    }

    /** @brief Set accessor functions for the LLRP ByteStream field */
    inline void
    setByteStream (
      llrp_u8v_t  value)
    {
        m_ByteStream = value;
    }


};


/**
 ** @brief  Class Definition CManufacturerCommandAck for LLRP message ManufacturerCommandAck
 **
 
    
  
 **/

class CManufacturerCommandAck : public CMessage
{
  public:
    CManufacturerCommandAck (void);
    ~CManufacturerCommandAck (void);

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
 ** @brief  Class Definition CManufacturerReport for LLRP message ManufacturerReport
 **
 
    
  
 **/

class CManufacturerReport : public CMessage
{
  public:
    CManufacturerReport (void);
    ~CManufacturerReport (void);

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
    llrp_u8v_t m_ByteStream;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdByteStream;
//@}

    /** @brief Get accessor functions for the LLRP ByteStream field */
    inline llrp_u8v_t
    getByteStream (void)
    {
        return m_ByteStream;
    }

    /** @brief Set accessor functions for the LLRP ByteStream field */
    inline void
    setByteStream (
      llrp_u8v_t  value)
    {
        m_ByteStream = value;
    }


};


/**
 ** @brief  Class Definition CManufacturerReportAck for LLRP message ManufacturerReportAck
 **
 
    
  
 **/

class CManufacturerReportAck : public CMessage
{
  public:
    CManufacturerReportAck (void);
    ~CManufacturerReportAck (void);

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
tmp_enrollCoreTypesIntoRegistry (
  CTypeRegistry *               pTypeRegistry);

#endif
