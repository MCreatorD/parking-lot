/*********************************************************************************************************
*
* File                : EN25Q256.c
* Hardware Environment: 
* Build Environment   : RealView MDK-ARM  Version: 5.15
* Version             : V1.0
* By                  : 
*
*                                  (c) Copyright 2005-2011, WaveShare
*                                       http://www.waveshare.net
*                                          All Rights Reserved
*
*********************************************************************************************************/
#include "EN25Q256.h"
#include "systick.h"
u16 EN25Q256_TYPE=EN25Q256_ID;	//默认是EN25Q256

#if 0
//要写入到GD25Q127的字符串数组
const u8 TEXT_Buffer[]={"STM32 SPI FLASH TEST"};
#define SIZE sizeof(TEXT_Buffer)
void FLASH_TEST(void)
{	
	u8 datatemp[SIZE];
	u32 FLASH_SIZE;
	printf("\r\n Flash is EN25Q256 and ID is %x\r\n",EN25Q256_ReadID());
	printf("\r\nFALSH EN25Q256 Write Test: \r\n");
	FLASH_SIZE=256*1024*1024;	//FLASH 大小为32M字节
	EN25Q256_Write((u8*)TEXT_Buffer,FLASH_SIZE-20,SIZE);			//从倒数第100个地址处开始,写入SIZE长度的数据
	
	printf("\r\nStart Read EN25Q256....: \r\n");
	EN25Q256_Read(datatemp,FLASH_SIZE-20,SIZE);					//从倒数第100个地址处开始,读出SIZE个字节
	printf("\r\nThe Data Readed Is:  %s\r\n",datatemp);//显示读到的字符串
}
#endif
/*
*@SPI3
*@FLASH_NSS   PA15 
*@FLASH_CLK		PB3
*@FLASH_MISO  PB4
*@FLASH_MOSI  PB5
*/

/*
*@256Mbits = 256 * 1024 *1024 / 8 = 33,554,432 bytes
*@页pages  256bytes 一个扇区16页
*@基础单位扇区sector 4Kbyte = 4096byte = 32768 bit
*@块Block  = 16 sector = 64Kbyte
*/
void EN25Q256_Init(void)
{	
	GPIO_InitTypeDef GPIO_InitStructure;

	//片选信号初始化 PA15
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;

  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
	
  EN25Q256_Disable;   //SPI FLASH不选中	 
	SPI3_Init();//初始化SPI

	printf("FLASH_SPI is ready!\r\n");

} 

//读取芯片ID
//返回值:0x1C18	   
//90h  dummy dummy 00h M7-M0 ID7-ID0
u32 EN25Q256_ReadID(void)
{
	u32 Temp = 0;	  
	EN25Q256_Enable;		
	SPI3_ReadSend_byte(EN25Q256_ManufactDeviceID);//发送读取ID命令
	SPI3_ReadSend_byte(0x00);//返回第一组8位不要
	SPI3_ReadSend_byte(0x00);//返回第二组8位不要
	SPI3_ReadSend_byte(0x00);//返回第三组8位不要   Address (000000h) 
	Temp|=SPI3_ReadSend_byte(0xFF)<<8;//Manufacturer ID  返回1CH
	Temp|=SPI3_ReadSend_byte(0xFF);//Device ID  
	EN25Q256_Disable;			    
	return Temp;
} 

//读取EN25Q256状态寄存器 (05H)
//BIT7  6   5   4   3   2   1   0
//SPR   RV  TB BP2 BP1 BP0 WEL BUSY
//SPR:默认0,状态寄存器保护位,配合WP使用
//TB,BP2,BP1,BP0:FLASH区域写保护设置
//WEL:写使能锁定
//BUSY:忙标记位(1,忙;0,空闲)
//默认:0x00
u8 EN25Q256_ReadSR(void)   
{  
	u8 byte=0;   
	EN25Q256_Enable;                            //使能器件   
	SPI3_ReadSend_byte(EN25Q256_ReadStatusReg); //发送读取状态寄存器命令    
	byte=SPI3_ReadSend_byte(0Xff);          //读取一个字节  
	EN25Q256_Disable;                            //取消片选     
	return byte;   
} 


