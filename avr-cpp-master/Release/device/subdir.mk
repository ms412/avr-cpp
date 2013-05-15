################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../device/gpio.cpp \
../device/timer2.cpp \
../device/uart0.cpp 

OBJS += \
./device/gpio.o \
./device/timer2.o \
./device/uart0.o 

CPP_DEPS += \
./device/gpio.d \
./device/timer2.d \
./device/uart0.d 


# Each subdirectory must supply rules for building sources it contributes
device/%.o: ../device/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -Wall -Os -fpack-struct -fshort-enums -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=at90can128 -DF_CPU=14745600UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


