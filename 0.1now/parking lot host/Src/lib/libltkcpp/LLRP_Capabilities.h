#ifndef __LLRP_CAPABILITIES_H__
#define __LLRP_CAPABILITIES_H__



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
class CGetDeviceCapabilities;
class CGetDeviceCapabilitiesAck;
*/
/* Custom messages */


/*
 * Parameter classes - forward decls
 */
/*
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
 ** @brief  Global enumeration EGetDeviceCapabilitiesRequestedData  for LLRP enumerated field GetDeviceCapabilitiesRequestedData
 **
 
    
    
    
    
    
    
    
  
 **/

enum EGetDeviceCapabilitiesRequestedData
{
GetDeviceCapabilitiesRequestedData_All = 0, /**< All */ GetDeviceCapabilitiesRequestedData_GenaralCapabilities = 1, /**< GenaralCapabilities */ GetDeviceCapabilitiesRequestedData_CommunicationCapabilities = 2, /**< CommunicationCapabilities */ GetDeviceCapabilitiesRequestedData_SpecCapabilities = 3, /**< SpecCapabilities */ GetDeviceCapabilitiesRequestedData_RfCapabilities = 4, /**< RfCapabilities */ GetDeviceCapabilitiesRequestedData_AirProtocolCapabilities = 5, /**< AirProtocolCapabilities */
};

extern const SEnumTableEntry
g_estGetDeviceCapabilitiesRequestedData[];



/** 
 * \defgroup CoreMessage  Core Message Classes
 * Classes to manipulate the messages defined by the Core LLRP protocol
 */
/*@{*/ 

/**
 ** @brief  Class Definition CGetDeviceCapabilities for LLRP message GetDeviceCapabilities
 **
 
    
  
 **/

class CGetDeviceCapabilities : public CMessage
{
  public:
    CGetDeviceCapabilities (void);
    ~CGetDeviceCapabilities (void);

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
    EGetDeviceCapabilitiesRequestedData  m_eRequestedData;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdRequestedData;
//@}

    /** @brief Get accessor functions for the LLRP RequestedData field */
    inline EGetDeviceCapabilitiesRequestedData
    getRequestedData (void)
    {
        return m_eRequestedData;
    }

    /** @brief Set accessor functions for the LLRP RequestedData field */
    inline void
    setRequestedData (
      EGetDeviceCapabilitiesRequestedData  value)
    {
        m_eRequestedData = value;
    }


};


/**
 ** @brief  Class Definition CGetDeviceCapabilitiesAck for LLRP message GetDeviceCapabilitiesAck
 **








 **/

class CGetDeviceCapabilitiesAck : public CMessage
{
  public:
    CGetDeviceCapabilitiesAck (void);
    ~CGetDeviceCapabilitiesAck (void);

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
    CGenaralCapabilities * m_pGenaralCapabilities;

  public:
    /** @brief Get accessor functions for the LLRP GenaralCapabilities sub-parameter */
    inline CGenaralCapabilities *
    getGenaralCapabilities (void)
    {
        return m_pGenaralCapabilities;
    }

    /** @brief Set accessor functions for the LLRP GenaralCapabilities sub-parameter */
    EResultCode
    setGenaralCapabilities (
      CGenaralCapabilities * pValue);


  protected:
    CCommunicationCapabilities * m_pCommunicationCapabilities;

  public:
    /** @brief Get accessor functions for the LLRP CommunicationCapabilities sub-parameter */
    inline CCommunicationCapabilities *
    getCommunicationCapabilities (void)
    {
        return m_pCommunicationCapabilities;
    }

    /** @brief Set accessor functions for the LLRP CommunicationCapabilities sub-parameter */
    EResultCode
    setCommunicationCapabilities (
      CCommunicationCapabilities * pValue);


  protected:
    CSpecCapabilities * m_pSpecCapabilities;

  public:
    /** @brief Get accessor functions for the LLRP SpecCapabilities sub-parameter */
    inline CSpecCapabilities *
    getSpecCapabilities (void)
    {
        return m_pSpecCapabilities;
    }

    /** @brief Set accessor functions for the LLRP SpecCapabilities sub-parameter */
    EResultCode
    setSpecCapabilities (
      CSpecCapabilities * pValue);


  protected:
    CRfCapabilities * m_pRfCapabilities;

  public:
    /** @brief Get accessor functions for the LLRP RfCapabilities sub-parameter */
    inline CRfCapabilities *
    getRfCapabilities (void)
    {
        return m_pRfCapabilities;
    }

    /** @brief Set accessor functions for the LLRP RfCapabilities sub-parameter */
    EResultCode
    setRfCapabilities (
      CRfCapabilities * pValue);


  protected:
    CAirProtocolCapabilities * m_pAirProtocolCapabilities;

  public:
    /** @brief Get accessor functions for the LLRP AirProtocolCapabilities sub-parameter */
    inline CAirProtocolCapabilities *
    getAirProtocolCapabilities (void)
    {
        return m_pAirProtocolCapabilities;
    }

    /** @brief Set accessor functions for the LLRP AirProtocolCapabilities sub-parameter */
    EResultCode
    setAirProtocolCapabilities (
      CAirProtocolCapabilities * pValue);


};


/*@}*/

/** 
 * \defgroup CoreParameter Core Parameter Classes
 * Classes to manipulate the parameters defined by the Core LLRP protocol
 */
/*@{*/ 

/**
 ** @brief  Class Definition CGenaralCapabilities for LLRP parameter GenaralCapabilities
 **
 
    
    
    
    
    
    
    
    
  
 **/


class CGenaralCapabilities : public CParameter
{
  public:
    CGenaralCapabilities (void);
    ~CGenaralCapabilities (void);

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
    llrp_utf8v_t m_DeviceManufacturerName;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdDeviceManufacturerName;
//@}

    /** @brief Get accessor functions for the LLRP DeviceManufacturerName field */
    inline llrp_utf8v_t
    getDeviceManufacturerName (void)
    {
        return m_DeviceManufacturerName;
    }

