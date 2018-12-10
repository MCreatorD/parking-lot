#include "stdio.h"
#include "string.h"

#include <stdlib.h>
#include <string.h>
#include "timer.h"

#include "stm32f2xx.h"
#include "mcutos.h"
#include "stdlib.h"
#include "ws_spi.h"
//#include "stdbool.h"
#include "sm2.h"
#include "Sm2Certification1.h"
#include "timer.h"
#include <stdio.h>

STRUCT_M2SEC_FRAME1 *pframe;

int FrameTypeToLen(int FRAME)
{
    switch(FRAME)
    {
    case M2SEC_RESRS_FRAME:
        return 14;
    case M2SEC_RESCER_FRAME:
        return 7;
    case M2SEC_SEC2CA_FRAME:
        return 982;;
    case M2SEC_RESACTIVE_FRAME:
        return 7;
    case M2SEC_SETACK_FRAME:
        return 7;
    case M2SEC_TAGDATA_FRAME:
        return 40+4;
    default:
        return 0;
    }
}
int getFrameContenLen(STRUCT_M2SEC_FRAME1 *pframe)
{
    uint16_t datalen = 0;
    datalen = pframe->DataLen[1]<<8|pframe->DataLen[0];
    return datalen-1;
}
int caluFrameLen(STRUCT_M2SEC_FRAME1 *pframe)
{
    uint16_t datalen = 0;
    datalen = pframe->DataLen[1]<<8|pframe->DataLen[0];
    return datalen+5;
}
uint8_t caluBCCCheck(STRUCT_M2SEC_FRAME1 *pframe)
{
    uint8_t bcccheck;
    uint16_t datalen = 0;
	  int i;
	  uint8_t * checkbuf = (uint8_t *)malloc(sizeof(datalen+3));
    datalen = pframe->DataLen[1]<<8|pframe->DataLen[0];

    checkbuf[0] = pframe->Type;
    checkbuf[1] = pframe->DataLen[0];
    checkbuf[2] = pframe->DataLen[1];
    checkbuf[3] = pframe->OperId;
    if(datalen>1)
    {
        memcpy(checkbuf+4,pframe->DataBuf,datalen-1);
    }
    bcccheck =checkbuf[0];
    for(i = 1; i<datalen+3; i++)
    {
        bcccheck ^= checkbuf[i];
    }
    free(checkbuf);
    return bcccheck;
}
void putFrameToBuf(STRUCT_M2SEC_FRAME1 *pframe,uint8_t *buf)
{
    uint16_t datalen = 0;
	    int pos = 0;
    datalen = pframe->DataLen[1]<<8|pframe->DataLen[0];

    memcpy(buf,(uint8_t*)pframe,5);
    pos = 5;
    if(datalen-1>0)
    {
        memcpy(buf+5,pframe->DataBuf,datalen-1);
        pos += datalen-1;
    }
    buf[pos] = pframe->BCCCheck;
}
STRUCT_M2SEC_FRAME1 * getFrameFromBuf(uint8_t *buf,int buflen)
{
	int i;
    uint16_t datalen = 0;
	STRUCT_M2SEC_FRAME1 *pframe;
	uint8_t * databuff;
    printf(" buf is:\n");
    for(i=0; i<buflen; i++)
    {
        printf("%02x,",buf[i]);
    }
    printf("sizeof(STRUCT_M2SEC_FRAME1):%d",sizeof(STRUCT_M2SEC_FRAME1));
    if(NULL==pframe)
    {
        printf("error\r\n");
    }
    pframe = (STRUCT_M2SEC_FRAME1 *)malloc(sizeof(STRUCT_M2SEC_FRAME1));
    printf("1buf[4]:%x",buf[4]);
    if(buflen<6)
    {
        return NULL;
    }
    printf("2buf[4]:%x",buf[4]);
    pframe->Head = buf[0];
    pframe->Type = buf[1];
    pframe->DataLen[0] = buf[2];
    pframe->DataLen[1] = buf[3];
    datalen = pframe->DataLen[1]<<8|pframe->DataLen[0];
    if(datalen+5>buflen||datalen<=0)
    {
        return NULL;
    }
    pframe->OperId = buf[4];
    databuff = (uint8_t *) malloc(sizeof(datalen-1));
    if(datalen>1)
    {
        memcpy(databuff,buf+5,datalen-1);
        pframe->DataBuf = databuff;
        pframe->BCCCheck = buf[ 5 + datalen-1];
    }
    else
    {
        pframe->DataBuf = NULL;
        pframe->BCCCheck = buf[5] ;
    }
    printf("ppframe->head:%x",pframe->Head);
    printf("ppframe->Type:%x",pframe->Type);
    printf("datalen:%x",datalen);
    printf("pframe->OperId:%x",pframe->OperId);
    printf("pframe->BCCCheck:%x",pframe->BCCCheck);
    if(pframe->BCCCheck==caluBCCCheck(pframe))
    {
        free(databuff);
        return pframe;
    }
    else
    {
        removeFrame(pframe);
        free(databuff);
        free(pframe);
        return NULL;
    }
}
STRUCT_M2SEC_FRAME1 * creatFrame(int frametype,uint8_t *contentbuf,int contentlen)
{
	int datalen = 0;
    pframe = (STRUCT_M2SEC_FRAME1 *)malloc(sizeof(STRUCT_M2SEC_FRAME1));  
    switch(frametype)
    {
    case M2SEC_APPLYRS_FRAME:
        pframe->Head = 0xAA;
        pframe->Type = 0x31;
        pframe->OperId = 0x01;
        datalen = contentlen + 1;
        break;
    case M2SEC_CER_FRAME:
        pframe->Head = 0xAA;
        pframe->Type = 0x31;
        pframe->OperId = 0x02;
        datalen = contentlen + 1;
        break;
    case M2SEC_USERMSG_FRAME:
        pframe->Head = 0xAA;
        pframe->Type = 0x31;
        pframe->OperId = 0x03;
        datalen = contentlen + 1;
        break;
    case M2SEC_LICENSE_FRAME:
        pframe->Head = 0xAA;
        pframe->Type = 0x31;
        pframe->OperId = 0x04;
        datalen = contentlen + 1;
        break;
    case M2SEC_CERCHAIN_FRAME:
        pframe->Head = 0xAA;
        pframe->Type = 0x31;
        pframe->OperId = 0x05;
        datalen = contentlen + 1;
        break;
    case M2SEC_SET_FRAME:
        pframe->Head = 0xAA;
        pframe->Type = 0x11;
        pframe->OperId = contentbuf[0];
        datalen = contentlen;
        break;
    }
    if(frametype!=M2SEC_SET_FRAME)
    {
        pframe->DataLen[0] = datalen&0x00FF;
        pframe->DataLen[1] = datalen>>8;
        if(contentlen==0)
        {
            pframe->DataBuf = NULL;
        }
        else
        {
            pframe->DataBuf = (uint8_t *)malloc (contentlen * sizeof(uint8_t));
            memcpy(pframe->DataBuf,contentbuf,contentlen);
        }
    }
    else
    {
        pframe->DataLen[0] = datalen&0x00FF;
        pframe->DataLen[1] = datalen>>8;
        if(contentlen==0)
        {
            pframe->DataBuf = NULL;
        }
        else
        {
            pframe->DataBuf = (uint8_t *)malloc ((contentlen-1) * sizeof(uint8_t));
            memcpy(pframe->DataBuf,contentbuf+1,contentlen-1);
        }
    }
    pframe->BCCCheck = caluBCCCheck(pframe);
    return pframe;
}
void removeFrame(STRUCT_M2SEC_FRAME1 *pframe)
{
    if(pframe==NULL)
    {
        return;
    }
    if(pframe->DataBuf!=NULL)
    {
        free(pframe->DataBuf);
    }
    free(pframe);
    pframe = NULL;
}
bool sendFrameToSecure(STRUCT_M2SEC_FRAME1 *pframe)
{
	int i=0;
    int framelen = caluFrameLen(pframe);
//    printf("framelen=%d\n",framelen);
    uint8_t * buf = (uint8_t *)malloc(sizeof(framelen));
    putFrameToBuf(pframe,buf);
//    printf("frame buf is:\n");
    for(i=0; i<framelen; i++)
    {
//        printf("%02x,",buf[i]);
    }
//    printf("\n");
    if(!SPIx_Send_bytes(buf,framelen))
    {
        free(buf);
        return false;
    }
    else
    {
        free(buf);
        return true;
    }
}
STRUCT_M2SEC_FRAME1 * getFrameFromSecure(int frametype)
{
	int i=0;
	STRUCT_M2SEC_FRAME1 * pframe;
    int framelen = FrameTypeToLen(frametype);
    uint8_t * buf = (uint8_t *)malloc(sizeof(framelen));
    if(SPIx_Receive_bytes(buf,framelen))
    {
        printf("receive buf is:\n");
        for(i=0; i<framelen; i++)
        {
            printf("%02x,",buf[i]);
        }
        pframe = getFrameFromBuf(buf,framelen);
        free(buf);
        return pframe;
    }
    else
    {
        free(buf);
        return NULL;
    }
}
void waitSafeFalling(void)
{
    while(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_7)==1)
    {
        ;
    }
}
void waitSafeRising(void)
{
    while(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_7)==0)
    {
        ;
    }
}
void    resetSecureModule()
{
    //GPIO_ResetBits(GPIOC,GPIO_Pin_8);
		printf("-------------resetSecureModule---------------------------------");
	  Board_EXIO_Init(0x08); //0000 1000
    Delay_ms1(4);
    Board_EXIO_Init(0x0C); //0000 1100
}
void resetSecMod(void)
{
    resetSecureModule();
}

