/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 15:32:04 by ddiakova          #+#    #+#             */
/*   Updated: 2021/09/06 15:32:07 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_length(t_data *data)
{
	int i;

	i = 0;
	while (data->map_tab[i] && (data->map_tab[i + 1][0] != '\0'))
	{
		if (ft_strlen(data->map_tab[i + 1]) == ft_strlen(data->map_tab[i]))
			i++;
		else 
			return (0);
	}
	return (1);
} 

int ft_check_wall(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] != 1)
			return (1);
		i++;
	}
	if (line[i - 1] != 1)
		return (0);
	return (0);
}

int ft_check_