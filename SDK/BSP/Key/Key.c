/**
************************************************************************************************
* @file			Key.h
* @author		Solution Team
* @brief		Key API function file
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
#include	"Key.h"

static U8 KeyDataCheck(void);
static void KeyDataResetCommon(void);

static U8 B_KeyPlayIn;
static U8 B_KeyStopIn;
static U8 B_KeyPrevIn;
static U8 B_KeyNextIn;
static U8 B_KeyModeIn;

//static U8 B_KeyInOver1000ms;
static U8 B_KeyInOver500ms;

//static U8 B_KeyCon1000ms;
static U8 B_KeyCon500ms;
static U8 B_KeyCon250ms;
static U8 B_KeyCon100ms;

static U8 B_KeyConti;
static U8 B_KeyOn;

static U8 KeyData;
static U8 KeyDataBack;

static U32 KeyOnDebounceTimer;

static U32 KeyTimer100ms;
static U32 KeyTimer250ms;
static U32 KeyTimer500ms;
static U32 KeyTimer1000ms;

KEY_Result KEY_Init(void)
{
	GPIO_InitStruct gpioStruct;

#if (__PRE_FPGA_MODE)

#if (__PRE_FPGA_MODE_IP_TEAM)

	gpioStruct.pin = GPIO_BIT_8 | GPIO_BIT_9 | GPIO_BIT_10 | GPIO_BIT_11 | GPIO_BIT_12;
	gpioStruct.direction = GPIO_DIRECTION_INPUT;
	gpioStruct.outputType = GPIO_OUTPUT_TYPE_PUSH_PULL;
	HAL_GPIO_Init(GPIO_1, &gpioStruct);

#else

//	SYS_PortModeSet(SYS_PORT_E, SYS_PORT_BIT_8, SYS_PORT_MODE_GPIO);	//key #6
//	SYS_PortModeSet(SYS_PORT_E, SYS_PORT_BIT_9, SYS_PORT_MODE_GPIO);	//key #7
//	SYS_PortModeSet(SYS_PORT_E, SYS_PORT_BIT_10, SYS_PORT_MODE_GPIO);	//key #8
//	SYS_PortModeSet(SYS_PORT_E, SYS_PORT_BIT_11, SYS_PORT_MODE_GPIO);	//key #9

	gpioStruct.pin = GPIO_BIT_8 | GPIO_BIT_9 | GPIO_BIT_10 | GPIO_BIT_11;
	gpioStruct.direction = GPIO_DIRECTION_INPUT;
	gpioStruct.outputType = GPIO_OUTPUT_TYPE_PUSH_PULL;
	HAL_GPIO_Init(GPIO_5, &gpioStruct);

#endif

#else

#endif

	return KEY_OK;
}
//----------------------------------------------------------------------------------------------
KEY_Result KEY_DeInit(void)
{
	return KEY_OK;
}
//----------------------------------------------------------------------------------------------
KEY_Result KEY_Scan(void)
{
	U8 KeyDataTemp;

	KeyDataTemp = KeyDataCheck();

	if(KeyDataTemp == KEY_NULL)
	{
		B_KeyOn = 0;

		KeyDataBack = 0;
		KeyOnDebounceTimer = 0;

		KeyDataResetCommon();

		return KEY_OK;
	}

	if(KeyDataTemp != KeyDataBack)		//new key In
	{
		KeyDataBack = KeyDataTemp;
		KeyOnDebounceTimer = 0;

		KeyDataResetCommon();

		return KEY_OK;
	}
	else if(B_KeyConti)
	{
		if(KeyTimer1000ms >= 1000)		//4ms X 1000 = 1000ms
		{
			KeyTimer1000ms = 0;

//			B_KeyCon1000ms = 1;
		}

		if(KeyTimer500ms >= 500)
		{
			KeyTimer500ms = 0;

			B_KeyCon500ms = 1;
		}

		if(KeyTimer250ms >= 250)
		{
			KeyTimer250ms = 0;

			B_KeyCon250ms = 1;
		}

		if(KeyTimer100ms >= 100)
		{
			KeyTimer100ms = 0;

			B_KeyCon100ms = 1;
		}

		return KEY_OK;
	}

	else if(KeyOnDebounceTimer < 40)
//	else if(KeyOnDebounceTimer < 50)
	{
		return KEY_OK;
	}

	else
	{
		B_KeyConti = 1;
		B_KeyOn = 1;

		KeyData = KeyDataTemp;

		B_KeyCon100ms = 0;
		B_KeyCon250ms = 0;
		B_KeyCon500ms = 0;
//		B_KeyCon1000ms = 0;

		KeyTimer100ms = 0;
		KeyTimer250ms = 0;
		KeyTimer500ms = 0;
		KeyTimer1000ms = 0;

		return KEY_OK;
	}
}
//----------------------------------------------------------------------------------------------
static void KeyPlay(void);
static void KeyStop(void);
static void KeyNext(void);
static void KeyPrev(void);
static void KeyMode(void);

static void LongKeyDataClear(void);

KEY_Result KEY_Process(void)
{
	switch(KeyData)
	{
		case KEY_PLAY:		KeyPlay();	break;
		case KEY_STOP:		KeyStop();	break;
		case KEY_PREV:		KeyPrev();	break;
		case KEY_NEXT:		KeyNext();	break;
		case KEY_MODE:		KeyMode();	break;
	}

	return KEY_OK;
}
//----------------------------------------------------------------------------------------------
KEY_Result KEY_TimerUpdate(void)
{
	KeyOnDebounceTimer++;

	KeyTimer100ms++;

	if(KeyTimer100ms >= 100)
	{
		KeyTimer100ms = 0;

		B_KeyCon100ms = 1;
	}

	KeyTimer250ms++;

	if(KeyTimer250ms >= 250)
	{
		KeyTimer250ms = 0;

		B_KeyCon250ms = 1;
	}

	KeyTimer500ms++;

	if(KeyTimer500ms >= 500)
	{
		KeyTimer500ms = 0;

		B_KeyCon500ms = 1;
	}

	KeyTimer1000ms++;

	if(KeyTimer1000ms >= 1000)
	{
		KeyTimer1000ms = 0;

//		B_KeyCon1000ms = 1;
	}

	return KEY_OK;
}
//----------------------------------------------------------------------------------------------
static void KeyDataResetCommon(void)
{
	B_KeyConti = 0;

	B_KeyCon100ms = 0;
	B_KeyCon250ms = 0;
	B_KeyCon500ms = 0;
//	B_KeyCon1000ms = 0;
}
//----------------------------------------------------------------------------------------------
static U8 KeyDataCheck(void)
{

#if (__PRE_FPGA_MODE)

#if (__PRE_FPGA_MODE_IP_TEAM)

	if(HAL_GPIO_BitRead(GPIO_1, GPIO_BIT_8) == 0)		//key #1
	{
		return KEY_PLAY;
	}

	if(HAL_GPIO_BitRead(GPIO_1, GPIO_BIT_9) == 0)		//key #2
	{
		return KEY_STOP;
	}

	if(HAL_GPIO_BitRead(GPIO_1, GPIO_BIT_10) == 0)		//key #3
	{
		return KEY_PREV;
	}

	if(HAL_GPIO_BitRead(GPIO_1, GPIO_BIT_11) == 0)		//key #4
	{
		return KEY_NEXT;
	}

	if(HAL_GPIO_BitRead(GPIO_1, GPIO_BIT_12) == 0)		//key #5
	{
		return KEY_MODE;
	}

#else

#endif

#else

#endif

	return KEY_NULL;
}
//----------------------------------------------------------------------------------------------
static void OnePlayKey(void);

static void KeyPlay(void)
{
	if(B_KeyPlayIn)
	{
		if(B_KeyConti)
		{
			if(B_KeyInOver500ms)
			{
				if(B_KeyCon100ms)
				{
					B_KeyCon100ms = 0;

					OnePlayKey();
				}
			}
			else
			{
				if(B_KeyCon500ms)
				{
					B_KeyInOver500ms = 1;
					B_KeyCon100ms = 0;

					KeyTimer100ms = 0;

					OnePlayKey();
				}
			}
		}
		else
		{
			if(B_KeyInOver500ms == 0)
			{
				OnePlayKey();
			}

			LongKeyDataClear();
		}

		return;
	}

	if(B_KeyOn == 0)
	{
		return;
	}

	B_KeyOn = 0;

	B_KeyPlayIn = 1;
	B_KeyInOver500ms = 0;

//	KeyTimerClear();
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
static void OnePlayKey(void)
{
	LED_Toggle(LED_1);
}
//----------------------------------------------------------------------------------------------
static void OneStopKey(void);

static void KeyStop(void)
{
	if(B_KeyStopIn)
	{
		if(B_KeyConti)
		{
			if(B_KeyInOver500ms)
			{
				if(B_KeyCon100ms)
				{
					B_KeyCon100ms = 0;

					OneStopKey();
				}
			}
			else
			{
				if(B_KeyCon500ms)
				{
					B_KeyInOver500ms = 1;
					B_KeyCon100ms = 0;

					KeyTimer100ms = 0;

					OneStopKey();
				}
			}
		}
		else
		{
			if(B_KeyInOver500ms == 0)
			{
				OneStopKey();
			}

			LongKeyDataClear();
		}

		return;
	}

	if(B_KeyOn == 0)
	{
		return;
	}

	B_KeyOn = 0;

	B_KeyStopIn = 1;
	B_KeyInOver500ms = 0;

//	KeyTimerClear();
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
static void OneStopKey(void)
{
	LED_Toggle(LED_2);
}
//----------------------------------------------------------------------------------------------
static void OnePrevKey(void);

static void KeyPrev(void)
{
	if(B_KeyPrevIn)
	{
		if(B_KeyConti)
		{
			if(B_KeyInOver500ms)
			{
				if(B_KeyCon250ms)
				{
					B_KeyCon250ms = 0;

					OnePrevKey();
				}
			}
			else
			{
				if(B_KeyCon500ms)
				{
					B_KeyInOver500ms = 1;
					B_KeyCon250ms = 0;

					KeyTimer250ms = 0;

					OnePrevKey();
				}
			}
		}
		else
		{
			if(B_KeyInOver500ms == 0)
			{
				OnePrevKey();
			}

			LongKeyDataClear();
		}

		return;
	}

	if(B_KeyOn == 0)
	{
		return;
	}

	B_KeyOn = 0;

	B_KeyPrevIn = 1;
	B_KeyInOver500ms = 0;

//	KeyTimerClear();
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
static void OnePrevKey(void)
{
	LED_Toggle(LED_3);
}
//----------------------------------------------------------------------------------------------
static void OneNextKey(void);

static void KeyNext(void)
{
	if(B_KeyNextIn)
	{
		if(B_KeyConti)
		{
			if(B_KeyInOver500ms)
			{
				if(B_KeyCon250ms)
				{
					B_KeyCon250ms = 0;

					OneNextKey();
				}
			}
			else
			{
				if(B_KeyCon500ms)
				{
					B_KeyInOver500ms = 1;
					B_KeyCon250ms = 0;

					KeyTimer250ms = 0;

					OneNextKey();
				}
			}
		}
		else
		{
			if(B_KeyInOver500ms == 0)
			{
				OneNextKey();
			}

			LongKeyDataClear();
		}

		return;
	}

	if(B_KeyOn == 0)
	{
		return;
	}

	B_KeyOn = 0;

	B_KeyNextIn = 1;
	B_KeyInOver500ms = 0;

//	KeyTimerClear();
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
static void OneNextKey(void)
{
	LED_Toggle(LED_4);
}
//----------------------------------------------------------------------------------------------
static void OneModeKey(void);

static void KeyMode(void)
{
	if(B_KeyModeIn)
	{
		if(B_KeyConti)
		{
			if(B_KeyInOver500ms)
			{
				if(B_KeyCon250ms)
				{
					B_KeyCon250ms = 0;

					OneModeKey();
				}
			}
			else
			{
				if(B_KeyCon500ms)
				{
					B_KeyInOver500ms = 1;
					B_KeyCon250ms = 0;

					KeyTimer250ms = 0;

					OneModeKey();
				}
			}
		}
		else
		{
			if(B_KeyInOver500ms == 0)
			{
				OneModeKey();
			}

			LongKeyDataClear();
		}

		return;
	}

	if(B_KeyOn == 0)
	{
		return;
	}

	B_KeyOn = 0;

	B_KeyModeIn = 1;
	B_KeyInOver500ms = 0;

//	KeyTimerClear();
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
static void OneModeKey(void)
{
	LED_Toggle(LED_1);
	LED_Toggle(LED_2);
	LED_Toggle(LED_3);
	LED_Toggle(LED_4);
}
//----------------------------------------------------------------------------------------------
static void LongKeyDataClear(void)
{
	B_KeyPlayIn = 0;
	B_KeyStopIn = 0;
	B_KeyNextIn = 0;
	B_KeyPrevIn = 0;
	B_KeyModeIn = 0;

	B_KeyCon100ms = 0;
	B_KeyCon250ms = 0;
	B_KeyCon500ms = 0;
//	B_KeyCon1000ms = 0;

	KeyTimer100ms = 0;
	KeyTimer250ms = 0;
	KeyTimer500ms = 0;
	KeyTimer1000ms = 0;
}

//----------------------------------------------------------------------------------------------
// end of file
//----------------------------------------------------------------------------------------------
