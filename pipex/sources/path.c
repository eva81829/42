/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:44:34 by fwu               #+#    #+#             */
/*   Updated: 2024/04/30 20:14:34 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	*combine_path_name(char *path, char *name)
{
	char	*tmp_path;
	char	*exe_path;

	tmp_path = ft_strjoin(path, "/");
	exe_path = ft_strjoin(tmp_path, name);
	free(tmp_path);
	return (exe_path);
}

// access(exe_path, X_OK): check if exe_path can be executed
char	*get_exe_path(char **env_path, char *exe_name)
{
	char	*exe_path;
	int		i;

	exe_path = NULL;
	i = 0;
	while (env_path && env_path[i] != NULL)
	{
		exe_path = combine_path_name(env_path[i], exe_name);
		if (access(exe_path, X_OK) == 0)
		{
			return (exe_path);
		}
		else
		{
			free(exe_path);
		}
		i++;
	}
	return (exe_path);
}
