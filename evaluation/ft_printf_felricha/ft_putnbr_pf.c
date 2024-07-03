/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felricha <felricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:04:20 by felricha          #+#    #+#             */
/*   Updated: 2024/03/13 16:49:30 by felricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_pf(int n, size_t *count)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar_pf('-', count);
		nb *= -1;
	}
	if (nb > 9)
	{
		ft_putnbr_pf(nb / 10, count);
		ft_putnbr_pf(nb % 10, count);
	}
	else
	{
		ft_putchar_pf(nb + '0', count);
	}
}
