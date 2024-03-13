/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 19:43:09 by fwu               #+#    #+#             */
/*   Updated: 2024/03/12 16:45:19 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_u(unsigned int value)
{
	int	count;

	if (value > 9)
	{
		ft_putnbr_fd(value / 10, 1);
	}
	ft_putchar_fd((value % 10) + '0', 1);
	count = get_digits(value);
	return (count);
}
