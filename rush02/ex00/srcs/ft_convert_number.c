/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_number.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghailema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 18:45:28 by ghailema          #+#    #+#             */
/*   Updated: 2023/06/24 18:45:29 by ghailema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<unistd.h>
#include"ft_dict_structure.h"
#include "ft_convertor_number.h"
#include "ft_print_str.h"
#include "ft_utils.h"
#include"ft_count_dictionary.h"

char	*ft_search(unsigned int number, struct s_dictionary *num_dictionary,
			char *file)
{
	int		i;

	i = 0;
	while (i < ft_count_lines(file))
	{
		if (num_dictionary[i].key == number)
		{
			return (num_dictionary[i].value);
		}
		i++;
	}
	return (NULL);
}

int	ft_get_digit(int len)
{
	if (len >= 3 && len <= 5)
		return (4);
	else if (len >= 6 && len <= 8)
		return (7);
	else if (len >= 9 && len <= 11)
		return (10);
	else
		return (len + 1);
}

void	ft_display_res(unsigned int number, struct s_dictionary
			num_dictionary[], int digit, char *file)
{
	ft_convert_number((number / digit), num_dictionary, file);
	ft_print(ft_search(digit, num_dictionary, file));
	if (ft_count_digit(number) == 2)
	{
		ft_print(" and ");
	}
	if (ft_count_digit(number) > 2)
	{
		ft_print(", ");
	}
	if (number % digit != 0)
	{	
		ft_convert_number((number % digit), num_dictionary, file);
	}
}

void	ft_convert_number(unsigned int number,
			struct s_dictionary num_dictionary[], char *file)
{
	int	len;
	int	digit;

	if (number == 0)
		ft_print_str(ft_search(number, num_dictionary, file));
	else if (number >= 100)
	{
		len = ft_get_digit(ft_count_digit(number));
		digit = ft_power(len - 1);
		ft_display_res(number, num_dictionary, digit, file);
	}
	else if (number >= 20)
	{
		ft_print(ft_search(number / 10 * 10, num_dictionary, file));
		if (number % 10 != 0)
		{
			ft_print("-");
			ft_convert_number((number % 10), num_dictionary, file);
		}	
	}
	else if (number > 0)
	{
		ft_print_str(ft_search(number, num_dictionary, file));
	}
}
