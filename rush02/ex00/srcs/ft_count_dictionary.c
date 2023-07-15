/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_dictionary.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghailema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 13:10:13 by ghailema          #+#    #+#             */
/*   Updated: 2023/06/25 13:10:17 by ghailema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include"ft_print_str.h"
#define BUFFER_SIZE 4096

void	ft_print_st(char *str);

int	read_lines(const char *filename, char *buffer, size_t buffer_size)
{
	int		file;
	ssize_t	bytes_read;

	file = open(filename, O_RDONLY);
	if (file == -1)
	{
		ft_print("Dict Error\n");
		return (-1);
	}
	bytes_read = read(file, buffer, buffer_size);
	close(file);
	return (bytes_read);
}

int	count_lines(const char *buffer, ssize_t bytes_read)
{
	int		line_count;
	ssize_t	i;
	int		is_empty_line;

	line_count = 0;
	is_empty_line = 1;
	i = 0;
	while (i < bytes_read)
	{
		if (buffer[i] == '\n')
		{
			if (!is_empty_line)
				line_count++;
			is_empty_line = 1;
		}
		else if (buffer[i] != ' ' && buffer[i] != '\t' && buffer[i] != '\r')
		{
			is_empty_line = 0;
		}
		i++;
	}
	return (line_count);
}

int	ft_count_lines(const char *filename)
{
	char	buffer[BUFFER_SIZE];
	ssize_t	bytes_read;
	int		line_count;

	bytes_read = read_lines(filename, buffer, sizeof(buffer));
	line_count = count_lines(buffer, bytes_read);
	return (line_count);
}
