/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebatist <hebatist@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 01:16:49 by hebatist          #+#    #+#             */
/*   Updated: 2025/02/12 01:25:28 by hebatist         ###   ########.fr       */
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
	int		*player_pos;
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

t_map_data	*build_map_data(char *map_name);
t_map		*build_st_map(t_map_data *st_map_data);
t_map		*validate_and_build_t_map(char *map_name);
char		**get_map_content(char *map_name, int length, int height);
char		**alloc_map_mem(int height);
void		clean_map(char **map, int heigth);
void		clean_t_map(t_map *st_map, int is_failure);
void		clean_t_map_data(t_map_data *st_map_data);
void		open_map_error(void);
void		print_map(char **map, int height);
void		print_st_map(t_map *st_map);
void		validate_path(t_map *st_map);
void		print_inv_map_message(void);
void		print_map_checkings(char **map, int length, int height);
void		print_t_map_checkings(t_map *st_map);
void		raw_play(t_map *st_map); /* TODO should be removed */
int			get_map_length(char *map_name);
int			get_map_height(char *map_name);
int			is_one_player(char **map, int length, int height);
int			invalid_chars_quant(char **map);
int			map_has_valid_walls(char **map, int length, int height);
int			exit_quant(char **map);
int			player_quant(char **map);
int			*get_player_pos(char **map);
int			collec_quant(char **map);
int			map_iter(char **map, int (*cmp)(char *line));;
int			map_iter_char(char **map, char c, int (*cmp)(char *line, char c));
int			*map_iter_pos(char **map, char c, int (*cmp)(char *line, char c));
int			check_char_quant(char *line, char c);
int			check_valid_chars(char *line);
int			get_char_y_pos(char *line, char c);

#endif
