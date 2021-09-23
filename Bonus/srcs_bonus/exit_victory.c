/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_victory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 15:57:01 by mqueguin          #+#    #+#             */
/*   Updated: 2021/09/22 13:19:29 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long.h"

int	exit_victory(t_game *game)
{
	if (game->nb_collectible == game->count_collectible)
	{
		printf("Nombres de coups : %d\n", game->count + 1);
		printf("You win !\n");
		mlx_destroy_image(game->mlx, game->img);
		mlx_destroy_window(game->mlx, game->mlx_win);
		free_tab2d(game->map);
		exit(1);
	}
	return (0);
}