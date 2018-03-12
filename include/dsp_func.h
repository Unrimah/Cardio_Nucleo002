#ifndef _DSP_FUNC_H_
#define _DSP_FUNC_H_

#include "stdint.h"
#include "FIRFilter.h"

int32_t get_average(int32_t *buffer, uint32_t length);
void sub_average(int32_t average, int32_t *buffer, uint32_t length);
void apply_filter(int32_t *buffer, const uint32_t length, const uint32_t filter_tap);
void apply_window(int32_t *buffer, const uint32_t length);

#endif //_DSP_FUNC_H_
