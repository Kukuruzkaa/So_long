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

void 	ft_cep(char *line)
{
	int i;
	int c;
	int e;
	int p;

	c = 0;
	e = 0;
	p = 0;
	i = -1;
	while (line[++i])
	{
		if (line[i] == 'C')
			c++;
		else if (line[i] == 'E')
			e++;
		else if (line[i] == 'P')
			p++;
	}
	if ( c < 1 || e < 1 || p < 1)
		ft_putstr_fd("Error : not enough game elements\n", 2);
}

void 	ft_full_map_error_check(int fd, t_data *data)
{

	int i;

	i = 0;
	if (get_next_line(fd, data->map_tab) == -1)
		ft_putstr_fd("Error : not valid file\n", 2);
	else if (ft_is_rectangular(data) == 0 || ft_is_same_length(data) == 0)
		ft_putstr_fd("Error : the map is not rectangular\n", 2);
	while (data->map_tab[i])
	{
		if (ft_is_ones_only(data->map_tab[i]) == 0 
			|| ft_is_one_ended(data->map_tab[i]) == 0)
			ft_putstr_fd("Error : the map is not closed\n", 2);
		else if (ft_is_possible_character(data->map_tab[i]) == 0)
			ft_putstr_fd("Error : not allowed character\n", 2);
		else
			ft_cep(data->map_tab[i]);
	}
	i++;	
}

