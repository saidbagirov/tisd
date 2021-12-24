#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"

typedef struct
{
	int ver1;
	int ver2;
} edge_t;

typedef struct
{
	int size;
	edge_t *edges;
} chain_t;

chain_t *chcreate(matrix_t matrix);
void chfree(chain_t *chain);
edge_t **alrows(const int n, const int m);
void frrows(edge_t **data, const int n);
void gvexport(matrix_t matrix);

#endif