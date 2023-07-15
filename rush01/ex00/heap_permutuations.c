/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_permutuations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghailema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 18:22:53 by ghailema          #+#    #+#             */
/*   Updated: 2023/06/17 18:23:02 by ghailema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Heap's algorithm generates the set of permutations of a set
 * of n objects. It was first proposed by B. R. Heap in 19631.
 * Source: Wikipedia
 */

int	g_permut[24][4];
int	g_cur;

/*
 * Put x in y and y in x
 */
void	ft_swap(int *x, int *y)
{
	int	temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

/*
 * Added the "v" combination to the "g_permut" list of combinations
 */
void	ft_add_permut(const int *v)
{
	g_permut[g_cur][0] = v[0];
	g_permut[g_cur][1] = v[1];
	g_permut[g_cur][2] = v[2];
	g_permut[g_cur][3] = v[3];
	g_cur = g_cur + 1;
}

/*
 * Implementation recursive de l'algorithme de Heap
 */
void	ft_heappermute(int c[], int n)
{
	int	i;

	if (n == 1)
		ft_add_permut(c);
	else
	{
		i = 0;
		while (i < n)
		{
			ft_heappermute (c, n - 1);
			if (n % 2 == 1)
				ft_swap(&c[0], &c[n - 1]);
			else
				ft_swap(&c[i], &c[n - 1]);
			i++;
		}
	}
}

/*
 * Copy each element of "told" into tnew
 */
void	ft_copy_array(int told[24][4], int tnew[24][4])
{
	int	cur1;
	int	cur2;

	cur1 = 0;
	while (cur1 < 24)
	{
		cur2 = 0;
		while (cur2 < 4)
		{
			tnew[cur1][cur2] = told[cur1][cur2];
			cur2++;
		}
		cur1++;
	}
}

/*
 * Generate permutations and copies in the "permut" array
 * pass in parameters
 */
void	ft_get_permut(int permut[24][4])
{
	int	el[4];

	el[0] = 1;
	el[1] = 2;
	el[2] = 3;
	el[3] = 4;
	g_cur = 0;
	ft_heappermute(el, 4);
	ft_copy_array(g_permut, permut);
}
