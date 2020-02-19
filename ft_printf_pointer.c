/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 17:35:11 by alvrodri          #+#    #+#             */
/*   Updated: 2020/02/18 16:13:31 by alvrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

void	ft_print_ptrwidth(char *str, t_flags *flags)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(str);
	while (i < flags->width - len)
	{
		write(1, flags->zero == 1 ? "0" : " ", 1);
		(flags->written++);
		i++;
	}
}

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

void	ft_print_pointer(va_list list, t_flags *flags)
{
	write(1, "0x", 2);
	ft_convert_to_hex_low((long) va_arg(list, void *));
}
