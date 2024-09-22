/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpothier <vpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 20:34:45 by fwu               #+#    #+#             */
/*   Updated: 2024/01/28 23:07:12 by vpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define TRUE  1
#define FALSE 0

//main.c

//check_arg.c
#define DEFAULT_PATH "numbers.dict"

typedef struct s_arg
{
	int		status;	
	char	*path;
	char	*value;
}	t_arg;
void	check_arg(t_arg *arg, int argc, char **argv);

//convert_dict
char	*get_number_0_to_19(int number);
char	*get_number_10_to_100(int number);
char	*get_number_more_than_1000(int number);

//utils.c
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
int		ft_strlen(char *str);
int		ft_atoi_hundred(char *str);

//read_dict.c
#define READ_LENGTH 100

char	*read_dict(char *path);

//number_convert.c
void	number_convert(char *value);