/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghailema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 18:23:48 by ghailema          #+#    #+#             */
/*   Updated: 2023/06/17 18:23:55 by ghailema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// functions.c
void	ft_lines_to_array(int ft_checktab[4][4], int permut[24][4], int linesnum[4]);
void	ft_print_solution(int tab[4][4]);
// heap_permut.c
void	ft_get_permut(int my_permut[24][4]);
// ft_verif.c
int		ft_verif(int tab[4][4], int *val);

/*
 * ft_loop on the 331,776 (24^4) possibilities, display and return to the first
 * solution
 */
void	ft_loop(int lines[4], int ft_checktab[4][4], int permut[24][4], int val[16])
{
	while (lines[0]++, lines[0] < 24)
	{
		lines[1] = 0;
		while (lines[1]++, lines[1] < 24)
		{
			lines[2] = 0;
			while (lines[2]++, lines[2] < 24)
			{
				lines[3] = 0;
				while (lines[3]++, lines[3] < 24)
				{
					ft_lines_to_array(ft_checktab, permut, lines);
					if (ft_verif(ft_checktab, val) == 1)
					{
						ft_print_solution(ft_checktab);
						return ;
					}
				}
			}
		}
	}
	write(1, "Error\n", 6);
}

/*
 * Create and initialize the variables necessary for the ft_loop function
  and call it
 * Used only to win lines
 */
void	ft_resolve(int val[16])
{
	int	permut[24][4];
	int	ft_checktab[4][4];
	int	linesnum[4];
	int	i_cur;

	i_cur = -1;
	while (i_cur++, i_cur < 4)
		linesnum[i_cur] = -1;
	ft_get_permut(permut);
	ft_loop(linesnum, ft_checktab, permut, val);
}

/*
 * ft_checks if the character of argv[1] at index cur is in its place and if so
 * appends it to the array val.
 * Used to reduce the number of handlines
 */
int	ft_process_char(int cur, char **argv, int val[16])
{
	if (cur > 31)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (cur % 2 == 0)
	{
		if (argv[1][cur] >= 49 && argv[1][cur] <= 52)
			val[cur / 2] = argv[1][cur] - 48;
		else
		{
			write(1, "Error\n", 6);
			return (1);
		}
	}
	else
	{
		if (argv[1][cur] != ' ')
		{
			write(1, "Error\n", 6);
			return (1);
		}
	}
	return (0);
}

/*
 * Main: get the input string and convert it into an array of values
 * then calls the ft_resolve function with this array
 */
int	main(int argc, char **argv)
{
	int	val[16];
	int	cur;

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	cur = -1;
	while (cur++, argv[1][cur] != 0)
	{
		if (ft_process_char(cur, argv, val) == 1)
			return (1);
	}
	ft_resolve(val);
}
