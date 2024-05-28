/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_characters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrechuli <mrechuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:04:32 by marvin            #+#    #+#             */
/*   Updated: 2024/05/28 17:59:30 by mrechuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

bool	verify_characters(char ch, size_t *c, size_t *e, size_t *p)
{
	if (ch == 'C')
		(*c)++;
	else if (ch == 'E')
		(*e)++;
	else if (ch == 'P')
		(*p)++;
	else if (ch != '0' && ch != '1' && ch != 'T')
		return (false);
	return (true);
}

void	check_characters(char **map)
{
	size_t	collectibles;
	size_t	exits;
	size_t	players;
	short	x;
	short	y;

	collectibles = 0;
	exits = 0;
	players = 0;
	x = -1;
	while (++x, map[x])
	{
		y = -1;
		while (++y, map[x][y])
		{
			if (!verify_characters(map[x][y], &collectibles, &exits, &players))
				error(map, "The map contains invalid characters");
		}
	}
	if (collectibles < 1)
		error(map, "Wrong number of collectibles! Must be at least 1.");
	if (exits != 1)
		error(map, "Wrong number of exits! There can only be 1.");
	if (players != 1)
		error(map, "Wrong number of players! There can only be 1.");
}
