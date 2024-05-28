/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrechuli <mrechuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:02:17 by marvin            #+#    #+#             */
/*   Updated: 2024/05/28 17:46:09 by mrechuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
		error(NULL, "You must enter only one map file");
	game.map = array_map(argv[1]);
	check_map(game.map);
	start_game(game);
	free_map(game.map);
	return (0);
}
