/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghailema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 13:21:27 by ghailema          #+#    #+#             */
/*   Updated: 2023/06/25 13:21:31 by ghailema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_digit(unsigned int number)
{
	int	count;

	count = 0;
	while (number / 10 != 0)
	{
		count++;
		number /= 10;
	}
	return (count);
}

int	ft_power(int digit)
{
	int	res;

	res = 1;
	while (digit > 0)
	{
		res *= 10;
		digit--;
	}
	return (res);
}

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

int	ft_count_str_for_file(char *str)
{
	int	count;

	count = 0;
	while (*str && *str != ' ' && *str != '\t' && *str != '\r')
	{
		count++;
		str++;
	}
	return (count);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	len1;
	int	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (len1 > len2)
	{
		return (1);
	}
	else if (len1 == len2)
	{
		while (*s1 && (*s1 == *s2))
		{
			s1++;
			s2++;
		}
		return (*(const unsigned char *)s1 - *(const unsigned char *)s2);
	}
	return (-1);
}
