#ifndef READ_MANAGE_H
#define READ_MANAGE_H
#include "stm32f2xx.h"
#include <map>
/*
*  read_manage 管理类
*
*
*
*/

/*状态标志*/
#define flash_Isok      0x0A
#define flash_Notok     0x00

/*
* flash 内存分配
* 01 ： 0A内存已经初始化且正常
* 02 ： 节点数量
* 03 ： 存储节点1地址
* 04 ： 存储节点2地址
*/
/*地址标志*/
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

#define Dev_version_flag        280 //版本序列号正常标志位	0x0A:正常 00:不正常
#define Dev_version_start       281 //版本序列号开始地址 连续21个

#define rfparam_flag            330 //射频配置参数正常标志位	0x0A:正常 00:不正常
#define rfpower_h               331 //射频功率高8位
#define rfpower_l               332 //射频功率低8位
#define rffrequency             333 //射频频点

#define cancellsave_flag        334 //对消值存储正常标志位	0x0A:正常 00:不正常
#define cancellqp_davalue_h     335 //Qp_DAValue高位
#define cancellqp_davalue_l     336 //Qp_DAValue低位

#define cancellqn_davalue_h     337 //Qn_DAValue高位
#define cancellqn_davalue_l     338 //Qn_DAValue低位

#define cancellip_davalue_h     339 //Ip_DAValue高位
#define cancellip_davalue_l     340 //Ip_DAValue低位

#define cancellin_davalue_h     341 //In_DAValue高位
#define cancellin_davalue_l     342 //In_DAValue低位

#define flash_threshold_flag    351 //门槛参数存在标志位
#define flash_threshold         352 //门槛参数


#define continueSelectSpc_flag        360 //持久化规则 正常标志位	0x0A:正常 00:不正常
#define continueSelectSSpc_start      361 //持久化规则

#define continueAccessSpc_flag        610 //持久化规则 正常标志位	0x0A:正常 00:不正常
#define continueAccessSpc_start       611 //持久化规则



//----------------用户存储配置信息（1M  0 ~ 0x100000）-----------------------
#define SN_STORAGE_flag          continueAccessSpc_start+1000-611
#define SN_STORAGE_ADDR          SN_STORAGE_flag+1
#define SN_STORAGE_SIZE          32

#define CONFIG_STORAGE_flag     SN_STORAGE_ADDR+SN_STORAGE_SIZE
#define CONFIG_STORAGE_ADDR     CONFIG_STORAGE_flag+1
#define CONFIG_STORAGE_SIZE     4096

#define POWER_PA_flag             CONFIG_STORAGE_ADDR+CONFIG_STORAGE_SIZE
#define POWER_PA_ADDR             POWER_PA_flag+1
#define POWER_PA_SIZE             4

#define GETCFG__flag            POWER_PA_ADDR+POWER_PA_SIZE
#define GETCFG_ADDR             GETCFG__flag+1
#define GETCFG_SIZE             4096



//flash信息存储区域结构体
typedef struct
{
	unsigned char Dev_flag;              //	版本序列号正常标志位	  0x0A:正常 00:不正常
	unsigned char Slave_Addr_flag;       //	地址信息正常标志位	    0x0A:正常 00:不正常
	unsigned char rf_param_flag;         //	射频配置参数正常标志位	0x0A:正常 00:不正常
	unsigned char cancell_save_flag;     //	对消值存储正常标志位	  0x0A:正常 00:不正常
	unsigned char readcar_threshold_flag;//	门槛存储正常标志位	0x0A:正常 00:不正常	
}flash_save_flag; //flash存储信息结构体

//读写器底层参数
typedef struct
{
	unsigned char RF_Frequency;      //射频频点  
	unsigned short int RF_Power;     //射频功率 16 位 1500 ~ 3700 
	unsigned short int radar_distance;//主机雷达参数	
}Slave_ConfigParam; //设备属性


//升级程序返回的参数
typedef struct
{
	uint16_t nr;     //第几包
	uint16_t result;//主机雷达参数	
}UpdateslaveAcktypedef; //设备属性

class read_manage
{
	public:
		 u8 slave_num;    //节点数量
		 u8 write_ok;     //分配flash烧录信息状态
	   u8 flash_Dev_ok; //芯片正常
	   std::map<unsigned char,unsigned char> salve_dev;    //从机 设备地址 flash历史保存
	   std::map<unsigned char,unsigned char> salve_dev_new;//从机 设备地址 新配置
	
	   //主机射频参数
	   Slave_ConfigParam host_dev_parm;

		 u8 led_mode;		//正式模式和测试模式灯光的切换
		 u8 SelectStep; //正式模式下来控制灯光确定流程控制变量
		 u8 hasCar;		  //第二步的确定有车或者确定没有车
		 u8 selcet_some_dev_R; //单节点读卡模式启动或关闭
	   u8 readcarthreshold;//车位在位门槛参数
		 //unsigned short int radar_distance;
	public:	
		 u8 current_dev;//当前操作的设备节点号
		 //u8 host_dev;//主机节点
		 u32 current_dev_count;//当前节点读卡次数
	   u32 hasTagTimeCount;//用作计数2s内读卡次数	 
		 unsigned int hasTagCount;//有卡计数
	
