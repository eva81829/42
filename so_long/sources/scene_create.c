/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 23:27:20 by fwu               #+#    #+#             */
/*   Updated: 2024/10/28 14:53:13 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	scene_initialize(t_scene *scene, t_map	map)
{
	scene->map = map;
	scene->height = map.height * CELL_HEIGHT + COUNTER_HEIGHT;
	scene->width = map.width * CELL_WIDTH;
	scene->counter.img = NULL;
	scene->coin = NULL;
	scene->exit = NULL;
	scene->player = NULL;
	scene->wall = NULL;
	scene->map_parse_end = false;
	scene->player_x = NOT_EXIST;
	scene->player_y = NOT_EXIST;
	scene->num_coin_collected = 0;
	scene->all_coin_collected = false;
	scene->is_game_end = false;
	scene->handler.key_r_press = false;
	scene->handler.key_l_press = false;
	scene->handler.key_u_press = false;
	scene->handler.key_d_press = false;
}

bool	display_steps(t_scene *scene)
{
	static int	steps = 0;
	char		*str_steps;

	str_steps = ft_itoa(steps);
	if (scene->counter.img)
		mlx_delete_image(scene->mlx, scene->counter.img);
	scene->counter.img = mlx_put_string(scene->mlx, str_steps, 0, 0);
	if (str_steps)
	{
		free (str_steps);
		str_steps = NULL;
	}
	if (!scene->counter.img)
	{
		perror(mlx_strerror(mlx_errno));
		return (false);
	}
	ft_putnbr_fd(steps, STDOUT_FILENO);
	ft_putstr_fd("\n", STDOUT_FILENO);
	if (steps < INT_MAX)
		steps++;
	return (true);
}

static bool	character_parse(t_scene *scene, char map_content, int y, int x)
{
	if ((!scene->map_parse_end) && (map_content == MARK_PLAYER))
	{
		scene->player_y = y;
		scene->player_x = x;
	}
	else if (!character_create(scene, y, x))
		return (false);
	return (true);
}

static bool	map_parse(t_scene *scene)
{
	int	x;
	int	y;

	y = 0;
	while (y < scene->map.height)
	{
		x = 0;
		while (x < scene->map.width)
		{
			if (!character_parse(scene, scene->map.data[y][x], y, x))
				return (false);
			x++;
		}
		y++;
	}
	scene->map_parse_end = true;
	character_parse(scene, MARK_PLAYER, scene->player_y, scene->player_x);
	return (true);
}

bool	scene_create(t_scene *scene, t_map	map)
{
	int	bg_num_img;

	scene_initialize(scene, map);
	if (!mlx_create(scene))
		return (false);
	bg_num_img = (scene->height / CELL_HEIGHT) * (scene->width / CELL_WIDTH);
	if (!bg_create(scene, bg_num_img))
		return (false);
	if (!display_steps(scene))
		return (false);
	if (!map_parse(scene))
		return (false);
	mlx_handler_start(scene);
	mlx_terminate(scene->mlx);
	return (true);
}
