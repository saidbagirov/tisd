#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "io.h"

typedef struct
{
	int size;
	int **matrix;
} matrix_t;

matrix_t *amcreate(const int size);

void amfree(matrix_t *matrix);

matrix_t *amcopy(matrix_t matrix);

int amfill(FILE *const stream, matrix_t *const matrix);

void amouptut(FILE *const stream, const matrix_t matrix);

void dfs(const matrix_t matrix, const int vertex, int *visited);

#endif