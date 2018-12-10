#include "read_manage.h"
#include "EN25Q256.h"
#include <map>
#include "rx485_rev.h"
#include "rx485_send.h"
#include "RX485_uart.h"
#include "communication.h"
#include "systick.h"
#include "buzzer_led.h"
#include "key_exit.h"
#include "air_interface.h"	
#include "rf_oper.h"
#include "LMX2541.h"
#include "cancellation.h"
#include <string.h>
#include <stdio.h>
#include "radar_model.h"
#include "main_application.h"
#include "cancellation.h"
#include "main.h"
using namespace std;
//默认构造
read_manage::read_manage()
{
  u8 temp = 0;
	//初始化为 正式灯光模式
	led_mode = 1;	
	//读卡轮数为0
	SelectStep = 0;
	//没有车
	hasCar = 0;
	//模式默认为主读卡
	selcet_some_dev_R = 0;	
	//
	readcarthreshold = 10;
	current_dev = 0;//默认先操作主机节点
	//构造默认初始化节点的(ID,Address)
   host_dev_parm.RF_Frequency = 0;
   host_dev_parm.RF_Power = 3600;	
	//上电读取FLash中存储的节点数量
	if(EN25Q256_ReadID() == EN25Q256_ID)//判断Flash是否正常
	{
		//Flash 设备正常
		flash_Dev_ok =  flash_Isok;
		
		EN25Q256_Read(&temp,flash_ok,1);//查询是否有有效的配置信息
		//存储正常
		write_ok = temp;
		if(write_ok == flash_Isok)//地址一代表Flash 石否有存储
		{
			  temp = 0; 
				EN25Q256_Read(&temp,flash_num,1);//地址二代表节点数量	
				this->slave_num  =	temp;	

				//1.上电的第一次查询应该从flash读取有效数据
				GetNodeInfoFromFlash();
				//2.射频配置参数正常标志位	0x0A:正常 00:不正常
				Getrfparam();
				//3.读取对消值 对消值存储正常标志位	0x0A:正常 00:不正常	
				Getcancellparam();
				//4.在位检测门槛
			  Getflashthreshold();
				//5.设备SN
				uint8_t versionnum[20];
				uint8_t numL = 15;
				//printf("numl :%d",numL);					
				GetDerviceVersion(versionnum,numL);
				//uint8_t p[] = "BL1810302002";
				llrp_u64_t sn = strToHex(versionnum+3);			
				g_pMainApplication->Devicesn = sn;
				printf("DeviceSN:%llx\n",sn);
					
		}else
		{
					salve_dev.insert(pair<unsigned char,unsigned char>(0,0));
					salve_dev.insert(pair<unsigned char,unsigned char>(1,1));
					salve_dev.insert(pair<unsigned char,unsigned char>(2,2));
					salve_dev.insert(pair<unsigned char,unsigned char>(3,3));
					salve_dev.insert(pair<unsigned char,unsigned char>(4,4));
					salve_dev.insert(pair<unsigned char,unsigned char>(5,5));
					salve_dev.insert(pair<unsigned char,unsigned char>(6,6));
					salve_dev.insert(pair<unsigned char,unsigned char>(7,7));	
					salve_dev.insert(pair<unsigned char,unsigned char>(8,8));
					salve_dev.insert(pair<unsigned char,unsigned char>(9,9));
					salve_dev.insert(pair<unsigned char,unsigned char>(10,10));	
		}	
	}
	else
	{
			//Flash 设备不正常
			flash_Dev_ok =  flash_Notok;
			//存储不正常
			write_ok = flash_Notok;		
			this->slave_num = 8;//构造初始化默认设置为8
	}		

	this->current_dev = salve_dev[0];//默认先操作主机
}

//析构
read_manage::~read_manage(){}
	
//设置节点数量		
bool read_manage::SetNodeCountToFlash(unsigned char num){//设置节点数量	
	u8 temp = 0 ;
	//烧写到Flash
	if(flash_Dev_ok == flash_Isok)//设备正常
	{
		EN25Q256_Write(&num,flash_num,1);
		EN25Q256_Read(&temp,flash_num,1);
		if(temp == num)//烧录成功
		{		
			this->slave_num = num;
			this->write_ok = flash_Isok;//flash信息正常
			EN25Q256_Write(&this->write_ok,flash_ok,1);
		}else{
			//节点数量不改变
			this->write_ok = flash_Notok;//flash信息不正常
			EN25Q256_Write(&this->write_ok,flash_ok,1);		
		}	
	}else{
		//Flash不正常认为存储的信息也不正常
		this->write_ok = flash_Notok;//flash信息不正常
	}
	return true;
}
//获取节点数量
unsigned char read_manage::GetNodeCountFromFlash()
{ 
	u8 temp;
	//判断存储有有效分配的flash分配信息
	if(this->write_ok == flash_Isok)
	{
		EN25Q256_Read(&temp,flash_num,1);
		this->slave_num = temp;
		return this->slave_num;
	}	
  return this->slave_num;//不做修改直接返回
}

