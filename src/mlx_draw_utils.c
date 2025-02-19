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
#include "../minilibx-linux/mlx.h"

void	draw_xpm_with_transparency(t_mlx *st_mlx, void *img, int x, int y)
{
	int				i;
	int				j;
	int				color;
	int				img_size;
	char			*data;

	i = -1;
	img_size = 32;
	data = mlx_get_data_addr(
			img, &st_mlx->img_bpp, &st_mlx->img_size_line, &st_mlx->img_endian);
	while (++i < img_size)
	{
		j = -1;
		while (++j < img_size)
		{
			color = *(int *)(data + (i * st_mlx->img_size_line
						+ j * (st_mlx->img_bpp / 8)));
			if ((color & 16777215) != 0)
				mlx_pixel_put(st_mlx->mlx, st_mlx->win, x + j, y + i, color);
		}
	}
}

void	paint_screen(t_mlx *st_mlx, int width, int height)
{
	int		x;
	int		y;
	int		img_size;

	x = 0;
	img_size = 32;
	while (x < height)
	{
		y = 0;
		while (y < width)
		{
			mlx_put_image_to_window(
				st_mlx->mlx, st_mlx->win, st_mlx->tile_img, y, x);
			y += img_size;
		}
		x += img_size;
	}
}

void	put_assets(t_mlx *st_mlx, char c, int w, int h)
{
	if (c == '1')
		draw_xpm_with_transparency(st_mlx, st_mlx->wall_img, w, h);
	if (c == 'P')
		draw_xpm_with_transparency(st_mlx, st_mlx->player_img, w, h);
	if (c == 'C')
		draw_xpm_with_transparency(st_mlx, st_mlx->collec_img, w, h);
	if (c == 'E')
		draw_xpm_with_transparency(st_mlx, st_mlx->exit_img, w, h);
	if (c == '0')
		draw_xpm_with_transparency(st_mlx, st_mlx->tile_img, w, h);
}

void	draw_screen(t_mlx *st_mlx, t_map *st_map)
{
	int     x;
	int		y;
	int		w;
	int		h;
	int		img_size;

	x = -1;
	h = 0;
	img_size = 32;
	while (++x < st_map->height)
	{
		y = -1;
		w = 0;
		while (++y < st_map->length)
		{
			put_assets(st_mlx, st_map->map[x][y], w, h);
			w += img_size;
		}
		h += img_size;
	}
	put_moves_on_screen(st_mlx);
}
