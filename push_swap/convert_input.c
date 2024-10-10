/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 19:10:57 by fwu               #+#    #+#             */
/*   Updated: 2024/10/07 15:17:28 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// i: num of times to get the current biggest number
// j: idx of each element to be swapped   
static void	bubble_sort(int *sequence, int len)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < len - 1)
	{
		j = 0;
		while (j < len - 1 - i)
		{
			if (sequence[j + 1] < sequence[j])
			{
				tmp = sequence[j];
				sequence[j] = sequence[j + 1];
				sequence[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

static bool	convert_sequence(t_input *input)
{
	int	i;
	int	j;

	bubble_sort(input->sequence_in, input->nums);
	if (!check_duplicate(input->sequence_in, input->nums))
		return (false);
	i = 0;
	while (i < input->nums)
	{
		j = 0;
		while (j < input->nums)
		{
			if (input->sequence_out[i] == input->sequence_in[j])
			{
				input->sequence_out[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
	return (true);
}

static bool	copy_sequence(t_input *input)
{
	int		i;
	char	*str;

	i = 0;
	while (input->new_argv && input->new_argv[i])
	{
		str = input->new_argv[i];
		if (!ft_isint(str))
			return (false);
		input->sequence_in[i] = ft_atoi(str);
		input->sequence_out[i] = ft_atoi(str);
		input->sequence_sorted[i] = i;
		i++;
	}
	return (true);
}

static bool	create_sequence(t_input *input)
{
	int	i;

	i = 0;
	while (input->new_argv && input->new_argv[i])
	{
		i++;
	}
	input->nums = i;
	if (input->nums == 0)
		return (true);
	input->sequence_in = (int *)ft_calloc((input->nums), sizeof(int));
	if (!input->sequence_in)
		return (false);
	input->sequence_out = (int *)ft_calloc((input->nums), sizeof(int));
	if (!input->sequence_out)
		return (false);
	input->sequence_sorted = (int *)ft_calloc((input->nums), sizeof(int));
	if (!input->sequence_sorted)
		return (false);
	return (true);
}

bool	convert_input(t_input *input)
{
	if (!check_args(input))
		return (false);
	if (!create_sequence(input))
		return (false);
	if (!copy_sequence(input))
		return (false);
	if (!convert_sequence(input))
		return (false);
	return (true);
}
