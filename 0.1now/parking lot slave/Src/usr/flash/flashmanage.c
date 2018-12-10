#include "flashmanage.h"
#include "EN25Q256.h" //flash �����Ͷ�д�����ļ�
#include "communication.h"
#include "cancellation.h"
#include <string.h>
//ҵ���ĵ�ַ��Ϣ�洢״̬��־λ
flash_save_flag flash_flag={0,0,0,0};//�洢flash����Ϣ������־λ

//������ʼ�� flash�洢�����Ļ���ȡ����
void flashmanageinit()
{
	//�洢��ʱ��ȡ���ݵ���ʱ����
	unsigned short int flash_temp_h = 0;
	unsigned short int flash_temp_l = 0;
	char datatemp[70] = {0};
	u8 flashMessage_temp = 0; //flash�洢��Ϣ��ȡװ�ص���ʱ����
	u8 flash_temp = 0;
	//��ʼ����flash������
	if(flash_Dev_ok == flash_Isok)//оƬ����
	{
		//1.��ַ��Ϣ������־λ	0x0A:���� 00:������
	  Get485addr();
		//2.��Ƶ���ò���������־λ	0x0A:���� 00:������
    Getrfparam();
	  //3.��ȡ����ֵ ����ֵ�洢������־λ	0x0A:���� 00:������	
		Getcancellparam();
		//4.��ѯ�豸�汾��
		GetDerviceVersion((u8*)datatemp);	
		//��ȡ��ַ
		//char str[] = "I we23|me any ideas from readers�� of course.";
    char *lc = strchr(datatemp, '|');
		if(lc == NULL) return;
		char sit = lc - datatemp;//���ŵ�ַ
    //printf("strchr: %d\n", sit );
		char num = (datatemp[sit-1]-0x30)+ (datatemp[sit-2]-0x30)*10;
		printf("addr: %d\n", num ); 
		
		//5.��ѯ�ƹ���ż���ֵ
		Getflashthreshold();
	}
}

//1.�����豸�汾��
const u8 Example_version[]={"BL-SR-200,BL1810301001"};
#define SIZE sizeof(Example_version)
void SetDerviceVersion(u8 *flashtmp,u8 len)
{
	char datatemp[60] = {0};
	printf("SIZE:%d\n",len);
	
	printf("\r\nFALSH SetDerviceVersion Write: \r\n");
	printf("\r\nThe flashtmp DerviceVersion Is:  %s\r\n",flashtmp);//��ʾ�������ַ���	
	EN25Q256_Write((u8*)flashtmp,Dev_version_start,len);		

	printf("\r\nStart Read DerviceVersion....: \r\n");
	EN25Q256_Read((u8 *)datatemp,Dev_version_start,len);					//�ӵ�����100��	
	printf("\r\nThe DerviceVersion Is:%s\r\n",datatemp);  //��ʾ�������ַ���		
	if(strcmp(datatemp,flashtmp) == 0) 
	{
		//flash�洢���� ���µ�ȫ�ֱ���
		flash_flag.Dev_flag = flash_Isok;//0x0A:����					
		EN25Q256_Write(&flash_flag.Dev_flag,Dev_version_flag,1);		
		printf("DerviceVersion wirte success \n");
		
		//��ȡ��ַ
		//char str[] = "I we23|me any ideas from readers�� of course.";
    char *lc = strchr(datatemp, '|');
		if(lc == NULL) return;
		char sit = lc - datatemp;
    printf("strchr�� %d\n", sit );
		char num = (datatemp[sit-1]-0x30)+ (datatemp[sit-2]-0x30)*10;
		printf("num %d\n", num ); 	

		config485addr(num);		
	}else{
		flash_flag.Dev_flag = flash_Notok;//0x0A:����					
		EN25Q256_Write(&flash_flag.Dev_flag,Dev_version_flag,1);		
		printf("DerviceVersion wirte false \n");		
	}
}	

