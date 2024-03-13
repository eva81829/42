/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 19:43:09 by fwu               #+#    #+#             */
/*   Updated: 2024/03/07 13:58:10 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_lx(unsigned int value)
{
	int	count;

	ft_puthex(value, LOWER_CASE);
	count = get_hex_digits(value);
	return (count);
}
