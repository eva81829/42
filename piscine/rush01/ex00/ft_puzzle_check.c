/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puzzle_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artopall <artopall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 10:50:29 by artopall          #+#    #+#             */
/*   Updated: 2024/01/21 18:03:18 by artopall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush.h"

int	ft_check_param(char *param)
{
	int	i;
	int	max;
	int	count;

	i = 0;
	max = 1;
	count = 0;
	while (param[i])
	{
		if (i % 2 == 1 && ft_isspace(param[i]))
			i += 1;
		else if (i % 2 == 1 && !ft_isspace(param[i]))
			return (0);
		else if (ft_isdigit(param[i]))
		{
			if (param[i] - '0' >= max)
				max = param[i] - '0';
			i += 1;
			count += 1;
		}
	}
	if (max <= ft_sqrt(count) && count >= 9)
		return (count / 4);
	return (0);
}

t_puzz	*ft_checkparams(int ac, char **av)
{
	t_puzz	*puzzle;

	puzzle = malloc(sizeof(*puzzle));
	if (!puzzle)
		return (NULL);
	puzzle->size = 0;
	if (av[1])
		puzzle->size = ft_check_param(av[1]);
	if (ac != 2 || !puzzle->size)
	{
		free(puzzle);
		return (NULL);
	}
	return (ft_create_grid(puzzle, av[1]));
}
