#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../Libft/libft.h"

# define NAME "So_long"
# define PLAYER "Wolf.xpm"
# define COLLECTIBLE "Lapin.xpm"
# define EXIT "Ship.xpm"
# define WALL "Volna.xpm"
# define BACKGROUND "Fon.xpm" 

# define WINDOW_SIZE_X 16
# define WINDOW_SIZE_Y 14

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

typedef struct  s_coordinates {
    int x;
    int y;
}               t_coordinates;          

typedef struct s_data {

    int     width;
    int     height;
    char    **map_tab;
    
	void    *mlx_ptr;
	void    *win_ptr;
    void    *image;
    int     w_width;
    int     w_height;
    int     index;
    int     movement;
    t_texture tex_player;
    t_texture tex_wall;
    t_texture tex_background;
    t_texture tex_exit;
    t_texture tex_collectible;
    t_coordinates   pos_player;
    t_coordinates   pos_collectible;
    t_coordinates   pos_exit; 
    t_coordinates   pos_wall;
    t_coordinates   pos_back; 
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
void	get_coordinates(t_data *data);
int	    quit_game(void *param);


#endif