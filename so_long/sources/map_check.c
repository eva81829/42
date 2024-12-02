/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:46:34 by fwu               #+#    #+#             */
/*   Updated: 2024/10/28 13:18:01 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static bool	map_is_rectangular(t_map map)
{
	int	y;

	y = 0;
	while (y < map.height)
	{
		if (ft_strlen(map.data[y]) != map.width)
		{
			print_error(MSG_MAP_NOT_RECTANGULAR);
			return (false);
		}
		y++;
	}
	return (true);
}

static bool	map_edge_is_wall(t_map *map, int x, int y)
{
	char	map_content;

	map_content = map->data[y][x];
	if (y == 0 || x == 0 || y == map->height - 1 || x == map->width - 1)
	{
		if (map_content != MARK_WALL)
		{
			print_error(MSG_EDGE_IS_NOT_WALL);
			return (false);
		}
	}
	return (true);
}

bool	map_check(t_map *map)
{
	if (!map_is_rectangular(*map))
		return (false);
	if (!loop_map(map, map_edge_is_wall))
		return (false);
	if (!map_content_check(map))
		return (false);
	if (!path_find(*map))
		return (false);
	return (true);
}
