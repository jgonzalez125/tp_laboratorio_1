################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../unitTests/src/addNodeTest.c \
../unitTests/src/addTest.c \
../unitTests/src/clearTest.c \
../unitTests/src/cloneTest.c \
../unitTests/src/containsAllTest.c \
../unitTests/src/containsTest.c \
../unitTests/src/deleteLinkedListTest.c \
../unitTests/src/getNodeTest.c \
../unitTests/src/getTest.c \
../unitTests/src/indexOfTest.c \
../unitTests/src/isEmptyTest.c \
../unitTests/src/lenTest.c \
../unitTests/src/main_test.c \
../unitTests/src/newTest.c \
../unitTests/src/popTest.c \
../unitTests/src/pushTest.c \
../unitTests/src/removeTest.c \
../unitTests/src/setTest.c \
../unitTests/src/sortTest.c \
../unitTests/src/subListTest.c 

OBJS += \
./unitTests/src/addNodeTest.o \
./unitTests/src/addTest.o \
./unitTests/src/clearTest.o \
./unitTests/src/cloneTest.o \
./unitTests/src/containsAllTest.o \
./unitTests/src/containsTest.o \
./unitTests/src/deleteLinkedListTest.o \
./unitTests/src/getNodeTest.o \
./unitTests/src/getTest.o \
./unitTests/src/indexOfTest.o \
./unitTests/src/isEmptyTest.o \
./unitTests/src/lenTest.o \
./unitTests/src/main_test.o \
./unitTests/src/newTest.o \
./unitTests/src/popTest.o \
./unitTests/src/pushTest.o \
./unitTests/src/removeTest.o \
./unitTests/src/setTest.o \
./unitTests/src/sortTest.o \
./unitTests/src/subListTest.o 

C_DEPS += \
./unitTests/src/addNodeTest.d \
./unitTests/src/addTest.d \
./unitTests/src/clearTest.d \
./unitTests/src/cloneTest.d \
./unitTests/src/containsAllTest.d \
./unitTests/src/containsTest.d \
./unitTests/src/deleteLinkedListTest.d \
./unitTests/src/getNodeTest.d \
./unitTests/src/getTest.d \
./unitTests/src/indexOfTest.d \
./unitTests/src/isEmptyTest.d \
./unitTests/src/lenTest.d \
./unitTests/src/main_test.d \
./unitTests/src/newTest.d \
./unitTests/src/popTest.d \
./unitTests/src/pushTest.d \
./unitTests/src/removeTest.d \
./unitTests/src/setTest.d \
./unitTests/src/sortTest.d \
./unitTests/src/subListTest.d 


# Each subdirectory must supply rules for building sources it contributes
unitTests/src/%.o: ../unitTests/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


