/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:07:25 by ddiakova          #+#    #+#             */
/*   Updated: 2021/10/24 17:25:10 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc == 2)
	{
		data = (t_data *)malloc(sizeof(t_data));
		ft_map_check(data, argv[1]);
		data_init(data, data->width, data->height);
		mlx_key_hook(data->win_ptr, &deal_key, data);
		mlx_hook(data->win_ptr, 17, 0, quit_game, data);
		mlx_loop_hook(data->mlx_ptr, &game_frame, data);
		mlx_loop(data->mlx_ptr);
	}
	else
		ft_putstr_fd("Error : not valid number of arguments\n", 2);
	return (0);
}