bool Certificate(void)
{
	int i=0;
	uint16_t timeCnt;
    
	STRUCT_M2SEC_FRAME1 *pframe1;
	int pos = 0;
	bool Result;
	uint8_t signtemp[32];
	uint8_t cerbuf[2048];
    uint8_t Rs[8] = {0};
    uint8_t Rm[8] = {0};
    uint8_t certif[6]= {0xaa,0x31,0x01,0x00,0x01,0x31};
    uint8_t needsigndata[32] = {0x00};
    uint8_t sign_cr[32] = {0x00};
    int crlen = 32;
    uint8_t sign_cs[32] = {0x00};
    int cslen = 32;
    uint16_t digitalCerLen=586;
	  uint8_t  RecSafe[100]= {0};
    
    uint8_t hash[32] = {0x00};
	__disable_irq();  
    waitSafeRising();
    Delay_ms1(10);
    SPIx_Send_bytes(certif,6);
    waitSafeFalling();
    Delay_ms1(10);
    SPIx_Receive_bytes(RecSafe,6+8);
    if(RecSafe[4]==1)
    {
		    Result=true;
        memcpy(Rs,RecSafe+5,8);
        srand( (timeCnt++));
        for(i=0; i<8; i++)
        {
            Rm[i] = rand()%256;
        }
        memcpy(needsigndata,Rm,8);
        memcpy(needsigndata+8,Rs,8);
        memcpy(needsigndata+16,devNr,8);
        for(i=0; i<32; i++)
        {
            hash[i] = needsigndata[31-i];
        }
        sm2_sign(hash,32, sm2PrivKey,32, sign_cr, &crlen, sign_cs, &cslen);
        
        
        memcpy(cerbuf,needsigndata,32);
        pos += 32;
        
        for(i=0; i<32; i++)
        {
            signtemp[i] = sign_cr[31-i];
        }
        memcpy(cerbuf+pos,signtemp,32);
        pos += 32;
        for(i=0;i<32; i++)
        {
            signtemp[i] = sign_cs[31-i];
        }
        memcpy(cerbuf+pos,signtemp,32);
        pos += 32;
        memcpy(cerbuf+pos,digitalCer,digitalCerLen);
        pos += digitalCerLen;
        pframe1 = creatFrame(M2SEC_CER_FRAME,cerbuf,pos);
        sendFrameToSecure(pframe1);
        removeFrame(pframe1);
        waitSafeFalling();
        SPIx_Receive_bytes(RecSafe,10);
    }
    else
    {
      printf("rs fail\r\n");
			Result=false;
    }
    __enable_irq();
		return Result;
}

