################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/Lcd/Lcd_program.c 

OBJS += \
./HAL/Lcd/Lcd_program.o 

C_DEPS += \
./HAL/Lcd/Lcd_program.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/Lcd/%.o: ../HAL/Lcd/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


