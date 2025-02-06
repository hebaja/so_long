#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	char	**map;
	int	length;
	int	height;

	if (argc == 2)
	{	
		length = get_map_length(argv[1]);
		height = get_map_height(argv[1]);
		//ft_printf("lenght -> %d, height -> %d\n", length, height);
		map = get_map_content(argv[1], length, height);
		//print_map(map, height);
		ft_printf("%d\n", is_one_player(map, length, height));
		clean_map(map, height, 0);
	}
	else
		ft_printf("You must insert a map path");

	return (EXIT_SUCCESS);
}
