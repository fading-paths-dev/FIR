#include <msp430.h> 



#include "common.h"
#include "filter.h"

static int8_t retVal = SUCCESS;


/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	resetFilter();

	while (retVal == SUCCESS)
	{
	    //TODO make individual functions for each int/float/impulse/step/sine situation and test those separately
	    for (uint8_t i = 0; i < SAMPLES; i++)
	    {
	        outputFloat[i] = calculateFilterOutputFloat(inputFloat[i]);
	        outputInt[i] = calculateFilterOutputInt(inputInt[i]);
	    }
	}

	return 0;
}

