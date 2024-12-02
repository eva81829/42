/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union_find.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 21:36:11 by fwu               #+#    #+#             */
/*   Updated: 2024/10/17 10:51:36 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static	int	*get_parent_arr(int num_elements)
{
	static int	*parent = NULL;
	int			i;

	if (!parent)
	{
		parent = (int *)ft_calloc((num_elements), sizeof(int));
		if (!parent)
		{
			print_error(MSG_PARENT_MALLOC_ERR);
			return (NULL);
		}
		i = 0;
		while (i < (num_elements))
		{
			parent[i] = i;
			i++;
		}
	}
	return (parent);
}

int	find_root(int element, int num_elements)
{
	int	*parent;

	parent = get_parent_arr(num_elements);
	if (!parent)
		return (ERR_NUM);
	if (element == parent[element])
		return (element);
	return (find_root(parent[element], num_elements));
}

bool	union_roots(int dst_element, int src_element, int num_elements)
{
	int	*parent;

	parent = get_parent_arr(num_elements);
	if (!parent)
		return (false);
	dst_element = find_root(dst_element, num_elements);
	src_element = find_root(src_element, num_elements);
	if ((dst_element == ERR_NUM) || (src_element == ERR_NUM))
		return (false);
	if (dst_element != src_element)
		parent[dst_element] = src_element;
	return (true);
}

void	print_roots(t_map map)
{
	t_ufind	uf;
	int		x;
	int		y;

	y = 0;
	while (y < map.height)
	{
		x = 0;
		while (x < map.width)
		{
			uf_initialize(map, x, y, &uf);
			uf.cur_root = find_root(uf.cur_element, uf.num_elements);
			ft_putnbr_fd(uf.cur_root, STDOUT_FILENO);
			ft_putstr_fd("\t", STDOUT_FILENO);
			x++;
		}
		ft_putstr_fd("\n", STDOUT_FILENO);
		y++;
	}
	ft_putstr_fd("\n", STDOUT_FILENO);
}
