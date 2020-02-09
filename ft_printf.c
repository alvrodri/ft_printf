/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:24:39 by alvrodri          #+#    #+#             */
/*   Updated: 2020/02/09 18:43:54 by alvrodri         ###   ########.fr       */
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

int	ft_printf(const char *str, ...)
{
	va_list args;
	int		i;

	va_start(args, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			if (str[i] == '%' && str[i + 1] == '%')
			{
				write(1, "%", 1);
			}
			else
			{
				ft_print_specific(str[i + 1], args);
			}
			i++;
		}
		else if (str[i] != '%')
		{
			write(1, &str[i], 1);
		}
		i++;
	}
	va_end(args);
}

int main()
{
	int				i;
	unsigned int 	ui;
	i = 10;
	ui = 50;

	ft_printf("percent: %%\nchar: %c\nstring: %s\nint: %d\npointer: %p\nunsigned int: %u\nhex low: %x\nhex up: %X\n", 'z', "me llamo alvaro", i, &i, ui, 1990, 1990);
}
