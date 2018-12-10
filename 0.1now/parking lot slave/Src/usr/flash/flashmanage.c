#include "flashmanage.h"
#include "EN25Q256.h" //flash 驱动和读写操作文件
#include "communication.h"
#include "cancellation.h"
#include <string.h>
//业务层的地址信息存储状态标志位
flash_save_flag flash_flag={0,0,0,0};//存储flash的信息正常标志位

//开机初始化 flash存储正常的话读取参数
void flashmanageinit()
{
	//存储临时读取数据的临时变量
	unsigned short int flash_temp_h = 0;
	unsigned short int flash_temp_l = 0;
	char datatemp[70] = {0};
	u8 flashMessage_temp = 0; //flash存储信息读取装载的临时变量
	u8 flash_temp = 0;
	//初始化完flash正常后
	if(flash_Dev_ok == flash_Isok)//芯片正常
	{
		//1.地址信息正常标志位	0x0A:正常 00:不正常
	  Get485addr();
		//2.射频配置参数正常标志位	0x0A:正常 00:不正常
    Getrfparam();
	  //3.读取对消值 对消值存储正常标志位	0x0A:正常 00:不正常	
		Getcancellparam();
		//4.查询设备版本号
		GetDerviceVersion((u8*)datatemp);	
		//提取地址
		//char str[] = "I we23|me any ideas from readers， of course.";
    char *lc = strchr(datatemp, '|');
		if(lc == NULL) return;
		char sit = lc - datatemp;//几号地址
    //printf("strchr: %d\n", sit );
		char num = (datatemp[sit-1]-0x30)+ (datatemp[sit-2]-0x30)*10;
		printf("addr: %d\n", num ); 
		
		//5.查询灯光的门槛数值
		Getflashthreshold();
	}
}

//1.设置设备版本号
const u8 Example_version[]={"BL-SR-200,BL1810301001"};
#define SIZE sizeof(Example_version)
void SetDerviceVersion(u8 *flashtmp,u8 len)
{
	char datatemp[60] = {0};
	printf("SIZE:%d\n",len);
	
	printf("\r\nFALSH SetDerviceVersion Write: \r\n");
	printf("\r\nThe flashtmp DerviceVersion Is:  %s\r\n",flashtmp);//显示读到的字符串	
	EN25Q256_Write((u8*)flashtmp,Dev_version_start,len);		

	printf("\r\nStart Read DerviceVersion....: \r\n");
	EN25Q256_Read((u8 *)datatemp,Dev_version_start,len);					//从倒数第100个	
	printf("\r\nThe DerviceVersion Is:%s\r\n",datatemp);  //显示读到的字符串		
	if(strcmp(datatemp,flashtmp) == 0) 
	{
		//flash存储正常 更新到全局变量
		flash_flag.Dev_flag = flash_Isok;//0x0A:正常					
		EN25Q256_Write(&flash_flag.Dev_flag,Dev_version_flag,1);		
		printf("DerviceVersion wirte success \n");
		
		//提取地址
		//char str[] = "I we23|me any ideas from readers， of course.";
    char *lc = strchr(datatemp, '|');
		if(lc == NULL) return;
		char sit = lc - datatemp;
    printf("strchr： %d\n", sit );
		char num = (datatemp[sit-1]-0x30)+ (datatemp[sit-2]-0x30)*10;
		printf("num %d\n", num ); 	

		config485addr(num);		
	}else{
		flash_flag.Dev_flag = flash_Notok;//0x0A:正常					
		EN25Q256_Write(&flash_flag.Dev_flag,Dev_version_flag,1);		
		printf("DerviceVersion wirte false \n");		
	}
}	

//2.查询设备版本号
void GetDerviceVersion(u8* datatemp)
{
  //	u8 datatemp[70];
	if (datatemp == NULL ) return;
	EN25Q256_Read(&flash_flag.Dev_flag,Dev_version_flag,1);	
	printf("Start Read EN25Q256....: \r\n");
	if(flash_flag.Dev_flag == flash_Isok)//0x0A:正常		
	{
		memset(datatemp,0,70);
		EN25Q256_Read(datatemp,Dev_version_start,56);			
		printf("\r\nThe Slave Message Is:%s\r\n",datatemp);//显示读到的字符串			
	}
}



