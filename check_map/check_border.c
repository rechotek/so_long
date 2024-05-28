/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_border.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrechuli <mrechuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:40:56 by mrechuli          #+#    #+#             */
/*   Updated: 2024/05/28 17:57:17 by mrechuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_border(char **map)
{
	size_t	width;
	size_t	height;
	short	x;
	short	y;

	width = map_width(map[0]) - 1;
	height = map_height(map) - 1;
	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (x == 0 || x == height || y == 0 || y == width)
			{
				if (map[x][y] != '1')
					error(map, "The map must be surrounded by walls");
			}
			y++;
		}
		x++;
	}
}
