#include "flash_manage.h"
#include "EN25Q256.h"
#include "cancellation.h"
#include <string.h>
/*----------------flash操作------------------------*/
//0.默认构造
flash_manage::flash_manage()
{
	
}



//1.设置设备版本号
bool flash_manage::SetDerviceVersion(u8 *flashtmp,u8 len)
{
	u8 datatemp[60];
	printf("SIZE:%d\n",len);
	if(flashtmp == NULL) return false;
	printf("\r\nFALSH SetDerviceVersion Write: \r\n");
	EN25Q256_Write((u8*)flashtmp,Dev_version_start,len);		
	printf("\r\nThe Write DerviceVersion Is:%s\n",flashtmp);//显示读到的字符串		
	
	EN25Q256_Read(datatemp,Dev_version_start,len);					//从倒数第100个	
	printf("\r\nThe Read  DerviceVersion Is:%s\r\n",datatemp);//显示读到的字符串		
	if(strcmp((char *)datatemp,(char *)flashtmp) == 0) 
	{
		//flash存储正常 更新到全局变量
		flash_flag.Dev_flag = flash_Isok;//0x0A:正常					
		EN25Q256_Write(&flash_flag.Dev_flag,Dev_version_flag,1);		
		printf("DerviceVersion wirte success \n");
		return true;
	}else{
		flash_flag.Dev_flag = flash_Notok;//0x0A:正常					
		EN25Q256_Write(&flash_flag.Dev_flag,Dev_version_flag,1);		
		printf("DerviceVersion wirte false \n");		
		return false;
	}
}
//2.查询设备版本号
bool flash_manage::GetDerviceVersion(u8 *datatemp,u8 len)
{
	if(datatemp == NULL) return 0;
	EN25Q256_Read(&flash_flag.Dev_flag,Dev_version_flag,1);		
	if(flash_flag.Dev_flag == flash_Isok)//0x0A:正常		
	{
		printf("\r\nStart Read EN25Q256....: \r\n");
		EN25Q256_Read(datatemp,Dev_version_start,len);			
		printf("\r\nThe Data Readed Is:  %s\r\n",datatemp);//显示读到的字符串
		return 1;		
	}	
}

//3. 配置射频配置参数
void flash_manage::configrfparam(unsigned short int rf_power,unsigned char rf_frequency)
{
	u8 tmp_write[3] = {0};
	u8 tmp_read[3] = {0};
	printf("config ...\n");	
	if(flash_Dev_ok == flash_Isok)//flash 设备正常
	{
		//射频功率高8位
		tmp_write[0] = (rf_power>>8)&0xff;
		EN25Q256_Write(&tmp_write[0],rfpower_h,1);
		//射频功率低8位
		tmp_write[1] = rf_power&0xff;
		EN25Q256_Write(&tmp_write[1],rfpower_l,1);	
		//射频频点
		tmp_write[2] = rf_frequency;
		EN25Q256_Write(&tmp_write[2],rffrequency,1);			
		//射频功率和频点校验 读取连续三个 rfpower_h rfpower_l rffrequency
		EN25Q256_Read(tmp_read,rfpower_h,3);
		if((( tmp_write[0] = tmp_read[0] )&&( tmp_write[1] = tmp_read[1] ))||( tmp_write[2] = tmp_read[2] ))
		{
			//更新ram 数据,ram 状态标志位和 flash 标志位			
			this->host_dev_parm.RF_Power = tmp_write[0]<<8|tmp_write[1];  
			this->host_dev_parm.RF_Frequency = tmp_write[2];
			//更新到全局变量 更新到flash存储正常 
			flash_flag.rf_param_flag = flash_Isok;//0x0A:正常					
			EN25Q256_Write(&flash_flag.rf_param_flag,rfparam_flag,1);
	
			//射频参数还需要配置出去
			//。。。。。。。。。。。。			
			printf("%d,ConfigRfPowerAck \n",host_dev_parm.RF_Power);		
			printf("%d,ConfigFrequencyAck \n",host_dev_parm.RF_Frequency);	
		}else{
			//flash写入不正常 更新到全局变量 
			flash_flag.rf_param_flag = flash_Notok;//0x00:不正常	
			//同时写入到flash
			EN25Q256_Write(&flash_flag.rf_param_flag,rfparam_flag,1);	
			printf("%d,ConfigRfPowerAck \n",host_dev_parm.RF_Power);		
			printf("%d,ConfigFrequencyAck \n",host_dev_parm.RF_Frequency);				
		}		
	}
}

