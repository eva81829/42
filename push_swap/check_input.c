/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:48:21 by fwu               #+#    #+#             */
/*   Updated: 2024/10/07 15:24:26 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initial_input(int argc, char **argv, t_input *input)
{
	input->argc = argc;
	input->argv = argv;
	input->new_argv = NULL;
	input->sequence_in = NULL;
	input->sequence_out = NULL;
	input->sequence_sorted = NULL;
	input->nums = 0;
}

void	delete_input(t_input *input)
{
	int	i;

	if (input->new_argv)
	{
		i = 0;
		while (input->new_argv[i])
		{
			free(input->new_argv[i]);
			i++;
		}
		free(input->new_argv);
		input->new_argv = NULL;
	}
	if (input->sequence_in)
		free(input->sequence_in);
	input->sequence_in = NULL;
	if (input->sequence_out)
		free(input->sequence_out);
	input->sequence_out = NULL;
	if (input->sequence_sorted)
		free(input->sequence_sorted);
	input->sequence_sorted = NULL;
}

bool	check_duplicate(int *sequence, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (sequence[i] == sequence[i + 1])
			return (false);
		i++;
	}
	return (true);
}

bool	check_args(t_input *input)
{
	int	i;

	if (input->argc <= 1)
		return (true);
	else if (input->argc == 2)
	{
		input->new_argv = ft_split(input->argv[1], ' ');
		if (!input->new_argv)
			return (false);
	}
	else
	{
		input->new_argv = (char **)ft_calloc(input->argc, sizeof(char *));
		if (!input->new_argv)
			return (false);
		i = 0;
		while (input->argv[++i])
		{
			input->new_argv[i - 1] = ft_strdup(input->argv[i]);
		}
	}
	return (true);
}

bool	check_sorted(t_input *input)
{
	int	i;

	if (input->nums == 0)
		return (true);
	i = 0;
	while (i < input->nums)
	{
		if (input->sequence_out[i] != input->sequence_sorted[i])
			return (false);
		i++;
	}
	return (true);
}
