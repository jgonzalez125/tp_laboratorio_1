################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Controller.c \
../src/LinkedList.c \
../src/Mesa.c \
../src/Mozo.c \
../src/menu.c \
../src/parser.c \
../src/trabajoPractico4.c \
../src/utn.c \
../src/validaciones.c 

OBJS += \
./src/Controller.o \
./src/LinkedList.o \
./src/Mesa.o \
./src/Mozo.o \
./src/menu.o \
./src/parser.o \
./src/trabajoPractico4.o \
./src/utn.o \
./src/validaciones.o 

C_DEPS += \
./src/Controller.d \
./src/LinkedList.d \
./src/Mesa.d \
./src/Mozo.d \
./src/menu.d \
./src/parser.d \
./src/trabajoPractico4.d \
./src/utn.d \
./src/validaciones.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


