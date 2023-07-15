/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghailema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:01:52 by ghailema          #+#    #+#             */
/*   Updated: 2023/06/26 14:18:53 by ghailema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<libgen.h>
#include<errno.h>
# define MAX_BUFFER_SIZE 4096

void	ft_put_str(char *str)
{
	while (*str)
	{
		write(1, &*str,1);
		str++;
	}
}

void	ft_display_file(int fd, char *filename)
{
	int	ret;
	char	buffer[MAX_BUFFER_SIZE + 1];

	ret = read(fd, buffer, MAX_BUFFER_SIZE);
	while (ret)
	{
		if (ret == -1)
		{
			ft_put_str("cat: ");
			ft_put_str(filename);
			ft_put_str(":");
			ft_put_str(strerror(errno));
			ft_put_str("\n");
			return ;
		}
		buffer[ret]= '\0';
		ft_put_str(buffer);
		ret = read(fd, buffer, MAX_BUFFER_SIZE);
	}
}
int	main(int argc, char **argv)
{
	int	fd;
	char	*filename;

	if (argc == 1)
	{
		ft_display_file(0,"");
	}
	else
	{
		while (--argc > 0)
		{
			filename = basename(argv[argc]);
			fd = open(argv[argc],O_RDONLY);
			if (fd == -1)
			{
				ft_put_str("cat: ");
				ft_put_str(filename);
				ft_put_str(":");
				ft_put_str(strerror(errno));
				ft_put_str("\n");
				continue;
			}
			ft_display_file(fd, filename);
			if (close(fd) == -1)
			{
				ft_put_str("cat: ");
				ft_put_str(filename);
				ft_put_str(": ");
				ft_put_str(strerror(errno));
				ft_put_str("\n");
				continue;
			}
		}
	}
	return (0);
}
