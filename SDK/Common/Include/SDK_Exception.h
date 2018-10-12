/**
************************************************************************************************
* @file			SDK_Exception.h
* @author		Solution Team
* @brief		SDK exception table define header file
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

#if (__FREE_RTOS)
extern __asm void xPortPendSVHandler(void);
extern __asm void vPortSVCHandler(void);
extern void xPortSysTickHandler(void);
#endif
//----------------------------------------------------------------------------------------------
extern __irq void NMIException(void);
extern __irq void HardFaultException(void);
extern __irq void MemManageException(void);
extern __irq void BusFaultException(void);
extern __irq void UsageFaultException(void);
extern __irq void DebugMonitor(void);
extern __irq void SVCHandler(void);
extern __irq void PendSVC(void);
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
extern __irq void STICK_Handler(void);

extern __irq void SYS_IrqHandler(void);
extern __irq void RTC_IrqHandler(void);
extern __irq void DMA_IrqHandler(void);
extern __irq void USB_IrqHandler(void);
extern __irq void USB_DMA_IrqHandler(void);
extern __irq void SDIO_IrqHandler(void);
extern __irq void SDMMC_IrqHandler(void);
extern __irq void EIP_H0_SEC_IrqHandler(void);
extern __irq void EIP_H0_IrqHandler(void);
extern __irq void EIP_H1_IrqHandler(void);
extern __irq void EIP_H2_IrqHandler(void);
extern __irq void ARIA_IrqHandler(void);
extern __irq void CRM_IrqHandler(void);
extern __irq void WDT_IrqHandler(void);
extern __irq void GPIO_1_IrqHandler(void);
extern __irq void GPIO_2_IrqHandler(void);
extern __irq void GPIO_3_IrqHandler(void);
extern __irq void GPIO_4_IrqHandler(void);
extern __irq void GPIO_5_IrqHandler(void);
extern __irq void I2C_1_IrqHandler(void);
extern __irq void I2C_2_IrqHandler(void);
extern __irq void SSP_1_IrqHandler(void);
extern __irq void SSP_2_IrqHandler(void);
extern __irq void SSP_3_IrqHandler(void);
extern __irq void SSP_4_IrqHandler(void);
extern __irq void UART_1_IrqHandler(void);
extern __irq void UART_2_IrqHandler(void);
extern __irq void UART_3_IrqHandler(void);
extern __irq void UART_4_IrqHandler(void);
extern __irq void TIM_1_IrqHandler(void);
extern __irq void TIM_2_IrqHandler(void);
extern __irq void CAN_1_IrqHandler(void);
//extern __irq void CAN_2_IrqHandler(void);		//R&D only
extern __irq void ADC_1_IrqHandler(void);

extern __irq void InterruptHandler(void);
//----------------------------------------------------------------------------------------------
extern void APP_STICK_CallBack(void);

extern void APP_SYS_CallBack(U32 status);
extern void APP_RTC_CallBack(U32 status);
extern void APP_DMA_CallBack(U32 status);
extern void APP_SDIO_CallBack(U32 status);
extern void APP_SDMMC_CallBack(U32 status);
extern void APP_USB_CallBack(U32 status);
extern void APP_USB_DMA_CallBack(U32 status);
extern void APP_EIP_H0_SEC_CallBack(U32 status);
extern void APP_EIP_H0_CallBack(U32 status);
extern void APP_EIP_H1_CallBack(U32 status);
extern void APP_EIP_H2_CallBack(U32 status);
extern void APP_ARIA_CallBack(U32 status);
extern void APP_CRM_CallBack(U32 status);
extern void APP_WDT_CallBack(U32 status);
extern void APP_GPIO_1_CallBack(U32 status);
extern void APP_GPIO_2_CallBack(U32 status);
extern void APP_GPIO_3_CallBack(U32 status);
extern void APP_GPIO_4_CallBack(U32 status);
extern void APP_GPIO_5_CallBack(U32 status);
extern void APP_I2C_1_CallBack(U32 status);
extern void APP_I2C_2_CallBack(U32 status);
extern void APP_SSP_1_CallBack(U32 status);
extern void APP_SSP_2_CallBack(U32 status);
extern void APP_SSP_3_CallBack(U32 status);
extern void APP_SSP_4_CallBack(U32 status);
extern void APP_UART_1_CallBack(U32 status);
extern void APP_UART_2_CallBack(U32 status);
extern void APP_UART_3_CallBack(U32 status);
extern void APP_UART_4_CallBack(U32 status);
extern void APP_TIM_1_CallBack(U32 status);
extern void APP_TIM_2_CallBack(U32 status);
extern void APP_CAN_1_CallBack(U32 status);
extern void APP_ADC_1_CallBack(U32 status);
//----------------------------------------------------------------------------------------------
/* linker-generated stack base address */
extern U32 Image$$ARM_LIB_STACKHEAP$$ZI$$Limit;

/* entry point for C run-time initialization */
extern int __main(void);

//----------------------------------------------------------------------------------------------
// end of file
//----------------------------------------------------------------------------------------------
