/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felricha <felricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:34:26 by felricha          #+#    #+#             */
/*   Updated: 2024/03/25 13:41:38 by felricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex_pf(const char *type, unsigned long long n, size_t *count)
{
	char	*hex_upper;
	char	*hex_lower;

	hex_upper = "0123456789ABCDEF";
	hex_lower = "0123456789abcdef";
	if (!type)
		return ;
	if (*type == 'X')
		ft_putnbrbase_pf(hex_upper, n, count);
	if (*type == 'x')
		ft_putnbrbase_pf(hex_lower, n, count);
}
