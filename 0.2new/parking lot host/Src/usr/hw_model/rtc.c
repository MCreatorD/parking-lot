#include "rtc.h"
#include <stdio.h>
#include <time.h>

#define RTC_CLOCK_SOURCE_LSE

RTC_InitTypeDef RTC_InitStructure;
RTC_TimeTypeDef RTC_TimeStructure;
RTC_DateTypeDef RTC_DateStructure;
RTC_TimeTypeDef  RTC_TimeStampStructure;
RTC_DateTypeDef  RTC_TimeStampDateStructure;
__IO uint32_t AsynchPrediv = 0, SynchPrediv = 0;


void RTC_Config(void)
{
  /* Enable the PWR clock */
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR, ENABLE);

  /* Allow access to RTC */
  PWR_BackupAccessCmd(ENABLE);

#if defined (RTC_CLOCK_SOURCE_LSI)  /* LSI used as RTC source clock*/
/* The RTC Clock may varies due to LSI frequency dispersion. */
  /* Enable the LSI OSC */ 
  RCC_LSICmd(ENABLE);

  /* Wait till LSI is ready */  
  while(RCC_GetFlagStatus(RCC_FLAG_LSIRDY) == RESET)
  {
  }

  /* Select the RTC Clock Source */
  RCC_RTCCLKConfig(RCC_RTCCLKSource_LSI);

  SynchPrediv = 0xFF;
  AsynchPrediv = 0x7F;

#elif defined (RTC_CLOCK_SOURCE_LSE) /* LSE used as RTC source clock */
  /* Enable the LSE OSC */
  RCC_LSEConfig(RCC_LSE_ON);

  /* Wait till LSE is ready */  
  while(RCC_GetFlagStatus(RCC_FLAG_LSERDY) == RESET)
  {
  }

  /* Select the RTC Clock Source */
  RCC_RTCCLKConfig(RCC_RTCCLKSource_LSE);

  SynchPrediv = 0xFF;
  AsynchPrediv = 0x7F;
    
#else
  #error Please select the RTC Clock source inside the main.c file
#endif /* RTC_CLOCK_SOURCE_LSI */

  /* Enable the RTC Clock */
  RCC_RTCCLKCmd(ENABLE);

  /* Wait for RTC APB registers synchronisation */
  RTC_WaitForSynchro();

  /* Enable The TimeStamp */
  RTC_TimeStampCmd(RTC_TimeStampEdge_Falling, ENABLE);    
}

/**
  * @brief  Display the current time on the Hyperterminal.
  * @param  None
  * @retval None
  */
void RTC_TimeShow(void)
{
  /* Get the current Time and Date */
  RTC_GetTime(RTC_Format_BIN, &RTC_TimeStructure);
 // printf("\r============== Current Time Display ============================\n");
  printf("\n\r  The current time (Hour-Minute-Second) is :  %0.2d:%0.2d:%0.2d \n", RTC_TimeStructure.RTC_Hours, RTC_TimeStructure.RTC_Minutes, RTC_TimeStructure.RTC_Seconds);
  /* Unfreeze the RTC DR Register */
  (void)RTC->DR;
}

/**
  * @brief  Display the current date on the Hyperterminal.
  * @param  None
  * @retval None
  */
void RTC_DateShow(void)
{
  /* Get the current Date */
  RTC_GetDate(RTC_Format_BIN, &RTC_DateStructure);
 // printf("\r============== Current Date Display ============================\n");
  printf("\n\r  The current date (WeekDay-Date-Month-Year) is :  %0.2d-%0.2d-%0.2d-%0.2d \n", RTC_DateStructure.RTC_WeekDay, RTC_DateStructure.RTC_Date, RTC_DateStructure.RTC_Month, RTC_DateStructure.RTC_Year);
}


/**
  * @brief  Display the current TimeStamp (time and date) on the Hyperterminal.
  * @param  None
  * @retval None
  */
void RTC_TimeStampShow(void)
{
//  /* Get the current TimeStamp */
//  RTC_GetTimeStamp(RTC_Format_BIN, &RTC_TimeStampStructure, &RTC_TimeStampDateStructure);
//  printf("\r==============TimeStamp Display (Time and Date)=================\n");
//  printf("\n\r  The current time stamp time (Hour-Minute-Second) is :  %0.2d:%0.2d:%0.2d \n", RTC_TimeStampStructure.RTC_Hours, RTC_TimeStampStructure.RTC_Minutes, RTC_TimeStampStructure.RTC_Seconds);
//  printf("\n\r  The current timestamp date (WeekDay-Date-Month) is :  %0.2d-%0.2d-%0.2d \n", RTC_TimeStampDateStructure.RTC_WeekDay, RTC_TimeStampDateStructure.RTC_Date, RTC_TimeStampDateStructure.RTC_Month);

	
	RTC_GetTime(RTC_Format_BIN, &RTC_TimeStructure);
	RTC_GetDate(RTC_Format_BIN, &RTC_DateStructure);
#if 0
	printf("\r\n  The current date (WeekDay-Date-Month-Year) is :  %0.2d-%0.2d-%0.2d-%0.2d \n", RTC_DateStructure.RTC_WeekDay, RTC_DateStructure.RTC_Date, RTC_DateStructure.RTC_Month, RTC_DateStructure.RTC_Year);
	printf("\r\n  The current time (Hour-Minute-Second) is :  %0.2d:%0.2d:%0.2d \n", RTC_TimeStructure.RTC_Hours, RTC_TimeStructure.RTC_Minutes, RTC_TimeStructure.RTC_Seconds);	
#endif
	(void)RTC->DR;


}