bool  read_manage::SetNodeInfoToFlash(std::map<unsigned char,unsigned char> nodeInfo)//设置节点信息(ID,Address)
{
	//将信息拷贝到map容器和烧录到Flash
	u8 temp = 0;
	u8 num = 0;
	printf("into SetNodeInfoToFlash \n");
	if (nodeInfo.size() <=0)
	{
		printf("nodeInfo.size() <= 0 ,return false\n");
		return false;
	}
	salve_dev_new.clear();
	//先记录拷贝到RAM  salve_dev_new新的配置 , 然后在烧录到FLASH
	for (std::map<unsigned char,unsigned char>::iterator it = nodeInfo.begin();it != nodeInfo.end();it++)
	{	
		salve_dev_new[it->first] = it->second;
	}
	//烧写到Flash
	if(flash_Dev_ok == flash_Isok)//设备正常
	{
			//烧录之前认为内容不正常
			this->write_ok = flash_Notok;//flash信息不正常
			//烧录到flash 认为不正常
			EN25Q256_Write(&this->write_ok,flash_ok,1);
			u8 deviceCount = 0;
		    EN25Q256_Read(&deviceCount,flash_num,1);
		    map<unsigned char,unsigned char>::iterator it = salve_dev_new.begin();
		    u8 addr = flash_addr1;
  		    //烧录节点信息		
			for(int i = 0;i < deviceCount;i++)
		    {			
				if (it != salve_dev_new.end())
				{
					EN25Q256_Write(&salve_dev_new[it->first],addr,1);
					it++;
					addr++;
				}
				else
				{
					break;
				}
		    }	
		  	//校验成功
			//更新到从机成功，更新到RAM
			//先记录拷贝到RAM  salve_dev_new新的配置
			for (std::map<unsigned char,unsigned char>::iterator it = salve_dev_new.begin();it != salve_dev_new.end();it++)
			{	
				salve_dev[it->first] = it->second ;
			}			
			//校验后认为内容正常
			this->write_ok = flash_Isok;//flash信息不正常
			//烧录到flash 认为正常
			EN25Q256_Write(&this->write_ok,flash_ok,1);		
			printf("flash write suc , return true\n");
			return true;
	}	
	printf("flash is no ready,return false\n");
	return false;
}

//ID addr
std::map<unsigned char,unsigned char>  read_manage::GetNodeInfoFromFlash(){          //查询设备节点配置信息
	u8 temp = 0;
	map<unsigned char,unsigned char> deviceInfo;
	EN25Q256_Read(&temp,flash_ok,1);
	printf("flash_ok :%x\n",temp);
	salve_dev.clear();//清除RAM中的数据
	//从Flash中以节点数量读取节点信息
	if(temp == flash_Isok)
	{
			//1.读取节点数量
			u8 deviceCount = 0;
		  EN25Q256_Read(&deviceCount,flash_num,1);
		  //map<u8,u8>::iterator it = salve_dev.begin();
			u8 addrtemp = flash_addr1;
		    //2.按数量读取节点信息 主机Flash
			for (int i = 0; i< deviceCount;i++)
			{
				EN25Q256_Read(&salve_dev[i+1],addrtemp,1);
				addrtemp ++;
			}
			salve_dev[0] = 0;//主机地址任意 主机按照节点号 0号节点
			//3.从机Flash
//			for (int i = 0; i< deviceCount;i++)
//			{
//				EN25Q256_Read(&salve_dev[i+1],addrtemp,1);
//				addrtemp ++;
//			}
	}
	return this->salve_dev;
}

//设置从机设备,从机设备出厂后后期地址任意不组织重新配置节点地址
bool read_manage::SetSlave_Addr(unsigned char addr,unsigned char addr_new)//每一个机器的从机设备地址
{
	u8 tmp_ack = 0;
	u8 reback[20] = {0};
	//配置从机时重新从FLASH中更新到RAM salve_dev
	//GetNodeInfoFromFlash();
	//对应flash的节点号下地址信息salve_dev[num]
	//配置 之前flash保存的内容为通信ID
//	printf("ConfigSlaveAddr %d change to %d\n",addr,addr_new);	
//	MCU_To_MCU(addr,ConfigSlaveAddr,addr_new); 
	printf("SetSlave_Addr %d change to %d\n",0,addr_new);	
	MCU_To_MCU(0,ConfigSlaveAddr,addr_new); 	
	Device_cpu = addr_new;	
	//等待返回
	tmp_ack = waitSlaveAck(ConfigSlaveAddrAck,500);
	//printf("waitSlaveAck :%d\n",tmp_ack);	
	if(1==tmp_ack)
	{
		printf("SetSlave_Addr success \n");	
		return true;
	}	
	printf("SetSlave_Addr false \n");	
	return false;
}

bool read_manage::GetSlave_Addr(unsigned char slave_add)//对应一个机器的从机设备地址
{
	u8 tmp_ack = 0;
	u8 reback[20] ={0};
	MCU_To_MCU(slave_add,GetSlaveAddr,0); //发出请求
	Device_cpu = slave_add;
	//等待返回
	tmp_ack = waitSlaveAckData(GetSlaveAddrAck,reback,RX485_recFrameLen-4,500);;
	//printf("waitSlaveAck :%d\n",tmp_ack);	
	if(1==tmp_ack)
	{
		printf("GetSlave_Addr :%d ok\n",slave_add);
		return true;
	}
		printf("GetSlave_Addr :%d flase\n",slave_add);	
	return false;
}


