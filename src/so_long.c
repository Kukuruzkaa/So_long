/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddiakova <ddiakova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 15:31:18 by ddiakova          #+#    #+#             */
/*   Updated: 2021/09/06 15:31:35 by ddiakova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	deal_key(int key, void *data)
// {
// 	ft_putchar('X');
// 	return (0);
// }

int		main(int argc, char **argv)
{
	t_data *data;
	int i;
	// char *line;
	int fd;
	// int ret;
	// int countline;
	fd = 0;
	i = 0;

	(void) argc;

 	data = (t_data*)malloc(sizeof(t_data));
	
	ft_read_map(argv[1], data);
	data->height = ft_get_height(data);
	data->width = ft_get_width(data);
	// data->mlx_ptr = mlx_init();
	// data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "so_long");
	// for (int x = 230; x < 260; x++)
	// {
	// 	for (int y = 230; y < 260; y++)
	// 	{
	// 		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0x00FF00);
	// 	}
	// }
	// mlx_key_hook(data->win_ptr, deal_key, NULL);
	// mlx_loop(data->mlx_ptr);


	while (data->map_tab[i] != NULL)
	{
		for (int j = 0; j < data->width; j++)
			printf ("%c", data->map_tab[i][j]);
		printf("\n");
		i++;
	}
	
	fd = open(argv[1], O_RDONLY, 0);
	ft_full_map_error_check(fd, data);
	close(fd);
	/*countline = 1;
	if (argc == 1)
		fd = 0;
	if (argc >= 2)
		fd = open(argv[1], O_RDONLY);
	while ((ret = get_next_line(fd, &line))==1)
    {
		printf("line %d = %s - [%d]\n", countline, line, ret);
    	free(line);
		countline++;
    }
	printf("line %d = %s - [%d]\n", countline, line, ret);
	free(line);
	printf("\nTest de LEAKS\n");
	system("leaks a.out | grep leaked\n"); */

	return (0);
}
