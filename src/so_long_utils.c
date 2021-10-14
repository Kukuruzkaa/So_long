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

// int     ft_get_height(char *file)
// {
//     char *line;
//     int height;
//     int fd;

//     height = 0;
//     fd = open(file, O_RDONLY, 0);
//     while (get_next_line(fd, &line))
//     {
//         height++;
//         free(line);
//     }
//     close (fd);
//     return (height);
// }

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
    printf("tab_size = %d\n", tab_size);

    (*data)->map_tab = ft_calloc(sizeof(char *), tab_size + 1);
    if (!(*data)->map_tab)
        return (NULL);
    while (lst)
    {
        printf("lst:[%s]\n", lst->content);
        printf("i = %d\n", i);
        (*data)->map_tab[i] = ft_strdup(lst->content);
        printf("map[i] = %s\n", (*data)->map_tab[i]);
        i++;
        lst = lst->next;
    }
    (*data)->map_tab[tab_size] = NULL;
    //printf("%d\n, %s\n", i, (*data)->map_tab[i]);
    ft_listclear(tmp);
    return ((*data)->map_tab);
}

// while (i < data->height)
//         {
//             data->map_tab[i] = ft_strdup(line);
//             i++;
//         }
//         data->map_tab[i] = NULL;


void  ft_read_map(char *file, t_data *data)
{
    t_list *map;
    int fd;
    int ret;
    char *line;
    // int i;

    map = NULL;
    line = NULL;
    // i = 0;
    // data->height = ft_get_height(file);
    // data->map_tab = malloc(sizeof(char *) * (data->height + 1));
    fd = open(file, O_RDONLY, 0);
        if (fd < 0)
            return ;
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
       printf("%s\n", line);
       if (line)
        {
            free(line);
            line = NULL;
        }
    }
    // t_list *tmp;
    // tmp = map;
    // while (tmp)
    // {
    //     printf("tmp:[%s]\n", tmp->content);
    //     tmp= tmp->next;
    // }
    ft_fill_map(&data, map);
    ft_listclear(&map);
    close (fd);
}
