/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:24:39 by alvrodri          #+#    #+#             */
/*   Updated: 2020/02/20 19:24:27 by alvrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

void	ft_print_specific(char type, va_list list, t_flags *flags)
{
	if (flags->precision != -1 && flags->zero == 1)
		flags->zero = -1;
	if (flags->minus == 1 && flags->zero == 1)
		flags->zero = -1;
	if (type == 's')
		ft_print_str(list, flags);
	else if (type == 'c')
		ft_print_char(list, flags);
	else if (type == 'd' || type == 'i')
		ft_print_int(va_arg(list, int), flags);
	else if (type == 'p')
		ft_print_pointer(list, flags);
	else if (type == 'u')
		ft_print_uint(va_arg(list, unsigned int), flags);
	else if (type == 'x')
		ft_print_x(va_arg(list, unsigned int), flags);
	/*else if (type == 'X')
		ft_print_hex_up(va_arg(list, unsigned int));*/
	else if (type == '%')
		ft_print_percent(flags);
}

void	ft_init_flags(t_flags *flags)
{
	flags->width = 0;
	flags->precision = -1;
	flags->minus = -1;
	flags->zero = -1;
}

int		ft_enable_flags(const char *str, t_flags *flags, va_list args)
{
	int i;

	i = 0;
	while (str[i] == '0')
	{
		flags->zero = 1;
		i++;
	}
	if (str[i] == '-')
	{
		flags->minus = 1;
		i++;
	}
	while (str[i] == '0')
	{
		flags->zero = 1;
		i++;
	}
	if (str[i] == '*')
	{
		flags->width = va_arg(args, int);
		i++;
	}
	else
		flags->width = ft_get_nbr(str, &i);
	if (str[i] == '.')
	{
		i++;
		if (!ft_isdigit(str[i]) && str[i] != '*' && !ft_isalpha(str[i]))
			return (-1);
		if (str[i] == '*')
		{
			flags->precision = va_arg(args, int);
			i++;
		}
		else
			flags->precision = ft_get_nbr(str, &i);
	}
	if (!ft_isalpha(str[i]) && str[i] != '%')
		return (1);
	ft_print_specific(str[i], args, flags);
	return (i + 2);
}

int		ft_printf(const char *str, ...)
{
	va_list args;
	t_flags flags;
	int		i;

	va_start(args, str);
	flags.written = 0;
	ft_init_flags(&flags);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			i += ft_enable_flags(str + i + 1, &flags, args);
			if (i == -1)
				return (flags.written);
			ft_init_flags(&flags);
		}
		else if (str[i] != '%')
		{
			write(1, &str[i], 1);
			(flags.written)++;
			i++;
		}
		else
			i++;
	}
	va_end(args);
	return (flags.written);
}
/*
int main()
{
	ft_printf("%.5x", 21);
}*/
