/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:24:39 by alvrodri          #+#    #+#             */
/*   Updated: 2020/02/12 13:46:28 by alvrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

void	ft_print_specific(char type, va_list list)
{
	if (type == 's')
		ft_print_str(list);
	else if (type == 'c')
		ft_print_char(list);
	else if (type == 'd' || type == 'i')
		ft_print_int(va_arg(list, int));
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
	flags->minus = -1;
	flags->zero = -1;
}

void	ft_enable_flags(const char *str, t_flags *flags, va_list args)
{
	if (ft_isdigit(str[0]) && str[0] != '0')
		flags->width = ft_atoi(str);
	else if (str[0] == '-')
	{
		flags->minus = 1;
		flags->width = ft_atoi(str + 1);
	}
	else if (str[0] == '0')
	{
		flags->zero = 1;
		flags->width = ft_atoi(str);
	}
	printf("width: %d, minus: %d, zero: %d\n", flags->width, flags->minus, flags->zero);
}

int	ft_printf(const char *str, ...)
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
			ft_enable_flags(str + i + 1, &flags, args);
			i++;
		}
		else if (str[i] != '%')
		{
			//write(1, &str[i], 1);
			i++;
		}
	}
	va_end(args);
}

int main()
{
	ft_printf("%95d", 10);
	ft_printf("%-6d", 10);
	ft_printf("%02d", 10);
}
