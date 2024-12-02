/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:54:26 by fwu               #+#    #+#             */
/*   Updated: 2024/10/22 18:04:34 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static	bool	union_top_left(t_ufind *uf, bool utop, bool uleft)
{
	bool	rst;

	rst = true;
	if (rst && utop)
		rst = union_roots(uf->cur_element, uf->top_element, uf->num_elements);
	if (rst && uleft)
		rst = union_roots(uf->cur_element, uf->left_element, uf->num_elements);
	return (rst);
}

static	bool	union_not_wall_elements(t_ufind *uf)
{
	bool	utop;
	bool	uleft;

	utop = (uf->top_mark != MARK_WALL);
	uleft = (uf->left_mark != MARK_WALL);
	return (union_top_left(uf, utop, uleft));
}

static	bool	uf_set_top_left(t_map map, t_ufind *uf)
{
	if (uf->cur_y == 0 || uf->cur_x == 0
		|| uf->cur_y == map.height - 1 || uf->cur_x == map.width - 1)
	{
		print_error(MSG_EDGE_CANT_SET_TOP_LEFT);
		return (false);
	}
	uf->top_mark = map.data[uf->cur_y - 1][uf->cur_x];
	uf->top_element = get_element(map.width, uf->cur_y - 1, uf->cur_x);
	uf->left_mark = map.data[uf->cur_y][uf->cur_x - 1];
	uf->left_element = get_element(map.width, uf->cur_y, uf->cur_x - 1);
	return (true);
}

bool	union_elements(t_map *map, int x, int y)
{
	t_ufind	uf;

	uf_initialize(*map, x, y, &uf);
	if (uf.cur_mark == MARK_WALL)
		return (union_roots(uf.cur_element, ROOT_WALL, uf.num_elements));
	else
	{
		if (!uf_set_top_left(*map, &uf))
			return (false);
		if (!union_not_wall_elements(&uf))
			return (false);
	}
	return (true);
}
