/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rectangular.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrechuli <mrechuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 19:21:56 by mrechuli          #+#    #+#             */
/*   Updated: 2024/05/28 18:00:00 by mrechuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_rectangular(char **map)
{
	size_t	len;
	short	x;

	len = map_width(map[0]);
	x = 1;
	while (map[x])
	{
		if (map_width(map[x]) != len)
			error(map, "The map must be rectangular!");
		x++;
	}
}
