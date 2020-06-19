#include "serial_comm.h"
#include "uart_bsp_comm.h"


Serial_Comm::Serial_Comm(int commid)
                    :Base_Comm(commid)
{
	//选择通信串口

    //serialRecBuf = this->recFrameBuf;
	
}

Serial_Comm::~Serial_Comm(){
    this->closeSerial();
}

unsigned short Serial_Comm::getCRC16(unsigned char *q, int len)
{
    unsigned short const ccittTable[256] = {
    0x0000, 0x1021, 0x2042, 0x3063, 0x4084, 0x50A5, 0x60C6, 0x70E7,
    0x8108, 0x9129, 0xA14A, 0xB16B, 0xC18C, 0xD1AD, 0xE1CE, 0xF1EF,
    0x1231, 0x0210, 0x3273, 0x2252, 0x52B5, 0x4294, 0x72F7, 0x62D6,
    0x9339, 0x8318, 0xB37B, 0xA35A, 0xD3BD, 0xC39C, 0xF3FF, 0xE3DE,
    0x2462, 0x3443, 0x0420, 0x1401, 0x64E6, 0x74C7, 0x44A4, 0x5485,
    0xA56A, 0xB54B, 0x8528, 0x9509, 0xE5EE, 0xF5CF, 0xC5AC, 0xD58D,
    0x3653, 0x2672, 0x1611, 0x0630, 0x76D7, 0x66F6, 0x5695, 0x46B4,
    0xB75B, 0xA77A, 0x9719, 0x8738, 0xF7DF, 0xE7FE, 0xD79D, 0xC7BC,
    0x48C4, 0x58E5, 0x6886, 0x78A7, 0x0840, 0x1861, 0x2802, 0x3823,
    0xC9CC, 0xD9ED, 0xE98E, 0xF9AF, 0x8948, 0x9969, 0xA90A, 0xB92B,
    0x5AF5, 0x4AD4, 0x7AB7, 0x6A96, 0x1A71, 0x0A50, 0x3A33, 0x2A12,
    0xDBFD, 0xCBDC, 0xFBBF, 0xEB9E, 0x9B79, 0x8B58, 0xBB3B, 0xAB1A,
    0x6CA6, 0x7C87, 0x4CE4, 0x5CC5, 0x2C22, 0x3C03, 0x0C60, 0x1C41,
    0xEDAE, 0xFD8F, 0xCDEC, 0xDDCD, 0xAD2A, 0xBD0B, 0x8D68, 0x9D49,
    0x7E97, 0x6EB6, 0x5ED5, 0x4EF4, 0x3E13, 0x2E32, 0x1E51, 0x0E70,
    0xFF9F, 0xEFBE, 0xDFDD, 0xCFFC, 0xBF1B, 0xAF3A, 0x9F59, 0x8F78,
    0x9188, 0x81A9, 0xB1CA, 0xA1EB, 0xD10C, 0xC12D, 0xF14E, 0xE16F,
    0x1080, 0x00A1, 0x30C2, 0x20E3, 0x5004, 0x4025, 0x7046, 0x6067,
    0x83B9, 0x9398, 0xA3FB, 0xB3DA, 0xC33D, 0xD31C, 0xE37F, 0xF35E,
    0x02B1, 0x1290, 0x22F3, 0x32D2, 0x4235, 0x5214, 0x6277, 0x7256,
    0xB5EA, 0xA5CB, 0x95A8, 0x8589, 0xF56E, 0xE54F, 0xD52C, 0xC50D,
    0x34E2, 0x24C3, 0x14A0, 0x0481, 0x7466, 0x6447, 0x5424, 0x4405,
    0xA7DB, 0xB7FA, 0x8799, 0x97B8, 0xE75F, 0xF77E, 0xC71D, 0xD73C,
    0x26D3, 0x36F2, 0x0691, 0x16B0, 0x6657, 0x7676, 0x4615, 0x5634,
    0xD94C, 0xC96D, 0xF90E, 0xE92F, 0x99C8, 0x89E9, 0xB98A, 0xA9AB,
    0x5844, 0x4865, 0x7806, 0x6827, 0x18C0, 0x08E1, 0x3882, 0x28A3,
    0xCB7D, 0xDB5C, 0xEB3F, 0xFB1E, 0x8BF9, 0x9BD8, 0xABBB, 0xBB9A,
    0x4A75, 0x5A54, 0x6A37, 0x7A16, 0x0AF1, 0x1AD0, 0x2AB3, 0x3A92,
    0xFD2E, 0xED0F, 0xDD6C, 0xCD4D, 0xBDAA, 0xAD8B, 0x9DE8, 0x8DC9,
    0x7C26, 0x6C07, 0x5C64, 0x4C45, 0x3CA2, 0x2C83, 0x1CE0, 0x0CC1,
    0xEF1F, 0xFF3E, 0xCF5D, 0xDF7C, 0xAF9B, 0xBFBA, 0x8FD9, 0x9FF8,
    0x6E17, 0x7E36, 0x4E55, 0x5E74, 0x2E93, 0x3EB2, 0x0ED1, 0x1EF0
    };
    unsigned short crc = 0;
    while (len-- > 0)
    crc = ccittTable[(crc >> 8 ^ *q++) & 0xff] ^ (crc << 8);
    //return ~crc;
	return crc;
}

/**
 * @brief Serial_Comm::escapeMessage
 * @param buf
 * @param len
 * @return
 * 对要发送的数据中的特殊字符进行转义处理
 */
