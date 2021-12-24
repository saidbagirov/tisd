#include "../inc/conn.h"

int is_graph_connected(matrix_t matrix)
{
	int *visited = calloc(matrix.size, sizeof(int));
	dfs(matrix, 0, visited);

	for (int i = 0; i < matrix.size; i++)
		if (!visited[i])
		{
			free(visited);
			return FALSE;
		}
	free(visited);

	return TRUE;
}