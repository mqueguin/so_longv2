/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:07:21 by mqueguin          #+#    #+#             */
/*   Updated: 2021/10/04 12:52:58 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long.h"

int	place_enemy_on_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[++y])
	{
		x = 0;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == '0')
			{
				game->enemy.pos[0] = x;
				game->enemy.pos[1] = y;
				return (1);
			}
		}
	}
	return (1);
}
