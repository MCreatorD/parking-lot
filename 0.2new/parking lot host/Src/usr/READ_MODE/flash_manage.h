#ifndef __flash_manage_H
#define __flash_manage_H


#include "stm32f2xx.h"


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

#define continueSelectSpc_flag        350 //持久化规则 正常标志位	0x0A:正常 00:不正常
#define continueSelectSSpc_start      351 //持久化规则

#define continueAccessSpc_flag        600 //持久化规则 正常标志位	0x0A:正常 00:不正常
#define continueAccessSpc_start       601 //持久化规则

//flash信息存储区域结构体
typedef struct
{
	unsigned char Dev_flag;           //03h	版本序列号正常标志位	  0x0A:正常 00:不正常
	unsigned char Slave_Addr_flag;    //01h	地址信息正常标志位	    0x0A:正常 00:不正常
	unsigned char rf_param_flag;      //19h	射频配置参数正常标志位	0x0A:正常 00:不正常
	unsigned char cancell_save_flag;  //1Dh	对消值存储正常标志位	  0x0A:正常 00:不正常
}flash_save_flag; //flash存储信息结构体

class flash_manage{
	/*-----------------flash操作-----------------*/	
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
};

#endif