#include "operationspec_execute_gb.h"
#include <stdio.h>

#include "general_functions.h"

#include "systick.h"

#include "buzzer_led.h"

Operationspec_Execute_GB::Operationspec_Execute_GB()
{
	m_pGBRfOper = (Rf_Oper_GB *)m_pRfOper;
}

Operationspec_Execute_GB::~Operationspec_Execute_GB()
{
}

MCU_TO_SECURE_FRAME *Operationspec_Execute_GB::convertGBFrameToHBSelectFrame(STRUCT_RF2M_FRAME* pGBFrame,CRfSpec *pRfSpec){

    if(pGBFrame==NULL){
        return NULL;
    }
    if(pGBFrame->Head[0]==0x80&&(pGBFrame->Head[1]==0x01||pGBFrame->Head[1]==0x00)){//是读或盘点标签
	
    if(pGBFrame->SuccessMark[1]!=1){ //是错误标志则简单返回空
        //printf("read is error!\n");
        return NULL;
    }

    MCU_TO_SECURE_FRAME *pframe = new MCU_TO_SECURE_FRAME;
    pframe->Head = 0xab;
    pframe->Type = 0x52;

    //以下由国标生成行标数据
    unsigned int buflen = 0;
   //printf("pGBFrame->DataLen[0]=%d,DataLen[1]=%d\n",pGBFrame->DataLen[0],pGBFrame->DataLen[1]);
       buflen = pGBFrame->DataLen[0]<<8|pGBFrame->DataLen[1];
      //printf("buflen=%d\n",buflen);
       unsigned char *buf = new unsigned char[buflen];
       memcpy(buf,pGBFrame->DataBuf,buflen);

//    /////////////////////////////////////////
//    if(pRfSpec->getSelectType()==0){
//        pframe->OperId = 0x01; //设为行标的盘点模式。
//    }else{
//        pframe->OperId = 0x02; //设为行标读模式。
//    }
        if(pGBFrame->Head[1]==0x01){//是读
            pframe->OperId = 0x02;
        }else{
            pframe->OperId = 0x01;
        }
        int tidlen = buf[0]*2 + 2; //注意，字长要换算为字节长，tidlen包括长度的2个字节
    unsigned int datalen = buflen+17+2- tidlen - 2; //数据长度要减去tidlen和数据长度字段的2个字节
    pframe->DataLen[0] = datalen;
    pframe->DataLen[1] = datalen>>8;

    datalen = datalen - 1; //数据区应去除OperId的字节数,并加上成功标志字节
    pframe->DataBuf = new unsigned char[datalen];
    int posi = 0;
    pframe->DataBuf[posi++] = 0x00; //成功标志
//    memset(pframe->DataBuf+posi,0x00,8); //因为国标TID和行标TID长度不一，故将国标全部数据都放入数据区，这里的TID则全填0。
     if(tidlen>=8){
     	memcpy(pframe->DataBuf+posi,buf+2,8); //不管读到的TID是多少，只取前8个字节
	    posi = posi + 8;
        }else{
            memcpy(pframe->DataBuf+posi,buf+2,tidlen);
            posi = posi + tidlen;
            int a = 8-tidlen;
            for(int i=0;i<a;i++){
                pframe->DataBuf[posi++] = 0x00; //不足的TID要补零
            }
        }
    unsigned char temp = pGBFrame->AntId[1];
	    unsigned char a = 0<<4; // 分区号
		   unsigned char b = 0<<2; //分区访问标识
    pframe->DataBuf[posi++] = temp|a|b;

    unsigned long long utc = General_Functions::getCurrentUTC();
    pframe->DataBuf[posi++] = utc>>56;
    pframe->DataBuf[posi++] = utc>>48;
    pframe->DataBuf[posi++] = utc>>40;
    pframe->DataBuf[posi++] = utc>>32;
    pframe->DataBuf[posi++] = utc>>24;
    pframe->DataBuf[posi++] = utc>>16;
    pframe->DataBuf[posi++] = utc>>8;
    pframe->DataBuf[posi++] = utc;



        if(buflen>=tidlen+2){ //用户区有数据
            int userlen = buf[tidlen]<<8|buf[tidlen+1]; //单位是字 //取出GB用户区数据长度
            //printf("userlen=%d,buflen=%d,tidlen=%d\n",userlen,buflen,tidlen);
            if(userlen*2<=buflen-2-tidlen){ //用户区数据长度应和buflen减去tidlen和长度字节后的长度相等
                memcpy(pframe->DataBuf+posi,buf+tidlen+2,userlen*2);

            }
        }
        delete [] buf;

        return pframe;
    }else if(pGBFrame->Head[0]==0x80&&pGBFrame->Head[1]==0x02){ //是写标签
        MCU_TO_SECURE_FRAME *pframe = new MCU_TO_SECURE_FRAME;
        pframe->Head = 0xab;
        pframe->Type = 0x52;

        //以下由国标生成行标数据
        unsigned int buflen = 0;
        //printf("pGBFrame->DataLen[0]=%d,DataLen[1]=%d\n",pGBFrame->DataLen[0],pGBFrame->DataLen[1]);
           buflen = pGBFrame->DataLen[0]<<8|pGBFrame->DataLen[1];
           //printf("buflen=%d\n",buflen);
           unsigned char *buf = new unsigned char[buflen];
           memcpy(buf,pGBFrame->DataBuf,buflen);

    //       printf("readed GB data is: ");
    //       for(int i=0;i<buflen;i++){
    //           printf("0x%02x,",buf[i]);
    //       }
    //       printf("\n");

        /////////////////////////////////////////

        //pframe->OperId = 0x01; //设为行标的盘点模式。
        pframe->OperId = 0x02; //设为行标的读模式


        int tidlen = buf[0]*2 + 2; //注意，字长要换算为字节长，tidlen包括长度的2个字节

        unsigned int datalen = buflen + 17+2 - tidlen - 2; //数据长度要减去tidlen和数据长度字段的2个字节
        pframe->DataLen[0] = datalen;
        pframe->DataLen[1] = datalen>>8;

        datalen = datalen - 1; //数据区应去除OperId的字节数,并加上成功标志字节
        pframe->DataBuf = new unsigned char[datalen];
        int posi = 0;
        pframe->DataBuf[posi++] = 0x00; //成功标志
        //memset(pframe->DataBuf+posi,0x00,8); //因为国标TID和行标TID长度不一，故将国标全部数据都放入数据区，这里的TID则全填0。

        if(tidlen>=8){
            memcpy(pframe->DataBuf+posi,buf+2,8); //不管读到的TID是多少，只取前8个字节
            posi = posi + 8;
        }else{
            memcpy(pframe->DataBuf+posi,buf+2,tidlen);
            posi = posi + tidlen;
        }
        unsigned char temp = pGBFrame->AntId[1];
        unsigned char a = 0<<4; // 分区号
        unsigned char b = 0<<2; //分区访问标识
        pframe->DataBuf[posi++] = temp|a|b;

        unsigned long long utc = General_Functions::getCurrentUTC();
        pframe->DataBuf[posi++] = utc>>56;
        pframe->DataBuf[posi++] = utc>>48;
        pframe->DataBuf[posi++] = utc>>40;
        pframe->DataBuf[posi++] = utc>>32;
        pframe->DataBuf[posi++] = utc>>24;
        pframe->DataBuf[posi++] = utc>>16;
        pframe->DataBuf[posi++] = utc>>8;
        pframe->DataBuf[posi++] = utc;


        if(buflen>=tidlen+2){ //用户区有数据
            int userlen = buf[tidlen]<<8|buf[tidlen+1]; //单位是字 //取出GB用户区数据长度
            //printf("userlen=%d,buflen=%d,tidlen=%d\n",userlen,buflen,tidlen);
            if(userlen*2<=buflen-2-tidlen){ //用户区数据长度应和buflen减去tidlen和长度字节后的长度相等
                memcpy(pframe->DataBuf+posi,buf+tidlen+2,userlen*2);
            }
        }
        delete [] buf;

        return pframe;
    }
}







