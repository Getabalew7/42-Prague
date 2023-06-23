/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghailema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:11:47 by ghailema          #+#    #+#             */
/*   Updated: 2023/06/15 19:13:06 by ghailema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_len(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
		index++;
	return (index);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	index;

	index = 0;
	while (src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

int	ft_flen(char **strings, int size, int sep_length)
{
	int	final_length;
	int	index;

	final_length = 0;
	index = 0;
	while (index < size)
	{
		final_length += ft_len(strings[index]);
		final_length += sep_length;
		index++;
	}
	final_length -= sep_length;
	return (final_length);
}

char	*ft_strs_join(char *d, int size, char **strs, char *sep)
{
	int	index;

	index = 0;
	while (index < size && (ft_flen(strs, size, ft_len(sep))))
	{
		ft_strcpy(d, strs[index]);
		d += ft_len(strs[index]);
		if (index < size - 1)
		{
			ft_strcpy(d, sep);
			d += ft_len(sep);
		}
		index++;
	}
	*d = '\0';
	return (d);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		index;
	char	*string;
	char	*d;

	if (size == 0)
	{
		string = (char *)malloc(sizeof(char));
		if (string == NULL)
		{
			return (NULL);
		}	
		string[0] = '\0';
		return (string);
	}
	string = (char *)malloc((ft_flen(strs, size, ft_len(sep)) + 1)
			* sizeof(char));
	d = string;
	if (!d)
		return (0);
	index = 0;
	d = ft_strs_join(d, size, strs, sep);
	*d = '\0';
	return (string);
}
