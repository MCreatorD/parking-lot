/*******************************************************************************
** �ļ���: 		common.c
** �汾��  		1.0
** ��������: 	RealView MDK-ARM 5.20
** ����: 		
** ��������: 	2016-03-20
** ����:		��ʾ���˵������˵�����ʾһϵ�в���������ض������ļ���
                ִ��Ӧ�ó����Լ���ֹд����(�������Flash��д����)��
** ����ļ�:	common.h��ymodem.h
** �޸���־��	2016-03-20   �����ĵ�
*******************************************************************************/

/* ����ͷ�ļ� *****************************************************************/
#include "common.h"
#include "ymodem.h"
#include "BspTime.h"
#include "bsp_uart_update.h"
#include "iap.h"
/* ���� ----------------------------------------------------------------------*/
pFunction Jump_To_Application;
uint32_t JumpAddress;
uint32_t BlockNbr = 0, UserMemoryMask = 0;
__IO uint32_t FlashProtection = 0;
extern uint32_t FlashDestination;


/*******************************************************************************
  * @�������ƣ�Int2Str
  * @����˵������������ת���ַ���
  * @���������intnum:����
  * @���������str��ת��Ϊ���ַ���
  * @���ز�������
  * @��ʷ��¼:     
     <����>    <ʱ��>      <�޸ļ�¼>
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
* @�������ƣ�Hex2Str
* @����˵������������ת��Hex�ַ���
* @���������intnum:����
* @���������str��ת��Ϊ���ַ���
* @���ز�������
* @��ʷ��¼:
<����>    <ʱ��>      <�޸ļ�¼>
*******************************************************************************/
void Hex2Str(uint8_t* str, int32_t intnum)
{
	uint32_t i, Div = 1000000000, j = 0, Status = 0;
	uint8_t hextmp[4] = { 0 };
	for (i = 0;i<4;i++)
	{
		hextmp[i] = intnum % 256;//ȡ����8λ����
		   intnum = intnum / 256;//����8λ
	}

	for (i = 0; i < 4; i++)
	{
		if ((*(hextmp + 3 - i) / 16) > 9)
		{//�ַ�A~
			str[j++] = *(hextmp + 3 - i) / 16 + 55;//��λ	
		}
		else {//����
			str[j++] = *(hextmp + 3 - i) / 16 + 48;//��λ	
		}

		if ((*(hextmp + 3 - i) % 16) > 9)
		{//�ַ�A~
			str[j++] = *(hextmp + 3 - i) % 16 + 55;//��λ
		}
		else {//����
			str[j++] = *(hextmp + 3 - i) % 16 + 48;//��λ
		}
	}
	//str[j--] = '/0';//����/0
}
/*******************************************************************************
  * @�������ƣ�Int2Str
  * @����˵�����ַ���ת������
  * @���������inputstr:��ת�����ַ���
  * @���������intnum��ת�õ�����
  * @���ز�����ת�����
               1����ȷ
               0������
  * @��ʷ��¼:     
     <����>    <ʱ��>      <�޸ļ�¼>
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
                //����1
                res = 1;
                break;
            }
            if (ISVALIDHEX(inputstr[i]))
            {
                val = (val << 4) + CONVERTHEX(inputstr[i]);
            }
            else
            {
                //��Ч���뷵��0
                res = 0;
                break;
            }
        }

        if (i >= 11)
        {
            res = 0;
        }
    }
    else//���10Ϊ2����
    {
        for (i = 0; i < 11; i++)
        {
            if (inputstr[i] == '\0')
            {
                *intnum = val;
                //����1
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
                //��Ч���뷵��0
                res = 0;
                break;
            }
        }
        //����10λ��Ч������0
        if (i >= 11)
        {
            res = 0;
        }
    }

    return res;
}

/*******************************************************************************
  * @�������ƣ�Int2Str
  * @����˵�����ַ���ת������
  * @���������inputstr:��ת�����ַ���
  * @���������intnum��ת�õ�����
  * @���ز�����ת�����
               1����ȷ
               0������
  * @��ʷ��¼:     
     <����>    <ʱ��>      <�޸ļ�¼>
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
  * @�������ƣ�SerialKeyPressed
  * @����˵�������Գ����ն��Ƿ��а�������
  * @���������key:����
  * @�����������
  * @���ز�����1����ȷ
               0������
  * @��ʷ��¼:     
     <����>    <ʱ��>      <�޸ļ�¼>
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
  * @�������ƣ�GetKey
  * @����˵����ͨ�������жϻ�ȥ����
  * @�����������
  * @�����������
  * @���ز��������µļ���
  * @��ʷ��¼:     
     <����>    <ʱ��>      <�޸ļ�¼>
*******************************************************************************/
uint8_t GetKey(void)
{
    uint8_t key = 0;

    //�ȴ���������
    while (IS_TIMEOUT_1MS(eTim2, 3000))
    {
        if (SerialKeyPressed((uint8_t*)&key)) break;
    }
    return key;

}

/*******************************************************************************
  * @�������ƣ�SerialPutChar
  * @����˵�������ڷ���һ���ַ�
  * @���������C:�跢�͵��ַ�
  * @�����������
  * @���ز�������
  * @��ʷ��¼:     
     <����>    <ʱ��>      <�޸ļ�¼>
*******************************************************************************/
void SerialPutChar(uint8_t c)
{
    USART_SendData(DownLoad_USARTx, c);
    while (USART_GetFlagStatus(DownLoad_USARTx, USART_FLAG_TXE) == RESET)
    {
    }
}

/*******************************************************************************
  * @�������ƣ�SerialPutChar
  * @����˵�������ڷ���һ���ַ���
  * @���������*s:�跢�͵��ַ���
  * @�����������
  * @���ز�������
  * @��ʷ��¼:     
     <����>    <ʱ��>      <�޸ļ�¼>
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
  * @�������ƣ�GetInputString
  * @����˵�����Ӵ��ڻ�ȡһ���ַ���
  * @���������*s:���ַ����ĵ�ַ
  * @�����������
  * @���ز�������
  * @��ʷ��¼:     
     <����>    <ʱ��>      <�޸ļ�¼>
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
        if (c == '\b')// Backspace ����  
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
  * @�������ƣ�Main_Menu
  * @����˵������ʾ�˵����ڳ����ն�
  * @�����������
  * @�����������
  * @���ز�������
  * @��ʷ��¼:     
     <����>    <ʱ��>      <�޸ļ�¼>
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
										
    while (IS_TIMEOUT_1MS(eTim2, 300))//����ʱ�û�ѡ��
    {
        switch(uStatus)
        {
            case 0:
							SerialPutString("\r*********************************************************\r\n");
							SerialPutString( "1.Uart Update Application\r\n");  
							//SerialPutString( "2.flash����Ӧ�ó���\r\n");							
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
//										SerialPutString( "\rFlash�������\n\r");//
//								    else 
//										SerialPutString("\rFlash����ʧ��\n\r"); //
//							}
							else if (key == 0x32)
							{
									SerialPutString("run into Application...\r\n");
									SerialPutString(" \r\n");
									BspTim2Close();
									iap_load_app(ApplicationAddress);//�г���ֱ����ת��
									SerialPutString("no user Program\r\n\n");
							}   
						
						//SerialPutString( "\r����APP\n\r");//
						break;
            default://Ĭ�ϴ��ⲿflash ��ȡ
            break;
        }  
    }	
}


/*******************************�ļ�����***************************************/
