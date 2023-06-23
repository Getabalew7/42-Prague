/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghailema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 14:37:23 by ghailema          #+#    #+#             */
/*   Updated: 2023/06/12 14:53:59 by ghailema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

unsigned	int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

unsigned	int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int	i;
	int	j;
	int	dest_len;
	int	src_len;

	i = 0;
	j = dest_len(dest);
	dest_len = ft_len(dest);
	src_len = ft_len(src);
	if (size == 0 || size <= dest_len)
		return (src_len + size);
	while (src [i] != '\0' && i < size - dest_len -1)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest_len + src_len);
}
