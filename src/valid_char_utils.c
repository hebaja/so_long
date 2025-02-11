/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_char_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebatist <hebatist@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:03:36 by hebatist          #+#    #+#             */
/*   Updated: 2025/02/11 17:03:38 by hebatist         ###   ########.fr       */
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
	while (++i < length -  1)
		if (line[i] != '0' && line[i] != '1' && line[i] != 'P' && line[i] != 'C' && line[i] != 'E')
			res++;
	return (res);
}

int	map_has_valid_walls(char **map, int length, int height)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < length - 1)
		if (map[0][i] != '1')
			return (0);
	i = 0;
	while(++i < height - 1)
	{
		if (map[i][0] != '1' || map[i][length - 2] != '1')
			return (0);
	}
	while (++j < length - 1)
		if (map[i][j] != '1')
			return (0);
	return (1);
}
