/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghailema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 16:49:07 by ghailema          #+#    #+#             */
/*   Updated: 2023/06/15 16:54:26 by ghailema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	*ft_range(int min, int max)
{
	int	*result;
	int	i;

	i = 0;
	if (min >= max)
		return (NULL);
	result = (int *)malloc((max - min) * sizeof(int));
	while (min < max)
	{
		result[i] = min;
		min++;
		i++;
	}
	return (result);
}
