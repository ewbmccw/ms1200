/**
************************************************************************************************
* @file			CRM.c
* @author		Solution Team
* @brief		CRM API function file
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

static U32 ClockLockRegister;
static U32 GroupResetModeLockRegister;

/**
************************************************************************************************
* @brief		CRM clock status read function
* @return		CRM_Return(U32)
************************************************************************************************
*/
CRM_Return CRM_ClockStatusRead(void)
{
	return HWREG(CRM->CSR);
}
/**
************************************************************************************************
* @brief		CRM clock ready check function
* @param		U32 : clock
* @return		CRM_Return(U32)
************************************************************************************************
*/
CRM_Return CRM_ClockReadyCheck(U32 clock)
{
	if(HWREG(CRM->CSR) & clock)
	{
		return CRM_READY;
	}
	else
	{
		return CRM_NOT_READY;
	}
}
/**
************************************************************************************************
* @brief		CRM clock interrupt enable function
* @param		U32 : interrupt
* @return		CRM_Result
************************************************************************************************
*/
CRM_Result CRM_ClockIntEnable(U32 interrupt)
{
	HWREG(CRM->CIER) |= Interrupt;

	return CRM_OK;
}
/**
************************************************************************************************
* @brief		CRM clock interrupt disable function
* @param		U32 : interrupt
* @return		CRM_Result
************************************************************************************************
*/
CRM_Result CRM_ClockIntDisable(U32 interrupt)
{
	HWREG(CRM->CIER) |= ~Interrupt;

	return CRM_OK;
}
/**
************************************************************************************************
* @brief		CRM clock interrupt status read function
* @return		CRM_Return(U32)
************************************************************************************************
*/
CRM_Return CRM_ClockIntStatusRead(void)
{
	return HWREG(CRM->CISR);
}
/**
************************************************************************************************
* @brief		CRM clock interrupt clear function
* @param		U32 : interrupt
* @return		CRM_Result
************************************************************************************************
*/
CRM_Result CRM_ClockIntClear(U32 interrupt)
{
	HWREG(CRM->CICR) |= Interrupt;

	return CRM_OK;
}
/**
************************************************************************************************
* @brief		CRM clock lock function
* @param		U32 : lock code
* @return		CRM_Result
************************************************************************************************
*/
CRM_Result CRM_ClockLock(U32 code)
{
	CRM_PreClockLockRegisterClear();
	CRM_PreClockLockEnable();
	CRM_PreClockLockKeySet();
	CRM_PreClockLockCodeSet(Code);
	CRM_PreClockLockRegisterApply();

	CRM_PreClockLockRegisterClear();
	CRM_PreClockLockEnable();
	CRM_PreClockLockKeyClear();
	CRM_PreClockLockCodeSet(Code);
	CRM_PreClockLockRegisterApply();

	CRM_PreClockLockRegisterClear();
	CRM_PreClockLockEnable();
	CRM_PreClockLockKeySet();
	CRM_PreClockLockCodeSet(Code);
	CRM_PreClockLockRegisterApply();

	return CRM_OK;
}
/**
************************************************************************************************
* @brief		CRM clock unlock function
* @param		U32 : lock code
* @return		CRM_Result
************************************************************************************************
*/
CRM_Result CRM_ClockUnlock(U32 code)
{
	CRM_PreClockLockRegisterClear();
	CRM_PreClockLockDisable();
	CRM_PreClockLockKeySet();
	CRM_PreClockLockCodeSet(Code);
	CRM_PreClockLockRegisterApply();

	CRM_PreClockLockRegisterClear();
	CRM_PreClockLockDisable();
	CRM_PreClockLockKeyClear();
	CRM_PreClockLockCodeSet(Code);
	CRM_PreClockLockRegisterApply();

	CRM_PreClockLockRegisterClear();
	CRM_PreClockLockDisable();
	CRM_PreClockLockKeySet();
	CRM_PreClockLockCodeSet(Code);
	CRM_PreClockLockRegisterApply();

	return CRM_OK;
}
/**
************************************************************************************************
* @brief		CRM pre clock lock register clear function
* @return		CRM_Result
************************************************************************************************
*/
CRM_Result CRM_PreClockLockRegisterClear(void)
{
	ClockLockRegister = 0;

	return CRM_OK;
}
/**
************************************************************************************************
* @brief		CRM pre clock lock register apply function
* @return		CRM_Result
************************************************************************************************
*/
CRM_Result CRM_PreClockLockRegisterApply(void)
{
	HWREG(CRM->CCLR) = ClockLockRegister;

	return CRM_OK;
}
/**
************************************************************************************************
* @brief		CRM pre clock lock enable function
* @return		CRM_Result
************************************************************************************************
*/
CRM_Result CRM_PreClockLockEnable(void)
{
	ClockLockRegister |= 1 << 0;		//bit0

	return CRM_OK;
}
/**
************************************************************************************************
* @brief		CRM pre clock lock disable function
* @return		CRM_Result
************************************************************************************************
*/
CRM_Result CRM_PreClockLockDisable(void)
{
	ClockLockRegister &= ~(1 << 0);		//bit0

	return CRM_OK;
}
/**
************************************************************************************************
* @brief		CRM pre clock lock code set function
* @param		U32 : lock code
* @return		CRM_Result
************************************************************************************************
*/
CRM_Result CRM_PreClockLockCodeSet(U32 code)
{
	U32 value;

	value = ClockLockRegister & ~(0x7FFF << 1);		//bit1 ~ 15
	code = code & 0x00007FFF;
	value = value | (code << 1);
	ClockLockRegister = value;

	return CRM_OK;
}
/**
************************************************************************************************
* @brief		CRM pre clock lock key set function
* @return		CRM_Result
************************************************************************************************
*/
CRM_Result CRM_PreClockLockKeySet(void)
{
	ClockLockRegister |= 1 << 16;			//bit16

	return CRM_OK;
}
/**
************************************************************************************************
* @brief		CRM pre clock lock key clear function
* @return		CRM_Result
************************************************************************************************
*/
CRM_Result CRM_PreClockLockKeyClear(void)
{
	ClockLockRegister &= ~(1 << 16);		//bit16

	return CRM_OK;
}
/**
************************************************************************************************
* @brief		CRM clock lock key check function
* @return		CRM_Return(U32)
************************************************************************************************
*/
CRM_Return CRM_ClockLockKeyCheck(U8 *State)
{
	return (HWREG(CRM->CCLR) >> 16) & 0x00000001;		//bit16
}
/**
************************************************************************************************
* @brief		CRM X'tal bypass mode enable function
* @return		CRM_Result
************************************************************************************************
*/
CRM_Result CRM_XtalByPassEnable(void)
{
	HWREG(CRM->OBDCR) |= 0x1 << 1;			//bit1

	return CRM_OK;
}
/**
************************************************************************************************
* @brief		CRM X'tal bypass mode disable function
* @return		CRM_Result
************************************************************************************************
*/
CRM_Result CRM_XtalByPassDisable(void)
{
	HWREG(CRM->OBDCR) &= ~(0x1 << 1);		//bit1

	return CRM_OK;
}
/**
************************************************************************************************
* @brief		CRM RTC enable function
* @return		CRM_Result
************************************************************************************************
*/
CRM_Result CRM_RtcEnable(void)				//If enabled once, this cannot be disabled by program.
{
	HWREG(CRM->OBDCR) |= 0x1 << 5;			//bit5

	return CRM_OK;
}
/**
************************************************************************************************
* @brief		CRM RTC clock enable function
* @return		CRM_Result
************************************************************************************************
*/
CRM_Result CRM_RtcClockEnable(void)			//If enabled once, this cannot be disabled by program.
{
	HWREG(CRM->OBDCR) |= 0x1 << 6;			//bit6

	return CRM_OK;
}
/**
************************************************************************************************
* @brief		CRM backup domain reset send function
* @param		U8 : level
* @return		CRM_Result
************************************************************************************************
*/
CRM_Result CRM_BackUpDomainResetSend(U8 level)
{
	if(level)
	{
		HWREG(CRM->OBDCR) |= 0x1 << 7;		//bit7
	}
	else
	{
		HWREG(CRM->OBDCR) &= ~(0x1 << 7);
	}

	return CRM_OK;
}
/**
************************************************************************************************
* @brief		CRM backup domain reset status check function
* @return		CRM_Return(U32)
************************************************************************************************
*/
CRM_Return CRM_BackUpDomainResetStatusCheck(void)
{
	return (HWREG(CRM->OBDCR) >> 7) & 0x00000001;		//bit7
}
/**
************************************************************************************************
* @brief		CRM PLL clock source select function
* @param		U32 : source
* @return		CRM_Result
************************************************************************************************
*/
CRM_Result CRM_PllSourceSelect(U32 source)
{
	U32 value;

	value = HWREG(CRM->PLLCR);

	value = value & ~(0x3 << 0);		//bit0 ~ 1
	source = (source & 0x00000003) << 0;
	value = value | source;

	HWREG(CRM->PLLCR) = value;

	return CRM_OK;
}
/**
************************************************************************************************
* @brief		CRM PLL output used check function
* @return		CRM_Return(U32)
************************************************************************************************
*/
CRM_Return CRM_PllUsedCheck(void)
{
	return (HWREG(CRM->PLLCR)) >> 4 & 0x00000001;		//bit4
}
/**
************************************************************************************************
* @brief		CRM PLL enable function
* @return		CRM_Result
************************************************************************************************
*/
CRM_Result CRM_PllEnable(void)
{
	HWREG(CRM->PLLCR) |= 0x1 << 5;			//bit5

	return CRM_OK;
}
/**
************************************************************************************************
* @brief		CRM PLL disable function
* @return		CRM_Result
************************************************************************************************
*/
CRM_Result CRM_PllDisable(void)
{
	HWREG(CRM->PLLCR) &= ~(0x1 << 5);		//bit5

	return CRM_OK;
}
/**
************************************************************************************************
* @brief		CRM PLL bypass mode enable function
* @return		CRM_Result
************************************************************************************************
*/
CRM_Result CRM_PllBypassEnable(void)
{
	HWREG(CRM->PLLCR) |= 0x1 << 6;			//bit6

	return CRM_OK;
}
/**
************************************************************************************************
* @brief		CRM PLL bypass mode disable function
* @return		CRM_Result
************************************************************************************************
*/
CRM_Result CRM_PllBypassDisable(void)
{
	HWREG(CRM->PLLCR) &= ~(0x1 << 6);		//bit6

	return CRM_OK;
}
/**
************************************************************************************************
* @brief		CRM PLL reset function
* @return		CRM_Result
************************************************************************************************
*/
CRM_Result CRM_PllReset(void)
{
	HWREG(CRM->PLLCR) |= 0x1 << 7;			//bit7

	return CRM_OK;
}
/**
************************************************************************************************
* @brief		CRM PLL feedback divider set function
* @param		U32 : divider
* @return		CRM_Result
************************************************************************************************
*/
CRM_Result CRM_PllFeedBackDividerSet(U32 divider)
{
	U32 value;

	value = HWREG(CRM->PLLCR);

	value = value & ~(0x1FFF << 8);				//bit8 ~ 20
	divider = (divider & 0x00001FFF) << 8;
	value = value | divider;

	HWREG(CRM->PLLCR) = value;

	return CRM_OK;
}
/**
************************************************************************************************
* @brief		CRM PLL input divider set function
* @param		U32 : divider
* @return		CRM_Result
************************************************************************************************
*/
CRM_Result CRM_PllInputDividerSet(U32 divider)
{
	U32 value;

	value = HWREG(CRM->PLLCR);

	value = value & ~(0x3F << 22);				//bit22 ~ 27
	divider = (divider & 0x0000003F) << 22;
	value = value | divider;

	HWREG(CRM->PLLCR) = value;

	return CRM_OK;
}
/**
************************************************************************************************
* @brief		CRM PLL output divider set function
* @param		U32 : divider
* @return		CRM_Result
************************************************************************************************
*/
CRM_Result CRM_PllOutputDividerSet(U32 divider)
{
	U32 value;

	value = HWREG(CRM->PLLCR);

	value = value & ~(0xF << 28);				//bit28 ~ 31
	divider = (divider & 0x0000000F) << 28;
	value = value | divider;

	HWREG(CRM->PLLCR) = value;

	return CRM_OK;
}
/**
************************************************************************************************
* @brief		CRM PLL loop filter adjust set function
* @param		U32 : data(adjust value)
* @return		CRM_Result
************************************************************************************************
*/
CRM_Result CRM_PllLoopFilterAdjustSet(U32 data)
{
	U32 value;

	value = HWREG(CRM->PLLC2R);

	value = value & ~(0xFFF << 0);			//bit0 ~ 11
	data = (data & 0x00000FFF) << 0;
	value = value | data;

	HWREG(CRM->PLLC2R) = value;

	return CRM_OK;
}
/**
************************************************************************************************
* @brief		CRM PLL numerator(X) set function
* @param		U32 : fracx
* @return		CRM_Result
************************************************************************************************
*/
CRM_Result CRM_PllFracxSet(U32 fracx)
{
	U32 value;

	value = HWREG(CRM->PLLC2R);

	value = value & ~(0xFF << 16);			//bit16 ~ 23
	fracx = (fracx & 0x000000FF) << 16;
	value = value | fracx;

	HWREG(CRM->PLLC2R) = value;

	return CRM_OK;
}
/**
************************************************************************************************
* @brief		CRM PLL denomiator(Y) set function
* @param		U32 : fracy
* @return		CRM_Result
************************************************************************************************
*/
CRM_Result CRM_PllFracySet(U32 fracy)
{
	U32 value;

	value = HWREG(CRM->PLLC2R);

	value = value & ~(0xFF << 24);			//bit24 ~ 31
	fracy = (fracy & 0x000000FF) << 24;
	value = value | fracy;

	HWREG(CRM->PLLC2R) = value;

	return CRM_OK;
}
/**
************************************************************************************************
* @brief		CRM divider A clock source select function
* @param		U32 : source
* @return		CRM_Result
************************************************************************************************
*/
CRM_Result CRM_DivaSourceSelect(U32 source)
{
	U32 value;

	value = HWREG(CRM->DACR)

	value = value & ~(0x3 << 0);			//bit0 ~ 1
	source = (source & 0x00000003) << 0;
	value = value | source;

	HWREG(CRM->DACR) = value;

	return CRM_OK;
}
/**
************************************************************************************************
* @brief		CRM divider A clock select mode set function
* @param		U8 : mode
* @return		CRM_Result
************************************************************************************************
*/
CRM_Result CRM_DivaSelectModeSet(U8 mode)
{
	if(mode == CRM_CLOCK_SELECT_MODE_GLITCHLESS)
	{
		HWREG(CRM->DACR) &= ~(0x1 << 3);	//bit3
	}
	else if(mode == CRM_CLOCK_SELECT_MODE_ASYNCHRONOUS)
	{
		HWREG(CRM->DACR) |= (0x1 << 3);		//bit3
	}
	else
	{
		ASSERT(ERROR_PARAM);				//not accept parameter
	}

	return CRM_OK;
}
/**
************************************************************************************************
* @brief		CRM divider A output used check function
* @return		CRM_Return(U32)
************************************************************************************************
*/
CRM_Return CRM_DivaUsedCheck(void)
{
	return (HWREG(CRM->DACR) >> 4) & 0x00000001;		//bit4
}
/**
************************************************************************************************
* @brief		CRM divider A ready check function
* @return		CRM_Return(U32)
************************************************************************************************
*/
CRM_Return CRM_DivaReadyCheck(void)
{
	return (HWREG(CRM->DACR) >> 5) & 0x00000001;		//bit5
}
/**
************************************************************************************************
* @brief		CRM divider A divider set function
* @param		U32 : divider
* @return		CRM_Result
************************************************************************************************
*/
CRM_Result CRM_DivaDividerSet(U32 divider)
{
	U32 value;

	value = HWREG(CRM->DACR);

	value = value & ~(0x3 << 8);		//bit8 ~ 9
	divider = (divider & 0x00000003) << 8;
	value = value | divider;

	HWREG(CRM->DACR) = value;

	return CRM_OK;
}
/**
************************************************************************************************
* @brief		CRM divider B clock source select function
* @param		U32 : source
* @return		CRM_Result
************************************************************************************************
*/
CRM_Result CRM_DivbSourceSelect(U8 Source)
{
	U32 Value;
	U32 Temp;

	Value = HWREG(CRM->DBCR);

	Value = Value & ~(0x7 << 0);		//bit0 ~ 2
	Temp = (U32)Source;
	Temp = (Temp & 0x00000007) << 0;
	Value = Value | Temp;

	HWREG(CRM->DBCR) = Value;

	return CRM_OK;
}
/**
************************************************************************************************
* @brief		CRM divider B clock select mode set function
* @param		U8 : mode
* @return		CRM_Result
************************************************************************************************
*/
CRM_Result CRM_DivbSelectModeSet(U8 mode)
{
	if(mode == CRM_CLOCK_SELECT_MODE_GLITCHLESS)
	{
		HWREG(CRM->DBCR) &= ~(0x1 << 3);		//bit3
	}
	else if(mode == CRM_CLOCK_SELECT_MODE_ASYNCHRONOUS)
	{
		HWREG(CRM->DBCR) |= (0x1 << 3);			//bit3
	}
	else
	{
		ASSERT(ERROR_PARAM);					//not accept parameter
	}

	return CRM_OK;
}
/**
************************************************************************************************
* @brief		CRM divider B output used check function
* @return		CRM_Return(U32)
************************************************************************************************
*/
CRM_Return CRM_DivbUsedCheck(void)
{
	return (HWREG(CRM->DBCR) >> 4) & 0x00000001;		//bit4
}
/**
************************************************************************************************
* @brief		CRM divider B ready check function
* @return		CRM_Return(U32)
************************************************************************************************
*/
CRM_Return CRM_DivbReadyCheck(void)
{
	return (HWREG(CRM->DBCR) >> 5) & 0x00000001;		//bit5
}
/**
************************************************************************************************
* @brief		CRM divider B divider set function
* @param		U32 : divider
* @return		CRM_Result
************************************************************************************************
*/
CRM_Result CRM_DivbDividerSet(U32 divider)
{
	U32 value;

	value = HWREG(CRM->DBCR);

	value = value & ~(0x7 << 8);		//bit8 ~ 10
	divider = (divider & 0x00000007) << 8;
	value = value | divider;

	HWREG(CRM->DBCR) = value;

	return CRM_OK;
}
/**
************************************************************************************************
* @brief		CRM divider B numerator(X) set function
* @param		U32 : fracx
* @return		CRM_Result
************************************************************************************************
*/
CRM_Result CRM_DivbFracxSet(U32 fracx)
{
	U32 value;

	value = HWREG(CRM->DBCR);

	value = value & ~(0xF << 16);		//bit16 ~ 19
	fracx = (fracx & 0x0000000F) << 16;
	value = value | fracx;

	HWREG(CRM->DBCR) = value;

	return CRM_OK;
}
/**
************************************************************************************************
* @brief		CRM divider B denomiator(Y) set function
* @param		U32 : fracy
* @return		CRM_Result
************************************************************************************************
*/
CRM_Result CRM_DivbFracySet(U32 fracy)
{
	U32 value;

	value = HWREG(CRM->DBCR);

	value = value & ~(0xF << 24);		//bit24 ~ 27
	fracy = (fracy & 0x0000000F) << 24;
	value = value | fracy;

	HWREG(CRM->DBCR) = value;

	return CRM_OK;
}
/**
************************************************************************************************
* @brief		CRM divider C clock source select function
* @param		U32 : source
* @return		CRM_Result
************************************************************************************************
*/
CRM_Result CRM_DivcSourceSelect(U32 source)
{
	U32 value;

	value = HWREG(CRM->DCCR);

	value = Value & ~(0x7 << 0);		//bit0 ~ 2
	source = (source & 0x00000007) << 0;
	value = value | source;

	HWREG(CRM->DCCR) = value;

	return CRM_OK;
}
/**
************************************************************************************************
* @brief		CRM divider C clock select mode set function
* @param		U8 : mode
* @return		CRM_Result
************************************************************************************************
*/
CRM_Result CRM_DivcSelectModeSet(U8 mode)
{
	if(mode == CRM_CLOCK_SELECT_MODE_GLITCHLESS)
	{
		HWREG(CRM->DCCR) &= ~(0x1 << 3);		//bit3
	}
	else if(mode == CRM_CLOCK_SELECT_MODE_ASYNCHRONOUS)
	{
		HWREG(CRM->DCCR) |= (0x1 << 3);			//bit3
	}
	else
	{
		ASSERT(ERROR_PARAM);					//not accept parameter
	}

	return CRM_OK;
}
/**
************************************************************************************************
* @brief		CRM divider C output used check function
* @return		CRM_Return(U32)
************************************************************************************************
*/
CRM_Return CRM_DivcUsedCheck(void)
{
	return (HWREG(CRM->DCCR) >> 4) & 0x00000001;		//bit4
}
/**
************************************************************************************************
* @brief		CRM divider C ready check function
* @return		CRM_Return(U32)
************************************************************************************************
*/
CRM_Return CRM_DivcReadyCheck(void)
{
	return (HWREG(CRM->DCCR) >> 5) & 0x00000001;		//bit5
}
/**
************************************************************************************************
* @brief		CRM divider C divider set function
* @param		U32 : divider
* @return		CRM_Result
************************************************************************************************
*/
CRM_Result CRM_DivcDividerSet(U32 divider)
{
	U32 value;

	value = HWREG(CRM->DCCR);

	value = value & ~(0xF << 8);		//bit8 ~ 11
	divider = (divider & 0x0000000F) << 8;
	value = value | divider;

	HWREG(CRM->DCCR) = value;

	return CRM_OK;
}
/**
************************************************************************************************
* @brief		CRM divider D clock source select function
* @param		U32 : source
* @return		CRM_Result
************************************************************************************************
*/
CRM_Result CRM_DivdSourceSelect(U32 source)
{
	U32 value;

	value = HWREG(CRM->DDCR);

	value = value & ~(0x7 << 0);		//bit0 ~ 2
	source = (source & 0x00000007) << 0;
	Value = Value | source;

	HWREG(CRM->DDCR) = value;

	return CRM_OK;
}
/**
************************************************************************************************
* @brief		CRM divider D clock select mode set function
* @param		U8 : mode
* @return		CRM_Result
************************************************************************************************
*/
CRM_Result CRM_DivdSelectModeSet(U8 mode)
{
	if(mode == CRM_CLOCK_SELECT_MODE_GLITCHLESS)
	{
		HWREG(CRM->DDCR) &= ~(0x1 << 3);		//bit3
	}
	else if(mode == CRM_CLOCK_SELECT_MODE_ASYNCHRONOUS)
	{
		HWREG(CRM->DDCR) |= (0x1 << 3);			//bit3
	}
	else
	{
		ASSERT(ERROR_PARAM);					//not accept parameter
	}

	return CRM_OK;
}
/**
************************************************************************************************
* @brief		CRM divider D output used check function
* @return		CRM_Return(U32)
************************************************************************************************
*/
CRM_Return CRM_DivdUsedCheck(void)
{
	return (HWREG(CRM->DDCR) >> 4) & 0x00000001;		//bit4
}
/**
************************************************************************************************
* @brief		CRM divider D ready check function
* @return		CRM_Return(U32)
************************************************************************************************
*/
CRM_Return CRM_DivdReadyCheck(void)
{
	return (HWREG(CRM->DDCR) >> 5) & 0x00000001;		//bit5
}
/**
************************************************************************************************
* @brief		CRM divider D divider set function
* @param		U32 : divider
* @return		CRM_Result
************************************************************************************************
*/
CRM_Result CRM_DivdDividerSet(U32 divider)
{
	U32 value;

	value = HWREG(CRM->DDCR);

	value = value & ~(0xF << 8);		//bit8 ~ 11
	divider = (divider & 0x0000000F) << 8;
	value = value | divider;

	HWREG(CRM->DDCR) = value;

	return CRM_OK;
}
/**
************************************************************************************************
* @brief		CRM divider D numerator(X) set function
* @param		U32 : fracx
* @return		CRM_Result
************************************************************************************************
*/
CRM_Result CRM_DivdFracxSet(U32 fracx)
{
	U32 value;

	value = HWREG(CRM->DDCR);

	value = value & ~(0xFF << 16);		//bit16 ~ 23
	fracx = (fracx & 0x000000FF) << 16;
	value = value | fracx;

	HWREG(CRM->DDCR) = value;

	return CRM_OK;
}
/**
************************************************************************************************
* @brief		CRM divider D denomiator(Y) set function
* @param		U32 : fracy
* @return		CRM_Result
************************************************************************************************
*/
CRM_Result CRM_DivdFracySet(U32 fracy)
{
	U32 value;

	value = HWREG(CRM->DDCR);

	value = value & ~(0xFF << 24);		//bit24 ~ 31
	fracy = (fracy & 0x000000FF) << 24;
	value = value | fracy;

	HWREG(CRM->DDCR) = value;

	return CRM_OK;
}
/**
************************************************************************************************
* @brief		CRM divider E clock source select function
* @param		U32 : source
* @return		CRM_Result
************************************************************************************************
*/
CRM_Result CRM_DiveSourceSelect(U32 source)
{
	U32 value;

	value = HWREG(CRM->DECR);

	value = value & ~(0x7 << 0);		//bit0 ~ 2
	source = (source & 0x00000007) << 0;
	value = value | source;

	HWREG(CRM->DECR) = value;

	return CRM_OK;
}
/**
************************************************************************************************
* @brief		CRM divider E clock select mode set function
* @param		U8 : mode
* @return		CRM_Result
************************************************************************************************
*/
CRM_Result CRM_DiveSelectModeSet(U8 mode)
{
	if(mode == CRM_CLOCK_SELECT_MODE_GLITCHLESS)
	{
		HWREG(CRM->DECR) &= ~(0x1 << 3);		//bit3
	}
	else if(mode == CRM_CLOCK_SELECT_MODE_ASYNCHRONOUS)
	{
		HWREG(CRM->DECR) |= (0x1 << 3);			//bit3
	}
	else
	{
		ASSERT(ERROR_PARAM);					//not accept parameter
	}

	return CRM_OK;
}
/**
************************************************************************************************
* @brief		CRM divider E output used check function
* @return		CRM_Return(U32)
************************************************************************************************
*/
CRM_Return CRM_DiveUsedCheck(void)
{
	return (HWREG(CRM->DECR) >> 4) & 0x00000001;		//bit4
}
/**
************************************************************************************************
* @brief		CRM divider E ready check function
* @return		CRM_Return(U32)
************************************************************************************************
*/
CRM_Return CRM_DiveReadyCheck(void)
{
	return (HWREG(CRM->DECR) >> 5) & 0x00000001;		//bit5
}
/**
************************************************************************************************
* @brief		CRM divider E divider set function
* @param		U32 : divider
* @return		CRM_Result
************************************************************************************************
*/
CRM_Result CRM_DiveDividerSet(U32 divider)
{
	U32 value;

	value = HWREG(CRM->DECR);

	value = value & ~(0x3F << 8);		//bit8 ~ 13
	divider = (divider & 0x0000003F) << 8;
	Value = value | divider;

	HWREG(CRM->DECR) = value;

	return CRM_OK;
}
//----------------------------------------------------------------------------------------------
CRM_Result CRM_SystemClockSourceSelect(U8 Source)
{
	U32 Value;
	U32 Temp;

	Value = rCRM_SYS_CLK_CTRL;

	Value = Value & ~(0x0000000F << 0);	//bit0 ~ 3
	Temp = (U32)Source;
	Temp = (Temp & 0x0000000F) << 0;
	Value = Value | Temp;

	rCRM_SYS_CLK_CTRL = Value;

	return CRM_OK;
}
//----------------------------------------------------------------------------------------------
CRM_Result CRM_AhbPrescalerSet(U32 Prescale)
{
	U32 Value;

	Value = rCRM_SYS_CLK_CTRL;

	Value = Value & ~(0x0000000F << 4);	//bit4 ~ 7
	Prescale = (Prescale & 0x0000000F) << 4;
	Value = Value | Prescale;

	rCRM_SYS_CLK_CTRL = Value;

	return CRM_OK;
}
//----------------------------------------------------------------------------------------------
CRM_Result CRM_Apb1PrescalerSet(U32 Prescale)
{
	U32 Value;

	Value = rCRM_SYS_CLK_CTRL;

	Value = Value & ~(0x00000007 << 8);	//bit8 ~ 10
	Prescale = (Prescale & 0x00000007) << 8;
	Value = Value | Prescale;

	rCRM_SYS_CLK_CTRL = Value;

	return CRM_OK;
}
//----------------------------------------------------------------------------------------------
CRM_Result CRM_Apb2PrescalerSet(U32 Prescale)
{
	U32 Value;

	Value = rCRM_SYS_CLK_CTRL;

	Value = Value & ~(0x00000007 << 12);	//bit12 ~ 14
	Prescale = (Prescale & 0x00000007) << 12;
	Value = Value | Prescale;

	rCRM_SYS_CLK_CTRL = Value;

	return CRM_OK;
}
//----------------------------------------------------------------------------------------------
CRM_Result CRM_AhbLowPowerEnable(void)
{
	rCRM_SYS_CLK_CTRL |= 0x1 << 16;		//bit16

	return CRM_OK;
}
//----------------------------------------------------------------------------------------------
CRM_Result CRM_AhbLowPowerDisable(void)
{
	rCRM_SYS_CLK_CTRL &= ~(0x1 << 16);	//bit16

	return CRM_OK;
}
//----------------------------------------------------------------------------------------------
CRM_Result CRM_Apb1LowPowerEnable(void)
{
	rCRM_SYS_CLK_CTRL |= 0x1 << 18;		//bit18

	return CRM_OK;
}
//----------------------------------------------------------------------------------------------
CRM_Result CRM_Apb1LowPowerDisable(void)
{
	rCRM_SYS_CLK_CTRL &= ~(0x1 << 18);	//bit18

	return CRM_OK;
}
//----------------------------------------------------------------------------------------------
CRM_Result CRM_Apb2LowPowerEnable(void)
{
	rCRM_SYS_CLK_CTRL |= 0x1 << 19;		//bit19

	return CRM_OK;
}
//----------------------------------------------------------------------------------------------
CRM_Result CRM_Apb2LowPowerDisable(void)
{
	rCRM_SYS_CLK_CTRL &= ~(0x1 << 19);	//bit19

	return CRM_OK;
}
//----------------------------------------------------------------------------------------------
CRM_Result CRM_BootRomClockDisable(void)
{
	rCRM_SYS_CLK_CTRL |= 0x1 << 20;		//bit20

	return CRM_OK;
}
//----------------------------------------------------------------------------------------------
CRM_Result CRM_EflashPrescalerSet(U32 Prescale)
{
	U32 Value;

	Value = rCRM_SYS_CLK_CTRL;

	Value = Value & ~(0x00000007 << 24);	//bit24 ~ 26
	Prescale = (Prescale & 0x00000007) << 24;
	Value = Value | Prescale;

	rCRM_SYS_CLK_CTRL = Value;

	return CRM_OK;
}
//----------------------------------------------------------------------------------------------
CRM_Result CRM_DeepSleepClockModeSet(U8 Mode)
{
	U32 Value;
	U32 Temp;

	Value = rCRM_SYS_CLK_CTRL;

	Value = Value & ~(0x00000003 << 30);		//bit30 ~ 31
	Temp = (U32)Mode;
	Temp = (Temp & 0x00000003) << 30;
	Value = Value | Temp;

	rCRM_SYS_CLK_CTRL = Value;

	return CRM_OK;
}
//----------------------------------------------------------------------------------------------
CRM_Result CRM_SystickSourceSelect(U8 Source)
{
	U32 Value;
	U32 Temp;

	Value = rCRM_ST_CLK_CTRL;

	Value = Value & ~(0x0000000F << 0);	//bit0 ~ 4
	Temp = (U32)Source;
	Temp = (Temp & 0x0000000F) << 0;
	Value = Value | Temp;

	rCRM_ST_CLK_CTRL = Value;

	return CRM_OK;
}
//----------------------------------------------------------------------------------------------
CRM_Result CRM_SystickRefClockEnable(void)
{
	rCRM_ST_CLK_CTRL |= 0x1 << 6;		//bit6

	return CRM_OK;
}
//----------------------------------------------------------------------------------------------
CRM_Result CRM_SystickRefClockDisable(void)
{
	rCRM_ST_CLK_CTRL &= ~(0x1 << 6);	//bit6

	return CRM_OK;
}
//----------------------------------------------------------------------------------------------
CRM_Result CRM_SystickSkewSet(U8 Mode)
{
	if(Mode)
	{
		rCRM_ST_CLK_CTRL |= 0x1 << 7;		//bit7
	}

	else
	{
		rCRM_ST_CLK_CTRL &= ~(0x1 << 7);	//bit7
	}


	return CRM_OK;
}
//----------------------------------------------------------------------------------------------
CRM_Result CRM_SystickCalValueSet(U32 Data)
{
	U32 Value;

	Value = rCRM_ST_CLK_CTRL;

	Value = Value & ~(0x00FFFFFF << 8);	//bit8 ~ 31
	Data = (Data & 0x00FFFFFF) << 8;
	Value = Value | Data;

	rCRM_ST_CLK_CTRL = Value;

	return CRM_OK;
}
//----------------------------------------------------------------------------------------------
CRM_Result CRM_PeriClockSelect(U8 Peripheral, U8 Source)
{
	volatile U32 *Register;
	U32 Value;
	U32 Position;
	U32 Temp;

	if(Peripheral == CRM_PERI_TIMER_1)
	{
		Register = &rCRM_PERI_CLK_SEL1;
		Position = 0;
	}

	else if(Peripheral == CRM_PERI_TIMER_2)
	{
		Register = &rCRM_PERI_CLK_SEL1;
		Position = 1;
	}

	else if(Peripheral == CRM_PERI_WATCHDOG)
	{
		Register = &rCRM_PERI_CLK_SEL1;
		Position = 2;
	}

	else if(Peripheral == CRM_PERI_QSPI)
	{
		Register = &rCRM_PERI_CLK_SEL1;
		Position = 3;
	}

	else if(Peripheral == CRM_PERI_SDMMC)
	{
		Register = &rCRM_PERI_CLK_SEL1;
		Position = 4;
	}

	else if(Peripheral == CRM_PERI_CLOCK_OUT_1)
	{
		Register = &rCRM_PERI_CLK_SEL1;
		Position = 6;
	}

	else if(Peripheral == CRM_PERI_CLOCK_OUT_2)
	{
		Register = &rCRM_PERI_CLK_SEL1;
		Position = 7;
	}

	else if(Peripheral == CRM_PERI_UART_1)
	{
		Register = &rCRM_PERI_CLK_SEL2;
		Position = 0;
	}

	else if(Peripheral == CRM_PERI_UART_2)
	{
		Register = &rCRM_PERI_CLK_SEL2;
		Position = 1;
	}

	else if(Peripheral == CRM_PERI_UART_3)
	{
		Register = &rCRM_PERI_CLK_SEL2;
		Position = 2;
	}

	else if(Peripheral == CRM_PERI_UART_4)
	{
		Register = &rCRM_PERI_CLK_SEL2;
		Position = 3;
	}

	else if(Peripheral == CRM_PERI_SPI_1)
	{
		Register = &rCRM_PERI_CLK_SEL2;
		Position = 4;
	}

	else if(Peripheral == CRM_PERI_SPI_2)
	{
		Register = &rCRM_PERI_CLK_SEL2;
		Position = 5;
	}

	else if(Peripheral == CRM_PERI_SPI_3)
	{
		Register = &rCRM_PERI_CLK_SEL2;
		Position = 6;
	}

	else if(Peripheral == CRM_PERI_SPI_4)
	{
		Register = &rCRM_PERI_CLK_SEL2;
		Position = 7;
	}

	else if(Peripheral == CRM_PERI_ADC)
	{
		Register = &rCRM_PERI_CLK_SEL3;
		Position = 0;
	}

	else if(Peripheral == CRM_PERI_USB)
	{
		Register = &rCRM_PERI_CLK_SEL3;
		Position = 2;
	}

	else if(Peripheral == CRM_PERI_CAN)
	{
		Register = &rCRM_PERI_CLK_SEL3;
		Position = 3;
	}

	else
	{
		return CRM_ERROR;
	}


	Value = *Register;

	Value = Value & ~(0x0000000F << (Position * 4));
	Temp = (U32)Source;
	Temp = (Temp & 0x0000000F) << (Position * 4);
	Value = Value | Temp;

	*Register = Value;

	return CRM_OK;
}
//----------------------------------------------------------------------------------------------
CRM_Result CRM_PeriClockEnable(U8 Peripheral)
{
	if(Peripheral == CRM_PERI_DMA)
	{
		rCRM_PERI_CLK_EN |= 0x1 << 0;
	}

	else if(Peripheral == CRM_PERI_EBI)
	{
		rCRM_PERI_CLK_EN |= 0x1 << 2;
	}

	else if(Peripheral == CRM_PERI_WATCHDOG)
	{
		rCRM_PERI_CLK_EN |= 0x1 << 3;
	}

	else if(Peripheral == CRM_PERI_TIMER_1)
	{
		rCRM_PERI_CLK_EN |= 0x1 << 4;
	}

	else if(Peripheral == CRM_PERI_TIMER_2)
	{
		rCRM_PERI_CLK_EN |= 0x1 << 5;
	}

	else if(Peripheral == CRM_PERI_GPIO_1)
	{
		rCRM_PERI_CLK_EN |= 0x1 << 8;
	}

	else if(Peripheral == CRM_PERI_GPIO_2)
	{
		rCRM_PERI_CLK_EN |= 0x1 << 9;
	}

	else if(Peripheral == CRM_PERI_GPIO_3)
	{
		rCRM_PERI_CLK_EN |= 0x1 << 10;
	}

	else if(Peripheral == CRM_PERI_GPIO_4)
	{
		rCRM_PERI_CLK_EN |= 0x1 << 11;
	}

	else if(Peripheral == CRM_PERI_GPIO_5)
	{
		rCRM_PERI_CLK_EN |= 0x1 << 12;
	}

	else if(Peripheral == CRM_PERI_QSPI)
	{
		rCRM_PERI_CLK_EN |= 0x1 << 14;
	}

	else if(Peripheral == CRM_PERI_SDMMC)
	{
		rCRM_PERI_CLK_EN |= 0x1 << 15;
	}

	else if(Peripheral == CRM_PERI_UART_1)
	{
		rCRM_PERI_CLK_EN |= 0x1 << 16;
	}

	else if(Peripheral == CRM_PERI_UART_2)
	{
		rCRM_PERI_CLK_EN |= 0x1 << 17;
	}

	else if(Peripheral == CRM_PERI_UART_3)
	{
		rCRM_PERI_CLK_EN |= 0x1 << 18;
	}

	else if(Peripheral == CRM_PERI_UART_4)
	{
		rCRM_PERI_CLK_EN |= 0x1 << 19;
	}

	else if(Peripheral == CRM_PERI_SPI_1)
	{
		rCRM_PERI_CLK_EN |= 0x1 << 20;
	}

	else if(Peripheral == CRM_PERI_SPI_2)
	{
		rCRM_PERI_CLK_EN |= 0x1 << 21;
	}

	else if(Peripheral == CRM_PERI_SPI_3)
	{
		rCRM_PERI_CLK_EN |= 0x1 << 22;
	}

	else if(Peripheral == CRM_PERI_SPI_4)
	{
		rCRM_PERI_CLK_EN |= 0x1 << 23;
	}

	else if(Peripheral == CRM_PERI_I2C_1)
	{
		rCRM_PERI_CLK_EN |= 0x1 << 24;
	}

	else if(Peripheral == CRM_PERI_I2C_2)
	{
		rCRM_PERI_CLK_EN |= 0x1 << 25;
	}

	else if(Peripheral == CRM_PERI_ADC)
	{
		rCRM_PERI_CLK_EN |= 0x1 << 26;
	}

	else if(Peripheral == CRM_PERI_USB)
	{
		rCRM_PERI_CLK_EN |= 0x1 << 27;
	}

	else if(Peripheral == CRM_PERI_CAN)
	{
		rCRM_PERI_CLK_EN |= 0x1 << 28;
	}

	else if(Peripheral == CRM_PERI_SDIO_SLAVE)
	{
		rCRM_PERI_CLK_EN |= 0x1 << 29;
	}

	else if(Peripheral == CRM_PERI_CLOCK_OUT_1)
	{
		rCRM_PERI_CLK_EN |= 0x1 << 30;
	}

	else if(Peripheral == CRM_PERI_CLOCK_OUT_2)
	{
		rCRM_PERI_CLK_EN |= 0x1 << 31;
	}

	else
	{
		return CRM_ERROR;
	}


	return CRM_OK;
}
//----------------------------------------------------------------------------------------------
CRM_Result CRM_PeriClockDisable(U8 Peripheral)
{
	if(Peripheral == CRM_PERI_DMA)
	{
		rCRM_PERI_CLK_EN |= ~(0x1 << 0);
	}

	else if(Peripheral == CRM_PERI_EBI)
	{
		rCRM_PERI_CLK_EN |= ~(0x1 << 2);
	}

	else if(Peripheral == CRM_PERI_WATCHDOG)
	{
		rCRM_PERI_CLK_EN |= ~(0x1 << 3);
	}

	else if(Peripheral == CRM_PERI_TIMER_1)
	{
		rCRM_PERI_CLK_EN |= ~(0x1 << 4);
	}

	else if(Peripheral == CRM_PERI_TIMER_2)
	{
		rCRM_PERI_CLK_EN |= ~(0x1 << 5);
	}

	else if(Peripheral == CRM_PERI_GPIO_1)
	{
		rCRM_PERI_CLK_EN |= ~(0x1 << 8);
	}

	else if(Peripheral == CRM_PERI_GPIO_2)
	{
		rCRM_PERI_CLK_EN |= ~(0x1 << 9);
	}

	else if(Peripheral == CRM_PERI_GPIO_3)
	{
		rCRM_PERI_CLK_EN |= ~(0x1 << 10);
	}

	else if(Peripheral == CRM_PERI_GPIO_4)
	{
		rCRM_PERI_CLK_EN |= ~(0x1 << 11);
	}

	else if(Peripheral == CRM_PERI_GPIO_5)
	{
		rCRM_PERI_CLK_EN |= ~(0x1 << 12);
	}

	else if(Peripheral == CRM_PERI_QSPI)
	{
		rCRM_PERI_CLK_EN |= ~(0x1 << 14);
	}

	else if(Peripheral == CRM_PERI_SDMMC)
	{
		rCRM_PERI_CLK_EN |= ~(0x1 << 15);
	}

	else if(Peripheral == CRM_PERI_UART_1)
	{
		rCRM_PERI_CLK_EN |= ~(0x1 << 16);
	}

	else if(Peripheral == CRM_PERI_UART_2)
	{
		rCRM_PERI_CLK_EN |= ~(0x1 << 17);
	}

	else if(Peripheral == CRM_PERI_UART_3)
	{
		rCRM_PERI_CLK_EN |= ~(0x1 << 18);
	}

	else if(Peripheral == CRM_PERI_UART_4)
	{
		rCRM_PERI_CLK_EN |= ~(0x1 << 19);
	}

	else if(Peripheral == CRM_PERI_SPI_1)
	{
		rCRM_PERI_CLK_EN |= ~(0x1 << 20);
	}

	else if(Peripheral == CRM_PERI_SPI_2)
	{
		rCRM_PERI_CLK_EN |= ~(0x1 << 21);
	}

	else if(Peripheral == CRM_PERI_SPI_3)
	{
		rCRM_PERI_CLK_EN |= ~(0x1 << 22);
	}

	else if(Peripheral == CRM_PERI_SPI_4)
	{
		rCRM_PERI_CLK_EN |= ~(0x1 << 23);
	}

	else if(Peripheral == CRM_PERI_I2C_1)
	{
		rCRM_PERI_CLK_EN |= ~(0x1 << 24);
	}

	else if(Peripheral == CRM_PERI_I2C_2)
	{
		rCRM_PERI_CLK_EN |= ~(0x1 << 25);
	}

	else if(Peripheral == CRM_PERI_ADC)
	{
		rCRM_PERI_CLK_EN |= ~(0x1 << 26);
	}

	else if(Peripheral == CRM_PERI_USB)
	{
		rCRM_PERI_CLK_EN |= ~(0x1 << 27);
	}

	else if(Peripheral == CRM_PERI_CAN)
	{
		rCRM_PERI_CLK_EN |= ~(0x1 << 28);
	}

	else if(Peripheral == CRM_PERI_SDIO_SLAVE)
	{
		rCRM_PERI_CLK_EN |= ~(0x1 << 29);
	}

	else if(Peripheral == CRM_PERI_CLOCK_OUT_1)
	{
		rCRM_PERI_CLK_EN |= ~(0x1 << 30);
	}

	else if(Peripheral == CRM_PERI_CLOCK_OUT_2)
	{
		rCRM_PERI_CLK_EN |= ~(0x1 << 31);
	}

	else
	{
		return CRM_ERROR;
	}


	return CRM_OK;
}
//----------------------------------------------------------------------------------------------
CRM_Result CRM_PeriClockLowPowerEnable(U8 Peripheral)
{
	if(Peripheral == CRM_PERI_DMA)
	{
		rCRM_PERI_CLK_LPEN |= 0x1 << 0;
	}

	else if(Peripheral == CRM_PERI_EBI)
	{
		rCRM_PERI_CLK_LPEN |= 0x1 << 2;
	}

	else if(Peripheral == CRM_PERI_WATCHDOG)
	{
		rCRM_PERI_CLK_LPEN |= 0x1 << 3;
	}

	else if(Peripheral == CRM_PERI_TIMER_1)
	{
		rCRM_PERI_CLK_LPEN |= 0x1 << 4;
	}

	else if(Peripheral == CRM_PERI_TIMER_2)
	{
		rCRM_PERI_CLK_LPEN |= 0x1 << 5;
	}

	else if(Peripheral == CRM_PERI_GPIO_1)
	{
		rCRM_PERI_CLK_LPEN |= 0x1 << 8;
	}

	else if(Peripheral == CRM_PERI_GPIO_2)
	{
		rCRM_PERI_CLK_LPEN |= 0x1 << 9;
	}

	else if(Peripheral == CRM_PERI_GPIO_3)
	{
		rCRM_PERI_CLK_LPEN |= 0x1 << 10;
	}

	else if(Peripheral == CRM_PERI_GPIO_4)
	{
		rCRM_PERI_CLK_LPEN |= 0x1 << 11;
	}

	else if(Peripheral == CRM_PERI_GPIO_5)
	{
		rCRM_PERI_CLK_LPEN |= 0x1 << 12;
	}

	else if(Peripheral == CRM_PERI_QSPI)
	{
		rCRM_PERI_CLK_LPEN |= 0x1 << 14;
	}

	else if(Peripheral == CRM_PERI_SDMMC)
	{
		rCRM_PERI_CLK_LPEN |= 0x1 << 15;
	}

	else if(Peripheral == CRM_PERI_UART_1)
	{
		rCRM_PERI_CLK_LPEN |= 0x1 << 16;
	}

	else if(Peripheral == CRM_PERI_UART_2)
	{
		rCRM_PERI_CLK_LPEN |= 0x1 << 17;
	}

	else if(Peripheral == CRM_PERI_UART_3)
	{
		rCRM_PERI_CLK_LPEN |= 0x1 << 18;
	}

	else if(Peripheral == CRM_PERI_UART_4)
	{
		rCRM_PERI_CLK_LPEN |= 0x1 << 19;
	}

	else if(Peripheral == CRM_PERI_SPI_1)
	{
		rCRM_PERI_CLK_LPEN |= 0x1 << 20;
	}

	else if(Peripheral == CRM_PERI_SPI_2)
	{
		rCRM_PERI_CLK_LPEN |= 0x1 << 21;
	}

	else if(Peripheral == CRM_PERI_SPI_3)
	{
		rCRM_PERI_CLK_LPEN |= 0x1 << 22;
	}

	else if(Peripheral == CRM_PERI_SPI_4)
	{
		rCRM_PERI_CLK_LPEN |= 0x1 << 23;
	}

	else if(Peripheral == CRM_PERI_I2C_1)
	{
		rCRM_PERI_CLK_LPEN |= 0x1 << 24;
	}

	else if(Peripheral == CRM_PERI_I2C_2)
	{
		rCRM_PERI_CLK_LPEN |= 0x1 << 25;
	}

	else if(Peripheral == CRM_PERI_ADC)
	{
		rCRM_PERI_CLK_LPEN |= 0x1 << 26;
	}

	else if(Peripheral == CRM_PERI_USB)
	{
		rCRM_PERI_CLK_LPEN |= 0x1 << 27;
	}

	else if(Peripheral == CRM_PERI_CAN)
	{
		rCRM_PERI_CLK_LPEN |= 0x1 << 28;
	}

	else if(Peripheral == CRM_PERI_SDIO_SLAVE)
	{
		rCRM_PERI_CLK_LPEN |= 0x1 << 29;
	}

	else
	{
		return CRM_ERROR;
	}


	return CRM_OK;
}
//----------------------------------------------------------------------------------------------
CRM_Result CRM_PeriClockLowPowerDisable(U8 Peripheral)
{
	if(Peripheral == CRM_PERI_DMA)
	{
		rCRM_PERI_CLK_LPEN |= ~(0x1 << 0);
	}

	else if(Peripheral == CRM_PERI_EBI)
	{
		rCRM_PERI_CLK_LPEN |= ~(0x1 << 2);
	}

	else if(Peripheral == CRM_PERI_WATCHDOG)
	{
		rCRM_PERI_CLK_LPEN |= ~(0x1 << 3);
	}

	else if(Peripheral == CRM_PERI_TIMER_1)
	{
		rCRM_PERI_CLK_LPEN |= ~(0x1 << 4);
	}

	else if(Peripheral == CRM_PERI_TIMER_2)
	{
		rCRM_PERI_CLK_LPEN |= ~(0x1 << 5);
	}

	else if(Peripheral == CRM_PERI_GPIO_1)
	{
		rCRM_PERI_CLK_LPEN |= ~(0x1 << 8);
	}

	else if(Peripheral == CRM_PERI_GPIO_2)
	{
		rCRM_PERI_CLK_LPEN |= ~(0x1 << 9);
	}

	else if(Peripheral == CRM_PERI_GPIO_3)
	{
		rCRM_PERI_CLK_LPEN |= ~(0x1 << 10);
	}

	else if(Peripheral == CRM_PERI_GPIO_4)
	{
		rCRM_PERI_CLK_LPEN |= ~(0x1 << 11);
	}

	else if(Peripheral == CRM_PERI_GPIO_5)
	{
		rCRM_PERI_CLK_LPEN |= ~(0x1 << 12);
	}

	else if(Peripheral == CRM_PERI_QSPI)
	{
		rCRM_PERI_CLK_LPEN |= ~(0x1 << 14);
	}

	else if(Peripheral == CRM_PERI_SDMMC)
	{
		rCRM_PERI_CLK_LPEN |= ~(0x1 << 15);
	}

	else if(Peripheral == CRM_PERI_UART_1)
	{
		rCRM_PERI_CLK_LPEN |= ~(0x1 << 16);
	}

	else if(Peripheral == CRM_PERI_UART_2)
	{
		rCRM_PERI_CLK_LPEN |= ~(0x1 << 17);
	}

	else if(Peripheral == CRM_PERI_UART_3)
	{
		rCRM_PERI_CLK_LPEN |= ~(0x1 << 18);
	}

	else if(Peripheral == CRM_PERI_UART_4)
	{
		rCRM_PERI_CLK_LPEN |= ~(0x1 << 19);
	}

	else if(Peripheral == CRM_PERI_SPI_1)
	{
		rCRM_PERI_CLK_LPEN |= ~(0x1 << 20);
	}

	else if(Peripheral == CRM_PERI_SPI_2)
	{
		rCRM_PERI_CLK_LPEN |= ~(0x1 << 21);
	}

	else if(Peripheral == CRM_PERI_SPI_3)
	{
		rCRM_PERI_CLK_LPEN |= ~(0x1 << 22);
	}

	else if(Peripheral == CRM_PERI_SPI_4)
	{
		rCRM_PERI_CLK_LPEN |= ~(0x1 << 23);
	}

	else if(Peripheral == CRM_PERI_I2C_1)
	{
		rCRM_PERI_CLK_LPEN |= ~(0x1 << 24);
	}

	else if(Peripheral == CRM_PERI_I2C_2)
	{
		rCRM_PERI_CLK_LPEN |= ~(0x1 << 25);
	}

	else if(Peripheral == CRM_PERI_ADC)
	{
		rCRM_PERI_CLK_LPEN |= ~(0x1 << 26);
	}

	else if(Peripheral == CRM_PERI_USB)
	{
		rCRM_PERI_CLK_LPEN |= ~(0x1 << 27);
	}

	else if(Peripheral == CRM_PERI_CAN)
	{
		rCRM_PERI_CLK_LPEN |= ~(0x1 << 28);
	}

	else if(Peripheral == CRM_PERI_SDIO_SLAVE)
	{
		rCRM_PERI_CLK_LPEN |= ~(0x1 << 29);
	}

	else
	{
		return CRM_ERROR;
	}


	return CRM_OK;
}
//----------------------------------------------------------------------------------------------
CRM_Result CRM_SecClockRateSet(U32 Rate)	//Rate / 8
{
	U32 Value;

	Value = rCRM_SECU_CLK_RST;

	Value = Value & ~(0x00000007 << 0);	//bit0 ~ 2
	Rate = (Rate & 0x00000007) << 0;
	Value = Value | Rate;

	rCRM_SECU_CLK_RST = Value;

	return CRM_OK;
}
//----------------------------------------------------------------------------------------------
CRM_Result CRM_SecSubSystemClockEnable(void)
{
	rCRM_SECU_CLK_RST |= 0x1 << 4;		//bit4

	return CRM_OK;
}
//----------------------------------------------------------------------------------------------
CRM_Result CRM_SecSubSystemClockDisable(void)
{
	rCRM_SECU_CLK_RST &= ~(0x1 << 4);	//bit4

	return CRM_OK;
}
//----------------------------------------------------------------------------------------------
CRM_Result CRM_SecCounterClockEnable(void)
{
	rCRM_SECU_CLK_RST |= 0x1 << 5;		//bit5

	return CRM_OK;
}
//----------------------------------------------------------------------------------------------
CRM_Result CRM_SecCounterClockDisable(void)
{
	rCRM_SECU_CLK_RST &= ~(0x1 << 5);	//bit5

	return CRM_OK;
}
//----------------------------------------------------------------------------------------------
CRM_Result CRM_AriaClockEnable(void)
{
	rCRM_SECU_CLK_RST |= 0x1 << 6;		//bit6

	return CRM_OK;
}
//----------------------------------------------------------------------------------------------
CRM_Result CRM_AriaClockDisable(void)
{
	rCRM_SECU_CLK_RST &= ~(0x1 << 6);	//bit6

	return CRM_OK;
}
//----------------------------------------------------------------------------------------------
CRM_Result CRM_SecSubSystemClockLowPowerEnable(void)
{
	rCRM_SECU_CLK_RST |= 0x1 << 8;		//bit8

	return CRM_OK;
}
//----------------------------------------------------------------------------------------------
CRM_Result CRM_SecSubSystemClockLowPowerDisable(void)
{
	rCRM_SECU_CLK_RST &= ~(0x1 << 8);	//bit8

	return CRM_OK;
}
//----------------------------------------------------------------------------------------------
CRM_Result CRM_SecSubSystemResetModeSet(U8 Mode)
{
	U32 Value;
	U32 Temp;

	Value = rCRM_SECU_CLK_RST;

	Value = Value & ~(0x00000003 << 12);	//bit12 ~ 13
	Temp = (U32)Mode;
	Temp = (Temp & 0x00000003) << 12;
	Value = Value | Temp;

	rCRM_SECU_CLK_RST = Value;

	return CRM_OK;
}
//----------------------------------------------------------------------------------------------
CRM_Result CRM_SecCounterResetModeSet(U8 Mode)
{
	U32 Value;
	U32 Temp;

	Value = rCRM_SECU_CLK_RST;

	Value = Value & ~(0x00000003 << 14);	//bit14 ~ 15
	Temp = (U32)Mode;
	Temp = (Temp & 0x00000003) << 14;
	Value = Value | Temp;

	rCRM_SECU_CLK_RST = Value;

	return CRM_OK;
}
//----------------------------------------------------------------------------------------------
CRM_Result CRM_SecSubSystemResetSend(U8 Level)
{
	if(Level)
	{
		rCRM_SECU_CLK_RST |= 0x1 << 16;	//bit16
	}

	else
	{
		rCRM_SECU_CLK_RST &= ~(0x1 << 16);
	}


	return CRM_OK;
}
//----------------------------------------------------------------------------------------------
CRM_Result CRM_AriaResetSend(U8 Level)
{
	if(Level)
	{
		rCRM_SECU_CLK_RST |= 0x1 << 18;	//bit18
	}

	else
	{
		rCRM_SECU_CLK_RST &= ~(0x1 << 18);
	}


	return CRM_OK;
}
//----------------------------------------------------------------------------------------------
CRM_Result CRM_SystemResetFlagCheck(U8 *State)
{
	*State = (U8)(rCRM_SYS_RST_STATE & (0x7 << 0));	//bit0 ~ 2

	return CRM_OK;
}
//----------------------------------------------------------------------------------------------
CRM_Result CRM_ResetRecordCheck(U8 Source, U8 *State)
{
	U32 Position;

	Position = (U32)Source;
	Position = Position + 4;

	*State = (U8)(rCRM_SYS_RST_STATE & (0x1 << Position));

	return CRM_OK;
}
//----------------------------------------------------------------------------------------------
CRM_Result CRM_GroupResetModeSet(U8 Mode, U32 Code)
{
	CRM_PreGroupResetModeLockRegisterClear();
	CRM_PreGroupResetModeSet(Mode);
	CRM_PreGroupResetModeLockKeySet();
	CRM_PreGroupResetModeLockCodeSet(Code);
	CRM_PreGroupResetModeLockRegisterApply();

	CRM_PreGroupResetModeLockRegisterClear();
	CRM_PreGroupResetModeSet(Mode);
	CRM_PreGroupResetModeLockKeyClear();
	CRM_PreGroupResetModeLockCodeSet(Code);
	CRM_PreGroupResetModeLockRegisterApply();

	CRM_PreGroupResetModeLockRegisterClear();
	CRM_PreGroupResetModeSet(Mode);
	CRM_PreGroupResetModeLockKeySet();
	CRM_PreGroupResetModeLockCodeSet(Code);
	CRM_PreGroupResetModeLockRegisterApply();

	return CRM_OK;
}
//----------------------------------------------------------------------------------------------
CRM_Result CRM_PreGroupResetModeSet(U8 Mode)
{
	U32 Value;
	U32 Temp;

	Value = GroupResetModeLockRegister;

	Value = Value & ~(0x00000003 << 0);	//bit0 ~ 1
	Temp = (U32)Mode;
	Temp = (Temp & 0x00000003) << 0;
	Value = Value | Temp;

	GroupResetModeLockRegister = Value;

	return CRM_OK;
}
//----------------------------------------------------------------------------------------------
CRM_Result CRM_PreGroupResetModeLockRegisterClear(void)
{
	GroupResetModeLockRegister = 0;

	return CRM_OK;
}
//----------------------------------------------------------------------------------------------
CRM_Result CRM_PreGroupResetModeLockRegisterApply(void)
{
	rCRM_GRP_RST_CTRL = GroupResetModeLockRegister;

	return CRM_OK;
}
//----------------------------------------------------------------------------------------------
CRM_Result CRM_PreGroupResetModeLockCodeSet(U32 Code)
{
	U32 Value;

	Value = GroupResetModeLockRegister & ~(0x3FFF << 2);	//bit2 ~ 15
	Code = Code & 0x00003FFF;
	Value = Value | (Code << 2);
	GroupResetModeLockRegister = Value;

	return CRM_OK;
}
//----------------------------------------------------------------------------------------------
CRM_Result CRM_PreGroupResetModeLockKeySet(void)
{
	GroupResetModeLockRegister |= 1 << 16;		//bit16

	return CRM_OK;
}
//----------------------------------------------------------------------------------------------
CRM_Result CRM_PreGroupResetModeLockKeyClear(void)
{
	GroupResetModeLockRegister &= ~(1 << 16);		//bit16

	return CRM_OK;
}
//----------------------------------------------------------------------------------------------
CRM_Result CRM_GroupResetModeLockKeyCheck(U8 *State)
{
	*State = (U8)((rCRM_GRP_RST_CTRL >> 16) & 0x00000001);	//bit16

	return CRM_OK;
}
//----------------------------------------------------------------------------------------------
CRM_Result CRM_PeriReset(U8 Peripheral)
{
	if(Peripheral == CRM_PERI_DMA)
	{
//		rCRM_PERI_RST |= 0x1 << 0;
		rCRM_PERI_RST = 0x1 << 0;
	}

	else if(Peripheral == CRM_PERI_EBI)
	{
//		rCRM_PERI_RST |= 0x1 << 2;
		rCRM_PERI_RST = 0x1 << 2;
	}

	else if(Peripheral == CRM_PERI_SYSCON)
	{
//		rCRM_PERI_RST |= 0x1 << 3;
		rCRM_PERI_RST = 0x1 << 3;
	}

	else if(Peripheral == CRM_PERI_TIMER_1)
	{
//		rCRM_PERI_RST |= 0x1 << 4;
		rCRM_PERI_RST = 0x1 << 4;
	}

	else if(Peripheral == CRM_PERI_TIMER_2)
	{
//		rCRM_PERI_RST |= 0x1 << 5;
		rCRM_PERI_RST = 0x1 << 5;
	}

	else if(Peripheral == CRM_PERI_GPIO_1)
	{
//		rCRM_PERI_RST |= 0x1 << 8;
		rCRM_PERI_RST = 0x1 << 8;
	}

	else if(Peripheral == CRM_PERI_GPIO_2)
	{
//		rCRM_PERI_RST |= 0x1 << 9;
		rCRM_PERI_RST = 0x1 << 9;
	}

	else if(Peripheral == CRM_PERI_GPIO_3)
	{
//		rCRM_PERI_RST |= 0x1 << 10;
		rCRM_PERI_RST = 0x1 << 10;
	}

	else if(Peripheral == CRM_PERI_GPIO_4)
	{
//		rCRM_PERI_RST |= 0x1 << 11;
		rCRM_PERI_RST = 0x1 << 11;
	}

	else if(Peripheral == CRM_PERI_GPIO_5)
	{
//		rCRM_PERI_RST |= 0x1 << 12;
		rCRM_PERI_RST = 0x1 << 12;
	}

	else if(Peripheral == CRM_PERI_QSPI)
	{
//		rCRM_PERI_RST |= 0x1 << 14;
		rCRM_PERI_RST = 0x1 << 14;
	}

	else if(Peripheral == CRM_PERI_SDMMC)
	{
//		rCRM_PERI_RST |= 0x1 << 15;
		rCRM_PERI_RST = 0x1 << 15;
	}

	else if(Peripheral == CRM_PERI_UART_1)
	{
//		rCRM_PERI_RST |= 0x1 << 16;
		rCRM_PERI_RST = 0x1 << 16;
	}

	else if(Peripheral == CRM_PERI_UART_2)
	{
//		rCRM_PERI_RST |= 0x1 << 17;
		rCRM_PERI_RST = 0x1 << 17;
	}

	else if(Peripheral == CRM_PERI_UART_3)
	{
//		rCRM_PERI_RST |= 0x1 << 18;
		rCRM_PERI_RST = 0x1 << 18;
	}

	else if(Peripheral == CRM_PERI_UART_4)
	{
//		rCRM_PERI_RST |= 0x1 << 19;
		rCRM_PERI_RST = 0x1 << 19;
	}

	else if(Peripheral == CRM_PERI_SPI_1)
	{
//		rCRM_PERI_RST |= 0x1 << 20;
		rCRM_PERI_RST = 0x1 << 20;
	}

	else if(Peripheral == CRM_PERI_SPI_2)
	{
//		rCRM_PERI_RST |= 0x1 << 21;
		rCRM_PERI_RST = 0x1 << 21;
	}

	else if(Peripheral == CRM_PERI_SPI_3)
	{
//		rCRM_PERI_RST |= 0x1 << 22;
		rCRM_PERI_RST = 0x1 << 22;
	}

	else if(Peripheral == CRM_PERI_SPI_4)
	{
//		rCRM_PERI_RST |= 0x1 << 23;
		rCRM_PERI_RST = 0x1 << 23;
	}

	else if(Peripheral == CRM_PERI_I2C_1)
	{
//		rCRM_PERI_RST |= 0x1 << 24;
		rCRM_PERI_RST = 0x1 << 24;
	}

	else if(Peripheral == CRM_PERI_I2C_2)
	{
//		rCRM_PERI_RST |= 0x1 << 25;
		rCRM_PERI_RST = 0x1 << 25;
	}

	else if(Peripheral == CRM_PERI_ADC)
	{
//		rCRM_PERI_RST |= 0x1 << 26;
		rCRM_PERI_RST = 0x1 << 26;
	}

	else if(Peripheral == CRM_PERI_USB)
	{
//		rCRM_PERI_RST |= 0x1 << 27;
		rCRM_PERI_RST = 0x1 << 27;
	}

	else if(Peripheral == CRM_PERI_CAN)
	{
//		rCRM_PERI_RST |= 0x1 << 28;
		rCRM_PERI_RST = 0x1 << 28;
	}

	else if(Peripheral == CRM_PERI_SDIO_SLAVE)
	{
//		rCRM_PERI_RST |= 0x1 << 29;
		rCRM_PERI_RST = 0x1 << 29;
	}

	else
	{
		return CRM_ERROR;
	}


	return CRM_OK;
}
//----------------------------------------------------------------------------------------------
CRM_Result CRM_ClockInitialize(void)
{
	U8 State;

#if (__PRE_FPGA_MODE)

#if (__PRE_FPGA_MODE_IP_TEAM)

#else

	rCRM_OSC_BKP_CTRL = 0;
	rCRM_PLL_CTRL = 0;

	CRM_XtalClockEnable();
	CRM_HsircEnable();
	CRM_RtcEnable();
	CRM_RtcClockEnable();

	CRM_PllSourceSelect(CRM_CLOCK_SOURCE_DEFAULT);
//	CRM_PllSourceSelect(CRM_CLOCK_SOURCE_HS_IRC);
//	CRM_PllSourceSelect(CRM_CLOCK_SOURCE_XTAL);

	CRM_PllEnable();

	State = CRM_ClockReadyCheck(CRM_CLOCK_SOURCE_DEFAULT);
	State = CRM_ClockReadyCheck(CRM_CLOCK_SOURCE_HS_IRC);
	State = CRM_ClockReadyCheck(CRM_CLOCK_SOURCE_XTAL);
	State = CRM_ClockReadyCheck(CRM_CLOCK_SOURCE_PLL);
	State = CRM_ClockReadyCheck(CRM_CLOCK_SOURCE_DIVIDER_A);
	State = CRM_ClockReadyCheck(CRM_CLOCK_SOURCE_DIVIDER_B);
	State = CRM_ClockReadyCheck(CRM_CLOCK_SOURCE_DIVIDER_C);
	State = CRM_ClockReadyCheck(CRM_CLOCK_SOURCE_DIVIDER_D);
	State = CRM_ClockReadyCheck(CRM_CLOCK_SOURCE_DIVIDER_E);

//	CRM_DivaSourceSelect(CRM_CLOCK_SOURCE_DEFAULT);
	CRM_DivaSourceSelect(CRM_CLOCK_SOURCE_HS_IRC);

	CRM_SystemClockSourceSelect(CRM_CLOCK_SOURCE_DEFAULT);
//	CRM_SystemClockSourceSelect(CRM_CLOCK_SOURCE_HS_IRC);
//	CRM_SystemClockSourceSelect(CRM_CLOCK_SOURCE_XTAL);
//	CRM_SystemClockSourceSelect(CRM_CLOCK_SOURCE_PLL);
//	CRM_SystemClockSourceSelect(CRM_CLOCK_SOURCE_DIVIDER_A);
//	CRM_SystemClockSourceSelect(CRM_CLOCK_SOURCE_DIVIDER_B);
//	CRM_SystemClockSourceSelect(CRM_CLOCK_SOURCE_DIVIDER_C);
//	CRM_SystemClockSourceSelect(CRM_CLOCK_SOURCE_DIVIDER_D);
//	CRM_SystemClockSourceSelect(CRM_CLOCK_SOURCE_DIVIDER_E);

//	CRM_PeriClockSelect(CRM_PERI_USB, CRM_CLOCK_SOURCE_DEFAULT);
	CRM_PeriClockSelect(CRM_PERI_USB, CRM_CLOCK_SOURCE_HS_IRC);
//	CRM_PeriClockSelect(CRM_PERI_USB, CRM_CLOCK_SOURCE_XTAL);
//	CRM_PeriClockSelect(CRM_PERI_USB, CRM_CLOCK_SOURCE_PLL);
//	CRM_PeriClockSelect(CRM_PERI_USB, CRM_CLOCK_SOURCE_DIVIDER_A);
//	CRM_PeriClockSelect(CRM_PERI_USB, CRM_CLOCK_SOURCE_DIVIDER_B);
//	CRM_PeriClockSelect(CRM_PERI_USB, CRM_CLOCK_SOURCE_DIVIDER_C);
//	CRM_PeriClockSelect(CRM_PERI_USB, CRM_CLOCK_SOURCE_DIVIDER_D);
//	CRM_PeriClockSelect(CRM_PERI_USB, CRM_CLOCK_SOURCE_DIVIDER_E);

#endif

#else

#endif

	return CRM_OK;
}
//----------------------------------------------------------------------------------------------
CRM_Result CRM_ClockEnable(U8 Position)
{
	if(0xFF == Position)
	{
		rPERI_CLK_EN = 0xFFFFFFFF;
	}

	else
	{
		rPERI_CLK_EN |= (1 << Position);
	}


	return CRM_OK;
}
//----------------------------------------------------------------------------------------------
CRM_Result CRM_ClockDisable(U8 Position)
{
	return CRM_OK;
}
//----------------------------------------------------------------------------------------------
__irq void CRM_IRQHandler(void)
{
}

//----------------------------------------------------------------------------------------------
//	End Of File
//----------------------------------------------------------------------------------------------
