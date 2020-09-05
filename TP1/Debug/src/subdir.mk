################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/menu.c \
../src/operaciones.c \
../src/utn.c \
../src/utn_tp1_laboratorio.c 

OBJS += \
./src/menu.o \
./src/operaciones.o \
./src/utn.o \
./src/utn_tp1_laboratorio.o 

C_DEPS += \
./src/menu.d \
./src/operaciones.d \
./src/utn.d \
./src/utn_tp1_laboratorio.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


