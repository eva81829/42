/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 13:52:15 by fwu               #+#    #+#             */
/*   Updated: 2024/03/07 13:50:41 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

# define UPPER_CASE 1
# define LOWER_CASE 0

//ft_printf.c
int		ft_printf(const char *format, ...);

//ft_utils.c
void	ft_puthex(unsigned long value, int is_upper);
int		get_hex_digits(unsigned long value);
int		get_digits(long n);

//ft_printf_x.c
int		ft_printf_c(int value);
int		ft_printf_s(char *value);
int		ft_printf_p(void *value);
int		ft_printf_d(int value);
int		ft_printf_i(int value);
int		ft_printf_u(unsigned int value);
int		ft_printf_lx(unsigned int value);
int		ft_printf_ux(unsigned int value);

#endif // FT_PRINTF_H
