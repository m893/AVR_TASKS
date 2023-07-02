################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SERVICE/croutine.c \
../SERVICE/event_groups.c \
../SERVICE/list.c \
../SERVICE/queue.c \
../SERVICE/stream_buffer.c \
../SERVICE/tasks.c \
../SERVICE/timers.c 

OBJS += \
./SERVICE/croutine.o \
./SERVICE/event_groups.o \
./SERVICE/list.o \
./SERVICE/queue.o \
./SERVICE/stream_buffer.o \
./SERVICE/tasks.o \
./SERVICE/timers.o 

C_DEPS += \
./SERVICE/croutine.d \
./SERVICE/event_groups.d \
./SERVICE/list.d \
./SERVICE/queue.d \
./SERVICE/stream_buffer.d \
./SERVICE/tasks.d \
./SERVICE/timers.d 


# Each subdirectory must supply rules for building sources it contributes
SERVICE/%.o: ../SERVICE/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


