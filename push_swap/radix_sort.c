/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:27:03 by fwu               #+#    #+#             */
/*   Updated: 2024/10/02 18:50:24 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_num(t_ilist *stack)
{
	int	max_num;

	max_num = 0;
	if (!stack)
		return (max_num);
	while (stack)
	{
		if (stack->content > max_num)
		{
			max_num = stack->content;
		}
		stack = stack->next;
	}
	return (max_num);
}

static int	get_max_bits(int max_num)
{
	int	max_bits;

	max_bits = 0;
	while (max_num >> max_bits)
	{
		max_bits += 1;
	}
	return (max_bits);
}

static void	sort_stacks(t_stacks *stacks, t_sort *sort)
{
	int	i;
	int	j;

	i = 0;
	sort->cur_b_size = 0;
	while (stacks->a && i++ < stacks->nums)
	{
		sort->cur_a_num = stacks->a->content;
		if (((sort->cur_a_num >> sort->cur_bit) & 1) == 0)
		{
			move_stacks(stacks, PB);
			sort->cur_b_size++;
		}
		else
		{
			move_stacks(stacks, RA);
		}
	}
	j = 0;
	while (j++ < sort->cur_b_size)
	{
		move_stacks(stacks, PA);
	}
}

// 100: in 1084 steps
// 500: in 6784 steps
void	radix_sort(t_stacks *stacks)
{
	t_sort	sort;

	sort.max_num = get_max_num(stacks->a);
	sort.max_bits = get_max_bits(sort.max_num);
	sort.cur_bit = 0;
	while (sort.cur_bit < sort.max_bits)
	{
		sort_stacks(stacks, &sort);
		sort.cur_bit++;
	}
}
