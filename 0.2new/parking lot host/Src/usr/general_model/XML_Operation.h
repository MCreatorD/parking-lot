/*
 * XML_Operation.h
 *
 *  Created on: 2016-6-24
 *      Author: root
 */

#ifndef XML_OPERATION_H_
#define XML_OPERATION_H_


#include <string>
#include <vector>
using namespace std;

#include "ltkcpp.h"
using namespace LLRP;

#include "HbFrame_Operation.h"
#include "LLRP_FIELDNAME.h"


class XML_Operation {
public:
	XML_Operation();
	virtual ~XML_Operation();

private:
	static std::vector<std::string> split(std::string str,std::string pattern);

public:
	static llrp_utf8v_t convertCharsToUtf8v(const char *buf);
	static llrp_u32v_t convertCharsTou32v(const char *buf);
	static llrp_u16v_t convertCharsTou16v(const char *buf);
	static llrp_u8v_t  convertCharsTou8v(const char *buf);
	static llrp_u8v_t  convertHexCharsTou8v(const char *buf);
	static llrp_u1_t   convertCharsTou1(const char *buf); //将“true"或“false"的字串转为0或1
	static llrp_u1v_t  convertCharsTou1v(const char *buf,int u1_count);

public:
	static CMessage* genMessage(int messageType,int messageID);
	static CParameter* genParam(int paramType,int contentCount,void *content...);
	static void addParamToMessage(CParameter *pParam,CMessage *pMessage);
	static void addParamToParameter(CParameter *pChild,CParameter *pParent);

public:
	static void addParamToElement(CParameter *pParam,CElement *pElement);

	static int lookupEnum(const char *value,const SEnumTableEntry enumTables[]);
	static const CFieldDescriptor* lookupFieldDescriptors(const char *propertyName,const CFieldDescriptor * const fieldDescriptors[]);

	static void addPropertyToMessage(const char *propertyName,const char * propertyValue,const char *attrName,const char *attrValue,CMessage *pMessage);
	static void addPropertyToMessage(const char *propertyName,const char * propertyValue,CMessage *pMessage);

	static void addPropertyToParameter(const char *propertyName,const char * propertyValue,CParameter *pParameter);
	static void addPropertyToParameter(const char *propertyName,const char * propertyValue,const char *attrName,const char *attrValue,CParameter *pParameter);

	static void addPropertyToElement(const char *propertyName,const char * propertyValue,CElement *pElement);
	static void addPropertyToElement(const char *propertyName,const char * propertyValue,const char *attrName,const char *attrValue,CElement *pElement);

public:
	static void ByteToHexStr(const unsigned char* source, char* dest, int sourceLen);
	static void HexStrToByte(const char* source, unsigned char* dest, int sourceLen);


};

#endif /* XML_OPERATION_H_ */
