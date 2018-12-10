#ifndef __FLASHMANAGE_H
#define __FLASHMANAGE_H
#include "stm32f2xx.h"
#include "cancellation.h"
/*״̬��־*/
#define flash_Isok      0x0A
#define flash_Notok     0x00
/*��ַ��־*/
#define addrMessage_flag         1 //��ַ��Ϣ������־λ	0x0A:���� 00:������
#define flash_dev_addr           2 //485��ַ

#define Dev_version_flag         3 //�汾���к�������־λ	0x0A:���� 00:������
#define Dev_version_start        4 //�汾���кſ�ʼ��ַ ����21��

#define rfparam_flag            70 //��Ƶ���ò���������־λ	0x0A:���� 00:������
#define rfpower_h               71 //��Ƶ���ʸ�8λ
#define rfpower_l               72 //��Ƶ���ʵ�8λ
#define rffrequency             73 //��ƵƵ��

#define cancellsave_flag        74 //����ֵ�洢������־λ	0x0A:���� 00:������
#define cancellqp_davalue_h     75 //Qp_DAValue��λ
#define cancellqp_davalue_l     76 //Qp_DAValue��λ

#define cancellqn_davalue_h     77 //Qn_DAValue��λ
#define cancellqn_davalue_l     78 //Qn_DAValue��λ

#define cancellip_davalue_h     79 //Ip_DAValue��λ
#define cancellip_davalue_l     80 //Ip_DAValue��λ

#define cancellin_davalue_h     81 //In_DAValue��λ
#define cancellin_davalue_l     82 //In_DAValue��λ

#define flash_threshold_flag    91 //�ż��������ڱ�־λ
#define flash_threshold         92 //�ż�����


//flash�洢��Ϣ�ṹ��
typedef struct
{
	unsigned char Dev_flag;          		 //	�汾���к�������־λ	0x0A:���� 00:������
	unsigned char Slave_Addr_flag;   		 //	��ַ��Ϣ������־λ	0x0A:���� 00:������
	unsigned char rf_param_flag;     		 //	��Ƶ���ò���������־λ	0x0A:���� 00:������
	unsigned char cancell_save_flag; 		 //	����ֵ�洢������־λ	0x0A:���� 00:������
	unsigned char readcar_threshold_flag;//	�ż��洢������־λ	0x0A:���� 00:������
}flash_save_flag; //flash�洢��Ϣ�ṹ��

#ifdef __cplusplus
 extern "C" {
#endif
extern flash_save_flag flash_flag;//�洢flash����Ϣ������־λ
//1.�����豸�汾��
void SetDerviceVersion(u8 *flashtmp,u8 len);
//2.��ѯ�豸�汾��
void GetDerviceVersion(u8* datatemp);

//����flash����
//1. ����485ͨ�ŵ�ַ
void config485addr(u8 addr);
u8 Get485addr();

//2. ������Ƶ���ò���
void configrfparam(unsigned short int rf_power,unsigned char rf_frequency);
u8 Getrfparam();
//3. ���ö�������
void configcancellparam(struct SQU_DA_Value tmp);
u8 Getcancellparam();


//5. �����ż�����ֵ
void flashthreshold(u8 threshold);
u8 Getflashthreshold();
//������ʼ�� flash�洢�����Ļ���ȡ����
void flashmanageinit();


#ifdef __cplusplus
}
#endif
 

#endif