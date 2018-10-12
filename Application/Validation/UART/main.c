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

static void APP_UartApiTest(void);
static void APP_UartHalApiTest(void);
static void APP_UartTest(void);
static void APP_UartIntTest(void);

static U32 LedBlinkTimer;
static U32 UartTestTimer;

int main(void)
{
	STICK_InitStruct stickInitStruct;

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

	LED_Init();
	KEY_Init();

//	APP_UartApiTest();
//	APP_UartHalApiTest();
	APP_UartTest();
}
//----------------------------------------------------------------------------------------------
static void APP_UartApiTest(void)
{
	U32 status;

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

	while(1);
}
//----------------------------------------------------------------------------------------------
static void APP_UartHalApiTest(void)
{
	UART_InitStruct *uartInitStruct;

	HAL_UART_DeInit(UART_1);

	HAL_UART_StructInit(uartInitStruct);

	uartInitStruct->baud = UART_BAUD_115200;
	uartInitStruct->fracx = 0;
	uartInitStruct->fracy = 0;
	uartInitStruct->triggerLevel = UART_TRIGGER_LEVEL_1;
	uartInitStruct->wordLength = UART_WORD_LENGTH_8BIT;
	uartInitStruct->stopBit = UART_STOP_BIT_1BIT;
	uartInitStruct->parityMode = UART_PARITY_DISABLE;
	uartInitStruct->parityType = UART_PARITY_TYPE_ODD;
	uartInitStruct->stickParityMode = UART_STICK_PARITY_LOGIC_0;
	HAL_UART_Init(UART_1, uartInitStruct);

	HAL_UART_IntEnable(UART_1, UART_INT_DATA_AVAIL | UART_INT_FIFO_EMPTY);
//	HAL_UART_IntEnable(UART_1, UART_INT_DATA_AVAIL);
//	HAL_UART_IntEnable(UART_1, UART_INT_FIFO_EMPTY);

	HAL_UART_IntDisable(UART_1, UART_INT_DATA_AVAIL | UART_INT_FIFO_EMPTY);
//	HAL_UART_IntDisable(UART_1, UART_INT_DATA_AVAIL);
//	HAL_UART_IntDisable(UART_1, UART_INT_FIFO_EMPTY);

	while(1);
}
//----------------------------------------------------------------------------------------------
static void APP_UartTest(void)
{
	U32 count;
	U32 position;

	UART_InitStruct *uartInitStruct;

	HAL_IRQ_Enable(UART_1_IRQn);
	HAL_IRQ_Enable(UART_2_IRQn);
	HAL_IRQ_Enable(UART_3_IRQn);
	HAL_IRQ_Enable(UART_4_IRQn);

	HAL_UART_StructInit(uartInitStruct);

	uartInitStruct->baud = UART_BAUD_115200;
	uartInitStruct->fracx = 2;		//24MHz, 115200bps ---> Refer UART register map formula!
	uartInitStruct->fracy = 10;
	uartInitStruct->triggerLevel = UART_TRIGGER_LEVEL_1;
	uartInitStruct->wordLength = UART_WORD_LENGTH_8BIT;
	uartInitStruct->stopBit = UART_STOP_BIT_1BIT;
	uartInitStruct->parityMode = UART_PARITY_DISABLE;
	uartInitStruct->parityType = UART_PARITY_TYPE_ODD;
	uartInitStruct->stickParityMode = UART_STICK_PARITY_LOGIC_0;
	HAL_UART_Init(UART_1, uartInitStruct);
	HAL_UART_Init(UART_3, uartInitStruct);

	HAL_UART_IntEnable(UART_1, UART_INT_DATA_AVAIL | UART_INT_FIFO_EMPTY);
	HAL_UART_IntEnable(UART_3, UART_INT_DATA_AVAIL | UART_INT_FIFO_EMPTY);

	UartTestTimer = 0;
	position = 0;

	while(1)
	{
		if(UartTestTimer == 0)
		{
			UartTestTimer = 100;

			if(position == 0)
			{
				HAL_UART_PutChar(UART_1, 0x31);
//				HAL_UART_PutChar(UART_2, 0x32);		//IP team bit file not include UART2
//				HAL_UART_PutChar(UART_3, 0x33);

				HAL_UART_PutPrintf("MS1200 UART Testing... %d \r\n", count);

				count++;
			}
		}
	}
}
//----------------------------------------------------------------------------------------------
static void APP_UartIntTest(void)
{
}
//----------------------------------------------------------------------------------------------
void APP_TimerUpdate(void)
{
	if(LedBlinkTimer)
	{
		LedBlinkTimer--;
	}

	if(UartTestTimer)
	{
		UartTestTimer--;
	}
}

//----------------------------------------------------------------------------------------------
// end of file
//----------------------------------------------------------------------------------------------
