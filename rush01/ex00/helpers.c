/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghailema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 18:22:32 by ghailema          #+#    #+#             */
/*   Updated: 2023/06/17 18:22:38 by ghailema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
 * Returns 1 if there are twice the same element in the array, returns 0 if
 * all items are different.
 */
int	ft_el_in_tab(int *row)
{
	int	cur;
	int	cur2;

	cur = 0;
	while (cur < 4)
	{
		cur2 = 0;
		while (cur2 < 4)
		{
			if (row[cur] == row[cur2] && cur != cur2)
				return (1);
			cur2++;
		}
		cur++;
	}
	return (0);
}

/*
 * Fills the checktab array with the rows of the permutations specified by
 * linesnum.
 */
void	ft_lines_to_array(int checktab[4][4], int permut[24][4], int linesnum[4])
{
	int	cur;
	int	cur2;

	cur = 0;
	cur2 = 0;
	while (cur < 4)
	{
		cur2 = 0;
		while (cur2 < 4)
		{
			checktab[cur][cur2] = permut[linesnum[cur]][cur2];
			cur2++;
		}
		cur++;
	}
}

/*
 * Take a two-dimensional 4*4 array and display it
 */
void	ft_print_solution(int tab[4][4])
{
	int		cur;
	int		cur2;
	char	c;

	cur = 0;
	while (cur < 4)
	{
		cur2 = 0;
		while (cur2 < 4)
		{
			c = tab[cur][cur2] + '0';
			write(1, &c, 1);
			if (cur2 != 3)
				write(1, " ", 1);
			cur2++;
		}
		write(1, "\n", 1);
		cur++;
	}
}

/*
 * Functions that invert the elements of the array passed as parameters
 */
void	ft_rev_int_tab(int *tab, int size)
{
	int	cur;
	int	t;

	cur = 0;
	while (cur < size / 2)
	{
		t = tab[cur];
		tab[cur] = tab[size - 1 - cur];
		tab[size - 1 - cur] = t;
		cur++;
	}
}

/*
 * Fills an array of 4 elements with the elements of the column
 * number "col_num"
 */
void	ft_get_cols(int col_tab[4], int tab[4][4], int col_num)
{
	col_tab[0] = tab[0][col_num];
	col_tab[1] = tab[1][col_num];
	col_tab[2] = tab[2][col_num];
	col_tab[3] = tab[3][col_num];
}
