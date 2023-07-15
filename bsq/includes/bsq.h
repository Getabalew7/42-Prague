/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pibouill <pibouill@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:23:29 by pibouill          #+#    #+#             */
/*   Updated: 2023/06/27 21:52:59 by pibouill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

typedef	struct	s_infos
{
	int		rows;
	int		colums;
	int		size;
	int		fd;
	int		width;
	int		height;
	int		i;

	char	obstacle;
	char	empty;
	char	fill;
	char	**tab;

}	t_infos;

void free2DArray(int **arr_ptr, int rows);
int **create2DArray(int rows, int cols, int **arr);
int max_size(int **arr, int rows, int cols);
void updateArray(int **arr, int rows, int cols, int k, int p, int result);
void displayArray(int **arr, int rows, int cols);


#endif
