/**
************************************************************************************************
* @file		WDT.c
* @author	Solution Team
* @brief	Watchdog Timer API function file
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
* @brief		Watchdog Timer enable function
* @return		WDT_Result
************************************************************************************************
*/
WDT_Result WDT_Enable(void)
{
	HWREG(WDT->CR) |= 1 << 0;			//bit0

	return WDT_OK;
}
/**
************************************************************************************************
* @brief		Watchdog Timer disable function
* @return		WDT_Result
************************************************************************************************
*/
WDT_Result WDT_Disable(void)
{
	HWREG(WDT->CR) &= ~(1 << 0);		//bit0

	return WDT_OK;
}
/**
************************************************************************************************
* @brief		Watchdog Timer early wakeup interrupt enable function
* @return		WDT_Result
************************************************************************************************
*/
WDT_Result WDT_EarlyWakeUpIntEnable(void)
{
	HWREG(WDT->CR) |= 1 << 1;			//bit1

	return WDT_OK;
}
/**
************************************************************************************************
* @brief		Watchdog Timer early wakeup interrupt disable function
* @return		WDT_Result
************************************************************************************************
*/
WDT_Result WDT_EarlyWakeUpIntDisable(void)
{
	HWREG(WDT->CR) &= ~(1 << 1);		//bit1

	return WDT_OK;
}
/**
************************************************************************************************
* @brief		Watchdog Timer window mode enable function
* @return		WDT_Result
************************************************************************************************
*/
WDT_Result WDT_WindowEnable(void)
{
	HWREG(WDT->CR) |= 1 << 2;		//bit2

	return WDT_OK;
}
/**
************************************************************************************************
* @brief		Watchdog Timer window mode disable function
* @return		WDT_Result
************************************************************************************************
*/
WDT_Result WDT_WindowDisable(void)
{
	HWREG(WDT->CR) &= ~(1 << 2);		//bit2

	return WDT_OK;
}
/**
************************************************************************************************
* @brief		Watchdog Timer test mode enable function
* @return		WDT_Result
************************************************************************************************
*/
WDT_Result WDT_TestModeEnable(void)
{
	HWREG(WDT->CR) |= 1 << 3;			//bit3

	return WDT_OK;
}
/**
************************************************************************************************
* @brief		Watchdog Timer test mode disable function
* @return		WDT_Result
************************************************************************************************
*/
WDT_Result WDT_TestModeDisable(void)
{
	HWREG(WDT->CR) &= ~(1 << 3);		//bit3

	return WDT_OK;
}
/**
************************************************************************************************
* @brief		Watchdog Timer test mode disable function
* @param		U8 : base -> 2^N, N = 0 ~ 12
* @return		WDT_Result
************************************************************************************************
*/
WDT_Result WDT_TimerBaseSet(U8 base)			//2^N, N: 0 ~ 12
{
	U32 value;
	U32 temp;

	if(base > 12)
	{
		ASSERT(ERROR_PARAM);					//not accept parameter
	}

	value = HWREG(WDT->CR) & ~(0xF << 4);		//bit4 ~ 7
	temp = (U32)base;
	value = value | (temp << 4);
	HWREG(WDT->CR) = value;

	return WDT_OK;
}
/**
************************************************************************************************
* @brief		Watchdog Timer early wakeup interrupt status check function
* @return		WDT_Return(U32)
************************************************************************************************
*/
WDT_Return WDT_EarlyWakeUpIntStatusCheck(void)
{
	if(HWREG(WDT->SR) & (0x1 << 0))		//bit0
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
/**
************************************************************************************************
* @brief		Watchdog Timer test mode interrupt status check function
* @return		WDT_Return(U32)
************************************************************************************************
*/
WDT_Return WDT_TestModeIntStatusCheck(void)
{
	if(HWREG(WDT->SR) & (0x1 << 1))		//bit1
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
/**
************************************************************************************************
* @brief		Watchdog Timer count read function
* @return		WDT_Return(U32)
************************************************************************************************
*/
WDT_Return WDT_CountRead(void)
{
	return HWREG(WDT->SR) & 0x0000FFFC;		//bit2 ~ 15 ---> Low 2 bit will not be shown.
}
/**
************************************************************************************************
* @brief		Watchdog Timer load value set function
* @param		U32 : load value
* @return		WDT_Result
************************************************************************************************
*/
WDT_Result WDT_LoadValueSet(U32 value)
{
	HWREG(WDT->LVR) = value;

	return WDT_OK;
}
/**
************************************************************************************************
* @brief		Watchdog Timer early wakeup interrupt value set function
* @param		U32 : load value
* @return		WDT_Result
************************************************************************************************
*/
WDT_Result WDT_EarlyWakeUpIntLoadValueSet(U32 value)
{
	HWREG(WDT->EWIVR) = value;

	return WDT_OK;
}
/**
************************************************************************************************
* @brief		Watchdog Timer window value set function
* @param		U32 : load value
* @return		WDT_Result
************************************************************************************************
*/
WDT_Result WDT_WindowValueSet(U32 value)
{
	HWREG(WDT->WVR) = value;

	return WDT_OK;
}
/**
************************************************************************************************
* @brief		Watchdog Timer lock function
* @param		U32 : code
* @return		WDT_Result
************************************************************************************************
*/
WDT_Result WDT_Lock(U32 code)
{
	WDT_PreLockRegisterClear();
	WDT_PreLockKeySet();
	WDT_PreLockCodeSet(code);
	WDT_PreLockRegisterApply();

	WDT_PreLockRegisterClear();
	WDT_PreLockKeyClear();
	WDT_PreLockCodeSet(code);
	WDT_PreLockRegisterApply();

	WDT_PreLockRegisterClear();
	WDT_PreLockKeySet();
	WDT_PreLockCodeSet(code);
	WDT_PreLockRegisterApply();

	return WDT_OK;
}
/**
************************************************************************************************
* @brief		Watchdog Timer unlock function
* @param		U32 : code
* @return		WDT_Result
************************************************************************************************
*/
WDT_Result WDT_Unlock(U32 code)
{
	WDT_PreLockRegisterClear();
	WDT_PreLockKeyClear();
	WDT_PreLockCodeSet(code);
	WDT_PreLockRegisterApply();

	return WDT_OK;
}
/**
************************************************************************************************
* @brief		Watchdog Timer (pre) lock register variable clear function
* @param		U32 : code
* @return		WDT_Result
************************************************************************************************
*/
WDT_Result WDT_PreLockRegisterClear(void)
{
	LockRegister = 0;

	return WDT_OK;
}
/**
************************************************************************************************
* @brief		Watchdog Timer (pre) lock register apply function
* @param		U32 : code
* @return		WDT_Result
************************************************************************************************
*/
WDT_Result WDT_PreLockRegisterApply(void)
{
	HWREG(WDT->LR) = LockRegister;

	return WDT_OK;
}
/**
************************************************************************************************
* @brief		Watchdog Timer (pre) lock register code set function
* @param		U32 : code
* @return		WDT_Result
************************************************************************************************
*/
WDT_Result WDT_PreLockCodeSet(U32 code)
{
	U32 value;

	value = LockRegister & ~(0x7FFF << 0);		//bit0 ~ 14
	code = code & 0x00007FFF;
	value = value | (code << 0);
	LockRegister = value;

	return WDT_OK;
}
/**
************************************************************************************************
* @brief		Watchdog Timer (pre) lock register key set function
* @return		WDT_Result
************************************************************************************************
*/
WDT_Result WDT_PreLockKeySet(void)
{
	LockRegister |= 1 << 15;		//bit15

	return WDT_OK;
}
/**
************************************************************************************************
* @brief		Watchdog Timer (pre) lock register key clear function
* @return		WDT_Result
************************************************************************************************
*/
WDT_Result WDT_PreLockKeyClear(void)
{
	LockRegister &= ~(1 << 15);		//bit15

	return WDT_OK;
}
/**
************************************************************************************************
* @brief		Watchdog Timer lock state check function
* @return		WDT_Return(U32)
************************************************************************************************
*/
WDT_Return WDT_LockStateCheck(void)
{
	return (HWREG(WDT->LR) >> 15) & 0x00000001;		//bit15
}
/**
************************************************************************************************
* @brief		Watchdog Timer interrupt handler
************************************************************************************************
*/
__irq void WDT_IrqHandler(void)
{
	APP_WDT_CallBack(HWREG(WDT->SR) & 0x00000003);
}

//----------------------------------------------------------------------------------------------
// end of file
//----------------------------------------------------------------------------------------------
