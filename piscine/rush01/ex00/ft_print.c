/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artopall <artopall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 08:35:40 by artopall          #+#    #+#             */
/*   Updated: 2024/01/21 19:25:52 by artopall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush.h"

void	ft_print_grid(t_puzz *game)
{
	int	y;
	int	x;

	y = 1;
	while (y < game->size + 1)
	{
		x = 1;
		while (x < game->size + 1)
		{
			ft_putchar(' ');
			ft_putchar(game->grid[y][x] + '0');
			x += 1;
		}
		ft_putchar('\n');
		y += 1;
	}
}

void	ft_printf(int state, t_puzz *puzz)
{
	if (state == 0)
	{
		ft_putstr("Error\n");
		if (puzz)
		{
			ft_free_all(puzz);
		}
		return ;
	}
	ft_print_grid(puzz);
	ft_free_all(puzz);
}
