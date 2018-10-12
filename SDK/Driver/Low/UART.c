/**
************************************************************************************************
* @file		UART.c
* @author	Solution Team
* @brief	UART API function file
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

/**
************************************************************************************************
* @brief		UART baudrate set function
* @param		REG_UART : UART register base address
* @param		U32 : baudrate
* @return		UART_Result
************************************************************************************************
*/
UART_Result UART_BaudRateSet(REG_UART *UARTx, U32 baud)
{
	U32 value;

	UART_DivisorAccessEnable(UARTx);

	value = CONFIG_UART_CLOCK / (16 * baud);

	HWREG(UARTx->DLL) = value & 0x000000FF;
	HWREG(UARTx->DLM) = (value & 0x0000FF00) >> 8;

	UART_DivisorAccessDisable(UARTx);

	return UART_OK;
}
/**
************************************************************************************************
* @brief		UART TX ready check function
* @param		REG_UART : UART register base address
* @return		UART_Return(U32) : 1 - ready, 0 - not ready
************************************************************************************************
*/
UART_Return UART_TxReadyCheck(REG_UART *UARTx)
{
	U8 status;

	status = HWREG(UARTx->LSR);

	if((status & UART_LINE_STATUS_FIFO_EMPTY) && (status & UART_LINE_STATUS_TRANS_EMPTY))
	{
		return UART_READY;
	}
	else
	{
		return UART_NOT_READY;
	}
}
/**
************************************************************************************************
* @brief		UART RX ready check function
* @param		REG_UART : UART register base address
* @return		UART_Return(U32) : 1 - ready, 0 - not ready
************************************************************************************************
*/
UART_Return UART_RxReadyCheck(REG_UART *UARTx)
{
	U8 status;

	status = HWREG(UARTx->LSR);

	if(status & UART_LINE_STATUS_DATA_READY)
	{
		return UART_READY;
	}
	else
	{
		return UART_NOT_READY;
	}
}
/**
************************************************************************************************
* @brief		UART receive function
* @param		REG_UART : UART register base address
* @return		UART_Return(U32) : receive data
************************************************************************************************
*/
UART_Return UART_Receive(REG_UART *UARTx)
{
	return HWREG(UARTx->RBR);
}
/**
************************************************************************************************
* @brief		UART transmit function
* @param		REG_UART : UART register base address
* @return		UART_Result
************************************************************************************************
*/
UART_Result UART_Transmit(REG_UART *UARTx, U8 data)
{
	HWREG(UARTx->THR) = (U32)data;

	return UART_OK;
}
/**
************************************************************************************************
* @brief		UART interrupt enable function
* @param		REG_UART : UART register base address
* @param		U8 : interrupt
* @return		UART_Result
************************************************************************************************
*/
UART_Result UART_IntEnable(REG_UART *UARTx, U8 interrupt)
{
	HWREG(UARTx->IER) |= (U32)interrupt;

	return UART_OK;
}
/**
************************************************************************************************
* @brief		UART interrupt disable function
* @param		REG_UART : UART register base address
* @param		U8 : interrupt
* @return		UART_Result
************************************************************************************************
*/
UART_Result UART_IntDisable(REG_UART *UARTx, U8 interrupt)
{
	HWREG(UARTx->IER) &= (U32)(~interrupt);

	return UART_OK;
}
/**
************************************************************************************************
* @brief		UART receive FIFO reset function
* @param		REG_UART : UART register base address
* @return		UART_Result
************************************************************************************************
*/
UART_Result UART_ReceiveFifoReset(REG_UART *UARTx)
{
	HWREG(UARTx->FCR) |= 0x1 << 1;		//bit1

	return UART_OK;
}
/**
************************************************************************************************
* @brief		UART transmit FIFO reset function
* @param		REG_UART : UART register base address
* @return		UART_Result
************************************************************************************************
*/
UART_Result UART_TransmitFifoReset(REG_UART *UARTx)
{
	HWREG(UARTx->FCR) |= 0x1 << 2;		//bit2

	return UART_OK;
}
/**
************************************************************************************************
* @brief		UART DMA mode enable function
* @param		REG_UART : UART register base address
* @return		UART_Result
************************************************************************************************
*/
UART_Result UART_DmaModeEnable(REG_UART *UARTx)
{
	HWREG(UARTx->FCR) |= 0x1 << 3;		//bit3

	return UART_OK;
}
/**
************************************************************************************************
* @brief		UART DMA mode disable function
* @param		REG_UART : UART register base address
* @return		UART_Result
************************************************************************************************
*/
UART_Result UART_DmaModeDisable(REG_UART *UARTx)
{
	HWREG(UARTx->FCR) &= ~(0x1 << 3);		//bit3

	return UART_OK;
}
/**
************************************************************************************************
* @brief		UART FIFO trigger level set function
* @param		REG_UART : UART register base address
* @param		U8 : trigger level
* @return		UART_Result
************************************************************************************************
*/
UART_Result UART_ReceiveFifoTriggerLevelSet(REG_UART *UARTx, U8 level)
{
	U32 value;
	U32 temp;

	if(level > UART_TRIGGER_LEVEL_14)
	{
		ASSERT(ERROR_PARAM);						//not accept parameter
	}

	value = HWREG(UARTx->FCR) & ~(0x3 << 6);		//bit6 ~ 7: trigger level
	temp = (U32)level;
	temp = temp & 0x3;
	value |= temp << 6;
	HWREG(UARTx->FCR) = value;

	return UART_OK;
}
/**
************************************************************************************************
* @brief		UART word length set function
* @param		REG_UART : UART register base address
* @param		U8 : word length
* @return		UART_Result
************************************************************************************************
*/
UART_Result UART_WordLengthSet(REG_UART *UARTx, U8 length)
{
	U32 value;
	U32 temp;

	if(length > UART_WORD_LENGTH_8BIT)
	{
		ASSERT(ERROR_PARAM);						//not accept parameter
	}

	value = HWREG(UARTx->LCR) & ~(0x3 << 0);		//bit0 ~ 1: word length
	temp = (U32)length;
	temp = temp & 0x3;
	value |= temp << 0;
	HWREG(UARTx->LCR) = value;

	return UART_OK;
}
/**
************************************************************************************************
* @brief		UART stop bit number set function
* @param		REG_UART : UART register base address
* @param		U8 : stop bit number
* @return		UART_Result
************************************************************************************************
*/
UART_Result UART_StopBitSet(REG_UART *UARTx, U8 stop)
{
	if(stop == UART_STOP_BIT_1BIT)
	{
		HWREG(UARTx->LCR) &= ~(0x1 << 2);		//bit2
	}
	else if(stop == UART_STOP_BIT_2BIT)
	{
		HWREG(UARTx->LCR) |= (0x1 << 2);		//bit2
	}
	else
	{
		ASSERT(ERROR_PARAM);					//not accept parameter
	}

	return UART_OK;
}
/**
************************************************************************************************
* @brief		UART parity set function
* @param		REG_UART : UART register base address
* @param		U8 : enable, disable
* @param		U8 : odd, even
* @param		U8 : stick parity
* @return		UART_Result
************************************************************************************************
*/
UART_Result UART_ParitySet(REG_UART *UARTx, U8 mode, U8 type, U8 stick)
{
	if(mode == UART_PARITY_DISABLE)
	{
		HWREG(UARTx->LCR) &= ~(0x1 << 3);		//bit3
	}
	else if(mode == UART_PARITY_ENABLE)
	{
		HWREG(UARTx->LCR) |= 0x1 << 3;			//bit3
	}
	else
	{
		ASSERT(ERROR_PARAM);					//not accept parameter
	}

	if(type == UART_PARITY_TYPE_ODD)
	{
		HWREG(UARTx->LCR) &= ~(0x1 << 4);		//bit4
	}
	else if(type == UART_PARITY_TYPE_EVEN)
	{
		HWREG(UARTx->LCR) |= 0x1 << 4;			//bit4
	}
	else
	{
		ASSERT(ERROR_PARAM);					//not accept parameter
	}

	if(stick == UART_STICK_PARITY_LOGIC_0)
	{
		HWREG(UARTx->LCR) &= ~(0x1 << 5);		//bit5
	}
	else if(stick == UART_STICK_PARITY_LOGIC_1)
	{
		HWREG(UARTx->LCR) |= 0x1 << 5;			//bit5
	}
	else
	{
		ASSERT(ERROR_PARAM);					//not accept parameter
	}

	return UART_OK;
}
/**
************************************************************************************************
* @brief		UART break enable function
* @param		REG_UART : UART register base address
* @return		UART_Result
************************************************************************************************
*/
UART_Result UART_BreakEnable(REG_UART *UARTx)
{
	HWREG(UARTx->LCR) |= 0x1 << 6;			//bit6

	return UART_OK;
}
/**
************************************************************************************************
* @brief		UART break disable function
* @param		REG_UART : UART register base address
* @return		UART_Result
************************************************************************************************
*/
UART_Result UART_BreakDisable(REG_UART *UARTx)
{
	HWREG(UARTx->LCR) &= ~(0x1 << 6);		//bit6

	return UART_OK;
}
/**
************************************************************************************************
* @brief		UART divisor access enable function
* @param		REG_UART : UART register base address
* @return		UART_Result
************************************************************************************************
*/
UART_Result UART_DivisorAccessEnable(REG_UART *UARTx)
{
	HWREG(UARTx->LCR) |= 0x1 << 7;			//bit7

	return UART_OK;
}
/**
************************************************************************************************
* @brief		UART divisor access disable function
* @param		REG_UART : UART register base address
* @return		UART_Result
************************************************************************************************
*/
UART_Result UART_DivisorAccessDisable(REG_UART *UARTx)
{
	HWREG(UARTx->LCR) &= ~(0x1 << 7);		//bit7

	return UART_OK;
}
/**
************************************************************************************************
* @brief		UART DTR state set function
* @param		REG_UART : UART register base address
* @param		U8 : state
* @return		UART_Result
************************************************************************************************
*/
UART_Result UART_DtrStateSet(REG_UART *UARTx, U8 state)
{
	if(state == UART_DTR_HIGH)
	{
		HWREG(UARTx->MCR) &= ~(0x1 << 0);		//bit0, 0: DTR high
	}
	else if(state == UART_DTR_LOW)
	{
		HWREG(UARTx->MCR) |= 0x1 << 0;
	}
	else
	{
		ASSERT(ERROR_PARAM);					//not accept parameter
	}

	return UART_OK;
}
/**
************************************************************************************************
* @brief		UART RTS state set function
* @param		REG_UART : UART register base address
* @param		U8 : state
* @return		UART_Result
************************************************************************************************
*/
UART_Result UART_RtsStateSet(REG_UART *UARTx, U8 state)
{
	if(state == UART_DTR_HIGH)
	{
		HWREG(UARTx->MCR) &= ~(0x1 << 1);		//bit1, 0: RTS high
	}
	else if(state == UART_DTR_LOW)
	{
		HWREG(UARTx->MCR) |= 0x1 << 1;
	}
	else
	{
		ASSERT(ERROR_PARAM);					//not accept parameter
	}

	return UART_OK;
}
/**
************************************************************************************************
* @brief		UART loopback mode enable function
* @param		REG_UART : UART register base address
* @return		UART_Result
************************************************************************************************
*/
UART_Result UART_LoopBackEnable(REG_UART *UARTx)
{
	HWREG(UARTx->MCR) |= 0x1 << 4;			//bit4

	return UART_OK;
}
/**
************************************************************************************************
* @brief		UART loopback mode disable function
* @param		REG_UART : UART register base address
* @return		UART_Result
************************************************************************************************
*/
UART_Result UART_LoopBackDisable(REG_UART *UARTx)
{
	HWREG(UARTx->MCR) &= ~(0x1 << 4);		//bit4

	return UART_OK;
}
/**
************************************************************************************************
* @brief		UART line status read function
* @param		REG_UART : UART register base address
* @return		UART_Return(U32) : line status
************************************************************************************************
*/
UART_Return UART_LineStatusRead(REG_UART *UARTx)
{
	return HWREG(UARTx->LSR);
}
/**
************************************************************************************************
* @brief		UART modem status read function
* @param		REG_UART : UART register base address
* @return		UART_Return(U32) : modem status
************************************************************************************************
*/
UART_Return UART_ModemStatusRead(REG_UART *UARTx)
{
	return HWREG(UARTx->MSR);
}
/**
************************************************************************************************
* @brief		UART over-sampling mode set function
* @param		REG_UART : UART register base address
* @param		U8 : mode
* @return		UART_Result
************************************************************************************************
*/
UART_Result UART_OverSampleModeSet(REG_UART *UARTx, U8 mode)
{
	if(mode == UART_OVER_SAMPLE_16)
	{
		HWREG(UARTx->LC2R) &= ~(0x1 << 0);		//bit0
	}
	else if(mode == UART_OVER_SAMPLE_8)
	{
		HWREG(UARTx->LC2R) |= 0x1 << 0;			//bit0
	}
	else
	{
		ASSERT(ERROR_PARAM);					//not accept parameter
	}

	return UART_OK;
}
/**
************************************************************************************************
* @brief		UART multi-sampling mode set function
* @param		REG_UART : UART register base address
* @param		U8 : mode
* @return		UART_Result
************************************************************************************************
*/
UART_Result UART_MultiSampleModeSet(REG_UART *UARTx, U8 mode)
{
	if(mode == UART_MULTI_SAMPLE_1)
	{
		HWREG(UARTx->LC2R) &= ~(0x1 << 1);		//bit1
	}
	else if(mode == UART_MULTI_SAMPLE_3)
	{
		HWREG(UARTx->LC2R) |= 0x1 << 1;			//bit1
	}
	else
	{
		ASSERT(ERROR_PARAM);					//not accept parameter
	}

	return UART_OK;
}
/**
************************************************************************************************
* @brief		UART data line mode set function
* @param		REG_UART : UART register base address
* @param		U8 : mode
* @return		UART_Result
************************************************************************************************
*/
UART_Result UART_DataLineModeSet(REG_UART *UARTx, U8 mode)
{
	U32 value;
	U32 temp;

	if(mode > UART_DATA_LINE_HALF_DUPLEX)
	{
		ASSERT(ERROR_PARAM);							//not accept parameter
	}
	else
	{
		value = HWREG(UARTx->LC2R) & ~(0x3 << 2);		//bit2 ~ 3
		temp = (U32)mode;
		temp = temp & 0x3;
		value |= temp << 2;
		HWREG(UARTx->LC2R) = value;
	}

	return UART_OK;
}
/**
************************************************************************************************
* @brief		UART fractional rate set function
* @param		REG_UART : UART register base address
* @param		U8 : numorator x
* @param		U8 : denomiator y
* @return		UART_Result
************************************************************************************************
*/
UART_Result UART_FracRateDividerSet(REG_UART *UARTx, U8 fracx, U8 fracy)
{
	U32 value;
	U32 temp1, temp2;

	UART_DivisorAccessEnable(UARTx);

	temp1 = (U32)(fracx & 0xF);
	temp2 = (U32)(fracy & 0xF);
	value = (temp2 << 4) | temp1;
	HWREG(UARTx->FDR) = value;

	UART_DivisorAccessDisable(UARTx);

	return UART_OK;
}
/**
************************************************************************************************
* @brief		UART bit timing set function
* @param		REG_UART : UART register base address
* @param		U8 : timing value
* @return		UART_Result
************************************************************************************************
*/
UART_Result UART_BitTimingSet(REG_UART *UARTx, U8 timing)
{
	HWREG(UARTx->BTR) = (U32)timing;

	return UART_OK;
}
/**
************************************************************************************************
* @brief		UART delay function
* @param		U32 : delay count
* @return		UART_Result
************************************************************************************************
*/
UART_Result UART_Delay(U32 count)
{
	U32 i;

	for(i = 0; i < count; i++)
	{
	}

	return UART_OK;
}
/**
************************************************************************************************
* @brief		UART 1 interrupt handler
************************************************************************************************
*/
__irq void UART_1_IrqHandler(void)
{
	U32 status;

	status = HWREG(UART_1->IIR);
	status &= 0x0E;
	status = status >> 1;

	APP_UART_1_CallBack(status);
}
/**
************************************************************************************************
* @brief		UART 2 interrupt handler
************************************************************************************************
*/
__irq void UART_2_IrqHandler(void)
{
	U32 status;

	status = HWREG(UART_2->IIR);
	status &= 0x0E;
	status = status >> 1;

	APP_UART_2_CallBack(status);
}
/**
************************************************************************************************
* @brief		UART 3 interrupt handler
************************************************************************************************
*/
__irq void UART_3_IrqHandler(void)
{
	U32 status;

	status = HWREG(UART_3->IIR);
	status &= 0x0E;
	status = status >> 1;

	APP_UART_3_CallBack(status);
}
/**
************************************************************************************************
* @brief		UART 4 interrupt handler
************************************************************************************************
*/
__irq void UART_4_IrqHandler(void)
{
	U32 status;

	status = HWREG(UART_4->IIR);
	status &= 0x0E;
	status = status >> 1;

	APP_UART_4_CallBack(status);
}

//----------------------------------------------------------------------------------------------
// end of file
//----------------------------------------------------------------------------------------------
