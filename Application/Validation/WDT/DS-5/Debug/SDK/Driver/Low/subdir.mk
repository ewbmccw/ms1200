################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/Projects/DS-5/MS1200\ -\ New/SDK/Driver/Low/CRM_API.c \
D:/Projects/DS-5/MS1200\ -\ New/SDK/Driver/Low/GPIO.c \
D:/Projects/DS-5/MS1200\ -\ New/SDK/Driver/Low/IRQ.c \
D:/Projects/DS-5/MS1200\ -\ New/SDK/Driver/Low/PMU.c \
D:/Projects/DS-5/MS1200\ -\ New/SDK/Driver/Low/RTC.c \
D:/Projects/DS-5/MS1200\ -\ New/SDK/Driver/Low/SysTick.c \
D:/Projects/DS-5/MS1200\ -\ New/SDK/Driver/Low/UART.c \
D:/Projects/DS-5/MS1200\ -\ New/SDK/Driver/Low/WDT.c 

OBJS += \
./SDK/Driver/Low/CRM_API.o \
./SDK/Driver/Low/GPIO.o \
./SDK/Driver/Low/IRQ.o \
./SDK/Driver/Low/PMU.o \
./SDK/Driver/Low/RTC.o \
./SDK/Driver/Low/SysTick.o \
./SDK/Driver/Low/UART.o \
./SDK/Driver/Low/WDT.o 


# Each subdirectory must supply rules for building sources it contributes
SDK/Driver/Low/CRM_API.o: D:/Projects/DS-5/MS1200\ -\ New/SDK/Driver/Low/CRM_API.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM C Compiler'
	armcc -D__CHECK_DEVICE_DEFINES -D__PRE_FPGA_MODE -D__PRE_FPGA_MODE_IP_TEAM -I"D:\Projects\DS-5\MS1200 - New\Application\eWBM_Main\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\BSP\LED\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\BSP\Key\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Common\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Driver\CMSIS\Device\eWBM\MS\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Driver\CMSIS\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Driver\HAL\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Driver\Low\Include" -O0 --cpu=Cortex-M3 -g -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

SDK/Driver/Low/GPIO.o: D:/Projects/DS-5/MS1200\ -\ New/SDK/Driver/Low/GPIO.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM C Compiler'
	armcc -D__CHECK_DEVICE_DEFINES -D__PRE_FPGA_MODE -D__PRE_FPGA_MODE_IP_TEAM -I"D:\Projects\DS-5\MS1200 - New\Application\eWBM_Main\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\BSP\LED\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\BSP\Key\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Common\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Driver\CMSIS\Device\eWBM\MS\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Driver\CMSIS\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Driver\HAL\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Driver\Low\Include" -O0 --cpu=Cortex-M3 -g -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

SDK/Driver/Low/IRQ.o: D:/Projects/DS-5/MS1200\ -\ New/SDK/Driver/Low/IRQ.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM C Compiler'
	armcc -D__CHECK_DEVICE_DEFINES -D__PRE_FPGA_MODE -D__PRE_FPGA_MODE_IP_TEAM -I"D:\Projects\DS-5\MS1200 - New\Application\eWBM_Main\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\BSP\LED\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\BSP\Key\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Common\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Driver\CMSIS\Device\eWBM\MS\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Driver\CMSIS\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Driver\HAL\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Driver\Low\Include" -O0 --cpu=Cortex-M3 -g -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

SDK/Driver/Low/PMU.o: D:/Projects/DS-5/MS1200\ -\ New/SDK/Driver/Low/PMU.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM C Compiler'
	armcc -D__CHECK_DEVICE_DEFINES -D__PRE_FPGA_MODE -D__PRE_FPGA_MODE_IP_TEAM -I"D:\Projects\DS-5\MS1200 - New\Application\eWBM_Main\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\BSP\LED\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\BSP\Key\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Common\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Driver\CMSIS\Device\eWBM\MS\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Driver\CMSIS\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Driver\HAL\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Driver\Low\Include" -O0 --cpu=Cortex-M3 -g -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

SDK/Driver/Low/RTC.o: D:/Projects/DS-5/MS1200\ -\ New/SDK/Driver/Low/RTC.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM C Compiler'
	armcc -D__CHECK_DEVICE_DEFINES -D__PRE_FPGA_MODE -D__PRE_FPGA_MODE_IP_TEAM -I"D:\Projects\DS-5\MS1200 - New\Application\eWBM_Main\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\BSP\LED\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\BSP\Key\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Common\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Driver\CMSIS\Device\eWBM\MS\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Driver\CMSIS\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Driver\HAL\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Driver\Low\Include" -O0 --cpu=Cortex-M3 -g -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

SDK/Driver/Low/SysTick.o: D:/Projects/DS-5/MS1200\ -\ New/SDK/Driver/Low/SysTick.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM C Compiler'
	armcc -D__CHECK_DEVICE_DEFINES -D__PRE_FPGA_MODE -D__PRE_FPGA_MODE_IP_TEAM -I"D:\Projects\DS-5\MS1200 - New\Application\eWBM_Main\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\BSP\LED\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\BSP\Key\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Common\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Driver\CMSIS\Device\eWBM\MS\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Driver\CMSIS\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Driver\HAL\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Driver\Low\Include" -O0 --cpu=Cortex-M3 -g -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

SDK/Driver/Low/UART.o: D:/Projects/DS-5/MS1200\ -\ New/SDK/Driver/Low/UART.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM C Compiler'
	armcc -D__CHECK_DEVICE_DEFINES -D__PRE_FPGA_MODE -D__PRE_FPGA_MODE_IP_TEAM -I"D:\Projects\DS-5\MS1200 - New\Application\eWBM_Main\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\BSP\LED\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\BSP\Key\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Common\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Driver\CMSIS\Device\eWBM\MS\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Driver\CMSIS\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Driver\HAL\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Driver\Low\Include" -O0 --cpu=Cortex-M3 -g -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

SDK/Driver/Low/WDT.o: D:/Projects/DS-5/MS1200\ -\ New/SDK/Driver/Low/WDT.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM C Compiler'
	armcc -D__CHECK_DEVICE_DEFINES -D__PRE_FPGA_MODE -D__PRE_FPGA_MODE_IP_TEAM -I"D:\Projects\DS-5\MS1200 - New\Application\eWBM_Main\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\BSP\LED\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\BSP\Key\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Common\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Driver\CMSIS\Device\eWBM\MS\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Driver\CMSIS\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Driver\HAL\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Driver\Low\Include" -O0 --cpu=Cortex-M3 -g -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