//写EN25Q256状态寄存器 (01H)
//只有SPR,TB,BP2,BP1,BP0(bit 7,5,4,3,2)可以写!!!
void EN25Q256_Write_SR(u8 sr)   
{   
	EN25Q256_Enable;                            //使能器件   
	SPI3_ReadSend_byte(EN25Q256_WriteStatusReg);//发送写取状态寄存器命令    
	SPI3_ReadSend_byte(sr);               	//写入一个字节  
	EN25Q256_Disable;                           //取消片选     	      
}   
//EN25Q256使能	 (06H)
//将WEL置位   
void EN25Q256_Write_Enable(void)   
{
	EN25Q256_Enable;                          	//使能器件   
  SPI3_ReadSend_byte(EN25Q256_WriteEnable); 	//发送写使能  
	EN25Q256_Disable;                          	//取消片选     	      
} 
//EN25Q256写禁止	 (04h)
//将WEL清零  
void EN25Q256_Write_Disable(void)   
{  
	EN25Q256_Enable;                            //使能器件   
    SPI3_ReadSend_byte(EN25Q256_WriteDisable);  //发送写禁止指令    
	EN25Q256_Disable;                             //取消片选     	      
}

//读取SPI FLASH  
//在指定地址开始读取指定长度的数据
//pBuffer:数据存储区
//ReadAddr:开始读取的地址(24bit)
//NumByteToRead:要读取的字节数(最大65535)
void EN25Q256_Read(u8* pBuffer,u32 ReadAddr,u16 NumByteToRead)   
{ 
 	u16 i;   										    
	EN25Q256_Enable;                            	//使能器件   
    SPI3_ReadSend_byte(EN25Q256_ReadData);         	//发送读取命令   
    SPI3_ReadSend_byte((u8)((ReadAddr)>>16));  	//发送24bit地址    
    SPI3_ReadSend_byte((u8)((ReadAddr)>>8));   
    SPI3_ReadSend_byte((u8)ReadAddr);   
    for(i=0;i<NumByteToRead;i++)
	{ 
        pBuffer[i]=SPI3_ReadSend_byte(0XFF);   	//循环读数  
  }
	EN25Q256_Disable;  				    	      
}  

//SPI在一页(0~65535)内写入少于256个字节的数据
//在指定地址开始写入最大256字节的数据
//pBuffer:数据存储区
//WriteAddr:开始写入的地址(24bit)
//NumByteToWrite:要写入的字节数(最大256),该数不应该超过该页的剩余字节数!!!	 
void EN25Q256_Write_Page(u8* pBuffer,u32 WriteAddr,u16 NumByteToWrite)
{
 	u16 i;  
    EN25Q256_Write_Enable();                  	//SET WEL 
		EN25Q256_Enable;                           	//使能器件   
    SPI3_ReadSend_byte(EN25Q256_PageProgram);      	//发送写页命令   
    SPI3_ReadSend_byte((u8)((WriteAddr)>>16)); 	//发送24bit地址    
    SPI3_ReadSend_byte((u8)((WriteAddr)>>8));   
    SPI3_ReadSend_byte((u8)WriteAddr);   
    for(i=0;i<NumByteToWrite;i++)SPI3_ReadSend_byte(pBuffer[i]);//循环写数  
	EN25Q256_Disable;                            	//取消片选 
	EN25Q256_Wait_Busy();					   		//等待写入结束
} 
//无检验写SPI FLASH 
//必须确保所写的地址范围内的数据全部为0XFF,否则在非0XFF处写入的数据将失败!
//具有自动换页功能 
//在指定地址开始写入指定长度的数据,但是要确保地址不越界!
//pBuffer:数据存储区
//WriteAddr:开始写入的地址(24bit)
//NumByteToWrite:要写入的字节数(最大65535)
//CHECK OK
void EN25Q256_Write_NoCheck(u8* pBuffer,u32 WriteAddr,u16 NumByteToWrite)   
{ 			 		 
	u16 pageremain;	   
	pageremain=256-WriteAddr%256; //单页剩余的字节数		 	    
	if(NumByteToWrite<=pageremain)pageremain=NumByteToWrite;//不大于256个字节
	while(1)
	{	   
		EN25Q256_Write_Page(pBuffer,WriteAddr,pageremain);
		if(NumByteToWrite==pageremain)break;//写入结束了
	 	else //NumByteToWrite>pageremain
		{
			pBuffer+=pageremain;
			WriteAddr+=pageremain;	

			NumByteToWrite-=pageremain;			  //减去已经写入了的字节数
			if(NumByteToWrite>256)pageremain=256; //一次可以写入256个字节
			else pageremain=NumByteToWrite; 	  //不够256个字节了
		}
	}	    
} 

