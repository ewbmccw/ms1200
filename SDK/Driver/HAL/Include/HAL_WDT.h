/**
************************************************************************************************
* @file		HAL_WDT.h
* @author	Solution Team
* @brief	HAL Watchdog Timer API function header file
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

extern WDT_Result HAL_WDT_StructInit(WDT_InitStruct *wdtStruct);
extern WDT_Result HAL_WDT_Init(WDT_InitStruct *wdtStruct);
extern WDT_Result HAL_WDT_DeInit(void);
extern WDT_Result HAL_WDT_Enable(void);
extern WDT_Result HAL_WDT_Disable(void);
extern WDT_Result HAL_WDT_Refresh(U16 loadValue);

//----------------------------------------------------------------------------------------------
// end of file
//----------------------------------------------------------------------------------------------
