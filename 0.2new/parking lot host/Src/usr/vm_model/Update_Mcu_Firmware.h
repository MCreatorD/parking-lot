#ifndef __UPDATE_MCU_FIRMWARE
#define __UPDATE_MCU_FIRMWARE
#include "stm32f2xx.h"

#define updatedev_hostmcu  0x22
#define updatedev_slovemcu 0x33


//最后1M存储程序文件
//FLASH_SIZE      =32*1024*1024   //FLASH 大小为32M字节  扇区4k对齐
//Dev_version_flag 31*1024*1024 = 32505856 
#define bin_flag        32505856-25 //占1个字节程序文件正常标志位	0x0A:正常 00:不正常
#define bin_size        bin_flag+1  //占4个字节
#define bin_name        bin_size+4  //占20个字节
#define bin_start       bin_name+20  //程序文件开始地址32505856  保证起始地址4K对齐效率更高

#define update_length   1024

/*状态标志*/
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