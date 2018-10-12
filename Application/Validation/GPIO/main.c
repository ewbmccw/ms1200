/**
************************************************************************************************
* @file		main.c
* @author	Solution Team
* @brief	main function file
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

#include	"main.h"
#include	"GPIO_Test.h"

void main(void)
{
	GPIO_Test();
//	GPIO_InterruptTest();

	while(1);		//Program Counter will not point here.
}

//----------------------------------------------------------------------------------------------
// end of file
//----------------------------------------------------------------------------------------------
