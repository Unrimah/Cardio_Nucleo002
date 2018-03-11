#ifndef FIRFILTER_H_
#define FIRFILTER_H_

/*

FIR filter designed with
 http://t-filter.appspot.com

sampling frequency: 8400 Hz

fixed point precision: 16 bits

* 0 Hz - 2000 Hz
  gain = 1
  desired ripple = 5 dB
  actual ripple = n/a

* 2500 Hz - 4200 Hz
  gain = 0
  desired attenuation = -20 dB
  actual attenuation = n/a

*/
#include "stdint.h"

#define FIRFILTER_TAP_NUM 10

typedef struct {
  int32_t history[FIRFILTER_TAP_NUM];
  uint32_t last_index;
} FIRFilter;

void FIRFilter_init(FIRFilter* f);
void FIRFilter_put(FIRFilter* f, int32_t input);
int32_t FIRFilter_get(FIRFilter* f);

#endif
