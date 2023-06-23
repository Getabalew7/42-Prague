/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghailema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:03:03 by ghailema          #+#    #+#             */
/*   Updated: 2023/06/15 18:03:05 by ghailema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*result;
	int	i;

	i = 0;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	result = (int *) malloc((max - min) * sizeof(int));
	if (!result)
	{
		return (-1);
	}
	while (min < max)
	{
		result[i] = min;
		min++;
		i++;
	}
	*range = result;
	return (i);
}
