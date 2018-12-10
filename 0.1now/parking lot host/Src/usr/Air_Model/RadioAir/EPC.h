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
extern uint8_t EPC_Response_Recv_Buf[200];
extern uint16_t EPC_ResponseRecvBits ;
extern uint16_t EPC_Recv_Byte_Index;
extern uint8_t EPC_Recv_Bit_Index;
extern uint8_t EPC_Temp_Recv_Byte;

extern uint8_t EPC_Recv_Stage;

extern uint8_t EPC_Response_Recv_Bufx[200];
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


//extern uint8_t EPC_Response_Recv_Bufx_Q[200];
//extern uint8_t EPC_Response_Recv_Buf_Q[200];
//extern uint8_t EPC_Recv_Bit_Indexx_Q;
//extern uint16_t EPC_Premablex_Q;
//extern uint8_t EPC_Recv_Stagex_Q;
//extern u32 EPC_periodx_Q;
//extern uint8_t EPC_Temp_Recv_Bytex_Q;
//extern uint16_t EPC_ResponseRecvBitsx_Q;
//extern uint16_t EPC_Recv_Byte_Indexx_Q;
//extern uint16_t EPC_ResponseRecvBits_Q;
//前项命令
#define ASK_DATA_PORT                           GPIOC        
#define ASK_DATA_PIN                            GPIO_Pin_4
#define ASK_DATA_CLK                            RCC_AHB1Periph_GPIOC



//前后相隔离
#define IFSW_CTR_PORT                           GPIOD        
#define IFSW_CTR_PIN                            GPIO_Pin_8
#define IFSW_CTR_CLK                            RCC_AHB1Periph_GPIOD

#define REAE_LED_A                              GPIOD
#define REAE_LED_A_PIN                          GPIO_Pin_12
#define REAE_LED_A_CLK                          RCC_AHB1Periph_GPIOD

#define Set_ASK_DATA()          ((ASK_DATA_PORT->BSRRL) = ASK_DATA_PIN)
#define Clr_ASK_DATA()          ((ASK_DATA_PORT->BSRRH) = ASK_DATA_PIN)




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
