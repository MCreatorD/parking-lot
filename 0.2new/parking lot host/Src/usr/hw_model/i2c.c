#include "i2c.h"
#include "stdio.h"
#define I2C1_SPEED               400000
#define I2C1_SLAVE_ADDRESS7      0x30

#define I2C2_SPEED               400000
#define I2C2_SLAVE_ADDRESS7      0x30

/*等待超时时间*/
#define I2C_Open207V_FLAG_TIMEOUT         ((uint32_t)0x1000)
#define I2C_Open207V_LONG_TIMEOUT         ((uint32_t)(10 * I2C_Open207V_FLAG_TIMEOUT))

static __IO uint32_t  I2CTimeout = I2C_Open207V_LONG_TIMEOUT;

void I2C1_Configuration(void)
{
	I2C_InitTypeDef  I2C_InitStructure;
	GPIO_InitTypeDef  GPIO_InitStructure; 
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB | RCC_AHB1Periph_GPIOB,ENABLE); //I2C1�Ľ�ʹ��
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C1,ENABLE); //i2c clkʹ��
	
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource7, GPIO_AF_I2C1); //SDA
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource6, GPIO_AF_I2C1); //SCL
	
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_7|GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
		
	I2C_DeInit(I2C1);
	I2C_InitStructure.I2C_Mode = I2C_Mode_I2C;
	I2C_InitStructure.I2C_DutyCycle = I2C_DutyCycle_2;
	I2C_InitStructure.I2C_OwnAddress1 = I2C1_SLAVE_ADDRESS7;
	I2C_InitStructure.I2C_Ack = I2C_Ack_Enable;
	I2C_InitStructure.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
	I2C_InitStructure.I2C_ClockSpeed = I2C1_SPEED;//400K
	
	I2C_Cmd(I2C1, ENABLE);
	I2C_Init(I2C1, &I2C_InitStructure);
	
	I2C_AcknowledgeConfig(I2C1, ENABLE);
}

void I2C2_Configuration(void)
{
	I2C_InitTypeDef  I2C_InitStructure;
	GPIO_InitTypeDef  GPIO_InitStructure; 
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB | RCC_AHB1Periph_GPIOB,ENABLE); //I2C1�Ľ�ʹ��
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C2,ENABLE); //i2c clkʹ��
	
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource11, GPIO_AF_I2C2); //SDA
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource10, GPIO_AF_I2C2); //SCL
	
	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_10;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
		
	I2C_DeInit(I2C2);
	I2C_InitStructure.I2C_Mode = I2C_Mode_I2C;
	I2C_InitStructure.I2C_DutyCycle = I2C_DutyCycle_2;
	I2C_InitStructure.I2C_OwnAddress1 = I2C2_SLAVE_ADDRESS7;
	I2C_InitStructure.I2C_Ack = I2C_Ack_Enable;
	I2C_InitStructure.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
	I2C_InitStructure.I2C_ClockSpeed = I2C2_SPEED;
	
	I2C_Cmd(I2C2, ENABLE);
	I2C_Init(I2C2, &I2C_InitStructure);
	
	I2C_AcknowledgeConfig(I2C2, ENABLE);
}


void I2C_delay(uint16_t cnt)
{
	while(cnt--);
}

/**
  * @brief  Basic management of the timeout situation.
  * @param  errorCode：错误代码，可以用来定位是哪个环节出错.
  * @retval 返回0，表示IIC读取失败.
  */
static uint32_t I2C_TIMEOUT_UserCallback(uint8_t errorCode)
{
  /* Block communication and all processes */
  IIC_ERROR("I2C 等待超时!errorCode = %d",errorCode);
  
  return 0;
}
/*******************************************************************************
* Function Name  : I2C_AcknowledgePolling
* Description    : Wait for EEPROM Standby state 
* Input          : I2C_TypeDef * , uint8_t
* Output         : None
* Return         : None
* Attention		 : None
*******************************************************************************/
static void I2C_AcknowledgePolling(I2C_TypeDef *I2Cx,uint8_t I2C_Addr)
{
  vu16 SR1_Tmp;
  do
  { 
    /* Send START condition */		
    I2C_GenerateSTART(I2Cx, ENABLE);
    /* Read EEPROM_I2C SR1 register */
    SR1_Tmp = I2C_ReadRegister(I2Cx, I2C_Register_SR1);
    /* Send EEPROM address for write */
	  I2C_Send7bitAddress(I2Cx, I2C_Addr, I2C_Direction_Transmitter);
  }while(!(I2C_ReadRegister(I2Cx, I2C_Register_SR1) & 0x0002));
  /* Clear AF flag */  
  I2C_ClearFlag(I2Cx, I2C_FLAG_AF);
  /* STOP condition */     
  I2C_GenerateSTOP(I2Cx, ENABLE);
}























