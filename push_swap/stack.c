/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:03:13 by fwu               #+#    #+#             */
/*   Updated: 2024/10/01 18:25:18 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initial_stacks(t_stacks *stacks)
{
	stacks->a = NULL;
	stacks->b = NULL;
	stacks->nums = 0;
	stacks->steps = 0;
}

bool	create_stacks(t_input input, t_stacks *stacks)
{
	int		i;
	int		num;
	t_ilist	*new_node;

	i = 0;
	stacks->nums = input.nums;
	while (i < stacks->nums)
	{
		num = input.sequence_out[i];
		new_node = ft_ilstnew(num);
		if (!new_node)
			return (false);
		if (!stacks->a)
			stacks->a = new_node;
		else
			ft_ilstadd_back(&stacks->a, new_node);
		i++;
	}
	return (true);
}

void	delete_content(int content)
{
	content = 0;
}

void	delete_stacks(t_stacks *stacks)
{
	if (stacks->a)
		ft_ilstclear(&stacks->a, delete_content);
	if (stacks->b)
		ft_ilstclear(&stacks->b, delete_content);
}

void	print_stacks(t_stacks stacks)
{
	t_ilist	*node_a;
	t_ilist	*node_b;

	node_a = stacks.a;
	node_b = stacks.b;
	while (node_a || node_b)
	{
		if (node_a && ft_ilstsize(node_a) >= ft_ilstsize(node_b))
		{
			ft_putnbr_fd(node_a->content, STDOUT_FILENO);
			node_a = node_a->next;
		}
		if (node_b && ft_ilstsize(node_b) > ft_ilstsize(node_a))
		{
			ft_putstr_fd("\t", STDOUT_FILENO);
			ft_putnbr_fd(node_b->content, STDOUT_FILENO);
			node_b = node_b->next;
		}
		ft_putstr_fd("\n", STDOUT_FILENO);
	}
	ft_putstr_fd("-\t-\n", STDOUT_FILENO);
	ft_putstr_fd("a\tb\n\n", STDOUT_FILENO);
}