time_t getUtc()
{
	time_t utc;
	struct tm *gm_date;
    RTC_GetTime(RTC_Format_BIN, &RTC_TimeStructure);
	RTC_GetDate(RTC_Format_BIN, &RTC_DateStructure);

	gm_date->tm_year=RTC_DateStructure.RTC_Year;//2018年,+1900就是现在的年
	gm_date->tm_mon=RTC_DateStructure.RTC_Month;//4月
	gm_date->tm_mday=RTC_DateStructure.RTC_Date;
	gm_date->tm_hour=RTC_TimeStructure.RTC_Hours;
	gm_date->tm_min=RTC_TimeStructure.RTC_Minutes;
	gm_date->tm_sec=RTC_TimeStructure.RTC_Seconds;
	
	utc = mktime(gm_date);
	printf("unix timestamp:%08x \r\n",utc);
	return utc;
}


int setRtc(unsigned int utc){
	
	int tmp_hh = 00; //tmp_hh = ((*time_date).tm_hour);
	int tmp_mm = 0; //(*time_date).tm_min;
	int tmp_ss = 0; //(*time_date).tm_sec;
	int tmp_year = 0; //(*time_date).tm_year-100;//年从2000开始算起
	int tmp_mon = 0; //(*time_date).tm_mon+1;
  int tmp_day = 0; //(*time_date).tm_mday;
	
	time_t t = utc;
	struct tm *time_date = localtime(&t);//在keil c下直接使用localtime即可转换时间，不可使用gmtime
	printf("tm_year = %d\n",(*time_date).tm_year-1900);
	printf("tm_mday = %d\n",(*time_date).tm_mday);
	printf("tm_mon = %d\n",(*time_date).tm_mon+1);
	printf("tm_hour = %d\n",(*time_date).tm_hour);
	printf("tm_min = %d\n",(*time_date).tm_min);
	printf("tm_sec = %d\n",(*time_date).tm_sec);
	
	tmp_hh = (*time_date).tm_hour;
	tmp_mm = (*time_date).tm_min;
	tmp_ss = (*time_date).tm_sec;
	tmp_year = (*time_date).tm_year-100;//年从2000开始算起
	tmp_mon = (*time_date).tm_mon+1;
  tmp_day = (*time_date).tm_mday;

	RTC_TimeStructure.RTC_H12     = RTC_H12_AM;
  printf("\r Set Hours\n");
  RTC_TimeStructure.RTC_Hours = tmp_hh;

  printf(":  %0.2d\n", tmp_hh);
  
  printf("\r  Set Minutes\n");
  RTC_TimeStructure.RTC_Minutes = tmp_mm;
  printf(":  %0.2d\n", tmp_mm);
  
  printf("\r  Set Seconds\n");
  RTC_TimeStructure.RTC_Seconds = tmp_ss;
  printf(":  %0.2d\n", tmp_ss);
	
  if(RTC_SetTime(RTC_Format_BIN, &RTC_TimeStructure) == ERROR)
  {
    printf("\n>> !! RTC Set Time failed. !! <<\n");
		return 0;
  } 
  else
  {
    printf("\n>> !! RTC Set Time success. !! <<\n");
    RTC_TimeShow();
    RTC_WriteBackupRegister(RTC_BKP_DR0, 0x32F2);
  }
  
	printf("\r Set WeekDay (01-07)\n");
  RTC_DateStructure.RTC_WeekDay = (*time_date).tm_wday+1;


  printf("\r Set Date (01-31)\n");
  RTC_DateStructure.RTC_Date = tmp_day;

  
  printf("\r Set Month (01-12)\n");
  RTC_DateStructure.RTC_Month = tmp_mon;

  
  printf("\r Set Year (00-99)\n");
  RTC_DateStructure.RTC_Year = tmp_year;


  if(RTC_SetDate(RTC_Format_BIN, &RTC_DateStructure) == ERROR)
  {
    printf("\n>> !! RTC Set Date failed. !! <<\n");
		return 0;
  } 
  else
  {
    printf("\n>> !! RTC Set Date success. !! <<\n");
    RTC_DateShow();
    RTC_WriteBackupRegister(RTC_BKP_DR0, 0x32F2);
  }
	return 1;
}

