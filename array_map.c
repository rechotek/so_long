/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrechuli <mrechuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:04:35 by marvin            #+#    #+#             */
/*   Updated: 2024/05/28 17:49:36 by mrechuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// przeksztalca mape w jeden, polaczony ciag znakow

static char	*read_map(int fd)
{
	char	*str;
	char	*tmp;
	char	*line;

	str = get_next_line(fd);
	if (!str)
		error(NULL, "Map file is empty");
	line = get_next_line(fd);
	while (line)
	{
		tmp = str;
		str = ft_strjoin(tmp, line);
		free(line);
		free(tmp);
		line = get_next_line(fd);
	}
	return (str);
}

char	**array_map(char *path)
{
	char	**map;
	char	*map_str;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		error(NULL, "Wrong file path");
	map_str = read_map(fd);
	map = ft_split(map_str, '\n');
	free(map_str);
	return (map);
}
