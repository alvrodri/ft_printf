/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvrodri <alvrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 11:54:43 by alvrodri          #+#    #+#             */
/*   Updated: 2020/02/20 14:59:23 by alvrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

void	ft_print_nbr(int nbr, t_flags *flags)
{
	long lnb;
	char c;

	lnb = nbr;
	if (lnb < 0)
	{
		lnb = -lnb;
		write(1, "-", 1);
		(flags->written)++;
	}
	if (lnb > 9)
	{
		ft_print_nbr(lnb / 10, flags);
		ft_print_nbr(lnb % 10, flags);
	}
	else
	{
		c = lnb + '0';
		write(1, &c, 1);
		(flags->written)++;
	}
}

void	ft_print_extra(int *nbr, int len, t_flags *flags)
{
	int i;

	i = 0;
	if (*nbr < 0 && flags->zero == 1)
	{
		*nbr = -(*nbr);
		write(1, "-", 1);
		(flags->written)++;
	}
	while (i < flags->width - len)
	{
		write(1, flags->zero == 1 ? "0" : " ", 1);
		(flags->written)++;
		i++;
	}
}

void	ft_print_wp(int nbr, t_flags *flags, int i)
{
	if (i != 1)
		i = 0;
	while (i < flags->width - flags->precision)
	{
		write(1, " ", 1);
		(flags->written)++;
		i++;
	}
}

void	ft_print_prec(int nbr, t_flags *flags, int m)
{
	int i;

	i = 0;
	if (nbr < 0)
	{
		i = 1;
		m = 1;
	}
	if (flags->minus == -1)
		ft_print_wp(nbr, flags, i);
	if (nbr < 0)
	{
		write(1, "-", 1);
		(flags->written)++;
		nbr = -nbr;
	}
	i = -1;
	while (++i < flags->precision - ft_get_length(nbr))
	{
		write(1, "0", 1);
		(flags->written)++;
	}
	ft_print_nbr(nbr, flags);
	if (flags->minus == 1)
		ft_print_wp(nbr, flags, m == 1 ? 1 : 0);
}

void	ft_print_int(int nbr, t_flags *flags)
{
	int m;

	if (flags->precision == 0)
	{
		ft_print_blank(flags->width, flags->zero);
		if (flags->width > 0)
			(flags->written) += flags->width;
		return ;
	}
	if (flags->precision != -1 && ft_get_length(nbr) < flags->precision)
		ft_print_prec(nbr, flags, m);
	else
	{
		if (flags->minus == 1)
		{
			ft_print_nbr(nbr, flags);
			ft_print_extra(&nbr, ft_get_length(nbr), flags);
		}
		else
		{
			ft_print_extra(&nbr, ft_get_length(nbr), flags);
			ft_print_nbr(nbr, flags);
		}
	}
}
