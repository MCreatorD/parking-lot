#include "update.h"
#include "EN25Q256.h"
/* 变量声明 -----------------------------------------------------------------*/
uint32_t FlashSource = bin_start;//程序存储flash的起始地址
uint16_t m_UpdateTotalPack = 0;  //升级内容总包数
uint32_t binlen = 0;						 //接收了的数据长度

void SoftReset(void)
{
	__set_FAULTMASK(1); // 关闭所有中断
	NVIC_SystemReset(); // 复位	
}

/*******************************************************************************
* @函数名称：FLASH_Message
* @函数说明：更新下载到外部flash程序的相关信息
* @输入参数：Size:文件长度
* @输入参数：Name:文件名称
* @输入参数：Flag:文件完整标志
* @输出参数：无
* @返回参数：无
* @历史记录:
<作者>    <时间>      <修改记录>
*******************************************************************************/
void FLASH_Message(uint32_t Size,char *Name , uint8_t Flag)
{
	uint8_t size_1 = 0;
	uint8_t size_2 = 0;
	uint8_t size_3 = 0;
	uint8_t size_4 = 0;
	//写入程序大小 高位在前
	size_1 = ((Size>> 16) & 0xff00) >> 16;
	size_2 = (Size >> 16) & 0x00ff;
	size_3 = (Size & 0xff00) >> 8;
	size_4 =  Size & 0x00ff;
	EN25Q256_Write((uint8_t *)&size_1, bin_size  ,1);
	EN25Q256_Write((uint8_t *)&size_2, bin_size+1,1);
	EN25Q256_Write((uint8_t *)&size_3, bin_size+2,1);
	EN25Q256_Write((uint8_t *)&size_4, bin_size+3,1);
	//写入程序的name
	EN25Q256_Write((uint8_t *)Name, bin_name, 18);
	//更新标志位
	EN25Q256_Write((uint8_t *)&Flag, bin_flag, 1);
}

void handleupdate(uint16_t packnum)
{
	FlashSource = bin_start;
	m_UpdateTotalPack = packnum;
	binlen = 0;
}

uint8_t sendFrameToSlavemcu(unsigned char *packet_data ,uint16_t pack_len)
{
		//uint8_t packet_data[update_length] = {0};
		//数据刷入到外部flash
		//if(packet_data == NULL) return 0;
		EN25Q256_Write((u8 *)packet_data, FlashSource, pack_len);
		FlashSource += pack_len;	
		return 1;
}