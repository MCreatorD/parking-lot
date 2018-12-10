#ifndef MCUTOSECURECOMM1_H_
#define MCUTOSECURECOMM1_H_

#include "stm32f2xx_conf.h"
#include "stdbool.h"
#include "board.h"
#include "utility.h"


#define M2SEC_APPLYRS_FRAME 0
#define M2SEC_RESRS_FRAME 1
#define M2SEC_CER_FRAME 2
#define M2SEC_RESCER_FRAME 3
#define M2SEC_USERMSG_FRAME 4
#define M2SEC_SEC2CA_FRAME 5
#define M2SEC_LICENSE_FRAME 6
#define M2SEC_CERCHAIN_FRAME 7
#define M2SEC_RESACTIVE_FRAME 8
#define M2SEC_SET_FRAME   9
#define M2SEC_SETACK_FRAME 10
#define M2SEC_TAGDATA_FRAME 11



	
	#ifdef __cplusplus
	 extern "C" {
	#endif
		typedef __packed struct MCU_TO_SECURE_FRAME1
    {
        uint8_t Head;
        uint8_t Type;
        uint8_t DataLen[2];
        uint8_t OperId;
        uint8_t *DataBuf;
        uint8_t BCCCheck;
    } STRUCT_M2SEC_FRAME1;
		 
		 
		 
    void resetSecMod(void);
    void waitSafeFalling(void);
    void waitSafeRising(void);
    STRUCT_M2SEC_FRAME1 * creatFrame(int frametype,uint8_t *contentbuf,int contentlen);
    void removeFrame(STRUCT_M2SEC_FRAME1 *pframe);
    bool sendFrameToSecure(STRUCT_M2SEC_FRAME1 *pframe);
    STRUCT_M2SEC_FRAME1 *getFrameFromSecure(int frametype);
    uint8_t caluBCCCheck(STRUCT_M2SEC_FRAME1 *pframe);
    int getFrameContenLen(STRUCT_M2SEC_FRAME1 *pframe);
    int caluFrameLen(STRUCT_M2SEC_FRAME1 *pframe);
    void putFrameToBuf(STRUCT_M2SEC_FRAME1 *pframe,uint8_t *buf);
    STRUCT_M2SEC_FRAME1 * getFrameFromBuf(uint8_t *buf,int buflen);
	
	extern STRUCT_M2SEC_FRAME1 *pframe;
	
	bool Certificate(void);
	uint8_t CreateReadTagConfigFromMob(u8* buff_obj,u8* buff_source);
	uint8_t CreateReaduser0TagConfig(u8* buff);
		
	extern uint8_t CreateReadTagConfig(u8* buff);
	
	#ifdef __cplusplus
	}
	#endif	

#endif
