/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felricha <felricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:43:02 by felricha          #+#    #+#             */
/*   Updated: 2024/04/18 12:49:51 by felricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"
# include <stdio.h>

int		ft_printf(const char *input, ...);
void	ft_putchar_pf(char c, size_t *count);
void	ft_putstr_pf(char *str, size_t *count);
void	ft_puthex_pf(const char *type, unsigned long long n, size_t *count);
void	ft_putnbr_pf(int n, size_t *count);
void	ft_put_unsigned_pf(unsigned int n, size_t *count);
void	ft_printptr_pf(void *ptr, size_t *count);
void	ft_putnbrbase_pf(char *base, unsigned long long n, size_t *count);

#endif
