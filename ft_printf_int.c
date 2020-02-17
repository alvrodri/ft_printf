/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvrodri <alvrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 11:54:43 by alvrodri          #+#    #+#             */
/*   Updated: 2020/02/17 17:02:52 by alvrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

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

void	ft_print_prec(int nbr, t_flags flags)
{
	int i;

	i = 0;
	while (i < flags.width - flags.precision)
	{
		write(1, " ", 1);
		i++;
	}
	i = 0;
	while (i < flags.precision - ft_get_length(nbr))
	{
		write(1, "0", 1);
		i++;
	}
	ft_print_nbr(nbr);
}

void	ft_print_int(int nbr, t_flags flags)
{
	if (flags.precision != -1 && ft_get_length(nbr) < flags.precision)
	{
		ft_print_prec(nbr, flags);
	}
	else
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
}
