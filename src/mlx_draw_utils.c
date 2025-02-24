/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebatist <hebatist@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:24:31 by hebatist          #+#    #+#             */
/*   Updated: 2025/02/18 11:24:34 by hebatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	put_assets(t_mlx *st_mlx, char c, int w, int h)
{
	if (c == '1')
		mlx_put_image_to_window(
			st_mlx->mlx, st_mlx->win, st_mlx->wall_img, w, h);
	if (c == 'P')
		mlx_put_image_to_window(
			st_mlx->mlx, st_mlx->win, st_mlx->player_img, w, h);
	if (c == 'C')
		mlx_put_image_to_window(
			st_mlx->mlx, st_mlx->win, st_mlx->collec_img, w, h);
	if (c == 'E')
		mlx_put_image_to_window(
			st_mlx->mlx, st_mlx->win, st_mlx->exit_img, w, h);
	if (c == '0')
		mlx_put_image_to_window(
			st_mlx->mlx, st_mlx->win, st_mlx->tile_img, w, h);
}

void	draw_screen(t_mlx *st_mlx, t_map *st_map)
{
	int		x;
	int		y;
	int		w;
	int		h;

	x = -1;
	h = 0;
	while (++x < st_map->height)
	{
		y = -1;
		w = 0;
		while (++y < st_map->length)
		{
			put_assets(st_mlx, st_map->map[x][y], w, h);
			w += IMG_SIZE;
		}
		h += IMG_SIZE;
	}
}
