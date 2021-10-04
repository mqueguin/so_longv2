/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:07:21 by mqueguin          #+#    #+#             */
/*   Updated: 2021/10/04 12:37:06 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long.h"

static	int	check_around(t_game *game, int x, int y)
{
	if ((game->map[y][x + 1] == '0' && game->map[y][x + 2] == '0')
			|| (game->map[y][x - 1] == '0' && game->map[y][x - 2] == '0'))
		return (1);
	return (0);
}

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
			if (game->map[y][x] == '0' && check_around(game, x, y))
			{
				game->enemy.pos[0] = x;
				game->enemy.pos[1] = y;
				return (1);
			}
		}
	}
	free_tab2d(game->map);
	ft_putstr_fd("Error\nUnable to place enemy on the map\n", 2);
	return (0);
}
