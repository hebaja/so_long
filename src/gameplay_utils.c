#include "../include/so_long.h"

int	is_char(char pos, char check)
{
	int	res;

	res = pos == check;
	return (res);
}

int	is_all_collected(t_map *st_map)
{
	int	res;

	res = (st_map->gettable_collecs - st_map->collected_collecs) == 0;
	return (res);
}

void	gameplay_validation(t_map *st_map)
{
	int	collec_qt;

	collec_qt = collec_quant(st_map->map);
	if (st_map->exit_found != 1
		|| st_map->gettable_collecs != collec_qt
		|| !st_map->exit_found)
	{
		ft_putstr_fd("Error\nInvalid map\n", 2);
		clean_t_map(st_map, 1);
	}
}

void	get_next_pos(t_map *st_map, int direction, int is_vertical)
{
	if (is_vertical)
	{	
		st_map->next_x = st_map->pos_x + direction;
		st_map->next_y = st_map->pos_y;
	}
	else
	{
		st_map->next_x = st_map->pos_x;
		st_map->next_y = st_map->pos_y + direction;
	}
	return (next_pos);
}
