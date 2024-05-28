/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrechuli <mrechuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:31:59 by marvin            #+#    #+#             */
/*   Updated: 2024/05/28 17:46:49 by mrechuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	short	x;

	x = 0;
	while (map[x])
	{
		free(map[x]);
		x++;
	}
	free(map);
}

void	error(char **map, char *msg)
{
	ft_printf("Error\n");
	ft_printf("%s\n", msg);
	if (map && map[0])
		free_map(map);
	exit(1);
}