	public:
		read_manage();
   ~read_manage();
	public:
			inline u8 getFlash_Dev(){
				return flash_Dev_ok;
			}

			inline u8 getWrite_ok(){
				return write_ok;
			} 	

			inline u8 getSlave_num(){
				return slave_num;
			} 			
	public:
			//设置主机设备
	    bool SetNodeCountToFlash(unsigned char num);                                //设置节点数量
		  unsigned char  GetNodeCountFromFlash();                                     //获取节点数量
	    bool SetNodeInfoToFlash(std::map<unsigned char,unsigned char> nodeInfo);    //设置节点信息(ID,Address)
    	std::map<unsigned char,unsigned char> GetNodeInfoFromFlash();               //查询主机设备节点配置信息

			//查询主机射频参数和控制对消
			//控制主机对消
			bool ConfigHost_cancell();
			bool ConfigHost_Carrier(u8 mode);//主机载波控制
			//向主机发送雷达数据 主动上报
			bool SendRadarData(unsigned short int radar_distance);

	
			//设置从机设备
			bool SetSlave_Addr(unsigned char addr,unsigned char addr_new);//对应一个机器的从机设备地址
			bool GetSlave_Addr(unsigned char slave_add);//对应一个机器的从机设备地址
			bool SetSlave_Message(unsigned char addr,unsigned char *buf,unsigned char len);	
			bool GetSlave_Message(unsigned char addr,unsigned char *buf,unsigned char len);		
			bool SetSlave_cancell(unsigned char *value);
			//设置从节点的射频参数、
			//配置射频功率 
			bool ConfigRf_Power(u8 slave_id,u32 value);
			bool GetSlaveRf_Power(u8 slave_id,unsigned short int * value);//返回数值和是否成功
			//设置从节点的射频频点
			bool Config_Frequency(u8 slave_id,u32 value);
			bool GetSlave_Frequency(u8 slave_id,unsigned char * value);//返回数值和是否成功
				//设置从节点 开关载波
			bool Config_Carrier(u8 slave_id,u8 value);
			//设置从节点 对消 开始对消 和停止对消
			bool Config_Cancellation(u8 slave_id,unsigned char *value);
			//查询从节点 对消值
			bool GetSlave_Cancellation(u8 slave_id,unsigned char *value);	
			//设置从节点 灯光模式
			bool Config_LedMode(u8 slave_id,u8 value);
			//查询从节点 灯光模式
			bool GetSlave_LedMode(u8 slave_id,unsigned char *value);	
			//设置从节点 灯光限制的门槛数值
			bool Config_LedThreshold(u8 slave_id,u8 value);
			//查询从节点 灯光模式
			bool GetSlave_LedThreshold(u8 slave_id,unsigned char *value);				
			//查询从节点 灯光限制的门槛数值
			bool GetSlaveRadar(u8 slave_id,unsigned short int * value);	
	public:
		//读卡流程控制
			//单节点读卡 选择节点 启动单节点读卡模式 运行Run
			bool select_dev_Read(u8 slave_id,u8 mode);	
			void Switch_Device(u8 cur_dev);//前端读卡设备切换
			void change_Device();
			void isturehasTag(u8 bState);
			void runModeChange(u8 runmode,u8 bState);
	public:
		  //测试API接口
			void read_managetest(u8 slave_add);	 
	public:
			//测试模式 单节点模式run
			void single_dev_run();
			//主控制下 主运行灯光规则模式
			void main_run();	
			void run();
	    void host_read();
			//开始读卡
			void start_read();
			//停止读卡时触发的操作
			void stop();
	
/*---------------------------flash操作-------------------------------*/
public:
		//主机flash存储标志位
	  flash_save_flag flash_flag;
	
public:
		//1. 设置设备版本
		bool SetDerviceVersion(u8 *flashtmp,u8 len);	
		//2. 查询设备版本号
		bool GetDerviceVersion(u8 *datatemp,u8 len);
		//3. 配置射频配置参数
		void configrfparam(unsigned short int rf_power,unsigned char rf_frequency);
		//4. 查询射频参数
		u8 Getrfparam();
		//5. 配置对消参数
		void configcancellparam(struct SQU_DA_Value tmp);
		//6.查询对消的四路电压
		u8 Getcancellparam();
		//7.配置门槛的数值
		void flashthreshold(u8 threshold);
		//8.门槛的数值信息
		u8 Getflashthreshold();
public:
		uint64_t strToHex(uint8_t SNstr[]);

public:
		bool UpdateslaveHandle(u8 slave_id,unsigned int  m_UpdateTotalPack);//1.握手通知 发送需要传输数据的总包数
		UpdateslaveAcktypedef Updateslavepag(u8 slave_id,uint16_t nr,uint16_t packlen,unsigned char *DataBuf);		//2.数据传输
		
};

extern uint8_t ReadCard_Count;//记录主机读卡的轮数


#endif
