/**
************************************************************************************************
* @file			SysTick.c
* @author		Solution Team
* @brief		SysTick API function file
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

static U32 TickCount;

/**
************************************************************************************************
* @brief		SysTick clock source select function
* @param		U8 : clock source
* @return		STICK_Result
************************************************************************************************
*/
STICK_Result STICK_ClockSourceSelect(U8 source)
{
	if(source == STICK_CLOCK_SRC_EXT_REF_CLOCK)
	{
		HWREG(STICK->CSR) &= ~(STICK_CLOCK_SOURCE);
	}
	else if(source == STICK_CLOCK_SRC_CORE_CLOCK)
	{
		HWREG(STICK->CSR) |= STICK_CLOCK_SOURCE;
	}
	else
	{
		ASSERT(ERROR_PARAM);		//not accept parameter
	}

	return STICK_OK;
}
/**
************************************************************************************************
* @brief		SysTick interrupt enable function
* @return		STICK_Result
************************************************************************************************
*/
STICK_Result STICK_IntEnable(void)
{
	HWREG(STICK->CSR) |= STICK_TICK_INT;

	return STICK_OK;
}
/**
************************************************************************************************
* @brief		SysTick interrupt disable function
* @return		STICK_Result
************************************************************************************************
*/
STICK_Result STICK_IntDisable(void)
{
	HWREG(STICK->CSR) &= ~(STICK_TICK_INT);

	return STICK_OK;
}
/**
************************************************************************************************
* @brief		SysTick enable function
* @return		STICK_Result
************************************************************************************************
*/
STICK_Result STICK_Enable(void)
{
	HWREG(STICK->CSR) |= STICK_ENABLE;

	return STICK_OK;
}
/**
************************************************************************************************
* @brief		SysTick disable function
* @return		STICK_Result
************************************************************************************************
*/
STICK_Result STICK_Disable(void)
{
	HWREG(STICK->CSR) &= ~(STICK_ENABLE);

	return STICK_OK;
}
/**
************************************************************************************************
* @brief		SysTick reload value set function
* @param		U32 : reload value
* @return		STICK_Result
************************************************************************************************
*/
STICK_Result STICK_ReloadValueSet(U32 reload)
{
	HWREG(STICK->RVR) = reload;

	return STICK_OK;
}
/**
************************************************************************************************
* @brief		SysTick current value set function
* @param		U32 : current value
* @return		STICK_Result
************************************************************************************************
*/
STICK_Result STICK_CurrentValueSet(U32 current)
{
	HWREG(STICK->CVR) = current;

	return STICK_OK;
}
/**
************************************************************************************************
* @brief		SysTick tick set function
* @param		U32 : tick value
* @return		STICK_Result
************************************************************************************************
*/
STICK_Result STICK_TickSet(U32 value)
{
	TickCount = value;

	return STICK_OK;
}
/**
************************************************************************************************
* @brief		SysTick tick get function
* @return		STICK_Return(U32)
************************************************************************************************
*/
STICK_Return STICK_TickGet(void)
{
	return TickCount;
}
/**
************************************************************************************************
* @brief		SysTick interrupt handler
************************************************************************************************
*/
__irq void STICK_Handler(void)
{
	TickCount++;

	APP_STICK_CallBack();
}

//----------------------------------------------------------------------------------------------
// end of file
//----------------------------------------------------------------------------------------------
