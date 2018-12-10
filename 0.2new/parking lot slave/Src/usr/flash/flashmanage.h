#ifndef __FLASHMANAGE_H
#define __FLASHMANAGE_H
#include "stm32f2xx.h"
#include "cancellation.h"
/*状态标志*/
#define flash_Isok      0x0A
#define flash_Notok     0x00
/*地址标志*/
#define addrMessage_flag         1 //地址信息正常标志位	0x0A:正常 00:不正常
#define flash_dev_addr           2 //485地址

#define Dev_version_flag         3 //版本序列号正常标志位	0x0A:正常 00:不正常
#define Dev_version_start        4 //版本序列号开始地址 连续21个

#define rfparam_flag            70 //射频配置参数正常标志位	0x0A:正常 00:不正常
#define rfpower_h               71 //射频功率高8位
#define rfpower_l               72 //射频功率低8位
#define rffrequency             73 //射频频点

#define cancellsave_flag        74 //对消值存储正常标志位	0x0A:正常 00:不正常
#define cancellqp_davalue_h     75 //Qp_DAValue高位
#define cancellqp_davalue_l     76 //Qp_DAValue低位

#define cancellqn_davalue_h     77 //Qn_DAValue高位
#define cancellqn_davalue_l     78 //Qn_DAValue低位

#define cancellip_davalue_h     79 //Ip_DAValue高位
#define cancellip_davalue_l     80 //Ip_DAValue低位

#define cancellin_davalue_h     81 //In_DAValue高位
#define cancellin_davalue_l     82 //In_DAValue低位

#define flash_threshold_flag    91 //门槛参数存在标志位
#define flash_threshold         92 //门槛参数


//flash存储信息结构体
typedef struct
{
	unsigned char Dev_flag;          		 //	版本序列号正常标志位	0x0A:正常 00:不正常
	unsigned char Slave_Addr_flag;   		 //	地址信息正常标志位	0x0A:正常 00:不正常
	unsigned char rf_param_flag;     		 //	射频配置参数正常标志位	0x0A:正常 00:不正常
	unsigned char cancell_save_flag; 		 //	对消值存储正常标志位	0x0A:正常 00:不正常
	unsigned char readcar_threshold_flag;//	门槛存储正常标志位	0x0A:正常 00:不正常
}flash_save_flag; //flash存储信息结构体

#ifdef __cplusplus
 extern "C" {
#endif
extern flash_save_flag flash_flag;//存储flash的信息正常标志位
//1.设置设备版本号
void SetDerviceVersion(u8 *flashtmp,u8 len);
//2.查询设备版本号
void GetDerviceVersion(u8* datatemp);

//更新flash参数
//1. 配置485通信地址
void config485addr(u8 addr);
u8 Get485addr();

//2. 配置射频配置参数
void configrfparam(unsigned short int rf_power,unsigned char rf_frequency);
u8 Getrfparam();
//3. 配置对消参数
void configcancellparam(struct SQU_DA_Value tmp);
u8 Getcancellparam();


//5. 配置门槛的数值
void flashthreshold(u8 threshold);
u8 Getflashthreshold();
//开机初始化 flash存储正常的话读取参数
void flashmanageinit();


#ifdef __cplusplus
}
#endif
 

#endif