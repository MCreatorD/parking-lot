/*****************************************************
Project : EPC&ISO18000 Series interrogator
Version  : 1.0
File name: "utility.h"
Date     : 2007-12-10
Author   : chengli
Company  : delisheng
Comments :
*****************************************************/
#ifndef UTILITY_H
#define UTILITY_H

#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32f2xx.h"

unsigned char CheckSum(unsigned char *uBuff, unsigned char uBuffLen) ;//reentrant;
unsigned char Byte_Parity_Cal(unsigned char Data);
void Calculate_CRC16(unsigned char * Crc,unsigned char * Data,unsigned char Length);
void Calculate_CRC16_Betys(unsigned char * Crc,unsigned char * Data,unsigned char Length);//chengli add
unsigned short Calculate_CRC16_Bits(unsigned char * Crc,unsigned char * Data,unsigned short Length);
unsigned char Check_CRC16(unsigned char * Data,unsigned char Length);
unsigned char XOR_Cal(unsigned char *uBuf,unsigned char num);
unsigned char HexToASCII(unsigned char data_hex);
unsigned char ASCIIToHex(unsigned char uData);
unsigned short CRC16(unsigned char *ptr, unsigned char len);
unsigned char CRC5(unsigned char *ptr, unsigned char len);
unsigned char Crc5Bit(unsigned char * Data,unsigned char Length); // ptr 为数据指针，len 为数据长度chengli add
unsigned char Crc5_8Bits(unsigned char ptr_buff);  // ptr 为数据指针，len 为数据长度
unsigned short  CRC16b(unsigned char* ptr, unsigned char nbits);
//only for verify crc
void Calculate_0CRC16(unsigned char * Crc,unsigned char * Data,unsigned char Length);
void Calculate_CRC16_Bytes(unsigned char * Crc,unsigned char * Data,unsigned char Length);
unsigned short int Crc1Betys(unsigned char ptr_buff,unsigned char len); // ptr 为数据指针，len 为数据长度
unsigned char  CheckSum_NEW(unsigned char *uBuff, unsigned char uBuffLen);
//void AddMyTagData(unsigned char *pTagData);
//void StuffSendBuf(unsigned char Data, unsigned char len);
//void ClearSendBuf(unsigned char *Buff, unsigned char len);

#ifdef __cplusplus
}
#endif

#endif
