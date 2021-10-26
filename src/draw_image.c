/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 14:44:56 by ddiakova          #+#    #+#             */
/*   Updated: 2021/10/24 20:57:41 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	file_to_image(t_data *data, t_texture *texture, char *img)
{
	int	fd;

	data->flag = 0;
	fd = open(img, O_RDONLY, 0);
	if (fd > 0)
	{
		texture->img = mlx_xpm_file_to_image(data->mlx_ptr, img,
				&(texture->t_width), &(texture->t_height));
		texture->addr = mlx_get_data_addr(texture->img, &(texture->bits_per_pixel),
			&(texture->line_length), &(texture->endian));
		close (fd);	
	}
	else
	{
		data->flag = 1;
		texture->img = NULL;
	}
}

void	my_mlx_sprite_put(t_data *data, t_texture *texture, int x, int y)
{
	int	i;
	int	j;
	int	bpp;
	int	start;

	i = 0;
	bpp = texture->bits_per_pixel / 8;
	start = bpp * (y * data->w_width + x);
	while (i < texture->t_height)
	{
		j = 0;
		while (j < texture->t_width)
		{
			if ((texture->addr[i * texture->line_length + j * bpp] != 0))
				ft_memcpy(data->addr + start + i * data->w_width * bpp
					+ j * bpp, texture->addr + bpp * texture->t_width * i
					+ j * bpp, bpp);
			j++;
		}
		i++;
	}
}

void	ft_draw_background(t_data *data)
{
	t_texture	*texture;
	int			x;
	int			y;

	texture = &(data->tex_dplayer);
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			texture = &(data->tex_background);
			my_mlx_sprite_put(data, texture, x * texture->t_width,
				y * texture->t_height);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image, 0, 0);
}

void	ft_draw_sprites(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < data->height)
	{
		x = -1;
		while (++x < data->width)
		{
			if (data->map_tab[y][x] == 'C')
				my_mlx_sprite_put(data, &(data->tex_collectible),
					x * data->tex_collectible.t_width,
					y * data->tex_collectible.t_height);
			else if (data->map_tab[y][x] == 'E')
				my_mlx_sprite_put(data, &(data->tex_exit),
					x * data->tex_exit.t_width,
					y * data->tex_exit.t_height);
			else if (data->map_tab[y][x] == '1')
				my_mlx_sprite_put(data, &(data->tex_wall),
					x * data->tex_wall.t_width,
					y * data->tex_wall.t_height);
		}
	}
}

void	ft_draw_player(t_data *data, t_texture *texture)
{
	if (data->keycode == 0)
		texture = &(data->tex_dplayer);
	if (data->keycode == LEFT || data->keycode == A)
		texture = &(data->tex_lplayer);
	if (data->keycode == RIGHT || data->keycode == D)
		texture = &(data->tex_rplayer);
	if (data->keycode == UP || data->keycode == W)
		texture = &(data->tex_uplayer);
	if (data->keycode == DOWN || data->keycode == S)
		texture = &(data->tex_dplayer);
	my_mlx_sprite_put(data, texture, data->pos_player.x * texture->t_width,
		data->pos_player.y * texture->t_height);
}
