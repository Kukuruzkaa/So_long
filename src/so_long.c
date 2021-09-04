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
	int j;
	char *line;
	int fd;
	int ret;
	int countline;

	i = 0;
	j = 0;

	(void) argc;
	// (void) argv;
	// int* number;

	// number = (int*)malloc(sizeof(int));
 	data = (t_data*)malloc(sizeof(t_data));
	
	ft_read_map(argv[1], data);
	
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
	return 0;
}
	
	// while (i < data->height)
	// {
	// 	while (j < data->width)
	// 	{
	// 		printf ("%d\n", data->map_tab[i][j]);
	// 		j++;
	// 	}
	// 	i++;
	// }


// 	return (0);
// }