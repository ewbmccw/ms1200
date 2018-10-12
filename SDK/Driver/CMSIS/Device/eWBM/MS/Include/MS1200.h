/**
************************************************************************************************
* @file			MS1200.h
* @author		Solution Team
* @brief		MS1200 header file
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

#ifndef	_MS1200_H_
#define	_MS1200_H_

#include	"SDK_Type.h"

#define STICK_BASE						0xE000E010

#define RTC_BASE						0x4000F000
#define CRM_BASE						0x40001000
#define WDT_BASE						0x40002000

#define GPIO_1_BASE						0x40020000
#define GPIO_2_BASE						0x40021000
#define GPIO_3_BASE						0x40022000
#define GPIO_4_BASE						0x40023000
#define GPIO_5_BASE						0x40024000

#define UART_1_BASE						0x40006000
#define UART_2_BASE						0x40007000
#define UART_3_BASE						0x40016000
#define UART_4_BASE						0x40017000
//----------------------------------------------------------------------------------------------
#define STICK							((REG_STICK *)STICK_BASE)

#define RTC								((REG_RTC *)RTC_BASE)
#define CRM								((REG_CRM *)CRM_BASE)
#define WDT								((REG_WDT *)WDT_BASE)

#define GPIO_1							((REG_GPIO *)GPIO_1_BASE)
#define GPIO_2							((REG_GPIO *)GPIO_2_BASE)
#define GPIO_3							((REG_GPIO *)GPIO_3_BASE)
#define GPIO_4							((REG_GPIO *)GPIO_4_BASE)
#define GPIO_5							((REG_GPIO *)GPIO_5_BASE)

#define UART_1							((REG_UART *)UART_1_BASE)
#define UART_2							((REG_UART *)UART_2_BASE)
#define UART_3							((REG_UART *)UART_3_BASE)
#define UART_4							((REG_UART *)UART_4_BASE)
//----------------------------------------------------------------------------------------------
typedef struct
{
	volatile U32 CSR;					//Control Status Register				address offset: 0x00
	volatile U32 RVR;					//Reload Value Register					address offset: 0x04
	volatile U32 CVR;					//Current Value Register				address offset: 0x08
	volatile U32 CALVR;					//Calibration Value Register			address offset: 0x0C
} STICK_Reg_t;

typedef struct
{
	#define ICR							ISR										//Interrupt Clear Register

	volatile U32 CR;					//Control Register						address offset: 0x00
	volatile U32 SR;					//Status Register						address offset: 0x04
	volatile U32 IER;					//Interrupt Enable Register				address offset: 0x08
	volatile U32 ISR;					//Interrupt Status Register				address offset: 0x0C
	volatile U32 AMR;					//Alarm Mask Register					address offset: 0x10
	volatile U32 RTTCR;					//RT-Timer Counter Register				address offset: 0x14
	volatile U32 CALR;					//Calibration Register					address offset: 0x18
	volatile U32 LR;					//Lock Register							address offset: 0x1C
	volatile U32 TR;					//Time Register							address offset: 0x20
	volatile U32 DR;					//Date Register							address offset: 0x24
	volatile U32 TSTR;					//Time Stamp Time Register				address offset: 0x28
	volatile U32 TSDR;					//Time Stamp Date Register				address offset: 0x2C
	volatile U32 A1TR;					//Alarm 1 Time Register					address offset: 0x30
	volatile U32 A1DR;					//Alarm 1 Date Register					address offset: 0x34
	volatile U32 A2TR;					//Alarm 2 Time Register					address offset: 0x38
	volatile U32 A2DR;					//Alarm 2 Date Register					address offset: 0x3C
	volatile U32 TDCR;					//Tamper Detection Control Register		address offset: 0x40
	volatile U32 RESERVED[14];
	volatile U32 PIDR;					//Peripheral ID Register				address offset: 0x7C
} RTC_Reg_t;

typedef struct
{
	#define CICR						CISR									//Clock Interrupt Clear Register

	volatile U32 CSR;					//Clock Status Register					address offset: 0x00
	volatile U32 CIER;					//Clock Interrupt Enable Register		address offset: 0x04
	volatile U32 CISR;					//Clock Interrupt Status Register		address offset: 0x08 ---> CISR(read), CICR(write)
	volatile U32 CCLR;					//Clock Control Lock Register			address offset: 0x0C
	volatile U32 OBDCR;					//Osc & Backup Domain Control Register	address offset: 0x10
	volatile U32 PLLCR;					//PLL Control Register					address offset: 0x14
	volatile U32 PLLC2R;				//PLL Control 2 Register				address offset: 0x18
	volatile U32 RESERVED1[1];
	volatile U32 DACR;					//Divider A Control Register			address offset: 0x20
	volatile U32 DBCR;					//Divider B Control Register			address offset: 0x24
	volatile U32 DCCR;					//Divider C Control Register			address offset: 0x28
	volatile U32 DDCR;					//Divider D Control Register			address offset: 0x2C
	volatile U32 DECR;					//Divider E Control Register			address offset: 0x30
	volatile U32 RESERVED2[1];
	volatile U32 SCCR;					//System Clock Control Register			address offset: 0x38
	volatile U32 STCCR;					//SysTick Clock Control Register		address offset: 0x3C
	volatile U32 PCS1R;					//Peripheral Clock Select 1 Register	address offset: 0x40
	volatile U32 PCS2R;					//Peripheral Clock Select 2 Register	address offset: 0x44
	volatile U32 PCS3R;					//Peripheral Clock Select 3 Register	address offset: 0x48
	volatile U32 RESERVED3[1];
	volatile U32 PCER;					//Peripheral Clock Enable Register		address offset: 0x50
	volatile U32 RESERVED4[1];
	volatile U32 PCLPER;				//Peri. Clock Low Power Enable Register	address offset: 0x58
	volatile U32 RESERVED5[1];
	volatile U32 SCRCR;					//Security Clock Reset Control Register	address offset: 0x60
	volatile U32 RESERVED6[1];
	volatile U32 SRSR;					//System Reset State Register			address offset: 0x68
	volatile U32 GRSR;					//Group Reset State Register			address offset: 0x6C
	volatile U32 PRR;					//Peripheral Reset Register				address offset: 0x70
	volatile U32 RESERVED7[2];
	volatile U32 PIDR;					//Peripheral ID Register				address offset: 0x7C
} CRM_Reg_t;

typedef struct
{
	volatile U32 CR;					//Control Register						address offset: 0x00
	volatile U32 SR;					//Status Register						address offset: 0x04
	volatile U32 LVR;					//Load Value Register					address offset: 0x08
	volatile U32 EWIVR;					//Early Wakeup Interrupt Value Register	address offset: 0x0C
	volatile U32 WVR;					//Window Value Register					address offset: 0x10
	volatile U32 LR;					//Lock Register							address offset: 0x14
	volatile U32 PID0R;					//Peripheral ID 0 Register				address offset: 0x18
	volatile U32 PID1R;					//Peripheral ID 1 Register				address offset: 0x1C
} WDT_Reg_t;

typedef struct
{
	volatile U32 PMR;					//Port Mode Register					address offset: 0x00
	volatile U32 OMR;					//Output Mode Register					address offset: 0x04
	volatile U32 DR;					//Data Register							address offset: 0x08
	volatile U32 DOR;					//Data Out Register						address offset: 0x0C
	volatile U32 SRR;					//Set Reset Register					address offset: 0x10
	volatile U32 RESERVED1[1];
	volatile U32 ITR;					//Interrupt Type Register				address offset: 0x18
	volatile U32 IPR;					//Interrupt Polarity Register			address offset: 0x1C
	volatile U32 IRSR;					//Interrupt Raw Status Register			address offset: 0x20
	volatile U32 IER;					//Interrupt Enable Register				address offset: 0x24
	volatile U32 ISR;					//Interrupt Status(Clear) Register		address offset: 0x28
	volatile U32 RESERVED2[4];
	volatile U32 PIDR;					//Peripheral ID Register				address offset: 0x3C
} GPIO_Reg_t;

typedef struct
{
	#define THR							RBR										//Transmitter Holding Register
	#define DLL							RBR										//Divisor Latch (LSB) Register
	#define DLM							IER										//Divisor Latch (MSB) Register
	#define FCR							IIR										//FIFO Control Register

	volatile U32 RBR;					//Receiver Buffer Register				address offset: 0x00 ---> RBR(DLAB = 0, read), THR(DLAB = 0, write), DLL(DLAB = 1)
	volatile U32 IER;					//Interrupt Enable Register				address offset: 0x04 ---> IER(DLAB = 0), DLM(DLAB = 1)
	volatile U32 IIR;					//Interrupt Identification Register		address offset: 0x08 ---> IIR(read), FCR(write)
	volatile U32 LCR;					//Line Control Register					address offset: 0x0C
	volatile U32 MCR;					//Modem Control Register				address offset: 0x10
	volatile U32 LSR;					//Line Status Register					address offset: 0x14
	volatile U32 MSR;					//Modem Status Register					address offset: 0x18
	volatile U32 RESERVED1[1];
	volatile U32 LC2R;					//Line Control Register 2				address offset: 0x20
	volatile U32 ICR;					//IrDA Control Register					address offset: 0x24
	volatile U32 FDR;					//Fractional-rate Divider Register		address offset: 0x28
	volatile U32 BTR;					//Bit Timing Register					address offset: 0x2C
	volatile U32 SCR;					//Smart Card Interface Control Register	address offset: 0x30
	volatile U32 RS485CR;				//RS485 Control Register				address offset: 0x34
	volatile U32 RS485AR;				//RS485 Address Match Register			address offset: 0x38
	volatile U32 RESERVED2[13];
	volatile U32 PID0R;					//Peripheral ID0 Register				address offset: 0x70
	volatile U32 PID1R;					//Peripheral ID1 Register				address offset: 0x74
	volatile U32 PID2R;					//Peripheral ID2 Register				address offset: 0x78
	volatile U32 PID3R;					//Peripheral ID3 Register				address offset: 0x7C
} UART_Reg_t;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
typedef U32								STICK_Return;
typedef	U32								RTC_Return;
typedef	U32								CRM_Return;
typedef	U32								WDT_Return;
typedef	U32								GPIO_Return;
typedef	U32								UART_Return;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
typedef STICK_Reg_t						REG_STICK;
typedef RTC_Reg_t						REG_RTC;
typedef CRM_Reg_t						REG_CRM;
typedef WDT_Reg_t						REG_WDT;
typedef GPIO_Reg_t						REG_GPIO;
typedef UART_Reg_t						REG_UART;

#endif

//----------------------------------------------------------------------------------------------
// end of file
//----------------------------------------------------------------------------------------------
