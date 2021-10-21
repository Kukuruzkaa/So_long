#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../Libft/libft.h"

# define NAME "So_long"
# define PLAYER "Wolf.xpm"
# define COLLECTIBLE "diamond.xpm"
# define EXIT "cave.xpm"
# define WALL "tree.xpm"
# define BACKGROUND "ground.xpm" 

# define WINDOW_SIZE_X 16
# define WINDOW_SIZE_Y 16

# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define W 119
# define S 115
# define A 97
# define D 100
# define ESC 65307

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
    void    *addr;
    int     w_width;
    int     w_height;
    int     index;
    int     movement;
    int     collectible;
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
void 	ft_full_map_error_check(t_data *data);
int     ft_get_height(t_data *data);
int     ft_get_width(t_data *data);
int 	ft_is_rectangular(t_data *data);
int	    ft_is_same_length(t_data *data);
int     ft_is_ones_only(char *line);
int     ft_is_one_ended(char *line);
int 	ft_is_possible_character(char *line);
void 	ft_cep(t_data *data, int c, int e, int p);
void	get_coordinates(t_data *data);
int	    quit_game(void *param);
void	ft_listclear(t_list **list);
void	lstdelone(t_list **list);
void	ft_freetab(char **tab);
int	deal_key(int key, void *param);
void	ft_free_data_and_exit(t_data *data);
void    ft_error_output(t_data *data, int err);

#endif