//从节点设备信息配置
bool read_manage::SetSlave_Message(unsigned char addr,unsigned char *buf,unsigned char len)
{
	if(buf == NULL) return false;
	u8 tmp_ack = 0;
	memset(RX485_TxMessage,0,RX485_MAX_TX_LEN);//RX485_TxMessage
	RX485_TxMessage[0] = SetSlaveMessage;
  memcpy(RX485_TxMessage+1,buf,len+1);
  printf("RX485_TxMessage :%s\n",RX485_TxMessage+1);
	sendCommData(MASTER_CPU ,addr,CPU_MODE,RX485_TxMessage,len+1);
	
	Device_cpu = addr;	
	//等待返回
	tmp_ack = waitSlaveAck(SetSlaveMessageAck,700);
	if(1==tmp_ack)
	{
		printf("SetSlave_Message%d ,ok\n",addr);	
		return true;
	}	
	  printf("SetSlave_Message%d ,flase\n",addr);	
	
	return false;	
}
//从节点设备信息查询
//buf  接受前端返回的字符串帧:Address:234|SN: BL1810303020|Type: BL-MR-200| Version:V3.2.9
bool read_manage::GetSlave_Message(unsigned char addr,unsigned char *buf,unsigned char len)
{
	if(buf == NULL) return false;

	MCU_To_MCU(addr,GetSlaveMessage,0);//从节点设备信息查询
	Device_cpu = addr;	
	//等待返回
	u8 tmp_ack = waitSlaveAckData(GetSlaveMessageAck,buf,len,5000);
	printf("Get message :%s\n",buf);
	if(1==tmp_ack)
	{
		printf("GetSlaveMessage%d ,ok\n",addr);	
		return true;
	}	
	  printf("GetSlaveMessage%d ,flase\n",addr);	
	
	return false;		
}	



//配置射频功率 
bool read_manage::ConfigRf_Power(u8 slave_id,u32 value)
{
	u8 tmp_ack = 0;
	if(slave_id == 0)//主机ID为0
	{
			this->host_dev_parm.RF_Power = value;//设置主机射频功率 
		  configrfparam(this->host_dev_parm.RF_Power,this->host_dev_parm.RF_Frequency);
		  tmp_ack = 1;//设置射频功率 结束
	}else{//从节点	
		MCU_To_MCU(slave_id,ConfigRfPower,value);//配置射频功率
		Device_cpu = slave_id;	
		//等待返回
		tmp_ack = waitSlaveAck(ConfigRfPowerAck,500);
	}
	if(1==tmp_ack)
	{
		printf("ConfigRf_Power%d : %d,ok\n",slave_id,value);	
		return true;
	}	
	  printf("ConfigRf_Power%d :%d,flase\n",slave_id,value);	
	
	return false;	
}
//查询从节点的射频功率值
bool read_manage::GetSlaveRf_Power(u8 slave_id,unsigned short int * value)//返回数值和是否成功
{
	u8 tmp_ack = 0;
	u8 reback[2] ={0};
  u16 data; 
	if(slave_id == 0)//主机ID为0
	{
		  *value = this->host_dev_parm.RF_Power ;//获取主机射频功率 
		  tmp_ack = 1;//设置射频功率 结束
	}else{//从节点	
    value[0] = value[1]	= 0;	
		MCU_To_MCU(slave_id,GetSlaveRfPower,0);//查询从节点射频功率值
		Device_cpu = slave_id;	
		//等待返回
		tmp_ack = waitSlaveAckData(GetSlaveRfPowerAck,reback,2,500);
		data = reback[0]<<8|reback[1];
		*value = data;
	}	
	if(1==tmp_ack)
	{
		printf("GetSlaveRfPowerAck %d:%d ok\n",slave_id,data);	
		return true;
	}	
	printf("GetSlaveRfPowerAck %d:%d false\n",slave_id,data);	
	return false;		
}

//设置从节点的射频频点
bool read_manage::Config_Frequency(u8 slave_id,u32 value)
{
	u8 tmp_ack = 0;
	if(slave_id == 0)//主机ID为0 地址为0
	{
			this->host_dev_parm.RF_Frequency = value;//设置主机频点
		  LMX2541_SetFrequency(this->host_dev_parm.RF_Frequency); 
	  	configrfparam(this->host_dev_parm.RF_Power,this->host_dev_parm.RF_Frequency);
		  tmp_ack = 1;//设置频点结束
	}else{//从节点
		MCU_To_MCU(slave_id,ConfigFrequency,value);//配置射频频点 
		Device_cpu = slave_id;	
		//等待返回
		tmp_ack = waitSlaveAck(ConfigFrequencyAck,500);
	}
	if(1==tmp_ack)
	{
		printf("Config_Frequency %d:%d ok\n",slave_id,value);	
		return true;
	}	
	printf("Config_Frequency %d:%d false\n",slave_id,value);	
	return false;		
	
}
//查询从节点频点
bool read_manage::GetSlave_Frequency(u8 slave_id,unsigned char * value)//返回数值和是否成功
{
	u8 tmp_ack = 0;	
	if(slave_id == 0)//主机ID为0
	{
		*value = this->host_dev_parm.RF_Frequency;//获取主机频点
		tmp_ack = 1;//设置频点结束
	}else{//从节点
		*value = 0;
		MCU_To_MCU(slave_id,GetSlaveFrequency,0);//查询从节点射频功率值
		Device_cpu = slave_id;	
		//等待返回
		tmp_ack = waitSlaveAckData(GetSlaveFrequencyAck,value,1,500);
	}
	if(1==tmp_ack)
	{
		printf("GetSlave_Frequency %d:%d ok\n",slave_id,*value);	
		return true;
	}	
	printf("GetSlave_Frequency %d:%d false\n",slave_id,*value);	
	return false;		
}


