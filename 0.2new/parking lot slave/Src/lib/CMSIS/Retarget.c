/******************************************************************************/
/* RETARGET.C: 'Retarget' layer for target-dependent low level functions      */
/******************************************************************************/
/* This file is part of the uVision/ARM development tools.                    */
/* Copyright (c) 2005 Keil Software. All rights reserved.                     */
/* This software may only be used under the terms of a valid, current,        */
/* end user licence from KEIL for a compatible version of KEIL software       */
/* development tools. Nothing else gives you the right to use this software.  */
/******************************************************************************/

#include <stdio.h>
#include <time.h>
#include <rt_misc.h>
#include "main.h"
#pragma import(__use_no_semihosting_swi)


extern int  sendchar(int ch);  /* in Serial.c */
extern int  getkey(void);      /* in Serial.c */
extern long timeval;           /* in Time.c   */


struct __FILE { int handle; /* Add whatever you need here */ };
FILE __stdout;
FILE __stdin;
FILE __stderr;


int fputc(int ch, FILE *f) {
	#ifdef __debug
  return (sendchar(ch));
	#endif
}

int fgetc(FILE *f) {
	#ifdef __debug
  return (sendchar(getkey()));
	#endif
}


int ferror(FILE *f) {
  /* Your implementation of ferror */
  return EOF;
}


void _ttywrch(int ch) {
  sendchar (ch);
}


void _sys_exit(int return_code) {
	printf("sys_exit \n");
  while (1);    /* endless loop */
}

//////////////////////////////////////////////

FILE *fopen(const char * path,const char * mode)
{
	//usart1<<"\n\r fopen. \n\r";
	return NULL;
}

long int ftell(FILE *stream){
/* Your implementation of ftell(). */
	//usart1<<"ftell\n\r";
	return 0;
}

int fclose(FILE *f){
/* Your implementation of fclose(). */
	//usart1<<"\n\r fclose \n\r";
	return 0;
}

int fseek(FILE *f, long nPos, int nMode){
/* Your implementation of fseek(). */
	//usart1<<"fseek\n\r";
	return 0;
}

int fflush(FILE *f){
/* Your implementation of fflush(). */
	return 0;
}