MCU_TO_SECURE_FRAME *Operationspec_Execute_GB::convertGBFrameToHBAccessFrame(STRUCT_RF2M_FRAME* pGBFrame,CRfSpec *pRfSpec){

    if(pGBFrame==NULL){
        return NULL;
    }

    if(pGBFrame->Head[0]==0x80&&(pGBFrame->Head[1]==0x01||pGBFrame->Head[1]==0x00)){//是读标签
    if(pGBFrame->SuccessMark[1]!=1){ //是错误标志则简单返回空
        //printf("read is error!\n");
        return NULL;
    }

    MCU_TO_SECURE_FRAME *pframe = new MCU_TO_SECURE_FRAME;
    pframe->Head = 0xab;
    pframe->Type = 0x52;

    //以下由国标生成行标数据
    unsigned int buflen = 0;
    //printf("pGBFrame->DataLen[0]=%d,DataLen[1]=%d\n",pGBFrame->DataLen[0],pGBFrame->DataLen[1]);
       buflen = pGBFrame->DataLen[0]<<8|pGBFrame->DataLen[1];
       //printf("buflen=%d\n",buflen);
       unsigned char *buf = new unsigned char[buflen];
       memcpy(buf,pGBFrame->DataBuf,buflen);

//       printf("readed GB data is: ");
//       for(int i=0;i<buflen;i++){
//           printf("0x%02x,",buf[i]);
//       }
//       printf("\n");

    /////////////////////////////////////////
    if(pRfSpec->getSelectType()==0){
        pframe->OperId = 0x01; //设为行标的盘点模式。
    }else{
        pframe->OperId = 0x02; //设为行标读模式。
    }

    int tidlen = buf[0]*2 + 2; //注意，字长要换算为字节长，tidlen包括长度的2个字节

    unsigned int datalen = buflen + 17+2 - tidlen - 2; //数据长度要减去tidlen和数据长度字段的2个字节
    pframe->DataLen[0] = datalen;
    pframe->DataLen[1] = datalen>>8;

    datalen = datalen - 1; //数据区应去除OperId的字节数,并加上成功标志字节
    pframe->DataBuf = new unsigned char[datalen];
    int posi = 0;
    pframe->DataBuf[posi++] = 0x00; //成功标志
    //memset(pframe->DataBuf+posi,0x00,8); //因为国标TID和行标TID长度不一，故将国标全部数据都放入数据区，这里的TID则全填0。

    if(tidlen>=8){
        memcpy(pframe->DataBuf+posi,buf+2,8); //不管读到的TID是多少，只取前8个字节
        posi = posi + 8;
    }else{
        memcpy(pframe->DataBuf+posi,buf+2,tidlen);
        posi = posi + tidlen;
    }
    unsigned char temp = pGBFrame->AntId[1];
    unsigned char a = 0<<4; // 分区号
    unsigned char b = 0<<2; //分区访问标识
    pframe->DataBuf[posi++] = temp|a|b;

    unsigned long long utc = General_Functions::getCurrentUTC();
    pframe->DataBuf[posi++] = utc>>56;
    pframe->DataBuf[posi++] = utc>>48;
    pframe->DataBuf[posi++] = utc>>40;
    pframe->DataBuf[posi++] = utc>>32;
    pframe->DataBuf[posi++] = utc>>24;
    pframe->DataBuf[posi++] = utc>>16;
    pframe->DataBuf[posi++] = utc>>8;
    pframe->DataBuf[posi++] = utc;


    if(buflen>=tidlen+2){ //用户区有数据
        int userlen = buf[tidlen]<<8|buf[tidlen+1]; //单位是字 //取出GB用户区数据长度
        //printf("userlen=%d,buflen=%d,tidlen=%d\n",userlen,buflen,tidlen);
        if(userlen*2<=buflen-2-tidlen){ //用户区数据长度应和buflen减去tidlen和长度字节后的长度相等
            memcpy(pframe->DataBuf+posi,buf+tidlen+2,userlen*2);

        }
    }
    delete [] buf;

    return pframe;
    }else if(pGBFrame->Head[0]==0x80&&pGBFrame->Head[1]==0x02){ //是写标签
        MCU_TO_SECURE_FRAME *pframe = new MCU_TO_SECURE_FRAME;
        pframe->Head = 0xaa;
        pframe->Type = 0xb2;
        pframe->OperId = 0x00; //写分区请求响应
        if(pGBFrame->SuccessMark[1]==0x01){//成功
            pframe->DataLen[1] = 0x00;
            pframe->DataLen[0] = 0x01;
            pframe->DataBuf = new unsigned char[1];
            pframe->DataBuf[0] = 0x00;
        }else{//失败
            pframe->DataLen[1] = 0x00;
            pframe->DataLen[0] = 0x02;
            pframe->DataBuf = new unsigned char[2];
            pframe->DataBuf[0] = 0x02;
            pframe->DataBuf[1] = 0x00;
        }
        pframe->BCCCheck = 0x00;
        return pframe;
    }
}



bool Operationspec_Execute_GB::singleSelectAccess(Tag_SelectSpec *pTagSelectSpec,Tag_AccessSpec *pTagAccessSpec,CAntennaSpec *pAntennaSpec,llrp_u16_t antSpecIndex,CRfSpec *pRfSpec){


}

void Operationspec_Execute_GB::run(){
	OperationSpec_Execute_Base::run();
}
