/**
************************************************************************************************
* @file			main.c
* @author		Solution Team
* @brief		main function file
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

#include	"main.h"
#include	"LED.h"
#include	"Key.h"

static void APP_WdtApiTest(void);
static void APP_WdtHalApiTest(void);
static void APP_WdtTest(void);

static U32 LedBlinkTimer;
static U32 WdtTestTimer;

int main(void)
{
	STICK_InitStruct stickStruct;

#if (__PRE_FPGA_MODE)

#if (__PRE_FPGA_MODE_IP_TEAM)

#else

	CRM_HsircEnable();

//	while(!CRM_ClockReadyCheck(CRM_CLOCK_SOURCE_HS_IRC));

//	CRM_SystickSourceSelect(CRM_CLOCK_SOURCE_DEFAULT);
	CRM_SystickSourceSelect(CRM_CLOCK_SOURCE_HS_IRC);		//previous applying
//	CRM_SystickSourceSelect(CRM_CLOCK_SOURCE_XTAL);
//	CRM_SystickSourceSelect(CRM_CLOCK_SOURCE_PLL);
//	CRM_SystickSourceSelect(CRM_CLOCK_SOURCE_DIVIDER_A);
//	CRM_SystickSourceSelect(CRM_CLOCK_SOURCE_DIVIDER_B);
//	CRM_SystickSourceSelect(CRM_CLOCK_SOURCE_DIVIDER_C);
//	CRM_SystickSourceSelect(CRM_CLOCK_SOURCE_DIVIDER_D);
//	CRM_SystickSourceSelect(CRM_CLOCK_SOURCE_DIVIDER_E);

#endif

#else

#endif

	stickStruct.clockSource = STICK_CLOCK_SRC_CORE_CLOCK;
	stickStruct.reload = STICK_RELOAD;
	stickStruct.current = 0;
	HAL_STICK_Init(&stickStruct);

	HAL_STICK_IntEnable();
	HAL_STICK_Enable();

	LED_Init();
	KEY_Init();

//	APP_WdtApiTest();
	APP_WdtHalApiTest();
//	APP_WdtTest();
}
//----------------------------------------------------------------------------------------------
static void APP_WdtApiTest(void)
{
	U8 base;
	U32 code;
	U32 status;
	U32 count;
	U32 value;
	U32 state;

	WDT_EarlyWakeUpIntDisable();
	WDT_EarlyWakeUpIntEnable();

	WDT_WindowDisable();
	WDT_WindowEnable();

	WDT_TestModeDisable();
	WDT_TestModeEnable();

	code = 0x0000;

//	WDT_Lock(code);
	WDT_Unlock(code);

//	WDT_Disable();
//	WDT_Enable();

	WDT_EarlyWakeUpIntEnable();
	WDT_EarlyWakeUpIntDisable();

	WDT_WindowDisable();
	WDT_WindowEnable();

	WDT_TestModeDisable();
	WDT_TestModeEnable();

	base = 12;

	WDT_TimerBaseSet(base);

	status = WDT_EarlyWakeUpIntStatusCheck();

	if(status)
	{
		__asm("nop");
		__asm("nop");
	}
	else
	{
		__asm("nop");
		__asm("nop");
	}

	status = WDT_TestModeIntStatusCheck();

	if(status)
	{
		__asm("nop");
		__asm("nop");
	}
	else
	{
		__asm("nop");
		__asm("nop");
	}

	count = WDT_CountRead();

	if(count)
	{
		__asm("nop");
		__asm("nop");
	}
	else
	{
		__asm("nop");
		__asm("nop");
	}

	value = 0xFFFF;

	WDT_LoadValueSet(value);
	WDT_EarlyWakeUpIntLoadValueSet(value);
	WDT_WindowValueSet(value);

	state = WDT_LockStateCheck();

	if(state)
	{
		__asm("nop");
		__asm("nop");
	}
	else
	{
		__asm("nop");
		__asm("nop");
	}

	while(1);
}
//----------------------------------------------------------------------------------------------
static void APP_WdtHalApiTest(void)
{
	WDT_InitStruct *wdtStruct;

	HAL_IRQ_Enable(WDT_IRQn);

	HAL_WDT_Disable();

	HAL_WDT_StructInit(wdtStruct);

	wdtStruct->base = 12;
	wdtStruct->loadValue = 0x8000;
	wdtStruct->earlyWakeUpValue = 0x4000;
	wdtStruct->earlyWakeUpIntMode = WDT_EARLY_WAKEUP_INT_ENABLE;
	wdtStruct->windowValue = 0;
	wdtStruct->windowMode = WDT_WINDOW_DISABLE;
	HAL_WDT_Init(wdtStruct);

	HAL_WDT_Enable();

	WdtTestTimer = 100;

	while(1)
	{
		if(WdtTestTimer == 0)
		{
			WdtTestTimer = 100;

//			HAL_WDT_Refresh(0x8000);
		}
	}
}
//----------------------------------------------------------------------------------------------
static void APP_WdtTest(void)
{
	while(1);
}
//----------------------------------------------------------------------------------------------
void APP_TimerUpdate(void)
{
	if(LedBlinkTimer)
	{
		LedBlinkTimer--;
	}

	if(WdtTestTimer)
	{
		WdtTestTimer--;
	}
}

//----------------------------------------------------------------------------------------------
// end of file
//----------------------------------------------------------------------------------------------
