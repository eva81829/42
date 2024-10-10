/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 12:59:15 by fwu               #+#    #+#             */
/*   Updated: 2024/10/08 17:03:41 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	push_swap(t_input *input, t_stacks	*stacks)
{
	if (!convert_input(input))
		return (false);
	if (check_sorted(input))
		return (true);
	if (!create_stacks(*input, stacks))
		return (false);
	if ((input->nums == 0) || (input->nums == 1))
		return (true);
	else if (input->nums == 2)
		two_sort(stacks);
	else if (input->nums == 3)
		three_sort(stacks);
	else if ((input->nums == 4) || (input->nums == 5))
		small_sort(stacks);
	else if (input->nums > 5)
		radix_sort(stacks);
	return (true);
}

int	main(int argc, char **argv)
{
	t_input		input;
	t_stacks	stacks;

	initial_input(argc, argv, &input);
	initial_stacks(&stacks);
	if (!push_swap(&input, &stacks))
	{
		ft_putstr_fd("Error\n", STDOUT_FILENO);
		delete_input(&input);
		delete_stacks(&stacks);
		return (1);
	}
	delete_input(&input);
	delete_stacks(&stacks);
	return (0);
}
