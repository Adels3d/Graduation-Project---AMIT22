################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_Interface.c \
../LCD_interface.c \
../SERVO_PROGRAM.c \
../main.c \
../motor_driver.c \
../timer_interface.c \
../ultrasonic.c 

OBJS += \
./DIO_Interface.o \
./LCD_interface.o \
./SERVO_PROGRAM.o \
./main.o \
./motor_driver.o \
./timer_interface.o \
./ultrasonic.o 

C_DEPS += \
./DIO_Interface.d \
./LCD_interface.d \
./SERVO_PROGRAM.d \
./main.d \
./motor_driver.d \
./timer_interface.d \
./ultrasonic.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O3 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


