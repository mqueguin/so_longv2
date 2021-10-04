/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 15:18:51 by mqueguin          #+#    #+#             */
/*   Updated: 2021/10/04 15:27:09 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long.h"

int	check_right_left_wall(t_game *game, int x_max)
{
	int	x;
	int	y;

	y = -1;
	while (game->map[++y])
	{
		x = 0;
		if (game->map[y][0] != '1')
			return (ft_putendl_fd("Error\nThe left wall is not closed", 2));
		if (game->map[y][x_max - 1] != '1' || game->map[y][x_max])
			return (ft_putendl_fd("Error\nThe right wall is not closed", 2));
	}
	return (y);
}

int	check_top_wall(t_game *game)
{
	int	x;

	x = -1;
	while (game->map[0][++x])
	{
		if (game->map[0][x] != '1')
		{
			ft_putendl_fd("Error\nThe top wall is not closed", 2);
			return (0);
		}
	}
	return (x);
}

void	check_elements_in_map(t_game *game, int b_exit, int b_player)
{
	if (!b_exit || !game->nb_collectible || !b_player)
	{
		free_tab2d(game->map);
		if (!b_exit && !b_player && !game->nb_collectible)
		{
			printf("Error\nA collectible, a player and");
			ft_putendl_fd(" an exit in the map are missing\n", 2);
		}
		else if (!b_exit)
			ft_putendl_fd("Error\nThere must be at least one exit", 2);
		else if (!b_player)
			ft_putendl_fd("Error\nThe player is missing", 2);
		else if (!game->nb_collectible)
			ft_putendl_fd("Error\nThere must be at least 1 collectible", 2);
		exit(0);
	}
}
