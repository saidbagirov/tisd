#include "../inc/matrix.h"

matrix_t *amcreate(const int size)
{
	matrix_t *matrix = malloc(sizeof(matrix_t));
	if (!matrix)
		return NULL;
	matrix->size = size;
	matrix->matrix = malloc(sizeof(int *) * size);
	if (!matrix->matrix)
	{
		free(matrix);
		return NULL;
	}
	for (int i = 0; i < size; i++)
	{
		matrix->matrix[i] = calloc(size, sizeof(int));
		if (!matrix->matrix[i])
		{
			for (int j = 0; j < i; j++)
				free(matrix->matrix[j]);
			free(matrix->matrix);
			free(matrix);

			return NULL;
		}
	}

	return matrix;
}

void amfree(matrix_t *matrix)
{
	for (int i = 0; i < matrix->size; ++i)
		free(matrix->matrix[i]);
	free(matrix->matrix);
	free(matrix);
}

matrix_t *amcopy(matrix_t matrix)
{
	matrix_t *copy = amcreate(matrix.size);

	for (int i = 0; i < matrix.size; i++)
		for (int j = 0; j < matrix.size; j++)
			if (matrix.matrix[i][j])
				copy->matrix[i][j] = GOT_CONNECTION;

	return copy;
}

int amfill(FILE *const stream, matrix_t *const matrix)
{
	int ver1, ver2;

	while (TRUE)
	{
		int ec = input_range(&ver1, -1, matrix->size - 1);
		if (ec)
			return ec;
		if (ver1 == EOI)
			break;
		ec = input_range(&ver2, 0, matrix->size - 1);
		if (ec)
			return ec;

		if (ver1 == ver2)
			return ERROR_PAIR;

		matrix->matrix[ver1][ver2] = GOT_CONNECTION;
		matrix->matrix[ver2][ver1] = GOT_CONNECTION;
	}

	return EOK;
}

void amouptut(FILE *const stream, const matrix_t matrix)
{
	for (int i = 0; i < matrix.size; i++)
	{
		for (int j = 0; j < matrix.size; j++)
			fprintf(stream, "%d ", matrix.matrix[i][j]);
		fprintf(stream, "\n");
	}
}

void dfs(const matrix_t matrix, const int vertex, int *visited)
{
	visited[vertex] = TRUE;

	for (int i = 0; i < matrix.size; i++)
		if (matrix.matrix[vertex][i] && !visited[i])
			dfs(matrix, i, visited);
}