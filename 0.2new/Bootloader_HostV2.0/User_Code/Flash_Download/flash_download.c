
/* ����ͷ�ļ� *****************************************************************/
#include "common.h"
#include "flash_download.h"
#include "iap.h"
/* �������� -----------------------------------------------------------------*/
uint32_t FlashSource = bin_start;//����洢flash����ʼ��ַ

/*******************************************************************************
* @�������ƣ�FLASH_Message
* @����˵�����������ص��ⲿflash����������Ϣ
* @���������Size:�ļ�����
* @���������Name:�ļ�����
* @���������Flag:�ļ�������־
* @�����������
* @���ز�������
* @��ʷ��¼:
<����>    <ʱ��>      <�޸ļ�¼>
*******************************************************************************/
void FLASH_Message(uint32_t Size,char *Name , uint8_t Flag)
{
	uint8_t size_1 = 0;
	uint8_t size_2 = 0;
	uint8_t size_3 = 0;
	uint8_t size_4 = 0;
	//д������С ��λ��ǰ
	size_1 = ((Size>> 16) & 0xff00) >> 16;
	size_2 = (Size >> 16) & 0x00ff;
	size_3 = (Size & 0xff00) >> 8;
	size_4 =  Size & 0x00ff;
	EN25Q256_Write((uint8_t *)&size_1, bin_size  ,1);
	EN25Q256_Write((uint8_t *)&size_2, bin_size+1,1);
	EN25Q256_Write((uint8_t *)&size_3, bin_size+2,1);
	EN25Q256_Write((uint8_t *)&size_4, bin_size+3,1);
	//д������name
	EN25Q256_Write((uint8_t *)Name, bin_name, 18);
	//���±�־λ
	EN25Q256_Write((uint8_t *)&Flag, bin_flag, 1);
}
/*******************************************************************************
  * @�������ƣ�FLASH_lenMask
  * @����˵��������1k ��Ҫ�Ĵ���
  * @���������Size:�ļ�����
  * @�����������
  * @���ز�����1k ��Ҫ�Ĵ���
  * @��ʷ��¼:     
     <����>    <ʱ��>      <�޸ļ�¼>
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
  * @�������ƣ�FlashDownload
  * @����˵����ͨ�����ⲿflash������µ��ڲ�
  * @�����������
  * @�������: ��
  * @���ز���: ��
  * @��ʷ��¼:     
     <����>    <ʱ��>      <�޸ļ�¼>
*******************************************************************************/
uint8_t FlashDownload(void)
{
	uint8_t res = 0;
	//1.�ж��ⲿflash �Ƿ��������ĳ����ļ�
	uint8_t flashbin_temp  = 0;//����������־λ
	uint8_t flashbin_temp1 = 0;//�����С�洢��λ
	uint8_t flashbin_temp2 = 0;//�����С�洢��λ
	uint8_t flashbin_temp3 = 0;//�����С�洢��λ
	uint8_t flashbin_temp4 = 0;//�����С�洢��λ

	uint8_t flashbinbuff[update_length] = {0};

	uint8_t Number[10] = "          ";
	uint8_t Number1[10] = "          ";
	uint32_t p_size = 0;
	uint8_t  code_name[20] = { 0 };
	uint32_t i;
//	uint32_t FlashSource = bin_start;//����洢flash����ʼ��ַ
	uint32_t FlashDestination = ApplicationAddress;

	EN25Q256_Read(&flashbin_temp,bin_flag,1);  //��ַ��Ϣ������־λ	0x0A:���� 00:������
	if(flashbin_temp == flash_Isok)//0x0A:����
	{
		//��ȡ�ж��ļ���С
		EN25Q256_Read(&flashbin_temp1, bin_size  , 1);
		EN25Q256_Read(&flashbin_temp2, bin_size+1, 1);
		EN25Q256_Read(&flashbin_temp3, bin_size+2, 1);
		EN25Q256_Read(&flashbin_temp4, bin_size+3, 1);
		p_size = flashbin_temp1 << 24| flashbin_temp2 << 16 | flashbin_temp3 << 8| flashbin_temp4;
		if (p_size <= 0) return 0;//�����ļ���С���� ���ش���

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
			//0.������д����
			//SerialPutString("\n\r");
			//Int2Str(Number, FlashSource);
			//SerialPutString(Number);

//			SerialPutString("  ");
//			Hex2Str(Number1, FlashDestination);
//			SerialPutString(Number1);
			SerialPutString(".");	
			//1.��ȡ�����ļ�
			EN25Q256_Read(flashbinbuff, FlashSource, update_length);    //��ַ������ڵ��ַ	 slave_cpu	
			//2.�Ѷ�ȡ��������ˢ�뵽FLASH
			iap_write_appbin(FlashDestination, flashbinbuff, update_length);
			//3.ƫ�����ݵ���ʼ��ַ
			FlashDestination += update_length; //�洢��Ŀ�ĵ�ƫ��update_length
			FlashSource += update_length;      //��ȡflash�ĵ�ַƫ��update_length
		}
		//��ת��־λ
		flashbin_temp = flash_Notok;
		EN25Q256_Write(&flashbin_temp, bin_flag, 1);  //��ַ��Ϣ������־λ	0x0A:���� 00:������
		SerialPutString("\n\r");
		res = 1;
	}else{
		res = 0;
	}
  return res; 		
}

/*******************************�ļ�����***************************************/
