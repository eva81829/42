/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puzzle_start.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 07:33:50 by artopall          #+#    #+#             */
/*   Updated: 2024/01/21 19:48:16 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush.h"

int	ft_puzz_solve(t_puzz *p, int x, int y)
{
	int	num;

	while (++y < p->size + 1)
	{
		x = 0;
		while (++x < p->size + 1)
		{
			if (p->grid[y][x] == 0)
			{
				num = 0;
				while (++num <= p->size)
				{
					if (ft_isdouble(p, x, y, num))
					{
						p->grid[y][x] = num;
						if (ft_puzz_solve(p, 0, 0))
							return (1);
						p->grid[y][x] = 0;
					}
				}
				return (0);
			}
		}
	}
	return (1);
}

void	ft_puzz_start(t_puzz *p)
{
	if (!p)
	{
		ft_printf(0, p);
		return ;
	}
	ft_printf(ft_puzz_solve(p, 0, 0), p);
}