//4.查询射频参数
u8 flash_manage::Getrfparam()
{
	u8 res = 0;
	//存储临时读取数据的临时变量
	unsigned short int flash_temp_h = 0;
	unsigned short int flash_temp_l = 0;	
	u8 flashMessage_temp = 0;
	printf("Read flash Getrfparam....\r\n");
	EN25Q256_Read(&flashMessage_temp,rfparam_flag,1); 
	if(flashMessage_temp == flash_Isok)//0x0A:正常
	{
		//flash存储正常 更新到全局变量
		//1.更新标志位
		flash_flag.rf_param_flag = flash_Isok;//0x0A:正常			
		//2.读取存储设备射频配置参数  射频功率
		EN25Q256_Read((u8 *)&flash_temp_h,rfpower_h,1);//射频功率高8位 RF_Power
		EN25Q256_Read((u8 *)&flash_temp_l,rfpower_l,1);//射频功率低8位 RF_Power	
		this->host_dev_parm.RF_Power = (flash_temp_h<<8)|flash_temp_l;
		//3.读取存储设备射频配置参数  射频频点
		EN25Q256_Read(&this->host_dev_parm.RF_Frequency,rffrequency,1);//射频频点	
		res = 1;
	}else{
		res = 0;
		printf("rfparam_flag is not ok\n");
	}		
	printf("m_slave.RF_Power :%d\n",this->host_dev_parm.RF_Power);
	printf("m_slave.RF_Frequency :%d\n",this->host_dev_parm.RF_Frequency);	
	return res;	
}
//5. 配置对消参数
void flash_manage::configcancellparam(struct SQU_DA_Value tmp)
{
	u8 tmp_write[8] = {0};
	u8 tmp_read[8] = {0};
	//组帧
	tmp_write[0] = (tmp.Qp_DAValue>>8)&0xff;
	tmp_write[1] = (tmp.Qp_DAValue)&0xff;	
	
	tmp_write[2] = (tmp.Qn_DAValue>>8)&0xff;
	tmp_write[3] = (tmp.Qn_DAValue)&0xff;	

	tmp_write[4] = (tmp.Ip_DAValue>>8)&0xff;
	tmp_write[5] = (tmp.Ip_DAValue)&0xff;	
	
	tmp_write[6] = (tmp.In_DAValue>>8)&0xff;
	tmp_write[7] = (tmp.In_DAValue)&0xff;		
	
	printf("config ...\n");	
	if(flash_Dev_ok == flash_Isok)//flash 设备正常
	{
		//写入
		//Qp_DAValue高位
		EN25Q256_Write(&tmp_write[0],cancellqp_davalue_h,1);
		//Qp_DAValue低位
		EN25Q256_Write(&tmp_write[1],cancellqp_davalue_l,1);
		
		//Qn_DAValue高位
		EN25Q256_Write(&tmp_write[2],cancellqn_davalue_h,1);
		//Qn_DAValue低位
		EN25Q256_Write(&tmp_write[3],cancellqn_davalue_l,1);
		
		//Ip_DAValue高位
		EN25Q256_Write(&tmp_write[4],cancellip_davalue_h,1);
		//Ip_DAValue低位
		EN25Q256_Write(&tmp_write[5],cancellip_davalue_l,1);
		
		//In_DAValue高位
		EN25Q256_Write(&tmp_write[6],cancellin_davalue_h,1);
		//In_DAValue低位
		EN25Q256_Write(&tmp_write[7],cancellin_davalue_l,1);		
	
		//读取8个连续内存的对消控制电压数据
		EN25Q256_Read(tmp_read,cancellqp_davalue_h,8);
		//比对
		if( ( tmp_write[0] == tmp_read[0] )&&( tmp_write[1] == tmp_read[1])
			&&( tmp_write[2] == tmp_read[2] )&&( tmp_write[3] == tmp_read[3])
			&&( tmp_write[4] == tmp_read[4] )&&( tmp_write[5] == tmp_read[5])
			&&( tmp_write[6] == tmp_read[6] )&&( tmp_write[7] == tmp_read[7]))
		{
			//更新ram 状态标志位和 flash 标志位
			flash_flag.cancell_save_flag = flash_Isok;		
			EN25Q256_Write(&flash_flag.cancell_save_flag,cancellsave_flag,1);	
			
			//更新全局ram 数据
			min_SquDAValue = tmp;
			//射频参数还需要配置出去
			//。。。。。。。。。。。。
		}else{
			printf("The cancell is not save\n");
			flash_flag.cancell_save_flag = flash_Notok;		
			EN25Q256_Write(&flash_flag.cancell_save_flag,cancellsave_flag,1);				
		}
		
	}		
}

