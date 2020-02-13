/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_specific.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 12:39:28 by alvrodri          #+#    #+#             */
/*   Updated: 2020/02/13 15:41:44 by alvrodri         ###   ########.fr       */
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

void	ft_print_uint(unsigned int nbr)
{
	char c;

	if (nbr > 9)
	{
		ft_print_uint(nbr / 10);
		ft_print_uint(nbr % 10);
	}
	else
	{
		c = nbr + '0';
		write(1, &c, 1);
	}
}
