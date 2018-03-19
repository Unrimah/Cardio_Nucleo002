/*
 * dsp_func.c
 *
 *  Created on: 12 мар. 2018 г.
 *      Author: Vladimir Bogdanov
 */
#include "dsp_func.h"
#include "stdlib.h"
#include "limits.h"

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

uint32_t apply_filter(int32_t *buffer, const uint32_t length, const uint32_t filter_tap)
{
	FIRFilter f;
	uint32_t i;
	uint32_t maxAmp = 0;

	FIRFilter_init(&f);
	for (i = 0; i < filter_tap; ++i)
	{
		FIRFilter_put(&f, buffer[i]);
	}

	for (i = 0; i < length - filter_tap; ++i)
	{
		buffer[i] = FIRFilter_get(&f);
		if ((uint32_t) abs(buffer[i]) > maxAmp)
		{
			maxAmp = abs(buffer[i]);
		}
		FIRFilter_put(&f, buffer[i + filter_tap]);
	}
	return (maxAmp);
}

q15_t *apply_window(int32_t *buffer_i, const uint32_t length, const uint32_t maxAmp)
{
	int32_t a = (length - 1) / 2;
	int32_t w;
	uint32_t n;
	q15_t *buffer_q15 = (q15_t*) buffer_i;
	q15_t k = SHRT_MAX / maxAmp; // normalization coefficient


	for (n = 0; n < length; ++n)
	{
		w = SHRT_MAX - abs((SHRT_MAX * n) / a - SHRT_MAX);
		buffer_q15[2 * n] = k * (buffer_i[n] * w) / SHRT_MAX;
		buffer_q15[2 * n + 1] = 0;
	}
	return buffer_q15;
}

uint32_t apply_fft(q15_t *buffer_src, q15_t *buffer_dst, const uint32_t fftSize)
{
	uint32_t maxIndex = 0;
	q15_t maxValue;
	uint32_t ifftFlag = 0;
	uint32_t doBitReverse = 1;
	arm_cfft_instance_q15 const *S;

	switch (fftSize)
	{
	case 16:
		S = &arm_cfft_sR_q15_len16;
		break;
	case 32:
		S = &arm_cfft_sR_q15_len32;
		break;
	case 64:
		S = &arm_cfft_sR_q15_len64;
		break;
	case 128:
		S = &arm_cfft_sR_q15_len128;
		break;
	case 256:
		S = &arm_cfft_sR_q15_len256;
		break;
	case 512:
		S = &arm_cfft_sR_q15_len512;
		break;
	case 1024:
		S = &arm_cfft_sR_q15_len1024;
		break;
	case 2048:
		S = &arm_cfft_sR_q15_len2048;
		break;
	case 4096:
		S = &arm_cfft_sR_q15_len4096;
		break;
	default:
		S = NULL;
	    _Error_Handler(__FILE__, __LINE__);

	}
	  /* Process the data through the CFFT/CIFFT module */
	  arm_cfft_q15(S, buffer_src, ifftFlag, doBitReverse);

	  /* Process the data through the Complex Magnitude Module for
	  calculating the magnitude at each bin */
	  arm_cmplx_mag_q15(buffer_src, buffer_dst, fftSize);

	  /* Calculates maxValue and returns corresponding BIN value */
	  arm_max_q15(buffer_dst, MAX_FREQ * ADC_MEASURE_COUNT / ADC_FREQ, &maxValue, &maxIndex); // 975

	  return maxIndex;

}