//设置从节点 开关载波
bool read_manage::Config_Carrier(u8 slave_id,u8 value)
{
	u8 tmp_ack = 0;
	if(slave_id == 0)//主机ID为0
	{
		ConfigHost_Carrier(value);//主机开载波
		tmp_ack = 1;//开载波结束
	}else{//从节点
		MCU_To_MCU(slave_id,ConfigCarrier,value);//1 开载波  0关 
		Device_cpu = slave_id;	
		//等待返回
		tmp_ack = waitSlaveAck(ConfigCarrierAck,500);
	}
	if(1==tmp_ack)
	{
		printf("Config_Carrier %d :%d  ok\n",slave_id,value);
		return true;
	}	
		printf("Config_Carrier %d :%d false\n",slave_id,value);
	return false;		
	
}
//设置从节点 对消 开始对消 和停止对消
bool read_manage::Config_Cancellation(u8 slave_id,unsigned char *value)
{
	u8 tmp_ack = 0;
  uint64_t data = 0; 
	if(slave_id == 0)//主机ID为0
	{
		ConfigHost_cancell();//主机对消
		//组帧 还原64为对消值
		for(int i=0;i<8;i++)
		{
			value[i] =min_SquDAValue.Squ_Value>>(8*(7-i))&0xff;
		}
		tmp_ack = 1;//对消结束
	}else{//从节点
		printf("ConfigCancellation :%d\n",slave_id);
		MCU_To_MCU(slave_id,ConfigCancellation,0);//对消
		Device_cpu = slave_id;	
		//等待返回
		tmp_ack = waitSlaveAckData(ConfigCancellationAck,value,8,4000000);			
	}
	//组帧 还原64为对消值
	for(int i=0;i<8;i++)
	{
		data = data<<8;
		data = data | value[i];
	}
	
	if(1==tmp_ack)
	{
		printf("Config_Cancellation %d :%lld  ok\n",slave_id,data);
		return true;
	}	
	printf("Config_Cancellation %d :%lld  false\n",slave_id,data);
	return false;		
}
//一键对消
bool read_manage::SetSlave_cancell(unsigned char *value)
{
		for(u8 i = 0 ;i <=slave_num;i++) 
		{	
			Config_Cancellation(salve_dev[i],value);
		}
}

//查询从节点 对消值
bool read_manage::GetSlave_Cancellation(u8 slave_id,unsigned char *value)
{
	u8 tmp_ack = 0;
	//u8 reback[8] ={0};
  uint64_t data = 0; 	
	if(slave_id == 0)//主机ID为0
	{
			//组帧 还原64为对消值
		for(int i=0;i<8;i++)
		{
			value[i] = min_SquDAValue.Squ_Value  >>(8*(7-i))&0xff;
		}
		tmp_ack = 1;
	}else{//从节点
		for(int i = 0;i<8;i++)
		{
			value[i] = 0;	
		}
		MCU_To_MCU(slave_id,GetSlaveCancellation,0);//查询从节点射频功率值
		Device_cpu = slave_id;	
		//等待返回
			tmp_ack = waitSlaveAckData(GetSlaveCancellationAck,value,8,500);			
	}

	//组帧 还原64为对消值
	for(int i=0;i<8;i++)
	{
		data = data<<8;
		data = data | value[i];
	}
	if(1==tmp_ack)
	{
		printf("GetSlave_Cancellation %d :%lld  ok\n",slave_id,data);
		return true;
	}	
	printf("GetSlave_Cancellation %d :%lld  ok\n",slave_id,data);
	return false;	
}

//设置从节点 灯光模式
bool read_manage::Config_LedMode(u8 slave_id,u8 value)
{
	u8 tmp_ack = 0;
	if(slave_id == 0)//主机ID为0
	{
		led_mode = value;
		//1.关闭定时器
		TIM_Cmd(TIM2, DISABLE);//使能TIMx 
		BUZZER_LED_H;//绿色		
		if(this->slave_num == 0)//只有主机
		{
			tmp_ack = 1;//灯光模式配置结束
		}	
	}else{//从节点
		MCU_To_MCU(slave_id,ConfigLedMode,value);//1 发行  0测试 
		Device_cpu = slave_id;	
		//等待返回
		tmp_ack = waitSlaveAck(ConfigLedModeAck,500);
	}
	if(1==tmp_ack)
	{
		printf("ConfigLedMode %d :%d  ok\n",slave_id,value);
		return true;
	}	
		printf("ConfigLedMode %d :%d false\n",slave_id,value);
	return false;	
}
//查询从节点 灯光模式
bool read_manage::GetSlave_LedMode(u8 slave_id,unsigned char *value)
{
	u8 tmp_ack = 0;	
	//检测传入指针安全性
	if(value == NULL) return 0;	
	if(slave_id == 0)//主机ID为0
	{
		*value = led_mode;//获取主机频点
		tmp_ack = 1;//设置频点结束
	}else{//从节点
		*value = 0;
		MCU_To_MCU(slave_id,GetLedMode,0);//查询从节点射频功率值
		Device_cpu = slave_id;	
		//等待返回
		tmp_ack = waitSlaveAckData(GetLedModeAck,value,1,500);
	}
	if(1==tmp_ack)
	{
		printf("GetLedMode %d:%d ok\n",slave_id,*value);	
		return true;
	}	
	printf("GetLedMode %d:%d false\n",slave_id,*value);	
	return false;
}		

