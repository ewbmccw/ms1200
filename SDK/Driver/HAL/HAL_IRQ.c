/**
************************************************************************************************
* @file		HAL_IRQ.c
* @author	Solution Team
* @brief	HAL IRQ API function file
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
* @brief		HAL IRQ enable function
* @param		IRQn_Type : IRQ number
* @return		IRQ_Result
************************************************************************************************
*/
IRQ_Result HAL_IRQ_Enable(IRQn_Type irqn)
{
	NVIC_ClearPendingIRQ(irqn);
	NVIC_EnableIRQ(irqn);

	return IRQ_OK;
}
/**
************************************************************************************************
* @brief		HAL IRQ enable function
* @param		IRQn_Type : IRQ number
* @return		IRQ_Result
************************************************************************************************
*/
IRQ_Result HAL_IRQ_Disable(IRQn_Type irqn)
{
	NVIC_DisableIRQ(irqn);

	return IRQ_OK;
}

//----------------------------------------------------------------------------------------------
// end of file
//----------------------------------------------------------------------------------------------
