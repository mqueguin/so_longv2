/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 19:12:31 by mqueguin          #+#    #+#             */
/*   Updated: 2021/10/04 13:01:00 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long.h"

void	ft_up(t_game *game)
{
	if (game->map[game->player_pos[1] - 1][game->player_pos[0]] == '1')
		return ;
	enemy_moves(game, game->enemy.b_move);
	if (game->map[game->player_pos[1] - 1][game->player_pos[0]] == 'E')
	{
		game->player_pos[1]--;
		exit_victory(game);
		game->count += 1;
	}
	else if ((game->map[game->player_pos[1] - 1][game->player_pos[0]] == '0')
			|| (game->map[game->player_pos[1] - 1][game->player_pos[0]] == 'C'))
	{
		game->player_pos[1]--;
		game->count += 1;
	}
}

void	ft_down(t_game *game)
{
	if (game->map[game->player_pos[1] + 1][game->player_pos[0]] == '1')
		return ;
	enemy_moves(game, game->enemy.b_move);
	if (game->map[game->player_pos[1] + 1][game->player_pos[0]] == 'E')
	{
		game->player_pos[1]++;
		exit_victory(game);
		game->count += 1;
	}
	else if ((game->map[game->player_pos[1] + 1][game->player_pos[0]] == '0')
			|| (game->map[game->player_pos[1] + 1][game->player_pos[0]] == 'C'))
	{
		game->player_pos[1]++;
		game->count += 1;
	}
}

void	ft_left(t_game *game)
{
	if (game->map[game->player_pos[1]][game->player_pos[0] - 1] == '1')
		return ;
	enemy_moves(game, game->enemy.b_move);
	if (game->map[game->player_pos[1]][game->player_pos[0] - 1] == 'E')
	{
		game->player_pos[0]--;
		exit_victory(game);
		game->count += 1;
	}
	else if ((game->map[game->player_pos[1]][game->player_pos[0] - 1] == '0')
			|| (game->map[game->player_pos[1]][game->player_pos[0] - 1] == 'C'))
	{
		game->player_pos[0]--;
		game->count += 1;
	}
}

void	ft_right(t_game *game)
{
	if (game->map[game->player_pos[1]][game->player_pos[0] + 1] == '1')
		return ;
	enemy_moves(game, game->enemy.b_move);
	if (game->map[game->player_pos[1]][game->player_pos[0] + 1] == 'E')
	{
		game->player_pos[0]++;
		exit_victory(game);
		game->count += 1;
	}
	else if ((game->map[game->player_pos[1]][game->player_pos[0] + 1] == '0')
			|| (game->map[game->player_pos[1]][game->player_pos[0] + 1] == 'C'))
	{
		game->player_pos[0]++;
		game->count += 1;
	}
}
