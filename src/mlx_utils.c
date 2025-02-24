/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebatist <hebatist@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:35:08 by hebatist          #+#    #+#             */
/*   Updated: 2025/02/18 11:35:10 by hebatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	clean(t_mlx *st_mlx)
{
	clean_t_map(st_mlx->st_map, 0);
	if (st_mlx->tile_img)
		mlx_destroy_image(st_mlx->mlx, st_mlx->tile_img);
	if (st_mlx->wall_img)
		mlx_destroy_image(st_mlx->mlx, st_mlx->wall_img);
	if (st_mlx->player_img)
		mlx_destroy_image(st_mlx->mlx, st_mlx->player_img);
	if (st_mlx->collec_img)
		mlx_destroy_image(st_mlx->mlx, st_mlx->collec_img);
	if (st_mlx->exit_img)
		mlx_destroy_image(st_mlx->mlx, st_mlx->exit_img);
	mlx_destroy_window(st_mlx->mlx, st_mlx->win);
	mlx_destroy_display(st_mlx->mlx);
	free(st_mlx->mlx);
	return (0);
}

int	build_mlx(t_mlx *st_mlx, t_map *st_map, char *map_name)
{
	st_mlx->img_size = IMG_SIZE;
	st_mlx->st_map = build_st_map(map_name);
	st_mlx->mlx = mlx_init();
	st_mlx->win = mlx_new_window(st_mlx->mlx,
			st_mlx->img_size * (st_map->length),
			st_mlx->img_size * st_map->height, "so_long");
	st_mlx->tile_img = mlx_xpm_file_to_image(st_mlx->mlx,
			"./assets/tile.xpm", &st_mlx->img_size, &st_mlx->img_size);
	st_mlx->wall_img = mlx_xpm_file_to_image(st_mlx->mlx,
			"./assets/tree.xpm", &st_mlx->img_size, &st_mlx->img_size);
	st_mlx->player_img = mlx_xpm_file_to_image(st_mlx->mlx,
			"./assets/tux.xpm", &st_mlx->img_size, &st_mlx->img_size);
	st_mlx->collec_img = mlx_xpm_file_to_image(st_mlx->mlx,
			"./assets/debian.xpm", &st_mlx->img_size, &st_mlx->img_size);
	st_mlx->exit_img = mlx_xpm_file_to_image(st_mlx->mlx,
			"./assets/exit.xpm", &st_mlx->img_size, &st_mlx->img_size);
	if (st_mlx->tile_img == NULL || st_mlx->wall_img == NULL
		|| st_mlx->player_img == NULL || st_mlx->collec_img == NULL
		|| st_mlx->exit_img == NULL)
		return (0);
	return (1);
}

void	draw_move(t_mlx *st_mlx, int direction, int is_vertical)
{
	move(st_mlx->st_map, direction, is_vertical);
	draw_screen(st_mlx, st_mlx->st_map);
}

int	handle_input(int keycode, t_mlx *st_mlx)
{
	if (keycode == 119 || keycode == 65362)
		draw_move(st_mlx, -1, 1);
	if (keycode == 115 || keycode == 65364)
		draw_move(st_mlx, 1, 1);
	if (keycode == 97 || keycode == 65361)
		draw_move(st_mlx, -1, 0);
	if (keycode == 100 || keycode == 65363)
		draw_move(st_mlx, 1, 0);
	if (keycode == 65307 || st_mlx->st_map->scaped)
	{
		clean(st_mlx);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
