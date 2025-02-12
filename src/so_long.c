/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebatist <hebatist@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:03:24 by hebatist          #+#    #+#             */
/*   Updated: 2025/02/12 01:13:01 by hebatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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

int	main(int argc, char **argv)
{
	t_map	*st_map;

	if (argc == 2)
	{
		st_map = validate_and_build_t_map(argv[1]);
		print_map_checkings(st_map->map, st_map->length, st_map->height);
		validate_path(st_map);
		print_t_map_checkings(st_map);
		gameplay_validation(st_map);
		// TODO insert gameplay here
		clean_t_map(st_map, 0);
	}
	else
	{
		ft_putstr_fd("Error\nYou must insert a map path\n", 2);
		exit(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
