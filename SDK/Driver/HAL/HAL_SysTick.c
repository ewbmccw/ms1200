/**
************************************************************************************************
* @file			HAL_SysTick.c
* @author		Solution Team
* @brief		HAL SysTick API function file
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

/**
************************************************************************************************
* @brief		HAL SysTick initialize function
* @param		STICK_InitStruct : SysTick initialize value structure
* @return		STICK_Result
************************************************************************************************
*/
STICK_Result HAL_STICK_Init(STICK_InitStruct *stickStruct)
{
	if(stickStruct->clockSource == STICK_CLOCK_SRC_EXT_REF_CLOCK)
	{
		STICK_ClockSourceSelect(STICK_CLOCK_SRC_EXT_REF_CLOCK);
	}
	else if(stickStruct->clockSource == STICK_CLOCK_SRC_CORE_CLOCK)
	{
		STICK_ClockSourceSelect(STICK_CLOCK_SRC_CORE_CLOCK);
	}
	else
	{
		ASSERT(ERROR_PARAM);		//not accept parameter
	}

	STICK_ReloadValueSet(stickStruct->reload);
	STICK_CurrentValueSet(stickStruct->current);

	return STICK_OK;
}
/**
************************************************************************************************
* @brief		HAL SysTick de-initialize function
* @return		STICK_Result
************************************************************************************************
*/
STICK_Result HAL_STICK_DeInit(void)
{
	STICK_ReloadValueSet(0);
	STICK_CurrentValueSet(0);
	STICK_IntDisable();
	STICK_Disable();

	return STICK_OK;
}
/**
************************************************************************************************
* @brief		HAL SysTick interrupt enable function
* @return		STICK_Result
************************************************************************************************
*/
STICK_Result HAL_STICK_IntEnable(void)
{
	STICK_IntEnable();

	return STICK_OK;
}
/**
************************************************************************************************
* @brief		HAL SysTick interrupt disable function
* @return		STICK_Result
************************************************************************************************
*/
STICK_Result HAL_STICK_IntDisable(void)
{
	STICK_IntDisable();

	return STICK_OK;
}
/**
************************************************************************************************
* @brief		HAL SysTick enable function
* @return		STICK_Result
************************************************************************************************
*/
STICK_Result HAL_STICK_Enable(void)
{
	STICK_Enable();

	return STICK_OK;
}
/**
************************************************************************************************
* @brief		HAL SysTick disable function
* @return		STICK_Result
************************************************************************************************
*/
STICK_Result HAL_STICK_Disable(void)
{
	STICK_Disable();

	return STICK_OK;
}

//----------------------------------------------------------------------------------------------
// end of file
//----------------------------------------------------------------------------------------------
