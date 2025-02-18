#include "../include/so_long.h"
#include "../minilibx-linux/mlx.h"

int     clean(t_mlx *st_mlx)
{
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

int	build_mlx(t_mlx *st_mlx, t_map_data *st_map_data)
{
	// TODO need to check and return 0 case file not found
	st_mlx->st_map = build_st_map(st_map_data);
	validate_path(st_mlx->st_map);
	gameplay_validation(st_mlx->st_map);

	st_mlx->mlx = mlx_init();
	st_mlx->win = mlx_new_window(st_mlx->mlx, 64 * (st_map_data->length -1), 64 * st_map_data->height , "so_long"); // 13 x 10
	st_mlx->tile_img = mlx_xpm_file_to_image(st_mlx->mlx, "./assets/tile.xpm", &st_mlx->img_width, &st_mlx->img_height);
	st_mlx->wall_img = mlx_xpm_file_to_image(st_mlx->mlx, "./assets/oak_tree_crop.xpm", &st_mlx->img_width, &st_mlx->img_height);
	st_mlx->player_img = mlx_xpm_file_to_image(st_mlx->mlx, "./assets/tux_7.xpm", &st_mlx->img_width, &st_mlx->img_height);
	st_mlx->collec_img = mlx_xpm_file_to_image(st_mlx->mlx, "./assets/ubuntu.xpm", &st_mlx->img_width, &st_mlx->img_height);
	st_mlx->exit_img = mlx_xpm_file_to_image(st_mlx->mlx, "./assets/exit_1.xpm", &st_mlx->img_width, &st_mlx->img_height);
	st_mlx->img_width = 64;
	st_mlx->img_height = 64;

	
	free(st_map_data);

	return (1);
}

int     handle_input(int keycode, t_mlx *st_mlx)
{
	if (keycode == 119 || keycode == 65362)
	{
		move(st_mlx->st_map, -1, 1);
		print_map_checkings(st_mlx->st_map->map, st_mlx->st_map->length, st_mlx->st_map->height);
		draw_screen(st_mlx, st_mlx->st_map);
	}
	if (keycode == 115 || keycode == 65364)
	{
		move(st_mlx->st_map, 1, 1);
		print_map_checkings(st_mlx->st_map->map, st_mlx->st_map->length, st_mlx->st_map->height);
		draw_screen(st_mlx, st_mlx->st_map);
	}
	if (keycode == 97 || keycode == 65361)
	{
		move(st_mlx->st_map, -1, 0);
		print_map_checkings(st_mlx->st_map->map, st_mlx->st_map->length, st_mlx->st_map->height);
		draw_screen(st_mlx, st_mlx->st_map);
	}
	if (keycode == 100 || keycode == 65363)
	{
		move(st_mlx->st_map, 1, 0);
		print_map_checkings(st_mlx->st_map->map, st_mlx->st_map->length, st_mlx->st_map->height);
		draw_screen(st_mlx, st_mlx->st_map);
	}
	if (keycode == 65307 || st_mlx->st_map->scaped)
	{
		clean(st_mlx);
		exit(EXIT_SUCCESS);
	}
	printf("The key %d has been pressed\n", keycode);
	return (0);
}
