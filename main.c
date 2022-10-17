#include <msp430.h> 



#include "common.h"
#include "filter.h"


/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	resetFilter();

	runThroughAllSamplesFloat();

	resetFilter();

	runThroughAllSamplesInt();

	return 0;
}

