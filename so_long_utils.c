#include "so_long.h"

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

    height = 0;
    fd = open(fd, O_RDONLY, 0);
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

    width = 0;
    fd = open(fd, O_RDONLY, 0);
    get_next_line(fd, &line));
    width = ft_counting_words(line, ' ');
    close(fd);
    return (width);
}

void    read_map(char *file, t_data *data)
{
    data->height = get_height(file);
    data->width = get_width(file);


}
