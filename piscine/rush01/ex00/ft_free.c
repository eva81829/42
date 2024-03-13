/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artopall <artopall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 12:52:05 by artopall          #+#    #+#             */
/*   Updated: 2024/01/21 12:57:18 by artopall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush.h"

void	ft_free_all(t_puzz *game)
{
	int	x;

	x = 0;
	while (x < game->size + 2)
	{
		free(game->grid[x]);
		x += 1;
	}
	free(game->grid);
	free(game);
}
