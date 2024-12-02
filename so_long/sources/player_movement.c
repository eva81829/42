/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 03:21:22 by fwu               #+#    #+#             */
/*   Updated: 2024/10/28 15:02:10 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

bool	player_meet_wall(t_scene *scene, int next_x, int next_y)
{
	int	i;

	i = 0;
	while (i < scene->map.num_wall)
	{
		if ((next_y - scene->wall[i].img->instances[0].y < CELL_HEIGHT)
			&& (next_y - scene->wall[i].img->instances[0].y >= 0)
			&& (next_x - scene->wall[i].img->instances[0].x < CELL_WIDTH)
			&& (next_x - scene->wall[i].img->instances[0].x >= 0))
		{
			return (true);
		}
		i++;
	}
	return (false);
}

bool	player_move(t_scene *scene, int next_x, int next_y)
{
	scene->player->img[DIR_R]->instances[0].x = next_x;
	scene->player->img[DIR_R]->instances[0].y = next_y;
	scene->player->img[DIR_L]->instances[0].x = next_x;
	scene->player->img[DIR_L]->instances[0].y = next_y;
	if (!display_steps(scene))
		return (false);
	return (true);
}

static void	game_end_check(t_scene *scene)
{
	if (scene->num_coin_collected >= scene->map.num_coin)
	{
		scene->exit->img[EXIT_S]->instances[0].enabled = false;
		scene->exit->img[EXIT_E]->instances[0].enabled = true;
		scene->all_coin_collected = true;
	}
}

bool	player_meet_coin(t_scene *scene, int next_x, int next_y)
{
	int	i;

	i = 0;
	while (i < scene->map.num_coin)
	{
		if ((next_y - scene->coin[i].img->instances[0].y < CELL_HEIGHT)
			&& (next_y - scene->coin[i].img->instances[0].y >= 0)
			&& (next_x - scene->coin[i].img->instances[0].x < CELL_WIDTH)
			&& (next_x - scene->coin[i].img->instances[0].x >= 0)
			&& (!(scene->coin[i].is_collected)))
		{
			scene->coin[i].img->instances[0].enabled = false;
			scene->coin[i].is_collected = true;
			scene->num_coin_collected++;
			game_end_check(scene);
			return (true);
		}
		i++;
	}
	return (false);
}

void	player_meet_exit(t_scene *scene, int next_x, int next_y)
{
	if ((next_y - scene->exit->img[EXIT_E]->instances[0].y < CELL_HEIGHT)
		&& (next_y - scene->exit->img[EXIT_E]->instances[0].y >= 0)
		&& (next_x - scene->exit->img[EXIT_E]->instances[0].x < CELL_WIDTH)
		&& (next_x - scene->exit->img[EXIT_E]->instances[0].x >= 0)
		&& (scene->all_coin_collected))
	{
		scene->exit->img[EXIT_E]->instances[0].enabled = false;
		scene->player->img[DIR_R]->instances[0].enabled = false;
		scene->player->img[DIR_L]->instances[0].enabled = false;
		mlx_put_string(scene->mlx, "WIN", next_x, next_y);
		ft_putstr_fd("WIN\n", STDOUT_FILENO);
		scene->is_game_end = true;
	}
}
