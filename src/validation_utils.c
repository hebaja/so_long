/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_char_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebatist <hebatist@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:03:36 by hebatist          #+#    #+#             */
/*   Updated: 2025/02/12 01:14:06 by hebatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_valid_chars(char *line)
{
	int	i;
	int	res;
	int	length;

	i = -1;
	res = 0;
	length = ft_strlen(line);
	while (++i < length)
		if (line[i] != '0' && line[i] != '1' && line[i] != 'P'
			&& line[i] != 'C' && line[i] != 'E')
			res++;
	return (res);
}

int	map_has_valid_walls(t_map *st_map)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	if (st_map->height == 1)
		return (0);
	while (++i < st_map->length)
		if (st_map->map[0][i] != '1')
			return (0);
	i = 0;
	while (++i < st_map->height - 1)
	{
		if (st_map->map[i][0] != '1'
			|| st_map->map[i][st_map->length - 1] != '1')
			return (0);
	}
	while (++j < st_map->length)
		if (st_map->map[i][j] != '1')
			return (0);
	return (1);
}

void	check_pathing(t_map *st_map, int x, int y, int is_init)
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
		check_pathing(st_map, x - 1, y, 0);
	if (y + 1 < st_map->length)
		check_pathing(st_map, x, y + 1, 0);
	if (x + 1 < st_map->height - 1)
		check_pathing(st_map, x + 1, y, 0);
	if (y - 1 >= 0)
		check_pathing(st_map, x, y - 1, 0);
}

void	set_copy_and_size(t_map *st_map, char *map_name, int length, int height)
{
	char	**map_copy;

	map_copy = get_map_content(map_name, length, height);
	if (map_copy == NULL)
		case_memory_allocation_error();
	st_map->map_copy = map_copy;
	st_map->length = length;
	st_map->height = height;
}

t_map	*validate_and_init_st_map(char *map_name)
{
	char	**map;
	t_map	*st_map;
	int		length;
	int		height;

	length = get_map_length(map_name);
	height = get_map_height(map_name);
	if (length < 3 || length > 56 || height < 3 || height > 30)
	{
		ft_putstr_fd("Error\nInvalid map\n", 2);
		exit(EXIT_FAILURE);
	}
	map = get_map_content(map_name, length, height);
	if (map == NULL)
		case_memory_allocation_error();
	st_map = (t_map *)malloc(sizeof(t_map));
	if (st_map == NULL)
	{
		clean_map(map, height);
		case_memory_allocation_error();
	}
	st_map->map = map;
	set_copy_and_size(st_map, map_name, length, height);
	return (st_map);
}
