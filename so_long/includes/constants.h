/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 21:23:20 by fwu               #+#    #+#             */
/*   Updated: 2024/10/28 14:56:10 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H

# define SO_LONG	"so_long"
# define NUM_ARGC	2

# define NOT_EXIST -1
# define UNION_FIND_FAIL -1
# define NUM_WALL_ELEMENTS 1
# define ROOT_WALL	0

# define MARK_COIN		'C'
# define MARK_EXIT		'E'
# define MARK_PLAYER	'P'
# define MARK_WALL		'1'
# define MARK_SPACE		'0'

// MLX
# define MLX_RESIZE false
# define CELL_WIDTH 32
# define CELL_HEIGHT 32
# define COUNTER_HEIGHT 32
# define COUNTER_Y 1

# define BG_R 0x00
# define BG_G 0x00
# define BG_B 0xFF
# define BG_A 0xFF

// abbreviation:
// S = Start
// E = End
// L = Left
// R = Right
// U = Up
// D = Down
# define PATH_BG					"./image/water.png"
# define PATH_COIN					"./image/grass.png"
# define PATH_EXIT_S				"./image/swirl_black.png"
# define PATH_EXIT_E				"./image/swirl_pink.png"
# define PATH_PLAYER_L				"./image/fish_gold_left.png"
# define PATH_PLAYER_R				"./image/fish_gold_right.png"
# define PATH_WALL					"./image/barrel.png"

# define NUM_DIR 	2
# define NUM_EXIT_IMG 2
# define EXIT_S 0
# define EXIT_E 1
# define DIR_R	0
# define DIR_L	1

# define KEY_E	MLX_KEY_ESCAPE
# define KEY_R	MLX_KEY_D
# define KEY_L	MLX_KEY_A
# define KEY_U 	MLX_KEY_W
# define KEY_D	MLX_KEY_S

typedef struct s_map
{
	int		height;
	int		width;
	char	**data;
	int		num_coin;
	int		num_exit;
	int		num_player;
	int		num_wall;
}	t_map;

typedef struct s_union_find
{
	int		num_elements;
	int		cur_x;
	int		cur_y;
	char	cur_mark;
	int		cur_element;
	int		cur_root;
	char	top_mark;
	int		top_element;
	char	left_mark;
	int		left_element;
}	t_ufind;

typedef struct s_background
{
	mlx_image_t	**img;
}	t_bg;

typedef struct s_counter
{
	mlx_image_t	*img;
}	t_counter;

typedef struct s_coin
{
	bool		is_collected;
	mlx_image_t	*img;
}	t_coin;

typedef struct s_exit
{
	mlx_image_t		*img[NUM_EXIT_IMG];
}	t_exit;

typedef struct s_player
{
	mlx_image_t		*img[NUM_DIR];
}	t_player;

typedef struct s_wall
{
	mlx_image_t		*img;
}	t_wall;

typedef struct s_png
{
	int		y;
	int		x;
	char	*path;
}	t_png;

typedef struct s_handler
{
	bool	key_r_press;
	bool	key_l_press;
	bool	key_u_press;
	bool	key_d_press;
}	t_handler;

typedef struct s_scene
{
	int			height;
	int			width;
	t_map		map;
	mlx_t		*mlx;
	t_bg		bg;
	t_counter	counter;
	t_coin		*coin;
	t_exit		*exit;
	t_player	*player;
	t_wall		*wall;
	bool		map_parse_end;
	int			player_x;
	int			player_y;
	int			num_coin_collected;
	bool		all_coin_collected;
	bool		is_game_end;
	t_handler	handler;
}	t_scene;

typedef struct s_game
{
	char	*map_name;
	t_map	map;
	t_scene	scene;
}	t_game;

#endif //CONSTANTS_H