    /** @brief Set accessor functions for the LLRP DeviceManufacturerName field */
    inline void
    setDeviceManufacturerName (
      llrp_utf8v_t value)
    {
        m_DeviceManufacturerName = value;
    }


  protected:
    llrp_u8v_t m_DeviceSN;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdDeviceSN;
//@}

    /** @brief Get accessor functions for the LLRP DeviceSN field */
    inline llrp_u8v_t
    getDeviceSN (void)
    {
        return m_DeviceSN;
    }

    /** @brief Set accessor functions for the LLRP DeviceSN field */
    inline void
    setDeviceSN (
      llrp_u8v_t value)
    {
        m_DeviceSN = value;
    }


  protected:
    llrp_u16_t m_DeviceModelType;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdDeviceModelType;
//@}

    /** @brief Get accessor functions for the LLRP DeviceModelType field */
    inline llrp_u16_t
    getDeviceModelType (void)
    {
        return m_DeviceModelType;
    }

    /** @brief Set accessor functions for the LLRP DeviceModelType field */
    inline void
    setDeviceModelType (
      llrp_u16_t value)
    {
        m_DeviceModelType = value;
    }


  protected:
    llrp_u16_t m_DeviceSpecificationType;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdDeviceSpecificationType;
//@}

    /** @brief Get accessor functions for the LLRP DeviceSpecificationType field */
    inline llrp_u16_t
    getDeviceSpecificationType (void)
    {
        return m_DeviceSpecificationType;
    }

    /** @brief Set accessor functions for the LLRP DeviceSpecificationType field */
    inline void
    setDeviceSpecificationType (
      llrp_u16_t value)
    {
        m_DeviceSpecificationType = value;
    }


  protected:
    llrp_u8_t m_MaxNumberOfAntennaSupported;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdMaxNumberOfAntennaSupported;
//@}

    /** @brief Get accessor functions for the LLRP MaxNumberOfAntennaSupported field */
    inline llrp_u8_t
    getMaxNumberOfAntennaSupported (void)
    {
        return m_MaxNumberOfAntennaSupported;
    }

    /** @brief Set accessor functions for the LLRP MaxNumberOfAntennaSupported field */
    inline void
    setMaxNumberOfAntennaSupported (
      llrp_u8_t value)
    {
        m_MaxNumberOfAntennaSupported = value;
    }


  protected:
    llrp_u1_t m_HasUTCClockCapability;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdHasUTCClockCapability;
//@}

    /** @brief Get accessor functions for the LLRP HasUTCClockCapability field */
    inline llrp_u1_t
    getHasUTCClockCapability (void)
    {
        return m_HasUTCClockCapability;
    }

    /** @brief Set accessor functions for the LLRP HasUTCClockCapability field */
    inline void
    setHasUTCClockCapability (
      llrp_u1_t value)
    {
        m_HasUTCClockCapability = value;
    }


  protected:
    llrp_u1_t m_HasLocationCapability;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdHasLocationCapability;
//@}

    /** @brief Get accessor functions for the LLRP HasLocationCapability field */
    inline llrp_u1_t
    getHasLocationCapability (void)
    {
        return m_HasLocationCapability;
    }

    /** @brief Set accessor functions for the LLRP HasLocationCapability field */
    inline void
    setHasLocationCapability (
      llrp_u1_t value)
    {
        m_HasLocationCapability = value;
    }


  protected:
    llrp_u1_t m_IsDeviceBinded;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdIsDeviceBinded;
//@}

    /** @brief Get accessor functions for the LLRP IsDeviceBinded field */
    inline llrp_u1_t
    getIsDeviceBinded (void)
    {
        return m_IsDeviceBinded;
    }

    /** @brief Set accessor functions for the LLRP IsDeviceBinded field */
    inline void
    setIsDeviceBinded (
      llrp_u1_t value)
    {
        m_IsDeviceBinded = value;
    }


  protected:
    CGPIOCapabilities * m_pGPIOCapabilities;

  public:
    /** @brief Get accessor functions for the LLRP GPIOCapabilities sub-parameter */
    inline CGPIOCapabilities *
    getGPIOCapabilities (void)
    {
        return m_pGPIOCapabilities;
    }

    /** @brief Set accessor functions for the LLRP GPIOCapabilities sub-parameter */
    EResultCode
    setGPIOCapabilities (
      CGPIOCapabilities * pValue);


};



/**
 ** @brief  Class Definition CGPIOCapabilities for LLRP parameter GPIOCapabilities
 **
 
    
    
  
 **/

class CGPIOCapabilities : public CParameter
{
  public:
    CGPIOCapabilities (void);
    ~CGPIOCapabilities (void);

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
    llrp_u8_t m_NumGPIs;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdNumGPIs;
//@}

    /** @brief Get accessor functions for the LLRP NumGPIs field */
    inline llrp_u8_t
    getNumGPIs (void)
    {
        return m_NumGPIs;
    }

    /** @brief Set accessor functions for the LLRP NumGPIs field */
    inline void
    setNumGPIs (
      llrp_u8_t  value)
    {
        m_NumGPIs = value;
    }


  protected:
    llrp_u8_t m_NumGPOs;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdNumGPOs;
//@}

    /** @brief Get accessor functions for the LLRP NumGPOs field */
    inline llrp_u8_t
    getNumGPOs (void)
    {
        return m_NumGPOs;
    }

    /** @brief Set accessor functions for the LLRP NumGPOs field */
    inline void
    setNumGPOs (
      llrp_u8_t  value)
    {
        m_NumGPOs = value;
    }


};


/**
 ** @brief  Class Definition CCommunicationCapabilities for LLRP parameter CommunicationCapabilities
 **
 
     
     
     
     
     
     
     
     
     
     
     
  
 **/

class CCommunicationCapabilities : public CParameter
{
  public:
    CCommunicationCapabilities (void);
    ~CCommunicationCapabilities (void);

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
    llrp_u1_t m_SupportEthernet;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdSupportEthernet;
//@}

    /** @brief Get accessor functions for the LLRP SupportEthernet field */
    inline llrp_u1_t
    getSupportEthernet (void)
    {
        return m_SupportEthernet;
    }

