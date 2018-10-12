/**
************************************************************************************************
* @file		RTC.h
* @author	Solution Team
* @brief	RTC API function header file
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

#ifndef	_RTC_H_
#define	_RTC_H_

typedef enum
{
	RTC_OK = 0,
	RTC_ERROR
} RTC_Result;

typedef enum
{
	RTC_INIT_DONE = 0,
	RTC_INIT_PENDING
} RTC_InitState;

typedef enum
{
	RTC_TAMPER_NUMBER_1 = 0,
	RTC_TAMPER_NUMBER_2,
	RTC_TAMPER_NUMBER_3
} RTC_TamperNumber;

typedef enum
{
	RTC_ALARM_NUMBER_1 = 0,
	RTC_ALARM_NUMBER_2,
} RTC_AlarmNumber;

typedef enum
{
	RTC_CALENDAR_SOURCE_SUB_SEC = 0x1,
	RTC_CALENDAR_SOURCE_SEC,
	RTC_CALENDAR_SOURCE_MIN,
	RTC_CALENDAR_SOURCE_HOUR,
	RTC_CALENDAR_SOURCE_DAY,
	RTC_CALENDAR_SOURCE_MON,
	RTC_CALENDAR_SOURCE_YEAR
} RTC_CalendarSource;

typedef enum
{
	RTC_ALARM_MODE_NORMAL = 0,
	RTC_ALARM_MODE_ONE_SHOT
} RTC_AlarmMode;

typedef enum
{
	RTC_TIMER_MODE_PERIODIC = 0,
	RTC_TIMER_MODE_ONE_SHOT
} RTC_TimerMode;

typedef enum
{
	RTC_TIMER_FREQ_8192 = 0,		//ccw wait: new register map applied
	RTC_TIMER_FREQ_4096,
	RTC_TIMER_FREQ_2048,
	RTC_TIMER_FREQ_1
} RTC_TimerFreq;

typedef enum
{
	RTC_OUTPUT_TIMER = 0,
	RTC_OUTPUT_CALIBRATION,
	RTC_OUTPUT_ALARM_1,
	RTC_OUTPUT_ALARM_2
} RTC_Output;

typedef enum
{
	RTC_OUTPUT_POLARITY_LOW = 0,
	RTC_OUTPUT_POLARITY_HIGH
} RTC_OutputPolarity;

typedef enum
{
	RTC_OUTPUT_TYPE_PUSH_PULL = 0,
	RTC_OUTPUT_TYPE_OPEN_DRAIN
} RTC_OutputType;

typedef enum
{
	RTC_CALIBRATION_OUTPUT_SUB_SEC = 0,
	RTC_CALIBRATION_OUTPUT_SEC
} RTC_CalibrationOutput;

typedef enum
{
	RTC_STATUS_ALARM_1= 0x0001,
	RTC_STATUS_ALARM_2 = 0x0002,
	RTC_STATUS_TIMER = 0x0004,
	RTC_STATUS_CALENDAR = 0x0008,
	RTC_STATUS_TAMPER_1_DETECT = 0x0010,
	RTC_STATUS_TAMPER_2_DETECT = 0x0020,
	RTC_STATUS_TAMPER_3_DETECT = 0x0040,
//	RTC_STATUS_RESERVED_1 = 0x0080,
	RTC_STATUS_TIME_STAMP_EVENT = 0x0100,
	RTC_STATUS_ALL = 0x017F
} RTC_Status;

typedef enum
{
	RTC_INT_ALARM_1= 0x0001,
	RTC_INT_ALARM_2 = 0x0002,
	RTC_INT_TIMER = 0x0004,
	RTC_INT_CALENDAR = 0x0008,
	RTC_INT_TAMPER_1_DETECT = 0x0010,
	RTC_INT_TAMPER_2_DETECT = 0x0020,
	RTC_INT_TAMPER_3_DETECT = 0x0040,
//	RTC_INT_RESERVED_1 = 0x0080,
	RTC_INT_TIME_STAMP_EVENT = 0x0100,
	RTC_INT_ALL = 0x017F
} RTC_Interrupt;

typedef enum
{
	RTC_ALARM_MASK_SUB_SEC = 0x0001,
	RTC_ALARM_MASK_SEC = 0x0002,
	RTC_ALARM_MASK_MIN = 0x0004,
	RTC_ALARM_MASK_HOUR = 0x0008,
	RTC_ALARM_MASK_DAY = 0x0010,
	RTC_ALARM_MASK_MON = 0x0020,
	RTC_ALARM_MASK_YEAR = 0x0040,
	RTC_ALARM_MASK_WEEK = 0x0080,
	RTC_ALARM_MASK_ALL = 0x00FF
} RTC_AlarmMask;

typedef enum
{
	RTC_CALIBRATE_PERIOD_8_SEC = 0,
	RTC_CALIBRATE_PERIOD_16_SEC,
	RTC_CALIBRATE_PERIOD_32_SEC
} RTC_CalibratePeriod;

typedef enum
{
	RTC_CALIBRATE_DIR_FORWARD = 0,
	RTC_CALIBRATE_DIR_BACKWARD
} RTC_CalibrateDirection;

typedef enum
{
	RTC_TIME_STAMP_EVENT_PIN = 0x0,
	RTC_TIME_STAMP_EVENT_INTERNAL,
	RTC_TIME_STAMP_EVENT_TAMPER_PIN_1 = 0x4,
	RTC_TIME_STAMP_EVENT_TAMPER_PIN_2,
	RTC_TIME_STAMP_EVENT_TAMPER_PIN_3
} RTC_TimeStampEvent;

typedef enum
{
	RTC_TAMPER_DETECT_PIN_1 = 0x1,
	RTC_TAMPER_DETECT_PIN_2,
	RTC_TAMPER_DETECT_PIN_3
} RTC_TamperDetectPin;

typedef enum
{
	RTC_TAMPER_DETECT_CLOCK_100HZ = 0x0,
	RTC_TAMPER_DETECT_CLOCK_50HZ,
	RTC_TAMPER_DETECT_CLOCK_25HZ,
	RTC_TAMPER_DETECT_CLOCK_12_5HZ
} RTC_TamperDetectClock;

typedef enum
{
	RTC_TAMPER_DETECT_MODE_EDGE = 0x0,
	RTC_TAMPER_DETECT_MODE_LEVEL
} RTC_TamperDetectMode;

typedef enum
{
	RTC_TAMPER_DETECT_COUNT_1 = 0x0,
	RTC_TAMPER_DETECT_COUNT_2,
	RTC_TAMPER_DETECT_COUNT_3,
	RTC_TAMPER_DETECT_COUNT_4
} RTC_TamperDetectCount;

typedef enum
{
	RTC_TAMPER_DETECT_POL_FALLING_EDGE = 0x0,		//falling edge / low level trigger
	RTC_TAMPER_DETECT_POL_RISING_EDGE				//rising edge / high level trigger
} RTC_TamperDetectPolarity;

typedef enum
{
	RTC_TAMPER_DETECT_CONDITION_ALL_PIN = 0x0,
	RTC_TAMPER_DETECT_CONDITION_ANY_PIN,
	RTC_TAMPER_DETECT_CONDITION_PIN_1 = 0x4,
	RTC_TAMPER_DETECT_CONDITION_PIN_2,
	RTC_TAMPER_DETECT_CONDITION_PIN_3
} RTC_TamperDetectCondition;

typedef enum
{
	RTC_TAMPER_DETECT_ACT_NONE = 0x0,
	RTC_TAMPER_DETECT_ACT_ERASE_BACKUP_MEM,
	RTC_TAMPER_DETECT_ACT_SYSTEM_RESET,
	RTC_TAMPER_DETECT_ACT_ERASE_AND_RESET
} RTC_TamperDetectAct;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
typedef struct
{
	U32 subSecond;
	U32 second;
	U32 minute;
	U32 hour;
} RTC_TimeStruct;

typedef struct
{
	U32 day;
	U32 month;
	U32 year;
	U32 week;
} RTC_DateStruct;

typedef struct
{
	U32 subSecond;
	U32 second;
	U32 minute;
	U32 hour;
	U32 day;
	U32 month;
	U32 year;
	U32 week;
	U32 mask;
} RTC_AlarmStruct;
//----------------------------------------------------------------------------------------------
extern RTC_Result RTC_InitRequest(void);
extern RTC_Return RTC_InitResultCheck(void);
extern RTC_Result RTC_CalendarSourceSelect(U8 source);
extern RTC_Result RTC_AlarmEnable(U8 alarmNumber);
extern RTC_Result RTC_AlarmDisable(U8 alarmNumber);
extern RTC_Result RTC_AlarmModeSelect(U8 alarmNumber, U8 mode);
extern RTC_Result RTC_TimerEnable(void);
extern RTC_Result RTC_TimerDisable(void);
extern RTC_Result RTC_TimerModeSelect(U8 mode);
extern RTC_Result RTC_TimerFreqSelect(U8 freq);
extern RTC_Result RTC_CalibrateEnable(void);
extern RTC_Return RTC_CalibrateCheck(void);
extern RTC_Result RTC_RefClockCompensateEnable(void);
extern RTC_Return RTC_RefClockCompensateCheck(void);
extern RTC_Result RTC_TimeStampEnable(void);
extern RTC_Result RTC_TimeStampDisable(void);
extern RTC_Result RTC_TimeStampInternalEventEnable(void);
extern RTC_Result RTC_TimeStampInternalEventDisable(void);
extern RTC_Result RTC_TamperDetectEnable(U8 tamperNumber);
extern RTC_Result RTC_TamperDetectDisable(U8 tamperNumber);
extern RTC_Result RTC_OutputSelect(U8 output);
extern RTC_Result RTC_OutputPolaritySelect(U8 polarity);
extern RTC_Result RTC_OutputTypeSelect(U8 type);
extern RTC_Result RTC_CalibrateOutputSelect(U8 output);
extern RTC_Return RTC_StatusRead(void);
extern RTC_Result RTC_IntEnable(U32 interrupt);
extern RTC_Result RTC_IntDisable(U32 interrupt);
extern RTC_Return RTC_IntRead(void);
extern RTC_Result RTC_IntClear(U32 interrupt);
extern RTC_Result RTC_AlarmMaskEnable(U8 alarmNumber, U32 mask);
extern RTC_Result RTC_AlarmMaskDisable(U8 alarmNumber, U32 mask);
extern RTC_Result RTC_TimerCounterSet(U32 count);
extern RTC_Return RTC_TimerCounterRead(void);
extern RTC_Result RTC_CalibratePeriodSelect(U8 period);
extern RTC_Result RTC_CalibrateDirectionSelect(U8 direction);
extern RTC_Result RTC_CalibrateCounterSet(U32 count);
extern RTC_Result RTC_Lock(U32 code);
extern RTC_Result RTC_Unlock(U32 code);
extern RTC_Result RTC_PreLockRegisterClear(void);
extern RTC_Result RTC_PreLockRegisterApply(void);
extern RTC_Result RTC_PreLockEnable(void);
extern RTC_Result RTC_PreLockDisable(void);
extern RTC_Result RTC_PreLockCodeSet(U32 code);
extern RTC_Result RTC_PreLockKeySet(void);
extern RTC_Result RTC_PreLockKeyClear(void);
extern RTC_Return RTC_LockStateCheck(void);
extern RTC_Result RTC_TimeSet(U32 subSecond, U32 second, U32 minute, U32 hour);
extern RTC_Result RTC_TimeRead(U32 *subSecond, U32 *second, U32 *minute, U32 *hour);
extern RTC_Result RTC_DateSet(U32 day, U32 month, U32 year, U32 week);
extern RTC_Result RTC_DateRead(U32 *day, U32 *month, U32 *year, U32 *week);
extern RTC_Result RTC_TimeStampTimeRead(U32 *subSecond, U32 *second, U32 *minute, U32 *hour);
extern RTC_Result RTC_TimeStampDateRead(U32 *day, U32 *month, U32 *year, U32 *week);
extern RTC_Return RTC_TimeStampEventCheck(void);
extern RTC_Result RTC_AlarmTimeSet(U8 alarmNumber, U32 subSecond, U32 second, U32 minute, U32 hour);
extern RTC_Result RTC_AlarmDateSet(U8 alarmNumber, U32 day, U32 month, U32 year, U32 week);
extern RTC_Result RTC_TamperDetectPinSelect(U8 pin);
extern RTC_Result RTC_TamperDetectClockSelect(U8 clock);
extern RTC_Result RTC_TamperDetectModeSelect(U8 mode);
extern RTC_Result RTC_TamperMajorRuleEnable(void);
extern RTC_Result RTC_TamperMajorRuleDisable(void);
extern RTC_Result RTC_TamperDetectCountSelect(U8 count);
extern RTC_Result RTC_TamperDetectPolaritySelect(U8 tamperNumber, U8 polarity);
extern RTC_Result RTC_TamperTimeStampEnable(void);
extern RTC_Result RTC_TamperTimeStampDisable(void);
extern RTC_Result RTC_TamperDetectConditionSelect(U8 condition);
extern RTC_Result RTC_TamperDetectActionSelect(U8 action);

#endif

//----------------------------------------------------------------------------------------------
// end of file
//----------------------------------------------------------------------------------------------
