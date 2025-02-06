#include "../include/so_long.h"

char	**get_map_content(char *map_name, int length, int height)
{
	int	fd;
	int	i;
	char	*str;
	char	**map;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		open_map_error();
	map = alloc_map_mem(height);
	i = -1;
	while (++i < height)
	{
		map[i] = ft_calloc(length, sizeof(char *));
		if (map[i] == NULL)
			clean_map(map, height, 1);
	}
	i = 0;
	str = get_next_line(fd);
	while (str != NULL)
	{
		ft_strlcpy(map[i++], str, length);
		free(str);
		str = get_next_line(fd);
	}
	return (map);
}

char	**alloc_map_mem(int	height)
{
	char	**map;

	map = ft_calloc(height, sizeof(char **));
	if (map == NULL)
		exit(EXIT_FAILURE);
	return (map);
}

void	clean_map(char **map, int height, int is_failure)
{
	int	i;

	i = -1;
	while (++i < height)
		free(map[i]);
	free(map);
	map = NULL;
	if (is_failure)
		exit(EXIT_FAILURE);
}

