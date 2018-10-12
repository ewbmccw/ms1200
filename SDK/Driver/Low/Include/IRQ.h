/**
************************************************************************************************
* @file		IRQ.h
* @author	Solution Team
* @brief	IRQ API function header file
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

typedef enum
{
	IRQ_OK = 0,
	IRQ_FAIL = 1,
} IRQ_Result;

typedef enum IRQn
{
	NonMaskableInt_IRQn					= -14,
	MemoryManagement_IRQn				= -12,
	BusFault_IRQn						= -11,
	UsageFault_IRQn						= -10,
	SVCall_IRQn							= -5,
	DebugMonitor_IRQn					= -4,
	PendSV_IRQn							= -2,
	SysTick_IRQn						= -1,

	SYS_IRQn							= 0,
	RTC_IRQn							= 1,
	DMA_IRQn							= 2,
	SDIO_IRQn							= 3,
	SDMMC_IRQn							= 4,
	USB_IRQn							= 5,
	USB_DMA_IRQn						= 6,
	EIP_H0_SEC_IRQn						= 7,
	EIP_H0_IRQn							= 8,
	EIP_H1_IRQn							= 9,
	EIP_H2_IRQn							= 10,
	ARIA_IRQn							= 11,
	CRM_IRQn							= 12,
	WDT_IRQn							= 13,
	GPIO_1_IRQn							= 14,
	GPIO_2_IRQn							= 15,
	GPIO_3_IRQn							= 16,
	GPIO_4_IRQn							= 17,
	GPIO_5_IRQn							= 18,
	I2C_1_IRQn							= 19,
	I2C_2_IRQn							= 20,
	SSP_1_IRQn							= 21,
	SSP_2_IRQn							= 22,
	SSP_3_IRQn							= 23,
	SSP_4_IRQn							= 24,
	UART_1_IRQn							= 25,
	UART_2_IRQn							= 26,
	UART_3_IRQn							= 27,
	UART_4_IRQn							= 28,
	TIMER_1_IRQn						= 29,
	TIMER_2_IRQn						= 30,
	CAN_1_IRQn							= 31,
	ADC_IRQn							= 32,
	RESERVED_33_IRQn					= 33,
	RESERVED_34_IRQn					= 34,
	RESERVED_35_IRQn					= 35,
	RESERVED_36_IRQn					= 36,
	RESERVED_37_IRQn					= 37,
	RESERVED_38_IRQn					= 38,
	RESERVED_39_IRQn					= 39,
//	RESERVED_40_IRQn					= 40,
	CAN_2_IRQn							= 40,		//R&D only
	RESERVED_41_IRQn					= 41,
	RESERVED_42_IRQn					= 42,
	RESERVED_43_IRQn					= 43,
	RESERVED_44_IRQn					= 44,
	RESERVED_45_IRQn					= 45,
	RESERVED_46_IRQn					= 46,
	RESERVED_47_IRQn					= 47
} IRQn_Type;
//----------------------------------------------------------------------------------------------
extern IRQ_Result IRQ_Enable(IRQn_Type irqn);
extern IRQ_Result IRQ_Disable(IRQn_Type irqn);

//----------------------------------------------------------------------------------------------
// end of file
//----------------------------------------------------------------------------------------------
