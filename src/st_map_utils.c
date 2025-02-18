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

void	open_map_error(void)
{
	perror("Error\nMap file not found");
	exit(EXIT_FAILURE);
}

char  **copy_map(t_map *st_map)
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

t_map	*build_st_map(t_map_data *st_map_data)
{
	t_map	*st_map;

	st_map = (t_map *)malloc(sizeof(t_map));
	if (st_map == NULL)
	{
		clean_map(st_map_data->map, st_map_data->height);
		exit(EXIT_FAILURE);
	}
	st_map->length = st_map_data->length;
	st_map->height = st_map_data->height;
	st_map->map = st_map_data->map;
	st_map->player_pos = get_player_pos(st_map_data->map);
	st_map->exit_found = 0;
	st_map->gettable_collecs = 0;
	st_map->collected_collecs = 0;
	st_map->moves = 0;
	st_map->scaped = 0;
	st_map->map_copy = copy_map(st_map);
	return (st_map);
}

void	validate_t_map_data(t_map_data *st_map_data)
{
	if (st_map_data == NULL)
		exit(EXIT_FAILURE);
	if (st_map_data->length < 0 || !st_map_data->is_walls_valid
		|| st_map_data->invalid_chars_qt > 0 || st_map_data->exit_qt != 1
		|| st_map_data->player_qt != 1 || st_map_data->collec_qt < 1)
	{
		clean_t_map_data(st_map_data);
		print_inv_map_message();
	}
}