/*******************************************************************************
* Function Name  : I2C_Read 没有加入超时机制
* Description    : 
* Input          : 
* Output         : 
* Return         : 
* Attention		 : None
*******************************************************************************/
//uint8_t I2C_Read(I2C_TypeDef *I2Cx,uint8_t I2C_Addr,uint8_t addr,uint8_t *buf,uint16_t num)
//{
//    if(num==0)
//	  return 1;
//	
//	  while(I2C_GetFlagStatus(I2Cx, I2C_FLAG_BUSY));
//		
//	  I2C_AcknowledgeConfig(I2Cx, ENABLE);


//    I2C_GenerateSTART(I2Cx, ENABLE);
//    while(!I2C_CheckEvent(I2Cx, I2C_EVENT_MASTER_MODE_SELECT));

//    I2C_Send7bitAddress(I2Cx,  I2C_Addr, I2C_Direction_Transmitter);
//    while (!I2C_CheckEvent(I2Cx, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED));

//	  I2C_SendData(I2Cx, addr);
//    while (!I2C_CheckEvent(I2Cx, I2C_EVENT_MASTER_BYTE_TRANSMITTED));
//		
//	  I2C_GenerateSTART(I2Cx, ENABLE);
//	  while(!I2C_CheckEvent(I2Cx, I2C_EVENT_MASTER_MODE_SELECT));
//	
//	  I2C_Send7bitAddress(I2Cx, I2C_Addr, I2C_Direction_Receiver);
//	  while(!I2C_CheckEvent(I2Cx, I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED));
//	
//    while (num)
//    {
//		if(num==1)
//		{
//     		I2C_AcknowledgeConfig(I2Cx, DISABLE);
//    		I2C_GenerateSTOP(I2Cx, ENABLE);
//		}
//	    
//		while(!I2C_CheckEvent(I2Cx, I2C_EVENT_MASTER_BYTE_RECEIVED));  /* EV7 */
//	    *buf = I2C_ReceiveData(I2Cx);
//	    buf++;
//	    /* Decrement the read bytes counter */
//	    num--;
//    }

//	I2C_AcknowledgeConfig(I2Cx, ENABLE);

//	return 0;
//}	

/*******************************************************************************
* Function Name  : I2C_WriteOneByte
* Description    : 
* Input          : 
* Output         : None
* Return         : 
* Attention		 : None
*******************************************************************************/
uint8_t I2C_WriteOneByte(I2C_TypeDef *I2Cx,uint8_t I2C_Addr,uint8_t addr,uint8_t value)
{
	I2CTimeout = I2C_Open207V_LONG_TIMEOUT;

	while(I2C_GetFlagStatus(I2Cx, I2C_FLAG_BUSY))
  {
    	if((I2CTimeout--) == 0) return I2C_TIMEOUT_UserCallback(4);
  }
		
  /* Send START condition */
  I2C_GenerateSTART(I2Cx, ENABLE);

  /* Test on EV5 and clear it */		
	I2CTimeout = I2C_Open207V_FLAG_TIMEOUT;
	while(!I2C_CheckEvent(I2Cx, I2C_EVENT_MASTER_MODE_SELECT))
	{
		if((I2CTimeout--) == 0) return I2C_TIMEOUT_UserCallback(5);
	} 

  /* Send EEPROM address for write */	
	I2C_Send7bitAddress(I2Cx, I2C_Addr, I2C_Direction_Transmitter);

  /* Test on EV6 and clear it */	
	I2CTimeout = I2C_Open207V_FLAG_TIMEOUT;	
	while(!I2C_CheckEvent(I2Cx, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED))
	{
		if((I2CTimeout--) == 0) return I2C_TIMEOUT_UserCallback(6);
	}

  /* Send the IIC address to write to */    	
  I2C_SendData(I2Cx, addr);
	
  /* Test on EV8 and clear it */ 	
	I2CTimeout = I2C_Open207V_FLAG_TIMEOUT;  
  while(!I2C_CheckEvent(I2Cx, I2C_EVENT_MASTER_BYTE_TRANSMITTED))
  {
    if((I2CTimeout--) == 0) return I2C_TIMEOUT_UserCallback(7);
  }
	
  /* Send the value to write to */ 
  I2C_SendData(I2Cx, value);

  /* Test on EV8 and clear it */	
	I2CTimeout = I2C_Open207V_FLAG_TIMEOUT; 
	while(!I2C_CheckEvent(I2Cx, I2C_EVENT_MASTER_BYTE_TRANSMITTED))
	{
		if((I2CTimeout--) == 0) return I2C_TIMEOUT_UserCallback(8);
	} 
	
  /* Send STOP condition */	
  	I2C_GenerateSTOP(I2Cx, ENABLE);
  
  	I2C_AcknowledgePolling(I2Cx,I2C_Addr);

	  I2C_delay(1);

	  return 0;
}


