/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_coordinates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 17:33:14 by ddiakova          #+#    #+#             */
/*   Updated: 2021/09/29 17:33:19 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_coordinates(t_data *data)
{
	int x;
	int y;

	y = 0;
	while (data->map_tab[y])
	{
		x = 0;
		while(data->map_tab[y][x])
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