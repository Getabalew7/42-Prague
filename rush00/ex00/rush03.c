/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: visaienk <visaienk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 10:40:44 by ghailema          #+#    #+#             */
/*   Updated: 2023/06/11 12:32:09 by visaienk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char ch);

void	ft_print_width(int x)
{
	int	i;

	i = 0;
	ft_putchar('A');
	while (i < x - 2)
	{
		ft_putchar('B');
		i++;
	}
	if (x != 1)
	{
		ft_putchar('C');
	}
	ft_putchar('\n');
}

void	ft_print_length(int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < y - 2)
	{
		ft_putchar('B');
		j = 0;
		while (j < x - 2)
		{
			ft_putchar(' ');
			j++;
		}
		if (x != 1)
		{
			ft_putchar('B');
		}
		ft_putchar('\n');
		i++;
	}
}

void	rush(int x, int y)
{
	if (x <= 0 || y <= 0)
	{
		write(1, "Error for 0 or -ve number", 25);
		return ;
	}
	ft_print_width(x);
	ft_print_length(x, y);
	if (y != 1)
	{
		ft_print_width(x);
	}
}
