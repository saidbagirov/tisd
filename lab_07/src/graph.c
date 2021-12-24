#include "../inc/graph.h"

chain_t *chcreate(matrix_t matrix)
{
	int edges = 0;

	for (int i = 0; i < matrix.size; i++)
		for (int j = 0; j < matrix.size; j++)
			if (matrix.matrix[i][j])
				edges++;

	edges /= 2;

	chain_t *chain = malloc(sizeof(chain_t));
	if (!chain)
		return NULL;
	chain->size = edges;
	chain->edges = malloc(sizeof(edge_t) * edges);
	if (!chain->edges)
	{
		free(chain);
		return NULL;
	}

	edge_t edge;
	int idx = 0;

	matrix_t *copy = amcopy(matrix);

	for (int i = 0; i < copy->size; i++)
		for (int j = 0; j < copy->size; j++)
			if (copy->matrix[i][j])
			{
				edge.ver1 = i;
				edge.ver2 = j;
				chain->edges[idx] = edge;

				copy->matrix[i][j] = 0;
				copy->matrix[j][i] = 0;

				idx++;
			}
	amfree(copy);

	return chain;
}

void chfree(chain_t *chain)
{
	free(chain->edges);
	free(chain);
}

edge_t **alrows(const int n, const int m)
{
	edge_t **data = malloc(sizeof(edge_t *) * n);
	if (!data)
		return NULL;

	for (int i = 0; i < n; i++)
	{
		data[i] = malloc(sizeof(edge_t) * m);
		if (!data[i])
		{
			for (int j = 0; j < i; ++j)
				free(data[j]);

			return NULL;
		}
	}

	return data;
}

void frrows(edge_t **data, const int n)
{
	for (int i = 0; i < n; i++)
		free(data[i]);
	free(data);
}

void gvexport(matrix_t matrix)
{
	FILE *export = fopen("graph.txt", "w");
	fprintf(export, "graph {\n");

	for (int i = 0; i < matrix.size; i++)
		for (int j = 0; j < matrix.size; j++)
			if (matrix.matrix[i][j])
				matrix.matrix[j][i] = 0;

	for (int i = 0; i < matrix.size; ++i)
	{
		for (int j = 0; j < matrix.size; ++j)
			if (matrix.matrix[i][j])
				fprintf(export, "%d -- %d;\n", i, j);
		fprintf(export, "%d;\n", i);
	}

	fprintf(export, "}\n");
	fclose(export);

	system("dot -Tpng graph.txt -o graph.png");
}