uint8_t CreateReadTagConfigFromMob(u8* buff_obj,u8* buff_source)
{
    buff_obj[0]=0xaa;
    buff_obj[1]=0x11;
    buff_obj[2]=0x09;
    buff_obj[3]=0;
    buff_obj[4]=0x06;
	if((buff_source[2]>=0x30)&&(buff_source[3]>=0x30)&&(buff_source[4]>=0x30))
	{
		buff_obj[5]=buff_source[2]-0x30 ;
		buff_obj[6]=buff_source[3]-0x30 ;
		buff_obj[7]=buff_source[4]-0x30 ;
	}
	else
	{
		buff_obj[5]=0 ;
		buff_obj[6]=0 ;
		buff_obj[7]=0 ;
	}
    buff_obj[8]=0x01;     //Ethan 读模式
    buff_obj[9]=0;
    buff_obj[10]=0;
    buff_obj[11]=0;
    buff_obj[12]=0;
    buff_obj[13]=XOR_Cal(&buff_obj[1],12);
    return 14;
}

uint8_t CreateReadTagConfigFromMob2(u8* buff_obj,u8* buff_source)
{
	uint8_t i;
	if(buff_source[2]==0x30)
	{
		buff_obj[0]=0xaa;
		buff_obj[1]=0x11;
		buff_obj[2]=0x09;
		buff_obj[3]=0;
		buff_obj[4]=0x06;
		buff_obj[5]=buff_source[2]-0x30 ;
		buff_obj[6]=buff_source[3]-0x30 ;
		buff_obj[7]=buff_source[4]-0x30 ;
		buff_obj[8]=0x01;
		buff_obj[9]=0;
		buff_obj[10]=0;
		buff_obj[11]=0;
		buff_obj[12]=0;
		buff_obj[13]=XOR_Cal(&buff_obj[1],12);
		return 14;
	}
	else if (buff_source[2]>=0x30)
	{
		buff_obj[0]=0xaa;
		buff_obj[1]=0x11;
		buff_obj[2]=9+(buff_source[2]-0x30-1)*7;
		buff_obj[3]=0;
		buff_obj[4]=0x06;
		buff_obj[5]=buff_source[2]-0x30 ;
		for(i=0;i<buff_obj[5];i++)
		{
			buff_obj[6+i*7]=buff_source[3+i*2];
			buff_obj[6+i*7+1]=buff_source[3+i*2+1];
			buff_obj[6+i*7+2]=1;
			buff_obj[6+i*7+3]=0;
			buff_obj[6+i*7+4]=0;
			buff_obj[6+i*7+5]=0;
			buff_obj[6+i*7+6]=0;
		}
		buff_obj[6+buff_obj[5]*7]=XOR_Cal(&buff_obj[1],6+buff_obj[5]*7-1);
		return (7+buff_obj[5]*7);
	}
	return 0;
}


