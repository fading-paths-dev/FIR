/*
 * filter.c
 *
 *  Created on: 6 Oct 2022
 *      Author: Kathryn.Whitehead
 */

#include "filter.h"

static int32_t filter_array_int[ELEMENTS];
static uint8_t coefficients_array_int[ELEMENTS] =  {11, 32, 90, 164, 215, 215, 164, 90, 32, 11}; // *1024

static float filter_array_float[ELEMENTS];
static float coefficients_array_float[ELEMENTS] =  {0.0110631440768700, 0.0313470712799202, 0.0877380341023896, 0.159724142609811, 0.210127607931010, 0.210127607931010, 0.159724142609811, 0.0877380341023896, 0.0313470712799202, 0.0110631440768700};

static void pushFilterElementsInt (int32_t data);
static void pushFilterElementsFloat(float data);


int32_t calculateFilterOutputInt (int32_t input)
{
    float sum = 0;

    pushFilterElementsInt(input);

    for (uint8_t p = 0; p < ELEMENTS; p++)
    {
        sum += filter_array_int[p] * coefficients_array_int[p];
    }

    return (int32_t)(sum / MULTIPLIER_FLOAT);
}

float calculateFilterOutputFloat (float input)
{
    float sum = 0;
    pushFilterElementsFloat(input);

    for (uint8_t p = 0; p < ELEMENTS; p++)
    {
        sum += filter_array_float[p] * coefficients_array_float[p];
    }

    return sum;
}


void resetFilter (void)
{
    for (uint8_t i = 0; i < ELEMENTS; i++)
    {
        filter_array_float[i] = 0x00;
        filter_array_int[i] = 0x00;
    }
}


static void pushFilterElementsInt (int32_t data)
{
    for (uint8_t i = (ELEMENTS - 1); i > 0; i--)
    {
        filter_array_int[i] = filter_array_int[i - 1];
    }
    filter_array_int[0] = data;
}

static void pushFilterElementsFloat(float data)
{
    for (uint8_t i = (ELEMENTS - 1); i > 0; i--)
    {
        filter_array_float[i] = filter_array_float[i - 1];
    }
    filter_array_float[0] = data;
}

void runThroughAllSamplesInt(void)
{
    for (uint8_t i = 0; i < SAMPLES; i++)
    {
        outputInt[i] = calculateFilterOutputInt(inputInt[i]);
    }
}

void runThroughAllSamplesFloat(void)
{
    for (uint8_t i = 0; i < SAMPLES; i++)
    {
        outputFloat[i] = calculateFilterOutputFloat(inputFloat[i]);
    }
}
