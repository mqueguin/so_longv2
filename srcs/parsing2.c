/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 18:38:59 by mqueguin          #+#    #+#             */
/*   Updated: 2021/09/30 19:24:05 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_right_left_wall(t_game *game, int x_max)
{
	int	x;
	int	y;

	y = -1;
	while (game->map[++y])
	{
		x = 0;
		if (game->map[y][0] != '1')
			return (ft_putendl_fd("Error\nLe mur de gauche n'est pas ferme", 2));
		if (game->map[y][x_max - 1] != '1' || game->map[y][x_max])
			return (ft_putendl_fd("Error\nLe mur de droite n'est pas ferme", 2));
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
			printf("Error\nLe mur du haut n'est pas ferme\n");
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
			printf(" an exit in the map are missing\n");
		}
		else if (!b_exit)
			printf("Error\nThere must be at least one exit\n");
		else if (!b_player)
			printf("Error\nThe player is missing\n");
		else if (!game->nb_collectible)
			printf("Error\nThere must be at least 1 collectible\n");
		exit(0);
	}
}
