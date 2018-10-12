/**
************************************************************************************************
* @file			SDK_Common.h
* @author		Solution Team
* @brief		SDK common header file
************************************************************************************************
* @attention
*
* Copyright(c) 2015 ~ 2020 eWBM Korea, Ltd.
* All rights reserved.
* This software contains confidential information of eWBM Korea Co., Ltd.
* And unauthorized distribution of this software, or any portion of it are prohibited.
*
************************************************************************************************
*/

#ifndef	_SDK_COMMON_H_
#define	_SDK_COMMON_H_

#include	<stdio.h>
#include	<stdint.h>
#include	<stdlib.h>
#include	<string.h>
#include	<stdarg.h>

#include	"MS1200.h"

#include	"APP_Define.h"
#include	"APP_MS1200_Config.h"

#include	"SDK_Type.h"
#include	"SDK_TypeRegister.h"
#include	"SDK_Constant.h"
#include	"SDK_Define.h"
#include	"SDK_Exception.h"
#include	"SDK_Macro.h"
#include	"SDK_Misc.h"

#include	"SysTick.h"
#include	"IRQ.h"
#include	"RTC.h"
#include	"WDT.h"
#include	"GPIO.h"
#include	"UART.h"

#include	"CRM_API.h"

#include	"HAL_SysTick.h"
#include	"HAL_IRQ.h"
#include	"HAL_WDT.h"
#include	"HAL_GPIO.h"
#include	"HAL_UART.h"
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define __CM3_REV						0x0200
#define __MPU_PRESENT					0
#define __NVIC_PRIO_BITS				4
#define __Vendor_SysTickConfig			0

#include	"core_cm3.h"

#endif

//----------------------------------------------------------------------------------------------
// end of file
//----------------------------------------------------------------------------------------------
