/**
************************************************************************************************
* @file			APP_Define.h
* @author		Solution Team
* @brief		APP define header file
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

#ifndef	_APP_DEFINE_H_
#define	_APP_DEFINE_H_

#define APP_FIRMWARE_VERSION_MAIN		1		//firmware main version number
#define APP_FIRMWARE_VERSION_SUB		0		//firmware sub version number
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define _EWBM_MS1200					1
#define _EWBM_MS500						0
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define _OP_MODE_RTOS					0
#define _OP_MODE_NON_RTOS				1

#define	_OP_MODE						_OP_MODE_NON_RTOS

#define	_OP_SIMULATION					0
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define _ASSERT_DEBUG					1

#define _SEMI_HOSTING					0
#define _UART_MONITOR					0
#define _USB_MONITOR					1
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define _SDK_INT_CALLBACK_ENABLE		1

#define _SDK_GPIO_MODULE_ENABLE			1
#define _SDK_I2C_MODULE_ENABLE			1

#define _SDK_1US_TIMER_ENABLE			1		//1us timer

#endif

//----------------------------------------------------------------------------------------------
// end of file
//----------------------------------------------------------------------------------------------
