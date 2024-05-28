/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrechuli <mrechuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:01:15 by marvin            #+#    #+#             */
/*   Updated: 2024/05/28 17:56:21 by mrechuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	init_textures(t_game *game)
{
	game->txt.a = mlx_xpm_file_to_image(game->mlx, "textures/0.xpm",
			&(game->width), &(game->height));
	game->txt.w = mlx_xpm_file_to_image(game->mlx, "textures/1.xpm",
			&(game->width), &(game->height));
	game->txt.c = mlx_xpm_file_to_image(game->mlx, "textures/c.xpm",
			&(game->width), &(game->height));
	game->txt.e = mlx_xpm_file_to_image(game->mlx, "textures/e.xpm",
			&(game->width), &(game->height));
	game->txt.t = mlx_xpm_file_to_image(game->mlx, "textures/t.xpm",
			&(game->width), &(game->height));
	game->txt.pb = mlx_xpm_file_to_image(game->mlx, "textures/pb.xpm",
			&(game->width), &(game->height));
	game->txt.pd = mlx_xpm_file_to_image(game->mlx, "textures/pd.xpm",
			&(game->width), &(game->height));
	game->txt.pl = mlx_xpm_file_to_image(game->mlx, "textures/pl.xpm",
			&(game->width), &(game->height));
	game->txt.pr = mlx_xpm_file_to_image(game->mlx, "textures/pr.xpm",
			&(game->width), &(game->height));
}

int	handle_key_events(int keycode, t_game *game)
{
	if (keycode == 65362)
		move_player(game, -1, 0, 'w');
	if (keycode == 65364)
		move_player(game, 1, 0, 's');
	if (keycode == 65361)
		move_player(game, 0, -1, 'a');
	if (keycode == 65363)
		move_player(game, 0, 1, 'd');
	if (keycode == 65307)
		close_game(game);
	return (0);
}

void	start_game(t_game game)
{
	game.mlx = mlx_init();
	game.width = map_width(game.map[0]);
	game.height = map_height(game.map);
	game.window = mlx_new_window(game.mlx, game.width * 50, game.height * 50,
			"so_long");
	find_gps(game.map, game.p_pos, game.e_pos);
	init_textures(&game);
	fill_textures(game, 'w');
	mlx_hook(game.window, 17, 0, close_game, &game);
	mlx_key_hook(game.window, handle_key_events, &game);
	mlx_loop(game.mlx);
}
