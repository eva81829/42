/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:11:37 by fwu               #+#    #+#             */
/*   Updated: 2024/04/30 22:55:42 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_arg	*arg;

	if (prepare_t_arg(&arg, argc, argv, envp) == FAIL)
	{
		free_t_arg(&arg);
		return (FAIL);
	}
	if (pipex(arg) == FAIL)
	{
		free_t_arg(&arg);
		return (FAIL);
	}
	free_t_arg(&arg);
	return (SUCCESS);
}
