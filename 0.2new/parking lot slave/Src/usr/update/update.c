#include "update.h"
#include "EN25Q256.h"
/* �������� -----------------------------------------------------------------*/
uint32_t FlashSource = bin_start;//����洢flash����ʼ��ַ
uint16_t m_UpdateTotalPack = 0;  //���������ܰ���
uint32_t binlen = 0;						 //�����˵����ݳ���

void SoftReset(void)
{
	__set_FAULTMASK(1); // �ر������ж�
	NVIC_SystemReset(); // ��λ	
}

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

void handleupdate(uint16_t packnum)
{
	FlashSource = bin_start;
	m_UpdateTotalPack = packnum;
	binlen = 0;
}

uint8_t sendFrameToSlavemcu(unsigned char *packet_data ,uint16_t pack_len)
{
		//uint8_t packet_data[update_length] = {0};
		//����ˢ�뵽�ⲿflash
		//if(packet_data == NULL) return 0;
		EN25Q256_Write((u8 *)packet_data, FlashSource, pack_len);
		FlashSource += pack_len;	
		return 1;
}