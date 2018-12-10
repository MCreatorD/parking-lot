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
u16 EN25Q256_TYPE=EN25Q256_ID;	//Ĭ����EN25Q256

#if 0
//Ҫд�뵽GD25Q127���ַ�������
const u8 TEXT_Buffer[]={"STM32 SPI FLASH TEST"};
#define SIZE sizeof(TEXT_Buffer)
void FLASH_TEST(void)
{	
	u8 datatemp[SIZE];
	u32 FLASH_SIZE;
	printf("\r\n Flash is EN25Q256 and ID is %x\r\n",EN25Q256_ReadID());
	printf("\r\nFALSH EN25Q256 Write Test: \r\n");
	FLASH_SIZE=256*1024*1024;	//FLASH ��СΪ32M�ֽ�
	EN25Q256_Write((u8*)TEXT_Buffer,FLASH_SIZE-20,SIZE);			//�ӵ�����100����ַ����ʼ,д��SIZE���ȵ�����
	
	printf("\r\nStart Read EN25Q256....: \r\n");
	EN25Q256_Read(datatemp,FLASH_SIZE-20,SIZE);					//�ӵ�����100����ַ����ʼ,����SIZE���ֽ�
	printf("\r\nThe Data Readed Is:  %s\r\n",datatemp);//��ʾ�������ַ���
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
*@ҳpages  256bytes һ������16ҳ
*@������λ����sector 4Kbyte = 4096byte = 32768 bit
*@��Block  = 16 sector = 64Kbyte
*/
void EN25Q256_Init(void)
{	
	GPIO_InitTypeDef GPIO_InitStructure;

	//Ƭѡ�źų�ʼ�� PA15
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;

  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
	
  EN25Q256_Disable;   //SPI FLASH��ѡ��	 
	SPI3_Init();//��ʼ��SPI

	printf("FLASH_SPI is ready!\r\n");

} 

//��ȡоƬID
//����ֵ:0x1C18	   
//90h  dummy dummy 00h M7-M0 ID7-ID0
u32 EN25Q256_ReadID(void)
{
	u32 Temp = 0;	  
	EN25Q256_Enable;		
	SPI3_ReadSend_byte(EN25Q256_ManufactDeviceID);//���Ͷ�ȡID����
	SPI3_ReadSend_byte(0x00);//���ص�һ��8λ��Ҫ
	SPI3_ReadSend_byte(0x00);//���صڶ���8λ��Ҫ
	SPI3_ReadSend_byte(0x00);//���ص�����8λ��Ҫ   Address (000000h) 
	Temp|=SPI3_ReadSend_byte(0xFF)<<8;//Manufacturer ID  ����1CH
	Temp|=SPI3_ReadSend_byte(0xFF);//Device ID  
	EN25Q256_Disable;			    
	return Temp;
} 

//��ȡEN25Q256״̬�Ĵ��� (05H)
//BIT7  6   5   4   3   2   1   0
//SPR   RV  TB BP2 BP1 BP0 WEL BUSY
//SPR:Ĭ��0,״̬�Ĵ�������λ,���WPʹ��
//TB,BP2,BP1,BP0:FLASH����д��������
//WEL:дʹ������
//BUSY:æ���λ(1,æ;0,����)
//Ĭ��:0x00
u8 EN25Q256_ReadSR(void)   
{  
	u8 byte=0;   
	EN25Q256_Enable;                            //ʹ������   
	SPI3_ReadSend_byte(EN25Q256_ReadStatusReg); //���Ͷ�ȡ״̬�Ĵ�������    
	byte=SPI3_ReadSend_byte(0Xff);          //��ȡһ���ֽ�  
	EN25Q256_Disable;                            //ȡ��Ƭѡ     
	return byte;   
} 


//дEN25Q256״̬�Ĵ��� (01H)
//ֻ��SPR,TB,BP2,BP1,BP0(bit 7,5,4,3,2)����д!!!
void EN25Q256_Write_SR(u8 sr)   
{   
	EN25Q256_Enable;                            //ʹ������   
	SPI3_ReadSend_byte(EN25Q256_WriteStatusReg);//����дȡ״̬�Ĵ�������    
	SPI3_ReadSend_byte(sr);               	//д��һ���ֽ�  
	EN25Q256_Disable;                           //ȡ��Ƭѡ     	      
}   
//EN25Q256ʹ��	 (06H)
//��WEL��λ   
void EN25Q256_Write_Enable(void)   
{
	EN25Q256_Enable;                          	//ʹ������   
  SPI3_ReadSend_byte(EN25Q256_WriteEnable); 	//����дʹ��  
	EN25Q256_Disable;                          	//ȡ��Ƭѡ     	      
} 
//EN25Q256д��ֹ	 (04h)
//��WEL����  
void EN25Q256_Write_Disable(void)   
{  
	EN25Q256_Enable;                            //ʹ������   
    SPI3_ReadSend_byte(EN25Q256_WriteDisable);  //����д��ָֹ��    
	EN25Q256_Disable;                             //ȡ��Ƭѡ     	      
}

//��ȡSPI FLASH  
//��ָ����ַ��ʼ��ȡָ�����ȵ�����
//pBuffer:���ݴ洢��
//ReadAddr:��ʼ��ȡ�ĵ�ַ(24bit)
//NumByteToRead:Ҫ��ȡ���ֽ���(���65535)
void EN25Q256_Read(u8* pBuffer,u32 ReadAddr,u16 NumByteToRead)   
{ 
 	u16 i;   										    
	EN25Q256_Enable;                            	//ʹ������   
    SPI3_ReadSend_byte(EN25Q256_ReadData);         	//���Ͷ�ȡ����   
    SPI3_ReadSend_byte((u8)((ReadAddr)>>16));  	//����24bit��ַ    
    SPI3_ReadSend_byte((u8)((ReadAddr)>>8));   
    SPI3_ReadSend_byte((u8)ReadAddr);   
    for(i=0;i<NumByteToRead;i++)
	{ 
        pBuffer[i]=SPI3_ReadSend_byte(0XFF);   	//ѭ������  
  }
	EN25Q256_Disable;  				    	      
}  

//SPI��һҳ(0~65535)��д������256���ֽڵ�����
//��ָ����ַ��ʼд�����256�ֽڵ�����
//pBuffer:���ݴ洢��
//WriteAddr:��ʼд��ĵ�ַ(24bit)
//NumByteToWrite:Ҫд����ֽ���(���256),������Ӧ�ó�����ҳ��ʣ���ֽ���!!!	 
void EN25Q256_Write_Page(u8* pBuffer,u32 WriteAddr,u16 NumByteToWrite)
{
 	u16 i;  
    EN25Q256_Write_Enable();                  	//SET WEL 
		EN25Q256_Enable;                           	//ʹ������   
    SPI3_ReadSend_byte(EN25Q256_PageProgram);      	//����дҳ����   
    SPI3_ReadSend_byte((u8)((WriteAddr)>>16)); 	//����24bit��ַ    
    SPI3_ReadSend_byte((u8)((WriteAddr)>>8));   
    SPI3_ReadSend_byte((u8)WriteAddr);   
    for(i=0;i<NumByteToWrite;i++)SPI3_ReadSend_byte(pBuffer[i]);//ѭ��д��  
	EN25Q256_Disable;                            	//ȡ��Ƭѡ 
	EN25Q256_Wait_Busy();					   		//�ȴ�д�����
} 
//�޼���дSPI FLASH 
//����ȷ����д�ĵ�ַ��Χ�ڵ�����ȫ��Ϊ0XFF,�����ڷ�0XFF��д������ݽ�ʧ��!
//�����Զ���ҳ���� 
//��ָ����ַ��ʼд��ָ�����ȵ�����,����Ҫȷ����ַ��Խ��!
//pBuffer:���ݴ洢��
//WriteAddr:��ʼд��ĵ�ַ(24bit)
//NumByteToWrite:Ҫд����ֽ���(���65535)
//CHECK OK
void EN25Q256_Write_NoCheck(u8* pBuffer,u32 WriteAddr,u16 NumByteToWrite)   
{ 			 		 
	u16 pageremain;	   
	pageremain=256-WriteAddr%256; //��ҳʣ����ֽ���		 	    
	if(NumByteToWrite<=pageremain)pageremain=NumByteToWrite;//������256���ֽ�
	while(1)
	{	   
		EN25Q256_Write_Page(pBuffer,WriteAddr,pageremain);
		if(NumByteToWrite==pageremain)break;//д�������
	 	else //NumByteToWrite>pageremain
		{
			pBuffer+=pageremain;
			WriteAddr+=pageremain;	

			NumByteToWrite-=pageremain;			  //��ȥ�Ѿ�д���˵��ֽ���
			if(NumByteToWrite>256)pageremain=256; //һ�ο���д��256���ֽ�
			else pageremain=NumByteToWrite; 	  //����256���ֽ���
		}
	}	    
} 

//дSPI FLASH  
//��ָ����ַ��ʼд��ָ�����ȵ�����
//�ú�������������!
//pBuffer:���ݴ洢��
//WriteAddr:��ʼд��ĵ�ַ(24bit)						
//NumByteToWrite:Ҫд����ֽ���(���65535)   
u8 EN25Q256_BUFFER[4096];	//����4k���� 4*1024 = 4096	 
void EN25Q256_Write(u8* pBuffer,u32 WriteAddr,u16 NumByteToWrite)   
{ 
	u32 secpos;
	u16 secoff;
	u16 secremain;	   
 	u16 i;    
	u8 * EN25Q256_BUF;	  
   	EN25Q256_BUF=EN25Q256_BUFFER;	     
 	secpos=WriteAddr/4096;//������ַ  
	secoff=WriteAddr%4096;//�������ڵ�ƫ��
	secremain=4096-secoff;//����ʣ��ռ��С   
 	//printf("ad:%X,nb:%X\r\n",WriteAddr,NumByteToWrite);//������
 	if(NumByteToWrite<=secremain)secremain=NumByteToWrite;//������4096���ֽ�
	while(1) 
	{	
		EN25Q256_Read(EN25Q256_BUF,secpos*4096,4096);//������������������
		for(i=0;i<secremain;i++)//У������ �ж���ʼ��ַ����ռ�״̬���
		{
			if(EN25Q256_BUF[secoff+i]!=0XFF)break;//��Ҫ����  	  
		}
		if(i<secremain)//��Ҫ����
		{
			EN25Q256_Erase_Sector(secpos);		//�����������
			for(i=0;i<secremain;i++)	   		//����
			{
				EN25Q256_BUF[i+secoff]=pBuffer[i];	  
			}
			EN25Q256_Write_NoCheck(EN25Q256_BUF,secpos*4096,4096);//д����������  

		}else EN25Q256_Write_NoCheck(pBuffer,WriteAddr,secremain);//д�Ѿ������˵�,ֱ��д������ʣ������. 				   
		if(NumByteToWrite==secremain)break;//д�������
		else//д��δ����
		{
			secpos++;//������ַ��1
			secoff=0;//ƫ��λ��Ϊ0 	 

		   	pBuffer+=secremain;  				//ָ��ƫ��
			WriteAddr+=secremain;				//д��ַƫ��	   
		   	NumByteToWrite-=secremain;			//�ֽ����ݼ�
			if(NumByteToWrite>4096)secremain=4096;//��һ����������д����
			else secremain=NumByteToWrite;		//��һ����������д����
		}	 
	}	 
}

//��������оƬ		  
//�ȴ�ʱ�䳬��...
void EN25Q256_Erase_Chip(void)   
{                                   
    EN25Q256_Write_Enable();                 	 	//SET WEL 
    EN25Q256_Wait_Busy();   
  	EN25Q256_Enable;                            	//ʹ������   
    SPI3_ReadSend_byte(EN25Q256_ChipErase);        	//����Ƭ��������  
  	EN25Q256_Disable;                            	//ȡ��Ƭѡ     	      
  	EN25Q256_Wait_Busy();   				   		//�ȴ�оƬ��������
}

//����һ������
//Dst_Addr:������ַ ����ʵ����������
//����һ��ɽ��������ʱ��:150ms
void EN25Q256_Erase_Sector(u32 Dst_Addr)   
{  
	//����falsh�������,������   
 	//printf("fe:%X\r\n",Dst_Addr);	  
 	Dst_Addr*=4096;
    EN25Q256_Write_Enable();                  	    //SET WEL 	 
    EN25Q256_Wait_Busy();   
  	EN25Q256_Enable;                            	//ʹ������   
    SPI3_ReadSend_byte(EN25Q256_SectorErase);      	//������������ָ�� 
    SPI3_ReadSend_byte((u8)((Dst_Addr)>>16));  	    //����24bit��ַ    
    SPI3_ReadSend_byte((u8)((Dst_Addr)>>8));   
    SPI3_ReadSend_byte((u8)Dst_Addr);  
		EN25Q256_Disable;                           //ȡ��Ƭѡ     	      
    EN25Q256_Wait_Busy();   				   	    //�ȴ��������
}  
//�ȴ�����
void EN25Q256_Wait_Busy(void)   
{   
	while((EN25Q256_ReadSR()&0x01)==0x01);  	    // �ȴ�BUSYλ���
} 

//�������ģʽ
void W25QXX_PowerDown(void)   
{ 
  	EN25Q256_Enable;                           	 	//ʹ������   
    SPI3_ReadSend_byte(EN25Q256_PowerDn);         //���͵�������  
	  EN25Q256_Disable;                            	//ȡ��Ƭѡ     	      
   //delay_us(3);                                    //�ȴ�TPD  
}   
//����
void W25QXX_WAKEUP(void)   
{  
  	EN25Q256_Enable;                            	//ʹ������   
    SPI3_ReadSend_byte(EN25Q256_ReleasePowerDown);	//  send W25X_PowerDown command 0xAB    
	EN25Q256_Disable;                            	//ȡ��Ƭѡ     	      
   // delay_us(3);                            	//�ȴ�TRES1
}   

