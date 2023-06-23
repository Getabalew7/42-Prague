/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghailema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:12:54 by ghailema          #+#    #+#             */
/*   Updated: 2023/06/12 13:19:32 by ghailema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	ft_strlen(char *str)
{
	int	size;
	int	i;

	size = 0;
	i = 0;
	while (str[i] != '\0')
	{
		i++;
		size++;
	}
	return (size);
}

char	*ft_strcat(char *dest, char *src)
{
	int	des_size;
	int	i;

	i = 0;
	des_size = ft_strlen(dest);
	while (src[i] != '\0')
	{
		dest[des_size + i] = src[i];
		i++;
	}
	dest[des_size + i] = '\0';
	return (dest);
}
