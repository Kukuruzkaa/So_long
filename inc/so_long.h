#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include "../Libft/libft.h"

# define NAME "So_long"
# define SPRITE "Star.xpm"
# define COLLECTIBLE "Fleur.xpm"

# define WINDOW_SIZE_X 10
# define WINDOW_SIZE_Y 10

# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define W 13
# define S 1
# define A 0
# define D 2
# define ESC 53

typedef struct s_frame {

    void    *img;
    // void    *item;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
    int     s_width;
    int     s_height;
}               t_frame;

typedef struct s_player {

    int ppos_x;
    int ppos_y;

}               t_player;

typedef struct s_data {

    int     width;
    int     height;
    char    **map_tab;
    
	void    *mlx_ptr;
	void    *win_ptr;
    void    *image;
    int     w_width;
    int     w_height;
    t_frame sprite;
    t_player player;
    
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
void 	ft_cep(t_data *data);

#endif