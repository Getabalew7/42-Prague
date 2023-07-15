/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghailema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 12:24:36 by ghailema          #+#    #+#             */
/*   Updated: 2023/06/26 12:39:37 by ghailema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<fcntl.h>

void	ft_putchar(char *str)
{
	while (*str)
	{
		write(1, &*str, 1);
		str++;
	}
}

int	ft_display(char *file)
{
	int		r;
	int		fd;
	char	a;

	fd = open(file, 0);
	r = read(fd, &a, 1);
	while (r)
	{
		if (r == -1)
			return (0);
		write(1, &a, 1);
		r = read(fd, &a, 1);
	}
	close (fd);
	return (1);
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
	{
		ft_putchar("File name missing.\n");
		return (0);
	}
	else if (argc > 2)
	{
		ft_putchar("Too many arguments.\n");
		return (0);
	}
	else
	{
		if (!ft_display(argv[1]))
			ft_putchar("Cannot read file.\n");
	}
	return (0);
}
