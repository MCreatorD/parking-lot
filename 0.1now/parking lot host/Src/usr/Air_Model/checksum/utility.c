/*****************************************************
Project : EPC&ISO18000 Series interrogator
Version  : 1.0
File name: "utility.c"
Date     :
Author   : chengli
Company  :delisheng
Comments :
******************************************************/
//#include <stdint.h>
//#include "utility.h"
//#include <math.h>
//#include <string.h>
//#include "myinclude.h"
#include "utility.h"

uint8_t CRC5_Buff;

const unsigned short crc16_table[256]=   //* CRC余式表
{
    0x0000, 0x1021, 0x2042, 0x3063, 0x4084, 0x50a5, 0x60c6, 0x70e7,
    0x8108, 0x9129, 0xa14a, 0xb16b, 0xc18c, 0xd1ad, 0xe1ce, 0xf1ef,
    0x1231, 0x0210, 0x3273, 0x2252, 0x52b5, 0x4294, 0x72f7, 0x62d6,
    0x9339, 0x8318, 0xb37b, 0xa35a, 0xd3bd, 0xc39c, 0xf3ff, 0xe3de,
    0x2462, 0x3443, 0x0420, 0x1401, 0x64e6, 0x74c7, 0x44a4, 0x5485,
    0xa56a, 0xb54b, 0x8528, 0x9509, 0xe5ee, 0xf5cf, 0xc5ac, 0xd58d,
    0x3653, 0x2672, 0x1611, 0x0630, 0x76d7, 0x66f6, 0x5695, 0x46b4,
    0xb75b, 0xa77a, 0x9719, 0x8738, 0xf7df, 0xe7fe, 0xd79d, 0xc7bc,
    0x48c4, 0x58e5, 0x6886, 0x78a7, 0x0840, 0x1861, 0x2802, 0x3823,
    0xc9cc, 0xd9ed, 0xe98e, 0xf9af, 0x8948, 0x9969, 0xa90a, 0xb92b,
    0x5af5, 0x4ad4, 0x7ab7, 0x6a96, 0x1a71, 0x0a50, 0x3a33, 0x2a12,
    0xdbfd, 0xcbdc, 0xfbbf, 0xeb9e, 0x9b79, 0x8b58, 0xbb3b, 0xab1a,
    0x6ca6, 0x7c87, 0x4ce4, 0x5cc5, 0x2c22, 0x3c03, 0x0c60, 0x1c41,
    0xedae, 0xfd8f, 0xcdec, 0xddcd, 0xad2a, 0xbd0b, 0x8d68, 0x9d49,
    0x7e97, 0x6eb6, 0x5ed5, 0x4ef4, 0x3e13, 0x2e32, 0x1e51, 0x0e70,
    0xff9f, 0xefbe, 0xdfdd, 0xcffc, 0xbf1b, 0xaf3a, 0x9f59, 0x8f78,
    0x9188, 0x81a9, 0xb1ca, 0xa1eb, 0xd10c, 0xc12d, 0xf14e, 0xe16f,
    0x1080, 0x00a1, 0x30c2, 0x20e3, 0x5004, 0x4025, 0x7046, 0x6067,
    0x83b9, 0x9398, 0xa3fb, 0xb3da, 0xc33d, 0xd31c, 0xe37f, 0xf35e,
    0x02b1, 0x1290, 0x22f3, 0x32d2, 0x4235, 0x5214, 0x6277, 0x7256,
    0xb5ea, 0xa5cb, 0x95a8, 0x8589, 0xf56e, 0xe54f, 0xd52c, 0xc50d,
    0x34e2, 0x24c3, 0x14a0, 0x0481, 0x7466, 0x6447, 0x5424, 0x4405,
    0xa7db, 0xb7fa, 0x8799, 0x97b8, 0xe75f, 0xf77e, 0xc71d, 0xd73c,
    0x26d3, 0x36f2, 0x0691, 0x16b0, 0x6657, 0x7676, 0x4615, 0x5634,
    0xd94c, 0xc96d, 0xf90e, 0xe92f, 0x99c8, 0x89e9, 0xb98a, 0xa9ab,
    0x5844, 0x4865, 0x7806, 0x6827, 0x18c0, 0x08e1, 0x3882, 0x28a3,
    0xcb7d, 0xdb5c, 0xeb3f, 0xfb1e, 0x8bf9, 0x9bd8, 0xabbb, 0xbb9a,
    0x4a75, 0x5a54, 0x6a37, 0x7a16, 0x0af1, 0x1ad0, 0x2ab3, 0x3a92,
    0xfd2e, 0xed0f, 0xdd6c, 0xcd4d, 0xbdaa, 0xad8b, 0x9de8, 0x8dc9,
    0x7c26, 0x6c07, 0x5c64, 0x4c45, 0x3ca2, 0x2c83, 0x1ce0, 0x0cc1,
    0xef1f, 0xff3e, 0xcf5d, 0xdf7c, 0xaf9b, 0xbfba, 0x8fd9, 0x9ff8,
    0x6e17, 0x7e36, 0x4e55, 0x5e74, 0x2e93, 0x3eb2, 0x0ed1, 0x1ef0
};
//unsigned char Byte_Parity_Cal(unsigned char Data)
//{
//    Data = (Data & 0x0F) ^ (Data >> 4);
//    Data = (Data & 0x03) ^ (Data >> 2);
//    Data = (Data & 0x01) ^ (Data >> 1);
//    return Data;
//}
//函数功能：数据累加和
unsigned char  CheckSum(unsigned char *uBuff, unsigned char uBuffLen) //reentrant
{
    unsigned char i,uSum=0;
    for(i=0; i<uBuffLen; i++)
    {
        uSum = uSum + uBuff[i];
    }
    uSum = (~uSum) + 1;
    return uSum;
}
unsigned char  CheckSum_NEW(unsigned char *uBuff, unsigned char uBuffLen) //reentrant
{
    unsigned char i,uSum=0;
    for(i=0; i<uBuffLen; i++)
    {
        uSum = uSum + uBuff[i];
    }
    //uSum = (~uSum) + 1;
    return uSum;
}
unsigned char XOR_Cal(unsigned char *uBuf,unsigned char num)
{
    unsigned char i;
    unsigned char result=0;
    for(i=0; i<num; i++)
    {
        result=result^uBuf[i];
    }
    return  result;
}
//函数功能：HEX  转ASCLL
unsigned char HexToASCII(unsigned char data_hex)
{
    unsigned char ASCII_Data;
    ASCII_Data=data_hex & 0x0F;
    if(ASCII_Data<10)
    {
        ASCII_Data=ASCII_Data+0x30;
    }
    else
    {
        ASCII_Data=ASCII_Data+0x37;
    }
    return ASCII_Data;
}
unsigned char ASCIIToHex(unsigned char uData)
{
    unsigned char uTemp=uData;
    if(uTemp>=0x41&&uTemp<=0x46)
    {
        uTemp=uTemp-0x37;
    }
    else if(uTemp>=0x30&&uTemp<=0x39)
    {
        uTemp=uTemp-0x30;
    }
    return uTemp;
}
void Calculate_CRC16(unsigned char * Crc,unsigned char * Data,unsigned char Length)
{
    unsigned short crc;
    unsigned char da;
    crc = 0xFFFF;
    while(Length--!=0)
    {
        da=(unsigned char) (crc/256);
        crc <<= 8;
        crc ^= crc16_table[da^*Data];
        Data++;
    }
    crc = ~crc;
    Crc[0] = (unsigned char)(crc >>8);
    Crc[1] = (unsigned char)(crc & 0x00FF);
}
/*CRC16Check,OK返回真,否则返回假*/
unsigned char Check_CRC16(unsigned char * Data,unsigned char Length)
{
    unsigned short crc;
    unsigned char da;
    crc = 0xFFFF;
    while(Length--!=0)
    {
        da=(unsigned char) (crc/256);
        crc <<= 8;
        crc ^= crc16_table[da^*Data];
        Data++;
    }
    if (crc == 0x1D0F)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
unsigned short CRC16(unsigned char *ptr, unsigned char len)
{
    unsigned short crc;
    unsigned char da;
    crc =0xffff;
    while(len--!=0)
    {
        da=(unsigned char) (crc/256);
        crc <<= 8;
        crc ^= crc16_table[da^*ptr];
        ptr++;
    }
    return(crc);
}
unsigned char CRC5(unsigned char *ptr,unsigned char nbits) // ptr 为数据指针，len 为数据长度
{
    uint8_t i;//,j=0;
    uint8_t crc = 0x05;
    i  = nbits%8;
    while(nbits--)
    {
        for(i=0x80; i!=0; i>>=1)
        {
            if((crc&0x10)!=0)
            {
                crc<<=1;
                crc^=0x05;
            }
            else
            {
                crc<<=1;
            }
            if((*ptr&i)!=0)
            {
                crc^=0x05;
            }
        }
        ptr++;
    }
    return(crc);
}
unsigned short CRC16b(unsigned char *ptr,unsigned char nbits) // ptr 为数据指针，len 为数据长度
{
    unsigned char  i,j=0;
    unsigned short crc = 0xFFFF;
    while(1)
    {
        for(i=0x80; i!=0; i >>= 1)
        {
            if((crc&0x8000)!=0)
            {
                crc<<=1;
                crc^=0x1021;
            }
            else
            {
                crc<<=1;
            }
            if((*ptr&i)!=0)
            {
                crc^=0x1021;
            }
            j++;
            if(j >= nbits)
            {
                return(crc);
            }
        }
        ptr++;
    }
}
void Calculate_CRC16_Bytes(uint8_t * Crc,uint8_t * Data,uint8_t Length)
{
    uint16_t CrcBUF;
    uint8_t da;
    CrcBUF = 0xFFFF;
    while(Length--!=0)
    {
        da=(uint8_t) (CrcBUF/256);
        CrcBUF <<= 8;
        CrcBUF ^= Crc1Betys((da^*Data),1) ;//crc16_table[da^*Data];
        Data++;
    }
    // CrcBUF = ~CrcBUF;
    Crc[0] = (uint8_t)(CrcBUF >>8);
    Crc[1] = (uint8_t)(CrcBUF & 0x00FF);
}
//only for verify crc,must be deleted
unsigned short Calc_CRC(unsigned short CRCacc,unsigned short cword)
{
    unsigned short i;
    unsigned short xorval;
    for (i=0; i<8; i++)
    {
        xorval = (( CRCacc>>8)^(cword<<i)) & 0x0080;
        CRCacc = (CRCacc <<1) & 0xFFFE;
        if (xorval)
        {
            CRCacc ^=0x1021;
        }
    }
    return CRCacc;
}
void Calculate_0CRC16(unsigned char * Crc,unsigned char * Data,unsigned char Length)
{
    unsigned char i;
    unsigned short CRCacc;
    CRCacc = 0xFFFF;
    for (i=0; i<Length; i++)
    {
        CRCacc = Calc_CRC(CRCacc,Data[i]);
    }
    CRCacc = ~CRCacc;
    Crc[0] = (unsigned char)(CRCacc >>8);
    Crc[1] = (unsigned char)(CRCacc & 0x00FF);
}
//uint TestCrc1Betys(uchar *ptr,uchar len); // ptr 为数据指针，len 为数据长度
//CRC16 Calculate Betys 07-12-21 chengli
//-----------------------------------------------------------------------
void Calculate_CRC16_Betys(unsigned char * Crc,unsigned char * Data,unsigned char Length)
{
    unsigned short CrcBUF;
    unsigned char da;
    CrcBUF = 0xFFFF;
    while(Length--!=0)
    {
        da=(unsigned char) (CrcBUF/256);
        CrcBUF <<= 8;
        CrcBUF ^= Crc1Betys((da^*Data),1) ;//crc16_table[da^*Data];
        Data++;
    }
    CrcBUF = ~CrcBUF;
    Crc[0] = (unsigned char)(CrcBUF >>8);
    Crc[1] = (unsigned char)(CrcBUF & 0x00FF);
}
//crc16软件算法子函数
uint16_t Crc1Betys(uint8_t ptr_buff,uint8_t len) // ptr 为数据指针，len 为数据长度
{
    uint8_t i;
    uint16_t crc; // CRC 码
    crc = 0x0000;
    while(len--)
    {
        for(i=0x80; i!=0; i>>=1)
        {
            if((crc&0x8000)!=0)
            {
                crc<<=1;
                crc^=0x1021;
            }
            else
            {
                crc<<=1;
            }
            if((ptr_buff&i)!=0)
            {
                crc^=0x1021;
            }
        }
        ptr_buff=0;
    }
    return(crc);
}
//--------------------------------------------------------------------------
//CRC5 Calculate Bits 07-12-21 chengli
unsigned char Crc5Bit(unsigned char * Data,unsigned char Length) // ptr 为数据指针，len 为数据长度
{
    unsigned char i,Betys,Bits,j=0;
    Betys = Length / 8;
    Bits = Length % 8;
    CRC5_Buff = 0x09;
    while(Betys--!=0)
    {
        Crc5_8Bits(*Data) ;
        Data++;
    }
    j=0x80;
    for(i=Bits; i!=0; i--)
    {
        if((CRC5_Buff &0x10)!=0)
        {
            CRC5_Buff <<=1;
            CRC5_Buff ^=0x09;
        }
        else
        {
            CRC5_Buff <<=1;
        }
        if((*Data&j)!=0)
        {
            CRC5_Buff ^=0x09;
        }
        j>>=1;
    }
    CRC5_Buff  = CRC5_Buff &0x1F;
    return(CRC5_Buff );
}
//crc5软件算法子函数
unsigned char Crc5_8Bits(unsigned char ptr_buff) // ptr 为数据指针，len 为数据长度
{
    uint8_t i;
    for(i=0x80; i!=0; i>>=1)
    {
        if((CRC5_Buff &0x10)!=0)
        {
            CRC5_Buff <<=1;
            CRC5_Buff ^=0x09;
        }
        else
        {
            CRC5_Buff <<=1;
        }
        if((ptr_buff&i)!=0)
        {
            CRC5_Buff ^=0x09;
        }
    }
    return(CRC5_Buff );
}
//---------------------------------------------------------------------------
unsigned int CRC16_Buff;
unsigned int Crc16l_1(uint8_t ptr_buff,uint8_t len); // ptr 为数据指针，len 为数据长度
//CRC16 Calculate Bits 07-12-21 chengli
//----------------------------------------------------------
unsigned short Calculate_CRC16_Bits(unsigned char * Crc,unsigned char * Data,unsigned short Length)
{
    uint8_t Bytes=0,Bits=0,i=0,j=0;
    Bytes=  Length/8;
    Bits =  Length%8;
    CRC16_Buff = 0xFFFF;
    while(Bytes--!=0)
    {
        Crc16l_1(*Data,1);
        Data++;
    }
    j = 0x80;
    for(i=Bits; i!=0; i--)
    {
        if((CRC16_Buff&0x8000) !=0)
        {
            CRC16_Buff<<=1;
            CRC16_Buff^=0x1021;
        }
        else
        {
            CRC16_Buff<<=1;
        }
        if((*Data&j)!=0)
        {
            CRC16_Buff^=0x1021;
        }
        j>>=1;
    }
    CRC16_Buff = ~CRC16_Buff;
    return(CRC16_Buff);
}
//crc16软件算法子函数
unsigned int  Crc16l_1(uint8_t ptr_buff,uint8_t len) // ptr 为数据指针，len 为数据长度
{
    uint8_t i;
    while(len--)
    {
        for(i=0x80; i!=0; i>>=1)
        {
            if((CRC16_Buff&0x8000)!=0)
            {
                CRC16_Buff<<=1;
                CRC16_Buff^=0x1021;
            }
            else
            {
                CRC16_Buff<<=1;
            }
            if((ptr_buff&i)!=0)
            {
                CRC16_Buff^=0x1021;
            }
        }
        ptr_buff=0;
    }
    return(CRC16_Buff);
}
//void AddMyTagData(unsigned char *pTagData)
//{
//}
//void StuffSendBuf(unsigned char Data, unsigned char len)
//{
//    signed char  i,j;
//    unsigned char  current_bytes;
//    unsigned char  current_bits;
//    if(0==len)
//    {
//        return;
//    }
//    current_bytes = EPC_BitsToSend /8;
//    current_bits  = EPC_BitsToSend %8;
//    i = 8 - current_bits-len;
//    if(i >= 0)
//    {
//        EPC_Send_Buf[current_bytes] |= Data<<i;
//    }
//    else
//    {
//        i = abs(i);
//        j = 8-i;
//        EPC_Send_Buf[current_bytes] |= Data>>i;
//        current_bytes++;
//        EPC_Send_Buf[current_bytes] |= Data<<j;
//    }
//    EPC_BitsToSend += len;
//}
//void ClearSendBuf(unsigned char *Buff, unsigned char len)
//{
//    memset(Buff, 0 , len);
//}
