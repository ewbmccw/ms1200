/**
************************************************************************************************
* @file			SDK_Exception.c
* @author		Solution Team
* @brief		SDK exception table define file
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

#pragma arm section rodata = "vectors"

ExecFuncPtr vector_table[] =
{
	(ExecFuncPtr)&Image$$ARM_LIB_STACKHEAP$$ZI$$Limit,
	(ExecFuncPtr)__main,
	NMIException,
	HardFaultException,
	MemManageException,
	BusFaultException,
	UsageFaultException,
	0,
	0,
	0,
	0,

#if (__FREE_RTOS)

	vPortSVCHandler,
	DebugMonitor,
	0,
	xPortPendSVHandler,
	xPortSysTickHandler,

#else

	SVCHandler,
	DebugMonitor,
	0,
	PendSVC,
	STICK_Handler,

#endif

	SYS_IrqHandler,			//00
	RTC_IrqHandler,			//01
	DMA_IrqHandler,			//02
	SDIO_IrqHandler,		//03
	SDMMC_IrqHandler,		//04
	USB_IrqHandler,			//05
	USB_DMA_IrqHandler,		//06
	EIP_H0_SEC_IrqHandler,	//07
	EIP_H0_IrqHandler,		//08
	EIP_H1_IrqHandler,		//09
	EIP_H2_IrqHandler,		//10
	ARIA_IrqHandler,		//11
	CRM_IrqHandler,			//12
	WDT_IrqHandler,			//13
	GPIO_1_IrqHandler,		//14
	GPIO_2_IrqHandler,		//15
	GPIO_3_IrqHandler,		//16
	GPIO_4_IrqHandler,		//17
	GPIO_5_IrqHandler,		//18
	I2C_1_IrqHandler,		//19
	I2C_2_IrqHandler,		//20
	SSP_1_IrqHandler,		//21
	SSP_2_IrqHandler,		//22
	SSP_3_IrqHandler,		//23
	SSP_4_IrqHandler,		//24
	UART_1_IrqHandler,		//25
	UART_2_IrqHandler,		//26
	UART_3_IrqHandler,		//27
	UART_4_IrqHandler,		//28
	TIM_1_IrqHandler,		//29
	TIM_2_IrqHandler,		//30
	CAN_1_IrqHandler,		//31
	ADC_1_IrqHandler,		//32
	InterruptHandler,		//33
	InterruptHandler,		//34
	InterruptHandler,		//35
	InterruptHandler,		//36
	InterruptHandler,		//37
	InterruptHandler,		//38
	InterruptHandler,		//39
	InterruptHandler,		//40
	InterruptHandler,		//41
	InterruptHandler,		//42
	InterruptHandler,		//43
	InterruptHandler,		//44
	InterruptHandler,		//45
	InterruptHandler,		//46
	InterruptHandler		//47
};

#pragma arm section
//----------------------------------------------------------------------------------------------
void prvGetRegistersFromStack(unsigned int *pulFaultStackAddress)
{
	/* These are volatile to try and prevent the compiler/linker optimising them
	away as the variables never actually get used.  If the debugger won't show the
	values of the variables, make them global my moving their declaration outside
	of this function. */
	volatile U32 R0;
	volatile U32 R1;
	volatile U32 R2;
	volatile U32 R3;
	volatile U32 R12;
	volatile U32 LR;	//Link Register
	volatile U32 PC;	//Program Counter
	volatile U32 PSR;	//Program Status Register

	R0 = pulFaultStackAddress[0];
	R1 = pulFaultStackAddress[1];
	R2 = pulFaultStackAddress[2];
	R3 = pulFaultStackAddress[3];

	R12 = pulFaultStackAddress[4];
	LR = pulFaultStackAddress[5];
	PC = pulFaultStackAddress[6];
	PSR = pulFaultStackAddress[7];

	/* When the following line is hit, the variables contain the register values. */
	for(;;);
}
//----------------------------------------------------------------------------------------------
__irq void NMIException(void)
{
	while(1);
}
//----------------------------------------------------------------------------------------------
__irq void HardFaultException(void)
{
//	__asm volatile("tst lr, #4");
//	__asm volatile("ite eq");
//	__asm volatile("mrseq r0, msp");
//	__asm volatile("mrsne r0, psp");
//	__asm volatile("ldr r1, [r0, #24]");
//	__asm volatile("ldr r2, handler2_address_const");
//	__asm volatile("bx r2");
//	__asm volatile("handler2_address_const: .word prvGetRegistersFromStack");

	while(1);
}
//----------------------------------------------------------------------------------------------
__irq void MemManageException(void)
{
	while(1);
}
//----------------------------------------------------------------------------------------------
__irq void BusFaultException(void)
{
	while(1);
}
//----------------------------------------------------------------------------------------------
__irq void UsageFaultException(void)
{
	while(1);
}
//----------------------------------------------------------------------------------------------
__irq void DebugMonitor(void)
{
	while(1);
}
//----------------------------------------------------------------------------------------------
__irq void SVCHandler(void)
{
	while(1);
}
//----------------------------------------------------------------------------------------------
__irq void PendSVC(void)
{
	while(1);
}
//----------------------------------------------------------------------------------------------
__irq void SYS_IrqHandler(void)
{
	while(1);
}
//----------------------------------------------------------------------------------------------
__irq void DMA_IrqHandler(void)
{
	while(1);
}
//----------------------------------------------------------------------------------------------
__irq void USB_IrqHandler(void)
{
	while(1);
}
//----------------------------------------------------------------------------------------------
__irq void USB_DMA_IrqHandler(void)
{
	while(1);
}
//----------------------------------------------------------------------------------------------
__irq void SDIO_IrqHandler(void)
{
	while(1);
}
//----------------------------------------------------------------------------------------------
__irq void SDMMC_IrqHandler(void)
{
	while(1);
}
//----------------------------------------------------------------------------------------------
__irq void EIP_H0_SEC_IrqHandler(void)
{
	while(1);
}
//----------------------------------------------------------------------------------------------
__irq void EIP_H0_IrqHandler(void)
{
	while(1);
}
//----------------------------------------------------------------------------------------------
__irq void EIP_H1_IrqHandler(void)
{
	while(1);
}
//----------------------------------------------------------------------------------------------
__irq void EIP_H2_IrqHandler(void)
{
	while(1);
}
//----------------------------------------------------------------------------------------------
__irq void ARIA_IrqHandler(void)
{
	while(1);
}
//----------------------------------------------------------------------------------------------
__irq void CRM_IrqHandler(void)
{
	while(1);
}
//----------------------------------------------------------------------------------------------
__irq void I2C_1_IrqHandler(void)
{
	while(1);
}
//----------------------------------------------------------------------------------------------
__irq void I2C_2_IrqHandler(void)
{
	while(1);
}
//----------------------------------------------------------------------------------------------
__irq void SSP_1_IrqHandler(void)
{
	while(1);
}
//----------------------------------------------------------------------------------------------
__irq void SSP_2_IrqHandler(void)
{
	while(1);
}
//----------------------------------------------------------------------------------------------
__irq void SSP_3_IrqHandler(void)
{
	while(1);
}
//----------------------------------------------------------------------------------------------
__irq void SSP_4_IrqHandler(void)
{
	while(1);
}
//----------------------------------------------------------------------------------------------
__irq void TIM_1_IrqHandler(void)
{
	while(1);
}
//----------------------------------------------------------------------------------------------
__irq void TIM_2_IrqHandler(void)
{
	while(1);
}
//----------------------------------------------------------------------------------------------
__irq void CAN_1_IrqHandler(void)
{
	while(1);
}
//----------------------------------------------------------------------------------------------
__irq void ADC_1_IrqHandler(void)
{
	while(1);
}
//----------------------------------------------------------------------------------------------
__irq void InterruptHandler(void)
{
	while(1);
}

//----------------------------------------------------------------------------------------------
// end of file
//----------------------------------------------------------------------------------------------
