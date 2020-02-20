/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 10:45:11 by alvrodri          #+#    #+#             */
/*   Updated: 2020/02/20 15:03:33 by alvrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

void	ft_print_pwidth(t_flags *flags)
{
	int i;

	i = 0;
	while (i < flags->width - 1)
	{
		write(1, flags->zero == 1 && flags->minus != 1 ? "0" : " ", 1);
		(flags->written)++;
		i++;
	}
}

void	ft_print_percent(t_flags *flags)
{
	if (flags->width != -1 && flags->minus != 1)
		ft_print_pwidth(flags);
	write(1, "%", 1);
	if (flags->width != 1 && flags->minus == 1)
		ft_print_pwidth(flags);
	(flags->written)++;
}
