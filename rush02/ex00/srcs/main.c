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
#include <fcntl.h>
#include "ft_dict_structure.h"
#include "ft_atoi.h"
#include"ft_convertor_number.h"
#include "ft_load_dictionary.h"
#include "ft_print_str.h"
#include "ft_count_dictionary.h"
#include "ft_utils.h"
#define FILE "numbers.dict"
#define BUFFER_SIZE 1024

struct s_dictionary	*g_num_dictionary;

int	ft_process_inputs(char *str)
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

int	ft_check_inputs(char *str)
{
	if (ft_strcmp(str, "4294967294") > 0)
	{
		ft_print("Error");
		write(1, "\n", 1);
		return (0);
	}
	if (!ft_process_inputs(str))
	{
		ft_print("Wrong input\n");
		return (0);
	}
	return (1);
}

int	ft_process_arguments(char *arg, char *num)
{
	unsigned int	number;

	number = ft_atoi(num);
	g_num_dictionary = malloc(ft_count_lines(arg)
			* sizeof(struct s_dictionary));
	if (!g_num_dictionary)
	{
		ft_print("Dict Error\n");
		return (0);
	}
	if (!ft_load_dictionary(g_num_dictionary, arg))
	{
		ft_print("Dict Error\n");
		return (0);
	}
	ft_convert_number(number, g_num_dictionary, arg);
	ft_print("\n");
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (!ft_check_inputs(argv[1]))
			return (0);
		ft_process_arguments(FILE, argv[1]);
	}
	else if (argc == 3)
	{
		if (!ft_check_inputs(argv[2]))
			return (0);
		ft_process_arguments(argv[1], argv[2]);
	}
	else
		ft_print_str("Error\n");
	free (g_num_dictionary);
}
