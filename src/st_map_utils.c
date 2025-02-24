/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebatist <hebatist@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:03:31 by hebatist          #+#    #+#             */
/*   Updated: 2025/02/17 18:50:27 by hebatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**alloc_map_mem(int height)
{
	char	**map;

	map = ft_calloc(height + 1, sizeof(char *));
	if (map == NULL)
		return (NULL);
	return (map);
}

char	**copy_map(t_map *st_map)
{
	int			i;
	char		**map_copy;

	i = -1;
	map_copy = alloc_map_mem(st_map->length);
	while (++i < st_map->height)
	{
		map_copy[i] = ft_calloc(st_map->length, sizeof(char));
		if (map_copy[i] == NULL)
			clean_map(map_copy, st_map->height);
	}
	i = -1;
	while (st_map->map[++i])
		ft_strlcpy(map_copy[i], st_map->map[i], st_map->length);
	return (map_copy);
}

void	validate_st_map(t_map *st_map)
{
	if (st_map->length < 0 || !st_map->is_walls_valid
		|| st_map->invalid_chars_qt > 0 || st_map->exit_qt != 1
		|| st_map->player_qt != 1 || st_map->collec_qt < 1)
	{
		ft_putstr_fd("Error\nIvalid map\n", 2);
		clean_t_map(st_map, 1);
	}
}

t_map	*build_st_map(char *map_name)
{
	t_map	*st_map;

	st_map = validate_and_init_st_map(map_name);
	st_map->exit_found = 0;
	st_map->gettable_collecs = 0;
	st_map->collected_collecs = 0;
	st_map->moves = 0;
	st_map->scaped = 0;
	st_map->is_walls_valid = map_has_valid_walls(st_map);
	st_map->invalid_chars_qt = invalid_chars_quant(st_map->map);
	st_map->exit_qt = exit_quant(st_map->map);
	st_map->player_qt = player_quant(st_map->map);
	st_map->collec_qt = collec_quant(st_map->map);
	get_player_pos(st_map);
	validate_st_map(st_map);
	check_pathing(st_map, st_map->pos_x, st_map->pos_y, 1);
	gameplay_validation(st_map);
	return (st_map);
}
