/* 包含头文件 *****************************************************************/
#include "common.h"
#include "ymodem.h"
#include "BspTime.h"
#include "bsp_uart_update.h"
#include "iap.h"
/* 变量 ----------------------------------------------------------------------*/
pFunction Jump_To_Application;
uint32_t JumpAddress;
uint32_t BlockNbr = 0, UserMemoryMask = 0;
__IO uint32_t FlashProtection = 0;
extern uint32_t FlashDestination;


/*******************************************************************************
  * @函数名称：Int2Str
  * @函数说明：整形数据转到字符串
  * @输入参数：intnum:数据
  * @输出参数：str：转换为的字符串
  * @返回参数：无
  * @历史记录:     
     <作者>    <时间>      <修改记录>
*******************************************************************************/
void Int2Str(uint8_t* str, int32_t intnum)
{
    uint32_t i, Div = 1000000000, j = 0, Status = 0;

    for (i = 0; i < 10; i++)
    {
        str[j++] = (intnum / Div) + 48;

        intnum = intnum % Div;
        Div /= 10;
        if ((str[j-1] == '0') & (Status == 0))
        {
            j = 0;
        }
        else
        {
            Status++;
        }
    }
}
/*******************************************************************************
* @函数名称：Hex2Str
* @函数说明：整形数据转到Hex字符串
* @输入参数：intnum:数据
* @输出参数：str：转换为的字符串
* @返回参数：无
* @历史记录:
<作者>    <时间>      <修改记录>
*******************************************************************************/
void Hex2Str(uint8_t* str, int32_t intnum)
{
	uint32_t i, Div = 1000000000, j = 0, Status = 0;
	uint8_t hextmp[4] = { 0 };
	for (i = 0;i<4;i++)
	{
		hextmp[i] = intnum % 256;//取出低8位数据
		   intnum = intnum / 256;//右移8位
	}

	for (i = 0; i < 4; i++)
	{
		if ((*(hextmp + 3 - i) / 16) > 9)
		{//字符A~
			str[j++] = *(hextmp + 3 - i) / 16 + 55;//高位	
		}
		else {//数字
			str[j++] = *(hextmp + 3 - i) / 16 + 48;//高位	
		}

		if ((*(hextmp + 3 - i) % 16) > 9)
		{//字符A~
			str[j++] = *(hextmp + 3 - i) % 16 + 55;//低位
		}
		else {//数字
			str[j++] = *(hextmp + 3 - i) % 16 + 48;//低位
		}
	}
	//str[j--] = '/0';//补充/0
}
/*******************************************************************************
  * @函数名称：Int2Str
  * @函数说明：字符串转到数据
  * @输入参数：inputstr:需转换的字符串
  * @输出参数：intnum：转好的数据
  * @返回参数：转换结果
               1：正确
               0：错误
  * @历史记录:     
     <作者>    <时间>      <修改记录>
*******************************************************************************/
uint32_t Str2Int(uint8_t *inputstr, int32_t *intnum)
{
    uint32_t i = 0, res = 0;
    uint32_t val = 0;

    if (inputstr[0] == '0' && (inputstr[1] == 'x' || inputstr[1] == 'X'))
    {
        if (inputstr[2] == '\0')
        {
            return 0;
        }
        for (i = 2; i < 11; i++)
        {
            if (inputstr[i] == '\0')
            {
                *intnum = val;
                //返回1
                res = 1;
                break;
            }
            if (ISVALIDHEX(inputstr[i]))
            {
                val = (val << 4) + CONVERTHEX(inputstr[i]);
            }
            else
            {
                //无效输入返回0
                res = 0;
                break;
            }
        }

        if (i >= 11)
        {
            res = 0;
        }
    }
    else//最多10为2输入
    {
        for (i = 0; i < 11; i++)
        {
            if (inputstr[i] == '\0')
            {
                *intnum = val;
                //返回1
                res = 1;
                break;
            }
            else if ((inputstr[i] == 'k' || inputstr[i] == 'K') && (i > 0))
            {
                val = val << 10;
                *intnum = val;
                res = 1;
                break;
            }
            else if ((inputstr[i] == 'm' || inputstr[i] == 'M') && (i > 0))
            {
                val = val << 20;
                *intnum = val;
                res = 1;
                break;
            }
            else if (ISVALIDDEC(inputstr[i]))
            {
                val = val * 10 + CONVERTDEC(inputstr[i]);
            }
            else
            {
                //无效输入返回0
                res = 0;
                break;
            }
        }
        //超过10位无效，返回0
        if (i >= 11)
        {
            res = 0;
        }
    }

    return res;
}

/*******************************************************************************
  * @函数名称：Int2Str
  * @函数说明：字符串转到数据
  * @输入参数：inputstr:需转换的字符串
  * @输出参数：intnum：转好的数据
  * @返回参数：转换结果
               1：正确
               0：错误
  * @历史记录:     
     <作者>    <时间>      <修改记录>
*******************************************************************************/
/**
  * @brief  Get an integer from the HyperTerminal
  * @param  num: The inetger
  * @retval 1: Correct
  *         0: Error
  */
uint32_t GetIntegerInput(int32_t * num)
{
    uint8_t inputstr[16];

    while (1)
    {
        GetInputString(inputstr);
        if (inputstr[0] == '\0') continue;
        if ((inputstr[0] == 'a' || inputstr[0] == 'A') && inputstr[1] == '\0')
        {
            SerialPutString("User Cancelled \r\n");
            return 0;
        }

        if (Str2Int(inputstr, num) == 0)
        {
            SerialPutString("Error, Input again: \r\n");
        }
        else
        {
            return 1;
        }
    }
}

