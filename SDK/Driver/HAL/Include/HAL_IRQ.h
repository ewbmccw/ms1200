/**
************************************************************************************************
* @file		HAL_IRQ.h
* @author	Solution Team
* @brief	HAL IRQ API function header file
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

#ifndef	_HAL_IRQ_H_
#define	_HAL_IRQ_H_

extern IRQ_Result HAL_IRQ_Enable(IRQn_Type irqn);
extern IRQ_Result HAL_IRQ_Disable(IRQn_Type irqn);

#endif

//----------------------------------------------------------------------------------------------
// end of file
//----------------------------------------------------------------------------------------------
