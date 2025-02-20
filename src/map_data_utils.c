/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_content_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebatist <hebatist@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:02:34 by hebatist          #+#    #+#             */
/*   Updated: 2025/02/12 00:55:58 by hebatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	open_map_error(void)
{
	perror("Error\nMap file not found");
	exit(EXIT_FAILURE);
}

void	copy_map_lines(char **map, char *map_name, int length)
{
	int			fd;
	int			i;
	char		*str;

	i = 0;
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		open_map_error();
	str = get_next_line(fd);
	while (str != NULL)
	{
		ft_strlcpy(map[i++], str, length + 1);
		free(str);
		str = get_next_line(fd);
	}
}

char	**get_map_content(char *map_name, int length, int height)
{
	int			fd;
	int			i;
	char		**map;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		open_map_error();
	map = alloc_map_mem(height);
	if (map == NULL)
		return (NULL);
	i = -1;
	while (++i < height)
	{
		map[i] = ft_calloc(length + 1, sizeof(char));
		if (map[i] == NULL)
		{
			clean_map(map, height);
			return (NULL);
		}
	}
	copy_map_lines(map, map_name, length);
	return (map);
}
