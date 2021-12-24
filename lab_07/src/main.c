#include "../inc/conn.h"
#include "../inc/io.h"

int main()
{
	int size;
	setbuf(stdout, NULL);
	welcome();

	printf("Введите число вершин графа: ");
	int ec = input_range(&size, 1, INT_MAX);
	if (ec)
	{
		printf("Неверное значение! Повторите попытку.\n");
		return ec;
	}

	matrix_t *matrix = amcreate(size);
	printf("Введите попарно номера связанных вершин (-1 для завершения):\n");
	ec = amfill(stdin, matrix);
	if (ec)
	{
		if (ec == ERROR_INT || ec == ERROR_RANGE)
		{ 
			printf("Неверное значение! Повторите попытку.\n");
			amfree(matrix);
			return ec;
		}
		if (ec == ERROR_PAIR)
		{
			printf("Неправильно введен путь\n");
			amfree(matrix);
			return ec;
		}
	}

	uint64_t start, end;
	start = tick();
	if (!is_graph_connected(*matrix))
		printf("Граф не является связным\n");
	else
		printf("Граф связный\n");
	end = tick();
	gvexport(*matrix);

	printf("Время выполнения алгоритма: %ju\n", end - start);

	return EOK;
}