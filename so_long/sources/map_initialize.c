/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_initialize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:46:34 by fwu               #+#    #+#             */
/*   Updated: 2024/10/28 13:21:49 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

bool	loop_map(t_map *map, bool (*f)(t_map *map, int x, int y))
{
	int	x;
	int	y;	

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (!f(map, x, y))
				return (false);
			x++;
		}
		y++;
	}
	return (true);
}

void	map_initialize(t_map	*map)
{
	map->height = 0;
	map->width = 0;
	map->data = NULL;
	map->num_coin = 0;
	map->num_exit = 0;
	map->num_player = 0;
}

void	print_map(t_map	map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < ft_strlen(map.data[i]))
		{
			ft_putchar_fd(map.data[i][j], STDOUT_FILENO);
			ft_putstr_fd("\t", STDOUT_FILENO);
			j++;
		}
		ft_putchar_fd('\n', STDOUT_FILENO);
		i++;
	}
	ft_putchar_fd('\n', STDOUT_FILENO);
}
