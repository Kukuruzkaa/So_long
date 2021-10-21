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

	i = -1;
	data->collectible = 0;
	while (data->map_tab[++i])
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
	}
	data->collectible = c;
	if ( c < 1 || e < 1 || p < 1)
		ft_error_output(data, 5);
}

void	ft_free_data_and_exit(t_data *data)
{
	ft_freetab(data->map_tab);
	free(data);
	exit (0);
}

void 	ft_full_map_error_check(t_data *data)
{

	int i;
	int j;

	i = 0;
	j = data->height - 1;

	if (ft_is_rectangular(data) == 0 || ft_is_same_length(data) == 0)
		ft_error_output(data, 1);
	else if (ft_is_ones_only(data->map_tab[i]) == 0 || ft_is_ones_only(data->map_tab[j]) == 0)
		ft_error_output(data, 2);
	while (data->map_tab[i])
	{
		if (ft_is_one_ended(data->map_tab[i]) == 0 && i != j)
			ft_error_output(data, 3);
		if (ft_is_possible_character(data->map_tab[i]) == 0)
			ft_error_output(data, 4);
		i++;
	}
	ft_cep(data, 0, 0, 0);
}