#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include "../Libft/libft.h"

typedef struct s_data {


    int width;
    int height;
    char **map_tab;
    
	void *mlx_ptr;
	void *win_ptr;
}				t_data;

void    ft_read_map(char *file, t_data *data);
int     ft_get_width(char *file);
int     ft_check_length(t_data *data);
int     ft_check_wall(char *line);


#endif