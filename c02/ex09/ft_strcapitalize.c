/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghailema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:53:00 by ghailema          #+#    #+#             */
/*   Updated: 2023/06/12 16:53:06 by ghailema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

char	*ft_strlowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] += 32;
		}
		i++;
	}
	return (str);
}

int	ft_check_digit(char ch)
{
	if (ch >= '0' && ch <= '9')
	{
		return (0);
	}
	return (1);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	ft_strlowercase(str);
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (j == 1)
			{
				str[i] -= 32;
			}
			j = 0;
		}
		else
		{
			j = ft_check_digit(str[i]);
		}
		i++;
	}
}
