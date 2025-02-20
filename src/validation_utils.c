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
	while (++i < length - 1)
		if (line[i] != '0' && line[i] != '1' && line[i] != 'P'
			&& line[i] != 'C' && line[i] != 'E')
			res++;
	return (res);
}

int	map_has_valid_walls(char **map, int length, int height)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	if (height == 1)
		return (0);
	while (++i < length - 1)
		if (map[0][i] != '1')
			return (0);
	i = 0;
	
	while (++i < height - 1)
	{
		if (map[i][0] != '1' || map[i][length - 2] != '1')
			return (0);
	}
	while (++j < length - 1)
		if (map[i][j] != '1')
			return (0);
	return (1);
}

void	validate_path(t_map *st_map, int x, int y, int is_init)
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
		validate_path(st_map, x - 1, y, 0);
	if (y + 1 < st_map->length - 1)
		validate_path(st_map, x, y + 1, 0);
	if (x + 1 < st_map->height - 1)
		validate_path(st_map, x + 1, y, 0);
	if (y - 1 >= 0)
		validate_path(st_map, x, y - 1, 0);
}

int	get_map_length(char *map_name)
{
	int			fd;
	char		*str;
	size_t		len;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		return (-1);
	str = get_next_line(fd);
	if (str == NULL)
		return (-2);
	len = ft_strlen(str);
	while (str != NULL)
	{
		free(str);
		str = get_next_line(fd);
		if (str != NULL && len != ft_strlen(str))
		{
			free(str);
			close(fd);
			return (-2);
		}
	}
	free (str);
	close(fd);
	return (len);
}

int	get_map_height(char *map_name)
{
	int			fd;
	char		*str;
	size_t		len;

	len = 0;
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		return (-1);
	str = get_next_line(fd);
	if (str == NULL)
		return (-2);
	while (str != NULL)
	{
		free(str);
		str = get_next_line(fd);
		len++;
	}
	return (len);
}