//2.��ѯ�豸�汾��
void GetDerviceVersion(u8* datatemp)
{
  //	u8 datatemp[70];
	if (datatemp == NULL ) return;
	EN25Q256_Read(&flash_flag.Dev_flag,Dev_version_flag,1);	
	printf("Start Read EN25Q256....: \r\n");
	if(flash_flag.Dev_flag == flash_Isok)//0x0A:����		
	{
		memset(datatemp,0,70);
		EN25Q256_Read(datatemp,Dev_version_start,56);			
		printf("\r\nThe Slave Message Is:%s\r\n",datatemp);//��ʾ�������ַ���			
	}
}



//����flash����
//1. ����485ͨ�ŵ�ַ
void config485addr(u8 addr)
{
	u8 tmp_addr = 0;	
	printf("config ...\n");
	if(flash_Dev_ok == flash_Isok)//flash �豸����
	{
		//485��ַд��
		tmp_addr = addr;//�ӻ���ַ ���µ�ram tmp_addr��
		EN25Q256_Write(&tmp_addr,flash_dev_addr,1);
		//��ȡ485��ַУ��
		EN25Q256_Read(&tmp_addr,flash_dev_addr,1);
		if(tmp_addr == addr)
		{
			//����ram ״̬��־λ�� flash ��־λ
			m_slave.Slave_Addr = tmp_addr;                
			//flash�洢���� ���µ�ȫ�ֱ���
			flash_flag.Slave_Addr_flag = flash_Isok;//0x0A:����					
			EN25Q256_Write(&flash_flag.Slave_Addr_flag,addrMessage_flag,1);
			//MCU_To_MCU(m_slave.Slave_Addr,ConfigSlaveAddrAck);//ConfigSlaveAddrAck
		}else{
			//flashд�벻���� ���µ�ȫ�ֱ��� ͬʱд�뵽flash
			flash_flag.Slave_Addr_flag = flash_Notok;//0x0A:����					
			EN25Q256_Write(&flash_flag.Slave_Addr_flag,addrMessage_flag,1);
			//MCU_To_MCU(m_slave.Slave_Addr,ConfigSlaveAddrAck);//ConfigSlaveAddrAck			
		}
	}	
	printf("config salve addr  :%d\n",m_slave.Slave_Addr);	
}

u8 Get485addr()
{
	u8 res = 0;
	//1.��ַ��Ϣ������־λ	0x0A:���� 00:������
	u8 flashMessage_temp = 0;
	EN25Q256_Read(&flashMessage_temp,addrMessage_flag,1);  //��ַ��Ϣ������־λ	0x0A:���� 00:������
	if(flashMessage_temp == flash_Isok)//0x0A:����
	{
		//flash�洢���� ���µ�ȫ�ֱ���
		flash_flag.Slave_Addr_flag = flash_Isok;//0x0A:����
		//��ȡ�洢�豸��ַ  485��ַ
		EN25Q256_Read(&m_slave.Slave_Addr,flash_dev_addr,1);//��ַ������ڵ��ַ	 slave_cpu	
		res = 1;
	}else{
		res = 0;
		printf("Slave_Addr_flag is not ok\n");
	}
	printf("slave_cpu :%d\n",m_slave.Slave_Addr);	
  return res; 	
}

