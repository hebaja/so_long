/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebatist <hebatist@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:03:09 by hebatist          #+#    #+#             */
/*   Updated: 2025/02/12 00:57:20 by hebatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	flood_fill(t_map *st_map, int x, int y, int is_init)
{
	if (!is_init)
	{
		if (st_map->map_copy[x][y] != '0'
			&& st_map->map_copy[x][y] != 'E'
			&& st_map->map_copy[x][y] != 'C')
			return ;
		if (st_map->map_copy[x][y] == 'E')
			st_map->exit_found = 1;
		if (st_map->map_copy[x][y] == 'C')
			st_map->gettable_collecs++;
	}
	st_map->map_copy[x][y] = 'X';
	if (x - 1 >= 0)
		flood_fill(st_map, x - 1, y, 0);
	if (y + 1 < st_map->length - 1)
		flood_fill(st_map, x, y + 1, 0);
	if (x + 1 < st_map->height - 1)
		flood_fill(st_map, x + 1, y, 0);
	if (y - 1 >= 0)
		flood_fill(st_map, x, y - 1, 0);
}

void	validate_path(t_map *st_map)
{
	int	*pos;

	pos = get_player_pos(st_map->map);
	flood_fill(st_map, pos[0], pos[1], 1);
}
