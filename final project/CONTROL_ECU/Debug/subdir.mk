################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CONTROL_ECU.c \
../Utilities.c \
../buzzer.c \
../dcmotor.c \
../external_eeprom.c \
../gpio.c \
../timer0.c \
../timer1.c \
../twi.c \
../usart.c 

OBJS += \
./CONTROL_ECU.o \
./Utilities.o \
./buzzer.o \
./dcmotor.o \
./external_eeprom.o \
./gpio.o \
./timer0.o \
./timer1.o \
./twi.o \
./usart.o 

C_DEPS += \
./CONTROL_ECU.d \
./Utilities.d \
./buzzer.d \
./dcmotor.d \
./external_eeprom.d \
./gpio.d \
./timer0.d \
./timer1.d \
./twi.d \
./usart.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


