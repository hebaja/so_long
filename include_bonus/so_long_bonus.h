/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebatist <hebatist@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 01:26:52 by hebatist          #+#    #+#             */
/*   Updated: 2025/02/21 01:26:54 by hebatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include "../lib/libft/include/libft.h"
# include "../lib/minilibx-linux/mlx.h"

typedef struct s_map
{
	char	**map;
	char	**map_copy;
	int		length;
	int		height;
	int		pos_x;
	int		pos_y;
	int		next_x;
	int		next_y;
	int		exit_found;
	int		gettable_collecs;
	int		collected_collecs;
	int		moves;
	int		scaped;
	int		is_walls_valid;
	int		invalid_chars_qt;
	int		exit_qt;
	int		player_qt;
	int		collec_qt;
}	t_map;

typedef struct s_mlx
{
	t_map	*st_map;
	void	*mlx;
	void	*win;
	void	*tile_img;
	void	*wall_img;
	void	*player_img;
	void	*collec_img;
	void	*exit_img;
	int		img_size;
	int		img_bpp;
	int		img_size_line;
	int		img_endian;
}	t_mlx;

# define IMG_SIZE 32

t_map		*build_st_map(char *map_name);
t_map		*validate_and_init_st_map(char *map_name);
char		**get_map_content(char *map_name, int length, int height);
char		**alloc_map_mem(int height);
void		clean_map(char **map, int heigth);
void		clean_t_map(t_map *st_map, int is_failure);
void		check_pathing(t_map *st_map, int x, int y, int is_init);
void		print_inv_map_message(void);
void		load_screen(t_map *st_map);
void		gameplay_validation(t_map *st_map);
void		get_next_pos(t_map *st_map, int direction, int is_vertical);
void		move(t_map *st_map, int direction, int is_vertical);
void		get_player_pos(t_map *st_map);
void		draw_screen(t_mlx *st_mlx, t_map *st_map);
void		put_moves_on_screen(t_mlx *st_mlx);
void		case_memory_allocation_error(void);
int			is_char(char pos, char check);
int			is_all_collected(t_map *st_map);
int			build_mlx(t_mlx *st_mlx, t_map *st_map, char *map_name);
int			handle_input(int keycode, t_mlx *st_mlx);
int			clean(t_mlx *st_mlx);
int			get_map_length(char *map_name);
int			get_map_height(char *map_name);
int			is_one_player(char **map, int length, int height);
int			map_has_valid_walls(t_map *st_map);
int			invalid_chars_quant(char **map);
int			exit_quant(char **map);
int			player_quant(char **map);
int			collec_quant(char **map);
int			map_iter(char **map, int (*cmp)(char *line));;
int			map_iter_char(char **map, char c, int (*cmp)(char *line, char c));
int			check_char_quant(char *line, char c);
int			check_valid_chars(char *line);

#endif
