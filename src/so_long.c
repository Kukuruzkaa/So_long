/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 15:31:18 by ddiakova          #+#    #+#             */
/*   Updated: 2021/10/24 20:59:52 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_coordinates(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map_tab[y])
	{
		x = 0;
		while (data->map_tab[y][x])
		{
			if (data->map_tab[y][x] == 'P')
			{
				data->pos_player.x = x;
				data->pos_player.y = y;
			}
			x++;
		}
		y++;
	}
}

void	load_textures(t_data *data, int count)
{
	file_to_image(data, &(data->tex_dplayer), D_PLAYER);
	if (data->flag == 1)
		count++;
	file_to_image(data, &(data->tex_uplayer), U_PLAYER);
	if (data->flag == 1)
		count++;
	file_to_image(data, &(data->tex_lplayer), L_PLAYER);
	if (data->flag == 1)
		count++;
	file_to_image(data, &(data->tex_rplayer), R_PLAYER);
	if (data->flag == 1)
		count++;
	file_to_image(data, &(data->tex_collectible), COLLECTIBLE);
	if (data->flag == 1)
		count++;
	file_to_image(data, &(data->tex_wall), WALL);
	if (data->flag == 1)
		count++;
	file_to_image(data, &(data->tex_background), BACKGROUND);
	if (data->flag == 1)
		count++;
	file_to_image(data, &(data->tex_exit), EXIT);
	if (data->flag == 1)
		count++;
	ft_error_quit(data, count);	
}

void	mlx_data_init(t_data *data, int width, int height)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
	{	
		free(data->mlx_ptr);
		exit (0);
	}
	load_textures(data, 0);
	data->w_width = width * data->tex_dplayer.t_width;
	data->w_height = height * data->tex_dplayer.t_height;
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->w_width,
			data->w_height, NAME);
	if (data->win_ptr == NULL)
	{
		free(data->mlx_ptr);
		exit (0);
	}
	get_coordinates(data);
	data->movement = 1;
	data->keycode = 0;
}

int	game_frame(void *param)
{
	t_data		*data;
	t_texture	*texture;
	int			bp;

	data = (t_data *)param;
	texture = &(data->tex_dplayer);
	data->index = 0;
	data->image = mlx_new_image(data->mlx_ptr, data->w_width, data->w_height);
	if (!data->image)
		return (0);
	data->addr = mlx_get_data_addr(data->image, &bp, &bp, &bp);
	ft_draw_background(data);
	ft_draw_sprites(data);
	texture = &(data->tex_dplayer);
	ft_draw_player(data, texture);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image, 0, 0);
	mlx_destroy_image(data->mlx_ptr, data->image);
	data->image = NULL;
	return (0);
}

void ft_destroy_images(t_data *data)
{
	if (data->tex_dplayer.img != NULL)
			mlx_destroy_image(data->mlx_ptr, data->tex_dplayer.img);
	if (data->tex_uplayer.img != NULL)
			mlx_destroy_image(data->mlx_ptr, data->tex_uplayer.img);
	if (data->tex_lplayer.img != NULL)
			mlx_destroy_image(data->mlx_ptr, data->tex_lplayer.img);
	if (data->tex_rplayer.img != NULL)
			mlx_destroy_image(data->mlx_ptr, data->tex_rplayer.img);
	if (data->tex_collectible.img)
			mlx_destroy_image(data->mlx_ptr, data->tex_collectible.img);
	if (data->tex_exit.img != NULL)
			mlx_destroy_image(data->mlx_ptr, data->tex_exit.img);
	if (data->tex_wall.img != NULL)
			mlx_destroy_image(data->mlx_ptr, data->tex_wall.img);
	if (data->tex_background.img != NULL)
			mlx_destroy_image(data->mlx_ptr, data->tex_background.img);
}

int	quit_game(void *param)
{
	t_data	*data;

	if (!param)
		exit(0);
	data = (t_data *)param;
	ft_freetab(data->map_tab);
	if (data->image)
		mlx_destroy_image(data->mlx_ptr, data->image);
	ft_destroy_images(data);
	if (data->win_ptr != NULL)
	{
			mlx_clear_window(data->mlx_ptr, data->win_ptr);
			mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	}
	if (data->mlx_ptr) 
	{
			mlx_destroy_display(data->mlx_ptr);
			free(data->mlx_ptr);
	}
	free(data);
	exit (0);
}