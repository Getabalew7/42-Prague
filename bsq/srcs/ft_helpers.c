#include <stdio.h>
#include <stdlib.h>
#include "../includes/pointer.h"

int	min(int a, int b, int c)
{
	int	l;

	if (a < b)
		l = a;
	else
		l = b;
	if (l < c)
		return (l);
	return (c);
}

int	**allocate_memory(int rows, int cols)
{
	int	**result;
	int	i;

	i = 0;
	result = (int **)malloc(rows * sizeof(int *));
	while (i < rows)
	{
		result[i] = (int *)malloc(cols * sizeof(int));
		i++;
	}
	return (result);
}

void	free_memory(int **result, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(result[i]);
		i++;
	}
}

void	initialize_first_row_and_column(int **result,
			int rows, int cols, int *max)
{
	int	i;
	int	j;

	i = 0;
	while (i < rows)
	{
		result[i][0] = g_arr_ptr[i][0];
		if (result[i][0] == 1)
		{
			*max = 1;
		}
		i++;
	}
	j = 0;
	while (j < cols) {
		result[0][j] = g_arr_ptr[0][j];
		if (result[0][j] == 1) {
			*max = 1;
		}
		j++;
	}
}

void calculateMaxSquare(int **result, int rows, int cols, int *max) {
	int	i;
	int j;
	int t;

	i = 1;
	while (i < rows) {
		j = 1;
		while (j < cols) {
			if (g_arr_ptr[i][j] == 0) {
				j++;
				continue;
			}
			t = min(result[i - 1][j], result[i - 1][j - 1], result[i][j - 1]);
			result[i][j] = t + 1;
			if (result[i][j] > *max) {
				*max = result[i][j];
			}
			j++;
		}
		i++;
	}
}

int max_size(int **arr, int rows, int cols)
{
	int	**result;
	int max;
	(void) arr;
	result = allocate_memory(rows, cols);
	max = 0;
	initialize_first_row_and_column(result, rows, cols, &max);
	calculateMaxSquare(result, rows, cols, &max);
	free_memory(result, rows);
	return (max);
}
