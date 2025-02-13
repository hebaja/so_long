#include "../include/so_long.h"

/*
	*
	* This file is just for
	* testing purposes
	*
*/

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

int	*get_next_pos(int *player_pos, int direction, int is_vertical)
{
	int	*next_pos;

	next_pos = (int *)malloc(sizeof(int) * 2);
	if (is_vertical)
	{	
		next_pos[0] = player_pos[0] + direction;
		next_pos[1] = player_pos[1];
	}
	else
	{
		next_pos[0] = player_pos[0];
		next_pos[1] = player_pos[1] + direction;
	}
	return (next_pos);
}

void	move(t_map *st_map, int direction, int is_vertical)
{
	int *player_pos;
	int	*next_pos;

	player_pos = get_player_pos(st_map->map);
	next_pos = get_next_pos(player_pos, direction, is_vertical);
	if (!is_char(st_map->map[next_pos[0]][next_pos[1]], '1'))
	{
		if (is_char(st_map->map[next_pos[0]][next_pos[1]], 'E'))
		{
			if (is_all_collected(st_map))
				st_map->scaped = 1;
			else
			{
				free(next_pos);
				return ;
			}
		}
		if (is_char(st_map->map[next_pos[0]][next_pos[1]], 'C'))
			st_map->collected_collecs++;
		st_map->map[player_pos[0]][player_pos[1]] = '0';
		st_map->map[next_pos[0]][next_pos[1]] = 'P';
		st_map->moves++;
		free(next_pos);
	}
}

void	raw_play(t_map *st_map)
{
	char	str[2];

	scanf("%s", str);
	while (ft_strncmp(str, "q", 2) != 0)
	{
		if (ft_strncmp(str, "w", 2) == 0)
			move(st_map, -1, 1);
		if (ft_strncmp(str, "s", 2) == 0)
			move(st_map, 1, 1);
		if (ft_strncmp(str, "a", 2) == 0)
			move(st_map, -1, 0);
		if (ft_strncmp(str, "d", 2) == 0)
			move(st_map, 1, 0);
		print_st_map(st_map);
		if (st_map->scaped)
			break ;
		scanf("%s", str);
	}
}