//写SPI FLASH  
//在指定地址开始写入指定长度的数据
//该函数带擦除操作!
//pBuffer:数据存储区
//WriteAddr:开始写入的地址(24bit)						
//NumByteToWrite:要写入的字节数(最大65535)   
u8 EN25Q256_BUFFER[4096];	//扇区4k对齐 4*1024 = 4096	 
void EN25Q256_Write(u8* pBuffer,u32 WriteAddr,u16 NumByteToWrite)   
{ 
	u32 secpos;
	u16 secoff;
	u16 secremain;	   
 	u16 i;    
	u8 * EN25Q256_BUF;	  
   	EN25Q256_BUF=EN25Q256_BUFFER;	     
 	secpos=WriteAddr/4096;//扇区地址  
	secoff=WriteAddr%4096;//在扇区内的偏移
	secremain=4096-secoff;//扇区剩余空间大小   
 	//printf("ad:%X,nb:%X\r\n",WriteAddr,NumByteToWrite);//测试用
 	if(NumByteToWrite<=secremain)secremain=NumByteToWrite;//不大于4096个字节
	while(1) 
	{	
		EN25Q256_Read(EN25Q256_BUF,secpos*4096,4096);//读出整个扇区的内容
		for(i=0;i<secremain;i++)//校验数据 判断起始地址后面空间状态清除
		{
			if(EN25Q256_BUF[secoff+i]!=0XFF)break;//需要擦除  	  
		}
		if(i<secremain)//需要擦除
		{
			EN25Q256_Erase_Sector(secpos);		//擦除这个扇区
			for(i=0;i<secremain;i++)	   		//复制
			{
				EN25Q256_BUF[i+secoff]=pBuffer[i];	  
			}
			EN25Q256_Write_NoCheck(EN25Q256_BUF,secpos*4096,4096);//写入整个扇区  

		}else EN25Q256_Write_NoCheck(pBuffer,WriteAddr,secremain);//写已经擦除了的,直接写入扇区剩余区间. 				   
		if(NumByteToWrite==secremain)break;//写入结束了
		else//写入未结束
		{
			secpos++;//扇区地址增1
			secoff=0;//偏移位置为0 	 

		   	pBuffer+=secremain;  				//指针偏移
			WriteAddr+=secremain;				//写地址偏移	   
		   	NumByteToWrite-=secremain;			//字节数递减
			if(NumByteToWrite>4096)secremain=4096;//下一个扇区还是写不完
			else secremain=NumByteToWrite;		//下一个扇区可以写完了
		}	 
	}	 
}

//擦除整个芯片		  
//等待时间超长...
void EN25Q256_Erase_Chip(void)   
{                                   
    EN25Q256_Write_Enable();                 	 	//SET WEL 
    EN25Q256_Wait_Busy();   
  	EN25Q256_Enable;                            	//使能器件   
    SPI3_ReadSend_byte(EN25Q256_ChipErase);        	//发送片擦除命令  
  	EN25Q256_Disable;                            	//取消片选     	      
  	EN25Q256_Wait_Busy();   				   		//等待芯片擦除结束
}

//擦除一个扇区
//Dst_Addr:扇区地址 根据实际容量设置
//擦除一个山区的最少时间:150ms
void EN25Q256_Erase_Sector(u32 Dst_Addr)   
{  
	//监视falsh擦除情况,测试用   
 	//printf("fe:%X\r\n",Dst_Addr);	  
 	Dst_Addr*=4096;
    EN25Q256_Write_Enable();                  	    //SET WEL 	 
    EN25Q256_Wait_Busy();   
  	EN25Q256_Enable;                            	//使能器件   
    SPI3_ReadSend_byte(EN25Q256_SectorErase);      	//发送扇区擦除指令 
    SPI3_ReadSend_byte((u8)((Dst_Addr)>>16));  	    //发送24bit地址    
    SPI3_ReadSend_byte((u8)((Dst_Addr)>>8));   
    SPI3_ReadSend_byte((u8)Dst_Addr);  
		EN25Q256_Disable;                           //取消片选     	      
    EN25Q256_Wait_Busy();   				   	    //等待擦除完成
}  
//等待空闲
void EN25Q256_Wait_Busy(void)   
{   
	while((EN25Q256_ReadSR()&0x01)==0x01);  	    // 等待BUSY位清空
} 

//进入掉电模式
void W25QXX_PowerDown(void)   
{ 
  	EN25Q256_Enable;                           	 	//使能器件   
    SPI3_ReadSend_byte(EN25Q256_PowerDn);         //发送掉电命令  
	  EN25Q256_Disable;                            	//取消片选     	      
   //delay_us(3);                                    //等待TPD  
}   
//唤醒
void W25QXX_WAKEUP(void)   
{  
  	EN25Q256_Enable;                            	//使能器件   
    SPI3_ReadSend_byte(EN25Q256_ReleasePowerDown);	//  send W25X_PowerDown command 0xAB    
	EN25Q256_Disable;                            	//取消片选     	      
   // delay_us(3);                            	//等待TRES1
}   

