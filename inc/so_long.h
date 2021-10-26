/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 16:31:39 by ddiakova          #+#    #+#             */
/*   Updated: 2021/10/24 18:25:11 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# define D_PLAYER "./textures/down.xpm"
# define U_PLAYER "./textures/up.xpm"
# define L_PLAYER "./textures/left.xpm"
# define R_PLAYER "./textures/right.xpm"
# define COLLECTIBLE "./textures/diamond.xpm"
# define EXIT "./textures/zamok.xpm"
# define WALL "./textures/tree.xpm"
# define BACKGROUND "./textures/ground.xpm" 

# define WINDOW_SIZE_X 20
# define WINDOW_SIZE_Y 24

# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define W 119
# define S 115
# define A 97
# define D 100
# define ESC 65307
// # define UP 126
// # define DOWN 125
// # define LEFT 123
// # define RIGHT 124
// # define W 13
// # define S 1
// # define A 0
// # define D 2
// # define ESC 53

typedef struct s_texture {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		t_width;
	int		t_height;
}					t_texture;

typedef struct s_coordinates {
	int	x;
	int	y;
}					t_coordinates;

typedef struct s_data {
	int				width;
	int				height;
	char			**map_tab;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*image;
	void			*addr;
	int				w_width;
	int				w_height;
	int				index;
	int				movement;
	int				collectible;
	int				keycode;
	int				flag;
	t_texture		tex_dplayer;
	t_texture		tex_uplayer;
	t_texture		tex_lplayer;
	t_texture		tex_rplayer;
	t_texture		tex_wall;
	t_texture		tex_background;
	t_texture		tex_exit;
	t_texture		tex_collectible;
	t_coordinates	pos_player;
	t_coordinates	pos_collectible;
	t_coordinates	pos_exit;
	t_coordinates	pos_wall;
	t_coordinates	pos_back;
}							t_data;

//parsing_utils
int		ft_get_height(t_data *data);
int		ft_get_width(t_data *data);
int		ft_strcmp(char *s1, char *s2);
int		ft_check_extention(char *file);
int		ft_check_file(char *file);
int		ft_is_rectangular(t_data *data);
int		ft_is_same_length(t_data *data);
int		ft_is_ones_only(char *line);
int		ft_is_one_ended(char *line);
int		ft_is_possible_character(char *line);

//parsing
void	ft_cep(t_data *data, int c, int e, int p);
char	**ft_fill_map(t_data **data, t_list *lst);
void	ft_read_map(char *file, t_data *data);
void	ft_full_map_error_check(t_data *data);
void	ft_add_lst(t_list **lst, char *line);

//errors
void	ft_error_output(t_data *data, int err);
void	ft_file_error(int fd, char *file);

//draw_functions
void	my_mlx_sprite_put(t_data *data, t_texture *texture, int x, int y);
void	load_textures(t_data *data);
void	ft_draw_background(t_data *data);
void	ft_draw_sprites(t_data *data);
void	ft_draw_player(t_data *data, t_texture *texture);

//mlx_functions
void	file_to_image(t_data *data, t_texture *texture, char *img);
int		deal_key(int key, void *param);

//game_functions
void	get_coordinates(t_data *data);
void	data_init(t_data *data, int width, int height);
int		game_frame(void *param);
int		quit_game(void *param);

//moves_functions
void	ft_chnage_y(t_data *data, int key, int one, int two);
void	ft_chnage_x(t_data *data, int key, int one, int two);

//free_functions 
void	ft_free_line(char *line);
void	ft_freetab(char **tab);
void	ft_listclear(t_list **list);
void	lstdelone(t_list **list);
void	ft_free_data_and_exit(t_data *data);
#endif
