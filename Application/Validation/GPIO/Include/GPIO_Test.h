/**
************************************************************************************************
* @file		GPIO_Test.h
* @author	Solution Team
* @brief	GPIO test function header file
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

#ifndef	_GPIO_TEST_H_
#define	_GPIO_TEST_H_

extern GPIO_Result GPIO_Test(void);
extern GPIO_Result GPIO_InterruptTest(void);
extern GPIO_Result GPIO_Initialize(void);

extern GPIO_Result GPIO_Delay(U32 Count);

#endif

//----------------------------------------------------------------------------------------------
// end of file
//----------------------------------------------------------------------------------------------
