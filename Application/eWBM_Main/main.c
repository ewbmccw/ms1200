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

#if (__FREE_RTOS)
#include	"FreeRTOS.h"
#include	"task.h"
#endif

#if (__FREE_RTOS)
extern BaseType_t xTaskCreate(TaskFunction_t pvTaskCode,
					const char * const pcName,
					unsigned short usStackDepth,
					void *pvParameters,
					UBaseType_t uxPriority,
					TaskHandle_t *pxCreatedTask);
extern void vTaskStartScheduler(void);
extern void vTaskDelay(TickType_t xTicksToDelay);
#endif

static void APP_Led1Toggle(void);
static void APP_Led2Toggle(void);

#if (__FREE_RTOS)
U32 SystemCoreClock = 48000000;
#endif

static U32 LedBlinkTimer;

int main(void)
{
	STICK_InitStruct stickInitStruct;
	GPIO_InitStruct gpioInitStruct;

	U32 state;
	U32 status;

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

	stickInitStruct.clockSource = STICK_CLOCK_SRC_CORE_CLOCK;
	stickInitStruct.reload = STICK_RELOAD;
	stickInitStruct.current = 0;
	HAL_STICK_Init(&stickInitStruct);

	HAL_STICK_IntEnable();
	HAL_STICK_Enable();

#if (0)
	LED_Init();
	KEY_Init();

	xTaskCreate(APP_Led1Toggle, "LED1_TOGGLE", 128, NULL, 0, NULL);
	xTaskCreate(APP_Led2Toggle, "LED2_TOGGLE", 128, NULL, 0, NULL);

	vTaskStartScheduler();

	while(1);
#endif

#if (1)
	LED_Init();

	while(1)
	{
		if(LedBlinkTimer == 0)
		{
			LedBlinkTimer = 500;

			LED_Toggle(LED_1);
			LED_Toggle(LED_2);
			LED_Toggle(LED_3);
			LED_Toggle(LED_4);
		}
	}
#endif

#if (0)
	LED_Init();
	KEY_Init();

	while(1)
	{
		KEY_Scan();
		KEY_Process();
	}
#endif

#if (0)		//GPIO test
#if (0)		//low level API function applied

	GPIO_OutputTypeSet(GPIO_1, GPIO_BIT_0, GPIO_OUTPUT_TYPE_PUSH_PULL);
	GPIO_OutputTypeSet(GPIO_1, GPIO_BIT_1, GPIO_OUTPUT_TYPE_PUSH_PULL);
	GPIO_OutputTypeSet(GPIO_1, GPIO_BIT_2, GPIO_OUTPUT_TYPE_PUSH_PULL);
	GPIO_OutputTypeSet(GPIO_1, GPIO_BIT_3, GPIO_OUTPUT_TYPE_PUSH_PULL);
//	GPIO_OutputTypeSet(GPIO_1, GPIO_BIT_4, 33);		//ccw test - Assert()
	GPIO_OutputEnable(GPIO_1, GPIO_BIT_0);
	GPIO_OutputEnable(GPIO_1, GPIO_BIT_1);
	GPIO_OutputEnable(GPIO_1, GPIO_BIT_2);
	GPIO_OutputEnable(GPIO_1, GPIO_BIT_3);
	GPIO_Write(GPIO_1, 0x0000);
	GPIO_Write(GPIO_1, 0xFFFF);
	GPIO_Write(GPIO_1, 0x0000);
	GPIO_Write(GPIO_1, 0xFFFF);

	while(1)
	{
		if(LedBlinkTimer == 0)
		{
			LedBlinkTimer = 500;

			GPIO_BitToggle(GPIO_1, GPIO_BIT_0);
			GPIO_BitToggle(GPIO_1, GPIO_BIT_1);
			GPIO_BitToggle(GPIO_1, GPIO_BIT_2);
			GPIO_BitToggle(GPIO_1, GPIO_BIT_3);
		}
	}

#else		//HAL API function applied

	gpioInitStruct.pin = GPIO_BIT_0 | GPIO_BIT_1 | GPIO_BIT_2 | GPIO_BIT_3;
	gpioInitStruct.direction = GPIO_DIRECTION_OUTPUT;
	gpioInitStruct.outputType = GPIO_OUTPUT_TYPE_PUSH_PULL;
	HAL_GPIO_Init(GPIO_1, &gpioInitStruct);

	HAL_GPIO_Write(GPIO_1, 0x0000);

	while(1)
	{
		if(LedBlinkTimer == 0)
		{
			LedBlinkTimer = 500;

			HAL_GPIO_BitToggle(GPIO_1, GPIO_BIT_0);
			HAL_GPIO_BitToggle(GPIO_1, GPIO_BIT_1);
			HAL_GPIO_BitToggle(GPIO_1, GPIO_BIT_2);
			HAL_GPIO_BitToggle(GPIO_1, GPIO_BIT_3);
		}
	}

#endif
#endif		//GPIO test

#if (0)		//UART test
#if (1)		//low level API function applied

	UART_DtrStateSet(UART_1, UART_DTR_LOW);
	UART_DtrStateSet(UART_1, UART_DTR_HIGH);

	UART_RtsStateSet(UART_1, UART_RTS_LOW);
	UART_RtsStateSet(UART_1, UART_RTS_HIGH);

	UART_LoopBackEnable(UART_1);
	UART_LoopBackDisable(UART_1);

	status = UART_LineStatusRead(UART_1);

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

	status = UART_ModemStatusRead(UART_1);

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

	UART_OverSampleModeSet(UART_1, UART_OVER_SAMPLE_8);
	UART_OverSampleModeSet(UART_1, UART_OVER_SAMPLE_16);

	UART_MultiSampleModeSet(UART_1, UART_MULTI_SAMPLE_3);
	UART_MultiSampleModeSet(UART_1, UART_MULTI_SAMPLE_1);

	UART_DataLineModeSet(UART_1, UART_DATA_LINE_HALF_DUPLEX);
	UART_DataLineModeSet(UART_1, UART_DATA_LINE_TRANSMIT_ONLY);
	UART_DataLineModeSet(UART_1, UART_DATA_LINE_RECEIVE_ONLY);
	UART_DataLineModeSet(UART_1, UART_DATA_LINE_FULL_DUPLEX);

	UART_FracRateDividerSet(UART_1, 0xF, 0xF);
	UART_FracRateDividerSet(UART_1, 0x0, 0xF);
	UART_FracRateDividerSet(UART_1, 0xF, 0x0);

	UART_BitTimingSet(UART_1, 0xFF);
	UART_BitTimingSet(UART_1, 0x00);

//	IRQ_Enable(UART_1_IRQn)
//	IRQ_Enable(UART_2_IRQn)

	while(1)
	{
	}

#else		//HAL API function applied

#endif
#endif		//UART test

}
//----------------------------------------------------------------------------------------------
static void APP_Led1Toggle(void)
{
	while(1)
	{
		LED_Toggle(LED_1);

#if (__FREE_RTOS)
		vTaskDelay(500);
#endif

	}
}
//----------------------------------------------------------------------------------------------
static void APP_Led2Toggle(void)
{
	while(1)
	{
		LED_Toggle(LED_2);

#if (__FREE_RTOS)
		vTaskDelay(500);
#endif

	}
}
//----------------------------------------------------------------------------------------------
void APP_TimerUpdate(void)
{
	if(LedBlinkTimer)
	{
		LedBlinkTimer--;
	}
}

//----------------------------------------------------------------------------------------------
// end of file
//----------------------------------------------------------------------------------------------
