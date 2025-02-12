/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebatist <hebatist@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:02:58 by hebatist          #+#    #+#             */
/*   Updated: 2025/02/12 01:16:02 by hebatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	get_map_length(char *map_name)
{
	int			fd;
	char		*str;
	size_t		len;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		return (-1);
	str = get_next_line(fd);
	if (str == NULL)
		return (-2);
	len = ft_strlen(str);
	while (str != NULL)
	{
		free(str);
		str = get_next_line(fd);
		if (str != NULL && len != ft_strlen(str))
		{
			free(str);
			close(fd);
			return (-2);
		}
	}
	free (str);
	close(fd);
	return (len);
}

int	get_map_height(char *map_name)
{
	int			fd;
	char		*str;
	size_t		len;

	len = 0;
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		return (-1);
	str = get_next_line(fd);
	if (str == NULL)
		return (-2);
	while (str != NULL)
	{
		free(str);
		str = get_next_line(fd);
		len++;
	}
	return (len);
}
