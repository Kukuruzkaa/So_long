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

	i = 0;
	j = 0;

	(void) argc;
	// int* number;

	// number = (int*)malloc(sizeof(int));
 	data = (t_data*)malloc(sizeof(t_data));
	
	ft_read_map(argv[1], data);
	while (i < data->height)
	{
		while (j < data->width)
		{
			printf ("%d\n", data->map_tab[i][j]);
			j++;
		}
		i++;
	}


	return (0);
}
