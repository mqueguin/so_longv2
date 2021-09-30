/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 12:56:52 by mqueguin          #+#    #+#             */
/*   Updated: 2021/09/30 14:52:07 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long.h"

/**
 * Fonction qui va simplement faire un switch
 * afin de determiner dans quel sens va allers
 * le creeper
 **/

void	enemy_moves(t_game *game)
{
	if ((game->map[game->enemy.enemy_pos[1]][game->enemy.enemy_pos[0] + 1] == '0'
			|| game->map[game->enemy.enemy_pos[1]][game->enemy.enemy_pos[0] + 1] == 'C'
			|| game->map[game->enemy.enemy_pos[1]][game->enemy.enemy_pos[0] + 1] == 'E'
			|| game->map[game->enemy.enemy_pos[1]][game->enemy.enemy_pos[0] + 1] == '1')
			&& game->enemy.b_move == 1)
	{
		if (game->map[game->enemy.enemy_pos[1]][game->enemy.enemy_pos[0] + 1] == '1')
		{
			game->enemy.b_move = 0;
			enemy_moves(game);
		}
		else
			game->enemy.enemy_pos[0] += 1;
	}
	else if (game->map[game->enemy.enemy_pos[1]][game->enemy.enemy_pos[0] - 1] == '0'
			|| game->map[game->enemy.enemy_pos[1]][game->enemy.enemy_pos[0] - 1] == 'C'
			|| game->map[game->enemy.enemy_pos[1]][game->enemy.enemy_pos[0] - 1] == 'E'
			|| game->map[game->enemy.enemy_pos[1]][game->enemy.enemy_pos[0] - 1] == '1')
	{
		if (game->map[game->enemy.enemy_pos[1]][game->enemy.enemy_pos[0] - 1] == '1')
		{
			game->enemy.b_move = 1;
			enemy_moves(game);
		}
		else
			game->enemy.enemy_pos[0] -= 1;
	}
}