    /** @brief Set accessor functions for the LLRP SupportEthernet field */
    inline void
    setSupportEthernet (
      llrp_u1_t  value)
    {
        m_SupportEthernet = value;
    }


  protected:
    llrp_u1_t m_SupportWIFI;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdSupportWIFI;
//@}

    /** @brief Get accessor functions for the LLRP SupportWIFI field */
    inline llrp_u1_t
    getSupportWIFI (void)
    {
        return m_SupportWIFI;
    }

    /** @brief Set accessor functions for the LLRP SupportWIFI field */
    inline void
    setSupportWIFI (
      llrp_u1_t  value)
    {
        m_SupportWIFI = value;
    }


  protected:
    llrp_u1_t m_SupportMobile;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdSupportMobile;
//@}

    /** @brief Get accessor functions for the LLRP SupportMobile field */
    inline llrp_u1_t
    getSupportMobile (void)
    {
        return m_SupportMobile;
    }

    /** @brief Set accessor functions for the LLRP SupportMobile field */
    inline void
    setSupportMobile (
      llrp_u1_t  value)
    {
        m_SupportMobile = value;
    }


  protected:
    llrp_u1_t m_SupportUSB;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdSupportUSB;
//@}

    /** @brief Get accessor functions for the LLRP SupportUSB field */
    inline llrp_u1_t
    getSupportUSB (void)
    {
        return m_SupportUSB;
    }

    /** @brief Set accessor functions for the LLRP SupportUSB field */
    inline void
    setSupportUSB (
      llrp_u1_t  value)
    {
        m_SupportUSB = value;
    }


  protected:
    llrp_u1_t m_SupportHttpLink;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdSupportHttpLink;
//@}

    /** @brief Get accessor functions for the LLRP SupportHttpLink field */
    inline llrp_u1_t
    getSupportHttpLink (void)
    {
        return m_SupportHttpLink;
    }

    /** @brief Set accessor functions for the LLRP SupportHttpLink field */
    inline void
    setSupportHttpLink (
      llrp_u1_t  value)
    {
        m_SupportHttpLink = value;
    }


  protected:
    llrp_u1_t m_SupportIPV6;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdSupportIPV6;
//@}

    /** @brief Get accessor functions for the LLRP SupportIPV6 field */
    inline llrp_u1_t
    getSupportIPV6 (void)
    {
        return m_SupportIPV6;
    }

    /** @brief Set accessor functions for the LLRP SupportIPV6 field */
    inline void
    setSupportIPV6 (
      llrp_u1_t  value)
    {
        m_SupportIPV6 = value;
    }


  protected:
    llrp_u1_t m_SupportSSL;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdSupportSSL;
//@}

    /** @brief Get accessor functions for the LLRP SupportSSL field */
    inline llrp_u1_t
    getSupportSSL (void)
    {
        return m_SupportSSL;
    }

    /** @brief Set accessor functions for the LLRP SupportSSL field */
    inline void
    setSupportSSL (
      llrp_u1_t  value)
    {
        m_SupportSSL = value;
    }


  protected:
    llrp_u8_t m_SupportTcpLinkNum;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdSupportTcpLinkNum;
//@}

    /** @brief Get accessor functions for the LLRP SupportTcpLinkNum field */
    inline llrp_u8_t
    getSupportTcpLinkNum (void)
    {
        return m_SupportTcpLinkNum;
    }

    /** @brief Set accessor functions for the LLRP SupportTcpLinkNum field */
    inline void
    setSupportTcpLinkNum (
      llrp_u8_t  value)
    {
        m_SupportTcpLinkNum = value;
    }


  protected:
    CSupportRS232 * m_pSupportRS232;

  public:
    /** @brief Get accessor functions for the LLRP SupportRS232 sub-parameter */  
    inline CSupportRS232 *
    getSupportRS232 (void)
    {
        return m_pSupportRS232;
    }

    /** @brief Set accessor functions for the LLRP SupportRS232 sub-parameter */  
    EResultCode
    setSupportRS232 (
      CSupportRS232 * pValue);


  protected:
    CSupportRS485 * m_pSupportRS485;

  public:
    /** @brief Get accessor functions for the LLRP SupportRS485 sub-parameter */  
    inline CSupportRS485 *
    getSupportRS485 (void)
    {
        return m_pSupportRS485;
    }

    /** @brief Set accessor functions for the LLRP SupportRS485 sub-parameter */  
    EResultCode
    setSupportRS485 (
      CSupportRS485 * pValue);


};


/**
 ** @brief  Class Definition CSupportRS232 for LLRP parameter SupportRS232
 **
 
     
     
  
 **/

class CSupportRS232 : public CParameter
{
  public:
    CSupportRS232 (void);
    ~CSupportRS232 (void);

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
    llrp_u8_t m_PortNum;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdPortNum;
//@}

    /** @brief Get accessor functions for the LLRP PortNum field */
    inline llrp_u8_t
    getPortNum (void)
    {
        return m_PortNum;
    }

    /** @brief Set accessor functions for the LLRP PortNum field */
    inline void
    setPortNum (
      llrp_u8_t  value)
    {
        m_PortNum = value;
    }


  protected:
    std::list<CSerialAttribute *> m_listSerialAttribute;

  public:
     /** @brief  Returns the first element of the SerialAttribute sub-parameter list*/  
    inline std::list<CSerialAttribute *>::iterator
    beginSerialAttribute (void)
    {
        return m_listSerialAttribute.begin();
    }

     /** @brief  Returns the last element of the SerialAttribute sub-parameter list*/  
    inline std::list<CSerialAttribute *>::iterator
    endSerialAttribute (void)
    {
        return m_listSerialAttribute.end();
    }

     /** @brief  Clears the LLRP SerialAttribute sub-parameter list*/  
    inline void
    clearSerialAttribute (void)
    {
        clearSubParameterList ((tListOfParameters *) &m_listSerialAttribute);
    }

    EResultCode
     /** @brief  Add a SerialAttribute to the LLRP sub-parameter list*/  
    addSerialAttribute (
      CSerialAttribute * pValue);


};


