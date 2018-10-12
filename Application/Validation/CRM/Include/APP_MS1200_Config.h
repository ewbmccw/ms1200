/**
************************************************************************************************
* @file		APP_MS1200_Config.h
* @author	Solution Team
* @brief	APP MS1200 configuration header file
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

#ifndef	_APP_MS1200_CONFIG_H_
#define	_APP_MS1200_CONFIG_H_

#if (__PRE_FPGA_MODE)

#if (__PRE_FPGA_MODE_IP_TEAM)

//#define CONFIG_UART_CLOCK				6 * 1000 * 1000			//6MHz
//#define CONFIG_UART_CLOCK				12 * 1000 * 1000		//12MHz
#define CONFIG_UART_CLOCK				24 * 1000 * 1000		//24MHz
//#define CONFIG_UART_CLOCK				25 * 1000 * 1000		//25MHz

#else

//#define CONFIG_UART_CLOCK				6 * 1000 * 1000			//6MHz
#define CONFIG_UART_CLOCK				12 * 1000 * 1000
//#define CONFIG_UART_CLOCK				66 * 1000 * 1000		//66MHz

#endif

#else

#define CONFIG_UART_CLOCK				12 * 1000 * 1000		//12MHz

#endif


#define CONFIG_UART_MAX_COUNT			128

//#define CONFIG_UART_PRINTF_CHANNEL	UART_1		//DR1151 daughter board
#define CONFIG_UART_PRINTF_CHANNEL		UART_3		//IP team 00001 board
#define CONFIG_UART_HOST_IF_CHANNEL		ART_3		//IP team 00001 board
//----------------------------------------------------------------------------------------------
#define CONFIG_CLK_FREQ_XTAL					24000000

#define CONFIG_CLK_SRC							CRM_REG_CLK_SRC_XTAL | CRM_REG_CLK_SRC_HS_IRC

#define CONFIG_CLK_EN_PLL                   (1)
#define CONFIG_PLL_CTRL_CLK_SEL             (CRM_REG_CLK_SRC_XTAL)
#define CONFIG_PLL_CTRL_FB_DIV              (7)
#define CONFIG_PLL_CTRL_PRE_DIV             (0)
#define CONFIG_PLL_CTRL_POST_DIV            (0)
#define CONFIG_PLL_CTRL_BWA                 (8)

#define CONFIG_CLK_EN_DIVA                  (1)
#define CONFIG_DIVA_CTRL_CLK_SEL            (CRM_REG_CLK_SRC_PLL)
#define CONFIG_DIVA_CTRL_VAL                (1)

#define CONFIG_CLK_EN_DIVB                  (1)
#define CONFIG_DIVB_CTRL_CLK_SEL            (CRM_REG_CLK_SRC_DIVA)
#define CONFIG_DIVB_CTRL_VAL                (1)

#define CONFIG_CLK_EN_DIVC                  (1)
#define CONFIG_DIVC_CTRL_CLK_SEL            (CRM_REG_CLK_SRC_DIVA)
#define CONFIG_DIVC_CTRL_VAL                (1)

#define CONFIG_CLK_EN_DIVD                  (1)
#define CONFIG_DIVD_CTRL_CLK_SEL            (CRM_REG_CLK_SRC_DIVA)
#define CONFIG_DIVD_CTRL_VAL                (1)

#define CONFIG_SYS_CLK_CTRL_SYS_CLK_SEL     (CRM_REG_CLK_SRC_DIVA)
#define CONFIG_SYS_CLK_CTRL_CPU_PRES        (0)
#define CONFIG_SYS_CLK_CTRL_APB_PRES        (1)

#define CONFIG_CLK_EN_SPIF                  (1)
#define CONFIG_SPIF_CLK_CTRL_CLK_SEL        (CRM_REG_CLK_SRC_PLL)

#define CONFIG_CLK_EN_UART                  (1)
#define CONFIG_PERI_CLK_SEL_UART            (CRM_REG_CLK_SRC_DIVB)

#define CONFIG_CLK_EN_SPI                   (1)
#define CONFIG_PERI_CLK_SEL_SPI             (CRM_REG_CLK_SRC_DIVB)

#define CONFIG_CLK_EN_SDIOH                 (0)
#define CONFIG_PERI_CLK_SEL_SDIOH           (CRM_REG_CLK_SRC_DIVA)

#define CONFIG_CLK_EN_CLKOUT1               (0)
#define CONFIG_PERI_CLK_SEL_CLKOUT1         (0)

#define CONFIG_CLK_EN_CLKOUT2               (0)
#define CONFIG_PERI_CLK_SEL_CLKOUT2         (0)

#endif

//----------------------------------------------------------------------------------------------
// end of file
//----------------------------------------------------------------------------------------------
