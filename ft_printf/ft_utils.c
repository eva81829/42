/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:50:04 by fwu               #+#    #+#             */
/*   Updated: 2024/03/07 13:45:14 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	gethex(unsigned long value, int is_upper)
{
	char	*hex_map;

	if (is_upper == UPPER_CASE)
	{
		hex_map = "0123456789ABCDEF";
	}
	else
	{
		hex_map = "0123456789abcdef";
	}
	if (value >= 0 && value <= 15)
	{
		return (*(value + hex_map));
	}
	return (*hex_map);
}

void	ft_puthex(unsigned long value, int is_upper)
{
	char	c;

	if (value <= 15)
	{
		c = gethex(value, is_upper);
		ft_putchar_fd(c, 1);
	}
	else
	{
		ft_puthex(value / 16, is_upper);
		c = gethex(value % 16, is_upper);
		ft_putchar_fd(c, 1);
	}
}

int	get_hex_digits(unsigned long value)
{
	int	count;

	count = 0;
	while (1)
	{
		if (value / 16 <= 0)
		{
			count++;
			break ;
		}
		count++;
		value /= 16;
	}
	return (count);
}

int	get_digits(long value)
{
	int	count;

	count = 0;
	if (value < 0)
	{
		count++;
		value *= -1;
	}
	while (1)
	{
		if (value / 10 <= 0)
		{
			count++;
			break ;
		}
		count++;
		value /= 10;
	}
	return (count);
}
