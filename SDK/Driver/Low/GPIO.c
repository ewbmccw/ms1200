/**
************************************************************************************************
* @file			GPIO.c
* @author		Solution Team
* @brief		GPIO API function file
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
* @brief		GPIO port read function
* @param		REG_GPIO : GPIO register base address
* @return		GPIO_Return(U32) : port value
************************************************************************************************
*/
GPIO_Return GPIO_Read(REG_GPIO *GPIOx)
{
	return HWREG(GPIOx->DR);
}
/**
************************************************************************************************
* @brief		GPIO bit read function
* @param		REG_GPIO : GPIO register base address
* @param		U16 : bit position
* @return		GPIO_Return(U32) : bit value
************************************************************************************************
*/
GPIO_Return GPIO_BitRead(REG_GPIO *GPIOx, U16 bit)
{
	U16 data;

	data = (HWREG(GPIOx->DR) & bit);

	if(data)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
/**
************************************************************************************************
* @brief		GPIO port write function
* @param		REG_GPIO : GPIO register base address
* @param		U16 : data
* @return		GPIO_Result
************************************************************************************************
*/
GPIO_Result GPIO_Write(REG_GPIO *GPIOx, U16 data)
{
	HWREG(GPIOx->DOR) = data;

	return GPIO_OK;
}
/**
************************************************************************************************
* @brief		GPIO output enable function
* @param		REG_GPIO : GPIO register base address
* @param		U16 : bit position
* @return		GPIO_Result
************************************************************************************************
*/
GPIO_Result GPIO_OutputEnable(REG_GPIO *GPIOx, U16 bit)
{
	HWREG(GPIOx->OMR) |= bit;

	return GPIO_OK;
}
/**
************************************************************************************************
* @brief		GPIO output disable function
* @param		REG_GPIO : GPIO register base address
* @param		U16 : bit position
* @return		GPIO_Result
************************************************************************************************
*/
GPIO_Result GPIO_OutputDisable(REG_GPIO *GPIOx, U16 bit)
{
	HWREG(GPIOx->OMR) &= ~bit;

	return GPIO_OK;
}
/**
************************************************************************************************
* @brief		GPIO output type set function
* @param		REG_GPIO : GPIO register base address
* @param		U16 : bit position
* @param		U8 : type
* @return		GPIO_Result
************************************************************************************************
*/
GPIO_Result GPIO_OutputTypeSet(REG_GPIO *GPIOx, U16 bit, U8 type)
{
	U8 number;

	number = BitPositionGet(bit);

	if(type == GPIO_OUTPUT_TYPE_PUSH_PULL)
	{
		HWREG(GPIOx->OMR) &= ~(1U << (number + 16));	//bit16 ~ bit31
	}
	else if(type == GPIO_OUTPUT_TYPE_OPEN_DRAIN)
	{
		HWREG(GPIOx->OMR) |= (1U << (number + 16));
	}
	else
	{
		ASSERT(ERROR_PARAM);		//not accept parameter
	}

	return GPIO_OK;
}
/**
************************************************************************************************
* @brief		GPIO bit set function
* @param		REG_GPIO : GPIO register base address
* @param		U16 : bit position
* @return		GPIO_Result
************************************************************************************************
*/
GPIO_Result GPIO_BitSet(REG_GPIO *GPIOx, U16 bit)
{
	HWREG(GPIOx->DOR) |= bit;

	return GPIO_OK;
}
/**
************************************************************************************************
* @brief		GPIO bit clear function
* @param		REG_GPIO : GPIO register base address
* @param		U16 : bit position
* @return		GPIO_Result
************************************************************************************************
*/
GPIO_Result GPIO_BitClear(REG_GPIO *GPIOx, U16 bit)
{
	HWREG(GPIOx->DOR) &= ~bit;

	return GPIO_OK;
}
/**
************************************************************************************************
* @brief		GPIO bit toggle function
* @param		REG_GPIO : GPIO register base address
* @param		U16 : bit position
* @return		GPIO_Result
************************************************************************************************
*/
GPIO_Result GPIO_BitToggle(REG_GPIO *GPIOx, U16 bit)
{
	HWREG(GPIOx->DOR) ^= bit;

	return GPIO_OK;
}
/**
************************************************************************************************
* @brief		GPIO interrupt type set function
* @param		REG_GPIO : GPIO register base address
* @param		U16 : bit position
* @param		U8 : interrupt type
* @return		GPIO_Result
************************************************************************************************
*/
GPIO_Result GPIO_IntTypeSet(REG_GPIO *GPIOx, U16 bit, U8 type)
{
	U8 number;

	number = BitPositionGet(bit);

	if(type == GPIO_INT_TYPE_EDGE)
	{
		HWREG(GPIOx->ITR) &= ~(1U << number);		//bit0 ~ bit15
	}
	else if(type == GPIO_INT_TYPE_LEVEL)
	{
		HWREG(GPIOx->ITR) |= (1U << number);
	}
	else
	{
		ASSERT(ERROR_PARAM);				//not accept parameter
	}

	return GPIO_OK;
}
/**
************************************************************************************************
* @brief		GPIO interrupt polarity set function
* @param		REG_GPIO : GPIO register base address
* @param		U16 : bit position
* @param		U8 : interrupt polarity
* @return		GPIO_Result
************************************************************************************************
*/
GPIO_Result GPIO_IntPolaritySet(REG_GPIO *GPIOx, U16 bit, U8 polarity)
{
	U8 number;

	number = BitPositionGet(bit);

	if(polarity == GPIO_INT_POLARITY_FALLING)
	{
		HWREG(GPIOx->IPR) &= ~(1U << number);		//bit0 ~ bit15
	}
	else if(polarity == GPIO_INT_POLARITY_RISING)
	{
		HWREG(GPIOx->IPR) |= (1U << number);
	}
	else
	{
		ASSERT(ERROR_PARAM);				//not accept parameter
	}

	return GPIO_OK;
}
/**
************************************************************************************************
* @brief		GPIO interrupt enable function
* @param		REG_GPIO : GPIO register base address
* @param		U16 : bit position
* @return		GPIO_Result
************************************************************************************************
*/
GPIO_Result GPIO_IntEnable(REG_GPIO *GPIOx, U16 bit)
{
	U8 number;

	number = BitPositionGet(bit);

	HWREG(GPIOx->IER) |= (1U << number);

	return GPIO_OK;
}
/**
************************************************************************************************
* @brief		GPIO interrupt disable function
* @param		REG_GPIO : GPIO register base address
* @param		U16 : bit position
* @return		GPIO_Result
************************************************************************************************
*/
GPIO_Result GPIO_IntDisable(REG_GPIO *GPIOx, U16 bit)
{
	U8 number;

	number = BitPositionGet(bit);

	HWREG(GPIOx->IER) &= ~(1U << number);

	return GPIO_OK;
}
/**
************************************************************************************************
* @brief		GPIO delay function
* @param		U32 : delay count
* @return		GPIO_Result
************************************************************************************************
*/
GPIO_Result GPIO_Delay(U32 count)
{
	U32 i;

	for(i = 0; i < count; i++)
	{
	}

	return GPIO_OK;
}
/**
************************************************************************************************
* @brief		GPIO 1 interrupt handler
************************************************************************************************
*/
__irq void GPIO_1_IrqHandler(void)
{
	U32 status;

	status = HWREG(GPIO_1->ISR);

	HWREG(GPIO_1->ISR) = status;

	APP_GPIO_1_CallBack(status);
}
/**
************************************************************************************************
* @brief		GPIO 2 interrupt handler
************************************************************************************************
*/
__irq void GPIO_2_IrqHandler(void)
{
	U32 status;

	status = HWREG(GPIO_2->ISR);

	HWREG(GPIO_2->ISR) = status;

	APP_GPIO_2_CallBack(status);
}
/**
************************************************************************************************
* @brief		GPIO 3 interrupt handler
************************************************************************************************
*/
__irq void GPIO_3_IrqHandler(void)
{
	U32 status;

	status = HWREG(GPIO_3->ISR);

	HWREG(GPIO_3->ISR) = status;

	APP_GPIO_3_CallBack(status);
}
/**
************************************************************************************************
* @brief		GPIO 4 interrupt handler
************************************************************************************************
*/
__irq void GPIO_4_IrqHandler(void)
{
	U32 status;

	status = HWREG(GPIO_4->ISR);

	HWREG(GPIO_4->ISR) = status;

	APP_GPIO_4_CallBack(status);
}
/**
************************************************************************************************
* @brief		GPIO 5 interrupt handler
************************************************************************************************
*/
__irq void GPIO_5_IrqHandler(void)
{
	U32 status;

	status = HWREG(GPIO_5->ISR);

	HWREG(GPIO_5->ISR) = status;

	APP_GPIO_5_CallBack(status);
}

//----------------------------------------------------------------------------------------------
// end of file
//----------------------------------------------------------------------------------------------
