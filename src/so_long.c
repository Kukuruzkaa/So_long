/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 15:31:18 by ddiakova          #+#    #+#             */
/*   Updated: 2021/09/06 15:31:35 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_sprite_put(t_data *data, t_texture *texture, int x, int y)
{
	int i;
	int j;
	int bpp;
	int start;

	i = 0;
	
	bpp = texture->bits_per_pixel / 8;
	start = bpp * (y * data->w_width + x);
	while (i < texture->t_height)
	{
		j = 0;
		while (j < texture->t_width)
		{
			if ((texture->addr[i * texture->line_length + j * bpp] != 0))
				ft_memcpy(data->addr + start + i * data->w_width * bpp + j * bpp, texture->addr + bpp * texture->t_width * i + j * bpp, bpp);
			j++;
		}
		i++;
	}
}

void 	file_to_image(t_data *data, t_texture* texture, char *img)
{
	int fd;

	fd = open(img, O_RDONLY, 0);
	if (fd < 0)
		return ;
	texture->img = mlx_xpm_file_to_image(data->mlx_ptr, img, &(texture->t_width), &(texture->t_height));
	if (!texture->img)
		return ;
	texture->addr = mlx_get_data_addr(texture->img, &(texture->bits_per_pixel), &(texture->line_length), &(texture->endian));
	close (fd);
}

void 	load_textures(t_data *data)
{
	file_to_image(data, &(data->tex_dplayer), D_PLAYER);
	file_to_image(data, &(data->tex_uplayer), U_PLAYER);
	file_to_image(data, &(data->tex_lplayer), L_PLAYER);
	file_to_image(data, &(data->tex_rplayer), R_PLAYER);
	file_to_image(data, &(data->tex_collectible), COLLECTIBLE);
	file_to_image(data, &(data->tex_wall), WALL);
	file_to_image(data, &(data->tex_background), BACKGROUND);
	file_to_image(data, &(data->tex_exit), EXIT);
}

void 	data_init(t_data *data, int width, int height)
{
	data->mlx_ptr = mlx_init();
	load_textures(data);
	data->w_width = width * data->tex_dplayer.t_width;
	data->w_height = height * data->tex_dplayer.t_height;
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->w_width, data->w_height, NAME);
	get_coordinates(data);
	data->movement = 1;
	data->keycode = 0;
}

void 	ft_draw_background(t_data *data)
{
	t_texture *texture = &(data->tex_dplayer);
	int x;
	int y;

	y = 0;
	while (y < data->height)
	{	
		x = 0;
		while (x < data->width)
		{
			texture = &(data->tex_background);
			my_mlx_sprite_put(data, texture, x * texture->t_width, y * texture->t_height);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image, 0, 0);
}

void 	ft_draw_sprites(t_data *data)
{
	int x;
	int y;

	y = -1;
	while (++y < data->height)
	{	
		x = -1;
		while (++x < data->width)
		{
			if (data->map_tab[y][x] == 'C')
				my_mlx_sprite_put(data, &(data->tex_collectible), x * data->tex_collectible.t_width, y * data->tex_collectible.t_height);
			else if (data->map_tab[y][x] == 'E')
				my_mlx_sprite_put(data, &(data->tex_exit), x * data->tex_exit.t_width, y * data->tex_exit.t_height);
			else if (data->map_tab[y][x] == '1')
				my_mlx_sprite_put(data, &(data->tex_wall), x * data->tex_wall.t_width, y * data->tex_wall.t_height);
		}
	}
}

void	ft_draw_player(t_data *data, t_texture *texture)
{
	if (data->keycode == 0)
	{
		texture = &(data->tex_dplayer);
		my_mlx_sprite_put(data, texture, data->pos_player.x * texture->t_width, data->pos_player.y * texture->t_height);
	}
	if (data->keycode == LEFT || data->keycode == A)
	{
		texture = &(data->tex_lplayer);
		my_mlx_sprite_put(data, texture, data->pos_player.x * texture->t_width, data->pos_player.y * texture->t_height);
	}
	if (data->keycode == RIGHT || data->keycode == D)
	{
		texture = &(data->tex_rplayer);
		my_mlx_sprite_put(data, texture, data->pos_player.x * texture->t_width, data->pos_player.y * texture->t_height);
	}
	if (data->keycode == UP || data->keycode == W)
	{
		texture = &(data->tex_uplayer);
		my_mlx_sprite_put(data, texture, data->pos_player.x * texture->t_width, data->pos_player.y * texture->t_height);
	}
	if (data->keycode == DOWN || data->keycode == S)
	{
		texture = &(data->tex_dplayer);
		my_mlx_sprite_put(data, texture, data->pos_player.x * texture->t_width, data->pos_player.y * texture->t_height);
	}
}

int 	game_frame(void *param)
{
	t_data *data = (t_data *)param;
	t_texture *texture = &(data->tex_dplayer);
	int bp;

	data->index = 0;
	data->image = mlx_new_image(data->mlx_ptr, data->w_width, data->w_height);
	if (!data->image)
		return 0;
	data->addr = mlx_get_data_addr(data->image, &bp, &bp, &bp);
	ft_draw_background(data);
	ft_draw_sprites(data);
	texture = &(data->tex_dplayer);
	ft_draw_player(data, texture);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image, 0, 0);
	mlx_destroy_image(data->mlx_ptr, data->image);
	data->image = NULL;
	data->index = 1;
	return (0);
}

int	quit_game(void *param)
{
	t_data *data = (t_data *)param;

	ft_freetab(data->map_tab);
	if (data->index == 0)
		mlx_destroy_image(data->mlx_ptr, data->image);
	mlx_destroy_image(data->mlx_ptr, data->tex_dplayer.img);
	mlx_destroy_image(data->mlx_ptr, data->tex_uplayer.img);
	mlx_destroy_image(data->mlx_ptr, data->tex_lplayer.img);
	mlx_destroy_image(data->mlx_ptr, data->tex_rplayer.img);
	mlx_destroy_image(data->mlx_ptr, data->tex_collectible.img);
	mlx_destroy_image(data->mlx_ptr, data->tex_exit.img);
	mlx_destroy_image(data->mlx_ptr, data->tex_wall.img);
	mlx_destroy_image(data->mlx_ptr, data->tex_background.img);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free(data);
	exit (0);
}
