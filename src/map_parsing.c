/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 14:57:41 by ddiakova          #+#    #+#             */
/*   Updated: 2021/09/10 14:57:44 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void 	ft_cep(t_data *data, int c, int e, int p)
{
	int i;
	int j;

	i = 0;
	data->collectible = 0;
	while (data->map_tab[i])
	{
		j = 0;
		while (j < data->width)
		{
			if (data->map_tab[i][j] == 'C')
				c++;
			else if (data->map_tab[i][j] == 'E')
				e++;
			else if (data->map_tab[i][j] == 'P')
				p++;
			j++;
		}
		i++;
	}
	data->collectible = c;
	if ( c < 1 || e < 1 || p < 1)
	{
		ft_putstr_fd("Error : not valid map => not enough game elements\n", 2);
		ft_freetab(data->map_tab);
		exit (0);
	}
}

void 	ft_full_map_error_check(int fd, t_data *data)
{

	int i;
	int j;

	i = 0;
	j = data->height - 1;
	(void) fd;
	// if (get_next_line(fd, data->map_tab[i]) == -1)
	// {
	// 	ft_putstr_fd("Error : not valid map => not valid file\n", 2);
	// 	ft_freetab(data->map_tab);
	// 	free(data);
	// 	exit (0);
	// }
	if (ft_is_rectangular(data) == 0 || ft_is_same_length(data) == 0)
	{
		ft_putstr_fd("Error : not valid map => not rectangular\n", 2);
		ft_freetab(data->map_tab);
		free(data);
		exit (0);
	}
	else if (ft_is_ones_only(data->map_tab[i]) == 0 || ft_is_ones_only(data->map_tab[j]) == 0)
	{
		ft_putstr_fd("Error : not valid map => not closed map\n", 2);
		ft_freetab(data->map_tab);
		exit (0);
	}
	while (data->map_tab[i])
	{
		if (ft_is_one_ended(data->map_tab[i]) == 0 && i != j)
		{
			ft_putstr_fd("Error : not valid map => not closed wall\n", 2);
			ft_freetab(data->map_tab);
			free(data);
			exit (0);
		}
		if (ft_is_possible_character(data->map_tab[i]) == 0)
		{
			ft_putstr_fd("Error : not valid map => not allowed character\n", 2);
			ft_freetab(data->map_tab);
			free(data);
			exit (0);
		}
		i++;
	}
	ft_cep(data, 0, 0, 0);
}

