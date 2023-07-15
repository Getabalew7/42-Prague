/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghailema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 10:03:40 by ghailema          #+#    #+#             */
/*   Updated: 2023/06/28 10:03:52 by ghailema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putstr(int fd, char *str);
int		is_directory(char *filename);

void	put_nl(int cur, int argc, char *filename, int files_num)
{
	if (files_num > 1)
	{
		if (cur != argc - 1)
			ft_putstr(1, "\n");
		if (is_directory(filename) == 1)
			ft_putstr(1, "\n");
	}
}
