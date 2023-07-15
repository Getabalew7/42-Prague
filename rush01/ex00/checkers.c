/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghailema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 18:21:18 by ghailema          #+#    #+#             */
/*   Updated: 2023/06/17 18:21:31 by ghailema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ft_checkers.c
void	ft_rev_int_tab(int *tab, int size);
int		ft_el_in_tab(int *row);
void	ft_get_cols(int col_tab[4], int tab[4][4], int col_num);

/*
 * ft_verifies that the line passed contains the correct number of visible boxes,
 * "val" is the values ​​given by the instruction
 * Row can represent either a row or a column
 */
int	ft_check(int *row, int val)
{
	int	stock;
	int	cur;
	int	num;

	cur = 1;
	stock = row[0];
	num = 1;
	while (num < 4)
	{
		if (row[num] > stock)
		{
			cur++;
			stock = row[num];
		}
		num++;
	}
	if (cur == val && ft_el_in_tab(row) == 0)
		return (1);
	else
		return (0);
}

/*
 * Reverse the row/column pass, make it pass by ft_check and
 * put it back in the right direction.
 * Allows to use the same ft_check function to ft_check both directions
 * of one row / column
 */
int	ft_check_reverse(int *row, int val)
{
	int	ret;

	ft_rev_int_tab(row, 4);
	ret = ft_check(row, val);
	ft_rev_int_tab(row, 4);
	return (ret);
}

/*
 * Calls the functions ft_check then ft_check_reverse on each line
 * val[n] is the value passed by the user for this line
 */
int	ft_verif_rows(int tab[4][4], int *val)
{
	if (ft_check(tab[0], val[8]) == 0 || ft_check_reverse(tab[0], val[12]) == 0)
		return (0);
	if (ft_check(tab[1], val[9]) == 0 || ft_check_reverse(tab[1], val[13]) == 0)
		return (0);
	if (ft_check(tab[2], val[10]) == 0 || ft_check_reverse(tab[2], val[14]) == 0)
		return (0);
	if (ft_check(tab[3], val[11]) == 0 || ft_check_reverse(tab[3], val[15]) == 0)
		return (0);
	return (1);
}

/*
 * Call the functions ft_check then ft_check_reverse on each column
 * val[n] is the value passed by the user for this column
 * We use ft_get_cols to put in test_tab all the values
 * of the column.
 */
int	ft_verif_cols(int tab[4][4], int *val)
{
	int	test_tab[4];

	ft_get_cols(test_tab, tab, 0);
	if (ft_check(test_tab, val[0]) == 0 || ft_check_reverse(test_tab, val[4]) == 0)
		return (0);
	ft_get_cols(test_tab, tab, 1);
	if (ft_check(test_tab, val[1]) == 0 || ft_check_reverse(test_tab, val[5]) == 0)
		return (0);
	ft_get_cols(test_tab, tab, 2);
	if (ft_check(test_tab, val[2]) == 0 || ft_check_reverse(test_tab, val[6]) == 0)
		return (0);
	ft_get_cols(test_tab, tab, 3);
	if (ft_check(test_tab, val[3]) == 0 || ft_check_reverse(test_tab, val[7]) == 0)
		return (0);
	return (1);
}

/*
 * Main function which calls the line ft_checks function
 * then columns
 */
int	ft_verif(int tab[4][4], int *val)
{
	if (ft_verif_rows(tab, val) == 0 || ft_verif_cols(tab, val) == 0)
		return (0);
	return (1);
}
