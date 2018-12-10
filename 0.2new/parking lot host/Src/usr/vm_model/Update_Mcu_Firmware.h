#ifndef __UPDATE_MCU_FIRMWARE
#define __UPDATE_MCU_FIRMWARE
#include "stm32f2xx.h"

#define updatedev_hostmcu  0x22
#define updatedev_slovemcu 0x33


//���1M�洢�����ļ�
//FLASH_SIZE      =32*1024*1024   //FLASH ��СΪ32M�ֽ�  ����4k����
//Dev_version_flag 31*1024*1024 = 32505856 
#define bin_flag        32505856-25 //ռ1���ֽڳ����ļ�������־λ	0x0A:���� 00:������
#define bin_size        bin_flag+1  //ռ4���ֽ�
#define bin_name        bin_size+4  //ռ20���ֽ�
#define bin_start       bin_name+20  //�����ļ���ʼ��ַ32505856  ��֤��ʼ��ַ4K����Ч�ʸ���

#define update_length   1024

/*״̬��־*/
#define flash_Isok      0x0A
#define flash_Notok     0x00
extern uint32_t FlashSource;

class Update_Mcu_Firmware{

	public:
		bool sendFrameToHostmcu(unsigned char *packet_data ,uint16_t pack_len);
	  void FLASH_Message(uint32_t Size,char *Name , uint8_t Flag);
		bool sendUpdateBlockToMcu(unsigned char dev,unsigned char *contentbuf,unsigned int contentlen);
};

#endif