/*******************************************************************************
* Function Name  : I2C_Write
* Description    : 
* Input          : 
* Output         : None
* Return         : 
* Attention		 : None
*******************************************************************************/
//uint8_t I2C_Write(I2C_TypeDef *I2Cx,uint8_t I2C_Addr,uint8_t addr,uint8_t *buf,uint16_t num)
//{
//	uint8_t err=0;
//	
//	while(num--)
//	{
//		if(I2C_WriteOneByte(I2Cx, I2C_Addr,addr++,*buf++))
//		{
//			err++;
//		}
//	}
//	if(err)
//		return 1;
//	else 
//		return 0;	
//}

uint8_t I2C_Write(I2C_TypeDef *I2Cx,uint8_t I2C_Addr,uint8_t addr,uint8_t *buf,uint16_t num)
{
	I2CTimeout = I2C_Open207V_LONG_TIMEOUT;

	while(I2C_GetFlagStatus(I2Cx, I2C_FLAG_BUSY))
  {
    	if((I2CTimeout--) == 0) return I2C_TIMEOUT_UserCallback(4);
  }
		
  /* Send START condition */
  I2C_GenerateSTART(I2Cx, ENABLE);

  /* Test on EV5 and clear it */		
	I2CTimeout = I2C_Open207V_FLAG_TIMEOUT;
	while(!I2C_CheckEvent(I2Cx, I2C_EVENT_MASTER_MODE_SELECT))
	{
		if((I2CTimeout--) == 0) return I2C_TIMEOUT_UserCallback(5);
	} 

  /* Send EEPROM address for write */	
	I2C_Send7bitAddress(I2Cx, I2C_Addr, I2C_Direction_Transmitter);

  /* Test on EV6 and clear it */	
	I2CTimeout = I2C_Open207V_FLAG_TIMEOUT;	
	while(!I2C_CheckEvent(I2Cx, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED))
	{
		if((I2CTimeout--) == 0) return I2C_TIMEOUT_UserCallback(6);
	}

  /* Send the IIC address to write to */    	
  I2C_SendData(I2Cx, addr);
	
  /* Test on EV8 and clear it */ 	
	I2CTimeout = I2C_Open207V_FLAG_TIMEOUT;  
  while(!I2C_CheckEvent(I2Cx, I2C_EVENT_MASTER_BYTE_TRANSMITTED))
  {
    if((I2CTimeout--) == 0) return I2C_TIMEOUT_UserCallback(7);
  }
	
  /* While there is data to be written */
  while(num--)  
  {
    /* Send the current byte */
    I2C_SendData(I2Cx, *buf); 

    /* Point to the next byte to be written */
    buf++; 
  
    I2CTimeout = I2C_Open207V_FLAG_TIMEOUT;

    /* Test on EV8 and clear it */
    while (!I2C_CheckEvent(I2Cx, I2C_EVENT_MASTER_BYTE_TRANSMITTED))
    {
			if((I2CTimeout--) == 0) return I2C_TIMEOUT_UserCallback(8);
    } 
  } 
	
	
  /* Send STOP condition */	
  I2C_GenerateSTOP(I2Cx, ENABLE);
  
  I2C_AcknowledgePolling(I2Cx,I2C_Addr);

	I2C_delay(1);

	return 0;	
}
/**
  * @brief   从IIC里面读取一块数据 
  * @param   
  *		@arg buf:存放从IIC读取的数据的缓冲区指针
  *		@arg I2C_Addr:接收数据的IIC的地址
  *     @arg num:要从IIC读取的字节数
  * @retval  无
  */
