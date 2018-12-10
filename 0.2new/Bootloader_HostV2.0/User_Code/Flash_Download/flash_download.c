
/* 包含头文件 *****************************************************************/
#include "common.h"
#include "flash_download.h"
#include "iap.h"
/* 变量声明 -----------------------------------------------------------------*/
uint32_t FlashSource = bin_start;//程序存储flash的起始地址

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
/*******************************************************************************
  * @函数名称：FLASH_lenMask
  * @函数说明：计算1k 需要的次数
  * @输入参数：Size:文件长度
  * @输出参数：无
  * @返回参数：1k 需要的次数
  * @历史记录:     
     <作者>    <时间>      <修改记录>
*******************************************************************************/
uint32_t FLASH_lenMask(__IO uint32_t Size)
{
	uint32_t pagenumber = 0x0;
	uint32_t size = Size;

	if ((size % update_length) != 0)
	{
		pagenumber = (size / update_length) + 1;
	}
	else
	{
		pagenumber = size / update_length;
	}
	return pagenumber;
}
/*******************************************************************************
  * @函数名称：FlashDownload
  * @函数说明：通过读外部flash程序跟新到内部
  * @输入参数：无
  * @输出参数: 无
  * @返回参数: 无
  * @历史记录:     
     <作者>    <时间>      <修改记录>
*******************************************************************************/
uint8_t FlashDownload(void)
{
	uint8_t res = 0;
	//1.判断外部flash 是否含有完整的程序文件
	uint8_t flashbin_temp  = 0;//程序完整标志位
	uint8_t flashbin_temp1 = 0;//程序大小存储高位
	uint8_t flashbin_temp2 = 0;//程序大小存储低位
	uint8_t flashbin_temp3 = 0;//程序大小存储低位
	uint8_t flashbin_temp4 = 0;//程序大小存储低位

	uint8_t flashbinbuff[update_length] = {0};

	uint8_t Number[10] = "          ";
	uint8_t Number1[10] = "          ";
	uint32_t p_size = 0;
	uint8_t  code_name[20] = { 0 };
	uint32_t i;
//	uint32_t FlashSource = bin_start;//程序存储flash的起始地址
	uint32_t FlashDestination = ApplicationAddress;

	EN25Q256_Read(&flashbin_temp,bin_flag,1);  //地址信息正常标志位	0x0A:正常 00:不正常
	if(flashbin_temp == flash_Isok)//0x0A:正常
	{
		//读取判断文件大小
		EN25Q256_Read(&flashbin_temp1, bin_size  , 1);
		EN25Q256_Read(&flashbin_temp2, bin_size+1, 1);
		EN25Q256_Read(&flashbin_temp3, bin_size+2, 1);
		EN25Q256_Read(&flashbin_temp4, bin_size+3, 1);
		p_size = flashbin_temp1 << 24| flashbin_temp2 << 16 | flashbin_temp3 << 8| flashbin_temp4;
		if (p_size <= 0) return 0;//程序文件大小不对 返回错误

		Int2Str(Number, p_size);
		SerialPutString("\n\r Size: ");
		SerialPutString(Number);
//		EN25Q256_Read(code_name, bin_name, 18);
//		SerialPutString("\n\r file: ");
//		SerialPutString(code_name);
		SerialPutString("\n\r update...........");
		p_size = FLASH_lenMask(p_size);

		for ( i = 0; i < p_size; i++)
		{
			//0.数据烧写进度
			//SerialPutString("\n\r");
			//Int2Str(Number, FlashSource);
			//SerialPutString(Number);

//			SerialPutString("  ");
//			Hex2Str(Number1, FlashDestination);
//			SerialPutString(Number1);
			SerialPutString(".");	
			//1.读取程序文件
			EN25Q256_Read(flashbinbuff, FlashSource, update_length);    //地址二代表节点地址	 slave_cpu	
			//2.把读取到的数据刷入到FLASH
			iap_write_appbin(FlashDestination, flashbinbuff, update_length);
			//3.偏移数据的起始地址
			FlashDestination += update_length; //存储的目的地偏移update_length
			FlashSource += update_length;      //读取flash的地址偏移update_length
		}
		//翻转标志位
		flashbin_temp = flash_Notok;
		EN25Q256_Write(&flashbin_temp, bin_flag, 1);  //地址信息正常标志位	0x0A:正常 00:不正常
		SerialPutString("\n\r");
		res = 1;
	}else{
		res = 0;
	}
  return res; 		
}

/*******************************文件结束***************************************/
