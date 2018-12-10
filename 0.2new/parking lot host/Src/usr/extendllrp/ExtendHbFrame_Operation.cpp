#include "ExtendHbFrame_Operation.h"

ExtendHbFrame_Operation::ExtendHbFrame_Operation()
{

}

CMessage* ExtendHbFrame_Operation::genMessage(int messageType,int messageID){
    CMessage * pmessage = NULL;
    switch(messageType){
    case ManufacturerCommand:
        pmessage = new CManufacturerCommand();
        break;
    case ManufacturerCommandAck:
        pmessage = new CManufacturerCommandAck();
        break;
    case ManufacturerReport:
        pmessage = new CManufacturerReport();
        break;
    case ManufacturerReportAck:
        pmessage = new CManufacturerReportAck();
        break;
    default:
        break;

    }//end of switch
    pmessage->setMessageID(messageID);
    pmessage->setDeviceSN(0x1234567887654321);//(0x1234567887654321);//BL1810302002

    return pmessage;
}

CParameter* ExtendHbFrame_Operation::genParam(int paramType,int contentCount,void *content...)
{

}

void ExtendHbFrame_Operation::addParamToMessage(CParameter *pParam,CMessage *pMessage)
{
    int messageid = pMessage->m_pType->m_TypeNum;
    int paramid = PARAM_BASE + pParam->m_pType->m_TypeNum;
    switch(messageid){
    case ManufacturerReportAck:
        ((CManufacturerReportAck*)pMessage)->setStatus((CStatus*)pParam);
        break;
    case ManufacturerCommandAck:
        ((CManufacturerCommandAck*)pMessage)->setStatus((CStatus*)pParam);
        break;
    default:
        break;

    }
}

void ExtendHbFrame_Operation::addParamToParameter(CParameter *pChild,CParameter *pParent)
{

}
