#ifndef __flash_manage_H
#define __flash_manage_H


#include "stm32f2xx.h"


/*״̬��־*/
#define flash_Isok      0x0A
#define flash_Notok     0x00

/*
* flash �ڴ����
* 01 �� 0A�ڴ��Ѿ���ʼ��������
* 02 �� �ڵ�����
* 03 �� �洢�ڵ�1��ַ
* 04 �� �洢�ڵ�2��ַ
*/
/*��ַ��־*/
#define flash_ok      0x01
#define flash_num     0x02
#define flash_addr1   0x03
#define flash_addr2   0x04
#define flash_addr3   0x05
#define flash_addr4   0x06
#define flash_addr5   0x07
#define flash_addr6   0x08
#define flash_addr7   0x09
#define flash_addr8   0x0A
#define flash_addr9   0x0B
#define flash_addr10  0x0C
#define flash_addr11  0x0D
#define flash_addr12  0x0E
#define flash_addr13  0x0F
#define flash_addr14  0x10

#define Dev_version_flag        280 //�汾���к�������־λ	0x0A:���� 00:������
#define Dev_version_start       281 //�汾���кſ�ʼ��ַ ����21��

#define rfparam_flag            330 //��Ƶ���ò���������־λ	0x0A:���� 00:������
#define rfpower_h               331 //��Ƶ���ʸ�8λ
#define rfpower_l               332 //��Ƶ���ʵ�8λ
#define rffrequency             333 //��ƵƵ��

#define cancellsave_flag        334 //����ֵ�洢������־λ	0x0A:���� 00:������
#define cancellqp_davalue_h     335 //Qp_DAValue��λ
#define cancellqp_davalue_l     336 //Qp_DAValue��λ

#define cancellqn_davalue_h     337 //Qn_DAValue��λ
#define cancellqn_davalue_l     338 //Qn_DAValue��λ

#define cancellip_davalue_h     339 //Ip_DAValue��λ
#define cancellip_davalue_l     340 //Ip_DAValue��λ

#define cancellin_davalue_h     341 //In_DAValue��λ
#define cancellin_davalue_l     342 //In_DAValue��λ

#define continueSelectSpc_flag        350 //�־û����� ������־λ	0x0A:���� 00:������
#define continueSelectSSpc_start      351 //�־û�����

#define continueAccessSpc_flag        600 //�־û����� ������־λ	0x0A:���� 00:������
#define continueAccessSpc_start       601 //�־û�����

//flash��Ϣ�洢����ṹ��
typedef struct
{
	unsigned char Dev_flag;           //03h	�汾���к�������־λ	  0x0A:���� 00:������
	unsigned char Slave_Addr_flag;    //01h	��ַ��Ϣ������־λ	    0x0A:���� 00:������
	unsigned char rf_param_flag;      //19h	��Ƶ���ò���������־λ	0x0A:���� 00:������
	unsigned char cancell_save_flag;  //1Dh	����ֵ�洢������־λ	  0x0A:���� 00:������
}flash_save_flag; //flash�洢��Ϣ�ṹ��

class flash_manage{
	/*-----------------flash����-----------------*/	
public:
		//����flash�洢��־λ
	  flash_save_flag flash_flag;
	
public:
		//1. �����豸�汾
		bool SetDerviceVersion(u8 *flashtmp,u8 len);	
		//2. ��ѯ�豸�汾��
		bool GetDerviceVersion(u8 *datatemp,u8 len);
		//3. ������Ƶ���ò���
		void configrfparam(unsigned short int rf_power,unsigned char rf_frequency);
		//4. ��ѯ��Ƶ����
		u8 Getrfparam();
		//5. ���ö�������
		void configcancellparam(struct SQU_DA_Value tmp);
		//6.��ѯ��������·��ѹ
		u8 Getcancellparam();
};

#endif