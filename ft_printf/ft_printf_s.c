/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 19:43:09 by fwu               #+#    #+#             */
/*   Updated: 2024/03/07 15:50:09 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_s(char *value)
{
	int	count;

	if (!value)
	{
		ft_putstr_fd("(null)", 1);
		count = 6;
	}
	else
	{
		ft_putstr_fd(value, 1);
		count = ft_strlen(value);
	}
	return (count);
}
