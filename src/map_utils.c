#include "../include/so_long.h"

void	print_map(char **map, int height)
{
	int	i;

	i = -1;
	while (++i < height)
		ft_printf("%s\n", map[i]);
}

void	open_map_error(void)
{
	perror("Map file not found");
	exit(EXIT_FAILURE);
}

int	get_map_length()
{
	size_t	len;
	char	*str;
	int	fd;

	fd = open("maps/map.txt", O_RDONLY);
	if (fd < 0)
		open_map_error();
	str = get_next_line(fd);
	len = ft_strlen(str);
	while (str != NULL)
	{
		free(str);
		str = get_next_line(fd);
		if (str != NULL && len != ft_strlen(str))
			return (-1);
	}
	free (str);
	return (len);
}

 int	get_map_height()
{
	size_t	len;
	char	*str;
	int	fd;

	len = 0;
	fd = open("maps/map.txt", O_RDONLY);
	if (fd < 0)
		open_map_error();
	str = get_next_line(fd);
	while (str != NULL)
	{
		free(str);
		str = get_next_line(fd);
		len++;
	}
	return (len);
}