//设置从节点 车辆在位检测门槛数值
bool read_manage::Config_LedThreshold(u8 slave_id,u8 value)
{
	u8 tmp_ack = 0;
	if(slave_id == 0)//主机ID为0
	{
		 this->readcarthreshold = value;
		//1.关闭定时器
		TIM_Cmd(TIM2, DISABLE);//使能TIMx 
		BUZZER_LED_H;//绿色		
		if(this->slave_num == 0)//只有主机
		{
			tmp_ack = 1;//车辆在位检测门槛配置结束
		}	
	}else{//从节点
		MCU_To_MCU(slave_id,ConfigLedThreshold,value);//1 发行  0测试 
		Device_cpu = slave_id;	
		//等待返回
		tmp_ack = waitSlaveAck(ConfigLedThresholdAck,500);
	}
	if(1==tmp_ack)
	{
		printf("ConfigLedThreshold %d :%d  ok\n",slave_id,value);
		return true;
	}	
		printf("ConfigLedThreshold %d :%d false\n",slave_id,value);
	return false;		
}
//查询从节点 车辆在位检测门槛
bool read_manage::GetSlave_LedThreshold(u8 slave_id,unsigned char *value)
{
	u8 tmp_ack = 0;	
	//检测传入指针安全性
	if(value == NULL) return 0;
	if(slave_id == 0)//主机ID为0
	{
		*value = led_mode;//获取主机频点
		tmp_ack = 1;//设置频点结束
	}else{//从节点
		*value = 0;
		MCU_To_MCU(slave_id,GetSlaveLedThreshold,0);//查询从节点射频功率值
		Device_cpu = slave_id;	
		//等待返回
		tmp_ack = waitSlaveAckData(GetSlaveLedThresholdAck,value,1,500);
	}
	if(1==tmp_ack)
	{
		printf("GetLedMode %d:%d ok\n",slave_id,*value);	
		return true;
	}	
	printf("GetLedMode %d:%d false\n",slave_id,*value);	
	return false;	
}

//查询从节点的雷达数据
bool read_manage::GetSlaveRadar(u8 slave_id,unsigned short int * value)
{
	u8 tmp_ack = 0;
	u8 reback[2] ={0};
  u16 data; 
	if(slave_id == 0)//主机ID为0
	{
			this->host_dev_parm.radar_distance = radar_read();
		  *value = this->host_dev_parm.radar_distance;//获取主机雷达数据
		  tmp_ack = 1;
	}else{//从节点	
    value[0] = value[1]	= 0;	
		MCU_To_MCU(slave_id,GetRadarDistance,0);//查询从节点的雷达数据
		Device_cpu = slave_id;	
		//等待返回
		tmp_ack = waitSlaveAckData(GetRadarDistanceAck,reback,2,500);
		data = reback[0]<<8|reback[1];
		*value = data;
	}	
	if(1==tmp_ack)
	{
		printf("GetRadarDistance %d:%d ok\n",slave_id,data);	
		return true;
	}	
	printf("GetRadarDistance %d:%d false\n",slave_id,data);	
	return false;		
}
//单节点读卡 选择节点 启动或者关闭单节点读卡模式 运行Run
bool read_manage::SendRadarData(unsigned short int radar_distance)
{
		CManufacturerReport *preportmessage =  (CManufacturerReport *)ExtendHbFrame_Operation::genMessage(ManufacturerReport,0);			
	  //3.发送响应
		llrp_u8v_t bytes = llrp_u8v_t(6); 									
		//2.1雷达信息查询的检测查询			
		bytes.m_pValue[0] = 0x36;  					
		bytes.m_pValue[1] = 0x00;           
		bytes.m_pValue[2] = 0x03;
		bytes.m_pValue[3] = this->current_dev;//当前节点ID
		bytes.m_pValue[4] = (radar_distance>>8)&0xff;		//射频功率
		bytes.m_pValue[5] =  radar_distance&0xff;		//射频功率						
		preportmessage->setByteStream(bytes);	
		if(preportmessage!=NULL)
		{				
			//printf("pMessage->getMessageID() :%d\n",pMessage->getMessageID());
			if(false == g_pMainApplication->getSerialComm()->immediateSendMessage(preportmessage,0))
			{
					printf("send ack fail!\n");
			}		
			delete preportmessage;				
		}		
	 	
	
}

bool read_manage::select_dev_Read(u8 slave_id,u8 mode)
{
	//选择节点号  slave_id
	current_dev = slave_id;
	printf("current_dev:%d\n",current_dev);
	//启动或者关闭单节点读卡模式
	this->selcet_some_dev_R = mode;
	printf("this->selcet_some_dev_R:%d \n",this->selcet_some_dev_R);
	
	return true;
	//运行Run
}


/*                            主机单元                     */
//控制主机对消
bool read_manage::ConfigHost_cancell()
{
	RFPowerON(this->host_dev_parm.RF_Power);	
	LMX2541_SetFrequency(this->host_dev_parm.RF_Frequency); 
  BUZZER_LED_L;//红色 
	Cancellation();//对消中闪烁
	RFPowerOFF();	
	configcancellparam(min_SquDAValue);
	BUZZER_LED_H;//绿色	
}

