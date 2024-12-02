/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_content_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:46:34 by fwu               #+#    #+#             */
/*   Updated: 2024/10/28 13:17:37 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static bool	map_count(t_map map)
{
	if (map.num_coin == ERR_NUM || map.num_coin < 1)
	{
		print_error(MSG_COIN_NUM_ERR);
		return (false);
	}
	if (map.num_exit == ERR_NUM || map.num_exit != 1)
	{
		print_error(MSG_EXIT_NUM_ERR);
		return (false);
	}
	if (map.num_player == ERR_NUM || map.num_player != 1)
	{
		print_error(MSG_PLAYER_NUM_ERR);
		return (false);
	}
	return (true);
}

static bool	map_content_is_character(t_map *map, int x, int y)
{
	char	map_content;

	map_content = map->data[y][x];
	if (map_content == MARK_COIN)
		map->num_coin++;
	else if (map_content == MARK_EXIT)
		map->num_exit++;
	else if (map_content == MARK_PLAYER)
		map->num_player++;
	else if (map_content == MARK_WALL)
		map->num_wall++;
	else if (map_content != MARK_SPACE)
	{
		print_error(MSG_CHARACTER_NOT_FOUND);
		return (false);
	}
	return (true);
}

bool	map_content_check(t_map *map)
{
	if (!loop_map(map, map_content_is_character))
		return (false);
	if (!map_count(*map))
		return (false);
	return (true);
}
