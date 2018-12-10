
/*
 ***************************************************************************
 *  Copyright 2007,2008 Impinj, Inc.
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 ***************************************************************************
 */

#include "LLRP_General.h"
#include "LLRP_Capabilities.h"
#include "LLRP_Operation.h"
#include "LLRP_NET.h"

namespace LLRP
{


static char     ident[] = {
	"$" "Id: libltkcpp "
	LTKCPP_VERSION_STR
	"  Built: "
	__DATE__
	" "
	__TIME__
	" $"
};

void
enrollCoreTypesIntoRegistry (
  CTypeRegistry *               pTypeRegistry)
{
	// Capabilities
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
  
    //pTypeRegistry->enroll(&CSecurityModuleCapabilities::s_typeDescriptor);
	
	// General
	
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
	
	// Net
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
  
    //pTypeRegistry->enroll(&CEthernetConfiguration::s_typeDescriptor);
  
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
  
    //pTypeRegistry->enroll(&CPasswordVersion::s_typeDescriptor);
  
    pTypeRegistry->enroll(&CVersionInfo::s_typeDescriptor);
  
    pTypeRegistry->enroll(&CVersionDownload::s_typeDescriptor);
  
    pTypeRegistry->enroll(&CAlarmReportInfo::s_typeDescriptor);
  
    pTypeRegistry->enroll(&CAlarmRestoreInfo::s_typeDescriptor);
  
    pTypeRegistry->enroll(&CAlarmSyncInfo::s_typeDescriptor);
  
    pTypeRegistry->enroll(&CDiagnosticTestItem::s_typeDescriptor);
  
    //pTypeRegistry->enroll(&CDiagnosticTestData::s_typeDescriptor);
  
    pTypeRegistry->enroll(&CDiagnosticTestResultItem::s_typeDescriptor);
  
    //pTypeRegistry->enroll(&CDiagnosticTestResultData::s_typeDescriptor);
  
    pTypeRegistry->enroll(&CDiagnosticTestResultAntennaConnected::s_typeDescriptor);
  
    pTypeRegistry->enroll(&CDiagnosticTestResultAntennaVSWR::s_typeDescriptor);
  
    pTypeRegistry->enroll(&CLocationConfiguration::s_typeDescriptor);
  
    //pTypeRegistry->enroll(&CLocationInfo::s_typeDescriptor);
  
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
	
	// Operation
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
  
    //pTypeRegistry->enroll(&COpSpec::s_typeDescriptor);
  
    pTypeRegistry->enroll(&CHbMatchSpec::s_typeDescriptor);
  
    pTypeRegistry->enroll(&CHbTargetTag::s_typeDescriptor);
  
    pTypeRegistry->enroll(&CHbReadSpec::s_typeDescriptor);
  
    pTypeRegistry->enroll(&CHbWriteSpec::s_typeDescriptor);
  
    pTypeRegistry->enroll(&CClientRequestSpec::s_typeDescriptor);
  
    pTypeRegistry->enroll(&CAccessReportSpec::s_typeDescriptor);
  
    pTypeRegistry->enroll(&CTagReportData::s_typeDescriptor);
  
    //pTypeRegistry->enroll(&CSelectSpecResult::s_typeDescriptor);
  
    //pTypeRegistry->enroll(&CAccessSpecResult::s_typeDescriptor);
  
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


/**
 ****************************************************************************
 ** @brief Gets the type registry for the LTKCPP
 ** 
 ** @return CTypeRegistry The Type registry.
 **/
CTypeRegistry *
getTheTypeRegistry (void)
{
	CTypeRegistry *         pTypeRegistry = new CTypeRegistry();

	enrollCoreTypesIntoRegistry (pTypeRegistry);

	return pTypeRegistry;
}


}; /* namespace LLRP */

