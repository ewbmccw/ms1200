/**
************************************************************************************************
* @file		WDT.h
* @author	Solution Team
* @brief	Watchdog Timer API function header file
***********************************************************************************************
* @attention
*
* Copyright(c) 2015 ~ 2020 eWBM Korea, Ltd.
* All rights reserved.
* This software contains confidential information of eWBM Korea Co., Ltd.
* And unauthorized distribution of this software, or any portion of it are prohibited.
*
***********************************************************************************************
*/

#ifndef	_WDT_H_
#define	_WDT_H_

typedef enum
{
	WDT_OK = 0,
	WDT_ERROR = 1
} WDT_Result;

typedef enum
{
	WDT_INT_ID_EARLY_WAKEUP = 0x01,
	WDT_INT_ID_TEST_MODE = 0x02
} WDT_IntId;

typedef enum
{
	WDT_EARLY_WAKEUP_INT_DISABLE = 0,
	WDT_EARLY_WAKEUP_INT_ENABLE = 1
} WDT_EarlyWakeupIntMode;

typedef enum
{
	WDT_WINDOW_DISABLE = 0,
	WDT_WINDOW_ENABLE = 1
} WDT_WindowMode;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
typedef struct
{
	U8 base;
	U16 loadValue;
	U16 earlyWakeUpValue;
	U8 earlyWakeUpIntMode;
	U16 windowValue;
	U8 windowMode;
} WDT_InitStruct;
//----------------------------------------------------------------------------------------------
extern WDT_Result WDT_Enable(void);
extern WDT_Result WDT_Disable(void);
extern WDT_Result WDT_EarlyWakeUpIntEnable(void);
extern WDT_Result WDT_EarlyWakeUpIntDisable(void);
extern WDT_Result WDT_WindowEnable(void);
extern WDT_Result WDT_WindowDisable(void);
extern WDT_Result WDT_TestModeEnable(void);
extern WDT_Result WDT_TestModeDisable(void);
extern WDT_Result WDT_TimerBaseSet(U8 base);
extern WDT_Return WDT_EarlyWakeUpIntStatusCheck(void);
extern WDT_Return WDT_TestModeIntStatusCheck(void);
extern WDT_Return WDT_CountRead(void);
extern WDT_Result WDT_LoadValueSet(U32 value);
extern WDT_Result WDT_EarlyWakeUpIntLoadValueSet(U32 value);
extern WDT_Result WDT_WindowValueSet(U32 value);
extern WDT_Result WDT_Lock(U32 code);
extern WDT_Result WDT_Unlock(U32 code);
extern WDT_Result WDT_PreLockRegisterClear(void);
extern WDT_Result WDT_PreLockRegisterApply(void);
extern WDT_Result WDT_PreLockCodeSet(U32 code);
extern WDT_Result WDT_PreLockKeySet(void);
extern WDT_Result WDT_PreLockKeyClear(void);
extern WDT_Return WDT_LockStateCheck(void);

#endif

//----------------------------------------------------------------------------------------------
// end of file
//----------------------------------------------------------------------------------------------
