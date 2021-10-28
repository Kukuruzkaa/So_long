/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:07:25 by ddiakova          #+#    #+#             */
/*   Updated: 2021/10/28 17:28:32 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc == 2)
	{
		data = (t_data *)malloc(sizeof(t_data));
		if (!data)
			return (0);
		ft_data_init(data);
		ft_map_check(data, argv[1]);
		mlx_data_init(data, data->width, data->height);
		mlx_key_hook(data->win_ptr, &deal_key, data);
		mlx_hook(data->win_ptr, 17, 0, quit_game, data);
		mlx_loop_hook(data->mlx_ptr, &game_frame, data);
		mlx_loop(data->mlx_ptr);
	}
	else
		ft_putstr_fd("Error : not valid number of arguments\n", 2);
	return (0);
}