//2. ������Ƶ���ò���
void configrfparam(unsigned short int rf_power,unsigned char rf_frequency)
{
	u8 tmp_write[3] = {0};
	u8 tmp_read[3] = {0};
	printf("config ...\n");	
	if(flash_Dev_ok == flash_Isok)//flash �豸����
	{
		//��Ƶ���ʸ�8λ
		tmp_write[0] = (rf_power>>8)&0xff;
		EN25Q256_Write(&tmp_write[0],rfpower_h,1);
		//��Ƶ���ʵ�8λ
		tmp_write[1] = rf_power&0xff;
		EN25Q256_Write(&tmp_write[1],rfpower_l,1);	
		//��ƵƵ��
		tmp_write[2] = rf_frequency;
		EN25Q256_Write(&tmp_write[2],rffrequency,1);			
		//��Ƶ���ʺ�Ƶ��У�� ��ȡ�������� rfpower_h rfpower_l rffrequency
		EN25Q256_Read(tmp_read,rfpower_h,3);
		if((( tmp_write[0] = tmp_read[0] )&&( tmp_write[1] = tmp_read[1] ))||( tmp_write[2] = tmp_read[2] ))
		{
			//����ram ����,ram ״̬��־λ�� flash ��־λ
			m_slave.RF_Power = tmp_write[0]<<8|tmp_write[1];  
			m_slave.RF_Frequency = tmp_write[2];
			//���µ�ȫ�ֱ��� ���µ�flash�洢���� 
			flash_flag.rf_param_flag = flash_Isok;//0x0A:����					
			EN25Q256_Write(&flash_flag.rf_param_flag,rfparam_flag,1);
//			MCU_To_MCU(m_slave.Slave_Addr,ConfigRfPowerAck);//ConfigRfPowerAck
//			MCU_To_MCU(m_slave.Slave_Addr,ConfigFrequencyAck);//	
	
			//��Ƶ��������Ҫ���ó�ȥ
			//������������������������			
			printf("%d,ConfigRfPowerAck success \n",m_slave.RF_Power);		
			printf("%d,ConfigFrequencyAck success \n",m_slave.RF_Frequency);	
		}else{
			//flashд�벻���� ���µ�ȫ�ֱ��� 
			flash_flag.rf_param_flag = flash_Notok;//0x00:������	
			//ͬʱд�뵽flash
			EN25Q256_Write(&flash_flag.rf_param_flag,rfparam_flag,1);
//			MCU_To_MCU(m_slave.Slave_Addr,ConfigRfPowerAck);//ConfigRfPowerAck
//			MCU_To_MCU(m_slave.Slave_Addr,ConfigFrequencyAck);//	
			
			printf("%d,ConfigRfPowerAck fail\n",m_slave.RF_Power);		
			printf("%d,ConfigFrequencyAck fail\n",m_slave.RF_Frequency);				
		}		
	}
}

u8 Getrfparam()
{
	u8 res = 0;
	//�洢��ʱ��ȡ���ݵ���ʱ����
	unsigned short int flash_temp_h = 0;
	unsigned short int flash_temp_l = 0;	
	u8 flashMessage_temp = 0;
	EN25Q256_Read(&flashMessage_temp,rfparam_flag,1); 
	if(flashMessage_temp == flash_Isok)//0x0A:����
	{
		//flash�洢���� ���µ�ȫ�ֱ���
		//1.���±�־λ
		flash_flag.rf_param_flag = flash_Isok;//0x0A:����			
		//2.��ȡ�洢�豸��Ƶ���ò���  ��Ƶ����
		EN25Q256_Read((u8 *)&flash_temp_h,rfpower_h,1);//��Ƶ���ʸ�8λ RF_Power
		EN25Q256_Read((u8 *)&flash_temp_l,rfpower_l,1);//��Ƶ���ʵ�8λ RF_Power
		m_slave.RF_Power = (flash_temp_h<<8)|flash_temp_l;
		
		//3.��ȡ�洢�豸��Ƶ���ò���  ��ƵƵ��
		EN25Q256_Read(&m_slave.RF_Frequency,rffrequency,1);//��ƵƵ��	
		res = 1;
	}else{
		res = 0;
		printf("rfparam_flag is not ok\n");
	}		
	printf("m_slave.RF_Power :%d\n",m_slave.RF_Power);
	printf("m_slave.RF_Frequency :%d\n",m_slave.RF_Frequency);	
	return res;	
}

