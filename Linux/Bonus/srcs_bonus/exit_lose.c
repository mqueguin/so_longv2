/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_lose.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 12:21:58 by mqueguin          #+#    #+#             */
/*   Updated: 2021/10/04 15:30:50 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/so_long.h"

void	exit_lose(t_game *game)
{
	printf("Nombres de coups : %d\n", game->count + 1);
	ft_putendl_fd("You lost !", 1);
	mlx_destroy_image(game->mlx, game->img);
	mlx_destroy_window(game->mlx, game->mlx_win);
	free_tab2d(game->map);
	exit(0);
}
