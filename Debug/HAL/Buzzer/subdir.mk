################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/Buzzer/Buzzer_program.c 

OBJS += \
./HAL/Buzzer/Buzzer_program.o 

C_DEPS += \
./HAL/Buzzer/Buzzer_program.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/Buzzer/%.o: ../HAL/Buzzer/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\Users\yassi\Desktop\yeclipse\New_Project\HAL\Buzzer" -I"C:\Users\yassi\Desktop\yeclipse\New_Project\HAL\Dc_Motor" -I"C:\Users\yassi\Desktop\yeclipse\New_Project\HAL\EEPROM" -I"C:\Users\yassi\Desktop\yeclipse\New_Project\HAL\KeyPad" -I"C:\Users\yassi\Desktop\yeclipse\New_Project\HAL\Lcd" -I"C:\Users\yassi\Desktop\yeclipse\New_Project\HAL\Led" -I"C:\Users\yassi\Desktop\yeclipse\New_Project\HAL\PushButton" -I"C:\Users\yassi\Desktop\yeclipse\New_Project\HAL\Ssd" -I"C:\Users\yassi\Desktop\yeclipse\New_Project\HAL\TempSensor" -I"C:\Users\yassi\Desktop\yeclipse\New_Project\LIB" -I"C:\Users\yassi\Desktop\yeclipse\New_Project\MCAL\ADC" -I"C:\Users\yassi\Desktop\yeclipse\New_Project\MCAL\Dio" -I"C:\Users\yassi\Desktop\yeclipse\New_Project\MCAL\Ext_Int" -I"C:\Users\yassi\Desktop\yeclipse\New_Project\MCAL\GIE" -I"C:\Users\yassi\Desktop\yeclipse\New_Project\MCAL\Timer0" -I"C:\Users\yassi\Desktop\yeclipse\New_Project\MCAL\Timer1" -I"C:\Users\yassi\Desktop\yeclipse\New_Project\MCAL\TWI" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


