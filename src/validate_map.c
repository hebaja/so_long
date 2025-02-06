int	is_one_player(char **map, int length, int height)
{
	int	i;
	int	j;
	int	found;

	i = -1;
	found = 0;
	while (++i < height)
	{
		j = -1;
		while (++j < length)
		{
			if (map[i][j] == 'P')
			{
				if (!found)
					found = 1;
				else
					return (0);
			}
		}
	}
	return (found);
}
