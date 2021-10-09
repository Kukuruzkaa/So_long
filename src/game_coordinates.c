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

void	lstdelone(t_list **list)
{
	if (*list)
	{
		free((*list)->content);
		free(*list);
		*list = NULL;
	}
}

void	ft_listclear(t_list **list)
{
	t_list	*t;

	if (!*list)
		return ;
	while (*list)
	{
		t = (*list)->next;
		lstdelone(list);
		*list = t;
	}
	*list = NULL;
}