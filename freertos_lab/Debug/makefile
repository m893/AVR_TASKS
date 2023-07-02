################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include SERVICE/portable/MemMang/subdir.mk
-include SERVICE/portable/GCC/ATMega323/subdir.mk
-include SERVICE/subdir.mk
-include MCAL/WDT/subdir.mk
-include MCAL/UART/subdir.mk
-include MCAL/TWI/subdir.mk
-include MCAL/TIMER/subdir.mk
-include MCAL/SPI/subdir.mk
-include MCAL/GIE/subdir.mk
-include MCAL/EXTERNAL_INTERRUPT/subdir.mk
-include MCAL/DIO/subdir.mk
-include MCAL/ADC/subdir.mk
-include HAL/LED/subdir.mk
-include HAL/LCD/subdir.mk
-include HAL/KPD/subdir.mk
-include HAL/EEPROM/subdir.mk
-include APP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
freertos_lab.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: freertos_lab.elf secondary-outputs

# Tool invocations
freertos_lab.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,freertos_lab.map -mmcu=atmega32 -o "freertos_lab.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

freertos_lab.lss: freertos_lab.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S freertos_lab.elf  >"freertos_lab.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: freertos_lab.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 freertos_lab.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) freertos_lab.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
