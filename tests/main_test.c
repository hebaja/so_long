#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
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

void redirect_stderr(void)
{
	cr_redirect_stderr();
}

char	**get_map(char *map_name, int length, int height)
{
	char	**map;

	map = get_map_content(map_name, length, height);
	return (map);
}

/*
Test(so_long_suite, test_so_long_no_map_found, .init=redirect_stderr)
{
	int status;
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		char *map_name = "maps/no_map.ber";
		int length = get_map_length(map_name);
		(void)length;
		exit(0);
	}
	waitpid(pid, &status, 0);
	cr_assert(WIFEXITED(status) && WEXITSTATUS(status) == EXIT_FAILURE, "Expected process to exit with failure");
	cr_assert_stderr_eq_str("Error\nProblem reading map file: No such file or directory\n", "Expected error message not found.");
}
*/

Test(so_long_suite, test_so_long_map_wrong_length)
{
	int     length;
	char	*map_name = "maps/map_wl.ber";
	
	length = get_map_length(map_name);
	cr_assert_eq(-2, length);
}

Test(so_long_suite, test_so_long_map_wrong_length_output, .init=redirect_stderr)
{
	int status;
	int	pid;
	int	fd[2];
	char	*rec_length;
	char	*expected = "-2";
	int	bytes;

	rec_length = malloc(sizeof(char) * 3);
	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		char *map_name = "maps/map_wl.ber";
		int length = get_map_length(map_name);
		ft_printf("%d", length);
		(void)length;
		exit(0);
	}
	bytes = read(fd[0], rec_length, 3);
	rec_length[bytes] = '\0';
	waitpid(pid, &status, 0);
	cr_assert_str_eq(rec_length, expected, "Expected output %s but got %s", expected, rec_length);
}

Test(so_long_suite, test_so_long_map_example_1, .init=redirect_all_stdout)
{
	char	**map;
	int     length;
	int     height;
	char	*map_name = "maps/map_ex1.ber";

	length = get_map_length(map_name);
	height = get_map_height(map_name);
	map = get_map(map_name, length, height);
	ft_printf("%d\n", player_quant(map));
	const char *expected = "1\n";
	FILE *output_file = cr_get_redirected_stdout();
	char output[64];
    	fgets(output, sizeof(output), output_file);
	cr_assert_str_eq(output, expected, "Expected output %s but got %s", expected, output);
}

Test(so_long_suite, test_so_long_map_example_2, .init=redirect_all_stdout)
{
	char	**map;
	int     length;
	int     height;
	char	*map_name = "maps/map_ex2.ber";

	length = get_map_length(map_name);
	height = get_map_height(map_name);
	map = get_map(map_name, length, height);
	ft_printf("%d\n", invalid_chars_quant(map));
	const char *expected = "0\n";
	FILE *output_file = cr_get_redirected_stdout();
	char output[64];
   	fgets(output, sizeof(output), output_file);
	cr_assert_str_eq(output, expected, "Expected output %s but got %s", expected, output);
}

Test(so_long_suite, test_so_long_map_has_valid_walls, .init=redirect_all_stdout)
{
	char	**map;
	int     length;
	int     height;
	char	*map_name = "maps/map_ex2.ber";

	length = get_map_length(map_name);
	height = get_map_height(map_name);
	map = get_map(map_name, length, height);
	ft_printf("%d\n", map_has_valid_walls(map, length, height));
	const char *expected = "1\n";
	FILE *output_file = cr_get_redirected_stdout();
	char output[64];
    	fgets(output, sizeof(output), output_file);
	cr_assert_str_eq(output, expected, "Expected output %s but got %s", expected, output);
}

Test(so_long_suite, test_so_long_map_has_invalid_walls_1, .init=redirect_all_stdout)
{
	char	**map;
	int     length;
	int     height;
	char	*map_name = "maps/map_ww_1.ber";

	length = get_map_length(map_name);
	height = get_map_height(map_name);
	map = get_map(map_name, length, height);
	ft_printf("%d\n", map_has_valid_walls(map, length, height));
	const char *expected = "0\n";
	FILE *output_file = cr_get_redirected_stdout();
	char output[64];
    	fgets(output, sizeof(output), output_file);
	cr_assert_str_eq(output, expected, "Expected output %s but got %s", expected, output);
}

