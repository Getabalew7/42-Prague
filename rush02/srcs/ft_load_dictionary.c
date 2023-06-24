#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "ft_dict_structure.h"
#include"ft_atoi.h"
#include"ft_split.h"
#include"ft_print_str.h"
#define FILE "numbers.dict"
#define BUFFER_SIZE 1024
//int ft_atoi(char *str);
//char **ft_split(char *str, char *charset);
//void	ft_print_str(char *str);
/*
struct s_dictionary *ft_load_dictionary(struct s_dictionary *num_dictionary)
{
	char *buffer;

	buffer = malloc(BUFFER_SIZE);
	ssize_t bytes_read;
	int fd;
	char line[BUFFER_SIZE];
	int line_length = 0;

	fd = open(FILE,O_RDONLY);
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
				num_dictionary[j].key = ft_atoi(split[0]);
				num_dictionary[j].value =split[1];
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
		printf("%s", "Error loading the dictionary");
		return 0;
	}
	free(buffer);
	close(fd);
	return (num_dictionary);
}*/
char *allocate_buffer()
{
	char *buffer = malloc(BUFFER_SIZE);
	return buffer;
}
int open_file()
{
	int fd = open(FILE, O_RDONLY);
	return fd;
}
ssize_t read_file(int fd, char *buffer)
{
	ssize_t bytes_read = read(fd, buffer, BUFFER_SIZE);
	return bytes_read;
}
void close_file(int fd)
{
	close(fd);
}
void parse_dictionary(char *buffer, ssize_t bytes_read, struct s_dictionary *num_dictionary)
{
	char line[BUFFER_SIZE];
	int line_length = 0;
	int i = 0;
	int j = 0;
	while (i < bytes_read)
	{
		if (buffer[i] == '\n')
		{
			line[line_length] = '\0';
			char **split = ft_split(line, ": ");
			num_dictionary[j].key = ft_atoi(split[0]);
			num_dictionary[j].value = split[1];
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
struct s_dictionary *ft_load_dictionary(struct s_dictionary *num_dictionary)
{
	char *buffer = allocate_buffer();
	int fd = open_file();
	if (fd == -1)
	{
		ft_print_str("Dict Error\n");
		free(buffer);
		return NULL;
	}
	ssize_t bytes_read = read_file(fd, buffer);
	if (bytes_read == -1)
	{
		ft_print_str("Dict Error\n");
		free(buffer);
		close_file(fd);
		return NULL;
	}
	close_file(fd);
	parse_dictionary(buffer, bytes_read, num_dictionary);
	free(buffer);
	return num_dictionary;
}
