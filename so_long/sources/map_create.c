/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:46:34 by fwu               #+#    #+#             */
/*   Updated: 2024/12/09 18:14:45 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static bool	map_convert(t_map	*map, char *str_map)
{
	int	i;

	map->data = ft_split(str_map, '\n');
	i = 0;
	while (map->data && map->data[i])
	{
		if (i == 0)
			map->width = ft_strlen(map->data[0]);
		i++;
	}
	map->height = i;
	if (map->height == 0 || map->width == 0)
	{
		print_error(MSG_EMPTY_MAP_ERR);
		return (false);
	}
	return (true);
}

static bool	check_empty_line(char *str_map, char *newline)
{
	if (newline)
	{
		if (ft_strncmp(newline, "\n", ft_strlen(newline)) != 0)
			return (true);
	}
	else
	{
		while (str_map && *str_map != '\0' && *(str_map + 1) != '\0')
			str_map++;
		if (str_map && *str_map != '\n')
			return (true);
	}
	print_error(MSG_EMPTY_LINE_ERR);
	return (false);
}

static bool	merge_lines(t_map	*map, char *newline)
{
	static char	*str_map = NULL;
	char		*tmp_map;

	if (!check_empty_line(str_map, newline))
		return (false);
	if (!newline)
		return (map_convert(map, str_map));
	if (!str_map)
		str_map = ft_strdup(newline);
	else
	{
		tmp_map = str_map;
		str_map = ft_strjoin(tmp_map, newline);
		free(tmp_map);
	}
	return (true);
}

static bool	map_read(t_map	*map, int fd)
{
	char	*newline;
	bool	rst;

	newline = NULL;
	rst = true;
	while (rst)
	{
		newline = get_next_line(fd);
		rst = merge_lines(map, newline);
		if (newline)
			free(newline);
		else
			break ;
	}
	return (rst);
}

bool	map_create(t_map *map, char *map_name)
{
	int		fd;

	map_initialize(map);
	if (ft_strncmp(ft_strchr(map_name, '.'), ".ber", 4) != 0)
		return (false);
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
	{
		print_error(MSG_READ_FILE_ERR);
		return (false);
	}
	if (!map_read(map, fd))
		return (false);
	if (!map_check(map))
		return (false);
	if (close(fd) == -1)
	{
		print_error(MSG_CLOSE_FILE_ERR);
		return (false);
	}
	return (true);
}
