#ifndef _DSP_FUNC_H_
#define _DSP_FUNC_H_


#include "stdint.h"
#include "FIRFilter.h"
#include "arm_math.h"
#include "arm_const_structs.h"
#include "stdlib.h"
#include "time.h"

extern void _Error_Handler(char *file, int line);

#define _SIMULATION_
#define ADC_MEASURE_COUNT (4096)
#define ADC_BUFFER_LENGTH_HALF (ADC_MEASURE_COUNT + FIRFILTER_TAP_NUM)
#define ADC_BUFFER_LENGTH (ADC_BUFFER_LENGTH_HALF*2)

int32_t get_average(int32_t *buffer, uint32_t length);
void sub_average(int32_t average, int32_t *buffer, uint32_t length);
uint32_t apply_filter(int32_t *buffer, const uint32_t length, const uint32_t filter_tap);
q15_t *apply_window(int32_t *buffer, const uint32_t length, const uint32_t maxAmp);
uint32_t apply_fft(q15_t *buffer_src, q15_t *buffer_dst, const uint32_t length);

#ifdef _SIMULATION_

//#define PI (3.14159265359)
#define SIGNAL_RANGE (3300) // mV
#define SCALE        (4096) // 12 bit sampling
#define CONST_LEVEL  (1650) // mV
#define AMP1         (20)   // mV
#define AMP2         (20)   // mV
#define AMP3         (50)   // mV
#define AMP_T        (100)  // mV - minimal amp for target freq
#define AMP_NOISE    (20)   // mV
#define FREQ1 (1000) // constant noise freq
#define FREQ2 (2200) // out-of-scope constant noise freq
#define FREQ3 (1)   //  slow oscillations of const level freq
#define FREQ_T (1050)   // base for TARGET freq
#define VFREQ_T (50)  // Hz/sec - increasing speed for TARGET freq
#define ADC_FREQ (8400) // sampling freq
#endif // _SIMULATION_

#endif //_DSP_FUNC_H_
