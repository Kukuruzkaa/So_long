/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 15:31:45 by ddiakova          #+#    #+#             */
/*   Updated: 2021/09/06 15:31:48 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int     ft_get_height(t_data *data)
{
    int height;
    int i;

    height = 0;
    i = 0;
    while (data->map_tab[i])
    {
        height++;
        i++;
    }
    return (height);
}

int     ft_get_width(t_data *data)
{
    int width;
    int i;

    i = 0;
    width = 0;
 
    width = ft_strlen(data->map_tab[i]);
    return (width);
}

char    **ft_fill_map(t_data **data, t_list *lst)
{
    int i;
    int tab_size;
    t_list **tmp;

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

int		ft_strcmp(char *s1, char *s2)
{
	int a;
	
	a = 0;
	while ((s1[a] != '\0') && ( s2[a] != '\0'))
	{
		if (s1[a] ==  s2[a])
			a++;
		if (s1[a] > s2[a] || s1[a] < s2[a])
			return (s1[a] - s2[a]);
	}
	return (0);
}

int 	ft_check_extention(char *file)
{
    int l;

    l = ft_strlen(file);
    if (l == 0)
        return (0);
    if (l < 5)
        return (0);
    if (ft_strcmp(file + l - 4, ".ber") != 0)
        return (0);
    return (1);
}

int   ft_check_file(char *file)
{
    int fd;

    fd = open(file, __O_DIRECTORY);
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


void  ft_free_line(char *line)
{
    if (line)
    {
        free(line);
        line = NULL;
    }
}


void  ft_read_map(char *file, t_data *data)
{
    t_list *map;
    int fd;
    int ret;
    char *line;

    map = NULL;
    line = NULL;
    fd = ft_check_file(file);
    ft_file_error(fd, file);
    while ((ret = get_next_line(fd, &line) == 1))
    {
       if (line != NULL && ft_strlen(line) > 0)
       {
            ft_lstadd_back(&map, ft_lstnew(ft_strdup(line)));
            ft_free_line(line);
       }
    }
    if (ret == 0)
    {
       ft_lstadd_back(&map, ft_lstnew(ft_strdup(line)));
       ft_free_line(line);       
    }
    ft_fill_map(&data, map);
    ft_listclear(&map);
    close (fd);
}
