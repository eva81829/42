/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpothier <vpothier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 20:40:44 by fwu               #+#    #+#             */
/*   Updated: 2024/01/28 23:20:04 by vpothier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

char	*read_dict(char *path)
{
	char	buffer[READ_LENGTH];
	ssize_t	bytes_read;/*how many bytes from each read*/
	ssize_t	i;
	ssize_t	j;
	int		fd;	
	/* char	current_char*/
	char	*dict_content;
	char	*dict_content_new;
	ssize_t	total_leng;

	/*chars of each read, each read READ_LENGTH bytes*/
	dict_content = 0;
	dict_content_new = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Dict Error\n");
		return (dict_content);
	}
	dict_content = 0;
	total_leng = 0;
	bytes_read = read(fd, buffer, sizeof(buffer));
	while (bytes_read > 0)
	{
		i = 0;
		while (i < bytes_read)
		{
			if (total_leng++ == 0)
			{
				dict_content = malloc(sizeof(char) * (total_leng + 1));
				dict_content[0] = buffer[i];
			}
			else
			{
				dict_content_new = malloc(sizeof(char) * (total_leng + 1));
				j = 0;
				while (j < total_leng - 1)
				{
					dict_content_new[j] = dict_content[j];
					j++;
				}
				dict_content_new[j] = buffer[i];
				free(dict_content);
				dict_content = dict_content_new;
			}
			dict_content[total_leng] = '\0';
			i++;
		}
		bytes_read = read(fd, buffer, sizeof(buffer));
	}
	close(fd);
	return (dict_content);
}
