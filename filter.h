/*
 * filter.h
 *
 *  Created on: 6 Oct 2022
 *      Author: Kathryn.Whitehead
 */

#ifndef SRC_FILTER_H_
#define SRC_FILTER_H_

#include "common.h"

int32_t calculateFilterOutputInt (int32_t input);
float calculateFilterOutputFloat (float input);


void resetFilter (void);

#endif /* SRC_FILTER_H_ */
