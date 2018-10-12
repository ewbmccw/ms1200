/**
************************************************************************************************
* @file		RTC.c
* @author	Solution Team
* @brief	RTC API function file
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

static U32 LockRegister;

/**
************************************************************************************************
* @brief		RTC initialize request function
* @return		RTC_Result
************************************************************************************************
*/
RTC_Result RTC_InitRequest(void)
{
	HWREG(RTC->CR) |= 1 << 0;					//bit0

	return RTC_OK;
}
/**
************************************************************************************************
* @brief		RTC intialize result check function
* @return		RTC_Return(U32)
************************************************************************************************
*/
RTC_Return RTC_InitResultCheck(void)
{
	if((HWREG(RTC->CR) >> 0) & 0x00000001)		//bit0
	{
		return RTC_INIT_PENDING;
	}
	else
	{
		return RTC_INIT_DONE;
	}
}
/**
************************************************************************************************
* @brief		RTC calendar source select function
*				(time/date increment select for calendar interrupt)
* @param		U8 : source
* @return		RTC_Result
************************************************************************************************
*/
RTC_Result RTC_CalendarSourceSelect(U8 source)
{
	U32 value;
	U32 temp;

	value = HWREG(RTC->CR) & ~(0x7 << 4);		//bit4 ~ 6
	temp = (U32)source;
	value = value | (temp << 4);
	HWREG(RTC->CR) = value;

	return RTC_OK;
}
/**
************************************************************************************************
* @brief		RTC alarm enable function
* @param		U8 : alarm number
* @return		RTC_Result
************************************************************************************************
*/
RTC_Result RTC_AlarmEnable(U8 alarmNumber)
{
	if(alarmNumber == RTC_ALARM_NUMBER_1)
	{
		HWREG(RTC->CR) |= 0x1 << 8;				//bit8
	}
	else if(alarmNumber == RTC_ALARM_NUMBER_2)
	{
		HWREG(RTC->CR) |= 0x1 << 9;				//bit9
	}
	else
	{
		ASSERT(ERROR_PARAM);					//not accept parameter
	}

	return RTC_OK;
}
/**
************************************************************************************************
* @brief		RTC alarm disable function
* @param		U8 : alarm number
* @return		RTC_Result
************************************************************************************************
*/
RTC_Result RTC_AlarmDisable(U8 alarmNumber)
{
	if(alarmNumber == RTC_ALARM_NUMBER_1)
	{
		HWREG(RTC->CR) &= ~(0x1 << 8);			//bit8
	}
	else if(alarmNumber == RTC_ALARM_NUMBER_2)
	{
		HWREG(RTC->CR) &= ~(0x1 << 9);			//bit9
	}
	else
	{
		ASSERT(ERROR_PARAM);					//not accept parameter
	}

	return RTC_OK;
}
/**
************************************************************************************************
* @brief		RTC alarm mode select function
* @param		U8 : alarm number
* @param		U8 : mode
* @return		RTC_Result
************************************************************************************************
*/
RTC_Result RTC_AlarmModeSelect(U8 alarmNumber, U8 mode)
{
	if(alarmNumber == RTC_ALARM_NUMBER_1)
	{
		if(mode == RTC_ALARM_MODE_NORMAL)
		{
			HWREG(RTC->CR) &= ~(0x1 << 10);		//bit10
		}
		else if(mode == RTC_ALARM_MODE_ONE_SHOT)
		{
			HWREG(RTC->CR) |= 0x1 << 10;
		}
		else
		{
			ASSERT(ERROR_PARAM);				//not accept parameter
		}
	}
	else if(alarmNumber == RTC_ALARM_NUMBER_2)
	{
		if(mode == RTC_ALARM_MODE_NORMAL)
		{
			HWREG(RTC->CR) &= ~(0x1 << 11);		//bit11
		}
		else if(mode == RTC_ALARM_MODE_ONE_SHOT)
		{
			HWREG(RTC->CR) |= 0x1 << 11;
		}
		else
		{
			ASSERT(ERROR_PARAM);				//not accept parameter
		}
	}
	else
	{
		ASSERT(ERROR_PARAM);					//not accept parameter
	}

	return RTC_OK;
}
/**
************************************************************************************************
* @brief		RTC timer enable function
* @return		RTC_Result
************************************************************************************************
*/
RTC_Result RTC_TimerEnable(void)
{
	HWREG(RTC->CR) |= 0x1 << 12;				//bit12

	return RTC_OK;
}
/**
************************************************************************************************
* @brief		RTC timer disable function
* @return		RTC_Result
************************************************************************************************
*/
RTC_Result RTC_TimerDisable(void)
{
	HWREG(RTC->CR) &= ~(0x1 << 12);				//bit12

	return RTC_OK;
}
/**
************************************************************************************************
* @brief		RTC timer mode select function
* @param		U8 : mode
* @return		RTC_Result
************************************************************************************************
*/
RTC_Result RTC_TimerModeSelect(U8 mode)
{
	if(mode == RTC_TIMER_MODE_PERIODIC)
	{
		HWREG(RTC->CR) &= ~(0x1 << 13);			//bit13
	}
	else if(mode == RTC_TIMER_MODE_ONE_SHOT)
	{
		HWREG(RTC->CR) |= 0x1 << 13;
	}
	else
	{
		ASSERT(ERROR_PARAM);					//not accept parameter
	}

	return RTC_OK;
}
/**
************************************************************************************************
* @brief		RTC timer frequency select function
* @param		U8 : mode
* @return		RTC_Result
************************************************************************************************
*/
RTC_Result RTC_TimerFreqSelect(U8 freq)
{
	U32 value;
	U32 temp;

	value = HWREG(RTC->CR) & ~(0x3 << 14);		//bit14 ~ 15
	temp = (U32)freq;
	value = value | (temp << 14);
	HWREG(RTC->CR) = value;

	return RTC_OK;
}
/**
************************************************************************************************
* @brief		RTC calibration enable function
* @return		RTC_Result
************************************************************************************************
*/
RTC_Result RTC_CalibrateEnable(void)
{
	HWREG(RTC->CR) |= 1 << 16;					//bit16

	return RTC_OK;
}
/**
************************************************************************************************
* @brief		RTC calibration check function
* @return		RTC_Return(U32)
************************************************************************************************
*/
RTC_Return RTC_CalibrateCheck(void)
{
	return (HWREG(RTC->CR) >> 16) & 0x00000001;		//bit16
}
/**
************************************************************************************************
* @brief		RTC reference clock compensation enable function
* @return		RTC_Result
************************************************************************************************
*/
RTC_Result RTC_RefClockCompensateEnable(void)
{
	HWREG(RTC->CR) |= 1 << 17;						//bit17

	return RTC_OK;
}
/**
************************************************************************************************
* @brief		RTC reference clock compensation check function
* @return		RTC_Return(U32)
************************************************************************************************
*/
RTC_Return RTC_RefClockCompensateCheck(void)
{
	return (HWREG(RTC->CR) >> 17) & 0x00000001;		//bit17
}
/**
************************************************************************************************
* @brief		RTC time stamp enable function
* @return		RTC_Result
************************************************************************************************
*/
RTC_Result RTC_TimeStampEnable(void)
{
	HWREG(RTC->CR) |= 1 << 18;			//bit18

	return RTC_OK;
}
/**
************************************************************************************************
* @brief		RTC time stamp disable function
* @return		RTC_Result
************************************************************************************************
*/
RTC_Result RTC_TimeStampDisable(void)
{
	HWREG(RTC->CR) &= ~(1 << 18);		//bit18

	return RTC_OK;
}
/**
************************************************************************************************
* @brief		RTC time stamp internal event enable function
* @return		RTC_Result
************************************************************************************************
*/
RTC_Result RTC_TimeStampInternalEventEnable(void)
{
	HWREG(RTC->CR) |= 1 << 19;			//bit19

	return RTC_OK;
}
/**
************************************************************************************************
* @brief		RTC time stamp internal event disable function
* @return		RTC_Result
************************************************************************************************
*/
RTC_Result RTC_TimeStampInternalEventDisable(void)
{
	HWREG(RTC->CR) &= ~(1 << 19);		//bit19

	return RTC_OK;
}
/**
************************************************************************************************
* @brief		RTC tamper detect enable function
* @param		U8 : tamper number
* @return		RTC_Result
************************************************************************************************
*/
RTC_Result RTC_TamperDetectEnable(U8 tamperNumber)
{
	if(tamperNumber == RTC_TAMPER_NUMBER_1)
	{
		HWREG(RTC->CR) |= 0x1 << 20;		//bit20
	}
	else if(tamperNumber == RTC_TAMPER_NUMBER_2)
	{
		HWREG(RTC->CR) |= 0x1 << 21;		//bit21
	}
	else if(tamperNumber == RTC_TAMPER_NUMBER_3)
	{
		HWREG(RTC->CR) |= 0x1 << 22;		//bit22
	}
	else
	{
		ASSERT(ERROR_PARAM);				//not accept parameter
	}

	return RTC_OK;
}
/**
************************************************************************************************
* @brief		RTC tamper detect disable function
* @param		U8 : tamper number
* @return		RTC_Result
************************************************************************************************
*/
RTC_Result RTC_TamperDetectDisable(U8 tamperNumber)
{
	if(tamperNumber == RTC_TAMPER_NUMBER_1)
	{
		HWREG(RTC->CR) &= ~(0x1 << 20);	//bit20
	}
	else if(tamperNumber == RTC_TAMPER_NUMBER_2)
	{
		HWREG(RTC->CR) &= ~(0x1 << 21);	//bit21
	}
	else if(tamperNumber == RTC_TAMPER_NUMBER_3)
	{
		HWREG(RTC->CR) &= ~(0x1 << 22);	//bit22
	}
	else
	{
		ASSERT(ERROR_PARAM);				//not accept parameter
	}

	return RTC_OK;
}
/**
************************************************************************************************
* @brief		RTC output select function
* @param		U8 : output
* @return		RTC_Result
************************************************************************************************
*/
RTC_Result RTC_OutputSelect(U8 output)
{
	U32 value;
	U32 temp;

	if(output > RTC_OUTPUT_ALARM_2)
	{
		ASSERT(ERROR_PARAM);					//not accept parameter
	}

	value = HWREG(RTC->CR) & ~(0x3 << 24);		//bit24 ~ 25
	temp = (U32)output;
	value = value | (temp << 24);
	HWREG(RTC->CR) = value;

	return RTC_OK;
}
/**
************************************************************************************************
* @brief		RTC output polarity select function
* @param		U8 : polarity
* @return		RTC_Result
************************************************************************************************
*/
RTC_Result RTC_OutputPolaritySelect(U8 polarity)
{
	if(polarity == RTC_OUTPUT_POLARITY_LOW)
	{
		HWREG(RTC->CR) &= ~(0x1 << 26);			//bit26
	}
	else if(polarity == RTC_OUTPUT_POLARITY_HIGH)
	{
		HWREG(RTC->CR) |= 0x1 << 26;
	}
	else
	{
		ASSERT(ERROR_PARAM);					//not accept parameter
	}

	return RTC_OK;
}
/**
************************************************************************************************
* @brief		RTC output type select function
* @param		U8 : type
* @return		RTC_Result
************************************************************************************************
*/
RTC_Result RTC_OutputTypeSelect(U8 type)
{
	if(type == RTC_OUTPUT_TYPE_PUSH_PULL)
	{
		HWREG(RTC->CR) &= ~(0x1 << 27);			//bit27
	}
	else if(type == RTC_OUTPUT_TYPE_OPEN_DRAIN)
	{
		HWREG(RTC->CR) |= 0x1 << 27;
	}
	else
	{
		ASSERT(ERROR_PARAM);					//not accept parameter
	}

	return RTC_OK;
}
/**
************************************************************************************************
* @brief		RTC calibration output select function
* @param		U8 : output
* @return		RTC_Result
************************************************************************************************
*/
RTC_Result RTC_CalibrateOutputSelect(U8 output)
{
	if(output == RTC_CALIBRATION_OUTPUT_SUB_SEC)
	{
		HWREG(RTC->CR) &= ~(0x1 << 28);		//bit28
	}
	else if(output == RTC_CALIBRATION_OUTPUT_SEC)
	{
		HWREG(RTC->CR) |= 0x1 << 28;
	}
	else
	{
		ASSERT(ERROR_PARAM);			//not accept parameter
	}

	return RTC_OK;
}
/**
************************************************************************************************
* @brief		RTC status read function
* @return		RTC_Return(U32)
************************************************************************************************
*/
RTC_Return RTC_StatusRead(void)
{
	return HWREG(RTC->SR);
}
/**
************************************************************************************************
* @brief		RTC interrupt enable function
* @param		U32 : interrupt
* @return		RTC_Result
************************************************************************************************
*/
RTC_Result RTC_IntEnable(U32 interrupt)
{
	HWREG(RTC->IER) |= interrupt;

	return RTC_OK;
}
/**
************************************************************************************************
* @brief		RTC interrupt disable function
* @param		U32 : interrupt
* @return		RTC_Result
************************************************************************************************
*/
RTC_Result RTC_IntDisable(U32 interrupt)
{
	HWREG(RTC->IER) &= ~(interrupt);

	return RTC_OK;
}
/**
************************************************************************************************
* @brief		RTC interrupt read function
* @return		RTC_Return(U32)
************************************************************************************************
*/
RTC_Return RTC_IntRead(void)
{
	return HWREG(RTC->ISR);
}
/**
************************************************************************************************
* @brief		RTC interrupt clear function
* @param		U32 : interrupt
* @return		RTC_Result
************************************************************************************************
*/
RTC_Result RTC_IntClear(U32 Interrupt)
{
	HWREG(RTC->ICR) = Interrupt;

	return RTC_OK;
}
/**
************************************************************************************************
* @brief		RTC alarm mask enable function
* @param		U8 : alarm number
* @param		U32 : mask position
* @return		RTC_Result
************************************************************************************************
*/
RTC_Result RTC_AlarmMaskEnable(U8 alarmNumber, U32 mask)
{
	if(alarmNumber == RTC_ALARM_NUMBER_1)
	{
		HWREG(RTC->AMR) |= mask;
	}
	else if(alarmNumber == RTC_ALARM_NUMBER_2)
	{
		HWREG(RTC->AMR) |= (mask << 8);		//bit8 ~ 15
	}
	else
	{
		ASSERT(ERROR_PARAM);				//not accept parameter
	}

	return RTC_OK;
}
/**
************************************************************************************************
* @brief		RTC alarm mask disable function
* @param		U8 : alarm number
* @param		U32 : mask position
* @return		RTC_Result
************************************************************************************************
*/
RTC_Result RTC_AlarmMaskDisable(U8 alarmNumber, U32 mask)
{
	if(alarmNumber == RTC_ALARM_NUMBER_1)
	{
		HWREG(RTC->AMR) &= ~(mask);
	}
	else if(alarmNumber == RTC_ALARM_NUMBER_2)
	{
		HWREG(RTC->AMR) &= ~(mask << 8);		//bit8 ~ 15
	}
	else
	{
		ASSERT(ERROR_PARAM);					//not accept parameter
	}

	return RTC_OK;
}
/**
************************************************************************************************
* @brief		RTC timer counter set function
* @param		U32 : mask position
* @return		RTC_Result
************************************************************************************************
*/
RTC_Result RTC_TimerCounterSet(U32 count)
{
	HWREG(RTC->RTTCR) = count;

	return RTC_OK;
}
/**
************************************************************************************************
* @brief		RTC timer counter read function
* @return		RTC_Return(U32)
************************************************************************************************
*/
RTC_Return RTC_TimerCounterRead(void)
{
	return HWREG(RTC->RTTCR);
}
/**
************************************************************************************************
* @brief		RTC calibration period select function
* @param		U8 : period
* @return		RTC_Result
************************************************************************************************
*/
RTC_Result RTC_CalibratePeriodSelect(U8 period)
{
	U32 value;
	U32 temp;

	if(period > RTC_CALIBRATE_PERIOD_32_SEC)
	{
		ASSERT(ERROR_PARAM);					//not accept parameter
	}

	value = HWREG(RTC->CALR) & ~(0x3 << 0);		//bit0 ~ 1
	temp = (U32)period;
	value = value | (temp << 0);
	HWREG(RTC->CALR) = value;

	return RTC_OK;
}
/**
************************************************************************************************
* @brief		RTC calibration direction select function
* @param		U8 : direction
* @return		RTC_Result
************************************************************************************************
*/
RTC_Result RTC_CalibrateDirectionSelect(U8 direction)
{
	if(direction == RTC_CALIBRATE_DIR_FORWARD)
	{
		HWREG(RTC->CALR) &= ~(0x1 << 2);		//bit2
	}
	else if(direction == RTC_CALIBRATE_DIR_BACKWARD)
	{
		HWREG(RTC->CALR) |= 0x1 << 2;
	}
	else
	{
		ASSERT(ERROR_PARAM);					//not accept parameter
	}

	return RTC_OK;
}
/**
************************************************************************************************
* @brief		RTC calibration counter function
* @param		U32 : count
* @return		RTC_Result
************************************************************************************************
*/
RTC_Result RTC_CalibrateCounterSet(U32 count)
{
	U32 value;

	if(count > 100)									//0 ~ 100
	{
		ASSERT(ERROR_PARAM);						//not accept parameter
	}

	value = HWREG(RTC->CALR) & ~(0x7F << 4);		//bit4 ~ 10
	count = count & 0x0000007F;
	value = value | (count << 4);
	HWREG(RTC->CALR) = value;

	return RTC_OK;
}
/**
************************************************************************************************
* @brief		RTC lock function
* @param		U32 : code
* @return		RTC_Result
************************************************************************************************
*/
RTC_Result RTC_Lock(U32 code)
{
	RTC_PreLockRegisterClear();
	RTC_PreLockEnable();
	RTC_PreLockKeySet();
	RTC_PreLockCodeSet(code);
	RTC_PreLockRegisterApply();

	RTC_PreLockRegisterClear();
	RTC_PreLockEnable();
	RTC_PreLockKeyClear();
	RTC_PreLockCodeSet(code);
	RTC_PreLockRegisterApply();

	RTC_PreLockRegisterClear();
	RTC_PreLockEnable();
	RTC_PreLockKeySet();
	RTC_PreLockCodeSet(code);
	RTC_PreLockRegisterApply();

	return RTC_OK;
}
/**
************************************************************************************************
* @brief		RTC unlock function
* @param		U32 : code
* @return		RTC_Result
************************************************************************************************
*/
RTC_Result RTC_Unlock(U32 code)
{
	RTC_PreLockRegisterClear();
	RTC_PreLockDisable();
	RTC_PreLockKeySet();
	RTC_PreLockCodeSet(code);
	RTC_PreLockRegisterApply();

	RTC_PreLockRegisterClear();
	RTC_PreLockDisable();
	RTC_PreLockKeyClear();
	RTC_PreLockCodeSet(code);
	RTC_PreLockRegisterApply();

	RTC_PreLockRegisterClear();
	RTC_PreLockDisable();
	RTC_PreLockKeySet();
	RTC_PreLockCodeSet(code);
	RTC_PreLockRegisterApply();

	return RTC_OK;
}
/**
************************************************************************************************
* @brief		RTC (pre) lock register variable clear function
* @return		RTC_Result
************************************************************************************************
*/
RTC_Result RTC_PreLockRegisterClear(void)
{
	LockRegister = 0;

	return RTC_OK;
}
/**
************************************************************************************************
* @brief		RTC (pre) lock register apply function
* @return		RTC_Result
************************************************************************************************
*/
RTC_Result RTC_PreLockRegisterApply(void)
{
	HWREG(RTC->LR) = LockRegister;

	return RTC_OK;
}
/**
************************************************************************************************
* @brief		RTC (pre) lock enable function
* @return		RTC_Result
************************************************************************************************
*/
RTC_Result RTC_PreLockEnable(void)
{
	LockRegister |= 1 << 0;			//bit0

	return RTC_OK;
}
/**
************************************************************************************************
* @brief		RTC (pre) lock disable function
* @return		RTC_Result
************************************************************************************************
*/
RTC_Result RTC_PreLockDisable(void)
{
	LockRegister &= ~(1 << 0);		//bit0

	return RTC_OK;
}
/**
************************************************************************************************
* @brief		RTC (pre) lock register code set function
* @param		U32 : code
* @return		RTC_Result
************************************************************************************************
*/
RTC_Result RTC_PreLockCodeSet(U32 code)
{
	U32 value;

	value = LockRegister & ~(0xFF << 8);		//bit8 ~ 15
	code = code & 0x000000FF;
	value = value | (code << 8);
	LockRegister = value;

	return RTC_OK;
}
/**
************************************************************************************************
* @brief		RTC (pre) lock register key set function
* @return		RTC_Result
************************************************************************************************
*/
RTC_Result RTC_PreLockKeySet(void)
{
	LockRegister |= 1 << 16;		//bit16

	return RTC_OK;
}
/**
************************************************************************************************
* @brief		RTC (pre) lock register key clear function
* @return		RTC_Result
************************************************************************************************
*/
RTC_Result RTC_PreLockKeyClear(void)
{
	LockRegister &= ~(1 << 16);		//bit16

	return RTC_OK;
}
/**
************************************************************************************************
* @brief		RTC lock state check function
* @return		RTC_Return(U32)
************************************************************************************************
*/
RTC_Return RTC_LockStateCheck(void)
{
	return (HWREG(RTC->LR) >> 16) & 0x00000001;		//bit16
}
/**
************************************************************************************************
* @brief		RTC time set function
* @param		U32 : sub-second
* @param		U32 : second
* @param		U32 : minute
* @param		U32 : hour
* @return		RTC_Result
************************************************************************************************
*/
RTC_Result RTC_TimeSet(U32 subSecond, U32 second, U32 minute, U32 hour)
{
	U32 value;

	value = HWREG(RTC->TR);

	value = value & ~(0x7F << 0);		//bit0 ~ 6
	subSecond = subSecond & 0x0000007F;
	value = value | (subSecond << 0);

	value = value & ~(0x3F << 8);		//bit8 ~ 13
	second = second & 0x0000003F;
	value = value | (second << 8);

	value = value & ~(0x3F << 16);		//bit16 ~ 21
	minute = minute & 0x0000003F;
	value = value | (minute << 16);

	value = value & ~(0xF << 24);		//bit24 ~ 28
	hour = hour & 0x0000000F;
	value = value | (hour << 24);

	HWREG(RTC->TR) = value;

	return RTC_OK;
}
/**
************************************************************************************************
* @brief		RTC time read function
* @param		U32 * : sub-second
* @param		U32 * : second
* @param		U32 * : minute
* @param		U32 * : hour
* @return		RTC_Result
************************************************************************************************
*/
RTC_Result RTC_TimeRead(U32 *subSecond, U32 *second, U32 *minute, U32 *hour)
{
	*subSecond = (HWREG(RTC->TR) >> 0) & 0x0000007F;	//bit0 ~ 6
	*second = (HWREG(RTC->TR) >> 8) & 0x0000003F;		//bit8 ~ 13
	*minute = (HWREG(RTC->TR) >> 16) & 0x0000003F;		//bit16 ~ 21
	*hour = (HWREG(RTC->TR) >> 24) & 0x0000001F;		//bit24 ~ 28

	return RTC_OK;
}
/**
************************************************************************************************
* @brief		RTC date set function
* @param		U32 : day
* @param		U32 : month
* @param		U32 : year
* @param		U32 : week
* @return		RTC_Result
************************************************************************************************
*/
RTC_Result RTC_DateSet(U32 day, U32 month, U32 year, U32 week)
{
	U32 value;

	value = HWREG(RTC->DR);

	value = value & ~(0x1F << 0);		//bit0 ~ 4
	day = day & 0x0000001F;
	value = value | (day << 0);

	value = value & ~(0xF << 8);		//bit8 ~ 11
	month = month & 0x0000000F;
	value = value | (month << 8);

	value = value & ~(0xFFF << 12);		//bit12 ~ 23
	year = year & 0x00000FFF;
	value = value | (year << 12);

	value = value & ~(0x7 << 24);		//bit24 ~ 26
	week = week & 0x00000007;
	value = value | (week << 24);

	HWREG(RTC->DR) = value;

	return RTC_OK;
}
/**
************************************************************************************************
* @brief		RTC date read function
* @param		U32 * : day
* @param		U32 * : month
* @param		U32 * : year
* @param		U32 * : week
* @return		RTC_Result
************************************************************************************************
*/
RTC_Result RTC_DateRead(U32 *day, U32 *month, U32 *year, U32 *week)
{
	*day = (HWREG(RTC->DR) >> 0) & 0x0000001F;			//bit0 ~ 4
	*month = (HWREG(RTC->DR) >> 8) & 0x0000000F;		//bit8 ~ 11
	*year = (HWREG(RTC->DR) >> 12) & 0x000000FFF;		//bit12 ~ 23
	*week = (HWREG(RTC->DR) >> 24) & 0x00000007;		//bit24 ~ 26

	return RTC_OK;
}
/**
************************************************************************************************
* @brief		RTC time stamp time read function
* @param		U32 * : sub-second
* @param		U32 * : second
* @param		U32 * : minute
* @param		U32 * : hour
* @return		RTC_Result
************************************************************************************************
*/
RTC_Result RTC_TimeStampTimeRead(U32 *subSecond, U32 *second, U32 *minute, U32 *hour)
{
	*subSecond = (HWREG(RTC->TSTR) >> 0) & 0x0000007F;		//bit0 ~ 6
	*second = (HWREG(RTC->TSTR) >> 8) & 0x0000003F;			//bit8 ~ 13
	*minute = (HWREG(RTC->TSTR) >> 16) & 0x0000003F;		//bit16 ~ 21
	*hour = (HWREG(RTC->TSTR) >> 24) & 0x0000001F;			//bit24 ~ 28

	return RTC_OK;
}
/**
************************************************************************************************
* @brief		RTC time stamp date read function
* @param		U32 * : day
* @param		U32 * : month
* @param		U32 * : year
* @param		U32 * : week
* @return		RTC_Result
************************************************************************************************
*/
RTC_Result RTC_TimeStampDateRead(U32 *day, U32 *month, U32 *year, U32 *week)
{
	*day = (HWREG(RTC->TSDR) >> 0) & 0x0000001F;		//bit0 ~ 4
	*month = (HWREG(RTC->TSDR) >> 8) & 0x0000000F;		//bit8 ~ 11
	*year = (HWREG(RTC->TSDR) >> 12) & 0x000000FFF;		//bit12 ~ 23
	*week = (HWREG(RTC->TSDR) >> 24) & 0x00000007;		//bit24 ~ 26

	return RTC_OK;
}
/**
************************************************************************************************
* @brief		RTC time stamp event check function
* @return		RTC_Return(U32)
************************************************************************************************
*/
RTC_Return RTC_TimeStampEventCheck(void)
{
	return HWREG(RTC->TSDR) & 0x00000007;
}
/**
************************************************************************************************
* @brief		RTC alarm time set function
* @param		U8 : alarm number
* @param		U32 : sub-second
* @param		U32 : second
* @param		U32 : minute
* @param		U32 : hour
* @return		RTC_Result
************************************************************************************************
*/
RTC_Result RTC_AlarmTimeSet(U8 alarmNumber, U32 subSecond, U32 second, U32 minute, U32 hour)
{
	volatile U32 *address;
	U32 value;

	if(alarmNumber == RTC_ALARM_NUMBER_1)
	{
		address = (U32 *)&HWREG(RTC->A1TR);
	}
	else if(alarmNumber == RTC_ALARM_NUMBER_2)
	{
		address = (U32 *)&HWREG(RTC->A2TR);
	}
	else
	{
		ASSERT(ERROR_PARAM);			//not accept parameter
	}

	value = *address;

	value = value & ~(0x7F << 0);		//bit0 ~ 6
	subSecond = subSecond & 0x0000007F;
	value = value | (subSecond << 0);

	value = value & ~(0x3F << 8);		//bit8 ~ 13
	second = second & 0x0000003F;
	value = value | (second << 8);

	value = value & ~(0x3F << 16);		//bit16 ~ 21
	minute = minute & 0x0000003F;
	value = value | (minute << 16);

	value = value & ~(0xF << 24);		//bit24 ~ 28
	hour = hour & 0x0000000F;
	value = value | (hour << 24);

	*address = value;

	return RTC_OK;
}
/**
************************************************************************************************
* @brief		RTC alarm date set function
* @param		U8 : alarm number
* @param		U32 : day
* @param		U32 : month
* @param		U32 : year
* @param		U32 : week
* @return		RTC_Result
************************************************************************************************
*/
RTC_Result RTC_AlarmDateSet(U8 alarmNumber, U32 day, U32 month, U32 year, U32 week)
{
	U32 *address;
	U32 value;

	if(alarmNumber == RTC_ALARM_NUMBER_1)
	{
		address = (U32 *)&HWREG(RTC->A1DR);
	}
	else if(alarmNumber == RTC_ALARM_NUMBER_2)
	{
		address = (U32 *)&HWREG(RTC->A2DR);
	}
	else
	{
		ASSERT(ERROR_PARAM);			//not accept parameter
	}

	value = *address;

	value = value & ~(0x1F << 0);		//bit0 ~ 4
	day = day & 0x0000001F;
	value = value | (day << 0);

	value = value & ~(0xF << 8);		//bit8 ~ 11
	month = month & 0x0000000F;
	value = value | (month << 8);

	value = value & ~(0xFFF << 12);		//bit12 ~ 23
	year = year & 0x00000FFF;
	value = value | (year << 12);

	value = value & ~(0x7 << 24);		//bit24 ~ 26
	week = week & 0x00000007;
	value = value | (week << 24);

	*address = value;

	return RTC_OK;
}
/**
************************************************************************************************
* @brief		RTC tamper detection pin select function
* @param		U8 : pin
* @return		RTC_Result
************************************************************************************************
*/
RTC_Result RTC_TamperDetectPinSelect(U8 pin)
{
	U32 value;
	U32 temp;

	value = HWREG(RTC->TDCR) & ~(0x3 << 0);		//bit0 ~ 1
	temp = (U32)pin;
	value = value | (temp << 0);
	HWREG(RTC->TDCR) = value;

	return RTC_OK;
}
/**
************************************************************************************************
* @brief		RTC tamper detection clock select function
* @param		U8 : clock
* @return		RTC_Result
************************************************************************************************
*/
RTC_Result RTC_TamperDetectClockSelect(U8 clock)
{
	U32 value;
	U32 temp;

	value = HWREG(RTC->TDCR) & ~(0x3 << 2);		//bit2 ~ 3
	temp = (U32)clock;
	value = value | (temp << 2);
	HWREG(RTC->TDCR) = value;

	return RTC_OK;
}
/**
************************************************************************************************
* @brief		RTC tamper detection mode select function
* @param		U8 : mode
* @return		RTC_Result
************************************************************************************************
*/
RTC_Result RTC_TamperDetectModeSelect(U8 mode)
{
	if(mode == RTC_TAMPER_DETECT_MODE_EDGE)
	{
		HWREG(RTC->TDCR) &= ~(0x1 << 4);		//bit4
	}
	else if(mode == RTC_TAMPER_DETECT_MODE_LEVEL)
	{
		HWREG(RTC->TDCR) |= 0x1 << 4;
	}
	else
	{
		ASSERT(ERROR_PARAM);					//not accept parameter
	}

	return RTC_OK;
}
/**
************************************************************************************************
* @brief		RTC tamper majority rule detection enable function
* @return		RTC_Result
************************************************************************************************
*/
RTC_Result RTC_TamperMajorRuleEnable(void)
{
	HWREG(RTC->TDCR) |= 0x1 << 5;				//bit5

	return RTC_OK;
}
/**
************************************************************************************************
* @brief		RTC tamper majority rule detection disable function
* @return		RTC_Result
************************************************************************************************
*/
RTC_Result RTC_TamperMajorRuleDisable(void)
{
	HWREG(RTC->TDCR) &= ~(0x1 << 5);			//bit5

	return RTC_OK;
}
/**
************************************************************************************************
* @brief		RTC tamper detection count select function
* @param		U8 : count
* @return		RTC_Result
************************************************************************************************
*/
RTC_Result RTC_TamperDetectCountSelect(U8 count)
{
	U32 value;
	U32 temp;

	value = HWREG(RTC->TDCR) & ~(0x3 << 6);		//bit6 ~ 7
	temp = (U32)count;
	value = value | (temp << 6);
	HWREG(RTC->TDCR) = value;

	return RTC_OK;
}
/**
************************************************************************************************
* @brief		RTC tamper detection polarity select function
* @param		U8 : tamper number
* @param		U8 : polarity
* @return		RTC_Result
************************************************************************************************
*/
RTC_Result RTC_TamperDetectPolaritySelect(U8 tamperNumber, U8 polarity)
{
	U32 shift;

	switch(tamperNumber)
	{
		case RTC_TAMPER_NUMBER_1:
		{
			shift = 8;					//bit8

			break;
		}
		case RTC_TAMPER_NUMBER_2:
		{
			shift = 9;					//bit9

			break;
		}
		case RTC_TAMPER_NUMBER_3:
		{
			shift = 10;					//bit10

			break;
		}
		default:
		{
			ASSERT(ERROR_PARAM);		//not accept parameter
		}
	}

	if(polarity == RTC_TAMPER_DETECT_POL_RISING_EDGE)
	{
		HWREG(RTC->TDCR) &= ~(0x1 << shift);
	}
	else if(polarity == RTC_TAMPER_DETECT_POL_FALLING_EDGE)
	{
		HWREG(RTC->TDCR) |= 0x1 << shift;
	}
	else
	{
		ASSERT(ERROR_PARAM);			//not accept parameter
	}

	return RTC_OK;
}
/**
************************************************************************************************
* @brief		RTC tamper detection time stamp enable function
* @return		RTC_Result
************************************************************************************************
*/
RTC_Result RTC_TamperTimeStampEnable(void)
{
	HWREG(RTC->TDCR) |= 0x1 << 12;			//bit12

	return RTC_OK;
}
/**
************************************************************************************************
* @brief		RTC tamper detection time stamp disable function
* @return		RTC_Result
************************************************************************************************
*/
RTC_Result RTC_TamperTimeStampDisable(void)
{
	HWREG(RTC->TDCR) &= ~(0x1 << 12);		//bit12

	return RTC_OK;
}
/**
************************************************************************************************
* @brief		RTC tamper detection condition select function
* @param		U8 : condition
* @return		RTC_Result
************************************************************************************************
*/
RTC_Result RTC_TamperDetectConditionSelect(U8 condition)
{
	U32 value;
	U32 temp;

	value = HWREG(RTC->TDCR) & ~(0x7 << 13);		//bit13 ~ 15
	temp = (U32)condition;
	value = value | (temp << 13);
	HWREG(RTC->TDCR) = value;

	return RTC_OK;
}
/**
************************************************************************************************
* @brief		RTC tamper detection counteraction select function
* @param		U8 : action
* @return		RTC_Result
************************************************************************************************
*/
RTC_Result RTC_TamperDetectActionSelect(U8 action)
{
	U32 value;
	U32 temp;

	value = HWREG(RTC->TDCR) & ~(0x3 << 16);		//bit16 ~ 17
	temp = (U32)action;
	value = value | (temp << 16);
	HWREG(RTC->TDCR) = value;

	return RTC_OK;
}
/**
************************************************************************************************
* @brief		RTC interrupt handler
************************************************************************************************
*/
__irq void RTC_IrqHandler(void)
{
	U32 status;

	status = HWREG(RTC->ISR);

	RTC_IntClear(status);

	APP_RTC_CallBack(status);
}

//----------------------------------------------------------------------------------------------
// end of file
//----------------------------------------------------------------------------------------------
