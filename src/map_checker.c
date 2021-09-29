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

int 	ft_is_rectangular(t_data *data)
{
	if  (data->height == data->width)
		return (0);
	return (1);
}

int	ft_is_same_length(t_data *data)
{
	int i;

	i = 0;
	while (data->map_tab[i] && data->map_tab[i + 1] != NULL)
	{
		if (ft_strlen(data->map_tab[i + 1]) != ft_strlen(data->map_tab[i])) 
			return (0);
		i++;
	}
	return (1);
} 

int ft_is_ones_only(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int ft_is_one_ended(char *line)
{
	int i;
	int j;

	i = 0;
	j = ft_strlen(line) - 1;

	while (line[i])
	{
		if (i == 0 || i == j)
		{
			if (line[i] != '1')
				return (0);
		}
		i++;
	}
	return (1);
}

int 	ft_is_possible_character(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (!ft_strchr("01CEP", line[i]))
			return (0);
		i++;
	}
	return (1);
}