/**
 ** @brief  Class Definition CSerialAttribute for LLRP parameter SerialAttribute
 **
 
      
      
      
      
      
  
 **/

class CSerialAttribute : public CParameter
{
  public:
    CSerialAttribute (void);
    ~CSerialAttribute (void);

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
    llrp_u32_t  m_BaudRate;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdBaudRate;
//@}

    /** @brief Get accessor functions for the LLRP BaudRate field */
    inline llrp_u32_t
    getBaudRate (void)
    {
        return m_BaudRate;
    }

    /** @brief Set accessor functions for the LLRP BaudRate field */
    inline void
    setBaudRate (
      llrp_u32_t  value)
    {
        m_BaudRate = value;
    }


  protected:
    llrp_u8_t m_DataBit;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdDataBit;
//@}

    /** @brief Get accessor functions for the LLRP DataBit field */
    inline llrp_u8_t
    getDataBit (void)
    {
        return m_DataBit;
    }

    /** @brief Set accessor functions for the LLRP DataBit field */
    inline void
    setDataBit (
      llrp_u8_t  value)
    {
        m_DataBit = value;
    }


  protected:
    llrp_u8_t m_StopBit;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdStopBit;
//@}

    /** @brief Get accessor functions for the LLRP StopBit field */
    inline llrp_u8_t
    getStopBit (void)
    {
        return m_StopBit;
    }

    /** @brief Set accessor functions for the LLRP StopBit field */
    inline void
    setStopBit (
      llrp_u8_t  value)
    {
        m_StopBit = value;
    }


  protected:
    llrp_u8_t m_Parity;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdParity;
//@}

    /** @brief Get accessor functions for the LLRP Parity field */
    inline llrp_u8_t
    getParity (void)
    {
        return m_Parity;
    }

    /** @brief Set accessor functions for the LLRP Parity field */
    inline void
    setParity (
      llrp_u8_t  value)
    {
        m_Parity = value;
    }


  protected:
    llrp_u8_t m_FlowControl;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdFlowControl;
//@}

    /** @brief Get accessor functions for the LLRP FlowControl field */
    inline llrp_u8_t
    getFlowControl (void)
    {
        return m_FlowControl;
    }

    /** @brief Set accessor functions for the LLRP FlowControl field */
    inline void
    setFlowControl (
      llrp_u8_t  value)
    {
        m_FlowControl = value;
    }


};


/**
 ** @brief  Class Definition CSupportRS485 for LLRP parameter SupportRS485
 **
 
      
      
  
 **/

class CSupportRS485 : public CParameter
{
  public:
    CSupportRS485 (void);
    ~CSupportRS485 (void);

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
    llrp_u8_t m_PortNum;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdPortNum;
//@}

    /** @brief Get accessor functions for the LLRP PortNum field */
    inline llrp_u8_t
    getPortNum (void)
    {
        return m_PortNum;
    }

    /** @brief Set accessor functions for the LLRP PortNum field */
    inline void
    setPortNum (
      llrp_u8_t  value)
    {
        m_PortNum = value;
    }


  protected:
    std::list<CSerialAttribute *> m_listSerialAttribute;

  public:
     /** @brief  Returns the first element of the SerialAttribute sub-parameter list*/  
    inline std::list<CSerialAttribute *>::iterator
    beginSerialAttribute (void)
    {
        return m_listSerialAttribute.begin();
    }

     /** @brief  Returns the last element of the SerialAttribute sub-parameter list*/  
    inline std::list<CSerialAttribute *>::iterator
    endSerialAttribute (void)
    {
        return m_listSerialAttribute.end();
    }

     /** @brief  Clears the LLRP SerialAttribute sub-parameter list*/  
    inline void
    clearSerialAttribute (void)
    {
        clearSubParameterList ((tListOfParameters *) &m_listSerialAttribute);
    }

    EResultCode
     /** @brief  Add a SerialAttribute to the LLRP sub-parameter list*/  
    addSerialAttribute (
      CSerialAttribute * pValue);


};


/**
 ** @brief  Class Definition CSpecCapabilities for LLRP parameter SpecCapabilities
 **
 
     
     
     
     
     
     
     
     
     
     
  
 **/

class CSpecCapabilities : public CParameter
{
  public:
    CSpecCapabilities (void);
    ~CSpecCapabilities (void);

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
    llrp_u1_t m_SupportsClientRequestOpSpec;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdSupportsClientRequestOpSpec;
//@}

    /** @brief Get accessor functions for the LLRP SupportsClientRequestOpSpec field */
    inline llrp_u1_t
    getSupportsClientRequestOpSpec (void)
    {
        return m_SupportsClientRequestOpSpec;
    }

    /** @brief Set accessor functions for the LLRP SupportsClientRequestOpSpec field */
    inline void
    setSupportsClientRequestOpSpec (
      llrp_u1_t  value)
    {
        m_SupportsClientRequestOpSpec = value;
    }


  protected:
    llrp_u1_t m_SupportsEventAndReportHolding;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdSupportsEventAndReportHolding;
//@}

    /** @brief Get accessor functions for the LLRP SupportsEventAndReportHolding field */
    inline llrp_u1_t
    getSupportsEventAndReportHolding (void)
    {
        return m_SupportsEventAndReportHolding;
    }

    /** @brief Set accessor functions for the LLRP SupportsEventAndReportHolding field */
    inline void
    setSupportsEventAndReportHolding (
      llrp_u1_t  value)
    {
        m_SupportsEventAndReportHolding = value;
    }


  protected:
    llrp_u16_t m_ClientRequestOpSpecTimeout;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdClientRequestOpSpecTimeout;
//@}

    /** @brief Get accessor functions for the LLRP ClientRequestOpSpecTimeout field */
    inline llrp_u16_t
    getClientRequestOpSpecTimeout (void)
    {
        return m_ClientRequestOpSpecTimeout;
    }

    /** @brief Set accessor functions for the LLRP ClientRequestOpSpecTimeout field */
    inline void
    setClientRequestOpSpecTimeout (
      llrp_u16_t  value)
    {
        m_ClientRequestOpSpecTimeout = value;
    }


