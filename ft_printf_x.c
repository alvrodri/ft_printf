/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 15:05:10 by alvrodri          #+#    #+#             */
/*   Updated: 2020/02/20 19:30:48 by alvrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

void	ft_print_x_precision(char *str, t_flags *flags)
{
	char	*tmp;
	int		len;

	tmp = str;
	len = ft_strlen(str);
	if (flags->precision > len)
		str = ft_substr(str, 0, flags->precision);
	if (flags->width > 0 && flags->minus != 1)
		flags->written +=
			ft_print_blank(flags->width - flags->precision, 0);
	if (flags->precision > len)
		flags->written +=
			ft_print_blank(flags->precision - len, 1);
	if (flags->precision != 0)
	{
		ft_putstr_fd(str, 1);
		flags->written += len;
	}
	if (flags->width > 0 && flags->minus == 1)
		flags->written +=
			ft_print_blank(flags->width - flags->precision, 0);
	free(tmp);
}

void	ft_print_x(unsigned int nbr, t_flags *flags)
{
	char *str;

	str = ft_itoa_base(nbr, "0123456789abcdef", 16);
	if (flags->precision != -1)
	{
		ft_print_x_precision(str, flags);
		return ;
	}
	if (flags->minus == -1 && flags->width > 0)
		flags->written +=
			ft_print_blank(flags->width - ft_strlen(str), flags->zero);
	ft_putstr_fd(str, 1);
	flags->written += ft_strlen(str);
	if (flags->minus == 1 && flags->width > 0)
		flags->written +=
			ft_print_blank(flags->width - ft_strlen(str), flags->zero);
	free(str);
}