//6.查询对消的四路电压
u8 flash_manage::Getcancellparam()
{
	u8 res = 0;
	//存储临时读取数据的临时变量
	unsigned short int flash_temp_h = 0;
	unsigned short int flash_temp_l = 0;	
	u8 flashMessage_temp = 0;
	printf("Read flash Getcancellparam....\r\n");
	EN25Q256_Read(&flashMessage_temp,cancellsave_flag,1);	
	if(flashMessage_temp == flash_Isok)//0x0A:正常
	{
		//flash存储正常 更新到全局变量
		//1.更新标志位
		flash_flag.cancell_save_flag = flash_Isok;//0x0A:正常			
		//2.读取存储设备射频配置参数  射频功率
		flash_temp_h = flash_temp_l = 0;
		EN25Q256_Read((u8 *)&flash_temp_h,cancellqp_davalue_h,1);//Qp_DAValue高位
		EN25Q256_Read((u8 *)&flash_temp_l,cancellqp_davalue_l,1);//Qp_DAValue低位
		min_SquDAValue.Qp_DAValue = (flash_temp_h<<8)|flash_temp_l;

		flash_temp_h = flash_temp_l = 0;
		EN25Q256_Read((u8 *)&flash_temp_h,cancellqn_davalue_h,1);//Qn_DAValue高位
		EN25Q256_Read((u8 *)&flash_temp_l,cancellqn_davalue_l,1);//Qn_DAValue低位
		min_SquDAValue.Qn_DAValue = (flash_temp_h<<8)|flash_temp_l;
		
		flash_temp_h = flash_temp_l = 0;
		EN25Q256_Read((u8 *)&flash_temp_h,cancellip_davalue_h,1);//Ip_DAValue高位
		EN25Q256_Read((u8 *)&flash_temp_l,cancellip_davalue_l,1);//Ip_DAValue低位
		min_SquDAValue.Ip_DAValue = (flash_temp_h<<8)|flash_temp_l;			

		flash_temp_h = flash_temp_l = 0;
		EN25Q256_Read((u8 *)&flash_temp_h,cancellin_davalue_h,1);//In_DAValue高位
		EN25Q256_Read((u8 *)&flash_temp_l,cancellin_davalue_l,1);//In_DAValue低位
		min_SquDAValue.In_DAValue = (flash_temp_h<<8)|flash_temp_l;			
					
		//3.读取存储设备射频配置参数  射频频点
		flash_temp_h = flash_temp_l = 0;
		EN25Q256_Read(&this->host_dev_parm.RF_Frequency,rffrequency,1);//射频频点	
		
		//射频参数还需要配置出去
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