/**
************************************************************************************************
* @file		HAL_UART.h
* @author	Solution Team
* @brief	HAL UART API function header file
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

#ifndef	_HAL_UART_H_
#define	_HAL_UART_H_

extern UART_Result HAL_UART_StructInit(UART_InitStruct *uartStruct);
extern UART_Result HAL_UART_Init(REG_UART *UARTx, UART_InitStruct *uartStruct);
extern UART_Result HAL_UART_DeInit(REG_UART *UARTx);
extern UART_Result HAL_UART_PutChar(REG_UART *UARTx, U8 data);
extern UART_Return HAL_UART_GetChar(REG_UART *UARTx);
extern UART_Result HAL_UART_PutString(REG_UART *UARTx, U8 *string);
extern UART_Result HAL_UART_GetString(REG_UART *UARTx, U8 *string);
extern UART_Result HAL_UART_PutPrintf(const S8 *fmt, ...);
extern UART_Result HAL_UART_IntEnable(REG_UART *UARTx, U8 interrupt);
extern UART_Result HAL_UART_IntDisable(REG_UART *UARTx, U8 interrupt);

extern UART_Return HAL_UART_Receive(REG_UART *UARTx);

#endif

//----------------------------------------------------------------------------------------------
// end of file
//----------------------------------------------------------------------------------------------
