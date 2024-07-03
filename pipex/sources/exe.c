/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:06:19 by fwu               #+#    #+#             */
/*   Updated: 2024/05/05 17:27:05 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static int	create_t_exe(t_exe **exe)
{
	*exe = (t_exe *)ft_calloc(1, sizeof(t_exe));
	if (!*exe)
		return (FAIL);
	return (SUCCESS);
}

// execute first cmd
// execute last cmd
// execute mid cmd
static void	get_exe_fd(int cur_cmd_idx, t_exe *exe, t_fd *fd, t_arg *arg)
{
	if (cur_cmd_idx == 0)
	{
		if (arg->here_doc)
			exe->infd = fd->pipe[INI_PIPE_IDX][READ_PIPE_IDX];
		else
			exe->infd = fd->infile;
		exe->outfd = fd->pipe[INI_PIPE_IDX + arg->here_doc][WRITE_PIPE_IDX];
	}
	else if (cur_cmd_idx == arg->cmd_num - 1)
	{
		exe->infd = fd->pipe[cur_cmd_idx + arg->here_doc - 1][READ_PIPE_IDX];
		exe->outfd = fd->outfile;
	}
	else
	{
		exe->infd = fd->pipe[cur_cmd_idx + arg->here_doc - 1][READ_PIPE_IDX];
		exe->outfd = fd->pipe[cur_cmd_idx + arg->here_doc][WRITE_PIPE_IDX];
	}
}

static char	**get_exe_argv(char *arg)
{
	return (ft_split(arg, ' '));
}

static int	get_exe_arg(int cur_cmd_idx, t_exe *exe, t_arg *arg)
{
	int		arg_cmd_idx;
	char	*cmd;

	if (arg->here_doc)
		arg_cmd_idx = PROGRAM + arg->here_doc + LIMITER + cur_cmd_idx;
	else
		arg_cmd_idx = PROGRAM + arg->here_doc + INFILE + cur_cmd_idx;
	cmd = arg->argv[arg_cmd_idx];
	exe->argv = get_exe_argv(cmd);
	if (!exe->argv)
		return (FAIL);
	exe->name = exe->argv[0];
	exe->path = get_exe_path(arg->env_path, exe->name);
	if (!exe->path)
		return (FAIL);
	exe->envp = arg->envp;
	return (SUCCESS);
}

int	prepare_t_exe(int cur_cmd_idx, t_exe **exe, t_fd *fd, t_arg *arg)
{
	if (create_t_exe(exe) == FAIL)
		return (FAIL);
	if (get_exe_arg(cur_cmd_idx, *exe, arg) == FAIL)
		return (FAIL);
	get_exe_fd(cur_cmd_idx, *exe, fd, arg);
	return (SUCCESS);
}
