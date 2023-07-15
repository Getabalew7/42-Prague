/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghailema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 10:48:16 by ghailema          #+#    #+#             */
/*   Updated: 2023/06/11 12:56:26 by ghailema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush(int x, int y);

int	fr_convert_to_integer(char *str)
{
	int	i;
	int	sum;
	int	digit;

	i = 0;
	sum = 0;
	while (str[i] != '\0')
	{
		digit = str[i] - '0';
		sum = sum * 10 + digit;
		i++;
	}
	return (sum);
}

int	main(int argc, char *argv[])
{
	int	x;
	int	y;

	if (argc != 3)
	{
		write(1, "Expected only 3 Arguments", 26);
		return (0);
	}
	x = fr_convert_to_integer(argv[1]);
	y = fr_convert_to_integer(argv[2]);
	rush(x, y);
	return (0);
}
