/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghailema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 15:41:41 by ghailema          #+#    #+#             */
/*   Updated: 2023/06/24 16:05:34 by ghailema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include <fcntl.h>
#include "ft_dict_structure.h"
#include "ft_atoi.h"
#include"ft_convertor_number.h"
#include "ft_load_dictionary.h"
#include "ft_print_str.h"
#include "ft_count_dictionary.h"
#define FILE "numbers.dict"

#define BUFFER_SIZE 1024
//void	ft_convert_number(int number, struct s_dictionary num_dictionary[]);
//int ft_count_lines(const char* filename);
struct s_dictionary *num_dictionary;
//struct s_dictionary *ft_load_dictionary(struct s_dictionary *num_dictionary);
//void	ft_print_str(char *str);

int ft_process_inputs(char *str)
{
	while (*str)
	{
		if (!(*str >= 48 && *str <= 57))
		{
			return (0);
		}
		str++;
	}
	return (1);
}
int	main(int argc, char **argv)
{
	if (argc ==2 )
	{
		int validate = ft_process_inputs(argv[1]);
		if (!validate)
		{
			ft_print_str("Wrong input");
			return (0);
		}
		int number = ft_atoi(argv[1]);
		num_dictionary = malloc(ft_count_lines(FILE) * 
						sizeof(struct s_dictionary));
		if (!num_dictionary)
			ft_print_str("Dict Error\n");
		if (!ft_load_dictionary(num_dictionary))
			ft_print_str("Dict Error\n");
		ft_convert_number(number, num_dictionary);
	}
	
	
	free(num_dictionary);
}
