/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_content_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebatist <hebatist@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:02:34 by hebatist          #+#    #+#             */
/*   Updated: 2025/02/11 17:02:36 by hebatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_inv_map_message(void)
{
	ft_putstr_fd("Error\nInvalid map\n", 2);
	exit(EXIT_FAILURE);
}

void	copy_map_lines(char **map, char *map_name, int length)
{
	int	fd;
	int	i;
	char	*str;

	i = 0;
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		open_map_error();
	str = get_next_line(fd);
	while (str != NULL)
	{
		ft_strlcpy(map[i++], str, length);
		free(str);
		str = get_next_line(fd);
	}
}

char	**get_map_content(char *map_name, int length, int height)
{
	int	fd;
	int	i;
	char	**map;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		open_map_error();
	map = alloc_map_mem(height);
	if (map == NULL)
		return (NULL);
	i = -1;
	while (++i < height)
	{
		map[i] = ft_calloc(length, sizeof(char));
		if (map[i] == NULL)
		{
			clean_map(map, height);
			return (NULL);
		}
	}
	copy_map_lines(map, map_name, length);
	return (map);
}

int	fill_data(t_map_data *st_map_data, char *map_name, int length, int height)
{
	char **map;

	map = get_map_content(map_name, length, height);
	if (map == NULL)
	{
		free(st_map_data);
		return (0);
	}
	st_map_data->length = length;
	st_map_data->height = height;
	st_map_data->map = map;
	st_map_data->is_walls_valid = map_has_valid_walls(map, st_map_data->length, st_map_data->height);
	st_map_data->invalid_chars_qt = invalid_chars_quant(map);
	st_map_data->exit_qt = exit_quant(map);
	st_map_data->player_qt = player_quant(map);
	st_map_data->collec_qt = collec_quant(map);
	return (1);
}

t_map_data	*build_map_data(char *map_name)
{
	t_map_data	*st_map_data;
	int	length;
	int	height;

	length = get_map_length(map_name);
	height = get_map_height(map_name);
	if (length == -1 || height == -1)
	{
		perror("Error\nProblem reading map file");
		return (NULL);
	}
	else if (length == -2 || height == -2)
	{
		ft_putstr_fd("Error\nInvalid map\n", 2);
		return (NULL);
	}
	st_map_data = (t_map_data *)malloc(sizeof(t_map_data));
	fill_data(st_map_data, map_name, length, height);
	return (st_map_data);
}