  protected:
    llrp_u8_t m_MaxPriorityLevelSupported;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdMaxPriorityLevelSupported;
//@}

    /** @brief Get accessor functions for the LLRP MaxPriorityLevelSupported field */
    inline llrp_u8_t
    getMaxPriorityLevelSupported (void)
    {
        return m_MaxPriorityLevelSupported;
    }

    /** @brief Set accessor functions for the LLRP MaxPriorityLevelSupported field */
    inline void
    setMaxPriorityLevelSupported (
      llrp_u8_t  value)
    {
        m_MaxPriorityLevelSupported = value;
    }


  protected:
    llrp_u8_t m_MaxNumSelectSpecs;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdMaxNumSelectSpecs;
//@}

    /** @brief Get accessor functions for the LLRP MaxNumSelectSpecs field */
    inline llrp_u8_t
    getMaxNumSelectSpecs (void)
    {
        return m_MaxNumSelectSpecs;
    }

    /** @brief Set accessor functions for the LLRP MaxNumSelectSpecs field */
    inline void
    setMaxNumSelectSpecs (
      llrp_u8_t  value)
    {
        m_MaxNumSelectSpecs = value;
    }


  protected:
    llrp_u8_t m_MaxNumAntennaSpecsPerSelectSpec;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdMaxNumAntennaSpecsPerSelectSpec;
//@}

    /** @brief Get accessor functions for the LLRP MaxNumAntennaSpecsPerSelectSpec field */
    inline llrp_u8_t
    getMaxNumAntennaSpecsPerSelectSpec (void)
    {
        return m_MaxNumAntennaSpecsPerSelectSpec;
    }

    /** @brief Set accessor functions for the LLRP MaxNumAntennaSpecsPerSelectSpec field */
    inline void
    setMaxNumAntennaSpecsPerSelectSpec (
      llrp_u8_t  value)
    {
        m_MaxNumAntennaSpecsPerSelectSpec = value;
    }


  protected:
    llrp_u8_t m_MaxNumRfSpecsPerAntennaSpec;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdMaxNumRfSpecsPerAntennaSpec;
//@}

    /** @brief Get accessor functions for the LLRP MaxNumRfSpecsPerAntennaSpec field */
    inline llrp_u8_t
    getMaxNumRfSpecsPerAntennaSpec (void)
    {
        return m_MaxNumRfSpecsPerAntennaSpec;
    }

    /** @brief Set accessor functions for the LLRP MaxNumRfSpecsPerAntennaSpec field */
    inline void
    setMaxNumRfSpecsPerAntennaSpec (
      llrp_u8_t  value)
    {
        m_MaxNumRfSpecsPerAntennaSpec = value;
    }


  protected:
    llrp_u8_t m_MaxNumAccessSpecs;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdMaxNumAccessSpecs;
//@}

    /** @brief Get accessor functions for the LLRP MaxNumAccessSpecs field */
    inline llrp_u8_t
    getMaxNumAccessSpecs (void)
    {
        return m_MaxNumAccessSpecs;
    }

    /** @brief Set accessor functions for the LLRP MaxNumAccessSpecs field */
    inline void
    setMaxNumAccessSpecs (
      llrp_u8_t  value)
    {
        m_MaxNumAccessSpecs = value;
    }


  protected:
    llrp_u8_t m_MaxNumOperationSpecsPerAccessSpec;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdMaxNumOperationSpecsPerAccessSpec;
//@}

    /** @brief Get accessor functions for the LLRP MaxNumOperationSpecsPerAccessSpec field */
    inline llrp_u8_t
    getMaxNumOperationSpecsPerAccessSpec (void)
    {
        return m_MaxNumOperationSpecsPerAccessSpec;
    }

    /** @brief Set accessor functions for the LLRP MaxNumOperationSpecsPerAccessSpec field */
    inline void
    setMaxNumOperationSpecsPerAccessSpec (
      llrp_u8_t  value)
    {
        m_MaxNumOperationSpecsPerAccessSpec = value;
    }


};


/**
 ** @brief  Class Definition CRfCapabilities for LLRP parameter RfCapabilities
 **
 
     
     
     
     
     
     
     
     
     
  
 **/

class CRfCapabilities : public CParameter
{
  public:
    CRfCapabilities (void);
    ~CRfCapabilities (void);

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
    llrp_u16_t m_CountryCode;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdCountryCode;
//@}

    /** @brief Get accessor functions for the LLRP CountryCode field */
    inline llrp_u16_t
    getCountryCode (void)
    {
        return m_CountryCode;
    }

    /** @brief Set accessor functions for the LLRP CountryCode field */
    inline void
    setCountryCode (
      llrp_u16_t  value)
    {
        m_CountryCode = value;
    }


  protected:
    llrp_u16_t m_CommunicationsStandard;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdCommunicationsStandard;
//@}

    /** @brief Get accessor functions for the LLRP CommunicationsStandard field */
    inline llrp_u16_t
    getCommunicationsStandard (void)
    {
        return m_CommunicationsStandard;
    }

    /** @brief Set accessor functions for the LLRP CommunicationsStandard field */
    inline void
    setCommunicationsStandard (
      llrp_u16_t  value)
    {
        m_CommunicationsStandard = value;
    }


  protected:
    std::list<CTransmitPowerLevelTable *> m_listTransmitPowerLevelTable;

  public:
     /** @brief  Returns the first element of the TransmitPowerLevelTable sub-parameter list*/  
    inline std::list<CTransmitPowerLevelTable *>::iterator
    beginTransmitPowerLevelTable (void)
    {
        return m_listTransmitPowerLevelTable.begin();
    }

     /** @brief  Returns the last element of the TransmitPowerLevelTable sub-parameter list*/  
    inline std::list<CTransmitPowerLevelTable *>::iterator
    endTransmitPowerLevelTable (void)
    {
        return m_listTransmitPowerLevelTable.end();
    }

     /** @brief  Clears the LLRP TransmitPowerLevelTable sub-parameter list*/  
    inline void
    clearTransmitPowerLevelTable (void)
    {
        clearSubParameterList ((tListOfParameters *) &m_listTransmitPowerLevelTable);
    }

