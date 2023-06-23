/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghailema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:10:34 by ghailema          #+#    #+#             */
/*   Updated: 2023/06/15 11:23:33 by ghailema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putstr(char *str)
{
	char	ch;

	ch = '\n';
	while (*str)
	{
		write(1, &(*str), 1);
		str++;
	}
	write(1, &ch, 1);
}

int	ft_str_compare(char *s1, char *s2)
{
	int	n;

	n = 0;
	while (s1[n] == s2[n])
		n++;
	return (s1[n] - s2[n]);
}

void	ft_sort_params(char *tab[], int size)
{
	int		i;
	int		j;
	char	*temp;

	i = 1;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (ft_str_compare(tab[i], tab[j]) > 0)
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
			j++;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	n;

	n = 1;
	ft_sort_params(argv, argc);
	while (n <= argc - 1)
	{
		ft_putstr(argv[n++]);
	}
	return (0);
}
