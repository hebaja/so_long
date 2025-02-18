/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebatist <hebatist@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:02:26 by hebatist          #+#    #+#             */
/*   Updated: 2025/02/17 21:30:50 by hebatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	exit_quant(char **map)
{
	int	res;

	res = map_iter_char(map, 'E', check_char_quant);
	return (res);
}

int	player_quant(char **map)
{
	int	res;

	res = map_iter_char(map, 'P', check_char_quant);
	return (res);
}

int	collec_quant(char **map)
{
	int	res;

	res = map_iter_char(map, 'C', check_char_quant);
	return (res);
}

int	invalid_chars_quant(char **map)
{
	int	res;

	res = map_iter(map, check_valid_chars);
	return (res);
}

int	is_char(char pos, char check)
{
	int	res;

	res = pos == check;
	return (res);
}
