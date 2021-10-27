/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 17:21:08 by ddiakova          #+#    #+#             */
/*   Updated: 2021/10/24 17:21:31 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_file_error(int fd, char *file)
{
	if (fd < 0 || ft_check_extention(file) == 0)
	{
		 ft_putstr_fd("Error : not valid file extention\n", 2);
		 exit(0);
	}
}

void	ft_error_output(t_data *data, int err)
{
	if (err == 1)
		ft_putstr_fd("Error : not valid map => not rectangular\n", 2);
	else if (err == 2)
		ft_putstr_fd("Error : not valid map => not closed map\n", 2);
	else if (err == 3)
		ft_putstr_fd("Error : not valid map => not closed wall\n", 2);
	else if (err == 4)
		ft_putstr_fd("Error : not valid map => not allowed character\n", 2);
	else if (err == 5)
		ft_putstr_fd("Error : not valid map => not enough game elements\n", 2);
	else if (err == 6)
		ft_putstr_fd("Error : not valid map => more than one player\n", 2);
	else if (err == 7)
		ft_putstr_fd("Error : Texture doesn't exist\n", 2);
	ft_free_data_and_exit(data);
}

void	ft_error_quit(t_data *data, int count)
{
	if (count > 0)
	{
		ft_putstr_fd("Error : Texture not found\n", 2);
		quit_game(data);
	}
}