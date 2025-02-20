/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebatist <hebatist@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:30:49 by hebatist          #+#    #+#             */
/*   Updated: 2025/02/20 13:30:51 by hebatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	case_error_reading_file(void)
{
	perror("Error\nProblem reading map file");
	exit(EXIT_FAILURE);
}

size_t	line_len(char *line)
{
	size_t	len;

	len = 0;
	while (*line && *line != '\n')
	{
		len++;
		line++;
	}
	return (len);
}

int	get_map_length(char *map_name)
{
	int			fd;
	char		*line;
	size_t		len;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		case_error_reading_file();
	line = get_next_line(fd);
	if (line == NULL)
		return (0);
	len = line_len(line);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		if (line != NULL && len != line_len(line))
		{
			free(line);
			close(fd);
			return (0);
		}
	}
	free (line);
	close(fd);
	return (len);
}

int	get_map_height(char *map_name)
{
	int			fd;
	char		*line;
	size_t		len;

	len = 0;
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		case_error_reading_file();
	line = get_next_line(fd);
	if (line == NULL)
		return (0);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		len++;
	}
	return (len);
}
