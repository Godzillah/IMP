################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FITkit3-demo/Sources/main.c 

OBJS += \
./FITkit3-demo/Sources/main.o 

C_DEPS += \
./FITkit3-demo/Sources/main.d 


# Each subdirectory must supply rules for building sources it contributes
FITkit3-demo/Sources/%.o: ../FITkit3-demo/Sources/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"../Sources" -I"../Includes" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


