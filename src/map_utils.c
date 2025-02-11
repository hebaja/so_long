/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hebatist <hebatist@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:02:58 by hebatist          #+#    #+#             */
/*   Updated: 2025/02/11 17:03:00 by hebatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	get_map_length(char *map_name)
{
	size_t	len;
	char	*str;
	int	fd;

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
	size_t	len;
	char	*str;
	int	fd;

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
