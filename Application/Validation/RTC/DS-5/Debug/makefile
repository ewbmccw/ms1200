################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := clean

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include SDK/Driver/Low/subdir.mk
-include SDK/Driver/Low/Include/subdir.mk
-include SDK/Driver/HAL/subdir.mk
-include SDK/Common/subdir.mk
-include SDK/BSP/LED/subdir.mk
-include SDK/BSP/Key/subdir.mk
-include objects.mk

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: MS1200\ -\ Validation\ -\ RTC.axf

# Tool invocations
MS1200\ -\ Validation\ -\ RTC.axf: $(OBJS) ..\scatter.scat $(USER_OBJS) $(LIBS)
	@echo 'Building target: $@'
	@echo 'Invoking: ARM Linker'
	armlink --scatter="..\scatter.scat" --map --info=sizes --list=MS1200.map -o "MS1200 - Validation - RTC.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS) $(EXECUTABLES) "MS1200 - Validation - RTC.axf" 
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
