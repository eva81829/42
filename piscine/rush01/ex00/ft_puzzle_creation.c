/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puzzle_creation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artopall <artopall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 07:12:36 by artopall          #+#    #+#             */
/*   Updated: 2024/01/21 10:58:05 by artopall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush.h"

int	ft_isoutside(int x, int y, int max, char c)
{
	if (c == 'f')
	{
		if (y == 0 && x > 0 && x < max - 1)
			return (1);
		else if (y == max - 1 && x > 0 && x < max - 1)
			return (1);
	}
	else
	{
		if (x == 0 && y > 0 && y < max - 1)
			return (1);
		else if (x == max - 1 && y > 0 && y < max - 1)
			return (1);
	}
	return (0);
}

void	ft_fill_left_right(t_puzz *puzzle, char *str)
{
	int	y;
	int	x;

	x = 0;
	while (x < puzzle->size + 2)
	{
		y = 0;
		while (y < puzzle->size + 2)
		{
			if (ft_isoutside(x, y, puzzle->size + 2, 'l'))
			{
				puzzle->grid[y][x] = (*str - '0');
				str += 2;
			}
			y += 1;
		}
		x += puzzle->size - 3;
	}
}

void	ft_fill_top_bottom(t_puzz *puzzle, char *str)
{
	int	y;
	int	x;

	y = 0;
	while (y < puzzle->size + 2)
	{
		x = 0;
		while (x < puzzle->size + 2)
		{
			if (ft_isoutside(x, y, puzzle->size + 2, 'f'))
			{
				puzzle->grid[y][x] = (*str - '0');
				str += 2;
			}
			else
				puzzle->grid[y][x] = 0;
			x += 1;
		}
		y += puzzle->size - 3;
	}
	ft_fill_left_right(puzzle, str);
}

t_puzz	*ft_create_grid(t_puzz *puzzle, char *str)
{
	int	i;

	i = 0;
	puzzle->grid = malloc(sizeof(int *) * (puzzle->size + 2));
	if (!puzzle->grid)
	{
		free(puzzle);
		return (NULL);
	}
	while (i < puzzle->size + 2)
	{
		puzzle->grid[i] = malloc(sizeof(int) * (puzzle->size + 2));
		if (!puzzle->grid[i])
		{
			while (--i >= 0)
				free(puzzle->grid[i]);
			free(puzzle->grid);
			free(puzzle);
			return (NULL);
		}
		i += 1;
	}
	ft_fill_top_bottom(puzzle, str);
	return (puzzle);
}
