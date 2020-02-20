/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 17:24:47 by alvrodri          #+#    #+#             */
/*   Updated: 2020/02/20 16:40:13 by alvrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

int		ft_get_spaces(char *str, t_flags *flags)
{
	if (flags->width > 0 && flags->precision > ft_strlen(str))
		return (flags->width - ft_strlen(str));
	else
		return (flags->width - flags->precision);
}

void	ft_print_strprec(char *str, t_flags *flags)
{
	int i;

	i = 0;
	if (flags->minus == -1)
		flags->written +=
			ft_print_blank(ft_get_spaces(str, flags), flags->zero);
	while (i < flags->precision && str[i])
	{
		write(1, &str[i], 1);
		(flags->written)++;
		i++;
	}
	if (flags->minus == 1)
		flags->written +=
			ft_print_blank(ft_get_spaces(str, flags), flags->zero);
}

void	ft_print_tstr(char *str, t_flags *flags, int i)
{
	while (str[i])
	{
		write(1, &str[i], 1);
		(flags->written++);
		i++;
	}
}

int		ft_check_null(char **str, int *n, t_flags *flags)
{
	if (*str == NULL)
	{
		*str = ft_strdup("(null)");
		*n = 1;
	}
	if (flags->precision == 0)
	{
		flags->written +=
			ft_print_blank(flags->width, flags->zero);
		return (1);
	}
	return (0);
}

void	ft_print_str(va_list list, t_flags *flags)
{
	char	*str;
	int		i;
	int		n;

	str = va_arg(list, char *);
	if (ft_check_null(&str, &n, flags) == 1)
		return ;
	if (flags->precision != -1)
	{
		ft_print_strprec(str, flags);
		return ;
	}
	if (flags->width > 0 && flags->minus == -1)
		flags->written +=
			ft_print_blank(flags->width - ft_strlen(str), flags->zero);
	i = 0;
	ft_print_tstr(str, flags, i);
	if (flags->width > 0 && flags->minus == 1)
		flags->written +=
			ft_print_blank(flags->width - ft_strlen(str), flags->zero);
	if (n == 1)
		free(str);
}
