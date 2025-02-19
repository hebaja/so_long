/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebatist <hebatist@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:03:24 by hebatist          #+#    #+#             */
/*   Updated: 2025/02/17 20:03:08 by hebatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../minilibx-linux/mlx.h"

void	error_loading_mlx(t_mlx *st_mlx, t_map_data *st_map_data)
{
	ft_putstr_fd("Error\nProblem loading assets\n", 2);
	free(st_map_data);
	st_map_data = NULL;
	clean(st_mlx);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	int						img_size;
	t_mlx					st_mlx;
	t_map_data				*st_map_data;

	if (argc == 2)
	{
		img_size = 32;
		st_map_data = build_map_data(argv[1]);
		validate_t_map_data(st_map_data);
		if (!build_mlx(&st_mlx, st_map_data))
			error_loading_mlx(&st_mlx, st_map_data);
		paint_screen(&st_mlx, img_size * st_mlx.st_map->length -1,
			img_size * st_mlx.st_map->height);
		draw_screen(&st_mlx, st_mlx.st_map);
		mlx_hook(st_mlx.win, 2, 1L << 0, handle_input, &st_mlx);
		mlx_hook(st_mlx.win, 17, 0, close_window, &st_mlx);
		mlx_loop(st_mlx.mlx);
		clean(&st_mlx);
	}
	else
	{
		ft_putstr_fd("Error\nYou must insert a valid map path\n", 2);
		exit(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
