/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrechuli <mrechuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:15:11 by marvin            #+#    #+#             */
/*   Updated: 2024/05/28 17:42:39 by mrechuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	map_width(char *map)
{
	size_t	x;

	x = 0;
	while (map[x] != '\n' && map[x] != '\0')
		x++;
	return (x);
}

size_t	map_height(char **map)
{
	size_t	x;

	x = 0;
	while (map[x])
		x++;
	return (x);
}

bool	is_all_collected(char **map)
{
	size_t	x;
	size_t	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'C' || map[x][y] == 'E')
				return (false);
			y++;
		}
		x++;
	}
	return (true);
}

void	find_gps(char **map, short *p_pos, short *e_pos)
{
	short	x;
	short	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'P' && p_pos)
			{
				p_pos[0] = x;
				p_pos[1] = y;
			}
			if (map[x][y] == 'E' && e_pos)
			{
				e_pos[0] = x;
				e_pos[1] = y;
			}
			y++;
		}
		x++;
	}
}
