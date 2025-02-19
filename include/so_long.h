/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebatist <hebatist@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 01:16:49 by hebatist          #+#    #+#             */
/*   Updated: 2025/02/17 21:33:48 by hebatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include "../libft/include/libft.h"

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
}	t_map;

typedef struct s_map_data
{
	char	**map;
	int		length;
	int		height;
	int		is_walls_valid;
	int		invalid_chars_qt;
	int		exit_qt;
	int		player_qt;
	int		collec_qt;
}	t_map_data;

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

t_map_data	*build_map_data(char *map_name);
t_map		*build_st_map(t_map_data *st_map_data);
char		**get_map_content(char *map_name, int length, int height);
char		**alloc_map_mem(int height);
char		**copy_map(t_map *st_map);
void		clean_map(char **map, int heigth);
void		clean_t_map(t_map *st_map, int is_failure);
void		clean_t_map_data(t_map_data *st_map_data);
void		open_map_error(void);
void		validate_path(t_map *st_map, int x, int y, int is_init);
void		print_inv_map_message(void);
void		load_screen(t_map *st_map);
void		paint_screen(t_mlx *st_mlx, int width, int height);
void		gameplay_validation(t_map *st_map);
void		gameplay_validation(t_map *st_map);
void		get_next_pos(t_map *st_map, int direction, int is_vertical);
void		move(t_map *st_map, int direction, int is_vertical);
void		validate_t_map_data(t_map_data *st_map_data);
void		get_player_pos(t_map *st_map);
void		draw_screen(t_mlx *st_mlx, t_map *st_map);
int			is_char(char pos, char check);
int			is_all_collected(t_map *st_map);
int			build_mlx(t_mlx *st_mlx, t_map_data *st_map_data);
int			handle_input(int keycode, t_mlx *st_mlx);
int			close_window(t_mlx *st_mlx);
int			clean(t_mlx *st_mlx);
int			get_map_length(char *map_name);
int			get_map_height(char *map_name);
int			is_one_player(char **map, int length, int height);
int			invalid_chars_quant(char **map);
int			map_has_valid_walls(char **map, int length, int height);
int			exit_quant(char **map);
int			player_quant(char **map);
int			collec_quant(char **map);
int			map_iter(char **map, int (*cmp)(char *line));;
int			map_iter_char(char **map, char c, int (*cmp)(char *line, char c));
int			check_char_quant(char *line, char c);
int			check_valid_chars(char *line);

//bonus
void	put_moves_on_screen(t_mlx *st_mlx);

#endif
