/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrechuli <mrechuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:36:00 by marvin            #+#    #+#             */
/*   Updated: 2024/05/28 17:53:34 by mrechuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	fill_texture(t_game game, void *txt, short x, short y)
{
	mlx_put_image_to_window(game.mlx, game.window, txt, x, y);
}

static void	fill_player(t_game game, char key, short x, short y)
{
	if (key == 'w')
		fill_texture(game, game.txt.pb, x, y);
	if (key == 's')
		fill_texture(game, game.txt.pd, x, y);
	if (key == 'a')
		fill_texture(game, game.txt.pl, x, y);
	if (key == 'd')
		fill_texture(game, game.txt.pr, x, y);
}

void	fill_textures(t_game game, char key)
{
	short	x;
	short	y;

	x = 0;
	while (game.map[x])
	{
		y = 0;
		while (game.map[x][y])
		{
			if (game.map[x][y] == '0')
				fill_texture(game, game.txt.a, y * 50, x * 50);
			if (game.map[x][y] == '1')
				fill_texture(game, game.txt.w, y * 50, x * 50);
			if (game.map[x][y] == 'C')
				fill_texture(game, game.txt.c, y * 50, x * 50);
			if (game.map[x][y] == 'E')
				fill_texture(game, game.txt.e, y * 50, x * 50);
			if (game.map[x][y] == 'T')
				fill_texture(game, game.txt.t, y * 50, x * 50);
			if (game.map[x][y] == 'P')
				fill_player(game, key, y * 50, x * 50);
			y++;
		}
		x++;
	}
}