//更新flash参数
//1. 配置485通信地址
void config485addr(u8 addr)
{
	u8 tmp_addr = 0;	
	printf("config ...\n");
	if(flash_Dev_ok == flash_Isok)//flash 设备正常
	{
		//485地址写入
		tmp_addr = addr;//从机地址 更新到ram tmp_addr中
		EN25Q256_Write(&tmp_addr,flash_dev_addr,1);
		//读取485地址校验
		EN25Q256_Read(&tmp_addr,flash_dev_addr,1);
		if(tmp_addr == addr)
		{
			//更新ram 状态标志位和 flash 标志位
			m_slave.Slave_Addr = tmp_addr;                
			//flash存储正常 更新到全局变量
			flash_flag.Slave_Addr_flag = flash_Isok;//0x0A:正常					
			EN25Q256_Write(&flash_flag.Slave_Addr_flag,addrMessage_flag,1);
			//MCU_To_MCU(m_slave.Slave_Addr,ConfigSlaveAddrAck);//ConfigSlaveAddrAck
		}else{
			//flash写入不正常 更新到全局变量 同时写入到flash
			flash_flag.Slave_Addr_flag = flash_Notok;//0x0A:正常					
			EN25Q256_Write(&flash_flag.Slave_Addr_flag,addrMessage_flag,1);
			//MCU_To_MCU(m_slave.Slave_Addr,ConfigSlaveAddrAck);//ConfigSlaveAddrAck			
		}
	}	
	printf("config salve addr  :%d\n",m_slave.Slave_Addr);	
}

u8 Get485addr()
{
	u8 res = 0;
	//1.地址信息正常标志位	0x0A:正常 00:不正常
	u8 flashMessage_temp = 0;
	EN25Q256_Read(&flashMessage_temp,addrMessage_flag,1);  //地址信息正常标志位	0x0A:正常 00:不正常
	if(flashMessage_temp == flash_Isok)//0x0A:正常
	{
		//flash存储正常 更新到全局变量
		flash_flag.Slave_Addr_flag = flash_Isok;//0x0A:正常
		//读取存储设备地址  485地址
		EN25Q256_Read(&m_slave.Slave_Addr,flash_dev_addr,1);//地址二代表节点地址	 slave_cpu	
		res = 1;
	}else{
		res = 0;
		printf("Slave_Addr_flag is not ok\n");
	}
	printf("slave_cpu :%d\n",m_slave.Slave_Addr);	
  return res; 	
}

//2. 配置射频配置参数
void configrfparam(unsigned short int rf_power,unsigned char rf_frequency)
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
			m_slave.RF_Power = tmp_write[0]<<8|tmp_write[1];  
			m_slave.RF_Frequency = tmp_write[2];
			//更新到全局变量 更新到flash存储正常 
			flash_flag.rf_param_flag = flash_Isok;//0x0A:正常					
			EN25Q256_Write(&flash_flag.rf_param_flag,rfparam_flag,1);