//主机开载波
bool read_manage::ConfigHost_Carrier(u8 mode)//主机载波控制
{
	if(mode)
	{
		RFPowerON(this->host_dev_parm.RF_Power);	
	}
	else{
		RFPowerOFF();	
	}
}



/*
* slave_num 节点数量
* cur_dev 当前读卡的节点                 
* 主机属于0号节点 从机器节点顺序是连续的
*/
void read_manage::Switch_Device(u8 cur_dev)//前端读卡设备切换
{
	//判断节点数的设置、得到最后一个节点号
	//if(current_dev == SLAVE_CPU10)//如果当前的设备为最后一个节点
	printf("slave_num:%d\n",this->slave_num);
	if(cur_dev >= this->slave_num)//如果当前的设备为最后一个节点转为0号主机读卡
	{
		//开始起主机读卡
		this->current_dev = 0;//切换为第一个节点cpu 主机读卡
	}else{
		this->current_dev = cur_dev+1;//切换为另外一个节点cpu		
	}
}
/*
* 停止当前节点 开始 下个节点
* 节点号是连续的,1 号 2号 3号节点
* 地址是随机配的20 56 78 89
*/
uint8_t radar_run = 0;
u8 ReadCard_Count = 0;
void read_manage::change_Device()
{
  uint8_t bState = 0;
	//切换从下一个节点前保证主机把数据读取上报完了	
	this->Switch_Device(this->current_dev);//传入当前的节点设备
	//开始下一个节点设备
	printf("start:%d,adrr:%d\n",current_dev,salve_dev[current_dev]);
	if(this->current_dev != 0)//开始主机节点
	{
		Device_cpu = salve_dev[current_dev];//当前接收处理的从机器地址
		MCU_To_MCU(Device_cpu,StartReadCard,0);	
	}else{
		host_read();
	}	
	//重新记次数
	current_dev_count = 0;//当前新节点从零开始
}

void  read_manage::isturehasTag(u8 bState)
{
	//第一次读取到标签                          启动闪烁
	//在之后的第4到7次来判断 车辆是否依旧存在  （停留）存在红色，（路过）不存在绿色
	//确定有车后检测是否依旧在  								从有车后每5次都不在则认为真的离开了
	switch(SelectStep)
	{
		case 0: 
		{ //第一次读取到标签
			if( bState == GL_OK ||GL_OVER == bState)
			{
				printf("....................Has car coming....................\n");
				//启动定时器
		    TIM_Cmd(TIM2, ENABLE);//使能TIMx 
				hasCar = 0; 
				//算第一次轮询
				ReadCard_Count = 0;
				SelectStep = 1;
			}	
		}		
		break;
		
		case 1:
		{
			if(ReadCard_Count <= readcarthreshold)//10轮之后 在连续 连续读取到的次数作为判别依据
			{
				if( bState == GL_OK ||GL_OVER == bState)
				{			
          hasCar++;				
				}		
			  printf("ReadCard_Count :%d,hasCar:%d\n",ReadCard_Count,hasCar);
	  	}
			if((ReadCard_Count>=readcarthreshold) || hasCar >= 1)//(readcarthreshold/2))//10轮之后统计下次数是否满足要求
			{
				TIM_Cmd(TIM2, DISABLE);//失能TIMx 
				if(hasCar >= 1)//(readcarthreshold/2))//10次读取到一半就算在
				{
					BUZZER_LED_L;//红色
					SelectStep = 2;		
					ReadCard_Count = 0;
					printf("....................Have car standby....................\n");
			    printf("ReadCard_Count :%d,hasCar:%d\n",ReadCard_Count,hasCar);					
				}
				else{
			  	BUZZER_LED_H;//绿色						  //没有车显示绿色
					SelectStep = 0;	//重新等待	
					printf("....................Don't have car....................\n");	
				}		
			}
	  }
		break;
		
		case 2://确定有车后检测是否依旧在
		{
				printf("ReadCard_Count :%d\n",ReadCard_Count);
				//从有车后每5次都不在则认为真的离开了
				if( (bState == GL_OK ||GL_OVER == bState) && ReadCard_Count<readcarthreshold)//认为在
				{	
					ReadCard_Count = 0;
					printf("....................The car still....................\n");			
				}
				else if(ReadCard_Count >= readcarthreshold)
				{
					printf("....................The car leave....................\n");							
				  //没有车显示绿色
			  	BUZZER_LED_H;//绿色
		  		SelectStep = 0;									
				}
		}
		break;
	}
}

