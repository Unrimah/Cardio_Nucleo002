/*
 * dsp_func.c
 *
 *  Created on: 12 мар. 2018 г.
 *      Author: NIOKR
 */
#include "dsp_func.h"
#include "stdlib.h"

int32_t get_average(int32_t *buffer, uint32_t length)
{
	int32_t accumulator = 0;
	uint32_t i;
	for (i = 0; i < length; ++i)
	{
		buffer[i] = (buffer[i] & 0x0FFF) << 4; // make 0x0509 from 0xFFFF0509 that sometimes happen
		accumulator += buffer[i]; 		 // 65535 representing maximum amplitude
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

q15_t *apply_window(int32_t *buffer_i, const uint32_t length)
{
	int32_t a = (length - 1) / 2;
	int32_t w;
	uint32_t n;
//	float32_t *buffer_f = (float32_t*) buffer_i;
	q15_t *buffer_q15 = (q15_t*) buffer_i;

	for (n = 0; n < length; ++n)
	{
		w = 65536 - abs((65536 * n) / a - 65536);
//		buffer_f[n] = (float) (buffer_i[n] * w) / 65536;
		buffer_q15[2 * n] = (buffer_i[n] * w) / 65536;
		buffer_q15[2 * n + 1] = 0;
	}
	return buffer_q15;
}

uint32_t apply_fft(q15_t *buffer_src, q15_t *buffer_dst, const uint32_t fftSize)
{
	uint32_t maxIndex = 0;
	q15_t maxValue;
//	uint32_t fftSize = ADC_MEASURE_COUNT; //4096
	uint32_t ifftFlag = 0;
	uint32_t doBitReverse = 1;

	switch (fftSize)
	{
	case 4096:
		break;
	default:
	    _Error_Handler(__FILE__, __LINE__);

	}
	  /* Process the data through the CFFT/CIFFT module */
	  arm_cfft_q15(&arm_cfft_sR_q15_len4096, buffer_src, ifftFlag, doBitReverse);

	  /* Process the data through the Complex Magnitude Module for
	  calculating the magnitude at each bin */
	  arm_cmplx_mag_q15(buffer_src, buffer_dst, fftSize);

	  /* Calculates maxValue and returns corresponding BIN value */
	  arm_max_q15(buffer_dst, fftSize, &maxValue, &maxIndex);

	  return maxIndex;
/*
	arm_status rfft_status;
	arm_rfft_fast_instance_f32 S;

	rfft_status = arm_rfft_fast_init_f32(&S, ADC_MEASURE_COUNT);

	if(rfft_status == ARM_MATH_SUCCESS)
	{
	    arm_cfft_q15(&S, buffer_src, buffer_dst, 0);//выполнение БФП
	    arm_cmplx_mag_q15(buffer_dst, buffer_src, ADC_MEASURE_COUNT);//вычисляем амплитуды гармоник
	}
*/

}
