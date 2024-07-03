/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 18:45:51 by fwu               #+#    #+#             */
/*   Updated: 2024/05/05 17:24:51 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static int	execute_exe(t_exe *exe, t_fd *fd)
{
	if (dup2(exe->infd, STDIN_FILENO) == -1)
		return (FAIL);
	if (dup2(exe->outfd, STDOUT_FILENO) == -1)
		return (FAIL);
	close_fd(fd);
	if (execve(exe->path, exe->argv, exe->envp) == -1)
	{
		ft_putstr_fd("pipex: ", STDERR_FILENO);
		ft_putstr_fd(exe->name, STDERR_FILENO);
		ft_putendl_fd(": command not found", STDERR_FILENO);
		return (FAIL);
	}
	return (SUCCESS);
}

static int	check_execute(int cur_cmd_idx, int cmd_num, t_fd *fd)
{
	if (cur_cmd_idx == 0 && fd->infile_status)
		return (FAIL);
	else if (cur_cmd_idx == cmd_num - 1 && fd->outfile_status)
		return (FAIL);
	return (SUCCESS);
}

static int	execute_cmd(int cur_cmd_idx, t_fd *fd, t_arg *arg)
{
	t_exe	*exe;

	if (prepare_t_exe(cur_cmd_idx, &exe, fd, arg) == FAIL)
	{
		free_t_exe(&exe);
		return (FAIL);
	}
	if (execute_exe(exe, fd) == FAIL)
	{
		free_t_exe(&exe);
		return (FAIL);
	}
	free_t_exe(&exe);
	return (SUCCESS);
}

int	fork_and_execute(t_fd *fd, t_arg *arg)
{
	int	id;	
	int	i;
	int	status;

	i = 0;
	while (i < arg->cmd_num)
	{
		id = fork();
		if (id == -1)
			return (FAIL);
		if (id == 0)
		{
			if (check_execute(i, arg->cmd_num, fd) == FAIL)
				return (FAIL);
			if (execute_cmd(i, fd, arg) == FAIL)
				return (FAIL);
		}
		waitpid(id, &status, WNOHANG);
		i++;
	}
	close_fd(fd);
	return (SUCCESS);
}
