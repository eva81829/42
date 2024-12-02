/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 03:21:22 by fwu               #+#    #+#             */
/*   Updated: 2024/10/28 15:04:44 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	handler_key_end(void	*param)
{
	t_scene	*scene;

	scene = (t_scene *) param;
	if (mlx_is_key_down(scene->mlx, KEY_E))
		mlx_close_window(scene->mlx);
}

static void	player_take_movement(t_scene *scene, int cur_key)
{
	int	next_x;
	int	next_y;

	next_x = scene->player->img[DIR_R]->instances[0].x;
	next_y = scene->player->img[DIR_R]->instances[0].y;
	if (cur_key == KEY_R)
		next_x += CELL_WIDTH;
	else if (cur_key == KEY_L)
		next_x -= CELL_WIDTH;
	else if (cur_key == KEY_U)
		next_y -= CELL_HEIGHT;
	else if (cur_key == KEY_D)
		next_y += CELL_HEIGHT;
	if (player_meet_wall(scene, next_x, next_y))
		return ;
	if (!player_move(scene, next_x, next_y))
		return ;
	if (player_meet_coin(scene, next_x, next_y))
		return ;
	player_meet_exit(scene, next_x, next_y);
}

static void	handler_key_horizontal(void	*param)
{
	t_scene	*scene;

	scene = (t_scene *) param;
	if (scene->is_game_end)
		return ;
	if (!mlx_is_key_down(scene->mlx, KEY_R) && scene->handler.key_r_press)
		scene->handler.key_r_press = false;
	if ((mlx_is_key_down(scene->mlx, KEY_R)) && (!scene->handler.key_r_press))
	{
		scene->player->img[DIR_R]->instances[0].enabled = true;
		scene->player->img[DIR_L]->instances[0].enabled = false;
		player_take_movement(scene, KEY_R);
		scene->handler.key_r_press = true;
	}
	if (!mlx_is_key_down(scene->mlx, KEY_L) && scene->handler.key_l_press)
		scene->handler.key_l_press = false;
	if ((mlx_is_key_down(scene->mlx, KEY_L)) && (!scene->handler.key_l_press))
	{
		scene->player->img[DIR_R]->instances[0].enabled = false;
		scene->player->img[DIR_L]->instances[0].enabled = true;
		player_take_movement(scene, KEY_L);
		scene->handler.key_l_press = true;
	}
}

static void	handler_key_vertical(void	*param)
{
	t_scene	*scene;

	scene = (t_scene *) param;
	if (scene->is_game_end)
		return ;
	if (!mlx_is_key_down(scene->mlx, KEY_U) && scene->handler.key_u_press)
		scene->handler.key_u_press = false;
	if ((mlx_is_key_down(scene->mlx, KEY_U)) && (!scene->handler.key_u_press))
	{
		player_take_movement(scene, KEY_U);
		scene->handler.key_u_press = true;
	}
	if (!mlx_is_key_down(scene->mlx, KEY_D) && scene->handler.key_d_press)
		scene->handler.key_d_press = false;
	if ((mlx_is_key_down(scene->mlx, KEY_D)) && (!scene->handler.key_d_press))
	{
		player_take_movement(scene, KEY_D);
		scene->handler.key_d_press = true;
	}
}

void	mlx_handler_start(t_scene	*scene)
{
	mlx_loop_hook(scene->mlx, handler_key_end, scene);
	mlx_loop_hook(scene->mlx, handler_key_horizontal, scene);
	mlx_loop_hook(scene->mlx, handler_key_vertical, scene);
	mlx_loop(scene->mlx);
}
