#include "lowpower.h"

//����ģʽ��PA0����

void init_lowpower()
{
    //������Դ����ĵ�Ԫ��ʱ��
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR, ENABLE);	
    /*���WU״̬λ*/
    PWR_ClearFlag (PWR_FLAG_WU);
    /* ʹ��WKUP���ŵĻ��ѹ��� ��ʹ��PA0  WKUP����������*/
    PWR_WakeUpPinCmd (ENABLE);	
}

void lowpower()//�������ģʽ
{
       /* �������ģʽ WKUP���������ػ���*/
	   //�ر����������ĵ�Դ
	   //1.�ر�FPGA��
//	   FPGA_PWR_EN_L;//�����Ƶ��Ҳ�Ͷ���
     PWR_EnterSTANDBYMode();	
}

void PWR_STOP()//ֹͣģʽ
{
	//�ر����������ĵ�Դ
	//1.�ر�FPGA��
//	FPGA_PWR_EN_L;//�����Ƶ��Ҳ�Ͷ���
	PWR_EnterSTOPMode(PWR_Regulator_ON, PWR_STOPEntry_WFI);  //ͣ��ģʽ
	SystemInit();//�˳��͹��ĺ��ʱ��������
	
}

//�����λ
void SoftReset(void)
{
	__set_FAULTMASK(1); // �ر������ж�
	NVIC_SystemReset(); // ��λ
}

            

            
