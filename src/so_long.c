/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebatist <hebatist@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:03:24 by hebatist          #+#    #+#             */
/*   Updated: 2025/02/12 01:13:01 by hebatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../minilibx-linux/mlx.h"

void	gameplay_validation(t_map *st_map)
{
	int	collec_qt;

	collec_qt = collec_quant(st_map->map);
	if (st_map->exit_found != 1
		|| st_map->gettable_collecs != collec_qt
		|| !st_map->exit_found)
	{
		ft_putstr_fd("Error\nInvalid map\n", 2);
		clean_t_map(st_map, 1);
	}
}

int     clean(t_mlx *st_mlx)
{
	// clean_map(st_mlx->map, st_mlx->map_height);
	clean_t_map(st_mlx->st_map, 0);
	mlx_destroy_image(st_mlx->mlx, st_mlx->tile_img);
	mlx_destroy_image(st_mlx->mlx, st_mlx->wall_img);
	mlx_destroy_image(st_mlx->mlx, st_mlx->player_img);
	mlx_destroy_image(st_mlx->mlx, st_mlx->collec_img);
	mlx_destroy_image(st_mlx->mlx, st_mlx->exit_img);
	mlx_destroy_window(st_mlx->mlx, st_mlx->win);
	mlx_destroy_display(st_mlx->mlx);
	free(st_mlx->mlx);
	return (0);
}

int	close_window(t_mlx *st_mlx)
{
	clean(st_mlx);
	exit(EXIT_SUCCESS);
}

int	build_mlx(t_mlx *st_mlx, t_map *st_map)
{
	// TODO need to check and return 0 case file not found
	st_mlx->mlx = mlx_init();
	st_mlx->win = mlx_new_window(st_mlx->mlx, 64 * (st_map->length -1), 64 * st_map->height , "so_long"); // 13 x 10
	st_mlx->tile_img = mlx_xpm_file_to_image(st_mlx->mlx, "./assets/tile.xpm", &st_mlx->img_width, &st_mlx->img_height);
	st_mlx->wall_img = mlx_xpm_file_to_image(st_mlx->mlx, "./assets/oak_tree_crop.xpm", &st_mlx->img_width, &st_mlx->img_height);
	st_mlx->player_img = mlx_xpm_file_to_image(st_mlx->mlx, "./assets/tux_7.xpm", &st_mlx->img_width, &st_mlx->img_height);
	st_mlx->collec_img = mlx_xpm_file_to_image(st_mlx->mlx, "./assets/ubuntu.xpm", &st_mlx->img_width, &st_mlx->img_height);
	st_mlx->exit_img = mlx_xpm_file_to_image(st_mlx->mlx, "./assets/exit_1.xpm", &st_mlx->img_width, &st_mlx->img_height);
	st_mlx->img_width = 64;
	st_mlx->img_height = 64;

	t_map	*st_map_copy;

	st_map_copy = (t_map *)malloc(sizeof(t_map) * 1);
	st_map_copy->height = st_map->height;
	st_map_copy->length = st_map->length;
	st_map_copy->map_copy = NULL;
	st_map_copy->gettable_collecs = 0;
	st_map_copy->collected_collecs = 0;
	st_map_copy->moves = 0;
	st_map_copy->exit_found = 0;
	st_map_copy->scaped = 0;
	st_map_copy->map = copy_map(st_map);
	st_map_copy->map_copy = copy_map(st_map);

	
	validate_path(st_map_copy);
	gameplay_validation(st_map_copy);


	st_mlx->st_map = st_map_copy;

	return (1);
}

int     handle_input(int keycode, t_mlx *st_mlx)
{
	if (keycode == 119 || keycode == 65362) //Down
	{
		move(st_mlx->st_map, -1, 1);
		// paint_screen(st_mlx, 64 * st_mlx->st_map->length -1, 64 * st_mlx->st_map->height);
		// print_map(st_mlx->st_map->map, st_mlx->st_map->height);
		print_map_checkings(st_mlx->st_map->map, st_mlx->st_map->length, st_mlx->st_map->height);
		// print_t_map_checkings(st_mlx->st_map);
		draw_screen(st_mlx, st_mlx->st_map);
	}
	if (keycode == 115 || keycode == 65364) //Down
	{
		move(st_mlx->st_map, 1, 1);
		// paint_screen(st_mlx, 64 * st_mlx->st_map->length -1, 64 * st_mlx->st_map->height);
		// print_map(st_mlx->st_map->map, st_mlx->st_map->height);
		// draw_screen(st_mlx, st_mlx->st_map);
		print_map_checkings(st_mlx->st_map->map, st_mlx->st_map->length, st_mlx->st_map->height);
		// print_t_map_checkings(st_mlx->st_map);
		draw_screen(st_mlx, st_mlx->st_map);
	}
	if (keycode == 97 || keycode == 65361) //Down
	{
		move(st_mlx->st_map, -1, 0);
		// paint_screen(st_mlx, 64 * st_mlx->st_map->length -1, 64 * st_mlx->st_map->height);
		// print_map(st_mlx->st_map->map, st_mlx->st_map->height);
		print_map_checkings(st_mlx->st_map->map, st_mlx->st_map->length, st_mlx->st_map->height);
		// print_t_map_checkings(st_mlx->st_map);
		draw_screen(st_mlx, st_mlx->st_map);
	}
	if (keycode == 100 || keycode == 65363) //Down
	{
		move(st_mlx->st_map, 1, 0);
		// paint_screen(st_mlx, 64 * st_mlx->st_map->length -1, 64 * st_mlx->st_map->height);
		// print_map(st_mlx->st_map->map, st_mlx->st_map->height);
		print_map_checkings(st_mlx->st_map->map, st_mlx->st_map->length, st_mlx->st_map->height);
		// print_t_map_checkings(st_mlx->st_map);
		draw_screen(st_mlx, st_mlx->st_map);
	}
	if (keycode == 65307)
	{
		clean(st_mlx);
		exit(EXIT_SUCCESS);
	}
	printf("The key %d has been pressed\n", keycode);
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx   st_mlx;
	t_map	*st_map;

	if (argc == 2)
	{
		st_map = validate_and_build_t_map(argv[1]);

		build_mlx(&st_mlx, st_map);

		// print_map_checkings(st_map->map, st_map->length, st_map->height);
		validate_path(st_mlx.st_map);
		// print_t_map_checkings(st_map);
		gameplay_validation(st_mlx.st_map);

		// TODO insert gameplay here
		// print_st_map(st_mlx.st_map);

		paint_screen(&st_mlx, 64 * st_mlx.st_map->length -1, 64 * st_mlx.st_map->height);
		draw_screen(&st_mlx, st_mlx.st_map);
		clean_t_map(st_map, 0);
		mlx_hook(st_mlx.win, 2, 1L<<0, handle_input, &st_mlx);
		mlx_hook(st_mlx.win, 17, 0, close_window, &st_mlx);
		mlx_loop(st_mlx.mlx);
		clean(&st_mlx);
		

		// raw_play(st_mlx.st_map); /* TODO remove this later*/
		// load_screen(st_map);

		// clean_t_map(st_map, 0);
	}
	else
	{
		ft_putstr_fd("Error\nYou must insert a map path\n", 2);
		exit(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
