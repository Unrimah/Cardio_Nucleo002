################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/ComplexMathFunctions/arm_cmplx_conj_f32.c \
../src/ComplexMathFunctions/arm_cmplx_conj_q15.c \
../src/ComplexMathFunctions/arm_cmplx_conj_q31.c \
../src/ComplexMathFunctions/arm_cmplx_dot_prod_f32.c \
../src/ComplexMathFunctions/arm_cmplx_dot_prod_q15.c \
../src/ComplexMathFunctions/arm_cmplx_dot_prod_q31.c \
../src/ComplexMathFunctions/arm_cmplx_mag_f32.c \
../src/ComplexMathFunctions/arm_cmplx_mag_q15.c \
../src/ComplexMathFunctions/arm_cmplx_mag_q31.c \
../src/ComplexMathFunctions/arm_cmplx_mag_squared_f32.c \
../src/ComplexMathFunctions/arm_cmplx_mag_squared_q15.c \
../src/ComplexMathFunctions/arm_cmplx_mag_squared_q31.c \
../src/ComplexMathFunctions/arm_cmplx_mult_cmplx_f32.c \
../src/ComplexMathFunctions/arm_cmplx_mult_cmplx_q15.c \
../src/ComplexMathFunctions/arm_cmplx_mult_cmplx_q31.c \
../src/ComplexMathFunctions/arm_cmplx_mult_real_f32.c \
../src/ComplexMathFunctions/arm_cmplx_mult_real_q15.c \
../src/ComplexMathFunctions/arm_cmplx_mult_real_q31.c 

OBJS += \
./src/ComplexMathFunctions/arm_cmplx_conj_f32.o \
./src/ComplexMathFunctions/arm_cmplx_conj_q15.o \
./src/ComplexMathFunctions/arm_cmplx_conj_q31.o \
./src/ComplexMathFunctions/arm_cmplx_dot_prod_f32.o \
./src/ComplexMathFunctions/arm_cmplx_dot_prod_q15.o \
./src/ComplexMathFunctions/arm_cmplx_dot_prod_q31.o \
./src/ComplexMathFunctions/arm_cmplx_mag_f32.o \
./src/ComplexMathFunctions/arm_cmplx_mag_q15.o \
./src/ComplexMathFunctions/arm_cmplx_mag_q31.o \
./src/ComplexMathFunctions/arm_cmplx_mag_squared_f32.o \
./src/ComplexMathFunctions/arm_cmplx_mag_squared_q15.o \
./src/ComplexMathFunctions/arm_cmplx_mag_squared_q31.o \
./src/ComplexMathFunctions/arm_cmplx_mult_cmplx_f32.o \
./src/ComplexMathFunctions/arm_cmplx_mult_cmplx_q15.o \
./src/ComplexMathFunctions/arm_cmplx_mult_cmplx_q31.o \
./src/ComplexMathFunctions/arm_cmplx_mult_real_f32.o \
./src/ComplexMathFunctions/arm_cmplx_mult_real_q15.o \
./src/ComplexMathFunctions/arm_cmplx_mult_real_q31.o 

C_DEPS += \
./src/ComplexMathFunctions/arm_cmplx_conj_f32.d \
./src/ComplexMathFunctions/arm_cmplx_conj_q15.d \
./src/ComplexMathFunctions/arm_cmplx_conj_q31.d \
./src/ComplexMathFunctions/arm_cmplx_dot_prod_f32.d \
./src/ComplexMathFunctions/arm_cmplx_dot_prod_q15.d \
./src/ComplexMathFunctions/arm_cmplx_dot_prod_q31.d \
./src/ComplexMathFunctions/arm_cmplx_mag_f32.d \
./src/ComplexMathFunctions/arm_cmplx_mag_q15.d \
./src/ComplexMathFunctions/arm_cmplx_mag_q31.d \
./src/ComplexMathFunctions/arm_cmplx_mag_squared_f32.d \
./src/ComplexMathFunctions/arm_cmplx_mag_squared_q15.d \
./src/ComplexMathFunctions/arm_cmplx_mag_squared_q31.d \
./src/ComplexMathFunctions/arm_cmplx_mult_cmplx_f32.d \
./src/ComplexMathFunctions/arm_cmplx_mult_cmplx_q15.d \
./src/ComplexMathFunctions/arm_cmplx_mult_cmplx_q31.d \
./src/ComplexMathFunctions/arm_cmplx_mult_real_f32.d \
./src/ComplexMathFunctions/arm_cmplx_mult_real_q15.d \
./src/ComplexMathFunctions/arm_cmplx_mult_real_q31.d 


# Each subdirectory must supply rules for building sources it contributes
src/ComplexMathFunctions/%.o: ../src/ComplexMathFunctions/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F401xE -DUSE_HAL_DRIVER -DHSE_VALUE=84000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f4-hal" -I"../system/include/stm32f4xx" -I"../system/include/cmsis/device" -I"../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"../Middlewares/Third_Party/FreeRTOS/Source/include" -I"../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


