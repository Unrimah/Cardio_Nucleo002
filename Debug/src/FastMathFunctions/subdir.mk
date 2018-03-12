################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/FastMathFunctions/arm_cos_f32.c \
../src/FastMathFunctions/arm_cos_q15.c \
../src/FastMathFunctions/arm_cos_q31.c \
../src/FastMathFunctions/arm_sin_f32.c \
../src/FastMathFunctions/arm_sin_q15.c \
../src/FastMathFunctions/arm_sin_q31.c \
../src/FastMathFunctions/arm_sqrt_q15.c \
../src/FastMathFunctions/arm_sqrt_q31.c 

OBJS += \
./src/FastMathFunctions/arm_cos_f32.o \
./src/FastMathFunctions/arm_cos_q15.o \
./src/FastMathFunctions/arm_cos_q31.o \
./src/FastMathFunctions/arm_sin_f32.o \
./src/FastMathFunctions/arm_sin_q15.o \
./src/FastMathFunctions/arm_sin_q31.o \
./src/FastMathFunctions/arm_sqrt_q15.o \
./src/FastMathFunctions/arm_sqrt_q31.o 

C_DEPS += \
./src/FastMathFunctions/arm_cos_f32.d \
./src/FastMathFunctions/arm_cos_q15.d \
./src/FastMathFunctions/arm_cos_q31.d \
./src/FastMathFunctions/arm_sin_f32.d \
./src/FastMathFunctions/arm_sin_q15.d \
./src/FastMathFunctions/arm_sin_q31.d \
./src/FastMathFunctions/arm_sqrt_q15.d \
./src/FastMathFunctions/arm_sqrt_q31.d 


# Each subdirectory must supply rules for building sources it contributes
src/FastMathFunctions/%.o: ../src/FastMathFunctions/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F401xE -DUSE_HAL_DRIVER -DHSE_VALUE=84000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f4-hal" -I"../system/include/stm32f4xx" -I"../system/include/cmsis/device" -I"../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"../Middlewares/Third_Party/FreeRTOS/Source/include" -I"../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


