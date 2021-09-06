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


// int	deal_key(int key, t_data *data)
// {
// 	ft_putchar('X');
// 	return (0);
// }

int		main(int argc, char **argv)
{
	t_data *data;
	int i;
	char *line;
	int fd;
	int ret;
	int countline;

	i = 0;

	(void) argc;
	// (void) argv;

 	data = (t_data*)malloc(sizeof(t_data));
	
	data->width = ft_get_width(argv[1]);
	ft_read_map(argv[1], data);
	while (data->map_tab[i] != NULL)
	{
		for (int j = 0; j <= data->width; j++)
			printf ("%c", data->map_tab[i][j]);
		printf("\n");
		i++;
	}
	
	// printf ("%d\n", (ft_check_length(data)));
	i = 0;
	while (data->map_tab[i] != NULL)
	{
		printf (" line : %d\n", (ft_check_wall(*data->map_tab)));
		printf("\n");
		i++;
	}
	
	
	countline = 1;
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
	system("leaks a.out | grep leaked\n"); 

	return (0);
}
