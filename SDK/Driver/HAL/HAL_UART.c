/**
************************************************************************************************
* @file			HAL_UART.c
* @author		Solution Team
* @brief		HAL UART API function file
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
* @brief		HAL UART initialize value structure default set function
* @param		UART_InitStruct : UART initialize value structure
* @return		UART_Result
************************************************************************************************
*/
UART_Result HAL_UART_StructInit(UART_InitStruct *uartStruct)
{
	uartStruct->baud = UART_BAUD_115200;
	uartStruct->fracx = 0;		//If this value is zero, fractional rate generator will not impact the division value.
	uartStruct->fracy = 0;
	uartStruct->triggerLevel = UART_TRIGGER_LEVEL_1;
	uartStruct->wordLength = UART_WORD_LENGTH_8BIT;
	uartStruct->stopBit = UART_STOP_BIT_1BIT;
	uartStruct->parityMode = UART_PARITY_DISABLE;
	uartStruct->parityType = UART_PARITY_TYPE_ODD;
	uartStruct->stickParityMode = UART_STICK_PARITY_LOGIC_0;

	return UART_OK;
}
/**
************************************************************************************************
* @brief		HAL UART initialize function
* @param		REG_UART : UART register base address
* @param		UART_InitStruct : UART initialize value structure
* @return		UART_Result
************************************************************************************************
*/
UART_Result HAL_UART_Init(REG_UART *UARTx, UART_InitStruct *uartStruct)
{
	UART_BaudRateSet(UARTx, uartStruct->baud);
	UART_FracRateDividerSet(UARTx, uartStruct->fracx, uartStruct->fracy);
	UART_ReceiveFifoTriggerLevelSet(UARTx, uartStruct->triggerLevel);
	UART_WordLengthSet(UARTx, uartStruct->wordLength);
	UART_StopBitSet(UARTx, uartStruct->stopBit);
	UART_ParitySet(UARTx, uartStruct->parityMode, uartStruct->parityType, uartStruct->stickParityMode);

	return UART_OK;
}
/**
************************************************************************************************
* @brief		HAL UART de-initialize function
* @param		REG_UART : UART register base address
* @return		UART_Result
************************************************************************************************
*/
UART_Result HAL_UART_DeInit(REG_UART *UARTx)
{
	return UART_OK;
}
/**
************************************************************************************************
* @brief		HAL UART put character function
* @param		REG_UART : UART register base address
* @param		U8 : character
* @return		UART_Result
************************************************************************************************
*/
UART_Result HAL_UART_PutChar(REG_UART *UARTx, U8 data)
{	if(data == '\n')
	{
		while(!UART_TxReadyCheck(UARTx));

		UART_Transmit(UARTx, '\r');
	}
	else if(data == '\r')
	{
		while(!UART_TxReadyCheck(UARTx));

		UART_Transmit(UARTx, '\n');
	}
	else
	{
		while(!UART_TxReadyCheck(UARTx));

		UART_Transmit(UARTx, data);
	}

	return UART_OK;
}
/**
************************************************************************************************
* @brief		HAL UART get character function
* @param		REG_UART : UART register base address
* @return		UART_Return(U32) : character
************************************************************************************************
*/
UART_Return HAL_UART_GetChar(REG_UART *UARTx)
{
	while(!UART_RxReadyCheck(UARTx));

	return UART_Receive(UARTx);
}
/**
************************************************************************************************
* @brief		HAL UART put string function
* @param		REG_UART : UART register base address
* @param		U8 * : string pointer
* @return		UART_Result
************************************************************************************************
*/
UART_Result HAL_UART_PutString(REG_UART *UARTx, U8 *string)
{
	while(*string)
	{
		HAL_UART_PutChar(UARTx, *string);

		string++;
	}

	return UART_OK;
}
/**
************************************************************************************************
* @brief		HAL UART get string function
* @param		REG_UART : UART register base address
* @param		U8 * : string pointer
* @return		UART_Result
************************************************************************************************
*/
UART_Result HAL_UART_GetString(REG_UART *UARTx, U8 *string)
{
	U8 *stringOri;
	U8 data;
	U32 counter;

	stringOri = string;
	counter = 0;

	while(1)
	{
		data = HAL_UART_GetChar(UARTx);

		if(data == '\r')
		{
			break;
		}

		if(data == '\b')
		{
			if(stringOri < string)
			{
				string--;
				counter--;
			}
		}
		else
		{
			if(counter < CONFIG_UART_MAX_COUNT)
			{
				*string++ = data;
				counter++;
			}
			else
			{
				*string = data;
			}
		}
	}

	return UART_OK;
}
/**
************************************************************************************************
* @brief		HAL UART put printf function
* @param		REG_UART : UART register base address
* @param		const U8 * : string pointer
* @return		UART_Result
************************************************************************************************
*/
UART_Result HAL_UART_PutPrintf(const S8 *fmt, ...)
{
	va_list args;
	U8 buffer[CONFIG_UART_MAX_COUNT];

	memset(buffer, 0x00, sizeof(buffer));

	va_start(args, fmt);
	vsprintf((char *)buffer, (const char *)fmt, args);
	va_end(args);

	HAL_UART_PutString(CONFIG_UART_PRINTF_CHANNEL, buffer);

	return UART_OK;
}
/**
************************************************************************************************
* @brief		HAL UART interrupt enable function
* @param		REG_UART : UART register base address
* @param		U8 : interrupt
* @return		UART_Result
************************************************************************************************
*/
UART_Result HAL_UART_IntEnable(REG_UART *UARTx, U8 interrupt)
{
	UART_IntEnable(UARTx, interrupt);

	return UART_OK;
}
/**
************************************************************************************************
* @brief		HAL UART interrupt disable function
* @param		REG_UART : UART register base address
* @param		U8 : interrupt
* @return		UART_Result
************************************************************************************************
*/
UART_Result HAL_UART_IntDisable(REG_UART *UARTx, U8 interrupt)
{
	UART_IntDisable(UARTx, interrupt);

	return UART_OK;
}
/**
************************************************************************************************
* @brief		HAL UART receive function
* @param		REG_UART : UART register base address
* @return		UART_Return(U32) : character
************************************************************************************************
*/
UART_Return HAL_UART_Receive(REG_UART *UARTx)
{
	return UART_Receive(UARTx);
}

//----------------------------------------------------------------------------------------------
// end of file
//----------------------------------------------------------------------------------------------
