/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:34:39 by fwu               #+#    #+#             */
/*   Updated: 2024/10/28 13:15:08 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// ./so_long map/valid_map1.ber
int32_t	main(int argc, char **argv)
{
	static t_game	game;

	if (argc != NUM_ARGC)
	{
		print_error(MSG_ARGC_ERR);
		return (EXIT_FAILURE);
	}
	game.map_name = argv[NUM_ARGC - 1];
	if (!map_create(&game.map, game.map_name))
		return (EXIT_FAILURE);
	if (!scene_create(&game.scene, game.map))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
