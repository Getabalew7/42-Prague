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
#include<stdio.h>
#include"ft_dict_structure.h"
void	ft_convert_number(int number, struct s_dictionary num_dictionary[]);
char *ft_search(int number, struct s_dictionary *num_dictionary)
{
	int i;

	i = 0;
	while (i < 32)
	{
		if(num_dictionary[i].key == number)
		{
			return (num_dictionary[i].value);
		}
		i++;
	}
	return (NULL);
}
void	ft_display_res(int number, struct s_dictionary num_dictionary[], int digit)
{
	printf("%s ", ft_search(number/digit,num_dictionary));
	printf("%s ", ft_search(digit,num_dictionary));
	if(number % digit != 0)
	{
		ft_convert_number((number % digit), num_dictionary);
	}
}
void	ft_convert_number(int number, struct s_dictionary num_dictionary[])
{
	if(number == 0)
		printf("%s", ft_search(number,num_dictionary));
	else if(number >= 1000000000)
		ft_display_res(number,num_dictionary,1000000000);
	else if(number >= 1000000)
		ft_display_res(number,num_dictionary,1000000);
	else if(number >= 1000)
		ft_display_res(number,num_dictionary,1000);
	else if(number >= 100)
	{
		ft_display_res(number,num_dictionary,100);
	}
	else if(number >= 20)
	{   
		printf("%s", "and ");
		printf("%s ", ft_search(number/10 *10,num_dictionary));
		if(number % 10 != 0)
			ft_convert_number((number % 10), num_dictionary);
	}
	else if(number > 0)
		printf("%s", ft_search(number ,num_dictionary));
	
}