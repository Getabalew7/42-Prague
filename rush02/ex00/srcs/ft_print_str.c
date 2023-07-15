/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghailema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 11:41:13 by ghailema          #+#    #+#             */
/*   Updated: 2023/06/25 11:41:21 by ghailema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_print_str(char *str)
{
	while (*str)
	{
		write(1, &*str, 1);
		str++;
	}
	write(1, " ", 1);
}

void	ft_print(char *str)
{
	while (*str)
	{
		write(1, &*str, 1);
		str++;
	}
}
