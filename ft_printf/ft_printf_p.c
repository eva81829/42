/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 19:43:09 by fwu               #+#    #+#             */
/*   Updated: 2024/03/07 13:58:20 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_p(void *value)
{
	int	count;

	ft_putstr_fd("0x", 1);
	ft_puthex((unsigned long)value, LOWER_CASE);
	count = get_hex_digits((unsigned long)value) + 2;
	return (count);
}