//3. ���ö�������
void configcancellparam(struct SQU_DA_Value tmp)
{
	u8 tmp_write[8] = {0};
	u8 tmp_read[8] = {0};
	//��֡
	tmp_write[0] = (tmp.Qp_DAValue>>8)&0xff;
	tmp_write[1] = (tmp.Qp_DAValue)&0xff;	
	
	tmp_write[2] = (tmp.Qn_DAValue>>8)&0xff;
	tmp_write[3] = (tmp.Qn_DAValue)&0xff;	

	tmp_write[4] = (tmp.Ip_DAValue>>8)&0xff;
	tmp_write[5] = (tmp.Ip_DAValue)&0xff;	
	
	tmp_write[6] = (tmp.In_DAValue>>8)&0xff;
	tmp_write[7] = (tmp.In_DAValue)&0xff;		
	
	printf("config ...\n");	
	if(flash_Dev_ok == flash_Isok)//flash �豸����
	{
		//д��
		//Qp_DAValue��λ
		EN25Q256_Write(&tmp_write[0],cancellqp_davalue_h,1);
		//Qp_DAValue��λ
		EN25Q256_Write(&tmp_write[1],cancellqp_davalue_l,1);
		
		//Qn_DAValue��λ
		EN25Q256_Write(&tmp_write[2],cancellqn_davalue_h,1);
		//Qn_DAValue��λ
		EN25Q256_Write(&tmp_write[3],cancellqn_davalue_l,1);
		
		//Ip_DAValue��λ
		EN25Q256_Write(&tmp_write[4],cancellip_davalue_h,1);
		//Ip_DAValue��λ
		EN25Q256_Write(&tmp_write[5],cancellip_davalue_l,1);
		
		//In_DAValue��λ
		EN25Q256_Write(&tmp_write[6],cancellin_davalue_h,1);
		//In_DAValue��λ
		EN25Q256_Write(&tmp_write[7],cancellin_davalue_l,1);		
		
		//��ȡ8�������ڴ�Ķ������Ƶ�ѹ����
		EN25Q256_Read(tmp_read,cancellqp_davalue_h,8);

		//�ȶ�
		if( ( tmp_write[0] == tmp_read[0] )&&( tmp_write[1] == tmp_read[1])
			&&( tmp_write[2] == tmp_read[2] )&&( tmp_write[3] == tmp_read[3])
			&&( tmp_write[4] == tmp_read[4] )&&( tmp_write[5] == tmp_read[5])
			&&( tmp_write[6] == tmp_read[6] )&&( tmp_write[7] == tmp_read[7]))
		{
			//����ram ״̬��־λ�� flash ��־λ
			flash_flag.cancell_save_flag = flash_Isok;		
			EN25Q256_Write(&flash_flag.cancell_save_flag,cancellsave_flag,1);	
			
			//����ȫ��ram ����
			min_SquDAValue = tmp;
			//��Ƶ��������Ҫ���ó�ȥ
			//������������������������
		}else{
			flash_flag.cancell_save_flag = flash_Notok;		
			EN25Q256_Write(&flash_flag.cancell_save_flag,cancellsave_flag,1);				
		}	
	}		
}

u8 Getcancellparam()
{
	u8 res = 0;
	//�洢��ʱ��ȡ���ݵ���ʱ����
	unsigned short int flash_temp_h = 0;
	unsigned short int flash_temp_l = 0;	
	u8 flashMessage_temp = 0;
	EN25Q256_Read(&flashMessage_temp,cancellsave_flag,1);	
	if(flashMessage_temp == flash_Isok)//0x0A:����
	{
		//flash�洢���� ���µ�ȫ�ֱ���
		//1.���±�־λ
		flash_flag.cancell_save_flag = flash_Isok;//0x0A:����			
		//2.��ȡ�洢�豸��Ƶ���ò���  ��Ƶ����
		flash_temp_h = flash_temp_l = 0;
		EN25Q256_Read((u8 *)&flash_temp_h,cancellqp_davalue_h,1);//Qp_DAValue��λ
		EN25Q256_Read((u8 *)&flash_temp_l,cancellqp_davalue_l,1);//Qp_DAValue��λ
		min_SquDAValue.Qp_DAValue = (flash_temp_h<<8)|flash_temp_l;

		flash_temp_h = flash_temp_l = 0;
		EN25Q256_Read((u8 *)&flash_temp_h,cancellqn_davalue_h,1);//Qn_DAValue��λ
		EN25Q256_Read((u8 *)&flash_temp_l,cancellqn_davalue_l,1);//Qn_DAValue��λ
		min_SquDAValue.Qn_DAValue = (flash_temp_h<<8)|flash_temp_l;
		
		flash_temp_h = flash_temp_l = 0;
		EN25Q256_Read((u8 *)&flash_temp_h,cancellip_davalue_h,1);//Ip_DAValue��λ
		EN25Q256_Read((u8 *)&flash_temp_l,cancellip_davalue_l,1);//Ip_DAValue��λ
		min_SquDAValue.Ip_DAValue = (flash_temp_h<<8)|flash_temp_l;			

		flash_temp_h = flash_temp_l = 0;
		EN25Q256_Read((u8 *)&flash_temp_h,cancellin_davalue_h,1);//In_DAValue��λ
		EN25Q256_Read((u8 *)&flash_temp_l,cancellin_davalue_l,1);//In_DAValue��λ
		min_SquDAValue.In_DAValue = (flash_temp_h<<8)|flash_temp_l;			
					
		//3.��ȡ�洢�豸��Ƶ���ò���  ��ƵƵ��
		flash_temp_h = flash_temp_l = 0;
		EN25Q256_Read(&m_slave.RF_Frequency,rffrequency,1);//��ƵƵ��	
		
		//��Ƶ��������Ҫ���ó�ȥ
		setDACValue(min_SquDAValue.Qp_DAValue,QP_CHANNEL);
		setDACValue(min_SquDAValue.Qn_DAValue,QN_CHANNEL);
		setDACValue(min_SquDAValue.Ip_DAValue,IP_CHANNEL);
		setDACValue(min_SquDAValue.In_DAValue,IN_CHANNEL);
		res = 0;
	}else{
		res = 1;
		printf("rfparam_flag is not ok\n");
	}
	printf("min_SquDAValue.Squ_Value=%lld,Qp_DA=%d,Qn_DA=%d,Ip_DA=%d,In_DA=%d\n",
			min_SquDAValue.Squ_Value,min_SquDAValue.Qp_DAValue,min_SquDAValue.Qn_DAValue,min_SquDAValue.Ip_DAValue,min_SquDAValue.In_DAValue);			
		
	return res;	
}

