/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:47:26 by fwu               #+#    #+#             */
/*   Updated: 2024/10/28 13:28:22 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../Libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include "constants.h"
# include "error.h"

// map_create.c
bool	map_create(t_map *map, char *map_name);

// map_initialize.c
bool	loop_map(t_map *map, bool (*f)(t_map *map, int x, int y));
void	map_initialize(t_map	*map);
void	print_map(t_map	map);

// map_check.c
bool	map_check(t_map *map);

// map_content_check.c
bool	map_content_check(t_map *map);

// path_find.c
int		get_element(int width, int y, int x);
void	uf_initialize(t_map map, int x, int y, t_ufind *uf);
bool	path_find(t_map	map);

// union_elements.c
bool	union_elements(t_map *map, int x, int y);

// union_find.c
int		find_root(int element, int num_elements);
bool	union_roots(int dst_element, int src_element, int num_elements);
// void	print_roots(t_map map);

// scene_create.c
void	scene_initialize(t_scene *scene, t_map	map);
bool	display_steps(t_scene *scene);
bool	scene_create(t_scene *scene, t_map	map);

// bg_create.c
bool	mlx_create(t_scene *scene);
void	set_png(t_png *png, int map_y, int map_x, char *path);
bool	png_to_image(mlx_t *mlx, mlx_image_t **img, t_png png, bool visible);
bool	bg_create(t_scene *scene, int num_img);

// character_create.c
bool	character_create(t_scene *scene, int y, int x);

// mlx_handler.c
void	mlx_handler_start(t_scene *scene);

// player_movement.c
bool	player_meet_wall(t_scene *scene, int next_x, int next_y);
bool	player_move(t_scene *scene, int next_x, int next_y);
bool	player_meet_coin(t_scene *scene, int next_x, int next_y);
void	player_meet_exit(t_scene *scene, int next_x, int next_y);

// error.c
void	print_error(char *error_msg);

#endif //SO_LONG_H