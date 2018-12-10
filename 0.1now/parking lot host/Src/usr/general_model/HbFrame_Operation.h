#ifndef __HBFRAME_OPERATION_H__
#define __HBFRAME_OPERATION_H__

#include "ltkcpp.h"
using namespace LLRP;
#include <string>
using namespace std;


#include "LLRP_Message_ID.h"
#include "LLRP_Parameter_ID.h"

#include "LLRP_General.h"
#include "LLRP_Capabilities.h"
#include "LLRP_Operation.h"
#include "LLRP_NET.h"

#define MAX_TX_LEN 2048
#define MAX_RX_LEN MAX_TX_LEN

class HbFrame_Operation
{
public:
	HbFrame_Operation(void);
	~HbFrame_Operation(void);
public:
	static CMessage* genMessage(int messageType,int messageID);
	static CParameter* genParam(int paramType,int contentCount,void *content...);
	static void addParamToMessage(CParameter *pParam,CMessage *pMessage);
	static void addParamToParameter(CParameter *pChild,CParameter *pParent);
public:
    static CMessage *getMessageFromBuf(unsigned char *buf,int messageLength);
    static int putMessageToBuf(CMessage *pmessage,unsigned char *buf,int buflen);
    static CMessage * copyMessage(CMessage *pMessage);
    static char *convertMessageToHex(CMessage *pMessage);
    static CMessage *convertHexToMessage(char *hexBuf);
    static void printMessage(CMessage *pMessage);
    static CMessage *getMessageFromXml(string xmlstring);
    static string getXmlFromMessage(CMessage *pmessage);
    static CParameter *getParameterFromXml(string xmlstring);
    static string getXmlFromParameter(CParameter *pParameter);
};


#endif
