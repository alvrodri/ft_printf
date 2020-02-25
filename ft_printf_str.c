/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 17:24:47 by alvrodri          #+#    #+#             */
/*   Updated: 2020/02/22 17:21:48 by alvrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

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

int		ft_check_null(char **str, t_flags *flags)
{
	if (*str == NULL)
		*str = ft_strdup("(null)");
	else
		*str = ft_strdup(*str);
	if (flags->precision == 0)
	{
		flags->written +=
			ft_print_blank(flags->width, flags->zero);
		free(*str);
		return (1);
	}
	return (0);
}

void	ft_print_str(va_list list, t_flags *flags)
{
	char	*str;
	int		i;

	str = va_arg(list, char *);
	if (ft_check_null(&str, flags) == 1)
		return ;
	if (flags->precision != -1)
	{
		ft_print_strprec(str, flags);
		free(str);
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
	free(str);
}
