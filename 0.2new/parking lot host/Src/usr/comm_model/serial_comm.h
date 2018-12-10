#ifndef SERIAL_COMM_H
#define SERIAL_COMM_H

#include "base_comm.h"


/**
 * @brief Serial_Comm::Serial_Comm
 * by lijin,2017.06.26,串口通信的类。继承Base_Comm。
 * 该类可直接用以进行RS232通信
 */

class Serial_Comm:public Base_Comm
{
public:
    Serial_Comm(int commid);
    ~Serial_Comm();
private:
    //unsigned char serialRecBuf[MAX_RX_LEN]; //用以接收数据的缓存区
		//unsigned char *serialRecBuf;	
		//int serialRecLen;
private:
    void clearRecBuf();
    unsigned short getCRC16(unsigned char *q, int len);
    llrp_u8v_t escapeMessage(unsigned char *buf,int len);
		bool deEscapeMessage(char* in,int in_len,char* out,int& out_len);
protected:
    bool isRecFinish();
    bool isSendReady();
public:
    bool openSerial(char *ttyName,int baud);
    void closeSerial();

protected:
    bool sendSerialData(unsigned char *message,int len);
public:	
		void run();
public:
    bool sendCommData(unsigned char *sendbuf,int sendlen);
    void startCommLink();
    void stopCommLink();
    int recvCommData(unsigned char *buf,int reclen);
public:

};

#endif // SERIAL_COMM_H
