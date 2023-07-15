/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghailema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 10:55:38 by ghailema          #+#    #+#             */
/*   Updated: 2023/06/09 10:58:49 by ghailema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_nums( char a, char b, char c, char s)
{
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &s, 1);
	write(1, &a, 1);
	write(1, &c, 1);
}

void	ft_print_comma(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;
	int	c;

	a = 48;
	while (a <= 57)
	{
		b = 48;
		while (b <= 57)
		{
			c = b + 1;
			while (c <= 57)
			{
				ft_print_nums(a, b, c, ' ');
				if (a < 87)
				{
					ft_print_comma(',');
				}
				c++;
			}
			b++;
		}
		a++;
	}
	write(1, "\b\e[K", 1);
}
