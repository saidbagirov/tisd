#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
typedef struct 
{
	int mantissa[30];
	int minus;
	int exp;
} long_float;
typedef struct
{
	int mantissa[30];
	int minus;
} long_int;
void init_long_int(long_int *number)
{
	number->minus = FALSE;
	for (int i = 0; i < 30; i++)
		number->mantissa[i] = 0;
}
void init_long_float(long_float *number)
{
	number->exp = 0;
	number->minus = FALSE;
	for (int i = 0; i < 30; i++)
		number->mantissa[i] = 0;
}
void normal(long_float *number)
{
	if (!number->mantissa[29])
	{
		int o = 0;
		while (!number->mantissa[29] && o < 30)
		{
			for (int i = 29; i > 0; i--)
				number->mantissa[i] = number->mantissa[i - 1];
			number->mantissa[0] = 0;
			number->exp++;
			o++;
		}
	}
}
void output_long_float(long_float number)
{
	int i = 0;
	while (!number.mantissa[i] && i < 29)
		i++;
	if (abs(number.exp + 30 - i) - 1 >= 99999)
		printf("Too big exper!\n");
	else
	{
		i = 0;
		if (number.minus)
			printf("-");
		if (!number.mantissa[29])
			printf("0\n");
		else
		{
			while (!number.mantissa[i] && i < 29)
				i++;
			int j = i;
			printf("0.");
			while(i < 30)
			{
				printf("%d", number.mantissa[i]);
				i++;
			}
			printf("e%d\n", number.exp + 30 - j);
		}
	}
}
int inp_long_int(long_int *number)
{
	char input[40];
	int i, j;
	for (i = 0; i < 30; i++)
		input[i] = '\0';
	printf("Enter int num:\n");
	printf("1        10        20       30\n");
	printf("|--------|---------|---------|\n");
	scanf("%s", input);
	i = 0;
	if (input[i] == '-')
	{
		number->minus = TRUE;
		i++;
	}
	while (i < 30 + number->minus)
	{
		if (!input[i])
			return 0;
		else if ('0' <= input[i] && input[i] <= '9')
		{
			for (j = 0; j < 29; j++)
				number->mantissa[j] = number->mantissa[j + 1];
			number->mantissa[29] = (int)(input[i] - '0');
			i++;
		}
		else
			return -1;
	}
	if (input[30 + number->minus])
		return -2;
	return 0;
}
int inp_long_float(long_float *number)
{
	char input[100];
	int i, j;
	int dot = FALSE;
	printf("Enter float num:\n");
	printf("1        10        20       30e1   5\n");
	printf("|--------|---------|---------|-|---|\n");
	scanf("%s", input);
	i = 0;
	if (input[i] == '-')
	{
		number->minus = TRUE;
		i++;
	}
	while (i < 30 + number->minus + dot)
	{
		if (input[i] == '\0')
			return 0;
		else if (input[i] == '.')
		{
			if (dot)
				return -1;
			dot = TRUE;
			i++;
		}
		else if ('0' <= input[i] && input[i] <= '9')
		{
			if (dot)
				number->exp--;
			for (j = 0; j < 29; j++)
				number->mantissa[j] = number->mantissa[j + 1];
			number->mantissa[29] = (int)(input[i] - '0');
			i++;
		}
		else if (input[i] == 'e')
			break;
		else
			return -1;
	}
	if ('0' <= input[i] && input[i] <= '9')
		return -2;
	if (input[i] == 'e')
	{
		i++;
		int e = 0;
		int em = FALSE;
		if (input[i] == '-')
		{
			em = TRUE;
			i++;
		}
		for(j = 0; j < 6; j++)
		{
			if (j == 5 && input[i])
				return -3;
			else if (!input[i])
				break;
			else if ('0' <= input[i] && input[i] <= '9')
			{
				e *= 10;
				e += input[i] - '0';
				i++;
			}
			else
				return -1;
		}
		if (em)
			e *= -1;
		number->exp += e;
	}
	normal(number);
	return 0;
}
long_float multiple_float_int(long_float number, long_int number2)
{
	int kk = FALSE, pk = 0;
	long_float sum, temp;
	init_long_float(&sum);
	for (int i = 29; i >= 0; i--)
	{
		init_long_float(&temp);
		temp.exp = number.exp + 29 - i;
		for (int j = 29; j >= 0; j--)
		{
			temp.mantissa[j] += number.mantissa[j] * number2.mantissa[i];
			if (temp.mantissa[j] > 9)
			{
				if (j)
				{
					temp.mantissa[j - 1] += temp.mantissa[j] / 10;
					temp.mantissa[j] %= 10;
				}
				else
				{
					if (temp.mantissa[29] > 4)
						kk = TRUE;
					for (int z = 30; z >= 2; z--)
						temp.mantissa[z] = temp.mantissa[z - 1];
					if (kk)
						temp.mantissa[29] += 1;
					kk = FALSE;
					temp.mantissa[1] = temp.mantissa[0] % 10;
					temp.mantissa[0] /= 10;
					temp.exp++;
				}
			}
		}
		if (sum.exp < temp.exp)
			while (sum.exp != temp.exp)
			{
				if (!temp.mantissa[0])
				{
					for (int r = 0; r < 29; r++)
						temp.mantissa[r] = temp.mantissa[r + 1];
					temp.mantissa[29] = 0;
					temp.exp--;
				}
				else
				{
					if (sum.mantissa[29] > 4)
						pk = TRUE;
					for (int r = 29; r > 0; r--)
						sum.mantissa[r] = sum.mantissa[r - 1];
					if (pk)
						sum.mantissa[29] += 1;
					pk = FALSE;
					sum.mantissa[0] = 0;
					sum.exp++;
				}
			}
		if (sum.exp > temp.exp)
			while (sum.exp != temp.exp)
			{
				if (!sum.mantissa[0])
				{
					for (int r = 0; r < 29; r++)
						sum.mantissa[r] = sum.mantissa[r + 1];
					sum.mantissa[29] = 0;
					sum.exp--;
				}
				else
				{
					for (int r = 29; r > 0; r--)
						temp.mantissa[r] = temp.mantissa[r - 1];
					temp.mantissa[0] = 0;
					temp.exp++;
				}
			}
		for (int r = 29; r >= 0; r--)
		{
			sum.mantissa[r] += temp.mantissa[r];
			if (sum.mantissa[r] > 9)
			{
				if (r)
				{
					sum.mantissa[r - 1] += sum.mantissa[r] / 10;
					sum.mantissa[r] %= 10;
				}
				else
				{
					for (int z = 29; z >= 2; z--)
						sum.mantissa[z] = sum.mantissa[z - 1] % 10;
					sum.mantissa[1] = sum.mantissa[0] % 10;
					sum.mantissa[0] /= 10;
					sum.exp++;
				}
			}
		}
	}
	if (number.minus || number2.minus)
		sum.minus = TRUE;
	if (number.minus && number2.minus)
		sum.minus = FALSE;
	normal(&sum);
	for (int i = 0; i < 30; i++)
		printf("%d", sum.mantissa[i]);
	return sum;
}
int main(void)
{
	setbuf(stdout, NULL);
	printf("Programm multiplies two numbers: real and integer\n\n");
	printf("Real number format: [-]m[.n][e[-]exp], where:\n\tm+n is mantissa up to 30 digits; \n\texp is exponent up to 5 digits.\n\n");
	printf("Integer number format: [-]n, where:\n\tn is mantissa up to 30 digits.\n\n");
	long_float factor1;
	long_int factor3;
	long_float sum;
	init_long_int(&factor3);
	init_long_float(&factor1);
	int i, j;
	i = inp_long_float(&factor1);
	switch (i)
	{
		case 0:
			j = inp_long_int(&factor3);
			switch (j)
			{
				case 0:
					sum = multiple_float_int(factor1, factor3);
					printf("\nMultiple: ");
					output_long_float(sum);
					break;
				case -1:
					printf("Incorrect symbol\n");
					break;
				case -2:
					printf("Too big mantissa\n");
					break;
				case -3:
					printf("Too big exper\n");
					break;
			}
			break;
		case -1:
			printf("Incorrect symbol\n");
			break;
		case -2:
			printf("Too big mantissa\n");
			break;
		case -3:
			printf("Too big exper\n");
			break;
		}
	return 0;
}