Test(so_long_suite, test_so_long_map_has_invalid_walls_2, .init=redirect_all_stdout)
{
	char	**map;
	int     length;
	int     height;
	char	*map_name = "maps/map_ww_2.ber";

	length = get_map_length(map_name);
	height = get_map_height(map_name);
	map = get_map(map_name, length, height);
	ft_printf("%d\n", map_has_valid_walls(map, length, height));
	const char *expected = "0\n";
	FILE *output_file = cr_get_redirected_stdout();
	char output[64];
    	fgets(output, sizeof(output), output_file);
	cr_assert_str_eq(output, expected, "Expected output %s but got %s", expected, output);
}

Test(so_long_suite, test_so_long_map_has_invalid_walls_3, .init=redirect_all_stdout)
{
	char	**map;
	int     length;
	int     height;
	char	*map_name = "maps/map_ww_3.ber";

	length = get_map_length(map_name);
	height = get_map_height(map_name);
	map = get_map(map_name, length, height);
	ft_printf("%d\n", map_has_valid_walls(map, length, height));
	const char *expected = "0\n";
	FILE *output_file = cr_get_redirected_stdout();
	char output[64];
    	fgets(output, sizeof(output), output_file);
	cr_assert_str_eq(output, expected, "Expected output %s but got %s", expected, output);
}

Test(so_long_suite, test_so_long_map_has_invalid_walls_4, .init=redirect_all_stdout)
{
	char	**map;
	int     length;
	int     height;
	char	*map_name = "maps/map_ww_4.ber";

	length = get_map_length(map_name);
	height = get_map_height(map_name);
	map = get_map(map_name, length, height);
	ft_printf("%d\n", map_has_valid_walls(map, length, height));
	const char *expected = "0\n";
	FILE *output_file = cr_get_redirected_stdout();
	char output[64];
    	fgets(output, sizeof(output), output_file);
	cr_assert_str_eq(output, expected, "Expected output %s but got %s", expected, output);
}

Test(so_long_suite, test_so_long_map_has_invalid_walls_5, .init=redirect_all_stdout)
{
	char	**map;
	int     length;
	int     height;
	char	*map_name = "maps/map_ww_5.ber";

	length = get_map_length(map_name);
	height = get_map_height(map_name);
	map = get_map(map_name, length, height);
	ft_printf("%d\n", map_has_valid_walls(map, length, height));
	const char *expected = "0\n";
	FILE *output_file = cr_get_redirected_stdout();
	char output[64];
    	fgets(output, sizeof(output), output_file);
	cr_assert_str_eq(output, expected, "Expected output %s but got %s", expected, output);
}

Test(so_long_suite, test_so_long_map_has_one_exit, .init=redirect_all_stdout)
{
	char	**map;
	int     length;
	int     height;
	char	*map_name = "maps/map_ex2.ber";

	length = get_map_length(map_name);
	height = get_map_height(map_name);
	map = get_map(map_name, length, height);
	ft_printf("%d\n", exit_quant(map));
	const char *expected = "1\n";
	FILE *output_file = cr_get_redirected_stdout();
	char output[64];
    	fgets(output, sizeof(output), output_file);
	cr_assert_str_eq(output, expected, "Expected output %s but got %s", expected, output);
}

Test(so_long_suite, test_so_long_map_has_3_exit, .init=redirect_all_stdout)
{
	char	**map;
	int     length;
	int     height;
	char	*map_name = "maps/map_3E.ber";

	length = get_map_length(map_name);
	height = get_map_height(map_name);
	map = get_map(map_name, length, height);
	ft_printf("%d\n", exit_quant(map));
	const char *expected = "3\n";
	FILE *output_file = cr_get_redirected_stdout();
	char output[64];
    	fgets(output, sizeof(output), output_file);
	cr_assert_str_eq(output, expected, "Expected output %s but got %s", expected, output);
}

Test(so_long_suite, test_so_long_map_right_collec_quant, .init=redirect_all_stdout)
{
	char	**map;
	int     length;
	int     height;
	char	*map_name = "maps/map_ex2.ber";

	length = get_map_length(map_name);
	height = get_map_height(map_name);
	map = get_map(map_name, length, height);
	ft_printf("%d\n", collec_quant(map));
	const char *expected = "5\n";
	FILE *output_file = cr_get_redirected_stdout();
	char output[64];
    	fgets(output, sizeof(output), output_file);
	cr_assert_str_eq(output, expected, "Expected output %s but got %s", expected, output);
}
