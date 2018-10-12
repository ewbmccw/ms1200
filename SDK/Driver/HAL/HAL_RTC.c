/**
************************************************************************************************
* @file		HAL_RTC.c
* @author	Solution Team
* @brief	HAL RTC API function file
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

#include	"SDK_Common.h"

/**
************************************************************************************************
* @brief		HAL RTC intialize function
* @return		RTC_Result
************************************************************************************************
*/
RTC_Result HAL_RTC_Init(void)
{
	U32 state;

	RTC_Unlock(0xA5);

	state = RTC_LockStateCheck();

	if(state)
	{
		__asm("nop");
		__asm("nop");
	}
	else
	{
		__asm("nop");
		__asm("nop");
	}

	return RTC_OK;
}
/**
************************************************************************************************
* @brief		HAL RTC de-intialize function
* @return		RTC_Result
************************************************************************************************
*/
RTC_Result HAL_RTC_DeInit(void)
{
	return RTC_OK;
}
/**
************************************************************************************************
* @brief		HAL RTC time set function
* @param		RTC_TimeStruct : RTC time structure
* @return		RTC_Result
************************************************************************************************
*/
RTC_Result HAL_RTC_TimeSet(RTC_TimeStruct *rtcTimeStruct)
{
	RTC_TimeSet(rtcTimeStruct->subSecond, rtcTimeStruct->second, rtcTimeStruct->minute, rtcTimeStruct->hour);
	RTC_InitRequest();

	return RTC_OK;
}
/**
************************************************************************************************
* @brief		HAL RTC time get function
* @param		RTC_TimeStruct : RTC time structure
* @return		RTC_Result
************************************************************************************************
*/
RTC_Result HAL_RTC_TimeGet(RTC_TimeStruct *rtcTimeStruct)
{
	U32 subSecond;
	U32 second;
	U32 minute;
	U32 hour;

	RTC_TimeRead(&subSecond, &second, &minute, &hour);

	rtcTimeStruct->subSecond = subSecond;
	rtcTimeStruct->second = second;
	rtcTimeStruct->minute = minute;
	rtcTimeStruct->hour = hour;

	return RTC_OK;
}
/**
************************************************************************************************
* @brief		HAL RTC date set function
* @param		RTC_DateStruct : RTC date structure
* @return		RTC_Result
************************************************************************************************
*/
RTC_Result HAL_RTC_DateSet(RTC_DateStruct *rtcDateStruct)
{
	RTC_DateSet(rtcDateStruct->day, rtcDateStruct->month, rtcDateStruct->year, rtcDateStruct->week);
	RTC_InitRequest();

	return RTC_OK;
}
/**
************************************************************************************************
* @brief		HAL RTC date get function
* @param		RTC_DateStruct : RTC date structure
* @return		RTC_Result
************************************************************************************************
*/
RTC_Result HAL_RTC_DateGet(RTC_DateStruct *rtcDateStruct)
{
	U32 day;
	U32 month;
	U32 year;
	U32 week;

	RTC_DateRead(&day, &month, &year, &week);

	rtcDateStruct->day = day;
	rtcDateStruct->month = month;
	rtcDateStruct->year = year;
	rtcDateStruct->week = week;

	return RTC_OK;
}
/**
************************************************************************************************
* @brief		HAL RTC alarm set function
* @param		U8 : alarm number
* @param		RTC_AlarmStruct : RTC alarm structure
* @return		RTC_Result
************************************************************************************************
*/
RTC_Result HAL_RTC_AlarmSet(U8 alarmNumber, RTC_AlarmStruct *rtcAlarmStruct)
{
	RTC_AlarmMaskDisable(alarmNumber, RTC_ALARM_MASK_ALL);

	RTC_AlarmTimeSet(alarmNumber, rtcAlarmStruct->subSecond, rtcAlarmStruct->second, rtcAlarmStruct->minute, rtcAlarmStruct->hour);
	RTC_AlarmDateSet(alarmNumber, rtcAlarmStruct->day, rtcAlarmStruct->month, rtcAlarmStruct->year, rtcAlarmStruct->week);

	RTC_AlarmMaskEnable(alarmNumber, rtcAlarmStruct->mask);

	return RTC_OK;
}
/**
************************************************************************************************
* @brief		HAL RTC alarm activate function
* @param		U8 : alarm number
* @return		RTC_Result
************************************************************************************************
*/
RTC_Result HAL_RTC_AlarmActivate(U8 alarmNumber)
{
	RTC_AlarmEnable(alarmNumber);

	return RTC_OK;
}
/**
************************************************************************************************
* @brief		HAL RTC alarm de-activate function
* @param		U8 : alarm number
* @return		RTC_Result
************************************************************************************************
*/
RTC_Result HAL_RTC_AlarmDeActivate(U8 alarmNumber)
{
	RTC_AlarmDisable(alarmNumber);

	return RTC_OK;
}
/**
************************************************************************************************
* @brief		HAL RTC interrupt enable function
* @param		U32 : interrupt
* @return		RTC_Result
************************************************************************************************
*/
RTC_Result HAL_RTC_IntEnable(U32 interrupt)
{
	RTC_IntEnable(interrupt);

	return RTC_OK;
}
/**
************************************************************************************************
* @brief		HAL RTC interrupt disable function
* @param		U32 : interrupt
* @return		RTC_Result
************************************************************************************************
*/
RTC_Result HAL_RTC_IntDisable(U32 interrupt)
{
	RTC_IntDisable(interrupt);

	return RTC_OK;
}

//----------------------------------------------------------------------------------------------
// end of file
//----------------------------------------------------------------------------------------------
