#ifndef __6D_H
#define __6D_H

#ifdef __cplusplus
 extern "C" {
#endif
	 
#include "stm32f2xx.h"
	 
#define _6D_TIME_8TC      7
#define _6D_TIME_2TC      1
#define _6D_TIME_3TC      2
#define _6D_TIME_4TC      3
#define _6D_TIME_5TC      4
#define _6D_CMD_Sort            0xAA
#define _6D_CMD_Query           0xA4
#define _6D_CMD_QueryRep        0x00
#define _6D_CMD_Divide          0x03
#define _6D_CMD_Disperse        0x08
#define _6D_CMD_Shrink          0x09
#define _6D_CMD_ACK             0x01
#define _6D_CMD_NAK             0xAF
#define _6D_CMD_RefreshRN       0xB4
#define _6D_CMD_Get_RN          0xB2
#define _6D_CMD_Access          0xA3
#define _6D_CMD_Read            0xA5
#define _6D_CMD_Write           0xA6
#define _6D_CMD_Erase           0xA7
#define _6D_CMD_Lock            0xA8
#define _6D_CMD_Kill            0xA9
#define _6D_CMD_Get_SecPara     0xAE
#define _6D_CMD_Req_XAuth       0xB5
#define _6D_CMD_XAuth           0xB6
#define _6D_CMD_Get_XAuth       0xB7
#define _6D_CMD_Req_XAuth_Ex    0xB8
#define _6D_CMD_Req_SAuth       0xA0
#define _6D_CMD_SAuth           0xB3
#define _6D_CMD_Get_SAuth       0xAC
#define _6D_CMD_Mul_SAuth       0xA1
#define _6D_CMD_Sec_Com         0xAD
#define _6D_MEM_TID            0x00
#define _6D_MEM_CODE           0x10
#define _6D_MEM_SAFE           0x20
#define _6D_MEM_USER_0         0x30
#define _6D_MEM_USER_1         0x31
#define _6D_MEM_USER_2         0x32
#define _6D_MEM_USER_3         0x33
#define _6D_MEM_USER_4         0x34
#define _6D_MEM_USER_5         0x35
#define _6D_MEM_USER_6         0x36
#define _6D_MEM_USER_7         0x37
#define _6D_MEM_USER_8         0x38
#define _6D_MEM_USER_9         0x39
#define _6D_MEM_USER_A         0x3A
#define _6D_MEM_USER_B         0x3B
#define _6D_MEM_USER_C         0x3C
#define _6D_MEM_USER_D         0x3D
#define _6D_MEM_USER_E         0x3E
#define _6D_MEM_USER_F         0x3F


#define GL_OK                      0x01
#define GL_ERROR                   0x00
#define GL_CRC_ERROR               0x03
#define GL_TRANSFER_ERROR          0x04
#define GL_NO_TAG                  0x05
#define GL_RN16_OK                 0x08
#define GL_OVER                    0x0A

#define IRQDisable()                        //__disable_irq();
#define IRQEnable()                         //__enable_irq();

void _6D_Sort(uint8_t MemBank,uint8_t Target,uint8_t Action,uint8_t *BitPointer,uint8_t BitLength,uint8_t* Mask);
void _6D_Query(uint8_t Sel,uint8_t Session,uint8_t Target,uint8_t TRext,uint8_t DR,uint8_t M);
void _6D_QueryRep(uint8_t Session);
void _6D_QueryRep(uint8_t Session);
void _6D_Divide(uint8_t Address,uint8_t Session);
void _6D_Disperse(uint8_t Session);
void _6D_Shrink(uint8_t Session);
void _6D_ACK(uint8_t* Handle);
void _6D_NAK(void);
void _6D_RefreshRN(uint8_t *Handle);
void _6D_Get_RN(uint8_t *handle);
void _6D_Access(uint8_t MemBank,uint8_t PassType, const uint8_t *Password,const uint8_t *RN, uint8_t *Handle);
void _6D_Read(uint8_t MemBank,uint8_t *WordPointer,uint8_t* Count,uint8_t *Handle);
void _6D_Write(uint8_t MemBank,uint8_t *WordPointer,uint8_t* Count,uint8_t *Data,uint8_t *Handle);
void _6D_Erase(uint8_t MemBank,uint8_t *WordPointer,uint8_t* Count,uint8_t *Handle);
void _6D_Lock(uint8_t MemBank,uint8_t Config,uint8_t Action,uint8_t *Handle);
void _6D_Kill(uint8_t *Handle);
void Get_SecPara(int8_t *Handle);
void Req_XAuth(int8_t *Handle);
void XAuth(void);
void Get_XAuth(void);
void Req_XAuth_Ex(void);
void Req_SAuth(void);
void SAuth(void);
void Get_SAuth(void);
void Mul_SAuth(void);
void Sec_Com(void);
void Send_Delimiter1(void);
void _6D_TOKEN1(uint8_t *data);
void _6D_TOKEN2(uint8_t *data);
void _6D_TOKEN3(uint8_t *data);
uint8_t _6D_RN16_FM0Decode(void);
uint8_t _6D_FM0Decode1(void);
uint8_t _6D_FM0Decode(void);
uint8_t _6D_TOKEN1Decode(void);
uint8_t _6D_TOKEN2Decode(void);
uint8_t _6D_TOKEN3Decode(void);
uint8_t _6D_MyFM0Decode(uint32_t iTimeOut,uint8_t bType);
uint8_t _6D_MyFM0Decode1(uint32_t iTimeOut,uint8_t bType);
uint8_t _6D_EPC_ReadOnlyOne_Protcol(unsigned char RFSwitchoffFlag);
uint8_t _6D_EPC_ReadMulti_Protcol(unsigned char RFSwitchoffFlag,unsigned short int rfpower);
uint8_t _6D_TEST_EPC_ReadOnlyOne_Protcol(void);
uint8_t _6D_EPC_Read_Protcol(unsigned char RFSwitchoffFlag,unsigned char MemBank, unsigned char *WordPtr, unsigned char WordCount);
uint8_t _6D_EPC_WriterOnlyOne_Protcol(unsigned char RFSwitchoffFlag,unsigned char MemBank, unsigned char *WordPtr, unsigned char *Data);
uint8_t _6D_EPC_Write_Protcol(unsigned char RFSwitchoffFlag,unsigned char MemBank, unsigned char *WordPtr, unsigned char *Data,unsigned char WordCount)  ;
uint8_t _6D_EPC_LockTag_Protcol(uint8_t RFSwitchoffFlag,uint8_t MemBank,uint8_t Config,uint8_t Action);
//uint8_t _6D_EPC_KillTag_Protcol(unsigned char RFSwitchoffFlag,unsigned char RFU_Buff, unsigned char Password1, unsigned char Password2,unsigned char Password3,unsigned char Password4);
//uint8_t _6D_EPC_EraseTag_Protcol(unsigned char RFSwitchoffFlag,unsigned char MemBank, unsigned char *WordPtr, unsigned char *Data,unsigned char WordCount);
//uint8_t _6D_EPC_AccessTag_Protcol(unsigned char RFSwitchoffFlag,unsigned char MemBank,unsigned char PassType,unsigned char *Password)   ;

uint8_t ReadTag(unsigned short int rfpower);

extern uint8_t channelSwitchCount;



#ifdef __cplusplus
}
#endif

#endif

