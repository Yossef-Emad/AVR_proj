################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/Timer1/subdir.mk
-include MCAL/Timer0/subdir.mk
-include MCAL/TWI/subdir.mk
-include MCAL/GIE/subdir.mk
-include MCAL/Ext_Int/subdir.mk
-include MCAL/Dio/subdir.mk
-include MCAL/ADC/subdir.mk
-include HAL/TempSensor/subdir.mk
-include HAL/Ssd/subdir.mk
-include HAL/PushButton/subdir.mk
-include HAL/Led/subdir.mk
-include HAL/Lcd/subdir.mk
-include HAL/KeyPad/subdir.mk
-include HAL/EEPROM/subdir.mk
-include HAL/Dc_Motor/subdir.mk
-include HAL/Buzzer/subdir.mk
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
New_Project.lss \

FLASH_IMAGE += \
New_Project.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: New_Project.elf secondary-outputs

# Tool invocations
New_Project.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,New_Project.map -mmcu=atmega32 -o "New_Project.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

New_Project.lss: New_Project.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S New_Project.elf  >"New_Project.lss"
	@echo 'Finished building: $@'
	@echo ' '

New_Project.hex: New_Project.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex New_Project.elf  "New_Project.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: New_Project.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 New_Project.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) New_Project.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
