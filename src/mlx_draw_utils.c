#include "../include/so_long.h"
#include "../minilibx-linux/mlx.h"

void    draw_xpm_with_transparency(t_mlx *st_mlx, void *img, int x, int y)
{
    int i, j;
    int color;
    char *data;
    int bpp, size_line, endian;
        int     white_color = 16777215;
        int     transparent_color = 0;

    data = mlx_get_data_addr(img, &bpp, &size_line, &endian);

    for (j = 0; j < 64; j++)
    {
        for (i = 0; i < 64; i++)
        {
            // Get the color at (i, j)
            color = *(int *)(data + (j * size_line + i * (bpp / 8)));

            // Check if the pixel is transparent (spaces in XPM)
            if ((color & white_color) != transparent_color) // Skip transparent pixels
                mlx_pixel_put(st_mlx->mlx, st_mlx->win, x + i, y + j, color);
        }
    }
}

void    paint_screen(t_mlx *st_mlx, int width, int height)
{
	int		x;
	int     y;
	int     img_width = 64;
	int     img_height = 64;

	x = 0;
	while (x < height)
	{
		y = 0;
		while (y < width)
		{
			mlx_put_image_to_window(st_mlx->mlx, st_mlx->win, st_mlx->tile_img, y, x);
			y += 64;
		}
		x += 64;
	}
}


int	put_assets(t_mlx *st_mlx, char c, int w, int h)
{
	//TODO maybe check for errors here
	if (c == '1')
		draw_xpm_with_transparency(st_mlx, st_mlx->wall_img, w, h);// mlx_put_image_to_window(st_mlx.mlx, st_mlx.win, st_mlx.wall_img, w, h);
		// mlx_put_image_to_window(st_mlx->mlx, st_mlx->win, st_mlx->wall_img, w, h);
	if (c == 'P')
		draw_xpm_with_transparency(st_mlx, st_mlx->player_img, w, h);
		// mlx_put_image_to_window(st_mlx->mlx, st_mlx->win, st_mlx->player_img, w, h);
	if (c == 'C')
		draw_xpm_with_transparency(st_mlx, st_mlx->collec_img, w, h);
		// mlx_put_image_to_window(st_mlx->mlx, st_mlx->win, st_mlx->collec_img, w, h);
	if (c == 'E')
		draw_xpm_with_transparency(st_mlx, st_mlx->exit_img, w, h);
		// mlx_put_image_to_window(st_mlx->mlx, st_mlx->win, st_mlx->exit_img, w, h);
	if (c == '0')
		draw_xpm_with_transparency(st_mlx, st_mlx->tile_img, w, h);
	return (1);
}

int	draw_screen(t_mlx *st_mlx, t_map *st_map)//TODO need to check case there is any error?
{
	int     x;
	int		y;
	int		w;
	int		h;

	x = -1;
	h = 0;
	while (++x < st_map->height)
	{
		y = -1;
		w = 0;
		while (++y < st_map->length)
		{
			put_assets(st_mlx, st_map->map[x][y], w, h);
			w += 64;
		}
		h += 64;
	}
	return (1);
}