void read_manage::runModeChange(u8 runmode,u8 bState)
{
		if (runmode == 0)//运行的灯光模式判断
		{
			//1.关闭定时器
			TIM_Cmd(TIM2, DISABLE);//使能TIMx 
			//2.清空标志位
			this->SelectStep = 0;//正式模式下来控制灯光确定流程控制变量
			this->hasCar = 0;		 //第二步的确定有车或者确定没有车
			
			if( bState == GL_OK ||GL_OVER == bState)
			{
				//读取到显示红色
				BUZZER_LED_L;//红色
			}
			else
			{
				BUZZER_LED_H;//绿色
			}					
		}else{
			isturehasTag(bState);
		}
}
		
		
void read_manage::read_managetest(u8 slave_add)
{
		//从节点地址
		//1.设置从节点的射频参数、
	  //配置射频功率 
	  if( this->ConfigRf_Power(slave_add,3800) == 1)
		{
			printf("ConfigRf_Power %d is ok\n",slave_add);
		}
		
		u16 slave1_rfpower = 0;
		//1.1查询从节点的功率值
		if(this->GetSlaveRf_Power(slave_add,&slave1_rfpower) == 1)
		{
			printf("GetSlaveRf_Power %d is %d ok\n",slave_add,slave1_rfpower);
		}
		
		//2.设置从节点的射频频点
		if( this->Config_Frequency(slave_add,0) == 1)
		{
			printf("Config_Frequency %d is ok\n",slave_add);
		}
		
		u8 slave1_rffre = 0;	
		//2.1查询频点值
		if( this->GetSlave_Frequency(slave_add,&slave1_rffre) == 1)
		{
			printf("GetSlave_Frequency %d is %d ok\n",slave_add,slave1_rffre);
		}
		
		//3. 开关载波
		if(this->Config_Carrier(slave_add,1) == 1)
		{
			printf("Config_Carrier %d is ok\n",slave_add);
		}
		
		printf("Config_Cancellation %d \n",slave_add);
//		//4. 对消
		if(this ->Config_Cancellation(slave_add,0) == 1)
		{
			printf("Config_Cancellation %d is ok\n",slave_add);
		}
		
		unsigned char slave1_Cancel[8] = {0};
		//4.1 查询对消值
		if( this->GetSlave_Cancellation(slave_add,slave1_Cancel) == 1)
		{
      uint64_t data = 0; 				
			//组帧 还原64为对消值
			for(int i=0;i<8;i++)
			{
				data = data<<8;
				data = data | slave1_Cancel[i];
			}
			printf("GetSlave_Cancellation %d is %llx ok\n",slave_add,data);
		}			
}

void read_manage::host_read()
{
		uint8_t bState = 0;
		#ifdef __radar
		this->host_dev_parm.radar_distance = radar_read();
		this->SendRadarData(this->host_dev_parm.radar_distance);
		#endif
		bState = ReadTag(host_dev_parm.RF_Power);
		runModeChange(led_mode,bState);//单节点下主机灯光 按照模式显示	
}

//开始读卡
//自动控制切换 3 可修改为宏定义次数
//开始读卡两种模式单节点读卡和多节点读卡
#define reportnum  2
void read_manage::start_read()
{
	 uint8_t bState = 0;
	//0. 判断读卡模式 0 多节点模式  1单节点模式
	if(this->selcet_some_dev_R == 1)//1 单节点模式
	{
		if(this->current_dev == 0)//主机
		{	
			host_read();
		}else{//从机
				Device_cpu = salve_dev[current_dev];//当前接收处理的从机器地址
				MCU_To_MCU(Device_cpu,StartReadCard,0);				
		}						
	}
	else if(this->selcet_some_dev_R == 0)//0 多节点模式
	{
		//1. 开始读卡 由主机和丛机切换
		if(current_dev_count <  reportnum)//继续当前节点
		{		
			if(current_dev != 0)
			{
				Device_cpu = salve_dev[current_dev];//当前接收处理的从机器地址
				MCU_To_MCU(Device_cpu,StartReadCard,0);		
			}
			else{
				host_read();
			}	
		}
		else if(current_dev_count >=  reportnum)//大于3个节点后切换
		{
				if(this->getSlave_num() != 0 )
				{
					change_Device();//切换要让主机读卡一次			
				}else{	
					host_read();					
				}			
		}		
	}	
}


//停止读卡是触发的操作
void read_manage::stop()
{
		KEY_TYPE = TRIG_UP;	                //停止读卡main_run
	  selcet_some_dev_R = 0;              //停止读卡single_run	
		TIM_Cmd(TIM2, DISABLE);							//关闭定时器中断
		BUZZER_LED_H;          							//灯光恢复成绿色	
	  ReadCard_Count = 0;                 //主机读卡计数清零
		SelectStep = 0;                     //读卡步骤切换为0
		//停止当前操作的从机
		MCU_To_MCU(salve_dev[current_dev],StopReadCard,0);	//关闭当前从机节点
	  //配置全部从机灯光
		for(u8 i = 0 ;i <= slave_num;i++) 
		{ //灯光模式
			Config_LedMode(salve_dev[i],led_mode);
		}
	  //printf("stop read card host\n");
}


void read_manage::run()
{ 
	uint8_t reback = 0;
	if(KEY_TYPE == read_start)//开始读卡后才接收后端的数据上报
	{
		if(RX485_ReadyForRecv == 1)
		{
				RX485_ReadyForRecv = 0;
				reback = MessageDeal(RX485_RxMessage,RX485_recFrameLen);
				//记录雷达数据返回的数据直接上报
				if(reback == GetRadarDistanceAck)
				{  
					//printf("SendRadarData !\n");
					#ifdef __radar
					this->SendRadarData(RX485_RxMessage[4]<<8|RX485_RxMessage[5]);
					#endif
				}			
		}		
	}
}

/*----------------flash操作------------------------*/

