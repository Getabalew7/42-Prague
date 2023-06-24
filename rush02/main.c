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
#include "ft_dict_structure.h"
#include <fcntl.h>
#define BUFFER_SIZE 1024
int	ft_atoi(char *str);
char	**ft_split(char *str, char *charset);
void	ft_convert_number(int number, struct s_dictionary num_dictionary[]);

struct s_dictionary num_dictinary[32];

int ft_load_dictionary()
{
	char *buffer;

	buffer = malloc(BUFFER_SIZE);
	ssize_t bytes_read;
	int fd;
	char line[BUFFER_SIZE];
    int line_length = 0;

	fd = open("numbers.dict",O_RDONLY);
	if (fd == -1)
	{
		printf("%s","Error opening file");
		return 0;
	}

	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		int i = 0;
		int j = 0;
		while (i< bytes_read)
		{	
			if (buffer[i] == '\n') 
			{
				line[line_length] = '\0';
        		
				char **split =ft_split(line, ": ");
				num_dictinary[j].key = ft_atoi(split[0]);
				num_dictinary[j].value =split[1];
        		line_length = 0;
				j++;
				
      		}
			else 
			{
				line[line_length] = buffer[i];
				line_length++;
      		}
			i++;
		}
	}
	if ( bytes_read == -1)
	{
		printf("%s", "Error loading the dictinary");
		return 0;
	}
	free(buffer);
	close(fd);
}
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
			printf("%s", "Wrong input");
			return (0);
		}
		int number = ft_atoi(argv[1]);
		ft_load_dictionary();
		ft_convert_number(number, num_dictinary);
		/* int i =0;
		while(i < 32)
		{
			printf("%i \t %s \n", num_dictinary[i].key, num_dictinary[i].value);
			i++;
		} */
	}

}
