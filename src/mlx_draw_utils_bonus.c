#include "../include/so_long.h"
#include "../minilibx-linux/mlx.h"

void	put_moves_on_screen(t_mlx *st_mlx)
{
	char	*move_qt;

	move_qt = ft_itoa(st_mlx->st_map->moves);
	mlx_string_put(st_mlx->mlx, st_mlx->win, 13, 13, 12000284, move_qt);
	free(move_qt);
}