void RTC_TimeRegulate(void)
{
  uint32_t tmp_hh = 00, tmp_mm = 00, tmp_ss = 00;

  printf("\r==============Default Time Settings=====================================\n");
  RTC_TimeStructure.RTC_H12     = RTC_H12_AM;
  printf("\r Set Hours\n");
  RTC_TimeStructure.RTC_Hours = tmp_hh;

  printf(":  %0.2d\n", tmp_hh);
  
  printf("\r  Set Minutes\n");
  RTC_TimeStructure.RTC_Minutes = tmp_mm;
  printf(":  %0.2d\n", tmp_mm);
  
  printf("\r  Set Seconds\n");
  RTC_TimeStructure.RTC_Seconds = tmp_ss;
  printf(":  %0.2d\n", tmp_ss);

  /* Configure the RTC time register */
  if(RTC_SetTime(RTC_Format_BIN, &RTC_TimeStructure) == ERROR)
  {
    printf("\n>> !! RTC Set Time failed. !! <<\n");
  } 
  else
  {
    printf("\n>> !! RTC Set Time success. !! <<\n");
    RTC_TimeShow();
    /* Indicator for the RTC configuration */
    RTC_WriteBackupRegister(RTC_BKP_DR0, 0x32F2);
  }
  
  tmp_hh = 01;
  tmp_mm = 01;
  tmp_ss = 18;

  printf("\r==============Default Date Settings=====================================\n");
	printf("\r Set WeekDay (01-07)\n");
  RTC_DateStructure.RTC_WeekDay = tmp_hh;
  printf(":  %0.2d\n", tmp_hh);
  tmp_hh = 01;
  printf("\r Set Date (01-31)\n");
  RTC_DateStructure.RTC_Date = tmp_hh;
  printf(":  %0.2d\n", tmp_hh);
  
  printf("\r Set Month (01-12)\n");
  RTC_DateStructure.RTC_Month = tmp_mm;
  printf(":  %0.2d\n", tmp_mm);
  
  printf("\r Set Year (00-99)\n");
  RTC_DateStructure.RTC_Year = tmp_ss;
  printf(":  %0.2d\n", tmp_ss);

  /* Configure the RTC date register */
  if(RTC_SetDate(RTC_Format_BIN, &RTC_DateStructure) == ERROR)
  {
    printf("\n>> !! RTC Set Date failed. !! <<\n");
  } 
  else
  {
    printf("\n>> !! RTC Set Date success. !! <<\n");
    RTC_DateShow();
    /* Indicator for the RTC configuration */
    RTC_WriteBackupRegister(RTC_BKP_DR0, 0x32F2);
  }

}

void initRtc(){
	if (RTC_ReadBackupRegister(RTC_BKP_DR0) != 0x32F2)
  {
    /* RTC configuration  */
    RTC_Config();

    /* Configure the RTC data register and RTC prescaler */
    RTC_InitStructure.RTC_AsynchPrediv = AsynchPrediv;
    RTC_InitStructure.RTC_SynchPrediv = SynchPrediv;
    RTC_InitStructure.RTC_HourFormat = RTC_HourFormat_24;
   
    /* Check on RTC init */
    if (RTC_Init(&RTC_InitStructure) == ERROR)
    {
//      printf("\n\r        /!\\***** RTC Prescaler Config failed ********/!\\ \n");
    }

    /* Configure the time register */
    RTC_TimeRegulate(); 
  }
  else
  {
    /* Check if the Power On Reset flag is set */
    if (RCC_GetFlagStatus(RCC_FLAG_PORRST) != RESET)
    {
//      printf("\r\n Power On Reset occurred....\n");
    }
    /* Check if the Pin Reset flag is set */
    else if (RCC_GetFlagStatus(RCC_FLAG_PINRST) != RESET)
    {
//      printf("\r\n External Reset occurred....\n");
    }

 //   printf("\r\n No need to configure RTC....\n");
    
    /* Enable the PWR clock */
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR, ENABLE);

    /* Allow access to RTC */
    PWR_BackupAccessCmd(ENABLE);

    /* Wait for RTC APB registers synchronisation */
    RTC_WaitForSynchro();

    /* Clear the RTC Alarm Flag */
    RTC_ClearFlag(RTC_FLAG_ALRAF);

    /* Clear the EXTI Line 17 Pending bit (Connected internally to RTC Alarm) */
    EXTI_ClearITPendingBit(EXTI_Line17);

    /* Display the RTC Time/Date and TimeStamp Time/Date */
    RTC_TimeShow();
    RTC_DateShow();
    RTC_TimeStampShow();
  }
	
}


