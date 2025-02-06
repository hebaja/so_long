#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include "../libft/include/libft.h"

char	**get_map_content(char *map_name, int length, int height);
char	**alloc_map_mem(int height);
void	clean_map(char **map, int height, int is_failure);
void	open_map_error(void);
void	print_map(char **map, int height);
int		get_map_length(char *map_name);
int		get_map_height(char *map_name);
int		is_one_player(char **map, int length, int height);

#endif
