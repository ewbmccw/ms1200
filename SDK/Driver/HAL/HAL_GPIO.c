/**
************************************************************************************************
* @file			HAL_GPIO.c
* @author		Solution Team
* @brief		HAL GPIO API function file
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
* @brief		HAL GPIO initialize value structure default set function
* @param		GPIO_InitStruct : GPIO initialize value structure
* @return		GPIO_Result
************************************************************************************************
*/
GPIO_Result HAL_GPIO_StructInit(GPIO_InitStruct *gpioInitStruct)
{
	gpioInitStruct->pin = GPIO_BIT_ALL;
	gpioInitStruct->direction = GPIO_DIRECTION_INPUT;
	gpioInitStruct->outputType = GPIO_OUTPUT_TYPE_PUSH_PULL;

	return GPIO_OK;
}
/**
************************************************************************************************
* @brief		HAL GPIO initialize function
* @param		REG_GPIO : GPIO register base address
* @param		GPIO_InitStruct : GPIO initialize value structure
* @return		GPIO_Result
************************************************************************************************
*/
GPIO_Result HAL_GPIO_Init(REG_GPIO *GPIOx, GPIO_InitStruct *gpioInitStruct)
{
	U32 i;
	U16 bit, position;

#if (_EWBM_MS1200)
	for(i = 0; i < 16; i++)
	{
		position = 1U << i;
		bit = gpioInitStruct->pin & position;

		if(bit)
		{
			if(gpioInitStruct->direction == GPIO_DIRECTION_INPUT)
			{
				GPIO_OutputDisable(GPIOx, bit);
			}
			else if(gpioInitStruct->direction == GPIO_DIRECTION_OUTPUT)
			{
				GPIO_OutputEnable(GPIOx, bit);
			}
			else
			{
				ASSERT(ERROR_PARAM);		//not accept parameter
			}

			if(gpioInitStruct->outputType == GPIO_OUTPUT_TYPE_PUSH_PULL)
			{
				GPIO_OutputTypeSet(GPIOx, bit, GPIO_OUTPUT_TYPE_PUSH_PULL);
			}
			else if(gpioInitStruct->outputType == GPIO_OUTPUT_TYPE_OPEN_DRAIN)
			{
				GPIO_OutputTypeSet(GPIOx, bit, GPIO_OUTPUT_TYPE_OPEN_DRAIN);
			}
			else
			{
				ASSERT(ERROR_PARAM);		//not accept parameter
			}
		}
	}
#endif

	return GPIO_OK;
}
/**
************************************************************************************************
* @brief		GPIO de-initialize HAL function
* @param		REG_GPIO : GPIO register base address
* @return		GPIO_Result
************************************************************************************************
*/
GPIO_Result HAL_GPIO_DeInit(REG_GPIO *GPIOx)
{
	//Clock Disable
	return GPIO_OK;
}
/**
************************************************************************************************
* @brief		GPIO port read HAL function
* @param		REG_GPIO : GPIO register base address
* @return		U32: port value
************************************************************************************************
*/
GPIO_Return HAL_GPIO_Read(REG_GPIO *GPIOx)
{
	return GPIO_Read(GPIOx);
}
/**
************************************************************************************************
* @brief		GPIO bit read HAL function
* @param		REG_GPIO : GPIO register base address
* @param		U16: bit position
* @return		U32: bit value
************************************************************************************************
*/
GPIO_Return HAL_GPIO_BitRead(REG_GPIO *GPIOx, U16 bit)
{
	return GPIO_BitRead(GPIOx, bit);
}
/**
************************************************************************************************
* @brief		GPIO port write HAL function
* @param		REG_GPIO : GPIO register base address
* @param		U16 : data
* @return		GPIO_Result
************************************************************************************************
*/
GPIO_Result HAL_GPIO_Write(REG_GPIO *GPIOx, U16 data)
{
	GPIO_Write(GPIOx, data);

	return GPIO_OK;
}
/**
************************************************************************************************
* @brief		GPIO bit set HAL function
* @param		REG_GPIO : GPIO register base address
* @param		U16 : bit position
* @return		GPIO_Result
************************************************************************************************
*/
GPIO_Result HAL_GPIO_BitSet(REG_GPIO *GPIOx, U16 bit)
{
	GPIO_BitSet(GPIOx, bit);

	return GPIO_OK;
}
/**
************************************************************************************************
* @brief		GPIO bit clear HAL function
* @param		REG_GPIO : GPIO register base address
* @param		U16 : bit position
* @return		GPIO_Result
************************************************************************************************
*/
GPIO_Result HAL_GPIO_BitClear(REG_GPIO *GPIOx, U16 bit)
{
	GPIO_BitClear(GPIOx, bit);

	return GPIO_OK;
}
/**
************************************************************************************************
* @brief		GPIO bit toggle HAL function
* @param		REG_GPIO : GPIO register base address
* @param		U16 : bit position
* @return		GPIO_Result
************************************************************************************************
*/
GPIO_Result HAL_GPIO_BitToggle(REG_GPIO *GPIOx, U16 bit)
{
	GPIO_BitToggle(GPIOx, bit);

	return GPIO_OK;
}
/**
************************************************************************************************
* @brief		GPIO interrupt initialize HAL function
* @param		REG_GPIO : GPIO register base address
* @param		GPIO_IntInitStruct : GPIO interrupt initialize value structure
* @return		GPIO_Result
************************************************************************************************
*/
GPIO_Result HAL_GPIO_IntInit(REG_GPIO *GPIOx, GPIO_IntInitStruct *gpioIntInitStruct)
{
	U32 i;
	U16 bit, position;

	for(i = 0; i < 16; i++)
	{
		position = 1U << i;
		bit = gpioIntInitStruct->pin & position;

		if(bit)
		{
			if(gpioIntInitStruct->intType == GPIO_INT_TYPE_EDGE)
			{
				GPIO_IntTypeSet(GPIOx, bit, GPIO_INT_TYPE_EDGE);
			}
			else if(gpioIntInitStruct->intType == GPIO_INT_TYPE_LEVEL)
			{
				GPIO_IntTypeSet(GPIOx, bit, GPIO_INT_TYPE_LEVEL);
			}
			else
			{
				ASSERT(ERROR_PARAM);		//not accept parameter
			}

			if(gpioIntInitStruct->intPolarity == GPIO_INT_POLARITY_FALLING)
			{
				GPIO_IntPolaritySet(GPIOx, bit, GPIO_INT_POLARITY_FALLING);
			}
			else if(gpioIntInitStruct->intPolarity == GPIO_INT_POLARITY_RISING)
			{
				GPIO_IntPolaritySet(GPIOx, bit, GPIO_INT_POLARITY_RISING);
			}
			else
			{
				ASSERT(ERROR_PARAM);		//not accept parameter
			}
		}
	}

	return GPIO_OK;
}
/**
************************************************************************************************
* @brief		GPIO bit interrupt enable HAL function
* @param		REG_GPIO : GPIO register base address
* @param		U16 : pin - bit combination
* @return		GPIO_Result
************************************************************************************************
*/
GPIO_Result HAL_GPIO_IntEnable(REG_GPIO *GPIOx, U16 pin)
{
	U32 i;
	U16 bit, position;

	for(i = 0; i < 16; i++)
	{
		position = 1U << i;
		bit = pin & position;

		if(bit)
		{
			GPIO_IntEnable(GPIOx, bit);
		}
	}

	return GPIO_OK;
}
/**
************************************************************************************************
* @brief		GPIO bit interrupt disable HAL function
* @param		REG_GPIO : GPIO register base address
* @param		U16 : pin - bit combination
* @return		GPIO_Result
************************************************************************************************
*/
GPIO_Result HAL_GPIO_IntDisable(REG_GPIO *GPIOx, U16 pin)
{
	U32 i;
	U16 bit, position;

	for(i = 0; i < 16; i++)
	{
		position = 1U << i;
		bit = pin & position;

		if(bit)
		{
			GPIO_IntDisable(GPIOx, bit);
		}
	}

	return GPIO_OK;
}

//----------------------------------------------------------------------------------------------
// end of file
//----------------------------------------------------------------------------------------------
