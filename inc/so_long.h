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
void 	ft_full_map_error_check(int fd, t_data *data);
int     ft_get_height(t_data *data);
int     ft_get_width(t_data *data);
int 	ft_is_rectangular(t_data *data);
int	    ft_is_same_length(t_data *data);
int     ft_is_ones_only(char *line);
int     ft_is_one_ended(char *line);
int 	ft_is_possible_character(char *line);
void 	ft_cep(char *line);

#endif