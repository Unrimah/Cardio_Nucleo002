#ifndef _DSP_FUNC_H_
#define _DSP_FUNC_H_


#include "stdint.h"
#include "FIRFilter.h"
#include "arm_math.h"

#define ADC_MEASURE_COUNT (2048) //(4096)
#define ADC_BUFFER_LENGTH_HALF (ADC_MEASURE_COUNT + FIRFILTER_TAP_NUM)
#define ADC_BUFFER_LENGTH (ADC_BUFFER_LENGTH_HALF*2)

int32_t get_average(int32_t *buffer, uint32_t length);
void sub_average(int32_t average, int32_t *buffer, uint32_t length);
void apply_filter(int32_t *buffer, const uint32_t length, const uint32_t filter_tap);
float32_t *apply_window(int32_t *buffer, const uint32_t length);
uint32_t apply_fft(float32_t *buffer_src, float32_t *buffer_dst, const uint32_t length);

#endif //_DSP_FUNC_H_
