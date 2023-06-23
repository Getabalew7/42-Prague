/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghailema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:50:22 by ghailema          #+#    #+#             */
/*   Updated: 2023/06/19 16:50:25 by ghailema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include<stdlib.h>

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		count++;
		str++;
	}
	return (count);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*des;

	i = 0;
	des = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!des)
	{
		return (NULL);
	}
	while (str[i] != '\0')
	{
		des[i] = str[i];
		i++;
	}
	des[i] = '\0';
	return (des);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int					index;
	struct s_stock_str	*stock;

	index = 0;
	stock = malloc(sizeof(struct s_stock_str) * (ac + 1));
	if (!stock)
	{
		return (NULL);
	}
	while (index < ac)
	{
		stock[index].size = ft_strlen(av[index]);
		stock[index].str = av[index];
		stock[index].copy = ft_strdup(av[index]);
		index++;
	}
	stock[index].str = 0;
	stock[index].copy = 0;
	return (stock);
}
