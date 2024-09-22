/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rush.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artopall <artopall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 07:03:51 by artopall          #+#    #+#             */
/*   Updated: 2024/01/21 19:03:54 by artopall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RUSH_H
# define FT_RUSH_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_puzz
{
	int	**grid;
	int	size;
}	t_puzz;

//ft_utils
int		ft_sqrt(int nb);
int		ft_isspace(char c);
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_isdigit(char c);

//ft_puzzle_creation
t_puzz	*ft_create_grid(t_puzz *puzzle, char *str);
void	ft_fill_top_bottom(t_puzz *puzzle, char *str);
void	ft_fill_left_right(t_puzz *puzzle, char *str);

//ft_puzzle_check
int		ft_check_param(char *param);
t_puzz	*ft_checkparams(int ac, char **av);

//ft_puzzle_start
void	ft_puzz_start(t_puzz *p);

void	ft_print_grid(t_puzz *game);
void	ft_printf(int state, t_puzz *puzz);

//ft_algorithm
int		ft_ishiding(t_puzz *p, int x, int y, int num);
int		ft_isdouble(t_puzz *p, int x, int y, int num);

//ft_free
void	ft_free_all(t_puzz *game);

#endif
