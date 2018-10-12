/**
************************************************************************************************
* @file			LED.h
* @author		Solution Team
* @brief		LED API function file
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

#include	"LED.h"

static U8 Q_Led1ToggleRequest;
static U8 Q_Led2ToggleRequest;
static U8 Q_Led3ToggleRequest;
static U8 Q_Led4ToggleRequest;
static U8 Q_Led5ToggleRequest;
static U8 Q_Led6ToggleRequest;
static U8 Q_Led7ToggleRequest;
static U8 Q_Led8ToggleRequest;
static U8 Q_Led9ToggleRequest;
static U8 Q_Led10ToggleRequest;
static U8 Q_Led11ToggleRequest;
static U8 Q_Led12ToggleRequest;

LED_Result LED_Init(void)
{
	GPIO_InitStruct gpioStruct;

#if (__PRE_FPGA_MODE)

#if (__PRE_FPGA_MODE_IP_TEAM)

	gpioStruct.pin = GPIO_BIT_0 | GPIO_BIT_1 | GPIO_BIT_2 | GPIO_BIT_3;
	gpioStruct.direction = GPIO_DIRECTION_OUTPUT;
	gpioStruct.outputType = GPIO_OUTPUT_TYPE_PUSH_PULL;
	HAL_GPIO_Init(GPIO_1, &gpioStruct);

	HAL_GPIO_Write(GPIO_1, 0x0000);

#else

#endif

#else

#endif

	return LED_OK;
}
//----------------------------------------------------------------------------------------------
LED_Result LED_DeInit(void)
{
	GPIO_InitStruct gpioStruct;

#if (__PRE_FPGA_MODE)

#if (__PRE_FPGA_MODE_IP_TEAM)

	gpioStruct.pin = GPIO_BIT_0 | GPIO_BIT_1 | GPIO_BIT_2 | GPIO_BIT_3;
	gpioStruct.direction = GPIO_DIRECTION_INPUT;
	gpioStruct.outputType = GPIO_OUTPUT_TYPE_PUSH_PULL;
	HAL_GPIO_Init(GPIO_1, &gpioStruct);

	HAL_GPIO_Write(GPIO_1, 0x0000);

#else

#endif

#else

#endif

	return LED_OK;
}
//----------------------------------------------------------------------------------------------
LED_Result LED_Control(void)
{
	if(Q_Led1ToggleRequest)
	{
		Q_Led1ToggleRequest = 0;

		LED_Toggle(LED_1);
	}

	if(Q_Led2ToggleRequest)
	{
		Q_Led2ToggleRequest = 0;

		LED_Toggle(LED_2);
	}

	if(Q_Led3ToggleRequest)
	{
		Q_Led3ToggleRequest = 0;

		LED_Toggle(LED_3);
	}

	if(Q_Led4ToggleRequest)
	{
		Q_Led4ToggleRequest = 0;

		LED_Toggle(LED_4);
	}

	if(Q_Led5ToggleRequest)
	{
		Q_Led5ToggleRequest = 0;

		LED_Toggle(LED_5);
	}

	if(Q_Led6ToggleRequest)
	{
		Q_Led6ToggleRequest = 0;

		LED_Toggle(LED_6);
	}

	if(Q_Led7ToggleRequest)
	{
		Q_Led7ToggleRequest = 0;

		LED_Toggle(LED_7);
	}

	if(Q_Led8ToggleRequest)
	{
		Q_Led8ToggleRequest = 0;

		LED_Toggle(LED_8);
	}

	if(Q_Led9ToggleRequest)
	{
		Q_Led9ToggleRequest = 0;

		LED_Toggle(LED_9);
	}

	if(Q_Led10ToggleRequest)
	{
		Q_Led10ToggleRequest = 0;

		LED_Toggle(LED_10);
	}

	if(Q_Led11ToggleRequest)
	{
		Q_Led11ToggleRequest = 0;

		LED_Toggle(LED_11);
	}

	if(Q_Led12ToggleRequest)
	{
		Q_Led12ToggleRequest = 0;

		LED_Toggle(LED_12);
	}

	return LED_OK;
}
//----------------------------------------------------------------------------------------------
LED_Result LED_On(U32 number)
{
	U16 bit;

#if (__PRE_FPGA_MODE)

#if (__PRE_FPGA_MODE_IP_TEAM)

	if(number < LED_5)
	{
		bit = BitPositionSet(number);

		HAL_GPIO_BitSet(GPIO_1, bit);
	}

#else

	if(number >= LED_9)
	{
		bit = BitPositionSet(number - 4);		//LED_9 == 8, LED_9: GPIO_5 bit4

		HAL_GPIO_BitSet(GPIO_5, bit);
	}
	else
	{
		bit = BitPositionSet(number);

		HAL_GPIO_BitSet(GPIO_1, bit);
	}

#endif

#else

#endif

	return LED_OK;
}
//----------------------------------------------------------------------------------------------
LED_Result LED_Off(U32 number)
{
	U16 bit;

#if (__PRE_FPGA_MODE)

#if (__PRE_FPGA_MODE_IP_TEAM)

	if(number < LED_5)
	{
		bit = BitPositionSet(number);

		HAL_GPIO_BitClear(GPIO_1, bit);
	}

#else

	if(number > LED_8)
	{
		bit = BitPositionSet(number - 4);		//LED_9 == 8, LED_9: GPIO_5 bit4

		HAL_GPIO_BitClear(GPIO_5, bit);
	}
	else
	{
		bit = BitPositionSet(number);

		HAL_GPIO_BitClear(GPIO_1, bit);
	}

#endif

#else

#endif

	return LED_OK;
}
//----------------------------------------------------------------------------------------------
LED_Result LED_Toggle(U32 number)
{
	U16 bit;

#if (__PRE_FPGA_MODE)

#if (__PRE_FPGA_MODE_IP_TEAM)

	if(number < LED_5)
	{
		bit = BitPositionSet(number);

		HAL_GPIO_BitToggle(GPIO_1, bit);
	}

#else

	if(number > LED_8)
	{
		bit = BitPositionSet(number - 4);		//LED_9 == 8, LED_9: GPIO_5 bit4

		HAL_GPIO_BitToggle(GPIO_5, bit);
	}
	else
	{
		bit = BitPositionSet(number);

		HAL_GPIO_BitToggle(GPIO_1, bit);
	}

#endif

#else

#endif

	return LED_OK;
}
//----------------------------------------------------------------------------------------------
LED_Result LED_ToggleRequestSet(U32 number)
{
	if(number == LED_1)
	{
		Q_Led1ToggleRequest = 1;
	}

	if(number == LED_2)
	{
		Q_Led2ToggleRequest = 1;
	}

	if(number == LED_3)
	{
		Q_Led3ToggleRequest = 1;
	}

	if(number == LED_4)
	{
		Q_Led4ToggleRequest = 1;
	}

	if(number == LED_5)
	{
		Q_Led5ToggleRequest = 1;
	}

	if(number == LED_6)
	{
		Q_Led6ToggleRequest = 1;
	}

	if(number == LED_7)
	{
		Q_Led7ToggleRequest = 1;
	}

	if(number == LED_8)
	{
		Q_Led8ToggleRequest = 1;
	}

	if(number == LED_9)
	{
		Q_Led9ToggleRequest = 1;
	}

	if(number == LED_10)
	{
		Q_Led10ToggleRequest = 1;
	}

	if(number == LED_11)
	{
		Q_Led11ToggleRequest = 1;
	}

	if(number == LED_12)
	{
		Q_Led12ToggleRequest = 1;
	}

	return LED_OK;
}
//----------------------------------------------------------------------------------------------
LED_Result LED_ToggleRequestClear(U32 number)
{
	if(number == LED_1)
	{
		Q_Led1ToggleRequest = 0;
	}

	if(number == LED_2)
	{
		Q_Led2ToggleRequest = 0;
	}

	if(number == LED_3)
	{
		Q_Led3ToggleRequest = 0;
	}

	if(number == LED_4)
	{
		Q_Led4ToggleRequest = 0;
	}

	if(number == LED_5)
	{
		Q_Led5ToggleRequest = 0;
	}

	if(number == LED_6)
	{
		Q_Led6ToggleRequest = 0;
	}

	if(number == LED_7)
	{
		Q_Led7ToggleRequest = 0;
	}

	if(number == LED_8)
	{
		Q_Led8ToggleRequest = 0;
	}

	if(number == LED_9)
	{
		Q_Led9ToggleRequest = 0;
	}

	if(number == LED_10)
	{
		Q_Led10ToggleRequest = 0;
	}

	if(number == LED_11)
	{
		Q_Led11ToggleRequest = 0;
	}

	if(number == LED_12)
	{
		Q_Led12ToggleRequest = 0;
	}

	return LED_OK;
}

//----------------------------------------------------------------------------------------------
// end of file
//----------------------------------------------------------------------------------------------
