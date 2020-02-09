/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:28:30 by alvrodri          #+#    #+#             */
/*   Updated: 2020/02/09 18:37:17 by alvrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTILS_H
# define FT_PRINTF_UTILS_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include "./libft/libft.h"

int		ft_printf(const char *str, ...);
void	ft_print_char(va_list list);
void	ft_print_str(va_list list);
void	ft_print_int(int nbr);
void	ft_print_uint(unsigned int nbr);
void	ft_print_pointer(va_list list);
void	ft_print_hex_low(int nbr);
void	ft_print_hex_up(int nbr);

#endif
