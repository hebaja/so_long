#include "libft/include/libft.h"
#include <stdio.h>

int	get_map_length()
{
	size_t	len;
	char	*str;
	int	fd;

	fd = open("maps/map.txt", O_RDONLY);
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
	str = get_next_line(fd);
	while (str != NULL)
	{
		free(str);
		str = get_next_line(fd);
		len++;
	}
	return (len);
}

void	print_map(char **map, int height)
{
	int	i;

	i = -1;
	while (map[++i])
		ft_printf("%s\n", map[i]);
}

int	main()
{
	int	fd;
	char	*str;
	char	**map;
	int	length;
	int	height;
	int	i;

	fd = open("maps/map.txt", O_RDONLY);
	
	if (fd < 0)
	{
		perror("Map file not found");
		exit(EXIT_FAILURE);
	}
	
	ft_printf("%d\n", fd);

	length = get_map_length();
	height = get_map_height();
	map = ft_calloc(sizeof(char **), height);
	if (map == NULL)
		exit(EXIT_FAILURE);
	i = -1;
	while (++i < height)
	{
		map[i] = ft_calloc(sizeof(char *), length);
		if (map[i] == NULL)
			exit(EXIT_FAILURE);
	}
	i = -1;
	str = get_next_line(fd);
	while (str != NULL)
	{
		int size = ft_strlcpy(map[++i], str, length);
		free(str);
		str = get_next_line(fd);
	}

	ft_printf("lenght -> %d, height -> %d\n", length, height);
	print_map(map, height);

	return (0);
}
