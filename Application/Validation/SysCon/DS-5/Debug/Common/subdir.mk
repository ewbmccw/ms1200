################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/Projects/DS-5/MS1200\ -\ New/SDK/Common/SDK_Exception.c \
D:/Projects/DS-5/MS1200\ -\ New/SDK/Common/SDK_Misc.c 

OBJS += \
./Common/SDK_Exception.o \
./Common/SDK_Misc.o 


# Each subdirectory must supply rules for building sources it contributes
Common/SDK_Exception.o: D:/Projects/DS-5/MS1200\ -\ New/SDK/Common/SDK_Exception.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM C Compiler'
	armcc -D__CHECK_DEVICE_DEFINES -D__PRE_FPGA_MODE -D__PRE_FPGA_MODE_IP_TEAM -I"D:\Projects\DS-5\MS1200 - New\Application\eWBM_Main\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\BSP\LED\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\BSP\Key\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Common\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Driver\CMSIS\Device\eWBM\MS\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Driver\CMSIS\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Driver\HAL\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Driver\Low\Include" -O0 --cpu=Cortex-M3 -g -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Common/SDK_Misc.o: D:/Projects/DS-5/MS1200\ -\ New/SDK/Common/SDK_Misc.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM C Compiler'
	armcc -D__CHECK_DEVICE_DEFINES -D__PRE_FPGA_MODE -D__PRE_FPGA_MODE_IP_TEAM -I"D:\Projects\DS-5\MS1200 - New\Application\eWBM_Main\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\BSP\LED\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\BSP\Key\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Common\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Driver\CMSIS\Device\eWBM\MS\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Driver\CMSIS\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Driver\HAL\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Driver\Low\Include" -O0 --cpu=Cortex-M3 -g -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


