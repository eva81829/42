/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:10:25 by fwu               #+#    #+#             */
/*   Updated: 2024/04/05 22:28:55 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

#define MIN_INPUT_ARG 4
#define STR_PATH_LEN 4
#define HERE_DOC_LEN 8

static int	check_args(int argc, char *argv[])
{
	if (argc - 1 < MIN_INPUT_ARG)
	{
		ft_putstr_fd("pipex: needs four arguments or more", STDERR_FILENO);
		return (FAIL);
	}
	if (ft_strncmp(argv[0 + PROGRAM], "here_doc", HERE_DOC_LEN) == 0)
	{
		if (argc - 1 < MIN_INPUT_ARG + 1)
		{
			ft_putstr_fd("pipex: needs five arguments or more", STDERR_FILENO);
			return (FAIL);
		}
	}
	return (SUCCESS);
}

static char	**get_env_path(char *sys_envp[])
{
	char	*total_path;
	char	**env_path;
	int		i;

	i = 0;
	env_path = NULL;
	while (sys_envp[i] != NULL)
	{
		if (ft_strncmp(sys_envp[i], "PATH", STR_PATH_LEN) == 0)
		{
			total_path = ft_strtrim(sys_envp[i], "PATH=");
			env_path = ft_split(total_path, ':');
			free(total_path);
			total_path = NULL;
			return (env_path);
		}
		i++;
	}
	return (env_path);
}

// add here_doc and relevant arg to arg
static void	get_arg_by_here_doc(t_arg	*arg)
{
	if (ft_strncmp(arg->argv[0 + PROGRAM], "here_doc", HERE_DOC_LEN) == 0)
		arg->here_doc = TRUE;
	else
		arg->here_doc = FALSE;
	if (arg->here_doc)
	{
		arg->cmd_num = arg->argc - PROGRAM - arg->here_doc - LIMITER - OUTFILE;
		arg->pipe_num = arg->cmd_num;
	}
	else
	{
		arg->cmd_num = arg->argc - PROGRAM - arg->here_doc - INFILE - OUTFILE;
		arg->pipe_num = arg->cmd_num - 1;
	}
}

// check_args
// add argc to arg
// add argv to arg
// add env_path to arg
static int	create_t_arg(t_arg	**arg, int argc, char *argv[], char *envp[])
{
	*arg = (t_arg *)ft_calloc(1, sizeof(t_arg));
	if (!*arg)
		return (FAIL);
	if (check_args(argc, argv) == FAIL)
		return (FAIL);
	(*arg)->argc = argc;
	(*arg)->argv = argv;
	(*arg)->envp = envp;
	(*arg)->env_path = get_env_path(envp);
	if (!(*arg)->env_path)
		return (FAIL);
	return (SUCCESS);
}

int	prepare_t_arg(t_arg	**arg, int argc, char *argv[], char *envp[])
{
	if (create_t_arg(arg, argc, argv, envp) == FAIL)
		return (FAIL);
	get_arg_by_here_doc(*arg);
	return (SUCCESS);
}
