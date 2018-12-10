#include <String.h>
#include <stdint.h>
#include <stdio.h>
#include "printf_usart.h"
#include "systick.h"
#include "LMX2541.h"
#include "cancellation.h"
#include "epc.h"
#include "ADC.h"
#include "rf_oper.h"
#include "READ_LED.h"
#include "EN25Q256.h"
#include "air_interface.h"
#include "rx485_send.h"
#include "RX485_uart.h"
#include "communication.h"
#include "time2.h"
#include "flashmanage.h"
#include "read_led_manage.h"
#include "radar_model.h"
#include "main.h"
u8  ReadCard_Flg=0;
u32 ReadCard_Count=0;
//�����ʼ��
void init_StdPeriph(void)
{
	//���жϷ��� 1 bits for pre-emption priority  3 bits for subpriority
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	
	//����printf�������õĴ��ڣ�����3��
	Printf_USART_Configuration();  //1   3
	      
	configMsTick();//�趨1ms��ϵͳʱ�ӵδ�	
	//printf("Printf_USART_Configuration finish!\n");	
}
u8 SelectStep = 0;
u8 hasCar = 0;
void  isturehasTag(u8 bState)
{
	//��һ�ζ�ȡ����ǩ
	//��ʼ����ʱ��1s���һ���Ƿ��б�ǩ������˸��
	//5s�����ɿ��Զ���ȷ���г�,5s��û������Ϊ�ǳ�����
	switch(SelectStep)
	{
		case 0: 
		{ //��һ�ζ�ȡ����ǩ
			if( bState == GL_OK ||bState == GL_OVER )
			{
				printf("....................Has car coming....................\n");
				//������ʱ��
		    TIM_Cmd(TIM2, ENABLE);//ʹ��TIMx 
				hasCar = 0;
				//���һ����ѯ
				ReadCard_Count = 0;
				SelectStep = 1;
			}	
		}		
		break;
		case 1:
		{
			if(ReadCard_Count <= m_slave.readcarthreshold)//10��֮�� ������ ������ȡ���Ĵ�����Ϊ�б�����
			{
				if( bState == GL_OK ||GL_OVER == bState)
				{			
          hasCar++;				
				}		
			  printf("ReadCard_Count :%d,hasCar:%d\n",ReadCard_Count,hasCar);		
	  	}
			if((ReadCard_Count>=m_slave.readcarthreshold) || hasCar >= 1)//(m_slave.readcarthreshold/2))//10��֮��ͳ���´����Ƿ�����Ҫ��
			{
			  TIM_Cmd(TIM2, DISABLE);//ʧ��TIMx 
				if(hasCar >= 1)//(m_slave.readcarthreshold/2))//10�ζ�ȡ��һ�������
				{
					led_h;//��ɫ
					SelectStep = 2;		
					ReadCard_Count = 0;
					printf("....................Have car standby....................\n");
			    printf("ReadCard_Count :%d,hasCar:%d\n",ReadCard_Count,hasCar);					
				}else{
			  	led_l;//��ɫ						  //û�г���ʾ��ɫ
					SelectStep = 0;	//���µȴ�	
					printf("....................Don't have car....................\n");	
				}			
			}
	  }
		break;
		
		case 2://ȷ���г������Ƿ�������
		{
				printf("ReadCard_Count :%d\n",ReadCard_Count);
				//���г���ÿ5�ζ���������Ϊ����뿪��
				if( (bState == GL_OK ||GL_OVER == bState) && ReadCard_Count<m_slave.readcarthreshold)//��Ϊ��
				{	
					ReadCard_Count = 0;
					led_h;//��ɫ
					printf("....................The car still....................\n");			
				}
				else if(ReadCard_Count >= m_slave.readcarthreshold)
				{
					printf("....................The car leave....................\n");							
				  //û�г���ʾ��ɫ
			  	led_l;//��ɫ
		  		SelectStep = 0;									
				}
		}
		break;
	}
}

void runModeChange(u8 runmode,u8 bState)
{
		if (runmode == 0)//���еĵƹ�ģʽ�ж�
		{
			//1.�رն�ʱ��
			TIM_Cmd(TIM2, DISABLE);//ʹ��TIMx 
			//2.��ձ�־λ
			SelectStep = 0;//��ʽģʽ�������Ƶƹ�ȷ�����̿��Ʊ���
			hasCar = 0;		 //�ڶ�����ȷ���г�����ȷ��û�г�
			
			if( bState == GL_OK ||bState == GL_OVER)
			{
					//��ȡ����ʾ��ɫ
					led_h;//��ɫ
			}
			else
			{
					led_l;//��ɫ
			}					
		}else{
			isturehasTag(bState);//��λ��λ���
		}	
}

void needcancell()
{
	if(isneedCancelltion == 1)
	{
		printf("Cancellation..\n");
		//�������ţ�����һ�ζ���
		RFPowerON(m_slave.RF_Power);	
		//�趨���໷
		LMX2541_SetFrequency(m_slave.RF_Frequency);   
		Cancellation();
		RFPowerOFF();		
		isneedCancelltion = 0;
		configcancellparam(min_SquDAValue);
		MCU_To_MCU(m_slave.Slave_Addr,ConfigCancellationAck);//��������Ӧ��
		printf("Cancellation.. RFPowerOFF \n");
	}	
}
int main(void)
{
	//������Դ��ʼ��
	init_StdPeriph();
	Rf_GPIO_Init(); //��Ƶ��Ԫ��ʼ��
	RX485_USART_Configuration();		
	Cancellation_Init();       //�������ֵĳ�ʼ��
	led_init;                //����ָʾ��
	radar_init();
	printf("Reader head start...\n");		
	EN25Q256_Init();               //�ⲿFLASH����		
	flashmanageinit();

	////////////////////////////////////////////
	//�趨���໷
	LMX2541_SetFrequency(m_slave.RF_Frequency);   
	led_l;//�رն���ָʾ��
	RFPowerOFF();//���ز�	
	TIM2_Configuration();
	
	uint8_t bState = 0;
	uint8_t s_cm = 0; 
  uint8_t send_radar = 0;
	while(1)
	{
		if(ReadCard_Flg==1)  //�����·��ӻ���ʼ����
		{
			if(send_radar == 1)
			{
				send_radar = 0;
				#ifdef __radar
				MCU_To_MCU(m_slave.Slave_Addr,GetRadarDistanceAck);//��ѯ�״�����ֵcmӦ��	
				#endif
			}
						
			bState = ReadTag();		
			ReadCard_Flg = 0;//�ӻ�ֻ��һ��		
			runModeChange(m_slave.Led_Mode,bState);				
		}else{
			if(send_radar == 0)
			{
				send_radar = 1;//���״�����
				#ifdef __radar
				m_slave.radar_distance	=	radar_read();
				#endif				
			}
		}
		needcancell();//�Ƿ���Ҫ����
		RS485_TX_L; //DE
		RS485_RX_L; //REn			
 }
}