//			MCU_To_MCU(m_slave.Slave_Addr,ConfigRfPowerAck);//ConfigRfPowerAck
//			MCU_To_MCU(m_slave.Slave_Addr,ConfigFrequencyAck);//	
	
			//射频参数还需要配置出去
			//。。。。。。。。。。。。			
			printf("%d,ConfigRfPowerAck success \n",m_slave.RF_Power);		
			printf("%d,ConfigFrequencyAck success \n",m_slave.RF_Frequency);	
		}else{
			//flash写入不正常 更新到全局变量 
			flash_flag.rf_param_flag = flash_Notok;//0x00:不正常	
			//同时写入到flash
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
	//存储临时读取数据的临时变量
	unsigned short int flash_temp_h = 0;
	unsigned short int flash_temp_l = 0;	
	u8 flashMessage_temp = 0;
	EN25Q256_Read(&flashMessage_temp,rfparam_flag,1); 
	if(flashMessage_temp == flash_Isok)//0x0A:正常
	{
		//flash存储正常 更新到全局变量
		//1.更新标志位
		flash_flag.rf_param_flag = flash_Isok;//0x0A:正常			
		//2.读取存储设备射频配置参数  射频功率
		EN25Q256_Read((u8 *)&flash_temp_h,rfpower_h,1);//射频功率高8位 RF_Power
		EN25Q256_Read((u8 *)&flash_temp_l,rfpower_l,1);//射频功率低8位 RF_Power
		m_slave.RF_Power = (flash_temp_h<<8)|flash_temp_l;
		
		//3.读取存储设备射频配置参数  射频频点
		EN25Q256_Read(&m_slave.RF_Frequency,rffrequency,1);//射频频点	
		res = 1;
	}else{
		res = 0;
		printf("rfparam_flag is not ok\n");
	}		
	printf("m_slave.RF_Power :%d\n",m_slave.RF_Power);
	printf("m_slave.RF_Frequency :%d\n",m_slave.RF_Frequency);	
	return res;	
}

//3. 配置对消参数
void configcancellparam(struct SQU_DA_Value tmp)
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
			flash_flag.cancell_save_flag = flash_Notok;		
			EN25Q256_Write(&flash_flag.cancell_save_flag,cancellsave_flag,1);				
		}	
	}		
}

u8 Getcancellparam()
{
	u8 res = 0;
	//存储临时读取数据的临时变量
	unsigned short int flash_temp_h = 0;
	unsigned short int flash_temp_l = 0;	
	u8 flashMessage_temp = 0;
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
		EN25Q256_Read(&m_slave.RF_Frequency,rffrequency,1);//射频频点	
		
		//射频参数还需要配置出去
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

//5. 配置门槛的数值
void flashthreshold(u8 threshold)
{
	u8 tmp_threshold = 0;	
	printf("flash config threshold...\n");
	if(flash_Dev_ok == flash_Isok)//flash 设备正常
	{
		//门槛数值按地址写入
		tmp_threshold = threshold;//从机地址 更新到ram tmp_addr中
		EN25Q256_Write(&tmp_threshold,flash_threshold,1);
		//读取门槛校验
		EN25Q256_Read(&tmp_threshold,flash_threshold,1);
		if(tmp_threshold == threshold)
		{
			//更新ram 状态标志位和 flash 标志位
			m_slave.readcarthreshold = tmp_threshold;                
			//flash存储正常 更新到全局变量
			flash_flag.readcar_threshold_flag = flash_Isok;//0x0A:正常					
			EN25Q256_Write(&flash_flag.readcar_threshold_flag,flash_threshold_flag,1);
			
		}else{
			//flash写入不正常 更新到全局变量 同时写入到flash
			flash_flag.readcar_threshold_flag = flash_Notok;//0x0A:正常					
			EN25Q256_Write(&flash_flag.readcar_threshold_flag,flash_threshold_flag,1);
		
		}
	}	
	printf("readcarthreshold config: %d\n",m_slave.readcarthreshold);		
}

u8 Getflashthreshold()
{
	u8 res = 0;
	//1.门槛的数值信息 正常标志位	0x0A:正常 00:不正常
	u8 flashMessage_temp = 0;
	EN25Q256_Read(&flashMessage_temp,flash_threshold_flag,1);  //地址信息正常标志位	0x0A:正常 00:不正常
	if(flashMessage_temp == flash_Isok)//0x0A:正常
	{
		//flash存储正常 更新到全局变量
		flash_flag.readcar_threshold_flag = flash_Isok;//0x0A:正常
		//读取门槛的数值
		EN25Q256_Read(&m_slave.readcarthreshold,flash_threshold,1);//地址二代表节点地址	 slave_cpu	
		res = 1;
	}else{
		res = 0;
		printf("Getflashthreshold is not ok\n");
	}
	printf("Getflashthreshold :%d\n",m_slave.readcarthreshold);	
  return res; 		
}