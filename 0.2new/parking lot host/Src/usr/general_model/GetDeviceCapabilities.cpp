#include "GetDeviceCapabilities.h"
#include <stdio.h>
#include <unistd.h>

#include "main_application.h"


GetDeviceCapabilitiesFuction::GetDeviceCapabilitiesFuction()
{

}

GetDeviceCapabilitiesFuction::~GetDeviceCapabilitiesFuction()
{

}

CMessage *GetDeviceCapabilitiesFuction::getDeviceCapabilitiesRequestedDataMessage(llrp_u8_t datatype)
{
    int messageid = 0;
    CMessage *pGetDeviceCapabilitiesAck = NULL;
    switch(datatype)
    {
    case GetDeviceCapabilitiesRequestedData_All:
    {
        pGetDeviceCapabilitiesAck = HbFrame_Operation::genMessage(GetDeviceCapabilitiesAck, messageid);
        CStatus *pStatus;
        pStatus = (CStatus *)HbFrame_Operation::genParam(Status,0,NULL);
        pStatus->setStatusCode(StatusCode_M_Success);
        //1
        CGenaralCapabilities *pGenaralCapabilities;
        pGenaralCapabilities = (CGenaralCapabilities *)HbFrame_Operation::genParam(GenaralCapabilities,0,NULL);
        pGenaralCapabilities->setDeviceManufacturerName(g_pMainApplication->deviceManufacturerName);
        pGenaralCapabilities->setDeviceSN(g_pMainApplication->deviceSN);
        pGenaralCapabilities->setDeviceModelType(DEVICE_MODEL_TYPE);
        pGenaralCapabilities->setDeviceSpecificationType(DEVICE_SPECIFICATION_TYPE);
        pGenaralCapabilities->setMaxNumberOfAntennaSupported(MAX_NUMBER_OF_ANTENNA_SUPPORTED);
        pGenaralCapabilities->setHasUTCClockCapability(HAS_UTC_CLOCK_CAPABILITY);
        pGenaralCapabilities->setHasLocationCapability(HAS_LOCATION_CAPABILITY);
        pGenaralCapabilities->setIsDeviceBinded(IS_DEVICE_BINDED);

        CGPIOCapabilities *pGPIOCapabilities;
        pGPIOCapabilities = (CGPIOCapabilities *)HbFrame_Operation::genParam(GPIOCapabilities,0,NULL);
        pGPIOCapabilities->setNumGPIs(NUM_GPIS);
        pGPIOCapabilities->setNumGPOs(NUM_GPOS);

        HbFrame_Operation::addParamToParameter((CParameter *)pGPIOCapabilities,(CParameter *)pGenaralCapabilities);
        HbFrame_Operation::addParamToMessage((CParameter *)pGenaralCapabilities,pGetDeviceCapabilitiesAck);

        //2
        CAirProtocolCapabilities *pAirProtocolCapabilities;
        pAirProtocolCapabilities = (CAirProtocolCapabilities*)HbFrame_Operation::genParam(AirProtocolCapabilities,0,NULL);

        CPerAntennaAirProtocol * pPerAntennaAirProtocol;
        pPerAntennaAirProtocol = (CPerAntennaAirProtocol*)HbFrame_Operation::genParam(PerAntennaAirProtocol,0,NULL);
        pPerAntennaAirProtocol->setAntennaID(ANTENNA_ID);


        llrp_u8v_t  m_Protocolids ;
        m_Protocolids = llrp_u8v_t(5);
        for(int i=0;i<m_Protocolids.m_nValue;i++)
        {
            m_Protocolids.m_pValue[i] = i;
        }

        pPerAntennaAirProtocol->setProtocolIDs(m_Protocolids);

        CHbProtocolCapabilities *pHbProtocolCapabilities;
        pHbProtocolCapabilities = (CHbProtocolCapabilities*)HbFrame_Operation::genParam(HbProtocolCapabilities,0,NULL);
        pHbProtocolCapabilities->setSupportQuery(SUPPORT_QUERY);
        pHbProtocolCapabilities->setSupportReadData(SUPPORT_READ_DATA);
        pHbProtocolCapabilities->setSupportWriteData(SUPPORT_WRITE_DATA);
        pHbProtocolCapabilities->setSupportWriteKey(SUPPORT_WRITE_KEY);

        HbFrame_Operation::addParamToParameter((CParameter*)pPerAntennaAirProtocol,(CParameter*)pAirProtocolCapabilities);

        HbFrame_Operation::addParamToParameter((CParameter*)pHbProtocolCapabilities,(CParameter*)pAirProtocolCapabilities);

        HbFrame_Operation::addParamToMessage((CParameter *)pAirProtocolCapabilities,pGetDeviceCapabilitiesAck);

        //3
        CCommunicationCapabilities *pCommunicationCapabilities;
        pCommunicationCapabilities =  (CCommunicationCapabilities *)HbFrame_Operation::genParam(CommunicationCapabilities,0,NULL);
        pCommunicationCapabilities->setSupportEthernet(SUPPORT_ETHERNET);
        pCommunicationCapabilities->setSupportHttpLink(SUPPORT_HTTP_LINK);
        pCommunicationCapabilities->setSupportIPV6(SUPPORT_IPV6);
        pCommunicationCapabilities->setSupportMobile(SUPPORT_MOBILE);
        pCommunicationCapabilities->setSupportSSL(SUPPORT_SSL);
        pCommunicationCapabilities->setSupportTcpLinkNum(SUPPORT_TCP_LINK_NUM);
        pCommunicationCapabilities->setSupportUSB(SUPPORT_USB);
        pCommunicationCapabilities->setSupportWIFI(SUPPORT_WIFI);

        CSupportRS232* pSupportRS232;
        pSupportRS232 =  (CSupportRS232*) HbFrame_Operation::genParam(SupportRS232,0,NULL);
        pSupportRS232->setPortNum(PORT_NUM);

        CSerialAttribute *pSerialAttribute;
        pSerialAttribute=(CSerialAttribute *)HbFrame_Operation::genParam(SerialAttribute,0,NULL);
        pSerialAttribute->setBaudRate(BAUD_RATE);
        HbFrame_Operation::addParamToParameter((CParameter*)pSerialAttribute,(CParameter*)pSupportRS232);


        CSupportRS485* pSupportRS485;
        pSupportRS485 = (CSupportRS485*)HbFrame_Operation::genParam(SupportRS485,0,NULL);
        pSupportRS485->setPortNum(PORT_NUM485);

        for(int i=0;i<4;i++){
            CSerialAttribute* pSerialAttribute485;
            pSerialAttribute485 = (CSerialAttribute*)HbFrame_Operation::genParam(SerialAttribute,0,NULL);
            pSerialAttribute485->setDataBit(8);
            pSerialAttribute485->setStopBit(1);
            pSerialAttribute485->setParity(0);
            pSerialAttribute485->setFlowControl(0);
            llrp_u32_t baud = 19200;
            switch(i){
            case 0:
                baud = 9600;
                break;
            case 1:
                baud = 9600;
                break;
            case 2:
                baud = 38400;
                break;
            case 3:
                baud = 115200;
                break;
            default:
                baud = 19200;
                break;
                pSerialAttribute485->setBaudRate(baud);
            }
            HbFrame_Operation::addParamToParameter((CParameter*)pSerialAttribute485,(CParameter*)pSupportRS485);
        }


        HbFrame_Operation::addParamToParameter((CParameter*)pSupportRS485,(CParameter*)pCommunicationCapabilities);
        HbFrame_Operation::addParamToParameter((CParameter*)pSupportRS232,(CParameter*)pCommunicationCapabilities);
        HbFrame_Operation::addParamToMessage((CParameter*)pCommunicationCapabilities,pGetDeviceCapabilitiesAck);


        //4
        CRfCapabilities* pRfCapabilities;
        pRfCapabilities = (CRfCapabilities*)HbFrame_Operation::genParam(RfCapabilities,0,NULL);
        pRfCapabilities->setCountryCode(COUNTRY_CODE);
        pRfCapabilities->setCommunicationsStandard(COMMUNICATIONS_STANDARD);

        CTransmitPowerLevelTable*  pTransmitPowerLevelTable;
        pTransmitPowerLevelTable =(CTransmitPowerLevelTable*) HbFrame_Operation::genParam(TransmitPowerLevelTable,0,NULL);
        pTransmitPowerLevelTable->setTransmitPowerValue(TRANSMIT_POWER_VALUE);
        pTransmitPowerLevelTable->setIndex(INDEX_FRE_INFO);

        CFrequencyInformation *pFrequencyInformation;
        pFrequencyInformation = (CFrequencyInformation*)HbFrame_Operation::genParam(FrequencyInformation,0,NULL);
        pFrequencyInformation->setHopping(HOP_PING);

        CFrequencyTable * pFrequencyTable;
        pFrequencyTable =  (CFrequencyTable*)HbFrame_Operation::genParam(FrequencyTable,0,NULL);
        pFrequencyTable->setIndex(INDEX_FRE_TABLE);
        pFrequencyTable->setFrequency(FREQUENCY);



        CForDataRateTable * pForDataRateTable;
        pForDataRateTable =(CForDataRateTable*) HbFrame_Operation::genParam(ForDataRateTable,0,NULL);
        pForDataRateTable->setIndex(INDEX_FOR_DATA_RATE_TABLE);
        pForDataRateTable->setForDataRate(FORDATA_RATE);

        CRevDataRateTable  *pRevDataRateTable;
        pRevDataRateTable=(CRevDataRateTable*)HbFrame_Operation::genParam(RevDataRateTable,0,NULL);
        pRevDataRateTable->setIndex(REV_DATA_TABLE_INDEX);
        pRevDataRateTable->setRevDataRate(REV_DATA_RATE);


        CForModulationTable *pForModulationTable;
        pForModulationTable =(CForModulationTable*) HbFrame_Operation::genParam(ForModulationTable,0,NULL);
        pForModulationTable->setIndex(INDEX_MODULATION_TABLE);
        pForModulationTable->setModulationType(MODULATION_TYPE);

        CRevDataEncodingTable* pRevDataEncodingTable;
        pRevDataEncodingTable = (CRevDataEncodingTable*)HbFrame_Operation::genParam(RevDataEncodingTable,0,NULL);
        pRevDataEncodingTable->setIndex(REV_DATA_ENCODING_TABLE_INDEX);
        pRevDataEncodingTable->setDataEncodingType(DATA_ENCODING_TYPE);

        CModuleDepthTable *pModuleDepthTable;
        pModuleDepthTable=(CModuleDepthTable*)HbFrame_Operation::genParam(ModuleDepthTable,0,NULL);
        pModuleDepthTable->setIndex(MODULE_DEDPTH_TABLE_INDEX);
        pModuleDepthTable->setModuleDepthValue(MODULE_DEPTH_VALUE);

        HbFrame_Operation::addParamToParameter((CParameter*)pTransmitPowerLevelTable,(CParameter*)pRfCapabilities);
        HbFrame_Operation::addParamToParameter((CParameter*)pFrequencyTable,(CParameter*)pFrequencyInformation);
        HbFrame_Operation::addParamToParameter((CParameter*)pFrequencyInformation,(CParameter*)pRfCapabilities);
        HbFrame_Operation::addParamToParameter((CParameter*)pForDataRateTable,(CParameter*)pRfCapabilities);
        HbFrame_Operation::addParamToParameter((CParameter*)pRevDataRateTable,(CParameter*)pRfCapabilities);
        HbFrame_Operation::addParamToParameter((CParameter*)pForModulationTable,(CParameter*)pRfCapabilities);
        HbFrame_Operation::addParamToParameter((CParameter*)pRevDataEncodingTable,(CParameter*)pRfCapabilities);
        HbFrame_Operation::addParamToParameter((CParameter*)pModuleDepthTable,(CParameter*)pRfCapabilities);
        HbFrame_Operation::addParamToMessage((CParameter*)pRfCapabilities,pGetDeviceCapabilitiesAck);
        //printf("dddddd\n");
        //5
        CSpecCapabilities *pSpecCapabilities;
        pSpecCapabilities = (CSpecCapabilities*) HbFrame_Operation::genParam(SpecCapabilities,0,NULL);
        pSpecCapabilities->setClientRequestOpSpecTimeout(CLIENT_REQUEST_OPSPEC_TIME_OUT);
        pSpecCapabilities->setMaxNumAccessSpecs(MAX_NUM_ACCESSSPECS);
        pSpecCapabilities->setMaxNumAntennaSpecsPerSelectSpec(MAX_NUM_ANTENNA_SPECS_PER_SELECT_SPEC);
        pSpecCapabilities->setMaxNumOperationSpecsPerAccessSpec(MAX_NUM_OPERATION_PECS_PER_ACCESSSPEC);
        pSpecCapabilities->setMaxNumRfSpecsPerAntennaSpec(MAX_NUM_RFSPECS_PER_ANTENNA_SPEC);
        pSpecCapabilities->setMaxNumSelectSpecs(MAX_NUM_SELECT_SPECS);
        pSpecCapabilities->setMaxPriorityLevelSupported(MAX_PRIORITY_LEVEL_SUPPORTED);
        pSpecCapabilities->setSupportsClientRequestOpSpec(SUPPORTS_CLIENT_REQUESTOP_SPEC);
        pSpecCapabilities->setSupportsEventAndReportHolding(SUPPORTS_EVENT_AND_REPORT_HOLDING);

        HbFrame_Operation::addParamToMessage((CParameter*)pSpecCapabilities,pGetDeviceCapabilitiesAck);

        HbFrame_Operation::addParamToMessage((CParameter *)pStatus,pGetDeviceCapabilitiesAck);
        return pGetDeviceCapabilitiesAck;
    }
        break;

    case GetDeviceCapabilitiesRequestedData_GenaralCapabilities:
    {
        pGetDeviceCapabilitiesAck = HbFrame_Operation::genMessage(GetDeviceCapabilitiesAck, messageid);
        CStatus *pStatus;
        pStatus = (CStatus *)HbFrame_Operation::genParam(Status,0,NULL);
        pStatus->setStatusCode(StatusCode_M_Success);

        CGenaralCapabilities *pGenaralCapabilities;
        pGenaralCapabilities = (CGenaralCapabilities *)HbFrame_Operation::genParam(GenaralCapabilities,0,NULL);
        pGenaralCapabilities->setDeviceManufacturerName(g_pMainApplication->deviceManufacturerName);
        pGenaralCapabilities->setDeviceSN(g_pMainApplication->deviceSN);
        pGenaralCapabilities->setDeviceModelType(DEVICE_MODEL_TYPE);
        pGenaralCapabilities->setDeviceSpecificationType(DEVICE_SPECIFICATION_TYPE);
        pGenaralCapabilities->setMaxNumberOfAntennaSupported(MAX_NUMBER_OF_ANTENNA_SUPPORTED);
        pGenaralCapabilities->setHasUTCClockCapability(HAS_UTC_CLOCK_CAPABILITY);
        pGenaralCapabilities->setHasLocationCapability(HAS_LOCATION_CAPABILITY);
        pGenaralCapabilities->setIsDeviceBinded(IS_DEVICE_BINDED);


        CGPIOCapabilities *pGPIOCapabilities;
        pGPIOCapabilities = (CGPIOCapabilities *)HbFrame_Operation::genParam(GPIOCapabilities,0,NULL);
        pGPIOCapabilities->setNumGPIs(NUM_GPIS);
        pGPIOCapabilities->setNumGPOs(NUM_GPOS);

        HbFrame_Operation::addParamToParameter((CParameter *)pGPIOCapabilities,(CParameter *)pGenaralCapabilities);
        HbFrame_Operation::addParamToMessage((CParameter *)pGenaralCapabilities,pGetDeviceCapabilitiesAck);
        HbFrame_Operation::addParamToMessage((CParameter *)pStatus,pGetDeviceCapabilitiesAck);

        return pGetDeviceCapabilitiesAck;
    }
        break;

    case GetDeviceCapabilitiesRequestedData_AirProtocolCapabilities:
    {
        pGetDeviceCapabilitiesAck=HbFrame_Operation::genMessage(GetDeviceCapabilitiesAck,messageid);

        CStatus *pStatus;
        pStatus = (CStatus *)HbFrame_Operation::genParam(Status,0,NULL);
        pStatus->setStatusCode(StatusCode_M_Success);

        CAirProtocolCapabilities *pAirProtocolCapabilities;
        pAirProtocolCapabilities = (CAirProtocolCapabilities*)HbFrame_Operation::genParam(AirProtocolCapabilities,0,NULL);

        CPerAntennaAirProtocol * pPerAntennaAirProtocol;
        pPerAntennaAirProtocol = (CPerAntennaAirProtocol*)HbFrame_Operation::genParam(PerAntennaAirProtocol,0,NULL);
        pPerAntennaAirProtocol->setAntennaID(ANTENNA_ID);

        llrp_u8v_t  m_Protocolids ;
        m_Protocolids = llrp_u8v_t(5);
        for(int i=0;i<m_Protocolids.m_nValue;i++)
        {
            m_Protocolids.m_pValue[i] = i;
        }
        pPerAntennaAirProtocol->setProtocolIDs(m_Protocolids);

        CHbProtocolCapabilities *pHbProtocolCapabilities;
        pHbProtocolCapabilities = (CHbProtocolCapabilities*)HbFrame_Operation::genParam(HbProtocolCapabilities,0,NULL);

        pHbProtocolCapabilities->setSupportQuery(SUPPORT_QUERY);

        pHbProtocolCapabilities->setSupportReadData(SUPPORT_READ_DATA);
        pHbProtocolCapabilities->setSupportWriteData(SUPPORT_WRITE_DATA);
        pHbProtocolCapabilities->setSupportWriteKey(SUPPORT_WRITE_KEY);
        HbFrame_Operation::addParamToParameter((CParameter*)pPerAntennaAirProtocol,(CParameter*)pAirProtocolCapabilities);

        HbFrame_Operation::addParamToParameter((CParameter*)pHbProtocolCapabilities,(CParameter*)pAirProtocolCapabilities);


        HbFrame_Operation::addParamToMessage((CParameter *)pAirProtocolCapabilities,pGetDeviceCapabilitiesAck);

        HbFrame_Operation::addParamToMessage((CParameter *)pStatus,pGetDeviceCapabilitiesAck);

        return pGetDeviceCapabilitiesAck;
    }
        break;

    case GetDeviceCapabilitiesRequestedData_CommunicationCapabilities:
    {
        pGetDeviceCapabilitiesAck = HbFrame_Operation::genMessage(GetDeviceCapabilitiesAck, messageid);
        CStatus *pStatus;
        pStatus = (CStatus *)HbFrame_Operation::genParam(Status,0,NULL);
        pStatus->setStatusCode(StatusCode_M_Success);
        CCommunicationCapabilities *pCommunicationCapabilities;
        pCommunicationCapabilities =  (CCommunicationCapabilities *)HbFrame_Operation::genParam(CommunicationCapabilities,0,NULL);
        pCommunicationCapabilities->setSupportEthernet(SUPPORT_ETHERNET);
        pCommunicationCapabilities->setSupportHttpLink(SUPPORT_HTTP_LINK);
        pCommunicationCapabilities->setSupportIPV6(SUPPORT_IPV6);
        pCommunicationCapabilities->setSupportMobile(SUPPORT_MOBILE);
        pCommunicationCapabilities->setSupportSSL(SUPPORT_SSL);
        pCommunicationCapabilities->setSupportTcpLinkNum(SUPPORT_TCP_LINK_NUM);
        pCommunicationCapabilities->setSupportUSB(SUPPORT_USB);
        pCommunicationCapabilities->setSupportWIFI(SUPPORT_WIFI);

        CSupportRS232* pSupportRS232;
        pSupportRS232 =  (CSupportRS232*) HbFrame_Operation::genParam(SupportRS232,0,NULL);
        pSupportRS232->setPortNum(PORT_NUM);
        
        CSerialAttribute *pSerialAttribute;
        pSerialAttribute=(CSerialAttribute *)HbFrame_Operation::genParam(SerialAttribute,0,NULL);
        pSerialAttribute->setBaudRate(BAUD_RATE);

        CSupportRS485 *pSupportRS485;
        pSupportRS485 =(CSupportRS485*) HbFrame_Operation::genParam(SupportRS485,0,NULL);
        pSupportRS485->setPortNum(PORT_NUM485);

        CSerialAttribute* pSerialAttribute1;
        pSerialAttribute1 =(CSerialAttribute*) HbFrame_Operation::genParam(SerialAttribute,0,NULL);
        pSerialAttribute1->setBaudRate(BAUD_RATE1);

        HbFrame_Operation::addParamToParameter((CParameter*)pSerialAttribute1,(CParameter*)pSupportRS485);
        HbFrame_Operation::addParamToParameter((CParameter*)pSerialAttribute,(CParameter*)pSupportRS232);
        HbFrame_Operation::addParamToParameter((CParameter*)pSupportRS485,(CParameter*)pCommunicationCapabilities);
        HbFrame_Operation::addParamToParameter((CParameter*)pSupportRS232,(CParameter*)pCommunicationCapabilities);
        HbFrame_Operation::addParamToMessage((CParameter*)pCommunicationCapabilities,pGetDeviceCapabilitiesAck);
        HbFrame_Operation::addParamToMessage((CParameter *)pStatus,pGetDeviceCapabilitiesAck);
        return pGetDeviceCapabilitiesAck;
    }
        break;

    case GetDeviceCapabilitiesRequestedData_RfCapabilities:
    {
        pGetDeviceCapabilitiesAck = HbFrame_Operation::genMessage(GetDeviceCapabilitiesAck, messageid);
        CStatus *pStatus;
        pStatus = (CStatus *)HbFrame_Operation::genParam(Status,0,NULL);
        pStatus->setStatusCode(StatusCode_M_Success);
        
        CRfCapabilities* pRfCapabilities;
        pRfCapabilities = (CRfCapabilities*)HbFrame_Operation::genParam(RfCapabilities,0,NULL);
        pRfCapabilities->setCountryCode(COUNTRY_CODE);
        pRfCapabilities->setCommunicationsStandard(COMMUNICATIONS_STANDARD);

        CTransmitPowerLevelTable*  pTransmitPowerLevelTable;
        pTransmitPowerLevelTable =(CTransmitPowerLevelTable*) HbFrame_Operation::genParam(TransmitPowerLevelTable,0,NULL);
        pTransmitPowerLevelTable->setTransmitPowerValue(TRANSMIT_POWER_VALUE);
        pTransmitPowerLevelTable->setIndex(INDEX_FRE_INFO);

        CFrequencyInformation *pFrequencyInformation;
        pFrequencyInformation = (CFrequencyInformation*)HbFrame_Operation::genParam(FrequencyInformation,0,NULL);
        pFrequencyInformation->setHopping(HOP_PING);

        CFrequencyTable * pFrequencyTable;
        pFrequencyTable =  (CFrequencyTable*)HbFrame_Operation::genParam(FrequencyTable,0,NULL);
        pFrequencyTable->setIndex(INDEX_FRE_TABLE);
        pFrequencyTable->setFrequency(FREQUENCY);



        CForDataRateTable * pForDataRateTable;
        pForDataRateTable =(CForDataRateTable*) HbFrame_Operation::genParam(ForDataRateTable,0,NULL);
        pForDataRateTable->setIndex(INDEX_FOR_DATA_RATE_TABLE);
        pForDataRateTable->setForDataRate(FORDATA_RATE);

        CRevDataRateTable  *pRevDataRateTable;
        pRevDataRateTable=(CRevDataRateTable*)HbFrame_Operation::genParam(RevDataRateTable,0,NULL);
        pRevDataRateTable->setIndex(REV_DATA_TABLE_INDEX);
        pRevDataRateTable->setRevDataRate(REV_DATA_RATE);


        CForModulationTable *pForModulationTable;
        pForModulationTable =(CForModulationTable*) HbFrame_Operation::genParam(ForModulationTable,0,NULL);
        pForModulationTable->setIndex(INDEX_MODULATION_TABLE);
        pForModulationTable->setModulationType(MODULATION_TYPE);

        CRevDataEncodingTable* pRevDataEncodingTable;
        pRevDataEncodingTable = (CRevDataEncodingTable*)HbFrame_Operation::genParam(RevDataEncodingTable,0,NULL);
        pRevDataEncodingTable->setIndex(REV_DATA_ENCODING_TABLE_INDEX);
        pRevDataEncodingTable->setDataEncodingType(DATA_ENCODING_TYPE);

        CModuleDepthTable *pModuleDepthTable;
        pModuleDepthTable=(CModuleDepthTable*)HbFrame_Operation::genParam(ModuleDepthTable,0,NULL);
        pModuleDepthTable->setIndex(MODULE_DEDPTH_TABLE_INDEX);
        pModuleDepthTable->setModuleDepthValue(MODULE_DEPTH_VALUE);

        HbFrame_Operation::addParamToParameter((CParameter*)pTransmitPowerLevelTable,(CParameter*)pRfCapabilities);
        HbFrame_Operation::addParamToParameter((CParameter*)pFrequencyTable,(CParameter*)pFrequencyInformation);
        HbFrame_Operation::addParamToParameter((CParameter*)pFrequencyInformation,(CParameter*)pRfCapabilities);
        HbFrame_Operation::addParamToParameter((CParameter*)pForDataRateTable,(CParameter*)pRfCapabilities);
        HbFrame_Operation::addParamToParameter((CParameter*)pRevDataRateTable,(CParameter*)pRfCapabilities);
        HbFrame_Operation::addParamToParameter((CParameter*)pForModulationTable,(CParameter*)pRfCapabilities);
        HbFrame_Operation::addParamToParameter((CParameter*)pRevDataEncodingTable,(CParameter*)pRfCapabilities);
        HbFrame_Operation::addParamToParameter((CParameter*)pModuleDepthTable,(CParameter*)pRfCapabilities);
        HbFrame_Operation::addParamToMessage((CParameter*)pRfCapabilities,pGetDeviceCapabilitiesAck);
        HbFrame_Operation::addParamToMessage((CParameter *)pStatus,pGetDeviceCapabilitiesAck);

        return  pGetDeviceCapabilitiesAck;
    }
        break;

    case GetDeviceCapabilitiesRequestedData_SpecCapabilities:
    {
        pGetDeviceCapabilitiesAck = HbFrame_Operation::genMessage(GetDeviceCapabilitiesAck, messageid);
        CStatus *pStatus;
        pStatus = (CStatus *)HbFrame_Operation::genParam(Status,0,NULL);
        pStatus->setStatusCode(StatusCode_M_Success);

        CSpecCapabilities *pSpecCapabilities;
        pSpecCapabilities = (CSpecCapabilities*)HbFrame_Operation::genParam(SpecCapabilities,0,NULL);
        pSpecCapabilities->setClientRequestOpSpecTimeout(CLIENT_REQUEST_OPSPEC_TIME_OUT);
        pSpecCapabilities->setMaxNumAccessSpecs(MAX_NUM_ACCESSSPECS);
        pSpecCapabilities->setMaxNumAntennaSpecsPerSelectSpec(MAX_NUM_ANTENNA_SPECS_PER_SELECT_SPEC);
        pSpecCapabilities->setMaxNumOperationSpecsPerAccessSpec(MAX_NUM_OPERATION_PECS_PER_ACCESSSPEC);
        pSpecCapabilities->setMaxNumRfSpecsPerAntennaSpec(MAX_NUM_RFSPECS_PER_ANTENNA_SPEC);
        pSpecCapabilities->setMaxNumSelectSpecs(MAX_NUM_SELECT_SPECS);
        pSpecCapabilities->setMaxPriorityLevelSupported(MAX_PRIORITY_LEVEL_SUPPORTED);
        pSpecCapabilities->setSupportsClientRequestOpSpec(SUPPORTS_CLIENT_REQUESTOP_SPEC);
        pSpecCapabilities->setSupportsEventAndReportHolding(SUPPORTS_EVENT_AND_REPORT_HOLDING);
        HbFrame_Operation::addParamToMessage((CParameter*)pSpecCapabilities,pGetDeviceCapabilitiesAck);
        HbFrame_Operation::addParamToMessage((CParameter *)pStatus,pGetDeviceCapabilitiesAck);
        return pGetDeviceCapabilitiesAck;
    }
        break;
    }
}
