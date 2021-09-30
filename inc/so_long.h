#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include "../Libft/libft.h"

# define NAME "So_long"
# define SPRITE "Lapin.xpm"
# define COLLECTIBLE "Fleur.xpm"

# define WINDOW_SIZE_X 10
# define WINDOW_SIZE_Y 8

# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define W 13
# define S 1
# define A 0
# define D 2
# define ESC 53

typedef struct s_texture {

    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
    int     t_width;
    int     t_height;
}               t_texture;

typedef struct s_item {

    int ipos_x;
    int ipos_y;
}              t_item;

typedef struct s_player {

    int ppos_x;
    int ppos_y;

}               t_player;

typedef struct s_exit {

    int epos_x;
    int epos_y;
}              t_exit;

// typedef struct s_objects {
//     int *tex1;
//     int *tex2;
// } t_textures;

typedef struct s_data {

    int     width;
    int     height;
    char    **map_tab;
    
	void    *mlx_ptr;
	void    *win_ptr;
    void    *image;
    int     w_width;
    int     w_height;
    t_texture sprite;
    t_texture wall;
    t_texture background;
    t_texture exit;
    t_texture collectible;
    t_player player;
    t_item   item;
    t_exit   door;
    // t_textures textures;   
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