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

void    ft_init(t_data *data)
{
    data->width = 0;
    data->height = 0;
    data->map_tab = NULL;
    
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
}

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

int 	ft_check_extention(char *file)
{
	char *str;
    int l;

    str = file;
    l = ft_strlen(str);
    if (l < 5)
        return (1);
    if (str[l - 1] == 'r' && str[l - 2] == 'e' 
        && str[l - 3] == 'b' && str[l - 4] == '.')
    {
        if (str[l - 5] == '.' || str[l - 5] == '/')
            return (1);
    }
    return (0);
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

void  ft_read_map(char *file, t_data *data)
{
    t_list *map;
    int fd;
    int ret;
    char *line;

    map = NULL;
    line = NULL;
    // if (ft_check_extention(file) == 0)
    // {
    //     ft_putstr_fd("Error : not valid file extention\n", 2);
    //     exit(0);
    // }
    fd = ft_check_file(file);
    if (fd < 0)
    {
        ft_putstr_fd("Error : file does not exist\n", 2);
        exit(0);
    }
    while ((ret = get_next_line(fd, &line) == 1))
    {
       if (line != NULL && ft_strlen(line) > 0)
       {
            ft_lstadd_back(&map, ft_lstnew(ft_strdup(line)));
            if (line)
            {
                free(line);
                line = NULL;
            }
       }
    }
    if (ret == 0)
    {
       ft_lstadd_back(&map, ft_lstnew(ft_strdup(line)));
       if (line)
        {
            free(line);
            line = NULL;
        }
    }
    ft_fill_map(&data, map);
    ft_listclear(&map);
    close (fd);
}
