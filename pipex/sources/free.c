/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 13:19:35 by fwu               #+#    #+#             */
/*   Updated: 2024/04/30 21:01:26 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

//arg.c
void	free_env_path(t_arg *arg)
{
	int	i;

	if (arg->env_path)
	{
		i = 0;
		while (arg->env_path[i])
		{
			free (arg->env_path[i]);
			arg->env_path[i] = NULL;
			i++;
		}
		free (arg->env_path);
		arg->env_path = NULL;
	}
}

//arg.c
void	free_t_arg(t_arg **arg)
{
	if (!*arg)
		return ;
	free_env_path(*arg);
	free(*arg);
	*arg = NULL;
}

//fd.c
void	free_t_fd(t_fd	**fd)
{
	if (!*fd)
		return ;
	if ((*fd)->pipe)
	{
		free((*fd)->pipe);
		(*fd)->pipe = NULL;
	}
	free(*fd);
	*fd = NULL;
}

//exe.c
static void	free_exe_argv(t_exe *exe)
{
	int	i;

	if (exe->argv)
	{
		i = 0;
		while (exe->argv[i])
		{
			free(exe->argv[i]);
			exe->argv[i] = NULL;
			i++;
		}
		free(exe->argv);
		exe->argv = NULL;
	}
}

//exe.c
void	free_t_exe(t_exe **exe)
{
	if (!*exe)
		return ;
	free_exe_argv(*exe);
	free (*exe);
	*exe = NULL;
}
