/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 15:53:25 by fwu               #+#    #+#             */
/*   Updated: 2024/05/01 21:49:19 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static int	pipe_fd(t_fd *fd)
{
	int	i;

	i = 0;
	while (i < fd->pipe_num)
	{
		if (pipe(fd->pipe[i]) == -1)
			return (FAIL);
		i++;
	}
	return (SUCCESS);
}

static int	check_diff(char	*limiter, char *newline)
{
	int	len_limiter;
	int	len_newline;
	int	len_cmp;

	len_limiter = ft_strlen(limiter);
	len_newline = ft_strlen(newline) - 1;
	if (len_limiter > len_newline)
		len_cmp = len_limiter;
	else
		len_cmp = len_newline;
	if (ft_strncmp(limiter, newline, len_cmp) != 0)
		return (FAIL);
	return (SUCCESS);
}

static void	get_input_from_here_doc(t_fd *fd, t_arg *arg)
{
	char	*limiter;
	char	*newline;

	if (arg->here_doc)
	{
		limiter = arg->argv[0 + PROGRAM + arg->here_doc];
		ft_putstr_fd("> ", STDOUT_FILENO);
		newline = get_next_line(STDIN_FILENO);
		while (newline != NULL && check_diff(limiter, newline) == FAIL)
		{
			ft_putstr_fd(newline, fd->pipe[INI_PIPE_IDX][WRITE_PIPE_IDX]);
			if (newline != NULL)
				free(newline);
			ft_putstr_fd("> ", STDOUT_FILENO);
			newline = get_next_line(STDIN_FILENO);
		}
		if (newline != NULL)
			free(newline);
	}
}

int	pipex(t_arg *arg)
{
	t_fd	*fd;

	if (prepare_t_fd(&fd, arg) == FAIL)
	{
		free_t_fd(&fd);
		return (FAIL);
	}
	if (pipe_fd(fd) == FAIL)
	{
		free_t_fd(&fd);
		return (FAIL);
	}
	get_input_from_here_doc(fd, arg);
	if (fork_and_execute(fd, arg) == FAIL)
	{
		free_t_fd(&fd);
		return (FAIL);
	}
	free_t_fd(&fd);
	return (SUCCESS);
}
