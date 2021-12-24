#ifndef IO_H
#define IO_H

#include <stdio.h>
#include <inttypes.h>

#include "defines.h"

void welcome();
void clinstream();
int input_range(int *const num, const int left, const int right);
uint64_t tick(void);

#endif