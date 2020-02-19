/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 17:24:47 by alvrodri          #+#    #+#             */
/*   Updated: 2020/02/18 13:11:06 by alvrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

void	ft_print_width(char *str, t_flags *flags)
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

void	ft_print_strprec(char *str, t_flags *flags)
{
	int i;

	i = 0;
	while (i < flags->width - flags->precision)
	{
		write(1, flags->zero == 1 ? "0" : " ", 1);
		(flags->written)++;
		i++;
	}
	i = 0;
	while (i < flags->precision && str[i])
	{
		write(1, &str[i], 1);
		(flags->written)++;
		i++;
	}
}

void    ft_print_str(va_list list, t_flags *flags)
{
    char    *str;
    int     i;

    str = va_arg(list, char *);
    if (str == NULL)
    {
        write(1, "(null)", 6);
        return ;
    }
	if (flags->precision != -1) 
	{
		ft_print_strprec(str, flags);
		return ;
	}
	if (flags->width != -1 && flags->minus == -1)
		ft_print_width(str, flags);
    i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
		(flags->written++);
        i++;
    }
	if (flags->width != 1 && flags->minus == 1)
		ft_print_width(str, flags);
}
