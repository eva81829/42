/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artopall <artopall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 07:06:02 by artopall          #+#    #+#             */
/*   Updated: 2024/01/21 12:06:00 by artopall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str += 1;
	}
}

int	ft_isspace(char c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

int	ft_isdigit(char c)
{
	return (c >= '1' && c <= '9');
}

int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	while (i < 10)
	{
		if (i * i == nb)
		{
			return (i);
		}
		i += 1;
	}
	return (0);
}
