/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 09:04:06 by artopall          #+#    #+#             */
/*   Updated: 2024/01/21 19:45:02 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush.h"

int	ft_ishiding(t_puzz *p, int x, int y, int num)
{
	int	i;
	int	tab[4];

	i = 1;
	tab[0] = p->grid[y][0];
	tab[1] = p->grid[0][x];
	tab[2] = 1;
	tab[3] = 1;
	(void)num;
	while (i <= p->size)
	{
		if (tab[2] <= p->grid[y][i])
			tab[2] += 1;
		i += 1;
	}
	return (tab[2] <= tab[0]);
}

int	ft_isdouble(t_puzz *p, int x, int y, int num)
{
	int	i;

	i = 1;
	while (i <= p->size)
	{
		if (p->grid[y][i] == num || p->grid[i][x] == num)
			return (0);
		i += 1;
	}
	return (1);
}
