################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/Projects/DS-5/MS1200\ -\ New/SDK/Middleware/Third_Party/FreeRTOS/Source/croutine.c \
D:/Projects/DS-5/MS1200\ -\ New/SDK/Middleware/Third_Party/FreeRTOS/Source/event_groups.c \
D:/Projects/DS-5/MS1200\ -\ New/SDK/Middleware/Third_Party/FreeRTOS/Source/list.c \
D:/Projects/DS-5/MS1200\ -\ New/SDK/Middleware/Third_Party/FreeRTOS/Source/queue.c \
D:/Projects/DS-5/MS1200\ -\ New/SDK/Middleware/Third_Party/FreeRTOS/Source/tasks.c \
D:/Projects/DS-5/MS1200\ -\ New/SDK/Middleware/Third_Party/FreeRTOS/Source/timers.c 

OBJS += \
./SDK/Middleware/Third_Party/FreeRTOS/Source/croutine.o \
./SDK/Middleware/Third_Party/FreeRTOS/Source/event_groups.o \
./SDK/Middleware/Third_Party/FreeRTOS/Source/list.o \
./SDK/Middleware/Third_Party/FreeRTOS/Source/queue.o \
./SDK/Middleware/Third_Party/FreeRTOS/Source/tasks.o \
./SDK/Middleware/Third_Party/FreeRTOS/Source/timers.o 


# Each subdirectory must supply rules for building sources it contributes
SDK/Middleware/Third_Party/FreeRTOS/Source/croutine.o: D:/Projects/DS-5/MS1200\ -\ New/SDK/Middleware/Third_Party/FreeRTOS/Source/croutine.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM C Compiler'
	armcc -D__CHECK_DEVICE_DEFINES -D__CC_ARM -D__PRE_FPGA_MODE -D__PRE_FPGA_MODE_IP_TEAM -I"D:\Projects\DS-5\MS1200 - New\SDK\Middleware\Third_Party\FreeRTOS\Source\CMSIS_RTOS" -I"D:\Projects\DS-5\MS1200 - New\SDK\Middleware\Third_Party\FreeRTOS\Source\include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Middleware\Third_Party\FreeRTOS\Source\portable\DS-5\ARM_CM3" -I"D:\Projects\DS-5\MS1200 - New\Application\eWBM_Main\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\BSP\LED\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\BSP\Key\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Common\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Driver\CMSIS\Device\eWBM\MS\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Driver\CMSIS\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Driver\HAL\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Driver\Low\Include" -O0 --cpu=Cortex-M3 -g -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

SDK/Middleware/Third_Party/FreeRTOS/Source/event_groups.o: D:/Projects/DS-5/MS1200\ -\ New/SDK/Middleware/Third_Party/FreeRTOS/Source/event_groups.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM C Compiler'
	armcc -D__CHECK_DEVICE_DEFINES -D__CC_ARM -D__PRE_FPGA_MODE -D__PRE_FPGA_MODE_IP_TEAM -I"D:\Projects\DS-5\MS1200 - New\SDK\Middleware\Third_Party\FreeRTOS\Source\CMSIS_RTOS" -I"D:\Projects\DS-5\MS1200 - New\SDK\Middleware\Third_Party\FreeRTOS\Source\include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Middleware\Third_Party\FreeRTOS\Source\portable\DS-5\ARM_CM3" -I"D:\Projects\DS-5\MS1200 - New\Application\eWBM_Main\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\BSP\LED\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\BSP\Key\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Common\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Driver\CMSIS\Device\eWBM\MS\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Driver\CMSIS\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Driver\HAL\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Driver\Low\Include" -O0 --cpu=Cortex-M3 -g -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

