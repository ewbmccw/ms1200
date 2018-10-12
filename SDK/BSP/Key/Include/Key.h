/**
************************************************************************************************
* @file			Key.h
* @author		Solution Team
* @brief		Key API function header file
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

#ifndef	_KEY_H_
#define	_KEY_H_

typedef enum
{
	KEY_OK = 0,
	KEY_ERROR = 1
} KEY_Result;

typedef enum
{
	KEY_NULL = 0,
	KEY_PLAY,
	KEY_STOP,
	KEY_PREV,
	KEY_NEXT,
	KEY_MODE
} KEY_Name;
//----------------------------------------------------------------------------------------------
extern KEY_Result KEY_Init(void);
extern KEY_Result KEY_DeInit(void);
extern KEY_Result KEY_Scan(void);
extern KEY_Result KEY_Process(void);
extern KEY_Result KEY_TimerUpdate(void);

#endif

//----------------------------------------------------------------------------------------------
// end of file
//----------------------------------------------------------------------------------------------
