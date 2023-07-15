/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibouill <pibouill@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:36:40 by ghailema          #+#    #+#             */
/*   Updated: 2023/06/27 21:53:05 by pibouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../includes/pointer.h"

void	copySubArray(int k, int p, int result, int conv[result][result])
{
	int	r_row;
	int	r_col;
	int	y;
	int	t;

	r_row = 0;
	t = 0;
	while (r_row < result && t < result)
	{
		r_col = 0;
		y = 0;
		while (r_col < result && y < result)
		{
			conv[r_row][r_col] = g_arr_ptr[k + r_row][p + r_col];
			r_col++;
			y++;
		}
		r_row++;
		t++;
	}
}

int	checkArray(int result, int conv[result][result])
{
	int	check;
	int	i;
	int	j;

	check = 1;
	i = 0;
	while (i < result && check == 1)
	{
		j = 0;
		while (j < result && check == 1)
		{
			if (conv[i][j] == 0) {
				check = 0;
			}
			j++;
		}
		i++;
	}
	return (check);
}

void updateSubArray(int** arr, int k, int p, int result) {
	int	r_row;
	int	t;
	int	r_col;
	int	y;

	r_row = 0;
	t = 0;
	while (r_row < result && t < result)
	{
		r_col = 0;
		y = 0;
		while (r_col < result && y < result)
		{
			arr[k + r_row][p + r_col] = fill;
			r_col++;
			y++;
		}
		r_row++;
		t++;
	}
}

void updateArray(int** arr, int rows, int cols, int result)
{
	int conv[result][result];
	int m;
	int check;
	int	p;
	int k;

	m= 1;
	k = 0;
	while (k < rows - (result - 1))
	{
		p = 0;
		while (p < cols - (result - 1))
		{
			copySubArray(k, p, result, conv);
			check = checkArray(result, conv);
			if (check == 1)
			{
				updateSubArray(arr, k, p, result);
				result = 0;
				result = 0;
			}
			p++;
		}
		k++;
	}
}
void displayArray(int** arr, int rows, int cols)
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
		{
            if (arr[i][j] == fill)
			{
                printf("%c", arr[i][j]);
            } else
			{
				if (arr[i][j] == 0)
				{
					arr[i][j] =obstacle;
				}
				if (arr[i][j] == 1)
				{
					arr[i][j] =space;
				}
                printf("%c", arr[i][j]);
            }
        }
        printf("\n");
    }
}
