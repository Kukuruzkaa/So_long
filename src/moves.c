#include "so_long.h"

void 	pmoves(t_data *data)
{
	int y;
	int x;

	y = data->pos_player.y;
	x = data->pos_player.x;

	if (data->map_tab[y][x] == '0' || data->map_tab[y][x] == 'C')
	{
		if (data->map_tab[y][x] == 'C')
		{
			data->map_tab[y][x] ='P';
			data->map_tab[data->pos_player.y][data->pos_player.x] = '0';
			data->collectible--;
		}
	}
	if (data->map_tab[y][x] == 'E' && data->collectible == 0)	
		quit_game(data);
}

int	deal_key(int key, void *param)
{
	t_data *data = (t_data *)param;
	if (key == LEFT || key == A)
	{	
		data->keycode = key;
		data->pos_player.x += -1;
		if (data->map_tab[data->pos_player.y][data->pos_player.x] == '1' 
		|| (data->map_tab[data->pos_player.y][data->pos_player.x] == 'E' && data->collectible > 0))
			data->pos_player.x += 1;
		else
		{
			pmoves(data);
			printf ("Current move : %d\n", data->movement);
			data->movement++;
		}
	}
	if (key == RIGHT || key == D)
	{	
		data->keycode = key;
		data->pos_player.x += 1;
		if (data->map_tab[data->pos_player.y][data->pos_player.x] == '1'
		|| (data->map_tab[data->pos_player.y][data->pos_player.x] == 'E' && data->collectible > 0))
			data->pos_player.x += -1;
		else
		{
			pmoves(data);
			printf ("Current move : %d\n", data->movement);
			data->movement++;
		}
	}	
	else if (key == UP || key == W)
	{	
		data->keycode = key;
		data->pos_player.y += -1;
		if (data->map_tab[data->pos_player.y][data->pos_player.x] == '1'
		|| (data->map_tab[data->pos_player.y][data->pos_player.x] == 'E' && data->collectible > 0))
			data->pos_player.y += 1;
		else
		{
			pmoves(data);
			printf ("Current move : %d\n", data->movement);
			data->movement++;
		}
	}	
	else if (key == DOWN || key == S)
	{
		data->keycode = key;
		data->pos_player.y += 1;
		if (data->map_tab[data->pos_player.y][data->pos_player.x] == '1'
		|| (data->map_tab[data->pos_player.y][data->pos_player.x] == 'E' && data->collectible > 0))
			data->pos_player.y += -1;
		else
		{
			pmoves(data);
			printf ("Current move : %d\n", data->movement);
			data->movement++;
		}
	}		
	else if (key == ESC)
		quit_game(data);

	if (data->width - 1 < 0)
		data->pos_player.x = 0;
	if (data->pos_player.x > data->width - 1)
		data->pos_player.x = data->width - 1;
	if (data->pos_player.x < 0)
		data->pos_player.x = 0;
	if (data->height - 1 < 0)
		data->pos_player.y = 0;
	if (data->pos_player.y > data->height - 1)
		data->pos_player.y = data->height - 1;
	if (data->pos_player.y < 0)
		data->pos_player.y = 0;
	return (0);
}

