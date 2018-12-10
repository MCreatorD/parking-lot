#ifndef __RX485_SEND_H
#define __RX485_SEND_H
#include "stm32f2xx.h"
#include "communication.h"
//#define RF     1
//#define MCU    2
//#define SAFE   4

#define RX485_MAX_TX_LEN 200
#define RX485_MAX_RX_LEN RX485_MAX_TX_LEN

typedef struct Message{
	int num;
	unsigned char Value[RX485_MAX_TX_LEN];
}Message;


	#ifdef __cplusplus
	 extern "C" {
	#endif

	//消息缓冲区
	extern u8  RX485_TxMessage[RX485_MAX_TX_LEN]; 
	extern u8  RX485_RxMessage[RX485_MAX_RX_LEN];


	//获取crc
	unsigned short getCRC16(unsigned char *q, int len);
 
	//对要发送的数据中的特殊字符进行转义处理
	Message escapeMessage(unsigned char *buf,int len);

  unsigned char sendSerialData(unsigned char sour_addr,unsigned char des_addr ,unsigned char cpu_rf ,unsigned char *message,int len);
  
	u8 sendCommData(unsigned char sour_addr,unsigned char des_addr ,unsigned char cpu_rf ,unsigned char *buf,int buflen);
  //主控CPU -> 从机CPU 
  void MCU_To_MCU(u8 slave_id,u8 cmd,u32 value);
	u8 SM_To_RF(u8 slave_id,u8 *data);
		 
	#ifdef __cplusplus
	}
	#endif
#endif
