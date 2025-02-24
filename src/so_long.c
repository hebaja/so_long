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

void	error_loading_mlx(t_mlx *st_mlx)
{
	ft_putstr_fd("Error\nProblem loading assets\n", 2);
	clean(st_mlx);
	exit(EXIT_FAILURE);
}

int	close_window(t_mlx *st_mlx)
{
	clean(st_mlx);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_mlx					st_mlx;
	t_map					*st_map;

	if (argc == 2)
	{
		st_map = build_st_map(argv[1]);
		if (!build_mlx(&st_mlx, st_map, argv[1]))
			error_loading_mlx(&st_mlx);
		draw_screen(&st_mlx, st_mlx.st_map);
		clean_t_map(st_map, 0);
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
