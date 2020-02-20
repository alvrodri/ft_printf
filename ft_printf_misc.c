/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_misc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 12:58:27 by alvrodri          #+#    #+#             */
/*   Updated: 2020/02/20 15:04:02 by alvrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

int	ft_get_nbr(const char *str, int *i)
{
	int res;

	res = -1;
	if (ft_isalpha(str[*i]))
		res = 0;
	while (ft_isdigit(str[*i]))
	{
		if (res == -1)
			res = str[*i] - '0';
		else
			res = res * 10 + (str[*i] - '0');
		(*i)++;
	}
	return (res);
}

int	ft_get_length(int nbr)
{
	int len;

	len = nbr < 0 ? 1 : 0;
	if (nbr < 0)
		nbr = -nbr;
	while (nbr > 9)
	{
		nbr /= 10;
		len++;
	}
	return (len + 1);
}

int	ft_print_blank(int len, int zero)
{
	int i;

	i = -1;
	while (++i < len)
		write(1, zero == 1 ? "0" : " ", 1);
	return (i);
}
