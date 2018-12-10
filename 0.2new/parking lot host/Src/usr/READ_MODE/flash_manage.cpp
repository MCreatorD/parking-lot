#include "flash_manage.h"
#include "EN25Q256.h"
#include "cancellation.h"
#include <string.h>
/*----------------flash����------------------------*/
//0.Ĭ�Ϲ���
flash_manage::flash_manage()
{
	
}



//1.�����豸�汾��
bool flash_manage::SetDerviceVersion(u8 *flashtmp,u8 len)
{
	u8 datatemp[60];
	printf("SIZE:%d\n",len);
	if(flashtmp == NULL) return false;
	printf("\r\nFALSH SetDerviceVersion Write: \r\n");
	EN25Q256_Write((u8*)flashtmp,Dev_version_start,len);		
	printf("\r\nThe Write DerviceVersion Is:%s\n",flashtmp);//��ʾ�������ַ���		
	
	EN25Q256_Read(datatemp,Dev_version_start,len);					//�ӵ�����100��	
	printf("\r\nThe Read  DerviceVersion Is:%s\r\n",datatemp);//��ʾ�������ַ���		
	if(strcmp((char *)datatemp,(char *)flashtmp) == 0) 
	{
		//flash�洢���� ���µ�ȫ�ֱ���
		flash_flag.Dev_flag = flash_Isok;//0x0A:����					
		EN25Q256_Write(&flash_flag.Dev_flag,Dev_version_flag,1);		
		printf("DerviceVersion wirte success \n");
		return true;
	}else{
		flash_flag.Dev_flag = flash_Notok;//0x0A:����					
		EN25Q256_Write(&flash_flag.Dev_flag,Dev_version_flag,1);		
		printf("DerviceVersion wirte false \n");		
		return false;
	}
}
//2.��ѯ�豸�汾��
bool flash_manage::GetDerviceVersion(u8 *datatemp,u8 len)
{
	if(datatemp == NULL) return 0;
	EN25Q256_Read(&flash_flag.Dev_flag,Dev_version_flag,1);		
	if(flash_flag.Dev_flag == flash_Isok)//0x0A:����		
	{
		printf("\r\nStart Read EN25Q256....: \r\n");
		EN25Q256_Read(datatemp,Dev_version_start,len);			
		printf("\r\nThe Data Readed Is:  %s\r\n",datatemp);//��ʾ�������ַ���
		return 1;		
	}	
}

//3. ������Ƶ���ò���
void flash_manage::configrfparam(unsigned short int rf_power,unsigned char rf_frequency)
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
			this->host_dev_parm.RF_Power = tmp_write[0]<<8|tmp_write[1];  
			this->host_dev_parm.RF_Frequency = tmp_write[2];
			//���µ�ȫ�ֱ��� ���µ�flash�洢���� 
			flash_flag.rf_param_flag = flash_Isok;//0x0A:����					
			EN25Q256_Write(&flash_flag.rf_param_flag,rfparam_flag,1);
	
			//��Ƶ��������Ҫ���ó�ȥ
			//������������������������			
			printf("%d,ConfigRfPowerAck \n",host_dev_parm.RF_Power);		
			printf("%d,ConfigFrequencyAck \n",host_dev_parm.RF_Frequency);	
		}else{
			//flashд�벻���� ���µ�ȫ�ֱ��� 
			flash_flag.rf_param_flag = flash_Notok;//0x00:������	
			//ͬʱд�뵽flash
			EN25Q256_Write(&flash_flag.rf_param_flag,rfparam_flag,1);	
			printf("%d,ConfigRfPowerAck \n",host_dev_parm.RF_Power);		
			printf("%d,ConfigFrequencyAck \n",host_dev_parm.RF_Frequency);				
		}		
	}
}

//4.��ѯ��Ƶ����
u8 flash_manage::Getrfparam()
{
	u8 res = 0;
	//�洢��ʱ��ȡ���ݵ���ʱ����
	unsigned short int flash_temp_h = 0;
	unsigned short int flash_temp_l = 0;	
	u8 flashMessage_temp = 0;
	printf("Read flash Getrfparam....\r\n");
	EN25Q256_Read(&flashMessage_temp,rfparam_flag,1); 
	if(flashMessage_temp == flash_Isok)//0x0A:����
	{
		//flash�洢���� ���µ�ȫ�ֱ���
		//1.���±�־λ
		flash_flag.rf_param_flag = flash_Isok;//0x0A:����			
		//2.��ȡ�洢�豸��Ƶ���ò���  ��Ƶ����
		EN25Q256_Read((u8 *)&flash_temp_h,rfpower_h,1);//��Ƶ���ʸ�8λ RF_Power
		EN25Q256_Read((u8 *)&flash_temp_l,rfpower_l,1);//��Ƶ���ʵ�8λ RF_Power	
		this->host_dev_parm.RF_Power = (flash_temp_h<<8)|flash_temp_l;
		//3.��ȡ�洢�豸��Ƶ���ò���  ��ƵƵ��
		EN25Q256_Read(&this->host_dev_parm.RF_Frequency,rffrequency,1);//��ƵƵ��	
		res = 1;
	}else{
		res = 0;
		printf("rfparam_flag is not ok\n");
	}		
	printf("m_slave.RF_Power :%d\n",this->host_dev_parm.RF_Power);
	printf("m_slave.RF_Frequency :%d\n",this->host_dev_parm.RF_Frequency);	
	return res;	
}
//5. ���ö�������
void flash_manage::configcancellparam(struct SQU_DA_Value tmp)
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
			printf("The cancell is not save\n");
			flash_flag.cancell_save_flag = flash_Notok;		
			EN25Q256_Write(&flash_flag.cancell_save_flag,cancellsave_flag,1);				
		}
		
	}		
}

//6.��ѯ��������·��ѹ
u8 flash_manage::Getcancellparam()
{
	u8 res = 0;
	//�洢��ʱ��ȡ���ݵ���ʱ����
	unsigned short int flash_temp_h = 0;
	unsigned short int flash_temp_l = 0;	
	u8 flashMessage_temp = 0;
	printf("Read flash Getcancellparam....\r\n");
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
		EN25Q256_Read(&this->host_dev_parm.RF_Frequency,rffrequency,1);//��ƵƵ��	
		
		//��Ƶ��������Ҫ���ó�ȥ
		setDACValue(min_SquDAValue.Qp_DAValue,QP_CHANNEL);
		setDACValue(min_SquDAValue.Qn_DAValue,QN_CHANNEL);
		setDACValue(min_SquDAValue.Ip_DAValue,IP_CHANNEL);
		setDACValue(min_SquDAValue.In_DAValue,IN_CHANNEL);
		res = 0;
	}else{
		res = 1;
		printf("Getcancellparam is not ok\n");
	}
	printf("min_SquDAValue.Squ_Value=%lld,Qp_DA=%d,Qn_DA=%d,Ip_DA=%d,In_DA=%d\n",
			min_SquDAValue.Squ_Value,min_SquDAValue.Qp_DAValue,min_SquDAValue.Qn_DAValue,min_SquDAValue.Ip_DAValue,min_SquDAValue.In_DAValue);			
		
	return res;	
}