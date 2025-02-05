#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include "../libft/include/libft.h"

char	**get_map_content(int length, int height);
char	**alloc_map_mem(int height);
void	clean_map(char **map, int height, int is_failure);
void	open_map_error(void);
void	print_map(char **map, int height);
int		get_map_length(void);
int		get_map_height(void);

#endif
