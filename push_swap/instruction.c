/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:10:36 by fwu               #+#    #+#             */
/*   Updated: 2024/10/02 18:41:36 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// swap first and second node
static void	swap(t_ilist **stack)
{
	t_ilist	*fst_node;
	t_ilist	*sec_node;

	fst_node = *stack;
	if (!fst_node)
		return ;
	sec_node = fst_node->next;
	if (!sec_node)
		return ;
	fst_node->next = sec_node->next;
	sec_node->next = fst_node;
	*stack = sec_node;
}

static void	push(t_ilist **stack_dst, t_ilist **stack_src)
{
	t_ilist	*src_node;
	t_ilist	*sec_node;

	src_node = *stack_src;
	if (!src_node)
		return ;
	sec_node = src_node->next;
	ft_ilstadd_front(stack_dst, src_node);
	*stack_src = sec_node;
}

// shift up all elements of stack by 1, first node becomes the last one
static void	rotate_up(t_ilist **stack)
{
	t_ilist	*fst_node;
	t_ilist	*sec_node;
	t_ilist	*last_node;

	fst_node = *stack;
	if (!fst_node)
		return ;
	sec_node = fst_node->next;
	if (!sec_node)
		return ;
	last_node = ft_ilstlast(*stack);
	last_node->next = fst_node;
	fst_node->next = NULL;
	*stack = sec_node;
}

// shift down all elements of stack by 1, last node becomes the first one
static void	rotate_down(t_ilist **stack)
{
	t_ilist	*fst_node;
	t_ilist	*sec_node;
	t_ilist	*new_node;
	int		lst_content;

	fst_node = *stack;
	if (!fst_node)
		return ;
	sec_node = fst_node->next;
	if (!sec_node)
		return ;
	lst_content = ft_ilstlast(*stack)->content;
	ft_ilstrm_last(stack, delete_content);
	new_node = ft_ilstnew(lst_content);
	ft_ilstadd_front(stack, new_node);
}

void	move_stacks(t_stacks	*stacks, char *instruction)
{
	ft_putstr_fd(instruction, STDOUT_FILENO);
	ft_putstr_fd("\n", STDOUT_FILENO);
	if (ft_strncmp(instruction, SA, INS_LEN) == 0)
		swap(&stacks->a);
	if (ft_strncmp(instruction, SB, INS_LEN) == 0)
		swap(&stacks->b);
	if (ft_strncmp(instruction, PA, INS_LEN) == 0)
		push(&stacks->a, &stacks->b);
	if (ft_strncmp(instruction, PB, INS_LEN) == 0)
		push(&stacks->b, &stacks->a);
	if (ft_strncmp(instruction, RA, INS_LEN) == 0
		|| ft_strncmp(instruction, RR, INS_LEN) == 0)
		rotate_up(&stacks->a);
	if (ft_strncmp(instruction, RB, INS_LEN) == 0
		|| ft_strncmp(instruction, RR, INS_LEN) == 0)
		rotate_up(&stacks->b);
	if (ft_strncmp(instruction, RRA, INS_LEN) == 0
		|| ft_strncmp(instruction, RRR, INS_LEN) == 0)
		rotate_down(&stacks->a);
	if (ft_strncmp(instruction, RRB, INS_LEN) == 0
		|| ft_strncmp(instruction, RRR, INS_LEN) == 0)
		rotate_down(&stacks->b);
	stacks->steps++;
}
