/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_way.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrechuli <mrechuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:40:53 by mrechuli          #+#    #+#             */
/*   Updated: 2024/05/28 18:01:21 by mrechuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	flood_fill(char **map, int height, int x, int y)
{
	size_t	width;

	width = map_width(map[0]);
	if (x < 0 || x >= height || y < 0 || y >= width
		|| map[x][y] == '1' || map[x][y] == 'X' || map[x][y] == 'T')
		return ;
	map[x][y] = 'X';
	flood_fill(map, height, x, y - 1);
	flood_fill(map, height, x, y + 1);
	flood_fill(map, height, x - 1, y);
	flood_fill(map, height, x + 1, y);
}

static char	**duplicate_map(char **map)
{
	char	**map_dup;
	short	x;

	map_dup = malloc(sizeof(char *) * (map_height(map) + 1));
	if (!map_dup)
		return (NULL);
	map_dup[map_height(map)] = NULL;
	x = 0;
	while (map[x])
	{
		map_dup[x] = ft_strdup(map[x]);
		if (!map_dup[x])
		{
			free_map(map_dup);
			return (NULL);
		}
		x++;
	}
	return (map_dup);
}

void	check_way(char **map)
{
	char	**map_dup;
	short	p_pos[2];
	size_t	height;

	height = map_height(map);
	map_dup = duplicate_map(map);
	if (!map_dup)
		error(map, "Allocation falied");
	find_gps(map_dup, p_pos, NULL);
	flood_fill(map_dup, height, p_pos[0], p_pos[1]);
	if (!is_all_collected(map_dup))
	{
		free_map(map_dup);
		error(map, "map is not finishable");
	}
	free_map(map_dup);
}
