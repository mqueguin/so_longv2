/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:07:21 by mqueguin          #+#    #+#             */
/*   Updated: 2021/09/29 15:51:17 by mqueguin         ###   ########.fr       */
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
				game->enemy.enemy_pos[0] = x;
				game->enemy.enemy_pos[1] = y;
				//game->map[game->enemy.enemy_pos[1]][game->enemy.enemy_pos[0]] = 'D';
				return (1);
			}
		}
	}
	free_tab2d(game->map);
	printf("Error\nUnable to place enemy on the map\n");
	return (0);
}