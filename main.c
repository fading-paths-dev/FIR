#include <msp430.h> 
#include <stdint.h>
#include <float.h>
#include <stdio.h>

#define ELEMENTS  10
//static float coefficients_array[ELEMENTS] =  {0.011063, 0.031347, 0.087738, 0.159724, 0.210128, 0.210128, 0.159724, 0.087738, 0.031347, 0.011063};
static uint8_t coefficients_array[ELEMENTS] =  {11, 31, 88, 160, 210, 210, 160, 88, 33, 11};
static int32_t filter_array[ELEMENTS];
static float input_array[ELEMENTS * 10U];
static float output_array[ELEMENTS * 10U];

static float calculateFilterOutput (int32_t input);

static float calculateFilterOutput (int32_t input)
{
    float sum = 0;
    for (uint8_t i = (ELEMENTS - 1); i > 0; i--)
    {
        filter_array[i] = filter_array[i - 1];
    }
    filter_array[0] = input;
    for (uint8_t p = 0; p < ELEMENTS; p++)
    {
        sum += (filter_array[p] * coefficients_array[p]);
    }
    return (sum / 1000000.0);
}

/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	for(uint8_t i = 0; i < (ELEMENTS * 10U); i++)
	{
	    output_array[i] = calculateFilterOutput ((int32_t) (input_array[i] * 1000.0));
	}


	return 0;
}
