/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 15:31:45 by ddiakova          #+#    #+#             */
/*   Updated: 2021/10/24 18:16:35 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_get_height(t_data *data)
{
	int	height;
	int	i;

	height = 0;
	i = 0;
	while (data->map_tab[i])
	{
		height++;
		i++;
	}
	return (height);
}

int	ft_get_width(t_data *data)
{
	int	width;
	int	i;

	i = 0;
	width = 0;
	width = ft_strlen(data->map_tab[i]);
	return (width);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	a;

	a = 0;
	while ((s1[a] != '\0') && (s2[a] != '\0'))
	{
		if (s1[a] == s2[a])
			a++;
		if (s1[a] > s2[a] || s1[a] < s2[a])
			return (s1[a] - s2[a]);
	}
	return (0);
}

int	ft_check_extention(char *file)
{
	int	l;

	l = ft_strlen(file);
	if (l == 0)
		 return (0);
	if (l < 5)
		return (0);
	if (ft_strcmp(file + l - 4, ".ber") != 0)
		return (0);
	return (1);
}

int	ft_check_file(char *file)
{
	int	fd;

	fd = open(file, O_DIRECTORY);
	if (fd > 0)
	{
		ft_putstr_fd("Error : not valid file => DIRECTORY\n", 2);
		close (fd);
		exit(0);
	}
	else
		fd = open(file, O_RDONLY, 0);
	return (fd);
}
