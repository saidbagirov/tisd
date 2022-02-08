#ifndef _TIME_H_
#define _TIME_H_
#include <time.h>
typedef struct
{
	long int time; // Time in ticks
	int amount;   // Amount of cleared or added elements
} times_t;
#endif