/**
************************************************************************************************
* @file		GPIO_Test.c
* @author	Solution Team
* @brief	GPIO test function file
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

GPIO_Result GPIO_Test(void)
{

#if (__PRE_FPGA_MODE)		//111

#if (__PRE_FPGA_MODE_IP_TEAM)	//222

#if (0)
	GPIO_PortModeSet(GPIO_1, GPIO_PORT_MODE_GPIO);

	GPIO_OutputTypeSet(GPIO_1, GPIO_BIT_0, GPIO_OUTPUT_TYPE_PUSH_PULL);
	GPIO_OutputTypeSet(GPIO_1, GPIO_BIT_1, GPIO_OUTPUT_TYPE_PUSH_PULL);
	GPIO_OutputTypeSet(GPIO_1, GPIO_BIT_2, GPIO_OUTPUT_TYPE_PUSH_PULL);
	GPIO_OutputTypeSet(GPIO_1, GPIO_BIT_3, GPIO_OUTPUT_TYPE_PUSH_PULL);

	GPIO_OutputDisable(GPIO_1, GPIO_BIT_ALL);

	GPIO_OutputEnable(GPIO_1, GPIO_BIT_0);		//GPIO_1 bit[3:0] - LED[4:1]
	GPIO_OutputEnable(GPIO_1, GPIO_BIT_1);
	GPIO_OutputEnable(GPIO_1, GPIO_BIT_2);
	GPIO_OutputEnable(GPIO_1, GPIO_BIT_3);

	while(1)
	{
		GPIO_BitToggle(GPIO_1, GPIO_BIT_0);
		GPIO_BitToggle(GPIO_1, GPIO_BIT_1);
		GPIO_BitToggle(GPIO_1, GPIO_BIT_2);
		GPIO_BitToggle(GPIO_1, GPIO_BIT_3);
	}
#endif

#if (1)
	APP_KeyInitialize();
	LED_Initialize();

	while(1)
	{
		APP_KeyScan();
		APP_KeyProcess();

		LED_Control();
	}
#endif

#if (0)	//For Finding FPGA Key Port
	U16 Port1, Port2;
	U16 Data1, Data2;

	SYS_PortModeSet(SYS_PORT_A, SYS_PORT_BIT_ALL, SYS_PORT_MODE_GPIO);
	SYS_PortModeSet(SYS_PORT_B, SYS_PORT_BIT_ALL, SYS_PORT_MODE_GPIO);

	GPIO_PortModeSet(GPIO_1, GPIO_PORT_MODE_GPIO);
	GPIO_PortModeSet(GPIO_2, GPIO_PORT_MODE_GPIO);

	GPIO_OutputDisable(GPIO_1, GPIO_BIT_ALL);
	GPIO_OutputDisable(GPIO_2, GPIO_BIT_ALL);

	GPIO_Read(GPIO_1, &Data1);
	GPIO_Read(GPIO_2, &Data2);

	while(1)
	{
		GPIO_Read(GPIO_1, &Port1);
		GPIO_Read(GPIO_2, &Port2);

		if(Port1 != Data1)
		{
			__asm("nop");
			__asm("nop");
		}


		if(Port2 != Data2)
		{
			__asm("nop");
			__asm("nop");
		}
	}
#endif

#if (0)	//For Checking All LED Operation
	LED_Initialize();

	while(1)
	{
		LED_On(LED_1);
		LED_On(LED_2);
		LED_On(LED_3);
		LED_On(LED_4);
		LED_On(LED_5);
		LED_On(LED_6);
		LED_On(LED_7);
		LED_On(LED_8);

		LED_Off(LED_1);
		LED_Off(LED_2);
		LED_Off(LED_3);
		LED_Off(LED_4);
		LED_Off(LED_5);
		LED_Off(LED_6);
		LED_Off(LED_7);
		LED_Off(LED_8);

		LED_On(LED_9);
		LED_On(LED_10);
		LED_On(LED_11);
		LED_On(LED_12);

		LED_Off(LED_9);
		LED_Off(LED_10);
		LED_Off(LED_11);
		LED_Off(LED_12);

		LED_Toggle(LED_9);
		LED_Toggle(LED_10);
		LED_Toggle(LED_11);
		LED_Toggle(LED_12);

		LED_Toggle(LED_9);
		LED_Toggle(LED_10);
		LED_Toggle(LED_11);
		LED_Toggle(LED_12);
	}
#endif

#if (0)
	APP_KeyInitialize();

	while(1)
	{
		APP_KeyScan();
		APP_KeyProcess();
	}
#endif

#if (1)
	while(0)
	{
//		GPIO_BitToggle(GPIO_4, GPIO_BIT_4);		//ULPI CLK
//		GPIO_BitToggle(GPIO_4, GPIO_BIT_5);		//ULPI DIR
//		GPIO_BitToggle(GPIO_4, GPIO_BIT_6);		//ULPI STP
//		GPIO_BitToggle(GPIO_4, GPIO_BIT_7);		//ULPI NXT
		GPIO_BitToggle(GPIO_4, GPIO_BIT_8);		//ULPI DATA0
		GPIO_BitToggle(GPIO_4, GPIO_BIT_9);		//ULPI DATA1
		GPIO_BitToggle(GPIO_4, GPIO_BIT_10);		//ULPI DATA2
		GPIO_BitToggle(GPIO_4, GPIO_BIT_11);		//ULPI DATA3
		GPIO_BitToggle(GPIO_4, GPIO_BIT_12);		//ULPI DATA4
		GPIO_BitToggle(GPIO_4, GPIO_BIT_13);		//ULPI DATA5
		GPIO_BitToggle(GPIO_4, GPIO_BIT_14);		//ULPI DATA6
		GPIO_BitToggle(GPIO_4, GPIO_BIT_15);		//ULPI DATA7

//		GPIO_BitToggle(GPIO_5, GPIO_BIT_4);		//LED
//		GPIO_BitToggle(GPIO_5, GPIO_BIT_5);
//		GPIO_BitToggle(GPIO_5, GPIO_BIT_6);
//		GPIO_BitToggle(GPIO_5, GPIO_BIT_7);
	}
#endif

	while(1)
	{
		GPIO_BitToggle(GPIO_1, GPIO_BIT_0);
		GPIO_BitToggle(GPIO_1, GPIO_BIT_1);
		GPIO_BitToggle(GPIO_1, GPIO_BIT_2);
		GPIO_BitToggle(GPIO_1, GPIO_BIT_3);
		GPIO_BitToggle(GPIO_1, GPIO_BIT_4);
		GPIO_BitToggle(GPIO_1, GPIO_BIT_5);
		GPIO_BitToggle(GPIO_1, GPIO_BIT_6);
		GPIO_BitToggle(GPIO_1, GPIO_BIT_7);

		GPIO_BitToggle(GPIO_1, GPIO_BIT_9);		//SmartCard CK

		GPIO_BitToggle(GPIO_1, GPIO_BIT_10);		//WAKEUP[1]


		GPIO_BitToggle(GPIO_2, GPIO_BIT_2);		//I2C1
		GPIO_BitToggle(GPIO_2, GPIO_BIT_3);

		GPIO_BitToggle(GPIO_2, GPIO_BIT_4);		//UART2
		GPIO_BitToggle(GPIO_2, GPIO_BIT_5);
		GPIO_BitToggle(GPIO_2, GPIO_BIT_6);
		GPIO_BitToggle(GPIO_2, GPIO_BIT_7);

		GPIO_BitToggle(GPIO_2, GPIO_BIT_8);		//UART3
		GPIO_BitToggle(GPIO_2, GPIO_BIT_9);

		GPIO_BitToggle(GPIO_2, GPIO_BIT_10);		//EMMC CLK
		GPIO_BitToggle(GPIO_2, GPIO_BIT_11);		//EMMC CMD
		GPIO_BitToggle(GPIO_2, GPIO_BIT_12);		//EMMC DATA0
		GPIO_BitToggle(GPIO_2, GPIO_BIT_13);		//EMMC DATA1
		GPIO_BitToggle(GPIO_2, GPIO_BIT_14);		//EMMC DATA2
		GPIO_BitToggle(GPIO_2, GPIO_BIT_15);		//EMMC DATA3


		GPIO_BitToggle(GPIO_3, GPIO_BIT_0);		//EMMC DATA4
		GPIO_BitToggle(GPIO_3, GPIO_BIT_1);		//EMMC DATA5
		GPIO_BitToggle(GPIO_3, GPIO_BIT_2);		//EMMC DATA6
		GPIO_BitToggle(GPIO_3, GPIO_BIT_3);		//EMMC DATA7
		GPIO_BitToggle(GPIO_3, GPIO_BIT_4);		//EMMC RSTN
		GPIO_BitToggle(GPIO_3, GPIO_BIT_5);		//EMMC RCLK

		GPIO_BitToggle(GPIO_3, GPIO_BIT_6);		//SD CD

		GPIO_BitToggle(GPIO_3, GPIO_BIT_7);		//SSP3
		GPIO_BitToggle(GPIO_3, GPIO_BIT_8);
		GPIO_BitToggle(GPIO_3, GPIO_BIT_9);
//		GPIO_BitToggle(GPIO_3, GPIO_BIT_10);
		GPIO_BitToggle(GPIO_3, GPIO_BIT_11);

		GPIO_BitToggle(GPIO_3, GPIO_BIT_12);		//SmartCard CMDVCC
		GPIO_BitToggle(GPIO_3, GPIO_BIT_13);		//SmartCard OFF
		GPIO_BitToggle(GPIO_3, GPIO_BIT_14);		//SmartCard 3/5V
		GPIO_BitToggle(GPIO_3, GPIO_BIT_15);		//SmartCard RST


		GPIO_BitToggle(GPIO_4, GPIO_BIT_0);		//CAN
		GPIO_BitToggle(GPIO_4, GPIO_BIT_1);

		GPIO_BitToggle(GPIO_4, GPIO_BIT_4);		//ULPI CLK
		GPIO_BitToggle(GPIO_4, GPIO_BIT_5);		//ULPI DIR
		GPIO_BitToggle(GPIO_4, GPIO_BIT_6);		//ULPI STP
		GPIO_BitToggle(GPIO_4, GPIO_BIT_7);		//ULPI NXT
		GPIO_BitToggle(GPIO_4, GPIO_BIT_8);		//ULPI DATA0
		GPIO_BitToggle(GPIO_4, GPIO_BIT_9);		//ULPI DATA1
		GPIO_BitToggle(GPIO_4, GPIO_BIT_10);		//ULPI DATA2
		GPIO_BitToggle(GPIO_4, GPIO_BIT_11);		//ULPI DATA3
		GPIO_BitToggle(GPIO_4, GPIO_BIT_12);		//ULPI DATA4
		GPIO_BitToggle(GPIO_4, GPIO_BIT_13);		//ULPI DATA5
		GPIO_BitToggle(GPIO_4, GPIO_BIT_14);		//ULPI DATA6
		GPIO_BitToggle(GPIO_4, GPIO_BIT_15);		//ULPI DATA7


		GPIO_BitToggle(GPIO_5, GPIO_BIT_0);		//USB FS VBUS
		GPIO_BitToggle(GPIO_5, GPIO_BIT_1);		//USB FS ID

		GPIO_BitToggle(GPIO_5, GPIO_BIT_4);		//LED
		GPIO_BitToggle(GPIO_5, GPIO_BIT_5);
		GPIO_BitToggle(GPIO_5, GPIO_BIT_6);
		GPIO_BitToggle(GPIO_5, GPIO_BIT_7);

//		GPIO_BitSet(GPIO_5, GPIO_BIT_4);		//LED
//		GPIO_BitSet(GPIO_5, GPIO_BIT_5);
//		GPIO_BitSet(GPIO_5, GPIO_BIT_6);
//		GPIO_BitSet(GPIO_5, GPIO_BIT_7);

//		GPIO_BitClear(GPIO_5, GPIO_BIT_4);		//LED
//		GPIO_BitClear(GPIO_5, GPIO_BIT_5);
//		GPIO_BitClear(GPIO_5, GPIO_BIT_6);
//		GPIO_BitClear(GPIO_5, GPIO_BIT_7);

		GPIO_BitToggle(GPIO_5, GPIO_BIT_8);		//SW
		GPIO_BitToggle(GPIO_5, GPIO_BIT_9);
		GPIO_BitToggle(GPIO_5, GPIO_BIT_10);
		GPIO_BitToggle(GPIO_5, GPIO_BIT_11);
	}

#endif	//222

#else	//111

#endif	//111


#if (0)
	GPIO_PortModeSet(GPIO_5, GPIO_PORT_MODE_GPIO);

	GPIO_OutputEnable(GPIO_5, GPIO_BIT_4);
	GPIO_OutputEnable(GPIO_5, GPIO_BIT_5);
	GPIO_OutputEnable(GPIO_5, GPIO_BIT_6);
	GPIO_OutputEnable(GPIO_5, GPIO_BIT_7);

	while(1)
	{
		GPIO_BitToggle(GPIO_5, GPIO_BIT_4);
		GPIO_BitToggle(GPIO_5, GPIO_BIT_5);
		GPIO_BitToggle(GPIO_5, GPIO_BIT_6);
		GPIO_BitToggle(GPIO_5, GPIO_BIT_7);
	}
#endif

#if (1)
	APP_KeyInitialize();
	LED_Initialize();

	while(1)
	{
		APP_KeyScan();
		APP_KeyProcess();

		LED_Control();
	}
#endif

#if (1)
	while(1)
	{
		U16 Data1, Data2;

		GPIO_OutputEnable(GPIO_1, GPIO_BIT_ALL);
//		GPIO_OutputEnable(GPIO_2, GPIO_BIT_ALL);

//		GPIO_OutputDisable(GPIO_1, GPIO_BIT_ALL);
		GPIO_OutputDisable(GPIO_2, GPIO_BIT_ALL);

		GPIO_BitClear(GPIO_1, GPIO_BIT_ALL);
//		GPIO_BitClear(GPIO_2, GPIO_BIT_ALL);

		GPIO_Read(GPIO_1, &Data1);
		GPIO_Read(GPIO_2, &Data2);

		GPIO_BitSet(GPIO_1, GPIO_BIT_ALL);
//		GPIO_BitSet(GPIO_2, GPIO_BIT_ALL);

		GPIO_Read(GPIO_1, &Data1);
		GPIO_Read(GPIO_2, &Data2);

		__asm("nop");
		__asm("nop");
	}
#endif

//	GPIO_InterruptTest();

#if (0)
	APP_KeyInitialize();

	while(1)
	{
		APP_KeyScan();
		APP_KeyProcess();
	}
#endif

	GPIO_Initialize();

#if (1)
	while(1)
	{
		U16 Data;

		GPIO_Read(GPIO_1, &Data);

		Data = Data >> 4;

		__asm("nop");
		__asm("nop");
	}
#endif

	while(1)
	{
//		GPIO_BitClear(GPIO_1, GPIO_BIT_0);	//GPIO #1 ---> SOC Team call GPIO #0
//		GPIO_BitSet(GPIO_1, GPIO_BIT_0);

		GPIO_BitClear(GPIO_1, GPIO_BIT_ALL);
		GPIO_BitSet(GPIO_1, GPIO_BIT_ALL);

		GPIO_BitClear(GPIO_1, GPIO_BIT_0);
		GPIO_BitSet(GPIO_1, GPIO_BIT_0);

		GPIO_BitClear(GPIO_1, GPIO_BIT_1);
		GPIO_BitSet(GPIO_1, GPIO_BIT_1);

		GPIO_BitClear(GPIO_1, GPIO_BIT_2);
		GPIO_BitSet(GPIO_1, GPIO_BIT_2);

		GPIO_BitClear(GPIO_1, GPIO_BIT_3);
		GPIO_BitSet(GPIO_1, GPIO_BIT_3);

		GPIO_BitToggle(GPIO_1, GPIO_BIT_0);
		GPIO_BitToggle(GPIO_1, GPIO_BIT_0);

		GPIO_BitToggle(GPIO_1, GPIO_BIT_1);
		GPIO_BitToggle(GPIO_1, GPIO_BIT_1);

		GPIO_BitToggle(GPIO_1, GPIO_BIT_2);
		GPIO_BitToggle(GPIO_1, GPIO_BIT_2);

		GPIO_BitToggle(GPIO_1, GPIO_BIT_3);
		GPIO_BitToggle(GPIO_1, GPIO_BIT_3);
	}


	return GPIO_OK;
}
//----------------------------------------------------------------------------------------------
GPIO_Result GPIO_InterruptTest(void)
{
	NVIC_ClearPendingIRQ(GPIO_2_IRQn);

	NVIC_EnableIRQ(GPIO_2_IRQn);

	GPIO_IntDisable(GPIO_2, GPIO_BIT_ALL);

	GPIO_IntTypeSet(GPIO_2, GPIO_INT_TYPE_EDGE);
	GPIO_IntPolaritySet(GPIO_2, GPIO_BIT_ALL, GPIO_INT_POLARITY_FALLING);

	GPIO_IntEnable(GPIO_2, GPIO_BIT_0);
	GPIO_IntEnable(GPIO_2, GPIO_BIT_1);
	GPIO_IntEnable(GPIO_2, GPIO_BIT_2);
	GPIO_IntEnable(GPIO_2, GPIO_BIT_3);
	GPIO_IntEnable(GPIO_2, GPIO_BIT_4);

	while(1)
	{
		__asm("nop");
		__asm("nop");
	}


	return GPIO_OK;
}
//----------------------------------------------------------------------------------------------
GPIO_Result GPIO_Initialize(void)
{
	U32 id0, id1, id2, id3;
	U32 Temp1, Temp2, Temp3;

	id0 = rGPIO_1_PERI_ID;
	id1 = rGPIO_1_PERI_ID;
	id2 = rGPIO_1_PERI_ID;
	id3 = rGPIO_1_PERI_ID;

	Temp1 = id0;
	Temp2 = id1;

	Temp3 = Temp1 + Temp2;

	__asm("nop");
	__asm("nop");

//	NVIC_ClearPendingIRQ(GPIO_1_IRQn);
//	NVIC_EnableIRQ(GPIO_1_IRQn);

#if (__PRE_FPGA_MODE)

#if (__PRE_FPGA_MODE_IP_TEAM)

	GPIO_PortModeSet(GPIO_1, GPIO_PORT_MODE_GPIO);

	GPIO_OutputDisable(GPIO_1, GPIO_BIT_ALL);

	GPIO_OutputEnable(GPIO_1, GPIO_BIT_0);
	GPIO_OutputEnable(GPIO_1, GPIO_BIT_1);
	GPIO_OutputEnable(GPIO_1, GPIO_BIT_2);
	GPIO_OutputEnable(GPIO_1, GPIO_BIT_3);

#else

//	GPIO_IntTypeSet(GPIO_1, GPIO_INT_TYPE_EDGE);
//	GPIO_IntPolaritySet(GPIO_1, GPIO_BIT_4, GPIO_INT_POLARITY_FALLING);
//	GPIO_IntEnable(GPIO_1, GPIO_BIT_4);

//	GPIO_PortModeSet(GPIO_1, GPIO_PORT_MODE_GPIO);	//rGPIO_1_PORT_MODE is read only.
//	GPIO_PortModeSet(GPIO_1, GPIO_PORT_MODE_MULTI_FUNCTION);

//	GPIO_OutputTypeSet(GPIO_1, GPIO_BIT_ALL, GPIO_OUTPUT_TYPE_OPEN_DRAIN);
//	GPIO_OutputTypeSet(GPIO_1, GPIO_BIT_ALL, GPIO_OUTPUT_TYPE_PUSH_PULL);

//	GPIO_OutputEnable(GPIO_1, GPIO_BIT_0);
//	GPIO_OutputEnable(GPIO_1, GPIO_BIT_1);
//	GPIO_OutputEnable(GPIO_1, GPIO_BIT_2);
//	GPIO_OutputEnable(GPIO_1, GPIO_BIT_3);
//	GPIO_OutputEnable(GPIO_1, GPIO_BIT_4);
//	GPIO_OutputEnable(GPIO_1, GPIO_BIT_5);
//	GPIO_OutputEnable(GPIO_1, GPIO_BIT_6);
//	GPIO_OutputEnable(GPIO_1, GPIO_BIT_7);
//	GPIO_OutputEnable(GPIO_1, GPIO_BIT_8);
//	GPIO_OutputEnable(GPIO_1, GPIO_BIT_9);
//	GPIO_OutputEnable(GPIO_1, GPIO_BIT_10);
//	GPIO_OutputEnable(GPIO_1, GPIO_BIT_11);
//	GPIO_OutputEnable(GPIO_1, GPIO_BIT_12);
//	GPIO_OutputEnable(GPIO_1, GPIO_BIT_13);
//	GPIO_OutputEnable(GPIO_1, GPIO_BIT_14);
//	GPIO_OutputEnable(GPIO_1, GPIO_BIT_15);
	GPIO_OutputEnable(GPIO_1, GPIO_BIT_ALL);
	GPIO_Write(GPIO_1, 0xFFFF);
	GPIO_Write(GPIO_1, 0x0000);

	GPIO_OutputEnable(GPIO_2, GPIO_BIT_ALL);
	GPIO_Write(GPIO_2, 0xFFFF);
	GPIO_Write(GPIO_2, 0x0000);

#endif

#else

#endif

	return GPIO_OK;
}
//----------------------------------------------------------------------------------------------
GPIO_Result GPIO_Delay(U32 Count)
{
	U32 i;

	for(i = 0; i < Count; i++)
	{
	}


	return GPIO_OK;
}

//----------------------------------------------------------------------------------------------
// end of file
//----------------------------------------------------------------------------------------------
