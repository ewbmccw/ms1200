/**
************************************************************************************************
* @file		HAL_WDT.c
* @author	Solution Team
* @brief	HAL Watchdog Timer API function file
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
* @brief		HAL Watchdog Timer initialize value structure default set function
* @param		WDT_InitStruct : Watchdog Timer initialize value structure
* @return		WDT_Result
************************************************************************************************
*/
WDT_Result HAL_WDT_StructInit(WDT_InitStruct *wdtStruct)
{
	wdtStruct->base = 0;
	wdtStruct->loadValue = 0xFFFF;
	wdtStruct->earlyWakeUpValue = 0;
	wdtStruct->earlyWakeUpIntMode = WDT_EARLY_WAKEUP_INT_DISABLE;
	wdtStruct->windowValue = 0;
	wdtStruct->windowMode = WDT_WINDOW_DISABLE;

	return WDT_OK;
}
/**
************************************************************************************************
* @brief		HAL Watchdog Timer initialize function
* @param		WDT_InitStruct : Watchdog Timer initialize value structure
* @return		WDT_Result
************************************************************************************************
*/
WDT_Result HAL_WDT_Init(WDT_InitStruct *wdtStruct)
{
	WDT_TimerBaseSet(wdtStruct->base);
	WDT_LoadValueSet(wdtStruct->loadValue);
	WDT_EarlyWakeUpIntLoadValueSet(wdtStruct->earlyWakeUpValue);

	if(wdtStruct->earlyWakeUpIntMode == WDT_EARLY_WAKEUP_INT_ENABLE)
	{
		WDT_EarlyWakeUpIntEnable();
	}
	else if(wdtStruct->earlyWakeUpIntMode == WDT_EARLY_WAKEUP_INT_DISABLE)
	{
		WDT_EarlyWakeUpIntDisable();
	}
	else
	{
		ASSERT(ERROR_PARAM);		//not accept parameter
	}

	WDT_WindowValueSet(wdtStruct->windowValue);

	if(wdtStruct->windowMode == WDT_WINDOW_ENABLE)
	{
		WDT_WindowEnable();
	}
	else if(wdtStruct->windowMode == WDT_WINDOW_DISABLE)
	{
		WDT_WindowDisable();
	}
	else
	{
		ASSERT(ERROR_PARAM);		//not accept parameter
	}

	return WDT_OK;
}
/**
************************************************************************************************
* @brief		HAL Watchdog Timer de-initialize function
* @return		WDT_Result
************************************************************************************************
*/
WDT_Result HAL_WDT_DeInit(void)
{
	return WDT_OK;
}
/**
************************************************************************************************
* @brief		HAL Watchdog Timer enable function
* @return		WDT_Result
************************************************************************************************
*/
WDT_Result HAL_WDT_Enable(void)
{
	WDT_Enable();

	return WDT_OK;
}
/**
************************************************************************************************
* @brief		HAL Watchdog Timer disable function
* @return		WDT_Result
************************************************************************************************
*/
WDT_Result HAL_WDT_Disable(void)
{
	WDT_Disable();

	return WDT_OK;
}
/**
************************************************************************************************
* @brief		HAL Watchdog Timer refresh function
* @param		U16 : load value
* @return		WDT_Result
************************************************************************************************
*/
WDT_Result HAL_WDT_Refresh(U16 loadValue)
{
	WDT_LoadValueSet(loadValue);

	return WDT_OK;
}

//----------------------------------------------------------------------------------------------
// end of file
//----------------------------------------------------------------------------------------------
