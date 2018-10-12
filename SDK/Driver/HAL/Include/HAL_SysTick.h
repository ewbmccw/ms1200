/**
************************************************************************************************
* @file			HAL_SysTick.h
* @author		Solution Team
* @brief		HAL SysTick API function header file
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

#ifndef	_HAL_SYSTICK_H_
#define	_HAL_SYSTICK_H_

extern STICK_Result HAL_STICK_Init(STICK_InitStruct *stickStruct);
extern STICK_Result HAL_STICK_DeInit(void);
extern STICK_Result HAL_STICK_IntEnable(void);
extern STICK_Result HAL_STICK_IntDisable(void);
extern STICK_Result HAL_STICK_Enable(void);
extern STICK_Result HAL_STICK_Disable(void);

#endif

//----------------------------------------------------------------------------------------------
// end of file
//----------------------------------------------------------------------------------------------