llrp_u8v_t  Serial_Comm::escapeMessage(unsigned char *buf,int len)
{
    unsigned char escapebuf[2*(MAX_TX_LEN+4)]; //转义后的字节流大小按每个字节都需转义的最大需求考虑
    int index = 0;
    for(int i=0;i<len;i++)
    {
        if(buf[i] == 0x7E)
        {
            escapebuf[index++] = 0x7D;
            escapebuf[index++] = 0x5E;
        }
        else if(buf[i] == 0x7D)
        {
            escapebuf[index++] = 0x7D;
            escapebuf[index++] = 0x5D;
        }
        else
        {
            escapebuf[index++] = buf[i];
        }
    }
    llrp_u8v_t res = llrp_u8v_t(index);
    memcpy(res.m_pValue,escapebuf,res.m_nValue);
    return res;
}

bool Serial_Comm::openSerial(char *ttyName,int baud)
{

}

void Serial_Comm::closeSerial()
{

}

bool Serial_Comm::sendSerialData(unsigned char *message,int len){
    //int messagelen = len;
		unsigned char serialmessage[MAX_TX_LEN+4];
    int posi = 0;
    serialmessage[posi++] = 0x00; //源地址暂定为全0
    serialmessage[posi++] = 0xFF; //目的地址暂定为全 1
    memcpy(serialmessage+posi,message,len);
    unsigned short crc16 = this->getCRC16(serialmessage,len+posi);
    posi += len;
    serialmessage[posi++] = crc16>>8;
    serialmessage[posi++] = crc16;
    llrp_u8v_t escapedata = this->escapeMessage(serialmessage,posi);
    //printf("escapedata.m_nValue=%d\n",escapedata.m_nValue);

    unsigned char senddata[MAX_TX_LEN+2];
    senddata[0] = 0x7E; //加上帧头
    memcpy(senddata+1,escapedata.m_pValue,escapedata.m_nValue);
    senddata[escapedata.m_nValue+1] = 0x7E; //加上帧尾

    //串口为非阻塞式写，所以返回的字节数不一定等要发送的字节数
    //int res = write(m_SerialFd,senddata,sizeof(senddata));
	
		int res = CommUSARTx_SendData(senddata,escapedata.m_nValue+2);		
    //printf("sendlen= %d\n",sendlen,res,posi);
    if(res<0){
        return false;
    }
    //printf("send serial data finish!\n");
    return true;
}

bool Serial_Comm::isSendReady()
{
	if(Comm_USART_TX_IDLE==1){
		return false;
	}else{
		return true;
	}
}

bool Serial_Comm::isRecFinish()
{
		if(Comm_USART_RX_STA==1){
		return true;
	}else{
		return false;
	}
}

void Serial_Comm::clearRecBuf(){

}

void Serial_Comm::startCommLink(){

}

/**
 * @brief Serial_Comm::stopCommLink
 */
void Serial_Comm::stopCommLink(){

}

/**
*	反转义    头尾0x7E 数据中有7E 换成7D 5e,那有数据7D 换成0x7D 0x5D
*/
bool Serial_Comm::deEscapeMessage(char* in,int in_len,char* out,int& out_len)
{
    if(in[0] == 0x7E && in[in_len - 1] == 0x7E)//校验数据头尾
    {
			out_len = 0;
			//以下将对特殊字符的转义反转过来
			for(int i = 1; i < in_len-1; i++) //数据
			{
					unsigned char c = in[i];
					if(c == 0x7D)
					{
							if(in[i + 1] == 0x5E)
							{
									out[out_len++] = 0x7E; //连续的0x7D 0x5e 反转义成7E 
									i += 1;
							}
							else if(in[i + 1] == 0x5D)
							{
									out[out_len++] = 0x7D; //连续的0x7D 0x5D 反转义成7D
									i += 1;
							}
							else
							{
									out[out_len++] = c;
							}
					}
					else
					{
							out[out_len++] = c;
					}
			}			

			//转意 后最后一位 和倒数第二位是 crc校验位			
      unsigned short crc = out[out_len-2]<<8|((out[out_len-1])) ;
			//不包含传输数据的头尾  0x7E
			unsigned short crc_get = getCRC16((unsigned char*)out,(int)(out_len-2)); //最后两个字节的CRC码不在计算范围内
			
			//发送过来的和接收数据运算得到的 crc 进行比较
			if(crc != crc_get) {
					return false;
			}
			//把转义后的前两个字节去除，即串口通信帧中，加上的目标地址和源地址去除。
			memmove(out,out+2,out_len-2);
			out_len = out_len - 2;
			return true;
    }
    else
    {   
        return false;
    }
}

int Serial_Comm::recvCommData(unsigned char *buf,int reclen){
		
		unsigned char out_buf[MAX_RX_LEN];
		int out_len = 0;
		bool ok = this->deEscapeMessage((char*)buf,reclen,(char*)out_buf,out_len);
		if(ok == true) {
			memcpy(this->recFrameBuf,out_buf,out_len);
			this->recFrameLen = out_len;
	
			Comm_USART_RX_STA = 0;
			this->m_ReadyForRecv = true;
			return  0;
		}else{
			Comm_USART_RX_STA = 0;
			this->m_ReadyForRecv = false;
			this->recFrameLen = 0;
			return -1;
		}
}

bool Serial_Comm::sendCommData(unsigned char *buf,int buflen){

    if(this->isSendReady()==false){
        printf("Serial comm is not ready!\n");
        return false;
    }
        //printf("Serial comm is ready!\n");
  
    bool res = this->sendSerialData(buf,buflen);
	  //printf("sendSerialData(buf,buflen) is ready!\n");
    return res;
}

void Serial_Comm::run(){

		 if(this->isRecFinish()==true){
			 			 this->recvCommData(Comm_USART_RX_BUF,Comm_RX_Len); 
		 }
	
     Base_Comm::run();
}


