/**
************************************************************************************************
* @file			SDK_Misc.c
* @author		Solution Team
* @brief		SDK miscellaneous function file
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
* @brief		bit position get function
* @param		U16 : bit position
* @return		U8 : 0 ~ 15
************************************************************************************************
*/
U8 BitPositionGet(U16 bit)
{
	U16 number;

	number = 0;

	while(1)
	{
		if((bit >> number) & 0x0001)
		{
			return number;
		}

		number++;

		if(number > 15)
		{
			ASSERT(ERROR_ABNORMAL);		//abnormal case
		}
	}
}
/**
************************************************************************************************
* @brief		bit position set function
* @param		U8 : number
* @return		U16 : 0x0001 ~ 0x1000
************************************************************************************************
*/
U16 BitPositionSet(U8 number)
{
	if(number > 15)
	{
		ASSERT(ERROR_ABNORMAL);			//abnormal case
	}

	return 1U << number;
}
/**
************************************************************************************************
* @brief		Assert function
************************************************************************************************
*/
void Assert(S8 *exp, S8 *file, U32 line)
{
	HOST_Printf("\t ASSERT(%s) @ %s: %d     \r\n", exp, file, line);
	HOST_Printf("\t HOST - System Halt!     \r\n");

	UART_Printf("\t ASSERT(%s) @ %s: %d     \r\n", exp, file, line);
	UART_Printf("\t UART - System Halt!     \r\n");

	while(1);
}

//----------------------------------------------------------------------------------------------
// end of file
//----------------------------------------------------------------------------------------------
