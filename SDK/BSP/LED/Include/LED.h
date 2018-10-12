/**
************************************************************************************************
* @file			LED.h
* @author		Solution Team
* @brief		LED API function header file
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

#ifndef	_LED_H_
#define	_LED_H_

typedef enum
{
	LED_OK = 0,
	LED_ERROR = 1
} LED_Result;

typedef enum
{
	LED_1 = 0,
	LED_2,
	LED_3,
	LED_4,
	LED_5,
	LED_6,
	LED_7,
	LED_8,
	LED_9,
	LED_10,
	LED_11,
	LED_12
} LED_Number;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
extern LED_Result LED_Init(void);
extern LED_Result LED_DeInit(void);
extern LED_Result LED_Control(void);

extern LED_Result LED_On(U32 number);
extern LED_Result LED_Off(U32 number);
extern LED_Result LED_Toggle(U32 number);

extern LED_Result LED_ToggleRequestSet(U32 number);
extern LED_Result LED_ToggleRequestClear(U32 number);

#endif

//----------------------------------------------------------------------------------------------
// end of file
//----------------------------------------------------------------------------------------------
