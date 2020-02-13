/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:24:39 by alvrodri          #+#    #+#             */
/*   Updated: 2020/02/13 16:19:17 by alvrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

void	ft_print_specific(char type, va_list list, t_flags flags)
{
	if (type == 's')
		ft_print_str(list);
	else if (type == 'c')
		ft_print_char(list);
	else if (type == 'd' || type == 'i')
		ft_print_int(va_arg(list, int), flags);
	else if (type == 'p')
		ft_print_pointer(list);
	else if (type == 'u')
		ft_print_uint(va_arg(list, unsigned int));
	else if (type == 'x')
		ft_print_hex_low(va_arg(list, int));
	else if (type == 'X')
		ft_print_hex_up(va_arg(list, int));
}

void	ft_init_flags(t_flags *flags)
{
	flags->width = -1;
	flags->precision = 1;
	flags->minus = -1;
	flags->zero = -1;
}

int		ft_enable_flags(const char *str, t_flags *flags, va_list args)
{
	int i;

	i = -1;
	while (str[++i] == '0')
		flags->zero = 1;
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
	while (ft_isdigit(str[i]))
	{
		if (flags->width == -1)
			flags->width = str[i] - '0';
		else
			flags->width = flags->width * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
		while (ft_isdigit(str[i]))
		{
			flags->precision = flags->precision * 10 + (str[i] - '0');
			i++;
		}
	ft_print_specific(str[i], args, *flags);
	return (i + 2);
}

int		ft_printf(const char *str, ...)
{
	va_list args;
	t_flags flags;
	int		i;

	va_start(args, str);
	ft_init_flags(&flags);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			i += ft_enable_flags(str + i + 1, &flags, args);
			ft_init_flags(&flags);
		}
		else if (str[i] != '%')
		{
			write(1, &str[i], 1);
			i++;
		}
	}
	va_end(args);
}

int main()
{
	/*printf("%05d || %5d || %-5d\n", 10, 10, 10);
	ft_printf("%05d || %5d || %-5d\n", 10, 10, 10);
	printf("%5d\n",1560133635);
	ft_printf("%5d\n",1560133635);
	printf("%07d\n",-2552);
	ft_printf("%07d",-2552);*/
	printf("%15.10d\n", -57);
	ft_printf("%15.10d\n", -57);
}
