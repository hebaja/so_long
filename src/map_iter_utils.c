/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iter_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebatist <hebatist@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:02:42 by hebatist          #+#    #+#             */
/*   Updated: 2025/02/12 00:56:36 by hebatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	map_iter(char **map, int (*cmp)(char *line))
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (map[++i] != NULL)
	{
		res += cmp(map[i]);
		if (map[i + 2] == NULL)
			break ;
	}
	return (res);
}

int	map_iter_char(char **map, char c, int (*cmp)(char *line, char c))
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (map[++i] != NULL)
	{
		res += cmp(map[i], c);
		if (map[i + 2] == NULL)
			break ;
	}
	return (res);
}

int	check_char_quant(char *line, char c)
{
	int	i;
	int	res;
	int	length;

	i = 0;
	res = 0;
	length = ft_strlen(line);
	while (++i < length - 1)
		if (line[i] == c)
			res++;
	return (res);
}

int	get_char_y_pos(char *line, char c)
{
	int	y;
	int	length;

	y = 0;
	length = ft_strlen(line);
	while (++y < length - 1)
	{
		if (line[y] == c)
			return (y);
	}
	return (-1);
}
