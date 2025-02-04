#include <stdio.h>

void	print_img(int img[6][5])
{
	int	i;
	int	j;

	i = -1;
	while (++i < 6)
	{
		j = -1;
		while (++j < 5)
			printf("%d ", img[i][j]);
		printf("\n");
	}
	printf("\n");
}

void	print_tmp_img(int img[6][5], int x, int y)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 6)
	{
		j = -1;
		while (++j < 5)
		{
			if (i == x && j == y)
				printf("8 ");
			else
				printf("%d ", img[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void	flood_fill(int img[6][5], int x, int y, int prev_color, int new_color)
{
	if (img[x][y] != prev_color)
		return ;
	print_tmp_img(img, x, y);
	img[x][y] = new_color;
	if (x - 1 >= 0)
		flood_fill(img, x - 1, y, prev_color, new_color);
	if (y + 1 < 5)
		flood_fill(img, x, y + 1, prev_color, new_color);
	if (x + 1 < 6)
		flood_fill(img, x + 1, y, prev_color, new_color);
	if (y - 1 >= 0)
		flood_fill(img, x, y - 1, prev_color, new_color);

}

void	change_color(int img[6][5], int x, int y, int new_color)
{
	int	prev_color;

	prev_color = img[x][y];
	flood_fill(img, x, y, prev_color, new_color);
	print_img(img);
}

int	main()
{
	int	img[6][5] = {{1,1,1,0,0},{1,1,1,0,0},{1,1,1,1,0},{1,1,0,0,0},{1,1,0,1,1},{0,0,0,1,1}};

	print_img(img);
	change_color(img, 3, 2, 4);
	return (0);
}
