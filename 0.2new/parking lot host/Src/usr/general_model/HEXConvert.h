#ifndef HEXCONVERT_H
#define HEXCONVERT_H

/**
 * @brief The HEXConvert class
 * by lijin 2017.03.21
 * 实现二进制和hex字符串互相转换的类。
 */

class HEXConvert
{
public:
	HEXConvert(void);
	~HEXConvert(void);

public:
    static int  strtohex(char *string, char *cbuf, int len);
    static void  hextostr(char *ptr,char *buf,int len);
	static int  hexTobyte(unsigned char* outbyte,char *srcstr,int len) ;
	static int  byteTohex(char *outstr, unsigned char *srcbyte,int len);
};

#endif

