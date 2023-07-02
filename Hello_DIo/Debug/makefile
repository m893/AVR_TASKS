################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
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
Hello_DIo.lss \

FLASH_IMAGE += \
Hello_DIo.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Hello_DIo.elf secondary-outputs

# Tool invocations
Hello_DIo.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Hello_DIo.map -mmcu=atmega32 -o "Hello_DIo.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Hello_DIo.lss: Hello_DIo.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Hello_DIo.elf  >"Hello_DIo.lss"
	@echo 'Finished building: $@'
	@echo ' '

Hello_DIo.hex: Hello_DIo.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Hello_DIo.elf  "Hello_DIo.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Hello_DIo.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Hello_DIo.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Hello_DIo.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
