/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrechuli <mrechuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:17:12 by mrechuli          #+#    #+#             */
/*   Updated: 2024/05/28 17:52:32 by mrechuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	display_moves(t_game *game, short moves)
{
	char	*str;

	str = ft_itoa(moves);
	mlx_string_put(game->mlx, game->window, 10, 20, 0xFFFFFFFF, "Moves: ");
	mlx_string_put(game->mlx, game->window, 70, 20, 0xFFFFFFFF, str);
	free(str);
}

void	move_player(t_game *game, short x_off, short y_off, char key)
{
	static short	moves = 0;
	short			new_row;
	short			new_col;

	new_row = game->p_pos[0] + x_off;
	new_col = game->p_pos[1] + y_off;
	if (game->map[new_row][new_col] == '1')
		return ;
	if (game->map[new_row][new_col] == 'T')
		close_game(game);
	moves++;
	if (game->map)
		game->map[new_row][new_col] = 'P';
	if (new_row == game->e_pos[0] && new_col == game->e_pos[1])
		if (is_all_collected(game->map))
			close_game(game);
	if (game->p_pos[0] == game->e_pos[0] && game->p_pos[1] == game->e_pos[1])
		game->map[game->p_pos[0]][game->p_pos[1]] = 'E';
	else
		game->map[game->p_pos[0]][game->p_pos[1]] = '0';
	game->p_pos[0] = new_row;
	game->p_pos[1] = new_col;
	fill_textures(*game, key);
	display_moves(game, moves);
}

int	close_game(t_game *game)
{
	mlx_destroy_image(game->mlx, game->txt.a);
	mlx_destroy_image(game->mlx, game->txt.w);
	mlx_destroy_image(game->mlx, game->txt.c);
	mlx_destroy_image(game->mlx, game->txt.e);
	mlx_destroy_image(game->mlx, game->txt.pb);
	mlx_destroy_image(game->mlx, game->txt.pd);
	mlx_destroy_image(game->mlx, game->txt.pl);
	mlx_destroy_image(game->mlx, game->txt.pr);
	mlx_destroy_image(game->mlx, game->txt.t);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_map(game->map);
	exit(0);
}
