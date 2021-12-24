#include "../inc/io.h"

/*
Welcomming print with available features.
*/
void welcome()
{
	printf("Данная программа проверяет граф на связность.\n\n");
}

/*
Clean input stream from trash.
*/
void clinstream()
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

/*
Input number in between.

Input data:
* int *const num - number of action to be done.
* const int left - left border of between.
* const int right - right border of between.
*/
int input_range(int *const num, const int left, const int right)
{
	if (scanf("%d", num) != GOT_ARG)
	{
		clinstream();
		return ERROR_INT;
	}

	if (*num < left || *num > right)
	{
		clinstream();
		return ERROR_RANGE;
	}

	return EOK;
}

uint64_t tick(void)
{
	uint32_t high, low;
	__asm__ __volatile__(
		"rdtsc\n"
		"movl %%edx, %0\n"
		"movl %%eax, %1\n"
		: "=r"(high), "=r"(low)::"%rax", "%rbx", "%rcx", "%rdx");

	uint64_t ticks = (uint64_t)high << 32 | low;

	return ticks;
}