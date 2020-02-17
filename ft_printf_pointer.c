/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 17:35:11 by alvrodri          #+#    #+#             */
/*   Updated: 2020/02/17 18:14:46 by alvrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

void	ft_convert_to_hex_low(long nbr)
{
	char c;

	if (nbr > 16)
	{
		ft_convert_to_hex_low(nbr / 16);
		ft_convert_to_hex_low(nbr % 16);
	}
	else
	{
		c = nbr > 9 ? nbr + 87 : nbr + '0';
		write(1, &c, 1);
	}
}

void	ft_print_hex_low(int nbr)
{
	char c;

	if (nbr > 16)
	{
		ft_print_hex_low(nbr / 16);
		ft_print_hex_low(nbr % 16);
	}
	else
	{
		c = nbr > 9 ? nbr + 87 : nbr + '0';
		write(1, &c, 1);
	}
}

void	ft_print_hex_up(int nbr)
{
	char c;

	if (nbr > 16)
	{
		ft_print_hex_up(nbr / 16);
		ft_print_hex_up(nbr % 16);
	}
	else
	{
		c = nbr > 9 ? nbr + 55 : nbr + '0';
		write(1, &c, 1);
	}
}

void	ft_print_pointer(va_list list)
{
	void *p;
	long add;

	p = va_arg(list, void *);
	add = (long) p;
	write(1, "0x", 2);
	ft_convert_to_hex_low(add);
}
