################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Controller.c \
../Employee.c \
../main.c \
../menu.c \
../parser.c \
../utn.c \
../validations.c 

OBJS += \
./Controller.o \
./Employee.o \
./main.o \
./menu.o \
./parser.o \
./utn.o \
./validations.o 

C_DEPS += \
./Controller.d \
./Employee.d \
./main.d \
./menu.d \
./parser.d \
./utn.d \
./validations.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


