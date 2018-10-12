/**
************************************************************************************************
* @file			main.c
* @author		Solution Team
* @brief		main function file
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

#include	"SDK_Common.h"

#include	"main.h"
#include	"LED.h"
#include	"Key.h"

static void APP_RtcApiTest(void);
static void APP_RtcHalApiTest(void);
static void APP_RtcTimerTest(void);
static void APP_RtcAlarmTest(void);
static void APP_RtcTimeStampTest(void);
static void APP_RtcCalibrateTest(void);

static U32 LedBlinkTimer;

int main(void)
{
	STICK_InitStruct stickStruct;

#if (__PRE_FPGA_MODE)

#if (__PRE_FPGA_MODE_IP_TEAM)

#else

	CRM_HsircEnable();

//	while(!CRM_ClockReadyCheck(CRM_CLOCK_SOURCE_HS_IRC));

//	CRM_SystickSourceSelect(CRM_CLOCK_SOURCE_DEFAULT);
	CRM_SystickSourceSelect(CRM_CLOCK_SOURCE_HS_IRC);		//previous applying
//	CRM_SystickSourceSelect(CRM_CLOCK_SOURCE_XTAL);
//	CRM_SystickSourceSelect(CRM_CLOCK_SOURCE_PLL);
//	CRM_SystickSourceSelect(CRM_CLOCK_SOURCE_DIVIDER_A);
//	CRM_SystickSourceSelect(CRM_CLOCK_SOURCE_DIVIDER_B);
//	CRM_SystickSourceSelect(CRM_CLOCK_SOURCE_DIVIDER_C);
//	CRM_SystickSourceSelect(CRM_CLOCK_SOURCE_DIVIDER_D);
//	CRM_SystickSourceSelect(CRM_CLOCK_SOURCE_DIVIDER_E);

#endif

#else

#endif

	stickStruct.clockSource = STICK_CLOCK_SRC_CORE_CLOCK;
	stickStruct.reload = STICK_RELOAD;
	stickStruct.current = 0;
	HAL_STICK_Init(&stickStruct);

	HAL_STICK_IntEnable();
	HAL_STICK_Enable();

	LED_Init();
	KEY_Init();

//	APP_RtcApiTest();
//	APP_RtcHalApiTest();
	APP_RtcTimerTest();
}
//----------------------------------------------------------------------------------------------
static void APP_RtcApiTest(void)
{
	U32 code;
	U32 status;
	U32 state;
	U32 count;
	U32 subSecond, second, minute, hour;
	U32 day, month, year, week;
	U32 event;

	code = 0xA5;
//	code = 0x3F;

	RTC_Unlock(code);		//Default state is lock. So RTC should be unlocked.
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

//	RTC_Lock(code);
//	state = RTC_LockStateCheck();

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

//	RTC_Unlock(code);
//	state = RTC_LockStateCheck();

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

//	RTC_Lock(code);
//	state = RTC_LockStateCheck();

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

//	RTC_Unlock(code);
//	state = RTC_LockStateCheck();

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

	RTC_CalendarSourceSelect(RTC_CALENDAR_SOURCE_YEAR);
	RTC_CalendarSourceSelect(RTC_CALENDAR_SOURCE_MON);
	RTC_CalendarSourceSelect(RTC_CALENDAR_SOURCE_DAY);
	RTC_CalendarSourceSelect(RTC_CALENDAR_SOURCE_HOUR);
	RTC_CalendarSourceSelect(RTC_CALENDAR_SOURCE_MIN);
	RTC_CalendarSourceSelect(RTC_CALENDAR_SOURCE_SEC);
	RTC_CalendarSourceSelect(RTC_CALENDAR_SOURCE_SUB_SEC);

	RTC_AlarmEnable(RTC_ALARM_NUMBER_1);
	RTC_AlarmDisable(RTC_ALARM_NUMBER_1);

	RTC_AlarmEnable(RTC_ALARM_NUMBER_2);
	RTC_AlarmDisable(RTC_ALARM_NUMBER_2);

	RTC_AlarmModeSelect(RTC_ALARM_NUMBER_1, RTC_ALARM_MODE_ONE_SHOT);
	RTC_AlarmModeSelect(RTC_ALARM_NUMBER_1, RTC_ALARM_MODE_NORMAL);

	RTC_AlarmModeSelect(RTC_ALARM_NUMBER_2, RTC_ALARM_MODE_ONE_SHOT);
	RTC_AlarmModeSelect(RTC_ALARM_NUMBER_2, RTC_ALARM_MODE_NORMAL);

	RTC_TimerDisable();

	RTC_TimerModeSelect(RTC_TIMER_MODE_ONE_SHOT);
	RTC_TimerModeSelect(RTC_TIMER_MODE_PERIODIC);

	RTC_TimerFreqSelect(RTC_TIMER_FREQ_1);
	RTC_TimerFreqSelect(RTC_TIMER_FREQ_2048);
	RTC_TimerFreqSelect(RTC_TIMER_FREQ_4096);
	RTC_TimerFreqSelect(RTC_TIMER_FREQ_8192);

	count = 0x0000FFFF;

	RTC_TimerCounterSet(count);

	count = 0x00000000;

	count = RTC_TimerCounterRead();

	RTC_TimerEnable();

	RTC_CalibrateEnable();
	state = RTC_CalibrateCheck();

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

	RTC_RefClockCompensateEnable();
	state = RTC_RefClockCompensateCheck();

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

	RTC_TimeStampEnable();
	RTC_TimeStampDisable();

	RTC_TimeStampInternalEventEnable();
	RTC_TimeStampInternalEventDisable();

	RTC_TamperDetectEnable(RTC_TAMPER_NUMBER_1);
	RTC_TamperDetectDisable(RTC_TAMPER_NUMBER_1);

	RTC_TamperDetectEnable(RTC_TAMPER_NUMBER_2);
	RTC_TamperDetectDisable(RTC_TAMPER_NUMBER_2);

	RTC_TamperDetectEnable(RTC_TAMPER_NUMBER_3);
	RTC_TamperDetectDisable(RTC_TAMPER_NUMBER_3);

	RTC_OutputSelect(RTC_OUTPUT_ALARM_2);
	RTC_OutputSelect(RTC_OUTPUT_ALARM_1);
	RTC_OutputSelect(RTC_OUTPUT_CALIBRATION);
	RTC_OutputSelect(RTC_OUTPUT_TIMER);

	RTC_OutputPolaritySelect(RTC_OUTPUT_POLARITY_HIGH);
	RTC_OutputPolaritySelect(RTC_OUTPUT_POLARITY_LOW);

	RTC_OutputTypeSelect(RTC_OUTPUT_TYPE_OPEN_DRAIN);
	RTC_OutputTypeSelect(RTC_OUTPUT_TYPE_PUSH_PULL);

	RTC_CalibrateOutputSelect(RTC_CALIBRATION_OUTPUT_SEC);
	RTC_CalibrateOutputSelect(RTC_CALIBRATION_OUTPUT_SUB_SEC);

	status = HWREG(RTC->CR);

	status = RTC_StatusRead();

	if(status)
	{
		__asm("nop");
		__asm("nop");
	}
	else
	{
		__asm("nop");
		__asm("nop");
	}

	RTC_IntEnable(RTC_INT_ALARM_1);
	RTC_IntEnable(RTC_INT_ALARM_2);
	RTC_IntEnable(RTC_INT_TIMER);
	RTC_IntEnable(RTC_INT_CALENDAR);
	RTC_IntEnable(RTC_INT_TAMPER_1_DETECT);
	RTC_IntEnable(RTC_INT_TAMPER_2_DETECT);
	RTC_IntEnable(RTC_INT_TAMPER_3_DETECT);
//	RTC_IntEnable(RTC_INT_RESERVED_1);
	RTC_IntEnable(RTC_INT_TIME_STAMP_EVENT);

	status = RTC_StatusRead();

	if(status)
	{
		__asm("nop");
		__asm("nop");
	}
	else
	{
		__asm("nop");
		__asm("nop");
	}

	RTC_IntDisable(RTC_INT_ALARM_1);
	RTC_IntDisable(RTC_INT_ALARM_2);
	RTC_IntDisable(RTC_INT_TIMER);
	RTC_IntDisable(RTC_INT_CALENDAR);
	RTC_IntDisable(RTC_INT_TAMPER_1_DETECT);
	RTC_IntDisable(RTC_INT_TAMPER_2_DETECT);
	RTC_IntDisable(RTC_INT_TAMPER_3_DETECT);
//	RTC_IntDisable(RTC_INT_RESERVED_1);
	RTC_IntDisable(RTC_INT_TIME_STAMP_EVENT);

	status = RTC_StatusRead();

	if(status)
	{
		__asm("nop");
		__asm("nop");
	}
	else
	{
		__asm("nop");
		__asm("nop");
	}

	RTC_IntEnable(RTC_INT_ALARM_1 | RTC_INT_ALARM_2 | RTC_INT_TIMER | RTC_INT_CALENDAR | RTC_INT_TAMPER_1_DETECT | RTC_INT_TAMPER_2_DETECT | RTC_INT_TAMPER_3_DETECT | RTC_INT_TIME_STAMP_EVENT);

	status = RTC_StatusRead();

	if(status)
	{
		__asm("nop");
		__asm("nop");
	}
	else
	{
		__asm("nop");
		__asm("nop");
	}

	RTC_IntDisable(RTC_INT_ALARM_1 | RTC_INT_ALARM_2 | RTC_INT_TIMER | RTC_INT_CALENDAR | RTC_INT_TAMPER_1_DETECT | RTC_INT_TAMPER_2_DETECT | RTC_INT_TAMPER_3_DETECT | RTC_INT_TIME_STAMP_EVENT);

	status = RTC_StatusRead();

	if(status)
	{
		__asm("nop");
		__asm("nop");
	}
	else
	{
		__asm("nop");
		__asm("nop");
	}

	RTC_IntClear(RTC_INT_ALARM_1);
	RTC_IntClear(RTC_INT_ALARM_2);
	RTC_IntClear(RTC_INT_TIMER);
	RTC_IntClear(RTC_INT_CALENDAR);
	RTC_IntClear(RTC_INT_TAMPER_1_DETECT);
	RTC_IntClear(RTC_INT_TAMPER_2_DETECT);
	RTC_IntClear(RTC_INT_TAMPER_3_DETECT);
//	RTC_IntClear(RTC_INT_RESERVED_1);
	RTC_IntClear(RTC_INT_TIME_STAMP_EVENT);

	RTC_AlarmMaskEnable(RTC_ALARM_NUMBER_1, RTC_ALARM_MASK_SUB_SEC);
	RTC_AlarmMaskDisable(RTC_ALARM_NUMBER_1, RTC_ALARM_MASK_SUB_SEC);
	RTC_AlarmMaskEnable(RTC_ALARM_NUMBER_1, RTC_ALARM_MASK_SEC);
	RTC_AlarmMaskDisable(RTC_ALARM_NUMBER_1, RTC_ALARM_MASK_SEC);
	RTC_AlarmMaskEnable(RTC_ALARM_NUMBER_1, RTC_ALARM_MASK_MIN);
	RTC_AlarmMaskDisable(RTC_ALARM_NUMBER_1, RTC_ALARM_MASK_MIN);
	RTC_AlarmMaskEnable(RTC_ALARM_NUMBER_1, RTC_ALARM_MASK_HOUR);
	RTC_AlarmMaskDisable(RTC_ALARM_NUMBER_1, RTC_ALARM_MASK_HOUR);
	RTC_AlarmMaskEnable(RTC_ALARM_NUMBER_1, RTC_ALARM_MASK_DAY);
	RTC_AlarmMaskDisable(RTC_ALARM_NUMBER_1, RTC_ALARM_MASK_DAY);
	RTC_AlarmMaskEnable(RTC_ALARM_NUMBER_1, RTC_ALARM_MASK_MON);
	RTC_AlarmMaskDisable(RTC_ALARM_NUMBER_1, RTC_ALARM_MASK_MON);
	RTC_AlarmMaskEnable(RTC_ALARM_NUMBER_1, RTC_ALARM_MASK_YEAR);
	RTC_AlarmMaskDisable(RTC_ALARM_NUMBER_1, RTC_ALARM_MASK_YEAR);
	RTC_AlarmMaskEnable(RTC_ALARM_NUMBER_1, RTC_ALARM_MASK_WEEK);
	RTC_AlarmMaskDisable(RTC_ALARM_NUMBER_1, RTC_ALARM_MASK_WEEK);

	RTC_AlarmMaskEnable(RTC_ALARM_NUMBER_1, RTC_ALARM_MASK_SUB_SEC | RTC_ALARM_MASK_SEC | RTC_ALARM_MASK_MIN | RTC_ALARM_MASK_HOUR);
	RTC_AlarmMaskDisable(RTC_ALARM_NUMBER_1, RTC_ALARM_MASK_SUB_SEC | RTC_ALARM_MASK_SEC | RTC_ALARM_MASK_MIN | RTC_ALARM_MASK_HOUR);

	RTC_AlarmMaskEnable(RTC_ALARM_NUMBER_1, RTC_ALARM_MASK_DAY | RTC_ALARM_MASK_MON | RTC_ALARM_MASK_YEAR | RTC_ALARM_MASK_WEEK);
	RTC_AlarmMaskDisable(RTC_ALARM_NUMBER_1, RTC_ALARM_MASK_DAY | RTC_ALARM_MASK_MON | RTC_ALARM_MASK_YEAR | RTC_ALARM_MASK_WEEK);

	RTC_AlarmMaskEnable(RTC_ALARM_NUMBER_2, RTC_ALARM_MASK_SUB_SEC);
	RTC_AlarmMaskDisable(RTC_ALARM_NUMBER_2, RTC_ALARM_MASK_SUB_SEC);
	RTC_AlarmMaskEnable(RTC_ALARM_NUMBER_2, RTC_ALARM_MASK_SEC);
	RTC_AlarmMaskDisable(RTC_ALARM_NUMBER_2, RTC_ALARM_MASK_SEC);
	RTC_AlarmMaskEnable(RTC_ALARM_NUMBER_2, RTC_ALARM_MASK_MIN);
	RTC_AlarmMaskDisable(RTC_ALARM_NUMBER_2, RTC_ALARM_MASK_MIN);
	RTC_AlarmMaskEnable(RTC_ALARM_NUMBER_2, RTC_ALARM_MASK_HOUR);
	RTC_AlarmMaskDisable(RTC_ALARM_NUMBER_2, RTC_ALARM_MASK_HOUR);
	RTC_AlarmMaskEnable(RTC_ALARM_NUMBER_2, RTC_ALARM_MASK_DAY);
	RTC_AlarmMaskDisable(RTC_ALARM_NUMBER_2, RTC_ALARM_MASK_DAY);
	RTC_AlarmMaskEnable(RTC_ALARM_NUMBER_2, RTC_ALARM_MASK_MON);
	RTC_AlarmMaskDisable(RTC_ALARM_NUMBER_2, RTC_ALARM_MASK_MON);
	RTC_AlarmMaskEnable(RTC_ALARM_NUMBER_2, RTC_ALARM_MASK_YEAR);
	RTC_AlarmMaskDisable(RTC_ALARM_NUMBER_2, RTC_ALARM_MASK_YEAR);
	RTC_AlarmMaskEnable(RTC_ALARM_NUMBER_2, RTC_ALARM_MASK_WEEK);
	RTC_AlarmMaskDisable(RTC_ALARM_NUMBER_2, RTC_ALARM_MASK_WEEK);

	RTC_AlarmMaskEnable(RTC_ALARM_NUMBER_2, RTC_ALARM_MASK_SUB_SEC | RTC_ALARM_MASK_SEC | RTC_ALARM_MASK_MIN | RTC_ALARM_MASK_HOUR);
	RTC_AlarmMaskDisable(RTC_ALARM_NUMBER_2, RTC_ALARM_MASK_SUB_SEC | RTC_ALARM_MASK_SEC | RTC_ALARM_MASK_MIN | RTC_ALARM_MASK_HOUR);

	RTC_AlarmMaskEnable(RTC_ALARM_NUMBER_2, RTC_ALARM_MASK_DAY | RTC_ALARM_MASK_MON | RTC_ALARM_MASK_YEAR | RTC_ALARM_MASK_WEEK);
	RTC_AlarmMaskDisable(RTC_ALARM_NUMBER_2, RTC_ALARM_MASK_DAY | RTC_ALARM_MASK_MON | RTC_ALARM_MASK_YEAR | RTC_ALARM_MASK_WEEK);

	RTC_CalibratePeriodSelect(RTC_CALIBRATE_PERIOD_32_SEC);
	RTC_CalibratePeriodSelect(RTC_CALIBRATE_PERIOD_16_SEC);
	RTC_CalibratePeriodSelect(RTC_CALIBRATE_PERIOD_8_SEC);

	RTC_CalibrateDirectionSelect(RTC_CALIBRATE_DIR_BACKWARD);
	RTC_CalibrateDirectionSelect(RTC_CALIBRATE_DIR_FORWARD);

	RTC_CalibrateCounterSet(100);
	RTC_CalibrateCounterSet(0);

	subSecond = 99;
	second = 59;
	minute = 59;
	hour = 23;

	RTC_TimeSet(subSecond, second, minute, hour);
	RTC_TimeRead(&subSecond, &second, &minute, &hour);

	day = 31;
	month = 12;
	year = 2017;
	week = 0x7;

	RTC_DateSet(day, month, year, week);
	RTC_DateRead(&day, &month, &year, &week);

	RTC_InitRequest();
	state = RTC_InitResultCheck();

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

	subSecond = 0;
	second = 0;
	minute = 0;
	hour = 0;

	RTC_TimeSet(subSecond, second, minute, hour);
	RTC_TimeRead(&subSecond, &second, &minute, &hour);

	day = 1;
	month = 1;
	year = 2016;
	week = 0x1;

	RTC_DateSet(day, month, year, week);
	RTC_DateRead(&day, &month, &year, &week);

	RTC_InitRequest();
	state = RTC_InitResultCheck();

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

	RTC_TimeStampTimeRead(&subSecond, &second, &minute, &hour);
	RTC_TimeStampDateRead(&day, &month, &year, &week);

	event = RTC_TimeStampEventCheck();

	if(event)
	{
		__asm("nop");
		__asm("nop");
	}
	else
	{
		__asm("nop");
		__asm("nop");
	}

	subSecond = 99;
	second = 59;
	minute = 59;
	hour = 23;

	RTC_AlarmTimeSet(RTC_ALARM_NUMBER_1, subSecond, second, minute, hour);
	RTC_AlarmTimeSet(RTC_ALARM_NUMBER_2, subSecond, second, minute, hour);

	day = 31;
	month = 12;
	year = 2017;
	week = 0x7;

	RTC_AlarmDateSet(RTC_ALARM_NUMBER_1, day, month, year, week);
	RTC_AlarmDateSet(RTC_ALARM_NUMBER_2, day, month, year, week);

	RTC_TamperDetectPinSelect(RTC_TAMPER_DETECT_PIN_3);
	RTC_TamperDetectPinSelect(RTC_TAMPER_DETECT_PIN_2);
	RTC_TamperDetectPinSelect(RTC_TAMPER_DETECT_PIN_1);

	RTC_TamperDetectClockSelect(RTC_TAMPER_DETECT_CLOCK_12_5HZ);
	RTC_TamperDetectClockSelect(RTC_TAMPER_DETECT_CLOCK_25HZ);
	RTC_TamperDetectClockSelect(RTC_TAMPER_DETECT_CLOCK_50HZ);
	RTC_TamperDetectClockSelect(RTC_TAMPER_DETECT_CLOCK_100HZ);

	RTC_TamperDetectModeSelect(RTC_TAMPER_DETECT_MODE_LEVEL);
	RTC_TamperDetectModeSelect(RTC_TAMPER_DETECT_MODE_EDGE);

	RTC_TamperMajorRuleEnable();
	RTC_TamperMajorRuleDisable();

	RTC_TamperDetectCountSelect(RTC_TAMPER_DETECT_COUNT_4);
	RTC_TamperDetectCountSelect(RTC_TAMPER_DETECT_COUNT_3);
	RTC_TamperDetectCountSelect(RTC_TAMPER_DETECT_COUNT_2);
	RTC_TamperDetectCountSelect(RTC_TAMPER_DETECT_COUNT_1);

	RTC_TamperDetectPolaritySelect(RTC_TAMPER_NUMBER_3, RTC_TAMPER_DETECT_POL_FALLING_EDGE);
	RTC_TamperDetectPolaritySelect(RTC_TAMPER_NUMBER_3, RTC_TAMPER_DETECT_POL_RISING_EDGE);

	RTC_TamperDetectPolaritySelect(RTC_TAMPER_NUMBER_2, RTC_TAMPER_DETECT_POL_FALLING_EDGE);
	RTC_TamperDetectPolaritySelect(RTC_TAMPER_NUMBER_2, RTC_TAMPER_DETECT_POL_RISING_EDGE);

	RTC_TamperDetectPolaritySelect(RTC_TAMPER_NUMBER_1, RTC_TAMPER_DETECT_POL_FALLING_EDGE);
	RTC_TamperDetectPolaritySelect(RTC_TAMPER_NUMBER_1, RTC_TAMPER_DETECT_POL_RISING_EDGE);

	RTC_TamperTimeStampEnable();
	RTC_TamperTimeStampDisable();

	RTC_TamperDetectConditionSelect(RTC_TAMPER_DETECT_CONDITION_PIN_3);
	RTC_TamperDetectConditionSelect(RTC_TAMPER_DETECT_CONDITION_PIN_2);
	RTC_TamperDetectConditionSelect(RTC_TAMPER_DETECT_CONDITION_PIN_1);
	RTC_TamperDetectConditionSelect(RTC_TAMPER_DETECT_CONDITION_ANY_PIN);
	RTC_TamperDetectConditionSelect(RTC_TAMPER_DETECT_CONDITION_ALL_PIN);

	RTC_TamperDetectActionSelect(RTC_TAMPER_DETECT_ACT_ERASE_AND_RESET);
	RTC_TamperDetectActionSelect(RTC_TAMPER_DETECT_ACT_SYSTEM_RESET);
	RTC_TamperDetectActionSelect(RTC_TAMPER_DETECT_ACT_ERASE_BACKUP_MEM);
	RTC_TamperDetectActionSelect(RTC_TAMPER_DETECT_ACT_NONE);

	code = 0xA5;
//	code = 0x3F;

//	RTC_Lock(code);
//	state = RTC_LockStateCheck();

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

	while(1);
}
//----------------------------------------------------------------------------------------------
static void APP_RtcHalApiTest(void)
{
	RTC_TimeStruct rtcTimeStruct;
	RTC_DateStruct rtcDateStruct;
	RTC_AlarmStruct rtcAlarmStruct;

	HAL_RTC_Init();
//	HAL_RTC_DeInit();

	IRQ_Enable(RTC_IRQn);

	HAL_RTC_IntDisable(RTC_INT_TIMER);
	HAL_RTC_IntDisable(RTC_INT_CALENDAR);

	HAL_RTC_IntEnable(RTC_INT_TIMER);

	rtcTimeStruct.subSecond = 99;
	rtcTimeStruct.second = 59;
	rtcTimeStruct.minute = 59;
	rtcTimeStruct.hour = 23;
	HAL_RTC_TimeSet(&rtcTimeStruct);

	rtcTimeStruct.subSecond = 0;
	rtcTimeStruct.second = 0;
	rtcTimeStruct.minute = 0;
	rtcTimeStruct.hour = 0;
	HAL_RTC_TimeGet(&rtcTimeStruct);

	rtcDateStruct.day = 31;
	rtcDateStruct.month = 12;
	rtcDateStruct.year = 2017;
	rtcDateStruct.week = 7;
	HAL_RTC_DateSet(&rtcDateStruct);

	rtcDateStruct.day = 0;
	rtcDateStruct.month = 0;
	rtcDateStruct.year = 0;
	rtcDateStruct.week = 0;
	HAL_RTC_DateGet(&rtcDateStruct);

	rtcTimeStruct.subSecond = 0;
	rtcTimeStruct.second = 50;
	rtcTimeStruct.minute = 59;
	rtcTimeStruct.hour = 23;
	HAL_RTC_TimeSet(&rtcTimeStruct);

	rtcDateStruct.day = 1;
	rtcDateStruct.month = 10;
	rtcDateStruct.year = 2018;
	rtcDateStruct.week = 1;
	HAL_RTC_DateSet(&rtcDateStruct);

	rtcAlarmStruct.subSecond = 0;
	rtcAlarmStruct.second = 59;
	rtcAlarmStruct.minute = 59;
	rtcAlarmStruct.hour = 23;
	rtcAlarmStruct.day = 1;
	rtcAlarmStruct.month = 10;
	rtcAlarmStruct.year = 2018;
	rtcAlarmStruct.week = 1;
	rtcAlarmStruct.mask = 0;
	HAL_RTC_AlarmSet(RTC_ALARM_NUMBER_1, &rtcAlarmStruct);

	HAL_RTC_AlarmActivate(RTC_ALARM_NUMBER_1);
//	HAL_RTC_AlarmDeActivate(RTC_ALARM_NUMBER_1);

	HAL_RTC_IntEnable(RTC_INT_ALARM_1);
//	HAL_RTC_IntDisable(RTC_INT_ALARM_1);

	while(1);
}
//----------------------------------------------------------------------------------------------
static void APP_RtcTimerTest(void)
{
	U32 code;
	U32 state;
	U32 count;

	CRM_RtcEnable();

	code = 0xA5;
//	code = 0x3F;

	RTC_Unlock(code);
	state = RTC_LockStateCheck();

	IRQ_Enable(RTC_IRQn);

	RTC_IntDisable(RTC_INT_TIMER);
	RTC_IntDisable(RTC_INT_CALENDAR);

	RTC_IntEnable(RTC_INT_TIMER);

	RTC_TimerDisable();

//	RTC_TimerModeSelect(RTC_TIMER_MODE_ONE_SHOT);
	RTC_TimerModeSelect(RTC_TIMER_MODE_PERIODIC);

//	RTC_TimerFreqSelect(RTC_TIMER_FREQ_1);
//	RTC_TimerFreqSelect(RTC_TIMER_FREQ_2048);
//	RTC_TimerFreqSelect(RTC_TIMER_FREQ_4096);
	RTC_TimerFreqSelect(RTC_TIMER_FREQ_8192);

//	count = 0x0000FFFF;
	count = 0x00000003;

	RTC_TimerCounterSet(count);

	count = 0x00000000;

	count = RTC_TimerCounterRead();

	RTC_TimerEnable();

	while(1)
	{
		count = RTC_TimerCounterRead();

		if(count)
		{
			__asm("nop");
			__asm("nop");
		}
		else
		{
			__asm("nop");
			__asm("nop");
		}
	}
}
//----------------------------------------------------------------------------------------------
static void APP_RtcAlarmTest(void)
{
	while(1);
}
//----------------------------------------------------------------------------------------------
static void APP_RtcTimeStampTest(void)
{
	while(1);
}
//----------------------------------------------------------------------------------------------
static void APP_RtcCalibrateTest(void)
{
	while(1);
}
//----------------------------------------------------------------------------------------------
void APP_TimerUpdate(void)
{
	if(LedBlinkTimer)
	{
		LedBlinkTimer--;
	}
}

//----------------------------------------------------------------------------------------------
// end of file
//----------------------------------------------------------------------------------------------
