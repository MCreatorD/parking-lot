#ifndef __EPC_H
#define __EPC_H

#ifdef __cplusplus
 extern "C" {
#endif

#include "stm32f2xx.h"

extern uint8_t  EPC_RN[2];
extern uint8_t  EPC_RN1[2];
extern uint8_t  EPC_RN2[2];

extern uint8_t  EPC_Send_Buf[16];
extern uint8_t EPC_BitsToSend;
extern uint8_t TRcal_timer;
extern uint8_t EPC_CRC[2];
extern uint8_t EPC_Response_Recv_Buf[512];
extern uint16_t EPC_ResponseRecvBits ;
extern uint16_t EPC_Recv_Byte_Index;
extern uint8_t EPC_Recv_Bit_Index;
extern uint8_t EPC_Temp_Recv_Byte;

extern uint8_t EPC_Recv_Stage;
extern uint8_t EPC_Recv_Bit_Indexx;
extern uint8_t EPC_Temp_Recv_Bytex;

extern uint8_t EPC_Response_Recv_Bufx[512];
extern uint16_t EPC_ResponseRecvBitsx ;
extern uint16_t EPC_Recv_Byte_Indexx;
extern uint8_t EPC_Recv_Bit_Indexx;
extern uint8_t EPC_Temp_Recv_Bytex;

extern uint8_t EPC_Recv_Stagex;
extern uint16_t EPC_Premablex;
extern u32 EPC_periodx;
extern uint16_t EPC_Return_Link_Bits;
extern uint16_t EPC_Premable;
extern u32 EPC_period;

#define Set_ASK_DATA()          ((GPIOC->BSRRL) = GPIO_Pin_4)
#define Clr_ASK_DATA()          ((GPIOC->BSRRH) = GPIO_Pin_4)
//#define Set_RFOUT_DATA()        ((GPIOD->BSRRL) = GPIO_Pin_2)
//#define Clr_RFOUT_DATA()        ((GPIOD->BSRRH) = GPIO_Pin_2)

#define IFSW_CTR_PORT                           GPIOB        //«∞∫Ûœ‡∏Ù¿Î
#define IFSW_CTR_PIN                            GPIO_Pin_15

//#define LOSLT_PORT                            GPIOA
//#define LOSLT_PIN                             GPIO_Pin_2

#define _6D_TIME_8TC      7
#define _6D_TIME_2TC      1
#define _6D_TIME_3TC      2
#define _6D_TIME_4TC      3
#define _6D_TIME_5TC      4

void StuffSendBuf(unsigned char Data, unsigned char len);
void ClearSendBuf(unsigned char *Buff, unsigned char len);
void Send_Delimiter(void);
void Send_Data(uint16_t Time);
void EPC_SendCommand(void);
void EPC_IO_Configure(void);

#ifdef __cplusplus
}
#endif
 
#endif
