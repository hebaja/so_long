/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_mem_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebatist <hebatist@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:02:14 by hebatist          #+#    #+#             */
/*   Updated: 2025/02/12 00:41:43 by hebatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	clean_map(char **map, int height)
{
	int	i;

	i = -1;
	while (++i < height)
		free(map[i]);
	free(map);
	map = NULL;
}

void	clean_t_map(t_map *st_map, int is_failure)
{
	clean_map(st_map->map, st_map->height);
	if (st_map->map_copy != NULL)
		clean_map(st_map->map_copy, st_map->height);
	free(st_map);
	st_map = NULL;
	if (is_failure)
		exit(EXIT_FAILURE);
}

void	case_memory_allocation_error(void)
{
	ft_putstr_fd("Error\nProblem allocating memory\n", 2);
	exit(EXIT_FAILURE);
}
