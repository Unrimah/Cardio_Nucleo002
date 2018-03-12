/*
 * dsp_func.c
 *
 *  Created on: 12 мар. 2018 г.
 *      Author: NIOKR
 */
#include "dsp_func.h"

int32_t get_average(int32_t *buffer, uint32_t length)
{
	int32_t accumulator = 0;
	uint32_t i;
	for (i = 0; i < length; ++i)
	{
		buffer[i] &= 0x0FFF; // make 0x0509 from 0xFFFF0509 that sometimes happen
		accumulator += buffer[i] << 4; // 65535 representing maximum amplitude
	}
	return (accumulator / length);
}

void sub_average(int32_t average, int32_t *buffer, uint32_t length)
{
	uint32_t i;
	for (i = 0; i < length; ++i)
	{
		buffer[i] -= average;
	}
}

void apply_filter(int32_t *buffer, const uint32_t length, const uint32_t filter_tap)
{
	FIRFilter f;
	uint32_t i;

	FIRFilter_init(&f);
	for (i = 0; i < filter_tap; ++i)
	{
		FIRFilter_put(&f, buffer[i]);
	}

	for (i = 0; i < length - filter_tap; ++i)
	{
		buffer[i] = FIRFilter_get(&f);
		FIRFilter_put(&f, buffer[i + filter_tap]);
	}
}

void apply_window(int32_t *buffer, const uint32_t length)
{
	int32_t a = (length - 1) / 2;
	int32_t w;
	int32_t n;

	for (n = 0; n < length; ++n)
	{
		w = 65536 - abs((65536  *n) / a - 65536);
		buffer[n] = (buffer[n] * w) / 65536;
	}

}
