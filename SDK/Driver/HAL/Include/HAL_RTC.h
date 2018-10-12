/**
************************************************************************************************
* @file		HAL_RTC.h
* @author	Solution Team
* @brief	HAL RTC API function header file
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

#ifndef	_HAL_RTC_H_
#define	_HAL_RTC_H_

extern RTC_Result HAL_RTC_Init(void);
extern RTC_Result HAL_RTC_DeInit(void);
extern RTC_Result HAL_RTC_TimeSet(RTC_TimeStruct *rtcTimeStruct);
extern RTC_Result HAL_RTC_TimeGet(RTC_TimeStruct *rtcTimeStruct);
extern RTC_Result HAL_RTC_DateSet(RTC_DateStruct *rtcDateStruct);
extern RTC_Result HAL_RTC_DateGet(RTC_DateStruct *rtcDateStruct);
extern RTC_Result HAL_RTC_AlarmSet(U8 alarmNumber, RTC_AlarmStruct *rtcAlarmStruct);
extern RTC_Result HAL_RTC_AlarmActivate(U8 alarmNumber);
extern RTC_Result HAL_RTC_AlarmDeActivate(U8 alarmNumber);
extern RTC_Result HAL_RTC_IntEnable(U32 interrupt);
extern RTC_Result HAL_RTC_IntDisable(U32 interrupt);

#endif

//----------------------------------------------------------------------------------------------
// end of file
//----------------------------------------------------------------------------------------------
