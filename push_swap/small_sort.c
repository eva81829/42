/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:33:06 by fwu               #+#    #+#             */
/*   Updated: 2024/10/02 18:55:38 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 2: in 1 steps
// 1 0   => SA
// 0 1   => X
void	two_sort(t_stacks *stacks)
{
	t_sort	sort;

	sort.cur_a_size = ft_ilstsize(stacks->a);
	if (sort.cur_a_size == 2)
	{
		sort.fst_num = stacks->a->content;
		sort.sec_num = stacks->a->next->content;
		if (sort.fst_num > sort.sec_num)
			move_stacks(stacks, SA);
	}
}

// 3: in 2 steps
// 2 0 1 => RA
// 2 1 0 => RA SA
// 1 2 0 => RRA
// 0 2 1 => RRA SA
// 1 0 2 => SA
// 0 1 2 => X
void	three_sort(t_stacks *stacks)
{
	t_sort	sort;

	sort.cur_a_size = ft_ilstsize(stacks->a);
	if (sort.cur_a_size == 3)
	{
		sort.fst_num = stacks->a->content;
		sort.sec_num = stacks->a->next->content;
		sort.trd_num = stacks->a->next->next->content;
		if ((sort.fst_num > sort.trd_num && sort.trd_num > sort.sec_num)
			|| (sort.fst_num > sort.sec_num && sort.sec_num > sort.trd_num))
			move_stacks(stacks, RA);
		if ((sort.sec_num > sort.fst_num && sort.fst_num > sort.trd_num)
			|| (sort.sec_num > sort.trd_num && sort.trd_num > sort.fst_num))
			move_stacks(stacks, RRA);
		if ((sort.fst_num > sort.sec_num && sort.sec_num > sort.trd_num)
			|| (sort.sec_num > sort.trd_num && sort.trd_num > sort.fst_num)
			|| (sort.trd_num > sort.fst_num && sort.fst_num > sort.sec_num))
			move_stacks(stacks, SA);
	}
}

static bool	is_in_stack(t_ilist *stack, int content)
{
	t_ilist	*tmp_node;

	tmp_node = stack;
	while (tmp_node)
	{
		if (content == tmp_node->content)
		{
			return (true);
		}
		tmp_node = tmp_node->next;
	}
	return (false);
}

// 4: in 4 steps
// 5: in 5 steps
// numbers in the stack must be sequence,
// min start from 0 and max end in (stacks->nums - 1): 0 1 2 3 4
// stack a & stack b must be sorted before insert
// stack a(ascending) : 0 1 3
// stack b(descending):   4 2
static void	insert_stacks(t_stacks *stacks)
{
	int	cur_num;

	cur_num = stacks->nums - 1;
	while (cur_num >= 0)
	{
		if (is_in_stack(stacks->b, cur_num))
			move_stacks(stacks, PA);
		else
			move_stacks(stacks, RRA);
		cur_num--;
	}
}

// 4: in 7 steps
// 5: in 10 steps
// 5: make first 2 numbers in stack a ascending,
// then push twice into stack b to make them descending
void	small_sort(t_stacks *stacks)
{
	t_sort	sort;

	sort.cur_a_size = ft_ilstsize(stacks->a);
	if (sort.cur_a_size == 4)
	{
		move_stacks(stacks, PB);
		three_sort(stacks);
		insert_stacks(stacks);
	}
	else if (sort.cur_a_size == 5)
	{
		sort.fst_num = stacks->a->content;
		sort.sec_num = stacks->a->next->content;
		if (sort.fst_num > sort.sec_num)
			move_stacks(stacks, SA);
		move_stacks(stacks, PB);
		move_stacks(stacks, PB);
		three_sort(stacks);
		insert_stacks(stacks);
	}
}
