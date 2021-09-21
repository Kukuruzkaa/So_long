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

int	deal_key(int key, t_data *data)
{
	(void) data;
	printf ("%c", key);
	return (0);
	
}

void 	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
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
	data->height = ft_get_height(data);
	data->width = ft_get_width(data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1920, 1080, "so_long");
	data->img = mlx_new_image(data->mlx_ptr, 1920, 1080);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	my_mlx_pixel_put(data, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	mlx_key_hook(data->win_ptr, deal_key, &data);
	mlx_loop(data->mlx_ptr);
	


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
