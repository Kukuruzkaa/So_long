#include "so_long.h"
void    ft_init(t_data *data)
{
    width = 0;
    height;
    int **map_tab;
    
	void *mlx_ptr;
	void *win_ptr;
}



int	ft_counting_words(char const *s, char c)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			nb++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (nb);
}

int     ft_get_height(char *file)
{
    char *line;
    int fd;
    int height;

    fd = 0;
    height = 0;
    fd = open(file, O_RDONLY, 0);
    while(get_next_line(fd, &line))
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

    fd = 0;
    width = 0;
    fd = open(file, O_RDONLY, 0);
    get_next_line(fd, &line);
    width = ft_counting_words(line, ' ');
    close(fd);
    return (width);
}

void    ft_fill_map(int *tab_element, char *line)
{
    int i;
    char **content;

    i = 0;
    tab_element = NULL;
    tab_element = (int*)malloc(sizeof(int));
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
        ft_fill_map(data->map_tab[i], line);
        free (line);
        i++;
    }
    close(fd);
    data->map_tab[i] = NULL;
}
