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

int	deal_key(int key, void *param)
{
	t_data *data = (t_data *)param;
	printf("key %d\n", key);
	if (key == LEFT || key == A)
		data->player.ppos_x += -1;
	else if (key == RIGHT || key == D)
		data->player.ppos_x += 1;
	else if (key == UP || key == W)
		data->player.ppos_y += -1;
	else if (key == DOWN || key == S)
		data->player.ppos_y += 1;

	if (WINDOW_SIZE_X - 1 < 0)
		data->player.ppos_x = 0;
	if (data->player.ppos_x > WINDOW_SIZE_X - 1)
		data->player.ppos_x = WINDOW_SIZE_X - 1;
	if (data->player.ppos_x < 0)
		data->player.ppos_x = 0;
	if (WINDOW_SIZE_Y - 1 < 0)
		data->player.ppos_y = 0;
	if (data->player.ppos_y > WINDOW_SIZE_Y - 1)
		data->player.ppos_y = WINDOW_SIZE_Y - 1;
	if (data->player.ppos_y < 0)
		data->player.ppos_y = 0;
	return (0);
}

void my_mlx_sprite_put (t_data *data, void *dest, t_frame *frame, int x, int y)
{
    int i;
    int start;
	int bpp;

	bpp = frame->bits_per_pixel / 8;
    i = 0;
    start = bpp * (x + y * data->w_width);
	
    while (i < frame->s_height)
    {
        ft_memcpy(dest + start + i * data->w_width * bpp, frame->addr + bpp * frame->s_width * i, bpp * frame->s_width);
        i++;
    }
}

void	get_image_transparency(t_frame *frame)
{
	int i;
	int j;

	i = 0;
	j = 0;

	while (i < frame->s_height)
	{
		while (j < frame->s_width)
		{
			if (frame->addr[i * frame->line_length + j * frame->bits_per_pixel / 8 + 0] == (char)0xff
				&& frame->addr[i * frame->line_length + j * frame->bits_per_pixel / 8 + 1] == (char)255
				&& frame->addr[i * frame->line_length + j * frame->bits_per_pixel / 8 + 2] == (char)255)
					frame->addr[i * frame->line_length + j * frame->bits_per_pixel / 8 + 3] = 0xFF;
			j++;
		}
		i++;
	}
}

// void 	my_mlx_pixel_put(t_frame *frame, int x, int y, int color)
// {
// 	char *dst;

// 	dst = frame->addr + (y * frame->line_length + x * (frame->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

void 	file_to_image(t_data *data, t_frame *frame, char *img)
{
	int fd;

	fd = open(img, O_RDONLY, 0);
	if (fd < 0)
		return ;
	frame->img = mlx_xpm_file_to_image(data->mlx_ptr, img, &(frame->s_width), &(frame->s_height));
	if (!frame->img)
		return ;
	frame->addr = mlx_get_data_addr(frame->img, &(frame->bits_per_pixel), &(frame->line_length), &(frame->endian));
	close (fd);
}

void 	data_init(t_data *data, int width, int height)
{
	data->mlx_ptr = mlx_init();
	file_to_image(data, &(data->sprite), SPRITE);
	get_image_transparency(&(data->sprite));
	data->w_width = width * data->sprite.s_width;
	data->w_height = height * data->sprite.s_height;
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->w_width, data->w_height, NAME);
	data->player.ppos_x = 0;
	data->player.ppos_y = 0;

}

int 	game_frame(void *param)
{
	t_data *data = (t_data *)param;
	t_frame *avatar = &(data->sprite);

	int bp;
	int x;
	int y;
	void *data_image;

	data->image = mlx_new_image(data->mlx_ptr, data->w_width, data->w_height);
	data_image = mlx_get_data_addr(data->image, &bp, &bp, &bp);
	x = data->player.ppos_x * avatar->s_width;
	y = data->player.ppos_y * avatar->s_height;
	my_mlx_sprite_put(data, data_image, avatar, x, y);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image, 0, 0);
	mlx_destroy_image(data->mlx_ptr, data->image);
	return (0);

}

int		main(int argc, char **argv)
{
	t_data *data;
	t_frame *frame;
	t_player *player;

	int i;
	int fd;

	fd = 0;
	i = 0;

	(void) argc;
 	data = (t_data*)malloc(sizeof(t_data));
	frame = (t_frame*)malloc(sizeof(t_frame));
	player = (t_player*)malloc(sizeof(t_player));

	ft_read_map(argv[1], data);
	data->height = ft_get_height(data);
	data->width = ft_get_width(data);

	data_init(data, WINDOW_SIZE_X, WINDOW_SIZE_Y);
	mlx_key_hook(data->win_ptr, &deal_key, data);
	mlx_loop_hook(data->mlx_ptr, &game_frame, data);
	mlx_loop(data->mlx_ptr);
	// my_mlx_pixel_put(frame, 5, 5, 0x00FF0000);
	
	
	
	while (data->map_tab[i] != NULL)
	{
		for (int j = 0; j < data->width; j++)
			printf ("%c", data->map_tab[i][j]);
		printf("\n");
		i++;
	}
	
	fd = open(argv[1], O_RDONLY, 0);
	ft_full_map_error_check(fd, data);
	close(fd);
	

	return (0);
}
