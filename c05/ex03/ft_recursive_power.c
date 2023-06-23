/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghailema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 09:59:43 by ghailema          #+#    #+#             */
/*   Updated: 2023/06/15 09:59:47 by ghailema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	int	result;

	result = 1;
	if (power > 0)
	{
		result = nb * ft_recursive_power(nb, power - 1);
	}
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	return (result);
}
