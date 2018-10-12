/**
************************************************************************************************
* @file		main.c
* @author	Solution Team
* @version	1.0
* @date		2018.09.03
* @brief	main function
************************************************************************************************
*/

#include	<stdio.h>
#include	<stdint.h>

#include	"SDK_Common.h"

void SYSTICK_Initialize(void);
void SYSTICK_Disable(void);
void SYSTICK_IntEnable(void);
void SYSTICK_IntDisable(void);

//static U32 ToggleTimer;
//static U32 SystickCounter;

static U32 ToggleTimer;
static U32 SystickCounter;

void main(void)
{
	GPIO_InitStruct GpioStruct;

	SYSTICK_IntDisable();
	SYSTICK_Initialize();
	SYSTICK_IntEnable();

	GpioStruct.Pin = GPIO_BIT_0 | GPIO_BIT_1;
	GpioStruct.Direction = GPIO_DIRECTION_OUTPUT;
	GpioStruct.OutputType = GPIO_OUTPUT_TYPE_PUSH_PULL;
	GPIO_H_Init(GPIO1, &GpioStruct);

	ToggleTimer = 500;

	while(1)
	{
		if(ToggleTimer == 0)
		{
			ToggleTimer = 500;

			GPIO_H_BitToggle(GPIO1, GPIO_BIT_0);
			GPIO_H_BitToggle(GPIO1, GPIO_BIT_1);
		}
	}
}
//----------------------------------------------------------------------------------------------
#define rSYSTICK_CTRL			*((volatile U32 *)0xE000E010
#define rSYSTICK_LOAD			*((volatile U32 *)0xE000E014
#define rSYSTICK_VALUE			*((volatile U32 *)0xE000E018
#define rSYSTICK_CALIB			*((volatile U32 *)0xE000E01C

#define SYSTICK_COUNT_FLAG		(1 << 16)
#define SYSTICK_CLOCK_SOURCE		(1 << 2)
#define SYSTICK_INTERRUPT		(1 << 1)
#define SYSTICK_ENABLE			(1 << 0)

//#define SYSTICK_LOAD			6	//6MHz(166.7ns) X 6 = About 1us ---> UART 115200bps: 8680ns = 8.68us
//#define SYSTICK_LOAD			60	//6MHz(166.7ns) X 60 = About 10us
//#define SYSTICK_LOAD			600	//6MHz(166.7ns) X 600 = About 100us ---> Systick Minimum Interval In 6MHz == Over 54us
//#define SYSTICK_LOAD			5998	//6MHz(166.7ns) X 5998 = About 1ms
//#define SYSTICK_LOAD			66000	//66MHz(15.15ns) X 66000 = About 1ms

//#define SYSTICK_LOAD			60	//12MHz(83.3ns) X 60 = About 5us
//#define SYSTICK_LOAD			300	//12MHz(83.3ns) X 300 = About 25us ---> Systick Minimum Interval In 12MHz == Over 27.8us
//#define SYSTICK_LOAD			340	//12MHz(83.3ns) X 340 = About 28.3us ---> Main Loop Very Long
//#define SYSTICK_LOAD			350	//12MHz(83.3ns) X 350 = About 29.1us ---> Main Loop Very Long
//#define SYSTICK_LOAD			400	//12MHz(83.3ns) X 400 = About 33.3us ---> Main Loop Some Long(About 100us)
//#define SYSTICK_LOAD			500	//12MHz(83.3ns) X 500 = About 41.7us ---> Auto Baudrate OK
//#define SYSTICK_LOAD			600	//12MHz(83.3ns) X 600 = About 50us
#define SYSTICK_LOAD			12004	//12MHz(83.3ns) X 12004 = About 1ms

//#define SYSTICK_LOAD			600	//33MHz(30ns) X 600 = About 18us

void SYSTICK_Initialize(void)
{
	SystickCounter = 0;

	CRM_HsircEnable();

	while(!CRM_ClockReadyCheck(CRM_CLOCK_SOURCE_HS_IRC));

//	CRM_SystickSourceSelect(CRM_CLOCK_SOURCE_DEFAULT);
	CRM_SystickSourceSelect(CRM_CLOCK_SOURCE_HS_IRC);
//	CRM_SystickSourceSelect(CRM_CLOCK_SOURCE_XTAL);
//	CRM_SystickSourceSelect(CRM_CLOCK_SOURCE_PLL);
//	CRM_SystickSourceSelect(CRM_CLOCK_SOURCE_DIVIDER_A);
//	CRM_SystickSourceSelect(CRM_CLOCK_SOURCE_DIVIDER_B);
//	CRM_SystickSourceSelect(CRM_CLOCK_SOURCE_DIVIDER_C);
//	CRM_SystickSourceSelect(CRM_CLOCK_SOURCE_DIVIDER_D);
//	CRM_SystickSourceSelect(CRM_CLOCK_SOURCE_DIVIDER_E);

	rSYSTICK_LOAD = SYSTICK_LOAD;
	rSYSTICK_VALUE = 0;

//	rSYSTICK_CTRL = SYSTICK_ENABLE | SYSTICK_INTERRUPT;	//start timer, with interrupts enabled
	rSYSTICK_CTRL = SYSTICK_ENABLE | SYSTICK_INTERRUPT | SYSTICK_CLOCK_SOURCE;
//	rSYSTICK_CTRL = SYSTICK_COUNT_FLAG | SYSTICK_ENABLE | SYSTICK_INTERRUPT | SYSTICK_CLOCK_SOURCE;

//	SYSTICK_IntEnable();
}
//----------------------------------------------------------------------------------------------
void SYSTICK_Disable(void)
{
	rSYSTICK_LOAD = 0;
	rSYSTICK_VALUE = 0;
	rSYSTICK_CTRL = 0;
}
//----------------------------------------------------------------------------------------------
void SYSTICK_IntEnable(void)
{
	rSYSTICK_CTRL |= SYSTICK_INTERRUPT;
}
//----------------------------------------------------------------------------------------------
void SYSTICK_IntDisable(void)
{
	rSYSTICK_CTRL &= ~(SYSTICK_INTERRUPT);
}
//----------------------------------------------------------------------------------------------
__irq void SYSTICK_IrqHandler(void)
{
	SystickCounter++;

	if(ToggleTimer)
	{
		ToggleTimer--;
	}


	APP_Time1msRoutine();
}

//----------------------------------------------------------------------------------------------
//	End Of File
//----------------------------------------------------------------------------------------------
