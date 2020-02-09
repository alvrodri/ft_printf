/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_specific.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 12:39:28 by alvrodri          #+#    #+#             */
/*   Updated: 2020/02/09 18:27:48 by alvrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

void	ft_print_char(va_list list)
{
	char c;

	c = va_arg(list, int);
	write(1, &c, 1);
}

void	ft_print_str(va_list list)
{
	char	*str;
	int		i;
	
	str = va_arg(list, char *);
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_print_int(int nbr)
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
		ft_print_int(lnb / 10);
		ft_print_int(lnb % 10);
	}
	else
	{
		c = lnb + '0';
		write(1, &c, 1);
	}
}

void	ft_print_uint(unsigned int nbr)
{
	char c;

	if (nbr > 9)
	{
		ft_print_int(nbr / 10);
		ft_print_int(nbr % 10);
	}
	else
	{
		c = nbr + '0';
		write(1, &c, 1);
	}
}
