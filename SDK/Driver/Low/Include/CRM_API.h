/**
************************************************************************************************
* @file			CRM.h
* @author		Solution Team
* @brief		GPIO API function header file
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

#ifndef	_CRM_H_
#define	_CRM_H_

#define CRM_BASE			0x40001000
#define rCRM_CLK_STS			*((volatile U32 *)(CRM_BASE + 0x00000000))
#define rCRM_CLK_INT_EN			*((volatile U32 *)(CRM_BASE + 0x00000004))
#define rCRM_CLK_INT_STS		*((volatile U32 *)(CRM_BASE + 0x00000008))
#define rCRM_CLK_INT_CLR		rCRM_CLK_INT_STS

#define rCRM_CLK_CTRL_LOCK		*((volatile U32 *)(CRM_BASE + 0x0000000C))
#define rCRM_OSC_BKP_CTRL		*((volatile U32 *)(CRM_BASE + 0x00000010))
#define rCRM_PLL_CTRL			*((volatile U32 *)(CRM_BASE + 0x00000014))
#define rCRM_PLL_CTRL2			*((volatile U32 *)(CRM_BASE + 0x00000018))
//#define Reserved			*((volatile U32 *)(CRM_BASE + 0x0000001C))
#define rCRM_DIVA_CTRL			*((volatile U32 *)(CRM_BASE + 0x00000020))
#define rCRM_DIVB_CTRL			*((volatile U32 *)(CRM_BASE + 0x00000024))
#define rCRM_DIVC_CTRL			*((volatile U32 *)(CRM_BASE + 0x00000028))
#define rCRM_DIVD_CTRL			*((volatile U32 *)(CRM_BASE + 0x0000002C))
#define rCRM_DIVE_CTRL			*((volatile U32 *)(CRM_BASE + 0x00000030))
//#define Reserved			*((volatile U32 *)(CRM_BASE + 0x00000034))
#define rCRM_SYS_CLK_CTRL		*((volatile U32 *)(CRM_BASE + 0x00000038))
#define rCRM_ST_CLK_CTRL		*((volatile U32 *)(CRM_BASE + 0x0000003C))
#define rCRM_PERI_CLK_SEL1		*((volatile U32 *)(CRM_BASE + 0x00000040))
#define rCRM_PERI_CLK_SEL2		*((volatile U32 *)(CRM_BASE + 0x00000044))
#define rCRM_PERI_CLK_SEL3		*((volatile U32 *)(CRM_BASE + 0x00000048))
//#define Reserved			*((volatile U32 *)(CRM_BASE + 0x00000050))
#define rCRM_PERI_CLK_EN		*((volatile U32 *)(CRM_BASE + 0x00000050))
//#define Reserved			*((volatile U32 *)(CRM_BASE + 0x00000054))
#define rCRM_PERI_CLK_LPEN		*((volatile U32 *)(CRM_BASE + 0x00000058))
//#define Reserved			*((volatile U32 *)(CRM_BASE + 0x0000005C))
#define rCRM_SECU_CLK_RST		*((volatile U32 *)(CRM_BASE + 0x00000060))
//#define Reserved			*((volatile U32 *)(CRM_BASE + 0x00000064))
#define rCRM_SYS_RST_STATE		*((volatile U32 *)(CRM_BASE + 0x00000068))
#define rCRM_GRP_RST_CTRL		*((volatile U32 *)(CRM_BASE + 0x0000006C))
#define rCRM_PERI_RST			*((volatile U32 *)(CRM_BASE + 0x00000070))

#define rCRM_PERI_ID			*((volatile U32 *)(CRM_BASE + 0x0000007C))
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define CLOCK_RESET_BASE		0x40001000
#define rCLK_STS			*((volatile unsigned int *)(CLOCK_RESET_BASE + 0x00000000))
#define rCLK_INT_EN			*((volatile unsigned int *)(CLOCK_RESET_BASE + 0x00000004))
#define rCLK_INT_STS			*((volatile unsigned int *)(CLOCK_RESET_BASE + 0x00000008))
#define rCLK_INT_CLR			rCLK_INT_STS
//#define				*((volatile unsigned int *)(CLOCK_RESET_BASE + 0x0000000C))

#define rPERI_CLK_EN			*((volatile unsigned int *)(CLOCK_RESET_BASE + 0x00000048))
//----------------------------------------------------------------------------------------------
typedef enum
{
	CRM_OK = 0,
	CRM_ERROR = 1,
	CRM_READY = TRUE,
	CRM_NOT_READY = FALSE
} CRM_Result;

typedef enum
{
	CRM_PERI_DMA = 0x00000001,
	CRM_PERI_EBI = 0x00000004,
	CRM_PERI_SYSCON = 0x00000004,		//CRM_PERI_EBI same position
	CRM_PERI_WATCHDOG = 0x00000008,
	CRM_PERI_TIMER_1 = 0x00000010,
	CRM_PERI_TIMER_2 = 0x00000020,

	CRM_PERI_GPIO_1 = 0x00000100,
	CRM_PERI_GPIO_2 = 0x00000200,
	CRM_PERI_GPIO_3 = 0x00000400,
	CRM_PERI_GPIO_4 = 0x00000800,
	CRM_PERI_GPIO_5 = 0x00001000,

	CRM_PERI_QSPI = 0x00004000,			//SPI flash interface
	CRM_PERI_SDMMC = 0x00008000,		//SDIO master(host)
	CRM_PERI_UART_1 = 0x00010000,
	CRM_PERI_UART_2 = 0x00020000,
	CRM_PERI_UART_3 = 0x00040000,
	CRM_PERI_UART_4 = 0x00080000,

	CRM_PERI_SPI_1 = 0x00100000,
	CRM_PERI_SPI_2 = 0x00200000,
	CRM_PERI_SPI_3 = 0x00400000,
	CRM_PERI_SPI_4 = 0x00800000,
	CRM_PERI_I2C_1 = 0x01000000,
	CRM_PERI_I2C_2 = 0x02000000,
	CRM_PERI_ADC = 0x04000000,
	CRM_PERI_USB = 0x08000000,
	CRM_PERI_CAN = 0x10000000,
	CRM_PERI_SDIO_SLAVE = 0x20000000,
	CRM_PERI_CLOCK_OUT_1 = 0x40000000,
	CRM_PERI_CLOCK_OUT_2 = 0x80000000
} CRM_Peripheral;

typedef enum
{
	CRM_STATUS_XTAL_READY = 0x00000002,
	CRM_STATUS_CLOCK_IN_READY = 0x00000004,

	CRM_STATUS_PLL_LOCK = 0x00000010,
	CRM_STATUS_PLL_UNLOCK = 0x00000020,

	CRM_STATUS_DIVIDER_READY = 0x00000100,

	CRM_STATUS_PERI_CLOCK_READY = 0x00000400,
	CRM_STATUS_PERI_RESET_READY = 0x00000800
	CRM_STATUS_ALL = 0x00000FFF;
} CRM_Status;

typedef enum
{
	CRM_INT_XTAL_READY = 0x00000002,
	CRM_INT_CLOCK_IN_READY = 0x00000004,

	CRM_INT_PLL_LOCK = 0x00000010,
	CRM_INT_PLL_UNLOCK = 0x00000020,

	CRM_INT_DIVIDER_READY = 0x00000100,

	CRM_INT_PERI_CLOCK_READY = 0x00000400,
	CRM_INT_PERI_RESET_READY = 0x00000800
	CRM_INT_ALL = 0x00000FFF;
} CRM_Interrupt;

typedef enum
{
	CRM_CLOCK_SOURCE_DEFAULT = 0,
	CRM_CLOCK_SOURCE_HS_IRC,
	CRM_CLOCK_SOURCE_XTAL,
	CRM_CLOCK_SOURCE_PLL,
	CRM_CLOCK_SOURCE_DIVIDER_A,
	CRM_CLOCK_SOURCE_DIVIDER_B,
	CRM_CLOCK_SOURCE_DIVIDER_C,
	CRM_CLOCK_SOURCE_DIVIDER_D,
	CRM_CLOCK_SOURCE_DIVIDER_E
} CRM_ClockSource;

typedef enum
{
	CRM_CLOCK_SELECT_MODE_GLITCHLESS = 0,
	CRM_CLOCK_SELECT_MODE_ASYNCHRONOUS
} CRM_ClockSelectMode;

typedef enum
{
	CRM_DS_CLOCK_MODE_AUTO_SW_DISABLE = 0,
	CRM_DS_CLOCK_MODE_AUTO_SW_HS_IRC,
	CRM_DS_CLOCK_MODE_AUTO_SW_XTAL,
	CRM_DS_CLOCK_MODE_AUTO_SW_XTAL_DOUBLE
} CRM_DeepSleepClockMode;

typedef enum
{
	CRM_SEC_RESET_MODE_SUB_SYSTEM = 0,
	CRM_SEC_RESET_MODE_SUB_CPU,
	CRM_SEC_RESET_MODE_SYSTEM,
	CRM_SEC_RESET_MODE_CHIP
} CRM_SecurityResetMode;

typedef enum
{
	CRM_SYS_RESET_FLAG_NONE = 0,
	CRM_SYS_RESET_FLAG_CPU,
	CRM_SYS_RESET_FLAG_MASTER_GROUP,
	CRM_SYS_RESET_FLAG_PERI_GROUP,
	CRM_SYS_RESET_FLAG_SYSTEM,
	CRM_SYS_RESET_FLAG_CHIP
} CRM_SystemResetFlag;

typedef enum
{
	CRM_RESET_REC_MAIN_POWER_DOWN = 0x00000010,
	CRM_RESET_REC_BOD = 0x00000020,
	CRM_RESET_REC_EXTERNAL_PIN = 0x00000040,
	CRM_RESET_REC_WAKE_UP = 0x00000080,
	CRM_RESET_REC_WATCHDOG = 0x00000100,
	CRM_RESET_REC_CPU_LOCKUP = 0x00000200,		//If RAM boot mode by JTAG is used, CPU lockup reset is disabled.
	CRM_RESET_REC_TAMPER_DETECT = 0x00000400
} CRM_ResetRecord;

typedef enum
{
	CRM_GROUP_RESET_MODE_CPU = 0,
	CRM_GROUP_RESET_MODE_MASTER,
	CRM_GROUP_RESET_MODE_PERI,
	CRM_GROUP_RESET_MODE_SYSTEM
} CRM_GroupResetMode;
//----------------------------------------------------------------------------------------------
extern CRM_Return CRM_ClockStatusRead(void);
extern CRM_Return CRM_ClockReadyCheck(U32 clock);		//clock: enum CRM_Status
extern CRM_Result CRM_ClockIntEnable(U32 interrupt);
extern CRM_Result CRM_ClockIntDisable(U32 interrupt);
extern CRM_Return CRM_ClockIntStatusRead(void);
extern CRM_Result CRM_ClockIntClear(U32 interrupt);
extern CRM_Result CRM_ClockLock(U32 code);
extern CRM_Result CRM_ClockUnlock(U32 code);
extern CRM_Result CRM_PreClockLockRegisterClear(void);
extern CRM_Result CRM_PreClockLockRegisterApply(void);
extern CRM_Result CRM_PreClockLockEnable(void);
extern CRM_Result CRM_PreClockLockDisable(void);
extern CRM_Result CRM_PreClockLockCodeSet(U32 code);
extern CRM_Result CRM_PreClockLockKeySet(void);
extern CRM_Result CRM_PreClockLockKeyClear(void);
extern CRM_Return CRM_ClockLockKeyCheck(void);
extern CRM_Result CRM_XtalByPassEnable(void);
extern CRM_Result CRM_XtalByPassDisable(void);
extern CRM_Result CRM_RtcEnable(void);					//If enabled once, this cannot be disabled by program.
extern CRM_Result CRM_RtcClockEnable(void);				//If enabled once, this cannot be disabled by program.
extern CRM_Result CRM_BackUpDomainResetSend(U8 level);
extern CRM_Return CRM_BackUpDomainResetStatusCheck(void);
extern CRM_Result CRM_PllSourceSelect(U32 source);
extern CRM_Return CRM_PllUsedCheck(void);
extern CRM_Result CRM_PllEnable(void);
extern CRM_Result CRM_PllDisable(void);
extern CRM_Result CRM_PllByPassEnable(void);
extern CRM_Result CRM_PllByPassDisable(void);
extern CRM_Result CRM_PllReset(void);
extern CRM_Result CRM_PllFeedBackDividerSet(U32 divider);
extern CRM_Result CRM_PllInputDividerSet(U32 divider);
extern CRM_Result CRM_PllOutputDividerSet(U32 divider);
extern CRM_Result CRM_PllLoopFilterAdjustSet(U32 data);
extern CRM_Result CRM_PllFracxSet(U32 fracx);
extern CRM_Result CRM_PllFracySet(U32 fracy);
extern CRM_Result CRM_DivaSourceSelect(U32 source);
extern CRM_Result CRM_DivaSelectModeSet(U8 mode);
extern CRM_Return CRM_DivaUsedCheck(void);
extern CRM_Return CRM_DivaReadyCheck(void);
extern CRM_Result CRM_DivaDividerSet(U32 divider);
extern CRM_Result CRM_DivbSourceSelect(U8 source);
extern CRM_Result CRM_DivbSelectModeSet(U8 mode);
extern CRM_Return CRM_DivbUsedCheck(void);
extern CRM_Return CRM_DivbReadyCheck(void);
extern CRM_Result CRM_DivbDividerSet(U32 divider);
extern CRM_Result CRM_DivbFracxSet(U32 fracx);
extern CRM_Result CRM_DivbFracySet(U32 fracy);
extern CRM_Result CRM_DivcSourceSelect(U8 source);
extern CRM_Result CRM_DivcSelectModeSet(U8 mode);
extern CRM_Return CRM_DivcUsedCheck(void);
extern CRM_Return CRM_DivcReadyCheck(void);
extern CRM_Result CRM_DivcDividerSet(U32 divider);
extern CRM_Result CRM_DivdSourceSelect(U8 source);
extern CRM_Result CRM_DivdSelectModeSet(U8 mode);
extern CRM_Return CRM_DivdUsedCheck(void);
extern CRM_Return CRM_DivdReadyCheck(void);
extern CRM_Result CRM_DivdDividerSet(U32 divider);
extern CRM_Result CRM_DivdFracxSet(U32 fracx);
extern CRM_Result CRM_DivdFracySet(U32 fracy);
extern CRM_Result CRM_DiveSourceSelect(U8 source);
extern CRM_Result CRM_DiveSelectModeSet(U8 mode);
extern CRM_Return CRM_DiveUsedCheck(void);
extern CRM_Return CRM_DiveReadyCheck(void);
extern CRM_Result CRM_DiveDividerSet(U32 divider);
extern CRM_Result CRM_SystemClockSourceSelect(U8 source);
extern CRM_Result CRM_AhbPrescalerSet(U32 prescale);
extern CRM_Result CRM_Apb1PrescalerSet(U32 prescale);
extern CRM_Result CRM_Apb2PrescalerSet(U32 prescale);
extern CRM_Result CRM_AhbLowPowerEnable(void);
extern CRM_Result CRM_AhbLowPowerDisable(void);
extern CRM_Result CRM_Apb1LowPowerEnable(void);
extern CRM_Result CRM_Apb1LowPowerDisable(void);
extern CRM_Result CRM_Apb2LowPowerEnable(void);
extern CRM_Result CRM_Apb2LowPowerDisable(void);
extern CRM_Result CRM_BootRomClockDisable(void);
extern CRM_Result CRM_EflashPrescalerSet(U32 prescale);
extern CRM_Result CRM_DeepSleepWakeUpCountSet(U8 data);			//ccw: appened
extern CRM_Result CRM_DeepSleepClockModeSet(U8 mode);
extern CRM_Result CRM_SystickSourceSelect(U8 source);
extern CRM_Result CRM_SystickRefClockEnable(void);
extern CRM_Result CRM_SystickRefClockDisable(void);
extern CRM_Return CRM_SystickSkewCheck(void);					//ccw: changed
extern CRM_Result CRM_SystickCalibrateValueSet(U32 value);
extern CRM_Result CRM_PeriClockSelect(U8 peripheral, U8 source);
extern CRM_Result CRM_PeriClockEnable(U8 peripheral);
extern CRM_Result CRM_PeriClockDisable(U8 peripheral);
extern CRM_Result CRM_PeriClockLowPowerEnable(U8 peripheral);
extern CRM_Result CRM_PeriClockLowPowerDisable(U8 peripheral);
extern CRM_Result CRM_SecClockRateSet(U32 rate);				//rate / 8
extern CRM_Result CRM_SecSubSystemClockEnable(void);
extern CRM_Result CRM_SecSubSystemClockDisable(void);
extern CRM_Result CRM_SecCounterClockEnable(void);
extern CRM_Result CRM_SecCounterClockDisable(void);
extern CRM_Result CRM_AriaClockEnable(void);
extern CRM_Result CRM_AriaClockDisable(void);
extern CRM_Result CRM_SecSubSystemClockStopEnable(void);		//ccw: changed
extern CRM_Result CRM_SecSubSystemClockStopDisable(void);		//ccw: changed
extern CRM_Result CRM_AriaClockStopEnable(void);				//ccw: appened
extern CRM_Result CRM_AriaClockStopDisable(void);				//ccw: appened
extern CRM_Result CRM_SecSubSystemResetModeSet(U8 mode);
extern CRM_Result CRM_SecCounterResetModeSet(U8 mode);
extern CRM_Result CRM_SecSubSystemResetSend(U8 level);
//extern CRM_Return CRM_SecSubSystemResetStatusCheck(void);		//ccw: appened
extern CRM_Result CRM_AriaResetSend(U8 level);
//extern CRM_Return CRM_AriaResetStatusCheck(void);				//ccw: appened
extern CRM_Return CRM_SystemResetFlagCheck(void);
extern CRM_Return CRM_ResetRecordCheck(U8 source);
extern CRM_Result CRM_GroupResetModeSet(U8 mode, U32 code);
extern CRM_Result CRM_PreGroupResetModeSet(U8 mode);
extern CRM_Result CRM_PreGroupResetModeLockRegisterClear(void);
extern CRM_Result CRM_PreGroupResetModeLockRegisterApply(void);
extern CRM_Result CRM_PreGroupResetModeLockCodeSet(U32 code);
extern CRM_Result CRM_PreGroupResetModeLockKeySet(void);
extern CRM_Result CRM_PreGroupResetModeLockKeyClear(void);
extern CRM_Return CRM_GroupResetModeLockKeyCheck(void);
extern CRM_Result CRM_PeriReset(U8 peripheral);

#endif

//----------------------------------------------------------------------------------------------
//	End Of File
//----------------------------------------------------------------------------------------------
