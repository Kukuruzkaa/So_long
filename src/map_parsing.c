/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 14:57:41 by ddiakova          #+#    #+#             */
/*   Updated: 2021/10/24 20:58:30 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_cep(t_data *data, int c, int e, int p)
{
	int	i;
	int	j;

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
	if (c < 1 || e < 1 || p < 1)
		ft_error_output(data, 5);
	if (p > 1)
		ft_error_output(data, 6);
}

char	**ft_fill_map(t_data **data, t_list *lst)
{
	int		i;
	int		tab_size;
	t_list	**tmp;

	i = 0;
	tmp = NULL;
	tmp = &lst;
	tab_size = ft_lstsize(lst);
	(*data)->map_tab = ft_calloc(sizeof(char *), tab_size + 1);
	if (!(*data)->map_tab)
		return (NULL);
	while (lst)
	{
		(*data)->map_tab[i] = ft_strdup(lst->content);
		i++;
		lst = lst->next;
	}
	(*data)->map_tab[tab_size] = NULL;
	ft_listclear(tmp);
	return ((*data)->map_tab);
}

void	ft_add_lst(t_list **lst, char *line)
{
	ft_lstadd_back(lst, ft_lstnew(ft_strdup(line)));
	ft_free_line(line);
}

void	ft_read_map(char *file, t_data *data)
{
	t_list	*map;
	int		fd;
	int		ret;
	char	*line;

	map = NULL;
	line = NULL;
	fd = ft_check_file(file);
	ft_file_error(fd, file);
	ret = get_next_line(fd, &line);
	while (ret == 1)
	{	
		if (line[0] == 0)
		{
			free(line);
			line = NULL;
		}
		if (line != NULL && ft_strlen(line) > 0 && line[0] != 0)
			ft_add_lst(&map, line);
		ret = get_next_line(fd, &line);
	}
	if (ret == 0)
		ft_add_lst(&map, line);
	ft_fill_map(&data, map);
	ft_listclear(&map);
	close (fd);
}

void	ft_full_map_error_check(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = data->height - 1;
	if (ft_is_rectangular(data) == 0 || ft_is_same_length(data) == 0)
		ft_error_output(data, 1);
	else if (ft_is_ones_only(data->map_tab[i]) == 0
		|| ft_is_ones_only(data->map_tab[j]) == 0)
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
