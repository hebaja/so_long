#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>

void	print_map(char **map, int height, int width)
{
	int	i;
	int	j;

	i = -1;
	while (++i < height)
	{
		j = -1;
		while (++j < width -1)
			printf("%c", map[i][j]);
		printf("\n");
	}
}

void	generate_walls(char **map, int height, int width)
{
	int	i;

	i = -1;
	while (++i < width - 1)
	{
		map[0][i] = '1';
		map[height -1][i] = '1';
	}
	i = -1;
	while (++i < height)
	{
		map[i][0] = '1';
		map[i][width - 2] = '1';
	}
}

void	generate_inside_walls(char **map, int height, int width)
{
	int	i;
	int	x;
	int	y;
	int	walls;

	i = -1;
	walls = (int)((height * width) * 0.15);
	srand(time(NULL));
	while (++i < walls)
	{
		x = rand() % (height -1);
		y = rand() % (width -2);
		if (x == 0 || y == 0)
		{
			i--;
			continue ;
		}
		if (map[x][y] == '1')
		{
			i--;
			continue ;
		}
		map[x][y] = '1';
	}
}

void	generate_collecs(char **map, int height, int width)
{
	int	i;
	int	x;
	int	y;
	int	walls;

	i = -1;
	walls = (int)((height * width) * 0.08);
	srand(time(NULL));
	while (++i < walls)
	{
		x = rand() % (height -1);
		y = rand() % (width -2);
		if (x == 0 || y == 0)
		{
			i--;
			continue ;
		}
		if (map[x][y] == '1' || map[x][y] == 'C')
		{
			i--;
			continue ;
		}
		map[x][y] = 'C';
	}
}

void	generate_player(char **map, int height, int width)
{
	int	x;
	int	y;
	int	flag;

	srand(time(NULL));
	flag = 0;
	while (flag == 0)
	{
		x = rand() % (height -1);
		y = rand() % (width -2);
		if (map[x][y] == '0')
		{
			map[x][y] = 'P';
			flag = 1;
		}
	}
}

void	generate_exit(char **map, int height, int width)
{
	int	x;
	int	y;
	int	flag;

	srand(time(NULL));
	flag = 0;
	while (flag == 0)
	{
		x = rand() % (height -1);
		y = rand() % (width -2);
		if (map[x][y] == '0')
		{
			map[x][y] = 'E';
			flag = 1;
		}
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int	height = atoi(argv[1]);
	int	width = atoi(argv[2]); 
	char	**map;
	
	i = -1;
	map = (char **)malloc(sizeof(char *) * height);
	while (++i < height)
		map[i] = (char *)malloc(sizeof(char) * (width + 1));
	i = -1;
	while (++i < height)
	{
		j = -1;
		while (++j < width)
			map[i][j] = '0';
		map[i][j] = '\0';
	}

	generate_walls(map, height, width);
	generate_inside_walls(map, height, width);
	generate_collecs(map, height, width);
	generate_player(map, height, width);
	generate_exit(map, height, width);
	print_map(map, height, width);
	i = -1;
	while (++i < height)
		free(map[i]);
	free(map);
	map = NULL;
	return (0);
}
