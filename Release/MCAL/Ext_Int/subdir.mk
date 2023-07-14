################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/Ext_Int/Ext_Int_program.c 

OBJS += \
./MCAL/Ext_Int/Ext_Int_program.o 

C_DEPS += \
./MCAL/Ext_Int/Ext_Int_program.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/Ext_Int/%.o: ../MCAL/Ext_Int/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


