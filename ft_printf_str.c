/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 17:24:47 by alvrodri          #+#    #+#             */
/*   Updated: 2020/02/19 16:48:07 by alvrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

void	ft_print_strprec(char *str, t_flags *flags)
{
	int i;

	i = 0;
	if (flags->minus == -1)
		flags->written +=
			ft_print_blank(flags->width - ft_strlen(str), flags->zero);
	while (i < flags->precision && str[i])
	{
		write(1, &str[i], 1);
		(flags->written)++;
		i++;
	}
	if (flags->minus == 1)
		flags->written +=
			ft_print_blank(flags->width - ft_strlen(str), flags->zero);
}

void    ft_print_str(va_list list, t_flags *flags)
{
    char    *str;
    int     i;

    str = va_arg(list, char *);
    if (str == NULL)
    {
        write(1, "(null)", 6);
		(flags->written) += 6;
        return ;
    }
	if (flags->precision == 0)
	{
		flags->written +=
			ft_print_blank(flags->width, flags->zero);
		if (flags->width > 0)
			(flags->written) += flags->width;
		return ;
	}
	if (flags->precision != -1) 
	{
		ft_print_strprec(str, flags);
		return ;
	}
	if (flags->width > 0 && flags->minus == -1)
		flags->written +=
			ft_print_blank(flags->width - ft_strlen(str), flags->zero);
    i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
		(flags->written++);
        i++;
    }
	if (flags->width > 0 && flags->minus == 1)
		flags->written +=
			ft_print_blank(flags->width - ft_strlen(str), flags->zero);
}
