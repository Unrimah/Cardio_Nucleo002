/*
 * FIRFilter.c
 *
 *  Created on: 11 мар. 2018 г.
 *      Author: VBogdanov
 */


#include "FIRFilter.h"

static int32_t filter_taps[FIRFILTER_TAP_NUM] = {
  1301,
  -3454,
  -4705,
  3748,
  15381,
  15381,
  3748,
  -4705,
  -3454,
  1301
};

void FIRFilter_init(FIRFilter* f) {
  int i;
  for(i = 0; i < FIRFILTER_TAP_NUM; ++i)
    f->history[i] = 0;
  f->last_index = 0;
}

void FIRFilter_put(FIRFilter* f, int32_t input) {
  f->history[f->last_index++] = input;
  if(f->last_index == FIRFILTER_TAP_NUM)
    f->last_index = 0;
}

int32_t FIRFilter_get(FIRFilter* f) {
  int32_t acc = 0;
  uint32_t index = f->last_index;
    index = index != 0 ? index-1 : FIRFILTER_TAP_NUM-1;
    acc += (long long)f->history[index] * filter_taps[0];
    index = index != 0 ? index-1 : FIRFILTER_TAP_NUM-1;
    acc += (long long)f->history[index] * filter_taps[1];
    index = index != 0 ? index-1 : FIRFILTER_TAP_NUM-1;
    acc += (long long)f->history[index] * filter_taps[2];
    index = index != 0 ? index-1 : FIRFILTER_TAP_NUM-1;
    acc += (long long)f->history[index] * filter_taps[3];
    index = index != 0 ? index-1 : FIRFILTER_TAP_NUM-1;
    acc += (long long)f->history[index] * filter_taps[4];
    index = index != 0 ? index-1 : FIRFILTER_TAP_NUM-1;
    acc += (long long)f->history[index] * filter_taps[5];
    index = index != 0 ? index-1 : FIRFILTER_TAP_NUM-1;
    acc += (long long)f->history[index] * filter_taps[6];
    index = index != 0 ? index-1 : FIRFILTER_TAP_NUM-1;
    acc += (long long)f->history[index] * filter_taps[7];
    index = index != 0 ? index-1 : FIRFILTER_TAP_NUM-1;
    acc += (long long)f->history[index] * filter_taps[8];
    index = index != 0 ? index-1 : FIRFILTER_TAP_NUM-1;
    acc += (long long)f->history[index] * filter_taps[9];
  return acc >> 16;
}
