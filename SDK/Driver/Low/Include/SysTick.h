/**
************************************************************************************************
* @file			SysTick.h
* @author		Solution Team
* @brief		SysTick API function header file
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

#ifndef	_SYSTICK_H_
#define	_SYSTICK_H_

typedef struct
{
	U8 clockSource;
	U32 reload;
	U32 current;
} STICK_InitStruct;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
typedef enum
{
	STICK_CLOCK_SRC_EXT_REF_CLOCK = 0,
	STICK_CLOCK_SRC_CORE_CLOCK
} STICK_ClockSource;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define STICK_COUNT_FLAG					(1U << 16)
#define STICK_CLOCK_SOURCE					(1U << 2)
#define STICK_TICK_INT						(1U << 1)
#define STICK_ENABLE						(1U << 0)

#if (__PRE_FPGA_MODE)

#if (__PRE_FPGA_MODE_IP_TEAM)

//#define STICK_RELOAD						5998		//6MHz(166.7ns) X 5998 = About 1ms
//#define STICK_RELOAD						23980		//24MHz(41.7ns) X 23980 = About 1ms
//#define STICK_RELOAD						25000		//25MHz(40ns) X 25000 = About 1ms
#define STICK_RELOAD						48076		//48MHz(20.8ns) X 48076 = About 1ms
//#define STICK_RELOAD						50000		//50MHz(20ns) X 50000 = 1ms

#else

//#define STICK_RELOAD						6			//6MHz(166.7ns) X 6 = About 1us ---> UART 115200bps: 8680ns = 8.68us
//#define STICK_RELOAD						60			//6MHz(166.7ns) X 60 = About 10us
//#define STICK_RELOAD						600			//6MHz(166.7ns) X 600 = About 100us ---> Systick Minimum Interval In 6MHz == Over 54us
//#define STICK_RELOAD						5998		//6MHz(166.7ns) X 5998 = About 1ms
//#define STICK_RELOAD						66000		//66MHz(15.15ns) X 66000 = About 1ms

//#define STICK_RELOAD						60			//12MHz(83.3ns) X 60 = About 5us
//#define STICK_RELOAD						300			//12MHz(83.3ns) X 300 = About 25us ---> Systick Minimum Interval In 12MHz == Over 27.8us
//#define STICK_RELOAD						340			//12MHz(83.3ns) X 340 = About 28.3us ---> Main Loop Very Long
//#define STICK_RELOAD						350			//12MHz(83.3ns) X 350 = About 29.1us ---> Main Loop Very Long
//#define STICK_RELOAD						400			//12MHz(83.3ns) X 400 = About 33.3us ---> Main Loop Some Long(About 100us)
//#define STICK_RELOAD						500			//12MHz(83.3ns) X 500 = About 41.7us ---> Auto Baudrate OK
//#define STICK_RELOAD						600			//12MHz(83.3ns) X 600 = About 50us
#define STICK_RELOAD						12004		//12MHz(83.3ns) X 12004 = About 1ms

//#define STICK_RELOAD						600		//33MHz(30ns) X 600 = About 18us

#endif

#else

#endif
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
typedef enum
{
	STICK_OK = 0,
	STICK_FAIL = 1
} STICK_Result;
//----------------------------------------------------------------------------------------------
extern STICK_Result STICK_ClockSourceSelect(U8 source);
extern STICK_Result STICK_IntEnable(void);
extern STICK_Result STICK_IntDisable(void);
extern STICK_Result STICK_Enable(void);
extern STICK_Result STICK_Disable(void);
extern STICK_Result STICK_ReloadValueSet(U32 value);
extern STICK_Result STICK_CurrentValueSet(U32 value);
extern STICK_Result STICK_TickSet(U32 value);
extern STICK_Return STICK_TickGet(void);

#endif

//----------------------------------------------------------------------------------------------
// end of file
//----------------------------------------------------------------------------------------------
