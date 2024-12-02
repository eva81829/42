/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_find.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:54:26 by fwu               #+#    #+#             */
/*   Updated: 2024/10/28 13:26:14 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// keep NUM_WALL_ELEMENTS for wall as indepent group
// element not wall start after NUM_WALL_ELEMENTS
// element not wall end with num_elements
int	get_element(int width, int y, int x)
{
	return (width * y + x + NUM_WALL_ELEMENTS);
}

void	uf_initialize(t_map map, int x, int y, t_ufind *uf)
{
	uf->num_elements = map.width * map.height + NUM_WALL_ELEMENTS;
	uf->cur_x = x;
	uf->cur_y = y;
	uf->cur_mark = map.data[uf->cur_y][uf->cur_x];
	uf->cur_element = get_element(map.width, uf->cur_y, uf->cur_x);
}

static bool	cep_have_same_root(t_map *map, int x, int y)
{
	static int	prev_root = NOT_EXIST;
	t_ufind		uf;

	uf_initialize(*map, x, y, &uf);
	if (uf.cur_mark == MARK_PLAYER || uf.cur_mark == MARK_COIN
		|| uf.cur_mark == MARK_EXIT)
	{
		uf.cur_root = find_root(uf.cur_element, uf.num_elements);
		if (uf.cur_root == ERR_NUM)
		{
			print_error(MSG_ROOT_NOT_FOUND);
			return (false);
		}
		if (prev_root == NOT_EXIST)
			prev_root = uf.cur_root;
		if (prev_root != uf.cur_root)
		{
			print_error(MSG_PATH_NOT_FOUND);
			return (false);
		}
	}
	return (true);
}

bool	path_find(t_map	map)
{
	if (!loop_map(&map, union_elements))
		return (false);
	if (!loop_map(&map, cep_have_same_root))
		return (false);
	return (true);
}