uint8_t CreateReadTagConfig(u8* buff)
{
	
	  buff[0]=0xaa; //同步头 接收数据取值0xAA,上报数据取值0xAB
    buff[1]=0x11; //帧类型 0001 配置帧 0001版本号
    buff[2]=9;    //帧长度 9
    buff[3]=0;    //帧长度
    buff[4]=0x06; //帧内容 操作标识 （6）工作模式
    buff[5]=0;    //读分区数量 0 （表示识读TID工作模式，不读取任何分区数据）
    buff[6]=0x00; //分区号 user_0
    buff[7]=0x02; //分区访问指示 行标指令读取全区数据
    buff[8]=0x01; //0000 密文   0001 高速读
    buff[9]=0;    //
    buff[10]=0;
    buff[11]=0;
    buff[12]=0;
    buff[13]=XOR_Cal(&buff[1],12); //校验码
    return 14;
	
}

uint8_t CreateReaduser0TagConfig(u8* buff)
{
	//aa,11,09,00,06,01,00,02,01,00,00,00,00,1c
	  buff[0]=0xaa; //同步头 接收数据取值0xAA,上报数据取值0xAB
    buff[1]=0x11; //帧类型 0001 配置帧 0001版本号
    buff[2]=0x09;    //帧长度 9
    buff[3]=0x00;    //帧长度
    buff[4]=0x06; //帧内容 操作标识 （6）工作模式
    buff[5]=0x01;    //读分区数量 0 （表示识读TID工作模式，不读取任何分区数据）
    buff[6]=0x00; //分区号 user_0
    buff[7]=0x02; //分区访问指示 行标指令读取全区数据
    buff[8]=0x01; //0000 密文   0001 高速读
    buff[9]=0x00;    //
    buff[10]=0x00;
    buff[11]=0x00;
    buff[12]=0x00;
	  buff[13]=0x1c;
    return 14;
	
}
