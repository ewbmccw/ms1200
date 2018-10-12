/**
************************************************************************************************
* @file			GPIO.h
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

#ifndef	_GPIO_H_
#define	_GPIO_H_

typedef enum
{
	GPIO_OK = 0,
	GPIO_FAIL = 1,
	GPIO_ERROR1,
	GPIO_ERROR2
} GPIO_Result;

typedef enum
{
	GPIO_BIT_0 = 0x0001,
	GPIO_BIT_1 = 0x0002,
	GPIO_BIT_2 = 0x0004,
	GPIO_BIT_3 = 0x0008,
	GPIO_BIT_4 = 0x0010,
	GPIO_BIT_5 = 0x0020,
	GPIO_BIT_6 = 0x0040,
	GPIO_BIT_7 = 0x0080,
	GPIO_BIT_8 = 0x0100,
	GPIO_BIT_9 = 0x0200,
	GPIO_BIT_10 = 0x0400,
	GPIO_BIT_11 = 0x0800,
	GPIO_BIT_12 = 0x1000,
	GPIO_BIT_13 = 0x2000,
	GPIO_BIT_14 = 0x4000,
	GPIO_BIT_15 = 0x8000,
	GPIO_BIT_ALL = 0xFFFF
} GPIO_BitPosition;

typedef enum
{
	GPIO_PORT_MODE_GPIO = 0,
	GPIO_PORT_MODE_MULTI_FUNCTION
} GPIO_PortMode;

typedef enum		//for HAL driver
{
	GPIO_DIRECTION_INPUT = 0,
	GPIO_DIRECTION_OUTPUT
} GPIO_Direction;

typedef enum
{
	GPIO_OUTPUT_TYPE_PUSH_PULL = 0,
	GPIO_OUTPUT_TYPE_OPEN_DRAIN
} GPIO_OutputType;

typedef enum
{
	GPIO_INT_TYPE_EDGE = 0,
	GPIO_INT_TYPE_LEVEL
} GPIO_IntType;

typedef enum
{
	GPIO_INT_POLARITY_FALLING = 0,
	GPIO_INT_POLARITY_RISING
} GPIO_IntPolarity;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
typedef struct
{
	U16 pin;
	GPIO_Direction direction;
	GPIO_OutputType outputType;
}GPIO_InitStruct;

typedef struct
{
	U16 pin;
	GPIO_IntType intType;
	GPIO_IntPolarity intPolarity;
}GPIO_IntInitStruct;
//----------------------------------------------------------------------------------------------
extern GPIO_Return GPIO_Read(REG_GPIO *GPIOx);
extern GPIO_Return GPIO_BitRead(REG_GPIO *GPIOx, U16 bit);
extern GPIO_Result GPIO_Write(REG_GPIO *GPIOx, U16 data);
extern GPIO_Result GPIO_OutputEnable(REG_GPIO *GPIOx, U16 bit);
extern GPIO_Result GPIO_OutputDisable(REG_GPIO *GPIOx, U16 bit);
extern GPIO_Result GPIO_OutputTypeSet(REG_GPIO *GPIOx, U16 bit, U8 type);
extern GPIO_Result GPIO_BitSet(REG_GPIO *GPIOx, U16 bit);
extern GPIO_Result GPIO_BitClear(REG_GPIO *GPIOx, U16 bit);
extern GPIO_Result GPIO_BitToggle(REG_GPIO *GPIOx, U16 bit);
extern GPIO_Result GPIO_IntTypeSet(REG_GPIO *GPIOx, U16 bit, U8 type);
extern GPIO_Result GPIO_IntPolaritySet(REG_GPIO *GPIOx, U16 bit, U8 polarity);
extern GPIO_Result GPIO_IntEnable(REG_GPIO *GPIOx, U16 bit);
extern GPIO_Result GPIO_IntDisable(REG_GPIO *GPIOx, U16 bit);

extern GPIO_Result GPIO_Delay(U32 count);

#endif

//----------------------------------------------------------------------------------------------
// end of file
//----------------------------------------------------------------------------------------------
