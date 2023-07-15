/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghailema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:20:25 by ghailema          #+#    #+#             */
/*   Updated: 2023/06/09 10:25:56 by ghailema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_nums(char c, char b, char d)
{
	write(1, &c, 1);
	write(1, &b, 1);
	write(1, &d, 1);
}

void	ft_print_comma(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb(void)
{
	int	a;
	int	b;
	int	c;

	a = 48;
	while (a < 58)
	{
		b = a + 1;
		while (b < 58)
		{
			c = b + 1;
			while (c < 58)
			{
				ft_print_nums(a, b, c);
				if (a < 55)
				{
					ft_print_comma(',');
				}
				c++;
			}
			b++;
		}
		a++;
	}
}
