/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbase_pf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felricha <felricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 12:04:12 by felricha          #+#    #+#             */
/*   Updated: 2024/04/12 14:05:49 by felricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		i++;
	}
	return (i);
}

void	ft_putnbrbase_pf(char *base, unsigned long long n, size_t *count)
{
	unsigned long	nbl;

	nbl = n;
	if (nbl >= ft_strlen(base))
	{
		ft_putnbrbase_pf(base, (nbl / (ft_strlen(base))), count);
		ft_putnbrbase_pf(base, (nbl % (ft_strlen(base))), count);
	}
	else
		ft_putchar_pf((base[nbl % ft_strlen(base)]), count);
}