/*******************************************************************************
  * @函数名称：SerialKeyPressed
  * @函数说明：测试超级终端是否有按键按下
  * @输入参数：key:按键
  * @输出参数：无
  * @返回参数：1：正确
               0：错误
  * @历史记录:     
     <作者>    <时间>      <修改记录>
*******************************************************************************/
uint32_t SerialKeyPressed(uint8_t *key)
{

    if ( USART_GetFlagStatus(DownLoad_USARTx, USART_FLAG_RXNE) != RESET)
    {
        *key = (uint8_t)DownLoad_USARTx->DR;
        return 1;
    }
    else
    {
        return 0;
    }
}

/*******************************************************************************
  * @函数名称：GetKey
  * @函数说明：通过超级中断回去键码
  * @输入参数：无
  * @输出参数：无
  * @返回参数：按下的键码
  * @历史记录:     
     <作者>    <时间>      <修改记录>
*******************************************************************************/
uint8_t GetKey(void)
{
    uint8_t key = 0;

    //等待按键按下
    while (IS_TIMEOUT_1MS(eTim2, 3000))
    {
        if (SerialKeyPressed((uint8_t*)&key)) break;
    }
    return key;

}

/*******************************************************************************
  * @函数名称：SerialPutChar
  * @函数说明：串口发送一个字符
  * @输入参数：C:需发送的字符
  * @输出参数：无
  * @返回参数：无
  * @历史记录:     
     <作者>    <时间>      <修改记录>
*******************************************************************************/
void SerialPutChar(uint8_t c)
{
    USART_SendData(DownLoad_USARTx, c);
    while (USART_GetFlagStatus(DownLoad_USARTx, USART_FLAG_TXE) == RESET)
    {
    }
}

/*******************************************************************************
  * @函数名称：SerialPutChar
  * @函数说明：串口发送一个字符串
  * @输入参数：*s:需发送的字符串
  * @输出参数：无
  * @返回参数：无
  * @历史记录:     
     <作者>    <时间>      <修改记录>
*******************************************************************************/
void Serial_PutString(uint8_t *s)
{
    while (*s != '\0')
    {
        SerialPutChar(*s);
        s++;
    }
}


/*******************************************************************************
  * @函数名称：GetInputString
  * @函数说明：从串口获取一个字符串
  * @输入参数：*s:存字符串的地址
  * @输出参数：无
  * @返回参数：无
  * @历史记录:     
     <作者>    <时间>      <修改记录>
*******************************************************************************/
void GetInputString (uint8_t * buffP)
{
    uint32_t bytes_read = 0;
    uint8_t c = 0;
    do
    {
        c = GetKey();
        if (c == '\r')
            break;
        if (c == '\b')// Backspace 按键  
        {
            if (bytes_read > 0)
            {
                SerialPutString("\b \b");
                bytes_read --;
            }
            continue;
        }
        if (bytes_read >= CMD_STRING_SIZE )
        {
            SerialPutString("Command string size overflow\r\n");
            bytes_read = 0;
            continue;
        }
        if (c >= 0x20 && c <= 0x7E)
        {
            buffP[bytes_read++] = c;
            SerialPutChar(c);
        }
    }
    while (1);
    SerialPutString(("\n\r"));
    buffP[bytes_read] = '\0';
}

/*******************************************************************************
  * @函数名称：Main_Menu
  * @函数说明：显示菜单栏在超级终端
  * @输入参数：无
  * @输出参数：无
  * @返回参数：无
  * @历史记录:     
     <作者>    <时间>      <修改记录>
*******************************************************************************/
void Main_Menu(void)
{
    uint8_t key = 0;
    static uint8_t uStatus = 0;
	  uint8_t tmp = 0;
	/* Download user application in the Flash */
		tmp = FlashDownload();
		if (tmp == 1)
		SerialPutString( "\rFlash update success\n\r");//
		else 
		SerialPutString("\rFlash don't have Application\n\r"); //
										
    while (IS_TIMEOUT_1MS(eTim2, 300))//倒计时用户选择
    {
        switch(uStatus)
        {
            case 0:
							SerialPutString("\r*********************************************************\r\n");
							SerialPutString( "1.Uart Update Application\r\n");  
							//SerialPutString( "2.flash更新应用程序。\r\n");							
							SerialPutString( "2.Run  Application\r\n");				
							SerialPutString( "*********************************************************\r\n");
							SerialPutString( "please select 1 or 2:\r\n");
							uStatus = 1;
            break;
            case 1:
							SerialPutString( "......\r\n");//
							key = GetKey();
							if (key == 0x31)
							{
									/* Download user application in the Flash */
									SerialDownload();
									SerialPutString("\rUart Update Application Finish\n\r"); //
							}
//							else if (key == 0x32)
//							{
//									/* Download user application in the Flash */
//									  tmp = FlashDownload();
//								    if (tmp == 1)
//										SerialPutString( "\rFlash更新完成\n\r");//
//								    else 
//										SerialPutString("\rFlash更新失败\n\r"); //
//							}
							else if (key == 0x32)
							{
									SerialPutString("run into Application...\r\n");
									SerialPutString(" \r\n");
									BspTim2Close();
									iap_load_app(ApplicationAddress);//有程序直接跳转了
									SerialPutString("no user Program\r\n\n");
							}   
						
						//SerialPutString( "\r进入APP\n\r");//
						break;
            default://默认从外部flash 读取
            break;
        }  
    }	
}


/*******************************文件结束***************************************/
