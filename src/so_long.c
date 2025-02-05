#include "../include/so_long.h"

int	main()
{
	char	**map;
	int	length;
	int	height;

	length = get_map_length();
	height = get_map_height();
	ft_printf("lenght -> %d, height -> %d\n", length, height);
	map = get_map_content(length, height);
	print_map(map, height);
	clean_map(map, height, 0);

	return (EXIT_SUCCESS);
}
