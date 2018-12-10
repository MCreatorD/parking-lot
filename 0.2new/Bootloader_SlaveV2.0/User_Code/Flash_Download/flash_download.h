#ifndef __FLASH_DOWNLOAD_H
#define __FLASH_DOWNLOAD_H
#include "EN25Q256.h"
#include "stm32f2xx.h"
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
void FLASH_Message(uint32_t Size, char *Name, uint8_t Flag);
u8 FlashDownload(void);
#endif
