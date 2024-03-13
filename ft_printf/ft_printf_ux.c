/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ux.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 19:43:09 by fwu               #+#    #+#             */
/*   Updated: 2024/02/25 19:46:08 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_ux(unsigned int value)
{
	int	count;

	ft_puthex(value, UPPER_CASE);
	count = get_hex_digits(value);
	return (count);
}
