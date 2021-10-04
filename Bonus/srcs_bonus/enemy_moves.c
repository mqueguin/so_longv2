/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 12:56:52 by mqueguin          #+#    #+#             */
/*   Updated: 2021/10/04 12:41:05 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long.h"

/**
 * Fonction qui va simplement faire un switch
 * afin de determiner dans quel sens va allers
 * le creeper
 **/

void	enemy_moves(t_game *game, int b_move)
{
	game->enemy.b_move = b_move;
	if ((game->map[game->enemy.pos[1]][game->enemy.pos[0] + 1] == '0'
		|| game->map[game->enemy.pos[1]][game->enemy.pos[0] + 1] == 'C'
		|| game->map[game->enemy.pos[1]][game->enemy.pos[0] + 1] == 'E'
		|| game->map[game->enemy.pos[1]][game->enemy.pos[0] + 1] == '1')
		&& game->enemy.b_move == 1)
	{
		if (game->map[game->enemy.pos[1]][game->enemy.pos[0] + 1] == '1')
			enemy_moves(game, 0);
		else
			game->enemy.pos[0] += 1;
	}
	else if (game->map[game->enemy.pos[1]][game->enemy.pos[0] - 1] == '0'
		|| game->map[game->enemy.pos[1]][game->enemy.pos[0] - 1] == 'C'
		|| game->map[game->enemy.pos[1]][game->enemy.pos[0] - 1] == 'E'
		|| game->map[game->enemy.pos[1]][game->enemy.pos[0] - 1] == '1')
	{
		if (game->map[game->enemy.pos[1]][game->enemy.pos[0] - 1] == '1')
			enemy_moves(game, 1);
		else
			game->enemy.pos[0] -= 1;
	}
}
