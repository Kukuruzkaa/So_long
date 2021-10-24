/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 17:33:14 by ddiakova          #+#    #+#             */
/*   Updated: 2021/10/24 17:23:05 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_line(char *line)
{
	if (line)
	{
		free(line);
		line = NULL;
	}
}

void	ft_freetab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_free_data_and_exit(t_data *data)
{
	ft_freetab(data->map_tab);
	free(data);
	exit (0);
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
