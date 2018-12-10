#ifndef __RX485_SEND_H
#define __RX485_SEND_H
#include "stm32f2xx.h"


#define RF     1
#define MCU    2
#define SAFE   4

#define MAX_TX_LEN 256
#define MAX_RX_LEN MAX_TX_LEN

typedef struct {
	int num;
	unsigned char Value[MAX_TX_LEN];
}Message;


	#ifdef __cplusplus
	 extern "C" {
	#endif

	//消息缓冲区
	extern u8  TxMessage[MAX_TX_LEN]; 
	extern u8 RxMessage[MAX_RX_LEN];


	//获取crc
	unsigned short getCRC16(unsigned char *q, int len);
 
	//对要发送的数据中的特殊字符进行转义处理
	Message escapeMessage(unsigned char *buf,int len);

  unsigned char sendSerialData(unsigned char sour_addr,unsigned char des_addr ,unsigned char cpu_rf,unsigned char *message,int len);
  
	u8 sendCommData(unsigned char sour_addr,unsigned char des_addr ,unsigned char cpu_rf,unsigned char *buf,int buflen);
  //主控CPU -> 从机CPU 
  void MCU_To_MCU(u8 slave_id,u8 cmd);
	u8 RF_To_SM(u8 bCommand,u8 *data,u8 timeout);//u8 bCommand,u8 *data,u8 timeout 
	#ifdef __cplusplus
	}
	#endif
#endif
