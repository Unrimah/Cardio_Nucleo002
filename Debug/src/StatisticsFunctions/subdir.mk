################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/StatisticsFunctions/arm_max_f32.c \
../src/StatisticsFunctions/arm_max_q15.c \
../src/StatisticsFunctions/arm_max_q31.c \
../src/StatisticsFunctions/arm_max_q7.c \
../src/StatisticsFunctions/arm_mean_f32.c \
../src/StatisticsFunctions/arm_mean_q15.c \
../src/StatisticsFunctions/arm_mean_q31.c \
../src/StatisticsFunctions/arm_mean_q7.c \
../src/StatisticsFunctions/arm_min_f32.c \
../src/StatisticsFunctions/arm_min_q15.c \
../src/StatisticsFunctions/arm_min_q31.c \
../src/StatisticsFunctions/arm_min_q7.c \
../src/StatisticsFunctions/arm_power_f32.c \
../src/StatisticsFunctions/arm_power_q15.c \
../src/StatisticsFunctions/arm_power_q31.c \
../src/StatisticsFunctions/arm_power_q7.c \
../src/StatisticsFunctions/arm_rms_f32.c \
../src/StatisticsFunctions/arm_rms_q15.c \
../src/StatisticsFunctions/arm_rms_q31.c \
../src/StatisticsFunctions/arm_std_f32.c \
../src/StatisticsFunctions/arm_std_q15.c \
../src/StatisticsFunctions/arm_std_q31.c \
../src/StatisticsFunctions/arm_var_f32.c \
../src/StatisticsFunctions/arm_var_q15.c \
../src/StatisticsFunctions/arm_var_q31.c 

OBJS += \
./src/StatisticsFunctions/arm_max_f32.o \
./src/StatisticsFunctions/arm_max_q15.o \
./src/StatisticsFunctions/arm_max_q31.o \
./src/StatisticsFunctions/arm_max_q7.o \
./src/StatisticsFunctions/arm_mean_f32.o \
./src/StatisticsFunctions/arm_mean_q15.o \
./src/StatisticsFunctions/arm_mean_q31.o \
./src/StatisticsFunctions/arm_mean_q7.o \
./src/StatisticsFunctions/arm_min_f32.o \
./src/StatisticsFunctions/arm_min_q15.o \
./src/StatisticsFunctions/arm_min_q31.o \
./src/StatisticsFunctions/arm_min_q7.o \
./src/StatisticsFunctions/arm_power_f32.o \
./src/StatisticsFunctions/arm_power_q15.o \
./src/StatisticsFunctions/arm_power_q31.o \
./src/StatisticsFunctions/arm_power_q7.o \
./src/StatisticsFunctions/arm_rms_f32.o \
./src/StatisticsFunctions/arm_rms_q15.o \
./src/StatisticsFunctions/arm_rms_q31.o \
./src/StatisticsFunctions/arm_std_f32.o \
./src/StatisticsFunctions/arm_std_q15.o \
./src/StatisticsFunctions/arm_std_q31.o \
./src/StatisticsFunctions/arm_var_f32.o \
./src/StatisticsFunctions/arm_var_q15.o \
./src/StatisticsFunctions/arm_var_q31.o 

C_DEPS += \
./src/StatisticsFunctions/arm_max_f32.d \
./src/StatisticsFunctions/arm_max_q15.d \
./src/StatisticsFunctions/arm_max_q31.d \
./src/StatisticsFunctions/arm_max_q7.d \
./src/StatisticsFunctions/arm_mean_f32.d \
./src/StatisticsFunctions/arm_mean_q15.d \
./src/StatisticsFunctions/arm_mean_q31.d \
./src/StatisticsFunctions/arm_mean_q7.d \
./src/StatisticsFunctions/arm_min_f32.d \
./src/StatisticsFunctions/arm_min_q15.d \
./src/StatisticsFunctions/arm_min_q31.d \
./src/StatisticsFunctions/arm_min_q7.d \
./src/StatisticsFunctions/arm_power_f32.d \
./src/StatisticsFunctions/arm_power_q15.d \
./src/StatisticsFunctions/arm_power_q31.d \
./src/StatisticsFunctions/arm_power_q7.d \
./src/StatisticsFunctions/arm_rms_f32.d \
./src/StatisticsFunctions/arm_rms_q15.d \
./src/StatisticsFunctions/arm_rms_q31.d \
./src/StatisticsFunctions/arm_std_f32.d \
./src/StatisticsFunctions/arm_std_q15.d \
./src/StatisticsFunctions/arm_std_q31.d \
./src/StatisticsFunctions/arm_var_f32.d \
./src/StatisticsFunctions/arm_var_q15.d \
./src/StatisticsFunctions/arm_var_q31.d 


# Each subdirectory must supply rules for building sources it contributes
src/StatisticsFunctions/%.o: ../src/StatisticsFunctions/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F401xE -DUSE_HAL_DRIVER -DHSE_VALUE=84000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f4-hal" -I"../system/include/stm32f4xx" -I"../system/include/cmsis/device" -I"../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"../Middlewares/Third_Party/FreeRTOS/Source/include" -I"../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


