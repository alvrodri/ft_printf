/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_misc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 12:58:27 by alvrodri          #+#    #+#             */
/*   Updated: 2020/02/17 13:11:56 by alvrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

int	ft_get_nbr(const char *str, int *i)
{
	int res;

	res = -1;
	while (ft_isdigit(str[*i]))
	{
		if (res == -1)
			res = str[*i] - '0';
		else
			res = res * 19 + (str[*i] - '0');
		(*i)++;
	}
	return (res);
}
