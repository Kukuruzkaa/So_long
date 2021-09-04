#include "so_long.h"

void    ft_init(t_data *data)
{
    data->width = 0;
    data->height = 0;
    data->map_tab = NULL;
    
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
}

int     ft_get_height(char *file)
{
    char *line;
    int fd;
    int height;
    int ret;

    fd = 0;
    height = 0;
    ret = 0;
    fd = open(file, O_RDONLY, 0);
    while((ret = (get_next_line(fd, &line)) > 0))
    {
        height++;
        free(line);
    }
    close(fd);
    return (height);
}

int     ft_get_width(char *file)
{
    char *line;
    int fd;
    int width;
    int ret;

    fd = 0;
    width = 0;
    ret = 0;
    fd = open(file, O_RDONLY, 0);
    while ((ret = get_next_line(fd, &line) > 0))
    {
        width = ft_strlen(line);
        free (line);
    }
    close(fd);
    return (width);
}

void    ft_fill_map(int *tab_element, char *line, t_data *data)
{
    int i;
    char **content;

    i = 0;
    tab_element = NULL;
    tab_element = (int*)malloc(sizeof(int) * (data->width + 1));
    content = NULL;
    content = ft_split(line, ' ');
    while (content[i])
    {
       tab_element[i] = ft_atoi(content[i]);
       free (content [i]);
       i++;
    }
    free(content);
}

void    ft_read_map(char *file, t_data *data)
{
    int i;
    int fd;
    char *line;

    line = NULL;
    i = 0;
    data->height = ft_get_height(file);
    data->width = ft_get_width(file);

    data->map_tab = (int**)malloc(sizeof(int*) * (data->height + 1));
    while (i <= data->height)
    {
        data->map_tab[i] = (int*)malloc(sizeof(int) * (data->width + 1));
        i++;
    }
    fd = open(file, O_RDONLY, 0);
    while (get_next_line(fd, &line))
    {
        ft_fill_map(data->map_tab[i], line, data);
        free (line);
        i++;
    }
    close(fd);
    data->map_tab[i] = NULL;
}