    EResultCode
     /** @brief  Add a TransmitPowerLevelTable to the LLRP sub-parameter list*/  
    addTransmitPowerLevelTable (
      CTransmitPowerLevelTable * pValue);


  protected:
    CFrequencyInformation * m_pFrequencyInformation;

  public:
    /** @brief Get accessor functions for the LLRP FrequencyInformation sub-parameter */  
    inline CFrequencyInformation *
    getFrequencyInformation (void)
    {
        return m_pFrequencyInformation;
    }

    /** @brief Set accessor functions for the LLRP FrequencyInformation sub-parameter */  
    EResultCode
    setFrequencyInformation (
      CFrequencyInformation * pValue);


  protected:
    std::list<CForDataRateTable *> m_listForDataRateTable;

  public:
     /** @brief  Returns the first element of the ForDataRateTable sub-parameter list*/  
    inline std::list<CForDataRateTable *>::iterator
    beginForDataRateTable (void)
    {
        return m_listForDataRateTable.begin();
    }

     /** @brief  Returns the last element of the ForDataRateTable sub-parameter list*/  
    inline std::list<CForDataRateTable *>::iterator
    endForDataRateTable (void)
    {
        return m_listForDataRateTable.end();
    }

     /** @brief  Clears the LLRP ForDataRateTable sub-parameter list*/  
    inline void
    clearForDataRateTable (void)
    {
        clearSubParameterList ((tListOfParameters *) &m_listForDataRateTable);
    }

    EResultCode
     /** @brief  Add a ForDataRateTable to the LLRP sub-parameter list*/  
    addForDataRateTable (
      CForDataRateTable * pValue);


  protected:
    std::list<CRevDataRateTable *> m_listRevDataRateTable;

  public:
     /** @brief  Returns the first element of the RevDataRateTable sub-parameter list*/  
    inline std::list<CRevDataRateTable *>::iterator
    beginRevDataRateTable (void)
    {
        return m_listRevDataRateTable.begin();
    }

     /** @brief  Returns the last element of the RevDataRateTable sub-parameter list*/  
    inline std::list<CRevDataRateTable *>::iterator
    endRevDataRateTable (void)
    {
        return m_listRevDataRateTable.end();
    }

     /** @brief  Clears the LLRP RevDataRateTable sub-parameter list*/  
    inline void
    clearRevDataRateTable (void)
    {
        clearSubParameterList ((tListOfParameters *) &m_listRevDataRateTable);
    }

    EResultCode
     /** @brief  Add a RevDataRateTable to the LLRP sub-parameter list*/  
    addRevDataRateTable (
      CRevDataRateTable * pValue);


  protected:
    std::list<CForModulationTable *> m_listForModulationTable;

  public:
     /** @brief  Returns the first element of the ForModulationTable sub-parameter list*/  
    inline std::list<CForModulationTable *>::iterator
    beginForModulationTable (void)
    {
        return m_listForModulationTable.begin();
    }

     /** @brief  Returns the last element of the ForModulationTable sub-parameter list*/  
    inline std::list<CForModulationTable *>::iterator
    endForModulationTable (void)
    {
        return m_listForModulationTable.end();
    }

     /** @brief  Clears the LLRP ForModulationTable sub-parameter list*/  
    inline void
    clearForModulationTable (void)
    {
        clearSubParameterList ((tListOfParameters *) &m_listForModulationTable);
    }

    EResultCode
     /** @brief  Add a ForModulationTable to the LLRP sub-parameter list*/  
    addForModulationTable (
      CForModulationTable * pValue);


  protected:
    std::list<CRevDataEncodingTable *> m_listRevDataEncodingTable;

  public:
     /** @brief  Returns the first element of the RevDataEncodingTable sub-parameter list*/  
    inline std::list<CRevDataEncodingTable *>::iterator
    beginRevDataEncodingTable (void)
    {
        return m_listRevDataEncodingTable.begin();
    }

     /** @brief  Returns the last element of the RevDataEncodingTable sub-parameter list*/  
    inline std::list<CRevDataEncodingTable *>::iterator
    endRevDataEncodingTable (void)
    {
        return m_listRevDataEncodingTable.end();
    }

     /** @brief  Clears the LLRP RevDataEncodingTable sub-parameter list*/  
    inline void
    clearRevDataEncodingTable (void)
    {
        clearSubParameterList ((tListOfParameters *) &m_listRevDataEncodingTable);
    }

    EResultCode
     /** @brief  Add a RevDataEncodingTable to the LLRP sub-parameter list*/  
    addRevDataEncodingTable (
      CRevDataEncodingTable * pValue);


  protected:
    std::list<CModuleDepthTable *> m_listModuleDepthTable;

  public:
     /** @brief  Returns the first element of the ModuleDepthTable sub-parameter list*/  
    inline std::list<CModuleDepthTable *>::iterator
    beginModuleDepthTable (void)
    {
        return m_listModuleDepthTable.begin();
    }

     /** @brief  Returns the last element of the ModuleDepthTable sub-parameter list*/  
    inline std::list<CModuleDepthTable *>::iterator
    endModuleDepthTable (void)
    {
        return m_listModuleDepthTable.end();
    }

     /** @brief  Clears the LLRP ModuleDepthTable sub-parameter list*/  
    inline void
    clearModuleDepthTable (void)
    {
        clearSubParameterList ((tListOfParameters *) &m_listModuleDepthTable);
    }

    EResultCode
     /** @brief  Add a ModuleDepthTable to the LLRP sub-parameter list*/  
    addModuleDepthTable (
      CModuleDepthTable * pValue);


};


/**
 ** @brief  Class Definition CTransmitPowerLevelTable for LLRP parameter TransmitPowerLevelTable
 **
 
     
     
  
 **/

class CTransmitPowerLevelTable : public CParameter
{
  public:
    CTransmitPowerLevelTable (void);
    ~CTransmitPowerLevelTable (void);

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


