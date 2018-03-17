#ifndef _PARAMETERS_CARDIO_
#define _PARAMETERS_CARDIO_

//#define _SIMULATION_

#define MAX_FREQ (2000)
#define ADC_FREQ (8400) // sampling freq
#define ADC_MEASURE_COUNT (4096)
#define FIRFILTER_TAP_NUM (10)
#define ADC_BUFFER_LENGTH_HALF (ADC_MEASURE_COUNT + FIRFILTER_TAP_NUM)
#define ADC_BUFFER_LENGTH (ADC_BUFFER_LENGTH_HALF*2)

#ifdef _SIMULATION_

#define SIGNAL_RANGE (3300) // mV
#define SCALE        (4096) // 12 bit sampling
#define CONST_LEVEL  (1650) // mV
#define AMP1         (20)   // mV
#define AMP2         (200)   // mV
#define AMP3         (50)   // mV
#define AMP_T        (100)  // mV - minimal amp for target freq
#define AMP_NOISE    (20)   // mV
#define FREQ1 (1000) // constant noise freq
#define FREQ2 (2100) // out-of-scope constant noise freq
#define FREQ3 (1)   //  slow oscillations of const level freq
#define FREQ_T (20)   // base for TARGET freq
#define VFREQ_T (50)  // Hz/sec - increasing speed for TARGET freq

#endif // _SIMULATION_



#endif //_PARAMETERS_CARDIO_
