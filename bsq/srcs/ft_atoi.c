/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghailema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:37:02 by ghailema          #+#    #+#             */
/*   Updated: 2023/06/13 18:49:49 by ghailema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdlib.h>
#include "../includes/pointer.h"
char	obstacle;
char	space;
char	fill;
int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while(*str)
	{
		count++;
		str++;
	}
	return (count);
}

char	*ft_strncpy(char *src)
{
	int 	len;
	char	*dest;
	int		i;
	len= ft_strlen(src) - 3;
	dest = (char *)malloc((len + 1) * sizeof(char));
	 i = 0;
	while(i < len)
	{
		dest[i] = src[i];
		i++;
	}
	// dest[i] = '\0';
	space = src[len];
	obstacle = src[len + 1];
	fill = src[len + 2];
	return (dest);
}

int	ft_whitespace(char *str, int *ptr_i)
{
	int	count;
	int	i;

	i = 0;
	count = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] && (str[i] == 43 || str[i] == 45))
	{
		if (str[i] == 45)
			count *= -1;
		i++;
	}
	*ptr_i = i;
	return (count);
}

int	ft_atoi(char *str)
{
	int	sign;
	int	result;
	int	i;

	result = 0;
	sign = ft_whitespace(str, &i);
	while (str[i] && str[i] >= 48 && str[i] <= 57)
	{
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	result *= sign;
	return (result);
}