//5. �����ż�����ֵ
void flashthreshold(u8 threshold)
{
	u8 tmp_threshold = 0;	
	printf("flash config threshold...\n");
	if(flash_Dev_ok == flash_Isok)//flash �豸����
	{
		//�ż���ֵ����ַд��
		tmp_threshold = threshold;//�ӻ���ַ ���µ�ram tmp_addr��
		EN25Q256_Write(&tmp_threshold,flash_threshold,1);
		//��ȡ�ż�У��
		EN25Q256_Read(&tmp_threshold,flash_threshold,1);
		if(tmp_threshold == threshold)
		{
			//����ram ״̬��־λ�� flash ��־λ
			m_slave.readcarthreshold = tmp_threshold;                
			//flash�洢���� ���µ�ȫ�ֱ���
			flash_flag.readcar_threshold_flag = flash_Isok;//0x0A:����					
			EN25Q256_Write(&flash_flag.readcar_threshold_flag,flash_threshold_flag,1);
			
		}else{
			//flashд�벻���� ���µ�ȫ�ֱ��� ͬʱд�뵽flash
			flash_flag.readcar_threshold_flag = flash_Notok;//0x0A:����					
			EN25Q256_Write(&flash_flag.readcar_threshold_flag,flash_threshold_flag,1);
		
		}
	}	
	printf("readcarthreshold config: %d\n",m_slave.readcarthreshold);		
}

u8 Getflashthreshold()
{
	u8 res = 0;
	//1.�ż�����ֵ��Ϣ ������־λ	0x0A:���� 00:������
	u8 flashMessage_temp = 0;
	EN25Q256_Read(&flashMessage_temp,flash_threshold_flag,1);  //��ַ��Ϣ������־λ	0x0A:���� 00:������
	if(flashMessage_temp == flash_Isok)//0x0A:����
	{
		//flash�洢���� ���µ�ȫ�ֱ���
		flash_flag.readcar_threshold_flag = flash_Isok;//0x0A:����
		//��ȡ�ż�����ֵ
		EN25Q256_Read(&m_slave.readcarthreshold,flash_threshold,1);//��ַ������ڵ��ַ	 slave_cpu	
		res = 1;
	}else{
		res = 0;
		printf("Getflashthreshold is not ok\n");
	}
	printf("Getflashthreshold :%d\n",m_slave.readcarthreshold);	
  return res; 		
}