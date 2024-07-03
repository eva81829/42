/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_pf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felricha <felricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:39:25 by felricha          #+#    #+#             */
/*   Updated: 2024/03/25 12:41:04 by felricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_unsigned_pf(unsigned int n, size_t *count)
{
	unsigned long	nb;

	nb = n;
	if (nb >= 10)
	{
		ft_put_unsigned_pf((nb / 10), count);
		ft_put_unsigned_pf((nb % 10), count);
	}
	else
		ft_putchar_pf((nb + '0'), count);
}
