/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebatist <hebatist@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:03:17 by hebatist          #+#    #+#             */
/*   Updated: 2025/02/12 01:11:23 by hebatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_map_checkings(char **map, int length, int height)
{
	ft_printf("invalid walls? -> %d\n", map_has_valid_walls(
			map, length, height));
	ft_printf("invalid chars -> %d\n", invalid_chars_quant(map));
	ft_printf("exit quantity -> %d\n", exit_quant(map));
	ft_printf("player quantity -> %d\n", player_quant(map));
	ft_printf("collec quantity -> %d\n", collec_quant(map));
	ft_printf("player position -> [%d][%d]\n",
		get_player_pos(map)[0],
		get_player_pos(map)[1]);
}

void	print_t_map_checkings(t_map *st_map)
{
	ft_printf("exit found? -> %d\n", st_map->exit_found);
	ft_printf("gettable collecs -> %d\n", st_map->gettable_collecs);
	print_map(st_map->map, st_map->height);
	print_map(st_map->map_copy, st_map->height);
}

void	print_map(char **map, int height)
{
	int	i;

	i = -1;
	while (++i < height)
		ft_printf("%s\n", map[i]);
}
