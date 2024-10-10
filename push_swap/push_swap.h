/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:27:20 by fwu               #+#    #+#             */
/*   Updated: 2024/10/07 15:15:26 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include "Libft/libft.h"

# define INS_LEN 3
# define SA "sa"
# define SB "sb"
# define SS "ss"
# define PA "pa"
# define PB "pb"
# define RA "ra"
# define RB "rb"
# define RR "rr"
# define RRA "rra"
# define RRB "rrb"
# define RRR "rrr"

typedef struct s_input
{
	int		argc;
	char	**argv;
	char	**new_argv;
	int		*sequence_in;
	int		*sequence_out;
	int		*sequence_sorted;
	int		nums;
}	t_input;

typedef struct s_stacks
{
	t_ilist	*a;
	t_ilist	*b;
	int		nums;
	int		steps;
}	t_stacks;

typedef struct s_sort
{
	int	fst_num;
	int	sec_num;
	int	trd_num;
	int	max_num;
	int	cur_num;
	int	cur_a_num;
	int	cur_a_size;
	int	cur_b_size;
	int	max_bits;
	int	cur_bit;
}	t_sort;

// check_input.c
void	initial_input(int argc, char **argv, t_input *input);
void	delete_input(t_input *input);
bool	check_duplicate(int *sequence, int len);
bool	check_args(t_input *input);
bool	check_sorted(t_input *input);

// convert_input.c
bool	convert_input(t_input *input);

// stack.c
void	initial_stacks(t_stacks *stacks);
bool	create_stacks(t_input input, t_stacks *stacks);
void	delete_content(int content);
void	delete_stacks(t_stacks *stacks);
void	print_stacks(t_stacks stacks);

// instruction.c
void	move_stacks(t_stacks *stacks, char *instruction);

// small_sort.c
void	two_sort(t_stacks *stacks);
void	three_sort(t_stacks *stacks);
void	small_sort(t_stacks *stacks);

// radix_sort.c
void	radix_sort(t_stacks	*stacks);

#endif //PUSH_SWAP_H