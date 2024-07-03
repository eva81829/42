/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwu <fwu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:44:16 by fwu               #+#    #+#             */
/*   Updated: 2024/05/22 15:51:26 by fwu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define WIDTH 512
#define HEIGHT 512

static mlx_image_t* img_bg;
static mlx_image_t* img_fish[2][2];
static mlx_image_t* img_barrel;
static mlx_image_t* img_grass;
// static mlx_image_t* img_bait;
static mlx_image_t* img_chest;

static int direction = 0;
static int color = 0;

static int key_up_press = 0;
static int key_down_press = 0;
static int key_left_press = 0;
static int key_right_press = 0;

static void error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void ft_move(void* param)
{
	mlx_t* mlx = param;
	int x;
	int y;
	
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP) && key_up_press == 0)
	{
		img_fish[direction][color]->instances[0].y -= 30;
		key_up_press = 1;
	} else if (!mlx_is_key_down(mlx, MLX_KEY_UP) && key_up_press == 1)
	{
		key_up_press = 0;
	}
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN) && key_down_press == 0)
	{
		img_fish[direction][color]->instances[0].y += 30;
		key_down_press = 1;
	} else if (!mlx_is_key_down(mlx, MLX_KEY_DOWN) && key_down_press == 1)
	{
		key_down_press = 0;
	}	
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT) && key_left_press == 0)
	{
		img_fish[direction][color]->instances[0].x -= 30;
		x = img_fish[direction][color]->instances[0].x;
		y = img_fish[direction][color]->instances[0].y;
		img_fish[direction][color]->instances[0].enabled = false;
		direction = 1;
		img_fish[direction][color]->instances[0].x = x;
		img_fish[direction][color]->instances[0].y = y;			
		img_fish[direction][color]->instances[0].enabled = true;
		key_left_press = 1;
	} else if (!mlx_is_key_down(mlx,  MLX_KEY_LEFT) && key_left_press == 1)
	{
		key_left_press = 0;
	}	
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT) && key_right_press == 0)
	{
		img_fish[direction][color]->instances[0].x += 30;
		x = img_fish[direction][color]->instances[0].x;
		y = img_fish[direction][color]->instances[0].y;
		img_fish[direction][color]->instances[0].enabled = false;
		direction = 0;
		img_fish[direction][color]->instances[0].x = x;
		img_fish[direction][color]->instances[0].y = y;			
		img_fish[direction][color]->instances[0].enabled = true;
		key_right_press = 1;
	} else if (!mlx_is_key_down(mlx,  MLX_KEY_RIGHT) && key_right_press == 1)
	{
		key_right_press = 0;
	}	
}

void ft_eat_grass()
{
	if ((img_fish[direction][color]->instances[0].y - img_grass->instances[0].y <= 20 && img_fish[direction][color]->instances[0].y - img_grass->instances[0].y >= -20)
	&& (img_fish[direction][color]->instances[0].x - img_grass->instances[0].x <= 20 && img_fish[direction][color]->instances[0].x - img_grass->instances[0].x >= -20))
		{
			img_grass->instances[0].enabled = false;
			img_fish[direction][color]->instances[0].enabled = false;
			int x = img_fish[direction][color]->instances[0].x;
			int y = img_fish[direction][color]->instances[0].y;
			color = 1;
			img_fish[direction][color]->instances[0].x = x;
			img_fish[direction][color]->instances[0].y = y;			
			img_fish[direction][color]->instances[0].enabled = true;
		}
}

void ft_meet_barrel(void* param)
{
	mlx_t* mlx = param;
		
	if ((img_fish[direction][color]->instances[0].y - img_barrel->instances[0].y <= 20 && img_fish[direction][color]->instances[0].y - img_barrel->instances[0].y >= -20)
	&& (img_fish[direction][color]->instances[0].x - img_barrel->instances[0].x <= 20 && img_fish[direction][color]->instances[0].x - img_barrel->instances[0].x >= -20))
	{
		if (mlx_is_key_down(mlx, MLX_KEY_UP))
			img_fish[direction][color]->instances[0].y += 30;
		if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
			img_fish[direction][color]->instances[0].y -= 30;
		if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
			img_fish[direction][color]->instances[0].x += 30;
		if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
			img_fish[direction][color]->instances[0].x -= 30;
	}
}

void ft_meet_wall()
{
	if (img_fish[direction][color]->instances[0].y < 0)
		img_fish[direction][color]->instances[0].y += 30;
	else if (img_fish[direction][color]->instances[0].x < 0)
		img_fish[direction][color]->instances[0].x += 30;
	if (img_fish[direction][color]->instances[0].y + 30 > HEIGHT)
		img_fish[direction][color]->instances[0].y -= 30;
	else if (img_fish[direction][color]->instances[0].x + 30 > WIDTH)
		img_fish[direction][color]->instances[0].x -= 30;
}

void ft_meet_chest(void* param)
{
	mlx_t* mlx = param;
		
	if ((img_fish[direction][color]->instances[0].y - img_chest->instances[0].y <= 20 && img_fish[direction][color]->instances[0].y - img_chest->instances[0].y >= -20)
	&& (img_fish[direction][color]->instances[0].x - img_chest->instances[0].x <= 20 && img_fish[direction][color]->instances[0].x - img_chest->instances[0].x >= -20))
		mlx_close_window(mlx);
}


int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

int32_t	main(void)
{
	// Start mlx
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "Test", true);
	if (!mlx)
        error();

	// Creates a whole new image
	if (!(img_bg = mlx_new_image(mlx, WIDTH, HEIGHT)))
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	// Put image on the window
	if (mlx_image_to_window(mlx, img_bg, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	for (uint32_t x = 0; x < img_bg->width; ++x)
	{
		for (uint32_t y = 0; y < img_bg->height; ++y)
		{
			uint32_t color = ft_pixel(
				0x00, // R
				0x00, // G
				0xFF, // B
				0xFF  // A
			);
			mlx_put_pixel(img_bg, x, y, color);
		}
	}

	// Try to load the file
	mlx_texture_t* texture1 = mlx_load_png("./image/fish_gold_right.png");
	if (!texture1)
        error();
	// Convert texture to a displayable image
	img_fish[0][0] = mlx_texture_to_image(mlx, texture1);
	if (!img_fish[0][0])
        error();
	// Display the image
	if (mlx_image_to_window(mlx, img_fish[0][0], 0, 0) < 0)
        error();
	
	// Try to load the file
	mlx_texture_t* texture5 = mlx_load_png("./image/fish_gold_left.png");
	if (!texture5)
        error();
	// Convert texture to a displayable image
	img_fish[1][0] = mlx_texture_to_image(mlx, texture5);
	if (!img_fish[1][0])
        error();
	// Display the image
	if (mlx_image_to_window(mlx, img_fish[1][0], 0, 0) < 0)
        error();		
	img_fish[1][0]->instances[0].enabled = false;

	// Try to load the file
	mlx_texture_t* texture6 = mlx_load_png("./image/fish_red_right.png");
	if (!texture6)
        error();
	// Convert texture to a displayable image
	img_fish[0][1] = mlx_texture_to_image(mlx, texture6);
	if (!img_fish[0][1])
        error();
	// Display the image
	if (mlx_image_to_window(mlx, img_fish[0][1], 0, 0) < 0)
        error();		
	img_fish[0][1]->instances[0].enabled = false;		

	// Try to load the file
	mlx_texture_t* texture7 = mlx_load_png("./image/fish_red_left.png");
	if (!texture7)
        error();
	// Convert texture to a displayable image
	img_fish[1][1] = mlx_texture_to_image(mlx, texture7);
	if (!img_fish[1][1])
        error();
	// Display the image
	if (mlx_image_to_window(mlx, img_fish[1][1], 0, 0) < 0)
        error();		
	img_fish[1][1]->instances[0].enabled = false;			

	// Try to load the file
	mlx_texture_t*texture2 = mlx_load_png("./image/barrel.png");
	if (!texture2)
        error();
	// Convert texture to a displayable image
	img_barrel = mlx_texture_to_image(mlx, texture2);
	if (!img_barrel)
        error();
	// Display the image
	if (mlx_image_to_window(mlx, img_barrel, 128, 128) < 0)
        error();

	// Try to load the file
	mlx_texture_t*texture3 = mlx_load_png("./image/grass.png");
	if (!texture2)
        error();
	// Convert texture to a displayable image
	img_grass = mlx_texture_to_image(mlx, texture3);
	if (!img_grass)
        error();
	// Display the image
	if (mlx_image_to_window(mlx, img_grass, 200, 200) < 0)
        error();

	// Try to load the file
	mlx_texture_t*texture4 = mlx_load_png("./image/treasure.png");
	if (!texture4)
        error();
	// Convert texture to a displayable image
	img_chest = mlx_texture_to_image(mlx, texture4);
	mlx_resize_image(img_chest, 30, 20);
	if (!img_chest)
        error();
	
	// Display the image
	if (mlx_image_to_window(mlx, img_chest, 300, 300) < 0)
        error();

	mlx_loop_hook(mlx, ft_move, mlx);
	mlx_loop_hook(mlx, ft_eat_grass, mlx);
	mlx_loop_hook(mlx, ft_meet_barrel, mlx);
	mlx_loop_hook(mlx, ft_meet_chest, mlx);
	mlx_loop_hook(mlx, ft_meet_wall, mlx);
	mlx_loop(mlx);

	mlx_delete_image(mlx, img_fish[0][0]);
	mlx_delete_texture(texture1);
	mlx_delete_image(mlx, img_fish[1][0]);
	mlx_delete_texture(texture5);
	mlx_delete_image(mlx, img_fish[0][1]);
	mlx_delete_texture(texture6);
	mlx_delete_image(mlx, img_fish[1][1]);
	mlx_delete_texture(texture7);
	mlx_delete_image(mlx, img_barrel);
	mlx_delete_texture(texture2);
	mlx_delete_image(mlx, img_grass);
	mlx_delete_texture(texture3);
	mlx_delete_image(mlx, img_chest);
	mlx_delete_texture(texture4);	

        // Optional, terminate will clean up any leftover images (not textures!)
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}

// int main(void)
// {
// 	return (0); 
// }