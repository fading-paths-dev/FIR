#include <msp430.h> 
#include <stdint.h>
#include <float.h>

#define ELEMENTS  10
static float coefficients_array[ELEMENTS] =  {0.011063, 0.031347, 0.087738, 0.159724, 0.210128, 0.210128, 0.159724, 0.087738, 0.031347, 0.011063};
static float filter_array[ELEMENTS];

static float calculateFilterOutput (float input);

static float calculateFilterOutput (float input)
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
    return sum;
}

/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	return 0;
}
