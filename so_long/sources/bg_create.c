/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bg_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 21:52:02 by fwu               #+#    #+#             */
/*   Updated: 2024/10/28 13:11:53 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

bool	mlx_create(t_scene *scene)
{
	scene->mlx = mlx_init(scene->width, scene->height, SO_LONG, MLX_RESIZE);
	if (!scene->mlx)
	{
		perror(mlx_strerror(mlx_errno));
		return (false);
	}
	return (true);
}

void	set_png(t_png *png, int map_y, int map_x, char *path)
{
	png->y = map_y * CELL_HEIGHT;
	png->x = map_x * CELL_WIDTH;
	png->path = path;
}

bool	png_to_image(mlx_t *mlx, mlx_image_t **img, t_png png, bool visible)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(png.path);
	if (!texture)
	{
		perror(mlx_strerror(mlx_errno));
		return (false);
	}
	*img = mlx_texture_to_image(mlx, texture);
	mlx_delete_texture(texture);
	if (!*img || mlx_image_to_window(mlx, *img, png.x, png.y) < 0)
	{
		perror(mlx_strerror(mlx_errno));
		return (false);
	}
	if (!visible)
		(*img)->instances[0].enabled = false;
	return (true);
}

bool	bg_create(t_scene *scene, int num_img)
{
	int		x;
	int		y;
	t_png	png;
	int		i;

	scene->bg.img = (mlx_image_t **)ft_calloc(num_img, sizeof(mlx_image_t *));
	if (!scene->bg.img)
		return (false);
	i = 0;
	y = 0;
	while (y < scene->map.height + COUNTER_Y)
	{
		x = 0;
		while (x < scene->map.width)
		{
			set_png(&png, y, x, PATH_BG);
			if (!png_to_image(scene->mlx, &scene->bg.img[i++], png, true))
				return (false);
			x++;
		}
		y++;
	}
	return (true);
}
