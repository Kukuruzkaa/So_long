/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:05:30 by ddiakova          #+#    #+#             */
/*   Updated: 2021/10/24 18:05:42 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_pposition(t_data *data)
{
	if (data->width - 1 < 0)
		data->pos_player.x = 0;
	if (data->pos_player.x > data->width - 1)
		data->pos_player.x = data->width - 1;
	if (data->pos_player.x < 0)
		data->pos_player.x = 0;
	if (data->height - 1 < 0)
		data->pos_player.y = 0;
	if (data->pos_player.y > data->height - 1)
		data->pos_player.y = data->height - 1;
	if (data->pos_player.y < 0)
		data->pos_player.y = 0;
}

void	pmoves(t_data *data)
{
	int	y;
	int	x;

	y = data->pos_player.y;
	x = data->pos_player.x;
	if (data->map_tab[y][x] == '0' || data->map_tab[y][x] == 'C')
	{
		if (data->map_tab[y][x] == 'C')
		{
			data->map_tab[y][x] = 'P';
			data->map_tab[data->pos_player.y][data->pos_player.x] = '0';
			data->collectible--;
		}
	}
	if (data->map_tab[y][x] == 'E' && data->collectible == 0)
		quit_game(data);
}

void	ft_change_x(t_data *data, int key, int one, int two)
{
	data->keycode = key;
	data->pos_player.x += one;
	if (data->map_tab[data->pos_player.y][data->pos_player.x] == '1'
	|| (data->map_tab[data->pos_player.y][data->pos_player.x] == 'E'
		&& data->collectible > 0))
		data->pos_player.x += two;
	else
	{
		pmoves(data);
		printf ("Current number of movements : %d\n", data->movement);
		data->movement++;
	}
}

void	ft_chnage_y(t_data *data, int key, int one, int two)
{
	data->keycode = key;
	data->pos_player.y += one;
	if (data->map_tab[data->pos_player.y][data->pos_player.x] == '1'
	|| (data->map_tab[data->pos_player.y][data->pos_player.x] == 'E'
		&& data->collectible > 0))
		data->pos_player.y += two;
	else
	{
		pmoves(data);
		printf ("Current number of movements : %d\n", data->movement);
		data->movement++;
	}
}

int	deal_key(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (key == LEFT || key == A)
		ft_change_x(data, key, -1, 1);
	if (key == RIGHT || key == D)
		ft_change_x(data, key, 1, -1);
	else if (key == UP || key == W)
		ft_chnage_y(data, key, -1, 1);
	else if (key == DOWN || key == S)
		ft_chnage_y(data, key, 1, -1);
	else if (key == ESC)
		quit_game(data);
	check_pposition(data);
	return (0);
}
