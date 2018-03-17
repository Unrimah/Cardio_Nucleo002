#ifndef _DSP_FUNC_H_
#define _DSP_FUNC_H_


#include "parameters.h"
#include "FIRFilter.h"
#include "arm_math.h"
#include "arm_const_structs.h"
#include "stdint.h"
#include "stdlib.h"
#include "time.h"

extern void _Error_Handler(char *file, int line);

int32_t get_average(int32_t *buffer, uint32_t length);
void sub_average(int32_t average, int32_t *buffer, uint32_t length);
uint32_t apply_filter(int32_t *buffer, const uint32_t length, const uint32_t filter_tap);
q15_t *apply_window(int32_t *buffer, const uint32_t length, const uint32_t maxAmp);
uint32_t apply_fft(q15_t *buffer_src, q15_t *buffer_dst, const uint32_t length);

#endif //_DSP_FUNC_H_
