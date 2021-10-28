/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 17:14:53 by ddiakova          #+#    #+#             */
/*   Updated: 2021/10/28 17:35:09 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_data_init(t_data *data)
{
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->image = NULL;
	data->addr = NULL;
	data->tex_dplayer.img = NULL;
	data->tex_uplayer.img = NULL;
	data->tex_lplayer.img = NULL;
	data->tex_rplayer.img = NULL;
	data->tex_wall.img = NULL;
	data->tex_background.img = NULL;
	data->tex_exit.img = NULL;
	data->tex_collectible.img = NULL;
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

void	ft_check_zero_line(char *line)
{
	if (line[0] == 0)
	{
		free(line);
		line = NULL;
	}
}

void	ft_map_check(t_data *data, char *str)
{
	int	fd;

	ft_read_map(str, data);
	fd = open(str, O_RDONLY, 0);
	data->height = ft_get_height(data);
	data->width = ft_get_width(data);
	ft_full_map_error_check(data);
	close(fd);
}
