/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 22:09:47 by fwu               #+#    #+#             */
/*   Updated: 2024/10/15 18:33:36 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_error(char *error_msg)
{
	ft_putstr_fd("Error\n", STDOUT_FILENO);
	ft_putstr_fd(error_msg, STDOUT_FILENO);
	ft_putstr_fd("\n", STDOUT_FILENO);
}
