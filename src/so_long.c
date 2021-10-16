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

// void my_mlx_sprite_put(t_data *data, void *dest, t_texture *texture, int x, int y)
// {
//     int i;
//     int start;
// 	int bpp;

// 	bpp = texture->bits_per_pixel / 8;
//     i = 0;
//     start = bpp * (x + y * data->w_width);
	
//     while (i < texture->t_height)
//     {
//         ft_memcpy(dest + start + i * data->w_width * bpp, texture->addr + bpp * texture->t_width * i, bpp * texture->t_width);
//         i++;
//     }
// }

void	my_mlx_sprite_put(t_data *data,t_texture *texture, int x, int y)
{
	int i;
	int j;
	int bpp;
	int start;

	i = 0;
	j = 0;
	bpp = texture->bits_per_pixel / 8;
	start = bpp * (x + y * data->w_width);
	while (i < texture->t_height)
	{
		while (j < texture->t_width)
		{
			if ((texture->addr[i * texture->line_length + j * bpp + 0] != 0)
				&& (texture->addr[i * texture->line_length + j * bpp + 1] != 0)
				&& (texture->addr[i * texture->line_length + j * bpp + 2] != 0)
				&&	(texture->addr[i * texture->line_length + j * bpp + 3] == 0))
			{
				ft_memcpy(data->addr + start + i * data->w_width * bpp + j * bpp, 
					texture->addr + bpp * texture->t_width * i + j * bpp, bpp * texture->t_width);
				ft_memcpy(data->addr + start + i * data->w_width * bpp + j * bpp, 
					texture->addr + bpp * texture->t_width * i + j * bpp, bpp * texture->t_width);
				ft_memcpy(data->addr + start + i * data->w_width * bpp + j * bpp, 
					texture->addr + bpp * texture->t_width * i + j * bpp, bpp * texture->t_width);
			}
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
	file_to_image(data, &(data->tex_player), PLAYER);
	file_to_image(data, &(data->tex_collectible), COLLECTIBLE);
	file_to_image(data, &(data->tex_wall), WALL);
	file_to_image(data, &(data->tex_background), BACKGROUND);
	file_to_image(data, &(data->tex_exit), EXIT);
}

// void 	transparency(t_data *data)
// {
// 	get_image_transparency(&(data->tex_player));
// 	get_image_transparency(&(data->tex_collectible));
// 	get_image_transparency(&(data->tex_exit));
// 	get_image_transparency(&(data->tex_wall));
// 	get_image_transparency(&(data->tex_background));
// }

void 	data_init(t_data *data, int width, int height)
{
	data->mlx_ptr = mlx_init();
	load_textures(data);
	data->w_width = width * data->tex_player.t_width;
	data->w_height = height * data->tex_player.t_height;
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->w_width, data->w_height, NAME);
	get_coordinates(data);
	data->movement = 1;
}

// void 	put_background(t_data *data)
// {

// }

int 	game_frame(void *param)
{
	t_data *data = (t_data *)param;
	t_texture *texture = &(data->tex_player);
	int bp;
	int x;
	int y;

	data->index = 0;
	data->image = mlx_new_image(data->mlx_ptr, data->w_width, data->w_height);
	if (!data->image)
		return 0;
	data->addr = mlx_get_data_addr(data->image, &bp, &bp, &bp);
	y = 0;
	while (y < data->height) // while (data->map_tab[y])
	{	
		x = 0;
		while (x < data->width) // while (data->map_tab[x])
		{
			texture = &(data->tex_background);
			my_mlx_sprite_put(data, texture, x * texture->t_width, y * texture->t_height);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image, 0, 0);
	y = 0;
	while (y < data->height) // while (data->map_tab[y])
	{	
		x = 0;
		while (x < data->width) // while (data->map_tab[x])
		{
			if (data->map_tab[y][x] == 'C')
			{
				texture = &(data->tex_collectible);
				my_mlx_sprite_put(data, texture, x * texture->t_width, y * texture->t_height);
			}
			else if (data->map_tab[y][x] == 'E')
			{
				texture = &(data->tex_exit);
				my_mlx_sprite_put(data, texture, x * texture->t_width, y * texture->t_height);
			}
			else if (data->map_tab[y][x] == '1')
			{
				texture = &(data->tex_wall);
				my_mlx_sprite_put(data, texture, x * texture->t_width, y * texture->t_height);
			}
			x++;
		}
		y++;
	}
	texture = &(data->tex_player);
	my_mlx_sprite_put(data->addr, texture, data->pos_player.x * texture->t_width, data->pos_player.y * texture->t_height);
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
	mlx_destroy_image(data->mlx_ptr, data->tex_player.img);
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

int		main(int argc, char **argv)
{
	t_data *data;
	int i;
	int fd;

	fd = 0;
	i = 0;

	(void) argc;
 	data = (t_data*)malloc(sizeof(t_data));
	
	ft_read_map(argv[1], data);
	fd = open(argv[1], O_RDONLY, 0);
	data->height = ft_get_height(data);
	data->width = ft_get_width(data);
	ft_full_map_error_check(data);
	close(fd);
	
	
	while (data->map_tab[i] != NULL)
	{
		for (int j = 0; j < data->width; j++)
			printf ("%c", data->map_tab[i][j]);
		printf("\n");
		i++;
	}

	data_init(data, data->width, data->height);
	mlx_key_hook(data->win_ptr, &deal_key, data);
	mlx_hook(data->win_ptr, 17, 0, quit_game, data);
	mlx_loop_hook(data->mlx_ptr, &game_frame, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}