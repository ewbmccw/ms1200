/**
************************************************************************************************
* @file		HAL_GPIO.h
* @author	Solution Team
* @brief	HAL GPIO API function header file
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

#ifndef	_HAL_GPIO_H_
#define	_HAL_GPIO_H_

extern GPIO_Result HAL_GPIO_StructInit(GPIO_InitStruct *gpioStruct);
extern GPIO_Result HAL_GPIO_Init(REG_GPIO *GPIOx, GPIO_InitStruct *gpioStruct);
extern GPIO_Result HAL_GPIO_DeInit(REG_GPIO *GPIOx);
extern GPIO_Return HAL_GPIO_Read(REG_GPIO *GPIOx);
extern GPIO_Return HAL_GPIO_BitRead(REG_GPIO *GPIOx, U16 bit);
extern GPIO_Result HAL_GPIO_Write(REG_GPIO *GPIOx, U16 data);
extern GPIO_Result HAL_GPIO_BitSet(REG_GPIO *GPIOx, U16 bit);
extern GPIO_Result HAL_GPIO_BitClear(REG_GPIO *GPIOx, U16 bit);
extern GPIO_Result HAL_GPIO_BitToggle(REG_GPIO *GPIOx, U16 bit);
extern GPIO_Result HAL_GPIO_IntInit(REG_GPIO *GPIOx, GPIO_IntInitStruct *gpioIntStruct);
extern GPIO_Result HAL_GPIO_IntEnable(REG_GPIO *GPIOx, U16 pin);
extern GPIO_Result HAL_GPIO_IntDisable(REG_GPIO *GPIOx, U16 pin);

#endif

//----------------------------------------------------------------------------------------------
// end of file
//----------------------------------------------------------------------------------------------