  protected:
    llrp_s16_t  m_TransmitPowerValue;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdTransmitPowerValue;
//@}

    /** @brief Get accessor functions for the LLRP TransmitPowerValue field */
    inline llrp_s16_t
    getTransmitPowerValue (void)
    {
        return m_TransmitPowerValue;
    }

    /** @brief Set accessor functions for the LLRP TransmitPowerValue field */
    inline void
    setTransmitPowerValue (
      llrp_s16_t  value)
    {
        m_TransmitPowerValue = value;
    }


};


/**
 ** @brief  Class Definition CFrequencyInformation for LLRP parameter FrequencyInformation
 **
 
     
     
     
  
 **/

class CFrequencyInformation : public CParameter
{
  public:
    CFrequencyInformation (void);
    ~CFrequencyInformation (void);

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
    llrp_u1_t m_Hopping;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdHopping;
//@}

    /** @brief Get accessor functions for the LLRP Hopping field */
    inline llrp_u1_t
    getHopping (void)
    {
        return m_Hopping;
    }

    /** @brief Set accessor functions for the LLRP Hopping field */
    inline void
    setHopping (
      llrp_u1_t  value)
    {
        m_Hopping = value;
    }


  protected:
    std::list<CFrequencyTable *> m_listFrequencyTable;

  public:
     /** @brief  Returns the first element of the FrequencyTable sub-parameter list*/  
    inline std::list<CFrequencyTable *>::iterator
    beginFrequencyTable (void)
    {
        return m_listFrequencyTable.begin();
    }

     /** @brief  Returns the last element of the FrequencyTable sub-parameter list*/  
    inline std::list<CFrequencyTable *>::iterator
    endFrequencyTable (void)
    {
        return m_listFrequencyTable.end();
    }

     /** @brief  Clears the LLRP FrequencyTable sub-parameter list*/  
    inline void
    clearFrequencyTable (void)
    {
        clearSubParameterList ((tListOfParameters *) &m_listFrequencyTable);
    }

    EResultCode
     /** @brief  Add a FrequencyTable to the LLRP sub-parameter list*/  
    addFrequencyTable (
      CFrequencyTable * pValue);


};


/**
 ** @brief  Class Definition CFrequencyTable for LLRP parameter FrequencyTable
 **
 
     
     
  
 **/

class CFrequencyTable : public CParameter
{
  public:
    CFrequencyTable (void);
    ~CFrequencyTable (void);

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


  protected:
    llrp_u32_t m_Frequency;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdFrequency;
//@}

    /** @brief Get accessor functions for the LLRP Frequency field */
    inline llrp_u32_t
    getFrequency (void)
    {
        return m_Frequency;
    }

    /** @brief Set accessor functions for the LLRP Frequency field */
    inline void
    setFrequency (
      llrp_u32_t  value)
    {
        m_Frequency = value;
    }


};


/**
 ** @brief  Class Definition CForDataRateTable for LLRP parameter ForDataRateTable
 **
 
    
    
  
 **/

class CForDataRateTable : public CParameter
{
  public:
    CForDataRateTable (void);
    ~CForDataRateTable (void);

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


  protected:
    llrp_u32_t m_ForDataRate;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdForDataRate;
//@}

    /** @brief Get accessor functions for the LLRP ForDataRate field */
    inline llrp_u32_t
    getForDataRate (void)
    {
        return m_ForDataRate;
    }

    /** @brief Set accessor functions for the LLRP ForDataRate field */
    inline void
    setForDataRate (
      llrp_u32_t  value)
    {
        m_ForDataRate = value;
    }


};


/**
 ** @brief  Class Definition CRevDataRateTable for LLRP parameter RevDataRateTable
 **
 
     
     
  
 **/

class CRevDataRateTable : public CParameter
{
  public:
    CRevDataRateTable (void);
    ~CRevDataRateTable (void);

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


  protected:
    llrp_u32_t m_RevDataRate;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdRevDataRate;
//@}

    /** @brief Get accessor functions for the LLRP RevDataRate field */
    inline llrp_u32_t
    getRevDataRate (void)
    {
        return m_RevDataRate;
    }

    /** @brief Set accessor functions for the LLRP RevDataRate field */
    inline void
    setRevDataRate (
      llrp_u32_t  value)
    {
        m_RevDataRate = value;
    }


};


/**
 ** @brief  Class Definition CForModulationTable for LLRP parameter ForModulationTable
 **
 
     
     
  
 **/

class CForModulationTable : public CParameter
{
  public:
    CForModulationTable (void);
    ~CForModulationTable (void);

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


  protected:
    llrp_u8_t m_ModulationType;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdModulationType;
//@}

    /** @brief Get accessor functions for the LLRP ModulationType field */
    inline llrp_u8_t
    getModulationType (void)
    {
        return m_ModulationType;
    }

    /** @brief Set accessor functions for the LLRP ModulationType field */
    inline void
    setModulationType (
      llrp_u8_t  value)
    {
        m_ModulationType = value;
    }


};


/**
 ** @brief  Class Definition CRevDataEncodingTable for LLRP parameter RevDataEncodingTable
 **
 
     
     
  
 **/

class CRevDataEncodingTable : public CParameter
{
  public:
    CRevDataEncodingTable (void);
    ~CRevDataEncodingTable (void);

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


  protected:
    llrp_u8_t m_DataEncodingType;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdDataEncodingType;
//@}

    /** @brief Get accessor functions for the LLRP DataEncodingType field */
    inline llrp_u8_t
    getDataEncodingType (void)
    {
        return m_DataEncodingType;
    }

    /** @brief Set accessor functions for the LLRP DataEncodingType field */
    inline void
    setDataEncodingType (
      llrp_u8_t  value)
    {
        m_DataEncodingType = value;
    }


};


/**
 ** @brief  Class Definition CModuleDepthTable for LLRP parameter ModuleDepthTable
 **
 
     
     
  
 **/

class CModuleDepthTable : public CParameter
{
  public:
    CModuleDepthTable (void);
    ~CModuleDepthTable (void);

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


  protected:
    llrp_u16_t m_ModuleDepthValue;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdModuleDepthValue;
//@}