//1.设置设备版本号
bool read_manage::SetDerviceVersion(u8 *flashtmp,u8 len)
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
bool read_manage::GetDerviceVersion(u8 *datatemp,u8 len)
{
	if(datatemp == NULL) return 0;
	EN25Q256_Read(&flash_flag.Dev_flag,Dev_version_flag,1);		
	if(flash_flag.Dev_flag == flash_Isok)//0x0A:正常		
	{
		//printf("\r\nStart Read EN25Q256....: \r\n");
		EN25Q256_Read(datatemp,Dev_version_start,len);			
		//printf("\r\nThe Data Readed Is:  %s\r\n",datatemp);//显示读到的字符串
		return 1;		
	}	
}

//3. 配置射频配置参数
void read_manage::configrfparam(unsigned short int rf_power,unsigned char rf_frequency)
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
u8 read_manage::Getrfparam()
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
void read_manage::configcancellparam(struct SQU_DA_Value tmp)
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
u8 read_manage::Getcancellparam()
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


//5. 配置门槛的数值
void read_manage::flashthreshold(u8 threshold)
{
	u8 tmp_threshold = 0;	
	printf("config threshold...\n");
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
			this->readcarthreshold = tmp_threshold;                
			//flash存储正常 更新到全局变量
			flash_flag.readcar_threshold_flag = flash_Isok;//0x0A:正常					
			EN25Q256_Write(&flash_flag.readcar_threshold_flag,flash_threshold_flag,1);
			
		}else{
			//flash写入不正常 更新到全局变量 同时写入到flash
			flash_flag.readcar_threshold_flag = flash_Notok;//0x0A:正常					
			EN25Q256_Write(&flash_flag.readcar_threshold_flag,flash_threshold_flag,1);
		
		}
	}	
	printf("readcarthreshold config: %d\n",this->readcarthreshold);		
}

u8 read_manage::Getflashthreshold()
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
		EN25Q256_Read(&this->readcarthreshold,flash_threshold,1);//地址二代表节点地址	 slave_cpu	
		res = 1;
	}else{
		res = 0;
		printf("Getflashthreshold is not ok\n");
	}
	printf("Getflashthreshold :%d\n",this->readcarthreshold);	
  return res; 		
}


uint64_t read_manage::strToHex(uint8_t SNstr[])
{
	uint64_t sn1 = 0;
	uint32_t devienum = 0;
	sn1 = 0;
	sn1  = (uint64_t)SNstr[0]<<56; //第1个'B' --> 0x42
//	printf("%8llx",sn1);
	sn1 |= (uint64_t)SNstr[1]<<48; //第2个'L' --> 0x4C
//	printf("%8llx",sn1);
	sn1 |= (llrp_u64_t)((SNstr[2]-48)*10+(SNstr[3]-48))<<40;
	sn1 |= (llrp_u64_t)((SNstr[4]-48)*10+(SNstr[5]-48))<<32;
//	printf("%8llx",sn1);	
	devienum = (SNstr[6]-48)*100000+(SNstr[7]-48)*10000+(SNstr[8]-48)*1000+(SNstr[9]-48)*100+(SNstr[10]-48)*10+(SNstr[11]-48)*1;
	sn1 += devienum;
//	printf("%8llx",sn1);
	return sn1;
}

//升级程序
bool read_manage::UpdateslaveHandle(u8 slave_id,unsigned int  m_UpdateTotalPack)//1.握手通知 发送需要传输数据的总包数
{
	memset(RX485_TxMessage,0,5);//RX485_TxMessage
	RX485_TxMessage[0] = Updateslavehandle;   //标识符	
	RX485_TxMessage[1] = m_UpdateTotalPack>>8;//数据包的总数H
	RX485_TxMessage[2] = m_UpdateTotalPack;   //数据包的总数L
	sendCommData(MASTER_CPU ,slave_id,CPU_MODE,RX485_TxMessage,3);
	uint8_t tmp_ack = waitSlaveAck(UpdateslavehandleAck,500);
	if(1==tmp_ack)
	{
		printf("Updateslavehandle %d ok\n",slave_id);
		return true;
	}	
		printf("Updateslavehandle %d false\n",slave_id);
	return false;	
}

UpdateslaveAcktypedef read_manage::Updateslavepag(u8 slave_id,uint16_t nr,uint16_t packlen,unsigned char *DataBuf)		//2.数据传输
{
	UpdateslaveAcktypedef result = {0,0};
	if(DataBuf == NULL) return result;
	u8 tmp_ack = 0;
	memset(RX485_TxMessage,0,RX485_MAX_TX_LEN);//RX485_TxMessage
	RX485_TxMessage[0] = Updateslave;//标识符
	RX485_TxMessage[1] = nr>>8;
	RX485_TxMessage[2] = nr;
	RX485_TxMessage[3] = packlen>>8;
	RX485_TxMessage[4] = packlen;	
  memcpy(RX485_TxMessage+5,DataBuf,packlen);
	sendCommData(MASTER_CPU ,slave_id,CPU_MODE,RX485_TxMessage,packlen+5);
	
	Device_cpu = slave_id;	
	//等待返回
	unsigned char ack_data[20] = {0};
  tmp_ack = waitSlaveAckData(UpdateslaveAck,ack_data,4,5000);	
	if(1==tmp_ack)
	{
		result.nr = ack_data[0]<<8|ack_data[1];
		result.result = ack_data[2];
		printf("Updateslave %d ,%d,ok\n",slave_id,result.result);	
		return result;
	}	
	  printf("Updateslave %d ,flase\n",slave_id);	
	
	return result;
}