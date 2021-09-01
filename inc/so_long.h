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
    int **map;
    
	void *mlx_ptr;
	void *win_ptr;
}				t_data;

void    read_map(char *file, t_data *data);


#endif