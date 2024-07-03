/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:17:19 by fwu               #+#    #+#             */
/*   Updated: 2024/05/05 17:25:25 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"

# define SUCCESS	0
# define FAIL	1

# define TRUE	1
# define FALSE   0

# define PROGRAM 1
# define INFILE 1
# define LIMITER 1
# define OUTFILE 1

# define INI_PIPE_IDX 0
# define WRITE_PIPE_IDX 1
# define READ_PIPE_IDX 0

//file description
# define INFILE_NOT_EXIST 0
# define FILE_OPEN_ERROR -1

//file status
# define FILE_OPEN_SUCCESS 0
# define FILE_OPEN_FAIL -1

typedef struct s_fd
{
	int	infile;
	int	outfile;
	int	infile_status;
	int	outfile_status;
	int	pipe_num;
	int	(*pipe)[2];
}	t_fd;

typedef struct s_exe
{
	int		infd;
	int		outfd;
	char	*name;	
	char	*path;
	char	**argv;
	char	**envp;	
}	t_exe;

typedef struct s_arg
{
	int		here_doc;
	int		cmd_num;
	int		pipe_num;
	int		argc;
	char	**argv;
	char	**envp;
	char	**env_path;
}	t_arg;

//arg.c
int		prepare_t_arg(t_arg **arg, int argc, char *argv[], char *envp[]);

//pipex.c
int		pipex(t_arg *arg);

//fd.c
int		prepare_t_fd(t_fd **fd, t_arg *arg);
void	close_fd(t_fd *fd);

//execute.c
int		fork_and_execute(t_fd *fd, t_arg *arg);

//exe.c
int		prepare_t_exe(int cur_cmd_idx, t_exe **exe, t_fd *fd, t_arg *arg);

//path.c
char	*get_exe_path(char **env_path, char *exe_name);

//free.c
void	free_env_path(t_arg *arg);
void	free_t_arg(t_arg **arg);
void	free_t_fd(t_fd	**fd);
void	free_t_exe(t_exe **exe);

#endif //PIPEX_H