/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_mlx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 13:45:51 by mqueguin          #+#    #+#             */
/*   Updated: 2021/10/04 12:56:40 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long.h"

void	initialize_mlx_and_window(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
	{
		free_tab2d(game->map);
		exit(0);
	}
	game->mlx_win = mlx_new_window(game->mlx, game->res[0] * 32,
			game->res[1] * 32, "so_long");
}
