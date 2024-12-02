/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 23:27:20 by fwu               #+#    #+#             */
/*   Updated: 2024/10/28 14:22:59 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static bool	coin_create(t_scene *scene, int num, int map_y, int map_x)
{
	static int	idx = 0;
	t_png		png;

	if (!scene->coin)
		scene->coin = (t_coin *)ft_calloc(num, sizeof(t_coin));
	if (!scene->coin)
		return (false);
	set_png(&png, map_y + COUNTER_Y, map_x, PATH_COIN);
	if (!png_to_image(scene->mlx, &scene->coin[idx].img, png, true))
		return (false);
	scene->coin[idx].is_collected = false;
	idx++;
	return (true);
}

static bool	exit_create(t_scene *scene, int num, int map_y, int map_x)
{
	static int	idx = 0;
	t_png		png;

	if (!scene->exit)
		scene->exit = (t_exit *)ft_calloc(num, sizeof(t_exit));
	if (!scene->exit)
		return (false);
	set_png(&png, map_y + COUNTER_Y, map_x, PATH_EXIT_S);
	if (!png_to_image(scene->mlx, &scene->exit[idx].img[EXIT_S], png, true))
		return (false);
	set_png(&png, map_y + COUNTER_Y, map_x, PATH_EXIT_E);
	if (!png_to_image(scene->mlx, &scene->exit[idx].img[EXIT_E], png, false))
		return (false);
	idx++;
	return (true);
}

static bool	player_create(t_scene *scene, int num, int map_y, int map_x)
{
	static int	idx = 0;
	t_png		png;

	if (!scene->player)
		scene->player = (t_player *)ft_calloc(num, sizeof(t_player));
	if (!scene->player)
		return (false);
	set_png(&png, map_y + COUNTER_Y, map_x, PATH_PLAYER_R);
	if (!png_to_image(scene->mlx, &scene->player[idx].img[DIR_R], png, true))
		return (false);
	set_png(&png, map_y + COUNTER_Y, map_x, PATH_PLAYER_L);
	if (!png_to_image(scene->mlx, &scene->player[idx].img[DIR_L], png, false))
		return (false);
	idx++;
	return (true);
}

static bool	wall_create(t_scene *scene, int num, int map_y, int map_x)
{
	static int	idx = 0;
	t_png		png;

	if (!scene->wall)
		scene->wall = (t_wall *)ft_calloc(num, sizeof(t_wall));
	if (!scene->wall)
		return (false);
	set_png(&png, map_y + COUNTER_Y, map_x, PATH_WALL);
	if (!png_to_image(scene->mlx, &scene->wall[idx].img, png, true))
		return (false);
	idx++;
	return (true);
}

bool	character_create(t_scene *scene, int map_y, int map_x)
{
	char	map_content;
	bool	rst;

	map_content = scene->map.data[map_y][map_x];
	rst = true;
	if (map_content == MARK_COIN)
		rst = coin_create(scene, scene->map.num_coin, map_y, map_x);
	else if (map_content == MARK_EXIT)
		rst = exit_create(scene, scene->map.num_exit, map_y, map_x);
	else if (map_content == MARK_WALL)
		rst = wall_create(scene, scene->map.num_wall, map_y, map_x);
	else if (map_content == MARK_PLAYER)
		rst = player_create(scene, scene->map.num_player, map_y, map_x);
	return (rst);
}
