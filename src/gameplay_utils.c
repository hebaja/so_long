/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebatist <hebatist@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 01:01:41 by hebatist          #+#    #+#             */
/*   Updated: 2025/02/18 01:01:43 by hebatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	is_all_collected(t_map *st_map)
{
	int	res;

	res = (st_map->gettable_collecs - st_map->collected_collecs) == 0;
	return (res);
}

void	gameplay_validation(t_map *st_map, t_map_data *st_map_data)
{
	int	collec_qt;

	collec_qt = collec_quant(st_map->map);
	if (st_map->exit_found != 1
		|| st_map->gettable_collecs != collec_qt
		|| !st_map->exit_found)
	{
		ft_putstr_fd("Error\nInvalid map\n", 2);
		free(st_map_data);
		clean_t_map(st_map, 1);
	}
}

void	get_player_pos(t_map *st_map)
{
	int	x;
	int	y;

	x = 0;
	while (++x < st_map->height -1)
	{
		y = 0;
		while (++y < st_map->length -1)
		{
			if (st_map->map[x][y] == 'P')
			{
				st_map->pos_x = x;
				st_map->pos_y = y;
				break ;
			}
		}
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
}

void	move(t_map *st_map, int direction, int is_vertical)
{
	get_player_pos(st_map);
	get_next_pos(st_map, direction, is_vertical);
	if (!is_char(st_map->map[st_map->next_x][st_map->next_y], '1'))
	{
		if (is_char(st_map->map[st_map->next_x][st_map->next_y], 'E'))
		{
			if (is_all_collected(st_map))
				st_map->scaped = 1;
			else
				return ;
		}
		if (is_char(st_map->map[st_map->next_x][st_map->next_y], 'C'))
			st_map->collected_collecs++;
		st_map->map[st_map->pos_x][st_map->pos_y] = '0';
		st_map->map[st_map->next_x][st_map->next_y] = 'P';
		st_map->moves++;
		ft_printf("%d\n", st_map->moves);
	}
}
