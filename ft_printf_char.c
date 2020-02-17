/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 17:55:46 by alvrodri          #+#    #+#             */
/*   Updated: 2020/02/17 18:11:29 by alvrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

void	ft_print_cwidth(t_flags *flags)
{
	int i;

	i = 0;
	while (i < flags->width - 1)
	{
		write(1, flags->zero == 1 ? "0" : " ", 1);
		(flags->written)++;
		i++;
	}
}

void	ft_print_char(va_list args, t_flags *flags)
{
	char c;

	c = va_arg(args, int);
	if (flags->width != -1 && flags->minus != 1)
		ft_print_cwidth(flags);
	if (c != 0)
		write(1, &c, 1);
	if (flags->width != 1 && flags->minus == 1)
		ft_print_cwidth(flags);
	(flags->written)++;
}
