/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvrodri <alvrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 11:54:43 by alvrodri          #+#    #+#             */
/*   Updated: 2020/02/17 13:24:26 by alvrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

int		ft_get_length(int nbr)
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

void	ft_print_nbr(int nbr)
{
	long lnb;
	char c;

	lnb = nbr;
	if (lnb < 0)
	{
		lnb = -lnb;
		write(1, "-", 1);
	}
	if (lnb > 9)
	{
		ft_print_nbr(lnb / 10);
		ft_print_nbr(lnb % 10);
	}
	else
	{
		c = lnb + '0';
		write(1, &c, 1);
	}
}

void	ft_print_extra(int *nbr, int len, t_flags flags)
{
	int i;

	i = 0;
	if (*nbr < 0)
	{
		write(1, "-", 1);
		*nbr = -*nbr;
	}
	while (i < flags.width - len)
	{
		write(1, flags.zero == 1 ? "0" : " ", 1);
		i++;
	}
}

void	ft_print_int(int nbr, t_flags flags)
{
	if (flags.minus == 1)
	{
		ft_print_nbr(nbr);
		ft_print_extra(&nbr, ft_get_length(nbr), flags);
	}
	else
	{
		ft_print_extra(&nbr, ft_get_length(nbr), flags);
		ft_print_nbr(nbr);
	}
}
