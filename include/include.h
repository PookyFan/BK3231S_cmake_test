//======================================================
// File Name:     include.h
// Author:        Zhou Guofei 
// Created Date:  
// Description:   Include Header file used in C Firmware Test
//                Re-Created for BK3231S @2014-09-11
//======================================================


#ifndef _FIRMWARE_INCLUDE_H_
#define _FIRMWARE_INCLUDE_H_


//----------------------------------------------
typedef unsigned char  BYTE;
typedef signed   int  int32;      //  �з���32λ���ͱ���
typedef signed   short int16;      //  �з���16λ���ͱ���
typedef signed   char  int8;       //  �з���8λ���ͱ��� 
typedef unsigned int  uint32;     //  �޷���32λ���ͱ���
typedef unsigned short uint16;     //  �޷���16λ���ͱ���
typedef unsigned char  uint8;      //  �޷���8λ���ͱ��� 
typedef float          fp32;       //  �����ȸ�������32λ���ȣ�
typedef double         fp64;       //  ˫���ȸ�������64λ���ȣ�

typedef void (*intr_callback)(void);



#include <string.h>

#include "BK3231S_reg.h"
#include "sys_types.h"	//add 20170803
#include "config.h"
#include "driver_uart.h"
#include "driver_icu.h"
#include "driver_gpio.h"
#include "driver_xvr.h"
#include "driver_timer.h"
#include "driver_WDT.h"
#include "driver_flash.h"
#include "driver_spi.h"
#include "keyboard.h"
#include "main.h"


#define FAST_CALL   __attribute__((section("fastcall")))

void delay_ms(unsigned int tt);
void FAST_CALL Host_Loop();

#endif