    /** @brief Get accessor functions for the LLRP ModuleDepthValue field */
    inline llrp_u16_t
    getModuleDepthValue (void)
    {
        return m_ModuleDepthValue;
    }

    /** @brief Set accessor functions for the LLRP ModuleDepthValue field */
    inline void
    setModuleDepthValue (
      llrp_u16_t  value)
    {
        m_ModuleDepthValue = value;
    }


};


/**
 ** @brief  Class Definition CAirProtocolCapabilities for LLRP parameter AirProtocolCapabilities
 **
 
     
     
  
 **/

class CAirProtocolCapabilities : public CParameter
{
  public:
    CAirProtocolCapabilities (void);
    ~CAirProtocolCapabilities (void);

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
    std::list<CPerAntennaAirProtocol *> m_listPerAntennaAirProtocol;

  public:
     /** @brief  Returns the first element of the PerAntennaAirProtocol sub-parameter list*/  
    inline std::list<CPerAntennaAirProtocol *>::iterator
    beginPerAntennaAirProtocol (void)
    {
        return m_listPerAntennaAirProtocol.begin();
    }

     /** @brief  Returns the last element of the PerAntennaAirProtocol sub-parameter list*/  
    inline std::list<CPerAntennaAirProtocol *>::iterator
    endPerAntennaAirProtocol (void)
    {
        return m_listPerAntennaAirProtocol.end();
    }

     /** @brief  Clears the LLRP PerAntennaAirProtocol sub-parameter list*/  
    inline void
    clearPerAntennaAirProtocol (void)
    {
        clearSubParameterList ((tListOfParameters *) &m_listPerAntennaAirProtocol);
    }

    EResultCode
     /** @brief  Add a PerAntennaAirProtocol to the LLRP sub-parameter list*/  
    addPerAntennaAirProtocol (
      CPerAntennaAirProtocol * pValue);


  protected:
    std::list<CHbProtocolCapabilities *> m_listHbProtocolCapabilities;

  public:
     /** @brief  Returns the first element of the HbProtocolCapabilities sub-parameter list*/  
    inline std::list<CHbProtocolCapabilities *>::iterator
    beginHbProtocolCapabilities (void)
    {
        return m_listHbProtocolCapabilities.begin();
    }

     /** @brief  Returns the last element of the HbProtocolCapabilities sub-parameter list*/  
    inline std::list<CHbProtocolCapabilities *>::iterator
    endHbProtocolCapabilities (void)
    {
        return m_listHbProtocolCapabilities.end();
    }

     /** @brief  Clears the LLRP HbProtocolCapabilities sub-parameter list*/  
    inline void
    clearHbProtocolCapabilities (void)
    {
        clearSubParameterList ((tListOfParameters *) &m_listHbProtocolCapabilities);
    }

    EResultCode
     /** @brief  Add a HbProtocolCapabilities to the LLRP sub-parameter list*/  
    addHbProtocolCapabilities (
      CHbProtocolCapabilities * pValue);


};


/**
 ** @brief  Class Definition CPerAntennaAirProtocol for LLRP parameter PerAntennaAirProtocol
 **
 
     
     
  
 **/

class CPerAntennaAirProtocol : public CParameter
{
  public:
    CPerAntennaAirProtocol (void);
    ~CPerAntennaAirProtocol (void);

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
    llrp_u8v_t m_ProtocolIDs;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdProtocolIDs;
//@}

    /** @brief Get accessor functions for the LLRP ProtocolIDs field */
    inline llrp_u8v_t
    getProtocolIDs (void)
    {
        return m_ProtocolIDs;
    }

    /** @brief Set accessor functions for the LLRP ProtocolIDs field */
    inline void
    setProtocolIDs (
      llrp_u8v_t  value)
    {
        m_ProtocolIDs = value;
    }


};


/**
 ** @brief  Class Definition CHbProtocolCapabilities for LLRP parameter HbProtocolCapabilities
 **
 
     
     
     
     
     
  
 **/

class CHbProtocolCapabilities : public CParameter
{
  public:
    CHbProtocolCapabilities (void);
    ~CHbProtocolCapabilities (void);

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
    llrp_u1_t m_SupportQuery;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdSupportQuery;
//@}

    /** @brief Get accessor functions for the LLRP SupportQuery field */
    inline llrp_u1_t
    getSupportQuery (void)
    {
        return m_SupportQuery;
    }

    /** @brief Set accessor functions for the LLRP SupportQuery field */
    inline void
    setSupportQuery (
      llrp_u1_t  value)
    {
        m_SupportQuery = value;
    }


  protected:
    llrp_u1_t m_SupportReadData;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdSupportReadData;
//@}

    /** @brief Get accessor functions for the LLRP SupportReadData field */
    inline llrp_u1_t
    getSupportReadData (void)
    {
        return m_SupportReadData;
    }

    /** @brief Set accessor functions for the LLRP SupportReadData field */
    inline void
    setSupportReadData (
      llrp_u1_t  value)
    {
        m_SupportReadData = value;
    }


  protected:
    llrp_u1_t m_SupportWriteData;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdSupportWriteData;
//@}

    /** @brief Get accessor functions for the LLRP SupportWriteData field */
    inline llrp_u1_t
    getSupportWriteData (void)
    {
        return m_SupportWriteData;
    }

    /** @brief Set accessor functions for the LLRP SupportWriteData field */
    inline void
    setSupportWriteData (
      llrp_u1_t  value)
    {
        m_SupportWriteData = value;
    }


  protected:
    llrp_u1_t m_SupportWriteKey;

/** @name Internal Framework Functions */
//@{
  public:
    static const CFieldDescriptor
    s_fdSupportWriteKey;
//@}

    /** @brief Get accessor functions for the LLRP SupportWriteKey field */
    inline llrp_u1_t
    getSupportWriteKey (void)
    {
        return m_SupportWriteKey;
    }

    /** @brief Set accessor functions for the LLRP SupportWriteKey field */
    inline void
    setSupportWriteKey (
      llrp_u1_t  value)
    {
        m_SupportWriteKey = value;
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
