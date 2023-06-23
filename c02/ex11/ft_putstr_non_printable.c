/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghailema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 13:25:25 by ghailema          #+#    #+#             */
/*   Updated: 2023/06/11 13:46:57 by ghailema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_char_is_printable(char c)
{
	if (c > 32 && c <= 126)
	{
		return (1);
	}
	return (0);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if (ft_char_is_printable(*str) == 1)
		{
			ft_putchar(*str);
		}
		else
		{
			ft_putchar('\\');
			ft_putchar("0123456789abcdef"[(*str) / 16]);
			ft_putchar("0123456789abcdef"[(*str) % 16]);
		}
		str++;
	}
}
