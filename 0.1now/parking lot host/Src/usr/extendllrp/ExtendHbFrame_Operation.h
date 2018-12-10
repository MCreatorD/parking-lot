#ifndef EXTENDHBFRAME_OPERATION_H
#define EXTENDHBFRAME_OPERATION_H

#include "ExtendLLRP.h"
class ExtendHbFrame_Operation
{
public:
    ExtendHbFrame_Operation();
public:
    static CMessage* genMessage(int messageType,int messageID);
    static CParameter* genParam(int paramType,int contentCount,void *content...);
    static void addParamToMessage(CParameter *pParam,CMessage *pMessage);
    static void addParamToParameter(CParameter *pChild,CParameter *pParent);
};

#endif // EXTENDHBFRAME_OPERATION_H
