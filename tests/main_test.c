#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../include/so_long.h"
#include "../libft/include/libft.h"
#include "criterion-2.4.2/include/criterion/assert.h"
#include "criterion-2.4.2/include/criterion/criterion.h"
#include "criterion-2.4.2/include/criterion/redirect.h"

void redirect_all_stdout(void)
{
         cr_redirect_stdout();
         cr_redirect_stderr();
}

char	**get_map(char *map_name, int length, int height)
{
	char	**map;

	map = get_map_content(map_name, length, height);
	return (map);
}

Test(so_long_suite, test_so_long_there_is_one_player, .init=redirect_all_stdout)
{
	char	**map;
	int     length;
	int     height;
	char	*map_name = "maps/map.txt";

	length = get_map_length(map_name);
	height = get_map_height(map_name);
	map = get_map(map_name, length, height);
	ft_printf("%d\n", is_one_player(map, length, height));
	const char *expected = "1\n";
	FILE *output_file = cr_get_redirected_stdout();
	char output[64];
    	fgets(output, sizeof(output), output_file);
	cr_assert_str_eq(output, expected, "Expected output %s but got %s", expected, output);
}