SDK/Middleware/Third_Party/FreeRTOS/Source/list.o: D:/Projects/DS-5/MS1200\ -\ New/SDK/Middleware/Third_Party/FreeRTOS/Source/list.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM C Compiler'
	armcc -D__CHECK_DEVICE_DEFINES -D__CC_ARM -D__PRE_FPGA_MODE -D__PRE_FPGA_MODE_IP_TEAM -I"D:\Projects\DS-5\MS1200 - New\SDK\Middleware\Third_Party\FreeRTOS\Source\CMSIS_RTOS" -I"D:\Projects\DS-5\MS1200 - New\SDK\Middleware\Third_Party\FreeRTOS\Source\include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Middleware\Third_Party\FreeRTOS\Source\portable\DS-5\ARM_CM3" -I"D:\Projects\DS-5\MS1200 - New\Application\eWBM_Main\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\BSP\LED\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\BSP\Key\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Common\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Driver\CMSIS\Device\eWBM\MS\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Driver\CMSIS\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Driver\HAL\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Driver\Low\Include" -O0 --cpu=Cortex-M3 -g -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

SDK/Middleware/Third_Party/FreeRTOS/Source/queue.o: D:/Projects/DS-5/MS1200\ -\ New/SDK/Middleware/Third_Party/FreeRTOS/Source/queue.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM C Compiler'
	armcc -D__CHECK_DEVICE_DEFINES -D__CC_ARM -D__PRE_FPGA_MODE -D__PRE_FPGA_MODE_IP_TEAM -I"D:\Projects\DS-5\MS1200 - New\SDK\Middleware\Third_Party\FreeRTOS\Source\CMSIS_RTOS" -I"D:\Projects\DS-5\MS1200 - New\SDK\Middleware\Third_Party\FreeRTOS\Source\include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Middleware\Third_Party\FreeRTOS\Source\portable\DS-5\ARM_CM3" -I"D:\Projects\DS-5\MS1200 - New\Application\eWBM_Main\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\BSP\LED\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\BSP\Key\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Common\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Driver\CMSIS\Device\eWBM\MS\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Driver\CMSIS\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Driver\HAL\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Driver\Low\Include" -O0 --cpu=Cortex-M3 -g -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

SDK/Middleware/Third_Party/FreeRTOS/Source/tasks.o: D:/Projects/DS-5/MS1200\ -\ New/SDK/Middleware/Third_Party/FreeRTOS/Source/tasks.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM C Compiler'
	armcc -D__CHECK_DEVICE_DEFINES -D__CC_ARM -D__PRE_FPGA_MODE -D__PRE_FPGA_MODE_IP_TEAM -I"D:\Projects\DS-5\MS1200 - New\SDK\Middleware\Third_Party\FreeRTOS\Source\CMSIS_RTOS" -I"D:\Projects\DS-5\MS1200 - New\SDK\Middleware\Third_Party\FreeRTOS\Source\include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Middleware\Third_Party\FreeRTOS\Source\portable\DS-5\ARM_CM3" -I"D:\Projects\DS-5\MS1200 - New\Application\eWBM_Main\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\BSP\LED\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\BSP\Key\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Common\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Driver\CMSIS\Device\eWBM\MS\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Driver\CMSIS\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Driver\HAL\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Driver\Low\Include" -O0 --cpu=Cortex-M3 -g -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

SDK/Middleware/Third_Party/FreeRTOS/Source/timers.o: D:/Projects/DS-5/MS1200\ -\ New/SDK/Middleware/Third_Party/FreeRTOS/Source/timers.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM C Compiler'
	armcc -D__CHECK_DEVICE_DEFINES -D__CC_ARM -D__PRE_FPGA_MODE -D__PRE_FPGA_MODE_IP_TEAM -I"D:\Projects\DS-5\MS1200 - New\SDK\Middleware\Third_Party\FreeRTOS\Source\CMSIS_RTOS" -I"D:\Projects\DS-5\MS1200 - New\SDK\Middleware\Third_Party\FreeRTOS\Source\include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Middleware\Third_Party\FreeRTOS\Source\portable\DS-5\ARM_CM3" -I"D:\Projects\DS-5\MS1200 - New\Application\eWBM_Main\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\BSP\LED\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\BSP\Key\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Common\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Driver\CMSIS\Device\eWBM\MS\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Driver\CMSIS\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Driver\HAL\Include" -I"D:\Projects\DS-5\MS1200 - New\SDK\Driver\Low\Include" -O0 --cpu=Cortex-M3 -g -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


