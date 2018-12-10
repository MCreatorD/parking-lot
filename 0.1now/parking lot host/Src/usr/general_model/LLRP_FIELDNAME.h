#ifndef __LLRP_FIELDNAME_H__
#define __LLRP_FIELDNAME_H__

/*
*	各消息或参数的属性名称
*/

#define S_VerType				"VerType"

//SetDeviceConfig中的属性
#define S_ResetToFactoryDefault "ResetToFactoryDefault"
//Identification
#define S_DeviceName "DeviceName"
//EventNotificationState
#define S_EventType "EventType"
#define S_NotificationState "NotificationState"
//AntennaProperties
#define S_AntennaConnected "AntennaConnected"
#define S_AntennaID "AntennaID"
#define S_AntennaGain "AntennaGain"

//AntennaConfiguration
#define S_TransmitPowerIndex "TransmitPowerIndex"
#define S_FrequencyIndexes "FrequencyIndexes"
#define S_ForDataRateIndex "ForDataRateIndex"
#define S_RevDataRateIndex "RevDataRateIndex"
#define S_ForModulationIndex "ForModulationIndex"
#define S_RevDataEncodingIndex "RevDataEncodingIndex"

//ModuleDepth
#define S_Index "Index"

//AlarmConfiguration
#define S_AlarmMask "AlarmMask"

//AlarmThreshod
#define S_TemperatureMaxValue "TemperatureMaxValue"
#define S_TemperatureMinValue "TemperatureMinValue"

//CommLinkConfiguration
#define S_LinkType "LinkType"

//KeepaliveSpec
#define S_KeepaliveTriggerType "KeepaliveTriggerType"
#define S_PeriodicTriggerValue "PeriodicTriggerValue"

//TcpLinkConfiguration
#define S_CommMode "CommMode"
#define S_IsSSL "IsSSL"

//ClientModeConfiguration
#define S_Port "Port"

//IPAddress
#define S_Version "Version"
#define S_Address "Address"

//SerialLinkConfiguration
#define S_IfIndex "IfIndex"
#define S_SrcAddr "SrcAddr"
#define S_DstAddr "DstAddr"

//HttpLinkConfiguration
#define S_ServerUrl "ServerUrl"

//EthernetIpv4Configuration
#define S_IPAddress "IPAddress"
#define S_IPMask "IPMask"
#define S_GateWayAddr "GateWayAddr"
#define S_DNSAddr "DNSAddr"
#define S_IsDHCP "IsDHCP"

//NTPConfiguration
#define S_NtpPeriodicTime "NtpPeriodicTime"

//SerialPortConfiguration
#define S_AttributeIndex "AttributeIndex"

//LocationConfiguration
#define S_LocationType "LocationType"

//GpsLocation
#define S_Longitude "Longitude"
#define S_Latitude "Latitude"
#define S_Altitude "Altitude"

//SelectSpec
#define S_SelectSpecID "SelectSpecID"
#define S_Priority "Priority"
#define S_CurrentState "SelectCurrentState"
#define S_Persistence "Persistence"

//SelectSpecStartTrigger
#define S_SelectSpecStartTriggerType "SelectSpecStartTriggerType"

//PeriodicTrigger
#define S_Offset "Offset"
#define S_Period "Period"

//GPITrigger
#define S_GPIPortNum "GPIPortNum"
#define S_GPIEvent "GPIEvent"
#define S_Timeout "Timeout"

//SelectSpecStopTrigger
#define S_SelectSpecStopTriggerType "SelectSpecStopTriggerType"
#define S_DurationValue "DurationValue"

//AntennaSpec
#define S_AntennaIDs "AntennaIDs"

//AntennaSpecStopTrigger
#define S_AntennaSpecStopTriggerType "AntennaSpecStopTriggerType"

//TagObservationTrigger
#define S_TriggerType "TriggerType"
#define S_NumberOfTags "NumberOfTags"
#define S_NumberOfAttempts "NumberOfAttempts"
#define S_TValue "TValue"

//RfSpec
#define S_RfSpecID "RfSpecID"
#define S_ProtocolID "ProtocolID"
#define S_SelectType "SelectType"

//MemoryBank
#define S_MemoryBankID "MemoryBankID"
#define S_ReadType "ReadType"
#define S_Pointer "Pointer"
#define S_Count "Count"
#define S_BankType "BankType"

//SelectReportSpec
#define S_SelectReportTrigger "SelectReportTrigger"
#define S_NValue "NValue"
#define S_EnableSelectSpecID "EnableSelectSpecID"
#define S_EnableSpecIndex "EnableSpecIndex"
#define S_EnableRfSpecID "EnableRfSpecID"
#define S_EnableAntennaID "EnableAntennaID"
#define S_EnablePeakRSSI "EnablePeakRSSI"
#define S_EnableFirstSeenTimestamp "EnableFirstSeenTimestamp"
#define S_EnableLastSeenTimestamp "EnableLastSeenTimestamp"
#define S_EnableTagSeenCount "EnableTagSeenCount"
#define S_EnableAccessSpecID "EnableAccessSpecID"

//TagReportData
#define S_SpecIndex "SpecIndex"
#define S_RfSpecID "RfSpecID"
#define S_PeakRSSI "PeakRSSI"
#define S_AccessSpecID "AccessSpecID"

//AccessSpec
#define S_AccessSpecID "AccessSpecID"
#define S_Persistence "Persistence"
#define S_AccessCurrentState "AccessCurrentState"

//AccessSpecStopTrigger
#define S_AccessSpecStopTriggerType "AccessSpecStopTriggerType"
#define S_OperationCountValue "OperationCountValue"

//HbTargetTag
#define S_MemoryType "MemoryType"
#define S_MatchType "MatchType"
#define S_TagMask "TagMask"
#define S_TagData "TagData"

//HbReadSpec
#define S_OpSpecID "OpSpecID"

//HbWriteSpec
#define S_Data "Data"

//ReadMode
#define S_RepeatReadFlag "RepeatReadFlag"
#define S_Timer "Timer"

//AccessReportSpec
#define S_AccessReportTrigger "AccessReportTrigger"

#endif 
