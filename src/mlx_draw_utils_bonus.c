/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebatist <hebatist@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:31:07 by hebatist          #+#    #+#             */
/*   Updated: 2025/02/20 13:31:08 by hebatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../minilibx-linux/mlx.h"

void	put_moves_on_screen(t_mlx *st_mlx)
{
	char	*move_qt;

	move_qt = ft_itoa(st_mlx->st_map->moves);
	mlx_string_put(st_mlx->mlx, st_mlx->win, 15, 15, 12000284, move_qt);
	free(move_qt);
}
