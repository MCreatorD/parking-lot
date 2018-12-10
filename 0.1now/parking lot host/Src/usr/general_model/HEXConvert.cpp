#include "HEXConvert.h"
#include <stdio.h>

HEXConvert::HEXConvert(void)
{
}

HEXConvert::~HEXConvert(void)
{
}

/****************************************************************************
函数名称: str_to_hex
函数功能: 字符串转换为十六进制
输入参数: string 字符串 cbuf 十六进制 len 字符串的长度。
输出参数: 无
*****************************************************************************/
int  HEXConvert::strtohex(char *string, char *cbuf, int len)
{
 unsigned char  high, low;
 int idx, ii=0;
 for (idx=0; idx<len; idx+=2)
 {
  high = string[idx];
  low = string[idx+1];

  if(high>='0' && high<='9')
   high = high-'0';
  else if(high>='A' && high<='F')
   high = high - 'A' + 10;
  else if(high>='a' && high<='f')
   high = high - 'a' + 10;
  else
   return -1;

  if(low>='0' && low<='9')
   low = low-'0';
  else if(low>='A' && low<='F')
   low = low - 'A' + 10;
  else if(low>='a' && low<='f')
   low = low - 'a' + 10;
  else
   return -1;

  cbuf[ii++] = high<<4 | low;
 }
 return 0;
}

/****************************************************************************
函数名称: hex_to_str
函数功能: 十六进制转字符串
输入参数: ptr 字符串 buf 十六进制 len 十六进制字符串的长度。
输出参数: 无
*****************************************************************************/
 void  HEXConvert::hextostr(char *ptr,char *buf,int len)
{
 for(int i = 0; i < len; i++)
 {
  sprintf(ptr,"%02x",buf[i]);
  ptr += 2;
 }
}

 /**
 * @brief HEXConvert::hexTobyte
 * @param outbyte
 * @param srcstr
 * @param len，hex字符数组长度
 * @return
 * hex字符数组转为二进制，返回转换后的二进数组的长度
 */
int HEXConvert::hexTobyte(unsigned char* outbyte,char *srcstr,int len) {
    char t[] = ("0123456789ABCDEF");

    int m = 0;
    int k = 0;
    int tmp = 0;
    for(int i=0;i<len;i++)
    {
          k=0;
          if((srcstr[i]>='0')&&(srcstr[i]<='9')) k=srcstr[i]-48;
          else if((srcstr[i]>='A')&&(srcstr[i]<='F'))k=srcstr[i]-55; //65
          else if((srcstr[i]>='a')&&(srcstr[i]<='f'))k=srcstr[i]-87; //97
          else{ k=0 ;
          // AfxMessageBox("sign exist equals 0");
          };

          if (i%2 !=0)
          {
              outbyte[m]=((tmp<<4)&0x00f0) |( k&0x00f);
           tmp=0;
           m++;
          }
          else
           tmp= k;

    }
    return len/2;
}


/**
  * @brief HEXConvert::byteTohex
  * @param outstr
  * @param srcbyte
  * @param len
  * @return
  * 二进制数组转为hex字符串
  * 返回的是hex字符数组的长度
  */
 int HEXConvert::byteTohex(char *outstr,unsigned char*  srcbyte, int len)
 {

    char t[] = ("0123456789ABCDEF");

  int a;
  char ch;
  int i=0,m=0;

  for(int i=0;i<len*2;i+=2)
  {
    a=(srcbyte[i/2]>>4)&0x0f;;
    ch=t[a];
    outstr[i] = ch;
    a=srcbyte[i/2]&0x0f;;
    ch=t[a];
    outstr[i+1] = ch;
  }
  return len*2;
}
