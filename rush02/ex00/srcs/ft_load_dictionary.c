/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_dictionary.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghailema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 12:28:01 by ghailema          #+#    #+#             */
/*   Updated: 2023/06/25 12:28:03 by ghailema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "ft_dict_structure.h"
#include"ft_atoi.h"
#include"ft_split.h"
#include"ft_print_str.h"
#include "ft_utils.h"
#define BUFFER_SIZE 1024

int		g_i;
int		g_j;

char	*allocate_buffer(void)
{
	char	*buffer;

	buffer = malloc(BUFFER_SIZE);
	return (buffer);
}

int	open_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	return (fd);
}

ssize_t	read_file(int fd, char *buffer)
{
	ssize_t	bytes_read;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	return (bytes_read);
}

void	parse_dictionary(char *buffer, ssize_t bytes_read, struct s_dictionary
			*num_dictionary)
{
	char	line[BUFFER_SIZE];
	int		line_length;
	char	**split;

	g_i = 0;
	g_j = 0;
	line_length = 0;
	while (g_i < bytes_read)
	{
		if (buffer[g_i] == '\n')
		{
			line[line_length] = '\0';
			if (ft_count_str_for_file(line) != 0)
			{
				split = ft_split(line, ": ");
				num_dictionary[g_j].key = ft_atoi(split[0]);
				num_dictionary[g_j].value = split[1];
				line_length = 0;
				g_j++;
			}
		}
		else
			line[line_length++] = buffer[g_i];
		g_i++;
	}
}

struct	s_dictionary	*ft_load_dictionary(struct s_dictionary *num_dictionary,
			char *file)
{
	ssize_t	bytes_read;
	char	*buffer;
	int		fd;

	buffer = allocate_buffer();
	fd = open_file(file);
	if (fd == -1)
	{
		ft_print("Dict Error\n");
		free(buffer);
		return (NULL);
	}
	bytes_read = read_file(fd, buffer);
	if (bytes_read == -1)
	{
		ft_print("Dict Error\n");
		free (buffer);
		close (fd);
		return (NULL);
	}
	close(fd);
	parse_dictionary(buffer, bytes_read, num_dictionary);
	free(buffer);
	return (num_dictionary);
}
