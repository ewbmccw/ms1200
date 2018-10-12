/**
************************************************************************************************
* @file			UART.h
* @author		Solution Team
* @brief		UART API function header file
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

#ifndef	_UART_H_
#define	_UART_H_

typedef enum
{
	UART_OK = 0,
	UART_ERROR = 1,

	UART_READY = 1,
	UART_NOT_READY = 0
} UART_Result;

typedef enum
{
	UART_BAUD_1200 = 1200,
	UART_BAUD_2400 = 2400,
	UART_BAUD_4800 = 4800,
	UART_BAUD_9600 = 9600,
	UART_BAUD_19200 = 19200,
	UART_BAUD_38400 = 38400,
	UART_BAUD_57600 = 57600,
	UART_BAUD_115200 = 115200,
	UART_BAUD_230400 = 230400,
	UART_BAUD_460800 = 460800,
	UART_BAUD_921600 = 921600
} UART_BaudRate;

typedef enum
{
	UART_INT_DATA_AVAIL = 0x01,
	UART_INT_FIFO_EMPTY = 0x02,
	UART_INT_LINE_STATUS = 0x04,
	UART_INT_MODEM_STATUS = 0x08,
	UART_INT_RECEIVER_ACTIVATION = 0x10,
	UART_INT_ALL = 0x1F
} UART_Interrupt;

typedef enum
{
	UART_INT_ID_MODEM_STATUS = 0x00,
	UART_INT_ID_FIFO_EMPTY = 0x01,
	UART_INT_ID_DATA_AVAIL = 0x02,
	UART_INT_ID_LINE_STATUS = 0x03,
	UART_INT_ID_TIMEOUT = 0x06,
	UART_INT_ID_RECEIVER_ACTIVATION = 0x07
} UART_IntId;

typedef enum
{
	UART_TRIGGER_LEVEL_1 = 0,
	UART_TRIGGER_LEVEL_4,
	UART_TRIGGER_LEVEL_8,
	UART_TRIGGER_LEVEL_14
} UART_TriggerLevel;

typedef enum
{
	UART_WORD_LENGTH_5BIT = 0,
	UART_WORD_LENGTH_6BIT,
	UART_WORD_LENGTH_7BIT,
	UART_WORD_LENGTH_8BIT
} UART_WordLength;

typedef enum
{
	UART_STOP_BIT_1BIT = 0,		//0.5 stop bits (When smart card interface enabled) or 1 stop bit (otherwise)
	UART_STOP_BIT_2BIT			//1.5 stop bits (When 5-bit WLS selected or smard card interface enabled) or 2 stop bits (otherwise)
} UART_StopBit;

typedef enum
{
	UART_PARITY_DISABLE = 0,
	UART_PARITY_ENABLE
} UART_ParityMode;

typedef enum
{
	UART_PARITY_TYPE_ODD = 0,
	UART_PARITY_TYPE_EVEN
} UART_ParityType;

typedef enum
{
	UART_STICK_PARITY_LOGIC_0 = 0,
	UART_STICK_PARITY_LOGIC_1
} UART_StickParityMode;

typedef enum
{
	UART_BREAK_DISABLE = 0,
	UART_BREAK_ENABLE
} UART_BreakMode;

typedef enum
{
	UART_DTR_HIGH = 0,
	UART_DTR_LOW
} UART_DtrState;

typedef enum
{
	UART_RTS_HIGH = 0,
	UART_RTS_LOW
} UART_RtsState;

typedef enum
{
	UART_LINE_STATUS_DATA_READY = 0x01,
	UART_LINE_STATUS_OVERRUN_ERROR = 0x02,
	UART_LINE_STATUS_PARITY_ERROR = 0x04,
	UART_LINE_STATUS_FRAME_ERROR = 0x08,
	UART_LINE_STATUS_BREAK_OCCUR = 0x10,
	UART_LINE_STATUS_FIFO_EMPTY = 0x20,
	UART_LINE_STATUS_TRANS_EMPTY = 0x40,
	UART_LINE_STATUS_RECEIVE_ERROR = 0x80
} UART_LineStatus;

typedef enum
{
	UART_MODEM_STATUS_DELTA_CTS = 0x01,
	UART_MODEM_STATUS_DELTA_DSR = 0x02,
	UART_MODEM_STATUS_RI_LOW_TO_HIGH = 0x04,
	UART_MODEM_STATUS_DELTA_DCD = 0x08,
	UART_MODEM_STATUS_CTS = 0x10,
	UART_MODEM_STATUS_DSR = 0x20,
	UART_MODEM_STATUS_RI = 0x40,
	UART_MODEM_STATUS_DCD = 0x80
} UART_ModemStatus;

typedef enum
{
	UART_OVER_SAMPLE_16 = 0,
	UART_OVER_SAMPLE_8
} UART_OverSampleMode;

typedef enum
{
	UART_MULTI_SAMPLE_1 = 0,
	UART_MULTI_SAMPLE_3				//default
} UART_MultiSampleMode;

typedef enum
{
	UART_DATA_LINE_FULL_DUPLEX = 0,
	UART_DATA_LINE_RECEIVE_ONLY,
	UART_DATA_LINE_TRANSMIT_ONLY,
	UART_DATA_LINE_HALF_DUPLEX
} UART_DataLineMode;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
typedef struct
{
	UART_BaudRate baud;
	U8 fracx;
	U8 fracy;
	UART_TriggerLevel triggerLevel;
	UART_WordLength wordLength;
	UART_StopBit stopBit;
	UART_ParityMode parityMode;		//parity enable/disable
	UART_ParityType parityType;
	UART_StickParityMode stickParityMode;
} UART_InitStruct;
//----------------------------------------------------------------------------------------------
extern UART_Result UART_BaudRateSet(REG_UART *UARTx, U32 baud);
extern UART_Return UART_TxReadyCheck(REG_UART *UARTx);
extern UART_Return UART_RxReadyCheck(REG_UART *UARTx);
extern UART_Return UART_Receive(REG_UART *UARTx);
extern UART_Result UART_Transmit(REG_UART *UARTx, U8 data);
extern UART_Result UART_IntEnable(REG_UART *UARTx, U8 interrupt);
extern UART_Result UART_IntDisable(REG_UART *UARTx, U8 interrupt);
extern UART_Result UART_ReceiveFifoReset(REG_UART *UARTx);
extern UART_Result UART_TransmitFifoReset(REG_UART *UARTx);
extern UART_Result UART_DmaModeEnable(REG_UART *UARTx);
extern UART_Result UART_DmaModeDisable(REG_UART *UARTx);
extern UART_Result UART_ReceiveFifoTriggerLevelSet(REG_UART *UARTx, U8 level);
extern UART_Result UART_WordLengthSet(REG_UART *UARTx, U8 length);
extern UART_Result UART_StopBitSet(REG_UART *UARTx, U8 stop);
extern UART_Result UART_ParitySet(REG_UART *UARTx, U8 mode, U8 type, U8 stick);
extern UART_Result UART_BreakEnable(REG_UART *UARTx);
extern UART_Result UART_BreakDisable(REG_UART *UARTx);
extern UART_Result UART_DivisorAccessEnable(REG_UART *UARTx);		//DLAB = 1
extern UART_Result UART_DivisorAccessDisable(REG_UART *UARTx);		//DLAB = 0
extern UART_Result UART_DtrStateSet(REG_UART *UARTx, U8 state);
extern UART_Result UART_RtsStateSet(REG_UART *UARTx, U8 state);
extern UART_Result UART_LoopBackEnable(REG_UART *UARTx);
extern UART_Result UART_LoopBackDisable(REG_UART *UARTx);
extern UART_Return UART_LineStatusRead(REG_UART *UARTx);
extern UART_Return UART_ModemStatusRead(REG_UART *UARTx);
extern UART_Result UART_OverSampleModeSet(REG_UART *UARTx, U8 mode);
extern UART_Result UART_MultiSampleModeSet(REG_UART *UARTx, U8 mode);
extern UART_Result UART_DataLineModeSet(REG_UART *UARTx, U8 mode);
//extern UART_Result UART_LowPowerEnable(REG_UART *UARTx);
//extern UART_Result UART_LowPowerDisable(REG_UART *UARTx);
//extern UART_Result UART_ExtDirectControlEnable(REG_UART *UARTx);
//extern UART_Result UART_ExtDirectControlDisable(REG_UART *UARTx);
//extern UART_Result UART_ExtDirectControlPinPolaritySet(REG_UART *UARTx, U8 polarity);
extern UART_Result UART_FracRateDividerSet(REG_UART *UARTx, U8 fracx, U8 fracy);
extern UART_Result UART_BitTimingSet(REG_UART *UARTx, U8 timing);

extern UART_Result UART_Delay(U32 count);

#endif

//----------------------------------------------------------------------------------------------
// end of file
//----------------------------------------------------------------------------------------------
