################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APPLICATION/HMI_ECU.c \
../APPLICATION/Utilities.c 

OBJS += \
./APPLICATION/HMI_ECU.o \
./APPLICATION/Utilities.o 

C_DEPS += \
./APPLICATION/HMI_ECU.d \
./APPLICATION/Utilities.d 


# Each subdirectory must supply rules for building sources it contributes
APPLICATION/%.o: ../APPLICATION/%.c APPLICATION/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