uint8_t I2C_Read(I2C_TypeDef *I2Cx,uint8_t I2C_Addr,uint8_t addr,uint8_t *buf,uint16_t num)
{
    if(num==0)
	  return 1;
		
    I2CTimeout = I2C_Open207V_FLAG_TIMEOUT;	
	  while(I2C_GetFlagStatus(I2Cx, I2C_FLAG_BUSY))
		{
			if((I2CTimeout--) == 0) return I2C_TIMEOUT_UserCallback(9);			
		}

	  I2C_AcknowledgeConfig(I2Cx, ENABLE);
		
		/* Send START condition */	
    I2C_GenerateSTART(I2Cx, ENABLE);
    /* Test on EV5 and clear it */		
    I2CTimeout = I2C_Open207V_FLAG_TIMEOUT;			
    while(!I2C_CheckEvent(I2Cx, I2C_EVENT_MASTER_MODE_SELECT))
		{
			if((I2CTimeout--) == 0) return I2C_TIMEOUT_UserCallback(10);			
		}	
		/* Send iic address for write */
    I2C_Send7bitAddress(I2Cx,  I2C_Addr, I2C_Direction_Transmitter);
		/* Test on EV6 and clear it */		
	  I2CTimeout = I2C_Open207V_FLAG_TIMEOUT;				
    while (!I2C_CheckEvent(I2Cx, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED))
		{
			if((I2CTimeout--) == 0) return I2C_TIMEOUT_UserCallback(11);		
		}
		/* Send the IIC address to write to */
	  I2C_SendData(I2Cx, addr);
    I2CTimeout = I2C_Open207V_FLAG_TIMEOUT;		
    while (!I2C_CheckEvent(I2Cx, I2C_EVENT_MASTER_BYTE_TRANSMITTED))
		{
			if((I2CTimeout--) == 0) return I2C_TIMEOUT_UserCallback(12);			
		}
		/* Send STRAT condition a second time */  		
	  I2C_GenerateSTART(I2Cx, ENABLE);
		/* Test on EV5 and clear it */
    I2CTimeout = I2C_Open207V_FLAG_TIMEOUT;		
	  while(!I2C_CheckEvent(I2Cx, I2C_EVENT_MASTER_MODE_SELECT))
		{
			if((I2CTimeout--) == 0) return I2C_TIMEOUT_UserCallback(13);			
		}
    /* Send IIC address for read */	
	  I2C_Send7bitAddress(I2Cx, I2C_Addr, I2C_Direction_Receiver);
		
		/* Test on EV6 and clear it */
    I2CTimeout = I2C_Open207V_FLAG_TIMEOUT;				
	  while(!I2C_CheckEvent(I2Cx, I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED))
		{
			if((I2CTimeout--) == 0) return I2C_TIMEOUT_UserCallback(14);			
		}
	
    while (num)
    {
			if(num==1)
			{ /* Disable Acknowledgement */
     		I2C_AcknowledgeConfig(I2Cx, DISABLE);
				/* Send STOP Condition */				
    		I2C_GenerateSTOP(I2Cx, ENABLE);
			}
			
			I2CTimeout = I2C_Open207V_LONG_TIMEOUT;	    
			while(I2C_CheckEvent(I2Cx, I2C_EVENT_MASTER_BYTE_RECEIVED) == 0)  /* EV7 */
			{
				if((I2CTimeout--) == 0) return I2C_TIMEOUT_UserCallback(3);				
			}
			
				/* Read a byte from the device */			
				*buf = I2C_ReceiveData(I2Cx);
        /* Point to the next location where the byte read will be saved */			
				buf++;
				/* Decrement the read bytes counter */
				num--;
    }
		
		/* Enable Acknowledgement to be ready for another reception */
		I2C_AcknowledgeConfig(I2Cx, ENABLE);

	return 0;	
}